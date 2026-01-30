#include "AppTest.h"
#include "databank.h"
#include "pal_can_if.h"
#include "vehicle_state.h"
#include "bt_control_logic.h"
#include "vehicle_config.h"
#include "bt_control_state.h"

#define MAKE_CAN_ID(dev_id) \
    ((VC_BASE_CAN_ID & 0xFFFF00FFUL) | ((uint32_t)(dev_id) << 8))

#define CTRL_IS_ALIVE(idx) (VS_Controller[(idx)].alive)

bool GPIO_PIN_HIGH_b;
bool GPIO_PIN_LOW_b;

uint8_t DataBuff_0[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t DataBuff_1[8] = {1, 1, 1, 1, 1, 1, 1, 1};
uint8_t DataBuff_2[8] = {2, 2, 2, 2, 2, 2, 2, 2};
uint8_t GpioInpdata[8];
uint32_t i;
uint16_t AdcDataBuff[8];
uint8_t Adcresult[8]; 
uint8_t Adcresult1[8];   
uint8_t Switch_var = 0;
uint8_t Switch_var2 = 0;

uint16_t can_cur_1;
uint16_t can_cur_2;
uint16_t can_cur_3;


void Call_Back_CAN0_Tx_Test(uint8_t CanNum_u8, uint8_t Channel_u8, uint8_t *DataBuff_pu8, uint8_t Dlc_u8, uint8_t CanMode_u8, uint8_t Ide_u8, uint32_t CanId_u32)
{
  CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, CanId_u32 + 1);
  return;
}

void Call_Back_CAN1_Tx_Test(uint8_t CanNum_u8, uint8_t Channel_u8, uint8_t *DataBuff_pu8, uint8_t Dlc_u8, uint8_t CanMode_u8, uint8_t Ide_u8, uint32_t CanId_u32)
{
  //CanMsgTransmit(CAN_2, DataBuff_0, 8, 0, 0, CanId_u32 + 1);
  Set_GPO_State(A2_GPOUTPUT1_HS1_E, DataBuff_pu8[0]);
  Set_GPO_State(A3_GPOUTPUT2_HS2_E, DataBuff_pu8[1]);
  Set_GPO_State(B4_GPOUTPUT3_HS3_E, DataBuff_pu8[2]);
  Set_GPO_State(C4_GPOUTPUT4_HS4_E, DataBuff_pu8[3]);
  /* LOW SIDE OUTPUTS*/
  Set_GPO_State(A1_GPOUTPUT5_LS1_E, DataBuff_pu8[4]);
  Set_GPO_State(B1_GPOUTPUT6_LS2_E, DataBuff_pu8[5]);
  Set_GPO_State(C1_GPOUTPUT7_LS3_E, DataBuff_pu8[6]);
  Set_GPO_State(D1_GPOUTPUT8_LS4_E, DataBuff_pu8[7]);
  return;
}

void Call_Back_CAN2_Tx_Test(uint8_t CanNum_u8, uint8_t Channel_u8, uint8_t *DataBuff_pu8, uint8_t Dlc_u8, uint8_t CanMode_u8, uint8_t Ide_u8, uint32_t CanId_u32)
{
  CanMsgTransmit(CAN_2, DataBuff_0, 8, 0, 0, CanId_u32 + 1);

  return;
}

void Test_GpioInput(void)
{
  GpioInpdata[0] = Get_GPInput_State(B2_GPINUPUT1_E); // Read gpio input
  GpioInpdata[1] = Get_GPInput_State(C2_GPINUPUT2_E);
  GpioInpdata[2] = Get_GPInput_State(D2_GPINUPUT3_E);
  GpioInpdata[3] = Get_GPInput_State(E2_GPINUPUT4_E);
  GpioInpdata[4] = Get_GPInput_State(F2_GPINUPUT5_E);
  GpioInpdata[5] = Get_GPInput_State(B3_GPINUPUT6_E);
  GpioInpdata[6] = Get_GPInput_State(C3_GPINUPUT7_E);
  GpioInpdata[7] = Get_GPInput_State(D3_GPINUPUT8_E);
  //CanMsgTransmit(CAN_2, &GpioInpdata[0], 8, 0, 0, 0x300);
  return;
}

void Test_HS_Gpio_Output(void)
{
  GPIO_PIN_HIGH_b = !GPIO_PIN_HIGH_b;

  // Set_GPO_State(A2_GPOUTPUT1_HS1_E, GPIO_PIN_HIGH_b);
  // Set_GPO_State(A3_GPOUTPUT2_HS2_E, GPIO_PIN_HIGH_b);
  // Set_GPO_State(B4_GPOUTPUT3_HS3_E, GPIO_PIN_LOW_b);
  // Set_GPO_State(C4_GPOUTPUT4_HS4_E, GPIO_PIN_LOW_b);
  // return;
}

void Test_LS_Gpio_Output(void)
{

  // Set_GPO_State(A1_GPOUTPUT5_LS1_E, SetLsOutData[0]); // Set gpio input
  // Set_GPO_State(A1_GPOUTPUT5_LS1_E, 1);
  // // Set_GPO_State(B1_GPOUTPUT6_LS2_E, SetLsOutData[1]);
  // Set_GPO_State(B1_GPOUTPUT6_LS2_E, 1);
  // // Set_GPO_State(C1_GPOUTPUT7_LS3_E, SetLsOutData[2]);
  // Set_GPO_State(C1_GPOUTPUT7_LS3_E, 1);
  // // Set_GPO_State(D1_GPOUTPUT8_LS4_E, SetLsOutData[3]);
  // Set_GPO_State(D1_GPOUTPUT8_LS4_E, 1);
}

void Test_GpioOutput(void)
{
  switch (Switch_var2)
  {
  case 0:
  {
    Test_LS_Gpio_Output();
    Switch_var2 = 1;
    break;
  }
  case 1:
  {
    Test_HS_Gpio_Output();
    Switch_var2 = 0;
    break;
  }
  default:
    break;
  }
  return;
}

void Test_Adc(void)
{
  switch (Switch_var)
  {
  case 0:
  {
    AdcDataBuff[0] = Get_ADC_Result(G3_ADC1_E);
    Adcresult[0] = AdcDataBuff[0];
    Adcresult[1] = (AdcDataBuff[0] >> 8);

    AdcDataBuff[1] = Get_ADC_Result(G4_ADC2_E);
    Adcresult[2] = AdcDataBuff[1];
    Adcresult[3] = (AdcDataBuff[1] >> 8);

    AdcDataBuff[2] = Get_ADC_Result(H3_ADC3_E);
    Adcresult[4] = AdcDataBuff[2];
    Adcresult[5] = (AdcDataBuff[2] >> 8);

    AdcDataBuff[3] = Get_ADC_Result(H4_ADC4_E);
    Adcresult[6] = AdcDataBuff[3];
    Adcresult[7] = (AdcDataBuff[3] >> 8);

    
    //CanMsgTransmit(CAN_2, &Adcresult[0], 8, 0, 0, 0x201);
    Switch_var = 1;
    break;
  }
  case 1:
  {
    AdcDataBuff[4] = Get_ADC_Result(J3_ADC5_E);
    Adcresult1[0] = AdcDataBuff[4];
    Adcresult1[1] = (AdcDataBuff[4] >> 8);

    AdcDataBuff[5] = Get_ADC_Result(J4_ADC6_E);
    Adcresult1[2] = AdcDataBuff[5];
    Adcresult1[3] = (AdcDataBuff[5] >> 8);

    AdcDataBuff[6] = Get_ADC_Result(K3_ADC7_E);
    Adcresult1[4] = AdcDataBuff[6];
    Adcresult1[5] = (AdcDataBuff[6] >> 8);

    AdcDataBuff[7] = Get_ADC_Result(K4_ADC8_E);
    Adcresult1[6] = AdcDataBuff[7];
    Adcresult1[7] = (AdcDataBuff[7] >> 8);
    //CanMsgTransmit(CAN_2, &Adcresult1[0], 8, 0, 0, 0x202);
    Switch_var = 0;
    break;
  }
  default:
    break;
  }

  return;
}

void fun1()
{
   CanMsgTransmit(CAN_2, DataBuff_2, 8, 0, 0, 0x183);
}
void fun2()
{
   CanMsgTransmit(CAN_2, DataBuff_2, 8, 0, 0, 0x184);
}
void fun3()
{
   //CanMsgTransmit(CAN_2, DataBuff_2, 8, 0, 0, 0x184);
}
void fun4()
{
   CanMsgTransmit(CAN_0, DataBuff_2, 8, 0, 0, 0x184);
}

//=============================================================================================================================================================================
//LSB AND THEN MSB
static uint16_t Current_To_CAN(float current_A)
{
    /* Negative protection */
    if (current_A < 0.0f)
        current_A = 0.0f;

    /* Upper bound protection */
    if (current_A > 600.0f)
        current_A = 600.0f;

    /* 0.1 A per bit, rounded */
    return (uint16_t)(current_A * 10.0f + 0.5f);
}

#define U16_TO_CAN_LE(buf, idx, val)            \
    do {                                       \
        (buf)[(idx)]     = (uint8_t)((val) & 0xFFU);        \
        (buf)[(idx) + 1] = (uint8_t)(((val) >> 8) & 0xFFU); \
    } while (0)

void CAN_Tx_VCUData(void)
{
    uint8_t DataBuff_0[8];
    uint8_t d[8];

    /* ================= ID 201 : Current RPM ================= */
    memset(DataBuff_0, 0, sizeof(DataBuff_0));
    U16_TO_CAN_LE(DataBuff_0, 0, VS_RPM_Wheel_Current);
    U16_TO_CAN_LE(DataBuff_0, 2, VS_RPM_Rotor);
    DataBuff_0[4] = VS_CurrentDirection;
    CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, 201);

    /* ================= ID 202 : Buttons + Temps ================= */
    memset(DataBuff_0, 0, sizeof(DataBuff_0));
    DataBuff_0[0] = VS_TurnLeft;
    DataBuff_0[1] = VS_TurnRight;
    DataBuff_0[2] = VS_KillSwitch;
    DataBuff_0[3] = VS_Direction;
    U16_TO_CAN_LE(DataBuff_0, 4, VS_Controller[CTRL_ROTOR].motor_temp_C);
    //U16_TO_CAN_LE(DataBuff_0, 6, VS_Controller[CTRL_WHEEL_RIGHT].motor_temp_C);
    CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, 202);   

    /* ================= ID 204 : Current Sensors ================= */
    memset(DataBuff_0, 0, sizeof(DataBuff_0));
    DataBuff_0[0] = 0x03; /* MUX */
    U16_TO_CAN_LE(DataBuff_0, 1, Current_To_CAN(VS_Current_1_A));
    U16_TO_CAN_LE(DataBuff_0, 3, Current_To_CAN(VS_Current_2_A));
    U16_TO_CAN_LE(DataBuff_0, 5, Current_To_CAN(VS_Current_3_A));
    CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, 204);

    /* ================= ID 205 : RPM Outputs ================= */
    memset(DataBuff_0, 0, sizeof(DataBuff_0));
    DataBuff_0[0] = 0x04; /* MUX */
    U16_TO_CAN_LE(DataBuff_0, 1, VS_RPM_Left);
    U16_TO_CAN_LE(DataBuff_0, 3, VS_RPM_Right);
    U16_TO_CAN_LE(DataBuff_0, 5, VS_RPM_Rotor);
    CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, 205);

    /* ================= ID 206 : Throttle ================= */
    memset(DataBuff_0, 0, sizeof(DataBuff_0));
    DataBuff_0[0] = 0x05; /* MUX */
    U16_TO_CAN_LE(DataBuff_0, 1, VS_Throttle_Wheel);
    U16_TO_CAN_LE(DataBuff_0, 3, VS_Throttle_Rotor);
    CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, 206);

    /* ================= ID 207 : Direction FSM ================= */
    //memset(DataBuff_0, 0, sizeof(DataBuff_0));
    //DataBuff_0[0] = 0x06; /* MUX */
    //DataBuff_0[1] = VS_DirState;
    //DataBuff_0[2] = VS_RequestedDirection;
    //U16_TO_CAN_LE(DataBuff_0, 3, VS_DirHoldCounter);
    //CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, 207);

        /* ================= ID 207 : Direction FSM ================= */
    memset(DataBuff_0, 0, sizeof(DataBuff_0));
    U16_TO_CAN_LE(DataBuff_0, 1, VS_RWCurrent_1_A);
    U16_TO_CAN_LE(DataBuff_0, 3, VS_RWCurrent_2_A);
    U16_TO_CAN_LE(DataBuff_0, 5, VS_RWCurrent_3_A);
    CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, 208);
/* ================= ID 191 : Battery Voltage ================= */
    memset(d, 0, sizeof(d));
    /* Battery 1 */
    if (VS_Battery1.Alive)
    {
        d[0] = (uint8_t)VS_Battery1.MOSFET_Temp_C;
        U16_TO_CAN_LE(d, 2, VS_Battery1.Voltage_dV);
        d[6] = VS_Battery1.Switch_Status;
    }
    /* Battery 2 */
    if (VS_Battery2.Alive)
    {
        d[1] = (uint8_t)VS_Battery2.MOSFET_Temp_C;
        U16_TO_CAN_LE(d, 4, VS_Battery2.Voltage_dV);
        d[7] = VS_Battery2.Switch_Status;
    }
    CanMsgTransmit(CAN_0, d, 8, 0, 0, 191);

/* ================= ID 192 : Battery Current ================= */
    memset(d, 0, sizeof(d));
    /* Battery 1 */
    if (VS_Battery1.Alive)
    {
        U16_TO_CAN_LE(d, 0, (uint16_t)VS_Battery1.Current_dA);
        U16_TO_CAN_LE(d, 4, VS_Battery1.Cycles);
    }
    /* Battery 2 */
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

void Controller_Data_Tx(void)
{
    uint8_t DataBuff_0[8];
    //uint32_t CanId_u32;
    /* ================= LEFT WHEEL ================= */
    memset(DataBuff_0, 0, sizeof(DataBuff_0));
    if (CTRL_IS_ALIVE(CTRL_WHEEL_LEFT))
    {
        U16_TO_CAN_LE(DataBuff_0, 0, VS_Controller[CTRL_WHEEL_LEFT].speed_rpm);
        U16_TO_CAN_LE(DataBuff_0, 2, (uint16_t)VS_Controller[CTRL_WHEEL_LEFT].motor_current_A);
        DataBuff_0[4] = VS_Controller[CTRL_WHEEL_LEFT].controller_temp_C;
        DataBuff_0[5] = VS_Controller[CTRL_WHEEL_LEFT].feedback_dir;
        U16_TO_CAN_LE(DataBuff_0, 6, VS_Controller[CTRL_WHEEL_LEFT].error_code);
    }
    CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, 0x12D);
    /* ================= RIGHT WHEEL ================= */
    memset(DataBuff_0, 0, sizeof(DataBuff_0));
    if (CTRL_IS_ALIVE(CTRL_WHEEL_RIGHT))
    {
        U16_TO_CAN_LE(DataBuff_0, 0, VS_Controller[CTRL_WHEEL_RIGHT].speed_rpm);
        U16_TO_CAN_LE(DataBuff_0, 2, (uint16_t)VS_Controller[CTRL_WHEEL_RIGHT].motor_current_A);
        DataBuff_0[4] = VS_Controller[CTRL_WHEEL_RIGHT].controller_temp_C;
        DataBuff_0[5] = VS_Controller[CTRL_WHEEL_RIGHT].feedback_dir;
        U16_TO_CAN_LE(DataBuff_0, 6, VS_Controller[CTRL_WHEEL_RIGHT].error_code);
    }
    CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, 0x12E);
    /* ================= ROTOR ================= */
    memset(DataBuff_0, 0, sizeof(DataBuff_0));
    if (CTRL_IS_ALIVE(CTRL_ROTOR))
    {
        U16_TO_CAN_LE(DataBuff_0, 0, VS_Controller[CTRL_ROTOR].speed_rpm);
        U16_TO_CAN_LE(DataBuff_0, 2, (uint16_t)VS_Controller[CTRL_ROTOR].motor_current_A);
        DataBuff_0[4] = VS_Controller[CTRL_ROTOR].controller_temp_C;
        DataBuff_0[5] = VS_Controller[CTRL_ROTOR].feedback_dir;
        U16_TO_CAN_LE(DataBuff_0, 6, VS_Controller[CTRL_ROTOR].error_code);
    }
    CanMsgTransmit(CAN_0, DataBuff_0, 8, 0, 0, 0x12F);
}

static uint8_t Build_Status_Byte(uint8_t direction)
{
    uint8_t status = 0U;
/*
direction:
0 = STOP
1 = FWD
2 = REV
*/
    /* Direction → bits [1:0] */
    status |= (direction & 0x03U);

    /* brake switch = 0 (BIT2), rest reserved = 0 */
    return status;
}

static void Send_RPM_To_Controller(uint8_t device_id, uint16_t rpm, uint8_t enable)
{
    uint8_t CanData[8];

    CanData[0] = (uint8_t)(rpm & 0xFF);          /* RPM LSB */
    CanData[1] = (uint8_t)((rpm >> 8) & 0xFF);   /* RPM MSB */
    CanData[2] = enable ? 1U : 0U;               /* Enable */

    /* ✅ Correct status byte */
    CanData[3] = Build_Status_Byte(VS_CurrentDirection);

    CanData[4] = 0U;
    CanData[5] = 0U;
    CanData[6] = 0U;
    CanData[7] = 0U;

    CanMsgTransmit(
        CAN_2,
        CanData,
        8,
        0,
        1,                      /* Extended ID */
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
        Send_RPM_To_Controller(
            VC_ROTOR_ID,
            VS_RPM_Rotor,
            1U
        );
    }
    else
    {
        Send_RPM_To_Controller(
            VC_ROTOR_ID,
            0U,
            0U
        );
    }
}

void Vehicle_ReadInputs(void)
{
    /* -------- ADC -------- */
    VS_Throttle_Wheel = Get_ADC_Result(G3_ADC1_E);
    VS_Throttle_Rotor = Get_ADC_Result(G4_ADC2_E);

    /* -------- GPIO -------- */
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
        /* Timeout expired */
        VS_Battery1.RxTimeoutMs = 0U;
        VS_Battery1.Alive = 0U;

        /* Invalidate data */
        VS_Battery1.Voltage_dV = 0U;
        VS_Battery1.Current_dA = 0;
        VS_Battery1.SOC        = 0U;
        VS_Battery1.SOH        = 0U;
    }

    /* Battery 2 — same logic */
        if (VS_Battery2.RxTimeoutMs > task_period_ms)
    {
        VS_Battery2.RxTimeoutMs -= task_period_ms;
    }
    else
    {
        /* Timeout expired */
        VS_Battery2.RxTimeoutMs = 0U;
        VS_Battery2.Alive = 0U;

        /* Invalidate data */
        VS_Battery2.Voltage_dV = 0U;
        VS_Battery2.Current_dA = 0;
        VS_Battery2.SOC        = 0U;
        VS_Battery2.SOH        = 0U;
    }
}

/*void CAN_functionality(void)
{
    //ADC_Service_Run();
    //GPIO_Service_Run();
    Vehicle_SendState_CAN1();
}*/

void CAN_functionality(void)
{
    //uint8_t direction_cmd;
    //Controller_Data_Tx();
    //CAN_Tx_VCUData(202);

    /* ================= SAFETY: KILL SWITCH ================= */
    if (VS_KillSwitch == 0U)
    {
        /* Disable all controllers */
        Send_RPM_To_Controller(VC_WHEEL_LEFT_ID,  0U, 0U);
        Send_RPM_To_Controller(VC_WHEEL_RIGHT_ID, 0U, 0U);
        Send_RPM_To_Controller(VC_ROTOR_ID,       0U, 0U);
        return;
    }

    /* ================= DIRECTION ================= */
    //direction_cmd = VS_CurrentDirection;  
    /* MUST be 1 = FWD, 2 = REV (already guaranteed by logic) */

    /* ================= WHEEL MOTORS ================= */
    Send_RPM_To_Controller(
        VC_WHEEL_LEFT_ID,
        VS_RPM_Left,
        1U                 /* enable */
    );

    Send_RPM_To_Controller(
        VC_WHEEL_RIGHT_ID,
        VS_RPM_Right,
        1U
    );

    /* ================= ROTOR MOTOR ================= */
    if (VS_RotorEnable != 0U)
    {
        Send_RPM_To_Controller(
            VC_ROTOR_ID,
            VS_RPM_Rotor,
            1U
        );
    }
    else
    {
        Send_RPM_To_Controller(
            VC_ROTOR_ID,
            0U,
            0U);
    }
    //Battery_Timeout_Task(500U);
}
/* 100 ms task */
void Battery_Timeout_Task_100ms(void)
{
    Battery_Timeout_Task(10000U);
}

void Vehicle_Task_10ms(void)
{
    if (BT_State.mode == BT_MODE_ACTIVE)
    {
        BT_Control_Step();          /* sets VS_RPM_* + direction */
        CAN_functionality_BT();    /* ONLY controller commands */
    }
    else
    {
        OnRoad_Mode_Step();
        CAN_functionality();
    }
}
