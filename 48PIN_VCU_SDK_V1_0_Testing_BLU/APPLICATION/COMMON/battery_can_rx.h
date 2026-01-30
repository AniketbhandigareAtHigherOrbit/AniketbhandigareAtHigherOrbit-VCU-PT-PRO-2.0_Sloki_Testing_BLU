#ifndef BATTERY_CAN_RX_H
#define BATTERY_CAN_RX_H

#include "app_typedef.h"

/* =========================================================
 * Battery-1 RX callback (CAN0)
 * ========================================================= */
void Call_Back_Battery_Rx_1(uint8_t CanNum_u8,
                          uint8_t Channel_u8,
                          uint8_t *DataBuff_pu8,
                          uint8_t Dlc_u8,
                          uint8_t CanMode_u8,
                          uint8_t Ide_u8,
                          uint32_t CanId_u32);

void Call_Back_Battery_Rx_2(uint8_t CanNum_u8,
                          uint8_t Channel_u8,
                          uint8_t *DataBuff_pu8,
                          uint8_t Dlc_u8,
                          uint8_t CanMode_u8,
                          uint8_t Ide_u8,
                          uint32_t CanId_u32);
#endif
