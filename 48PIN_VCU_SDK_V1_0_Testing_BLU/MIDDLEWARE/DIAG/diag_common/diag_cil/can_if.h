/******************************************************************************
 *    FILENAME    : can_if.h
 *    DESCRIPTION : This file contains buffer for CIL layer data extraction as  and other structs defined in i15676.h
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Jithesh     18/01/2017		   Initial version
 ******************************************************************************
*/ 
#ifndef CAN_IF_H_
#define CAN_IF_H_

/* Section: Included Files                                                */
#include "diag_typedefs.h"
//DRV-CIL Interface

/* ************************************************************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */


#define NUM_CAN_SIGNALS                                             ((CIL_DCAN_END_E)   - (CIL_CAN_START_E))
#define CIL_CANGetSigIndex(SigName)	                            (uint16_t)((SigName) - CIL_CAN_START_E)

//The direction of data transfer is Transmission
#define CAN_TX                                                          0
//The direction of data transfer is Reception
#define CAN_RX                                                          1
//Message type is Standard frame format
#define CAN_STD                                                         0
//Message type is Extended frame format
#define CAN_EXT                                                         1


#define CIL_CAN_GetCilDptr(sig)     (CIL_CAN_Conf_aSt[CIL_CANGetSigIndex(sig)].Data_p) 
#define CIL_CAN_GET_MSG_TYPE(sig)   (CIL_CAN_Conf_aSt[CIL_CANGetSigIndex(sig)].Communication_Type_En)
/*

     *****************************************************************************
     *****************************************************************************
     Section: Data Types
     *****************************************************************************
     *****************************************************************************

      A brief description of a section can be given directly below the section
        banner.
     


     *****************************************************************************
*/

// Enumeration defining the Return Codes for the CAN Driver

typedef enum CanReturnCode_Tag
{
    CAN_FAILED_E = 0,           // Failure indicator
    CAN_SUCCESS_E,              // Success indicator
    CANNULL_E,                 // Null pointer indicator
    CAN_BUSY_E,
    CAN_BUFFER_EMPTY_E,         // Buffer is empty
    CAN_INACTIVE_E,            //  If the CAN module is not in error active state
    CAN_INVALID_MODULE_E,       // Module requested is not valid
    CAN_INVALID_BUFFER_E
}CAN_RESP_En_t;

/* Enumeration defining CAN ID Format */ 

typedef enum
{
    STD_E = 0U,              /*Standard ID format*/
    EXT_E = 1U,              /*Extended ID format*/
}CAN_IDFormat_En_t;

/* Enumeration defining CAN ID Format */ 

typedef enum
{
    DLC_CHECK_DISABLE_E = 0U,               /* DLC checking is enabled */
    DLC_CHECK_ENABLE_E = 1U,              /* DLC checking is disabled */
}CAN_DlcEnable_En_t;

/* structure to manage the message frame

*/

typedef struct 
{
    uint32_t ID_u32;                 //Message ID
    uint8_t  DataLength_u8;          //Data length
    uint8_t  DataBytes_au8[8];       //Data Bytes
    CAN_IDFormat_En_t MessageType_u8;    /*Message type*/
}CAN_MessageFrame_St_t;

	
/* structure to manage the scheduled message.

*/
typedef struct {
	CAN_MessageFrame_St_t 	msg;
	uint16_t		rxCnt; 
	bool			rxFlag;
}CanSchedMsg_St_t;



	
// Enumeration defining Interrupt mode and Polling mode	
typedef enum
{
    J1939_CAN_MSG_E,
    ISO14229_CAN_MSG_E,
    TOTAL_CAN_MSG_TYPE_E,
}CanMsgType_En_t ;
	
typedef enum 			
{
    CAN_INT_E = 0,				// Interrupt mode
    CAN_POL_E				    // Polling   mode
}CAN_INT_POL_En_t;
typedef enum
{
    STD_CAN_E = 0U,              /*Standard ID format*/
    EXT_CAN_E = 1U,                   /*Extended ID format*/
}HAL_CAN_IDFormat_En_t;

typedef enum
{
    DATA_FRAME_E = 0U,              /*Data frame format*/
    REMOTE_FRAME_E                 /*Remote frame format*/
}HAL_CAN_MsgFormat_En_t;

// Enumeration defining different modules supported by the driver
typedef enum CanModule_Tag
{
    CAN1_E = 0,   //CAN Module 0
	CAN2_E = 1,   //CAN Module 1
	CAN3_E = 2,	  //CAN Module 2
    FLEXCAN_NUM_E      //Used for array size
}Can_Module_En_t;      // Ordered

/* structure definition for CIL Configuration */
typedef struct
{
    uint32_t                      ID_u32;                  /*Message ID*/
    uint32_t                      ID_MASK_u32;             /*Message ID*/
    Can_Module_En_t				  Can_Module_En;
    uint16_t                      Label_u16;               /*Label*/
    HAL_CAN_IDFormat_En_t         IDE_u8;                  /*IDE mask*/
    uint8_t                       RTR_u8;                  /*RTR mask*/
    uint8_t                       IsTxHistEn;              /*Tx history buffer enable*/
    uint8_t                       IsOnShotTx;              /*Enable or disable retry on error*/
    uint8_t                       BufferDirection_u8;      /* Data direction */
    uint8_t                       Dlc_Length_u8;           /* DLC according to CAN_Matrix */
}HAL_CAN_MsgConf_St_t;


// Structure managing the HAL-CAN parameters
typedef struct CanMessage_Tag2
{
    uint32_t                ID_u32;                        /* Message ID */
    uint8_t                 MessageType_u8;                /* Message type */
    uint8_t                 BufferDirection_u8;            /* Data direction */
    CAN_INT_POL_En_t        Pol_Int_En;                    /* Polling or interrupt */
}HAL_CAN_Params_St;

//  
typedef void (*CIL_CAN_FnPtr)(uint16_t, CAN_MessageFrame_St_t );

typedef struct
{
    //HAL_CAN_Params_St        HAL_CAN_Conf_St;           /* HAL specific config table for CAN */
    HAL_CAN_MsgConf_St_t     HAL_CAN_MsgConf_St;          /* HAL specific config table for CAN */
    uint16_t                 SignalName_u16;              /* Signal Name */
    CIL_CAN_FnPtr            CAN_FnPtr;                   /* Call back function for processing in CIL */
    void*                    Data_p;                      /* Data Pointer*/
    CAN_DlcEnable_En_t       CAN_DlcEnable_En;            /* Parameter to enable / disable dlc length check */
    CanMsgType_En_t 	Communication_Type_En;  /* Communication Type  */
}CIL_CAN_Conf_St_t;

extern bool CAN_Rx_Flag_b;
extern bool CAN_Tx_Flag_b;

extern uint8_t CanTxRxStatus_au8[TOTAL_CAN_MSG_TYPE_E];
	
//extern const CIL_CAN_Conf_St_t CIL_CAN_Conf_aSt[];

extern CAN_RESP_En_t CIL_CAN_Tx_AckMsg (uint16_t SignalName_u16, CAN_MessageFrame_St_t Can_Applidata_St);
extern CAN_RESP_En_t CIL_CAN_Tx_DynamicMsg (uint16_t SignalName_u16, CAN_MessageFrame_St_t Can_Applidata_St);
extern void CIL_CAN_Init(void);
extern void CanSched_RxCallBackInt(uint16_t signalName , CAN_MessageFrame_St_t canMsgRx );
extern void CanSchedulerTxSchdlrReinit(CanMsgType_En_t CanMsgType_En);
extern void CanSchedulerRxSchdlrReinit(CanMsgType_En_t CanMsgType_En);
extern void CIL_CAN_HAL2CIL_IntCallBck(uint8_t ,uint8_t,uint8_t,uint32_t,uint8_t *);
extern void CilCanStatusMaskSet(CanMsgType_En_t CommType_En, uint8_t Status_u8);
/**
 *  @brief  Function to set claimed address.
*  @param   Address : Address of variable holding a claimed address.
 *  @return  none
 */
extern void CIL_CAN_SetClaimedAddr(uint8_t Address);
// void CilCanStatusMaskSet(CanMsgType_En_t CommType_En, uint8_t SetMask_u8);
#endif

/* *****************************************************************************
 End of File
 */
