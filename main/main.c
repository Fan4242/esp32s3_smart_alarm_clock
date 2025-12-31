#include <stdio.h>
#include "lv_port.h"
#include "xl9555.h"
#include "string.h"
#include "driver/gpio.h"
#include "lv_demos.h"
#include "esp_lvgl_port.h"
#include "esp_log.h"
#include "ft6336u_driver.h"
#include "gui_guider.h"
#include "custom.h"
#include "button.h"
#include "ap_wifi.h"
#include <time.h>
#include "esp_sntp.h"
#include "nvs_flash.h"
#include "weather.h"
#include "esp_spiffs.h"
#include "board_config.h"
#include "nocodec_audio.h"  //音频播放头文件
#include <sys/stat.h>   //获取文件状态头文件

#define TAG "main"

//I2S采样率
#define SAMPLE_RATE         24000

lv_ui guider_ui;

/** 从spiffs中加载html页面到内存
 * @param 无
 * @return 无 
*/
static void img_spiffs_init(void)
{
    //定义挂载点
    esp_vfs_spiffs_conf_t conf = {
        .base_path = "/img",            //挂载点
        .partition_label = "img",         //分区名称
        .max_files = 5,                    //最大打开的文件数
        .format_if_mount_failed = false    //挂载失败是否执行格式化
        };
    //挂载spiffs
    ESP_ERROR_CHECK(esp_vfs_spiffs_register(&conf));
}

//spiffs文件系统挂载点
#define AUDIO_MOUNT     "/spiffs"
//初始化spiffs文件系统
void audio_spiffs_init(void)
{
    esp_vfs_spiffs_conf_t conf = {
      .base_path = AUDIO_MOUNT,     //挂载点
      .partition_label = "audio",  //指定spiffs分区，如果为NULL，则默认为分区表中第一个spiffs类型的分区
      .max_files = 2,               //最大可同时打开的文件数
      .format_if_mount_failed = true
    };

    //初始化和挂载spiffs分区
    esp_vfs_spiffs_register(&conf);
}

// 按位表示
static volatile uint16_t xl9555_button_level = 0xFFFF;

int get_button_level(int gpio)
{
    return (xl9555_button_level & gpio) ? 1 : 0;
}

void long_press(int gpio)
{
    ap_wifi_apcfg(true);
}

void button_init(void)
{
    button_config_t button_cfg =
        {
            .active_level = 0,
            .getlevel_cb = get_button_level,
            .gpio_num = IO0_1,
            .long_cb = long_press,
            .long_press_time = 3000,
            .short_cb = NULL,
        };
    button_event_set(&button_cfg);
}

// xl9555的中断回调函数，这个函数的第一个参数会告诉主机那些gpio引脚有电平变化
// 第二个参数就是发生了什么变化
void xl9555_input_callback(uint16_t io_num, int level)
{
    if (level)
        xl9555_button_level |= io_num;
    else
        xl9555_button_level &= ~io_num;
    if (io_num == IO1_1)
    {
        if (!level) // 为0，检测到下降沿
        {
            ft6336u_int_info(true);
        }
        else
        {
            ft6336u_int_info(false);
        }
    }
    ESP_LOGI(TAG, "gpio_num:%d,level:%d", io_num, level);
}

static lv_obj_t *btn;
static lv_obj_t *label1;
static lv_obj_t *label2;

static void lv_event_test(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    static int click_cnt = 0;
    if (code == LV_EVENT_CLICKED)
    {
        char text[32];
        click_cnt++;
        snprintf(text, sizeof(text), "click cnt:%d", click_cnt);
        lv_label_set_text(label1, text);
        if (click_cnt >= 5)
        {
            lv_obj_remove_event_cb(btn, lv_event_test);
        }
    }
}

static void lv_timer_test(lv_timer_t *t)
{
    char text[32];
    static int timer_cnt = 0;
    timer_cnt++;
    snprintf(text, sizeof(text), "timer cnt:%d", timer_cnt);
    lv_label_set_text(label2, text);
    if (timer_cnt >= 10)
    {
        lv_timer_pause(t);
    }
}



// sntp回调函数
static void sntp_finish_callback(struct timeval *tv)
{
    struct tm t; // 分解时间结构体
    localtime_r(&tv->tv_sec, &t);
    set_home_time(&guider_ui, t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_wday, t.tm_hour, t.tm_min, t.tm_sec);
}

// sntp初始化函数
void my_sntp_init()
{
    if (!esp_sntp_enabled())
    {
        ESP_LOGI(TAG, "sntp_init");
        esp_sntp_setoperatingmode(ESP_SNTP_OPMODE_POLL);
        esp_sntp_setservername(0, "ntp.aliyun.com");
        esp_sntp_setservername(1, "time.asia.apple.com");
        esp_sntp_setservername(2, "pool.ntp.org");
        esp_sntp_set_time_sync_notification_cb(sntp_finish_callback);
        esp_sntp_init();
    }
}

void wifi_state_callback(WIFI_STATE state)
{
    if (state == WIFI_STATE_CONNECTED)
    {
        my_sntp_init();
        ESP_LOGI(TAG, "WIFI connected!");
    }
}

//开始播放声音
void start_play(void)
{
    const size_t write_size_byte = 8192;
    struct stat st;
    if(stat(AUDIO_MOUNT"/record.pcm",&st) == 0)
    {
        ESP_LOGI(TAG,"record.pcm filesize:%ld",st.st_size);
    }
    FILE *f = fopen(AUDIO_MOUNT"/record.pcm", "r");
    if(!f)
    {
        ESP_LOGI(TAG,"record.pcm open fail!");
        return;
    }
    ESP_LOGI(TAG,"Start play");
    uint8_t *i2s_write_buff = malloc(write_size_byte);
    if(!i2s_write_buff)
    {
        fclose(f);
        return;
    }
    size_t read_byte = 0;
    do
    {
        fread(i2s_write_buff,write_size_byte,1,f);
        audio_write((const int16_t*)i2s_write_buff,write_size_byte/2);
        read_byte += write_size_byte;
        vTaskDelay(pdMS_TO_TICKS(10));
    } while (read_byte < st.st_size);
    free(i2s_write_buff);
    fclose(f);
    ESP_LOGI(TAG,"Play done");
}

void app_main(void)
{
    nvs_flash_init(); // 进行nvs初始化
    xl9555_init(XL9555_SDA, XL9555_SCL, XL9555_INT, xl9555_input_callback);
    xl9555_ioconfig(~(LCD_RSR_IO | LCD_BL_IO | SPK_EN_IO) & 0xFFFF); // 将相应的位掩码清0设置为输出，其他为输入
    xl9555_pin_write(LCD_BL_IO, 1);
    img_spiffs_init();
    lv_port_init();
    lvgl_port_lock(0);
    setup_ui(&guider_ui);
    custom_init(&guider_ui);
    lvgl_port_unlock();
    button_init();
    //喇叭初始化
    init_speaker(AUDIO_BCLK_IO, AUDIO_WS_IO, AUDIOS_DOUT_IO, SAMPLE_RATE);
    //初始化spiff文件系统
    audio_spiffs_init();
    //拉高SPK_EN_IO,为后续开始播放音频做准备
    xl9555_pin_write(SPK_EN_IO,1);
    vTaskDelay(pdMS_TO_TICKS(100));
    //开始播放
    start_play();
    ap_wifi_init(wifi_state_callback); // 参数为wifi连接成功与否的回调函数
    /*进行时区设置*/
    setenv("TZ", "CST-8", 1); // 设置东八区时区
    tzset();                  // 生效环境变量
    weather_start();
}
