/*
 * Copyright(c) 2012-2017 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */
/* 
   _h_c_lib.h
*/

#ifndef __H_C_LIB_H
#define __H_C_LIB_H

#if defined(__PIC)
#pragma section text
#endif

extern void hdwinit(void);
extern void _INITSCT_RH(void *, void *, void *, void *);

#if defined(__PIC)
#pragma section default
#endif

#endif /* __H_C_LIB_H */
