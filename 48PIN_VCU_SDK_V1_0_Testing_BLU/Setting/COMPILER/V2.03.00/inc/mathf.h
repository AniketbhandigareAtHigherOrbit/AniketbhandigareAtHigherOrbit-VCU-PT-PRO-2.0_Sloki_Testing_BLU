/*
 * Copyright(c) 2012-2018 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */
/* 
   mathf.h
*/

#ifndef	__MATHF_H
#define	__MATHF_H

#define HUGE_VALF 	((float)__INFINITY__)

#if defined(__PIC)
#pragma section text
#endif

extern	float	acosf(float);
extern	float	asinf(float);
extern	float	atanf(float);
extern	float	atan2f(float, float);
extern	float	cosf(float);
extern	float	sinf(float);
extern	float	tanf(float);
extern	float	coshf(float);
extern	float	sinhf(float);
extern	float	tanhf(float);
extern	float	expf(float);
extern	float	frexpf(float, int *);
extern	float	ldexpf(float, int);
extern	float	logf(float);
extern	float	log10f(float);
extern	float	modff(float, float *);
extern	float	powf(float, float);
extern	float	sqrtf(float);
extern	float	ceilf(float);
extern	float	fabsf(float);
extern	float	floorf(float);
extern	float	roundf(float);
extern	long	lroundf(float);
#if (__STDC_VERSION__ >= 199901L) || !defined(__STDC__)
extern	long long	llroundf(float x);
#endif
extern	float	truncf(float);
extern	float	fmodf(float, float);
extern	float	copysignf(float, float);
extern	float	fmaxf(float, float);
extern	float	fminf(float, float);

#if defined(__PIC)
#pragma section default
#endif

#endif	/* __MATHF_H */
