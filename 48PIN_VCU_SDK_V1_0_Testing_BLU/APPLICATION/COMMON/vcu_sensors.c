#include "vcu_sensors.h"
#include "vehicle_state.h"

/* =========================================================
 *  ADC INPUTS FROM ADC SERVICE
 * ========================================================= */
extern uint16_t VS_ADC5;   // Current Sensor 1
extern uint16_t VS_ADC8;   // Current Sensor 2
extern uint16_t VS_ADC3;   // Current Sensor 3

/* =========================================================
 *  ADC & SENSOR CONFIG
 * ========================================================= */
#define ADC_MAX_COUNTS          4095.0f
#define ADC_REF_VOLTAGE         3.3f

/* ---- Per-sensor calibration (update from Python) ---- */
#define CUR_ZERO_VOLT_1         1.65f
#define CUR_ZERO_VOLT_2         1.65f
#define CUR_ZERO_VOLT_3         1.65f

#define CUR_SENS_1              0.066f   // V/A
#define CUR_SENS_2              0.066f
#define CUR_SENS_3              0.066f

/* =========================================================
 *  AVERAGING CONFIG
 * ========================================================= */
#define SENSOR_TASK_PERIOD_MS   10
#define AVG_WINDOW_MS           1000
#define AVG_SAMPLE_COUNT        (AVG_WINDOW_MS / SENSOR_TASK_PERIOD_MS)

/* =========================================================
 *  STATIC ACCUMULATORS
 * ========================================================= */
static uint32_t sum_adc_1 = 0;
static uint32_t sum_adc_2 = 0;
static uint32_t sum_adc_3 = 0;

static uint16_t sample_counter = 0;

/* =========================================================
 *  LOCAL FUNCTIONS
 * ========================================================= */
static float ADC_To_Voltage(uint16_t adc);
static float Voltage_To_Current(float voltage, float zero_v, float sens);

/* =========================================================
 *  INIT
 * ========================================================= */
void VCU_Sensors_Init(void)
{
    sum_adc_1 = 0;
    sum_adc_2 = 0;
    sum_adc_3 = 0;
    sample_counter = 0;

    VS_Current_1_A = 0.0f;
    VS_Current_2_A = 0.0f;
    VS_Current_3_A = 0.0f;

    VS_RWCurrent_1_A = 0;
    VS_RWCurrent_2_A = 0;
    VS_RWCurrent_3_A = 0;
}

/* =========================================================
 *  10ms SENSOR TASK
 * ========================================================= */
void VCU_Sensors_10ms(void)
{
    /* Accumulate ADC samples */

    sum_adc_1 += VS_ADC5;
    sum_adc_2 += VS_ADC8;
    sum_adc_3 += VS_ADC3;

    sample_counter++;
    
    if (sample_counter >= AVG_SAMPLE_COUNT)
    {
        VS_RWCurrent_1_A = VS_ADC5;
        VS_RWCurrent_2_A = VS_ADC8;
        VS_RWCurrent_3_A = VS_ADC3;
    }
    /* 1 second window completed */
    if (sample_counter >= AVG_SAMPLE_COUNT)
    {

        uint16_t avg_adc_1 = (uint16_t)(sum_adc_1 / AVG_SAMPLE_COUNT);
        uint16_t avg_adc_2 = (uint16_t)(sum_adc_2 / AVG_SAMPLE_COUNT);
        uint16_t avg_adc_3 = (uint16_t)(sum_adc_3 / AVG_SAMPLE_COUNT);

        float v1 = ADC_To_Voltage(avg_adc_1);
        float v2 = ADC_To_Voltage(avg_adc_2);
        float v3 = ADC_To_Voltage(avg_adc_3);

        /* Convert to current (Amps) */
        VS_Current_1_A = Voltage_To_Current(v1, CUR_ZERO_VOLT_1, CUR_SENS_1);
        VS_Current_2_A = Voltage_To_Current(v2, CUR_ZERO_VOLT_2, CUR_SENS_2);
        VS_Current_3_A = Voltage_To_Current(v3, CUR_ZERO_VOLT_3, CUR_SENS_3);

        /* Clamp negative noise */
        if (VS_Current_1_A < 0.0f) VS_Current_1_A = 0.0f;
        if (VS_Current_2_A < 0.0f) VS_Current_2_A = 0.0f;
        if (VS_Current_3_A < 0.0f) VS_Current_3_A = 0.0f;

        /* Reset accumulators */
        sum_adc_1 = 0;
        sum_adc_2 = 0;
        sum_adc_3 = 0;
        sample_counter = 0;
    }
}

/* =========================================================
 *  CONVERSION FUNCTIONS
 * ========================================================= */
static float ADC_To_Voltage(uint16_t adc)
{
    return ((float)adc * ADC_REF_VOLTAGE) / ADC_MAX_COUNTS;
}

static float Voltage_To_Current(float voltage, float zero_v, float sens)
{
    return (voltage - zero_v) / sens;
}
