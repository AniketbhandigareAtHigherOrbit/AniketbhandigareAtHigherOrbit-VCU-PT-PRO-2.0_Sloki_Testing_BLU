#include "controller_can_rx.h"
#include "vehicle_state.h"

/* ---------------------------------------------------------
 * Controller RX callback (exact-ID based)
 * --------------------------------------------------------- */
void Call_Back_Controller_Rx(uint8_t CanNum_u8,
                             uint8_t Channel_u8,
                             uint8_t *DataBuff_pu8,
                             uint8_t Dlc_u8,
                             uint8_t CanMode_u8,
                             uint8_t Ide_u8,
                             uint32_t CanId_u32)
{
    ControllerIndex_t ctrl_idx;
    uint16_t raw;

    if (Dlc_u8 < 8U)
    {
        return;
    }

    /* ---------- Map CAN ID → Controller ---------- */
    switch (CanId_u32)
    {
        /* Controller 4 : Left Wheel */
        case 0xCF11E04:
        case 0xCF11F04:
            ctrl_idx = CTRL_WHEEL_LEFT;
            break;

        /* Controller 5 : Rotor */
        case 0xCF11E05:
        case 0xCF11F05:
            ctrl_idx = CTRL_ROTOR;
            break;

        /* Controller 6 : Right Wheel */
        case 0xCF11E06:
        case 0xCF11F06:
            ctrl_idx = CTRL_WHEEL_RIGHT;
            break;

        default:
            return;
    }

    /* =================================================
     * MESSAGE E : Speed, Current, Voltage, Error
     * IDs : 0xCF11E04 / 05 / 06
     * ================================================= */
    if ((CanId_u32 & 0xFFFFFF00UL) == 0xCF11E00UL)
    {
        /* Speed (1 rpm / bit) */
        VS_Controller[ctrl_idx].speed_rpm =
            (uint16_t)DataBuff_pu8[0] |
            ((uint16_t)DataBuff_pu8[1] << 8);

        /* Motor current (0.1 A / bit) */
        raw =
            (uint16_t)DataBuff_pu8[2] |
            ((uint16_t)DataBuff_pu8[3] << 8);
        VS_Controller[ctrl_idx].motor_current_A =
            (int16_t)(raw / 10);

        /* Battery voltage (0.1 V / bit) */
        raw =
            (uint16_t)DataBuff_pu8[4] |
            ((uint16_t)DataBuff_pu8[5] << 8);
        VS_Controller[ctrl_idx].battery_voltage_dV =
            raw / 10;

        /* Error code */
        VS_Controller[ctrl_idx].error_code =
            (uint16_t)DataBuff_pu8[6] |
            ((uint16_t)DataBuff_pu8[7] << 8);
    }

    /* =================================================
     * MESSAGE F : Speed, Temperature, Direction, Status
     * IDs : 0xCF11F04 / 05 / 06
     * ================================================= */
    else if ((CanId_u32 & 0xFFFFFF00UL) == 0xCF11F00UL)
    {
        /* Speed */
        VS_Controller[ctrl_idx].speed_rpm =
            (uint16_t)DataBuff_pu8[0] |
            ((uint16_t)DataBuff_pu8[1] << 8);

        /* Temperatures */
        VS_Controller[ctrl_idx].controller_temp_C =
            (int8_t)DataBuff_pu8[2] - 40;

        VS_Controller[ctrl_idx].motor_temp_C =
            (int8_t)DataBuff_pu8[3] - 30;

        /* Direction (bit-packed) */
        VS_Controller[ctrl_idx].command_dir =
            DataBuff_pu8[4] & 0x03U;

        VS_Controller[ctrl_idx].feedback_dir =
            (DataBuff_pu8[4] >> 2) & 0x03U;

        /* Switch / Hall status bitmap */
        VS_Controller[ctrl_idx].switch_status =
            DataBuff_pu8[5];
    }

    VS_Controller[ctrl_idx].alive = 1U;

    (void)CanNum_u8;
    (void)Channel_u8;
    (void)CanMode_u8;
    (void)Ide_u8;
}
