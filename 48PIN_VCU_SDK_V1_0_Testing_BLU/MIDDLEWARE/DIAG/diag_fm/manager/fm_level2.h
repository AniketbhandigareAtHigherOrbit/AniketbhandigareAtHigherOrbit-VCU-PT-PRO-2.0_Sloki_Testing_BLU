/***************************************************************************************************
 *    FILENAME    : 
 *
 *    DESCRIPTION : 
 *
 *    $Id         : $    
 *
 ***************************************************************************************************
 * Revision history
 * 
 * Ver Author       Date       Description
 * 1             
 ***************************************************************************************************
*/

#ifndef    _FM_LEVEL2_H_
#define    _FM_LEVEL2_H_



/*
 ***************************************************************************************************
 *    Includes
 ***************************************************************************************************
*/
//#include "common.h"
#include <stdint.h>
#include "diag_typedefs.h"
#include "diag_adapt.h"
//#include "math_util.h"
#include "fm_conf.h"
#include "fmff_conf.h"

/*
 **************************************************************************************************
 *    Enum and Structure definition
 **************************************************************************************************
*/

/*
    Enum defining the state in power on MIL test
*/
typedef enum
{
    MIL_TEST_ON = 0,
    MIL_TEST_OFF1,
    MIL_TEST_RDY,    
    MIL_TEST_NOT_RDY,
    MIL_TEST_OFF2,
    MIL_TEST_DONE
}FML2_MIL_STATUS_En_t;

typedef enum
{
	FM_L2_ERR_ENTRY1 = 0,
	FM_L2_ERR_ENTRY2,
	FM_L2_ERR_ENTRY3,
	FM_L2_ERR_ENTRY4,
	FM_L2_ERR_ENTRY5,
	FM_L2_ERR_ENTRY6,
	FM_L2_ERR_ENTRY7,
	FM_L2_ERR_ENTRY8,
	FM_L2_ERR_ENTRY9,
	FM_L2_ERR_ENTRY10
}FML2_ERR_ENTRY_En_t;

/*
    Timings involved in power on MIL test
*/ 
#define MIL_TEST_ON_TIME_MS      5000   //MIL on time in milli seconds
#define MIL_TEST_OFF1_TIME_MS    10000  //MIL off time1 in milliseconds
#define MIL_TEST_RDY_TIME_MS     5000   //MIL on time  if readiness is completed
                                        //in milliseconds
#define MIL_TEST_NOTRDY_TIME_MS  500    //MIL on-off time  if readiness is not
                                        //completedin milliseconds
#define MIL_TEST_OFF2_TIME_MS    5000   //MIL off time2 in milliseconds

#define MIL_NOT_RDY_PATTERN_REPEAT    (MIL_TEST_RDY_TIME_MS/MIL_TEST_NOTRDY_TIME_MS)


/*
    States of a Fault in L2 NV Memory array
*/
typedef enum 
{
    FM_NOENTRY = 0,
    FM_POTENTIAL,
    FM_CONFIRMED,    
    FM_HEALING,      // also called as "previously" active DTC
    FM_DELETING,
    NUM_OF_MEMSTATES
}FML2_FaultState_En_t;

/*
    Status Register of an L2 Fault object.
    
    Note:    
    Bit positions in the status register should not be disturbed and 
    bits positions should be identitical to the L1 status register
    (FML1_StatusReg_Uni_t)
*/
//#pragma pack (1)
typedef union
{
    struct
    {
        /* Byte - 0 */
        uint32_t    FerErr    : 1;     // Error Type: Functional error
        uint32_t    NplErr    : 1;     // Error Type: Non-plausible error
        uint32_t    SigErr    : 1;     // Error Type: Signal error
        uint32_t    MinErr    : 1;     // Error Type: Minimum error
        uint32_t    MaxErr    : 1;     // Error Type: Maximum error
        uint32_t    Priority  : 3;     // Fault Priority

        /* Byte - 1 */
        uint32_t    Erf       : 1;     // Error Flag
        uint32_t    MIL_Indi  : 1;     // Fault is MIL indictable
        uint32_t    GPL_Indi  : 1;     // Fault is GPL indictable
        uint32_t    Prsnt_FltSt: 4;    // Present Level-2 Fault states as defined by FML2_FaultState_En_t. 
        uint32_t    Prev_FltSt : 4;    // Previous Level-2 Fault states as defined by FML2_FaultState_En_t. 
        uint32_t    Occur_Count : 7;   // Occurrance count should increment only once of it's first occurrance (increments after every reset)

        /* Byte - 1, 2 & 3 */
        uint32_t    Reserved : (6);    // Reserved.
    }Reg_St;
    U32_St_t      Reg;             
}FML2_StatusReg_Uni_t;  

/*
    Level-2 fault memory structure.
    @code tag - @[CODE_FML2_FLTMEM]@{SDD_FML2_FLTMEM}
*/



// 0x370 bytes - with union, 2 entries
// 0x488 bytes - with no union, 2 entries
// 0x258 bytes - with no union, no uint16_t[]
// 0x208 bytes - with pack(1), no union, no uint16[]
// 0x320 bytes - pack(1), union, 2 entries 
// 0x438 bytes - pack(1), no union, 2 entries 
// 0x2f8 bytes (760 bytes) - pack1, union, 2 ntries [13],[26]
//


#pragma pack (1)//todo harsh
typedef struct
{
    FML2_StatusReg_Uni_t   FML2_StatusReg_Uni; // Status register  (4)
#if (TRUE == FM_UDS_SUPPORTED)
    uint8_t                L2FrzFrm_UDS_au8[FMFF_CONF_UDS_FRZFRM_TOTALBYTES]; 	   // Manufacturer specific non-OBD frz frm buffer
#endif
    
#if (TRUE == FM_OBD_SUPPORTED)
    uint8_t                L2FrzFrm_OBD_au8[FMFF_CONF_OBD_FRZFRM_TOTALBYTES]; 	   // Manufacturer specific non-OBD frz frm buffer
#endif
    
#if (TRUE == FM_J1939_SUPPORTED)
/* To do : For this project OBD faults are not required. So commented this for J1939. */ 
    // uint8_t                L2FrzFrm_J1939_au8[FMFF_CONF_J1939_FRZFRM_TOTALBYTES]; 	// Manufacturer specific non-OBD frz frm buffer
#endif
    
    uint16_t               FreqCnt_u16;                 // Fault Frequency counter. (2)
//#if EUD_HDV_2005_55_EC
    uint16_t               OperMin_WthoutErr_Total_u16; // Operating minutes of the fault incase of 2005/55/EC directive (2)
//#endif
    uint8_t                WUPCylCnt_u8;                // WUP cycle counter for the state transitions.  (1)
    uint8_t                DrvCylCnt_u8;                // Driving cycle counter for the state transitions. (1)
    FM_FaultPath_En_t      FaultPath_En;                // Fault Paths  (2)
    bool                   Upd_St;                      // Updation status (1)
    uint32_t               error_handle;                // This helps in finding out the oldest data in flash (4)
                                                        // When the fault is getting registered in flash, value in 
                                                        // global variable "" is moved to this.
	uint16_t 			   OperationCycle_u16;			// Operation cycle count
}FML2_FaultMem_St_t; 

/*
 **************************************************************************************************
 *    Function Prototype
 **************************************************************************************************
*/

/*
 *****************************************************
    Functions which are exported to Task scheduler
 *****************************************************
*/
/**
*    @brief  Initialization function for Fault management level-2.
*    @param  None
*    @return None
*/
extern void FML2_Init(void);

/**
 *    @brief  Initialization function for the status flag of occurrence count
 *
 *    @param  None
 *    @return None
 */
extern void FM_OCcnt_StatusInit(void);

/**
*    @brief  Task to handle the level-2 fault history state machine.
*            The task is scheduled by Fault manager scheduler every 1000ms.
*    @param  None
*    @return None
*/
extern void FML2_FltHndl_proc(void);

/**
*    @brief  Task to change the state of faults based on EUD_HDV_2005_55_EC
*            1:This task will be called from the fault manager scheduler
*               every 1 min
*
*    @param  None
*    @return None
*/
extern void FML2_FltHndl_EUD_HDV_2005_55_EC_proc(void);

/**
*    @brief : Task to test the Mal Function Lamp Test.
*             The task is scheduled by Fault manager scheduler every 1000ms.
*    @param : none.
*    @return :none.
*/
extern void FML2_TestMIL_proc (void);

/**
*    @brief : Task to onitor the state of the MIL. The function modifies the MIL status 
*             depending on the status of the level-2 faults.s
*             The task is scheduled by Fault manager scheduler every 1000ms.
*    @param : none.
*    @return :none.
*/
extern void FML2_MonWarnLamp_proc (void);

/**
*    @brief  Task to respond to the level-1's indication to register the fault.
*            The task keeps track of the faults in level-1 for registering it into level-2.
*            The task is scheduled by Fault manager scheduler every 1000ms.
*    @param  None.
*    @return None.
*/
extern int8_t FML2_CopyL1_to_L2 (u16_FaultPath_t, uint8_t);

/**
*    @brief : Tasks to check for any changes in the level-2 fault memory.
*             If yes, update the same to the NV memory.
*             The task is scheduled by Fault manager scheduler every 1000ms.
*    @param : .
*    @param : .
*    @return :.
*/
extern void FML2_UpdtNVMem_proc (void);

/**
*    @brief : Poweroff function for FM level2 operation.
*             This function ensures incase the level-2 fault memory has undergone
*             some modifictaion and is not yet updated to NV memory. 
*    @param : none.
*    @return :none.
*/
extern void FML2_PwrOff(void);  

/*
 *****************************************************
    APIs for EOBD/Application software
 *****************************************************
*/
/**
*    @brief : Function to find number of the all NONOBD related faults in L2 memory
*    @param : none.
*    @return No of faults
*/
extern uint8_t FML2_NofAllNONOBDFaults(void); 

/**
*    @brief  Function to find number of the pending NONOBD related faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern u16_FaultPath_t FML2_NofPndngNONOBDFaults(void);

/**
*    @brief  Function to find number of the confirmed NONOBD related faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern uint8_t FML2_NofCnfrmNONOBDFaults(void);

/**
*    @brief  Function to find number of the deleting NONOBD related faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern uint8_t FML2_NofDeletingNONOBDFaults(void);

/**
*    @brief  Function to find number of all faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern uint8_t FML2_NofAllFaults(void);

/**
*    @brief  Function to find number of all pending faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern u16_FaultPath_t FML2_NofAllPndngFaults(void);

/**
*    @brief  Function to find number of all confirmed faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern uint8_t FML2_NofAllCnfrmFaults(void);

/**
*    @brief  Function to find number of all deleting faults in L2 memory
*
*    @param  None
*    @return No of faults
*/
extern uint8_t FML2_NofAllDeletingFaults(void);

/**
*    @brief : Function to know the status of Mal Indication Lamp.
*    @param : None.
*    @return :TRUE: if MIL is ON, FALSE: otherwise.
*/
extern bool FML2_StatusOf_MI (void);

/**
*    @brief : Function to turn ON the MIL.
*    @param : none.
*    @return :none.
*/
extern void FML2_TurnOnMI (void);

/**
*    @brief : Function to turn OFF the MIL.
*    @param : none.
*    @return :none.
*/
extern void FML2_TurnOffMI (void);

/**
*    @brief : Function to know the status of Glow plug lamp
*    @param : None.
*    @return :TRUE: if GPL is ON, FALSE: otherwise.
*/
extern bool FML2_StatusOf_GPL (void);

/**
*    @brief : Function to turn ON the GPL.
*    @param : none.
*    @return :none.
*/
extern void FML2_TurnOnGPL (void);

/**
*    @brief : Function to turn OFF the GPL.
*    @param : none.
*    @return :none.
*/
extern void FML2_TurnOffGPL (void);

/**
*    @brief : Function to clear the all NONOBD related faults in L2 memory
*    @param : none.
*    @return :none.
*/
extern void FML2_ClrAllNONOBDFaults(void);

/**
*    @brief  Function to clear the pending NONOBD related faults in L2 memory
*
*    @param  None
*    @return None
*/
extern void FML2_ClrPndngNONOBDFaults(void);

/**
*    @brief  Function to clear the confirmed NONOBD related faults in L2 memory
*
*    @param  None
*    @return None
*/
 void FML2_ClrCnfrmNONOBDFaults(void);

/**
*    @brief  Function to clear the deleting NONOBD related faults in L2 memory
*
*    @param  None
*    @return None
*/
extern void FML2_ClrDeletingNONOBDFaults(void);

/**
*    @brief  Function to clear all faults in L2 memory
*
*    @param  None
*    @return None
*/
extern void FML2_ClrAllFaults(void);

/**
*    @brief  Function to clear all pending faults in L2 memory
*
*    @param  None
*    @return None
*/
extern void FML2_ClrAllPndngFaults(void);

/**
*    @brief  Function to clear all confirmed faults in L2 memory
*
*    @param  None
*    @return None
*/
extern void FML2_ClrAllCnfrmFaults(void);

/**
*    @brief  Function to clear all deleting faults in L2 memory
*
*    @param  None
*    @return None
*/
extern void FML2_ClrAllDeletingFaults(void);

/**
*    @brief : Function to read the NONOBD specific Freeze frame from level-2 fault memory.
*    @param : Index to the level-2 fault memory array.
*    @param : Address of the buffer where the freeze frames datas are copied.
*    @return :negative response code. 0: for successful reading, 1: for failure.
*/
extern uint8_t FML2_ReadCmpltNONOBDFrzFrm(uint16_t DTC_u16, uint16_t* DataBuff_pu16, FM_ProtocolType_En_t FM_ProtocolType_En);

/**
*    @brief  Function fills the parameter pointer with DTC codes of confirmed
*            NON OBD faults
*
*    @param  Pointer to update the DTC codes
*
*    @return Number of DTC codes copied
*/
extern int8_t _FML2_GetAllCnfrmNONOBD_DTCs (uint32_t *DTCVal_pu32, FM_ProtocolType_En_t FM_ProtocolType_En);

/**
*    @brief  Function fills the parameter pointer with DTC codes of confirmed
*            OBD and NON OBD faults
*
*    @param  Pointer to update the DTC codes
*
*    @return Number of DTC codes copied
*/
extern int8_t _FML2_GetAllCnfrmDTCs (uint32_t *DTCVal_pu32, FM_ProtocolType_En_t FM_ProtocolType_En);

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
extern int8_t FML2_GetCnfrmNONOBD_DTC (uint8_t EntryNum_u8, uint32_t *DTCVal_pu32, FM_ProtocolType_En_t FM_ProtocolType_En);

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
extern int8_t FML2_GetCnfrmDTC (uint8_t EntryNum_u8, uint32_t *DTCVal_pu32, FM_ProtocolType_En_t FM_ProtocolType_En);

/**
*    @brief  Function fills the parameter pointer with fault type and 
*            fault paths of NON OBD related entries in L2 memory
*
*    @param  pointer to update the FltPaths
*    @param  Pointer to update the FltTypes
*
*    @return Number of NON OBD related faults in L2 memory
*/
extern int8_t FML2_GetAllCnfrmNONOBD_FltPaths_FltTypes (uint16_t* FltPath_pu16, uint8_t* FltType_pu8);

/**
*    @brief  Function fills the parameter pointer with fault type and 
*            fault paths of all (OBD + NON-OBD) entries in L2 memory
*
*    @param  pointer to update the FltPaths
*    @param  Pointer to update the FltTypes
*
*    @return Number of OBD + NON-OBD related faults in L2 memory
*/
extern int8_t FML2_GetAllCnfrm_FltPaths_FltTypes (uint16_t* FltPath_pu16, uint8_t* FltType_pu8);

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
extern int8_t FML2_GetCnfrmNONOBD_FltPath_FltType (uint8_t EntryNum_u8, uint16_t* FltPath_pu16, uint8_t* FltType_pu8);

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
extern int8_t FML2_GetCnfrm_FltPath_FltType (uint8_t EntryNum_u8, uint16_t* FltPath_pu16, uint8_t* FltType_pu8);


extern int16_t FML2_ClrL2Err_ByDTC (uint16_t DTC_u16, FM_ProtocolType_En_t FM_ProtocolType_En);

/*
 ***************************************************************************************************
 *    Global variables
 ***************************************************************************************************
*/
//To hold the state of MIL test
extern uint8_t MIL_Test_Mode_u8;
/* Holds the Occurrenc count */
extern bool IncCntState_ab[FM_CONF_MAX_L2FAULT_ENTRIES];
/* */
extern FML2_FaultMem_St_t    FML2_FaultMem_aSt[FM_CONF_MAX_L2FAULT_ENTRIES]; 
/* */
extern int8_t  FML2_GetFltIndxOfPath(u16_FaultPath_t,uint8_t);

/*
 **************************************************************************************************
 *    MACROS for Level-2
 **************************************************************************************************
*/
#define FML2_GetPrsntFaultState(FltIndx_u8)       	(FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.Prsnt_FltSt)
#define FML2_GetPrevFaultState(FltIndx_u8)       	(FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.Prev_FltSt)

#define FML2_SetPrsntFaultState(FltIndx_u8, val)    (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.Prsnt_FltSt = val)
#define FML2_SetPrevFaultState(FltIndx_u8, val)     (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.Prev_FltSt = val)

#define FML2_IncOccurCnt(FltIndx_u8)                (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.Occur_Count++)
#define FML2_GetOccurCnt(FltIndx_u8)                (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.Occur_Count)
#define FML2_SetOccurCnt(FltIndx_u8, val)           (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.Occur_Count = val)

#define FML2_GetPriority(FltIndx_u8)         (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.Priority)
#define FML2_SetPriority(FltIndx_u8, val)    (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.Priority = val)

#define FML2_GetErrorHandle(FltIndx_u8)      (FML2_FaultMem_aSt[FltIndx_u8].error_handle)
#define FML2_SetErrorHandle(FltIndx_u8,val)  (FML2_FaultMem_aSt[FltIndx_u8].error_handle = val)

#define FML2_GetFreqCtr(FltIndx_u8)      (FML2_FaultMem_aSt[FltIndx_u8].FreqCnt_u16      )
#define FML2_IncFreqCtr(FltIndx_u8)      (FML2_FaultMem_aSt[FltIndx_u8].FreqCnt_u16++    )
#define FML2_DecFreqCtr(FltIndx_u8)      (FML2_FaultMem_aSt[FltIndx_u8].FreqCnt_u16--    )
#define FML2_ClrFreqCtr(FltIndx_u8)      (FML2_FaultMem_aSt[FltIndx_u8].FreqCnt_u16 = 0  )
#define FML2_SetFreqCtr(FltIndx_u8, val) (FML2_FaultMem_aSt[FltIndx_u8].FreqCnt_u16 = val)

#define FML2_SetDrvCyCtr(FltIndx_u8, val)    (FML2_FaultMem_aSt[FltIndx_u8].DrvCylCnt_u8 = val)
#define FML2_GetDrvCyCtr(FltIndx_u8)         (FML2_FaultMem_aSt[FltIndx_u8].DrvCylCnt_u8      )
#define FML2_RstDrvCyCtr(FltIndx_u8)         (FML2_FaultMem_aSt[FltIndx_u8].DrvCylCnt_u8 = 0  )
#define FML2_IncDrvCyCtr(FltIndx_u8)         (FML2_FaultMem_aSt[FltIndx_u8].DrvCylCnt_u8++    )
#define FML2_DecDrvCyCtr(FltIndx_u8)         (FML2_FaultMem_aSt[FltIndx_u8].DrvCylCnt_u8--    )

#define FML2_SetWUPCyCtr(FltIndx_u8, val)     (FML2_FaultMem_aSt[FltIndx_u8].WUPCylCnt_u8 = val)
#define FML2_RstWUPCyCtr(FltIndx_u8)        (FML2_FaultMem_aSt[FltIndx_u8].WUPCylCnt_u8 = 0)
#define FML2_GetWUPCyCtr(FltIndx_u8)          (FML2_FaultMem_aSt[FltIndx_u8].WUPCylCnt_u8)
#define FML2_IncWUPCyCtr(FltIndx_u8)         (FML2_FaultMem_aSt[FltIndx_u8].WUPCylCnt_u8++    )
#define FML2_DecWUPCyCtr(FltIndx_u8)         (FML2_FaultMem_aSt[FltIndx_u8].WUPCylCnt_u8--    )

#define FML2_GetDistDrv_MILOn_Kms()          (FML2_CommonNVData_St.DistDrv_MILOn_kms_u16)
#define FML2_GetTimeDrv_MILOn_min()          (FML2_CommonNVData_St.Time_MILOn_min_u16)
#define FML2_GetDistDrvSi_DTCClr_Kms()       (FML2_CommonNVData_St.DistDrvSi_DTCClr_kms_u16)
#define FML2_GetTimeDrvSi_DTCClr_min()       (FML2_CommonNVData_St.TimeSi_DTCClr_min_u16)
#define FML2_GetWUPSi_DTCClr()               (FML2_CommonNVData_St.WUPSi_DTCClr_u8)
#define FML2_GetNofFltEntry()                (FML2_CommonNVData_St.FM_FltEntryCnt_u8)
#define FML2_GetMIL_Status()                 (FML2_CommonNVData_St.FM_MI_Status_b)

#define FML2_GetFaultPath(FltIndx_u8)        (FML2_FaultMem_aSt[FltIndx_u8].FaultPath_En)
#define FML2_SetFaultPath(FltIndx_u8, value) (FML2_FaultMem_aSt[FltIndx_u8].FaultPath_En = value)

#define FML2_SetMIL_Indicatable(FltIndx_u8)    (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.MIL_Indi = TRUE)
#define FML2_ClrMIL_Indicatable(FltIndx_u8)    (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.MIL_Indi = FALSE)
#define FML2_GetMIL_Indicatable(FltIndx_u8)    (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.MIL_Indi)

#define FML2_SetGPL_Indicatable(FltIndx_u8)    (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.GPL_Indi = TRUE)
#define FML2_ClrGPL_Indicatable(FltIndx_u8)    (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.GPL_Indi = FALSE)
#define FML2_GetGPL_Indicatable(FltIndx_u8)    (FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg_St.GPL_Indi)

#if EUD_HDV_2005_55_EC
     uint16_t OperMin_CrntDryCyl_u16;
    
    #define FML2_UptOPMWE(FltIndx_u8)  FML2_FaultMem_aSt[FltIndx_u8].OperMin_WthoutErr_Total_u16 += (OperMin_CrntDryCyl_u16 - OpMin_WOE_CDC_u16[FltIndx_u8]); OpMin_WOE_CDC_u16[FltIndx_u8] = OperMin_CrntDryCyl_u16    
    #define FML2_GetOPMWE(FltIndx_u8)  FML2_FaultMem_aSt[FltIndx_u8].OperMin_WthoutErr_Total_u16
    #define FML2_RstOPMWE(FltIndx_u8)  FML2_FaultMem_aSt[FltIndx_u8].OperMin_WthoutErr_Total_u16 = 0;OpMin_WOE_CDC_u16[FltIndx_u8] = OperMin_CrntDryCyl_u16   
#endif

#define FML2_SetErrType(FltIndx_u8, val)   ((FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg.byt_St.hh_u8) |= (val & ERRORTYPE_FIELD))
#define FML2_ClrErrType(FltIndx_u8)        ((FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg.byt_St.hh_u8) &= (~ERRORTYPE_FIELD))
#define FML2_GetErrType(FltIndx_u8)        ((FML2_FaultMem_aSt[FltIndx_u8].FML2_StatusReg_Uni.Reg.byt_St.hh_u8) & ERRORTYPE_FIELD)

/* @code tag - @[CODE_FML2_GET_FRZFRM_VALUE]@{SDD_FML2_GET_FRZFRM_VALUE} */
#define FML2_GET_FRZFRM_VALUE(FltIndx_u8,PID_ind) (FML2_FaultMem_aSt[FltIndx_u8].L2FrzFrm_au8[PID_ind])

#define FML2_SetUpt_St(FltIndx_u8)         (FML2_FaultMem_aSt[FltIndx_u8].Upd_St = TRUE)
#define FML2_ClrUpt_St(FltIndx_u8)         (FML2_FaultMem_aSt[FltIndx_u8].Upd_St = FALSE)
#define FML2_GetUpt_St(FltIndx_u8)         (FML2_FaultMem_aSt[FltIndx_u8].Upd_St)

/* @code tag - @[CODE_FML2_CPY_FRZFRM]@{SDD_FML2_CPY_FRZFRM} */
#define FML2_Cpy_FrzFrm(FltInd,FltPath,ind) (FML2_FaultMem_aSt[FltInd].L2FrzFrm_au8[ind] = FaultPath_aSt[FltPath].L1FrzFrm_au8[ind])

extern int8_t _FML2_GetAllDeletingDTCs (uint16_t *DTCVal_pu16, FM_ProtocolType_En_t FM_ProtocolType_En);

extern int8_t _FML2_GetAllDeletingNONOBD_DTCs (uint16_t *DTCVal_pu16, FM_ProtocolType_En_t FM_ProtocolType_En);
extern int16_t FML2_GetFaultIndexByDTC (uint32_t DTC_u32, FM_ProtocolType_En_t FM_ProtocolType_En);

//static void   ClrFltEntry(uint8_t);
extern void   ClrFltEntry(uint8_t);

extern int8_t FML2_Get_DTCs(uint32_t* DTC_pu32, uint16_t numdtc_req_u16, FM_ProtocolType_En_t FM_ProtocolType_En, FM_Fault_Type_En_t FM_Fault_Type_En ,FM_Fault_Condition_En_t FM_Fault_Condition_En);

#endif


