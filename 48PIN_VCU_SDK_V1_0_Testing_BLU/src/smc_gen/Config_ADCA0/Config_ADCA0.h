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
* File Name        : Config_ADCA0.h
* Component Version: 1.5.0
* Device(s)        : R7F701687
* Description      : This file implements device driver for Config_ADCA0.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_ad.h"

#ifndef CFG_Config_ADCA0_H
#define CFG_Config_ADCA0_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

#define _ADC0_UPPER_LIMIT_TABLE0                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE0                  (0x00000000UL)
#define _ADC0_UPPER_LIMIT_TABLE1                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE1                  (0x00000000UL)
#define _ADC0_UPPER_LIMIT_TABLE2                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE2                  (0x00000000UL)
#define _ADC0_UPPER_LIMIT_TABLE3                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE3                  (0x00000000UL)
#define _ADC0_UPPER_LIMIT_TABLE4                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE4                  (0x00000000UL)
#define _ADC0_UPPER_LIMIT_TABLE5                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE5                  (0x00000000UL)
#define _ADC0_UPPER_LIMIT_TABLE6                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE6                  (0x00000000UL)
#define _ADC0_UPPER_LIMIT_TABLE7                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE7                  (0x00000000UL)
#define _ADC0_STABILIZATION_TIME_TABLE0           (0x00000008UL)
#define _ADC0_STABILIZATION_TIME_TABLE1           (0x00000008UL)
#define _ADC0_STABILIZATION_TIME_TABLE2           (0x00000008UL)
#define _ADC0_STABILIZATION_TIME_TABLE3           (0x00000008UL)
#define _ADC0_STABILIZATION_TIME_TABLE4           (0x00000008UL)
#define _ADC0_STABILIZATION_TIME_TABLE5           (0x00000008UL)
#define _ADC0_STABILIZATION_TIME_TABLE6           (0x00000008UL)
#define _ADC0_STABILIZATION_TIME_TABLE7           (0x00000008UL)
#define _ADC0_SG1_START_POINTER                   (0x00000000UL)
#define _ADC0_SG1_END_POINTER                     (0x00000007UL)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_ADCA0_Create(void);
void R_Config_ADCA0_Halt(void);
void R_Config_ADCA0_SelfDiagnostic_VoltageCircuitOn(void);
void R_Config_ADCA0_SelfDiagnostic_VoltageCircuitOff(void);
void R_Config_ADCA0_ScanGroup1_Start(void);
void R_Config_ADCA0_ScanGroup1_OperationOn(void);
void R_Config_ADCA0_ScanGroup1_OperationOff(void);
MD_STATUS R_Config_ADCA0_ScanGroup1_GetResult(uint16_t * const buffer, uint8_t buffer_size);
void R_Config_ADCA0_Create_UserInit(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
