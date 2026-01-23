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
   float.h
*/

#ifndef __FLOAT_H
#define __FLOAT_H

/* rounding mode for floating-point addition */
#if defined(_ROZ)
#define FLT_ROUNDS	0		/* rounds toward zero */
#else
#define FLT_ROUNDS	1		/* rounds to nearest */
#endif

#if (__STDC_VERSION__ >= 199901L)
/* format whose range and precision may be greater than required by the type. */
#define FLT_EVAL_METHOD 0
#endif

/* radix of exponent representation, b */
#define FLT_RADIX	2		/* radix of exponent */

/* number of base-FLT_RADIX digits in the floating-point significand, p */
#if defined(__DBL4)
#define FLT_MANT_DIG	24
#define DBL_MANT_DIG	24
#define LDBL_MANT_DIG	24
#else
#define FLT_MANT_DIG	24
#define DBL_MANT_DIG	53
#define LDBL_MANT_DIG	53
#endif

/*
 * number of decimal digits, n, such that any floating-point number in the
 * widest supported floating type with p max radix b digits can be rounded
 * to a floating-point number with n decimal digits and back again without
 * change to the value
 */
#if (__STDC_VERSION__ >= 199901L)
  #if defined(__DBL4)
    #define DECIMAL_DIG 9
  #else
    #define DECIMAL_DIG 17
  #endif
#endif

/*
 * number of decimal digits, q, such that any floating-point number with
 * q decimal digits can be rounded into a floating-point number with
 * p radix b digits and back again without change to the q decimal
 * digits
 */
#if defined(__DBL4)
#define FLT_DIG		6
#define DBL_DIG		6
#define LDBL_DIG	6
#else
#define FLT_DIG		6
#define DBL_DIG		15
#define LDBL_DIG	15
#endif

/*
 * minimum negative integer such that FLT_RADIX raised to that power
 * minus 1 is a normalized floating-point number, e_{min}
 */
#if defined(__DBL4)
#define FLT_MIN_EXP	-125
#define DBL_MIN_EXP	-125
#define LDBL_MIN_EXP	-125
#else
#define FLT_MIN_EXP	-125
#define DBL_MIN_EXP	-1021
#define LDBL_MIN_EXP	-1021
#endif

/*
 * minimum negative integer such that 10 raised to that power is in the
 * range of normalized floating-point numbers, (log_{10}b^{e_{min}-1})
 */
#if defined(__DBL4)
#define FLT_MIN_10_EXP	-37
#define DBL_MIN_10_EXP	-37
#define LDBL_MIN_10_EXP	-37
#else
#define FLT_MIN_10_EXP	-37
#define DBL_MIN_10_EXP	-307
#define LDBL_MIN_10_EXP	-307
#endif

/*
 * maximum integer such that FLT_RADIX raised to that power minus 1 is
 * a representable finite floating-point number, (e_{max})
 */
#if defined(__DBL4)
#define FLT_MAX_EXP	+128
#define DBL_MAX_EXP	+128
#define LDBL_MAX_EXP	+128
#else
#define FLT_MAX_EXP	+128
#define DBL_MAX_EXP	+1024
#define LDBL_MAX_EXP	+1024
#endif

/*
 * maximum integer such that 10 raised to that power is in the range of
 * representable finite floating-point numbers, (log_{10}((1-b^{-p}) * b^{e_{max}}))
 */
#if defined(__DBL4)
#define FLT_MAX_10_EXP	+38
#define DBL_MAX_10_EXP	+38
#define LDBL_MAX_10_EXP	+38
#else
#define FLT_MAX_10_EXP	+38
#define DBL_MAX_10_EXP	+308
#define LDBL_MAX_10_EXP	+308
#endif

/* maximum representable finite floating-point number, (1-b^{-p}) * b^{e_{max}}) */
#if defined(__DBL4)
#define FLT_MAX		3.40282347E+38F
#define DBL_MAX		3.40282347E+38F
#define LDBL_MAX	3.40282347E+38F
#else
#define FLT_MAX		3.40282347E+38F
#define DBL_MAX		1.7976931348623157E+308
#define LDBL_MAX	1.7976931348623157E+308
#endif

/*
 * the difference between 1.0 and the least value greater than 1.0
 * that is representable in the given floating point type, b^{1-p}
 */
#if defined(__DBL4)
#define FLT_EPSILON	1.19209290E-07F
#define DBL_EPSILON	1.19209290E-07F
#define LDBL_EPSILON	1.19209290E-07F
#else
#define FLT_EPSILON	1.19209290E-07F
#define DBL_EPSILON	2.2204460492503131E-16
#define LDBL_EPSILON	2.2204460492503131E-16
#endif

/* minimum normalized positive floating-point number, b^{e_{min}-1} */
#if defined(__DBL4)
#define FLT_MIN		1.17549436E-38F
#define DBL_MIN		1.17549436E-38F
#define LDBL_MIN	1.17549436E-38F
#else
#define FLT_MIN		1.17549436E-38F
#define DBL_MIN		2.2250738585072014E-308
#define LDBL_MIN	2.2250738585072014E-308
#endif

#endif	/*  __FLOAT_H */
