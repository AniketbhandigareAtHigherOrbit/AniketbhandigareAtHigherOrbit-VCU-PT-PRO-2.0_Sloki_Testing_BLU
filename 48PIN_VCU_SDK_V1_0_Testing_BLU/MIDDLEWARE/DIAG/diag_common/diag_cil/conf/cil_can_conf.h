/******************************************************************************
 *    FILENAME    : cil_can_conf.h
 *    DESCRIPTION : File contains CIL_CAN_Conf.c related definitions and declarations.
 ******************************************************************************
 * Revision history
 *  
 * Ver   Author       Date               Description
 * 1     Sushil      27/10/2018		     Initial version
 ******************************************************************************
*/ 
#ifndef _CIL_CAN_CONF_H_
#define _CIL_CAN_CONF_H_
/*
 ****************************************************************************************
 *    Includes
 ****************************************************************************************
*/
#include "can_if.h"
#include "diag_sys_conf.h"

/*
 ****************************************************************************************
 *    Defines
 ****************************************************************************************
*/  
#define CIL_CAN_GetID(sig)          (CIL_CAN_Conf_aSt[sig].HAL_CAN_MsgConf_St.ID_u32)
#define MIN_DLC_LENGTH              (8u)


#define CAN_RX_TX_DISABLE       0x00u 
#define CAN_RX_ONLY             0x01u
#define CAN_TX_ONLY             0x02u
#define CAN_RX_TX_ENABLE        0x04u

#define CAN_RX_STATUS_MASK()     (CAN_RX_ONLY|CAN_RX_TX_ENABLE)
#define CAN_TX_STATUS_MASK()     (CAN_TX_ONLY|CAN_RX_TX_ENABLE)

#define CHECK_FOR_CAN_SCHDLR_INIT(PresentMask,SetMask,Mask) (!(PresentMask&Mask) && (SetMask&Mask)?true:false)

#define MCU_SUPPORTED  FALSE
/*
 ****************************************************************************************
 *    ENUM Definition 
 ****************************************************************************************
*/
/*
    Enum defined to sort out the type callback recieved from cil or network layer to upper layer.
*/
typedef enum
{
    CIL_NEW_REQ_Rxed_E = 1,
    CIL_Rx_ERROR_E = 2,
    CIL_TX_CONFRM_E = 3,
    CIL_TX_ERROR_E = 4,
    CIL_FF_RXED_E = 5,
}nl2tp_CbkType_En_t;

typedef enum
{
    CIL_CAN_START_E = 0,
    /****************************** CAN RX Frames ******************************/
    CIL_CAN_RX_START_E = CIL_CAN_START_E,

    /*************** UDS CAN RX frames **************/
    CIL_RX_UDS_START = CIL_CAN_RX_START_E,
#if (TRUE == DIAG_CONF_UDS_SUPPORTED && TRUE == DIAG_CONF_CANTP_SUPPORTED)
    CIL_CANTP_REQ_IVN_RX_E = CIL_RX_UDS_START,
    CIL_CANTP_REQ_TESTER_RX_E,
    CIL_CANTP_REQ_FUNC_RX_E,
    CIL_RX_UDS_END,
#else
    CIL_RX_UDS_END = CIL_RX_UDS_START,
#endif

    /*************** OBD CAN RX frames **************/
    CIL_RX_OBD_START = CIL_RX_UDS_END,
#if (TRUE == DIAG_CONF_OBD2_SUPPORTED && TRUE == DIAG_CONF_CANTP_SUPPORTED)
    CIL_CANTP_REQ_OBD_TESTER_RX_E = CIL_RX_OBD_START,
    CIL_RX_OBD_END,
#else
    CIL_RX_OBD_END = CIL_RX_OBD_START,
#endif

    /*************** J1939 CAN RX frames **************/
    CIL_RX_J1939_START = CIL_RX_OBD_END,
#if (TRUE == DIAG_CONF_J1939_SUPPORTED)
    CIL_J1939_TPCM_BAM_RX_E = CIL_RX_J1939_START,
    CIL_J1939_TPCM_RX_E,
    CIL_J1939_TPDT_BAM_RX_E,
    CIL_J1939_TPDT_RX_E,
    CIL_J1939_DM22_RX_E,
    CIL_J1939_81_NMAC_RX_E,
    CIL_J1939_REQ_DA_BAM_RX_E,
    CIL_J1939_REQ_DA_RX_E,
    CIL_RX_J1939_END,
#else
    CIL_RX_J1939_END = CIL_RX_J1939_START,
#endif

/*************** FM EEPROM CAN RX frames **************/
    CIL_EEPROM_FAULT_RX_START__E = CIL_RX_J1939_END,
#if (TRUE == DIAG_TEST_FM_EEPROM_DEMO)
    CIL_EEPROM_FAULT_FUNC_RX_E = CIL_EEPROM_FAULT_RX_START__E,
    CIL_EEPROM_FAULT_FUNC_RX_END,
#else
    CIL_EEPROM_FAULT_FUNC_RX_END = CIL_EEPROM_FAULT_RX_START__E,
#endif

/*************** FM TEST CAN RX frames **************/
    CIL_RX_FM_TEST_START_E = CIL_EEPROM_FAULT_FUNC_RX_END,
#if (TRUE == DIAG_TEST_FM_DEMO && TRUE == DIAG_CONF_FM_SUPPORTED)
    CIL_RX_FM_TEST_DEMO_E = CIL_RX_FM_TEST_START_E,
    CIL_RX_FM_TEST_END_E,
#else
    CIL_RX_FM_TEST_END_E = CIL_RX_FM_TEST_START_E,
#endif

/*************** MCU CAN RX frames **************/
    CIL_RX_MCU_START_E = CIL_RX_FM_TEST_END_E,
#if (TRUE == MCU_SUPPORTED)  
 CIL_RX_MCU_END_E = CIL_RX_MCU_START_E,  
#else
    CIL_RX_MCU_END_E = CIL_RX_MCU_START_E,
#endif

    CIL_CAN_RX_END_E =     CIL_RX_MCU_END_E,
    
/********************************************** CAN TX Frames ***************************************/
    CIL_CAN_TX_START_E = CIL_CAN_RX_END_E,

    /*************** UDS CAN TX frames **************/
    CIL_TX_UDS_START_E = CIL_CAN_TX_START_E,
#if (TRUE == DIAG_CONF_UDS_SUPPORTED)
    CIL_CANTP_RESP_TESTER_TX_E = CIL_TX_UDS_START_E,
    CIL_CANTP_RESP_IVN_TX_E,
    CIL_TX_UDS_END_E,
#else
    CIL_TX_UDS_END_E = CIL_TX_UDS_START_E,
#endif

    /*************** OBD CAN TX frames **************/
    CIL_TX_OBD_START_E = CIL_TX_UDS_END_E,
#if (TRUE == DIAG_CONF_OBD2_SUPPORTED)
    CIL_CANTP_RESP_OBD_TESTER_TX_E = CIL_TX_OBD_START,
    CIL_TX_OBD_END_E,
#else
    CIL_TX_OBD_END_E = CIL_TX_OBD_START_E,
#endif

    /*************** J1939 CAN TX frames **************/
    CIL_TX_J1939_START_E = CIL_TX_OBD_END_E,
#if (TRUE == DIAG_CONF_J1939_SUPPORTED)
    CIL_J1939_TPCM_TX_E = CIL_TX_J1939_START_E,
    CIL_j1939_tpdt_TX_E,
    CIL_J1939_ACK_TX_E,
    CIL_J1939_REQ_TX_E,
    CIL_J1939_71_TEST1_TX_E,
    CIL_J1939_71_TEST2_TX_E,
    CIL_J1939_71_TEST3_TX_E,
    CIL_TX_J1939_END_E,
#else
    CIL_TX_J1939_END_E = CIL_TX_J1939_START_E,
#endif

    /*************** FM EEPROM TEST CAN TX frames **************/
    CIL_EEPROM_FAULT_TX_START_E = CIL_TX_J1939_END_E,
#if (TRUE == DIAG_TEST_FM_EEPROM_DEMO)
    CIL_EEPROM_FAULT_FUNC_TX_E = CIL_EEPROM_FAULT_TX_START_E,
    CIL_EEPROM_FAULT_TX_END_E,
#else
    CIL_EEPROM_FAULT_TX_END_E = CIL_EEPROM_FAULT_TX_START_E,
#endif

    /*************** FM TEST CAN TX frames **************/
    CIL_TX_FM_TEST_START_E = CIL_EEPROM_FAULT_TX_END_E,
#if (TRUE == DIAG_TEST_FM_DEMO)
    CIL_FM_TEST1_TX_E = CIL_TX_FM_TEST_START_E,
    CIL_FM_TEST2_TX_E,
    CIL_TX_FM_TEST_END_E,
#else
    CIL_TX_FM_TEST_END_E = CIL_TX_FM_TEST_START_E,
#endif



    CIL_CAN_TX_END_E = CIL_TX_FM_TEST_END_E,
    CIL_DCAN_TOTAL_RX_E = CIL_CAN_RX_END_E,
    
    CIL_CAN_TOTAL_TX_E = CIL_CAN_TX_END_E - CIL_CAN_RX_END_E,
    CIL_DCAN_END_E = CIL_CAN_TX_END_E,
} CIL_SigName_En_t;


/*
 ****************************************************************************************
 *    Structure Definition 
 ****************************************************************************************
*/


/*
 ****************************************************************************************
 *    al Variables
 ****************************************************************************************
*/ 
extern const CIL_CAN_Conf_St_t CIL_CAN_Conf_aSt[];


/*
 ****************************************************************************************
 *    Function Prototypes
 ****************************************************************************************
*/
#endif

/* *****************************************************************************
 End of File
 */

