
/*********************************************************************************
 *    FILENAME    : diag_adapt.h                                                 *          
 *    DESCRIPTION : Application adapter interface file for DIAG Stacks.          *
 *********************************************************************************
 * Revision history                                                              *               
 *                                                                               *
 * Ver Author       Date               Description                               *
 * 1   Sloki     1/10/2019		   Initial version                           *
 *********************************************************************************
*/  

#ifndef _DIAG_ADAPT_H_
#define _DIAG_ADAPT_H_

#include "diag_typedefs.h"

#define U2_DIAG_SIZE (U2)(922)	/*DID paratemetrs are total of 820 bytes*/
#define SOFTWARE_VERSION_INTERNAL "V2.25.0.17"


extern uint8_t COMMUNICATION_Status_au8[1 ];
extern uint16_t Dist_Drvn;


#endif
