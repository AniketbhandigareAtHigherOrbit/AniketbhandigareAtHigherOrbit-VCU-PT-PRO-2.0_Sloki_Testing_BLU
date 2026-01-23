/******************************************************************************
 *    FILENAME    : diag_appl_test.c
 *    DESCRIPTION : Application test interface file for DIAG Stacks.
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki       10/01/2019		   Initial version
 ******************************************************************************
*/ 

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef _DIAG_APPL_TEST_H_
#define _DIAG_APPL_TEST_H_

#include "can_if.h"
#include "diag_sys_conf.h"
#if(TRUE == DIAG_CONF_J1939_SUPPORTED)
//	#include "j1939_73_dmx.h"
#endif
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

#if(TRUE == DIAG_TEST_DEMO_CODE)

#define TEST_FAULT_DID_1 0xA100
#define TEST_FAULT_DID_2 0xA101
#define TEST_FAULT_DID_3 0xA102
#define TEST_FAULT_DID_4 0xA103
#define TEST_FAULT_DID_5 0xA104
#define TEST_FAULT_DID_6 0xA105
#define TEST_FAULT_DID_7 0xA106
#define TEST_FAULT_DID_8 0xA107
#define TEST_FAULT_DID_9 0xA108
#define TEST_FAULT_DID_10 0xA109

extern uint8_t test_fault_input1_au8[1];
extern uint8_t test_fault_input2_au8[1]; 
extern uint8_t test_fault_input3_au8[1]; 
extern uint8_t test_fault_input4_au8[1]; 
extern uint8_t test_fault_input5_au8[1]; 
extern uint8_t test_fault_input6_au8[1]; 
extern uint8_t test_fault_input7_au8[1]; 
extern uint8_t test_fault_input8_au8[1]; 
extern uint8_t test_fault_input9_au8[1]; 
extern uint8_t test_fault_input10_au8[1]; 

extern uint8_t Rv_test_fault_input1_au8[1];
extern uint8_t Rv_test_fault_input2_au8[1]; 
extern uint8_t Rv_test_fault_input3_au8[1]; 
extern uint8_t Rv_test_fault_input4_au8[1]; 
extern uint8_t Rv_test_fault_input5_au8[1]; 
extern uint8_t Rv_test_fault_input6_au8[1]; 
extern uint8_t Rv_test_fault_input7_au8[1]; 
extern uint8_t Rv_test_fault_input8_au8[1]; 
extern uint8_t Rv_test_fault_input9_au8[1]; 
extern uint8_t Rv_test_fault_input10_au8[1]; 




typedef struct {
	uint16_t        FM_DID_u8;
	uint8_t*         FM_test_input_pu8;
}FM_Test_St_t;

extern FM_Test_St_t FM_Test_St[10];
#endif

#if(TRUE == DIAG_TEST_FM_EEPROM_DEMO)
	extern CanSchedMsg_St_t CanTest_St [1];
#endif


#if (TRUE == DIAG_TEST_J1939_DEMO)

	#define FM_DUMMY_FAULTPATHS			10

	 typedef struct
	 {
		 uint32_t SPN_u19:19;
		 uint32_t FMI_u5:5;
		 uint32_t CM_u1:1;
		 uint32_t OC_u7:7;
	 }J1939_DTCSample_Format_t;

	 typedef union
	 {
		 J1939_DTCSample_Format_t   DTC_St;
	 	 uint32_t            DTC_u32;
		 uint8_t             DTC_au8[4];
	 }J1939_DTC_Sample_Uni_t;

     extern const J1939_DTC_Sample_Uni_t J1939_DTC_Sample_Conf_aUni[10];

     extern void FM_GetDemo_DTCs(uint32_t * prevActiveFaults_aUni, uint8_t NumOfPrevActiveFaults_u8);

#endif

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */
#if(TRUE == DIAG_TEST_DEMO_CODE)
	extern void diag_appl_test_fm_proc_50ms(void);
#endif
#if(TRUE == DIAG_TEST_FM_EEPROM_DEMO)
	extern void diag_appl_test_fm_write(uint32_t Addr, uint32_t data);
	extern uint32_t diag_appl_test_fm_read(uint32_t Addr);
#endif
#if(TRUE == DIAG_TEST_FM_DEMO && TRUE == DIAG_CONF_FM_SUPPORTED)
	extern void diag_fm_tx_fault1 (void);
	extern void diag_fm_tx_fault2 (void);
	extern void diag_appl_test_fm_drv_Cycle(uint16_t CIL_SigName_En, CAN_MessageFrame_St_t* Can_Applidata_St);
#endif
//extern void diag_appl_test_fm_write(uint32_t Addr, uint32_t data);
extern void EEpromTest(void);



#endif


