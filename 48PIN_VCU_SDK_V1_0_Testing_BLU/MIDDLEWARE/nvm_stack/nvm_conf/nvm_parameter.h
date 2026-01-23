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
| 02/08/2024     Jeevan Jestin N           Sloki Software Technologies LLP.
|-------------------------------------------------------------------------------
|******************************************************************************/

#ifndef NVM_PARAMETER_H
#define NVM_PARAMETER_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "sys_typedefs.h"
#include "app_typedef.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/

/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef enum
{
    /* NVM Block 0*/
    DIAG_SECURITY_STATE_E,
    DIAG_SESSION_STATE_E,
    REPROGRAM_REQ_STATE_E,
    ECU_RESET_E,
    SBL_STATE_E,
    NEW_SBL_CRC_E,
    NEW_SBL_SIZE_E, 
    SBL_UPDATE_FLAG_E,
    RANNDUM_NUMBER_E,

    /* NVM Block 1 */
    VIN_NUMBER_E,
    REPAIR_SHOP_CODE_E,
    PROGRAMMING_DATE_E,
    ASW_REPROGRAM_SEQ_E,
    ACTIVE_DIAG_SESSION_E,
    
    /* NVM Block 2 */
    FEE_FM_COMMON_DATA_E,
    FEE_FM_RDYRESULTS_E,
    FEE_FM_TFSLC_E,

    /* NVM Block 3 */
    FEE_FM_L2_ENTRY1_E,
    FEE_FM_L2_ENTRY2_E,
    FEE_FM_L2_ENTRY3_E,
    FEE_FM_L2_ENTRY4_E,
    FEE_FM_L2_ENTRY5_E,
    FEE_FM_L2_ENTRY6_E,
    FEE_FM_L2_ENTRY7_E,
    FEE_FM_L2_ENTRY8_E,
    FEE_FM_L2_ENTRY9_E,
    FEE_FM_L2_ENTRY10_E,

    /* NVM Block 4*/
    APPLICATION_SOFTWARE_VERSION,
    
    /* NVM Block 5*/
    CONFIG_DATA_E,
    
}Nvm_Parameter_En_t;


/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/

#endif
/*---------------------- End of File -----------------------------------------*/