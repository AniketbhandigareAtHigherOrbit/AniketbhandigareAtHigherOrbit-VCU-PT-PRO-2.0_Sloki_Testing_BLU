/***************************************************************************************************
 *    FILENAME    :  fmdtc_conf.h
 *
 *    DESCRIPTION : Contains the configuration data for DTCs
 *
 *    $Id         : $
 *
 ***************************************************************************************************
 * Revision history
 *
 * Ver Author       Date       Description
 * 1   Sloki          25/09/2018
 ***************************************************************************************************
 */

#ifndef FMDTC_CONF_H
#define FMDTC_CONF_H
#include "diag_typedefs.h"
#include "fm_conf.h"
// #include <stdint.h>

#if (TRUE == FM_UDS_SUPPORTED)

extern const uint32_t DTCMappingTable_UDS_aSt[NUM_OF_FAULTPATHS_E][MAX_NUM_ERROR_TYPES - 1];
//	extern const uint16_t  DTCMappingTable_OBD_aSt[NUM_OF_FAULTPATHS_E][MAX_NUM_ERROR_TYPES-1];c
#define GET_DTC_VALUE_DTC_MAPTBL(fpath, ftype) (DTCMappingTable_UDS_aSt[fpath][ftype])
#endif
//	extern const uint16_t  DTCMappingTable_OBD_aSt[NUM_OF_FAULTPATHS_E][MAX_NUM_ERROR_TYPES-1];

#if (TRUE == FM_J1939_SUPPORTED)

typedef enum
{
	ABOVE_NORMAL_SEVERE = 0, // 0  (MAX)    	 FMI_DataValidButAboveNormalOperationalRange_MostSevereLevel_E = 0,
	BELOW_NORMAL_SEVERE,	 // 1  (MIN)       FMI_DataValidButBelowNormalOperationalRange_MostSevereLevel_E,
	DATA_INCORRECT,			 // 2  (SIG)       FMI_DataErraticIntermittentOrIncorrect_E,
	VOLTAGE_ABOVE_NORMAL,	 // 3  (MAX)       FMI_VoltageAboveNormalOrShortedToHighSource_E,
	VOLTAGE_BELOW_NORMAL,	 // 4  (MIN)       FMI_VoltageBelowNormalOrShortedToLowSource_E,
	CURRENT_BELOW_NORMAL,	 // 5  (MIN)       FMI_CurrentBelowNormalOrOpenCircuit_E,
	CURRENT_ABOVE_NORMAL,	 // 6  (MAX)       FMI_CurrentAboveNormalOrGroundedCircuit_E,
	SYSTEM_OUT_OF_RANGE,	 // 7  (SIG)       FMI_MechanicalSystemNotRespondingOrOutOfAdjustment_E,
	INVALID_TIME_PERIOD,	 // 8  (NPL)       FMI_AbnormalFrequencyOrPulseWidthOrPeriod_E,
	INVALID_UPDATE_RATE,	 // 9  (NPL)       FMI_AbnormalUpdateRate_E,
	INVALID_RATE_OF_CHANGE,	 // 10 (NPL)       FMI_AbnormalRateOfChange_E,
	UNDEFINED_ERR,			 // 11 (NPL)       FMI_RootCauseNotKnown_E,
	DEVICE_NOT_FUNCTIONAL,	 // 12 (FER)       FMI_BadIntelligentDeviceOrComponent_E,
	INVALID_CALIBRATION,	 // 13 (FER)       FMI_OutOfCalibration_E,
	SPECIAL_INSTRUCTION,	 // 14 (FER)       FMI_SpecialInstructions_E,
	ABOVE_NORMAL_TRIVIAL,	 // 15 (MAX)       FMI_DataValidButAboveNormalOperatingRangeLeastSevereLevel_E,
	ABOVE_NORMAL_MODERATE,	 // 16 (MAX)       FMI_DataValidButAboveNormalOperatingRangeModeratelySevereLevel_E,
	BELOW_NORMAL_TRIVIAL,	 // 17 (MIN)       FMI_DataValidButBelowNormalOperatingRangeLeastSevereLevel_E,
	BELOW_NORMAL_MODERATE,	 // 18 (MIN)       FMI_DataValidButBelowNormalOperatingRangeModeratelySevereLevel_E,
	DATA_RX_ERR,			 // 19 (FER)       FMI_ReceivedNetworkDataInError_E,
	DATA_DRIFT_HIGH,		 // 20 (FER)       FMI_DataDriftedHigh_E,
	DATA_DRIFT_LOW,			 // 21 (FER)       FMI_DataDriftedLow_E,
	CONDITION_EXIST			 // 23 (NPL)        FMI_ConditionExists_E
} J1939DTC_FMI_En_t;

typedef struct
{
	uint32_t SPN_u19 : 19;
	uint32_t FMI_u5 : 5;
	uint32_t CM_u1 : 1;
	uint32_t OC_u7 : 7;
} J1939_DTCFormat_t;

typedef union
{
	J1939_DTCFormat_t DTC_St;
	uint32_t DTC_u32;
	uint8_t DTC_au8[4];
} J1939_DTC_Uni_t;

extern const J1939_DTC_Uni_t J1939_DTC_Conf_aUni[NUM_OF_FAULTPATHS_E];
#endif
#endif
