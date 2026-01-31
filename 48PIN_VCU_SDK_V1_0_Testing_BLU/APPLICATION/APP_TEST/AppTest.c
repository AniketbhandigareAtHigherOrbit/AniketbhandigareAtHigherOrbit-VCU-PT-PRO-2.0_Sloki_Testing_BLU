#include "AppTest.h"
#include "databank.h"
#include "pal_can_if.h"
#include "vehicle_state.h"
#include "bt_control_logic.h"
#include "vehicle_config.h"
#include "bt_control_state.h"

/* ================= Helpers / Macros ================= */

#define MAKE_CAN_ID(dev_id) \
    ((VC_BASE_CAN_ID & 0xFFFF00FFUL) | ((uint32_t)(dev_id) << 8))

#define CTRL_IS_ALIVE(idx) (VS_Controller[(idx)].alive)

#define U16_TO_CAN_LE(buf, idx, val)                                  \
    do {                                                              \
        (buf)[(idx)]     = (uint8_t)((uint16_t)(val) & 0xFFU);        \
        (buf)[(idx) + 1] = (uint8_t)(((uint16_t)(val) >> 8) & 0xFFU); \
    } while (0)

/* LSB then MSB */
static uint16_t Current_To_CAN(float current_A)
{
    if (current_A < 0.0f)   current_A = 0.0f;
    if (current_A > 600.0f) current_A = 600.0f;

    /* 0.1 A per bit, rounded */
    return (uint16_t)(current_A * 10.0f + 0.5f);
}

/* ================= VCU Telemetry TX ================= */

void CAN_Tx_VCUData(void)
{
    uint8_t buf[8];
    uint8_t d[8];

    /* ================= ID 201 : Current RPM ================= */
    memset(buf, 0, sizeof(buf));
    U16_TO_CAN_LE(buf, 0, VS_RPM_Wheel_Current);
    U16_TO_CAN_LE(buf, 2, VS_RPM_Rotor);
    buf[4] = VS_CurrentDirection;
    CanMsgTransmit(CAN_0, buf, 8, 0, 0, 201);

    /* ================= ID 202 : Buttons + Temps ================= */
    memset(buf, 0, sizeof(buf));
    buf[0] = VS_TurnLeft;
    buf[1] = VS_TurnRight;
    buf[2] = VS_KillSwitch;
    buf[3] = VS_Direction;
    U16_TO_CAN_LE(buf, 4, VS_Controller[CTRL_ROTOR].motor_temp_C);
    CanMsgTransmit(CAN_0, buf, 8, 0, 0, 202);

    /* ================= ID 204 : Current Sensors ================= */
    memset(buf, 0, sizeof(buf));
    buf[0] = 0x03; /* MUX */
    U16_TO_CAN_LE(buf, 1, Current_To_CAN(VS_Current_1_A));
    U16_TO_CAN_LE(buf, 3, Current_To_CAN(VS_Current_2_A));
    U16_TO_CAN_LE(buf, 5, Current_To_CAN(VS_Current_3_A));
    CanMsgTransmit(CAN_0, buf, 8, 0, 0, 204);

    /* ================= ID 205 : RPM Outputs ================= */
    memset(buf, 0, sizeof(buf));
    buf[0] = 0x04; /* MUX */
    U16_TO_CAN_LE(buf, 1, VS_RPM_Left);
    U16_TO_CAN_LE(buf, 3, VS_RPM_Right);
    U16_TO_CAN_LE(buf, 5, VS_RPM_Rotor);
    CanMsgTransmit(CAN_0, buf, 8, 0, 0, 205);

    /* ================= ID 206 : Throttle ================= */
    memset(buf, 0, sizeof(buf));
    buf[0] = 0x05; /* MUX */
    U16_TO_CAN_LE(buf, 1, VS_Throttle_Wheel);
    U16_TO_CAN_LE(buf, 3, VS_Throttle_Rotor);
    CanMsgTransmit(CAN_0, buf, 8, 0, 0, 206);

    /* ================= ID 208 : RW Currents =================
       (Kept payload layout exactly as your current code: bytes 1..6 used, byte 0 left 0) */
    memset(buf, 0, sizeof(buf));
    U16_TO_CAN_LE(buf, 1, VS_RWCurrent_1_A);
    U16_TO_CAN_LE(buf, 3, VS_RWCurrent_2_A);
    U16_TO_CAN_LE(buf, 5, VS_RWCurrent_3_A);
    CanMsgTransmit(CAN_0, buf, 8, 0, 0, 208);

    /* ================= ID 191 : Battery Voltage ================= */
    memset(d, 0, sizeof(d));
    if (VS_Battery1.Alive)
    {
        d[0] = (uint8_t)VS_Battery1.MOSFET_Temp_C;
        U16_TO_CAN_LE(d, 2, VS_Battery1.Voltage_dV);
        d[6] = VS_Battery1.Switch_Status;
    }
    if (VS_Battery2.Alive)
    {
        d[1] = (uint8_t)VS_Battery2.MOSFET_Temp_C;
        U16_TO_CAN_LE(d, 4, VS_Battery2.Voltage_dV);
        d[7] = VS_Battery2.Switch_Status;
    }
    CanMsgTransmit(CAN_0, d, 8, 0, 0, 191);

    /* ================= ID 192 : Battery Current ================= */
    memset(d, 0, sizeof(d));
    if (VS_Battery1.Alive)
    {
        U16_TO_CAN_LE(d, 0, (uint16_t)VS_Battery1.Current_dA);
        U16_TO_CAN_LE(d, 4, VS_Battery1.Cycles);
    }
    if (VS_Battery2.Alive)
    {
        U16_TO_CAN_LE(d, 2, (uint16_t)VS_Battery2.Current_dA);
        U16_TO_CAN_LE(d, 6, VS_Battery2.Cycles);
    }
    CanMsgTransmit(CAN_0, d, 8, 0, 0, 192);

    /* ================= ID 193 : SOC / SOH ================= */
    memset(d, 0, sizeof(d));
    if (VS_Battery1.Alive)
    {
        d[0] = VS_Battery1.SOC;
        d[2] = VS_Battery1.SOH;
    }
    if (VS_Battery2.Alive)
    {
        d[1] = VS_Battery2.SOC;
        d[3] = VS_Battery2.SOH;
    }
    CanMsgTransmit(CAN_0, d, 8, 0, 0, 193);
}

/* ================= Controller Telemetry TX ================= */

void Controller_Data_Tx(void)
{
    uint8_t buf[8];

    /* LEFT WHEEL (0x12D) */
    memset(buf, 0, sizeof(buf));
    if (CTRL_IS_ALIVE(CTRL_WHEEL_LEFT))
    {
        U16_TO_CAN_LE(buf, 0, VS_Controller[CTRL_WHEEL_LEFT].speed_rpm);
        U16_TO_CAN_LE(buf, 2, (uint16_t)VS_Controller[CTRL_WHEEL_LEFT].motor_current_A);
        buf[4] = VS_Controller[CTRL_WHEEL_LEFT].controller_temp_C;
        buf[5] = VS_Controller[CTRL_WHEEL_LEFT].feedback_dir;
        U16_TO_CAN_LE(buf, 6, VS_Controller[CTRL_WHEEL_LEFT].error_code);
    }
    CanMsgTransmit(CAN_0, buf, 8, 0, 0, 0x12D);

    /* RIGHT WHEEL (0x12E) */
    memset(buf, 0, sizeof(buf));
    if (CTRL_IS_ALIVE(CTRL_WHEEL_RIGHT))
    {
        U16_TO_CAN_LE(buf, 0, VS_Controller[CTRL_WHEEL_RIGHT].speed_rpm);
        U16_TO_CAN_LE(buf, 2, (uint16_t)VS_Controller[CTRL_WHEEL_RIGHT].motor_current_A);
        buf[4] = VS_Controller[CTRL_WHEEL_RIGHT].controller_temp_C;
        buf[5] = VS_Controller[CTRL_WHEEL_RIGHT].feedback_dir;
        U16_TO_CAN_LE(buf, 6, VS_Controller[CTRL_WHEEL_RIGHT].error_code);
    }
    CanMsgTransmit(CAN_0, buf, 8, 0, 0, 0x12E);

    /* ROTOR (0x12F) */
    memset(buf, 0, sizeof(buf));
    if (CTRL_IS_ALIVE(CTRL_ROTOR))
    {
        U16_TO_CAN_LE(buf, 0, VS_Controller[CTRL_ROTOR].speed_rpm);
        U16_TO_CAN_LE(buf, 2, (uint16_t)VS_Controller[CTRL_ROTOR].motor_current_A);
        buf[4] = VS_Controller[CTRL_ROTOR].controller_temp_C;
        buf[5] = VS_Controller[CTRL_ROTOR].feedback_dir;
        U16_TO_CAN_LE(buf, 6, VS_Controller[CTRL_ROTOR].error_code);
    }
    CanMsgTransmit(CAN_0, buf, 8, 0, 0, 0x12F);
}

/* ================= Controller Command TX ================= */

static uint8_t Build_Status_Byte(uint8_t direction)
{
    uint8_t status = 0U;

    /*
      direction:
      0 = STOP
      1 = FWD
      2 = REV
    */
    status |= (direction & 0x03U);  /* bits [1:0] */
    return status;                 /* brake/reserved remain 0 */
}

static void Send_RPM_To_Controller(uint8_t device_id, uint16_t rpm, uint8_t enable)
{
    uint8_t CanData[8];

    /* Fully deterministic payload */
    memset(CanData, 0, sizeof(CanData));

    CanData[0] = (uint8_t)(rpm & 0xFFU);
    CanData[1] = (uint8_t)((rpm >> 8) & 0xFFU);
    CanData[2] = (enable != 0U) ? 1U : 0U;
    CanData[3] = Build_Status_Byte(VS_CurrentDirection);

    CanMsgTransmit(
        CAN_2,
        CanData,
        8,
        0,
        1, /* Extended ID */
        MAKE_CAN_ID(device_id)
    );
}

/* ================= Direction helper ================= */

void CAN_functionality_BT(void)
{
    uint8_t en_left;
    uint8_t en_right;

    /* Kill switch ALWAYS wins */
    if (VS_KillSwitch == 0U)
    {
        Send_RPM_To_Controller(VC_WHEEL_LEFT_ID,  0U, 0U);
        Send_RPM_To_Controller(VC_WHEEL_RIGHT_ID, 0U, 0U);
        Send_RPM_To_Controller(VC_ROTOR_ID,       0U, 0U);
        return;
    }

    en_left  = (VS_RPM_Left  > 0U) ? 1U : 0U;
    en_right = (VS_RPM_Right > 0U) ? 1U : 0U;

    Send_RPM_To_Controller(VC_WHEEL_LEFT_ID,  VS_RPM_Left,  en_left);
    Send_RPM_To_Controller(VC_WHEEL_RIGHT_ID, VS_RPM_Right, en_right);

    /* Rotor motor */
    if (VS_RotorEnable != 0U)
    {
        Send_RPM_To_Controller(VC_ROTOR_ID, VS_RPM_Rotor, 1U);
    }
    else
    {
        Send_RPM_To_Controller(VC_ROTOR_ID, 0U, 0U);
    }
}

void Vehicle_ReadInputs(void)
{
    /* ADC */
    VS_Throttle_Wheel = Get_ADC_Result(G3_ADC1_E);
    VS_Throttle_Rotor = Get_ADC_Result(G4_ADC2_E);

    /* GPIO */
    VS_KillSwitch = Get_GPInput_State(B2_GPINUPUT1_E);
    VS_TurnLeft   = Get_GPInput_State(C2_GPINUPUT2_E);
    VS_TurnRight  = Get_GPInput_State(D2_GPINUPUT3_E);
    VS_Direction  = Get_GPInput_State(E2_GPINUPUT4_E);
}

void Battery_Timeout_Task(uint16_t task_period_ms)
{
    /* Battery 1 */
    if (VS_Battery1.RxTimeoutMs > task_period_ms)
    {
        VS_Battery1.RxTimeoutMs -= task_period_ms;
    }
    else
    {
        VS_Battery1.RxTimeoutMs = 0U;
        VS_Battery1.Alive = 0U;

        VS_Battery1.Voltage_dV = 0U;
        VS_Battery1.Current_dA = 0;
        VS_Battery1.SOC        = 0U;
        VS_Battery1.SOH        = 0U;
    }

    /* Battery 2 */
    if (VS_Battery2.RxTimeoutMs > task_period_ms)
    {
        VS_Battery2.RxTimeoutMs -= task_period_ms;
    }
    else
    {
        VS_Battery2.RxTimeoutMs = 0U;
        VS_Battery2.Alive = 0U;

        VS_Battery2.Voltage_dV = 0U;
        VS_Battery2.Current_dA = 0;
        VS_Battery2.SOC        = 0U;
        VS_Battery2.SOH        = 0U;
    }
}

void CAN_functionality(void)
{
    /* SAFETY: KILL SWITCH */
    if (VS_KillSwitch == 0U)
    {
        Send_RPM_To_Controller(VC_WHEEL_LEFT_ID,  0U, 0U);
        Send_RPM_To_Controller(VC_WHEEL_RIGHT_ID, 0U, 0U);
        Send_RPM_To_Controller(VC_ROTOR_ID,       0U, 0U);
        return;
    }

    /* Wheel motors (kept exactly: always enabled here) */
    Send_RPM_To_Controller(VC_WHEEL_LEFT_ID,  VS_RPM_Left,  1U);
    Send_RPM_To_Controller(VC_WHEEL_RIGHT_ID, VS_RPM_Right, 1U);

    /* Rotor motor */
    if (VS_RotorEnable != 0U)
    {
        Send_RPM_To_Controller(VC_ROTOR_ID, VS_RPM_Rotor, 1U);
    }
    else
    {
        Send_RPM_To_Controller(VC_ROTOR_ID, 0U, 0U);
    }
}

/* 100 ms task */
void Battery_Timeout_Task_100ms(void)
{
    Battery_Timeout_Task(10000U);
}

void Vehicle_Task_10ms(void)
{
    OnRoad_Mode_Step();
    CAN_functionality();
    /* if (BT_State.mode == BT_MODE_ACTIVE)
    {
        BT_Control_Step();       
        CAN_functionality_BT();  
    }
    else
    {
        OnRoad_Mode_Step();
        CAN_functionality();
    } */ 
}
