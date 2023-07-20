/*
 * samotor.c
 *
 * created: 2023-07-05
 *  author:
 */
#include "samotor.h"

// SA���ʵʱ����
int PositiveAngleX = 0;
int ReverseAngleX = 0;
int PositiveAngleY = 0;
int ReverseAngleY = 0;

// SA���Ŀ��ֵ
int MinStep_X = 0;
int MinStep_Y = 0;
int MaxStep_X = 0;
int MaxStep_Y = 0;

// SA�����ǰ����״̬
int samotor_Current_Status = SAMOTOR_STATE_STOP;

// SA�����ʼ��
void samotor_Init(void)
{
    //����GPIOΪ���״̬
    gpio_enable(SA_X_PU,DIR_OUT);
    gpio_enable(SA_X_DIR,DIR_OUT);
    // gpio_enable(SA_Y_PU,DIR_OUT);
    // gpio_enable(SA_Y_DIR,DIR_OUT);
    
    gpio_write(SA_X_PU,ON);
    // gpio_write(SA_Y_PU,ON);
}

//--------------------------< X�������ƺ��� >----------------------------//

// ����X����Ŀ��ֵ
void set_Xsamotor(int step, int direction)
{
    if (direction == 0)
    {
        if ((MinStep_X - step) < 0 && MinStep_X > 0)
        {
            MaxStep_X += step - MinStep_X;
            MinStep_X = 0;
        }
        else if (MinStep_X > 0)
        {
            MinStep_X -= step;
        }
        else
        {
            MaxStep_X += step;
        }
    }
    else if (direction == 1)
    {
        if ((MaxStep_X - step) < 0 && MaxStep_X > 0)
        {
            MinStep_X += step - MaxStep_X;
            MaxStep_X = 0;
        }
        else if (MaxStep_X > 0)
        {
            MaxStep_X -= step;
        }
        else
        {
            MinStep_X += step;
        }
    }
}

//--------------------------< Y�������ƺ��� >----------------------------//

// ����Y����Ŀ��ֵ
// void set_Ysamotor(int step, int direction)
// {
//     if (direction == 0)
//     {

//         if ((MinStep_Y - step) < 0 && MinStep_Y > 0)
//         {
//             MaxStep_Y += step - MinStep_Y;
//             MinStep_Y = 0;
//         }
//         else if (MinStep_Y > 0)
//         {
//             MinStep_Y -= step;
//         }
//         else
//         {
//             MaxStep_Y += step;
//         }
//     }
//     else if (direction == 1)
//     {
//         if ((MaxStep_Y - step) < 0 && MaxStep_Y > 0)
//         {
//             MinStep_Y += step - MaxStep_Y;
//             MaxStep_Y = 0;
//         }
//         else if (MaxStep_Y > 0)
//         {
//             MaxStep_Y -= step;
//         }
//         else
//         {
//             MinStep_Y += step;
//         }
//     }
// }

// ȫ�����
void set_Zero(void)
{
    MaxStep_X = 0;
    MinStep_X = 0;
    MaxStep_Y = 0;
    MinStep_Y = 0;
}

// ����SA�����ת��Ŀ��ֵ
void run_Motor(void)
{
    //-------------------------------< X���������� >--------------------------------//
    // X������ת����
    if (PositiveAngleX < MaxStep_X && MinStep_X == 0 && ReverseAngleX != 0)
    {
        gpio_write(SA_X_DIR, ON);

        gpio_write(SA_X_PU, OFF);
        delay_us(SPEED);
        gpio_write(SA_X_PU, ON);
        delay_us(SPEED);

        ReverseAngleX -= 1;
        samotor_Current_Status = SAMOTOR_STATE_POS;
    }
    else if (PositiveAngleX < MaxStep_X && MinStep_X == 0 && ReverseAngleX == 0)
    {
        gpio_write(SA_X_DIR, ON);

        gpio_write(SA_X_PU, OFF);
        delay_us(SPEED);
        gpio_write(SA_X_PU, ON);
        delay_us(SPEED);
        PositiveAngleX += 1;
        samotor_Current_Status = SAMOTOR_STATE_POS;
    }
    else if (PositiveAngleX > MaxStep_X && MinStep_X == 0 && ReverseAngleX == 0)
    {
        gpio_write(SA_X_DIR, OFF);

        gpio_write(SA_X_PU, OFF);
        delay_us(SPEED);
        gpio_write(SA_X_PU, ON);
        delay_us(SPEED);
        PositiveAngleX -= 1;
        samotor_Current_Status = SAMOTOR_STATE_POS;
    }
    // X������ת����
    else if (ReverseAngleX < MinStep_X && MaxStep_X == 0 && PositiveAngleX != 0)
    {
        gpio_write(SA_X_DIR, OFF);

        gpio_write(SA_X_PU, OFF);
        delay_us(SPEED);
        gpio_write(SA_X_PU, ON);
        delay_us(SPEED);
        PositiveAngleX -= 1;
        samotor_Current_Status = SAMOTOR_STATE_DEV;
    }
    else if (ReverseAngleX < MinStep_X && MaxStep_X == 0 && PositiveAngleX == 0)
    {
        gpio_write(SA_X_DIR, OFF);

        gpio_write(SA_X_PU, OFF);
        delay_us(SPEED);
        gpio_write(SA_X_PU, ON);
        delay_us(SPEED);
        ReverseAngleX += 1;
        samotor_Current_Status = SAMOTOR_STATE_DEV;
    }
    else if (ReverseAngleX > MinStep_X && MaxStep_X == 0 && PositiveAngleX == 0)
    {
        gpio_write(SA_X_DIR, ON);

        gpio_write(SA_X_PU, OFF);
        delay_us(SPEED);
        gpio_write(SA_X_PU, ON);
        delay_us(SPEED);
        ReverseAngleX -= 1;
        samotor_Current_Status = SAMOTOR_STATE_DEV;
    }

    if ((PositiveAngleX == MaxStep_X) && (ReverseAngleX == MinStep_X))
    {
        samotor_Current_Status = SAMOTOR_STATE_STOP;
    }
    

    //-------------------------------< Y���������� >--------------------------------//

    // // Y������ת����
    // if (PositiveAngleY < MaxStep_Y && MinStep_Y == 0 && ReverseAngleY != 0)
    // {
    //     gpio_write(SA_Y_DIR, ON);

    //     gpio_write(SA_Y_PU, OFF);
    //     delay_us(SPEED);
    //     gpio_write(SA_Y_PU, ON);
    //     delay_us(SPEED);

    //     ReverseAngleY -= 1;
    // }
    // else if (PositiveAngleY < MaxStep_Y && MinStep_Y == 0 && ReverseAngleY == 0)
    // {
    //     gpio_write(SA_Y_DIR, ON);

    //     gpio_write(SA_Y_PU, OFF);
    //     delay_us(SPEED);
    //     gpio_write(SA_Y_PU, ON);
    //     delay_us(SPEED);

    //     PositiveAngleY += 1;
    // }
    // else if (PositiveAngleY > MaxStep_Y && MinStep_Y == 0 && ReverseAngleY == 0)
    // {
    //     gpio_write(SA_Y_DIR, OFF);

    //     gpio_write(SA_Y_PU, OFF);
    //     delay_us(SPEED);
    //     gpio_write(SA_Y_PU, ON);
    //     delay_us(SPEED);

    //     PositiveAngleY -= 1;
    // }
    // // Y������ת����
    // else if (ReverseAngleY < MinStep_Y && MaxStep_Y == 0 && PositiveAngleY != 0)
    // {
    //     gpio_write(SA_Y_DIR, OFF);

    //     gpio_write(SA_Y_PU, OFF);
    //     delay_us(SPEED);
    //     gpio_write(SA_Y_PU, ON);
    //     delay_us(SPEED);

    //     PositiveAngleY -= 1;
    // }
    // else if (ReverseAngleY < MinStep_Y && MaxStep_Y == 0 && PositiveAngleY == 0)
    // {
    //     gpio_write(SA_Y_DIR, OFF);

    //     gpio_write(SA_Y_PU, OFF);
    //     delay_us(SPEED);
    //     gpio_write(SA_Y_PU, ON);
    //     delay_us(SPEED);

    //     ReverseAngleY += 1;
    // }
    // else if (ReverseAngleY > MinStep_Y && MaxStep_Y == 0 && PositiveAngleY == 0)
    // {
    //     gpio_write(SA_Y_DIR, ON);

    //     gpio_write(SA_Y_PU, OFF);
    //     delay_us(SPEED);
    //     gpio_write(SA_Y_PU, ON);
    //     delay_us(SPEED);

    //     ReverseAngleY -= 1;
    // }

    //----------------------------< ������������� >-------------------------------//
}
