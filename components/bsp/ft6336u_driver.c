#include "ft6336u_driver.h"
#include "esp_log.h"
#include "driver/i2c_master.h"

#define TAG "ft6336u"

static i2c_master_bus_handle_t ft6336u_bus_handle = NULL;
static i2c_master_dev_handle_t ft6336u_dev_handle = NULL;
static bool ft6336u_int_flag = false;

esp_err_t ft6336u_driver(gpio_num_t sda,gpio_num_t scl)
{
    /*配置i2c总线 i2c总线初始化*/
    i2c_master_bus_config_t bus_config = 
    {
        .clk_source = I2C_CLK_SRC_DEFAULT,  //使用默认时钟，40M的晶振
        .sda_io_num = sda,
        .scl_io_num = scl,
        .glitch_ignore_cnt = 7,     //滤波作用，典型值为7，如果i2c总线上出现小于7个时钟周期的脉冲就会被过滤掉
        .i2c_port = -1, //给我们自动选择没有用的i2c端口号
    };
    i2c_new_master_bus(&bus_config,&ft6336u_bus_handle);

    //添加触摸芯片设备到i2c总线
    /*i2c设备配置*/
    i2c_device_config_t dev_config = 
    {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,     //7位的i2c地址
        .device_address = 0x38,     //i2c器件地址，芯片的地址为0x38
        .scl_speed_hz = 400*1000,   //scl的频率,i2c的快速模式
    };
    i2c_master_bus_add_device(ft6336u_bus_handle,&dev_config,&ft6336u_dev_handle);      //添加i2c设备并获得设备操作句柄
    
    uint8_t read_buf[1];
    uint8_t write_buf[2];
    esp_err_t ret = ESP_FAIL;
    write_buf[0] = 0xA3;        //读厂商ID的寄存器地址
    /* 读取厂商ID寄存器的值，看看器件是否有问题 */
    ret = i2c_master_transmit_receive(ft6336u_dev_handle,&write_buf[0],1,&read_buf[0],1,1000);
    if(ret != ESP_OK)
    {
        return ret;
    } 
    write_buf[0] = 0xA4;        //第一个是寄存器地址
    write_buf[1] = 0x00;        //第二个是要写入什么值 ,这里是设置中断模式为中断查询模式
    ret = i2c_master_transmit(ft6336u_dev_handle,&write_buf[0],2,1000);
    return ret;
}

void ft6336u_read(int16_t *x,int16_t *y,int *state)
{
    uint8_t read_buf[5];
    uint8_t write_buf[1];
    static int16_t last_x = 0;
    static int16_t last_y = 0;
    if(!ft6336u_int_flag)   //如果判断到没有触摸点被按下则不需要再执行之后的读操作了，节省系统的资源
    {
        *x = last_x;
        *y = last_y;
        *state = 0;
        return;
    }
    write_buf[0] = 0x02;
    i2c_master_transmit_receive(ft6336u_dev_handle,&write_buf[0],1,&read_buf[0],5,500);
    if((read_buf[0] & 0x0f) != 1)
    {
        *x = last_x;
        *y = last_y;
        *state = 0;
        return;
    }
    int16_t current_x = ((read_buf[1]&0x0F)<<8) | read_buf[2];  //x坐标值
    int16_t current_y = ((read_buf[3]&0x0F)<<8) | read_buf[4];  //y坐标值
    last_x = current_x;
    last_y = current_y;
    *x = current_x;
    *y = current_y;
    *state = 1;
}

void ft6336u_int_info(bool flag)
{
    ft6336u_int_flag = flag;
}