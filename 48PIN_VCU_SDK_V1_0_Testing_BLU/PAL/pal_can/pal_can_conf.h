/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : pal_can_conf.c
|    Project        : VCU_ASW
|    Description    : The file contains the configration data of CAN module
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date             Name                      Company
| --------     ---------------------     ---------------------------------------
| 08/12/2023     Jeevan Jestin N           Sloki Software Technologies Pvt Ltd.
|-------------------------------------------------------------------------------
|******************************************************************************/
#ifndef CAN_CONF_H
#define CAN_CONF_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include"r_cg_macrodriver.h"
#include"rscan_driver.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/

/*
Note:
    Maximum number of message filter per channel is 128 
*/
#define TOTAL_RX_FILTER_CAN_0       2
#define TOTAL_RX_FILTER_CAN_1       6
#define TOTAL_RX_FILTER_CAN_2       7

#define CAN_0                       0
#define CAN_1                       1
#define CAN_2                       2
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
// extern const uint8_t can0RxSize_u8;
// extern const uint8_t can1RxSize_u8;
// extern const uint8_t can2RxSize_u8;

extern  const uint8_t Can0_Rx_filter_u8;
extern   const uint8_t Can1_Rx_filter_u8;
extern  const uint8_t Can2_Rx_filter_u8;

extern RSCANchannelConf_St_t RSCANchannelConf_aSt[];
extern CanRxFilterConf_St_t Can0RxFilterConf_aSt[/*Can0_Rx_filter_u8*/];
extern CanRxFilterConf_St_t Can1RxFilterConf_aSt[/*Can1_Rx_filter_u8*/];
extern CanRxFilterConf_St_t Can2RxFilterConf_aSt[/*Can2_Rx_filter_u8]*/];



/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/

#endif
/*---------------------- End of File -----------------------------------------*/