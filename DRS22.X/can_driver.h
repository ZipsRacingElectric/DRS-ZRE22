/* 
 * File:   can_driver.h
 * Author: Nathan, Ethan, and Ethan
 *
 * Created on December 26, 2021, 10:07 PM
 */

#ifndef CAN_DRIVER_H
#define	CAN_DRIVER_H

#include "mcc_generated_files/can_types.h"

void CAN_Initialize(void);
void CAN_Handle_Message_Rx(void);
void CAN_Msg_Send(uint16_t id, CAN_DLC dlc, uint8_t *tx_data);

#endif	/* CAN_DRIVER_H */