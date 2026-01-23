/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File	    : iso14229_serv83.h
|    Project	    : MIL_PBL_CV
|    Description    : This file contains variables and functions of iso14229
|                     service 27.
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date     	     Name                      Company
| --------     ---------------------     ---------------------------------------
| 31/07/2024       Manikandan S                 Sloki Software Technologies LLP.
|-------------------------------------------------------------------------------
|******************************************************************************/

#ifndef ISO14229_SERV83_H /* Guard against multiple inclusion */
#define ISO14229_SERV83_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "uds_conf.h"
#include "i15765.h"
#include "uds_session.h"

/*******************************************************************************
 *  Define & Macros
 ******************************************************************************/
#define SERV_83_MIN_LEN 0x02
#define SERV_83_MAX_LEN 0x05
#define UDS83_SECURITY_CHECK TRUE
#define READ_EXTENDED_TIMINGPARAMETERSET 0x01
#define SET_TIMINGPARAMETER_TODEFAULTVALUES 0x02
#define READ_CURRENTLY_ACTIVETIMINGPARAMETERS 0x03
#define SET_TIMINGPARAMETERS_TOGIVENVALUES 0x04
#define POS_RESP_SUPRESS_VALUE 0x80

/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/

typedef enum
{
    READ_EXTENDEDTIMING_PARAMETERSET_E = READ_EXTENDED_TIMINGPARAMETERSET,
    SET_TIMINGPARAMETER_TODEFAULTVALUES_E = SET_TIMINGPARAMETER_TODEFAULTVALUES,
    READ_CURRENTLY_ACTIVETIMINGPARAMETERS_E = READ_CURRENTLY_ACTIVETIMINGPARAMETERS,
    SET_TIMINGPARAMETERS_TOGIVENVALUES_E = SET_TIMINGPARAMETERS_TOGIVENVALUES

} SA_SUB_FUN83_En_t;

/*******************************************************************************
 *  GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *  FUNCTION PROTOTYPES
 ******************************************************************************/
extern UDS_Serv_resptype_En_t iso14229_serv83(UDS_Serv_St_t *UDS_Serv_pSt); 
extern void UDS_Serv83_Timeout(void);

#endif /*_ISO14229_SERV83_H */
/*---------------------- End of File -----------------------------------------*/
