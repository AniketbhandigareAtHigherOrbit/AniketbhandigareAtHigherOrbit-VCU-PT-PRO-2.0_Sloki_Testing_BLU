#include "vcu_sensors.h"
#include "vehicle_state.h"

/* =========================================================
 *  ADC INPUTS
 * ========================================================= */
extern uint16_t VS_ADC5;   /* Current Sensor 1 */
extern uint16_t VS_ADC8;   /* Current Sensor 2 */
extern uint16_t VS_ADC3;   /* Current Sensor 3 */

/* =========================================================
 *  ADC CONFIG
 * ========================================================= */
#define ADC_MAX_COUNTS      65535.0f
#define ADC_REF_VOLTAGE     5.0f

/* =========================================================
 *  WCS1700 CONFIG
 * ========================================================= */
#define WCS1700_SENS        0.036f    /* V/A (36 mV/A) */

/* =========================================================
 *  FILTER CONFIG
 * ========================================================= */
#define SENSOR_TASK_PERIOD_MS   10U
#define AVG_WINDOW_MS           100U          /* start small for debug */
#define AVG_SAMPLE_COUNT        (AVG_WINDOW_MS / SENSOR_TASK_PERIOD_MS)

/* =========================================================
 *  STATIC DATA
 * ========================================================= */
static uint32_t sum_adc_1 = 0U;
static uint32_t sum_adc_2 = 0U;
static uint32_t sum_adc_3 = 0U;
static uint16_t sample_counter = 0U;

/* ZERO OFFSET (ADC COUNTS) */
static float zero_adc_1 = 0.0f;
static float zero_adc_2 = 0.0f;
static float zero_adc_3 = 0.0f;

/* =========================================================
 *  INIT – MUST BE CALLED WITH **NO CURRENT FLOW**
 * ========================================================= */
void VCU_Sensors_Init(void)
{
    /* Capture true zero-current ADC offset */
    zero_adc_1 = (float)VS_ADC5;
    zero_adc_2 = (float)VS_ADC8;
    zero_adc_3 = (float)VS_ADC3;

    sum_adc_1 = 0U;
    sum_adc_2 = 0U;
    sum_adc_3 = 0U;
    sample_counter = 0U;

    VS_Current_1_A = 0.0f;
    VS_Current_2_A = 0.0f;
    VS_Current_3_A = 0.0f;

    VS_RWCurrent_1_A = 0U;
    VS_RWCurrent_2_A = 0U;
    VS_RWCurrent_3_A = 0U;
}

/* =========================================================
 *  10ms SENSOR TASK
 * ========================================================= */
void VCU_Sensors_10ms(void)
{
    float avg_adc_1;
    float avg_adc_2;
    float avg_adc_3;

    /* Publish true raw ADC values (for CAN / logging) */
    VS_RWCurrent_1_A = VS_ADC5;
    VS_RWCurrent_2_A = VS_ADC8;
    VS_RWCurrent_3_A = VS_ADC3;

    /* Accumulate samples */
    sum_adc_1 += VS_ADC5;
    sum_adc_2 += VS_ADC8;
    sum_adc_3 += VS_ADC3;
    sample_counter++;

    if (sample_counter >= AVG_SAMPLE_COUNT)
    {
        avg_adc_1 = (float)sum_adc_1 / (float)AVG_SAMPLE_COUNT;
        avg_adc_2 = (float)sum_adc_2 / (float)AVG_SAMPLE_COUNT;
        avg_adc_3 = (float)sum_adc_3 / (float)AVG_SAMPLE_COUNT;

        /* ===== CURRENT COMPUTATION (DELTA ADC METHOD) ===== */
        VS_Current_1_A =
            ((avg_adc_1 - zero_adc_1) * ADC_REF_VOLTAGE) /
            (ADC_MAX_COUNTS * WCS1700_SENS);

        VS_Current_2_A =
            ((avg_adc_2 - zero_adc_2) * ADC_REF_VOLTAGE) /
            (ADC_MAX_COUNTS * WCS1700_SENS);

        VS_Current_3_A =
            ((avg_adc_3 - zero_adc_3) * ADC_REF_VOLTAGE) /
            (ADC_MAX_COUNTS * WCS1700_SENS);

        /* Clamp negative noise */
        if (VS_Current_1_A < 0.0f) VS_Current_1_A = 0.0f;
        if (VS_Current_2_A < 0.0f) VS_Current_2_A = 0.0f;
        if (VS_Current_3_A < 0.0f) VS_Current_3_A = 0.0f;

        /* Reset */
        sum_adc_1 = 0U;
        sum_adc_2 = 0U;
        sum_adc_3 = 0U;
        sample_counter = 0U;
    }
}
