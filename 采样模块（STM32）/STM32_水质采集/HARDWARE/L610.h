#ifndef __L610_H__
#define __L610_H__
#include "stm32f4xx.h"                  // Device header

extern unsigned char _4G_BUF[300];
extern uint8_t Rx_p;

void L610_Init(void);
void L610_SendData(char * Addr,char * Data);
void _LCD_Show4GBUF(uint8_t*_4G_BUF,uint8_t Len);

#endif

