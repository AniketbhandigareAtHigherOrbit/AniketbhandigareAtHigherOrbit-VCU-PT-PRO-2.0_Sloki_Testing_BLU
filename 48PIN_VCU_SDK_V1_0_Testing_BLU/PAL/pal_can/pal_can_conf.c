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
|   Date              Name                        Company
| ----------     ---------------     -----------------------------------
| 08/12/2023       Jeevan Jestin N             Sloki Software Technologies Pvt Ltd
|-------------------------------------------------------------------------------
|******************************************************************************/

/*******************************************************************************
 *  HEADER FILE INCLUDES
 ******************************************************************************/
#include"pal_can_conf.h"
#include"AppTest.h"
#include"controller_can_rx.h"
#include"battery_can_rx.h"
/*******************************************************************************
 *  MACRO DEFINITION
 ******************************************************************************/

/*******************************************************************************
 *  GLOBAL VARIABLES DEFNITION 
 ******************************************************************************/


const uint8_t Can0_Rx_filter_u8 = 4;
const uint8_t Can1_Rx_filter_u8 = 1;
const uint8_t Can2_Rx_filter_u8 = 10;


// CanRxFilterConf_St_t Can0RxFilterConf_aSt[];
// CanRxFilterConf_St_t Can1RxFilterConf_aSt[];
// CanRxFilterConf_St_t Can2RxFilterConf_aSt[];
/*******************************************************************************
 *  STRUCTURE AND ENUM DEFNITION 
 ******************************************************************************/
CanRxFilterConf_St_t Can0RxFilterConf_aSt[TOTAL_RX_FILTER_CAN_0] =
{
    {0x0746CD62U, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx_1},
    {0x0746D608U, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx_2},
    {0x0746CE3EU, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx_2},
    {0x0746CD04U, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx_1},
    //{0x074, 0x1FF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx},
    //0x0746CD04
};

CanRxFilterConf_St_t Can1RxFilterConf_aSt[TOTAL_RX_FILTER_CAN_1] =
{
    /* -------- Controller 4 (Left Wheel) -------- */
    {0x0746CE3EU, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx_1},
   // {0xCF11E04, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
   // {0xCF11F04, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
    /* -------- Controller 5 (Rotor) -------- */
   // {0xCF11E05, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
   // {0xCF11F05, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
    /* -------- Controller 6 (Right Wheel) -------- */
   // {0xCF11E06, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
    //{0xCF11F06, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
};

CanRxFilterConf_St_t Can2RxFilterConf_aSt[TOTAL_RX_FILTER_CAN_2] = 
{
    
    {0x0746CD62U, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx_1},
    {0x0746D608U, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx_2},
    {0x0746CE3EU, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx_2},
    {0x0746CD04U, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx_1},

    {0xCF11E04, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
    {0xCF11F04, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
    /* -------- Controller 5 (Rotor) -------- */
    {0xCF11E05, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
    {0xCF11F05, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
    /* -------- Controller 6 (Right Wheel) -------- */
    {0xCF11E06, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
    {0xCF11F06, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Controller_Rx},
      //{0x0746D608U, 0x1FFFFFFF, RX_FIFO_BUFF_E, EXT_IDE_E, Call_Back_Battery_Rx},
   //0x0746CD62
};

RSCANchannelConf_St_t RSCANchannelConf_aSt[] = 
{
    /* Note:
            CAN configuration channel number should be in sequential order 
    */
    {true,_500K_BAUDRATE_E,_5MBPS_BAUDRATE_E,CAN_FD_MODE_E,CAN_0,TOTAL_RX_FILTER_CAN_0,Can0RxFilterConf_aSt},
    {true,_500K_BAUDRATE_E,_5MBPS_BAUDRATE_E,CAN_FD_MODE_E,CAN_1,TOTAL_RX_FILTER_CAN_1,Can1RxFilterConf_aSt},
    {true,_500K_BAUDRATE_E,_5MBPS_BAUDRATE_E,CAN_FD_MODE_E,CAN_2,TOTAL_RX_FILTER_CAN_2,Can2RxFilterConf_aSt},
};
/*******************************************************************************
 *  STATIC FUNCTION PROTOTYPES
 ******************************************************************************/

/*******************************************************************************
 *  FUNCTION DEFINITIONS
 ******************************************************************************/

/* -----------------------------------------------------------------------------
*  FUNCTION DESCRIPTION
*  -----------------------------------------------------------------------------
*   Function Name : NONE
*   Description   : NONE
*   Parameters    : None
*   Return Value  : None
*  ---------------------------------------------------------------------------*/

/*---------------------- End of File -----------------------------------------*/