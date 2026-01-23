/******************************************************************************
 *    FILENAME    : can_sched.h
 *    DESCRIPTION : This file contains buffer for CIL layer data extraction as  and other structs defined in i15676.h
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/  


#ifndef CAN_SCHED_H
#define CAN_SCHED_H

#include "diag_typedefs.h"
#include "diag_sys_conf.h"
#if(TRUE == DIAG_CONF_CANTP_SUPPORTED)
	#include "i15765.h"
#endif
#include "can_sched_conf.h"
#include "can_if.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef enum
{
	TX_ON_RX_ON_E,
	TX_ON_RX_OFF_E,
	TX_OFF_RX_ON_E,
	TX_OFF_RX_OFF_E,
}CanSchedulerState_En_t;
 
 extern CanSchedulerState_En_t CanSchedulerState_En;
/***************************************************************************** */
extern void CanSched_5ms (void);
extern void CanSched_Init (void);

void CanRxScheduler(void);
void CanTxScheduler(void);

extern void SetCanScheduler(CanSchedulerState_En_t CanSchedulerState);

#endif

/* *****************************************************************************
 End of File
 */
 
 
