#ifndef _WEATHER_H_
#define _WEATHER_H_

// //存储从心知天气中获取到的数据
// typedef struct
// {
//     int high_temp;      //当天的最高气温
//     int low_temp;       //当天的最低气温
//     char code[4];       //图片代码
// }weather_data_pkt_t;

typedef struct
{
    char date[16];
    int high_temp;
    int low_temp;
    char code_day[4];
    char code_night[4];
}weather_data_pkt_t;


void weather_start(void);

#endif