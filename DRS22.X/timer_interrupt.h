/* 
 * File:   timer_interrupt.h
 * Author: mzifz
 *
 * Created on February 24, 2022, 6:50 PM
 */

#ifndef TIMER_INTERRUPT_H
#define	TIMER_INTERRUPT_H

#ifdef	__cplusplus
extern "C" {
#endif

void TMR1_initialize();
void Set_Threshold(int value);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_INTERRUPT_H */

