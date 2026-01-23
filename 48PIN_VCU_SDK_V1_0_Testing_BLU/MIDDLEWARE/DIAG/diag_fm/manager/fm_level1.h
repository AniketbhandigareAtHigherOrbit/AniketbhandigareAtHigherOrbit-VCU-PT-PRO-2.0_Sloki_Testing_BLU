/***************************************************************************************************
 *    FILENAME    : fm_level1.h
 *
 *    DESCRIPTION : File defines all the functions related to Fault manager Level 1
 *
 *    $Id         : $    
 *
 ***************************************************************************************************
 * Revision history
 * 
 * Ver Author       Date       Description
 * 1                17/09/2008
 ***************************************************************************************************
*/

#ifndef    _FM_LEVEL1_H_
#define    _FM_LEVEL1_H_

/* Centralized declaration of variables */
#ifdef MAIN
#define
#else
#define MAIN  
#endif

/*
 ***************************************************************************************************
 *    Includes
 ***************************************************************************************************
*/
//#include "common.h"
#include <stdint.h>
#include "fm_conf.h"
#include "diag_typedefs.h"
#include "diag_adapt.h"
#include "fmff_conf.h"

#include "fm.h"
/*
 ***************************************************************************************************
 *    Defines
 ***************************************************************************************************
*/
#if BIGENDIAN_SYSTEM
    #define ERRORTYPE_FIELD      0xF8
#else
    #define ERRORTYPE_FIELD      0x1F
#endif

#define MASK_ERRORTYPE       (~ERRORTYPE_FIELD)

/*
 **************************************************************************************************
 *    Enum definition
 **************************************************************************************************
*/
typedef enum
{
    FML1_IDLE_E = 0,            // Idle state - No report for the fault from application layer
    FML1_DEBRDY_E,              // Debounce to Ready state for the readiness test
    FML1_RDYCMPLT_E,            // Readiness completion

    FML1_DEBMAXDFCT_E,          // Debounce to defect (Max error) for the defect deboucing at Level-1
    FML1_DEBMINDFCT_E,          // Debounce to defect (Min error) for the defect deboucing at Level-1
    FML1_DEBSIGDFCT_E,          // Debounce to defect (Sig error) for the defect deboucing at Level-1
    FML1_DEBNPLDFCT_E,          // Debounce to defect (Non plausible  error) for the defect deboucing at Level-1
    FML1_DEBFERDFCT_E,          // Debounce to defect (Functional error) for the defect deboucing at Level-1
    
    FML1_DEBHEAL_E,             // Debounce to Heal for the defect deboucing at Level-1
    FML1_HEALED_E,              // Healed state
    FML1_DFCTCNFRMD_E,          // Confirmed state for the fault at Level-1
    NUM_OF_FML1STATES_E         // Total number of L1 debouncing states
}FML1_DebState_En_t;

/*
 **************************************************************************************************
 *    Structure definition
 **************************************************************************************************
*/
// CP - continously present

typedef union
{
    U16_St_t wrd;
    
    struct
    {
        // Byte 0
        uint16_t    FerCp     : 1;     // Fer is continuously present in the current driving cycle.
        uint16_t    NplCp     : 1;     // Npl is continuously present in the current driving cycle.
        uint16_t    SigCp     : 1;     // Sig is continuously present in the current driving cycle.
        uint16_t    MinCp     : 1;     // Min is continuously present in the current driving cycle.
        uint16_t    MaxCp     : 1;     // Max is continuously present in the current driving cycle.
        uint16_t    Reserved1 : 3;     // Reserved.

        
        //Byte 1
        // Status says this error has already occured 
        //once and got cleared so not present continously
        uint16_t    StFerCp  : 1;
        uint16_t    StNplCp  : 1;
        uint16_t    StSigCp  : 1;
        uint16_t    StMinCp  : 1;
        uint16_t    StMaxCp  : 1;
        uint16_t    Reserved2 : 3;
    }bf;

    
}FML1_FltPrCt_St_t;

/*
    Structure to hold the result of the readiness monitoring
    
    'RdyMonMat_au8': 
    
         Brief:This is the readiness monitoring matrix maintained in RAM.
               During power on this matrix is downloaded from the NV memory
               and updated in to this array.Readiness status is updates in 
               to NV RAM in a periodic fashion by FM level 2 software.One bit
               is assigned per fault path
               
*/

//#define SIZE_OF_RDY_MON_MAT 	(NUM_OF_FAULTPATHS_E/8)+1
#define SIZE_OF_RDY_MON_MAT 	8

//#pragma pack (1)
/**
***************************************************************************************************
This matrix contains # of entries which is equivalent to number of fault paths.
Each entry signifies individual faultpath with each bit reserved for individual fault type.
In future, 3 more different type of faults can be added if required.
Particular bit shall be set to HIGH when a particular fault type is reported to the FM.
This matrix shall be stored in EEPROM. 
This matrix is reset to ZERO only when clear request comes from the tester.
The matrix is not cleared because of auto healing of the fault. With auto healing the fault entry from
L1 & L2 are removed but not from this matrix.
***************************************************************************************************
ARRANGEMENT of TFSLC_Mat_au8:
TFSLC_Mat_au8[0] = [NPL,	FER,	SIG,	MIN,	MAX, 	x,	 	x,	 	x], where 'x' is 'Not used'.
TFSLC_Mat_au8[1] = [NPL,	FER,	SIG,	MIN,	MAX, 	x,	 	x,	 	x], where 'x' is 'Not used'.
TFSLC_Mat_au8[2] = [NPL,	FER,	SIG,	MIN,	MAX, 	x,	 	x,	 	x], where 'x' is 'Not used'.
	;
	;
	;
TFSLC_Mat_au8[NUM_OF_FAULTPATHS_E] = [NPL,	FER,	SIG,	MIN,	MAX, 	x,	 	x,	 	x], where 'x' is 'Not used'.
***************************************************************************************************
*/
typedef struct
{
    uint8_t                RdyMonMat_au8[SIZE_OF_RDY_MON_MAT];      // Readiness Monitoring Matrix to hold total of 256 bits
    uint8_t                TFSLC_Mat_au8[NUM_OF_FAULTPATHS_E];      // Test Failed Since Last Clear Matrix (5 bits per every byte is used)
    FML1_FltPrCt_St_t      FltCp_aSt[NUM_OF_FAULTPATHS_E];          // Array to hold the fault existance 
                                                                    // info in the current driving cycle
    bool                 RdyChngd_b;                                // Matrix value changed. Indication to write to NV memory
}FML1_FltMon_St_t;


/*
    The Fault Manager Level-1 Status register (size:32bits)

    Note:
    Bit positions in the status register should not be disturbed and 
    bits positions should be identitical to the L2 status register
    (FML2_StatusReg_Uni_t)
    
    @code tag - @[CODE_DERIVED_FML1_STREG]@{SDD_DERIVED_FML1_STREG}
*/

typedef union
{
    //#pragma bit_order
    struct
    {
        /* Byte - 0 */
        uint32_t    FerErr  : 1;     // Error Type: Functional error
        uint32_t    NplErr  : 1;     // Error Type: Non-plausible error
        uint32_t    SigErr  : 1;     // Error Type: Signal error
        uint32_t    MinErr  : 1;     // Error Type: Minimum error
        uint32_t    MaxErr  : 1;     // Error Type: Maximum error
        uint32_t    Priority: 3;     // Fault Priority

        /* Byte - 1 */
        /*uint32_t    FerMask : 1;     // Mask for Functional error    (Not used)
        uint32_t    NplMask : 1;     // Mask for Non-plausible error (Not used)
        uint32_t    SigMask : 1;     // Mask for Signal error        (Not used)
        uint32_t    MinMask : 1;     // Mask for Minimum error       (Not used)    
        uint32_t    MaxMask : 1;     // Mask for Maximum error       (Not used) */
        uint32_t TF_b0       : 1;    //Testfailed
        uint32_t TFTOC_b1    : 1;    //TestFailedThisOperationCycle
        uint32_t PDTC_b2     : 1;    //PendingDTC
        uint32_t CDTC_b3     : 1;    //ConfirmedDTC
        uint32_t TNCSLC_b4   : 1;    //TestNotCompletedSinceLastClear
        uint32_t TFSLC_b5    : 1;    //TestFailedSinceLastClear
        uint32_t TNCTOC_b6   : 1;    //TestNotCompletedThisOperationCycle
        uint32_t WIR_b7      : 1;    //WarningIndicatorRequested   

        /* Byte - 2 */
        uint32_t    FerMem  : 1;     // Fer Fault memorized in Level-2.(Not used)
        uint32_t    NplMem  : 1;     // Npl Fault memorized in Level-2.(Not used)
        uint32_t    SigMem  : 1;     // Sig Fault memorized in Level-2.(Not used)
        uint32_t    MinMem  : 1;     // Min Fault memorized in Level-2.(Not used)
        uint32_t    MaxMem  : 1;     // Max Fault memorized in Level-2.(Not used)
        uint32_t    RdyGrp  : 3;     // Readiness group.

        /* Byte - 3 */
        uint32_t    DebSt   : 4;     // Level-1 Debounce status. 
        uint32_t    Upd_St  : 1;     // Updation status
        uint32_t    Erf     : 1;     // Error Flag
        uint32_t    Rdy     : 1;     // Readiness flag.
        uint32_t    Tst     : 1;     // Fault Test flag for the Current driving cycle.
    }Reg_St;
    U32_St_t      Reg;             
}FML1_StatusReg_Uni_t; 

/*
 **************************************************************************************************
    Variable declaration
 **************************************************************************************************
*/

/*
 **************************************************************************************************
    The Fault Manager Level-1 Data structure
 **************************************************************************************************
@code tag - @[CODE_DERIVED_FML1_FLTPATH]@{SDD_DERIVED_FML1_FLTPATH}
@code tag - @[CODE_DERIVED_FML1_FLTPATH_STR]@{SDD_DERIVED_FML1_FLTPATH_STR}
*/
#pragma pack (1)
typedef struct
{
    FML1_StatusReg_Uni_t  L1StReg_Uni;          	// FM Level-1 Status register 
    int16_t                DebCnt_u16;           	// Debounce to defect and debounce to heal counter.
    int16_t                ActDebCnt_u16;
#if (TRUE == FM_UDS_SUPPORTED)
    uint8_t                L1FrzFrm_UDS_au8[FMFF_CONF_UDS_FRZFRM_TOTALBYTES]; 	// Manufacturer specific non-OBD frz frm buffer
#endif
    
#if (TRUE == FM_OBD_SUPPORTED)
    uint8_t                L1FrzFrm_OBD_au8[FMFF_CONF_OBD_FRZFRM_TOTALBYTES]; 	// Manufacturer specific non-OBD frz frm buffer
#endif
    
#if (TRUE == FM_J1939_SUPPORTED)
    ////////////// To do : For this project freeze frames are not required. So commented this for J1939.
    // uint8_t                L1FrzFrm_J1939_au8[FMFF_CONF_J1939_FRZFRM_TOTALBYTES]; 	// Manufacturer specific non-OBD frz frm buffer
#endif
    
}FML1_FaultPath_St_t;




/*
 **************************************************************************************************
 *    Function  prototype
 **************************************************************************************************
*/
extern bool	FML1_FrzFrmUpdated_b;
/*
 *****************************************************
    Functions which are exported to Task scheduler
 *****************************************************
*/
/**
*    @brief : Initialization function for Fault manager level-1.
*    @param : none.
*    @return :none.
*/
extern void FML1_Init (void);

/**
*    @brief : Task for Readiness monitoring.
*    @param : none.
*    @return :none.
*/
extern void FML1_HndlRdy (void);

/**
*    @brief : Power off function for readiness monitoring flags.
*    @param : none.
*    @return :none.
*/
extern void FML1_Rdy_pwroff (void); 

/*
 *****************************************************
    APIs for EOBD/Application software
 *****************************************************
*/
/**
*    @brief : The function to report application specific faults to the fault manager.
*             This API is provided to the application layer.
*    @param : FaultPath_En - Application specific Fault Paths as configured by the application user in Fault manager.
*    @param : ErrorType_En   - Error catgory of the fault (E.g. MAX, MIN, SIG..etc) Refer to FM_ErrorType_En_t table for proper parameter.
*    @return : none.
*/
extern void FML1_ReportFault(u16_FaultPath_t FaultPath,    uint8_t ErrorType_u8);

/**
*    @brief : Clears the readiness completion variable. Also clears the
*             readiness monitoring test results in NV memory
*    @param : none.
*    @return :none.
*/
extern void FML1_ClrRdyMonFlags(void);

/*
*    @brief   Returns the status of readiness
*
*    @param   None.
*    @return  TRUE or FALSE
*/
extern bool FML1_IsRdyComplete (void);

/**
*    @brief   Returns the status of Fuel system readiness
*
*    @param   None.
*    @return  TRUE or FALSE
*/
extern bool FML1_IsFUELSysRdyComplete (void);

/**
*    @brief   Returns the status of EGR system readiness
*
*    @param   None.
*    @return  TRUE or FALSE
*/
extern bool FML1_IsEGRSysRdyComplete (void);

/**
*    @brief   Returns the status of CCOMP system readiness
*
*    @param   None.
*    @return  TRUE or FALSE
*/
extern bool FML1_IsCCOPMSysRdyComplete (void);

/**
*    @brief   Update the NV memory with the readiness monitoring test results 
*             of the current driving cycle.
*
*    @param   None.
*    @return  None.
*/
extern void FML1_UpdtNVMem_proc(void);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  Fault status
*/
extern uint8_t FML1_GetFltSt(u16_FaultPath_t);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FML1_GetErrSt(u16_FaultPath_t FltPath);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FML1_GetMaxErrFltSt(u16_FaultPath_t FLT_PATH);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FML1_GetMinErrFltSt(u16_FaultPath_t FLT_PATH);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FML1_GetSigErrFltSt(u16_FaultPath_t FLT_PATH);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FML1_GetNplErrFltSt(u16_FaultPath_t FLT_PATH);

/**
*    @brief   Return the status of the Fault type
*
*    @param   Fault Type
*    @return  TRUE
*    @return  FALSE
*/
extern bool FML1_GetFerErrFltSt(u16_FaultPath_t FLT_PATH);

/**
*    @brief   Function to read the Test failed status.
*
*    @param   FaultPath_En Fualtpath acts as index for each DTC.
*    @return  None.
*/
extern bool FML1_GetTestFailedStatus(u16_FaultPath_t FaultPath_En);

/**
*    @brief   Function to read the Test failed this operation cycle status.
*
*    @param   FaultPath_En Fualtpath acts as index for each DTC.
*    @return  None.
*/
extern bool FML1_GetTestFailedThisOCStatus(u16_FaultPath_t FaultPath_En);

/**
*    @brief   Function to read the Test not completed since last clear status.
*
*    @param   FaultPath_En Fualtpath acts as index for each DTC.
*    @return  None.
*/
extern bool FML1_GetTestNotCompletedSLCStatus(u16_FaultPath_t FaultPath_En);

/**
*    @brief   Function to read the Test failed since last clear status.
*
*    @param   FaultPath_En Fualtpath acts as index for each DTC.
*    @return  None.
*/
extern bool FML1_GetTestFailedSLCStatus(u16_FaultPath_t FaultPath_En);

/**
*    @brief   Function to read the Test not completed this operation cycle status.
*
*    @param   FaultPath_En Fualtpath acts as index for each DTC.
*    @return  None.
*/
extern bool FML1_GetTestNotCompletedThisOCStatus(u16_FaultPath_t FaultPath_En);

/**
*    @brief   Function to read the Warning Indicator Requested status.
*
*    @param   FaultPath_En Fualtpath acts as index for each DTC.
*    @return  None.
*/
extern bool FML1_GetWIRStatus(u16_FaultPath_t FaultPath_En);



extern void FML1_ClrAllContPrsnt (u16_FaultPath_t FaultPath_En);
extern uint16_t FML1_GetNumberOfPresentFaults (void);

/*
 **************************************************************************************************
 *    Export variables
 **************************************************************************************************
*/
 extern FML1_FltMon_St_t       FML1_FltMonRam_St;
 extern FML1_FaultPath_St_t    FaultPath_aSt[NUM_OF_FAULTPATHS_E]; 

/*
 **************************************************************************************************
 *    MACROS
 **************************************************************************************************
*/

/*
    MACROS to read the status of a fault
    @code tag - @[CODE_FML1_GETFLTSTATUS]@{SDD_FML1_GETFLTSTATUS}
*/
#define FML1_GetMaxErr(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MaxErr)
#define FML1_GetMinErr(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MinErr)
#define FML1_GetSigErr(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.SigErr)
#define FML1_GetNplErr(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.NplErr)
#define FML1_GetFerErr(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.FerErr)
#define FML1_GetErrType(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt_St.hh_u8 & ERRORTYPE_FIELD)

#define FML1_GetMaxMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MaxMask)
#define FML1_GetMinMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MinMask)
#define FML1_GetSigMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.SigMask)
#define FML1_GetNplMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.NplMask)
#define FML1_GetFerMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.FerMask)
#define FML1_GetErrMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt.hl & ERRORTYPE_FIELD)

#define FML1_GetMaxMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MaxMem)
#define FML1_GetMinMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MinMem)
#define FML1_GetSigMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.SigMem)
#define FML1_GetNplMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.NplMem)
#define FML1_GetFerMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.FerMem)
#define FML1_GetErrMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt.lh & ERRORTYPE_FIELD)

#define FML1_GetErf(FaultPath_En)            (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Erf)
#define FML1_GetRdy(FaultPath_En)            (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Rdy)
#define FML1_GetTst(FaultPath_En)            (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Tst)

#define FML1_GetPriority(FaultPath_En)       (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Priority)
#define FML1_GetDebStatus(FaultPath_En)      (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.DebSt)
#define FML1_GetRdyGroup(FaultPath_En)       (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.RdyGrp)
          
/*
    MACROS to set the attributes of a fault
*/
#define FML1_SetMaxErrBit(FaultPath_En)      (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MaxErr = TRUE)
#define FML1_SetMinErrBit(FaultPath_En)      (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MinErr = TRUE)
#define FML1_SetSigErrBit(FaultPath_En)      (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.SigErr = TRUE)
#define FML1_SetNplErrBit(FaultPath_En)      (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.NplErr = TRUE)
#define FML1_SetFerErrBit(FaultPath_En)      (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.FerErr = TRUE)
#define FML1_SetErrType(FaultPath_En, val)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt.hh |= (val & ERRORTYPE_FIELD))

#define FML1_ClrMaxErr(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MaxErr = FALSE)
#define FML1_ClrMinErr(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MinErr = FALSE)
#define FML1_ClrSigErr(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.SigErr = FALSE)
#define FML1_ClrNplErr(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.NplErr = FALSE)
#define FML1_ClrFerErr(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.FerErr = FALSE)
#define FML1_ClrErrType(FaultPath_En, val)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt.hh &= (~(val & ERRORTYPE_FIELD)))

/*Status of DTCs operation*/
#define FML1_GetStatusOfDTC(FaultPath_En)            (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt.hl_u8)
#define FML1_SetStatusOfDTC(FaultPath_En, val)       (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt.hl_u8 = val);

#define FML1_SET_TF_STATUS_OF_DTC_MAPTBL(FaultPath_En)       (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TF_b0     =  TRUE)
#define FML1_SET_TFTOC_STATUS_OF_DTC_MAPTBL(FaultPath_En)    (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TFTOC_b1  =  TRUE)
#define FML1_SET_PDTC_STATUS_OF_DTC_MAPTBL(FaultPath_En)     (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.PDTC_b2   =  TRUE)
#define FML1_SET_CDTC_STATUS_OF_DTC_MAPTBL(FaultPath_En)     (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.CDTC_b3   =  TRUE)
#define FML1_SET_TNCSLC_STATUS_OF_DTC_MAPTBL(FaultPath_En)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TNCSLC_b4 =  TRUE)
#define FML1_SET_TFSLC_STATUS_OF_DTC_MAPTBL(FaultPath_En)    (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TFSLC_b5  =  TRUE)
#define FML1_SET_TNCTOC_STATUS_OF_DTC_MAPTBL(FaultPath_En)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TNCTOC_b6 =  TRUE)
#define FML1_SET_WIR_STATUS_OF_DTC_MAPTBL(FaultPath_En)      (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.WIR_b7    =  TRUE)

#define FML1_CLR_TF_STATUS_OF_DTC_MAPTBL(FaultPath_En)       (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TF_b0     =  FALSE)
#define FML1_CLR_TFTOC_STATUS_OF_DTC_MAPTBL(FaultPath_En)    (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TFTOC_b1  =  FALSE)
#define FML1_CLR_PDTC_STATUS_OF_DTC_MAPTBL(FaultPath_En)     (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.PDTC_b2   =  FALSE)
#define FML1_CLR_CDTC_STATUS_OF_DTC_MAPTBL(FaultPath_En)     (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.CDTC_b3   =  FALSE)
#define FML1_CLR_TNCSLC_STATUS_OF_DTC_MAPTBL(FaultPath_En)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TNCSLC_b4 =  FALSE)
#define FML1_CLR_TFSLC_STATUS_OF_DTC_MAPTBL(FaultPath_En)    (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TFSLC_b5  =  FALSE)
#define FML1_CLR_TNCTOC_STATUS_OF_DTC_MAPTBL(FaultPath_En)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TNCTOC_b6 =  FALSE)
#define FML1_CLR_WIR_STATUS_OF_DTC_MAPTBL(FaultPath_En)      (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.WIR_b7    =  FALSE)

#define FML1_GET_TF_STATUS_OF_DTC_MAPTBL(FaultPath_En)       (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TF_b0)
#define FML1_GET_TFTOC_STATUS_OF_DTC_MAPTBL(FaultPath_En)    (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TFTOC_b1)
#define FML1_GET_PDTC_STATUS_OF_DTC_MAPTBL(FaultPath_En)     (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.PDTC_b2)
#define FML1_GET_CDTC_STATUS_OF_DTC_MAPTBL(FaultPath_En)     (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.CDTC_b3)
#define FML1_GET_TNCSLC_STATUS_OF_DTC_MAPTBL(FaultPath_En)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TNCSLC_b4)
#define FML1_GET_TFSLC_STATUS_OF_DTC_MAPTBL(FaultPath_En)    (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TFSLC_b5)
#define FML1_GET_TNCTOC_STATUS_OF_DTC_MAPTBL(FaultPath_En)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.TNCTOC_b6)
#define FML1_GET_WIR_STATUS_OF_DTC_MAPTBL(FaultPath_En)      (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.WIR_b7)

/*#define FML1_SetMaxMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MaxMask = TRUE)
#define FML1_SetMinMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MinMask = TRUE)
#define FML1_SetSigMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.SigMask = TRUE)
#define FML1_SetNplMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.NplMask = TRUE)
#define FML1_SetFerMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.FerMask = TRUE)
#define FML1_SetErrMask(FaultPath_En, val)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt.hl |= (val & ERRORTYPE_FIELD))

#define FML1_ClrMaxMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MaxMask = FALSE)
#define FML1_ClrMinMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MinMask = FALSE)
#define FML1_ClrSigMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.SigMask = FALSE)
#define FML1_ClrNplMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.NplMask = FALSE)
#define FML1_ClrFerMask(FaultPath_En)        (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.FerMask = FALSE)
#define FML1_ClrErrMask(FaultPath_En, val)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt.hl &= (~(val & ERRORTYPE_FIELD)))*/

#define FML1_SetMaxMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MaxMem = TRUE)
#define FML1_SetMinMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MinMem = TRUE)
#define FML1_SetSigMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.SigMem = TRUE)
#define FML1_SetNplMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.NplMem = TRUE)
#define FML1_SetFerMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.FerMem = TRUE)
#define FML1_SetErrMem(FaultPath_En,  val)   ((FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt.lh) |= (val & ERRORTYPE_FIELD))

#define FML1_ClrMaxMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MaxMem = FALSE)
#define FML1_ClrMinMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.MinMem = FALSE)
#define FML1_ClrSigMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.SigMem = FALSE)
#define FML1_ClrNplMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.NplMem = FALSE)
#define FML1_ClrFerMem(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.FerMem = FALSE)
#define FML1_ClrErrMem(FaultPath_En,  val)   (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt.lh &= (~(val & ERRORTYPE_FIELD)))

#define FML1_SetErf(FaultPath_En)            (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Erf = TRUE)
#define FML1_SetRdy(FaultPath_En)            (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Rdy = TRUE)
#define FML1_SetTst(FaultPath_En)            (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Tst = TRUE)

#define FML1_ClrErf(FaultPath_En)            (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Erf = FALSE)
#define FML1_ClrRdy(FaultPath_En)            (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Rdy = FALSE)
#define FML1_ClrTst(FaultPath_En)            (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Tst = FALSE)

#define FML1_SetPriority(FaultPath_En, Value)       (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Priority = Value)
#define FML1_SetDebStatus(FaultPath_En, Value)      (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.DebSt= Value)
#define FML1_SetReadyGroup(FaultPath_En, Value)     (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.RdyGrp = Value)
#define FML1_SetRdyChanged()                         (FML1_FltMonRam_St.RdyChngd_b = TRUE)  
#define FML1_ClrRdyChanged()                         (FML1_FltMonRam_St.RdyChngd_b = FALSE)  
#define FML1_IsRdyChanged()                          (FML1_FltMonRam_St.RdyChngd_b)  

#define FML1_SetDebCnt(FaultPath_En, Value)     (FaultPath_aSt[FaultPath_En].DebCnt_u16 = Value)
#define FML1_SetActDebCnt(FaultPath_En, Value)  (FaultPath_aSt[FaultPath_En].ActDebCnt_u16 = Value)
#define FML1_GetActDebCnt(FaultPath_En)         (FaultPath_aSt[FaultPath_En].ActDebCnt_u16)
#define FML1_StartDebCnt(FaultPath_En)       (FaultPath_aSt[FaultPath_En].DebCnt_u16 = 1)
#define FML1_ResetDebCnt(FaultPath_En)       (FaultPath_aSt[FaultPath_En].DebCnt_u16 = 0)
#define FML1_IncDebCnt(FaultPath_En)         (FaultPath_aSt[FaultPath_En].DebCnt_u16++)
#define FML1_DecDebCnt(FaultPath_En)         (FaultPath_aSt[FaultPath_En].DebCnt_u16--)
#define FML1_GetDebCnt(FaultPath_En)         (FaultPath_aSt[FaultPath_En].DebCnt_u16)

#define FML1_ClrStReg(FaultPath_En)          (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.wrd_u32 = 0)
#define FML1_ClrAllErrBits(FaultPath_En)     (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg.byt_St.hh_u8 &= MASK_ERRORTYPE)

#define FML1_GetMaxContPrsnt(FaultPath_En)   (FML1_FltMonRam_St.FltCp_aSt[FaultPath_En].bf.MaxCp)
#define FML1_GetMinContPrsnt(FaultPath_En)   (FML1_FltMonRam_St.FltCp_aSt[FaultPath_En].bf.MinCp)
#define FML1_GetSigContPrsnt(FaultPath_En)   (FML1_FltMonRam_St.FltCp_aSt[FaultPath_En].bf.SigCp)
#define FML1_GetNplContPrsnt(FaultPath_En)   (FML1_FltMonRam_St.FltCp_aSt[FaultPath_En].bf.NplCp)
#define FML1_GetFerContPrsnt(FaultPath_En)   (FML1_FltMonRam_St.FltCp_aSt[FaultPath_En].bf.FerCp)
#define FML1_GetAllContPrsnt(FaultPath_En)   (FML1_FltMonRam_St.FltCp_aSt[FaultPath_En].wrd.byt_St.h_u8 & ERRORTYPE_FIELD)
#define FML1_RSTContPrsnt(FaultPath_En)      (FML1_FltMonRam_St.FltCp_aSt[FaultPath_En].wrd.hwd_u16 = 0)

/*
    Defines for Readiness flags for different monitoring groups
*/
#define FML1_SETRdyCmpltFUELSys()   ( FML1_RdyCmpltFUELSys_u8  = TRUE )
#define FML1_SETRdyCmpltEGRSys()    ( FML1_RdyCmpltEGRSys_u8   = TRUE )
#define FML1_SETRdyCmpltCCOMPSys()  ( FML1_RdyCmpltCCOMPSys_u8 = TRUE )

#define FML1_CLRRdyCmpltFUELSys()   ( FML1_RdyCmpltFUELSys_u8  = FALSE )
#define FML1_CLRRdyCmpltEGRSys()    ( FML1_RdyCmpltEGRSys_u8   = FALSE )
#define FML1_CLRRdyCmpltCCOMPSys()  ( FML1_RdyCmpltCCOMPSys_u8 = FALSE )

#define FML1_GETRdyCmpltFUELSys()   ( FML1_RdyCmpltFUELSys_u8  )
#define FML1_GETRdyCmpltEGRSys()    ( FML1_RdyCmpltEGRSys_u8   )
#define FML1_GETRdyCmpltCCOMPSys()  ( FML1_RdyCmpltCCOMPSys_u8 )

#define FML1_SetUpt_St(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Upd_St = TRUE)
#define FML1_ClrUpt_St(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Upd_St = FALSE)
#define FML1_GetUpt_St(FaultPath_En)         (FaultPath_aSt[FaultPath_En].L1StReg_Uni.Reg_St.Upd_St)

//#define FML1_GetOBDFrzFrmCallBack(FaultPath_En, idx)    (APPL_FAULTCONF_aSt[FaultPath_En].FrzFrm_OBDData_pSt[idx].FrzFrm_Fptr)
//#define FML1_OBDFrzFrmCallBack(FaultPath_En, idx)    (APPL_FAULTCONF_aSt[FaultPath_En].FrzFrm_OBDData_pSt[idx].FrzFrm_Fptr())
//#define FML1_GetNonOBDFrzFrmCallBack(FaultPath_En, idx) (APPL_FAULTCONF_aSt[FaultPath_En].FrzFrm_NONOBDData_pSt[idx].FrzFrm_Fptr)
//#define FML1_NonOBDFrzFrmCallBack(FaultPath_En, idx) (APPL_FAULTCONF_aSt[FaultPath_En].FrzFrm_NONOBDData_pSt[idx].FrzFrm_Fptr())
//#define FML1_GetNonOBDFrzFrmCount(FaultPath_En) (APPL_FAULTCONF_aSt[FaultPath_En].FM_NONOBDFrzFrm_Entries_u8)
//todo harsh
#define FML1_Cpy_OBDFrzFrm(FaultPath_En,ind, val)    (FaultPath_aSt[FaultPath_En].L1FrzFrm_OBD_au8[ind] = val)
#define FML1_Cpy_NONOBDFrzFrm(FaultPath_En,ind, val) (FaultPath_aSt[FaultPath_En].L1FrzFrm_UDS_au8[ind] = val)


extern  int8_t FML1_Get_DTC(uint32_t* DTC_pu32, uint16_t ReadLimit_u16, FM_ProtocolType_En_t FM_ProtocolType_En, FM_Fault_Type_En_t FM_Fault_Type_En ,FM_Fault_Condition_En_t FM_Fault_Condition_En);

/************************************************************
    Inline function definitions for handling Error bits
*************************************************************/

#endif

