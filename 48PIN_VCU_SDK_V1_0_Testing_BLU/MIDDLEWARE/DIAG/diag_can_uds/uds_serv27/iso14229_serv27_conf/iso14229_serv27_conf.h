/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File      		: iso14229_serv27_conf.h
|    Project      	: MIL_PBL_CV
|    Description    : configuration description for UDS service - Security
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date             Name                        Company
| ----------     ---------------     -----------------------------------
|31/07/2024       Manikandan S         Sloki Software Technologies LLP
|-------------------------------------------------------------------------------
|******************************************************************************/
#ifndef ISO14229_SERV27_CONF_H    /* Guard against multiple inclusion */
#define ISO14229_SERV27_CONF_H

/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "uds_conf.h"
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define TOTAL_SECURITY_LVL  0x02U

#define SECURITY_LEVEL_1    0x01U
#define SECURITY_LEVEL_2    0x05U

#define SEED_LEN            4U
#define KEY_LEN             4U

#define CIPHER_LEN          4U

#define MAX_KEY_LEN         KEY_LEN
#define MAX_SEED_LEN        SEED_LEN

#define ONES_COMPLIMENT                 FALSE

#define RANDOM_NUM_GENERATION           TRUE
#define RAND_FUNCTION_GENERATION        FALSE
#define AES32_ALGORITHM                 TRUE
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef struct 
{
    uint32_t *DelayTimerTable_pu8;
    uint16_t SupportedSession_u16;
    uint16_t LvlEqu_u16;
    uint8_t SecurityLvl_u8;
    uint8_t SeedLen_u8;
    uint8_t KeyLen_u8;
    uint8_t DelayTimerEn_u8;
    uint8_t TotalDelayTimer_u8;
    uint8_t MaxAttempt_u8;
}UdsSecurityAccess_St_t;

typedef bool (*RandomNumGenerator_Fptr_t)(uint8_t* Buff_pu8,uint8_t Len_u8, uint8_t* Seed_pu8);
typedef bool (*KeyGenerator_Fptr_t)(uint8_t* KeyBuff_pu8,uint8_t *Seed_pu8,uint8_t KeyLen_u8,uint8_t SeedLen_u8,uint8_t Level_u8);

/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern const UdsSecurityAccess_St_t UdsSecurityAccess_aSt[TOTAL_SECURITY_LVL];
extern const RandomNumGenerator_Fptr_t RandomNumGenerator_Fptr;
extern const KeyGenerator_Fptr_t KeyGenerator_Fptr;
extern const UdsServInitCallback_Fptr_t UdsServ27InitCallback_Fptr;
extern uint32_t CipherText_u32;
extern uint32_t PlainText_u32;
/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/
extern void Uds27ServInitCallback(void);
extern void GenerateSeedCallback(uint8_t *databuff_pu8, uint8_t Len_u8, uint8_t* Seed_pu8);
extern void GenerateKeyCallback(uint8_t *databuff_pu8,uint8_t *Seed_pu8, uint8_t keyLen_u8,uint8_t SeedLen_u8, uint8_t SecLvl_u8);
#endif
/*---------------------- End of File -----------------------------------------*/

