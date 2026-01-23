/*
 * Copyright(c) 1997-2017 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */
/* 
   limits.h
*/

#ifndef	__LIMITS_H
#define	__LIMITS_H

#define CHAR_BIT 8

/* not support multibyte characters */
#define MB_LEN_MAX 1

#define SCHAR_MIN (-128)
#define SCHAR_MAX 127

#define UCHAR_MAX 255

#ifdef __CHAR_UNSIGNED__
#define CHAR_MIN 0
#define CHAR_MAX 255
#else
#define CHAR_MIN (-128)
#define CHAR_MAX 127
#endif

#define SHRT_MIN (-32768)
#define SHRT_MAX 32767

#define USHRT_MAX 65535

#define INT_MIN (-INT_MAX-1)
#define INT_MAX 2147483647

#define UINT_MAX 4294967295U

#define LONG_MIN (-LONG_MAX-1)
#define LONG_MAX 2147483647L

#define ULONG_MAX 4294967295UL

#if (__STDC_VERSION__ >= 199901L) || !defined(__STDC__)
#define LLONG_MIN (-LLONG_MAX-1)
#define LLONG_MAX 9223372036854775807LL

#define ULLONG_MAX 18446744073709551615ULL
#endif /* (__STDC_VERSION__ >= 199901L) || !defined(__STDC__) */

#endif /* __LIMITS_H */
