/******************************************************************************
 *    FILENAME    : can_callback.c
 *    DESCRIPTION : description contain callback function for data backup from can
 ******************************************************************************
 * Revision history
 *
 * Ver Author       Date               Description
 * 1   Sandeep     12/11/2020		   Initial version
 ******************************************************************************
*/

#include "can_callback.h"

hal2cil_fptr_t CAN_HAL2CIL_FnPtr = NULL;

void DRV_CAN_Reg_CilCallBack(hal2cil_fptr_t hal2cil_fptr)
{
	CAN_HAL2CIL_FnPtr = hal2cil_fptr;
	return;
}

void DRV_HAL2CIL_CallBack(uint8_t IDE_u8, uint8_t DLC_u8, uint8_t CAN_Module_u8, uint32_t CAN_ID_u32,uint8_t *DataBytes_au8)
{
	if (CAN_HAL2CIL_FnPtr!=NULL)/* != NULL*/
	{
		CAN_HAL2CIL_FnPtr(IDE_u8, DLC_u8, CAN_Module_u8, CAN_ID_u32, DataBytes_au8);
	}
}
