#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * Library       : Data Flash Access Library for Renesas RH850 devices
 *
 * File Name     : $Source: r_fdl_types.h $
 * Lib. Version  : $RH850_FDL_LIB_VERSION_T01: V2.13 $
 * Mod. Revision : $Revision: 1.20 $
 * Mod. Date     : $Date: 2019/04/19 19:07:12JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : User interface type definitions
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

#ifndef R_FDL_TYPES_H
#define R_FDL_TYPES_H

#include "r_typedefs.h"
#include "app_typedef.h"

/*********************************************************************************************************************
 * Global type definitions
 *********************************************************************************************************************/
/* ---------------- Configuration ------------------------------------------ */
/**
   \struct r_fdl_descriptor_t
   FDL descriptor variable definition.
*/
typedef struct R_FDL_DESCRIPTOR_T
{
    uint16_t    cpuFrequencyMHz_u16;        /**< Flash hardware frequency in MHz */
    uint16_t    fdlPoolSize_u16;            /**< FDL pool size in no. of blocks */
    uint16_t    eelPoolStart_u16;           /**< 1st block of the EEL pool */
    uint16_t    eelPoolSize_u16;            /**< Last block of the EEL pool */
} r_fdl_descriptor_t;

typedef unsigned char                       pfdl_u08;  //
typedef unsigned int                        rfdl_u16;
typedef unsigned long int                   pfdl_u32;

/* ---------------- Operation ---------------------------------------------- */
/**
   \enum r_fdl_status_t
   FDL status return values
*/
typedef enum R_FDL_STATUS_T
{
    R_FDL_OK                    = 0,        /**< Operation terminated successfully */
    R_FDL_BUSY                  = 1,        /**< Operation is still ongoing */
    R_FDL_SUSPENDED             = 2,        /**< Flash operation is suspended */
    R_FDL_ERR_CONFIGURATION     = 3,        /**< The FDL configuration (descriptor) was wrong */
    R_FDL_ERR_PARAMETER         = 4,        /**< A parameter of the FDL function call was wrong */
    R_FDL_ERR_PROTECTION        = 5,        /**< Operation blocked due to wrong parameters */
    R_FDL_ERR_REJECTED          = 6,        /**< Flow error, e.g. another operation is still busy */
    R_FDL_ERR_WRITE             = 7,        /**< Flash write error */
    R_FDL_ERR_ERASE             = 8,        /**< Flash erase error */
    R_FDL_ERR_BLANKCHECK        = 9,        /**< Flash blank check error */
    R_FDL_ERR_COMMAND           = 10,       /**< Unknown command */
    R_FDL_ERR_ECC_SED           = 11,       /**< Single bit error detected by ECC */
    R_FDL_ERR_ECC_DED           = 12,       /**< Double bit error detected by ECC */
    R_FDL_ERR_INTERNAL          = 13,       /**< Library internal error */
    R_FDL_CANCELLED             = 14        /**< Flash operation is cancelled */
} r_fdl_status_t;

/**
   \enum r_fdl_accessType_t
   FDL operations originator defines.
   Set by the user when starting an FDL operation.
   Reset to ..._NONE by the library on operation end.
*/
typedef enum R_FDL_ACCESS_TYPE_T
{
    R_FDL_ACCESS_NONE           = 0,        /**< FDL internal value. Not used by the application */
    R_FDL_ACCESS_USER           = 1,        /**< User application wants to execute an FDL operation */
    R_FDL_ACCESS_EEL            = 2         /**< The EEL wants to execute an FDL operation */
} r_fdl_accessType_t;

/**
   \enum r_fdl_command_t
   FDL operation commands
*/
typedef enum R_FDL_COMMAND_T
{
    R_FDL_CMD_ERASE             = 0,        /**< Flash block erase (Multiple blocks) */
    R_FDL_CMD_WRITE             = 1,        /**< Flash write (Multiple words) */
    R_FDL_CMD_BLANKCHECK        = 2,        /**< Flash blank check command (Multiple words) */
    R_FDL_CMD_READ              = 3,        /**< Flash read with ECC error polling (Multiple words) */
    /* Number 4 is a removed number. It was R_FDL_CMD_WRITE16B. */
    R_FDL_CMD_PREPARE_ENV       = 5         /**< Prepare Flash environment */
} r_fdl_command_t;


/**
   \struct r_fdl_request_t
   FDL operations request structure, required for R_FDL_Execute
*/
typedef volatile struct R_FDL_REQUEST_T
{
    r_fdl_command_t     command_enu;        /**< FDL operation, e.g. R_FDL_CMD_ERASE */
    uint32_t            bufAddr_u32;        /**< Write operation: Source data address */
    uint32_t            idx_u32;            /**< Write, blank check, read operation: byte index (address)\n
                                                 Erase operation: block number of the first block to erase */
    uint16_t            cnt_u16;            /**< Write operation: Number of words to write \n
                                                 Erase operation: Number of blocks to erase \n
                                                 Blank Check operation: Number of words to check \n
                                                 Read operation: Number of words to read */
    r_fdl_accessType_t  accessType_enu;     /**< Data Flash access originator: \n
                                                 R_FDL_ACCESS_USER: User code \n
                                                 R_FDL_ACCESS_EEL: EEL library */
    r_fdl_status_t      status_enu;         /**< status return value of the FDL */
} r_fdl_request_t;

/*********************************************************************************************************************/
#endif /* ifndef R_FDL_TYPES_H */

