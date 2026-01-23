/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File      		: iso14229_serv11.h
|    Project      	: MIL_PBL_CV
|    Description    : Service description for UDS service  - ERCReset
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

#ifndef UDS_SERV11_H_
#define UDS_SERV11_H_


/*******************************************************************************
 *  Includes
 ******************************************************************************/
 #include "uds_conf.h"

/*******************************************************************************
 *  Define & Macros
 ******************************************************************************/
 
 #define UDS_SERVICE11_SID                                 (0x11)
 #define UDS_SERVICE11_LEN                                 (0x02)
 /* sub function */
 #define UDS_SERV11_HARDWARE_RST                           (0x01)
 #define UDS_SERV11_KEY_ON_OFF_RST                         (0x02)
 #define UDS_SERV11_SOFTWARE_RST                           (0x03)
 #define UDS_SERV11_ENABLE_RAPID_POWER_SHUTDOWN            (0x04)
 #define UDS_SERV11_DISABLE_RAPID_POWER_SHUTDOWN           (0x05)
 
#define UDS_SER_11_REQ_SECURITY			FALSE
 
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL VARIABLES
 ******************************************************************************/

 
/*******************************************************************************
 *  FUNCTION PROTOTYPES
 ******************************************************************************/
UDS_Serv_resptype_En_t iso14229_serv11(UDS_Serv_St_t* UDS_Serv_pSt);
extern void UDS_Serv11_Hardware_Rst(void);    
extern void UDS_Serv11_Key_On_Off_Rst(void); 
extern void UDS_Serv11_Software_Rst(void);  
extern void UDS_Serv11_Enable_Rapid_Power_Shutdown(void); 
extern void UDS_Serv11_Disable_Rapid_Power_Shutdown(void);
extern void Serv11Init(void);
 #endif /*UDS_SERV11_H_*/
/*---------------------- End of File -----------------------------------------*/
