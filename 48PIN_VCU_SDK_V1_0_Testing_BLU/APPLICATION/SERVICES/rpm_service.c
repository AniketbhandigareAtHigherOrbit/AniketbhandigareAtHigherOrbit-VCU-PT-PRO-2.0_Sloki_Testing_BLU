#include "vehicle_state.h"
#include "vehicle_config.h"
/* =========================================================
 *  CONFIG
 * ========================================================= */
#define ADC_MAX_VALUE        4095U

#define WHEEL_MAX_RPM        1500U
#define ROTOR_MAX_RPM        3000U

#define ADC_DEADBAND         80U     /* small noise rejection */

/* =========================================================
 *  RPM SERVICE
 *  Converts ADC throttle values to RPM
 * ========================================================= */
void RPM_Service_Run(void)
{
    /* -------- Wheel motor -------- */
    if (VS_Throttle_Wheel <= ADC_DEADBAND)
    {
        VS_RPM_Wheel = 0;
    }
    else
    {
        VS_RPM_Wheel =
            (uint16_t)(((VS_Throttle_Wheel - ADC_DEADBAND) * WHEEL_MAX_RPM) /
                       (ADC_MAX_VALUE - ADC_DEADBAND));
    }

    /* -------- Rotor motor -------- */
    if (VS_Throttle_Rotor <= ADC_DEADBAND)
    {
        VS_RPM_Rotor = 0;
    }
    else
    {
        VS_RPM_Rotor =
            (uint16_t)(((VS_Throttle_Rotor - ADC_DEADBAND) * ROTOR_MAX_RPM) /
                       (ADC_MAX_VALUE - ADC_DEADBAND));
    }
}
