#include "battery_can_rx.h"
#include "vehicle_state.h"

/* ---------------------------------------------------------
 * Common Battery RX callback
 * - Same CAN line
 * - Same format
 * - Different CAN IDs
 * --------------------------------------------------------- */
void Call_Back_Battery_Rx_1(uint8_t CanNum_u8,
                          uint8_t Channel_u8,
                          uint8_t *D,
                          uint8_t Dlc_u8,
                          uint8_t CanMode_u8,
                          uint8_t Ide_u8,
                          uint32_t CanId_u32)
{
    BatteryState_t *bat;
    uint8_t mux;
    uint16_t raw;
    uint16_t raw1;

    if (Dlc_u8 < 8U)
        return;

    /* ---------------- Battery selection by CAN ID ---------------- */
    switch (CanId_u32)
    {
        /* Battery 1 IDs  0x0746CD62, 0x0746CD04*/
        case 0x0746CD62U:
        case 0x0746CD04U:
        //case 0x0746CE3EU:
        //case 0x0746D608U:
            bat = &VS_Battery1;
            break;

        /* Battery 2 IDs */
        //case 0x0746CD62U:
        //case 0x0746CD04U:
        //case 0x0746CE3EU:
        //case 0x0746D608U:
            //bat = &VS_Battery2;
            //break;

        //default:
            //return;
    }

    /* ---------------- MUX decoding ---------------- */
    mux = D[0];

    switch (mux)
    {
        /* MUX 1 : Voltage / Current */
        case 1:
            raw = (uint16_t)D[2] | ((uint16_t)D[3] << 8);
            bat->Voltage_dV = (int16_t)raw;

            raw1 = (uint16_t)D[4] | ((uint16_t)D[5] << 8);
            bat->Current_dA = (int16_t)raw1;
            break;

        /* MUX 2 : SOC / SOH / Cycles */
        case 2:
            bat->SOC = D[1];
            bat->SOH = D[2];

            bat->Cycles =
                (uint16_t)D[3] |
                ((uint16_t)D[4] << 8);
            break;

        /* MUX 3 : Switch status */
        case 3:
            bat->Switch_Status = D[1];
            break;

        /* MUX 7 : Temperatures */
        case 7:
            bat->Ambient_Temp_C = (int8_t)D[1] - 40;
            bat->MOSFET_Temp_C  = (int8_t)D[2] - 40;
            break;

        default:
            break;
    }

    bat->Alive = 1U;
    bat->RxTimeoutMs  =1000U;

    (void)CanNum_u8;
    (void)Channel_u8;
    (void)CanMode_u8;
    (void)Ide_u8;
}

void Call_Back_Battery_Rx_2(uint8_t CanNum_u8,
                          uint8_t Channel_u8,
                          uint8_t *D,
                          uint8_t Dlc_u8,
                          uint8_t CanMode_u8,
                          uint8_t Ide_u8,
                          uint32_t CanId_u32)
{
    BatteryState_t *bat;
    uint8_t mux;
    uint16_t raw;
    uint16_t raw1;

    if (Dlc_u8 < 8U)
        return;

    /* ---------------- Battery selection by CAN ID ---------------- */
    switch (CanId_u32)
    {
        /* Battery 1 IDs  0x0746CD62, 0x0746CD04*/
        //case 0x0746CD62U:
        //case 0x0746CD04U:
        //case 0x0746CE3EU:
        //case 0x0746D608U:
            //bat = &VS_Battery1;
            //break;

        /* Battery 2 IDs */
        //case 0x0746CD62U:
        //case 0x0746CD04U:
        case 0x0746CE3EU:
        case 0x0746D608U:
            bat = &VS_Battery2;
            break;

        default:
            return;
    }

    /* ---------------- MUX decoding ---------------- */
    mux = D[0];

    switch (mux)
    {
        /* MUX 1 : Voltage / Current */
        case 1:
            raw = (uint16_t)D[2] | ((uint16_t)D[3] << 8);
            bat->Voltage_dV = (int16_t)raw;

            raw1 = (uint16_t)D[4] | ((uint16_t)D[5] << 8);
            bat->Current_dA = (int16_t)raw1;
            break;

        /* MUX 2 : SOC / SOH / Cycles */
        case 2:
            bat->SOC = D[1];
            bat->SOH = D[2];

            bat->Cycles =
                (uint16_t)D[3] |
                ((uint16_t)D[4] << 8);
            break;

        /* MUX 3 : Switch status */
        case 3:
            bat->Switch_Status = D[1];
            break;

        /* MUX 7 : Temperatures */
        case 7:
            bat->Ambient_Temp_C = (int8_t)D[1] - 40;
            bat->MOSFET_Temp_C  = (int8_t)D[2] - 40;
            break;

        default:
            break;
    }

    bat->Alive = 1U;
    bat->RxTimeoutMs  =1000U;

    (void)CanNum_u8;
    (void)Channel_u8;
    (void)CanMode_u8;
    (void)Ide_u8;
}
