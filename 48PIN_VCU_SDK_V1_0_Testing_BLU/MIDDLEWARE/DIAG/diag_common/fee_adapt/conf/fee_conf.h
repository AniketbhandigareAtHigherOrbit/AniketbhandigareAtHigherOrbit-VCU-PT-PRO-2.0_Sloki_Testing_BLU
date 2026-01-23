/******************************************************************************
 *    FILENAME    : fee_conf.h
 *    DESCRIPTION : EEPROM configuration 
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/ 

#ifndef _FEE_CONF_H_
#define _FEE_CONF_H_

#include "diag_typedefs.h"
//#include "app_typedef.h"
#include "fee_adapt.h"
#include "diag_sys_conf.h"
#include "fm_conf.h"
#if(TRUE == DIAG_BOOT_LOADER_SUPPORTED)
#define APP_PATTERN					0x55AA55AA
#define BOOT_PATTERN				0xAA55AA55




/* Address of  the Flash from where the application starts executing */
/* Rule: Set BOOTLOADER_FLASH_BASE_ADDRESS to _RESET_ADDR value of application linker script*/
#define APP_START_ADDRESS			0x0000E000 /*This is application  memory address*/
#define APP_SIZE					0x0000B000
#define APP_END_ADDRESS     		(APP_START_ADDRESS + (APP_SIZE - 1))
#define BOOT_START_ADDRESS			0x00000000 /*This application boot memory*/
#define CRC_RESET_VALUE             0xFFFFFFFF
//#define DRIVE_VALIDATION_START_ADDRESS    APP_END_ADDRESS
#define DRIVE_VALIDATION_START_ADDRESS    (APP_START_ADDRESS - 0x2000)
//#define DRIVE_VALIDATION_END_ADDRESS      (DRIVE_CRC_END_ADDRESS)
#define DRIVE_VALIDATION_END_ADDRESS      (APP_START_ADDRESS - 0x01)

#endif

#if(TRUE == DIAG_CONF_FM_SUPPORTED)
/* Structure declaration for EEPROM layout */

typedef const struct
{
    uint32_t      FEE_MsgName_u32;    /* Message Name */
    uint32_t      StartAddress_u32;   /* Starting address of the message */
    uint16_t      Size_u16;           /* Length of the data to be stored in memory */
}FEE_AddrConfig_St_t;


typedef enum
{
  FEE_FM_L2_ENTRY1,
  FEE_FM_L2_ENTRY2,
  FEE_FM_L2_ENTRY3,
  FEE_FM_L2_ENTRY4,
  FEE_FM_L2_ENTRY5,
  FEE_FM_L2_ENTRY6,
  FEE_FM_L2_ENTRY7,
  FEE_FM_L2_ENTRY8,
  FEE_FM_L2_ENTRY9,
  FEE_FM_L2_ENTRY10,
  FEE_FM_COMMON_DATA,
  FEE_FM_RDYRESULTS,
  FEE_FM_TFSLC,
  TOTAL_FEE_SIGNAL_E 
}FEE_EntryName_En_t;

typedef const struct
{
  uint16_t Entry_Name_u16;
  uint16_t FEE_Nvm_Param_u16;
}FEE_FMInfo_St_t;


#define FM_FEE_START_ADDRESS (4160U)
#endif

#if(TRUE == DIAG_CONF_FM_SUPPORTED)
  	extern const FEE_AddrConfig_St_t FEE_AddrConfig_aSt[TOTAL_FEE_SIGNAL_E];
    extern const FEE_FMInfo_St_t FEE_FM_Config_aSt[TOTAL_FM_SIGNAL_E];
#endif




#endif
