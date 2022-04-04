#include "mcc_generated_files/can1.h"
#include "mcc_generated_files/can_types.h"
#include "mcc_generated_files/pin_manager.h"
#include "global_constants.h"
#include "timer_interrupt.h"
#include "can_driver.h"

CAN_MSG_OBJ message;
uint8_t can_data[8] = {0,0,0,0,0,0,0,0};
uint16_t temporary_var;

void CAN_Initialize(void)
{
    message.data = can_data;
    
    CAN1_TransmitEnable();
    CAN1_ReceiveEnable();
    CAN1_OperationModeSet(CAN_NORMAL_OPERATION_MODE);
    CAN1_SetRxBufferInterruptHandler(&CAN_Handle_Message_Rx);
    
    CAN_STDBY_SetLow();
}

void CAN_Handle_Message_Rx(void)
{
    //Get the CAN message
    if(CAN1_Receive(&message))
    {
        switch(message.msgId)
        {
            case ID_CAN_DRS_STATE:
                if (message.data[0] == 0x01)  //TODO: These values need to be calibrated
                {
                    Set_Threshold(375);
                }
                else
                {
                    Set_Threshold(250);
                }
                LED3_SetHigh();
                break;
                
            
            //put CAN message handling here
        }
    }
}

void CAN_Msg_Send(uint16_t id, CAN_DLC dlc, uint8_t *tx_data)
{
    CAN_MSG_FIELD overhead = {
        .idType = CAN_FRAME_STD,
        .frameType = CAN_FRAME_DATA,
        .dlc = dlc,
    };

    CAN_MSG_OBJ msg = {
        .msgId = id,
        .field = overhead,
        .data = tx_data,
    };

    CAN_TX_MSG_REQUEST_STATUS status = CAN1_Transmit(CAN_PRIORITY_MEDIUM, &msg);
    if(status == CAN_TX_MSG_REQUEST_SUCCESS)
    {
        LED4_SetHigh();
    }
    else
    {
        LED4_SetLow();
    }
}