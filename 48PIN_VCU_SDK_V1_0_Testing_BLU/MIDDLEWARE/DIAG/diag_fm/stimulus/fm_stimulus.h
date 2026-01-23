
/******************************************************************************
 *    FILENAME    : fm_stimulus.h
 *    DESCRIPTION : stimulus functions for fault manager stack.
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   sloki     		   Initial version
 ******************************************************************************
*/  



#ifndef _FM_STIMULUS_H_
#define _FM_STIMULUS_H_


/*
 **************************************************************************************************
 *    Includes
 **************************************************************************************************
 */

#include "diag_typedefs.h"
 
/***************************************************************************************************
*    Class Definition
***************************************************************************************************/

#include "fm.h"

//class FM_STM_T
//{
//public:
//	uint8_t i;
//
//
//private:
//	uint8_t k;
//};
//class FM_STM_T
//{
//public:
//
//    static const uint32_t MODE_OFF = 0;
//    static const uint32_t MODE_ON  = 1;
//
//	static const uint8_t  NO_ERR = 0;
//	static const uint8_t  MAX_ERR = 1;
//	static const uint8_t  MIN_ERR = 2;
//	static const uint8_t  SIG_ERR = 3;
//	static const uint8_t  NPL_ERR = 4;
//	static const uint8_t  FER_ERR = 5;
//
//
//
//    /**
//    *  @brief     Constructor with radix information for alignment of set value
//    *  @param     none
//    *  @return    none
//    */
//    FM_STM_T(void);
//
//	/**
//     *  @brief	 Init function
//     *  @param   none
//     *  @return  none
//     *
//     */
//    void Init (void);
//
//
//    /**
//    *  @brief     Stimulates the forced value when mode flag ist set, otherwise
//    * 			  returns the value value_u16
//    *  @param     value
//    *  @return    -
//    */
//    uint8_t Stimulus(uint8_t value_u8);
//
//    /**
//    *  @brief     Set the callback function for checking whether the simulation
//    *             mode shall be left.
//    *             The function shall return TRUE for aborting the simlation
//    *             an FALSE for still staying in simulation mode. The callback function
//    *             can only reset the simulation mode but can not enter it!
//    *  @param     callback_p Pointer to Abort-Function
//    *  @return    -
//    */
//    void SetSimulationCallback(FM_STM_CALLBACK callback_p);
//
//
//    /**
//    *  @brief     Get the mode state value of the stimulus object
//    *  @param     -
//    *  @return    Mode_u8
//    */
//    uint8_t GetModeState();
//
//    /**
//    *  @brief     This is an overriding function to enable the stimulus.
//    *             The function shall enable the mode and assign the value
//    *             to the stimulus variable.
//    *  @param     SINT16 / uint16_t / bool
//    *  @return    none
//    */
//    void SetStimulus(uint8_t value_u8);
//
//
//    /**
//    *  @brief     This is an overriding function to disable the stimulus.
//    *             The function shall disable the mode variable.
//    *  @param     none
//    *  @return    none
//    */
//    void ResetStimulus();
//
//
//
//
//
//protected:
//
//private:
//    // Watchdog expire time
//    static const uint16_t WATCHDOG_TIME_MS = 1000;
//  	static const SINT32 MAX_VALUE_BOOLEAN = 1;
//  	static const SINT32 MIN_VALUE_BOOLEAN = 0;
//
//    /**
//    *  @brief     Checks whether the simulation mode shall be left or not
//    *  @param     -
//    *  @return    -
//    */
//    void CheckMode (void);
//
//    /*
//    @@ ELEMENT    = FaultForceValue_u8
//    @@ STRUCTURE  = FM_STM_T
//    @@ A2L_TYPE   = MEASURE WRITEABLE ForceValue
//    @@ DATA_TYPE  = $uint8_t$
//    @@ CONVERSION = TABLE 0 "NO_ERR" 1 "MAX_ERR" 2 "MIN_ERR" 3 "SIG_ERR" 4 "NPL_ERR" 5 "FER_ERR"
//    @@ END
//    */
//    uint8_t  FaultForceValue_u8;		/* Value to be forced when force is active */
//
//	FM_STM_CALLBACK AbortSimulation_p;  // Callback for deactivating the simulation mode
//
//	/*
//    @@ ELEMENT    = Mode_u8
//    @@ STRUCTURE  = FM_STM_T
//    @@ A2L_TYPE   = MEASURE WRITEABLE Mode
//    @@ DATA_TYPE  = $uint8_t$ [0 ... 4]
//    @@ CONVERSION = TABLE $TABLE_STIMULUS$
//    @@ END
//    */
//    uint8_t   Mode_u8;
//
//
//};

 /**
*  FUNCTION NAME : FM_Stimulus
*  FILENAME      : fm_stimulus.h
*  @param        : DidList_En DidList Enum, 
*  @param        : srcValue_pu8 pointing to Real data
*  @param        : dstValue_pu8 pointing to global variable
*  @brief        : This function will return the forcevalue or realvalue depends on mode.
*  @return       : Non.                     
*/

extern void FM_Stimulus(FM_FaultPath_En_t FaultPath_En ,  uint8_t RealFltType);


 /**
*  FUNCTION NAME : FM_SetStimulus
*  FILENAME      : fm_stimulus.h
*  @param        : ForceValue_pu8  pointer to forcevalue 
*  @brief        : This function will set mode to true and assign forcevalue
                   to the respective forcevalues in the structure.
*  @return       : void                     
*/
extern void  FM_SetStimulus(FM_FaultPath_En_t FaultPath_En, uint8_t ForceFltType);
   

 /**
*  FUNCTION NAME : FM_ResetStimulus
*  FILENAME      : fm_stimulus.h
*  @param        : DidList_En DidList Enum, 
*  @brief        : This function will set mode to false.
*  @return       : void                     
*/
extern void  FM_ResetStimulus(FM_FaultPath_En_t FaultPath_En);

#endif
