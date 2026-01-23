/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File          : crc_util.h
|    Project      : MIL_PBL_CV
|    Description    : This file has the structure for generator polynomial and the CRC16 calculation
 *                  function for specified memory blocks .
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date             Name                        Company
| ----------     ---------------     -----------------------------------
| 31/07/2024       Manikandan S        Sloki Software Technologies LLP
|-------------------------------------------------------------------------------
|******************************************************************************/

 #ifndef __CRC_CRC32_H
 #define __CRC_CRC32_H

 /*
*******************************************************************************
* Includes
*******************************************************************************
*/
#include "diag_typedefs.h"
#include "sys_typedefs.h"
/*
 **************************************************************************************************
 *    Defines
 **************************************************************************************************
 */
#define TABLE_SIZE 256
// #define POLY 0x1021
// #define INIT_CRC 0xFFFF
 /*
 **************************************************************************************************
 *    Variable declaration
 **************************************************************************************************
 */
 
 /*
 **************************************************************************************************
 *    Function Prototype
 **************************************************************************************************
 */
/**---------
 *  @brief     :Function calc_crc32 calculates the crc32 for the continuous memory block of 
 *            given size.It calculates the new crc32 value based on the older crc32 value.
 *
 *  @param   Crc_Data_pu8 - The starting address of the memory block
 *           Crc_Size_u32 - size of the memory block
 *           Crc_Last_Crc_su32 - previous value of crc32
 *
 *  @return  The crc32 value calculated - It returns crc32 value calculated so far.
 *-----------
 */
 uint32_t Crc_CalculateCRC32(const uint8_t *Crc_Data_pu8, uint32_t Crc_Size_u32, uint32_t Crc_Last_Crc32_su32);

#endif

/* *****************************************************************************
 End of File
 */

