#ifndef __LED_H__
#define __LED_H__

#include "stm32f4xx.h"                  // Device header

#define  LED1  *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOF->ODR - 0x40000000)*32+9*4)
#define  LED2  *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOF->ODR - 0x40000000)*32+10*4)

#define LED1_Port  GPIOF
#define LED1_Pin   GPIO_Pin_9
#define LED1_CLK   RCC_AHB1Periph_GPIOF

#define LED2_Port  GPIOF
#define LED2_Pin   GPIO_Pin_10
#define LED2_CLK   RCC_AHB1Periph_GPIOF

void LED_Init(void);
void LED_Toggle(uint16_t LED_Pin);

#endif
