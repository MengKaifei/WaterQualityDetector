/*
 * limit.c
 *
 * created: 2023-07-09
 *  author: 
 */

#include "limit.h"

void Limit_Init(void)
{
    gpio_enable(LIMIT_KEY_1,DIR_IN);
    gpio_enable(LIMIT_KEY_2,DIR_IN);
}

int Limit_Scan(void)
{
    if (gpio_read(LIMIT_KEY_1) == OFF)
    {
        delay_ms(30);
        if (gpio_read(LIMIT_KEY_1) == OFF)
        {
            return 1;
        }
    }
    if (gpio_read(LIMIT_KEY_2) == OFF)
    {
        delay_ms(30);
        if (gpio_read(LIMIT_KEY_2) == OFF)
        {
            return 2;
        }
    }

    return 0;
}
