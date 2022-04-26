#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/pin_manager.h"

static int threshold;
void Set_Threshold(int value)
{
    threshold = value;
}
void PWM1() 
{
    
}

void TMR1_initialize()
{
    TMR1_SetInterruptHandler(PWM1);
}
