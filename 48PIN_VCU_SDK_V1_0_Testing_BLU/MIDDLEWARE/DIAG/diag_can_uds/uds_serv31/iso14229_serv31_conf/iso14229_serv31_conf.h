/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File      		: iso14229_serv31_conf.h
|    Project      	: MIL_PBL_CV
|    Description    : configuration description for UDS service - Routine Control
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

#ifndef UDS_SERV31_CONF_H
#define UDS_SERV31_CONF_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include"uds_conf.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define ERASE_RC_PASS               0x00
#define ERASE_ROUTINE_INPROGRESS    0x01
#define ERASE_RC_FAIL               0x02

#define CHECKSUM_RC_PASS               0x00
#define CHECKSUM_ROUTINE_INPROGRESS    0x01
#define CHECKSUM_RC_FAIL               0x02

#define ROLLBACK_RC_PASS               0x00
#define ROLLBACK_ROUTINE_INPROGRESS    0x01
#define ROLLBACK_RC_FAIL               0x02

#define ERASE_LEN_SIZE          0x04
#define ERASE_ADDR_LEN          0x04

#define CHECKSUM_LEN_SIZE          0x04
#define CHECKSUM_ADDR_LEN          0x04

#define	TOTAL_ASW_BLOCKS                (0x01U)
#define TOTAL_RID                       (0x04U)
#define UDS_31_ROUTINE_RESULT_LEN		(2u)

#define RID_CHECK_PROGRAMMING_DEPENDENCY                    (0xFF01)
#define RID_START_CHECK_PROG_DEPENDENCY_LEN					(4)
#define RID_STOP_CHECK_PROG_DEPENDENCY_LEN					(4)
#define RID_RESULT_CHECK_PROG_DEPENDENCY_LEN				(4)
#define RID_START_CHECK_PROG_DEPENDENCY_RESP_OPTBYTE_LEN	(2)
#define RID_STOP_CHECK_PROG_DEPENDENCY_RESP_OPTBYTE_LEN		(0)
#define RID_RESULT_CHECK_PROG_DEPENDENCY_RESP_OPTBYTE_LEN	(1)
#define RID_CHECK_PROG_DEPENDENCY_LEN_RESP_LEN			    (4)

#define RID_DEFAULT_CONFIG_DATA                             (0xF001)
#define RID_START_DEFAULT_CONFIG_DATA_LEN					(4)
#define RID_STOP_DEFAULT_CONFIG_DATA_LEN					(4)
#define RID_RESULT_DEFAULT_CONFIG_DATA_LEN					(4)
#define RID_START_DEFAULT_CONFIG_DATA_RESP_OPTBYTE_LEN		(1)
#define RID_STOP_DEFAULT_CONFIG_DATA_RESP_OPTBYTE_LEN		(0)
#define RID_RESULT_DEFAULT_CONFIG_DATA_RESP_OPTBYTE_LEN		(1)
#define RID_DEFAULT_CONFIG_DATA_LEN_RESP_LEN			    (4)

#define RID_SERVICE_RMD_RESET                       (0x3F00)
#define RID_START_SERVICE_RMD_LEN					(4)
#define RID_STOP_SERVICE_RMD_LEN					(4)
#define RID_RESULT_SERVICE_RMD_LEN					(4)
#define RID_START_SERVICE_RMD_RESP_OPTBYTE_LEN		(1)
#define RID_STOP_SERVICE_RMD_RESP_OPTBYTE_LEN		(0)
#define RID_RESULT_SERVICE_RMD_RESP_OPTBYTE_LEN		(1)
#define RID_SERVICE_RMD_LEN_RESP_LEN				(4)

#define RID_CHECK_REPROGRAMMING_PRECONDITION 				(0xFE01)
#define RID_START_CHECK_REPROG_PRECOND_LEN					(4)
#define RID_STOP_CHECK_REPROG_PRECOND_LEN					(4)
#define RID_RESULT_CHECK_REPROG_PRECOND_LEN					(4)
#define RID_START_CHECK_REPROG_PRECOND_RESP_OPTBYTE_LEN		(0)
#define RID_STOP_CHECK_REPROG_PRECOND_RESP_OPTBYTE_LEN		(0)
#define RID_RESULT_CHECK_REPROG_PRECOND_RESP_OPTBYTE_LEN	(1)
#define RID_CHECK_REPROG_PRECOND_LEN_RESP_LEN				(4)

#define RID_ENTER_BOOTMODE_DATA 							(0xFE02)
#define RID_START_ENTER_BOOTMODE_LEN						(4)
#define RID_STOP_ENTER_BOOTMODE_LEN							(4)
#define RID_RESULT_ENTER_BOOTMODE_LEN						(4)
#define RID_START_ENTER_BOOTMODE_RESP_OPTBYTE_LEN			(0)
#define RID_STOP_ENTER_BOOTMODE_RESP_OPTBYTE_LEN		    (0)
#define RID_RESULT_ENTER_BOOTMODE_RESP_OPTBYTE_LEN		    (1)
#define RID_ENTER_BOOTMODE_LEN_RESP_LEN						(4)

#define ROUTINE_IN_PROGRSS				(0x01)
#define ROUITNE_COMPLETED				(0x00)
#define ROUTINE_FAIL					(0x02)

/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef struct
{
	uint8_t                  (*callbackFptr) (uint8_t *DataPtr_pu8,uint8_t RoutineType_u8, uint8_t* RIDdiscrepter);
	uint16_t                RID_u16;
	uint8_t                 StartRoutineReqLen_u8;
	uint8_t 			    StopRoutineReqLen_u8;
	uint8_t                 RoutineResultReqLen_u8;
	uint8_t                 RespLen_u8 ;
	uint8_t                 RoutineState_u8;
	uint8_t					DiagSession_u8;
	uint8_t					SecurityLvl_u8;
	uint8_t				  	Result_au8[UDS_31_ROUTINE_RESULT_LEN];
	uint8_t 				StartRespOptionByteLen_u8;
	uint8_t 				StopRespOptionByteLen_u8;
	uint8_t 				ResultRespOptionByteLen_u8;			
	uint8_t 				WaitPendingEnable_u8;	
    uint8_t                 RoutineStop_u8;
    uint8_t                 RoutineResult_u8;			  
}RIDConf_St_t;

typedef enum{
	RC_NONE_E,
    RC_PASS_E,
    RC_FAIL_E,
}RCresult_En_t;

/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern RIDConf_St_t 		RIDConf_aSt[TOTAL_RID];
extern bool Reprogramming_b;
/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/
extern uint8_t CheckProgDependency(uint8_t *DataPtr_pu8, uint8_t RoutineType_u8, uint8_t *RIDdiscrepter);
extern uint8_t ReprogramPreCondition(uint8_t *DataPtr_pu8, uint8_t RoutineType_u8, uint8_t *RIDdiscrepter);
extern uint8_t WriteDefaultConfigData(uint8_t *DataPtr_pu8, uint8_t RoutineType_u8, uint8_t *RIDdiscrepter);
extern uint8_t EnterBootMode(uint8_t *DataPtr_pu8, uint8_t RoutineType_u8, uint8_t *RIDdiscrepter);
// extern uint8_t UpdateServiceResetInfo(uint8_t *DataPtr_pu8, uint8_t RoutineType_u8, uint8_t *RIDdiscrepter);
#endif
/*---------------------- End of File -----------------------------------------*/