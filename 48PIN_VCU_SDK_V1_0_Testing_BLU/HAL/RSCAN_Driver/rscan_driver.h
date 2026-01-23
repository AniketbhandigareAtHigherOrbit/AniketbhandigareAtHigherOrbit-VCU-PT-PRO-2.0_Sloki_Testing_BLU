/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : rscan_driver.h
|    Project        : CAN Driver development
|    Description    : The file is implements the RSCAN driver
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
#ifndef RSCAN_DRIVER_H
#define RSCAN_DRIVER_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "app_typedef.h"
#include"rscan_reg.h"
//#include "r_cg_macrodriver.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define RSCANFD0_BASE   (0xFFD00000)
#define UNIT_0      0
#define CLASSIC_CAN_MAX_LEN    ( 8U)
#define CANFD_MAX_LEN           (64U)

#define CANFD_LEN_12            (12U)
#define CANFD_LEN_16            (16U)
#define CANFD_LEN_20            (20U)
#define CANFD_LEN_24            (24U)
#define CANFD_LEN_32            (32U)
#define CANFD_LEN_48            (48U)
#define CANFD_LEN_64            (64u)

typedef void (*CanRxCallback_Fptr_t)(uint8_t Unit_u8,uint8_t Channel_u8,uint8_t* DataBuff_pu8,uint8_t Dlc_u8,uint8_t CanMode_u8,uint8_t Ide_u8,uint32_t CanId_u32);
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef enum
{
    CLASSICAL_CAN_MODE_E,
    CAN_FD_MODE_E,
}CanTransferMode_En_t;

typedef enum
{
    CAN_CHANNEL_1_E,
    CAN_CHANNEL_2_E,
    CAN_CHANNEL_3_E,
}CanChannel_En_t;

typedef enum
{
    _125K_BUADRATE_E,
    _250K_BAUDRATE_E,
    _500K_BAUDRATE_E,
    _1MBPS_BAUDRATE_E,
    _2MBPS_BAUDRATE_E,
    _4MBPS_BAUDRATE_E,
    _5MBPS_BAUDRATE_E,
}RsCanBuadrate_En_t;

typedef enum
{
    RX_BUFF_E,
    RX_FIFO_BUFF_E,
    TXRX_FIFO_RX_BUFF_E
}CanRxBuffType_En_t;

typedef enum
{
    TX_BUFF_E,
    TXRX_BUFF_TX_BUFF_E,
    TX_QUEUE_E,
    TX_HISTORY_BUFF_E,
}CanTxBuffType_En_t;

typedef enum
{
    STD_IDE_E,
    EXT_IDE_E,
}CanIDE_En_t;

typedef const struct 
{
    uint32_t CanId_u32;
    uint32_t MaskId_u32;
    CanRxBuffType_En_t RxBuffType_En;
    CanIDE_En_t Ide_u8;
    CanRxCallback_Fptr_t CanRxCallback_Fptr;
}CanRxFilterConf_St_t;

typedef const struct 
{
    uint8_t ChannelEn_u8;
    uint8_t NomilalBitrate_u8;
    uint8_t DataBitrate_u8;
    uint8_t CANMode_u8;
    uint8_t CanChannel_u8;
    uint8_t TotalRxFilter_u8;
    CanRxFilterConf_St_t *CanRxFilterConf_pSt;
}RSCANchannelConf_St_t;

/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern CanRxCallback_Fptr_t CanRxCallback_Fptr;
uint8_t RSCANinit(uint8_t Unit_u8,RSCANchannelConf_St_t* RSCANchannelConf_pSt);
extern uint8_t RSCAN_get_can_Bus_status(uint8_t Channel_u8);
uint8_t RSCANtransmit(uint8_t Unit_u8,uint8_t Channel_u8,uint8_t* DataBuff_pu8,uint8_t Dlc_u8,uint8_t CanMode_u8,uint8_t Ide_u8,uint32_t CanId_u32);
/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/

#endif
/*---------------------- End of File -----------------------------------------*/