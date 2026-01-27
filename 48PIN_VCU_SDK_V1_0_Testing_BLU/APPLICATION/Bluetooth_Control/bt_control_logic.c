#include "bt_control_logic.h"
#include "bt_control_state.h"
#include "bt_control_config.h"
#include "vehicle_state.h"

/* ================= Slew ================= */

static uint16_t Slew(uint16_t target,
                     uint16_t current,
                     uint16_t step)
{
    if (target > current + step)
        return current + step;
    if (current > target + step)
        return current - step;
    return target;
}

void BT_Control_Step(void)
{
    uint16_t base;
    uint16_t diff;

        /* Bluetooth owns direction */
    if (BT_State.drive_dir == 1U)
    {
        VS_CurrentDirection = 1U;   /* FWD */
    }
    else if (BT_State.drive_dir == 2U)
    {
        VS_CurrentDirection = 2U;   /* REV */
    }
    else
    {
        VS_CurrentDirection = 0U;   /* STOP */
    }

    if (BT_State.mode != BT_MODE_ACTIVE)
        return;

    /* ================= WATCHDOG ================= */
    if (BT_State.timeout_ms == 0U)
    {
        BT_Control_Reset();
        return;
    }
    else
    {
        BT_State.timeout_ms -= BT_TASK_PERIOD_MS;
    }

    /* ================= DIRECTION ================= */
    VS_CurrentDirection = BT_State.drive_dir;

    /* ================= BASE RPM ================= */
    base = BT_State.target_rpm;
    if (base > BT_MAX_WHEEL_RPM)
        base = BT_MAX_WHEEL_RPM;

    base = Slew(base, VS_RPM_Wheel_Current, BT_RPM_SLEW_RATE);
    VS_RPM_Wheel_Current = base;

    /* ================= STEERING ================= */
    diff = (base * BT_TURN_DIFF_PERCENT) / 100U;

    if (BT_State.steering == 1U) /* LEFT */
    {
        VS_RPM_Left  = base - diff;
        VS_RPM_Right = base + diff;
    }
    else if (BT_State.steering == 2U) /* RIGHT */
    {
        VS_RPM_Left  = base + diff;
        VS_RPM_Right = base - diff;
    }
    else
    {
        VS_RPM_Left  = base;
        VS_RPM_Right = base;
    }

    /* ================= ROTOR ================= */
    if (BT_State.rotor_enable)
    {
        VS_RPM_Rotor =
            Slew(BT_MAX_ROTOR_RPM,
                 VS_RPM_Rotor,
                 BT_RPM_SLEW_RATE);
    }
    else
    {
        VS_RPM_Rotor =
            Slew(0U,
                 VS_RPM_Rotor,
                 BT_RPM_SLEW_RATE);
    }
}

