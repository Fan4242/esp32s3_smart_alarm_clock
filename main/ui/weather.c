#include "weather.h"
#include "esp_http_client.h"    //包含HTTP功能的API函数
#include <stdio.h>
#include <string.h>
#include "cJSON.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gui_guider.h"
#include "wifi_manager.h"
#include "custom.h"

#define TAG "weather"

#define WEATHER_BUFF_LEN 2048   //数组存储最大长度
#define WHEATER_PRIVATE_KEY "SqxbRec90m2-P9DJq" //心知天气私钥

extern lv_ui guider_ui; //guider_ui定义在main，这里前向声明

//地理位置城市（一个中文字使用utf-8编码是需要三个字符的，所以定义长一点）
static char city_name[48];

//http接收到的数据
static uint8_t weather_data_buff[WEATHER_BUFF_LEN];

//http接收到的数据长度
static int weather_data_size = 0;

static esp_err_t _weather_http_client_event_handler(esp_http_client_event_t *evt)
{
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:    //错误事件
            //ESP_LOGI(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:    //连接成功事件
            //ESP_LOGI(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:    //发送头事件
            //ESP_LOGI(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:    //接收头事件
            //ESP_LOGI(TAG, "HTTP_EVENT_ON_HEADER");
            printf("%.*s", evt->data_len, (char*)evt->data);
            break;
        case HTTP_EVENT_ON_DATA:    //接收数据事件
            {
                size_t copy_len = 0;
                ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
                printf("HTTP_EVENT_ON_DATA data=%.*s\r\n", evt->data_len,(char*)evt->data);
                if(evt->data_len > WEATHER_BUFF_LEN - weather_data_size)
                {
                    copy_len = WEATHER_BUFF_LEN - weather_data_size;
                }
                else
                {
                    copy_len = evt->data_len;
                }
                memcpy(&weather_data_buff[weather_data_size],evt->data,copy_len);
                weather_data_size += copy_len;
            }
            break;
        case HTTP_EVENT_ON_FINISH:    //会话完成事件
            weather_data_size = 0;
            break;
        case HTTP_EVENT_DISCONNECTED:    //断开事件
            //ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            weather_data_size = 0;
            break;
        case HTTP_EVENT_REDIRECT:
            //ESP_LOGI(TAG, "HTTP_EVENT_REDIRECT");
            break;
    }
    
    return ESP_OK;
}

// //天气json包解析函数
// static esp_err_t pasre_weather(char* weather_js)
// {
    
//     cJSON *wt_js = cJSON_Parse(weather_js);
//     if(!wt_js)
//     {
//         ESP_LOGI(TAG,"Invaild weather json");
//         return ESP_FAIL;
//     }
//     cJSON *result_js = cJSON_GetObjectItem(wt_js, "results");   //根据results名称去找到成员
//     if(!result_js)  //是否成功获取到
//     {
//         ESP_LOGI(TAG,"Invaild weather results");
//         return ESP_FAIL;
//     }
//     cJSON *result_child_js = result_js->child;  //引用child就可以获取数组成员的第一个对象
//     weather_data_pkt_t weather_data_pkt[3];     //存储三个天气数据的结构体数组 
//     char city[48];  //城市名（中文字符）
//     int index = 0;  //用来索引数组的下标

//     //在心知天气中直接获取到城市位置
//     cJSON *location_js = cJSON_GetObjectItem(result_child_js, "location");
//     cJSON *name_js = cJSON_GetObjectItem(location_js, "name");  //获取到城市的位置名字
//     if(name_js)
//     {
//         snprintf(city, sizeof(city), "%s",cJSON_GetStringValue(name_js));
//         ESP_LOGI(TAG,"city_name:%s",city);
//     }


//     cJSON *daily_js = cJSON_GetObjectItem(result_child_js, "daily");
    
    
//     if(!daily_js)    //获取到daily_js不为null，其内部也是一个数组
//     {
//         cJSON* daily_child_js = daily_js->child;    //获取到第一个成员
//         while (daily_child_js) 
//         {
//             //基于json获取其中需要的成员
//             cJSON *high_js = cJSON_GetObjectItem(daily_child_js, "high");
//             cJSON *low_js = cJSON_GetObjectItem(daily_child_js, "low");
//             cJSON *code_js = cJSON_GetObjectItem(daily_child_js, "code_day");
//             if(index < 3)
//             {
//                 sscanf(cJSON_GetStringValue(high_js), "%d",&weather_data_pkt[index].high_temp); //获取字符串类型，再将其转化为整型，存储到数组数组
//                 sscanf(cJSON_GetStringValue(low_js), "%d",&weather_data_pkt[index].low_temp);   
//                 snprintf(weather_data_pkt[index].code, sizeof(weather_data_pkt[index].code), "%s", cJSON_GetStringValue(code_js));
//                 ESP_LOGI(TAG,"day[%d]->high temp:%d,low temp:%d,day_code:%s",index,weather_data_pkt[index].high_temp,weather_data_pkt[index].low_temp,weather_data_pkt[index].code);
//             }
//             index+=1;
//             daily_child_js = daily_child_js->next; //像链表操作一样指向下一个child
//         }
//         // 设置到显示界面中去
//         //设置城市显示
//         set_home_city(&guider_ui, city);
//         //设置天气图标和天气最低-最高温度
//         char img_path[32];  //图片路径
//         snprintf(img_path, sizeof(img_path), "/img/%s/@1x.png",weather_data_pkt[0].code);
//         set_today_img(&guider_ui,img_path,weather_data_pkt[0].low_temp,weather_data_pkt[0].high_temp);
//         snprintf(img_path, sizeof(img_path), "/img/%s/@1x.png",weather_data_pkt[1].code);
//         set_tomorrow_img(&guider_ui,img_path,weather_data_pkt[1].low_temp,weather_data_pkt[1].high_temp);
//         snprintf(img_path, sizeof(img_path), "/img/%s/@1x.png",weather_data_pkt[2].code);
//         set_after_img(&guider_ui,img_path,weather_data_pkt[2].low_temp,weather_data_pkt[2].high_temp);
//     }
//     cJSON_Delete(wt_js);
//     return ESP_OK;
// }
// static esp_err_t parse_weather(char* weather_js);
/** 解析返回的天气数据
 * @param json数据
 * @return ESP_OK or ESP_FAIL
*/
static esp_err_t parse_weather(char* weather_js)
{
    cJSON *wt_js = cJSON_Parse(weather_js);
    if(!wt_js)
    {
        ESP_LOGI(TAG,"invaild json format");
        return ESP_FAIL;
    }
    cJSON *result_js = cJSON_GetObjectItem(wt_js,"results");
    if(!result_js)
    {
        ESP_LOGI(TAG,"非法结果,请查看私钥释放正确!");
        return ESP_FAIL;
    }
    cJSON *result_child_js = result_js->child;
    weather_data_pkt_t  weather_data[3];
    char city_name[32] = {0};
    int index = 0;
    while(result_child_js)
    {
        cJSON *location_js = cJSON_GetObjectItem(result_child_js,"location");
        cJSON *cityname_js = NULL;
        if(location_js)
        {
            cityname_js = cJSON_GetObjectItem(location_js,"name");
            if(cityname_js)
            {
                snprintf(city_name,sizeof(city_name),"%s",cJSON_GetStringValue(cityname_js));
            }
        }
        cJSON *daily_js = cJSON_GetObjectItem(result_child_js,"daily");
        if(daily_js)
        {
            cJSON *daily_child_js = daily_js->child;
            while(daily_child_js)
            {
                cJSON* date_js = cJSON_GetObjectItem(daily_child_js,"date");
                cJSON* code_day = cJSON_GetObjectItem(daily_child_js,"code_day");
                cJSON* code_night = cJSON_GetObjectItem(daily_child_js,"code_night");
                cJSON* high_js = cJSON_GetObjectItem(daily_child_js,"high");
                cJSON* low_js = cJSON_GetObjectItem(daily_child_js,"low");
                if(index < 3)
                {
                    snprintf(weather_data[index].date,16,"%s",cJSON_GetStringValue(date_js));
                    snprintf(weather_data[index].code_day,4,"%s",cJSON_GetStringValue(code_day));
                    snprintf(weather_data[index].code_night,4,"%s",cJSON_GetStringValue(code_night));
                    sscanf(cJSON_GetStringValue(high_js),"%d",&weather_data[index].high_temp);
                    sscanf(cJSON_GetStringValue(low_js),"%d",&weather_data[index].low_temp);
                }
                index++;
                daily_child_js = daily_child_js->next;
            }
            //调用显示接口，把天气信息设置到LVGL里面去
            set_home_city(&guider_ui,city_name);
            char img_path[32];
            snprintf(img_path,sizeof(img_path),"/img/%s@1x.png",weather_data[0].code_day);
            set_today_img(&guider_ui,img_path,weather_data[0].low_temp,weather_data[0].high_temp);

            snprintf(img_path,sizeof(img_path),"/img/%s@1x.png",weather_data[1].code_day);
            set_tomorrow_img(&guider_ui,img_path,weather_data[1].low_temp,weather_data[1].high_temp);

            snprintf(img_path,sizeof(img_path),"/img/%s@1x.png",weather_data[2].code_day);
            set_after_img(&guider_ui,img_path,weather_data[2].low_temp,weather_data[2].high_temp);
        }
        result_child_js = result_child_js->next;
    }
    cJSON_Delete(wt_js);
    return ESP_OK;
}

static esp_err_t weather_http_connect(void)
{
    static char url[256];
    snprintf(url,sizeof(url),
    "http://api.seniverse.com/v3/weather/daily.json?key=%s&location=%s&language=zh-Hans&unit=c&start=0&days=3",
    WHEATER_PRIVATE_KEY,city_name);
    esp_http_client_config_t config =
    {
        .url = url,
        .event_handler = _weather_http_client_event_handler,
    };
    //初始化结构体
    esp_http_client_handle_t http_client = esp_http_client_init(&config);	//初始化http连接
    memset(weather_data_buff, 0, WEATHER_BUFF_LEN); //清空weather_buff数据
    weather_data_size = 0;  //接收到的数据长度也清0
    esp_err_t err  = esp_http_client_perform(http_client);  //全部数据接收到后此函数才会返回，其会阻塞
    parse_weather((char*)weather_data_buff);
    esp_http_client_cleanup(http_client);
    return err;
}



//解析城市地址json数据的函数
static esp_err_t pasre_location(char* location_data)
{
    cJSON *location_js = cJSON_Parse(location_data);    //获取JSON对象树
    if(!location_js)
    {
        if (!location_js)
        {
            ESP_LOGI(TAG,"Invaild location json");
            return ESP_FAIL;
        }
    }
    cJSON *city_js = cJSON_GetObjectItem(location_js, "city");
    if (!city_js)
    {
        ESP_LOGI(TAG, "Invaild location city");
        return ESP_FAIL;
    }
    snprintf(city_name, sizeof(city_name), "%s",cJSON_GetStringValue(city_js)); //格式化赋值字符串数组
    ESP_LOGI(TAG, "location->city name:%s",city_name);  //打印城市信息
    cJSON_Delete(location_js);  //使用Parese生成的JSON树在后续需要释放
    return ESP_OK;
}

//连接到读取城市信息网站的函数
static esp_err_t location_http_connect(void)
{
    static char url[256];
    snprintf(url,sizeof(url),
    "http://ip-api.com/json/?lang=en");
    esp_http_client_config_t config =
    {
        .url = url,
        .event_handler = _weather_http_client_event_handler,
    };
    //初始化结构体
    esp_http_client_handle_t http_client = esp_http_client_init(&config);	//初始化http连接
    memset(weather_data_buff, 0, WEATHER_BUFF_LEN); //清空weather_buff数据
    weather_data_size = 0;  //接收到的数据长度也清0
    esp_err_t err  = esp_http_client_perform(http_client);  //全部数据接收到后此函数才会返回，其会阻塞
    pasre_location((char*)weather_data_buff);
    esp_http_client_cleanup(http_client);   //关闭清理http
    return err;
}

static void weather_task(void* param)
{
    while (1)
    {
        if (!wifi_manager_is_connect())     //是否联网
        {
            vTaskDelay(pdMS_TO_TICKS(2000));
        }
        else 
        {
            location_http_connect();
            weather_http_connect();
            vTaskDelay(pdMS_TO_TICKS(1000*1800));   //延时半个小时
        }
    }
}

//对外的接口函数
void weather_start(void)
{
    xTaskCreatePinnedToCore(weather_task,"weather_task", 4096, NULL, 2, NULL, 1);
}
