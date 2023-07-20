#ifndef _UART_H
#define _UART_H

#include <stdint.h>
#include "ls1b.h"
#include "ls1b_gpio.h"
#include "ns16550.h"
#include "stdio.h"
#include "string.h"

// ����״̬�궨��
#define UART_YES    1
#define UART_NO     0

// ��������������ָ��궨��
#define DISPLAY_NO_RES          0x00
#define DISPLAY_STOP_CLIKED     0x01
#define DISPLAY_START_CLIKED    0x02
#define DISPLAY_TIMER_CLIKED    0x03

// �������ݳ���
#define DISPLAY_LIGHT_DATA_LEN 290

extern int getPH_Current_Status;    // PHֵ��ȡ�жϱ�־λ
extern int getTem_Current_Status;   // �¶�ֵ��ȡ�жϱ�־λ
extern int getTur_Current_Status;   // ���Ƕ�ֵ��ȡ�жϱ�־λ

void send_ph_value(double ph);      // ����PHֵ����
void send_temp_value(double temp);  // �����¶�����
void send_tre_value(double tre);    // ���ͻ��Ƕ�����
void send_light_data(uint8_t light_data[DISPLAY_LIGHT_DATA_LEN]);   // ���͹�������

extern char buff[8];
extern unsigned char data1;
extern unsigned char data2;
extern unsigned char data3;
extern unsigned char data4;

extern unsigned char PH_Data[8];   // PH����ͨ��Э������
extern unsigned char Tem_Data[8];  // �¶Ȳ���ͨ��Э������
extern unsigned char Tur_Data[8];  // ���ǶȲ���ͨ��Э������

void UART1_Config_Init(void);           // ����1��ʼ��
unsigned int UART1_Read(void);          // ����1���ݶ�ȡ
void UART1_Send(unsigned char ch[]);    // ����1��������
void UART4_Config_Init(void);           // ����4��ʼ��
unsigned int UART4_Read(void);          // ����4���ݶ�ȡ

extern uint8_t light_Data[DISPLAY_LIGHT_DATA_LEN];

#endif // _UART_H
