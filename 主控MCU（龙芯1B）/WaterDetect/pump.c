/*
 * pump.c
 *
 * created: 2023-07-08
 *  author: 
 */
#include "pump.h"

// 水泵初始化
void pump_Init(void)
{
    gpio_enable(PUMP_1,DIR_OUT);
    gpio_enable(PUMP_2,DIR_OUT);
    gpio_enable(PUMP_3,DIR_OUT);
    gpio_enable(PUMP_4,DIR_OUT);

    gpio_write(PUMP_1,OFF);
    gpio_write(PUMP_2,OFF);
    gpio_write(PUMP_3,OFF);
    gpio_write(PUMP_4,OFF);
}

// 设置水泵运行（mode为水泵序号）
void set_Pump_Start(int mode)
{
    switch (mode)
    {
    case 1:
        gpio_write(PUMP_1,ON);
        break;
    
    case 2:
        gpio_write(PUMP_2,ON);
        break;
    
    case 3:
        gpio_write(PUMP_3,ON);
        break;
    
    case 4:
        gpio_write(PUMP_4,ON);
        break;
    
    default:
        break;
    }
}

// 设置水泵停止（mode为水泵序号）
void set_Pump_Stop(int mode)
{
    switch (mode)
    {
    case 1:
        gpio_write(PUMP_1,OFF);
        break;
    
    case 2:
        gpio_write(PUMP_2,OFF);
        break;
    
    case 3:
        gpio_write(PUMP_3,OFF);
        break;
    
    case 4:
        gpio_write(PUMP_4,OFF);
        break;
    
    default:
        break;
    }
}
