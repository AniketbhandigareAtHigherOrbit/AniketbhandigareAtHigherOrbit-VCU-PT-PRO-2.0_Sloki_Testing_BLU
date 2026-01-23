/******************************************************************************
 *    FILENAME    : diag_sys_conf.h
 *    DESCRIPTION : This file contains version # of ISO 14229 stack software.
 *                  This is an internal version # to track the stack development.
 *                  This version # does not refer to ver # of UDS Standard. 
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/    

#ifndef	_DIAG_SYS_CONF_H_
#define _DIAG_SYS_CONF_H_

/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/
#include "diag_typedefs.h"
#include "app_typedef.h"
/*******************************************************************************
 *  MACRO DEFINITION
 ******************************************************************************/

#define	DIAG_CONF_FM_SUPPORTED			(TRUE)//TODO Configurable Parameter
#define	DIAG_CONF_CANTP_SUPPORTED		(TRUE)//TODO Configurable Parameter

#define	DIAG_CONF_UDS_SUPPORTED			(TRUE)//TODO Configurable Parameter
#define	DIAG_CONF_OBD2_SUPPORTED		(FALSE)//TODO Configurable Parameter
#define	DIAG_CONF_J1939_SUPPORTED		(FALSE)//TODO Configurable Parameter

#define DIAG_BOOT_LOADER_SUPPORTED 	    (FALSE)//TODO Configurable Parameter

#define	DIAG_CONF_J1587_SUPPORTED		(FALSE)
#define	DIAG_CONF_DOIP_SUPPORTED		(FALSE)


#define DIAG_CONF_INTERRUPTS         	(FALSE)//TODO Configurable Parameter
#define DIAG_CONF_CAN_IF         		(TRUE)//TODO Configurable Parameter
#define DIAG_CONF_EEPROM         		(FALSE)//TODO Configurable Parameter

#define DIAG_TEST_DEMO_CODE    			(FALSE)//TODO Configurable Parameter
#define DIAG_TEST_FM_EEPROM_DEMO    	(FALSE)//TODO Configurable Parameter
#define DIAG_TEST_FM_DEMO    			(FALSE)//TODO Configurable Parameter

#define DIAG_TEST_J1939_DEMO    	    (TRUE)//TODO Configurable Parameter



#define DIAG_CONF_CORE_LITTLE_ENDIAN 	(TRUE)//TODO Configurable Parameter

#if(FALSE ==  DIAG_CONF_CORE_LITTLE_ENDIAN)
	#define DIAG_CONF_CORE_BIG_ENDIAN   (TRUE)
#endif


#endif
