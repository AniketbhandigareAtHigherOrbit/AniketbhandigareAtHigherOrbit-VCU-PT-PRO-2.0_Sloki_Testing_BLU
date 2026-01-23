#include "app_typedef.h"
#include "vehicle_config.h"

/* =========================================================
 *  ADC CONFIG
 * ========================================================= */
const uint16_t VC_ADC_MAX_VALUE = 4095U;   /* 12-bit ADC */

/* =========================================================
 *  RPM CONFIG
 * ========================================================= */
const uint16_t VC_WHEEL_MAX_RPM = 1300U;
const uint16_t VC_ROTOR_MAX_RPM = 3000U;

/* =========================================================
 *  CONTROLLER DEVICE IDs
 * ========================================================= */
const uint8_t VC_WHEEL_LEFT_ID  = 4U;
const uint8_t VC_WHEEL_RIGHT_ID = 6U;
const uint8_t VC_ROTOR_ID       = 5U;

/* =========================================================
 *  CAN CONFIG
 * ========================================================= */
const uint8_t VC_CAN_ENABLE_DEFAULT = 1U;
const uint8_t VC_DIRECTION_DEFAULT  = 1U;   /* 1 = FWD */

/* =========================================================
 *  CAN BASE ID (Message 3)
 * ========================================================= */
const uint32_t VC_BASE_CAN_ID = 0x0CF1001EUL;

const uint16_t VC_TURN_REDUCTION_RPM = 100U;
const uint16_t VC_TURN_LOW_RPM = 100U;
