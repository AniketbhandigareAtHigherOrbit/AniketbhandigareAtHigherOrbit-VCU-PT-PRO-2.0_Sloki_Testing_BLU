/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File      		: iso14229_serv10_conf.h
|    Project      	: MIL_PBL_CV
|    Description    : configuration description for UDS service - Session Control
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

#ifndef ISO14229_SID10_CONF_H
#define ISO14229_SID10_CONF_H

/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "uds_conf.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define TOTAL_DIAG_SESSION			0x04

#define DIAG_SESS_TYPE_DEFAULT		0x01
#define DIAG_SESS_TYPE_PROGRAMMING	0x02
#define DIAG_SESS_TYPE_EXTENDED		0x03
#define DIAG_SESS_TYPE_FOTA			0x55
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef struct 
{
	uint8_t         (*callbackFptr) (void);
    uint16_t         DiagSessEquValue_u8;
	uint16_t		SupportedSession_u16;
	uint8_t			DiagSessionType_u8;
}UdsDiagSession_St_t;
/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern const UdsDiagSession_St_t UdsDiagSession_aSt[TOTAL_DIAG_SESSION];
/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/
uint8_t DiagDefaultSessCbk(void);
uint8_t DiagProgrammingSessCbk(void);
uint8_t DiagExtSessCbk(void);
uint8_t DiagFotaSessCbk(void);

#endif
/*---------------------- End of File -----------------------------------------*/