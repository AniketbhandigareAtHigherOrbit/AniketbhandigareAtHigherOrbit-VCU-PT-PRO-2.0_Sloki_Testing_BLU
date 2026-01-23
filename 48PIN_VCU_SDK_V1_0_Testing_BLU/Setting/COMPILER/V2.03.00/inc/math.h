/*
 * Copyright(c) 1997-2018 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */
/* 
   math.h
*/

#ifndef	__MATH_H
#define	__MATH_H

#define HUGE_VAL 	((double)__INFINITY__)

#if defined(__PIC)
#pragma section text
#endif

#if (__STDC_VERSION__ >= 199901L)

typedef double double_t;
typedef float float_t;

#define HUGE_VALL 	((long double)__INFINITY__)
#define INFINITY    (__INFINITY__)
#define NAN         (__NAN__)

#define FP_INFINITE 1
#define FP_NAN 2
#define FP_NORMAL (-1)
#define FP_SUBNORMAL (-2)
#define FP_ZERO 0

#define MATH_ERRNO 1
#define MATH_ERREXCEPT 2

#define math_errhandling MATH_ERRNO

#endif /* (__STDC_VERSION__ >= 199901L) */

extern	double	acos(double);
extern	double	asin(double);
extern	double	atan(double);
extern	double	atan2(double, double);
extern	double	cos(double);
extern	double	sin(double);
extern	double	tan(double);
extern	double	cosh(double);
extern	double	sinh(double);
extern	double	tanh(double);
extern	double	exp(double);
extern	double	frexp(double, int *);
extern	double	ldexp(double, int);
extern	double	log(double);
extern	double	log10(double);
extern	double	modf(double, double *);
extern	double	pow(double, double);
extern	double	sqrt(double);
extern	double	ceil(double);
extern	double	fabs(double);
extern	double	floor(double);
extern	double	round(double);
extern	long	lround(double);
#if (__STDC_VERSION__ >= 199901L) || !defined(__STDC__)
extern	long long	llround(double);
#endif
extern	double	trunc(double);
extern	double	fmod(double, double);
extern	double	copysign(double, double);
extern	double	fmax(double, double);
extern	double	fmin(double, double);

extern	long double	acosl(long double);
extern	long double	asinl(long double);
extern	long double	atanl(long double);
extern	long double	atan2l(long double, long double);
extern	long double	cosl(long double);
extern	long double	sinl(long double);
extern	long double	tanl(long double);
extern	long double	coshl(long double);
extern	long double	sinhl(long double);
extern	long double	tanhl(long double);
extern	long double	expl(long double);
extern	long double	frexpl(long double, int *);
extern	long double	ldexpl(long double, int);
extern	long double	logl(long double);
extern	long double	log10l(long double);
extern	long double	modfl(long double, long double *);
extern	long double	fabsl(long double);
extern	long double	powl(long double, long double);
extern	long double	sqrtl(long double);
extern	long double	ceill(long double);
extern	long double	floorl(long double);
extern	long double	roundl(long double);
extern	long	lroundl(long double);
#if (__STDC_VERSION__ >= 199901L) || !defined(__STDC__)
extern	long long	llroundl(long double x);
#endif
extern	long double	truncl(long double);
extern	long double	fmodl(long double, long double);
extern	long double	copysignl(long double, long double);
extern	long double	fmaxl(long double, long double);
extern	long double	fminl(long double, long double);

#if defined(__PIC)
#pragma section default
#endif

#include <mathf.h>

#endif	/* __MATH_H */
