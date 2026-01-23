#include "vcu_sensors.h"
#include "vehicle_state.h"

/* =========================================================
 *  ADC INPUTS FROM ADC SERVICE
 * ========================================================= */
extern uint16_t VS_ADC5;   // Current Sensor 1
extern uint16_t VS_ADC8;   // Current Sensor 2
extern uint16_t VS_ADC3;   // Current Sensor 3

/* =========================================================
 *  ADC CONFIG (RH850)
 * ========================================================= */
#define ADC_MAX_COUNTS          4095.0f
#define ADC_REF_VOLTAGE         3.30f   // Measure and tune if needed

/* =========================================================
 *  WCS1500 SENSOR CONFIG (3.3V SUPPLY)
 * ========================================================= */
#define CUR_ZERO_VOLT_1         1.65f   // Vcc / 2
#define CUR_ZERO_VOLT_2         1.65f
#define CUR_ZERO_VOLT_3         1.65f

#define CUR_SENS_1              0.066f  // 66 mV/A
#define CUR_SENS_2              0.066f
#define CUR_SENS_3              0.066f

/* =========================================================
 *  FILTER CONFIG
 * ========================================================= */
#define SENSOR_TASK_PERIOD_MS   10U
#define AVG_WINDOW_MS           100U    // FAST response (100 ms)
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
static inline float ADC_To_Voltage(uint16_t adc);
static inline float Voltage_To_Current(float voltage,
                                       float zero_v,
                                       float sens);

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

    /* Raw ADC debug (instantaneous) */
    VS_RWCurrent_1_A = 0U;
    VS_RWCurrent_2_A = 0U;
    VS_RWCurrent_3_A = 0U;
}

/* =========================================================
 *  10ms SENSOR TASK
 * ========================================================= */
void VCU_Sensors_10ms(void)
{
    /* Capture raw ADC every cycle (for CAN / debug) */
    VS_RWCurrent_1_A = VS_ADC5;
    VS_RWCurrent_2_A = VS_ADC8;
    VS_RWCurrent_3_A = VS_ADC3;

    /* Accumulate for averaging */
    sum_adc_1 += VS_ADC5;
    sum_adc_2 += VS_ADC8;
    sum_adc_3 += VS_ADC3;
    sample_counter++;

    if (sample_counter >= AVG_SAMPLE_COUNT)
    {
        /* Average ADC */
        uint16_t avg_adc_1 = (uint16_t)(sum_adc_1 / AVG_SAMPLE_COUNT);
        uint16_t avg_adc_2 = (uint16_t)(sum_adc_2 / AVG_SAMPLE_COUNT);
        uint16_t avg_adc_3 = (uint16_t)(sum_adc_3 / AVG_SAMPLE_COUNT);

        /* Convert to voltage */
        float v1 = ADC_To_Voltage(avg_adc_1);
        float v2 = ADC_To_Voltage(avg_adc_2);
        float v3 = ADC_To_Voltage(avg_adc_3);

        /* Convert to current */
        VS_Current_1_A = Voltage_To_Current(v1,
                                            CUR_ZERO_VOLT_1,
                                            CUR_SENS_1);
        VS_Current_2_A = Voltage_To_Current(v2,
                                            CUR_ZERO_VOLT_2,
                                            CUR_SENS_2);
        VS_Current_3_A = Voltage_To_Current(v3,
                                            CUR_ZERO_VOLT_3,
                                            CUR_SENS_3);

        /* Clamp only small negative noise */
        if (VS_Current_1_A > -0.5f && VS_Current_1_A < 0.0f)
            VS_Current_1_A = 0.0f;
        if (VS_Current_2_A > -0.5f && VS_Current_2_A < 0.0f)
            VS_Current_2_A = 0.0f;
        if (VS_Current_3_A > -0.5f && VS_Current_3_A < 0.0f)
            VS_Current_3_A = 0.0f;

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
static inline float ADC_To_Voltage(uint16_t adc)
{
    return ((float)adc * ADC_REF_VOLTAGE) / ADC_MAX_COUNTS;
}

static inline float Voltage_To_Current(float voltage,
                                       float zero_v,
                                       float sens)
{
    return (voltage - zero_v) / sens;
}
