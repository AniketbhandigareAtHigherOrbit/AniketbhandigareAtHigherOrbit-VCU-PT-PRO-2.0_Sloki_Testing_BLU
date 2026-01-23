/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File      		: iso14229_serv11_conf.h
|    Project      	: MIL_PBL_CV
|    Description    : configuration description for UDS service - ECUReset
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date             Name                        Company
| ----------     ---------------     -----------------------------------
|31/07/2024       Manikandan S         Sloki Software Technologies LLP
|-------------------------------------------------------------------------------
|******************************************************************************/
#ifndef UDS_SERV11_CONF_H_
#define UDS_SERV11_CONF_H_

/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "uds_conf.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define TOTAL_RESET_TYPE                0x03
#define  ECU_RESET_REQ_LEN              0x02


#define ECU_HARD_RESET                      0x01
#define ECU_KEY_OFF_RESET                   0x02
#define ECU_SOFT_RESET                      0x03
#define ECU_RAPIDPWOERSHUTDOWN_ENABLE       0x04
#define ECU_RAPIDPWOERSHUTDOWN_DISABLE      0x05

#define ECU_RESET_COUNTER                  (50U)
/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/
uint8_t EcuHardReset(void);
uint8_t EcuKeyOffOnReset(void);
uint8_t EcuSoftReset(void);
uint8_t EcuEnableRapidPowerShutDown(void);
uint8_t EcuDisableRapidPowerShutDown(void);
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef struct 
{
	uint8_t         (*callbackFptr) (void);
	uint8_t			ResetType_u8;
	uint8_t			SecurityLvl_u8;
}UdsEcuReset_St_t;
/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern const UdsEcuReset_St_t UdsEcuReset_aSt[TOTAL_RESET_TYPE];
extern bool SoftResetRequested_b;
extern bool KeyOffOnRequested_b;


#endif
/*---------------------- End of File -----------------------------------------*/