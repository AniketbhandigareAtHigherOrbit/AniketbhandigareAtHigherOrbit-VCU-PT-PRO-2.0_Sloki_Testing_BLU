#include "on_road_logic.h"
#include "vehicle_state.h"
#include "vehicle_config.h"

static uint16_t VS_DirNeutralTimer_ms = 0U;
static uint16_t VS_TurnHoldTime_ms   = 0U;
static uint16_t VS_TurnGradDiff_RPM = 0U;
static uint8_t VS_TurnPrev = 0U;
#define ONROAD_TASK_PERIOD_MS  10U

/* ================= Helper: ADC → RPM ================= */
static uint16_t Throttle_To_RPM(uint16_t adc)
{
    return (uint32_t)adc * VC_WHEEL_MAX_RPM / VC_ADC_MAX_VALUE;
}

/* ================= Helper: Slew limiter ================= */
static uint16_t Apply_RPM_Slew(uint16_t target,
                               uint16_t current,
                               uint16_t slew)
{
    if (target > current + slew)
    {
        return current + slew;
    }
    else if (current > target + slew)
    {
        return current - slew;
    }
    else
    {
        return target;
    }
}

/* ===================================================== */
/*                  ON-ROAD MODE STEP                    */
/* ===================================================== */
void OnRoad_Mode_Step(void)
{
    uint16_t base_rpm;
    uint16_t rotor_rpm;
    uint8_t  requested_dir;
    uint16_t target_left_rpm;
    uint16_t target_right_rpm;
    uint16_t diff;
    uint16_t base;
    uint16_t slew;
    uint8_t turn_now;

    /* =====================================================
    * 1. SAFETY (highest priority)
    * ===================================================== */

    /* Detect KillSwitch rising edge */
    if ((VS_KillSwitchPrev == 0U) && (VS_KillSwitch == 1U))
    {
        VS_KillRecoveryActive = 1U;
    }
    VS_KillSwitchPrev = VS_KillSwitch;

    /* ---------- KillSwitch ACTIVE (OFF = emergency stop) ---------- */
    if (VS_KillSwitch == 0U)
    {
        /* Stop all actuators */
        VS_RPM_Left  = 0U;
        VS_RPM_Right = 0U;
        VS_RPM_Rotor = 0U;

        VS_RPM_Wheel_Current = 0U;

        /* Reset direction control */
        VS_CurrentDirection = DIR_STOP;
        VS_DirState         = DIR_STATE_IDLE;
        VS_DirHoldCounter   = 0U;
        VS_DirNeutralTimer_ms = 0U;

        /* ---------- HARD RESET TURN MEMORY ---------- */
        VS_TurnIntensity    = 0U;
        VS_TurnHoldTime_ms  = 0U;
        VS_TurnGradDiff_RPM = 0U;
        VS_TurnEntryTime_ms = 0U;
        VS_TurnPrev         = 0U;

        /* ---------- Prevent aggressive recovery ---------- */
        VS_KillRecoveryActive = 0U;

        return;
    }
    
    if (VS_KillRecoveryActive == 1U)
    {
        if (VS_RPM_Wheel_Current < VC_KILL_RECOVERY_RPM_LIMIT)
        {
            VS_RPM_Wheel_Current = base_rpm;
        }
        else
        {
            VS_RPM_Wheel_Current =
                Apply_RPM_Slew(base_rpm,
                            VS_RPM_Wheel_Current,
                            VC_RPM_SLEW_RATE);
        }

        VS_KillRecoveryActive = 0U;
    }

        /* =====================================================
    * DIRECTION REQUEST HANDLING (level-based, safe)
    * ===================================================== */
    

    /* Map GPIO level to direction enum */
    requested_dir = (VS_Direction_Request == 0U) ?
                    DIR_FORWARD :
                    DIR_REVERSE;

    /* Accept new request ONLY when FSM is idle */
    if ((requested_dir != VS_Direction) &&
        (VS_DirState == DIR_STATE_IDLE))
    {
        VS_Direction = requested_dir;
    }

    /* =====================================================
     * 2. DIRECTION REQUEST (edge-triggered)
     * ===================================================== */
    if ((VS_Direction != VS_CurrentDirection) &&
        (VS_DirState == DIR_STATE_IDLE))
    {
        VS_RequestedDirection = VS_Direction;
        VS_DirState = DIR_STATE_RAMP_DOWN;
    }

    /* =====================================================
     * 3. DIRECTION STATE MACHINE (exclusive owner of RPM)
     * ===================================================== */
    if (VS_DirState != DIR_STATE_IDLE)
    {
        switch (VS_DirState)
        {
            case DIR_STATE_RAMP_DOWN:
                if (VS_RPM_Wheel_Current > VC_DIR_RAMP_STEP_RPM)
                {
                    VS_RPM_Wheel_Current -= VC_DIR_RAMP_STEP_RPM;
                }
                else
                {
                    VS_RPM_Wheel_Current = 0U;
                    VS_DirHoldCounter = 0U;
                    VS_DirState = DIR_STATE_NEUTRAL;
                    VS_DirNeutralTimer_ms = 0U;   // IMPORTANT
                }
                break;

            case DIR_STATE_NEUTRAL:
                VS_RPM_Wheel_Current = 0U;

                VS_DirNeutralTimer_ms += ONROAD_TASK_PERIOD_MS;

                if (VS_DirNeutralTimer_ms >= VC_DIR_NEUTRAL_TIME_MS)
                {
                    VS_DirNeutralTimer_ms = 0U;
                    VS_CurrentDirection = VS_RequestedDirection;
                    VS_DirState = DIR_STATE_RAMP_UP;
                }
                break;


            case DIR_STATE_RAMP_UP:
                base_rpm = Throttle_To_RPM(VS_Throttle_Wheel);

                if (VS_RPM_Wheel_Current + VC_DIR_RAMP_STEP_RPM < base_rpm)
                {
                    VS_RPM_Wheel_Current += VC_DIR_RAMP_STEP_RPM;
                }
                else
                {
                    VS_RPM_Wheel_Current = base_rpm;
                    VS_DirState = DIR_STATE_IDLE;
                }
                break;

            default:
                VS_DirState = DIR_STATE_IDLE;
                break;
        }
    }
    else
    {
        /* =====================================================
         * 4. THROTTLE → BASE RPM (ONLY WHEN FSM IDLE)
         * ===================================================== */
        base_rpm = Throttle_To_RPM(VS_Throttle_Wheel);

        if (base_rpm < VC_THROTTLE_DEAD_ZONE)
        {
            base_rpm = 0U;
        }

        /* =====================================================
         * 5. SLEW LIMITING
         * ===================================================== */
        if (VS_KillRecoveryActive == 1U)
        {
            /* Jump-start RPM to avoid dead feel */
            VS_RPM_Wheel_Current = base_rpm;

            /* Disable recovery after first cycle */
            VS_KillRecoveryActive = 0U;
        }
        else
        {
            VS_RPM_Wheel_Current =
                Apply_RPM_Slew(base_rpm,
                            VS_RPM_Wheel_Current,
                            VC_RPM_SLEW_RATE);
        }
    }
        
    /* =====================================================
    * 6. TURN LOGIC (LEFT / RIGHT) — JERK-FREE
    * ===================================================== */
    /* =====================================================
    * 6A. DUAL TURN OVERRIDE (LEFT + RIGHT)
    * ===================================================== */
    #if VC_DUAL_TURN_STOP_ENABLE
    if (VS_TurnLeft && VS_TurnRight)
    {
        target_left_rpm  = 0U;
        target_right_rpm = 0U;

        VS_RPM_Left  = Apply_RPM_Slew(0U, VS_RPM_Left,  VC_RPM_SLEW_RATE_EXIT);
        VS_RPM_Right = Apply_RPM_Slew(0U, VS_RPM_Right, VC_RPM_SLEW_RATE_EXIT);

        VS_RPM_Rotor = 0U;

        VS_TurnIntensity    = 0U;
        VS_TurnHoldTime_ms  = 0U;
        VS_TurnGradDiff_RPM = 0U;
        VS_TurnEntryTime_ms = 0U;

        return;
    }
    #endif

    /* =====================================================
    * TURN EDGE DETECTION (for entry softening)
    * ===================================================== */
    turn_now = (VS_TurnLeft || VS_TurnRight);

    if ((turn_now == 1U) && (VS_TurnPrev == 0U))
    {
        VS_TurnEntryTime_ms = 0U;   /* new turn press */
    }
    VS_TurnPrev = turn_now;

    base = VS_RPM_Wheel_Current;

    /* ---------- No turn ---------- */
    if (!VS_TurnLeft && !VS_TurnRight)
    {
        VS_TurnHoldTime_ms   = 0U;
        VS_TurnGradDiff_RPM = 0U;
        VS_TurnEntryTime_ms = 0U;

        VS_TurnIntensity = 0U;

        target_left_rpm  = base;
        target_right_rpm = base;
    }
    else
    {
        /* ---------- Desired differential ---------- */
        diff = (base * VC_TURN_DIFF_RATIO_NUM) / VC_TURN_DIFF_RATIO_DEN;

        /* ---------- Low-speed softening ---------- */
        if (base < VC_TURN_LOW_RPM_LIMIT)
        {
            if (diff < VC_TURN_SOFT_DIFF_MIN)
                diff = VC_TURN_SOFT_DIFF_MIN;
        }
        else
        {
            if (diff < VC_TURN_DIFF_MIN_RPM)
                diff = VC_TURN_DIFF_MIN_RPM;
        }

        if (diff > VC_TURN_DIFF_MAX_RPM)
            diff = VC_TURN_DIFF_MAX_RPM;

        /* =================================================
        * LOW RPM TURN GRADIENT (TIME-BASED)
        * ================================================= */
        if (base < VC_TURN_GRADIENT_RPM_LIMIT)
        {
            if (VS_TurnHoldTime_ms < 60000U)
                VS_TurnHoldTime_ms += ONROAD_TASK_PERIOD_MS;

            if (VS_TurnHoldTime_ms >= VC_TURN_GRADIENT_DELAY_MS)
            {
                if ((VS_TurnHoldTime_ms % VC_TURN_GRADIENT_STEP_MS) == 0U)
                {
                    if (VS_TurnGradDiff_RPM < VC_TURN_GRADIENT_MAX_DIFF)
                        VS_TurnGradDiff_RPM += VC_TURN_GRADIENT_STEP_RPM;
                }
            }
        }
        else
        {
            VS_TurnHoldTime_ms   = 0U;
            VS_TurnGradDiff_RPM = 0U;
        }

        diff += VS_TurnGradDiff_RPM;

        if (diff > VC_TURN_DIFF_MAX_RPM)
            diff = VC_TURN_DIFF_MAX_RPM;

        /* =================================================
        * HIGH / MID RPM ENTRY SOFTENING (NEW)
        * ================================================= */
    #if VC_TURN_ENTRY_SOFTEN_ENABLE
        if ((base >= VC_TURN_ENTRY_RPM_START) &&
            (VS_TurnEntryTime_ms < VC_TURN_ENTRY_TIME_MS))
        {
            uint16_t entry_limit;

            VS_TurnEntryTime_ms += ONROAD_TASK_PERIOD_MS;

            entry_limit =
                (diff * VC_TURN_ENTRY_MAX_RATIO_NUM) /
                VC_TURN_ENTRY_MAX_RATIO_DEN;

            if (diff > entry_limit)
                diff = entry_limit;
        }
    #endif

        /* ---------- Ramp TURN INTENSITY ---------- */
        VS_TurnIntensity =
            Apply_RPM_Slew(diff,
                        VS_TurnIntensity,
                        VC_TURN_INTENSITY_SLEW);

        /* ---------- Apply yaw ---------- */
        if (VS_TurnLeft)
        {
            target_left_rpm =
                (base > VS_TurnIntensity) ?
                (base - VS_TurnIntensity) :
                VC_TURN_INNER_MIN_RPM;

            target_right_rpm = base + (VS_TurnIntensity / 2U);
        }
        else
        {
            target_right_rpm =
                (base > VS_TurnIntensity) ?
                (base - VS_TurnIntensity) :
                VC_TURN_INNER_MIN_RPM;

            target_left_rpm = base + (VS_TurnIntensity / 2U);
        }
    }

    /* ---------- Clamp ---------- */
    if (target_left_rpm > VC_WHEEL_MAX_RPM)
        target_left_rpm = VC_WHEEL_MAX_RPM;

    if (target_right_rpm > VC_WHEEL_MAX_RPM)
        target_right_rpm = VC_WHEEL_MAX_RPM;

    /* ---------- Slew ---------- */
    slew =
        (base < VC_TURN_LOW_RPM_LIMIT) ?
        VC_RPM_SLEW_RATE_TURN_OUTER :
        VC_RPM_SLEW_RATE_TURN_INNER;

    VS_RPM_Left  = Apply_RPM_Slew(target_left_rpm,  VS_RPM_Left,  slew);
    VS_RPM_Right = Apply_RPM_Slew(target_right_rpm, VS_RPM_Right, slew);

    /* =====================================================
     * 7. ROTOR LOGIC (independent)
     * ===================================================== */
    if (VS_RotorEnable == 0U)
    {
        VS_RPM_Rotor = 0U;
    }
    else
    {
        rotor_rpm =
            (uint32_t)VS_Throttle_Rotor *
            VC_MAX_RPM_ROTOR /
            VC_ADC_MAX_VALUE;

        VS_RPM_Rotor =
            (rotor_rpm < VC_ROTOR_DEADZONE_RPM) ? 0U : rotor_rpm;
    }
}
