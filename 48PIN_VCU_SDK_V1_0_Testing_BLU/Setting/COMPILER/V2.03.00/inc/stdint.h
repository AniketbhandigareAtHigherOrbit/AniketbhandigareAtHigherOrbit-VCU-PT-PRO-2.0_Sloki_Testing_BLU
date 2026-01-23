/*
 * Copyright(c) 2017, 2019 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */

#ifndef	__STDINT_H
#define	__STDINT_H

#if (__STDC_VERSION__ >= 199901L)

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;

typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef int int_least32_t;
typedef unsigned int uint_least32_t;
typedef long long int_least64_t;
typedef unsigned long long uint_least64_t;

typedef int int_fast8_t;
typedef unsigned int uint_fast8_t;
typedef signed long int_fast16_t;
typedef unsigned int uint_fast16_t;
typedef signed long int_fast32_t;
typedef unsigned int uint_fast32_t;
typedef signed long long int_fast64_t;
typedef unsigned long long uint_fast64_t;

typedef int intptr_t;
typedef unsigned int uintptr_t;

typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;

#define INT8_MIN (-0x7f-1)
#define INT16_MIN (-0x7fff-1)
#define INT32_MIN (-0x7fffffff-1)
#define INT64_MIN (-0x7fffffffffffffffLL-1)

#define INT8_MAX (0x7f)
#define INT16_MAX (0x7fff)
#define INT32_MAX (0x7fffffff)
#define INT64_MAX (0x7fffffffffffffffLL)

#define UINT8_MAX (0xff)
#define UINT16_MAX (0xffff)
#define UINT32_MAX (0xffffffff)
#define UINT64_MAX (0xffffffffffffffffULL)

#define INT_LEAST8_MIN (-0x7f-1)
#define INT_LEAST16_MIN (-0x7fff-1)
#define INT_LEAST32_MIN (-0x7fffffff-1)
#define INT_LEAST64_MIN (-0x7fffffffffffffffLL-1)

#define INT_LEAST8_MAX (0x7f)
#define INT_LEAST16_MAX (0x7fff)
#define INT_LEAST32_MAX (0x7fffffff)
#define INT_LEAST64_MAX (0x7fffffffffffffffLL)

#define UINT_LEAST8_MAX (0xff)
#define UINT_LEAST16_MAX (0xffff)
#define UINT_LEAST32_MAX (0xffffffffU)
#define UINT_LEAST64_MAX (0xffffffffffffffffULL)

#define INT_FAST8_MIN (-0x7fffffff-1)
#define INT_FAST16_MIN (-0x7fffffff-1)
#define INT_FAST32_MIN (-0x7fffffff-1)
#define INT_FAST64_MIN (-0x7fffffffffffffffLL-1)

#define INT_FAST8_MAX (0x7fffffff)
#define INT_FAST16_MAX (0x7fffffff)
#define INT_FAST32_MAX (0x7fffffff)
#define INT_FAST64_MAX (0x7fffffffffffffffLL)

#define UINT_FAST8_MAX (0xffffffffU)
#define UINT_FAST16_MAX (0xffffffffU)
#define UINT_FAST32_MAX (0xffffffffU)
#define UINT_FAST64_MAX (0xffffffffffffffffULL)

#define INTPTR_MIN (-0x7fffffff-1)
#define INTPTR_MAX (0x7fffffff)
#define UINTPTR_MAX (0xffffffffU)

#define INTMAX_MIN (-0x7fffffffffffffffLL-1)
#define INTMAX_MAX (0x7fffffffffffffffLL)
#define UINTMAX_MAX (0xffffffffffffffffULL)

#define PTRDIFF_MIN (-0x7fffffff-1)
#define PTRDIFF_MAX (0x7fffffff)
#define SIZE_MAX (0xffffffffU)

#define INT8_C(_x)  (_x)
#define INT16_C(_x) (_x)
#define INT32_C(_x) (_x)
#define INT64_C(_x) (_x ## LL)

#define UINT8_C(_x)  (_x)
#define UINT16_C(_x) (_x)
#define UINT32_C(_x) (_x ## U)
#define UINT64_C(_x) (_x ## ULL)

#define INTMAX_C(_x)  (_x ## LL)
#define UINTMAX_C(_x) (_x ## ULL)

#endif /* (__STDC_VERSION__ >= 199901L) */

#endif	/* __STDINT_H */
