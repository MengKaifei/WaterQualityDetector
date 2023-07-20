#ifndef __SERIAL_H__
#define __SERIAL_H__
#include "stm32f4xx.h"                  // Device header
#include <stdio.h>

extern uint8_t USART2_BUF[8];

void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
	
void USART2_Init(void);	
uint8_t USART2_CheckPack(void);	
void USART2_SendByte(uint8_t Byte);
void USART2_SendPack(uint8_t Command,uint16_t DATA1,uint16_t DATA2);
	
#endif
