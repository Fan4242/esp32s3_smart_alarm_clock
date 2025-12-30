#include "aida64.h"
#include "esp_http_client.h"    //要使用http的客户端模式
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"  //使用事件通知组
#include "custom.h"  

#define TAG "AIDA64"

extern lv_ui guider_ui; 

//连接任务句柄
static TaskHandle_t aida64_task_handle = NULL;
//http访问地址
static char host_aida64_url[128];
//任务函数前向声明
static void aida64_monitor_task(void* param);
//http客户端的操作句柄
static esp_http_client_handle_t http_client = NULL;
//事件组静态变量
static EventGroupHandle_t aida64_event_handle = NULL;
//事件标志位
#define AIDA64_CONNECT_BIT  BIT0
//是否连接标志
static bool is_http_connect = false;

//启动与aida64的通信连接,传入电脑的主机IP地址
void aida64_monitor_start(const char* ip)
{
    //创建一个事件组
    if (aida64_event_handle==NULL)
        aida64_event_handle = xEventGroupCreate();
    //创建连接任务
    if (aida64_task_handle==NULL)
        xTaskCreatePinnedToCore(aida64_monitor_task, "AIDA64", 4096, NULL, 3, &aida64_task_handle,1);
    snprintf(host_aida64_url, sizeof(host_aida64_url), "http://%s:80/sse",ip);
    //设置事件标志组，发起任务
    xEventGroupSetBits(aida64_event_handle, AIDA64_CONNECT_BIT);
}
    
//断开与电脑主机的连接
void aida64_monitor_stop(void)
{
    //关闭http连接，perform函数在此时会返回
    esp_http_client_close(http_client);
}
//返回是否与电脑主机连接的状态
int aida64_monitor_isconnect(void)
{
    return is_http_connect;
}
//aida64数据的解析函数
static bool aida64_monitor_parse(char* data,aida64_data_t* aida64_data)
{
    const char* search_str = NULL;
    if (!data)
        return false;
    //CPU rate提取
    search_str = strstr(data,"CPU rate ");
    if (search_str)
    {
        sscanf(search_str, "%*[^0-9]%d",&aida64_data->cpu_rata);
    }
    else 
        return false;
    //CPU temp
    search_str = strstr(data,"CPU temp ");
    if (search_str)
    {
        sscanf(search_str, "%*[^0-9]%d",&aida64_data->cpu_temp);
    }
    else 
        return false;
    //MEM rate
    search_str = strstr(data,"MEM rate ");
    if (search_str)
    {
        sscanf(search_str, "%*[^0-9]%d",&aida64_data->mem_rate);
    }
    else 
        return false;
    //MEM use
    search_str = strstr(data,"MEM use ");
    if (search_str)
    {
        sscanf(search_str, "%*[^0-9]%d",&aida64_data->mem_use);
    }
    else 
        return false;
    return true;
}

static esp_err_t _aida64_http_client_event_handler(esp_http_client_event_t *evt)
{
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:    //错误事件
            //ESP_LOGI(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:    //连接成功事件
            is_http_connect = true;
            set_monitor_connect_status(&guider_ui,true);
            //ESP_LOGI(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:    //发送头事件
            //ESP_LOGI(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:    //接收头事件
            //ESP_LOGI(TAG, "HTTP_EVENT_ON_HEADER");
            // printf("%.*s", evt->data_len, (char*)evt->data);
            break;
        case HTTP_EVENT_ON_DATA:    //接收数据事件
        {
            ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
            printf("HTTP_EVENT_ON_DATA data=%.*s\r\n", evt->data_len,(char*)evt->data);
            aida64_data_t aida64_data;
            if(aida64_monitor_parse((char*)evt->data, &aida64_data))
            {
                set_monitor_param(&guider_ui, aida64_data.cpu_rata, aida64_data.cpu_temp, aida64_data.mem_rate, aida64_data.mem_use);
            }
            break;
        }
        case HTTP_EVENT_ON_FINISH:    //会话完成事件
            break;
        case HTTP_EVENT_DISCONNECTED:    //断开事件
            //ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            break;
        case HTTP_EVENT_REDIRECT:
            //ESP_LOGI(TAG, "HTTP_EVENT_REDIRECT");
            break;
    }
    
    return ESP_OK;
}

//连接任务
static void aida64_monitor_task(void* param)
{
    esp_http_client_config_t config =
    {
        .url = "http://172.20.10.3:80/sse",
        .event_handler = _aida64_http_client_event_handler,
    };
    //初始化结构体
    http_client = esp_http_client_init(&config);	//初始化http连接
    while (1)
    {
        //esp_err_t err  = esp_http_client_perform(http_client);  //全部数据接收到后此函数才会返回，其会阻塞

        //等待相应的标志位
        EventBits_t ev = xEventGroupWaitBits(aida64_event_handle, AIDA64_CONNECT_BIT, pdTRUE, pdFALSE, pdMS_TO_TICKS(1000));
        //如果等到标志位后就设置url，设置获取方法,设置请求头
        if (ev & AIDA64_CONNECT_BIT)
        {
            esp_http_client_set_url(http_client, host_aida64_url);
            esp_http_client_set_method(http_client, HTTP_METHOD_GET);
            esp_http_client_set_header(http_client, "Accept", "text/event-stream");
            ESP_LOGI(TAG,"http perform");
            //实现一个完整的http连接请求，建立了sse连接之后perform是不会返回的，但是其不会一直去占用时间片，其会等待接收的数据，等待的过程会释放时间片
            esp_http_client_perform(http_client);
            //perform函数返回后说明http连接已经终止
            is_http_connect = false;
            set_monitor_connect_status(&guider_ui,false);
        }
    }
}