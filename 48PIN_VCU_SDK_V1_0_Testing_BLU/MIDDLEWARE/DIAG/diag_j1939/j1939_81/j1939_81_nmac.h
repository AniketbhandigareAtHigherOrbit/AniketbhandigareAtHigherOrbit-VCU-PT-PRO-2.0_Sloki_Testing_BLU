/*******************************************************************************
*    FILENAME    : j1939_81_nmac.h
*
*    @brief      : Contains all general J1939-81 address claim mechanism
*                    
*    
*
*******************************************************************************
* Revision history
* 
* Ver Author       Date       Description
* 1   Sloki
*******************************************************************************
*/

/*
*******************************************************************************
*    Includes
*******************************************************************************
*/
#ifndef	_J1939_81_NMAC_H_
#define _J1939_81_NMAC_H_

//#include "stack_typedefs.h"
#include "can_sched_conf.h" 

/*
********************************************************************************
* defines
********************************************************************************
*/
/*Start address definition*/
#define J1939_81_NMAC_STARTADDRESS		0U

#define J1939_81_DATA_LENGTH			8U
#define J1939_81_MSBNAME_LENGTH			4U
#define J1939_81_LSBNAME_LENGTH			4U
#define J1939_81_CANID_LENGTH			4U
#define J1939_81_NMAC_MINADDRESS		0U
#define J1939_81_NMAC_MAXADDRESS		253U   
#define J1939_NMAC_PGN	 				0xEE00U
#define J1939_GLOBAL_ADDR				0x00FFU
#define J1939_NULL_ADDR				    0xFEU
#define J1939_PF_REQUEST				0xEAU
#define J1939_PF_ADDRESS_CLAIMED		0xEEU  /*with gloabal address   */
#define J1939_PF_CANNOT_CLAIM_ADDRESS	0xEEU  /*with NULL address      */

#define J1939_81_CONTENTION_WAIT_TIME_MS	250U 

#define NMAC_NAME_VIA_CALRAM    		(0)
/*
*********************************************************************************
*    Enum definitions
*********************************************************************************
*/
typedef enum
{
    J1939_NMAC_IDLE_E,
    J1939_NMAC_CANNOT_CLAIM_E,
    J1939_NMAC_PROCESSING_ADDR_CLAIM_E,
    J1939_NMAC_INPROGRESS_E,
    J1939_NMAC_DONE_E,
    J1939_NMAC_NOT_DONE_E
}J1939_NMAC_State_En_t;

typedef enum
{
    J1939_81_NMAC_TX_MODE,
    J1939_81_NMAC_RX_MODE
}J1939_NMAC_AddClaiming_Mode_En_t;  

typedef enum
{
    J1939_81_NO_RESP_E = 0,
    J1939_81_CANNOTCLAIM_E = 1,
    J1939AP_81_START_PROCESS_E = 2
}J1939_NMAC_AddClaiming_Status_En_t; 

/*
*********************************************************************************
*    Structure and Union definitions
*********************************************************************************
*/
typedef union
{
    struct
    {
        uint8_t Arbitrary_Address_b1	:1;
        uint8_t Industry_group_b3		:3;
        uint8_t Vehivle_Instance_b4	:4;
        uint8_t Vehicle_System_b7		:7;
        uint8_t Reserved_b1		:1;
        uint8_t Function_b8		:8;		
        uint8_t Function_Instance_b5	:5;
        uint8_t ECU_Instance_b3		:3;
    }Name;
    uint32_t Name_u32;
    uint8_t  Name_au8[4];
}J1939_81_NMAC_MSBName_Uni_t;

typedef union
{
    struct
    {
        uint32_t Manufacturer_Code_b11    :11;
        uint32_t Indentity_Number_21	:21;
    }Name;
    uint32_t Name_u32;
    uint8_t  Name_au8[4];
}J1939_81_NMAC_LSBName_Uni_t;

typedef union
{
    struct
    {
        uint8_t PDUFormat_u8;
        uint8_t SourceAddress_u8;		
    }Identifiers;
    uint16_t Identifiers_u16;
}J1939_81_NMAC_FrameIdentifier_Uni_t;

typedef struct
{
    J1939_81_NMAC_MSBName_Uni_t MSBName_Uni;
    J1939_81_NMAC_LSBName_Uni_t LSBName_Uni;
}J1939_81_NMAC_Name_St_t;
        
    
/*
*********************************************************************************
*    al Variables
*********************************************************************************
*/

/*
*********************************************************************************
*    MACROS to read the configuration parameter
*********************************************************************************
*/

/*
*********************************************************************************
*    Global Variables
*********************************************************************************
*/
extern  uint8_t J1939_NMAC_ECU_ClaimedAddr_u8;
extern J1939_NMAC_State_En_t J1939_81_NMAC_State_En;

/*
********************************************************************************
* function declaration
********************************************************************************
*/
 extern void J1939_81_NMAC_Init(void);
 extern void J1939_81_RXNMAC_Callback (uint16_t signalName, CAN_MessageFrame_St_t* canMsgRx);
 extern void J1939_81_nmac_50ms(void);
 extern void J1939_81_SendReqPGNResp(void);

#endif

