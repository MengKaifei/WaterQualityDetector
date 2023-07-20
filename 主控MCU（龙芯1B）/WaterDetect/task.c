/*
 * task.c
 *
 * created: 2023-07-09
 *  author: 
 */

#include "task.h"

// SA�����ת�Ƕ�
int angle = (360.0/25.0) * (10000.0/360.0);

// ����һȫ�Զ����к���
void Task_Start_1(void)
{
    //-----------------------------�������̿�ʼ---------------------------//

    // DC���������ת
    dcmotor_Positive();
    while (dcmotor_Current_Status != DCMOTOR_STATE_STOP);

    // SA���˳ʱ����ת
    set_Xsamotor(angle,0);
    rt_thread_delay(100);
    while (samotor_Current_Status != SAMOTOR_STATE_STOP)
    {
        rt_thread_delay(100);
    }

    // ����ˮ��2����ˮ����ע����Ʒ
    set_Pump_Start(2);
    delay_ms(30000);
    delay_ms(20000);
    // �ر�ˮ��2
    set_Pump_Stop(2);

    // �����ģ�鷢�Ϳ�ʼPHֵ����ָ��ȴ��ش�����
    UART1_Send(PH_Data);
//    ls1x_uart_write(devUART1,PH_Data,8,NULL);
    while (getPH_Current_Status != UART_YES)
    {
        rt_thread_delay(2000);
        // �����ģ�鷢�Ϳ�ʼPHֵ����ָ��ȴ��ش�����
        UART1_Send(PH_Data);
    }
    
    getPH_Current_Status = UART_NO;

    // �����ģ�鷢�Ϳ�ʼ�¶Ȳ���ָ��ȴ��ش�����
    UART1_Send(Tem_Data);
//    ls1x_uart_write(devUART1,Tem_Data,8,NULL);
    while (getTem_Current_Status != UART_YES)
    {
        rt_thread_delay(2000);
        // �����ģ�鷢�Ϳ�ʼ�¶Ȳ���ָ��ȴ��ش�����
        UART1_Send(Tem_Data);
    }
    
    getTem_Current_Status = UART_NO;

    // �����ģ�鷢�Ϳ�ʼ���ǶȲ���ָ��ȴ��ش�����
    UART1_Send(Tur_Data);
//    ls1x_uart_write(devUART1,Tur_Data,8,NULL);
    while (getTur_Current_Status != UART_YES)
    {
        rt_thread_delay(2000);
        // �����ģ�鷢�Ϳ�ʼ���ǶȲ���ָ��ȴ��ش�����
        UART1_Send(Tur_Data);
    }

    getTur_Current_Status = UART_NO;

    // �����ģ�鷢�Ϳ�ʼ���ײ���ָ��ȴ��ش�����
    send_light_data(light_Data);

    // DC���������ת
    dcmotor_Reverse();
    while (dcmotor_Current_Status != DCMOTOR_STATE_STOP);

    // ����ˮ��1���Թ���ע����Ʒ
    set_Pump_Start(1);
    delay_ms(1000);
    // �ر�ˮ��1
    set_Pump_Stop(1);

    // DC���������ת
    dcmotor_Positive();

    // ����ˮ��4����ˮ����ˮ�ų�
    set_Pump_Start(4);
    delay_ms(35000);
    delay_ms(30000);
    // �ر�ˮ��4
    set_Pump_Stop(4);

    // ����ˮ��3ʹ����ˮ���ϴ��ˮ��
    set_Pump_Start(3);
    delay_ms(30000);
    delay_ms(20000);
    // �ر�ˮ��3
    set_Pump_Stop(3);

    // ����ˮ��4����ˮ����ˮ�ų�
    set_Pump_Start(4);
    delay_ms(35000);
    delay_ms(30000);
    // �ر�ˮ��4
    set_Pump_Stop(4);

    //-----------------------------�������̽���---------------------------//
}
