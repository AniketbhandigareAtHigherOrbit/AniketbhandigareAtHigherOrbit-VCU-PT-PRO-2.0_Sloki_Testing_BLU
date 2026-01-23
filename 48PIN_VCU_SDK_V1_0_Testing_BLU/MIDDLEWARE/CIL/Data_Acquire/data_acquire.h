/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : data_acquire.c
|    Project        :  OSM_VCU_ASW VCU ASW
|    Description    : The file acquires the data.
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date             Name                      Company
| --------     ---------------------     ---------------------------------------
| 
|-------------------------------------------------------------------------------
|******************************************************************************/
#ifndef DATA_ACQUIRE_H
#define DATA_ACQUIRE_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include"app_typedef.h"
#include"pal_gpio_conf.h"
//#include"pal_adc_conf.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/

/* Port pin read at 5ms interval ("ReadGpioInputState" called at every 5ms) */
#define PIN_READ_TIME                     (5) 

#define TOTAL_ADC_INPUT ((uint16_t)ADC_Chnl_IP_End)

#define FILTER_FACTOR_1 0.1f
#define FILTER_FACTOR_2 0.2f
#define FILTER_FACTOR_3 0.3f
#define FILTER_FACTOR_4 0.4f
#define FILTER_FACTOR_5 0.5f
#define FILTER_FACTOR_6 0.6f
#define FILTER_FACTOR_7 0.7f
#define FILTER_FACTOR_8 0.8f
#define FILTER_FACTOR_9 0.9f
#define FILTER_FACTOR_10 1.0f
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef enum
{
    GPIO_INP_OFF_E,
    GPIO_INP_ON_E,
    GPIO_INP_OFF_HOLD_E,
    GPIO_INP_ON_HOLD_E,
} GpioInputState_En_t;

#pragma pack(1)
typedef struct 
{
    uint16_t            DebounceCount_u16;
    uint8_t             SignalState_u8;
    bool				LongPress_b;
    GpioInputState_En_t InpState_En;
    uint8_t             ReadValue_u8;
}DInpSignal_St_t;

typedef struct 
{
    uint8_t PresentState_u8;
    uint8_t PreviousState_u8;
}DOutputSignal_St_t;

typedef struct
{
    uint16_t DebounceCount_u16;
    uint16_t PresentAdc_u16;
    uint16_t PrevAdc_u16;
    uint16_t ActualValue_u16;
    bool StartDebounce_b;
}AdcInpSignal_St_t;


/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern uint8_t CAN_BusOff_Error_u8;
extern DInpSignal_St_t DInpSignal_aSt[];
extern AdcInpSignal_St_t AdcInpSignal_aSt[];
extern DOutputSignal_St_t DOutputSig_aSt[TOTAL_DO_E];
/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/
extern void ReadInputSignal(void);
extern void DataAquireInit(void);
extern void WriteOutputSignals(void);

#endif
/*---------------------- End of File -----------------------------------------*/