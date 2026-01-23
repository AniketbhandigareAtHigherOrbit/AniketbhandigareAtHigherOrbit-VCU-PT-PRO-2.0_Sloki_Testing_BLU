#include "bt_control_state.h"

bt_control_state_t BT_State;

void BT_Control_Reset(void)
{
    BT_State.mode        = BT_MODE_INACTIVE;
    BT_State.drive_dir   = 0U;
    BT_State.target_rpm  = 0U;
    BT_State.steering    = 0U;
    BT_State.rotor_enable= 0U;

    BT_State.alive_cnt   = 0U;
    BT_State.alive_prev  = 0U;
    BT_State.timeout_ms  = 0U;
}
