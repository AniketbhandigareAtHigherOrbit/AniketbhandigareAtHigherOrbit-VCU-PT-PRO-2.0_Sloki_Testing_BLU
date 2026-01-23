/******************************************************************************
 *    FILENAME    : can_sched_conf.h
 *    DESCRIPTION : This file contains buffer for CIL layer data extraction as  and other structs defined in i15676.h
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/  

#ifndef CAN_SCHED_CONF_H_
#define CAN_SCHED_CONF_H_

#include "can_if.h"
#include "diag_typedefs.h"
#include "diag_sys_conf.h"
#if(TRUE == DIAG_CONF_CANTP_SUPPORTED)
	#include "i15765.h"
#endif
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */
#define 	J1939_CONF_SCHED_TICK_PERIOD		(5) 		// in terms of 1ms.

#define    	PERIODICITY_MS(x)  					((x)/J1939_CONF_SCHED_TICK_PERIOD)
#define    	NO_TIMEOUT   						0

#if(TRUE == DIAG_CONF_J1939_SUPPORTED)

#define  BITPOSTX_CAN_DM1_TIME      0U
#define  BITPOSTX_CAN_DM1_EVENT     1U
#define  BITPOSRX_CAN_SPECREQ       2U
#define  BITPOSRX_CAN_TPCMRX        3U
#define  BITPOSRX_CAN_TPCMBAM       4U
#define  BITPOSRX_CAN_TPDTRX        5U
#define  BITPOSRX_CAN_TPDTBAM       6U
#define  BITPOSRX_CAN_DM22          7U
#define  BITPOSRX_CAN_J1939_81_NMAC 8U
#define  BITPOSRX_CAN_J1939_REQ_DA  9U
#define  BITPOSRX_CAN_J1939_REQ_MA  10U

#endif
/*Reception*/

typedef void (*CANSCHED_CB_Fptr_t)( uint16_t sig,  CAN_MessageFrame_St_t* msg_rf );
typedef bool (*CAN_SIGALC_MSGA_Fptr_t)(uint32_t  Bitpos);
typedef void (*CANSCHED_TCB_Fptr_t)(void);
  

/*
 ******************************************************************************
 *    CAN SCHEDULER configuration structure
 ******************************************************************************
*/ 
#pragma  pack(1)
typedef struct
{
    uint32_t                    CIL_CAN_SigName_En;     /* CIL CAN */
    uint32_t                    Timeoutms_u32;          /* Timeout value in ms */
    CANSCHED_CB_Fptr_t          CANSCHED_CB_Fptr;       /* Receive callback function  */
    CANSCHED_TCB_Fptr_t         CANSCHED_TCB_Fptr;      /* Timeout callback function  */
}CANSCHED_RX_Conf_St_t;

#pragma  pack(1)
typedef struct
{  
    uint32_t                    CIL_CAN_SigName_En;     /* CIL CAN */
    const uint16_t              Cycle_Time_u16;         /* Pointer to constant which contains the cylce time in ms */
    const uint16_t		Offset_Time_u16; 	/* Offset time in ms */
    CANSCHED_TCB_Fptr_t         CANSCHED_CB_Fptr;       /* Tx callback function  */
}CANSCHED_TX_Conf_St_t;

#if(TRUE == DIAG_CONF_UDS_SUPPORTED)
	#define CAN_SCHED_CONF_UDS_RX_MSG (CIL_RX_UDS_END - CIL_RX_UDS_START)
#else
	#define CAN_SCHED_CONF_UDS_RX_MSG 0
#endif

#if(TRUE == DIAG_CONF_OBD2_SUPPORTED)
	#define CAN_SCHED_CONF_OBD_RX_MSG (CIL_RX_OBD_END - CIL_RX_OBD_START)
#else
	#define CAN_SCHED_CONF_OBD_RX_MSG 0
#endif

#if(TRUE == DIAG_CONF_J1939_SUPPORTED)
	#define CAN_SCHED_CONF_J1939_RX_MSG (CIL_RX_J1939_END - CIL_RX_J1939_START)
#else
	#define CAN_SCHED_CONF_J1939_RX_MSG 0
#endif

#define CAN_SCHED_CONF_TOTAL_RX_MSG     (CAN_SCHED_CONF_UDS_RX_MSG + CAN_SCHED_CONF_OBD_RX_MSG + CAN_SCHED_CONF_J1939_RX_MSG) + 3u  // This shall be updated manually by the user depending on number of entries in the Rx conf table.
extern  const CANSCHED_RX_Conf_St_t   CANSCHED_RX_Conf_aSt[];

#if(TRUE == DIAG_CONF_J1939_SUPPORTED)
	#define CAN_SCHED_CONF_J1939_TX_MSG 13
#else
	#define CAN_SCHED_CONF_J1939_TX_MSG 0
#endif
#if(TRUE == DIAG_TEST_FM_DEMO && TRUE == DIAG_CONF_FM_SUPPORTED)
	#define CAN_SCHED_CONF_FM_DEMO_TX_MSG  2
#else
	#define CAN_SCHED_CONF_FM_DEMO_TX_MSG  0
#endif

#define CAN_SCHED_CONF_TOTAL_TX_MSG     CAN_SCHED_CONF_J1939_TX_MSG + CAN_SCHED_CONF_FM_DEMO_TX_MSG + 17//+ 1  // This shall be updated manually by the user depending on number of entries in the Tx conf table.
extern  const CANSCHED_TX_Conf_St_t   CANSCHED_TX_Conf_aSt[];



extern void CanSched_5ms (void);
extern void CAN_CONFIG_CalcCANConfig(void);
#if (TRUE == DIAG_CONF_J1939_SUPPORTED)
extern bool IsTXCanMessageActive(uint32_t BitPosCANMessage);
extern bool IsRXCanMessageActive(uint32_t BitPosCANMessage);
#endif


#endif

/* *****************************************************************************
 End of File
 */
 
 
