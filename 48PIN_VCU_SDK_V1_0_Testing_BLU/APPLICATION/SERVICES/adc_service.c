#include "databank.h"
#include "vehicle_state.h"

/* =========================================================
 *  ADC SERVICE
 *  Reads all ADC channels continuously
 *  Updates global vehicle state variables
 * 
 * ========================================================= */
/* ----------- Extra ADCs ----------- */
uint16_t VS_ADC3 = 0;
uint16_t VS_ADC4 = 0;
uint16_t VS_ADC5 = 0;
uint16_t VS_ADC6 = 0;
uint16_t VS_ADC7 = 0;
uint16_t VS_ADC8 = 0;

void ADC_Service_Run(void)
{
    /* Wheel & Rotor throttles (main use) */
    VS_Throttle_Wheel = Get_ADC_Result(G3_ADC1_E);
    VS_Throttle_Rotor = Get_ADC_Result(G4_ADC2_E);

    /* Optional / future use ADCs */
    VS_ADC3 = Get_ADC_Result(H3_ADC3_E);
    VS_ADC4 = Get_ADC_Result(H4_ADC4_E);
    VS_ADC5 = Get_ADC_Result(J3_ADC5_E);
    VS_ADC6 = Get_ADC_Result(J4_ADC6_E);
    VS_ADC7 = Get_ADC_Result(K3_ADC7_E);
    VS_ADC8 = Get_ADC_Result(K4_ADC8_E);
}



