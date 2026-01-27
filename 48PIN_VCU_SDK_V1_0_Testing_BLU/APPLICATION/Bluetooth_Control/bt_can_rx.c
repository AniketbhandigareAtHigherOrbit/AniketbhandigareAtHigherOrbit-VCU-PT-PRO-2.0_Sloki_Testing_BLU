#include "bt_can_rx.h"
#include "bt_control_state.h"
#include "bt_control_config.h"

void Call_Back_BT_Command_Rx(uint8_t CanNum_u8,
                             uint32_t CanId_u32,
                             uint8_t *Data_pu8,
                             uint8_t Dlc_u8)
{
    (void)CanNum_u8;

    /* Only extended, exact length */
    if (Dlc_u8 != 8U)
        return;

    /* Magic check */
    if (Data_pu8[0] != BT_CMD_MAGIC)
        return;

    /* Update Bluetooth state */
    BT_State.drive_dir    = Data_pu8[1];
    BT_State.target_rpm   = (uint16_t)((Data_pu8[2] << 8) | Data_pu8[3]);
    BT_State.steering     = Data_pu8[4];
    BT_State.rotor_enable = Data_pu8[5];

    BT_State.alive_cnt    = Data_pu8[7];
    BT_State.timeout_ms   = BT_ALIVE_TIMEOUT_MS;
    BT_State.mode         = BT_MODE_ACTIVE;
}
