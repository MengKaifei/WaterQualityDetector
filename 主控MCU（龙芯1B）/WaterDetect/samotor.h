/*
 * samotor.h
 *
 * created: 2023-07-05
 *  author: 
 */

#ifndef _SAMOTOR_H
#define _SAMOTOR_H

#include "ls1b.h"
#include "ls1b_gpio.h"
#include "mips.h"
#include "tick.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RATIO_X         1       // X轴电机减速比
#define RATIO_Y         1       // Y轴电机减速比

#define STEP_X 			10000 * RATIO_X	    // X轴电机转一圈所需步数
#define DEFAULT_STEP_X	100 * RATIO_X	    // X轴左、右转函数调用一次所走步数
#define STEP_Y 			10000 * RATIO_Y	    // Y轴电机转一圈所需步数
#define DEFAULT_STEP_Y	100 * RATIO_Y	    // Y轴左、右转函数调用一次所走步数
#define SPEED           500                 // SA电机旋转速度，越小越快

// 电机IO口定义 
#define SA_X_PU			53
#define SA_X_DIR		52
#define SA_Y_PU			30
#define SA_Y_DIR		29

#define ON  1
#define OFF 0

// 电机当前状态宏定义
#define SAMOTOR_STATE_STOP      0
#define SAMOTOR_STATE_POS       1
#define SAMOTOR_STATE_DEV       2

extern int samotor_Current_Status;  // SA电机当前状态
extern int PositiveAngleX;      	// X轴正实时角度
extern int ReverseAngleX;	        // X轴负实时角度
extern int PositiveAngleY;	        // Y轴正实时角度
extern int ReverseAngleY;	        // Y轴负实时角度
extern int MinStep_X;               // X轴反转目标值
extern int MinStep_Y;               // Y轴反转目标值
extern int MaxStep_X;               // X轴正转目标值
extern int MaxStep_Y;               // Y轴正转目标值

void samotor_Init(void);                    // SA电机初始化
void set_Xsamotor(int step,int direction);  // 设置SA电机X轴目标值
void set_Ysamotor(int step,int direction);  // 设置SA电机Y轴目标值
void set_Zero(void);                        // SA电机全轴回零
void run_Motor(void);                       // 控制SA电机运行到目标值

#ifdef __cplusplus
}
#endif

#endif // _SAMOTOR_H

