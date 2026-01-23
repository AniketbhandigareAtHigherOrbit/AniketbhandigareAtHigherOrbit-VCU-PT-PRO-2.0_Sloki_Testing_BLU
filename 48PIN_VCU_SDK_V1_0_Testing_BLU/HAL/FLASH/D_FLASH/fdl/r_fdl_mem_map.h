#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * Library       : Data Flash Access Library for Renesas RH850 devices
*
 * File Name     : $Source: r_fdl_mem_map.h $
 * Lib. Version  : $RH850_FDL_LIB_VERSION_T01: V2.11 $
 * Mod. Revision : $Revision: 1.11 $
 * Mod. Date     : $Date: 2016/06/01 12:39:18JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : FDL section mapping definitions
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
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2015-2016 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_ON 0292
#endif

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 0292)
 * Reason:       To support automatic insertion of revision, module name etc. by the source revision control system
 *               it is necessary to violate the rule, because the system uses non basic characters as placeholders.
 * Verification: The placeholders are used in commentars only. Therefore rule violation cannot influency code
 *               compilation.
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 19.6 (QAC message 0841), 19.15 (QAC message 0883)
 * Reason:       The section mapping concept (Mapping code, constants and data to specific linker sections) bases on 
 *               a central include file containing all section mapping  defines and pragmas. This need to be included 
 *               multiple times within the code. The file itself only contains those defines, pragmas and checks
 *               including #undef to ensure correct file usage
 * Verification: This is the standard concept defined for AUTOSAR implementations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Global compiler definitions
 *********************************************************************************************************************/
#ifdef AUTOSAR_IMPLEMENTATION
    #if defined R_FDL_START_SEC_PUBLIC_CODE
        #define FDL_START_SEC_PUBLIC_CODE                                                       /* PRQA S 0883 */
    #elif defined R_FDL_STOP_SEC_PUBLIC_CODE
        #define FDL_STOP_SEC_PUBLIC_CODE
    #elif defined R_FDL_START_SEC_CONST
        #define FDL_START_SEC_CONST_UNSPECIFIED
    #elif defined R_FDL_STOP_SEC_CONST
        #define FDL_STOP_SEC_CONST_UNSPECIFIED
    #elif defined R_FDL_START_SEC_VAR
        #define FDL_START_SEC_VAR_UNSPECIFIED
    #elif defined R_FDL_STOP_SEC_VAR
        #define FDL_STOP_SEC_VAR_UNSPECIFIED
    #else
      #error "r_fdl_mem_map.h: No valid section define found"
    #endif
    
    #include "MemMap.h"
#else

    #if defined R_FDL_START_SEC_PUBLIC_CODE
        #undef R_FDL_START_SEC_PUBLIC_CODE                                                          /* PRQA S 0841 */
        #if   R_FDL_COMPILER == R_FDL_COMP_GHS
            #pragma ghs section text=".R_FDL_Text"
        #elif R_FDL_COMPILER == R_FDL_COMP_IAR
            #pragma location = "R_FDL_Text"
        #elif R_FDL_COMPILER == R_FDL_COMP_REC
            #pragma section text "R_FDL_Text"
        #endif
    #elif defined R_FDL_STOP_SEC_PUBLIC_CODE
        #undef R_FDL_STOP_SEC_PUBLIC_CODE                                                           /* PRQA S 0841 */
        #if   R_FDL_COMPILER == R_FDL_COMP_GHS
            #pragma ghs section text=default
        #elif R_FDL_COMPILER == R_FDL_COMP_IAR
            /* location only for one function, so no default required */
        #elif R_FDL_COMPILER == R_FDL_COMP_REC
            #pragma section default
        #endif

    #elif defined R_FDL_START_SEC_CONST
        #undef R_FDL_START_SEC_CONST                                                                /* PRQA S 0841 */
        #if   R_FDL_COMPILER == R_FDL_COMP_GHS
            #pragma ghs startdata
            #pragma ghs section rodata=".R_FDL_Const"
        #elif R_FDL_COMPILER == R_FDL_COMP_IAR
            #pragma constseg = "R_FDL_Const"
        #elif R_FDL_COMPILER == R_FDL_COMP_REC
            #pragma section const "R_FDL_Const"
        #endif
    #elif defined R_FDL_STOP_SEC_CONST
        #undef R_FDL_STOP_SEC_CONST                                                                 /* PRQA S 0841 */
        #if   R_FDL_COMPILER == R_FDL_COMP_GHS
            #pragma ghs section rodata=default
            #pragma ghs enddata
        #elif R_FDL_COMPILER == R_FDL_COMP_IAR
            #pragma constseg = default
        #elif R_FDL_COMPILER == R_FDL_COMP_REC
            #pragma section default
        #endif

    #elif defined R_FDL_START_SEC_VAR
        #undef R_FDL_START_SEC_VAR                                                                  /* PRQA S 0841 */
        #if R_FDL_COMPILER == R_FDL_COMP_GHS
            #pragma ghs startdata
            #pragma ghs section bss = ".R_FDL_Data"
        #elif R_FDL_COMPILER == R_FDL_COMP_IAR
            #pragma dataseg = R_FDL_Data
        #elif R_FDL_COMPILER == R_FDL_COMP_REC
            #pragma section r0_disp32 "R_FDL_Data"
        #endif
    #elif defined R_FDL_STOP_SEC_VAR
        #undef R_FDL_STOP_SEC_VAR                                                                   /* PRQA S 0841 */
        #if R_FDL_COMPILER == R_FDL_COMP_GHS
            #pragma ghs section bss = default
            #pragma ghs enddata
        #elif R_FDL_COMPILER == R_FDL_COMP_IAR
            #pragma dataseg = default
        #elif R_FDL_COMPILER == R_FDL_COMP_REC
            #pragma section default
        #endif

    #elif defined R_FDL_START_SEC_CODERAM
        #undef R_FDL_START_SEC_CODERAM                                                                  /* PRQA S 0841 */
        #if R_FDL_COMPILER == R_FDL_COMP_GHS
            #pragma ghs startdata
            #pragma ghs section bss = ".R_FDL_CodeRam"
        #elif R_FDL_COMPILER == R_FDL_COMP_IAR
            #pragma dataseg = R_FDL_CodeRam
        #elif R_FDL_COMPILER == R_FDL_COMP_REC
            #pragma section r0_disp32 "R_FDL_CodeRam"
        #endif
    #elif defined R_FDL_STOP_SEC_CODERAM
        #undef R_FDL_STOP_SEC_CODERAM                                                                   /* PRQA S 0841 */
        #if R_FDL_COMPILER == R_FDL_COMP_GHS
            #pragma ghs section bss = default
            #pragma ghs enddata
        #elif R_FDL_COMPILER == R_FDL_COMP_IAR
            #pragma dataseg = default
        #elif R_FDL_COMPILER == R_FDL_COMP_REC
            #pragma section default
        #endif

    #else
      #error "r_fdl_mem_map.h: No valid section define found"
    #endif /* if defined R_FDL_START_SEC_PUBLIC_CODE */

#endif /* ifdef AUTOSAR_IMPLEMENTATION */
/*********************************************************************************************************************/

