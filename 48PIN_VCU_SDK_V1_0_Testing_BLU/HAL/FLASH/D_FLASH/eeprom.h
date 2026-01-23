///*******************************************************************************
//|-------------------------------------------------------------------------------
//|   FILE DESCRIPTION
//|-------------------------------------------------------------------------------
//|    File           : eeprom.h
//|    Project        :  OSM_VCU_ASW RH850/F1KM S1-80pin
//|    Description    : The file implements application for accessing the eeprom.
//|-------------------------------------------------------------------------------
//|
//|-------------------------------------------------------------------------------
//|               A U T H O R   I D E N T I T Y
//|-------------------------------------------------------------------------------
//|   Date             Name                      Company
//| --------     ---------------------     ---------------------------------------
//| 18/08/2022       Jeevan Jestin N             Sloki Software Technologies Pvt Ltd
//|-------------------------------------------------------------------------------
//|******************************************************************************/
//#ifndef EEPROM_H
//#define EEPROM_H
///*******************************************************************************
// *  HEARDER FILE INCLUDES
// ******************************************************************************/
//#include "r_cg_macrodriver.h"
//#include "app_typedef.h"
////#include "r_typedefs.h"
///*******************************************************************************
// *  MACRO DEFNITION
// ******************************************************************************/
//#define MAXIMUM_FDL_BLOCK       1023
//#define SIZE_OF_ONE_BLOCK       16
//#define FDL_BLOCK_START_ADDRS   0xFF200000
//#define BYTE_SIZE_OF_BLOCK      (64) /* 1 block is 64 bytes*/
//#define WORD_SIZE_OF_BLOCK      (16) /* 1 block is 16 word */
//#define TOTAL_BLOCK             (1024)


//#define MEMORY_ACCESS_SIZE          (0x04)
///*******************************************************************************
// *  STRUCTURES, ENUMS and TYPEDEFS
// ******************************************************************************/
//#pragma pack(1)
//typedef struct 
//{
//    uint16_t BlockStartPos_u16;
//    uint16_t BlockEndPos_u16;
//    uint16_t NumOfBlock_u16;
//    uint16_t NumOfbytes_u16;
//    bool BlankCheckDone_b;

//}EEprom_St_t;
//#pragma unpack

///*******************************************************************************
// *  EXTERN GLOBAL VARIABLES
// ******************************************************************************/

///*******************************************************************************
// *  EXTERN FUNCTION
// ******************************************************************************/
//extern bool DFlash_Init(void);
//extern bool FDL_Read(uint16_t ReadVirtualAddr_u16,uint16_t DataSize_u16,uint8_t *DataBuff_u8);
//extern bool FDL_write(uint16_t WriteVirtualAddr_u16,uint16_t DataSize_u16,uint8_t *DataBuff_u8);
//extern void FDL_erase(uint16_t ReadVirtualAddr_u16);
//extern void fun_fdl_write(uint16_t ReadVirtualAddr_u16,uint16_t WriteVirtualAddr_u16, uint16_t DataSize_u16, uint8_t*  DataBuff_u8);
//extern void fun_fdl_Read(uint16_t ReadVirtualAddr_u16,uint16_t WriteVirtualAddr_u16, uint16_t DataSize_u16, uint8_t*  DataBuff_u8);
//#endif
///*---------------------- End of File -----------------------------------------*/