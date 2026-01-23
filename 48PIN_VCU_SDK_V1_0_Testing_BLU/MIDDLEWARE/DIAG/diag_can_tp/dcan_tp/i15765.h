/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : i15765.h
|    Project        : MIL_PBL_CV
|    Description    : Implements the CAN TP & NL layer (header file)
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


#ifndef _ISO15765_TP_H_
#define _ISO15765_TP_H_

/*
 *********************************************************************************
 *    Includes
 *********************************************************************************
*/
//#include <stdint.h>
#include "i15765_conf.h"

/*
************************************************************************************
*  Defines
************************************************************************************
*/
#define SID_INDEX                                                         0
#define RESPCODE_INDEX                                                    0
#define NUM_TIMESLICE_TO_WAIT                                             5




/* Return parameters for CAN Transmit functions */
#define DCAN_FRAMESENT       	0x00U
#define DCAN_FRAMENOTSENT    	0x01U

/* Return parameters for CAN Transmit functions */
#define DCAN_MSGSENT       		0x00U
#define DCAN_MSGNOTSENT    		0x01U
#define DCAN_MSGABRTTX     		0x02U
#define TOTAL_TIMING_PARAMETERS  0x02

/**
     Structure to handle application layer state machine
*/
typedef enum
{
    DCAN_TP_ST_IDLE_E,           // Idle State
    DCAN_TP_ST_RX_INPROG_E,      // Rx is in progress waiting for NLIndication
    DCAN_TP_ST_RX_COMPLETE_E,    // Rx complete obtained NlIndication
    DCAN_TP_ST_RESP_PEND_E,      // Request received response pending
    DCAN_TP_ST_TX_INITIATED_E,   // Data transmission for response initiated
    DCAN_TP_ST_TX_INPROG_E,      // Response data transmission in progress
    DCAN_TP_ST_PROC_REQ_E        // Process the request
}DCAN_TPStatus_En_t;

/**
     Structure to manage the P2 timings
*/
typedef  struct
{
    uint32_t P2_u32;  // Configuration for P2 timings ISO 15765 limits it to 50ms max
    uint32_t P3_u32;  // Configuration for P3 timings ISO 15765 limits it to 5000ms max

}DCAN_TPTimingCfg_St_t;

/**
     Structure to manage application layer data Rx and Tx
*/
typedef struct
{
    uint32_t 	timer_u32;         // Current value of the timer
    uint32_t 	P2_timings_u32;    // P2 time. Captured by the network layer during NlIndication
    uint8_t* 	databuf_pu8;       // Pointer to the main data buffer
    uint16_t 	numbytes_req_u16;  // Numbytes in request. Filled by the NL (copy of bufferlength_u16)
    uint16_t 	numbytes_resp_u16; // Number of bytes in the response. Filled by the calling service
    uint8_t 		flag_P2Ext_b;        // Flag to indicate if P2 timing is extended
    uint8_t  	al_state_u8;       // Application state.
    uint8_t 		flag_FF_rcvd_b;      // Flag for FF frame indication
    uint8_t 		flag_new_req_rcvd_b; // Flag for new request indication
    uint8_t 		flag_confirm_b;      // Flag for confirmation of response message transmission
    uint8_t 		flag_err_in_rx;      // Flag for error in reception
    uint8_t 		flag_err_in_tx;      // Flag for error in transmission
	uint8_t 		tx_prcwait_b;	
	uint32_t 	sessionTimeoutTimer_u32;
}DCAN_tpFrameCtrl_St_t;

// DCAN_tpFrameCtrl_paSt


//Sloki : Changing for Multiple Instances	
// Management of pointer to the global application frame structure
// Configuration structure for application timing
extern DCAN_TPTimingCfg_St_t DCAN_TPTiming_St;

// Transport layer process scheduled periodically
extern void DCAN_TP_Proc_5ms(void);
//This function is called after receiving NL_Indication from network layer
extern void DCAN_TP_NewReqRecd (uint8_t canTpInstanceId_u16,uint16_t numbytes_req_u16);
//This function is called after receiving FF Indication from network layer
extern void DCAN_TP_FFRecd (uint8_t Index_instance_u8);
//This function is called after receiving NL_Confirm from network layer
extern void DCAN_TP_TxConf (uint8_t Index_instance_u8);
//  void DCAN_ALInit (void);
//This function is called if the error in transmission occurs
extern void DCAN_TP_TxErr (uint8_t Index_instance_u8);
//This function is called if the error in reception occurs
extern void DCAN_TP_RxErr (uint8_t canTpInstanceId_u16);
// Transport layer initialization process
extern void DCAN_TP_Init (void);
extern void CANSched_RxMsgCallback(uint16_t CIL_SigName_En, CAN_MessageFrame_St_t* Can_Applidata_St);

// Do not delete the  statement below its used only for geenrating a compile time error
// This line is used for error handling only
// Check if the diagnostic buffer is greater than atleast 128 bytes
// If the diagnostic buffer size is less than 128, then we will get a compile time error.
// Check the #define and modify it
//  uint8_t test_diagbuffer[MAX_LENGTH_DIAGBUFFER-128];


extern void clearBuffer(uint16_t signal_Index_u16,TP_Buff_En_t TP_Buff_En);
// Do not delete the  statement below its used only for generating a compile time error
// This line is used for error handling only
// Check if the diagnostic buffer is greater than atleast 128 bytes
// If the diagnostic buffer size is less than 128, then we will get a compile time error.
// Check the #define and modify it
//  uint8_t test_diagbuffer[MAX_LENGTH_DIAGBUFFER-128];
extern DCAN_TPTimingCfg_St_t  DCAN_TPTimings_aSt[TOTAL_TIMING_PARAMETERS];
extern DCAN_TPTimingCfg_St_t DCAN_TPTiming_St;


extern DCAN_tpFrameCtrl_St_t *DCAN_tpFrameCtrl_paSt[DCAN_TP_INSTANCE_TOTAL_E][TOTAL_CH];
extern void i15765_tp_init_buffers(void);
extern void Diag_Disable_Interrupts(void);
extern void Diag_Restore_Interrupts(void);

#endif

/* *****************************************************************************
 End of File
 */
