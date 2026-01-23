#ifndef VEHICLE_CONFIG_H
#define VEHICLE_CONFIG_H

#include "app_typedef.h"
#define VC_RPM_SLEW_RATE        50U   /* RPM per cycle */
#define VC_RPM_SLEW_RATE_TURN   80U
#define VC_RPM_TARGETRPM_TURN   300U
#define VC_THROTTLE_DEAD_ZONE  180U
#define VC_LONG_PRESS_MS        10U   /* long press threshold */
#define VC_SINGLE_WHEEL_LOW_RPM 100U   /* slower wheel RPM */
#define VC_MAX_RPM_ROTOR        3000U
#define VC_ROTOR_DEADZONE_RPM   180U
#define VC_DIR_RAMP_STEP_RPM     80U
#define VC_DIR_NEUTRAL_CYCLES    5U    /* 5 × 10ms = 50ms */
#define VC_DIR_NEUTRAL_TIME_MS   30U   /* same as safety_pause = 0.3s */

/* ================= TURN LOGIC CONFIG ================= */
/* Differential scaling (percentage of base RPM) */
#define VC_TURN_DIFF_RATIO_NUM     1U
#define VC_TURN_DIFF_RATIO_DEN     2U      /* 50% of base RPM */
/* Differential RPM limits */
#define VC_TURN_DIFF_MIN_RPM       200U    /* sharper low-speed turn */
#define VC_TURN_DIFF_MAX_RPM       700U    /* aggressive but safe high-speed */
/* Mid-speed boost */
#define VC_TURN_MID_RPM_START      400U
#define VC_TURN_MID_RPM_END        1000U
#define VC_TURN_MID_BOOST_RPM      250U
/* Inner wheel floor (never stall) */
#define VC_TURN_INNER_MIN_RPM      120U
/* Slew rates during turn */
#define VC_RPM_SLEW_RATE_TURN_INNER  150U
#define VC_RPM_SLEW_RATE_TURN_OUTER  100U
#define VC_TURN_INTENSITY_SLEW     80U   /* how fast turn builds */
#define VC_TURN_LOW_RPM_LIMIT     350U  /* below this, soften turn */
#define VC_TURN_SOFT_DIFF_MIN     80U   /* small diff at low RPM */
/* ---------- Turn intensity slew ---------- */
#define VC_TURN_INTENSITY_SLEW_LOW    80U
#define VC_TURN_INTENSITY_SLEW_HIGH   40U   /* slows entry at high speed */
/* ---------- Turn RPM limits ---------- */
#define VC_TURN_OUTER_BOOST_MAX       250U  /* prevents handle pull */
/* ---------- Turn exit ---------- */
#define VC_RPM_SLEW_RATE_EXIT         150U  /* faster straightening */
#define VC_RPM_SLEW_RATE_TURN         90U
#define VC_TURN_HIGH_RPM_START        900U

/* =========================================================
 *  ADC CONFIG
 * ========================================================= */
extern const uint16_t VC_ADC_MAX_VALUE;

/* =========================================================
 *  RPM CONFIG
 * ========================================================= */
extern const uint16_t VC_WHEEL_MAX_RPM;
extern const uint16_t VC_ROTOR_MAX_RPM;

/* =========================================================
 *  CONTROLLER DEVICE IDs
 * ========================================================= */
extern const uint8_t VC_WHEEL_LEFT_ID;
extern const uint8_t VC_WHEEL_RIGHT_ID;
extern const uint8_t VC_ROTOR_ID;

/* =========================================================
 *  CAN CONFIG
 * ========================================================= */
extern const uint8_t VC_CAN_ENABLE_DEFAULT;
extern const uint8_t VC_DIRECTION_DEFAULT;

/* =========================================================
 *  CAN BASE ID (Message 3)
 * ========================================================= */
extern const uint32_t VC_BASE_CAN_ID;
extern const uint16_t VC_TURN_REDUCTION_RPM;
extern const uint16_t VC_TURN_LOW_RPM;
#endif /* VEHICLE_CONFIG_H */
// battries data ---------------------------------------------------

