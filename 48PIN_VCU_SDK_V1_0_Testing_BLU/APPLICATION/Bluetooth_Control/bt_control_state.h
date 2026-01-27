#ifndef BT_CONTROL_STATE_H
#define BT_CONTROL_STATE_H

#include "databank.h"

typedef enum
{
    BT_MODE_INACTIVE = 0,
    BT_MODE_ACTIVE
} bt_mode_t;

typedef struct
{
    bt_mode_t mode;

    uint8_t  drive_dir;      /* 0 STOP, 1 FWD, 2 REV */
    uint16_t target_rpm;
    uint8_t  steering;       /* 0 STR, 1 LEFT, 2 RIGHT */
    uint8_t  rotor_enable;

    uint8_t  alive_cnt;
    uint8_t  alive_prev;
    uint16_t timeout_ms;

} bt_control_state_t;

extern bt_control_state_t BT_State;

void BT_Control_Reset(void);

#endif
