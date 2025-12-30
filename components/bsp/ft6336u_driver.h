#ifndef _FT6336U_DRIVER_H_
#define _FT6336U_DRIVER_H_

#include "esp_err.h"
#include "driver/gpio.h"

esp_err_t ft6336u_driver(gpio_num_t sda,gpio_num_t scl);    //初始化i2c及设备函数
void ft6336u_read(int16_t *x,int16_t *y,int *state);
void ft6336u_int_info(bool flag);

#endif