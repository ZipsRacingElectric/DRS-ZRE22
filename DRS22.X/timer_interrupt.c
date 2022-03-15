#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/pin_manager.h"


unsigned int counter = 0;
static int threshold = 375;

void Set_Threshold(int value)
{
    threshold = value;
}

void PWM1() 
{
    counter = (counter + 1);
    if (counter < threshold)
    {
        IO_RA11_SetHigh();
    }
    else
    {
        IO_RA11_SetLow();
    }
    if (counter >= 5000)
    {
        counter = 0;
    }
}

void TMR1_initialize()
{
    TMR1_SetInterruptHandler(PWM1);
    TMR1_Start();
}

