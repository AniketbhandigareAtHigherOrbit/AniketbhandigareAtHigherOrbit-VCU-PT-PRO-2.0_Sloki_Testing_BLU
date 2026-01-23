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
   stdarg.h
*/

#ifndef	__STDARG_H
#define	__STDARG_H

typedef	char	*va_list;

#define	__WORDSIZEOF(_n)		((sizeof(_n) + 3) & (~3))

#if defined(__PIC)
#pragma section text
#endif

void __builtin_va_start(va_list);

#if defined(__PIC)
#pragma section default
#endif

#define	va_start(_ap,_parmN)	__builtin_va_start((_ap))
#define	va_arg(_ap,_type)		(*(_type *)(((_ap)+=__WORDSIZEOF(_type))-__WORDSIZEOF(_type)))
#if (__STDC_VERSION__ >= 199901L)
#define	va_copy(_dest,_src)	((_dest)=(_src))
#endif /* (__STDC_VERSION__ >= 199901L) */
#define	va_end(_ap)		((void)0)

#endif	/* __STDARG_H */
