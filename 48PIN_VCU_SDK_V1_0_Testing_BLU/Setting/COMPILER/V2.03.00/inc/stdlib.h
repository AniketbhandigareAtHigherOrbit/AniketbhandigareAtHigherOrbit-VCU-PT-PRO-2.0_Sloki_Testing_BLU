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
   stdlib.h
*/

#ifndef	__STDLIB_H
#define	__STDLIB_H

#ifndef __STDDEF_H
#include <stddef.h>
#endif

typedef	struct {
	int	quot;
	int	rem;
	} div_t;
typedef	div_t	ldiv_t;

#define	RAND_MAX	0x7fff

#define MB_CUR_MAX	1

#if defined(__PIC)
#pragma section text
#endif

extern	double atof(const char *);
extern	float atoff(const char *);

extern	int atoi(const char *);
extern	long int atol(const char *);

extern	double strtod(const char *, char **);
extern	float strtodf(const char *, char **);

extern	long int strtol(const char *, char **, int);
extern	unsigned long int strtoul(const char *, char **, int);

extern	int rand(void);
extern	void srand(unsigned int);

extern	void *malloc(size_t);
extern	void free(void *);
extern	void *calloc(size_t, size_t);
extern	void *realloc(void *, size_t);

extern	void *bsearch(const void *, const void *, size_t, size_t,
                      int (*)(const void *, const void *));
extern	void qsort(void *, size_t, size_t,
                   int (*)(const void *, const void *));

extern	int abs(int);
extern	long int labs(long int);
extern	div_t div(int, int);
extern	ldiv_t ldiv(long int, long int);

extern	void abort(void);

#if (__STDC_VERSION__ >= 199901L) || !defined(__STDC__)
typedef struct {
	long long int	quot;
	long long int	rem;
	} lldiv_t;

extern	long long int atoll(const char *);
extern	long long int strtoll(const char *, char **, int);
extern	unsigned long long int strtoull(const char *, char **, int);
extern	long long int llabs(long long int);
extern	lldiv_t lldiv(long long int, long long int);
#endif /* (__STDC_VERSION__ >= 199901L) || !defined(__STDC__) */

#if defined(__PIC)
#pragma section default
#endif

#endif	/* __STDLIB_H */
