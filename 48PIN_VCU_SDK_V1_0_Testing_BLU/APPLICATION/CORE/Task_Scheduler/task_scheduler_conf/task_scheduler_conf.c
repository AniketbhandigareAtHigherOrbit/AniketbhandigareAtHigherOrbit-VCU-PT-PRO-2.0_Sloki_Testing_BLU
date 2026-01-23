/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : task_scheduler_conf.c
|    Project        :  
|    Description    : The file implements .
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

/*******************************************************************************
 *  HEADER FILE INCLUDES
 ******************************************************************************/
#include "task_scheduler_conf.h"
#include "com_tasksched.h"
#include "data_acquire.h"
#include "databank.h"
#include "nvm_data.h"
#include "ext_eeprom.h"
//#include "app_init.h"
#include "data_acquire.h"
#include "fid.h"
#include "AppTest.h"
#include "adc_service.h"
#include "gpio_service.h"
#include "rpm_service.h"
#include "on_road_logic.h"
#include "vcu_sensors.h"
#include "Can_Broadcast.h"
/*******************************************************************************
 *  MACRO DEFINITION
 ******************************************************************************/

/*******************************************************************************
 *  GLOBAL VARIABLES DEFNITION
 ******************************************************************************/
extern void ADC_Service_Run(void);
extern void GPIO_Service_Run(void);
extern void CAN_functionality(void);
extern void RPM_Service_Run(void);
extern void OnRoad_Mode_Step(void);
extern void Direction_Logic_Run(void);
extern void CAN_Tx_VCUData(void);
extern void Controller_Data_Tx(void);
extern void VCU_Sensors_10ms(void); 
extern void Battery_Timeout_Task_100ms(void);
extern void can_tx_Fucntion(void); 
/*******************************************************************************
 *  STRUCTURE AND ENUM DEFNITION
 ******************************************************************************/
const uint8_t Total_task_u8=TOTAL_TASK;
TaskConf_St_t TaskConf_St[TOTAL_TASK] =
{	
   
    //{Test_Adc               ,TS_PERIODICTY(50),  INIT_VALUE},
    // {Test_GpioInput         ,TS_PERIODICTY(50),  INIT_VALUE},
    // {Test_GpioOutput        ,TS_PERIODICTY(50),  INIT_VALUE},
    // {CAN_functionality        ,TS_PERIODICTY(50),  INIT_VALUE},
    //  {fun1        ,TS_PERIODICTY(50),  INIT_VALUE},
    //  {fun2        ,TS_PERIODICTY(50),  INIT_VALUE},
    //  {fun3       ,TS_PERIODICTY(50),  INIT_VALUE},
    //  {fun4       ,TS_PERIODICTY(50),  INIT_VALUE},
    { ADC_Service_Run,        TS_PERIODICTY(10),  INIT_VALUE },
    { GPIO_Service_Run,       TS_PERIODICTY(10),  INIT_VALUE },
    { VCU_Sensors_10ms,       TS_PERIODICTY(10),  INIT_VALUE },
    { Battery_Timeout_Task_100ms, TS_PERIODICTY(100), INIT_VALUE },
    { CAN_Tx_VCUData,         TS_PERIODICTY(20),  INIT_VALUE },  /* Vehicle + Battery */
    { Controller_Data_Tx,     TS_PERIODICTY(20),  INIT_VALUE },  /* Controller mirror */
    { OnRoad_Mode_Step,       TS_PERIODICTY(50),  INIT_VALUE },
    { CAN_functionality,  TS_PERIODICTY(50),  INIT_VALUE },
    { can_tx_Fucntion,  TS_PERIODICTY(100),  INIT_VALUE },

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