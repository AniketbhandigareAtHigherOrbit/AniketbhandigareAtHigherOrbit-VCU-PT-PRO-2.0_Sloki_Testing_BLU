#ifndef APPTEST
#define APPTEST

#include"pal_can_conf.h"
// #include"rscan_driver.h"
// #include"rscan_typedefs.h"
// #include"rscan_reg.h"
extern void Vehicle_Task_10ms(void);
extern void Battery_Timeout_Task_100ms(void);
extern void CAN_Tx_VCUData(void);
extern void Controller_Data_Tx(void);
extern void CAN_functionality();
extern void CAN_functionality_BT();

#endif /* APPTEST */
