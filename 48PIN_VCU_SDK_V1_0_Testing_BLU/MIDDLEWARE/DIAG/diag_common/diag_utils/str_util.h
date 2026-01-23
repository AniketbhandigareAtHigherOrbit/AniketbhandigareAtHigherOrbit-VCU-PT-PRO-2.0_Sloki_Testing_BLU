/******************************************************************************
 *    FILENAME    : str_util.h
 *    DESCRIPTION : Include file for string utility functions
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/ 

#ifndef STRUTIL_H
#define STRUTIL_H
#include "diag_typedefs.h"
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files
                                                   */

/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */




 uint16_t STR_Cat  (uint8_t *dest_pv, const void *src_pv, uint16_t srcLen_u16);
// Memcpy function
// #endif
void CopyData (void *dest_pv, uint32_t len_u32, const void *src_pv);
uint8_t CompareBuff(const uint8_t *Buff1_pu8,const uint8_t  *Buff2_pu8,const uint32_t Len_u32);
//  #if 1
 void ReversData (uint32_t len_u32, const void *src_pv);
 void rvereseArray(uint8_t arr[], uint8_t start, uint8_t end);
//Memset function
 void SetMem (uint8_t*, uint8_t, uint32_t);
//Memcmp function
 bool CmpData (const uint8_t*, uint32_t, const uint8_t*);

// Reverse a string
 void ReverseString (uint8_t * str_pu8, uint16_t len_u16);

 bool STR_toUINT (const void *src_pv, uint32_t* value_p32);
 uint32_t STR_len (const void *src_pv);

#endif 


/* *****************************************************************************
 End of File
 */
