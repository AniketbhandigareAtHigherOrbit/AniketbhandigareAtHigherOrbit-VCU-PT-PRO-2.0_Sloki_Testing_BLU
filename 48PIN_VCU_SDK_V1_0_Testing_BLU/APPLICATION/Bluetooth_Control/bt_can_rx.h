#ifndef BT_CAN_RX_H
#define BT_CAN_RX_H

#include "databank.h"

void Call_Back_BT_Command_Rx(uint8_t CanNum_u8,
                             uint32_t CanId_u32,
                             uint8_t *Data_pu8,
                             uint8_t Dlc_u8);

#endif
