/*********************************************************************************************************************
 * File Name     : $Source: target.h $
 * Mod. Revision : $Revision: 1.3 $
 * Mod. Date     : $Date: 2019/05/07 09:32:19JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Target specific defines
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

#ifndef TARGET_H
#define TARGET_H

/*********************************************************************************************************************
 * Include list
 *********************************************************************************************************************/
#include "app.h"
#include "iodefine.h"
#if APP_COMPILER == APP_COMP_REC
   #include "iodefine.h"
#elif APP_COMPILER == APP_COMP_IAR
#if __VER__ <= 140
    #include "ior7f701007xafp.h"
#else
    #include "ior7f701007.h"
#endif
#else
/*  #include "dr7f701007_0.h" */
    #include "dr7f701007.dvf.h"
#endif

/*********************************************************************************************************************
 * Global macros
 *********************************************************************************************************************/

/******* Initialize CPU clock and peripheral clock ***************************/
#define INIT_CPU_AND_FPERIPHERAL_CLK                                                            \
    /* Prepare 16MHz MainOsz */                                                                 \
    MOSCC=0x06;                     /* Set MainOSC gain (8MHz < MOSC frequency =< 16MHz) */     \
    MOSCST=0xFFFF;                  /* Set MainOSC stabilization time to max (8,19 ms) */       \
                                                                                                \
    PROTCMD0=0xa5;                  /* Trigger Enable (protected write) */                      \
    MOSCE=0x01;                                                                                 \
    MOSCE=(~0x01);                                                                              \
    MOSCE=0x01;                                                                                 \
    while ((MOSCS&0x04) != 0x4);    /* Wait for stable MainOSC */                               \
                                                                                                \
    /* Prepare PLL*/                                                                            \
    /*PLLC=0x00000227;                 8 MHz MainOSC -> 80MHz PLL */                            \
    PLLC=0x00000a27;                /*16 MHz MainOSC -> 80MHz PLL */                            \
    PROTCMD1=0xa5;                  /* enable PLL (protected write) */                          \
    PLLE=0x01;                                                                                  \
    PLLE=(~0x01);                                                                               \
    PLLE=0x01;                                                                                  \
    while((PLLS&0x04) != 0x04);     /*Wait for stable PLL */                                    \
                                                                                                \
    /* CPU Clock devider = 1 */                                                                 \
    PROTCMD1=0xa5;                                                                              \
    CKSC_CPUCLKD_CTL=0x01;                                                                      \
    CKSC_CPUCLKD_CTL=(~0x01);                                                                   \
    CKSC_CPUCLKD_CTL=0x01;                                                                      \
    while(CKSC_CPUCLKD_ACT!=0x01);                                                              \
                                                                                                \
    /* PLL -> CPU Clock */                                                                      \
    PROTCMD1=0xa5;                                                                              \
    CKSC_CPUCLKS_CTL=0x03;                                                                      \
    CKSC_CPUCLKS_CTL=(~0x03);                                                                   \
    CKSC_CPUCLKS_CTL=0x03;                                                                      \
    while(CKSC_CPUCLKS_ACT!=0x03);                                                              \


/* F1L WS2.0 needs Flash authentication prior to switch mode */
/*
#define R_FDL_DEVICE_SPECIFIC_INIT                                  \
            *(volatile uint32_t *)0xFFA08000 = 0xFFFFFFFF;          \
            *(volatile uint32_t *)0xFFA08004 = 0xFFFFFFFF;          \
            *(volatile uint32_t *)0xFFA08008 = 0xFFFFFFFF;          \
            *(volatile uint32_t *)0xFFA0800C = 0xFFFFFFFF;
*/
/******* Initialize the Data Flash access ************************************/
#define INIT_FLASHACCESS                                                                        \
    EEPRDCYCL = 0x0F; 

#define DISABLE_FLASHACCESS                                                                     \

/*********************************************************************************************************************/
#endif    /* #ifndef TARGET_H */
