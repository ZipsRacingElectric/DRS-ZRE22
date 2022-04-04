#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/pin_manager.h"


static uint16_t counter = 0;
static uint16_t threshold = 375;

void Set_Threshold(uint16_t value)
{
    threshold = value;
}

void PWM1() 
{
    counter++;
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

