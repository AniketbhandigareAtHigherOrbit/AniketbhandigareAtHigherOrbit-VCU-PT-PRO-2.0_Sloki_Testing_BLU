/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : rscan_typedefs.h
|    Project        : CAN Driver development
|    Description    : The file contains the typedefs of RSCAN
|    Version        : V1_00
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date              Name                        Company
| ----------     ---------------     -----------------------------------
| 17/10/2023       Jeevan Jestin N             Sloki Software Technologies Pvt Ltd
|-------------------------------------------------------------------------------
|******************************************************************************/

/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "app_typedef.h"
//#include "r_cg_macrodriver.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define RSCAN_MAX_UNIT      1
#define RSCAN_UNIT0_MAX_CHANNEL 3

#define RSCAN_MAX_RECEIVE_RULE_PER_PAGE 15

#define RSCAN_UNIT0_TXRX_FIFO_BUFF_PER_CHANNEL   3
#define RSCAN_UNIT0_RX_FIFO 8
#define RSCAN_UNIT0_RX_BUFF 128

#define RSCAN_UNIT0_TX_BUFF_PER_CHNL    32

#define MAX_RX_RULE_PER_CHANNEL    256
#define MAX_RX_RULE_ALLOWED        128
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef const struct 
{
    uint8_t TotalChannel_u8;
    uint8_t TransReceivefifoBuff_u8;
    uint8_t ReceiveFifoBuff_u8;
    uint16_t IndReceivBuff_u16;
    uint16_t TransmitBuffPerChannel_u16;
}RSCANconfg_St_t;

typedef enum
{
    RSCAN_INIT_OK_E,
    RSCAN_INVALID_UNIT_E,
    RSCAN_INVALID_CHANNEL_E,
    RSCAN_MAX_RX_CHN_RULE_E,
    RSCAN_MAX_RX_UNIT_RULE_E,
    RSCAN_RX_FILTER_NULL_E,
    RSCAN_INVALID_RX_RULE_ENTRY_E,
    RSCAN_INCORRECT_BAUDRATE_E,
}RsCanInitSt_En_t;

typedef enum
{
    RSCAN_TX_SUCCESS_E,
    RSCAN_TX_FIFO_FULL_E,
    RSCAN_TX_INVALID_UNIT_E,
    RSCAN_TX_INVALID_CHANNEL_E,
    RSCAN_INVALID_TX_LEN_E,
}RSCANTxState_En_t;
/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern RSCANconfg_St_t RSCANconfg_St[RSCAN_MAX_UNIT];
/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/

/*---------------------- End of File -----------------------------------------*/