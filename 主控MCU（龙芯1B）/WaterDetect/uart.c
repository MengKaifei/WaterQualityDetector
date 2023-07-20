#include "uart.h"
#include "string.h"
#include "stdint.h"
#include "rtthread.h"

/*******************************************************************
 **函数名：UART1_set_IO,UART4_set_IO
 **函数功能：初始化uart的IO口
 **形参：无
 **返回值：无
 **说明:UART1_RX:50 -- 数据接收
        UART1_TX:51 -- 数据发送
        UART4_RX:58 -- 数据接收
        UART4_TX:59 -- 数据发送
 *******************************************************************/

// 串口状态标志位
int getPH_Current_Status = UART_NO;
int getTem_Current_Status = UART_NO;
int getTur_Current_Status = UART_NO;

// 接收的数据的长度
int count;
// 存放接收到的数据
char buff[8];

unsigned char starBit = 0;
unsigned char taskBit = 0;
unsigned char data1 = 0;
unsigned char data2 = 0;
unsigned char data3 = 0;
unsigned char data4 = 0;
unsigned char check = 0;
unsigned char stopBit = 0;
unsigned char sum = 0;

uint8_t light_Data[DISPLAY_LIGHT_DATA_LEN] = {12, 12, 11, 13, 11, 12, 13, 12, 14, 11, 13, 12, 12, 12, 11, 12, 12,
                                              12, 11, 11, 13, 13, 11, 12, 12, 13, 12, 11, 11, 13, 12, 12, 11, 10,
                                              12, 12, 13, 13, 12, 10, 13, 13, 12, 12, 12, 11, 12, 11, 13, 12, 10,
                                              13, 12, 13, 12, 12, 11, 10, 10, 13, 12, 13, 12, 11, 13, 14, 12, 14,
                                              12, 14, 12, 12, 14, 12, 14, 13, 13, 12, 13, 12, 13, 12, 14, 13, 13,
                                              14, 13, 14, 16, 16, 17, 20, 26, 31, 38, 48, 59, 74, 94, 115, 136,
                                              155, 162, 164, 151, 140, 123, 108, 94, 82, 72, 65, 55, 52, 50, 52,
                                              55, 57, 60, 66, 73, 79, 87, 93, 96, 99, 101, 102, 104, 106, 108,
                                              112, 116, 124, 127, 133, 139, 146, 150, 154, 154, 156, 153, 150,
                                              148, 145, 141, 139, 135, 133, 133, 132, 134, 131, 135, 140, 141,
                                              143, 146, 147, 146, 146, 148, 144, 142, 139, 135, 130, 128, 118,
                                              118, 115, 115, 111, 109, 108, 109, 106, 107, 109, 107, 105, 108,
                                              105, 99, 100, 99, 96, 94, 92, 87, 84, 79, 77, 74, 69, 66, 61, 61,
                                              58, 56, 53, 53, 48, 46, 44, 44, 40, 40, 39, 37, 36, 34, 34, 34, 33,
                                              30, 30, 30, 30, 27, 27, 28, 25, 25, 24, 22, 22, 21, 22, 19, 18, 18,
                                              19, 17, 17, 17, 16, 16, 14, 15, 16, 15, 14, 14, 13, 13, 13, 14, 14,
                                              13, 14, 13, 13, 12, 14, 11, 12, 12, 13, 13, 12, 12, 12, 12, 12, 12,
                                              12, 12, 11, 12, 12, 12, 11, 13, 13, 12, 11, 11, 11, 9, 11, 12, 12,
                                              12, 10, 12, 11, 12, 11};

/*******************************************************发送通信协议区**************************************************/

// 与采样模块的通信协议
unsigned char PH_Data[8] = {0x5A, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5B};   // PH采样通信协议
unsigned char Tem_Data[8] = {0x5A, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x5B};  // 温度采样通信协议
unsigned char Tur_Data[8] = {0x5A, 0x03, 0x00, 0x00, 0x00, 0x00, 0x02, 0x5B};  // 浑浊度采样通信协议

// 与串口屏通信，发送PH值
void send_ph_value(double ph) {
    // 存放待发送数据
    unsigned char buf[64] = {0};

    // 修改串口屏PH显示值
    sprintf(buf, "ph.txt=\"%.2f\"", ph);

    // 将上述字符串转换为串口屏通信协议
    unsigned int buf_str_len = strlen(buf);
    int i = buf_str_len;
    for (; i < buf_str_len + 3; i++) {
        buf[i] = 0xff;
    }

    // 给串口屏发送数据
    ls1x_uart_write(devUART4, buf, buf_str_len + 3, NULL);
}

// 与串口屏通信，发送温度值
void send_temp_value(double temp) {
    // 存放待发送数据
    unsigned char buf[64] = {0};

    // 修改串口屏温度显示值
    sprintf(buf, "temp.txt=\"%.2f\"", temp);

    // 将上述字符串转换为串口屏通信协议
    unsigned int buf_str_len = strlen(buf);
    int i = buf_str_len;
    for (; i < buf_str_len + 3; i++) {
        buf[i] = 0xff;
    }

    // 给串口屏发送数据
    ls1x_uart_write(devUART4, buf, buf_str_len + 3, NULL);
}

// 与串口屏通信，发送浑浊度值
void send_tre_value(double tre) {
    // 存放待发送数据
    unsigned char buf[64] = {0};

    // 修改串口屏浑浊度显示值
    sprintf(buf, "tre.txt=\"%.2f\"", tre);

    // 将上述字符串转换为串口屏通信协议
    unsigned int buf_str_len = strlen(buf);
    int i = buf_str_len;
    for (; i < buf_str_len + 3; i++) {
        buf[i] = 0xff;
    }

    // 给串口屏发送数据
    ls1x_uart_write(devUART4, buf, buf_str_len + 3, NULL);
}

// 与串口屏通信，发送光谱数据
void send_light_data(uint8_t light_data[DISPLAY_LIGHT_DATA_LEN]) {
    uint8_t buf[64] = {0};
    // 开始传输图表数据
    sprintf(buf, "addt LIG_CHAR.id,0,%d\xff\xff\xff", DISPLAY_LIGHT_DATA_LEN);
    ls1x_uart_write(devUART4, buf, strlen(buf), NULL);
    // 等待开始
    rt_thread_delay(100);
    // 开始传输数据
    ls1x_uart_write(devUART4, light_data, DISPLAY_LIGHT_DATA_LEN, NULL);

    ls1x_uart_write(devUART4, "\x01\xff\xff\xff", strlen("\x01\xff\xff\xff"), NULL);
}

/**********************************************************************************************************************/

/*******************************************************UART1配置区****************************************************/

void UART1_Config_Init(void) {
    unsigned int BaudRate = 115200;
    ls1x_uart_init(devUART1, (void *) BaudRate); //初始化串口
    ls1x_uart_open(devUART1, NULL); //打开串口
}

// 读取串口数据
unsigned int UART1_Read(void) {
    // 接收数据，并将长度赋值给count
    count = ls1x_uart_read(devUART1, buff, 8, NULL);
    if (count == 8) {
        starBit = buff[0];
        taskBit = buff[1];
        data1 = buff[2];
        data2 = buff[3];
        data3 = buff[4];
        data4 = buff[5];
        check = buff[6];
        stopBit = buff[7];
        sum = starBit ^ taskBit ^ data1 ^ data2 ^ data3 ^ data4 ^ stopBit;
        if (starBit == 0x5A && sum == check && stopBit == 0x5B) {
            // 发送数据
            // ls1x_uart_write(devUART1, &taskBit,1,NULL);
            return taskBit;
        } else {
            return 0;
        }
    } else {
        // 发送数据
        // ls1x_uart_write(devUART1,buff,count,NULL);
        return 0;
    }
    return 0;
}

// 发送串口数据
void UART1_Send(unsigned char ch[]) {
    ls1x_uart_write(devUART1, ch, 8, NULL);
}

/**********************************************************************************************************************/

/*******************************************************UART4配置区****************************************************/

void UART4_Config_Init(void) {
    unsigned int BaudRate = 115200;
    ls1x_uart_init(devUART4, (void *) BaudRate); //初始化串口
    ls1x_uart_open(devUART4, NULL); //打开串口
}

// 读取串口数据
unsigned int UART4_Read(void) {
    // 接收数据，并将长度赋值给count
    static unsigned char buff_Uart4[8] = {0};

    // 解析通信协议
    if (ls1x_uart_read(devUART4, buff_Uart4, 7, NULL) == 7 && buff_Uart4[0] == 0x65 && buff_Uart4[3] == 0x01 &&
        buff_Uart4[6] == 0xff) {
        return buff_Uart4[2];
    }
    return DISPLAY_NO_RES;
}
