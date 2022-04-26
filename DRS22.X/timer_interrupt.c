#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/pin_manager.h"


static uint16_t counter = 0;
static uint16_t pwm_high_threshold = 375;

void Set_Threshold(uint16_t value)
{
    pwm_high_threshold = value;
}

void PWM1(void) 
{
    counter++;
    if (counter < pwm_high_threshold)
    {
        IO_DRS_PWM_SetHigh();
    }
    else
    {
        IO_DRS_PWM_SetLow();
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

