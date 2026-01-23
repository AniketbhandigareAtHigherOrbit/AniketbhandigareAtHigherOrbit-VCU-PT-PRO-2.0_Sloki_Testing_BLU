/***************************************************************************************************
 *    FILENAME    :  fm_conf.h
 *
 *    DESCRIPTION : Contains the configuration data for the fault management
 *                  Level 1 and 2. Application user should configure this
 *                  file prior to the compilation.
 *
 *    $Id         : $
 *
 ***************************************************************************************************
 * Revision history
 *
 * Ver Author       Date       Description
 * 1    Sloki         25/09/2018
 ***************************************************************************************************
 */

#ifndef FM_CONF_H
#define FM_CONF_H

/*
***************************************************************************************************
*    Includes
***************************************************************************************************
*/
// #include "common.h"
#include "fmdtc_conf.h"
#include "diag_sys_conf.h"
#include "diag_typedefs.h"

#define FM_UDS_SUPPORTED (TRUE)

#define FM_OBD_SUPPORTED (FALSE)

#define FM_J1939_SUPPORTED (FALSE)

/*
***************************************************************************************************
*    Type Defines
***************************************************************************************************
*/

/*
***************************************************************************************************
*    Enumerations
***************************************************************************************************
*/

/*
***************************************************************************************************
*    Defines
***************************************************************************************************
*/
/*
" CONFIGURATION TABLE FOR APPLICATION USER "
*/
/* @code tag - @[CODE_FM_NOF_L2ENTRIES]@{SDD_FM_NOF_L2ENTRIES} */
#define FM_CONF_MAX_L2FAULT_ENTRIES 10 // Max number of fault entries in the NV Memory

// #define FM_CONF_OBD_FRZFRM_ENTRIES      			11       // Max number of freeze frame entries for OBD relevant faults
// #define FM_CONF_J1939_FRZFRM_ENTRIES   			    11       // Max number of freeze frame entries for NONOBD relevant faults
/* @code tag - @[CODE_FM_NOF_FRZFRMENTRIES]@{SDD_FM_NOF_FRZFRMENTRIES} */
// #define MAX_FRZFRM_ENTRIES      			10       // Max number of freeze frame entries in the NV Memory
//  This value should be the maximum value of either
//  OBD relevant or NONOBD relevant
// #define NONFM_CONF_OBD_FRZFRM_ENTRIES   			10       // Max number of freeze frame entries for NONOBD relevant faults


//#define MAX_BYTES_MANUF_FRZFRM		    	26
#define GLOBAL_SNAPSHOT_CNT			    	2


#define LATESTFRZFRM_ENABLED 0 // 1: Latest freeze frame is stored, 0: Only first freeze frame.

/* @code tag - @[CODE_FM_SELECT_EUD]@{SDD_FM_SELECT_EUD} */
#define EUD_LDV_98_69_EC 0   // 1: EU Directive 98/69/EC is used for Light Duty Vehicle, 0: otherwise.
#define EUD_HDV_2005_55_EC 0 // 1: EU Directive 2005/55/EC is used for Heavy Duty Vehicle, 0: otherwise.
#if EUD_HDV_2005_55_EC
#define FM_CONF_OBD_DELETING_MIN (200 * 60) // Number of minutes to Delete a Healed fault
#define FM_CONF_OBD_HEALING_MIN (24 * 60)   // Number of minutes to Heal a confimed fault
#endif
#define BIGENDIAN_SYSTEM 0 // 1: For Big endian supported controller, 0: for little endian controllers.

#define DTCSTATUS_AVAL_MASK 0x7F // A byte whose bits  are defined the same as statusOfDTC and represents the status bits that are supported by the server.

#define		DTCSEVERITY_AVAL_MASK				0x0A     // A byte whose bits are defined the same as severity of DTC and represents the status bits that are supported by the server.

#define TOTAL_NONSUPPORTING_FAULTS 4

#define CAPTURE_FRZFRAME_FIRST_CONFIRMED (0u)
#define CAPTURE_FRZFRAME_LATEST_CONFIRMED (!CAPTURE_FRZFRAME_FIRST_CONFIRMED)

#define GET_TIME_SINCE_ENGINE_ON_MIN() 0
#define GET_DIST_SINCE_ENGINE_ON() Dist_Drvn

/**
Error handling at compilation time
**/
#if EUD_LDV_98_69_EC
#if EUD_HDV_2005_55_EC
// #error "FM_CONF.H: Error - Both EU Directives (98/69/EC and 2005/55/EC) are enabled. Enable any one!"
#endif
#else
#if (!EUD_HDV_2005_55_EC)
// #error "FM_CONF.H: Error - Non of the EU directives (98/69/EC and 2005/55/EC) are enabled!"
#endif
#endif

#define FM_SCHEDULER_RATE_MS 50                               //(50ms) = scheduler rate
#define FM_100MS_SCHEDULER_CNT (100 / FM_SCHEDULER_RATE_MS)   //(100ms/50ms) = 2
#define FM_1000MS_SCHEDULER_CNT (1000 / FM_SCHEDULER_RATE_MS) //(1000ms/50ms) = 20
#define FM_1MIN_SCHEDULER_CNT (60000 / FM_SCHEDULER_RATE_MS)  //(60000ms/50ms) = 1200
//(1 min = 60000ms)

/*
The function FM_ReadFrzFrm_ByDTC() returns freezeframe for faults in L2, in addition if
the freezeframe from L2 memory is also required, then the below macro can be set to TRUE.
*/
#define FRZFRM_FROM_FML1 TRUE
/*
**************************************************************************************************
*    Enum definitions
**************************************************************************************************
*/
/********************************************************************************
MACROS
*********************************************************************************/

// #define    FM_GET_FLTTYPE(bitpos)  (1u << (bitpos+3))
#define FM_GET_FLTTYPE(bitpos) (1u << (4 - bitpos))

#define FM_MAX_DTC_ROWS NUM_OF_FAULTPATHS_E
#define FM_MAX_DTC_COLS (MAX_NUM_ERROR_TYPES - 1)

/* convert the fault type (bit encoded value) into index for DTC table
-3 in the below expression is because of fault type info is stored in
status register from bit position 3. In order to remove the offset, we need to
subtract the bit position by 3 */
#define GET_COLINDEX_BY_FLTTYPE(ftype) 0 // TODO Sushil(GET_BIT_POS(ftype) - 3)

// Constants bit positions used for indicating the readiness groups supported.
#define FM_RDY_FUEL_GRP_BP 0
#define FM_RDY_EGR_GRP_BP 1
#define FM_RDY_CCOMP_GRP_BP 2
// Constant bit mask for checking the supported readiness groups
#define FM_RDYGRP_MASK ((1 << FM_RDY_FUEL_GRP_BP) | (1 << FM_RDY_EGR_GRP_BP) | (1 << FM_RDY_CCOMP_GRP_BP))

#define GET_DEBDEFECT_CTR(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].DebounceCtr_St.DefectCtr_u16)
#define GET_DEBHEAL_CTR(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].DebounceCtr_St.HealCtr_u16)
#define GET_DEBREADY_CTR(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].DebounceCtr_St.ReadyCtr_u16)
#define GET_DEBAging_CTR(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].DebounceCtr_St.AgingCtr_u8)

#define GET_POTENTIAL_CTR(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].L2_ConfirmCtr_St.DrvCy_PotentialCnts_u16)
#define GET_HEALING_CTR(FaultPath)  (APPL_FAULTCONF_aSt[FaultPath].L2_ConfirmCtr_St.DrvCy_HealingCnts_u8)
#define GET_DELETING_CTR(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].L2_ConfirmCtr_St.Wucy_DelCnts_u16)

#define GET_FAULT_PRIORITY(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].FaultPriority_En)
#define GET_FAULT_RDYGRP(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].FaultRdyGrp_En)
#define GET_SUPPORTEDFAULT(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].SupportedFaults_u8)

#if ((TRUE == FM_OBD_SUPPORTED) || (TRUE == FM_J1939_SUPPORTED))
#define IS_FAULT_OBD_RELEVANT(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].OBD_Relevant_u8)
#else
#define IS_FAULT_OBD_RELEVANT(FaultPath) (false)
#endif
#define IS_FAULT_GPL_INDICATABLE(FaultPath) (APPL_FAULTCONF_aSt[FaultPath].GPL_Indicatable_u8)

#define GET_FUNCTIONAL_UNIT(FaultPath)        (APPL_FAULTCONF_aSt[FaultPath].FM_FunctionalUnit_En)
#define GET_FAULT_PATH_DTC_MAPTBL(FltIndx)    (DTCMappingTable_UDS_aSt[FltIndx].FaultPath_En)
//#define GET_FAULT_TYPE_DTC_MAPTBL(FltIndx)    (DTCMappingTable_UDS_aSt[FltIndx].ErrorType_u8)
//#define GET_DTC_VALUE_DTC_MAPTBL(fpath,ftype)   (DTCMappingTable_UDS_aSt[ fpath ][ ftype ])
// NONOBD specific
// Note:The number of potential counts, healing counts and deleting counts
// should not be configured with less than one
/* @code tag - @[CODE_FM_FMCONFITEMS]@{SDD_FM_FMCONFITEMS} */
#define FM_CONF_NOF_NONOBD_POTENTIALCNTS(FaultPath)    GET_POTENTIAL_CTR(FaultPath)         // Number of Operating sequence to confirm a potential fault
#define FM_CONF_NOF_NONOBD_HEALINGCNTS(FaultPath)  GET_HEALING_CTR(FaultPath)               /*GET_DEBAging_CTR(FautlPath)*/                // Number of Driving cycles to Heal a confimed fault
#define FM_CONF_NOF_NONOBD_DELETECNTS(FaultPath) GET_DELETING_CTR(FaultPath)                // Number of WUP cycles to Delete a Healed fault
/*
    EU Regulation counts
*/
#define FM_CONF_NOF_OBD_POTENTIALCNTS 2 // Number of Operating sequence to confirm a potential fault
#define FM_CONF_NOF_OBD_HEALINGCNTS 3   // Number of Driving cycles to Heal a confimed fault
#define FM_CONF_NOF_OBD_DELETECNTS 40   // Number of WUP cycles to Delete a Healed fault


#define  NO_ERROR             0u
#define  MAX_ERROR            1u
#define  MIN_ERROR            2u
#define  SIG_ERROR            3u
#define  NPL_ERROR            4u
#define  FER_ERROR            5u
#define  MAX_NUM_ERROR_TYPES  6u
/*
***************************************************************************************************
*    Export variables
***************************************************************************************************
*/

typedef enum
{
  FM_L2_ENTRY1,
  FM_L2_ENTRY2,
  FM_L2_ENTRY3,
  FM_L2_ENTRY4,
  FM_L2_ENTRY5,
  FM_L2_ENTRY6,
  FM_L2_ENTRY7,
  FM_L2_ENTRY8,
  FM_L2_ENTRY9,
  FM_L2_ENTRY10,
  FM_COMMON_DATA,
  FM_RDYRESULTS,
  FM_TFSLC,
  TOTAL_FM_SIGNAL_E
} FM_FEE_EntryName_En_t;

typedef enum
{
  FM_NO_PROTO_E = 0,
  FM_PROTO_UDS_E,
  FM_PROTO_OBD_E,
  FM_PROTO_J1939_E,
  FM_PROTO_TOTAL_SUPPORTED
} FM_ProtocolType_En_t;

typedef enum
{
  FM_PRIO_0_E = 0,
  FM_PRIO_1_E,
  FM_PRIO_2_E,
  FM_PRIO_3_E,
  FM_PRIO_4_E,
  NUM_OF_FM_PRIORITIES_E
} FM_FaultPriority_En_t;

typedef enum
{
  RDY_NO_RDY_GRP = 0, // Readiness flag not required for some faults
  RDY_FUEL_GRP,       // Readiness flag for Fuel system related faults
  RDY_EGR_GRP,        // Readiness flag for EGR system related faults
  RDY_CCOMP_GRP,      // Readiness flag for Comprehensive Component system related faults
  NUM_OF_RDY_GRP
} FM_RdyType_En_t;

typedef enum
{
  FM_FUN_NW_E = 0,
  FM_FUN_BODY_E,
  FM_ANY_E = 0xFFFFFF,
} FM_FunctionalUnit_En_t;


// Constants used for the error code registration.
/* @code tag - @[CODE_FM_FLTTYPES]@{SDD_FM_FLTTYPES} */
#define FM_NO_ERR (NO_ERROR)
#define FM_MAX_ERR (1u << (MAX_ERROR + 2u)) // 0000 1000
#define FM_MIN_ERR (1u << (MIN_ERROR + 2u)) // 0001 0000
#define FM_SIG_ERR (1u << (SIG_ERROR + 2u)) // 0010 0000
#define FM_NPL_ERR (1u << (NPL_ERROR + 2u)) // 0100 0000
#define FM_FER_ERR (1u << (FER_ERROR + 2u)) // 1000 0000

#define FM_ALL_ERR (FM_MAX_ERR | FM_MIN_ERR | FM_SIG_ERR | FM_NPL_ERR | FM_FER_ERR)
/*
" CONFIGURATION TABLE FOR APPLICATION USER "
Application user will make entries here.
Number of entries correspond to the number of components that can be diagnosed in the system.
@code tag - @[CODE_DERIVED_FM_FLTPATH_CONF]@{SDD_DERIVED_FM_FLTPATH_CONF}
*/
typedef enum
{
  FM_FAULT_START_E=0,
  FP_COMMUNICATION_ERR_E  =FM_FAULT_START_E,
  NUM_OF_FAULTPATHS_E,
  FM_FP_INVALID_E
} FM_FaultPath_En_t;

typedef struct
{
  uint16_t DefectCtr_u16;
  int16_t HealCtr_u16;
  int16_t ReadyCtr_u16;
  uint8_t AgingCtr_u8;
} FM_DebounceCtr_St_t;

typedef struct
{
  uint16_t DrvCy_PotentialCnts_u16;
  uint8_t DrvCy_HealingCnts_u8;
  uint16_t Wucy_DelCnts_u16;
}FM_L2_CnfrmCtr_St_t;


#pragma pack(1)
typedef struct
{
  FM_FaultPath_En_t FaultPath_En;              // Application specific Fault Paths for FM.  (2)
  FM_DebounceCtr_St_t DebounceCtr_St;          // L1 debounce counter structure. (7)
  FM_L2_CnfrmCtr_St_t L2_ConfirmCtr_St;        // L2 debounce counter structure.
  FM_FaultPriority_En_t FaultPriority_En;      // Priority of the Fault. (2)
  FM_RdyType_En_t FaultRdyGrp_En;              // Readiness monitoring group for the faults[RDY_FUEL_GRP, RDY_EGR_GRP, RDY_CCOMP_GRP]. (2)
  FM_FunctionalUnit_En_t FM_FunctionalUnit_En; // 1-byte value which identifies the corresponding basic vehicle / system function which reportsthe DTC. (2)
  uint8_t SupportedFaults_u8;                  // Supported error types E.g [FM_MAX_ERR | FM_MIN_ERR].(Not used) (1)
#if ((TRUE == FM_OBD_SUPPORTED) || (TRUE == FM_J1939_SUPPORTED))
  uint8_t OBD_Relevant_u8; // Is Fault OBD Specific? otherwise NONOBD specific (non-OBD).  (1)
#endif
  uint8_t GPL_Indicatable_u8; // If non OBD specific, Is fault Glow Plug Lamp indicatable.    (1)
} FM_APPL_FLTCONF_St_t;       // (25 bytes)

extern const FM_APPL_FLTCONF_St_t APPL_FAULTCONF_aSt[NUM_OF_FAULTPATHS_E];
extern const uint16_t DTCMappingTable_size_u16;
extern const uint32_t FM_DTC_Status_St[NUM_OF_FAULTPATHS_E];

extern uint16_t RPM_N_u16 ;
extern uint16_t Dist_Drvn;        //in Km
 
#endif
