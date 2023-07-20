/*
 * key.c
 *
 * created: 2023-07-05
 *  author: 
 */
#include "key.h"

int keyValue = 0;

// 板载按键初始化
void key_Init(void)
{
    gpio_enable(KEY_1,DIR_IN);
    gpio_enable(KEY_2,DIR_IN);
    gpio_enable(KEY_3,DIR_IN);
    gpio_enable(KEY_4,DIR_IN);
    
    gpio_write(KEY_1,ON);
    gpio_write(KEY_2,ON);
    gpio_write(KEY_3,ON);
    gpio_write(KEY_4,ON);
}

// 板载按键触发函数
int key_Scan(void)
{
    if (gpio_read(KEY_1) == OFF)
    {
        delay_ms(30);
        if (gpio_read(KEY_1) == OFF)
        {
            return 1;
        }
    }
    if (gpio_read(KEY_2) == OFF)
    {
        delay_ms(30);
        if (gpio_read(KEY_2) == OFF)
        {
            return 2;
        }
    }
    if (gpio_read(KEY_3) == OFF)
    {
        delay_ms(30);
        if (gpio_read(KEY_3) == OFF)
        {
            return 3;
        }
    }
    if (gpio_read(KEY_4) == OFF)
    {
        delay_ms(30);
        if (gpio_read(KEY_4) == OFF)
        {
            return 4;
        }
    }
    
    return 0;
}
