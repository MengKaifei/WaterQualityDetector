/*
 * dcmotor.c
 *
 * created: 2023-07-06
 *  author: 
 */
#include "dcmotor.h"

int dcmotor_Current_Status = DCMOTOR_STATE_STOP;

// �����ʼ��
void dcmotor_Init(void)
{
    gpio_enable(DC_X_C1,DIR_OUT);
    gpio_enable(DC_X_C2,DIR_OUT);

    gpio_write(DC_X_C1, ON);
    gpio_write(DC_X_C2, ON);
}

// �����ת
void dcmotor_Positive(void)
{
    gpio_write(DC_X_C1,ON);
    gpio_write(DC_X_C2,OFF);
    dcmotor_Current_Status = DCMOTOR_STATE_POS;
}

// �����ת
void dcmotor_Reverse(void)
{
    gpio_write(DC_X_C1,OFF);
    gpio_write(DC_X_C2,ON);
    dcmotor_Current_Status = DCMOTOR_STATE_DEV;
}

// ���ֹͣ
void dcmotor_Stop(void)
{
    gpio_write(DC_X_C1, ON);
    gpio_write(DC_X_C2, ON);
    dcmotor_Current_Status = DCMOTOR_STATE_STOP;
}
