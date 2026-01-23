/*
 * Copyright(c) 1997-2019 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */
/* 
   setjmp.h
*/

#ifndef __SETJMP_H
#define __SETJMP_H

#ifndef __REL_SETJMP_REG
  #ifdef __reg32__
    #define __REL_SETJMP_REG 0xbff00000u
  #else
    #define __REL_SETJMP_REG 0xbe000000u
  #endif
#endif

#define setjmp(_buf) _REL_setjmp((_buf), __REL_SETJMP_REG)

typedef int jmp_buf[14];

#if defined(__PIC)
#pragma section text
#endif

extern int _REL_setjmp(jmp_buf, unsigned long);
extern void longjmp(jmp_buf, int);

#if defined(__PIC)
#pragma section default
#endif

#endif /* __SETJMP_H */
