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

#ifndef EXT_EEPROM_H
#define EXT_EEPROM_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "sys_typedefs.h"
#include "app_typedef.h"
#include "r_fdl_types.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define QUEUE_SIZE      10u
#define QUEUE_START     0u
#define QUEUE_END       (QUEUE_SIZE - 1u) 

#define EA_MODE_READ    2u
#define EA_MODE_WRITE   1u

#define EA_REQ_PASS     0x00u
#define EA_REQ_FAIL     0x01u

#define EEPROM_PAGE_SIZE    64u
#define EEPROM_READ_ONESHOT 64u
#define EEPROM_CYCLETIME    10u   /* 5 MILLISEC */
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef struct 
{
    uint32_t Identifier_u32;
    uint32_t Ea_Addr_u32;
    uint8_t* Buff_Addr_pu8;
    uint16_t EaLen_u16;
    uint8_t Mode_u8;
}Ea_Data_St_t;

typedef struct 
{
    Ea_Data_St_t* Data_pSt;
    uint8_t Front_u8;
    uint8_t Rear_u8;
}Ea_Queue_St_t;

typedef enum
{
    EA_REQ_NULL,
    EA_REQ_INPROGRESS_E,
    EA_REQ_FAIL_E,
    EA_REQ_PASS_E,
}Ea_Result_En_t;
/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/
extern void EepromInit(void);
extern void Ea_Scheduler(void);
uint8_t EepromRead(uint32_t addr_u32,uint8_t* Buff_pu8,uint32_t Size_u32);
uint8_t EepromWrite(uint32_t addr_u32,uint8_t* Buff_pu8,uint32_t Size_u32);
void Ea_Req_CompleteCallback(uint32_t Identifier_u32,uint8_t Result_u8);
bool Read_Eeprom(uint32_t Identifier_u32, uint32_t Mem_Addr_u32, uint8_t* Buff_Addr_pu8,uint16_t Read_Len_u16);
bool Write_Eeprom(uint32_t Identifier_u32, uint32_t Mem_Addr_u32, uint8_t* Buff_Addr_pu8,uint16_t Read_Len_u16);
#endif
/*---------------------- End of File -----------------------------------------*/
