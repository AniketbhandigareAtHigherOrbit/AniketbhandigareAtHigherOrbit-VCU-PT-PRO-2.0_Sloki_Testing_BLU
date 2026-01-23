/******************************************************************************
 *    FILENAME    : uds_DID.h
 *    DESCRIPTION : This file contains configuration data for UDS services.
 ******************************************************************************
 * Revision history
 *  
 * Ver Author           Date                      Description
 * 1   Sloki       10/01/2019		   Initial version
 ******************************************************************************
*/  

#ifndef UDS_DTC_H_
#define UDS_DTC_H_


#ifdef	__cplusplus
 "C" {
#endif


/*
 *******************************************************************************
 *    Includes
 *******************************************************************************
 */

//#include <stdint.h>
#include "diag_typedefs.h"

  
extern uint16_t GetExtendedDataRecordByDTCNumber(uint8_t* service_buffer_pu8);
  
/**
*    @brief  This function will take one status mask value which is 1-byte.
*            Do AND operation between status_mask_u8 and DTC actual status mask if it results one
*            then increment the numberoffaults variable by 1 and at last return it.
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*/
extern uint16_t GetNumOfFaultsByMask(uint8_t* service_buffer_pu8);

/**
 *    @brief  This function will take one buffer address as an argument and fault manager has to write the DTCs. 
 *            fault manager has to write immediate next to their respective DTCs. 
 *    @param DTCBuff    :   address of buffer    
 *    @return length of data
 */
extern uint16_t GetDTCsByStatusMask(uint8_t* service_buffer_pu8);
/**
*    @brief  This function will take one buffer address as an argument.
*               fault manager has to write the snapshot dtc values with their individual record numbers
*               the DTC and the record value should be immediate next to each other
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*/
extern uint16_t GetDTCSnapshotIdentification(uint8_t* service_buffer_pu8);

/**
*    @brief  In this function we will send data buffer address which have DTC value and DTC snapshot record number.
*               fault manager has to take the values and rewrite the buffer in following way
*               DTC which is                         3 bytes
*               DTCstatus                            1 byte
*               DTCSnapshotRecordNumber              1 byte
*               DTCSnapshotRecordNumberOfIdentifiers 1 byte
*               data identifiers                     2bytes
*               DTC snapshot records                 ...
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*/
extern uint16_t GetDTCSnapshotRecordByDTCNumber(uint8_t* service_buffer_pu8);


/**
*    @brief  this function will pass the severity_mask_u8 and status_mask_u8 as arguments.
*               fault manager has to ((statusOfDTC & DTCStatusMask) & (severity & DTCSeverityMask)) != 0 do this operation for every DTC
*               if its satisfies the 8 bit number has to be incremented. and at last it has to be returned.
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*/
extern uint16_t GetNumberOfDTCBySeverityMaskRecord(uint8_t* service_buffer_pu8);


/**
*    @brief  this function will pass the data buffer address severity_mask_u8 and status_mask_u8 as arguments.
*               fault manager has to ((statusOfDTC & DTCStatusMask) & (severity & DTCSeverityMask)) != 0 do this operation for every DTC
*               if its satisfies it has to write the values to the buffer as following
*               DTCStatusAvailabilityMask        1 byte
*               DTCSeverity                      1 byte
*               DTCFunctionalUnit                1 byte
*               DTC                              3 bytes
*               status of DTC                    1 byte
* 
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*/
extern uint16_t GetDTCBySeverityMaskRecord(uint8_t* service_buffer_pu8);

/**
*    @brief  This function we will send data buffer address which have DTC value.
*               fault manager has to write the values to the buffer as following
*               DTCStatusAvailabilityMask        1 byte
*               DTCSeverity                      1 byte
*               DTCFunctionalUnit                1 byte
*               DTC                              3 bytes
*               status of DTC                    1 byte
* 
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*/
extern uint16_t SeverityInformationOfDTC(uint8_t* service_buffer_pu8);
/**
*    @brief  This function will pass the data buffer address.
*               fault manager has to write all DTCs that it support into the buffer.
* 
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*/
extern uint16_t SupportedDTCs(uint8_t* service_buffer_pu8);

/**
*    @brief  this function will pass the data buffer address.
*               fault manager has to write only one DTC which was failed first into the buffer.
*               if No failed DTCs have occurred since the last ClearDiagnosticInformation don't write anything
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*/
extern uint16_t GetFirstTestFailedDTC(uint8_t* service_buffer_pu8);

/**
*    @brief  This function will pass the data buffer address.
*               fault manager has to write only one DTC which was confirmed first into the buffer.
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*/
extern uint16_t GetFirstConfirmedDTC(uint8_t* service_buffer_pu8);

/**
*    @brief  This function will pass the data buffer which is empty.
*               fault manager has to write DTC and its respective fault detection counter value.
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*
**/
extern uint16_t GetDTCFaultDetectionCounter(uint8_t* service_buffer_pu8);
/**
*    @brief  This function will pass the data buffer which is empty.
*                fault manager has to write DTC along with their statuses into the buffer which are permanent
*
*    @param  service_buffer_pu8 Holds the Tx data
*    @return length of data
*
**/
extern uint16_t GetDTCWithPermanentStatus(uint8_t* service_buffer_pu8);

/**
 *    @brief  This function will record the global and local snapshoot information.
 *
 *    @param  service_buffer_pu8 Holds the Tx data
 *    @return length of data
 *
 **/
extern void FreezeFrame_DataLog(uint16_t Did_u16, uint8_t * Parameter_Address, uint32_t *BuffIndex_u32);

/**
 *    @brief  This function will read the parameter size as per the DID.
 *
 *    @param  Did_u16 Holds the DID number
 *    @return void
 *
 **/
extern uint8_t Get_FreezeFrame_ParamSize(uint16_t Did_u16);
#endif
