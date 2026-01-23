/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : nvm_conf.h
|    Project        : TML EV
|    Description    : The file contains the NVM stack configuration .
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date             Name                      Company
| --------     ---------------------     ---------------------------------------
| 17/07/2024     Jeevan Jestin N           Sloki Software Technologies LLP.
|-------------------------------------------------------------------------------
|******************************************************************************/
#ifndef NVM_CONF_H
#define NVM_CONF_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "diag_typedefs.h"
#include"nvm_parameter.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define NVM_BLOCK_HEADER_SIZE       (4u)
#define NVM_CRC_SIZE                (2u)

#define BLOCK_START_OFFSET          NVM_BLOCK_HEADER_SIZE
#define NVM_CRC_POS_1                   (2u)
#define NVM_CRC_POS_2                   (3u)



/******************************** PBL Parameter  *********************************/
#define PBL_PARAM_BLK_START_ADDR                      0u
#define TOTAL_PBL_PARAM_PARAMETER                     9u
/* PBL Parameter block size */
#define   DIAG_SECURITY_STATE_SIZE                    1u
#define   DIAG_SESSION_STATE_SIZE                     1u
#define   REPROGRAM_REQ_STATE_SIZE                    1u
#define   ECU_RESET_SIZE                              1u
#define   SBL_STATE_SIZE                              1u
#define   NEW_SBL_CRC_SIZE                            4u
#define   NEW_SBL_SIZE_SIZE                           4u 
#define   SBL_UPDATE_FLAG_SIZE                        1u
#define   RANNDUM_NUMBER_SIZE                         4u
#define PBL_PARAMETER_BLOCK_RESERVE_SIZE              106u

/* PBL Parameter offset */

#define   DIAG_SECURITY_STATE_OFFSET                 (BLOCK_START_OFFSET) 
#define   DIAG_SESSION_STATE_OFFSET                  (DIAG_SECURITY_STATE_OFFSET        +  DIAG_SECURITY_STATE_SIZE)
#define   REPROGRAM_REQ_STATE_OFFSET                 (DIAG_SESSION_STATE_OFFSET         +  DIAG_SESSION_STATE_SIZE)
#define   ECU_RESET_OFFSET                           (REPROGRAM_REQ_STATE_OFFSET        +  REPROGRAM_REQ_STATE_SIZE)
#define   SBL_STATE_OFFSET                           (ECU_RESET_OFFSET                  +  ECU_RESET_SIZE)
#define   NEW_SBL_CRC_OFFSET                         (SBL_STATE_OFFSET                  +  SBL_STATE_SIZE)
#define   NEW_SBL_SIZE_OFFSET                        (NEW_SBL_CRC_OFFSET                +  NEW_SBL_CRC_SIZE)
#define   SBL_UPDATE_FLAG_OFFSET                     (NEW_SBL_SIZE_OFFSET               +  NEW_SBL_SIZE_SIZE)
#define   RANNDUM_NUMBER_OFFSET                      (SBL_UPDATE_FLAG_OFFSET            +  SBL_UPDATE_FLAG_SIZE)


#define PBL_PARAM_NVM_BLOCK_SIZE                     (NVM_BLOCK_HEADER_SIZE             +\
                                                        DIAG_SECURITY_STATE_SIZE        +\
                                                        DIAG_SESSION_STATE_SIZE         +\
                                                        REPROGRAM_REQ_STATE_SIZE        +\
                                                        ECU_RESET_SIZE                  +\
                                                        SBL_STATE_SIZE                  +\
                                                        NEW_SBL_SIZE_SIZE               +\
                                                        NEW_SBL_CRC_SIZE                +\
                                                        SBL_UPDATE_FLAG_SIZE            +\
                                                        RANNDUM_NUMBER_SIZE				+\
														PBL_PARAMETER_BLOCK_RESERVE_SIZE)

/******************************** Bootloader DID Configuration  *********************************/
#define BOOTLOADER_DID_BLK_START_ADDR                       128u
#define TOTAL_BOOTLOADER_DID_BLK_PARAMETER                  5u
/* Bootloader DIDs block size */
#define   VIN_NUMBER_SIZE                                   17u
#define   REPAIR_SHOP_CODE_SIZE                             9u
#define   PROGRAMMING_DATE_SIZE                             10u
#define   REPROGRAMMING_SEQ_SIZE                            1u
#define   ACTIVE_DIAG_SESION_SIZE                           1u
#define BOOTLOADER_DID_BLOCK_RESERVE_SIZE                   22u

/* Bootloader DIDs block parameter offset */

#define   VIN_NUMBER_OFFSET                          (BLOCK_START_OFFSET) 
#define   REPAIR_SHOP_CODE_OFFSET                    (VIN_NUMBER_OFFSET        +  VIN_NUMBER_SIZE)
#define   PROGRAMMING_DATE_OFFSET                    (REPAIR_SHOP_CODE_OFFSET  +  REPAIR_SHOP_CODE_SIZE)
#define   REPROGRAMMING_SEQ_OFFSET                   (PROGRAMMING_DATE_OFFSET  +  PROGRAMMING_DATE_SIZE)
#define   ACTIVE_DIAG_SESION_OFFSET                  (REPROGRAMMING_SEQ_OFFSET +  REPROGRAMMING_SEQ_SIZE)


#define BOOTLOADER_PARAM_NVM_BLOCK_SIZE                 (NVM_BLOCK_HEADER_SIZE          +\
                                                        VIN_NUMBER_SIZE                 +\
                                                        REPAIR_SHOP_CODE_SIZE           +\
                                                        PROGRAMMING_DATE_SIZE           +\
                                                        REPROGRAMMING_SEQ_SIZE          +\
                                                        ACTIVE_DIAG_SESION_SIZE         +\
														BOOTLOADER_DID_BLOCK_RESERVE_SIZE)

/******************************** FM Configuration *********************************/
#define FM_CONFIG_BLK_START_ADDR                     192u
#define TOTAL_FM_CONFIG_BLK_PARAMETER                3u
/* Manufacturing data block size */
#define FM_COMMON_DATA_SIZE                         16u  
#define FM_RDYRESULTS_SIZE                          8u
#define FM_TFSLC_SIZE                               17u  //41u
#define FM_CONFIG_BLK_RESERVE_SIZE                  19u//91u     

#define FM_COMMON_DATA_OFFSET          (BLOCK_START_OFFSET)
#define FM_RDYRESULTS_OFFSET           (FM_COMMON_DATA_OFFSET       + FM_COMMON_DATA_SIZE) 
#define FM_TFSLC_OFFSET               (FM_RDYRESULTS_OFFSET         + FM_RDYRESULTS_SIZE)
 

#define FM_CONFIG_NVM_BLOCK_SIZE                    (NVM_BLOCK_HEADER_SIZE+FM_COMMON_DATA_SIZE+\
                                                   FM_RDYRESULTS_SIZE                +\
                                                   FM_TFSLC_SIZE            +\
                                                   FM_CONFIG_BLK_RESERVE_SIZE  )

/******************************** FM data block  *********************************/
#define FM_ENTRY_BLK_START_ADDR                      256u
#define TOTAL_FM_ENTRY_BLK_PARAMETER                 10U


#define FEE_FM_L2_ENTRY1_SIZE                         69u
#define FEE_FM_L2_ENTRY2_SIZE                         69u  
#define FEE_FM_L2_ENTRY3_SIZE                         69u  
#define FEE_FM_L2_ENTRY4_SIZE                         69u  
#define FEE_FM_L2_ENTRY5_SIZE                         69u  
#define FEE_FM_L2_ENTRY6_SIZE                         69u  
#define FEE_FM_L2_ENTRY7_SIZE                         69u  
#define FEE_FM_L2_ENTRY8_SIZE                         69u  
#define FEE_FM_L2_ENTRY9_SIZE                         69u
#define FEE_FM_L2_ENTRY10_SIZE                        69u  
#define FM_ENTRY_BLK_RESERVE_SIZE                     10u      

#define FEE_FM_L2_ENTRY1_OFFSET                     (BLOCK_START_OFFSET)
#define FEE_FM_L2_ENTRY2_OFFSET                     (FEE_FM_L2_ENTRY1_OFFSET       + FEE_FM_L2_ENTRY1_SIZE) 
#define FEE_FM_L2_ENTRY3_OFFSET                     (FEE_FM_L2_ENTRY2_OFFSET       + FEE_FM_L2_ENTRY2_SIZE) 
#define FEE_FM_L2_ENTRY4_OFFSET                     (FEE_FM_L2_ENTRY3_OFFSET       + FEE_FM_L2_ENTRY3_SIZE) 
#define FEE_FM_L2_ENTRY5_OFFSET                     (FEE_FM_L2_ENTRY4_OFFSET       + FEE_FM_L2_ENTRY4_SIZE) 
#define FEE_FM_L2_ENTRY6_OFFSET                     (FEE_FM_L2_ENTRY5_OFFSET       + FEE_FM_L2_ENTRY5_SIZE) 
#define FEE_FM_L2_ENTRY7_OFFSET                     (FEE_FM_L2_ENTRY6_OFFSET       + FEE_FM_L2_ENTRY6_SIZE) 
#define FEE_FM_L2_ENTRY8_OFFSET                     (FEE_FM_L2_ENTRY7_OFFSET       + FEE_FM_L2_ENTRY7_SIZE) 
#define FEE_FM_L2_ENTRY9_OFFSET                     (FEE_FM_L2_ENTRY8_OFFSET       + FEE_FM_L2_ENTRY8_SIZE)
#define FEE_FM_L2_ENTRY10_OFFSET                    (FEE_FM_L2_ENTRY9_OFFSET       + FEE_FM_L2_ENTRY9_SIZE) 
 

#define FM_ENTRY_BLK_SIZE                    (NVM_BLOCK_HEADER_SIZE+FEE_FM_L2_ENTRY1_SIZE+\
                                                   FEE_FM_L2_ENTRY2_SIZE                +\
                                                   FEE_FM_L2_ENTRY3_SIZE            +\
                                                   FEE_FM_L2_ENTRY4_SIZE            +\
                                                   FEE_FM_L2_ENTRY5_SIZE            +\
                                                   FEE_FM_L2_ENTRY6_SIZE            +\
                                                   FEE_FM_L2_ENTRY7_SIZE            +\
                                                   FEE_FM_L2_ENTRY8_SIZE            +\
                                                   FEE_FM_L2_ENTRY9_SIZE            +\
                                                   FEE_FM_L2_ENTRY10_SIZE            +\
                                                   FM_ENTRY_BLK_RESERVE_SIZE  )

/******************************** Application SW Version *********************************/  
#define ASW_VER_CONFIG_BLK_START_ADDR                960U
#define ASW_VER_BLK_PAREMETER                        1u
/* Manufacturing data block size */
#define ASW_VER_DATA_SIZE                            (15u)

#define ASW_VER_CONFIG_BLOCK_RESERVE_SIZE            (45u)

#define ASW_VER_OFFSET                      (BLOCK_START_OFFSET)
         

#define ASW_VER_NVM_BLK_SIZE                (NVM_BLOCK_HEADER_SIZE + \
                                             ASW_VER_DATA_SIZE +\
                                             ASW_VER_CONFIG_BLOCK_RESERVE_SIZE)

/******************************** Application Configuration *********************************/  
#define FEATURE_CONFIG_BLK_START_ADDR                1024U
#define TOTAL_FEATURE_BLK_PAREMETER                  1u
/* Manufacturing data block size */
#define CONFIGURATION_DATA_SIZE                      (1u)

#define FEATURE_CONFIG_BLOCK_RESERVE_SIZE            (59u)

#define CONFIGURATION_DATA_OFFSET                (BLOCK_START_OFFSET)
         

#define FEATURE_CONFIG_NVM_BLK_SIZE         (NVM_BLOCK_HEADER_SIZE + \
                                             CONFIGURATION_DATA_SIZE +\
                                             FEATURE_CONFIG_BLOCK_RESERVE_SIZE)

/*******************************************************************************
*  STRUCTURES, ENUMS and TYPEDEFS
*******************************************************************************/

/*LDRA_EXCLUDE_START 630 S 
    <justification start> Explicitly assigned to the start value. 
    The duplication does not cause functional issues because it is not used as an independent value in logic or algorithms. 
    It only serves as a base constant for initialization purposes.
   <justification end>
*/

typedef enum
{
    NVM_BLK_START_E,
    NVM_BLK_ID_0_E = NVM_BLK_START_E,
    NVM_BLK_ID_1_E,
    NVM_BLK_ID_2_E,
    NVM_BLK_ID_3_E,
    NVM_BLK_ID_4_E,
    NVM_BLK_ID_5_E,   
    TOTAL_NVM_BLK_E,
}NvmBlockId_En_t;

typedef enum
{
    NVM_FM_ENTRY_1_E,
    NVM_FM_ENTRY_2_E,
    NVM_FM_ENTRY_3_E,
    NVM_FM_ENTRY_4_E,
    NVM_FM_ENTRY_5_E,
    NVM_FM_ENTRY_6_E,
    NVM_FM_ENTRY_7_E,
    NVM_FM_ENTRY_8_E,
    NVM_FM_ENTRY_9_E,
    NVM_FM_ENTRY_10_E,
    TOTAL_NVM_FM_ENTRY_E
}NvmFmEntryBlk_En_t;

/*LDRA_EXCLUDE_END 630 S */
#pragma pack(1)
typedef const struct
{
    Nvm_Parameter_En_t Parameter_En;
    uint32_t Offset_u32;
    uint16_t Size_u16;
}Blk_Descriptor_St_t;

#pragma pack(1)
typedef struct 
{
    NvmBlockId_En_t   Id_En;
    uint32_t   Start_Addr_u32;
    uint32_t   Length_u32;
    uint8_t   *RAMCopy_pu8;
    const uint8_t   *RomCopy_pu8;
    Blk_Descriptor_St_t*      Descriptor_pSt;
    uint16_t  TotalParameter_u16;
    bool   Nvm_Storage_u8;
}NvmBlk_St_t;

/*******************************************************************************
*  EXTERN GLOBAL VARIABLES
*******************************************************************************/
extern const NvmBlk_St_t NvmBlk_aSt[TOTAL_NVM_BLK_E];
/*******************************************************************************
*  EXTERN FUNCTION
*******************************************************************************/

#endif
/*---------------------- End of File -----------------------------------------*/


