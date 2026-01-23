/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File	    : iso14229_serv28.h
|    Project	    : NIL_PBL_CV
|    Description    : Service description for UDS service - Communication Control.
|                     
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date     	      Name                        Company
| ----------     ---------------     -----------------------------------
| 31/07/2024       Manikandan S        Sloki Software Technologies LLP
|-------------------------------------------------------------------------------
|******************************************************************************/


#ifndef _ISO14229_SERV28_H
#define	_ISO14229_SERV28_H 


/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "uds_conf.h"

  

/*******************************************************************************
 *  Define & Macros
 ******************************************************************************/

#define SERV_28_MIN_LEN                                     0x03u  /* @summary: minimum message length */
#define SERV_28_MAX_LEN                                     0x05u  /* @summary: maximum message length */
  

/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/

 
/* @Summary : - sub-functions which is going to be supported in this service */
typedef enum
{
    ENABLE_RX_AND_TX_SUB_ID_E = 0x00u,  
    ENABLE_RX_AND_DISABLE_TX_SUB_ID_E,
    DISABLE_RX_AND_ENABLE_TX_SUB_ID_E,
    DISABLE_RX_AND_TX_SUB_ID_E,
    ENABLE_RX_AND_DISABLE_TX_WITH_ENHANCED_ADDR_INFO_SUB_ID_E,
    ENABLE_RX_AND_TX_WITH_ENHANCED_ADDR_INFO_SUB_ID_E,
}COMMUNICATION_SUBID_En_t ;


/* @Summary : - this enum for communication type */
typedef enum
{
    NORMAL_COMM_MSG_E = 0x01u,
    NETWORK_MANAGEMENT_COMM_MSG_E,
    NETWORK_MANAGEMENT_AND_NORMAL_COMM_MSG_E,
    TOTAL_COMM_TYPE_E,
}COMMUNICATION_TYPE_En_t ;

typedef void (*COMM_MSG_Fptr_t)(bool , bool );

typedef struct
{
    COMMUNICATION_TYPE_En_t COMMUNICATION_TYPE_En;
    COMM_MSG_Fptr_t COMM_MSG_Fptr;
}Comm_Config_St_t;

/*******************************************************************************
 *  GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *  FUNCTION PROTOTYPES
 ******************************************************************************/
extern UDS_Serv_resptype_En_t iso14229_serv28(UDS_Serv_St_t* );
extern void UDS_Serv28_Timeout(void);

#endif	/* _ISO14229_SERV28_H */
/*---------------------- End of File -----------------------------------------*/
