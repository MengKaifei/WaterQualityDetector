#ifndef __KEY_H__
#define __KEY_H__
#include "stm32f4xx.h"                  // Device header
#include "Delay.h"

#define KEY_1  *(volatile uint32_t *)(0x42000000 +((uint32_t)&GPIOE->IDR - 0x40000000)*32+2*4)
#define KEY_2  *(volatile uint32_t *)(0x42000000 +((uint32_t)&GPIOE->IDR - 0x40000000)*32+3*4)
#define KEY_3  *(volatile uint32_t *)(0x42000000 +((uint32_t)&GPIOE->IDR - 0x40000000)*32+4*4)



#define KEY_1_Port  GPIOE
#define KEY_1_Pin   GPIO_Pin_2
#define KEY_1_CLK   RCC_AHB1Periph_GPIOE

#define KEY_2_Port  GPIOE
#define KEY_2_Pin   GPIO_Pin_4
#define KEY_2_CLK   RCC_AHB1Periph_GPIOE

#define KEY_3_Port  GPIOE
#define KEY_3_Pin   GPIO_Pin_4
#define KEY_3_CLK   RCC_AHB1Periph_GPIOE


void Key_Init(void);

uint8_t Key_Scan(void);

#endif
