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
#ifndef DATA_H
#define DATA_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "sys_typedefs.h"
#include "app_typedef.h"
#include "nvm_parameter.h"
#include "nvm_conf.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define NVM_RETRY_MAX       (2U)
// #define POLY                (0x1021u)
// #define INIT_CRC            (0xFFFFu)
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef enum
{
    NVM_WRITE_OK_E,
    NVM_READ_OK_E,
    NVM_WAIT_E,
    NVM_INVALID_PAREMETER_E,
    NVM_DATA_INVALID_E,
    NVM_ERROR_E,
}NvmAccessSt_En_t;

typedef enum
{
    NVM_INIT_E,
    NVM_INIT_PROGRESS_E,
    NVM_INIT_FAIL_E,
    NVM_VERIFY_PROGRESS_E,
    NVM_INCONSTITENT_E,
    NVM_UPLOAD_E,
    NVM_UPLOAD_PROGRESS_E,
    NVM_UPLOAD_FAIL_E,
    NVM_IDLE_E,
}NvmBlockState_En_t;

typedef struct 
{
    NvmBlockState_En_t BlockState_En;
    uint8_t FailCnt_u8;
    uint8_t ReqResult_u8;
    bool ReqComplete_b;
    bool ShutdownWrite_b;
    bool BlkValid_b;
}NvmBlkData_St_t;

/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern NvmBlkData_St_t NvmBlkData_aSt[TOTAL_NVM_BLK_E];

/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/
void Nvm_Scheduler(void);
NvmAccessSt_En_t Nvm_Read(uint16_t Param_u16, uint8_t *Data_Buff_pu8);
NvmAccessSt_En_t Nvm_Write(uint16_t Param_u16, uint8_t *Data_Buff_pu8);
void NvmReqCompleteCallback(uint32_t Identifier_u32,uint8_t Result_u8);
uint16_t crc16(const uint8_t *data, uint32_t length,uint16_t CRC_val);
void Nvm_Shutdown(void);
bool Is_Nvm_Idle(void);
extern  void MemCopy(uint8_t  *  Dest_pu8, const uint8_t  * Srs_pu8, uint32_t Len_u32);
extern NvmAccessSt_En_t ApplNVMUpload(uint32_t BlockNumber_u32, uint8_t *Data_Buff_pu8, uint8_t Length2Write_u8);
#endif
/*---------------------- End of File -----------------------------------------*/

