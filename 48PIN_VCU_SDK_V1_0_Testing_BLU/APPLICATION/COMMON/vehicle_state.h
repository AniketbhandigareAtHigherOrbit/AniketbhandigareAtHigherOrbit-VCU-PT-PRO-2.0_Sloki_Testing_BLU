#ifndef VEHICLE_STATE_H
#define VEHICLE_STATE_H

#include "app_typedef.h"

/* ================= Inputs ================= */
extern uint16_t VS_RPM_Wheel_Target;
extern uint16_t VS_RPM_Wheel_Current;

extern uint16_t VS_Throttle_Wheel;
extern uint16_t VS_Throttle_Rotor;

extern uint8_t  VS_KillSwitch;
extern uint8_t  VS_TurnLeft;
extern uint8_t  VS_TurnRight;

extern uint8_t  VS_Direction_Request;
extern uint8_t  VS_Direction;
extern uint8_t  VS_RotorEnable;

/* ================= Outputs ================= */
extern uint16_t VS_RPM_Left;
extern uint16_t VS_RPM_Right;
extern uint16_t VS_RPM_Rotor;
extern uint16_t VS_RPM_Wheel;

extern uint8_t  VS_MotorEnable;

/* ================= Status ================= */
extern uint8_t VS_FaultFlag;

/* ================= GPIO ================= */
extern uint8_t VS_GPIO5;
extern uint8_t VS_GPIO6;
extern uint8_t VS_GPIO7;
extern uint8_t VS_GPIO8;

/* ================= Drive mode ================= */
typedef enum
{
    MODE_IDLE = 0,
    MODE_SINGLE_LEFT,
    MODE_SINGLE_RIGHT
} DriveMode_En_t;

extern DriveMode_En_t VS_DriveMode;

/* ================= Buttons ================= */
extern uint8_t  VS_LeftBtn_Last;
extern uint8_t  VS_RightBtn_Last;

extern uint16_t VS_LeftBtn_HoldMs;
extern uint16_t VS_RightBtn_HoldMs;

/* ================= Direction FSM ================= */
typedef enum
{
    DIR_STATE_IDLE = 0,
    DIR_STATE_RAMP_DOWN,
    DIR_STATE_NEUTRAL,
    DIR_STATE_RAMP_UP
} DirectionState_En_t;

typedef enum
{
    DIR_STOP    = 0U,
    DIR_FORWARD = 1U,
    DIR_REVERSE = 2U
} Direction_t;

extern DirectionState_En_t VS_DirState;
extern uint8_t  VS_CurrentDirection;
extern uint8_t  VS_RequestedDirection;
extern uint16_t VS_DirHoldCounter;
extern uint8_t VS_KillSwitchPrev;
extern uint8_t VS_KillRecoveryActive;
extern uint16_t VS_TurnIntensity;
extern uint16_t VS_TurnHoldTime_ms;


/* ================= Controller ================= */
typedef enum
{
    CTRL_WHEEL_LEFT = 0,
    CTRL_WHEEL_RIGHT,
    CTRL_ROTOR,
    CTRL_COUNT
} ControllerIndex_t;

typedef struct
{
    uint16_t speed_rpm;
    int16_t  motor_current_A;
    uint16_t battery_voltage_dV;

    uint8_t  controller_temp_C;
    uint8_t  motor_temp_C;

    uint16_t error_code;

    uint8_t  feedback_dir;
    uint8_t  command_dir;
    uint8_t  switch_status;

    uint8_t  alive;
} ControllerState_t;

extern ControllerState_t VS_Controller[CTRL_COUNT];

/* ================= Currents ================= */
extern float VS_Current_1_A;
extern float VS_Current_2_A;
extern float VS_Current_3_A;

extern uint16_t VS_RWCurrent_1_A;
extern uint16_t VS_RWCurrent_2_A;
extern uint16_t VS_RWCurrent_3_A;
/* ================= Battery ================= */
typedef struct
{
    uint16_t Voltage_dV;
    int16_t  Current_dA;
    uint8_t  SOC;
    uint8_t  SOH;
    uint16_t Cycles;
    uint16_t Capacity;

    uint8_t  Switch_Status;
    int8_t   Ambient_Temp_C;
    int8_t   MOSFET_Temp_C;

    uint8_t  Alive;
    uint16_t RxTimeoutMs;
} BatteryState_t;

extern BatteryState_t VS_Battery1;
extern BatteryState_t VS_Battery2;

#endif /* VEHICLE_STATE_H */
