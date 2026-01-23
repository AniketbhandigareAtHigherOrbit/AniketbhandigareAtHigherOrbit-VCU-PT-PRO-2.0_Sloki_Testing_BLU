/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : i15765_priv.h
|    Project        : MIL_PBL_CV
|    Description    : ontains all private declaration for Diagnostics on CAN (DCAN).
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

/*
 **************************************************************************************************
 *    Includes
 **************************************************************************************************
*/
#ifndef _I15765_PRIV_H_
#define _I15765_PRIV_H_

//#include <stdint.h>
#include "cil_can_conf.h"

/*
 ***************************************************************************************************
 *    Defines
 ***************************************************************************************************
*/

/* Types of frames */
#define DCAN_PCI_SF           (0x00)  /* PCI for Single frame       */
#define DCAN_PCI_FF           (0x10)  /* PCI for First frame        */
#define DCAN_PCI_CF           (0x20)  /* PCI for consecutive frame  */
#define DCAN_PCI_FC           (0x30)  /* PCI for Flow control frame */

/* Types of Flow control */
#define DCAN_FC_CTS           (0x00)  /* Continue to send flow status */
#define DCAN_FC_WAIT          (0x01)  /* Wait to send flow status     */
#define DCAN_FC_OVERFLOW      (0x02)  /* Overcflow status             */

#define DCAN_MAXDLC           (0x08)
             

/*
 **************************************************************************************************
 *    Enum definitions
 **************************************************************************************************
*/

/* Target address type */
typedef enum
{
    TATYPE_PHYSICAL_E = 0,     /* 1-to-1 communication                    */
    TATYPE_FUNCTIONAL_E        /* 1-to-n communication(only single frame) */
}DCAN_TAtype_en_t;

/*
   Message type : used to identify the type and range of address information parameters included
                  in service call
*/
/*  @code tag     : @[CODE_DCAN_MTYPE] @{SDD_DCAN_MTYPE} */

typedef enum
{
    MTYPE_DIAG_E = 0,          /* Diagnostics        */
    MTYPE_REMDIAG_E            /* Remote Diagnostics */
}DCAN_Mtype_en_t;

/*
   Contains the status relating to the outcome of a service execution.
   if two or more errors are discovered at the same time , then the network layer entity shall
   use the parameter value first found in this list in the error indication to the higher layers
*/
/*  @code tag     : @[CODE_DCAN_NLRESULT] @{SDD_DCAN_NLRESULT} */

typedef enum
{
    DCAN_NL_OK_E = 0,               /* Network layer transmission/Reception is O.K */
    DCAN_NL_TIMEOUT_A_E,            /* Frame transmission timeout */
    DCAN_NL_TIMEOUT_Bs_E,           /* Sender side timeout */
    DCAN_NL_TIMEOUT_Cr_E,           /* Receiver side timeout */
    DCAN_NL_WRONG_SN_E,             /* Wrong Sequence number */
    DCAN_NL_INVALID_FS_E,           /* Invalid FS */
    DCAN_NL_UNEXP_PDU_E,            /* Unexpected frame */
    DCAN_NL_WFT_OVRN_E,             /* Wait frame over run */
    DCAN_NL_BUFFER_OVFLW_E,         /* Buffer overflow */
    DCAN_NL_ERROR_E                 /* Unknown Error */
}DCAN_NLResult_en_t;
    
/* Different Status of the network layer */
typedef enum
{
    DCAN_NL_ST_IDLE_E,         /* Idle state */
    DCAN_NL_ST_WAITFC_E,       /* Wait for Flow control  TX IN PROG */
    DCAN_NL_ST_WAITCF_E,       /* Wait for consecutive frame  RX IN PROG */
    DCAN_NL_ST_SENDFC_E,       /* Send flow control RX IN PROG */
    DCAN_NL_ST_SENDFC_OVR_E,   /* Send flow control with flow status as overflow */
    DCAN_NL_ST_SENDCF_E        /* Send consecutive frames  TX IN PROG */
}DCAN_NLStatus_en_t;

/* Contains the status relating to the outcome of a service execution for parameter changes*/
typedef enum
{
    DCAN_NL_PAR_OK_E = 0,                /* Service execution completed */
    DCAN_NL_PAR_RX_ON_E,                 /* Service did not execute on the receiver side only */
    DCAN_NL_PAR_WRONG_PARAMETER_E,       /* Undefined parameter */
    DCAN_NL_PAR_WRONG_VALUE_E            /* Out of range */
}DCAN_ResChngPar_en_t;

/* Responses types for internal state  machine of the module */
typedef enum
{
    DCAN_NO_RESP_AGAIN_E = 0x00,    /* No response again*/
    DCAN_NO_RESPONSE_E,             /* No response */
    DCAN_RESPONSE_OK_E,             /* Response is either is POS or NEG */
    DCAN_RESPONSE_PENDING_E,        /* Response is either POS AGAIN or NEG again */
    DCAN_RESPONSE_WAITPEND_E,       /* Response is wait pend */
    DCAN_RESPONSE_WAITBUSYREPEAT_E  /* Response is of type wait busy repeat request */
}DCAN_RESPONSE_en_t;

/* NL buffer State */
typedef enum
{
    DCAN_NL_STBUFF_IDLE_E,   /* Buffer is in the idle state */
    DCAN_NL_STBUFF_AL_E,     /* Buffer is locked by the application layer */
    DCAN_NL_STBUFF_NL_E      /* Buffer is locked by the network layer */
}DCAN_StatusNlBuf_en_t;

/*
 **************************************************************************************************
 *    Structure definitions
 **************************************************************************************************
*/
/*  @code tag     : @[CODE_DCAN_AI] @{SDD_DCAN_AI} */

// structure which holds Address Information
typedef struct
{
    uint8_t DCAN_N_SA;     /* Network Source Address */
    uint8_t DCAN_N_TA;     /* Network Target Address   */
    uint8_t DCAN_N_AE;     /* Network Address Extension */
    DCAN_TAtype_en_t  DCAN_N_TAtype; /* Network Target address type */
}DCAN_Net_AI;

/*
 **************************************************************************************************
 *    Variables
 **************************************************************************************************
*/
typedef void (*DCAN_Appl_fcbk)(uint16_t Signal_instance_u16,nl2tp_CbkType_En_t, const uint8_t*, uint16_t);
extern DCAN_Appl_fcbk DCAN_ApplCbk;


/*
 **************************************************************************************************
 *    Function prototypes
 **************************************************************************************************
*/

//extern void DCAN_NLConfirm (uint16_t buffer_index_u8 , DCAN_NLResult_en_t nl_result);
//extern void DCAN_NLFFIndication (uint16_t buffer_index_u8 , uint16_t datalength_u16);
//Sloki : Changing for Multiple Instances
extern void DCAN_NL_RX( uint32_t CanId_u32, uint8_t dlc_u8, uint8_t *data_pu8);
//  void DCAN_NL_RX(uint16_t SigName_u16, uint32_t CanId_u32, uint8_t dlc_u8, uint8_t *data_pu8);

extern void DCAN_NLUnlockBuffer (void);
extern void DCAN_NLLockBufferForAL (void);

#endif

/* *****************************************************************************
 End of File
 */
