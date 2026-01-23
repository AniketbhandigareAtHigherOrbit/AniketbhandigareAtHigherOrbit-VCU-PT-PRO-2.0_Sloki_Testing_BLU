/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : rfdl_user.h
|    Project        :  OSM_VCU_ASW VCU
|    Module         : Data flash
|    Description    :
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date              Name                        Company
| ----------     ---------------     -----------------------------------
|  15-01-2024        Nishanth S                      Sloki Software Technologies Pvt Ltd
|-------------------------------------------------------------------------------
|******************************************************************************/
#ifndef RFDL_USER_H
#define RFDL_USER_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
/* Data flash library */
// #include "pfdl.h"                /* Library header file */
// #include "pfdl_types.h"          /* Library header file */
#include "app_typedef.h"
//#include "pfdl_user"
#include "r_fdl.h"
//#include "eeprom.h"
#include "sys_typedefs.h"
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Basic data */
#define TOTAL_FDL_BLOCKS			8		/* Total Bocks in Data Flash */
#define EACH_FDL_BLOCK_SIZE   			0x400	  	/* Standard block size */
#define FDL_WRITE_BUFFER_SIZE	   		710      		/* Write data size */
#define FDL_READ_BUFFER_SIZE	   		50     		/* Write data size */


/* PFDL initial settings */
#define FDL_FRQUENCY		      		32      	/* Sets the frequency (32 MHz) */
#define FDL_VOLTAGE		      		0x00    	/* Sets the voltage mode (full-speed mode) */


/* default access code */
//#define CPU_FREQUENCY_MHZ (120)
///* FDL pool will use 512 blocks * 64 bytes = 32KB, no EEL pool */
//#define FDL_POOL_SIZE (16u * 64u)
//#define EEL_POOL_START (0)
//#define EEL_POOL_SIZE (0)


// #define MAXIMUM_FDL_BLOCK       1023
// #define SIZE_OF_ONE_BLOCK       16
// #define FDL_BLOCK_START_ADDRS   0xFF200000
// #define BYTE_SIZE_OF_BLOCK      (64) /* 1 block is 64 bytes*/
// #define WORD_SIZE_OF_BLOCK      (16) /* 1 block is 16 word */
// #define TOTAL_BLOCK             (1024)


// #define MEMORY_ACCESS_SIZE          (0x04)



typedef struct 
{
    uint16_t BlockStartPos_u16;
    uint16_t BlockEndPos_u16;
    uint16_t NumOfBlock_u16;
    uint16_t NumOfbytes_u16;
    bool BlankCheckDone_b;

}EEprom_St_tt;

/***********************************************************************************************************************
Structures and Enums
***********************************************************************************************************************/


/***********************************************************************************************************************
Export Variables and Functions
***********************************************************************************************************************/

extern uint32_t        dubWriteBuffer[ FDL_WRITE_BUFFER_SIZE ];
extern uint32_t        dubReadBuffer[ FDL_READ_BUFFER_SIZE];
extern uint32_t        dubReadtempBuffer[64];

r_fdl_request_t 	r_pfdl_samFdlStart ( void );  /* pfdl initialization processing */
void          	r_pfdl_samFdlEnd   ( void );  /* pfdl end processing            */
extern void 		FDL_Erase(rfdl_u16 Block_Number, rfdl_u16 Total_Blocks);
extern void FDL_Read(rfdl_u16 Block_Number, rfdl_u16 Position_at_Block, rfdl_u16 Num_Of_Bytes);
extern void     FDL_ODO_Read(rfdl_u16 Block_Number, rfdl_u16 Position_at_Block, rfdl_u16 Num_Of_Bytes);
// extern void 	FDL_Write(rfdl_u16 Block_Number, rfdl_u16 Position_at_Block, rfdl_u16 Num_Of_Bytes);
r_fdl_status_t FDL_Write(rfdl_u16 Block_Number, rfdl_u16 Position_at_Block, rfdl_u16 Num_Of_Bytes);
extern bool Dflash_init(void);
extern uint8_t FDL_Blankcheck(uint32_t,uint32_t,uint16_t);
#endif /* RFDL_USER_H */


