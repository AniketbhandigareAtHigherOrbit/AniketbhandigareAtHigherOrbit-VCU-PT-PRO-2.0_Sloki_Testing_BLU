#include "Can_Broadcast.h"
#include "databank.h"
#include "pal_can_if.h"
#include "vehicle_state.h"
#include "vehicle_config.h"

uint8_t DataBuff_4[8] = {1, 1, 1, 1, 1, 1, 1, 1};

void can_tx_Fucntion()
{
   CanMsgTransmit(CAN_1, DataBuff_4, 8, 0, 0, 0x184);
}