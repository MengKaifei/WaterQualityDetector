/*
 * Copyright (C) 2020-2021 Suzhou Tiancheng Software Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * Loongson 1B RT-Thread Application
 */

#include <time.h>
#include <stdio.h>
#include "ls1b.h"
#include "ls1b_gpio.h"
#include "mips.h"
#include "rtthread.h"
#include "key.h"
#include "samotor.h"
#include "dcmotor.h"
#include "uart.h"
#include "pump.h"
#include "task.h"
#include "limit.h"


#define ON  1
#define OFF 0

//-------------------------------------------------------------------------------------------------
// BSP
//-------------------------------------------------------------------------------------------------

#include "bsp.h"

#if defined(BSP_USE_FB)

#include "ls1x_fb.h"

#ifdef XPT2046_DRV
char LCD_display_mode[] = LCD_800x480;
#elif defined(GT1151_DRV)
char LCD_display_mode[] = LCD_480x800;
#else
#error "��bsp.h��ѡ������ XPT2046_DRV ���� GT1151_DRV"
       "XPT2046_DRV:  ����800*480 �����Ĵ�����."
       "GT1151_DRV:   ����480*800 �����Ĵ�����."
       "�������ѡ��, ע�͵��� error ��Ϣ, Ȼ���Զ���: LCD_display_mode[]"
#endif
#endif

//-------------------------------------------------------------------------------------------------
// �߳�����
//-------------------------------------------------------------------------------------------------

// ��������߳�
static rt_thread_t m_demo_thread = NULL;

static void demo_thread(void *arg) {
    for (;;) {
        // �����������
        run_Motor();
    }
}

// ����1�߳�
static rt_thread_t m_uart1_thread = NULL;

static void uart1_thread(void *arg) {
    for (;;) {
        rt_thread_delay(100);

        unsigned int ch;

        double num;

        switch (ch = UART1_Read()) {
            case 0x01:
                // ����PHֵ����
                num = (data1 * 1000 + data2 * 100 + data3 * 10 + data4) / 100.0;
                // ����PHֵ���ݵ�������
                send_ph_value(num);
                // �޸�PHֵ��ȡ��־λΪ���
                getPH_Current_Status = UART_YES;
                break;

            case 0x02:
                // �����¶�ֵ����
                num = (data1 * 1000 + data2 * 100 + data3 * 10 + data4) / 100.0;
                // �����¶�ֵ���ݵ�������
                send_temp_value(num);
                // �޸��¶�ֵ��ȡ��־λΪ���
                getTem_Current_Status = UART_YES;
                break;

            case 0x03:
                // �������Ƕ�ֵ����
                num = (data1 * 1000 + data2 * 100 + data3 * 10 + data4) / 100.0;
                // ���ͻ��Ƕ�ֵ���ݵ�������
                send_tre_value(num);
                // �޸Ļ��Ƕ�ֵ��ȡ��־λΪ���
                getTur_Current_Status = UART_YES;
                break;

            default:
                break;
        }
    }
}

// ����4�߳�
static rt_thread_t m_uart4_thread = NULL;

static void uart4_thread(void *arg) {
    for (;;) {
        switch (UART4_Read()) {
            // ��ͣ
            case DISPLAY_STOP_CLIKED:
                // ��ͣ����
                dcmotor_Stop();
                set_Pump_Stop(1);
                break;

                // ��ʼ
            case DISPLAY_START_CLIKED:
                Task_Start_1();
                break;

                // ��ʱ
            case DISPLAY_TIMER_CLIKED:

                break;

            default:
                break;
        }

        rt_thread_delay(100);
    }
}

// ���ذ����߳�
static rt_thread_t m_key_thread = NULL;

static void key_thread(void *arg) {
    for (;;) {
        // rt_kprintf("tick count = %i\r\n", tickcount);

        rt_thread_delay(100);

        switch (key_Scan()) {
            case 1:
                // ��ͣ
                set_Pump_Start(1);
                break;

            case 2:
                // ����PHֵ
                set_Pump_Stop(1);
                set_Pump_Stop(2);
                set_Pump_Stop(3);
                set_Pump_Stop(4);
                break;

            case 3:
                // �������
                set_Pump_Start(4);
                break;

            case 4:
                // �����ģ�鷢�Ϳ�ʼPHֵ����ָ��ȴ��ش�����
                UART1_Send(PH_Data);
                while (getPH_Current_Status != UART_YES)
                {
                    rt_thread_delay(2000);
                    // �����ģ�鷢�Ϳ�ʼPHֵ����ָ��ȴ��ش�����
                    UART1_Send(PH_Data);
                }

                getPH_Current_Status = UART_NO;

                // �����ģ�鷢�Ϳ�ʼ�¶Ȳ���ָ��ȴ��ش�����
                UART1_Send(Tem_Data);
//              ls1x_uart_write(devUART1,Tem_Data,8,NULL);
                while (getTem_Current_Status != UART_YES)
                {
                    rt_thread_delay(2000);
                    // �����ģ�鷢�Ϳ�ʼ�¶Ȳ���ָ��ȴ��ش�����
                    UART1_Send(Tem_Data);
                }

                getTem_Current_Status = UART_NO;

                // �����ģ�鷢�Ϳ�ʼ���ǶȲ���ָ��ȴ��ش�����
                UART1_Send(Tur_Data);
//              ls1x_uart_write(devUART1,Tur_Data,8,NULL);
                while (getTur_Current_Status != UART_YES)
                {
                    rt_thread_delay(2000);
                    // �����ģ�鷢�Ϳ�ʼ���ǶȲ���ָ��ȴ��ش�����
                    UART1_Send(Tur_Data);
                }

                getTur_Current_Status = UART_NO;
                
                break;

            default:
                break;
        }
    }
}

// ��λ�����߳�
static rt_thread_t m_limit_thread = NULL;

static void limit_thread(void *arg) {
    for (;;) {

        rt_thread_delay(100);

        switch (Limit_Scan()) {
            case 1:
                // ����λ����ִ���¼��������ת0.5sֹͣ��
                dcmotor_Positive();
                delay_ms(500);
                dcmotor_Stop();
                break;

            case 2:
                // ����λ����ִ���¼��������ת0.5sֹͣ
                dcmotor_Reverse();
                delay_ms(500);
                dcmotor_Stop();
                break;

            default:
                break;
        }

    }
}

//-------------------------------------------------------------------------------------------------

int main(int argc, char **argv) {
    rt_kprintf("\r\nWelcome to RT-Thread.\r\n\r\n");

    ls1x_drv_init();            /* Initialize device drivers */

    rt_ls1x_drv_init();         /* Initialize device drivers for RTT */

//  install_3th_libraries(); 	/* Install 3th libraies */

    key_Init();

    Limit_Init();

    samotor_Init();

    dcmotor_Init();

    pump_Init();

    UART1_Config_Init();
    UART4_Config_Init();

    /*
     * RT-Thread �����ʼ��
     */
    m_demo_thread = rt_thread_create("demothread",
                                     demo_thread,
                                     NULL,         // arg
                                     1024 * 4,       // statck size
                                     11,           // priority
                                     10);          // slice ticks

    m_uart1_thread = rt_thread_create("uart1thread",
                                      uart1_thread,
                                      NULL,         // arg
                                      1024 * 4,       // statck size
                                      9,           // priority
                                      10);          // slice ticks

    m_uart4_thread = rt_thread_create("uart4thread",
                                      uart4_thread,
                                      NULL,         // arg
                                      1024 * 4,       // statck size
                                      10,           // priority
                                      10);          // slice ticks

    m_key_thread = rt_thread_create("keythread",
                                    key_thread,
                                    NULL,         // arg
                                    1024 * 4,       // statck size
                                    8,           // priority
                                    10);          // slice ticks

    m_limit_thread = rt_thread_create("limitthread",
                                      limit_thread,
                                      NULL,         // arg
                                      1024 * 4,       // statck size
                                      7,           // priority
                                      10);          // slice ticks

    if (m_demo_thread == NULL) {
        rt_kprintf("create demo thread fail!\r\n");
    } else {
        rt_thread_startup(m_demo_thread);
    }

    if (m_uart1_thread == NULL) {
        rt_kprintf("create uart1 thread fail!\r\n");
    } else {
        rt_thread_startup(m_uart1_thread);
    }

    if (m_uart4_thread == NULL) {
        rt_kprintf("create uart4 thread fail!\r\n");
    } else {
        rt_thread_startup(m_uart4_thread);
    }

    if (m_key_thread == NULL) {
        rt_kprintf("create key thread fail!\r\n");
    } else {
        rt_thread_startup(m_key_thread);
    }

    if (m_limit_thread == NULL) {
        rt_kprintf("create limit thread fail!\r\n");
    } else {
        rt_thread_startup(m_limit_thread);
    }

    /*
     * Finsh as another thread...
     */
    return 0;
}

/*
 * @@ End
 */
