/***************************************************************************************************
 *    FILENAME    :  fmff_conf.h
 *
 *    DESCRIPTION : File contains the configuration table for freeze frames.
 *
 *    $Id         : $    
 *
 ***************************************************************************************************
 * Revision history
 * 
 * Ver Author       Date       Description
 * 1   Sloki/Harsh          24/07/2020
 ***************************************************************************************************
*/

#ifndef    _FMFF_CONF_H_
#define    _FMFF_CONF_H_

#include <stdint.h>
//#include "uds_conf.h"
#include "fm_conf.h"
#include "diag_typedefs.h"
//#include "databank.h"
/*
***************************************************************************************************
*    Includes
***************************************************************************************************
*/

/*
***************************************************************************************************
*    Type Defines
***************************************************************************************************
*/
typedef uint16_t (*FrzFrm_Fptr_t) (void);

/*
***************************************************************************************************
*    Defines
***************************************************************************************************
*/

/* Freeze Frame Configuration for UDS Protocol */
/* # of entries in Global snapshot freeze frame config table */
#define FMFF_CONF_UDS_GLBSS_ENTRIES				2

/* # of entries in specific snapshots (UDS Protocol) */
#define FMFF_CONF_UDS_LOCAL_01_ENTRIES		4
#define FMFF_CONF_UDS_LOCAL_02_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_03_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_04_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_05_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_06_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_07_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_08_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_09_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_10_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_11_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_12_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_13_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_14_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_15_ENTRIES		1
#define FMFF_CONF_UDS_LOCAL_16_ENTRIES		1
/*
The function FM_ReadFrzFrm_ByDTC() returns freezeframe for faults in L2, in addition if
the freezeframe from L1 memory is also required, then the below macro can be set to TRUE. 
*/
#define FRZFRM_FROM_FML1    TRUE
/*
**************************************************************************************************
*    Enum definitions
**************************************************************************************************
*/


/*
**************************************************************************************************
*    Structure definitions
**************************************************************************************************
*/



/* 
The Freeze frame structure definition for EOBD faults.
@code tag - @[CODE_FM_FRZFRM_CONFTBL]@{SDD_FM_FRZFRM_CONFTBL}
*/
#if (TRUE == FM_UDS_SUPPORTED)

#define FMFF_CONF_UDS_FRZFRM_GLBSS_BYTES    (24)
#define FMFF_CONF_UDS_FRZFRM_LOCAL_BYTES    (24)
/* Total number of bytes of Global and Specific FF together */
#define FMFF_CONF_UDS_FRZFRM_TOTALBYTES     (FMFF_CONF_UDS_FRZFRM_GLBSS_BYTES + FMFF_CONF_UDS_FRZFRM_LOCAL_BYTES)  

#pragma pack (1)
// typedef struct
// {
//   uint16_t		    DID_u16;   				// DID number.
//   uint8_t*		    ParamBuffer_pu8;   		// freeze frame parameter buffer.
//   uint16_t          ParamSize_u16;          // parameter buffer length in bytes.
//   FrzFrm_Fptr_t     FrzFrm_Fptr;            // Function for freezeframe capture
// }FM_FrzFrm_UDS_Data_St_t;



#pragma pack (1)
typedef struct
{
  FM_FaultPath_En_t    	            FM_FaultPath_En;
  const uint16_t 	                  *FM_FrzFrm_LocalEntries;
  uint16_t			        	          NumOfEntries_u16;
}FM_FrzFrmMasterConfig_UDS_St_t;

// extern const FM_FrzFrm_UDS_Data_St_t FM_Global_Snapshot_UDS_aSt[FMFF_CONF_UDS_GLBSS_ENTRIES];
extern const FM_FrzFrmMasterConfig_UDS_St_t	FM_FrzFrmMasterConfig_UDS_aSt[NUM_OF_FAULTPATHS_E];

extern const uint16_t FM_Global_Snapshot_UDS_au16[FMFF_CONF_UDS_GLBSS_ENTRIES];
extern const uint16_t FM_FrzFrm_Local01_UDS_au16[FMFF_CONF_UDS_LOCAL_01_ENTRIES];

extern uint8_t Sample1_au8[1];
extern uint8_t Sample2_au8[1];
extern uint8_t Sample3_au8[1];
extern uint8_t Sample4_au8[1];
extern uint8_t Sample5_au8[1];
extern uint8_t Sample6_au8[1];

#endif

   
#endif



