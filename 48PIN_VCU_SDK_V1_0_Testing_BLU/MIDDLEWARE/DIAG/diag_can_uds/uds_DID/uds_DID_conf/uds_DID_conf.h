/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File         : uds_DID_conf.h
|    Project      : MIL_PBL_CV
|    Description  : Service description for UDS DID service configurations
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
#ifndef _UDS_DID_CONF_H_
#define	_UDS_DID_CONF_H_
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "uds_conf.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/

#define SAMPLE_DID_DATA_SIZE			2

#define DUMMY_BLOCK_E					0xFFFFU
#define DUMMY_PARAMETER_E			    0xFFFFU

/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef bool (*CB_outofrange_Fptr_t)(uint8_t did_i, UDS_Serv_St_t *RxBuff_pu8);

typedef uint16_t (*FrzFrm_Fptr_t) (void);
#pragma pack(1)
typedef struct
{
  uint8_t*		    ParamBuffer_pu8;   		// freeze frame parameter buffer.
  uint16_t          ParamSize_u16;          // parameter buffer length in bytes.
  FrzFrm_Fptr_t     FrzFrm_Fptr;            // Function for freezeframe capture
}FM_FrzFrm_UDS_St_t;
#pragma pack(1)
typedef struct 
{
	uint16_t DID_u16;
	uint16_t DidLen_u16;
	uint8_t MemoryType_u8;
	const uint8_t* Dataptr_pu8;
	uint8_t AccessType_u8;
	uint8_t WriteDiagSession_u8;
	uint8_t ReadDiagSession_u8;
	uint8_t WriteSecurityLvl_u8;
	uint8_t ReadSecurityLvl_u8;
	CB_outofrange_Fptr_t CB_outofrange_Fptr; /* Pointer used for hold the Real Time Value */
	FM_FrzFrm_UDS_St_t FM_FrzFrm_UDS_St;
}DidConf_st_t;
#pragma pack(1)
typedef struct 
{
	uint16_t DID_u16;
	uint16_t NvmBlock_u16;
	uint16_t NvmParameter_u16;
	uint32_t InternalFlashAddress_u32;
}DidNvmIf_St_t;

/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern const DidConf_st_t DidConf_ast[TOTAL_DID];
extern const DidNvmIf_St_t DidNvmIf_aSt[TOTAL_DID];
/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/
extern uint8_t GetDidDescriptor(uint16_t DID_u16,DidConf_st_t** DidConfDptr_pSt);

#endif
/*---------------------- End of File -----------------------------------------*/