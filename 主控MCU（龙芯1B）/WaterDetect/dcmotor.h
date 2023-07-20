/*
 * dcmotor.h
 *
 * created: 2023-07-06
 *  author: 
 */

#ifndef _DCMOTOR_H
#define _DCMOTOR_H

#include "ls1b.h"
#include "ls1b_gpio.h"
#include "mips.h"
#include "tick.h"

#ifdef __cplusplus
extern "C" {
#endif

// ���IO�ڶ��� 
#define DC_X_C2			39
#define DC_X_C1		    38

#define ON  1
#define OFF 0

#define DCMOTOR_STATE_STOP      0
#define DCMOTOR_STATE_POS       1
#define DCMOTOR_STATE_DEV       2

extern int dcmotor_Current_Status;

void dcmotor_Init(void);        // DC�����ʼ��
void dcmotor_Positive(void);    // DC�����ת
void dcmotor_Reverse(void);     // DC�����ת
void dcmotor_Stop(void);        // DC���ֹͣ

#ifdef __cplusplus
}
#endif

#endif // _DCMOTOR_H

