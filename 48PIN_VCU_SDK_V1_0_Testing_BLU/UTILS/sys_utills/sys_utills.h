/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : DataAcquire.h
|    Project        : IDAN Motor VCU
|    Description    : This file contains the export variables and functions
|                     to initialize and Operate the bms functanality.
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date             Name                      Company
| --------     ---------------------     ---------------------------------------
| 20/04/2021     Name           Sloki Software Technologies LLP.
|-------------------------------------------------------------------------------
|******************************************************************************/
#ifndef SYS_UTILLS_H
#define SYS_UTILLS_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include"sys_typedefs.h"
#include "app_typedef.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define GET_TIME_MAXVALUE()       (0xFFFFFFFFu)
// #define GET_TIME_MS()       (TS_time_ms_u32)
// #define INC_TIME_1MS()       (TS_time_ms_u32+=1u)
// #define INC_TIME_5MS()       (TS_time_ms_u32+=5u)
// #define TIME_DIFF_MS(v)     ((uint32_t) ((GET_TIME_MS()) - (v)))
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef enum
{
	FALLING_E,
	RISING_E
} CurrentModuleState_En_t;
/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern volatile uint32_t TS_time_ms_u32;
extern volatile uint32_t _RandomNum_u32;
/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/
extern uint32_t GetTimeDelayDiff(uint32_t ActualTime_u32,uint32_t CapturedTime_u32);
extern CurrentModuleState_En_t CheckModuleStatus(uint8_t PresentValue_u8,uint8_t PreviousValue_u8);
extern uint16_t lowPassFilter16bit(uint16_t Current_Value_u16, uint16_t Previous_Value_u16,float Alpha_Value_f32);
//extern uint8_t lowPassFilter8bit(uint8_t Current_Value_u8, uint16_t Previous_Value_u8,float Alpha_Value_f32);
extern bool GetRisingState(uint8_t PresentValue_u8, uint8_t PreviousValue_u8);
extern uint32_t Difference(uint32_t Digit1_u32, uint32_t Digit2_u32);
#endif
/*---------------------- End of File -----------------------------------------*/
