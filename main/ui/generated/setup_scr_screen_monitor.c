/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_monitor(lv_ui *ui)
{
    //Write codes screen_monitor
    ui->screen_monitor = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_monitor, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_monitor, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_monitor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_cont_cpu
    ui->screen_monitor_cont_cpu = lv_obj_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_cont_cpu, 12, 19);
    lv_obj_set_size(ui->screen_monitor_cont_cpu, 140, 110);
    lv_obj_set_scrollbar_mode(ui->screen_monitor_cont_cpu, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_monitor_cont_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_cont_cpu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_monitor_cont_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_monitor_cont_cpu, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_monitor_cont_cpu, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_cont_cpu, 156, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_cont_cpu, lv_color_hex(0x3d72ad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_cont_cpu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_cpu_title
    ui->screen_monitor_label_cpu_title = lv_label_create(ui->screen_monitor_cont_cpu);
    lv_obj_set_pos(ui->screen_monitor_label_cpu_title, 8, 5);
    lv_obj_set_size(ui->screen_monitor_label_cpu_title, 117, 35);
    lv_label_set_text(ui->screen_monitor_label_cpu_title, "CPU");
    lv_label_set_long_mode(ui->screen_monitor_label_cpu_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_cpu_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_cpu_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_cpu_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_cpu_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_cpu_title, &lv_font_ZiTiQuanWeiJunHeiW22_36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_cpu_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_cpu_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_cpu_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_cpu_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_cpu_title, 188, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_label_cpu_title, lv_color_hex(0x0235a9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_label_cpu_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_cpu_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_cpu_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_cpu_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_cpu_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_cpu_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_cpu_used
    ui->screen_monitor_label_cpu_used = lv_label_create(ui->screen_monitor_cont_cpu);
    lv_obj_set_pos(ui->screen_monitor_label_cpu_used, 8, 50);
    lv_obj_set_size(ui->screen_monitor_label_cpu_used, 77, 20);
    lv_label_set_text(ui->screen_monitor_label_cpu_used, "使用率：");
    lv_label_set_long_mode(ui->screen_monitor_label_cpu_used, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_cpu_used, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_cpu_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_cpu_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_cpu_used, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_cpu_used, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_cpu_used, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_cpu_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_cpu_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_cpu_used, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_cpu_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_cpu_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_cpu_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_cpu_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_cpu_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_cpu_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_cpu_temp
    ui->screen_monitor_label_cpu_temp = lv_label_create(ui->screen_monitor_cont_cpu);
    lv_obj_set_pos(ui->screen_monitor_label_cpu_temp, 8, 79);
    lv_obj_set_size(ui->screen_monitor_label_cpu_temp, 77, 20);
    lv_label_set_text(ui->screen_monitor_label_cpu_temp, "温度：");
    lv_label_set_long_mode(ui->screen_monitor_label_cpu_temp, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_cpu_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_cpu_temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_cpu_temp, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_cpu_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_cpu_temp, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_cpu_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_cpu_value1
    ui->screen_monitor_label_cpu_value1 = lv_label_create(ui->screen_monitor_cont_cpu);
    lv_obj_set_pos(ui->screen_monitor_label_cpu_value1, 92, 49);
    lv_obj_set_size(ui->screen_monitor_label_cpu_value1, 39, 20);
    lv_label_set_text(ui->screen_monitor_label_cpu_value1, "80%");
    lv_label_set_long_mode(ui->screen_monitor_label_cpu_value1, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_cpu_value1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_cpu_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_cpu_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_cpu_value1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_cpu_value1, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_cpu_value1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_cpu_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_cpu_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_cpu_value1, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_cpu_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_cpu_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_cpu_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_cpu_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_cpu_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_cpu_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_cpu_value2
    ui->screen_monitor_label_cpu_value2 = lv_label_create(ui->screen_monitor_cont_cpu);
    lv_obj_set_pos(ui->screen_monitor_label_cpu_value2, 92, 77);
    lv_obj_set_size(ui->screen_monitor_label_cpu_value2, 39, 20);
    lv_label_set_text(ui->screen_monitor_label_cpu_value2, "50℃");
    lv_label_set_long_mode(ui->screen_monitor_label_cpu_value2, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_cpu_value2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_cpu_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_cpu_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_cpu_value2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_cpu_value2, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_cpu_value2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_cpu_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_cpu_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_cpu_value2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_cpu_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_cpu_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_cpu_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_cpu_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_cpu_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_cpu_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_ta_ip
    ui->screen_monitor_ta_ip = lv_textarea_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_ta_ip, 59, 143);
    lv_obj_set_size(ui->screen_monitor_ta_ip, 179, 33);
    lv_textarea_set_text(ui->screen_monitor_ta_ip, "192.168.100.123");
    lv_textarea_set_placeholder_text(ui->screen_monitor_ta_ip, "");
    lv_textarea_set_password_bullet(ui->screen_monitor_ta_ip, "*");
    lv_textarea_set_password_mode(ui->screen_monitor_ta_ip, false);
    lv_textarea_set_one_line(ui->screen_monitor_ta_ip, true);
    lv_textarea_set_accepted_chars(ui->screen_monitor_ta_ip, "");
    lv_textarea_set_max_length(ui->screen_monitor_ta_ip, 34);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_monitor_ta_ip, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_monitor_ta_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_monitor_ta_ip, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_ta_ip, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_ta_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_ta_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_ta_ip, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_ta_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_ta_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_ta_ip, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_monitor_ta_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_monitor_ta_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_monitor_ta_ip, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_monitor_ta_ip, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_ta_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_ta_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_ta_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_ta_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_ta_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_monitor_ta_ip, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_monitor_ta_ip, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_ta_ip, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_ta_ip, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_ta_ip, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_monitor_btn_connect
    ui->screen_monitor_btn_connect = lv_button_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_btn_connect, 247, 151);
    lv_obj_set_size(ui->screen_monitor_btn_connect, 67, 25);
    ui->screen_monitor_btn_connect_label = lv_label_create(ui->screen_monitor_btn_connect);
    lv_label_set_text(ui->screen_monitor_btn_connect_label, "连接");
    lv_label_set_long_mode(ui->screen_monitor_btn_connect_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_monitor_btn_connect_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_monitor_btn_connect, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_monitor_btn_connect_label, LV_PCT(100));

    //Write style for screen_monitor_btn_connect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_monitor_btn_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_btn_connect, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_btn_connect, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_monitor_btn_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_btn_connect, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_btn_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_btn_connect, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_btn_connect, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_btn_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_btn_connect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_host
    ui->screen_monitor_label_host = lv_label_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_label_host, 8, 153);
    lv_obj_set_size(ui->screen_monitor_label_host, 58, 20);
    lv_label_set_text(ui->screen_monitor_label_host, "主机：");
    lv_label_set_long_mode(ui->screen_monitor_label_host, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_host, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_host, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_host, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_host, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_host, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_staus
    ui->screen_monitor_label_staus = lv_label_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_label_staus, 59, 192);
    lv_obj_set_size(ui->screen_monitor_label_staus, 85, 24);
    lv_label_set_text(ui->screen_monitor_label_staus, "未连接");
    lv_label_set_long_mode(ui->screen_monitor_label_staus, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_staus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_staus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_staus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_staus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_staus, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_staus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_staus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_staus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_staus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_staus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_staus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_staus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_staus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_staus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_staus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_cont_men
    ui->screen_monitor_cont_men = lv_obj_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_cont_men, 169, 19);
    lv_obj_set_size(ui->screen_monitor_cont_men, 140, 110);
    lv_obj_set_scrollbar_mode(ui->screen_monitor_cont_men, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_monitor_cont_men, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_cont_men, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_monitor_cont_men, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_monitor_cont_men, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_monitor_cont_men, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_cont_men, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_cont_men, 156, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_cont_men, lv_color_hex(0x3d72ad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_cont_men, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_cont_men, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_cont_men, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_cont_men, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_cont_men, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_cont_men, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_mem_title
    ui->screen_monitor_label_mem_title = lv_label_create(ui->screen_monitor_cont_men);
    lv_obj_set_pos(ui->screen_monitor_label_mem_title, 9, 3);
    lv_obj_set_size(ui->screen_monitor_label_mem_title, 117, 38);
    lv_label_set_text(ui->screen_monitor_label_mem_title, "内存");
    lv_label_set_long_mode(ui->screen_monitor_label_mem_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_mem_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_mem_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_mem_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_mem_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_mem_title, &lv_font_ZiTiQuanWeiJunHeiW22_36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_mem_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_mem_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_mem_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_mem_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_mem_title, 200, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_label_mem_title, lv_color_hex(0xc47d00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_label_mem_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_mem_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_mem_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_mem_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_mem_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_mem_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_mem_used
    ui->screen_monitor_label_mem_used = lv_label_create(ui->screen_monitor_cont_men);
    lv_obj_set_pos(ui->screen_monitor_label_mem_used, 8, 48);
    lv_obj_set_size(ui->screen_monitor_label_mem_used, 77, 20);
    lv_label_set_text(ui->screen_monitor_label_mem_used, "使用率：");
    lv_label_set_long_mode(ui->screen_monitor_label_mem_used, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_mem_used, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_mem_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_mem_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_mem_used, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_mem_used, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_mem_used, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_mem_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_mem_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_mem_used, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_mem_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_mem_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_mem_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_mem_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_mem_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_mem_used, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_mem_valid
    ui->screen_monitor_label_mem_valid = lv_label_create(ui->screen_monitor_cont_men);
    lv_obj_set_pos(ui->screen_monitor_label_mem_valid, 9, 79);
    lv_obj_set_size(ui->screen_monitor_label_mem_valid, 77, 20);
    lv_label_set_text(ui->screen_monitor_label_mem_valid, "可用：");
    lv_label_set_long_mode(ui->screen_monitor_label_mem_valid, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_mem_valid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_mem_valid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_mem_valid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_mem_valid, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_mem_valid, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_mem_valid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_mem_valid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_mem_valid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_mem_valid, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_mem_valid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_mem_valid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_mem_valid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_mem_valid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_mem_valid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_mem_valid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_men_value1
    ui->screen_monitor_label_men_value1 = lv_label_create(ui->screen_monitor_cont_men);
    lv_obj_set_pos(ui->screen_monitor_label_men_value1, 90, 48);
    lv_obj_set_size(ui->screen_monitor_label_men_value1, 39, 20);
    lv_label_set_text(ui->screen_monitor_label_men_value1, "43%");
    lv_label_set_long_mode(ui->screen_monitor_label_men_value1, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_men_value1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_men_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_men_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_men_value1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_men_value1, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_men_value1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_men_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_men_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_men_value1, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_men_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_men_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_men_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_men_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_men_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_men_value1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_men_value2
    ui->screen_monitor_label_men_value2 = lv_label_create(ui->screen_monitor_cont_men);
    lv_obj_set_pos(ui->screen_monitor_label_men_value2, 63, 75);
    lv_obj_set_size(ui->screen_monitor_label_men_value2, 66, 20);
    lv_label_set_text(ui->screen_monitor_label_men_value2, "2450MB");
    lv_label_set_long_mode(ui->screen_monitor_label_men_value2, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_men_value2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_men_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_men_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_men_value2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_men_value2, &lv_customer_font_ZiTiQuanWeiJunHeiW22_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_men_value2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_men_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_men_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_men_value2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_men_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_men_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_men_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_men_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_men_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_men_value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_monitor.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_monitor);

    //Init events for screen.
    events_init_screen_monitor(ui);
}
