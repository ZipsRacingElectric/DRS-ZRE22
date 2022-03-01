#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/pin_manager.h"


unsigned int counter = 0
static int threshold;
void Set_Threshold(int value)
{
    threshold = value;
}

void PWM1() 
{
    counter = (counter + 1);
    if (counter < threshold)
    {
        IO_RA7_SetHigh();
    }
    else
    {
        IO_RA7_SetLow();
    }
    if (counter >= 5000)
    {
        counter = 0;
    }
}

void TMR1_initialize()
{
    TMR1_SetInterruptHandler(PWM1);
}

