
/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File      		: iso14229_serv27.h
|    Project      	: MIL_PBL_CV
|    Description    : Service description for UDS service  - Security
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

#ifndef ISO14229_SERV27_H    /* Guard against multiple inclusion */
#define ISO14229_SERV27_H


/****************************************************************************
 * Includes                                                    
 ****************************************************************************/
#include "uds_conf.h"

/*******************************************************************************
 *  Define & Macros
 ******************************************************************************/
#define SECURITY_ACCESS_MIN_LEN 2
#define SECURITY_ACCESS_SEED_REQ_LEN 2
/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef enum
{
    SA_SEED_REQ_E,               
    SA_RECEIVE_KEY_E,
    SA_DELAYTIMER_EN_E,
    SA_ACCESS_OK_E                
}SA_STATE_MACHINE_En_t;

typedef enum
{
    SF_TYPE_ODD_E,
    SF_TYPE_EVEN_E,
}SubFuncType_En_t;

typedef union
{
    uint32_t random_number;
    uint8_t byte_buff[4];
}SPLIT_RAND_Un_t;


typedef union
{
    uint32_t random_number_au32[4];
    uint16_t random_number_au16[8];    
    uint8_t random_number_au8[16];
}AES_128_Un_t;

/*******************************************************************************
 *  GLOBAL VARIABLES
 ******************************************************************************/

extern UDS_Serv_resptype_En_t iso14229_serv27(UDS_Serv_St_t*  UDS_Serv_pSt);
extern uint16_t iso14229_serv27_securitycheck(void);
extern void iso14229_serv27_timeout(void);
extern void UDS_Service27Init(void);
extern void DelayTimerCheck(void);
#endif /* _ISO14229_SERV27_H */

/*---------------------- End of File -----------------------------------------*/
