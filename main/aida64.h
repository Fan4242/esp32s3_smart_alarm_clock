#ifndef _AIDA64_H_
#define _AIDA64_H_

typedef struct
{
    int cpu_rata;
    int cpu_temp;
    int mem_rate;
    int mem_use;
} aida64_data_t;

//启动与aida64的通信连接,传入电脑的主机IP地址
void aida64_monitor_start(const char* ip);
//断开与电脑主机的连接
void aida64_monitor_stop(void);
//返回是否与电脑主机连接的状态
int aida64_monitor_isconnect(void);

#endif