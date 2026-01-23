#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * Library       : Data Flash Access Library for Renesas RH850 devices
 *
 * File Name     : $Source: r_fdl_global.h $
 * Lib. Version  : $RH850_FDL_LIB_VERSION_T01: V2.13 $
 * Mod. Revision : $Revision: 1.47 $
 * Mod. Date     : $Date: 2019/04/19 19:07:12JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : FDL internal definitions and global functions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only  intended for use with Renesas products.
 * No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
 * TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS
 * AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
 * REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * www.renesas.com/disclaimer
 *
 * Copyright (C) 2015-2019 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_ON 0292
#endif

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 0292)
 * Reason:       To support automatic insertion of revision, module name etc. by the source revision control system
 *               it is necessary to violate the rule, because the system uses non basic characters as placeholders.
 * Verification: The placeholders are used in commentaries only. Therefore rule violation cannot influence code
 *               compilation.
 *********************************************************************************************************************/

#ifndef R_FDL_GLOBAL_H
#define R_FDL_GLOBAL_H


/*********************************************************************************************************************
 * Include list
 *********************************************************************************************************************/
#include "r_typedefs.h"
#include "app_typedef.h"
#include "r_fdl.h"
#include "r_fdl_env.h"

/*********************************************************************************************************************
 * Global constants (define, const, ...)
 *********************************************************************************************************************/
/* -------------------- Library version string ----------------------------- */
#define R_FDL_VERSION_STRING                    "DH850T01xxxxxxV213"

/* -------------------- Misc constants ------------------------------------- */
/* Reset value of request pointers */
#define R_FDL_REQUEST_POINTER_UNDEFINED         (r_fdl_request_t *)(0x00000000u)
#define R_FDL_DESCRIPTOR_POINTER_UNDEFINED      (r_fdl_descriptor_t *)(0x00000000u)
#define R_FDL_NULL                              (0x00000000u)


/* -------------------- Size of RAM buffer for Code exececution ------------ */
/* Estimation of stack variable size:
   - Code size R_FDL_FCUFct_InitRAM_Asm: 166 Bytes (GHS/REC/IAR)
   - Code 1st address must be 16Byte aligned (fetch size): +16Bytes
   - Code last address must be 16Byte aligned (fetch size)
   - Prefetch: 4*16Byte
   --> 176Bytes (166Bytes aligned to 16Bytes) + 16Bytes + 64Bytes
       = 256Bytes = 128half words (=instruction alignment)
   - Code size R_FDL_IFct_GetFWParam_Asm: always less than R_FDL_FCUFct_InitRAM_Asm
*/
#define R_FDL_RAM_CODE_SIZE_HW                  (128)

/* ----- Unique timeout value is 40us ----- */
/* Clear cache register check loop timeout */
/* clocks per timeout loop */
#define R_FDL_TIMEOUT_CC_CLK_P_LOOP             (3u)
/* timeout loop_count: (40us * f_MHz) / (clk per loop)   ---  but rounding up to be considered */
#define R_FDL_TIMEOUT_CC                        (   ( (40u * (uint32_t)(g_fdl_str.RTCfg_pstr->cpuFrequencyMHz_u16)) \
                                                  + (R_FDL_TIMEOUT_CC_CLK_P_LOOP - 1u) ) / R_FDL_TIMEOUT_CC_CLK_P_LOOP )

/* IO register check loop timeout */
/* clocks per timeout loop */
#define R_FDL_TIMEOUT_CHKREG_CLK_P_LOOP         (19u)
/* timeout loop_count: (40us * f_MHz) / (clk per loop)   ---  but rounding up to be considered */
#define R_FDL_TIMEOUT_CHKREG                    (   ( (40u * (uint32_t)(g_fdl_str.RTCfg_pstr->cpuFrequencyMHz_u16)) \
                                                  + (R_FDL_TIMEOUT_CHKREG_CLK_P_LOOP - 1u) ) / R_FDL_TIMEOUT_CHKREG_CLK_P_LOOP )

/*********************************************************************************************************************
 * Global type definitions
 *********************************************************************************************************************/
/**
   \enum r_fdl_flag_t
   standard FDL internal flag definition
*/
typedef enum R_FDL_FLAG_T
{
    R_FDL_FALSE,                                    /**< Flag false */
    R_FDL_TRUE                                      /**< Flag true */
} r_fdl_flag_t;

/**
   \enum r_fdl_int_status_t
   definition of the FDL operational status
*/
typedef enum R_FDL_INT_STATUS_T
{
    R_FDL_ISTAT_NOINIT          = 0x00000000uL,     /**< Pattern for uninitialized library (0x00000000) */
    R_FDL_ISTAT_INIT            = 0x55555554uL,     /**< Pattern for initialized library after R_FDL_Init */
    R_FDL_ISTAT_NORMALOP        = 0x55555555uL,     /**< Pattern for prepared library after
                                                         R_FDL_CMD_PREPARE_ENV execution */
    R_FDL_ISTAT_SUSPEND_PR      = 0x55555556uL,     /**< Pattern for library in suspend processing */
    R_FDL_ISTAT_SUSPENDED       = 0x55555557uL      /**< Pattern for library in suspend status */
} r_fdl_int_status_t;

/**
   \typedef r_fdl_pFct_ExeInRAM
   pointer to a function. Is used in e.g. R_FDL_FCUFct_InitRAM_...
*/
typedef void (* r_fdl_pFct_ExeInRAM)(uint32_t * param_pu32);

/**
   \enum r_fdl_op_status_t
   definition of the internal operation status required for switch mode handling
*/
typedef enum R_FDL_OP_STATUS_T
{
    R_FDL_OP_IDLE                 = 0,              /**< No on-going operation */
    R_FDL_OP_EXECUTE_SYNC_ON      = 1,              /**< Operation ready to start, switch mode
                                                         to P/E requested */
    R_FDL_OP_PREPARE_START        = 2,              /**< Prepare environment operation ready to start,
                                                         switch mode to P/E requested */
    R_FDL_OP_PREPARE_RST_FCU      = 3,              /**< Prepare environment operation started,
                                                         switch mode to P/E requested */
    R_FDL_OP_PREPARE_END          = 4,              /**< Prepare environment operation on-going, FCU reset performed,
                                                         switch mode to read requested */
    R_FDL_OP_RESUME_SYNC_ON       = 5,              /**< Resume request accepted, switch mode
                                                         to P/E requested */
    R_FDL_OP_RESUME_MULTI_SYNC_ON = 6,              /**< Resume request accepted to restart a multiple operation,
                                                         switch mode to P/E requested */
    R_FDL_OP_BUSY                 = 7,              /**< On-going operation */
    R_FDL_OP_SUSPEND_SYNC_OFF     = 8,              /**< Suspend processing finished, switch mode to read requested */
    R_FDL_OP_END_SYNC_OFF         = 9               /**< Operation finished, switch mode to read requested */
} r_fdl_op_status_t;

/**
   @enum r_fdl_sbwu_status_t
   definition of the internal stand-by/wake-up processing status
*/
typedef enum R_FDL_SBWU_STATUS_T
{
    R_FDL_SBWU_INIT                    = 1,         /**< Pattern for initialized library */
    R_FDL_SBWU_STANDBY_PR_SUSPEND      = 2,         /**< Pattern for waiting for suspend completion */
    R_FDL_SBWU_STANDBY_PR_SW_USER      = 3,         /**< Pattern for library in standby processing switch user mode */
    R_FDL_SBWU_STANDBY_PR_SYNC_USER    = 4,         /**< Pattern for library in standby processing sync user mode switch */
    R_FDL_SBWU_STANDBY                 = 5,         /**< Pattern for library in standby */
    R_FDL_SBWU_WAKEUP_PR_SYNC_PE       = 6          /**< Pattern for library in wakeup processing sync PE mode */
} r_fdl_sbwu_status_t;


/**
   \struct r_fdl_multiOp_t
   structure containing the data required for multi operations (erase multiple blocks, write multiple half words data)
*/
typedef struct R_FDL_MULTIOP_T
{
    uint32_t            flashAdd_u32;               /**< source data pointer */
    uint32_t            bufAdd_u32;                 /**< destination data pointer */
    uint32_t            flashAddEnd_u32;            /**< last source address to write */
    r_fdl_accessType_t  accessType_enu;             /**< access type */
} r_fdl_multiOp_t;

/**
   \struct r_fdl_data_t
   this structure contains all FDL internal data
*/
typedef struct R_FDL_DATA_T
{
    const r_fdl_descriptor_t *  RTCfg_pstr;         /**< pointer to descriptor structure, initialized by
                                                         R_FDL_ISTAT_INIT */
    r_fdl_multiOp_t     mulOp_str;                  /**< multi operation (erase/write) variables. Set when a multi
                                                         operation is started, checked/updated when a single
                                                         erase/write is finished */
    r_fdl_multiOp_t     spdMulOp_str;               /**< multi operation variables backup for FDL suspend */
    r_fdl_request_t *   reqSuspend_pstr;            /**< request structure pointer backup buffer for suspend/resume */
    r_fdl_request_t *   reqInt_pstr;                /**< request structure pointer for current operation */
    r_fdl_op_status_t   opStatus_enu;               /**< Operation status required for switch mode handling */
    uint32_t            opFailAddr_u32;             /**< fail address of the blank check operation */
    uint32_t            dfSize_u32;                 /**< Data Flash size, required for boundary checks */
    uint32_t            baseAddrECC_u32;            /**< ECC base address determined on firmware
                                                         parameter version */
    uint32_t            chksumEndAddr_u32;          /**< Checksum end address */
    uint32_t            chksumVal_u32;              /**< Checksum value */
    uint16_t            flashMode_u16;              /**< Current Flash operating mode: P/E or Read */
    r_fdl_status_t      spdResStatus_enu;           /**< result backup buffer for suspend/resume */
    r_fdl_status_t      opResult_enu;               /**< result backup buffer for switch mode handling */
    r_fdl_flag_t        cancelRequest_enu;          /**< cancel request indication to the handler */
    r_fdl_flag_t        spdSpdRequest_enu;          /**< suspend request indication to the handler */
    r_fdl_flag_t        spdResRequest_enu;          /**< resume request indication to the handler */
    r_fdl_int_status_t  iStat_enu;                  /**< FDL operational status variable */
    r_fdl_sbwu_status_t sbWuStat_enu;               /**< FDL stand-by / wake-up status */
    r_fdl_flag_t        sbWuSuspended_enu;          /**< Indication if FACI suspend command was sent */
} r_fdl_data_t;


/*********************************************************************************************************************
 * Global macros
 *********************************************************************************************************************/
/* Static functions definition */
#ifndef R_FDL_STATIC
    #define R_FDL_STATIC static
#endif

#ifndef FDL_CRITICAL_SECTION_STANDBY_BEGIN
    #define FDL_CRITICAL_SECTION_STANDBY_BEGIN      /* Macro for Critical Section of StandBy-WakeUp */
#endif
#ifndef FDL_CRITICAL_SECTION_STANDBY_END
    #define FDL_CRITICAL_SECTION_STANDBY_END        /* Macro for Critical Section of StandBy-WakeUp */
#endif


/*********************************************************************************************************************
 * Global function prototypes
 *********************************************************************************************************************/
r_fdl_status_t  R_FDL_FCUFct_CheckFatalError       (void);
r_fdl_flag_t    R_FDL_FCUFct_ChkReady_TS           (void);
r_fdl_flag_t    R_FDL_FCUFct_ChkSuspendable_TS     (void);
r_fdl_flag_t    R_FDL_FCUFct_ChkStartable          (r_fdl_command_t     cmd_enu);
void            R_FDL_FCUFct_ClearStatus           (void);
r_fdl_status_t  R_FDL_FCUFct_GetStat               (void);
r_fdl_status_t  R_FDL_FCUFct_InitRAM               (void);
r_fdl_status_t  R_FDL_FCUFct_ReadOperation         (volatile uint32_t * pAddSrc_u32,
                                                    uint32_t            addDest_u32,
                                                    uint32_t            cnt_u32);
r_fdl_flag_t    R_FDL_FCUFct_ResumeChkNeed_TS      (void);
void            R_FDL_FCUFct_Resume_TS             (void);
r_fdl_status_t  R_FDL_FCUFct_SetFrequency          (void);
r_fdl_status_t  R_FDL_FCUFct_GetDFSize             (uint32_t            *size);
r_fdl_status_t  R_FDL_FCUFct_StartBCEraseOperation (uint32_t            addStart_u32,
                                                    uint32_t            addEnd_u32,
                                                    uint8_t             fcuCmd_u08,
                                                    r_fdl_accessType_t  accType_enu);
r_fdl_status_t  R_FDL_FCUFct_StartWriteOperation   (uint32_t            addSrc_u32,
                                                    uint32_t            addDest_u32,
                                                    uint32_t            cnt_u32,
                                                    r_fdl_accessType_t  accType_enu);
void            R_FDL_FCUFct_Suspend_TS            (void);
r_fdl_status_t  R_FDL_FCUFct_SwitchMode_Start      (uint16_t            mode_u16);
r_fdl_status_t  R_FDL_FCUFct_SwitchMode_Check_TS   (uint16_t faciMode);
r_fdl_status_t  R_FDL_IFct_ChkAccessBoundaries     (uint32_t            addrStart_u32,
                                                    uint32_t            bCnt_u32,
                                                    r_fdl_accessType_t  accType_enu,
                                                    uint32_t            granularity_u32);
void            R_FDL_IFct_WriteMemoryU08_TS       (uint32_t            addr_u32,
                                                    uint8_t             val_u08);
void            R_FDL_IFct_CalcFOpUnitCnt_BC       (uint32_t *          cnt_pu32,
                                                    uint32_t            addr_u32);
r_fdl_status_t  R_FDL_FCUFct_ForcedStop            (void);
void            R_FDL_FCUFct_Switch_FAEINT         (r_fdl_flag_t        on_t);
r_fdl_status_t  R_FDL_FCUFct_VerifyChecksum        (void);
r_fdl_status_t  R_FDL_FCUFct_StandBy_Processing    (void);
r_fdl_status_t  R_FDL_FCUFct_WakeUp_Processing     (void);


/*********************************************************************************************************************
 * Global data declarations
 *********************************************************************************************************************/
#define R_FDL_START_SEC_VAR
#include "r_fdl_mem_map.h"

#if R_FDL_COMPILER == R_FDL_COMP_GHS
    #define R_FDL_NOINIT
#elif R_FDL_COMPILER == R_FDL_COMP_IAR
    #define R_FDL_NOINIT __no_init
#elif R_FDL_COMPILER == R_FDL_COMP_REC
    #define R_FDL_NOINIT
#endif

extern R_FDL_NOINIT r_fdl_data_t   g_fdl_str;         /**< fdl global variable structure */

#define R_FDL_STOP_SEC_VAR
#include "r_fdl_mem_map.h"

#ifndef R_FDL_EXE_INIT_CODE_ON_STACK
    #define R_FDL_START_SEC_CODERAM
    #include "r_fdl_mem_map.h"

    /* Code size calculation described in r_fdl_global.h */
    extern R_FDL_NOINIT uint16_t g_fdl_ramCodeBuf_au16[R_FDL_RAM_CODE_SIZE_HW];

    #define R_FDL_STOP_SEC_CODERAM
    #include "r_fdl_mem_map.h"
#endif
    

    
/*********************************************************************************************************************/


/*********************************************************************************************************************
 * Add test defines and typedefs
 *********************************************************************************************************************/
#ifdef PATCH_TO_SIMULATE_ERRORS
    #include "FDL-tc_common.h"
#endif

    /* specific defines for coverage measurement */
    #ifdef _BullseyeCoverage
        #define R_FDL_COV_SAVEOFF _Pragma ("BullseyeCoverage save off")
        #define R_FDL_COV_RESTORE _Pragma ("BullseyeCoverage restore")
    #else
        #define R_FDL_COV_SAVEOFF
        #define R_FDL_COV_RESTORE
    #endif
/*********************************************************************************************************************/
#endif /* ifndef R_FDL_GLOBAL_H */

