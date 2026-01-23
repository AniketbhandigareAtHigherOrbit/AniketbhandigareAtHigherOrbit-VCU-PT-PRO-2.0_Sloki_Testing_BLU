/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : DataBank.h
|    Project        :  OSM_VCU_ASW 
|    Description    : 
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
#ifndef DATABANK_H
#define DATABANK_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include"app_typedef.h"

/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/


/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef enum
{
	GPINUPUT_START_E = 0,
	B2_GPINUPUT1_E = GPINUPUT_START_E,
	C2_GPINUPUT2_E,
	D2_GPINUPUT3_E,
	E2_GPINUPUT4_E,
	F2_GPINUPUT5_E,
	B3_GPINUPUT6_E,
	C3_GPINUPUT7_E,
	D3_GPINUPUT8_E,
	GPINUPUT_TOTAL_E
} GpInputSignal_En_t;


typedef enum
{
	ADC_START_E = 0,
	G3_ADC1_E = ADC_START_E,
	G4_ADC2_E,
	H3_ADC3_E,
	H4_ADC4_E,
	J3_ADC5_E,
	J4_ADC6_E,
	K3_ADC7_E,
	K4_ADC8_E,
	ADC_TOTAL_E
} AdcInput_En_t;

typedef enum
{
	GPOUTPUT_START_E = 0,
	A2_GPOUTPUT1_HS1_E = GPOUTPUT_START_E,/* A2 */
	A3_GPOUTPUT2_HS2_E,/* A3 */
	B4_GPOUTPUT3_HS3_E,/* B4*/	
	C4_GPOUTPUT4_HS4_E,/* C4 */
	A1_GPOUTPUT5_LS1_E, /* A1 */
	B1_GPOUTPUT6_LS2_E,/* B1 */
	C1_GPOUTPUT7_LS3_E,/* C1 */
	D1_GPOUTPUT8_LS4_E, /* D1 */
	GPOUTPUT_TOTAL_E,
} GpOutputSignal_En_t;




/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/

extern uint8_t Get_GPInput_State(GpInputSignal_En_t GPI_Channel_Num);
extern uint16_t Get_ADC_Result(AdcInput_En_t ADC_Channel_Num);
extern void Set_GPO_State(GpOutputSignal_En_t GPOutput_Channel_Num, bool PinState_b);


#endif

/*---------------------- End of File -----------------------------------------*/