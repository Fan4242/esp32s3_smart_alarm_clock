#pragma once
#include "xl9555.h"

//xl9555的引脚
#define XL9555_SDA      GPIO_NUM_10
#define XL9555_SCL      GPIO_NUM_11
#define XL9555_INT      GPIO_NUM_17

//audio的I2S相关引脚
#define AUDIO_BCLK_IO   GPIO_NUM_46
#define AUDIO_WS_IO     GPIO_NUM_9 
#define AUDIOS_DOUT_IO  GPIO_NUM_8
#define SPK_EN_IO       IO0_0

//LCD相关的引脚
#define LCD_RSR_IO      IO1_3
#define LCD_BL_IO       IO1_2