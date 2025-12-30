/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"                    // 先包含 lvgl.h，确保所有类型定义可用
#include "custom.h"
#include "esp_lvgl_port.h"


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */
extern int screen_home_digital_clock_now_hour_value;
extern int screen_home_digital_clock_now_min_value;
extern int screen_home_digital_clock_now_sec_value;

int screen_home_digital_clock_now_year_value;
int screen_home_digital_clock_now_month_value;
int screen_home_digital_clock_now_day_value;
int screen_home_digital_clock_now_w_day_value;

//设置日期以及时间到LVGL页面的函数（内部没有实现时间更新）
void set_home_time(lv_ui* ui,int year,int month,int day,int w_day,int hour,int min,int sec)
{
    screen_home_digital_clock_now_hour_value = hour;
    screen_home_digital_clock_now_min_value = min;
    screen_home_digital_clock_now_sec_value = sec;
    screen_home_digital_clock_now_year_value = year;
    screen_home_digital_clock_now_month_value = month;
    screen_home_digital_clock_now_day_value = day;
    screen_home_digital_clock_now_w_day_value = w_day;

    char text[64];
    snprintf(text,sizeof(text),"%d年%d月%d日",year,month,day);

    char week_text[64];
    static const char* week_day_text[] = 
    {
        "星期日",
        "星期一",
        "星期二",
        "星期三",
        "星期四",
        "星期五",
        "星期六",
    };  
    snprintf(week_text,sizeof(week_text),"%s",week_day_text[w_day]);
    lvgl_port_lock(0);   //进行加锁
    lv_label_set_text(ui->screen_home_label_week,week_text);
    lv_label_set_text(ui->screen_home_label_day,text);
    lvgl_port_unlock();
}

void set_today_img(lv_ui* ui,const char* img_path,int low,int high)
{
    char temp_text[32];
    lvgl_port_lock(0);   //进行加锁
    lv_img_set_src(ui->screen_home_img_today,img_path); //如果传路径进去的话，会调用C语言标准的文件操作
    snprintf(temp_text, sizeof(temp_text), "%d-%d℃",low,high);
    lv_label_set_text(ui->screen_home_label_temple1, temp_text);
    lvgl_port_unlock();
}
void set_tomorrow_img(lv_ui* ui,const char* img_path,int low,int high)
{
    char temp_text[32];
    lvgl_port_lock(0);   //进行加锁
    lv_img_set_src(ui->screen_home_img_tomorrow,img_path); //如果传路径进去的话，会调用C语言标准的文件操作
    snprintf(temp_text, sizeof(temp_text), "%d-%d℃",low,high);
    lv_label_set_text(ui->screen_home_label_temple2, temp_text);
    lvgl_port_unlock();
}
void set_after_img(lv_ui* ui,const char* img_path,int low,int high)
{
    char temp_text[32];
    lvgl_port_lock(0);   //进行加锁
    lv_img_set_src(ui->screen_home_img_after,img_path); //如果传路径进去的话，会调用C语言标准的文件操作
    snprintf(temp_text, sizeof(temp_text), "%d-%d℃",low,high);
    lv_label_set_text(ui->screen_home_label_temple3, temp_text);
    lvgl_port_unlock();
}

//设置显示城市
void set_home_city(lv_ui* ui,const char* city)
{
    char city_text[32];
    lvgl_port_lock(0);   //进行加锁
    snprintf(city_text, sizeof(city_text), "%s",city);
    lv_label_set_text(ui->screen_home_label_city, city_text);
    lvgl_port_unlock();
}

//显示意见参数
void set_monitor_param(lv_ui* ui,int cpu_rate,int cpu_temp,int men_rate,int men_use)
{
    char value[16]; //要显示的值
    lvgl_port_lock(0);   //进行加锁
    
    //CPU rate
    snprintf(value, sizeof(value), "%d%%",cpu_rate);
    lv_label_set_text(ui->screen_monitor_label_cpu_value1, value);
    //CPU temp
    snprintf(value, sizeof(value), "%d℃",cpu_temp);
    lv_label_set_text(ui->screen_monitor_label_cpu_value2, value);
    //MEM rate
    snprintf(value, sizeof(value), "%d%%",men_rate);
    lv_label_set_text(ui->screen_monitor_label_men_value1, value);
    //MEM use
    snprintf(value, sizeof(value), "%dMB",men_use);
    lv_label_set_text(ui->screen_monitor_label_men_value2, value);

    lvgl_port_unlock();
}
//设置连接状态
void set_monitor_connect_status(lv_ui* ui,bool flag)
{
    lvgl_port_lock(0);   //进行加锁
    //断开状态
    if(!flag)
    {
        lv_label_set_text(ui->screen_monitor_label_staus, "未连接");
        lv_label_set_text(ui->screen_monitor_btn_connect_label, "连接");
    }
    //连接状态
    else 
    {
        lv_label_set_text(ui->screen_monitor_label_staus, "已连接");
        lv_label_set_text(ui->screen_monitor_btn_connect_label, "断开");
    }
    lvgl_port_unlock();
}

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

