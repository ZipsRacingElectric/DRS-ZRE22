/* 
 * File:   timer_interrupt.h
 * Author: Nathaniel Rohr/Ethan Zifzal/Ethan Schwartz
 *
 * Created on February 24, 2022, 6:50 PM
 */

#ifndef TIMER_INTERRUPT_H
#define	TIMER_INTERRUPT_H

#ifdef	__cplusplus
extern "C" {
#endif

void TMR1_initialize();
void Set_Threshold(uint16_t value);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_INTERRUPT_H */

