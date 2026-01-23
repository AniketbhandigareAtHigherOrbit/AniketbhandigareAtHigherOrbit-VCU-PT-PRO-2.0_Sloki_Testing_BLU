/******************************************************************************
 *    FILENAME    : fee_adapt.h
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki       10/01/2019		   Initial version
 ******************************************************************************
*/ 
#ifndef    _FEE_ADAPT_H_
#define    _FEE_ADAPT_H_



#include  <stdbool.h>
//#include "uds_conf.h"
#include "diag_typedefs.h"
//#include "app_typedef.h"
//#include "diag_adapt.h"
#include "diag_sys_conf.h"

#if(TRUE == DIAG_CONF_FM_SUPPORTED)
	extern U2 u2_DTC_Entry_Size;
#endif

//extern void WriteFlash_Adapt(uint32_t flashAddr,  uint32_t sourceData);

//extern bool WRITE_STATUS_Adapt();

#if(TRUE == DIAG_CONF_FM_SUPPORTED)
	/**
	*    @brief  Read data from Flash to buffer
	*
	*    @param  Message name
	*    @param  Pointer to buffer
	*    @return None
	*/
	extern  void FEE_Read(uint8_t EntryName_u8, uint8_t* buf_pu8);


	/**
	*    @brief  Write data from Flash to buffer
	*
	*    @param  Message name
	*    @param  Pointer to buffer
	*    @return None
	*/
	extern void FEE_Write(uint8_t EntryName_u8, uint8_t* buf_pu8);
#endif

#if(TRUE == DIAG_BOOT_LOADER_SUPPORTED)
	extern bool Flash_Pattern_Write(uint32_t address,uint32_t data);
#endif

#endif
