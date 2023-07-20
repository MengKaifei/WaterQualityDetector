#ifndef _UART_H
#define _UART_H

#include <stdint.h>
#include "ls1b.h"
#include "ls1b_gpio.h"
#include "ns16550.h"
#include "stdio.h"
#include "string.h"

// 串口状态宏定义
#define UART_YES    1
#define UART_NO     0

// 串口屏按键触发指令宏定义
#define DISPLAY_NO_RES          0x00
#define DISPLAY_STOP_CLIKED     0x01
#define DISPLAY_START_CLIKED    0x02
#define DISPLAY_TIMER_CLIKED    0x03

// 光谱数据长度
#define DISPLAY_LIGHT_DATA_LEN 290

extern int getPH_Current_Status;    // PH值获取判断标志位
extern int getTem_Current_Status;   // 温度值获取判断标志位
extern int getTur_Current_Status;   // 浑浊度值获取判断标志位

void send_ph_value(double ph);      // 发送PH值数据
void send_temp_value(double temp);  // 发送温度数据
void send_tre_value(double tre);    // 发送浑浊度数据
void send_light_data(uint8_t light_data[DISPLAY_LIGHT_DATA_LEN]);   // 发送光谱数据

extern char buff[8];
extern unsigned char data1;
extern unsigned char data2;
extern unsigned char data3;
extern unsigned char data4;

extern unsigned char PH_Data[8];   // PH采样通信协议数组
extern unsigned char Tem_Data[8];  // 温度采样通信协议数组
extern unsigned char Tur_Data[8];  // 浑浊度采样通信协议数组

void UART1_Config_Init(void);           // 串口1初始化
unsigned int UART1_Read(void);          // 串口1数据读取
void UART1_Send(unsigned char ch[]);    // 串口1发送数据
void UART4_Config_Init(void);           // 串口4初始化
unsigned int UART4_Read(void);          // 串口4数据读取

extern uint8_t light_Data[DISPLAY_LIGHT_DATA_LEN];

#endif // _UART_H
