/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File          : uds_session.h
|    Project      : MIL_PBL_CV
|    Description    : Service description for UDS session
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date             Name                        Company
| ----------     ---------------     -----------------------------------
| 31/07/2024       Manikandan S        Sloki Software Technologies LLP
|-------------------------------------------------------------------------------
|******************************************************************************/
#ifndef _UDS_SESSION_H_
#define _UDS_SESSION_H_

/*
*******************************************************************************
* Includes
*******************************************************************************
*/
#include "diag_typedefs.h"
/**************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
#define     UDS_NEG_RESP_CODE   0x7F

//#pragma pack(push, 4)      
typedef struct
{
	uint8_t* 				RxBuff_pu8;       // Pointer to the RX data buffer
	uint8_t* 				TxBuff_pu8;       // Pointer to the TX data buffer
	uint16_t 				RxLen_u16;  // Number of bytes in the request. Filled by the network layer (copy of bufferlength_u16)
	uint16_t 				TxLen_u16; // Number of bytes in the response. Filled by the calling service
}UDS_Serv_St_t;
//#pragma pack(pop) 

typedef enum
{
    UDS_SERV_RESP_UNKNOWN_E = 0, // Unknown response
    UDS_SERV_RESP_POS_E ,        // Positive response
    UDS_SERV_RESP_NEG_E,         // Negative response
    UDS_SERV_RESP_NORESP_E,      // No response
    UDS_SERV_RESP_WAITPEND_E,     // Wait response
}UDS_Serv_resptype_En_t;

typedef const struct
{
	uint8_t  				sid_u8;                     // Service identifier
	void (*ServiceInit_Fptr_t) (void); // Call back function to the init function called from service distributor init
	UDS_Serv_resptype_En_t (*Service_Fptr_t) (UDS_Serv_St_t*);// Call back function to for the service
	// Note additional entries can be added to this structure to cater to other diagnostic protocol
	uint8_t 				Session_subid_u8;
	uint8_t					FunAddrEnable_u8;
}ServiceDistUDS_St_t;

extern UDS_Serv_St_t    Serv_databuf_St;


/**
 *  Function name  : void uds_session_proc_5ms()
 *  @brief         : Function for uds session process of 5ms.
 *  @param         : none
 *  @return        : none.
 */
extern void uds_session_proc_5ms(void);

/**
 *  Function name  : void ServDistUDS_init().
 *  @brief         : Function for service distributor initialization.
 *  @param         : none
 *  @return        : none.
 */
extern void ServDistUDS_init (void);

extern void UDS_Serv_init(void);

/**
* Function name  : void service_distributor_timeout(void)
* @brief         : Function is call all service timeout function 
* @param         : none
* @return        : none
*/ 
extern void service_distributor_timeout(void);


/**
* Function name  : Serv_resptype_En_t ServDist_CAN ()
* @brief         : Function implements the service distributor for ISO 14229
* @param         : NULL
* @return        : Type of response
* @Code tag      : @[CODE_OBD_SERVDIST_2] @{SDD_OBD_SERVDIST_2}
*/ 


extern void setUDSServDist(const ServiceDistUDS_St_t* ConfigServDist_pt, uint32_t numentries_u32);
extern void servDistSetstr(void);

/* *****************************************************************************
 End of File
 */
#endif

