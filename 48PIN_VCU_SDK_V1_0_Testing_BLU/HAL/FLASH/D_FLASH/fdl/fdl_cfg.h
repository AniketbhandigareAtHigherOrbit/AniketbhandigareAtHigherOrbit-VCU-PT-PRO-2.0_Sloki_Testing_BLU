#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * File Name     : $Source: fdl_cfg.h $
 * Mod. Revision : $Revision: 1.2 $
 * Mod. Date     : $Date: 2019/04/26 11:34:56JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : FDL pre-compile definitions
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
 * Verification: The placeholders are used in commentary only. Therefore rule violation cannot influence code 
 *               compilation.
 *********************************************************************************************************************/

#ifndef FDL_CFG_H
#define FDL_CFG_H

/*********************************************************************************************************************
 * device specific define
 *********************************************************************************************************************/

    /******************************************************************************************************************
    * Callback defines to disable interrupts during execution of critical code sections in the 
    * function R_FDL_Init.
    * All possibly occurring exceptions must be disabled because during execution of the critical 
    * sections the Flash is not accessible
    ******************************************************************************************************************/
   
    #define R_FDL_NO_BFA_SWITCH  
   void FDL_User_CriticalSetionBegin (void);
    void FDL_User_CriticalSetionEnd (void);

    #define FDL_CRITICAL_SECTION_BEGIN     FDL_User_CriticalSetionBegin();      /* PRQA S 3412 */
    #define FDL_CRITICAL_SECTION_END       FDL_User_CriticalSetionEnd();        /* PRQA S 3412 */

    /******************************************************************************************************************
    * Optional configuration
    ******************************************************************************************************************/
    /* Enable compatibility mode */
   //  #define R_FDL_LIB_V1_COMPATIBILITY 

/*********************************************************************************************************************/
#endif /* #ifndef FDL_CFG_H */
