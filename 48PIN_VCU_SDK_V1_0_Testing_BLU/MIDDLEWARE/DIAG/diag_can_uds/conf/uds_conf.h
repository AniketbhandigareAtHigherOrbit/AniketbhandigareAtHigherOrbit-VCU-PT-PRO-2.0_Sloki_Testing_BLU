/******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File	          : uds_conf.h
|    Project	      :  MIL_PBL_CV
|    Description    : File contains  definitions and declarations for all the 
                      uds services.
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date     	     Name                      Company
| --------     ---------------------     ---------------------------------------
| 31/07/2024       Manikandan S               Sloki Software Technologies LLP.
|-------------------------------------------------------------------------------
*******************************************************************************/

#ifndef _UDS_CONF_H_
#define _UDS_CONF_H_

/*******************************************************************************
 *  Includes
 ******************************************************************************/

#include "str_util.h"
#include "nvm_parameter.h"
#include "uds_session.h"
#include "diag_appl_test.h"
#include "diag_typedefs.h"
#include "diag_sys_conf.h"
#if(TRUE == DIAG_CONF_CANTP_SUPPORTED)
#include "i15765.h"
#include"nvm_parameter.h"
#include"nvm_conf.h"
#include "nvm_data.h"
//#include "eeprom.h"
//#include "eep_at02m.h"
#endif

/*******************************************************************************
 *  Define & Macros
 ******************************************************************************/
 
/********************To enable and disable the service*************************/
#define UDS_SERVICE10_ENABLE   TRUE  /* To enable and disable the service10 */
#define UDS_SERVICE11_ENABLE   TRUE  /* To enable and disable the service11 */
#define UDS_SERVICE14_ENABLE   TRUE  /* To enable and disable the service14 */
#define UDS_SERVICE19_ENABLE   TRUE  /* To enable and disable the service19 */
#define UDS_SERVICE22_ENABLE   TRUE /* To enable and disable the service22 */
#define UDS_SERVICE23_ENABLE   FALSE /* To enable and disable the service23 */
#define UDS_SERVICE27_ENABLE   TRUE  /* To enable and disable the service27 */
#define UDS_SERVICE28_ENABLE   TRUE  /* To enable and disable the service28 */
#define UDS_SERVICE2E_ENABLE   TRUE  /* To enable and disable the service2E */
#define UDS_SERVICE2F_ENABLE   FALSE /* To enable and disable the service2F */
#define UDS_SERVICE31_ENABLE   TRUE  /* To enable and disable the service31 */
#define UDS_SERVICE34_ENABLE   FALSE  /* To enable and disable the service34 */
#define UDS_SERVICE36_ENABLE   FALSE  /* To enable and disable the service36 */
#define UDS_SERVICE37_ENABLE   FALSE  /* To enable and disable the service37 */
#define UDS_SERVICE3D_ENABLE   FALSE /* To enable and disable the service3D */
#define UDS_SERVICE3E_ENABLE   TRUE  /* To enable and disable the service3E */
#define UDS_SERVICE83_ENABLE   FALSE  /* To enable and disable the service83 */
#define UDS_SERVICE85_ENABLE   TRUE /* To enable and disable the service85 */
#define UDS_SERVICE87_ENABLE   FALSE  /* To enable and disable the service87 */
#define UDS_D_WRITE_ENABLE     TRUE
#define UDS_TASKS_WRITE_ENABLE FALSE

/******************************************************************************/
#define SECURITY_GAIN_SIZE	1

#define SUB_FUNC_MASK_VALUE             (0x7F)
#define POS_RESP_MASK_SUPRESS_VALUE     (0x80)
#define POS_RESP_SUPPRESS_VALUE			(0x80)

/*****************************Session modes************************************/
#define UDS_SESS_EQU_DEFAULT                (0x01u)
#define UDS_SESS_EQU_PROG                   (0x02u)
#define UDS_SESS_EQU_EXTENDED               (0x04u)
#define UDS_SESS_EQU_FOTA                   (0x08u)	

#define UDS_SESS_ALL	(UDS_SESS_EQU_DEFAULT|UDS_SESS_EQU_PROG|UDS_SESS_EQU_EXTENDED|UDS_SESS_EQU_FOTA)
#define UDS_SESS_NON	(0x00u)

#define NO_SECURITY_EQU						(0x00)
#define SECURITY_EQU_LEVEL_1				(0x01u)
#define SECURITY_EQU_LEVEL_2				(0x02u)
#define SECURITY_EQU_LEVEL_3				(0x04u)
#define SECURITY_EQU_LEVEL_4				(0x08u)
#define SECURITY_EQU_LEVEL_5				(0x10u)
#define SECURITY_EQU_LEVEL_6				(0x20u)


/******************************************************************************/
/*****************************UDS SID LIST*************************************/
#define SID_SESSIONCONTROL              (0x10)
#define SID_ECURESET                    (0x11)
#define SID_CDTC                        (0x14)
#define SID_RDTC                        (0x19)
#define SID_RDBDID                      (0x22)
#define SID_RMBA                        (0x23)
#define SID_SA                          (0x27)
#define SID_COMMUNICATIONCONTROL        (0x28)
#define SID_PDID                        (0x2A)
#define SID_DDID                        (0x2C)
#define SID_WDBDID                      (0x2E)
#define SID_IOCBDID                     (0x2F)
#define SID_ROUTINE_CONTROL             (0x31)
#define SID_REQUEST_DOWNLOAD            (0x34)
#define SID_TRANSFER_DATA               (0x36)
#define SID_TRANSFER_DATA_EXIST         (0x37)
#define SID_TESTERPRESENT               (0x3E)
#define SID_WMBA                        (0x3D)
#define SID_CONTROLDTC                  (0x85)
#define SID_ATP                         (0x83)
#define SID_LINK_CONTROL								(0x87)
/******************************************************************************/
/*****************************UDS NRC LIST*************************************/
#define GENERAL_REJECT					(0x10)
#define SERVICE_NOT_SUPPORTED           (0x11)
#define SUB_FUNC_NOT_SUPPORTED          (0x12)
#define INVALID_MESSAGE_LENGTH          (0x13)
#define RESP_LEN_EXCEEDED               (0x14)
#define CONDITION_NOT_CORRECT           (0x22)
#define REQUEST_SEQUENCE_ERR            (0x24)
#define REQUEST_OUT_OF_RANGE            (0x31)
#define SECURITY_ACCESS_DENIED          (0x33)
#define AUTHENTICATION_REQUIRED         (0x34)
#define INVALID_KEY                     (0x35)
#define EXCEEDED_NUMBER_OF_ATTEMPTS     (0x36)    
#define REQ_TIMEDELAY_NOTEX             (0x37)
#define UPLOAD_DOWNLOAD_NOT_ACCEPTED    (0x70)
#define TRANSFER_DATA_SUSPENDED         (0x71)
#define GEN_PROG_FAILURE                (0x72)  
#define WRONG_BLOCK_SEQUENCE_CNTR       (0x73)
#define ERROR_REQ_OK_RESP_PENDING       (0x78)
#define SUBFUNC_NOSUPP_IN_ACTIVE_SESS   (0x7E)
#define SERVNOSUPP_IN_ACTIVE_SESS       (0x7F)
#define VOLTAGE_TOO_HIGH                (0x92)
#define VOLTAGE_TOO_LOW                 (0x93)
#define NEGATIVE_RESP                  	(0x7F)

#define DEFAULT_P2_CAN_MAX                    50  /* P2  Server Max = 50ms   */
#define DEFAULT_P2_CAN_MAX_HB                 0u
	
#define P2_SERVER_MAX       5000    /* P2* Server Max = 5000ms */
#define P2_SERVER_MAX_RESOLUTION    10

#define ENHANCED_P2_CAN_MAX                   ((P2_SERVER_MAX/P2_SERVER_MAX_RESOLUTION) & 0xFF) 
#define ENHANCED_P2_CAN_MAX_HB                (((P2_SERVER_MAX/P2_SERVER_MAX_RESOLUTION) >> EIGHT) & 0xFF)

/******************************************************************************/
/**********************Service 0x31********************************************/
typedef enum
{
	SECURITY_LEVEL_1_E, /* Programming secret key*/
	SECURITY_LEVEL_2_E, /* Enhanced Secret key*/
	SECURITY_LEVEL_3_E, 
	SECURITY_LEVEL_4_E, /* EOL line secret key*/
	TOTAL_SECURITY_LEVEL_E,
	NO_SECURITY_REQ_E,
	ANY_ONE_SECURITY_REQ_E,
}Uds27SecrtLevel_En_t;

typedef enum
{
	FLASH_NONE_E,
	INTERNAL_FLASH_E,
	EXTERNAL_EEPROM_1_STORAGE_E,
	EXTERNAL_EEPROM_2_STORAGE_E,
	RAM_MEMORY_E,
}FlashTypes_En_t;

typedef enum
{
Software_invalid_E,
Software_Backup_in_progress_E,
Software_Backup_completed_E,
Software_download_in_progress_E,
Software_self_rollback_E,
Software_valid_E,
Software_verification_in_progress_E,
Software_external_roll_back_E,
}FOTA_Status_En_t;

#pragma pack(1)
typedef struct 
{
	uint32_t Active_Code_Size_u32;
	uint32_t Active_Code_CRC_u32;
	uint32_t Backup_Code_Size_u32;
	uint32_t Backup_Code_CRC_u32;
	uint8_t Backup_Code_Error_u8;
	FOTA_Status_En_t FOTA_Status_En;
	uint8_t Code_Fail_Counter_u8;
}Code_Details_st_t;


#pragma pack(1)
typedef struct 
{
	uint32_t Active_SBL_Size_u32;
	uint32_t Active_SBL_CRC_u32;
	uint8_t Backup_SBL_Error_u8;
	// uint8_t SBL_Update_Flag_u8;
}SBL_Data_st_t;

#pragma pack(1)
typedef struct 
{
	Code_Details_st_t ASW_Data_st;
	Code_Details_st_t HMI_Data_st;
	SBL_Data_st_t SBL_Data_st;
	uint8_t Software_Update_Mode_FOTA_Or_Tester;
}BSW_NVM_Data_St_t;

#pragma pack(1)
typedef struct 
{
	uint32_t Active_App_Size_u32;
	uint32_t Active_App_CRC_u32;
	uint32_t Backup_App_Size_u32;
	uint32_t Backup_App_CRC_u32;
	uint32_t Active_HMI_Size_u32;
	uint32_t Active_HMI_CRC_u32;
	uint32_t Backup_HMI_Size_u32;
	uint32_t Backup_HMI_CRC_u32;
	uint32_t Backup_SBL_Size_u32;
	uint32_t Backup_SBL_CRC_u32;
	uint8_t Backup_SBL_Error_u8;
	uint8_t Backup_ASW_Error_u8;
	uint8_t Backup_HMI_Error_u8;
	uint8_t ASW_SW_Status_u8;
	uint8_t HMI_SW_Status_u8;
	uint8_t ASW_Fail_Counter_u8;
	uint8_t HMI_Fail_Counter_u8;
	// uint8_t SBL_Update_Flag_u8;
	uint8_t Softare_Update_Mode_u8;
}BSW_NVM_Update_St_t;
/******************************************************************************/
/**********************Service 0x31********************************************/


/******************************************************************************/
/**********************Service 0x19********************************************/
#if (TRUE == UDS_SERVICE19_ENABLE)
#define SERV19_NUMOF_SUB_FUNCTIONS        (5U)
#define SERV19_RECORDNUMBER_SUPPORTED     (0x01U)
#define SERV19_RECORDNUMBER_SUPPORTED_ALL (0xFFU)
#endif
/******************************************************************************/
/**********************Service 0x14********************************************/
#if (TRUE == UDS_SERVICE14_ENABLE)
#define NUMBER_OF_GROUP_DTC_IDs         (0x01U)
#endif
/******************************************************************************/
#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE) || (TRUE == UDS_SERVICE2F_ENABLE))
/***************************Service 0x22/0x2E DIDs*****************************/
#if (TRUE == DIAG_TEST_DEMO_CODE)
	#define SAMPLE_DID_1                  (0xA200)
	#define SAMPLE_DID_2                  (0xA201)
	#define SAMPLE_DID_3                  (0xA202)
	#define SAMPLE_DID_4                  (0xA203)
	#define SAMPLE_DID_5                  (0xA204)
	#define SAMPLE_DID_6                  (0xA205)
	#define SAMPLE_DID_7                  (0xA206)
	#define SAMPLE_DID_8                  (0xA207)
	#define SAMPLE_DID_9                  (0xA208)
	#define SAMPLE_DID_10                 (0xA209)
#endif
/********************************** DID RELATED DATA ***********************************/

/**********MANUFACTURING DATA DID************* */

#define DID_VIN_NUM								0xF190
#define DID_REPAIR_SHOP_CODE					0xF198
#define DID_PROGRAMMING_DATE					0xF199
#define DID_REPROGRAMMING_SEQUENCE				0x721E
#define DID_ACTIVE_DIAG_SESSION					0xF186

/********** ECU INFORMATION DID ************* */

#define DID_ECU_MANUFACTURING_DATE  			0xF18B
#define DID_SUPPLIER_ECU_SERIAL_NUMBER			0xF18C
#define DID_ECU_HARDWARE_NUMBER				    0xF193
#define DID_ECU_ASW_NUMBER						0xF195
#define DID_SUPPLIER_ECU_PART_NUMBER			0xF187
#define DID_BSW_IDENTIFICATION_NUMBER			0xF180

#define ECU_MANUFACTURING_DATE_SIZE		       0x20
#define SUPPLIER_ECU_SERIAL_NUMBER_SIZE		   0x20	
#define ECU_HARDWARE_NUMBER_SIZE		       0x20		
#define ECU_ASW_NUMBER_SIZE		               0x20			
#define SUPPLIER_ECU_PART_NUMBER			   0x20			
#define BSW_IDENTIFICATION_NUMBER_SIZE		   0x20			
	
#define FLASH_DID_START_ADDRESS				   0x800
#define SUPPLIER_ECU_SERIAL_NUMBER_ADDRESS 	   (FLASH_DID_START_ADDRESS+ECU_MANUFACTURING_DATE_SIZE)
#define ECU_HARDWARE_NUMBER_ADDRESS 	       (SUPPLIER_ECU_SERIAL_NUMBER_ADDRESS+SUPPLIER_ECU_SERIAL_NUMBER_SIZE)
#define ECU_ASW_NUMBER_ADDRESS 	               (0x19000)
#define SUPPLIER_ECU_PART_NUMBER_ADDRESS 	   (ECU_HARDWARE_NUMBER_ADDRESS+ECU_HARDWARE_NUMBER_SIZE+ECU_ASW_NUMBER_SIZE)
#define BSW_IDENTIFICATION_NUMBER_ADDRESS 	   (SUPPLIER_ECU_PART_NUMBER_ADDRESS +SUPPLIER_ECU_PART_NUMBER)


/* ******* Global Snapshot DID **********/
#define GLOBAL_FF_DID_1								    0xA000
#define GLOBAL_FF_DID_2								    0xA001


/* ******* Local Snapshot DID **********/								    
#define SAMPLE_DID_2								    0x720A
#define SAMPLE_DID_3								    0x7201
#define SAMPLE_DID_4								    0x7202
#define SAMPLE_DID_5								    0x7203
#define SAMPLE_DID_6								    0x7204

#define DID_CONFIGURATION_DATA						0x0100
#define DID_ASW_SW_VERSION					     	0xF181

#define TOTAL_DID							24


#define PBL_NVM_BLOCK		0x00
#define BSW_NVM_BLOCK		0x03
#define BLOCK_0_RESERVED						(19u)


// #define EEPROM_OFFSET						(0x1E00)
// #define NVM_HEADER_SIZE						(0x02)
// #define NVM_CRC_SIZE						(0X02)
// #define PBL_NVM_START_ADDR					(64u)
// #define PBL_PARAM_NVM_OFFSET					(PBL_NVM_START_ADDR+NVM_CRC_SIZE+NVM_HEADER_SIZE)
// #define BSW_NVM_START_ADDR					(204u)
// #define BSW_PARAM_NVM_OFFSET					(BSW_NVM_START_ADDR+NVM_CRC_SIZE+NVM_HEADER_SIZE)

// #define DID_NVM_START_ADDR					(104u)
// #define DID_NVM_OFFSET						(DID_NVM_START_ADDR+NVM_CRC_SIZE+NVM_HEADER_SIZE)


// #define ECU_PBL_SOFTWARE_NUMBER						 (0x723E)
// #define ECU_SBL_SOFTWARE_NUMBER					     (0x723F)
// // #define ECU_VM_ECU_HARDWARENUMBER				     (0xF191)

// #define ECU_PBL_SOFTWARE_NUMBER_SIZE				 (17)
// #define ECU_SBL_SOFTWARE_NUMBER_SIZE			     (17)
// // #define ECU_VM_ECU_HARDWARENUMBER_SIZE				 (17)
// #define Boot_Software_Identification_SIZE			 (25)	
// #define Boot_FingerPrint_Data_SIZE					 (31)

#define Prog_Secret_Key_offset						(14)
#define Enhanced_Secret_offset                      (18)
#define End_Of_Line_Secret_offset                   (22)

#define PROG_SECRET_KEY			(0x04) /* In bytes*/
#define REPROG_REQ_MASK			(0x0F)
#define REPROG_REQ_UNMASK		(0xF0)
#define REPROG_VALUE			(0x01)

/* DID bit position */
#define DATA_BLOCK_VALID	0x5A
#define DATA_BLOCK_INVALID	0xA5

#endif
/**********************UART****************************************************/
/* user defined can be changed if required*/
#define START_OF_FRAME             0X5555
#define END_OF_FRAME               0xAAAA

/* length of each filed in the frame */
#define MAX_FRAME_LENGTH           0x02
#define SOURCE_ID_LENGTH           0x01
#define FRAME_TYPE                 0x01
#define PAYLOAD_MIN_SIZE           0x03
#define PAYLOAD_MAX_SIZE           0x400
// #define CRC_SIZE                   0x01

#define  BOOTLOADER_RESERVED_EEPROM       0X20

/******************************************************************************/
/**********************************MACHINE_STATE********************************/
#define	MPU_UART_ENABLE		FALSE

/******************************************************************************/
/*******************************BIT MAPPED DID*********************************/

/******************************************************************************/
/********************************NUMERIC DID***********************************/

/******************************************************************************/
/******************************STATE ENCODED DID*******************************/

/******************************************************************************/
/*********************************PACKETED DID*********************************/

/******************************************************************************/

/******************************************************************************/
/***********************Service 0x83***************************/			
//#define DEFAULT_VALUE        		0x00u    /* Default extended timing parameter set*/
//#define CUSTOMER_VALUE        	0x01u    /* Customer extended timing parameter set*/
/******************************************************************************/

#if (TRUE == UDS_SERVICE22_ENABLE)
/***********************Service 0x22 MIN and MAX LEN***************************/
#define SERV22_MIN_LEN        		0x03u    /* Minimum Length for Read Data Identifier*/
#define MAX_DID_READ				0x04
#define SERV22_MAX_LEN        		(1 +2*MAX_DID_READ)   /* Maximum Length for Read Data Identifier*/
/******************************************************************************/
#endif
#if (TRUE == UDS_SERVICE2E_ENABLE)
/***********************Service 0x22 MIN and MAX LEN***************************/			
#define SERV2E_MIN_LEN        		0x04u    /* Minimum Length for Write Data Identifier*/
#define SERV2E_MAX_LEN        		0x64u    /* Maximum Length for Write Data Identifier*/
/******************************************************************************/
#endif

/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/

/*******************************service states*********************************/
typedef enum
{
	UDS_SERV_STAT_UNKNOWN_E = 0,
	UDS_SERV_STAT_REQUEST_DOWNLOAD_E,
	UDS_SERV_STAT_REQUEST_UPLOAD_E
}UDS_Serv_Stat_En_t;

typedef enum
{
	IDLE_STATE_E = 0U,
	WAIT_PENDING_E,
}ST_MACHINE_En_t;

typedef enum
{
	FPD_START_E,
	BSW_FPD_E = FPD_START_E,
	ASW_FPD_E,
	CONFIG_FPD_E,
	CALLIB_FPD_E,
	TOTAL_FPD_E,
}FingerPrintDID_En_t;

typedef enum
{
	TESTER_PROGRAMMING_E,
	FOTA_PROGRAMMING_E,
}SW_UpdateMode_St_t;
/******************************************************************************/
/************************UDS Service service Enum******************************/
typedef enum
{
	UDS_SERVICE_START_E = 0,
	
	UDS_SERVICE10_START_E = UDS_SERVICE_START_E,
#if (TRUE == UDS_SERVICE10_ENABLE)
	UDS_SERVICE10_E  ,
	UDS_SERVICE10_END_E = UDS_SERVICE10_E,
#else
	UDS_SERVICE10_END_E = UDS_SERVICE10_START_E,
#endif

	UDS_SERVICE11_START_E = UDS_SERVICE10_END_E,
#if (TRUE ==UDS_SERVICE11_ENABLE)
	UDS_SERVICE11_E ,
	UDS_SERVICE11_END_E = UDS_SERVICE11_E,
#else
	UDS_SERVICE11_END_E = UDS_SERVICE11_START_E ,
#endif

	UDS_SERVICE14_START_E = UDS_SERVICE11_END_E,
#if (TRUE ==UDS_SERVICE14_ENABLE)
	UDS_SERVICE14_E ,
	UDS_SERVICE14_END_E = UDS_SERVICE14_E,
#else
	 UDS_SERVICE14_END_E = UDS_SERVICE14_START_E ,
#endif

	UDS_SERVICE19_START_E = UDS_SERVICE14_END_E,
#if (TRUE ==UDS_SERVICE19_ENABLE)
	UDS_SERVICE19_E ,
	UDS_SERVICE19_END_E = UDS_SERVICE19_E,
#else
	 UDS_SERVICE19_END_E = UDS_SERVICE19_START_E ,
#endif

	UDS_SERVICE22_START_E = UDS_SERVICE19_END_E,
#if (TRUE ==UDS_SERVICE22_ENABLE)
	UDS_SERVICE22_E ,
	UDS_SERVICE22_END_E = UDS_SERVICE22_E,
#else
	 UDS_SERVICE22_END_E = UDS_SERVICE22_START_E ,
#endif

	UDS_SERVICE23_START_E = UDS_SERVICE22_END_E,
#if (TRUE ==UDS_SERVICE23_ENABLE)
	UDS_SERVICE23_E ,
	UDS_SERVICE23_END_E = UDS_SERVICE23_E,
#else
	 UDS_SERVICE23_END_E = UDS_SERVICE23_START_E ,
#endif

	UDS_SERVICE27_START_E = UDS_SERVICE23_END_E,
#if (TRUE ==UDS_SERVICE27_ENABLE)
	UDS_SERVICE27_E ,
	UDS_SERVICE27_END_E = UDS_SERVICE27_E,
#else
	 UDS_SERVICE27_END_E = UDS_SERVICE27_START_E ,
#endif


	UDS_SERVICE28_START_E = UDS_SERVICE27_END_E,
#if (TRUE ==UDS_SERVICE27_ENABLE)
	UDS_SERVICE28_E ,
	UDS_SERVICE28_END_E = UDS_SERVICE28_E,
#else
	 UDS_SERVICE28_END_E = UDS_SERVICE28_START_E ,
#endif

	UDS_SERVICE2E_START_E = UDS_SERVICE28_END_E,
#if (TRUE ==UDS_SERVICE2E_ENABLE)
	UDS_SERVICE2E_E ,
	UDS_SERVICE2E_END_E = UDS_SERVICE2E_E,
#else
	 UDS_SERVICE2E_END_E = UDS_SERVICE2E_START_E ,
#endif

	UDS_SERVICE2F_START_E = UDS_SERVICE2E_END_E,
#if (TRUE ==UDS_SERVICE2F_ENABLE)
	UDS_SERVICE2F_E ,
	UDS_SERVICE2F_END_E = UDS_SERVICE2F_E,
#else
	 UDS_SERVICE2F_END_E = UDS_SERVICE2F_START_E ,
#endif

	UDS_SERVICE31_START_E = UDS_SERVICE2F_END_E,
#if (TRUE ==UDS_SERVICE31_ENABLE)
	UDS_SERVICE31_E ,
	UDS_SERVICE31_END_E = UDS_SERVICE31_E,
#else
	 UDS_SERVICE31_END_E = UDS_SERVICE31_START_E ,
#endif

	UDS_SERVICE34_START_E = UDS_SERVICE31_END_E,
#if (TRUE ==UDS_SERVICE34_ENABLE)
	UDS_SERVICE34_E ,
	UDS_SERVICE34_END_E = UDS_SERVICE34_E,
#else
	 UDS_SERVICE34_END_E = UDS_SERVICE34_START_E ,
#endif


	UDS_SERVICE36_START_E = UDS_SERVICE34_END_E,
#if (TRUE ==UDS_SERVICE36_ENABLE)
	UDS_SERVICE36_E ,
	UDS_SERVICE36_END_E = UDS_SERVICE36_E,
#else
	 UDS_SERVICE36_END_E = UDS_SERVICE36_START_E ,
#endif

	UDS_SERVICE37_START_E = UDS_SERVICE36_END_E,
#if (TRUE ==UDS_SERVICE37_ENABLE)
	UDS_SERVICE37_E ,
	UDS_SERVICE37_END_E = UDS_SERVICE37_E,
#else
	 UDS_SERVICE37_END_E = UDS_SERVICE37_START_E ,
#endif

	UDS_SERVICE3D_START_E = UDS_SERVICE37_END_E,
#if (TRUE ==UDS_SERVICE3D_ENABLE)
	UDS_SERVICE3D_E ,
	UDS_SERVICE3D_END_E = UDS_SERVICE3D_E,
#else
	 UDS_SERVICE3D_END_E = UDS_SERVICE3D_START_E ,
#endif

	UDS_SERVICE3E_START_E = UDS_SERVICE3D_END_E,
#if (TRUE ==UDS_SERVICE3E_ENABLE)
	UDS_SERVICE3E_E ,
	UDS_SERVICE3E_END_E = UDS_SERVICE3E_E,
#else
	 UDS_SERVICE3E_END_E = UDS_SERVICE3E_START_E ,
#endif

	UDS_SERVICE83_START_E = UDS_SERVICE3E_END_E,
#if (TRUE ==UDS_SERVICE83_ENABLE)
	UDS_SERVICE83_E ,
	UDS_SERVICE83_END_E = UDS_SERVICE83_E,
#else
	 UDS_SERVICE83_END_E = UDS_SERVICE83_START_E ,
#endif

	UDS_SERVICE85_START_E = UDS_SERVICE83_END_E,
#if (TRUE ==UDS_SERVICE85_ENABLE)
	UDS_SERVICE85_E ,
	UDS_SERVICE85_END_E = UDS_SERVICE85_E,
#else
	 UDS_SERVICE85_END_E = UDS_SERVICE85_START_E ,
#endif

	UDS_SERVICE87_START_E = UDS_SERVICE85_END_E,
#if (TRUE ==UDS_SERVICE87_ENABLE)
	UDS_SERVICE87_E ,
	UDS_SERVICE87_END_E = UDS_SERVICE87_E,
#else
	 UDS_SERVICE87_END_E = UDS_SERVICE87_START_E ,
#endif

	UDS_TOTAL_SERVICE_E = UDS_SERVICE87_END_E ,
	
	
}UDS_Service_En_t;

/******************************************************************************/
/***********************state machine for boot loader software*****************/
typedef enum
{
	SERVICE_IDLE_E = 0U,
	SERVICE31_CHECK_REPROGRAMMING_PRECONDITION_E,
	SERVICE31_ERASE_E ,
	SERVICE34_E ,
	SERVICE36_E ,
	SERVICE37_E ,
	SERVICE31_CHECK_PROGRAMMING_DEPENDENCY_E ,
	SERVICE31_ACTIVATE_SECENDARY_BOOTLOADER_E,
	SERVICE31_CHECK_VALID_SOFTWARE_COMPONENT_E,
}FlashState_En_t;          

/******************************************************************************/
/***************************state machine for erase ***************************/
typedef enum
{
	NOT_ERASABLE_E = 0U,
	ERASABLE_E,
}EraseState_En_t;
/******************************************************************************/
/****************************related to service 31*****************************/
/******************************************************************************/
/**************All the supported sessions for UDS Services*********************/

/******************************************************************************/
#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE) || (TRUE == UDS_SERVICE2F_ENABLE))
/***************************UDS Service 0x22/0x2E *****************************/

/******************************************************************************/
#endif
#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE) || (TRUE == UDS_SERVICE2F_ENABLE))
/***************************UDS Service 0x22/0x2E *****************************/
typedef enum
{
	ASCII_E = 0u,            /* Used for STRING/Character Type*/
	INT_E,                   /* Used for Numerical Type*/
	HEX_E,
	NUMERIC_E,
	STATE_ENCODED_E,
	PACKETED_E,
	BIT_MAPPED_E
}DID_Value_Status_En_t;
/******************************************************************************/
#endif
#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE) || (TRUE == UDS_SERVICE2F_ENABLE))
/***************************UDS Service 0x22/0x2E *****************************/
typedef enum
{
	READ_ONLY_E = 1u,        /* READ_ONLY Access Type for DID*/
	WRITE_ONLY_E,            /* WRITE_ONLY Access Type for DID*/
	READ_WRITE_E,            /* READ_WRITE_ONLY Access Type for DID*/
	IO_CONTROL_E,
	FREEZE_FRAME_E
}DID_aceess_type_En_t;
#endif
/******************************************************************************/
#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE) || (TRUE == UDS_SERVICE2F_ENABLE))
/***************************UDS Service 0x22/0x2E******************************/
/***************************UDS Service state machine******************************/

/*********************************************************************************/

typedef union
{
	uint32_t 				Permission_u8;

}DID_Permission_Un_t;	/* Union used for DID session Check  */
/******************************************************************************/
#endif
#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE) || (TRUE == UDS_SERVICE2F_ENABLE))
/***************************UDS Service 0x22/0x2E******************************/
typedef enum
{
	SLOW_RATE_E = 1,
	MEDIUM_RATE_E = 2,
	FAST_RATE_E = 3,
	STOP_PERIODIC_TX_E = 4,
	UN_INIT_E
}Transmition_Modes_En_t;
/******************************************************************************/
#endif
typedef enum
{
	RAM_STORAGE_E,
	FLASH_STORAGE_E,
	EEPROM_STORAGE_E
}Memory_type_En_t;
#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE) || (TRUE == UDS_SERVICE2F_ENABLE))
/*******************************IO_CONTROL*************************************/

/******************************************************************************/
#endif
/************************UDS Service 0x19 structure****************************/

/******************************************************************************/
/*************************related to service31*********************************/

#pragma pack(1)
typedef struct 
{
	uint8_t DiagSecurityState_u8;
	uint8_t DiagSessionState_u8;
	uint8_t ReprogramReqState_u8;
	uint8_t EcuReset_u8;
	uint8_t SBLstate_u8;
	uint32_t New_SBL_CRC_u32;
	uint32_t New_SBL_Size_u32;
	uint8_t SBL_Update_Flag_u8;
	uint32_t RandomNum_u32;
}PblParam_St_t;

typedef const struct 
{
	const uint8_t PblNoModule_u8;
	const uint8_t PblVersion_au8[24];
	const uint8_t BswDate_au8[10];
	const uint8_t BswShopCode_au8[10];
	const uint8_t BswTesterSerNum_au8[10];
	const uint8_t ReprogSeq_u8;
}ProductInfo_St_t;

typedef uint8_t (*Erase_Fptr_t)(uint32_t MemAddrs_u32, uint32_t MemSize_u32);
typedef uint8_t (*Write_Fptr_t)(uint32_t MemAddrs_u32, uint32_t MemSize_u32, uint8_t * DataBuff_pu8);
typedef uint8_t (*Read_Fptr_t)(uint32_t MemAddrs_u32, uint32_t MemSize_u32, uint8_t * DataBuff_pu8);

typedef struct 
{
	Erase_Fptr_t Active_Erase_Routine;
	Write_Fptr_t Active_Write_Routine;
	Read_Fptr_t Active_Read_Routine;
	Erase_Fptr_t Backup_Erase_Routine;
	Write_Fptr_t Backup_Write_Routine;
	Read_Fptr_t Backup_Read_Routine;
	void* BSW_NVM_Data_St;
}MemAccFptr_St_t;

typedef struct
{
	uint16_t                  BlockID_u16;
	uint32_t                  StartAddr_u32;
	uint32_t                  Size_u32;
	EraseState_En_t           EraseState_En;
	uint8_t 				 BlockState_u8;
	uint32_t          		BackupMemStartAddr_u32;
	uint32_t         		 BackupMemSize_u32;
	FlashTypes_En_t		  ActiveMemory_En;
	FlashTypes_En_t		  BackupMemory_En;
	MemAccFptr_St_t*		MemAccFptr_St;
}MemBlockConf_St_t;

typedef enum 
{
	DATA_BLOCK_VALID_E,
	DATA_BLOCK_INVALID_E,
	ERASE_STARTED_E,
	ERASE_INPROGRESS_E,
	ERASE_COMPLETED_E,
	DOWNLOAD_INPROGRESS_E,
	DOWNLOAD_COMPLETED_E,
	VERIFICATION_INPROGRESS_E,
	VERIFICATION_COMPLETED_E,
	BACKUP_ERASE_STARTED_E,
	BACKUP_ERASE_INPROGRESS_E,
	BACKUP_ERASE_COMPLETED_E,
	BACKUP_DOWNLOAD_INPROGRESS_E,
	BACKUP_DOWNLOAD_COMPLETED_E,
	BACKUP_VERIFICATION_INPROGRESS_E,
	BACKUP_VERIFICATION_COMPLETED_E,
	SBL_BACKUP_STARTED_E,
	SBL_BACKUP_INPROGRESS_E,
	SBL_BACKUP_COMPLETED,
	ROLLBACK_STARTED_E,
	ROLLBACK_INPROGRESS_E,
	ROLLBACK_COMPLETED_E,
	ROLLBACK_ERASE_STARTED_E,
	ROLLBACK_ERASE_INPROGRESS_E,
	ROLLBACK_ERASE_COMPLETED_E,
	ROLLBACK_DOWNLOAD_INPROGRESS_E,
	ROLLBACK_DOWNLOAD_COMPLETED_E,
	ROLLBACK_VERIFICATION_INPROGRESS_E,
	ROLLBACK_VERIFICATION_COMPLETED_E,
	CHECK_ACTIVE_MEMORY_STARTED_E,
	CHECK_ACTIVE_MEMORY_INPROGERSS_E,
	CHECK_ACTIVE_MEMORY_COMPLETED_E,
}BlkState_St_t;

/*******************************related to 31 service*********************************/
typedef struct
{
	uint32_t                  Addr_u32;
	uint32_t                  Size_u32;
}Add_Size_St_t;
/******************************************************************************/
/*************************related to service31*********************************/

typedef enum
{
	ROUTINE_IDLE_E,
	ROUTINE_START_E,
	ROUTINE_INPROGRESS_E,
	ROUTINE_COMPLETED_E,
}Uds31RoutineResult_En_t;

typedef enum
{
	ASW_BLOCK_E,
	TOTAL_BLOCK_E,
}ProgramBlock_En_t;

typedef struct 
{
	uint16_t SblErasenum_u16;
	uint16_t SblVarifiednum_u16;
}SblPgmData_St_t;
/******************************************************************************/
#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE))
/*************************related to service22/2E******************************/
typedef struct
{
	uint8_t                   Masking_Byte_pos;		/* Byte position		*/
	uint8_t	                  Masking_Data;           /* Min Data Value		*/
}ST_DID_MASK;
/******************************************************************************/
#endif

#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE) || (TRUE == UDS_SERVICE2F_ENABLE))
/*************************related to service22/2E******************************/
                                        /* Structure declaration used by RDBDID(0x22) & WDBDID(0x2E)*/
/******************************************************************************/
#endif
/*******************************************************************************
 *  GLOBAL VARIABLES
 ******************************************************************************/
/******************************************Used  br servic 11******************/
 extern bool SoftReset_b;
 extern volatile bool HardReset_b;
 extern bool JumpToSBL_b;
 extern bool JumpToApplication_b;
 extern uint8_t ReProgmReq_u8;
 extern uint8_t PgmDelayEn_u8;

 extern uint32_t SblJumpCnt_u32; 
 extern uint32_t ApplJumpCnt_u32;
 extern uint32_t EcuResetCnt_u32;
 extern uint32_t PblDelayWaitCnt_u32;

 extern SblPgmData_St_t SblPgmData_St;
 extern bool Prg_stratd_flag;

extern ProductInfo_St_t DevInfo_St;
extern SW_UpdateMode_St_t SW_UpdateMode_St;

/******************************************************************************/
extern const ServiceDistUDS_St_t UDSServDist_apt[UDS_TOTAL_SERVICE_E];
/*************************related to servic 31 ********************************/

/*************************related to servic 31 ********************************/
extern MemBlockConf_St_t   	MemBlockConf_aSt[TOTAL_BLOCK_E]; 
/*************************related to servic 19*********************************/
typedef enum
{
	SERV19_NUMBER_OF_DTC_BY_STATUS_MASK_E = 0x01, // 1
	SERV19_DTC_BY_STATUS_MASK_E,				  // 2
	SERV19_DTC_SNAPSHOT_IDENTIFICATION_E,
	SERV19_DTC_SNAPSHOT_RECORD_BY_DTC_NUMBER_E, // 4
	SERV19_DTC_STORED_RECORD_BY_RECORD_NUMBER_E,
	SERV19_DTC_EXTENDED_DATA_RECORD_BY_DTC_NUMBER_E, // 6
	SERV19_NUMBER_OF_DTC_BY_SEVERITY_MASK_RECORD_E,
	SERV19_DTC_BY_SEVERITY_MASK_RECORD_E,
	SERV19_SEVERITY_INFORMATION_OF_DTC_E,
	SERV19_SUPPORTED_DTC_E, // 0A
	SERV19_FIRST_TEST_FAILED_E,
	SERV19_FIRST_CONFIRMED_E,
	SERV19_MOST_RECENT_TEST_FAILED_E,
	SERV19_MOST_RECENT_CONFIRMED_E,
	SERV19_MIRROR_MEMORY_DTC_BY_STATUS_MASK_E,
	SERV19_MIRROR_MEMORY_EXTENDED_DATA_RECORD_BY_DTC_NUMBER_E,
	SERV19_NUMBER_OF_MIRROR_MEMORY_BY_DTC_E,
	SERV19_NUMBER_OF_EMISSION_RELATED_OBD_DTC_BY_STATUS_MASK_E,
	SERV19_EMISSION_RELATED_OBD_DTC_BY_STATUS_MASK_E,
	SERV19_DTC_FAULT_DETECTION_COUNTER_E,
	SERV19_DTC_WITH_PERMANENT_STATUS_E,
	SERV19_DTC_EXTENDED_DATA_RECORD_BY_RECORD_NUMBER_E,
	SERV19_USER_DEFINE_MEMORY_DTC_BY_STATUS_MASK_E,
	SERV19_USER_DEFINE_MEMORY_DTC_SNAPSHOT_RECORD_BY_DTC_NUMBER_E,
	SERV19_USER_DEFINE_MEMORY_DTC_EXTENDED_DATA_RECORD_BY_DTC_NUMBER_E,
	SERV19_WWH_OBD_DTC_BY_MASK_RECORD_E = 0x42,
	SERV19_WWH_OBD_DTC_WITH_PERMANENT_STATUS_E = 0x55,
} SubFunctionSer19_En_t;

typedef struct
{
	SubFunctionSer19_En_t SUB_FUNCTION_ID;
	uint16_t (*Subfun_Fptr_t)(uint8_t *);
	uint8_t DTC_SubFun_Valide_Length_u8;
} SubFunctionSer19_St_t;

#if (TRUE == UDS_SERVICE19_ENABLE)
extern const SubFunctionSer19_St_t Service19_SubFunctionsaSt[SERV19_NUMOF_SUB_FUNCTIONS];
#endif
#if (TRUE == UDS_SERVICE14_ENABLE)
extern const uint32_t GroupOfDTCIDs_au32[NUMBER_OF_GROUP_DTC_IDs];
#endif
#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE) || (TRUE == UDS_SERVICE2F_ENABLE))
/*************************related to servic 22/2E******************************/
extern const uint8_t * ASW_ID_pu8;
#endif
#if ((TRUE == UDS_SERVICE2E_ENABLE) || (TRUE == UDS_SERVICE22_ENABLE) || (TRUE == UDS_SERVICE2F_ENABLE))
/****************This Structure Array DID_Config_aSt[] is used by both 
 *0x22(RDBDID) and 0x2E(WDBDID) Services***************************************/
#endif

extern const char ASW_ID_au8[ASW_VER_DATA_SIZE];
extern PblParam_St_t PblParam_St;
// extern const uint8_t UNIQUE_FOTA_ID_u8[UNIQUE_FOTA_ID_SIZE];
// extern const char ECU_State_au8[ECU_STATE_SIZE];
// extern const uint8_t TML_ECU_SW_NUMBER_u8[TML_ECU_SW_NUMBER_SIZE];
// extern const uint8_t HMI_ASW_PART_NUMBER_u8[HMI_ASW_PART_NUMBER_SIZE];
/* -----------------------------------------------------------------------------
*  FUNCTION DECLERATION DESCRIPTION
*  -----------------------------------------------------------------------------
*   Function Name : UDS_GetCurrentSession
*   Description   : The function checks the security status
*   Parameters    : Null 
*   Return Value  : bool
*******************************************************************************/ 
typedef void (*UdsServInitCallback_Fptr_t)(void);
extern uint8_t iso14229_securitycheck(uint16_t Lvl_u16);
extern bool UdsDiagSessionCheck(uint8_t session_u8);
extern void UDS_SessionTimeout(void);
extern  void ReadPblParameter(void);
extern void ResetSoftwareJumpCnt(void);
extern FlashState_En_t UDS_GetBootloader_SM(void);
extern void UDS_UpdateBootloader_SM(FlashState_En_t Set_FlashState_En);
extern BSW_NVM_Data_St_t BSW_NVM_Data_St;
extern void ReadBSW_NVMParameter(void);
extern void UdsAppProc(void);
extern void UpdateNVMblock(uint8_t BlockID_u8);
extern void BSW_NVM_Write_Update(void);
extern void BSW_NVM_Read_Update(void);
extern void UDS_Security_Lock (void);
#endif
/*------------------------------ End of File ---------------------------------*/
