/******************************************************************************
 *    FILENAME    : cil_can_conf.c
 *    DESCRIPTION : File contains the common declarations related to CIL layers.
 ******************************************************************************
 * Revision history
 *
 * Ver   Author       Date               Description
 * 1     Sushil      27/10/2018		     Initial version
 ******************************************************************************
 */

/* Section: Included Files                                       */
// #include "can_if.h"
#include "cil_can_conf.h"
#include "diag_appl_test.h"
#include "iso14229_serv28.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*
 * @summary:- can structure message buffer
 */

CanSchedMsg_St_t CanSB_St[CIL_DCAN_TOTAL_RX_E] = {0};

const CIL_CAN_Conf_St_t CIL_CAN_Conf_aSt[CIL_DCAN_END_E] =
    {
#if (TRUE == DIAG_CONF_UDS_SUPPORTED && TRUE == DIAG_CONF_CANTP_SUPPORTED)
        {{0x6F0, 0x7FF, CAN1_E, 0x10, STD_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_CANTP_REQ_IVN_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_CANTP_REQ_IVN_RX_E].msg,       DLC_CHECK_ENABLE_E, ISO14229_CAN_MSG_E},
        {{0x7F0, 0x7FF, CAN2_E, 0x10, STD_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_CANTP_REQ_TESTER_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_CANTP_REQ_TESTER_RX_E].msg, DLC_CHECK_ENABLE_E, ISO14229_CAN_MSG_E},        
        {{0x7DF, 0x7FF, CAN2_E, 0x10, STD_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_CANTP_REQ_FUNC_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_CANTP_REQ_FUNC_RX_E].msg,      DLC_CHECK_DISABLE_E, ISO14229_CAN_MSG_E},
#endif
#if (TRUE == DIAG_CONF_OBD2_SUPPORTED && TRUE == DIAG_CONF_CANTP_SUPPORTED)

        {{0x18DB33F0, 0x1FFFFFFC, CAN1_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_CANTP_REQ_OBD_TESTER_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_CANTP_REQ_OBD_TESTER_RX_E].msg, DLC_CHECK_DISABLE_E, ISO14229_CAN_MSG_E}, //@
#endif
#if (TRUE == DIAG_CONF_J1939_SUPPORTED)
        {{0x10ECFF00, 0x10FFFF00, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_J1939_TPCM_BAM_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_J1939_TPCM_BAM_RX_E].msg, DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},            /*@ */
        {{0x10EC0000, 0x10FF0000, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_J1939_TPCM_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_J1939_TPCM_RX_E].msg, DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},                    /*@ */
        {{0x10EBFF00, 0x10FFFF00, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_J1939_TPDT_BAM_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_J1939_TPDT_BAM_RX_E].msg, DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},            /*@ */
        {{0x10EB0000, 0x10FF0000, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_J1939_TPDT_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_J1939_TPDT_RX_E].msg, DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},                    /*@ */
        {{0x18C300F0, 0x1FFF0000, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_J1939_DM22_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_J1939_DM22_RX_E].msg, DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},                    /*@ */
        {{0x10EEFF00, 0x10FFFF00, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_J1939_81_NMAC_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_J1939_81_NMAC_RX_E].msg, DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},              /*@ */
        {{0x10EAFF00, 0x10FFFF00, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_J1939_REQ_DA_BAM_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_J1939_REQ_DA_BAM_RX_E].msg, DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},        /*@ */
        {/*0x18EA0000*/ {0x10EA0000, 0x10FF0000, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_J1939_REQ_DA_RX_E, CanSched_RxCallBackInt, &CanSB_St[CIL_J1939_REQ_DA_RX_E].msg, DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E}, /*@ */
#endif
#if (TRUE == DIAG_TEST_FM_EEPROM_DEMO)
        {{0x7EF, 0x7EF, CAN1_E, 0x10, STD_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_EEPROM_FAULT_FUNC_RX_E, CanSched_RxCallBackInt, &CanTest_St[0].msg, DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E}, //@
#endif
#if (TRUE == DIAG_TEST_FM_DEMO && TRUE == DIAG_CONF_FM_SUPPORTED)
        {{0x710, 0x710, CAN1_E, 0x10, STD_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_RX, MIN_DLC_LENGTH}, CIL_RX_FM_TEST_DEMO_E, CanSched_RxCallBackInt, &CanSB_St[CIL_RX_FM_TEST_DEMO_E].msg, DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E}, //@
#endif

#if (TRUE == MCU_SUPPORTED)       
#endif

#if (TRUE == DIAG_CONF_UDS_SUPPORTED && TRUE == DIAG_CONF_CANTP_SUPPORTED)
        {{0x7F1, 0U, CAN2_E, 0x10, STD_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_CANTP_RESP_TESTER_TX_E, NULL, NULL, DLC_CHECK_ENABLE_E, ISO14229_CAN_MSG_E}, //@
        {{0x6F1, 0U, CAN1_E, 0x10, STD_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_CANTP_RESP_IVN_TX_E, NULL, NULL, DLC_CHECK_DISABLE_E, ISO14229_CAN_MSG_E},    //@
#endif

#if (TRUE == DIAG_CONF_OBD2_SUPPORTED && TRUE == DIAG_CONF_CANTP_SUPPORTED)
        {{0x18DAF110, 0U, CAN1_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_CANTP_RESP_OBD_TESTER_TX_E, NULL, NULL, DLC_CHECK_DISABLE_E}, //@
#endif

#if (TRUE == DIAG_CONF_J1939_SUPPORTED)
        {{0x18EC0100, 0U, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_J1939_TPCM_TX_E, NULL, NULL,DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},     /*@ */
        {{0x18EB0100, 0U, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_j1939_tpdt_TX_E, NULL, NULL,DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},     /*@ */
        {{0x18E8FF00, 0U, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_J1939_ACK_TX_E, NULL, NULL,DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},      /*@ */
        {{0x18EAFF00, 0U, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_J1939_REQ_TX_E, NULL, NULL,DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E},      /*@ */
        {{0x18AA0000, 0U, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_J1939_71_TEST1_TX_E, NULL, NULL,DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E}, /*@ */
        {{0x18AB0000, 0U, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_J1939_71_TEST2_TX_E, NULL, NULL,DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E}, /*@ */
        {{0x18AC0000, 0U, CAN2_E, 0x10, EXT_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_J1939_71_TEST3_TX_E, NULL, NULL,DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E}, /*@ */
#endif
#if (TRUE == DIAG_TEST_FM_EEPROM_DEMO)
        {{0x512, 0U, CAN1_E, 0x10, STD_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_EEPROM_FAULT_FUNC_TX_E, NULL, NULL,DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E}, //@
#endif

#if (TRUE == DIAG_TEST_FM_DEMO && TRUE == DIAG_CONF_FM_SUPPORTED)
        {{0x701, 0U, CAN1_E, 0x10, STD_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_FM_TEST1_TX_E, NULL, NULL,DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E}, //@
        {{0x702, 0U, CAN1_E, 0x10, STD_CAN_E, DATA_FRAME_E, FALSE, FALSE, CAN_TX, MIN_DLC_LENGTH}, CIL_FM_TEST2_TX_E, NULL, NULL,DLC_CHECK_DISABLE_E, J1939_CAN_MSG_E}, //@
#endif



};

/******************************************************************************
 End of File
 ******************************************************************************/
