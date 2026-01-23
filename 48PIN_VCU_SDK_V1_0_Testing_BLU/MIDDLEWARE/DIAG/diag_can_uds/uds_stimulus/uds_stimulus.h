/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File          : uds_stimulus.h
|    Project      : MIL_PBL_CV
|    Description    : stimulus functions for handling DID for IOCBLI service.
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


#ifndef _UDS_STIMULUS_H_
#define _UDS_STIMULUS_H_
/*
 **************************************************************************************************
 *    Includes
 **************************************************************************************************
 */
 
#include "uds_conf.h"



 /**
*  FUNCTION NAME : UDS_Stimulus
*  FILENAME      : uds_stimulus.h
*  @param        : DidList_En DidList Enum, 
*  @param        : srcValue_pu8 pointing to Real data
*  @param        : dstValue_pu8 pointing to global variable
*  @brief        : This function will return the forcevalue or realvalue depends on mode.
*  @return       : Non.                     
*/

//extern void UDS_Stimulus(ISO14229_DidList_En_t DidList_En ,  uint8_t *srcValue_pu8 ,  uint8_t *dstValue_pu8 );


 /**
*  FUNCTION NAME : UDS_SetStimulus
*  FILENAME      : uds_stimulus.h
*  @param        : ForceValue_pu8  pointer to forcevalue 
*  @brief        : This function will set mode to true and assign forcevalue
                   to the respective forcevalues in the structure.
*  @return       : void                     
*/
//extern void  UDS_SetStimulus(ISO14229_DidList_En_t DidList_En, uint8_t *ForceValue_pu8);
   

 /**
*  FUNCTION NAME : UDS_ResetStimulus
*  FILENAME      : uds_stimulus.h
*  @param        : DidList_En DidList Enum, 
*  @brief        : This function will set mode to false.
*  @return       : void                     
*/
//extern void  UDS_ResetStimulus(ISO14229_DidList_En_t DidList_En);

#endif