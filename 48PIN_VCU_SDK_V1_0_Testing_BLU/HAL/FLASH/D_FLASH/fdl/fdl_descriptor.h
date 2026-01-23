/*********************************************************************************************************************
 * File Name     : $Source: fdl_descriptor.h $
 * Mod. Revision : $Revision: 1.2 $
 * Mod. Date     : $Date: 2019/04/26 11:34:57JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : FDL run-time configuration descriptor variable related defines. 
 *                 To be configured according to the application needs
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

#ifndef FDL_DESCRIPTOR_H
#define FDL_DESCRIPTOR_H

/*********************************************************************************************************************
    User changeable defines
 *********************************************************************************************************************/

    /*****************************************************************************************************************
     *  Important definitions for run-time configuration of the FDL: 
     *   - Frequency -
     *****************************************************************************************************************/
    /* The Flash programming hardware is provided with a clock, derived from the CPU subsystem frequency. Check that 
       the frequency is correct as this has an impact on the programming quality and performance! */
    #define CPU_FREQUENCY_MHZ      120                              /**< CPU frequency in MHz */

    /*****************************************************************************************************************
     *  Important definitions for run-time configuration of the FDL: 
     *   - EEL/FDL Pool -
     *****************************************************************************************************************/
    /* The physical erase unit of the Data Flash is 64Byte. 
       The Renesas EEL works with a ring buffer consisting of ring buffer (virtual) blocks that merge a certain number 
       of physical blocks.
       E.g. virtual block size of 2kB equals 32 physical blocks of 64Bytes --> EEL_VIRTUALBLOCKSIZE = 32
            virtual block size of 4kB equals 64 physical blocks of 64Bytes --> EEL_VIRTUALBLOCKSIZE = 64
       
       Note: If the Renesas EEL is not used, an alignment is not necessary "EEL_VIRTUALBLOCKSIZE" need not be defined 
       and the pools start and size definitions can be set free to the applicaiton needs */
    #define EEL_VIRTUALBLOCKSIZE    64u                     

    #define FDL_POOL_SIZE           (16u * EEL_VIRTUALBLOCKSIZE)    /**< Number of Data Flash blocks, accessible by 
                                                                         the FDL. Typically it is the complete 
                                                                         no. of available Data Flash blocks */    
    #define EEL_POOL_START         0  //(1u * EEL_VIRTUALBLOCKSIZE)     /**< 1st block of the EEL pool */
    #define EEL_POOL_SIZE          0  // (6u * EEL_VIRTUALBLOCKSIZE)     /**< no. of blocks for the EEL pool */     


/*********************************************************************************************************************
 * Even if possible, this section should not b echanged by the user
 *********************************************************************************************************************/

    /*****************************************************************************************************************
     *  Descriptor variable declaration
     *****************************************************************************************************************/
    extern const r_fdl_descriptor_t sampleApp_fdlConfig_enu;           /**< FDL descriptor variable */


/*********************************************************************************************************************/
#endif  /* #ifndef FDL_DESCRIPTOR_H */
