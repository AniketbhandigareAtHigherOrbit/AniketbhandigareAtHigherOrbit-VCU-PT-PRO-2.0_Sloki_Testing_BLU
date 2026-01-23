/******************************************************************************
 *    FILENAME    : j1939.h
 *
 *    DESCRIPTION : Contains all declaration and interfaces used for J1939 
 *
 *    AUTHOR      :
 *
 *    $Id         : $    
 *
 ******************************************************************************
 * Revision history
 * 
 * Ver Author       Date               Description
 * 1   Sloki             
 ******************************************************************************
*/    
#ifndef __J1939_H_
#define __J1939_H_

/*
 ******************************************************************************
 *    Includes
 ******************************************************************************
*/
#include "can_if.h"
#include "j1939_conf.h"
#include "j1939_81_nmac.h"
#include "j1939_71.h"

/*
 ******************************************************************************
 *    MACROS and  Defines
 ******************************************************************************
*/
#define TTL_DM1_SA  (7u)

/*
 ****************************************************************************************
 *    ENUM Definition 
 ****************************************************************************************
*/

/*
    Contains the buffer status of J1939
*/
typedef enum
{
    J1939_BUFF_IDLE_E,
    J1939_BUFF_BAM_E,
    J1939_BUFF_RTS_CTS_E,
    J1939_BUFF_AL_E
}J1939_buf_En_t;

/*
    Contains the connection abort reason
*/
typedef enum
{
    J1939_ALREADY_IN_SESSION_E = 1,
    J1939_NEED_RESOURCES_E,
    J1939_TIMEOUT_E
}J1939_ConnAbortReason_En_t;

/*
    Contains control byte for acknowledgment
*/
typedef enum
{
    J1939_POSITIVE_ACK_E,
    J1939_NEGATIVE_ACK_E,
    J1939_ACCESS_DENIED_E,
    J1939_CANNOT_RESPOND_E
}J1939_ACK_Reason_En_t;

/*
    Contains the transport layer status of J1939
*/
typedef enum
{
    J1939_TL_ST_IDLE_E,
    J1939_TL_ST_WAIT_EOMSG_ACK_E,
    J1939_TL_ST_WAIT_RTS_E,
    J1939_TL_ST_WAIT_CTS_E,
    J1939_TL_ST_WAIT_TO_SEND_DT_E,
    J1939_TL_ST_SEND_DT_E,
    J1939_TL_ST_SEND_CONN_ABORT_E,
    J1939_TL_ST_WAIT_DT_E,
    J1939_TL_ST_WAIT_TO_NEXT_DT_E   
}J1939_TLStatus_En_t;

/*
    Contains the Buffer Index of J1939 Tx and Rx
*/
typedef enum
{
    J1939_TX_BUFF_E,
    J1939_RX_BUFF_E 
}J1939_BuffIndex_En_t;

/*
 ****************************************************************************************
 *    Structure Definition 
 ****************************************************************************************
*/
#pragma(1)
typedef struct 
{
    uint32_t timer_u32;           /* Timer */
    /*
    @@ ELEMENT    = pgn_u32
    @@ STRUCTURE  = J1939_TpMsg_St_t
    @@ A2L_TYPE   = PARAMETER
    @@ DATA_TYPE  = $uint32_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= "PGN"
    @@ END
    */
    uint32_t pgn_u32;                /* To store PGN */
    
    /*
    @@ ELEMENT    = bufferindex_u16
    @@ STRUCTURE  = J1939_TpMsg_St_t
    @@ A2L_TYPE   = PARAMETER
    @@ DATA_TYPE  = $uint16_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= "PGN"
    @@ END
    */
    uint16_t bufferindex_u16;     /* Buffer index */
    
    /*
    @@ ELEMENT    = bufferlength_u16
    @@ STRUCTURE  = J1939_TpMsg_St_t
    @@ A2L_TYPE   = PARAMETER
    @@ DATA_TYPE  = $uint16_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= "PGN"
    @@ END
    */
    uint16_t bufferlength_u16;    /* Buffer length */
    uint8_t  *buffer_pu8;         /* Buffer pointer */
    
     /*
    @@ ELEMENT    = seqctr_u8
    @@ STRUCTURE  = J1939_TpMsg_St_t
    @@ A2L_TYPE   = PARAMETER
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= "Seq num"
    @@ END
    */
    uint8_t  seqctr_u8;           /* Sequence counter for multi packet message */
    uint8_t  bufferstate_u8;      /* Buffer State */
    uint8_t  tl_state_u8;            /* Transport layer state */
    /*
    @@ ELEMENT    = max_packets_u8
    @@ STRUCTURE  = J1939_TpMsg_St_t
    @@ A2L_TYPE   = PARAMETER
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= "max packet"
    @@ END
    */
    uint8_t  max_packets_u8;        /* Maximum number of packets that can be sent 
                                       in response to one CTS */ 
                                       
    /*
    @@ ELEMENT    = total_packets_u8
    @@ STRUCTURE  = J1939_TpMsg_St_t
    @@ A2L_TYPE   = PARAMETER
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= "total packet"
    @@ END
    */   
    uint8_t  total_packets_u8;    /* Total number of packets */
    
     /*
    @@ ELEMENT    = num_packets_to_send_u8
    @@ STRUCTURE  = J1939_TpMsg_St_t
    @@ A2L_TYPE   = PARAMETER
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= "packet to send"
    @@ END
    */ 
    uint8_t  num_packets_to_send_u8;/* Number of packets to be sent or to send */
    uint8_t  num_packets_to_receive_u8;/* Number of packets to be sent or to send */
    uint8_t  other_ecu_add_u8;    /* To store the tester address */
    /*
    @@ ELEMENT    = num_packet_recd_u8
    @@ STRUCTURE  = J1939_TpMsg_St_t
    @@ A2L_TYPE   = PARAMETER
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= "packet to send"
    @@ END
    */ 
    uint8_t  num_packet_recd_u8;    /* To store number of packets received */
    
    /*
    @@ ELEMENT    = next_packet_num_u8
    @@ STRUCTURE  = J1939_TpMsg_St_t
    @@ A2L_TYPE   = PARAMETER
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= "next packet"
    @@ END
    */
    uint8_t  next_packet_num_u8;   
    
     /*
    @@ ELEMENT    = last_CTS_maxPackets_u8
    @@ STRUCTURE  = J1939_TpMsg_St_t
    @@ A2L_TYPE   = PARAMETER
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= "next packet"
    @@ END
    */
    uint8_t last_CTS_maxPackets_u8;                                        
}J1939_TpMsg_St_t;

/*Structure to hold the received data and related component*/
typedef struct
{
    uint32_t 	PGN_u32;
    uint16_t 	len_u16;
    uint8_t     SA_u8;
    uint8_t 	DMxData[MAX_BUFFER_SIZE];
}DM_DataPackets_St_t;

typedef void (*DMRxClbk_Fptr_t)(DM_DataPackets_St_t* DataPackets_pSt);

/*
 ******************************************************************************
 *    Variable declarations
 ******************************************************************************
*/

extern J1939_TpMsg_St_t *J1939_TpMsg_paSt[TOTAL_CH][J1939_SA_TOTAL_NUM];

/*
 ******************************************************************************
 *    Function declarations
 ******************************************************************************
*/
/*Scheduler al function declaration*/
#if(TRUE == DIAG_CONF_J1939_SUPPORTED)
 extern void J1939_Init(void);
 extern void J1939_sched_50ms (void);
#endif

/*J1939 callback function declaration*/
 extern bool J1939_tx_reqPGN(uint8_t dest_addr_u8 ,uint32_t req_pgn_u32); 
 extern void J1939_rqPgnClbk_timeout (void);
 extern void J1939_reqPgnClbk (uint16_t CIL_SigName_En, CAN_MessageFrame_St_t* Can_Applidata_St);
 extern void J1939_tpcmClbk (uint16_t CIL_SigName_En, CAN_MessageFrame_St_t* Can_Applidata_St);
 extern void J1939_tpdtClbk (uint16_t CIL_SigName_En, CAN_MessageFrame_St_t* Can_Applidata_St);
 extern void J1939_dm22Clbk (uint16_t CIL_SigName_En, CAN_MessageFrame_St_t* Can_Applidata_St);

/*J1939 TP layer function declaration*/
 extern void J1939_tp_RegDMRxClbk(DMRxClbk_Fptr_t DMRxClbk);
 extern void J1939_tp_init(void);
 extern void J1939_tp_tx_init(uint8_t instNum_u8);
 extern void J1939_tp_rx_init(uint8_t instNum_u8);
 extern void J1939_tp_txDtManage(void);
 extern void J1939_tp_txCMbam(uint16_t len_u16, uint32_t pgn_u32, uint8_t index_u8);
 extern void J1939_tp_txTpdt(uint8_t BuffIndex_u8, uint8_t SA_index_u8);
 extern void J1939_tp_txCMrts(uint16_t len_u16, uint32_t pgn_u32, uint8_t index_u8);
 extern void J1939_tp_txConnAbort(uint8_t conn_abort_reason_u8, uint32_t pgn_u32, uint8_t address_u8, J1939_BuffIndex_En_t Buff_En);                                    
 extern void J1939_tp_txCMcts(uint8_t seq_ctr_u8, uint8_t InstNum_u8);
 extern void J1939_tp_rxdt(const uint8_t buffer_au8[], uint8_t SAInstance_u8);
 extern void J1939_tp_rxdtbam(uint8_t BuffIndex_u8, const uint8_t buffer_au8[],uint8_t reqSAInstance_u8);
 extern void J1939_tp_txEndOfMsgAck(uint8_t SAInstance_u8);
 extern void J1939_tp_rxEndOfMsgAck(uint8_t SAInstance_u8);
 extern uint8_t J1939_tp_dataCopy(const uint8_t srcaddr_pu8[],uint8_t destaddr_pu8[], uint16_t len_u16);
 extern void J1939_PgnSfClbk(uint16_t CIL_SigName_En, CAN_MessageFrame_St_t* Can_Applidata_St);
 // extern bool J1939_appl_send_request(uint8_t dest_addr_u8 ,uint32_t req_pgn_u32);  
#endif


