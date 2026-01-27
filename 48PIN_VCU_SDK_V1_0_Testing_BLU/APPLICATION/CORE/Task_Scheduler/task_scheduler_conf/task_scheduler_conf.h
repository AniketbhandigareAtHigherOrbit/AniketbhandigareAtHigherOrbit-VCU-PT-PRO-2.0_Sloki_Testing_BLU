/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : task_scheduler_conf.h
|    Project        : 
|    Description    : The file schedule the task.
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date              Name                        Company
| ----------     ---------------     -----------------------------------
| 
|-------------------------------------------------------------------------------
|******************************************************************************/

#ifndef TASK_SCHEDULER_CONF
#define TASK_SCHEDULER_CONF
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "app_typedef.h"
#include "task_scheduler.h"
/*******************************************************************************
 *  FUNCTION POINTER DECLARATION
 ******************************************************************************/
typedef void (*Task_Fptr_t)(void);
/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define TS_INTERVAL 5 /* 5 millisec*/
#define TS_PERIODICTY(x) (x / TS_INTERVAL)
// #define TOTAL_TASK  6

#define INIT_VALUE  0u

/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
#pragma pack(1)
typedef struct
{
    const Task_Fptr_t Task_Fptr;
    const uint16_t Periodicity_u16;
    uint16_t TaskTimerCounter_u16;    
} TaskConf_St_t;
#pragma unpack

typedef enum
{
    TASK_START_E = 0,
    TASK_ADC_SERVICE_E = TASK_START_E,
    TASK_GPIO_SERVICE_E,
    TASK_CAN_FUNCTIONALITY_E,
    TASK_VCUDATA_E,
    TASK_CONTROLLERDATA_E,
    //TASK_RPM_SERVICE_E,
    TASK_ONROAD_LOGIC,
    TASK_SENSOR_E,
    TASK_TIMEOUTCANRX_E,
    //TASK_BROADCAST_E,
    TOTAL_TASK
} Task_En_t;

/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/
extern TaskConf_St_t TaskConf_St[TOTAL_TASK];
extern const uint8_t Total_task_u8;

/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/

#endif /* TASK_SCHD_CONF */
/*---------------------- End of File -----------------------------------------*/