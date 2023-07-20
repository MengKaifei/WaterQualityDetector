/*
 * task.c
 *
 * created: 2023-07-09
 *  author: 
 */

#include "task.h"

// SA电机旋转角度
int angle = (360.0/25.0) * (10000.0/360.0);

// 任务一全自动运行函数
void Task_Start_1(void)
{
    //-----------------------------任务流程开始---------------------------//

    // DC电机向上旋转
    dcmotor_Positive();
    while (dcmotor_Current_Status != DCMOTOR_STATE_STOP);

    // SA电机顺时针旋转
    set_Xsamotor(angle,0);
    rt_thread_delay(100);
    while (samotor_Current_Status != SAMOTOR_STATE_STOP)
    {
        rt_thread_delay(100);
    }

    // 开启水泵2往样水箱中注入样品
    set_Pump_Start(2);
    delay_ms(30000);
    delay_ms(20000);
    // 关闭水泵2
    set_Pump_Stop(2);

    // 向采样模块发送开始PH值采样指令，等待回传数据
    UART1_Send(PH_Data);
//    ls1x_uart_write(devUART1,PH_Data,8,NULL);
    while (getPH_Current_Status != UART_YES)
    {
        rt_thread_delay(2000);
        // 向采样模块发送开始PH值采样指令，等待回传数据
        UART1_Send(PH_Data);
    }
    
    getPH_Current_Status = UART_NO;

    // 向采样模块发送开始温度采样指令，等待回传数据
    UART1_Send(Tem_Data);
//    ls1x_uart_write(devUART1,Tem_Data,8,NULL);
    while (getTem_Current_Status != UART_YES)
    {
        rt_thread_delay(2000);
        // 向采样模块发送开始温度采样指令，等待回传数据
        UART1_Send(Tem_Data);
    }
    
    getTem_Current_Status = UART_NO;

    // 向采样模块发送开始浑浊度采样指令，等待回传数据
    UART1_Send(Tur_Data);
//    ls1x_uart_write(devUART1,Tur_Data,8,NULL);
    while (getTur_Current_Status != UART_YES)
    {
        rt_thread_delay(2000);
        // 向采样模块发送开始浑浊度采样指令，等待回传数据
        UART1_Send(Tur_Data);
    }

    getTur_Current_Status = UART_NO;

    // 向采样模块发送开始光谱采样指令，等待回传数据
    send_light_data(light_Data);

    // DC电机向下旋转
    dcmotor_Reverse();
    while (dcmotor_Current_Status != DCMOTOR_STATE_STOP);

    // 开启水泵1往试管中注入样品
    set_Pump_Start(1);
    delay_ms(1000);
    // 关闭水泵1
    set_Pump_Stop(1);

    // DC电机向上旋转
    dcmotor_Positive();

    // 开启水泵4将样水箱中水排出
    set_Pump_Start(4);
    delay_ms(35000);
    delay_ms(30000);
    // 关闭水泵4
    set_Pump_Stop(4);

    // 开启水泵3使用清水箱冲洗样水箱
    set_Pump_Start(3);
    delay_ms(30000);
    delay_ms(20000);
    // 关闭水泵3
    set_Pump_Stop(3);

    // 开启水泵4将样水箱中水排出
    set_Pump_Start(4);
    delay_ms(35000);
    delay_ms(30000);
    // 关闭水泵4
    set_Pump_Stop(4);

    //-----------------------------任务流程结束---------------------------//
}
