/*
 ****************************************************************************************
 *    FILENAME    : j1939_73_dmx.h
 *
 *    DESCRIPTION : File contains .c related definitions and declarations.
 *
 *    $Id         : $
 *
 ****************************************************************************************
 * Revision history
 *
 * Ver Author              Date              Description
 * 1   Sloki    
 ****************************************************************************************
*/

/*
 ****************************************************************************************
 *    Includes
 ****************************************************************************************
*/
#ifndef _J1939_73_DMX_H_
#define _J1939_73_DMX_H_

#include "can_sched_conf.h" 
#if(TRUE == DIAG_CONF_FM_SUPPORTED)
	#include "fmdtc_conf.h"
#endif

#if(TRUE == DIAG_TEST_J1939_DEMO)
	#include "diag_appl_test.h"
#endif

/*
 ****************************************************************************************
 *    Defines
 ****************************************************************************************
*/  
#define J1939_73_APPL_BUFF_LEN        			255U
#define DM1_PERIODICITY_MILLISECS    1000U   /* 1000ms*/

/* For DM22 */
#define CTRL_CLR_PREVACT_FLT       0X01U     /* Request to clear/reset previously active DTC control byte        */
#define POSITIVE_ACK_PREVACT_FLT   0X02U     /* Positive Acknowledge of to clear/reset previously active DTC     */
#define NEGATIVE_ACK_PREVACT_FLT   0X03U     /* Negative Acknowledge of to clear/reset previously active DTC     */
#define CTRL_CLR_ACT_FLT           0X11U     /* Request to clear/reset  active DTC control byte                  */
#define POSITIVE_ACK_ACT_FLT       0X12U     /* Positive Acknowledge of to clear/reset  active DTC               */
#define NEGATIVE_ACK_ACT_FLT       0X13U     /* Negative Acknowledge of to clear/reset  active DTC               */


#define J1939_GLBACK_BASE_ID       0x18E8FF00UL  /* Priority + PGN + global destination for acknowldgement.*/

/*
 ****************************************************************************************
 *    ENUM Definition 
 ****************************************************************************************
*/
typedef enum
{
    J1939APPL_NO_RESP = 0,
    J1939APPL_SF_RESP = 1,
    J1939APPL_MF_RESP = 2,
    J1939APPL_ACK_POS = 3,
    J1939APPL_ACK_NEG = 4,
    J1939APPL_ACK_ACCESSDENIED = 5,
    J1939APPL_ACK_ECUBUSY = 6
}J1939Appl_DMxRetStatus_En_t;

typedef enum
{
    J1939_APPL_IDLE_E,                /* IDLE state */
    J1939_APPL_SERV_INPROGRESS_E,     /* Service in processing */
    J1939_APPL_RESP_SF_PROGRESS_E,    /* Single frame response */
    J1939_APPL_RESP_MF_PROGRESS_E     /* Multi frame response */
}J1939_stateAppl_En_t;

/*
 ****************************************************************************************
 *    Structure Definition 
 ****************************************************************************************
*/

typedef union
{
    uint32_t W_u32;
    struct
    {
        uint32_t SPN_b19 : 19;
        uint32_t FMI_b5  : 5;
        uint32_t CM_b1   : 1;
        uint32_t OC_b7   : 7;
    }B;
}J1939DTC_Uni_t;


typedef union
{
    uint32_t all_u32;
    struct
    {
        bool MIL_b;
        bool RSL_b;
        bool AWL_b;
        bool PL_b;
    }B;	
}stLamps_Uni_t;

typedef struct
{

   /*
    @@ ELEMENT    = respLen_u32
    @@ STRUCTURE  = J1939_Appl_St_t
    @@ A2L_TYPE   = MEASURE
    @@ DATA_TYPE  = $uint32_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= ""
    @@ END
    */
    uint32_t  respLen_u32;                  /* response length */ 

   /*
    @@ ELEMENT    = pgn_u32
    @@ STRUCTURE  = J1939_Appl_St_t
    @@ A2L_TYPE   = MEASURE
    @@ DATA_TYPE  = $uint32_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= ""
    @@ END
    */
    uint32_t  pgn_u32;                      /* PGN value of the response */ 

   /*
    @@ ELEMENT    = dataBuff
    @@ STRUCTURE  = J1939_Appl_St_t
    @@ A2L_TYPE   = MEASURE
    @@ DATA_TYPE  = $uint8_t$
    @@ DIMENSION  = 255
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= ""
    @@ END
    */
    uint8_t   dataBuff[J1939_73_APPL_BUFF_LEN];                /* application layer buffer for response */ 

    /*
    @@ ELEMENT    = otherAdd_u8
    @@ STRUCTURE  = J1939_Appl_St_t
    @@ A2L_TYPE   = MEASURE
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= ""
    @@ END
    */
    uint8_t  otherAdd_u8;                  /* Address of other ECU */ 
    
    /*
    @@ ELEMENT    = isDestSpecific_b
    @@ STRUCTURE  = J1939_Appl_St_t
    @@ A2L_TYPE   = MEASURE
    @@ DATA_TYPE  = $bool$
    @@ CONVERSION = LINEAR $RADIX_0$ ""
    @@ DESCRIPTION= ""
    @@ END
    */
    bool  isDestSpecific_b;                  /* differentiate between BAM and RTS */ 
    /*
    @@ ELEMENT    = stateAppl_En
    @@ STRUCTURE  = J1939_Appl_St_t
    @@ A2L_TYPE   = MEASURE
    @@ DATA_TYPE  = $uint32_t$
    @@ CONVERSION = TABLE 0 "IDLE" 1 "SERV_INPROGRESS" 2 "SF_PROGRESS" 3 "MF_PROGRESS"
    @@ DESCRIPTION= ""
    @@ END
    */
    J1939_stateAppl_En_t  stateAppl_En;   /* state of the J1939-73 state machine */
}J1939_Appl_St_t;


/*
 ****************************************************************************************
 *    al Variables
 ****************************************************************************************
*/ 
extern J1939_Appl_St_t  J1939_appl_St;     /* J1939-73 diag appl layer data structure */

/*
 ****************************************************************************************
 *    Function Prototypes
 ****************************************************************************************
*/
extern void 	J1939_DM1_schedTask (void);
extern J1939Appl_DMxRetStatus_En_t J1939_TX_claimedAddress (CAN_MessageFrame_St_t* Can_Applidata_St);
extern J1939Appl_DMxRetStatus_En_t J1939_TX_DM1 (CAN_MessageFrame_St_t* Can_Applidata_St, uint8_t reqSAIndex_u8);
extern J1939Appl_DMxRetStatus_En_t J1939_TX_DM2 (CAN_MessageFrame_St_t* Can_Applidata_St, uint8_t reqSAIndex_u8);
extern J1939Appl_DMxRetStatus_En_t J1939_TX_DM3 (CAN_MessageFrame_St_t* Can_Applidata_St, uint8_t reqSAIndex_u8);
extern J1939Appl_DMxRetStatus_En_t J1939_TX_DM4 (CAN_MessageFrame_St_t* Can_Applidata_St, uint8_t reqSAIndex_u8);
extern J1939Appl_DMxRetStatus_En_t J1939_TX_DM6 (CAN_MessageFrame_St_t* Can_Applidata_St, uint8_t reqSAIndex_u8);
extern J1939Appl_DMxRetStatus_En_t J1939_rqPgnSample_Callback(CAN_MessageFrame_St_t *Can_Applidata_St, uint32_t pgnIndex_u32, uint8_t SAIndex_u8);
extern void J1939_RTS_TEST(void);
extern uint8_t GetSourceAddrInst(uint8_t ReqSA_u8);
#endif


