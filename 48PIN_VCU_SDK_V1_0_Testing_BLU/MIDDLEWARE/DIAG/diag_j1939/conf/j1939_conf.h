/*
 ****************************************************************************************
 *    FILENAME    : j1939_conf.h
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
#ifndef _J1939_CONF_H_
#define _J1939_CONF_H_
/*
 ****************************************************************************************
 *    Includes
 ****************************************************************************************
*/
#include <stdint.h>
#include <stdbool.h>
#include "j1939_73_dmx.h"
#include "diag_sys_conf.h"
#if (TRUE == DIAG_CONF_FM_SUPPORTED)
#include "fm.h"
#define FM_FAULTPATHS NUM_OF_FAULTPATHS_E
#define FM_L2_ENTRY FM_CONF_MAX_L2FAULT_ENTRIES
#elif (TRUE == DIAG_TEST_J1939_DEMO)
#define FM_FAULTPATHS FM_DUMMY_FAULTPATHS
#define RPM_DUMMY_u16 0
#define FM_L2_ENTRY 0
#else
#define FM_FAULTPATHS 0
#define RPM_DUMMY_u16 0
#define FM_L2_ENTRY 0
#endif
/*
 ****************************************************************************************
 *    Defines
 ****************************************************************************************
 */

/*J1939 configuration*/
#define MAX_BUFFER_SIZE 55U
#define MAX_PACKETS_TO_SEND 16U
#define J1939_ECU_ID 0x17U

/*NMAC configuration*/

/*ECU NAME definition*/
#define J1939_81_NMAC_ARBITRARY_ADDRESS 0x01U /*1 Bit                        */
#define J1939_81_NMAC_INDUSTRY_GROUP 0U       /*3 Bits                       */
#define J1939_81_NMAC_VEHICLE_INSTANCE 0U     /*4 Bits                       */
#define J1939_81_NMAC_VEHICLE_SYSTEM 0U       /*8 Bits (7th bit is reserved) */
#define J1939_81_NMAC_FUNCTION 0U             /*8 Bits                       */
#define J1939_81_NMAC_FUNCTION_INSTANCE 0U    /*5 Bits                       */
#define J1939_81_NMAC_ECU_INSTANCE 0U         /*3 Bits                       */
#define J1939_81_NMAC_MANUFACTURER_CODE 16U   /*11 Bits                      */
#define J1939_81_NMAC_IDENTITY_NUMBER 50U     /*21 Bits                      */

#define NUM_PACKETS_DT 0x07U
#define NUM_DATABYTES_MSG 0x07U
#define MIN_DATALEN_TPCM 9U
#define MAX_DATALEN_TPCM 1785
#define J1939_UNUSEDBYTES 0xFFU
#define J1939_MAXDLC 0x08U
#define J1939_GLOBAL_REQ 0xFFU

#define J1939_SAE_RES 0xFFU
#define J1939_BASE_ID 0x18000000UL     /* J1939 ID filled with PRIORITY filled only.*/
#define J1939_ACK_BASE_ID 0x18E80000UL /* Priority + PGN for acknowldgement.*/
#define J1939_HOURBASE_ID 0x18FEE517UL
#define J1939_TPCM_GLB_ID 0x1CECFF00UL
#define J1939_TPCM_BASE_ID 0x18EC0000UL
#define j1939_tpdt_GLB_ID 0x1CEBFF00UL
#define j1939_tpdt_BASE_ID 0x18EB0000UL
#define j1939_REQMSG_BASE_ID 0x18EA0000UL

/* Parameter Group Numbers */
#define J1939_REQ_PGN 0xEA00U
#define J1939_ACK_PGN 0xE800U
#define J1939_COMMAND_PGN 0xCF00U
#define J1939_TPCM_PGN 0xEC00U
#define J1939_TP_DT_PGN 0xEB00U
#define J1939_81_REQ_PGN 0xEE00U

/* Number of bytes in the data field of Request PGN */
#define J1939_REQ_PGN_LEN 0x3U
#define J1939_PDU1_PF_MAX 0xF0

/* Requested Parameter Group Numbers */
#define J1939_DM1_PGN 65226U /*(0xFECA)*/
#define J1939_DM2_PGN 0xFECBU
#define J1939_DM3_PGN 0xFECCU
#define J1939_DM4_PGN 0xFECDU
#define J1939_DM6_PGN 0xFECFU
#define J1939_DM11_PGN 0xFED3U
#define J1939_DM12_PGN 0xFED4U
#define J1939_DM14_PGN 0xD900U
#define J1939_DM15_PGN 0xD800U
#define J1939_DM16_PGN 0xD700U
#define J1939_DM18_PGN 0xD400U
#define J1939_DM21_PGN 0xC100U
#define J1939_DM22_PGN 0xC300U
#define J1939_DM27_PGN 0xFD82U
#define J1939_DM28_PGN 0xFD80U

/* Requested Parameter Group Numbers Specified*/
#define J1939_SAMPLE1_PGN 0xFEE5
#define J1939_SAMPLE2_PGN 0xFEE9

/* Transport Protocol Connection Management - Control Bytes */
#define J1939_TPCM_CTRLBYTE_RTS 16U
#define J1939_TPCM_CTRLBYTE_CTS 17U
#define J1939_TPCM_CTRLBYTE_EOMSG_ACK 19U
#define J1939_TPCM_CTRLBYTE_BAM 32U
#define J1939_TPCM_CTRLBYTE_CONN_ABORT 255U

/* Timing Parameters */
#define J1939_T1 750U  /* Configuration for T1 timings SAE J1939-21 \
                   limits it to 750ms max */
#define J1939_T2 1250U /* Configuration for T2 timings SAE J1939-21 \
                      limits it to 1250ms max */
#define J1939_T3 1250U /* Configuration for T3 timings SAE J1939-21 \
                      limits it to 1250ms max */
#define J1939_T4 1050U /* Configuration for T4 timings SAE J1939-21 \
                      limits it to 1050ms max */
#define J1939_TR 200U  /* Configuration for Tr timings SAE J1939-21 \
                   limits it to 200ms max */
#define J1939_TH 500U  /* Configuration for Th timings SAE J1939-21 \
                   limits it to 500ms max */
#define SIGNAL_NA 0xFFU

#define EVCU1_ADDR            0x27U
#define EVCU2_ADDR            0x99U
#define BMS_ADDR              0xF3U
#define AUX1_ADDR             0x80U
#define AUX2_ADDR             0x81U
#define DCDC_ADDR             0x8FU
#define TCP_ADDR              0x90U
#define DNR_ADDR              0x05U
#define BCS_ADDR              0x82U
#define MCU_ADDR              0xEFU
#define IMMOBILIZER_ADDR      0x1DU
#define E_LUBE_PUMP_ADDR      0x2EU
#define EBS_ADDR              0x0BU
#define HVAC_ADDR             0x19U
#define VECU_ADDR             0x21U
#define IC_ADDR               0x17U
#define DMS_ADDR              0x47U
#define BAC_ADDR              0xECU
#define TCU_ADDR              0xFBU

/**
     Structure to handle the timings (J1939-21)
*/
typedef const struct
{
  uint16_t T1_u16; /* Configuration for T1 timings SAE J1939-21 limits it to
                   750ms max */
  uint16_t T2_u16; /* Configuration for T2 timings SAE J1939-21 limits it to
                   1250ms max */
  uint16_t T3_u16; /* Configuration for T3 timings SAE J1939-21 limits it to
                   1250ms max */
  uint16_t T4_u16; /* Configuration for T4 timings SAE J1939-21 limits it to
                   1050ms max */
  uint16_t Tr_u16; /* Configuration for Tr timings SAE J1939-21 limits it to
                   200ms max */
  uint16_t Th_u16; /* Configuration for Th timings SAE J1939-21 limits it to
                   500ms max */
} J1939_tlTimingCfg_St_t;

/**
     Structure to handle the timings (J1939-21)
*/
typedef const struct
{
  uint8_t SA_Inst_u8;
  uint8_t SourceAddress_u8;
}J1939_Instance_St_t;

typedef enum
{
  J1939_81_REQ,
  J1939_73_DM1,
  J1939_73_DM2,
  J1939_73_DM3,
  J1939_73_DM4,
  J1939_73_DM6,
  J1939_73_DMx_SERV_TOTAL_NUM,
} J1939_PGN_En;

typedef enum
{
  J1939_TEST1_PGN,
  J1939_TEST2_PGN,
  J1939_SPECIFIC_TOTAL_NUM,
} J1939_SPECIFIC_PGN_En;

typedef enum
{
  J1939_SA_0x27,
  J1939_SA_0x99,
  J1939_SA_0xF3,
  J1939_SA_0x80,
  J1939_SA_0x81,
  J1939_SA_0x8F,
  J1939_SA_0x90,
  J1939_SA_0x05,
  J1939_SA_0x82,
  J1939_SA_0xEF,
  J1939_SA_0x1D,
  J1939_SA_0x2E,
  J1939_SA_0x0B,
  J1939_SA_0x19,
  J1939_SA_0x21,
  J1939_SA_0x17,
  J1939_SA_0x47,
  J1939_SA_0xEC,
  J1939_SA_0xFB,
  J1939_SA_TOTAL_NUM
} J1939_INST_En;

/**
  Service Dist table (J1939-73)
*/
typedef const struct
{
  uint16_t PGN_u16;                                                                               // Service identifier
  void (*ServiceInit_Fptr_t)(void);                                                               // Call back function to the init function called from service distributor.
  J1939Appl_DMxRetStatus_En_t (*Service_Fptr_t)(CAN_MessageFrame_St_t *, uint8_t SAInstance_u8);  // Call back function to for the DM service
                                                                                                  // Note additional entries can be added to this structure to cater to other diagnostic protocol
  void *data_pv;
} J1939_ServDist_St_t;

typedef J1939Appl_DMxRetStatus_En_t (*Req_Callback_Fptr_t)(CAN_MessageFrame_St_t * Var, uint32_t Index_u32, uint8_t SAInstance_u8);

typedef struct
{
  uint16_t Req_Type_u16;                   /* Type of the Request */
  Req_Callback_Fptr_t Req_Callback_Fptr; /* Request callback function */
  uint8_t *Req_FuncData_pu8;             /* callback function data */
} J1939_SPECIFIC_PGN_St_t;

/*
 ****************************************************************************************
 *    al Variables
 ****************************************************************************************
 */
extern J1939_tlTimingCfg_St_t J1939_tlTiming_St[TOTAL_CH];
extern J1939_tlTimingCfg_St_t *J1939_tlTiming_pSt[TOTAL_CH];
extern const J1939_ServDist_St_t J1939_ServDist_aSt[];
extern const J1939_SPECIFIC_PGN_St_t J1939_SPECIFIC_PGN_St[];
extern bool J1939_ADDRESSCLAIMING_ACTIVE_FLAG_b;
extern const J1939_Instance_St_t J1939_Instance_aSt[J1939_SA_TOTAL_NUM];

/*
 ****************************************************************************************
 *    ENUM Definition
 ****************************************************************************************
 */

/*
 ****************************************************************************************
 *    Structure Definition
 ****************************************************************************************
 */

/*
 ******************************************************************************
 *    Variable declarations
 ******************************************************************************
 */

/*
 ****************************************************************************************
 *    Function Prototypes
 ****************************************************************************************
 */

#endif
