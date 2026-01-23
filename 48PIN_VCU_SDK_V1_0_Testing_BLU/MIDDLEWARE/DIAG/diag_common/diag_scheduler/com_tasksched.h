/******************************************************************************
 *    FILENAME    : com_ts.h
 *    DESCRIPTION : File contains the common declarations of the function
 ******************************************************************************
 * Revision history
 *  
 * Ver   Author       Date               Description
 * 1     Sushil      27/10/2018		     Initial version
 ******************************************************************************
*/ 
#ifndef COM_TASK_SCHEDULER_H
#define COM_TASK_SCHEDULER_H
/* Section: Included Files                                               */
#include "diag_typedefs.h"
#include "app_typedef.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */


extern void Diag_TS_Proc_5ms (void);
extern void Diag_TS_Init(void);
extern void Diag_TS_FM_Init(void);
extern void Diag_TS_FM_Proc_5ms (void);


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */



/* *****************************************************************************
 End of File
 */
#endif


