/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2018, 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : r_cg_ad.h
* Version          : 1.0.120
* Device(s)        : R7F701687
* Description      : General header file for ADCA peripheral.
***********************************************************************************************************************/

#ifndef ADCA_H
#define ADCA_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Virtual Channel Register j (ADCAnVCRj)
*/
/* MPX enable (MPXE) */
#define _ADC_MPX_DISABLE                          (0x00000000UL) /* MPX is prohibited */
#define _ADC_MPX_ENABLE                           (0x00008000UL) /* MPX is permitted */
/* A/D conversion type select for self-diagnosis (CNVCLS) */
#define _ADC_SELF_DIAG_HOLD_VALUE                 (0x00000000UL) /* A/D conversion of the hold value is performed */
#define _ADC_SELF_DIAG_NORMAL                     (0x00000200UL) /* Normal A/D conversion is performed */
/* A/D conversion end interrupt enable (ADIE) */
#define _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE      (0x00000000UL) /* Scan group x end interrupt (INT_SGx) is not
                                                                    generated */
#define _ADC_VIRTUAL_CHANNEL_END_INT_ENABLE       (0x00000100UL) /* Scan group x end interrupt (INT_SGx) is generated */
/* Upper limit/lower limit table select (ULS[3:0]) */
#define _ADC_LIMIT_TABLE_SELECT_NONE              (0x00000000UL) /* Upper limit/lower limit are not checked */
#define _ADC_LIMIT_TABLE_SELECT_0                 (0x00000040UL) /* Upper limit/lower limit are checked for ULLMTBR0 */
#define _ADC_LIMIT_TABLE_SELECT_1                 (0x00000080UL) /* Upper limit/lower limit are checked for ULLMTBR1 */
#define _ADC_LIMIT_TABLE_SELECT_2                 (0x000000C0UL) /* Upper limit/lower limit are checked for ULLMTBR2 */
#define _ADC_LIMIT_TABLE_SELECT_3                 (0x00000400UL) /* Upper limit/lower limit are checked for ULLMTBR3 */
#define _ADC_LIMIT_TABLE_SELECT_4                 (0x00000440UL) /* Upper limit/lower limit are checked for ULLMTBR4 */
#define _ADC_LIMIT_TABLE_SELECT_5                 (0x00000480UL) /* Upper limit/lower limit are checked for ULLMTBR5 */
#define _ADC_LIMIT_TABLE_SELECT_6                 (0x000004C0UL) /* Upper limit/lower limit are checked for ULLMTBR6 */
#define _ADC_LIMIT_TABLE_SELECT_7                 (0x00000800UL) /* Upper limit/lower limit are checked for ULLMTBR7 */
/* Physical channel select (GCTRL[5:0]) */
#define _ADC_PHYSICAL_CHANNEL_ANI00               (0x00000000UL) /* ANIn00 */
#define _ADC_PHYSICAL_CHANNEL_ANI01               (0x00000001UL) /* ANIn01 */
#define _ADC_PHYSICAL_CHANNEL_ANI02               (0x00000002UL) /* ANIn02 */
#define _ADC_PHYSICAL_CHANNEL_ANI03               (0x00000003UL) /* ANIn03 */
#define _ADC_PHYSICAL_CHANNEL_ANI04               (0x00000004UL) /* ANIn04 */
#define _ADC_PHYSICAL_CHANNEL_ANI05               (0x00000005UL) /* ANIn05 */
#define _ADC_PHYSICAL_CHANNEL_ANI06               (0x00000006UL) /* ANIn06 */
#define _ADC_PHYSICAL_CHANNEL_ANI07               (0x00000007UL) /* ANIn07 */
#define _ADC_PHYSICAL_CHANNEL_ANI08               (0x00000008UL) /* ANIn08 */
#define _ADC_PHYSICAL_CHANNEL_ANI09               (0x00000009UL) /* ANIn09 */
#define _ADC_PHYSICAL_CHANNEL_ANI10               (0x0000000AUL) /* ANIn10 */
#define _ADC_PHYSICAL_CHANNEL_ANI11               (0x0000000BUL) /* ANIn11 */
#define _ADC_PHYSICAL_CHANNEL_ANI12               (0x0000000CUL) /* ANIn12 */
#define _ADC_PHYSICAL_CHANNEL_ANI13               (0x0000000DUL) /* ANIn13 */
#define _ADC_PHYSICAL_CHANNEL_ANI14               (0x0000000EUL) /* ANIn14 */
#define _ADC_PHYSICAL_CHANNEL_ANI15               (0x0000000FUL) /* ANIn15 */
#define _ADC_PHYSICAL_CHANNEL_ANI16               (0x00000010UL) /* ANIn16 */
#define _ADC_PHYSICAL_CHANNEL_ANI17               (0x00000011UL) /* ANIn17 */
#define _ADC_PHYSICAL_CHANNEL_ANI18               (0x00000012UL) /* ANIn18 */
#define _ADC_PHYSICAL_CHANNEL_ANI19               (0x00000013UL) /* ANIn19 */
#define _ADC_PHYSICAL_CHANNEL_ANI20               (0x00000014UL) /* ANIn20 */
#define _ADC_PHYSICAL_CHANNEL_ANI21               (0x00000015UL) /* ANIn21 */
#define _ADC_PHYSICAL_CHANNEL_ANI22               (0x00000016UL) /* ANIn22 */
#define _ADC_PHYSICAL_CHANNEL_ANI23               (0x00000017UL) /* ANIn23 */
#define _ADC_PHYSICAL_CHANNEL_ANI24               (0x00000018UL) /* ANIn24 */
#define _ADC_PHYSICAL_CHANNEL_ANI25               (0x00000019UL) /* ANIn25 */
#define _ADC_PHYSICAL_CHANNEL_ANI26               (0x0000001AUL) /* ANIn26 */
#define _ADC_PHYSICAL_CHANNEL_ANI27               (0x0000001BUL) /* ANIn27 */
#define _ADC_PHYSICAL_CHANNEL_ANI28               (0x0000001CUL) /* ANIn28 */
#define _ADC_PHYSICAL_CHANNEL_ANI29               (0x0000001DUL) /* ANIn29 */
#define _ADC_PHYSICAL_CHANNEL_ANI30               (0x0000001EUL) /* ANIn30 */
#define _ADC_PHYSICAL_CHANNEL_ANI31               (0x0000001FUL) /* ANIn31 */
#define _ADC_PHYSICAL_CHANNEL_ANI32               (0x00000020UL) /* ANIn32 */
#define _ADC_PHYSICAL_CHANNEL_ANI33               (0x00000021UL) /* ANIn33 */
#define _ADC_PHYSICAL_CHANNEL_ANI34               (0x00000022UL) /* ANIn34 */
#define _ADC_PHYSICAL_CHANNEL_ANI35               (0x00000023UL) /* ANIn35 */
#define _ADC_PHYSICAL_CHANNEL_DIAGNOSIS           (0x00000024UL) /* Diagnosis channel */

/*
    A/D Force Halt Register (ADCAnADHALTR)
*/
/* ADCA force halt trigger (HALT) */
#define _ADC_HALT                                 (0x00000001UL) /* Scan groups are halted */

/*
    A/D Control Register (ADCAnADCR)
*/
/* Self-diagnostic voltage standby control (DGON) */
#define _ADC_SELF_DIAG_VOLTAGE_CIRCUIT_OFF        (0xFFFFFF7FUL) /* The self-diagnostic voltage circuit is turned off */
#define _ADC_SELF_DIAG_VOLTAGE_CIRCUIT_ON         (0x00000080UL) /* The self-diagnostic voltage circuit is turned on,
                                                                    or the reference voltage is updated */
/* Alignment control (CRAC) */
#define _ADC_RIGHT_ALIGNED                        (0x00000000UL) /* The results of conversion are stored
                                                                    right-aligned */
#define _ADC_LEFT_ALIGNED                         (0x00000020UL) /* The results of conversion are stored
                                                                    left-aligned */
/* 12/10 bit select mode (CTYP) */
#define _ADC_12_BIT_MODE                          (0x00000000UL) /* 12-bit mode */
#define _ADC_10_BIT_MODE                          (0x00000010UL) /* 10-bit mode */
/* Suspend mode select (SUSMTD[1:0]) */
#define _ADC_SYNC_SUSPEND                         (0x00000000UL) /* Synchronous suspend */
#define _ADC_ASYNC_SYNC_SUSPEND                   (0x00000001UL) /* Synchronous and asynchronous mixed suspend */
#define _ADC_ASYNC_SUSPEND                        (0x00000002UL) /* Asynchronous suspend */

/*
    T&H Sampling Start Control Register (ADCAnTHSMPSTCR)
*/
/* T&H sampling start control trigger (SMPST) */
#define _ADC_TH_SAMPLING_START                    (0x00000001UL) /* Sampling for all T&H is started */

/*
    T&H Control Register (ADCAnTHCR)
*/
/* Automatic sampling mask control (ASMPMSK) */
#define _ADC_TH_SAMPLING_MANUAL                   (0x00000000UL) /* Automatic sampling is not performed */
#define _ADC_TH_SAMPLING_AUTOMATIC                (0x00000001UL) /* Automatic sampling is performed */

/*
    T&H Group A Hold Start Control Register (ADCAnTHAHLDSTCR)
*/
/* T&H group A hold start control trigger (HLDST) */
#define _ADC_TH_GROUP_A_START                     (0x00000001UL) /* Hold for T&H group A is started */

/*
    T&H Group B Hold Start Control Register (ADCAnTHBHLDSTCR)
*/
/* T&H group B hold start control trigger (HLDST) */
#define _ADC_TH_GROUP_B_START                     (0x00000001UL) /* Hold for T&H group B is started */

/*
    T&H Group A Control Register (ADCAnTHACR)
*/
/* T&H group A hold completion trigger enable (HLDCTE) */
#define _ADC_TH_GRPA_SELF_DIAG_PROCEED_DISABLE    (0x00000000UL) /* Self-diagnosis does not proceed */
#define _ADC_TH_GRPA_SELF_DIAG_PROCEED_ENABLE     (0x00000020UL) /* Self-diagnosis proceeds */
/* T&H group A hold trigger enable (HLDTE) */
#define _ADC_TH_GRPA_START_TRIGGER_USED           (0x00000000UL) /* The SGx trigger selected in SGS[1:0] is selected
                                                                    for the hold start trigger of T&H group A */
#define _ADC_TH_GRPA_START_TRIGGER_UNUSED         (0x00000010UL) /* The SGx trigger selected in SGS[1:0] is not selected
                                                                    for the hold start trigger of T&H group A */
/* T&H group A scan group select (SGS[1:0]) */
#define _ADC_TH_GRPA_SELECT_NONE                  (0x00000000UL) /* No scan group is selected for T&H group A */
#define _ADC_TH_GRPA_SELECT_SG1                   (0x00000001UL) /* SG1 is selected for T&H group A */
#define _ADC_TH_GRPA_SELECT_SG2                   (0x00000002UL) /* SG2 is selected for T&H group A */
#define _ADC_TH_GRPA_SELECT_SG3                   (0x00000003UL) /* SG3 is selected for T&H group A */

/*
    T&H Group B Control Register (ADCAnTHBCR)
*/
/* T&H group B hold completion trigger enable (HLDCTE) */
#define _ADC_TH_GRPB_SELF_DIAG_PROCEED_DISABLE    (0x00000000UL) /* Self-diagnosis does not proceed */
#define _ADC_TH_GRPB_SELF_DIAG_PROCEED_ENABLE     (0x00000020UL) /* Self-diagnosis proceeds */
/* T&H group B hold trigger enable (HLDTE) */
#define _ADC_TH_GRPB_START_TRIGGER_USED           (0x00000000UL) /* The SGx trigger selected in SGS[1:0] is selected
                                                                    for the hold start trigger of T&H group B */
#define _ADC_TH_GRPB_START_TRIGGER_UNUSED         (0x00000010UL) /* The SGx trigger selected in SGS[1:0] is not selected
                                                                    for the hold start trigger of T&H group B */
/* T&H group B scan group select (SGS[1:0]) */
#define _ADC_TH_GRPB_SELECT_NONE                  (0x00000000UL) /* No scan group is selected for T&H group B */
#define _ADC_TH_GRPB_SELECT_SG1                   (0x00000001UL) /* SG1 is selected for T&H group B */
#define _ADC_TH_GRPB_SELECT_SG2                   (0x00000002UL) /* SG2 is selected for T&H group B */
#define _ADC_TH_GRPB_SELECT_SG3                   (0x00000003UL) /* SG3 is selected for T&H group B */

/*
    T&H Enable Register (ADCAnTHER)
*/
/* T&H5 enable (TH5E) */
#define _ADC_TH5_DISABLED                         (0x00000000UL) /* T&H5 is disabled */
#define _ADC_TH5_ENABLED                          (0x00000020UL) /* T&H5 is enabled */
/* T&H4 enable (TH4E) */
#define _ADC_TH4_DISABLED                         (0x00000000UL) /* T&H4 is disabled */
#define _ADC_TH4_ENABLED                          (0x00000010UL) /* T&H4 is enabled */
/* T&H3 enable (TH3E) */
#define _ADC_TH3_DISABLED                         (0x00000000UL) /* T&H3 is disabled */
#define _ADC_TH3_ENABLED                          (0x00000008UL) /* T&H3 is enabled */
/* T&H2 enable (TH2E) */
#define _ADC_TH2_DISABLED                         (0x00000000UL) /* T&H2 is disabled */
#define _ADC_TH2_ENABLED                          (0x00000004UL) /* T&H2 is enabled */
/* T&H1 enable (TH1E) */
#define _ADC_TH1_DISABLED                         (0x00000000UL) /* T&H1 is disabled */
#define _ADC_TH1_ENABLED                          (0x00000002UL) /* T&H1 is enabled */
/* T&H0 enable (TH0E) */
#define _ADC_TH0_DISABLED                         (0x00000000UL) /* T&H0 is disabled */
#define _ADC_TH0_ENABLED                          (0x00000001UL) /* T&H0 is enabled */

/*
    T&H Group Select Register (ADCAnTHGSR)
*/
/* T&H5 group select (TH5GS) */
#define _ADC_TH5_GROUP_A                          (0x00000000UL) /* T&H5 is selected to group A */
#define _ADC_TH5_GROUP_B                          (0x00000020UL) /* T&H5 is selected to group B */
/* T&H4 group select (TH4GS) */
#define _ADC_TH4_GROUP_A                          (0x00000000UL) /* T&H4 is selected to group A */
#define _ADC_TH4_GROUP_B                          (0x00000010UL) /* T&H4 is selected to group B */
/* T&H3 group select (TH3GS) */
#define _ADC_TH3_GROUP_A                          (0x00000000UL) /* T&H3 is selected to group A */
#define _ADC_TH3_GROUP_B                          (0x00000008UL) /* T&H3 is selected to group B */
/* T&H2 group select (TH2GS) */
#define _ADC_TH2_GROUP_A                          (0x00000000UL) /* T&H2 is selected to group A */
#define _ADC_TH2_GROUP_B                          (0x00000004UL) /* T&H2 is selected to group B */
/* T&H1 group select (TH1GS) */
#define _ADC_TH1_GROUP_A                          (0x00000000UL) /* T&H1 is selected to group A */
#define _ADC_TH1_GROUP_B                          (0x00000002UL) /* T&H1 is selected to group B */
/* T&H0 group select (TH0GS) */
#define _ADC_TH0_GROUP_A                          (0x00000000UL) /* T&H0 is selected to group A */
#define _ADC_TH0_GROUP_B                          (0x00000001UL) /* T&H0 is selected to group B */

/*
    Sampling Control Register (ADCAnSMPCR)
*/
/* Set the sampling time (the number of cycles) (SMPT[7:0]) */
#define _ADC_SAMPLING_18_CYCLES                   (0x00000012UL) /* 18 cycles (ADCLK = 8 MHz to 32 MHz) */
#define _ADC_SAMPLING_24_CYCLES                   (0x00000018UL) /* 24 cycles (ADCLK = 8 MHz to 40 MHz) */

/*
    MPX Stabilization Time Selection Register 0 (ADCAnMPXSTBTSELR0)
*/
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn07 (STBTCH07[2:0]) */
#define _ADC_ANI07_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI07_STBT_SELECT_1                  (0x10000000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI07_STBT_SELECT_2                  (0x20000000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI07_STBT_SELECT_3                  (0x30000000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI07_STBT_SELECT_4                  (0x40000000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI07_STBT_SELECT_5                  (0x50000000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI07_STBT_SELECT_6                  (0x60000000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI07_STBT_SELECT_7                  (0x70000000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn06 (STBTCH06[2:0]) */
#define _ADC_ANI06_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI06_STBT_SELECT_1                  (0x01000000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI06_STBT_SELECT_2                  (0x02000000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI06_STBT_SELECT_3                  (0x03000000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI06_STBT_SELECT_4                  (0x04000000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI06_STBT_SELECT_5                  (0x05000000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI06_STBT_SELECT_6                  (0x06000000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI06_STBT_SELECT_7                  (0x07000000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn05 (STBTCH05[2:0]) */
#define _ADC_ANI05_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI05_STBT_SELECT_1                  (0x00100000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI05_STBT_SELECT_2                  (0x00200000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI05_STBT_SELECT_3                  (0x00300000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI05_STBT_SELECT_4                  (0x00400000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI05_STBT_SELECT_5                  (0x00500000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI05_STBT_SELECT_6                  (0x00600000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI05_STBT_SELECT_7                  (0x00700000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn04 (STBTCH04[2:0]) */
#define _ADC_ANI04_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI04_STBT_SELECT_1                  (0x00010000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI04_STBT_SELECT_2                  (0x00020000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI04_STBT_SELECT_3                  (0x00030000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI04_STBT_SELECT_4                  (0x00040000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI04_STBT_SELECT_5                  (0x00050000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI04_STBT_SELECT_6                  (0x00060000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI04_STBT_SELECT_7                  (0x00070000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn03 (STBTCH03[2:0]) */
#define _ADC_ANI03_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI03_STBT_SELECT_1                  (0x00001000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI03_STBT_SELECT_2                  (0x00002000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI03_STBT_SELECT_3                  (0x00003000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI03_STBT_SELECT_4                  (0x00004000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI03_STBT_SELECT_5                  (0x00005000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI03_STBT_SELECT_6                  (0x00006000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI03_STBT_SELECT_7                  (0x00007000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn02 (STBTCH02[2:0]) */
#define _ADC_ANI02_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI02_STBT_SELECT_1                  (0x00000100UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI02_STBT_SELECT_2                  (0x00000200UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI02_STBT_SELECT_3                  (0x00000300UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI02_STBT_SELECT_4                  (0x00000400UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI02_STBT_SELECT_5                  (0x00000500UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI02_STBT_SELECT_6                  (0x00000600UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI02_STBT_SELECT_7                  (0x00000700UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn01 (STBTCH01[2:0]) */
#define _ADC_ANI01_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI01_STBT_SELECT_1                  (0x00000010UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI01_STBT_SELECT_2                  (0x00000020UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI01_STBT_SELECT_3                  (0x00000030UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI01_STBT_SELECT_4                  (0x00000040UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI01_STBT_SELECT_5                  (0x00000050UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI01_STBT_SELECT_6                  (0x00000060UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI01_STBT_SELECT_7                  (0x00000070UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn00 (STBTCH00[2:0]) */
#define _ADC_ANI00_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI00_STBT_SELECT_1                  (0x00000001UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI00_STBT_SELECT_2                  (0x00000002UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI00_STBT_SELECT_3                  (0x00000003UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI00_STBT_SELECT_4                  (0x00000004UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI00_STBT_SELECT_5                  (0x00000005UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI00_STBT_SELECT_6                  (0x00000006UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI00_STBT_SELECT_7                  (0x00000007UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */

/*
    MPX Stabilization Time Selection Register 1 (ADCAnMPXSTBTSELR1)
*/
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn15 (STBTCH15[2:0]) */
#define _ADC_ANI15_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI15_STBT_SELECT_1                  (0x10000000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI15_STBT_SELECT_2                  (0x20000000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI15_STBT_SELECT_3                  (0x30000000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI15_STBT_SELECT_4                  (0x40000000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI15_STBT_SELECT_5                  (0x50000000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI15_STBT_SELECT_6                  (0x60000000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI15_STBT_SELECT_7                  (0x70000000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn14 (STBTCH14[2:0]) */
#define _ADC_ANI14_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI14_STBT_SELECT_1                  (0x01000000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI14_STBT_SELECT_2                  (0x02000000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI14_STBT_SELECT_3                  (0x03000000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI14_STBT_SELECT_4                  (0x04000000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI14_STBT_SELECT_5                  (0x05000000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI14_STBT_SELECT_6                  (0x06000000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI14_STBT_SELECT_7                  (0x07000000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn13 (STBTCH13[2:0]) */
#define _ADC_ANI13_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI13_STBT_SELECT_1                  (0x00100000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI13_STBT_SELECT_2                  (0x00200000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI13_STBT_SELECT_3                  (0x00300000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI13_STBT_SELECT_4                  (0x00400000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI13_STBT_SELECT_5                  (0x00500000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI13_STBT_SELECT_6                  (0x00600000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI13_STBT_SELECT_7                  (0x00700000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn12 (STBTCH12[2:0]) */
#define _ADC_ANI12_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI12_STBT_SELECT_1                  (0x00010000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI12_STBT_SELECT_2                  (0x00020000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI12_STBT_SELECT_3                  (0x00030000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI12_STBT_SELECT_4                  (0x00040000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI12_STBT_SELECT_5                  (0x00050000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI12_STBT_SELECT_6                  (0x00060000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI12_STBT_SELECT_7                  (0x00070000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn11 (STBTCH11[2:0]) */
#define _ADC_ANI11_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI11_STBT_SELECT_1                  (0x00001000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI11_STBT_SELECT_2                  (0x00002000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI11_STBT_SELECT_3                  (0x00003000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI11_STBT_SELECT_4                  (0x00004000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI11_STBT_SELECT_5                  (0x00005000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI11_STBT_SELECT_6                  (0x00006000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI11_STBT_SELECT_7                  (0x00007000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn10 (STBTCH10[2:0]) */
#define _ADC_ANI10_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI10_STBT_SELECT_1                  (0x00000100UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI10_STBT_SELECT_2                  (0x00000200UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI10_STBT_SELECT_3                  (0x00000300UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI10_STBT_SELECT_4                  (0x00000400UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI10_STBT_SELECT_5                  (0x00000500UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI10_STBT_SELECT_6                  (0x00000600UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI10_STBT_SELECT_7                  (0x00000700UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn09 (STBTCH09[2:0]) */
#define _ADC_ANI09_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI09_STBT_SELECT_1                  (0x00000010UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI09_STBT_SELECT_2                  (0x00000020UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI09_STBT_SELECT_3                  (0x00000030UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI09_STBT_SELECT_4                  (0x00000040UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI09_STBT_SELECT_5                  (0x00000050UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI09_STBT_SELECT_6                  (0x00000060UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI09_STBT_SELECT_7                  (0x00000070UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn08 (STBTCH08[2:0]) */
#define _ADC_ANI08_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI08_STBT_SELECT_1                  (0x00000001UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI08_STBT_SELECT_2                  (0x00000002UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI08_STBT_SELECT_3                  (0x00000003UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI08_STBT_SELECT_4                  (0x00000004UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI08_STBT_SELECT_5                  (0x00000005UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI08_STBT_SELECT_6                  (0x00000006UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI08_STBT_SELECT_7                  (0x00000007UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */

/*
    MPX Stabilization Time Selection Register 2 (ADCAnMPXSTBTSELR2)
*/
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn23 (STBTCH23[2:0]) */
#define _ADC_ANI23_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI23_STBT_SELECT_1                  (0x10000000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI23_STBT_SELECT_2                  (0x20000000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI23_STBT_SELECT_3                  (0x30000000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI23_STBT_SELECT_4                  (0x40000000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI23_STBT_SELECT_5                  (0x50000000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI23_STBT_SELECT_6                  (0x60000000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI23_STBT_SELECT_7                  (0x70000000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn22 (STBTCH22[2:0]) */
#define _ADC_ANI22_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI22_STBT_SELECT_1                  (0x01000000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI22_STBT_SELECT_2                  (0x02000000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI22_STBT_SELECT_3                  (0x03000000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI22_STBT_SELECT_4                  (0x04000000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI22_STBT_SELECT_5                  (0x05000000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI22_STBT_SELECT_6                  (0x06000000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI22_STBT_SELECT_7                  (0x07000000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn21 (STBTCH21[2:0]) */
#define _ADC_ANI21_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI21_STBT_SELECT_1                  (0x00100000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI21_STBT_SELECT_2                  (0x00200000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI21_STBT_SELECT_3                  (0x00300000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI21_STBT_SELECT_4                  (0x00400000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI21_STBT_SELECT_5                  (0x00500000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI21_STBT_SELECT_6                  (0x00600000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI21_STBT_SELECT_7                  (0x00700000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn20 (STBTCH20[2:0]) */
#define _ADC_ANI20_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI20_STBT_SELECT_1                  (0x00010000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI20_STBT_SELECT_2                  (0x00020000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI20_STBT_SELECT_3                  (0x00030000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI20_STBT_SELECT_4                  (0x00040000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI20_STBT_SELECT_5                  (0x00050000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI20_STBT_SELECT_6                  (0x00060000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI20_STBT_SELECT_7                  (0x00070000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn19 (STBTCH19[2:0]) */
#define _ADC_ANI19_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI19_STBT_SELECT_1                  (0x00001000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI19_STBT_SELECT_2                  (0x00002000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI19_STBT_SELECT_3                  (0x00003000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI19_STBT_SELECT_4                  (0x00004000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI19_STBT_SELECT_5                  (0x00005000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI19_STBT_SELECT_6                  (0x00006000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI19_STBT_SELECT_7                  (0x00007000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn18 (STBTCH18[2:0]) */
#define _ADC_ANI18_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI18_STBT_SELECT_1                  (0x00000100UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI18_STBT_SELECT_2                  (0x00000200UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI18_STBT_SELECT_3                  (0x00000300UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI18_STBT_SELECT_4                  (0x00000400UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI18_STBT_SELECT_5                  (0x00000500UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI18_STBT_SELECT_6                  (0x00000600UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI18_STBT_SELECT_7                  (0x00000700UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn17 (STBTCH17[2:0]) */
#define _ADC_ANI17_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI17_STBT_SELECT_1                  (0x00000010UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI17_STBT_SELECT_2                  (0x00000020UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI17_STBT_SELECT_3                  (0x00000030UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI17_STBT_SELECT_4                  (0x00000040UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI17_STBT_SELECT_5                  (0x00000050UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI17_STBT_SELECT_6                  (0x00000060UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI17_STBT_SELECT_7                  (0x00000070UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn16 (STBTCH16[2:0]) */
#define _ADC_ANI16_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI16_STBT_SELECT_1                  (0x00000001UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI16_STBT_SELECT_2                  (0x00000002UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI16_STBT_SELECT_3                  (0x00000003UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI16_STBT_SELECT_4                  (0x00000004UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI16_STBT_SELECT_5                  (0x00000005UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI16_STBT_SELECT_6                  (0x00000006UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI16_STBT_SELECT_7                  (0x00000007UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */

/*
    MPX Stabilization Time Selection Register 3 (ADCAnMPXSTBTSELR3)
*/
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn31 (STBTCH31[2:0]) */
#define _ADC_ANI31_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI31_STBT_SELECT_1                  (0x10000000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI31_STBT_SELECT_2                  (0x20000000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI31_STBT_SELECT_3                  (0x30000000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI31_STBT_SELECT_4                  (0x40000000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI31_STBT_SELECT_5                  (0x50000000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI31_STBT_SELECT_6                  (0x60000000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI31_STBT_SELECT_7                  (0x70000000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn30 (STBTCH30[2:0]) */
#define _ADC_ANI30_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI30_STBT_SELECT_1                  (0x01000000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI30_STBT_SELECT_2                  (0x02000000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI30_STBT_SELECT_3                  (0x03000000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI30_STBT_SELECT_4                  (0x04000000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI30_STBT_SELECT_5                  (0x05000000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI30_STBT_SELECT_6                  (0x06000000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI30_STBT_SELECT_7                  (0x07000000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn29 (STBTCH29[2:0]) */
#define _ADC_ANI29_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI29_STBT_SELECT_1                  (0x00100000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI29_STBT_SELECT_2                  (0x00200000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI29_STBT_SELECT_3                  (0x00300000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI29_STBT_SELECT_4                  (0x00400000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI29_STBT_SELECT_5                  (0x00500000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI29_STBT_SELECT_6                  (0x00600000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI29_STBT_SELECT_7                  (0x00700000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn28 (STBTCH28[2:0]) */
#define _ADC_ANI28_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI28_STBT_SELECT_1                  (0x00010000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI28_STBT_SELECT_2                  (0x00020000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI28_STBT_SELECT_3                  (0x00030000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI28_STBT_SELECT_4                  (0x00040000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI28_STBT_SELECT_5                  (0x00050000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI28_STBT_SELECT_6                  (0x00060000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI28_STBT_SELECT_7                  (0x00070000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn27 (STBTCH27[2:0]) */
#define _ADC_ANI27_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI27_STBT_SELECT_1                  (0x00001000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI27_STBT_SELECT_2                  (0x00002000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI27_STBT_SELECT_3                  (0x00003000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI27_STBT_SELECT_4                  (0x00004000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI27_STBT_SELECT_5                  (0x00005000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI27_STBT_SELECT_6                  (0x00006000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI27_STBT_SELECT_7                  (0x00007000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn26 (STBTCH26[2:0]) */
#define _ADC_ANI26_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI26_STBT_SELECT_1                  (0x00000100UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI26_STBT_SELECT_2                  (0x00000200UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI26_STBT_SELECT_3                  (0x00000300UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI26_STBT_SELECT_4                  (0x00000400UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI26_STBT_SELECT_5                  (0x00000500UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI26_STBT_SELECT_6                  (0x00000600UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI26_STBT_SELECT_7                  (0x00000700UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn25 (STBTCH25[2:0]) */
#define _ADC_ANI25_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI25_STBT_SELECT_1                  (0x00000010UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI25_STBT_SELECT_2                  (0x00000020UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI25_STBT_SELECT_3                  (0x00000030UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI25_STBT_SELECT_4                  (0x00000040UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI25_STBT_SELECT_5                  (0x00000050UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI25_STBT_SELECT_6                  (0x00000060UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI25_STBT_SELECT_7                  (0x00000070UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn24 (STBTCH24[2:0]) */
#define _ADC_ANI24_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI24_STBT_SELECT_1                  (0x00000001UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI24_STBT_SELECT_2                  (0x00000002UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI24_STBT_SELECT_3                  (0x00000003UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI24_STBT_SELECT_4                  (0x00000004UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI24_STBT_SELECT_5                  (0x00000005UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI24_STBT_SELECT_6                  (0x00000006UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI24_STBT_SELECT_7                  (0x00000007UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */

/*
    MPX Stabilization Time Selection Register 4 (ADCAnMPXSTBTSELR4)
*/
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn35 (STBTCH35[2:0]) */
#define _ADC_ANI35_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI35_STBT_SELECT_1                  (0x00001000UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI35_STBT_SELECT_2                  (0x00002000UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI35_STBT_SELECT_3                  (0x00003000UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI35_STBT_SELECT_4                  (0x00004000UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI35_STBT_SELECT_5                  (0x00005000UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI35_STBT_SELECT_6                  (0x00006000UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI35_STBT_SELECT_7                  (0x00007000UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn34 (STBTCH34[2:0]) */
#define _ADC_ANI34_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI34_STBT_SELECT_1                  (0x00000100UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI34_STBT_SELECT_2                  (0x00000200UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI34_STBT_SELECT_3                  (0x00000300UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI34_STBT_SELECT_4                  (0x00000400UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI34_STBT_SELECT_5                  (0x00000500UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI34_STBT_SELECT_6                  (0x00000600UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI34_STBT_SELECT_7                  (0x00000700UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn33 (STBTCH33[2:0]) */
#define _ADC_ANI33_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI33_STBT_SELECT_1                  (0x00000010UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI33_STBT_SELECT_2                  (0x00000020UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI33_STBT_SELECT_3                  (0x00000030UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI33_STBT_SELECT_4                  (0x00000040UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI33_STBT_SELECT_5                  (0x00000050UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI33_STBT_SELECT_6                  (0x00000060UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI33_STBT_SELECT_7                  (0x00000070UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */
/* Select the value from ADCAnMPXSTBTR0 to 7 for MPX stabilization time for ANIn32 (STBTCH32[2:0]) */
#define _ADC_ANI32_STBT_SELECT_0                  (0x00000000UL) /* ADCAnMPXSTBTR0 is used for MPX stabilization time */
#define _ADC_ANI32_STBT_SELECT_1                  (0x00000001UL) /* ADCAnMPXSTBTR1 is used for MPX stabilization time */
#define _ADC_ANI32_STBT_SELECT_2                  (0x00000002UL) /* ADCAnMPXSTBTR2 is used for MPX stabilization time */
#define _ADC_ANI32_STBT_SELECT_3                  (0x00000003UL) /* ADCAnMPXSTBTR3 is used for MPX stabilization time */
#define _ADC_ANI32_STBT_SELECT_4                  (0x00000004UL) /* ADCAnMPXSTBTR4 is used for MPX stabilization time */
#define _ADC_ANI32_STBT_SELECT_5                  (0x00000005UL) /* ADCAnMPXSTBTR5 is used for MPX stabilization time */
#define _ADC_ANI32_STBT_SELECT_6                  (0x00000006UL) /* ADCAnMPXSTBTR6 is used for MPX stabilization time */
#define _ADC_ANI32_STBT_SELECT_7                  (0x00000007UL) /* ADCAnMPXSTBTR7 is used for MPX stabilization time */

/*
    Safety Control Register (ADCAnSFTCR)
*/
/* Read and clear enable (RDCLRE) */
#define _ADC_READ_CLEAR_DISABLE                   (0x00000000UL) /* The A/D conversion result is not cleared by
                                                                    hardware */
#define _ADC_READ_CLEAR_ENABLE                    (0x00000010UL) /* The A/D conversion result is cleared by hardware */
/* A/D error interrupt (INT_ADE) enable on upper/lower limit error detection (ULEIE) */
#define _ADC_LIMIT_ERROR_INT_DISABLE              (0x00000000UL) /* Disabled */
#define _ADC_LIMIT_ERROR_INT_ENABLE               (0x00000008UL) /* Enabled */
/* A/D error interrupt (INT_ADE) enable on overwrite error detection (OWEIE) */
#define _ADC_OVERWRITE_ERROR_INT_DISABLE          (0x00000000UL) /* Disabled */
#define _ADC_OVERWRITE_ERROR_INT_ENABLE           (0x00000004UL) /* Enabled */

/*
    Scan Group x Start Control Register (ADCAnSGSTCRx)
*/
/* Scan group start trigger (SGST) */
#define _ADC_START                                (0x00000001UL) /* Starts the target SGx */

/*
    PWM-Diag Scan Stop Control Register (ADCAnPWDSGSTPCR)
*/
/* Scan group for PWM-Diag stop trigger (PWDSGSTP) */
#define _ADC_PWD_STOP                             (0x00000001UL) /* Stops scan group for PWM-Diag */

/*
    PWM-Diag Scan Group Control Register (ADCAnPWDSGCR)
*/
/* PWM-Diag trigger mode select (PWDTRGMD) */
#define _ADC_PWM_DIAG_HW_TRIGGER_DISABLE          (0x00000000UL) /* PWSA_ADTRG trigger input is disabled */
#define _ADC_PWM_DIAG_HW_TRIGGER_ENABLE           (0x00000001UL) /* PWSA_ADTRG is selected for the trigger input to the
                                                                    PWM-Diag scan group */

/*
    Scan Group x Control Register (ADCAnSGCRx)
*/
/* Scan mode (SCANMD) */
#define _ADC_SG_SCAN_MODE_MULTICYCLE              (0x00000000UL) /* Multicycle scan mode */
#define _ADC_SG_SCAN_MODE_CONTINUOUS              (0x00000020UL) /* Continuous scan mode */
/* Scan end interrupt enable (ADIE) */
#define _ADC_SG_SCAN_END_INT_DISABLE              (0x00000000UL) /* INT_SGx is not output */
#define _ADC_SG_SCAN_END_INT_ENABLE               (0x00000010UL) /* INT_SGx is output */
/* Channel repeat times select (SCT[1:0]) */
#define _ADC_SG_CHANNEL_REPEAT_TIME_1             (0x00000000UL) /* Channel repeat times is one */
#define _ADC_SG_CHANNEL_REPEAT_TIME_2             (0x00000004UL) /* Channel repeat times is two */
#define _ADC_SG_CHANNEL_REPEAT_TIME_4             (0x00000008UL) /* Channel repeat times is four */
/* Trigger mode (TRGMD) */
#define _ADC_SG_HW_TRIGGER_DISABLE                (0x00000000UL) /* Trigger input is disabled */
#define _ADC_SG_HW_TRIGGER_ENABLE                 (0x00000001UL) /* Start trigger or hold complete trigger A/B
                                                                     is selected */

/*
    Scan Group x Multicycle Register (ADCAnSGMCYCRx)
*/
/* Multicycle number specification (MCYC[1:0]) */
#define _ADC_SG_MULTICYCLE_NUMBER_1               (0x00000000UL) /* Number of scans = 1 */
#define _ADC_SG_MULTICYCLE_NUMBER_2               (0x00000001UL) /* Number of scans = 2 */
#define _ADC_SG_MULTICYCLE_NUMBER_4               (0x00000003UL) /* Number of scans = 4 */

/*
    Scan Group x Stop Control Register (ADCAnSGSTPCRx)
*/
/* Scan group x stop trigger (SGSTP) */
#define _ADC_STOP                                 (0x00000001UL) /* Stops the target SGx */

/*
    Scan Group x Start Trigger Control Register (ADCAnSGTSELx)
*/
/* A/D conversion hardware trigger select (TxSEL9) */
#define _ADC_SG_HW_TRIGGER_FACTOR_9               (0x00000200UL) /* Hardware trigger factor 9 enabled */
/* A/D conversion hardware trigger select (TxSEL8) */
#define _ADC_SG_HW_TRIGGER_FACTOR_8               (0x00000100UL) /* Hardware trigger factor 8 enabled */
/* A/D conversion hardware trigger select (TxSEL7) */
#define _ADC_SG_HW_TRIGGER_FACTOR_7               (0x00000080UL) /* Hardware trigger factor 7 enabled */
/* A/D conversion hardware trigger select (TxSEL6) */
#define _ADC_SG_HW_TRIGGER_FACTOR_6               (0x00000040UL) /* Hardware trigger factor 6 enabled */
/* A/D conversion hardware trigger select (TxSEL5) */
#define _ADC_SG_HW_TRIGGER_FACTOR_5               (0x00000020UL) /* Hardware trigger factor 5 enabled */
/* A/D conversion hardware trigger select (TxSEL4) */
#define _ADC_SG_HW_TRIGGER_FACTOR_4               (0x00000010UL) /* Hardware trigger factor 4 enabled */
/* A/D conversion hardware trigger select (TxSEL3) */
#define _ADC_SG_HW_TRIGGER_FACTOR_3               (0x00000008UL) /* Hardware trigger factor 3 enabled */
/* A/D conversion hardware trigger select (TxSEL2) */
#define _ADC_SG_HW_TRIGGER_FACTOR_2               (0x00000004UL) /* Hardware trigger factor 2 enabled */
/* A/D conversion hardware trigger select (TxSEL1) */
#define _ADC_SG_HW_TRIGGER_FACTOR_1               (0x00000002UL) /* Hardware trigger factor 1 enabled */
/* A/D conversion hardware trigger select (TxSEL0) */
#define _ADC_SG_HW_TRIGGER_EXTERNAL_PIN           (0x00000001UL) /* External trigger pin enabled */

/*
    Self-Diagnosis Control Register 0 (ADCAnDGCTL0)
*/
/* Self-diagnostic voltage level select (PSEL[2:0]) */
#define _ADC_SELF_DIAG_VOLTAGE_LEVEL_0            (0x00000000UL) /* Hi-z to DIAGOUT0, Hi-z to DIAGOUT1,
                                                                    Hi-z to DIAGOUT2, Hi-z to ADDIAGOUT */
#define _ADC_SELF_DIAG_VOLTAGE_LEVEL_1            (0x00000001UL) /* 1/3AnVREF to DIAGOUT0, 1/2AnVREF to DIAGOUT1,
                                                                    2/3AnVREF to DIAGOUT2, AnVSS to ADDIAGOUT */
#define _ADC_SELF_DIAG_VOLTAGE_LEVEL_2            (0x00000002UL) /* 1/2AnVREF to DIAGOUT0, 2/3AnVREF to DIAGOUT1,
                                                                    1/3AnVREF to DIAGOUT2, 1/3AnVREF to ADDIAGOUT */
#define _ADC_SELF_DIAG_VOLTAGE_LEVEL_3            (0x00000003UL) /* 2/3AnVREF to DIAGOUT0, 1/3AnVREF to DIAGOUT1,
                                                                    1/2AnVREF to DIAGOUT2, 1/2AnVREF to ADDIAGOUT */
#define _ADC_SELF_DIAG_VOLTAGE_LEVEL_4            (0x00000004UL) /* Hi-z to DIAGOUT0, Hi-z to DIAGOUT1,
                                                                    Hi-z to DIAGOUT2, 2/3AnVREF to ADDIAGOUT */
#define _ADC_SELF_DIAG_VOLTAGE_LEVEL_5            (0x00000005UL) /* 1/3AnVREF to DIAGOUT0, 1/3AnVREF to DIAGOUT1,
                                                                    1/3AnVREF to DIAGOUT2, AnVREF to ADDIAGOUT */
#define _ADC_SELF_DIAG_VOLTAGE_LEVEL_6            (0x00000006UL) /* 1/2AnVREF to DIAGOUT0, 1/2AnVREF to DIAGOUT1,
                                                                    1/2AnVREF to DIAGOUT2, AnVREF to ADDIAGOUT */
#define _ADC_SELF_DIAG_VOLTAGE_LEVEL_7            (0x00000007UL) /* 2/3AnVREF to DIAGOUT0, 2/3AnVREF to DIAGOUT1,
                                                                    2/3AnVREF to DIAGOUT2, AnVREF to ADDIAGOUT */

/*
    Self-Diagnosis Control Register 1 (ADCAnDGCTL1)
*/
/* Self-diagnostic channel select (CDG[15]) */
#define _ADC_SELF_DIAG_CH15_SEL_ANI15             (0x00000000UL) /* ANIn15 is selected */
#define _ADC_SELF_DIAG_CH15_SEL_DIAGOUT0          (0x00008000UL) /* DIAGOUT0 is selected */
/* Self-diagnostic channel select (CDG[14]) */
#define _ADC_SELF_DIAG_CH14_SEL_ANI14             (0x00000000UL) /* ANIn14 is selected */
#define _ADC_SELF_DIAG_CH14_SEL_DIAGOUT2          (0x00004000UL) /* DIAGOUT2 is selected */
/* Self-diagnostic channel select (CDG[13]) */
#define _ADC_SELF_DIAG_CH13_SEL_ANI13             (0x00000000UL) /* ANIn13 is selected */
#define _ADC_SELF_DIAG_CH13_SEL_DIAGOUT1          (0x00002000UL) /* DIAGOUT1 is selected */
/* Self-diagnostic channel select (CDG[12]) */
#define _ADC_SELF_DIAG_CH12_SEL_ANI12             (0x00000000UL) /* ANIn12 is selected */
#define _ADC_SELF_DIAG_CH12_SEL_DIAGOUT0          (0x00001000UL) /* DIAGOUT0 is selected */
/* Self-diagnostic channel select (CDG[11]) */
#define _ADC_SELF_DIAG_CH11_SEL_ANI11             (0x00000000UL) /* ANIn11 is selected */
#define _ADC_SELF_DIAG_CH11_SEL_DIAGOUT2          (0x00000800UL) /* DIAGOUT2 is selected */
/* Self-diagnostic channel select (CDG[10]) */
#define _ADC_SELF_DIAG_CH10_SEL_ANI10             (0x00000000UL) /* ANIn10 is selected */
#define _ADC_SELF_DIAG_CH10_SEL_DIAGOUT1          (0x00000400UL) /* DIAGOUT1 is selected */
/* Self-diagnostic channel select (CDG[9]) */
#define _ADC_SELF_DIAG_CH09_SEL_ANI09             (0x00000000UL) /* ANIn09 is selected */
#define _ADC_SELF_DIAG_CH09_SEL_DIAGOUT0          (0x00000200UL) /* DIAGOUT0 is selected */
/* Self-diagnostic channel select (CDG[8]) */
#define _ADC_SELF_DIAG_CH08_SEL_ANI08             (0x00000000UL) /* ANIn08 is selected */
#define _ADC_SELF_DIAG_CH08_SEL_DIAGOUT2          (0x00000100UL) /* DIAGOUT2 is selected */
/* Self-diagnostic channel select (CDG[7]) */
#define _ADC_SELF_DIAG_CH07_SEL_ANI07             (0x00000000UL) /* ANIn07 is selected */
#define _ADC_SELF_DIAG_CH07_SEL_DIAGOUT1          (0x00000080UL) /* DIAGOUT1 is selected */
/* Self-diagnostic channel select (CDG[6]) */
#define _ADC_SELF_DIAG_CH06_SEL_ANI06             (0x00000000UL) /* ANIn06 is selected */
#define _ADC_SELF_DIAG_CH06_SEL_DIAGOUT0          (0x00000040UL) /* DIAGOUT0 is selected */
/* Self-diagnostic channel select (CDG[5]) */
#define _ADC_SELF_DIAG_CH05_SEL_ANI05             (0x00000000UL) /* ANIn05 is selected */
#define _ADC_SELF_DIAG_CH05_SEL_DIAGOUT2          (0x00000020UL) /* DIAGOUT2 is selected */
/* Self-diagnostic channel select (CDG[4]) */
#define _ADC_SELF_DIAG_CH04_SEL_ANI04             (0x00000000UL) /* ANIn04 is selected */
#define _ADC_SELF_DIAG_CH04_SEL_DIAGOUT1          (0x00000010UL) /* DIAGOUT1 is selected */
/* Self-diagnostic channel select (CDG[3]) */
#define _ADC_SELF_DIAG_CH03_SEL_ANI03             (0x00000000UL) /* ANIn03 is selected */
#define _ADC_SELF_DIAG_CH03_SEL_DIAGOUT0          (0x00000008UL) /* DIAGOUT0 is selected */
/* Self-diagnostic channel select (CDG[2]) */
#define _ADC_SELF_DIAG_CH02_SEL_ANI02             (0x00000000UL) /* ANIn02 is selected */
#define _ADC_SELF_DIAG_CH02_SEL_DIAGOUT2          (0x00000004UL) /* DIAGOUT2 is selected */
/* Self-diagnostic channel select (CDG[1]) */
#define _ADC_SELF_DIAG_CH01_SEL_ANI01             (0x00000000UL) /* ANIn01 is selected */
#define _ADC_SELF_DIAG_CH01_SEL_DIAGOUT1          (0x00000002UL) /* DIAGOUT1 is selected */
/* Self-diagnostic channel select (CDG[0]) */
#define _ADC_SELF_DIAG_CH00_SEL_ANI00             (0x00000000UL) /* ANIn00 is selected */
#define _ADC_SELF_DIAG_CH00_SEL_DIAGOUT0          (0x00000001UL) /* DIAGOUT0 is selected */

/*
    Pull Down Control Register 1 (ADCAnPDCTL1)
*/
/* Pull down enable control of ANIn15 (PDNA[15]) */
#define _ADC_ANI15_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI15_PULLDOWN_ENABLE                (0x00008000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn14 (PDNA[14]) */
#define _ADC_ANI14_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI14_PULLDOWN_ENABLE                (0x00004000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn13 (PDNA[13]) */
#define _ADC_ANI13_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI13_PULLDOWN_ENABLE                (0x00002000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn12 (PDNA[12]) */
#define _ADC_ANI12_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI12_PULLDOWN_ENABLE                (0x00001000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn11 (PDNA[11]) */
#define _ADC_ANI11_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI11_PULLDOWN_ENABLE                (0x00000800UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn10 (PDNA[10]) */
#define _ADC_ANI10_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI10_PULLDOWN_ENABLE                (0x00000400UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn09 (PDNA[9]) */
#define _ADC_ANI09_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI09_PULLDOWN_ENABLE                (0x00000200UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn08 (PDNA[8]) */
#define _ADC_ANI08_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI08_PULLDOWN_ENABLE                (0x00000100UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn0 (PDNA[7]) */
#define _ADC_ANI07_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI07_PULLDOWN_ENABLE                (0x00000080UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn06 (PDNA[6]) */
#define _ADC_ANI06_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI06_PULLDOWN_ENABLE                (0x00000040UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn05 (PDNA[5]) */
#define _ADC_ANI05_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI05_PULLDOWN_ENABLE                (0x00000020UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn04 (PDNA[4]) */
#define _ADC_ANI04_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI04_PULLDOWN_ENABLE                (0x00000010UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn03 (PDNA[3]) */
#define _ADC_ANI03_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI03_PULLDOWN_ENABLE                (0x00000008UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn02 (PDNA[2]) */
#define _ADC_ANI02_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI02_PULLDOWN_ENABLE                (0x00000004UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn01 (PDNA[1]) */
#define _ADC_ANI01_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI01_PULLDOWN_ENABLE                (0x00000002UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn00 (PDNA[0]) */
#define _ADC_ANI00_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI00_PULLDOWN_ENABLE                (0x00000001UL) /* An on-chip pull-down resistor is connected */

/*
    Pull Down Control Register 2 (ADCAnPDCTL2)
*/
/* Pull down enable control of ANIn35 (PDNB[19]) */
#define _ADC_ANI35_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI35_PULLDOWN_ENABLE                (0x00080000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn34 (PDNB[18]) */
#define _ADC_ANI34_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI34_PULLDOWN_ENABLE                (0x00040000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn33 (PDNB[17]) */
#define _ADC_ANI33_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI33_PULLDOWN_ENABLE                (0x00020000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn32 (PDNB[16]) */
#define _ADC_ANI32_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI32_PULLDOWN_ENABLE                (0x00010000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn31 (PDNB[15]) */
#define _ADC_ANI31_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI31_PULLDOWN_ENABLE                (0x00008000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn30 (PDNB[14]) */
#define _ADC_ANI30_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI30_PULLDOWN_ENABLE                (0x00004000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn29 (PDNB[13]) */
#define _ADC_ANI29_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI29_PULLDOWN_ENABLE                (0x00002000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn28 (PDNB[12]) */
#define _ADC_ANI28_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI28_PULLDOWN_ENABLE                (0x00001000UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn27 (PDNB[11]) */
#define _ADC_ANI27_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI27_PULLDOWN_ENABLE                (0x00000800UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn26 (PDNB[10]) */
#define _ADC_ANI26_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI26_PULLDOWN_ENABLE                (0x00000400UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn25 (PDNB[9]) */
#define _ADC_ANI25_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI25_PULLDOWN_ENABLE                (0x00000200UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn24 (PDNB[8]) */
#define _ADC_ANI24_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI24_PULLDOWN_ENABLE                (0x00000100UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn23 (PDNB[7]) */
#define _ADC_ANI23_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI23_PULLDOWN_ENABLE                (0x00000080UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn22 (PDNB[6]) */
#define _ADC_ANI22_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI22_PULLDOWN_ENABLE                (0x00000040UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn21 (PDNB[5]) */
#define _ADC_ANI21_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI21_PULLDOWN_ENABLE                (0x00000020UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn20 (PDNB[4]) */
#define _ADC_ANI20_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI20_PULLDOWN_ENABLE                (0x00000010UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn19 (PDNB[3]) */
#define _ADC_ANI19_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI19_PULLDOWN_ENABLE                (0x00000008UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn18 (PDNB[2]) */
#define _ADC_ANI18_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI18_PULLDOWN_ENABLE                (0x00000004UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn17 (PDNB[1]) */
#define _ADC_ANI17_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI17_PULLDOWN_ENABLE                (0x00000002UL) /* An on-chip pull-down resistor is connected */
/* Pull down enable control of ANIn16 (PDNB[0]) */
#define _ADC_ANI16_PULLDOWN_DISABLE               (0x00000000UL) /* An on-chip pull-down resistor is not connected */
#define _ADC_ANI16_PULLDOWN_ENABLE                (0x00000001UL) /* An on-chip pull-down resistor is connected */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _ADC0_VCHANNEL_DATA_BASE                  (0xFFF20100UL) /* ADCA0DRj register bass address */
#define _ADC1_VCHANNEL_DATA_BASE                  (0xFFD6D100UL) /* ADCA1DRj register bass address */
#define _ADC0_PWD_VCHANNEL_DATA_BASE              (0xFFF2017AUL) /* ADCA0PWDTSNDRH register bass address */
#define _ADC1_PWD_VCHANNEL_DATA_BASE              (0xFFD6D17AUL) /* ADCA1PWDTSNDRH register bass address */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
