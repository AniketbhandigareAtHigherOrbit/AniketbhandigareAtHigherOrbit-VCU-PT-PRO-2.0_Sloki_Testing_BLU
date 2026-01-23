/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : i15765_conf.h
|    Project        : MIL_PBL_CV
|    Description    : This file contains configuration structure definition.
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
#ifndef _I15765_CONF_H_
#define _I15765_CONF_H_

/*
 ***************************************************************************************************
 *    Includes
 ***************************************************************************************************
*/
#include "can_if.h"
#include "i15765_priv.h"
#include "diag_typedefs.h"
#include "diag_adapt.h"


/*
 ***************************************************************************************************
 *    Defines
 ***************************************************************************************************
*/

#define NUMBYTES_SID 		        1      // Number of bytes that can hold a valid SID according to ISO protocol
#define NUMBYTES_PID 		        1      // Number of bytes that can hold a valid PID according to ISO protocol
#define NUMBYTES_DID 		        2      // Number of bytes that can hold a valid DID according to UDS protocol
#define NUMBYTES_RESPCODE 	        1      // Number of bytes to hold positive or neg response code.

#define ISO15765_CONF_NUMDATABYTES 	0x200    // Remaining data reserved for sending data and for OBD change its value to 253//Todo Sandeep K Y

// This includes 1 byte for SID, 1 byte for PID and the remaining for data
#define MAX_LENGTH_DIAGBUFFER       ((NUMBYTES_SID) + (NUMBYTES_PID) + (ISO15765_CONF_NUMDATABYTES))
// Number of bytes available for the service interpreter is the max size - the size of
// response code (which is 1 byte) and the SID sent in the response
#define MAX_LENGTH_DIAGSERVICE      (MAX_LENGTH_DIAGBUFFER - NUMBYTES_RESPCODE - NUMBYTES_SID)

#define DEFAULT_VALUE        		0x00u    /* Default extended timing parameter set*/
#define CUSTOMER_VALUE        	0x01u    /* Customer extended timing parameter set*/

typedef enum
{
    CANTP_HALF_DUPLEX_E = 0,
    CANTP_FULL_DUPLEX_E,
    TOTAL_CH
}CAN_TP_DuplexConf_En_t;

#define CANTP_FULL_DUPLEX               1U
#define CANTP_HALF_DUPLEX				0U

#define ISO15765_CONF_CH_TYPE                       CANTP_FULL_DUPLEX // CANTP_FULL_DUPLEX or CANTP_HALF_DUPLEX
#define ISO15765_CONF_SESSION_TIMEOUT_DELAY_MS      5000// 5 sec

/* Filler bytes for padding request and response frame */
#define ISO15765_CONF_DCAN_RESFILLERBYTE   	        0x00U



typedef enum {
		BUFF1_TP_E = 0, 
		BUFF2_TP_E,
		BUFF_TP_MAX_E,
}TP_Buff_En_t;


/*Enum used to get the current structure for channel.*/
typedef enum
{
    BUFF1_NL_E = 0,
	BUFF2_NL_E,
	BUFF_NL_MAX,
}CH_DIR_En_t;


typedef enum
{
	DCAN_TP_INSTANCE_START_E = 0,
	DCAN_TP_INSTANCE_UDSDIAG_START_E = DCAN_TP_INSTANCE_START_E,
#if(TRUE == DIAG_CONF_UDS_SUPPORTED)
	//DCAN_TP_INSTANCE_IVN_E = DCAN_TP_INSTANCE_UDSDIAG_START_E,
	DCAN_TP_INSTANCE_UDSDIAG_E = DCAN_TP_INSTANCE_UDSDIAG_START_E,
	DCAN_TP_INSTANCE_UDSDIAG_END_E,
#else
	DCAN_TP_INSTANCE_UDSDIAG_END_E = DCAN_TP_INSTANCE_UDSDIAG_START_E,
#endif
	DCAN_TP_INSTANCE_OBDDIAG_START_E = DCAN_TP_INSTANCE_UDSDIAG_END_E,
#if(TRUE == DIAG_CONF_OBD2_SUPPORTED)
	DCAN_TP_INSTANCE_OBDDIAG_E = DCAN_TP_INSTANCE_OBDDIAG_START_E,
	DCAN_TP_INSTANCE_OBDDIAG_END_E,
#else
	DCAN_TP_INSTANCE_OBDDIAG_END_E = DCAN_TP_INSTANCE_OBDDIAG_START_E,
#endif
	DCAN_TP_INSTANCE_TOTAL_E = DCAN_TP_INSTANCE_OBDDIAG_END_E,
}DCAN_TP_Instance_En_t;

typedef struct
{
    DCAN_TP_Instance_En_t  DCAN_TP_Instance_En;                  /* Instance ID of TP layer */
    uint16_t               CIL_CAN_TxSignalName_u16;              /* Corresponding CIL CAN Signal Name for TX */
    uint16_t               CIL_CAN_RxSignalName_u16;              /* Corresponding CIL CAN Signal Name for RX */
}DCAN_TP_InstanceCANSignConf_St_t;


/*
 **************************************************************************************************
 *    Enum definitions
 **************************************************************************************************
*/
/*
 **************************************************************************************************
 *    Structure definitions
 **************************************************************************************************
*/

/* Typedef's of the network layer timing Structure ; this structure is configured only once */
typedef const struct
{
    uint32_t 	NL_AsArti_u32;      /* Maximum time between the starting of the transmission and */
                                    /* actual transmission of the message */
    uint32_t 	NL_Bsmaxti_u32;     /* Maximum time between FF/CF(CTS)/FC(WTS) and FC */
    uint32_t 	NL_Crmaxti_u32;     /* Maximum time between FC(CTS) and CF */
    uint8_t 	NL_BSmax_u8;        /* Maximum number of Consecutive frame to be transmitted as Blocks ( BSMax) */
    uint8_t 	NL_STmin_u8;        /* Minimum separation time */
    uint8_t 	NL_WFTmax_u8;       /* Maximum number of wait to send flow control to be sent or processed */
}DCAN_nlTimingCfg_st_t;

/* Input vector table for network layer */
typedef const struct
{
    uint32_t 	Rx_CanFuncID_u32;             /* Receive CAN Functional ID */
    uint32_t 	Rx_CanPhyID_u32;              /* Receive CAN Physical ID */
    uint32_t 	Tx_CanRespID_32;              /* Transmit CAN ID */
    DCAN_nlTimingCfg_st_t *timingData_ps;/* Timing Structure */
    uint16_t 	canhandle_u16;                /* CAN Rx handle */
    uint16_t 	canTxhandle_u16;              /* CAN Tx handle */
    uint8_t 	canNode_u8;                    /* CAN node number */
    uint8_t 		sendDlcEight_b;                /* True = Send with DLC has eight,False = send actual DLC */
}DCAN_nlInputVector_st_t;

/*  Structure which holds details for each message frames TX/RX */
//#pragma pack(push, 4)
typedef struct
{
    uint32_t    timer_u32;              /* Timer */
    uint16_t    bufferindex_u16;        /* Buffer index */
    uint16_t    bufferlength_u16;       /* Buffer length */
    uint16_t    datatoRxTx_u16;         /* Data to Receive and Transmit */
    uint8_t     *buffer_pu8;            /* Buffer pointer */
    uint8_t     bufferstate_u8;         /* Buffer State */
    uint8_t     nl_state_u8;            /* Network layer state */
    uint8_t     activeNlhandle_u8;      /* Active Network layer handle */
    uint8_t     wtsfcCtrl_u8;           /* Wait to send flow Control */
    uint8_t     SNCtr_u8;               /* Sequence Counter */
    uint8_t     BSmaxCtr_u8;            /* Bsmax Counter */
    uint8_t     stmin_u8;               /* active Stmin timer */
    uint8_t     BSmax_u8;               /* BSmax value */

}DCAN_nlFrameCtrl_st_t;
//#pragma pack(pop)


/*
 **************************************************************************************************
 *    Variables
 **************************************************************************************************
*/

// Hold the channel two data for receiption. 
extern DCAN_nlFrameCtrl_st_t 		        CH1_nlFrameCtrl_st[DCAN_TP_INSTANCE_TOTAL_E]; 
extern DCAN_TP_InstanceCANSignConf_St_t     DCAN_TP_InstanceCANSignConf_aSt[DCAN_TP_INSTANCE_TOTAL_E];
extern DCAN_nlFrameCtrl_st_t 		        CH2_nlFrameCtrl_st[DCAN_TP_INSTANCE_TOTAL_E];
extern DCAN_nlFrameCtrl_st_t*		        DCAN_nlFrameCtrl_paSt[DCAN_TP_INSTANCE_TOTAL_E][TOTAL_CH];
extern uint8_t* 					        CHBuffer_au8[DCAN_TP_INSTANCE_TOTAL_E][TOTAL_CH];
extern DCAN_nlInputVector_st_t*	            DCAN_nlInputVector_pst[DCAN_TP_INSTANCE_TOTAL_E];
extern DCAN_nlInputVector_st_t 	            DCAN_nlInputVector_st[DCAN_TP_INSTANCE_TOTAL_E];
extern uint8_t                              FunAddessedID_flag ;



/*
 **************************************************************************************************
 *    Function prototypes
 **************************************************************************************************
*/ 
/**
 *  FUNCTION NAME : DCAN_NL_Init
 *  @param        : none
 *
 *  @brief        : intialise the interal network layer message control register struct
 *                  DCAN_nlFrameCtrl_st
 *
 *  @return       : none
 *
 *  @code tag     : @[CODE_I5765_DCAN_NLINIT_DERIVED] @{SDD_I5765_DCAN_NLINIT_DERIVED}
 *
 */
 void DCAN_NL_Init (void);


/**
 *  FUNCTION NAME : DCAN_RegisterCbk
 *
 *  @param        : none
 *
 *  @brief        : Register the application layer callback function.
 *
 *  @return       : none
 *
 */
extern void DCAN_NL_RegisterCbk      (DCAN_Appl_fcbk Appl_cbk);
extern bool DCAN_NL_TX (uint16_t instanceIndex_u8 , uint8_t* databuffer_pu8, uint16_t datalength_u16);
extern void DCAN_Co_Proc            (void);
extern void DCAN_NL_Proc_5ms        (void);
extern void CANSched_RxMsgCallback  (uint16_t CIL_SigName_En, CAN_MessageFrame_St_t* Can_Applidata_St);
#endif

/* *****************************************************************************
 End of File
 */
 
