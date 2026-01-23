/***************************************************************************************************
 *    FILENAME    : fm.h
 *
 *    DESCRIPTION : File declares the common functions related to Fault manager
 *                  level 1 and Level 2. It monitors and updates the common
 *                  data used for Fault manager 
 *
 *    $Id         : $    
 *
 ***************************************************************************************************
 * Revision history
 * 
 * Ver Author       Date        Description
 * 1                25/09/2008
 ***************************************************************************************************
*/

#ifndef    _FM_H_
#define    _FM_H_

/*
 ***************************************************************************************************
 *    Includes
 ***************************************************************************************************
*/

#include <stdint.h>
#include "fm_conf.h"
#include "math_util.h"
#include <stdbool.h>
//#include "fmdtc_conf.h"
//#include "uds_serv85.h"
//#include "battvolt.h" // todo harsh


/*
 **************************************************************************************************
 *    Enum and Structure definition
 **************************************************************************************************
*/

//fault path

typedef uint16_t u16_FaultPath_t;
#define FREEZEFRAME_RECORD_ID           1u
#define NUM_OF_RECORDS                  1u
#define NUM_OF_RECORD_IDENTIFIERS       1u
#define NONE_DATA_IDENTIFIERS           0u

#define TOTAL_DTCCLR_INDICATOR  2
#define DTCCLR_IND_FOR_ACT_FLT  0
#define DTCCLR_IND_FOR_CNFRM_FLT  1



/*
    Common variables present in L2 NV Memory array. 
    These variables are common for all the fault entries.
    Some of these variables are PIDs for ISO15031-5, Service-01.
    All these paramters are cleared to zero with ISO15031-5, Service-04.
    
    @code tag - @[CODE_DERIVED_FML2_COMMONDATA_ST]@{SDD_DERIVED_FML2_COMMONDATA_ST}
*/

typedef struct
{
    /*
    @@ ELEMENT    = FM_Total_Error_Handles
    @@ STRUCTURE  = FML2_CommonData_St_t
    @@ A2L_TYPE   = PARAMETER FM_TotalFltEntryCnt
    @@ DATA_TYPE  = $uint32_t$
    @@ CONVERSION = LINEAR $RADIX_0$ "cnt"
    @@ GROUP      = SUBGRP_FM
    @@ DESCRIPTION= "Num of entries into FM sincle last clear"
    @@ END
    */
    uint32_t    FM_Total_Error_Handles;      // This variable keeps track of the total number of entries put in to 
                                           // NV memory.This helps in finding out the oldest reported data.This
                                           // variable is incremented for every fault added to NV ram.
                                           // This variable will not get decremented when an entry is deleted 
                                           // from L2 memory.

    /*
    @@ ELEMENT    = DistDrv_MILOn_Kms_u16
    @@ STRUCTURE  = FML2_CommonData_St_t
    @@ A2L_TYPE   = PARAMETER DistDrvn_MILOn
    @@ DATA_TYPE  = $uint16_t$
    @@ CONVERSION = LINEAR $RADIX_0$ "kms"
    @@ GROUP      = SUBGRP_FM
    @@ DESCRIPTION= "Distance driven in Kms with MIL ON"
    @@ END
    */
    uint16_t    DistDrv_MILOn_Kms_u16;       // Distance driven in Kms with MIL ON.

    /*
    @@ ELEMENT    = DistDrvSi_DTCClr_Kms_u16
    @@ STRUCTURE  = FML2_CommonData_St_t
    @@ A2L_TYPE   = PARAMETER DistDrvn_DTCClr
    @@ DATA_TYPE  = $uint16_t$
    @@ CONVERSION = LINEAR $RADIX_0$ "kms"
    @@ GROUP      = SUBGRP_FM
    @@ DESCRIPTION= "Distance driven in Kms since DTC clear"
    @@ END
    */
    uint16_t    DistDrvSi_DTCClr_Kms_u16;    // Distance driven in Kms since DTC Clear.

    /*
    @@ ELEMENT    = Time_MILOn_min_u16
    @@ STRUCTURE  = FML2_CommonData_St_t
    @@ A2L_TYPE   = PARAMETER Duration_MILOn
    @@ DATA_TYPE  = $uint16_t$
    @@ CONVERSION = LINEAR $RADIX_0$ "min"
    @@ GROUP      = SUBGRP_FM
    @@ DESCRIPTION= "Operating Time in minutes with MIL on"
    @@ END
    */
    uint16_t    Time_MILOn_min_u16;          // Operating Time in minutes with MIL on.

    /*
    @@ ELEMENT    = TimeSi_DTCClr_min_u16
    @@ STRUCTURE  = FML2_CommonData_St_t
    @@ A2L_TYPE   = PARAMETER Duration_DTCClr
    @@ DATA_TYPE  = $uint16_t$
    @@ CONVERSION = LINEAR $RADIX_0$ "min"
    @@ GROUP      = SUBGRP_FM
    @@ DESCRIPTION= "Operating Time in minutes since DTC Clear"
    @@ END
    */
    uint16_t    TimeSi_DTCClr_min_u16;       // Operating Time in minutes since DTC Clear.

    /*
    @@ ELEMENT    = WUPSi_DTCClr_u8
    @@ STRUCTURE  = FML2_CommonData_St_t
    @@ A2L_TYPE   = PARAMETER WUP_DTCClr
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ "cnt"
    @@ GROUP      = SUBGRP_FM
    @@ DESCRIPTION= "Number of Warmup cycles since DTC Clear"
    @@ END
    */
    uint8_t     WUPSi_DTCClr_u8;             // Number of Warmup cycles since DTC Clear.

    /*
    @@ ELEMENT    = FM_FltEntryCnt_u8
    @@ STRUCTURE  = FML2_CommonData_St_t
    @@ A2L_TYPE   = PARAMETER FM_CurrFltCnt
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ "cnt"
    @@ GROUP      = SUBGRP_FM
    @@ DESCRIPTION= "Number of entries in Level-2 memory"
    @@ END
    */
    uint8_t     FM_FltEntryCnt_u8;           // Number of entries in Level-2 memory.
                                           // This variable shows the number of entries currently
                                           // in L2 memory
    /*
    @@ ELEMENT    = Upd_St
    @@ STRUCTURE  = FML2_CommonData_St_t
    @@ A2L_TYPE   = PARAMETER UpdateFlag
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ " "
    @@ GROUP      = SUBGRP_FM
    @@ DESCRIPTION= "Updation status of the structure"
    @@ END
    */
    bool      Upd_St;                      // Updation status of the structure

    /*
    @@ ELEMENT    = WUPSi_MILOff_u8
    @@ STRUCTURE  = FML2_CommonData_St_t
    @@ A2L_TYPE   = PARAMETER WUPSi_MILOff
    @@ DATA_TYPE  = $uint8_t$
    @@ CONVERSION = LINEAR $RADIX_0$ "cnt"
    @@ GROUP      = SUBGRP_FM
    @@ DESCRIPTION= "Number of Warmup cycles since DTC Clear"
    @@ END
    */
    uint8_t     WUPSi_MILOff_u8;           

}FML2_CommonData_St_t;


typedef struct
{
    uint32_t      ActiveDTC_u32;
    uint32_t      CnfrmedDTC_u32;
    bool        DTCClearedIndicator[TOTAL_DTCCLR_INDICATOR];
}FM_FirstFailedFltsInfo_St_t; /*Structure holds the first failed DTC since last DTC clear*/
      
typedef union
{
  struct{
	uint8_t stTF_b0       : 1;    //Testfailed
	uint8_t stTFTOC_b1    : 1;    //TestFailedThisOperationCycle
	uint8_t stPDTC_b2     : 1;    //PendingDTC
	uint8_t stCDTC_b3     : 1;    //ConfirmedDTC
	uint8_t stTNCSLC_b4   : 1;    //TestNotCompletedSinceLastClear
	uint8_t stTFSLC_b5    : 1;    //TestFailedSinceLastClear
	uint8_t stTNCTOC_b6   : 1;    //TestNotCompletedThisOperationCycle
	uint8_t stWIR_b7      : 1;    //WarningIndicatorRequested   
  }status_bit;
  uint8_t Status_u8;
}FM_DTCStatus_Un_t;


		
/*
 ***************************************************************************************************
 *    Defines
 ***************************************************************************************************
*/

// Other defines
#define    NA                      0xFF       // Not applicable

//driving cycle trigger
#define DRIVING_CYCLE_TRIGGER_SEC   11        //time since engine on

//Warm up cycle: Sufficient vehicle operation such that the coolant temperature
//has risen by a least 22 ?K from engine starting and reaches a minimum 
//temperature of 343 ?K (70 ?C) and engine coolant temperature within the range 
//343 K to 373 K (70 ?C to 100 ?C)
#define DELTA_TEMP_INC_VALID_WUP_CYL   22
#define MIN_TEMP_VALID_WUP_CYL         70

//maximum limits for commom counters
#define MAX_DIST_DRVN_MIL_ON_KM  65535
#define MAX_DIST_DRVN_DTC_CLR_KM 65535
#define MAX_TIME_MIL_ON_MIN      65535
#define MAX_TIME_DTC_CLR_MIN     65535
#define MAX_COUNT_WARMUP_CYL     255
#define MAX_L2ERR_FREQ_CNT       0xFFFF

#define FM_RST_Entries_In_L2() FML2_CommonNVData_St.FM_FltEntryCnt_u8 = 0;FM_Set_CmnCntr_UptSt()
#define FM_Get_Entries_In_L2() (FML2_CommonNVData_St.FM_FltEntryCnt_u8)
#define FM_INC_Entries_In_L2() FML2_CommonNVData_St.FM_FltEntryCnt_u8++;FM_Set_CmnCntr_UptSt()
#define FM_DEC_Entries_In_L2() FML2_CommonNVData_St.FM_FltEntryCnt_u8--;FM_Set_CmnCntr_UptSt()

#define FM_RST_TotalErrorHandle() FML2_CommonNVData_St.FM_Total_Error_Handles = 0;FM_Set_CmnCntr_UptSt()
#define FM_Get_TotalErrorHandle() (FML2_CommonNVData_St.FM_Total_Error_Handles)
#define FM_INC_TotalErrorHandle() FML2_CommonNVData_St.FM_Total_Error_Handles++;FM_Set_CmnCntr_UptSt()
#define FM_DEC_TotalErrorHandle() FML2_CommonNVData_St.FM_Total_Error_Handles--;FM_Set_CmnCntr_UptSt()

#define FM_GET_DryCylInd() (FM_DrvCyInd_b        )
#define FM_SET_DryCylInd() (FM_DrvCyInd_b = TRUE )
#define FM_CLR_DryCylInd() (FM_DrvCyInd_b = FALSE)

#define FM_GET_WUPCylInd() (FM_WUPCyInd_b        )
#define FM_SET_WUPCylInd() (FM_WUPCyInd_b = TRUE )
#define FM_CLR_WUPCylInd() (FM_WUPCyInd_b = FALSE)

#define FM_Set_CmnCntr_UptSt()    (FML2_CommonNVData_St.Upd_St = TRUE)
#define FM_Clr_CmnCntr_UptSt()    (FML2_CommonNVData_St.Upd_St = FALSE)
#define FM_Get_CmnCntr_UptSt()    (FML2_CommonNVData_St.Upd_St)

#define FM_RST_DIST_DRV_MIL_ON_KM()   (FML2_CommonNVData_St.DistDrv_MILOn_Kms_u16 = 0)
/* @code tag - @[CODE_FM_READCOMMONDATA]@{SDD_FM_READCOMMONDATA} */
#define FM_GET_DIST_DRV_MIL_ON_KM()   (FML2_CommonNVData_St.DistDrv_MILOn_Kms_u16)
#define FM_UPT_DIST_DRV_MIL_ON_KM(val) (FML2_CommonNVData_St.DistDrv_MILOn_Kms_u16 = val)

#define FM_RST_DIST_DRV_DTC_CLR_KM()  (FML2_CommonNVData_St.DistDrvSi_DTCClr_Kms_u16 = 0)
/* @code tag - @[CODE_FM_READCOMMONDATA]@{SDD_FM_READCOMMONDATA} */
#define FM_GET_DIST_DRV_DTC_CLR_KM()  (FML2_CommonNVData_St.DistDrvSi_DTCClr_Kms_u16)
#define FM_UPT_DIST_DRV_DTC_CLR_KM(val) (FML2_CommonNVData_St.DistDrvSi_DTCClr_Kms_u16 = val)

#define FM_RST_TIME_MIL_ON_MIN()      (FML2_CommonNVData_St.Time_MILOn_min_u16 = 0)
/* @code tag - @[CODE_FM_READCOMMONDATA]@{SDD_FM_READCOMMONDATA} */
#define FM_GET_TIME_MIL_ON_MIN()      (FML2_CommonNVData_St.Time_MILOn_min_u16)
#define FM_UPT_TIME_MIL_ON_MIN(val) (FML2_CommonNVData_St.Time_MILOn_min_u16 = val)

#define FM_RST_TIME_DTC_CLR_MIN()     (FML2_CommonNVData_St.TimeSi_DTCClr_min_u16 = 0)
/* @code tag - @[CODE_FM_READCOMMONDATA]@{SDD_FM_READCOMMONDATA} */
#define FM_GET_TIME_DTC_CLR_MIN()     (FML2_CommonNVData_St.TimeSi_DTCClr_min_u16)
#define FM_UPT_TIME_DTC_CLR_MIN(val) (FML2_CommonNVData_St.TimeSi_DTCClr_min_u16 = val)

#define FM_RST_WUPCYL_DTC_CLR() (FML2_CommonNVData_St.WUPSi_DTCClr_u8 = 0)
/* @code tag - @[CODE_FM_READCOMMONDATA]@{SDD_FM_READCOMMONDATA} */
#define FM_GET_WUPCYL_DTC_CLR() (FML2_CommonNVData_St.WUPSi_DTCClr_u8)
#define FM_UPT_WUPCYL_DTC_CLR(val) (FML2_CommonNVData_St.WUPSi_DTCClr_u8 = val)

#define FM_RST_WUPCYL_MIL_OFF() (FML2_CommonNVData_St.WUPSi_MILOff_u8 = 0)
/* @code tag - @[CODE_FM_READCOMMONDATA]@{SDD_FM_READCOMMONDATA} */
#define FM_GET_WUPCYL_MIL_OFF() (FML2_CommonNVData_St.WUPSi_MILOff_u8)
#define FM_UPT_WUPCYL_MIL_OFF(val) (FML2_CommonNVData_St.WUPSi_MILOff_u8 = val)


/*
 ***************************************************************************************************
 *    Entern global variables
 ***************************************************************************************************
*/
extern bool FM_DTC_SettingsOff_b;

extern FM_FirstFailedFltsInfo_St_t FM_FirstFailedFltsInfo_St; 
//extern FM_ProtocolType_En_t FM_ProtocolTypeSet_En;

/*
 ***************************************************************************************************
 *    Export functions
 ***************************************************************************************************
*/

/**
*    @brief  Schedules the Fault manager related tasks.
*    @param  None.
*    @return None.
*/
extern void FM_Sched_proc (void);

/**
*    @brief  Task to monitor the driving cycle. The task will update the global 
*            flag "FM_DrvCyInd_b".
*    @param  None.
*    @return None.
*/
extern void FM_MonDrvCy_proc (void);

/**
*    @brief  Task to monitor the driving cycle. The task will update the global 
*            flag "FM_WUPCyInd_b".
*    @param  None.
*    @return None.
*/
extern void FM_WUPCy_proc (void);

/**
*    @brief : Function to clear the common data in fault memory, such as
*             duration counter, distance driven and MIL status.
*    @param : none.
*    @return :none.
*/
extern void FM_ClrCommonData(void);
/**
*    @brief : Task to handle the common objects like duration counter and driven distance.
*    @param : none.
*    @return :none.
*/
extern void FM_HndlCommonCntrs_proc (void);

/**
*    @brief  Function which executes Initialisation functionalities FM in seequence
*
*    @param  None.
*    @return None.
*/
extern void FM_Init(void);
extern void FM_BON(void);
extern void FM_Wkup(void);
extern void FM_NVM_Entry_Write(void);
void AcsDTC_param(void);

/**
*    @brief  Function which executes power off functionalities FM in seequence
*
*    @param  None.
*    @return None.
*/
extern void FM_PowerOff (void);

/**
*    @brief  The function ensures that common counters are stored on to NV
*
*    @param  None.
*    @return None.
*/
extern void FM_UpdtCommonData_proc(void);

/**
*    @brief  Function increments the total number of errors logged in L2 memory.
*            This variable will be cleared when tester request for clearing all
*            NONOBD specific faults or if the number of current entries in L2
*            becomes zero
*
*    @param  None
*    @return None
*/
extern void FM_Inc_Error_handle(void);

/**
*    @brief  Function decrements the total number of errors logged in L2 memory.
*            This variable will be cleared when tester request for clearing all
*            NONOBD specific faults or if the number of current entries in L2
*            becomes zero
*
*    @param  None
*    @return None
*/
extern void FM_Dec_Error_handle(void);

/**
*    @brief  Function increments the number of entries currently in L2 memory 
*
*    @param  None
*    @return None
*/
extern void FM_IncNofEntries_L2(void);

/**
*    @brief  Function decrements the number of entries currently in L2 memory 
*
*    @param  None
*    @return None
*/
extern void FM_DecNofEntries_L2(void);

/**
*    @brief  The function to report application specific faults to the fault 
*            manager.This API is provided to the application layer.
*
*    @param  FaultPath_En - Application specific Fault Paths as configured 
*            by the application user in Fault manager.
*
*    @param  ErrorType_En   - Error catgory of the fault (E.g. MAX, MIN, 
*            SIG,etc) Refer to FM_ErrorType_En_t table for proper parameter.
*
*    @return None.
*/
extern void FM_ReportFault(FM_FaultPath_En_t FltPath,uint8_t ErrorType_En);

/**
*    @brief   Returns the status of DTC mask
*
*    @param   FaultPath_En - Application specific Fault Paths as configured 
*             by the application user in Fault manager.
*    @return  TRUE or FALSE
*    @code tag - @[CODE_FM_RDY_CMPLT]@{SDD_FM_RDY_CMPLT}
*/
extern bool FM_DTC_Mask_Sts (u16_FaultPath_t FltPath);

/**
*    @brief   Returns the status of readiness
*
*    @param   None.
*    @return  TRUE or FALSE
*/
extern bool FM_IsRdyComplete (void);

/**
*    @brief   Returns the status of Fuel system readiness
*
*    @param   None.
*    @return  TRUE or FALSE
*/
extern bool FM_IsFUELSysRdyComplete (void);


/**
*    @brief   Returns the status of EGR system readiness
*
*    @param   None.
*    @return  TRUE or FALSE
*/
extern bool FM_IsEGRSysRdyComplete (void);

/**
*    @brief   Returns the status of CCOMP system readiness
*
*    @param   None.
*    @return  TRUE or FALSE
*/
extern bool FM_IsCCOPMSysRdyComplete (void);

/**
*    @brief  Function returns the DTC value of a fault path.
*            Refers to the DTC mapping table and returns the corresponding 
*            DTC value
*
*    @param  Fault Path.
*    @param  Fault type.
*
*    @return 16 bit P-code (power train code)
*    @return 0 -- if failure
*/
extern uint16_t FM_GetDTCofPath (u16_FaultPath_t FaultPath, uint8_t FltType_u8, FM_ProtocolType_En_t FM_ProtocolType_En);

/**
*    @brief  Function to read the NONOBD specific Freeze frame from level-2 
*            fault mamory.
*
*    @param  DTC
*    @param  Address of the buffer where the freeze frames datas are copied.
*
*    @return Number of DTC freeze frames successfully copied
*/
extern uint8_t FM_ReadCmpltNONOBDFrzFrm(uint16_t DTC_u16, uint16_t* DataBuff_pu16, FM_ProtocolType_En_t FM_ProtocolType_En);

/**
*    @brief  Function to clear the all NONOBD related faults in L2 memory
*
*    @param  None
*    @return None
*/ 
extern void FM_ClrAllNONOBDFaults(void);

/**
*    @brief  Function to clear the pending NONOBD related faults in L2 memory
*
*    @param  None
*    @return None
*/
extern void FM_ClrPndngNONOBDFaults(void);

/**
*    @brief  Function to clear the confirmed NONOBD related faults in L2 memory
*
*    @param  None
*    @return None
*/ 
extern void FM_ClrCnfrmNONOBDFaults(void);

/**
*    @brief  Function to clear the deleting NONOBD related faults in L2 memory
*
*    @param  None
*    @return None
*/

extern void FM_ClrDeletingNONOBDFaults(void);

/**
*    @brief  Function to clear all faults in L2 memory
*
*    @param  None
*    @return None
*/
extern void FM_ClrAllFaults(void);

/**
*    @brief  Function to clear all pending faults in L2 memory
*
*    @param  None
*    @return None
*/
extern void FM_ClrAllPndngFaults(void);

/**
*    @brief  Function to clear all confirmed faults in L2 memory
*
*    @param  None
*    @return None
*/
extern void FM_ClrAllCnfrmFaults(void);

/**
*    @brief  Function to clear all deleting faults in L2 memory
*
*    @param  None
*    @return None
*/ 
extern void FM_ClrAllDeletingFaults(void);

/**
*    @brief  Function to find number of the pending NONOBD related faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern u16_FaultPath_t FM_NofPndngNONOBDFaults(void);

/**
*    @brief  Function to find number of the confirmed NONOBD related faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern uint8_t FM_NofCnfrmNONOBDFaults(void);

/**
*    @brief  Function to find number of the deleting NONOBD related faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern uint8_t FM_NofPrevActvNONOBDFaults(void);

/**
*    @brief  Function to find number of all faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern uint8_t FM_NofAllFaults(void);



/**
*    @brief  Function to find number of all deleting faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern uint8_t FM_NofAllPrevActvFaults(void);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  Fault status
*             - FM_NO_ERR
*             - FM_MAX_ERR
*             - FM_MIN_ERR
*             - FM_SIG_ERR
*             - FM_NPL_ERR
*             - FM_FER_ERR
*
*/
extern uint8_t FM_GetErr(u16_FaultPath_t FltPath);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FM_GetErrSt(u16_FaultPath_t FltPath);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FM_GetMaxErr(u16_FaultPath_t FLT_PATH);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FM_GetMinErr(u16_FaultPath_t FLT_PATH);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FM_GetSigErr(u16_FaultPath_t FLT_PATH);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FM_GetNplErr(u16_FaultPath_t FLT_PATH);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FM_GetFerErr(u16_FaultPath_t FLT_PATH);

/**
*    @brief  Function fills the parameter pointer with DTC codes of confirmed
*            NON OBD faults
*
*    @param  Pointer to update the DTC codes
*
*    @return Number of DTC codes copied
*/
extern int8_t FM_GetAllCnfrmNONOBD_DTCs (uint32_t *DTCVal_pu32, FM_ProtocolType_En_t FM_ProtocolType_En);

/**
*    @brief  Function fills the parameter pointer with DTC codes of confirmed
*            OBD and NON OBD faults
*
*    @param  Pointer to update the DTC codes
*
*    @return Number of DTC codes copied
*/
extern int8_t FM_GetAllCnfrmDTCs (uint32_t *DTCVal_pu32, FM_ProtocolType_En_t FM_ProtocolType_En);

/**
*    @brief  Function fills the parameter pointer with DTC code of
*            Nth(EntryNum_u8) entry NON OBD fault
*
*    @param  Entry Number in L2 memory
*    @param  Pointer to update the DTC codes
*
*    @return -1 - No OBD DTC exists with specified entry number
*    @return  0 - Success
*/
extern int8_t FM_GetCnfrmNONOBD_DTC (uint8_t EntryNum_u8, uint32_t *DTCVal_pu32, FM_ProtocolType_En_t FM_ProtocolType_En);

/**
*    @brief  Function fills the parameter pointer with DTC code of 
*            Nth(EntryNum_u8) entry of OBD or NON-OBD fault
*
*    @param  Entry Number in L2 memory
*    @param  Pointer to update the DTC codes
*
*    @return -1 - No OBD DTC exists with specified entry number
*    @return  0 - Success
*/
extern int8_t FM_GetCnfrmDTC (uint8_t EntryNum_u8, uint32_t *DTCVal_pu32, FM_ProtocolType_En_t FM_ProtocolType_En);

/**
*    @brief  Function fills the parameter pointer with fault type and 
*            fault paths of NON OBD related entries in L2 memory
*
*    @param  pointer to update the FltPaths
*    @param  Pointer to update the FltTypes
*
*    @return Number of NON OBD related faults in L2 memory
*/
extern int8_t FM_GetAllCnfrmNONOBD_FltPaths_FltTypes (uint16_t* FltPath_pu16, uint8_t* FltType_pu8);

/**
*    @brief  Function fills the parameter pointer with fault type and 
*            fault paths of all (OBD + NON-OBD) entries in L2 memory
*
*    @param  pointer to update the FltPaths
*    @param  Pointer to update the FltTypes
*
*    @return Number of OBD + NON-OBD related faults in L2 memory
*/
extern int8_t FM_GetAllCnfrm_FltPaths_FltTypes (uint16_t* FltPath_pu16, uint8_t* FltType_pu8);

/**
*    @brief  Function fills the parameter pointer with fault type and 
*            fault paths of particular OBD entry in L2 memory
*
*    @param  pointer to update the FltPaths
*    @param  Pointer to update the FltTypes
*
*    @return -1 - No NON OBD fault exists with specified entry number
*    @return  0 - Success
*/
extern int8_t FM_GetCnfrmNONOBD_FltPath_FltType (uint8_t EntryNum_u8, uint16_t* FltPath_pu16, uint8_t* FltType_pu8);

/**
*    @brief  Function fills the parameter pointer with fault type and 
*            fault paths of particular OBD or NON-OBD entry in L2 memory
*
*    @param  pointer to update the FltPaths
*    @param  Pointer to update the FltTypes
*
*    @return -1 - No OBD or NON-OBD fault exists with specified entry number
*    @return  0 - Success
*/
extern int8_t FM_GetCnfrm_FltPath_FltType (uint8_t EntryNum_u8, uint16_t* FltPath_pu16, uint8_t* FltType_pu8);

/**
*    @brief  Function to find the list of readiness components that are supported. 
*    @param  None
*    @return Bit mask indicating the supported readiness groups
*/
extern uint8_t FM_GetSuppRdyGroup(void);


/**
*    @brief  Wrapper function to turn off MI
*
*    @param  None
*    @return None
*/ 
extern void FM_TurnOffMI (void);

/**
*    @brief : Wrapper function to clear the readiness completion variable. Also clears the
*             readiness monitoring test results in NV memory
*    @param : none.
*    @return :none.
*/
extern void FM_ClrRdyMonFlags(void);

/**
*    @brief  Function to read frequency counter that caused Freeze frame storage.
*    @param  None
*    @return Frequency counter
*/
extern uint16_t FM_GetFreqCnt_OBDFrzFrm(void);

/**
*    @brief  Function to get time since key ON in milli second.
*    @param  None
*    @return time in milli seconds
*/
extern uint32_t FM_GET_TIME_SINCE_KEY_ON_MS(void);

/**
*    @brief  Function to get time since key ON in second.
*    @param  None
*    @return time in seconds
*/
extern uint32_t FM_GET_TIME_SINCE_ENGINE_ON_SEC(void);

extern uint16_t FM_ReadDTCsOfPresentFaults (uint32_t* DTC_pu16, uint16_t ReadLimit_u16, FM_ProtocolType_En_t FM_ProtocolType_En);
extern uint16_t FM_GetNumberOfPresentFaults (void);

/**
*    @brief : Get the DTC value of a fault path.
*    @param : Fault Path.
*    @param : Fault type.
*    @return :16 bit P-code (power train code).
*/
extern uint32_t GetDTCofFltPathFltType (u16_FaultPath_t FaultPath, uint8_t FltType_u8, FM_ProtocolType_En_t FM_ProtocolType_En);
extern int16_t GetFltPathFltType_ByDTC (uint32_t DTC_u32, uint16_t* FltPath_pu16, uint8_t* FltType_pu8, FM_ProtocolType_En_t FM_ProtocolType_En);

extern int16_t FM_ReadFrzFrm_ByDTC (uint16_t DTC_u16, uint16_t* FrzFrmBuff_pu16, FM_ProtocolType_En_t FM_ProtocolType_En);
extern int16_t FM_ClrL2Err_ByDTC (uint16_t DTC_u16, FM_ProtocolType_En_t FM_ProtocolType_En);

extern void FML1_ClrAllFaults(void);

/**
*    @brief  Function returns the Fault path state of the L2 error memory.              
*    @param  FaultPath_au8 Status Array which contains the L2 Fault state.                      
*    @param  FaultState_au8 Status Array which contains the L2 Fault state.                      
*    @return Number of L2Errors
*  
*/
extern uint8_t FM_GetPathStateL2FaultMatrix(uint8_t* FaultPath_au8, uint8_t* FaultState_au8);

/**
*    @brief  Function to find number of all pending faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern u16_FaultPath_t FM_NofAllPndngFaults(void);

/**
*    @brief  Function to find number of all confirmed faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern uint8_t FM_NofAllCnfrmFaults(void);

/**
*    @brief  Wrapper function to know the status of Mal Indication Lamp.
*
*    @param  None.
*    @return TRUE: if MIL is ON, FALSE: otherwise.
*/
extern bool FM_StatusOf_MI(void);

/**
*    @brief  Function to get number of Active DTCs.
*
*    @param  DTCbuffer_pu32  buffer to hold the DTCs.
*    @return Number of DTCs.
*/
extern int8_t FM_GetTestActiveDTCs(uint32_t* DTCbuffer_pu32, FM_ProtocolType_En_t FM_ProtocolType_En) ;

/**
*    @brief  Function to get status of requested DTC.
*            Faultmanager maintains seperate 8-bit status field.
*            
*              byte7	byte6	byte5	byte4	byte3	byte2	byte1	byte0
*		                 Rdy    L2-D	 L2-H	 L2-C	 L2-P	 L1         
*
*            L1: Active or Current faults
*            L2-P: Potential or Pending faults 
*            L2-C: Confirmed faults
*            L2-H: Healing
*            L2-D: Deleting
*            Rdy: Readiness.
*            
*    @param  DTC_u32  requested DTC.
*    @return Status.
*/
extern FM_DTCStatus_Un_t FM_GetStatusOfDTCByDTCs(uint32_t DTC_u32, FM_ProtocolType_En_t FM_ProtocolType_En);


/**
*    @brief  Function to get all freezeframe recording DTCs.
*
*    @param  DTC_pu32  buffer to hold the DTCs.
*    @return Number of DTCs.
*/
extern int8_t FM_GetAllSnapshotRecordDTCs(uint32_t* DTC_pu32) ;

/**
*    @brief  Function to get freezeframe record ID by DTCs.
*
*    @param  DTC_u32  requested DTC.
*    @param  snapshot_records_ID_au8  id.
*    @return Number of DTCs.
*/
extern uint8_t FM_GetAllSnapshotRecordIDByDTC(uint32_t DTC_u32,uint8_t* snapshot_records_ID_au8) ;

/**
*    @brief  Function to get number of freezeframe records (First ocurence and last occurence).
*            We support First occurence hence records are 1.
*
*    @param  DTC_u32  requested DTC.
*    @param  record_number_u8 
*    @return Number of DTCs.
*/
extern uint8_t FM_GetNumberOfSnapshotRecordIdentifiersByDTC(uint32_t DTC_u32,uint8_t record_number_u8) ;

/**
*    @brief  Function to get DataIdentifiers of freezeframes for particular DTC.
*
*    @param  DTC_u32  requested DTC.
*    @param  record_number_u8 
*    @param  dataidentifiers_au8 
*    @return None.
*/
//extern void FM_GetDataIdentifiersByDTC(uint32_t DTC_u32, uint8_t record_number_u8,uint8_t* dataidentifiers_au8) ;

/**
*    @brief  Function to get all freezeframe recording DTCs under records.
*
*    @param  record_number_u8  .
*    @param  DTC_pu32  buffer to hold the DTCs.
*    @return Number of DTCs.
*/
extern int8_t FM_GetDTCsOfSnapshotRecordByRecordNumber(uint8_t record_number_u8,uint32_t* DTC_pu32) ;


/**
*    @brief  Function to get all stored recording DTCs under records.
*
*    @param  record_number_u8  .
*    @param  DTC_pu32  buffer to hold the DTCs.
*    @return Number of DTCs.
*/
extern int8_t FM_GetDTCsOfStoredRecordByRecordNumber(uint8_t record_number_u8,uint32_t* DTC_pu32);

extern int16_t FM_GetExtendedDataRecordByDTCNumber(uint32_t, uint8_t, uint8_t*,FM_ProtocolType_En_t);
/**
*    @brief  Function to read the freeze frame.
*
*    @param  DTC_pu32  buffer to hold the DTCs.
*    @param  record_number_u8  
*    @param  records_au16 array to hold the freeze data
*    @return Number of data record.
*/
extern int16_t FM_GetDataRecordsByDTC(uint32_t DTC_u32,uint8_t record_number_u8,uint16_t* records_au16, FM_ProtocolType_En_t FM_ProtocolType_En) ;

/**
*    @brief  Function to get priority of given DTC.
*
*    @param  DTC_u32  buffer to hold the DTCs.
*    @return Priority.
*/
extern uint8_t FM_GetSeverityMaskByDTC(uint32_t DTC_u32, FM_ProtocolType_En_t FM_ProtocolType_En) ;

/**
*    @brief  Function to get unctionality ID for the particular DTC that has sent
*
*    @param  DTC_u32  buffer to hold the DTCs.
*    @return Functional Unit or error.
*/
extern int16_t FM_GetFunctionalUnitOfDTCByDTC(uint32_t DTC_u32, FM_ProtocolType_En_t FM_ProtocolType_En) ;

/**
*    @brief  Function to get number of all supported DTCs.
*
*    @param  DTCbuffer_pu32  buffer to hold the DTCs.
*    @return Number of DTCs.
*/
extern uint8_t FM_GetAllSupportedDTCs(uint32_t* DTCbuffer_pu32, FM_ProtocolType_En_t FM_ProtocolType_En) ;

/**
*    @brief  Function to get DTC which was failed for the first time after clear diagnostic session.
*
*    @param  None.
*    @return First failed DTC.
*/
extern uint32_t FM_GetFirstTestFailedDTC(void) ;

/**
*    @brief  Function to get DTC which was confirmed for the first time after clear diagnostic session.
*    @param  None.
*    @return First failed DTC.
*/ 
extern uint32_t FM_GetFirstConfirmedDTC(void) ;

// return the DTC which was failed for the last time after clear diagnostic session
extern uint32_t FM_GetMostRecentTestFailedDTC(void) ;

// return the DTC which was confirmed for the last time after clear diagnostic session
extern uint32_t FM_GetMostRecentConfirmedDTC(void) ;


//return negative response
extern int32_t FM_MirrorMemoryExtendedDataByDTCNumber(uint32_t DTCnumber_u32, uint8_t* buffer);


//return negative responses

extern int8_t FM_GetDTCExtDataRecordByRecordNumber(uint32_t DTC_u32);

// return negative responses
extern int8_t FM_GetUserDefMemoryDTCByStatusMask(uint32_t DTC_u32);

//return negative responses
extern int8_t FM_GetUserDefMemoryDTCSnapshotRecordByDTCNumber(uint32_t DTC_u32);

//return negative responses
extern int8_t  FM_GetUserDefMemoryDTCExtDataRecordByDTCNumber(uint32_t DTC_u32);



/**
*    @brief  Function to get mirror memory of FreezeFrame.
*
*    @param  DTCbuffer_au8  holds themirror memory DTC.
*    @return Number of DTCs or error.
*/
extern int16_t FM_GetAllMirrorMemoryDTC(uint8_t* DTCbuffer_au8) ;

/**
*    @brief  Function to get the status of the Mirror DTC that has passed
*
*    @param  DTC_u32  mirror memory DTC.
*    @return Status or error.
*/
extern int16_t FM_GetStatusOfMirrorMemoryDTCByDTCs(uint32_t DTC_u32);


/**
*    @brief  Function to get the Permanent status DTCs.
*
*    @param  DTCbuffer_pu32   buffer.
*    @return Number of DTCs copied into buffer.
*/
extern int8_t FM_GetDTCWithPermanentStatus(uint32_t* DTCbuffer_pu32, FM_ProtocolType_En_t FM_ProtocolType_En);

/**
*    @brief  Function to get the fault detection counter value of the particular DTC
*
*    @param  DTC_u32   DTC.
*    @return Detection count or error.
*/
extern int16_t FM_GetDTCFaultDetectionCounterByDTC(uint32_t DTC_u32, FM_ProtocolType_En_t FM_ProtocolType_En) ;

// return number of DTCs that has written
// write the all the DTCs which have permanent status into the buffer
 //int16_t FM_GetDTCWithPermanentStatus(uint8_t* DTCbuffer_au8) ;


/**
*    @brief  Function to clear Diagnostic information fault.
*
*    @param  FM_FunctionalUnit_En   group of DTC.
*    @return stastus.
*/
extern bool FM_ClearDiagnosticInformationForDTCGroup(FM_FunctionalUnit_En_t FM_FunctionalUnit_En);
extern uint8_t FM_GetStatusAvailabiltyMask(void);
extern uint8_t FM_GetSeverityAvailabiltyMask(void);
/*
  @brief Function to get status availability mask.
  @retus status availability mask.
*/

/*
*    @brief  Function to get number of freezeframe records (First ocurence and last occurence).
*            We support First occurence hence records are 1.
*
*    @param  DTC_u32  requested DTC.
*    @param  record_number_u8 
*    @return Number of DTCs.
*/

extern uint8_t u8_FM_GetNumOfSnapshotDIDs(u16_FaultPath_t FltPath_En,  uint16_t idx);

extern bool GetHistoryFaultStatusByDTC(const uint32_t DTC_u32, FM_ProtocolType_En_t FM_ProtocolType_En);

extern uint8_t Rd_DTC_HistoryFlag(int8_t FltIndx_u8);

/*
 ***************************************************************************************************
 *    Export variables
 ***************************************************************************************************
*/  

extern uint16_t    ADCRawCntMAP_u16;
extern uint16_t    ADCRawCntACT_u16;

extern bool  FM_CEL_MIL_b;
extern bool  FM_GPL_b;

// RAM copy of the common data
extern FML2_CommonData_St_t  FML2_CommonNVData_St;

// Driving cycle Indicator - The flag is set 11 seconds after the engine is ON
extern bool FM_DrvCyInd_b;

// WUP cycle Indicator - The flag is set when engine coolant temperature 
// has increased by 275 degK and the minimum temperature of 
// 343 degK (70 deg Celcius).
extern bool FM_WUPCyInd_b;

// Operating hours for the current driving cycle
#if EUD_HDV_2005_55_EC
extern  uint16_t OperMin_CrntDryCyl_u16;
#endif

extern int8_t _FM_GetAllDeletingDTCs (uint16_t *DTCVal_pu16, FM_ProtocolType_En_t FM_ProtocolType_En);

//extern int8_t FML2_GetAllProtocolPndng_DTCs(uint32_t* DTCVal_pu32, uint16_t numdtc_req_u16, FM_ProtocolType_En_t FM_ProtocolType_En);
extern int8_t _FML2_GetAllPndng_DTCs(uint32_t *DTCVal_pu16, uint16_t numdtc_req_u16, FM_ProtocolType_En_t FM_ProtocolType_En);
#if ((TRUE == FM_OBD_SUPPORTED) || (TRUE == FM_J1939_SUPPORTED))
/* To do : For this project OBD faults are not required. So commented this for J1939. */ 
//extern int8_t _FML2_GetOBDPndng_DTCs(uint16_t *DTCVal_pu16, uint16_t numdtc_req_u16, FM_ProtocolType_En_t FM_ProtocolType_En);
//extern int8_t FML2_GetOBDPndng_ProtocolDTCs(uint16_t* DTCVal_pu16, uint16_t numdtc_req_u16, FM_ProtocolType_En_t FM_ProtocolType_En);
#endif

extern void FM_SetDTCBitMask(uint8_t u8_index, uint8_t u8_support);
extern void AcsDTCBitMask(void);

/**
*    @brief  Function to SET "Test failed since last clear" flag for a given faultpath & type.
*
*    @param  faultpath & fault type
*    @return TRUE: for valid faultpath value.
*    @return FALSE: for invalid faultpath value (out of range).
*/
extern bool  FM_SetTFSLC_ByFltPathFltType(u16_FaultPath_t FaultPath_En, uint8_t FltType_u8);

/**
*    @brief  Function to clear "Test failed since last clear" flag for a given faultpath & type.
*
*    @param  faultpath & fault type
*    @return TRUE: for valid faultpath value.
*    @return FALSE: for invalid faultpath value (out of range).
*/
extern bool  FM_ClrTFSLC_ByFltPathFltType(u16_FaultPath_t FaultPath_En, uint8_t FltType_u8);

/**
*    @brief  Function to clear "Test failed since last clear" flag for all fault paths.
*
*    @param  none
*    @return TRUE: reset all the flags.
*/
extern bool  FM_ClrTFSLC_All(void);
/**
*    @brief  Function to get the Test Failed Since last clear flag for a given fault path & type.
*
*    @param  fault path & fault type
*    @return TRUE: for valid faultpath value.
*			 FALSE: for invalid faultpath value.
*/
extern bool  FM_GetTFSLC_ByFltPathFltType(u16_FaultPath_t FaultPath_En, uint8_t FltType_u8);

extern int16_t FM_ReadFrzFrm_ByFltIndex(int8_t FltIndex_s8, uint8_t* destBuff_pu8, FM_ProtocolType_En_t FM_ProtocolType_En);
extern int16_t FM_ReadFrzFrm_ByFltPathFltType(u16_FaultPath_t FaultPath_En, uint8_t FltType_u8, uint8_t* destBuff_pu8, FM_ProtocolType_En_t FM_ProtocolType_En);



typedef enum
{
    FM_OBD_E = 0,
    FM_NONOBD_E,
    FM_ALL_E,
    FM_TOTAL_FAULT_TYPE_SUPPORTED_E
}FM_Fault_Type_En_t;

typedef enum
{
    FM_PRESENT_E = 0,
    FM_PENDING_E,
    FM_CONFIRMED_E,
    FM_DELETING_E,
    FM_TOTAL_FAULT_CONDITION_SUPPORTED
}FM_Fault_Condition_En_t;

extern int8_t FM_Get_DTCs(uint32_t* DTC_pu32, uint16_t ReadLimit_u16, FM_ProtocolType_En_t FM_ProtocolType_En, FM_Fault_Type_En_t FM_Fault_Type_En ,FM_Fault_Condition_En_t FM_Fault_Condition_En);
extern int8_t FM_FM_Get_DTCs(uint32_t* DTC_pu32, uint16_t numdtc_req_u16, FM_ProtocolType_En_t FM_ProtocolType_En, FM_Fault_Type_En_t FM_Fault_Type_En ,FM_Fault_Condition_En_t FM_Fault_Condition_En);

#endif


