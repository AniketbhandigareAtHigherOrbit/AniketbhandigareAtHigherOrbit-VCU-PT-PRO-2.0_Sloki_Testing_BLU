#ifndef CONTROLLER_CAN_RX_H
#define CONTROLLER_CAN_RX_H

#include "app_typedef.h"

/* Common RX callback for all controller CAN messages */
void Call_Back_Controller_Rx(uint8_t CanNum_u8,
                             uint8_t Channel_u8,
                             uint8_t *DataBuff_pu8,
                             uint8_t Dlc_u8,
                             uint8_t CanMode_u8,
                             uint8_t Ide_u8,
                             uint32_t CanId_u32);

#endif /* CONTROLLER_CAN_RX_H */
