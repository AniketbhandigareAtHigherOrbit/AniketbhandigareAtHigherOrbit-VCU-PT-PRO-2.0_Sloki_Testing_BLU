/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : iso14229_serv87.h
|    Project        : MIL_PBL_CV
|    Description    : This file contains the export variables and functions to
|                     which acn be implemented in the H file.
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date            Name                      Company
| --------     ---------------------     ---------------------------------------
|  31/07/2024       Manikandan S           Sloki Software Technologies LLP.
|-------------------------------------------------------------------------------
|******************************************************************************/

#ifndef ISO14229_SERV87_H
#define ISO14229_SERV87_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "uds_conf.h"

/*******************************************************************************
 *  Define & Macros
 ******************************************************************************/

#define POS_RESP_SUPRESS_VALUE 0x80
#define SERV_87_MAX_LEN 3u
#define SERV_87_MIN_LEN 2u

#define LCTP_MASK_VALUE 0x7F /* LinkControlType*/
#define MODE_TRANSITION_SPECIFIC_PARAMETER_ENABLE FALSE
#define MODE_TRANSITION_FIXED_PARAMETER 0x01
#define MODE_TRANSITION_SPECIFIC_PARAMETER 0x02
#define TRANSITION_MODE 0X03
#define ISO_14229_CANBAUD_START_ID 0x10

#define MPHB 0X02 /* mode parameter high byte*/
#define MPMB 0X03 /* mode parameter middle byte*/
#define MPLB 0x04 /* mode parameter low byte*/

#define SID87_SECURITY_REQUIRED			FALSE
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef enum
{
	CANBAUD_START_ID_E = ISO_14229_CANBAUD_START_ID,
	CAN125000BAUD_ID_E = CANBAUD_START_ID_E,
	CAN250000BAUD_ID_E,
	CAN500000BAUD_ID_E,
	CAN1000000BAUD_ID_E,
	CANBAUD_END_ID_E = CAN1000000BAUD_ID_E,
} uds_serv_87_CANbaud_En_t;

typedef enum
{
	MODE_TRANSITION_FIXED_PARAMETER_E = MODE_TRANSITION_FIXED_PARAMETER,
	MODE_TRANSITION_SPECIFIC_PARAMETER_E = MODE_TRANSITION_SPECIFIC_PARAMETER,
	TRANSITION_MODE_E = TRANSITION_MODE,
} uds_serv87_LCTP_En_t;
/*******************************************************************************
 *  GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *  FUNCTION PROTOTYPES
 ******************************************************************************/
/* -----------------------------------------------------------------------------
 *  FUNCTION DECLERATION DESCRIPTION
 *  -----------------------------------------------------------------------------
 *   Function Name : iso14229_serv87
 *   Description   : The function process the service_10 requests
 *   Parameters    : UDS_Serv_St_t* UDS_Serv_pSt - pointer to service distributer
 *                   table.
 *   Return Value  : None
 *******************************************************************************/
extern UDS_Serv_resptype_En_t iso14229_serv87(UDS_Serv_St_t *);

/* -----------------------------------------------------------------------------
 *  FUNCTION DESCRIPTION
 *  -----------------------------------------------------------------------------
 *   Function Name : UDS_Serv87_Timeout
 *   Description   : This function resets the relevant variables/parameters when
 *                   session timesout.
 *   Parameters    : none.
 *   Return Value  : none.
 *******************************************************************************/
void iso14229_serv87_timeout(void);

/* -----------------------------------------------------------------------------
*  FUNCTION DESCRIPTION
*  -----------------------------------------------------------------------------
*   Function Name : ChangeCANbaudrate
*   Description   : The function Re_init the CAN baudrate.
*   Parameters    : None
*   Return Value  : None
*******************************************************************************/

void ChangeCANbaudrate(uds_serv_87_CANbaud_En_t CANbaud_En);
#endif /* ISO14229_SERV87_H */
/*------------------------------ End of File ---------------------------------*/
