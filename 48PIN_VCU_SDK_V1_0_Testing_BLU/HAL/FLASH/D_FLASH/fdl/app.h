/*********************************************************************************************************************
 * File Name     : $Source: app.h $
 * Mod. Revision : $Revision: 1.9 $
 * Mod. Date     : $Date: 2019/04/26 11:31:23JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Sample application header file
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
 * Copyright (C) 2014-2019 Renesas Electronics Corporation. All rights reserved.     
 *********************************************************************************************************************/


#ifndef SAMPLEAPP_H
#define SAMPLEAPP_H

/*********************************************************************************************************************
 * Global compiler definition
 *********************************************************************************************************************/
#define APP_COMP_GHS 1
#define APP_COMP_IAR 2
#define APP_COMP_REC 3

#if defined (__IAR_SYSTEMS_ASM__)
    #define APP_COMPILER APP_COMP_IAR
#elif defined (__IAR_SYSTEMS_ICC__)
    #define APP_COMPILER APP_COMP_IAR
#elif defined(__v850e3v5__)
    #define APP_COMPILER APP_COMP_REC
#else /*GHS */
    #define APP_COMPILER APP_COMP_GHS
#endif

/*********************************************************************************************************************/
#endif    /* #ifndef SAMPLEAPP_H */
