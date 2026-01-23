/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : comm_cntrl_adapt.h
|    Project        : MIL_PBL_CV
|    Description    :  The file contatins the common control tasks.
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date              Name                        Company
| ----------     ---------------     -----------------------------------
| 31/07/2024       Manikandan S             Sloki Software Technologies LLP
|-------------------------------------------------------------------------------
|******************************************************************************/ 

#ifndef _COMM_CONTROL_ADAPT_H_
#define _COMM_CONTROL_ADAPT_H_

/*******************************************************************************
 *  HEADER FILE INCLUDES
 ******************************************************************************/

#include "uds_conf.h"
#include "iso14229_serv28.h"


/*******************************************************************************
 *  EXTERN FUNCTIONS
 ******************************************************************************/
 extern void NormalCommMsg_Adapt(bool Rx_Status_b,  bool Tx_Status_b);

 extern void NWMngmntCommMsg_Adapt(bool Rx_Status_b,  bool Tx_Status_b);

 extern void NWMngmnt_NormalCommMsg_Adapt(bool Rx_Status_b,  bool Tx_Status_b);

 extern uint8_t Get_IVN_Normal_Com_Tx_Sts(void);

 extern uint8_t Get_IVN_Normal_Com_Rx_Sts(void);
 
 extern uint8_t Get_IVN_Network_Com_Tx_Sts(void);
 
 extern uint8_t Get_IVN_Network_Com_Rx_Sts(void);
 
 
 #endif
