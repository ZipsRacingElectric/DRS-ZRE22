/* 
 * File:   global_constants.h
 * Author: natha
 *
 * Created on February 14, 2022, 6:36 PM
 */

#ifndef GLOBAL_CONSTANTS_H
#define	GLOBAL_CONSTANTS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define ID_CAN_DRS_STATE 0x123

#define FCY 40000000UL          // Instruction cycle frequency, Hz - required for __delayXXX() to work


#ifdef	__cplusplus
}
#endif

#endif	/* GLOBAL_CONSTANTS_H */

