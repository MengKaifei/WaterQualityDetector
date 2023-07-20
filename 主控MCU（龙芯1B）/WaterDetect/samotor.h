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

#define RATIO_X         1       // X�������ٱ�
#define RATIO_Y         1       // Y�������ٱ�

#define STEP_X 			10000 * RATIO_X	    // X����תһȦ���貽��
#define DEFAULT_STEP_X	100 * RATIO_X	    // X������ת��������һ�����߲���
#define STEP_Y 			10000 * RATIO_Y	    // Y����תһȦ���貽��
#define DEFAULT_STEP_Y	100 * RATIO_Y	    // Y������ת��������һ�����߲���
#define SPEED           500                 // SA�����ת�ٶȣ�ԽСԽ��

// ���IO�ڶ��� 
#define SA_X_PU			53
#define SA_X_DIR		52
#define SA_Y_PU			30
#define SA_Y_DIR		29

#define ON  1
#define OFF 0

// �����ǰ״̬�궨��
#define SAMOTOR_STATE_STOP      0
#define SAMOTOR_STATE_POS       1
#define SAMOTOR_STATE_DEV       2

extern int samotor_Current_Status;  // SA�����ǰ״̬
extern int PositiveAngleX;      	// X����ʵʱ�Ƕ�
extern int ReverseAngleX;	        // X�Ḻʵʱ�Ƕ�
extern int PositiveAngleY;	        // Y����ʵʱ�Ƕ�
extern int ReverseAngleY;	        // Y�Ḻʵʱ�Ƕ�
extern int MinStep_X;               // X�ᷴתĿ��ֵ
extern int MinStep_Y;               // Y�ᷴתĿ��ֵ
extern int MaxStep_X;               // X����תĿ��ֵ
extern int MaxStep_Y;               // Y����תĿ��ֵ

void samotor_Init(void);                    // SA�����ʼ��
void set_Xsamotor(int step,int direction);  // ����SA���X��Ŀ��ֵ
void set_Ysamotor(int step,int direction);  // ����SA���Y��Ŀ��ֵ
void set_Zero(void);                        // SA���ȫ�����
void run_Motor(void);                       // ����SA������е�Ŀ��ֵ

#ifdef __cplusplus
}
#endif

#endif // _SAMOTOR_H

