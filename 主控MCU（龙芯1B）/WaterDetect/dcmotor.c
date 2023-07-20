/*
 * dcmotor.c
 *
 * created: 2023-07-06
 *  author: 
 */
#include "dcmotor.h"

int dcmotor_Current_Status = DCMOTOR_STATE_STOP;

// 电机初始化
void dcmotor_Init(void)
{
    gpio_enable(DC_X_C1,DIR_OUT);
    gpio_enable(DC_X_C2,DIR_OUT);

    gpio_write(DC_X_C1, ON);
    gpio_write(DC_X_C2, ON);
}

// 电机正转
void dcmotor_Positive(void)
{
    gpio_write(DC_X_C1,ON);
    gpio_write(DC_X_C2,OFF);
    dcmotor_Current_Status = DCMOTOR_STATE_POS;
}

// 电机反转
void dcmotor_Reverse(void)
{
    gpio_write(DC_X_C1,OFF);
    gpio_write(DC_X_C2,ON);
    dcmotor_Current_Status = DCMOTOR_STATE_DEV;
}

// 电机停止
void dcmotor_Stop(void)
{
    gpio_write(DC_X_C1, ON);
    gpio_write(DC_X_C2, ON);
    dcmotor_Current_Status = DCMOTOR_STATE_STOP;
}
