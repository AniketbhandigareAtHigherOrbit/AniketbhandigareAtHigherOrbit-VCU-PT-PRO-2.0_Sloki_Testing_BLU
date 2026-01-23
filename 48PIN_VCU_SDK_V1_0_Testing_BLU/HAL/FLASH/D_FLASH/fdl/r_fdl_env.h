#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * Library       : Data Flash Access Library for Renesas RH850 devices
 *
 * File Name     : $Source: r_fdl_env.h $
 * Lib. Version  : $RH850_FDL_LIB_VERSION_T01: V2.13 $
 * Mod. Revision : $Revision: 1.24 $
 * Mod. Date     : $Date: 2019/04/19 19:07:15JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Flash programming hardware related definitions
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

#ifndef R_FDL_ENV_H
#define R_FDL_ENV_H


/*********************************************************************************************************************
 * Global constants (define, const, ...)
 *********************************************************************************************************************/
/* ---------------- FCU definitions ---------------------------------------- */
#ifdef R_FDL_CPE_SUPPORT
    #include "r_fdl_env_cpe.h"
#else
    #define R_FCU_BASE                  (0xFFA10000u)
    #define R_FCU_RAM_ADD               (0xFFA12000u)
    #define R_FCU_DFLASH_CMD_ADD        (0xFFA20000u)
    #define R_BWCBUF_G3K_ADD            (0xFFBC0700u)
    #define R_BWCBUF_G3KH_ADD           (0xFFC5B000u)
#endif

#define R_FCU_REGADD_FASTAT_U08         (R_FCU_BASE + 0x010u)
#define R_FCU_REGBIT_FASTAT_CMDLK       (0x10u)
    
#define R_FCU_REGADD_FAEINT_U08         (R_FCU_BASE + 0x014u)
#define R_FCU_REGVAL_FAEINT_DISABLE     (0x88u)
#define R_FCU_REGVAL_FAEINT_ENABLE      (0x99u)
    
#define R_FCU_REGADD_FMATSELC_U16       (R_FCU_BASE + 0x020u)
#define R_FCU_REGBIT_FMATSELC_KEY       (0x3B00u)
#define R_FCU_REGBIT_FMATSELC_EX3S      (0x0004u)               /* Select EXA3 */
#define R_FCU_REGBIT_FMATSELC_RESET     (0x0000u)
    
#define R_FCU_REGADD_FSADR_U32          (R_FCU_BASE + 0x030u)
#define R_FCU_REGADD_FEADR_U32          (R_FCU_BASE + 0x034u)
    
#define R_FCU_REGADD_FCURAME_U16        (R_FCU_BASE + 0x054u)
#define R_FCU_REGBIT_FCURAME_KEY        (0xC400u)
#define R_FCU_REGBIT_FCURAME_FCRME      (0x0001u)               /* 1: on, 0: off */
#define R_FCU_REGBIT_FCURAME_FRAMTRAN   (0x0002u)               /* 0: RW, 1: High speed */
#define R_FCU_REGBIT_FCURAME_RESET      (0x0000u)
    
#define R_FCU_REGADD_FSTATR_U32         (R_FCU_BASE + 0x080u)
#define R_FCU_REGBIT_FSTATR_FRCRCT      (0x00000001u)
#define R_FCU_REGBIT_FSTATR_FRDTCT      (0x00000002u)
#define R_FCU_REGBIT_FSTATR_TBLDTCT     (0x00000008u)
#define R_FCU_REGBIT_FSTATR_CFGDTCT     (0x00000020u)
#define R_FCU_REGBIT_FSTATR_FHVEERR     (0x00000040u)
#define R_FCU_REGBIT_FSTATR_FCUERR      (0x00000080u)
#define R_FCU_REGBIT_FSTATR_PRGSPD      (0x00000100u)
#define R_FCU_REGBIT_FSTATR_ERSSPD      (0x00000200u)
#define R_FCU_REGBIT_FSTATR_DBFULL      (0x00000400u)
#define R_FCU_REGBIT_FSTATR_SUSRDY      (0x00000800u)
#define R_FCU_REGBIT_FSTATR_PRGERR      (0x00001000u)
#define R_FCU_REGBIT_FSTATR_ERSERR      (0x00002000u)
#define R_FCU_REGBIT_FSTATR_ILGERR      (0x00004000u)
#define R_FCU_REGBIT_FSTATR_FRDY        (0x00008000u)
#define R_FCU_REGBIT_FSTATR_OTPDTCT     (0x00020000u)
#define R_FCU_REGBIT_FSTATR_RESET       (0x00000000u)
    
#define R_FCU_REGADD_FENTRYR_U16        (R_FCU_BASE + 0x084u)
#define R_FCU_REGBIT_FENTRY_FENTRYD     (0x0080u)
#define R_FCU_REGBIT_FENTRY_FENTRYC     (0x0001u)
#define R_FCU_REGBIT_FENTRY_KEY         (0xAA00u)
#define R_FCU_REGBIT_FENTRY_OFF         (0x0000u)
#define R_FCU_REGBIT_FENTRY_KEYMASK     (0x00FFu)
#define R_FCU_MODE_PE                   (R_FCU_REGBIT_FENTRY_FENTRYD)
#define R_FCU_MODE_CPE                  (R_FCU_REGBIT_FENTRY_FENTRYC)
#define R_FCU_MODE_USER                 (R_FCU_REGBIT_FENTRY_OFF)
    
#define R_FCU_REGADD_FBCSTAT_U08        (R_FCU_BASE + 0x0D4u)
#define R_FCU_REGBIT_FBCSTAT_BCST       (0x01u)
    
#define R_FCU_REGADD_FPSADDR_U32        (R_FCU_BASE + 0x0D8u)
    
#define R_FCU_REGADD_PCKAR_U16          (R_FCU_BASE + 0x0E4u)
#define R_FCU_REGBIT_PCKAR_KEY          (0x1E00u)
    
#define R_DECC_BASE_E1X                 (0xFFC62C00u)
#define R_DECC_BASE_F1X                 (0xFFC66000u)
#define R_DECC_BASE                     (g_fdl_str.baseAddrECC_u32)
    
#define R_FCU_REGADD_DFERSTR_U32        (R_DECC_BASE + 0x004u)
#define R_FCU_REGBIT_DFERSTR_SEDF       (0x00000001u)
#define R_FCU_REGBIT_DFERSTR_DEDF       (0x00000002u)
#define R_FCU_REGVAL_DFERSTR_NOERR      (0x00000000u)
    
#define R_FCU_REGADD_DFERSTC_U08        (R_DECC_BASE + 0x008u)
#define R_FCU_REGBIT_DFERSTC_ERRCLR     (0x01u)
    
#define R_FCU_REGADD_DFERINT_U08        (R_DECC_BASE + 0x014u)
#define R_FCU_REGVAL_DFERINT_NOINT      (0x00u)


/* The BFA defines are just dummy defines in order to remember that the values are required.
   The values are used in in-line assembly code and cannot be derived from this header file */
#define R_CCIB_BASE                     (0xFFC59000u)
    
#define R_FCU_REGADD_BFASELR_U08        (R_CCIB_BASE + 0x008u)
#define R_FCU_REGBIT_BFASELR_BFASEL     (0x01u)
#define R_FCU_REGBIT_BFASELR_RESET      (0x00u)


/* ---------------- Other Data Flash related defines ----------------------- */
#define R_FCU_RAM_SIZE                  (0x00001000u)

#ifdef R_FDL_INNER_NO_BFA_SWITCH
    #define R_FCU_RAM_BASE_ADD               (0x01037000u)
    #define R_FCU_FWPARAM_BASE_ADD           (0x01030000u)
#else
    #define R_FCU_RAM_BASE_ADD               (0x00017000u)
    #define R_FCU_FWPARAM_BASE_ADD           (0x00010000u)
#endif
#define R_FCU_RAM_SRC_ADD               (R_FCU_RAM_BASE_ADD)
#define R_FCU_RAM_ADD_CHKSUM_END        (R_FCU_RAM_BASE_ADD + 0x00000FF8u)
#define R_FCU_RAM_ADD_CHKSUM            (R_FCU_RAM_BASE_ADD + 0x00000FFCu)
#define R_EXTRA3_FWVER                  (R_FCU_FWPARAM_BASE_ADD + 0x00000219u)
#define R_EXTRA3_FMAX                   (R_FCU_FWPARAM_BASE_ADD + 0x00000234u)
#define R_EXTRA3_FMIN                   (R_FCU_FWPARAM_BASE_ADD + 0x00000238u)
#define R_EXTRA3_FDIV_FWVER_03          (R_FCU_FWPARAM_BASE_ADD + 0x00000264u)
#define R_EXTRA3_FPCLK_FWVER_03         (R_FCU_FWPARAM_BASE_ADD + 0x00000274u)
#define R_EXTRA3_FDIV_FWVER_04          (R_FCU_FWPARAM_BASE_ADD + 0x00000265u)
#define R_EXTRA3_FPCLK_FWVER_04         (R_FCU_FWPARAM_BASE_ADD + 0x00000278u)
#define R_EXTRA3_SCDSADD                (R_FCU_FWPARAM_BASE_ADD + 0x00000270u)
#define R_EXTRA3_ECCADDR                (R_FCU_FWPARAM_BASE_ADD + 0x00000288u)
        
#define R_FCU_FWVER_03                  (0x03u)
#define R_FCU_FWVER_04                  (0x04u)
        
#define R_PRDSEL3_OFFSET                (0xC8u)
#define R_PRDNAME2_OFFSET               (0xD4u)
#define R_PRDNAME_010x                  (0x00303130u)

#define R_FCU_DFLASH_READ_ADD           (0xFF200000u)

#define R_FCU_CMD_ERASE                 (0x20u)                 /* FCU erase command */
#define R_FCU_CMD_CLEARSTAT             (0x50u)                 /* FCU clear status reg. command */
#define R_FCU_CMD_BLANKCHECK            (0x71u)                 /* FCU BC command */
#define R_FCU_CMD_SUSPEND               (0xB0u)                 /* FCU suspend command */
#define R_FCU_CMD_FORCED_STOP           (0xB3u)                 /* Stop and reset FCU */
#define R_FCU_CMD_WRITE                 (0xE8u)                 /* FCU write command */
#define R_FCU_CMD_EXE                   (0xD0u)                 /* FCU start execution */

#define R_FCU_DATA_TRANSFERSIZE         (0x02u)
        
#define R_FCU_FMIN                      (0x0004u)
#define R_FCU_FMAX                      (0x0064u)
        
#define R_BLOCK_SIZE                    (0x0040u)               /* EEP Flash block size in bytes */
#define R_BLOCK_SIZE_2N                 (0x0006u)               /* EEP block size as 2^N Bytes */
#define R_WRITE_SIZE                    (0x00000004u)          /* Normal write granularity */
#define R_MACROSIZE_MIN                 (0x00001000u)          /* Minimum Flash macro size */

#define R_PID_CORE_MASK                 (0x000000E0u)
#define R_PID_CORE_G3K                  (0x00000020u)
#define R_PID_CORE_G3KH                 (0x000000a0u)

/* ---------------------------- Other defines ------------------------------ */
#define R_U32_ALIGNED                   (0x03u)

/*********************************************************************************************************************/
#endif /* ifndef R_FDL_ENV_H */

