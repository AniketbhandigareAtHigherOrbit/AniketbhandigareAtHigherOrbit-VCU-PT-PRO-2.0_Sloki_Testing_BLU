#include "controller_can_rx.h"
#include "vehicle_state.h"

/* Base IDs (maskable) */
#define CTRL_MSG_E_BASE   (0xCF11E00UL)
#define CTRL_MSG_F_BASE   (0xCF11F00UL)
#define CTRL_ID_MASK      (0xFFFFFF00UL)
#define CTRL_NODE_MASK    (0x000000FFUL)

/* Node IDs (last byte) */
#define NODE_LEFT   (0x04U)
#define NODE_ROTOR  (0x05U)
#define NODE_RIGHT  (0x06U)

/* Bounds-safe little-endian read */
static uint16_t rd_u16_le(const uint8_t *p, uint8_t dlc, uint8_t idx, uint8_t *ok)
{
    if ((uint8_t)(idx + 1U) >= dlc) { *ok = 0U; return 0U; }
    *ok = 1U;
    return (uint16_t)p[idx] | ((uint16_t)p[idx + 1U] << 8);
}

/* ---------------- Message E parse (only updates fields that exist) ---------------- */
static void Controller_Parse_MessageE(ControllerIndex_t ctrl_idx,
                                      const uint8_t *d,
                                      uint8_t dlc)
{
    uint8_t ok;
    uint16_t raw;

    /* speed: bytes 0..1 */
    raw = rd_u16_le(d, dlc, 0U, &ok);
    if (ok) VS_Controller[ctrl_idx].speed_rpm = raw;

    /* motor current: bytes 2..3 */
    raw = rd_u16_le(d, dlc, 2U, &ok);
    if (ok) VS_Controller[ctrl_idx].motor_current_A = (int16_t)(raw / 10U);

    /* battery voltage: bytes 4..5 */
    raw = rd_u16_le(d, dlc, 4U, &ok);
    if (ok) VS_Controller[ctrl_idx].battery_voltage_dV = (uint16_t)(raw / 10U);

    /* error code: bytes 6..7 */
    raw = rd_u16_le(d, dlc, 6U, &ok);
    if (ok) VS_Controller[ctrl_idx].error_code = raw;
}

/* ---------------- Message F parse (only updates fields that exist) ---------------- */
static void Controller_Parse_MessageF(ControllerIndex_t ctrl_idx,
                                      const uint8_t *d,
                                      uint8_t dlc)
{
    uint8_t ok;
    uint16_t raw;

    /* speed: bytes 0..1 */
    raw = rd_u16_le(d, dlc, 0U, &ok);
    if (ok) VS_Controller[ctrl_idx].speed_rpm = raw;

    /* controller temp: byte 2 */
    if (dlc > 2U) VS_Controller[ctrl_idx].controller_temp_C = (int8_t)d[2] - 40;

    /* motor temp: byte 3 */
    if (dlc > 3U) VS_Controller[ctrl_idx].motor_temp_C = (int8_t)d[3] - 30;

    /* dirs: byte 4 */
    if (dlc > 4U)
    {
        VS_Controller[ctrl_idx].command_dir  =  d[4]        & 0x03U;
        VS_Controller[ctrl_idx].feedback_dir = (d[4] >> 2)  & 0x03U;
    }

    /* switch bitmap: byte 5 */
    if (dlc > 5U) VS_Controller[ctrl_idx].switch_status = d[5];
}

/* Map node-id to controller index */
static uint8_t Node_To_CtrlIndex(uint8_t node, ControllerIndex_t *out)
{
    switch (node)
    {
        case NODE_LEFT:  *out = CTRL_WHEEL_LEFT;  return 1U;
        case NODE_ROTOR: *out = CTRL_ROTOR;       return 1U;
        case NODE_RIGHT: *out = CTRL_WHEEL_RIGHT; return 1U;
        default: return 0U;
    }
}

void Call_Back_Controller_Rx(uint8_t CanNum_u8,
                             uint8_t Channel_u8,
                             uint8_t *DataBuff_pu8,
                             uint8_t Dlc_u8,
                             uint8_t CanMode_u8,
                             uint8_t Ide_u8,
                             uint32_t CanId_u32)
{
    ControllerIndex_t idx;
    uint32_t base = (CanId_u32 & CTRL_ID_MASK);
    uint8_t node  = (uint8_t)(CanId_u32 & CTRL_NODE_MASK);

    /* Only process our nodes */
    if (!Node_To_CtrlIndex(node, &idx))
    {
        goto out;
    }

    /* Parse E/F */
    if (base == CTRL_MSG_E_BASE)
    {
        Controller_Parse_MessageE(idx, DataBuff_pu8, Dlc_u8);
        VS_Controller[idx].alive = 1U;
    }
    else if (base == CTRL_MSG_F_BASE)
    {
        Controller_Parse_MessageF(idx, DataBuff_pu8, Dlc_u8);
        VS_Controller[idx].alive = 1U;
    }
    else
    {
        /* Not our message type */
    }

out:
    (void)CanNum_u8;
    (void)Channel_u8;
    (void)CanMode_u8;
    (void)Ide_u8;
}
