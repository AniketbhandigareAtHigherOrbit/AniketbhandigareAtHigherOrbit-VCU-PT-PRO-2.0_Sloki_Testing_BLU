/*
 * Copyright(c) 2016 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */

#ifndef __HALF_H
#define __HALF_H

/* number of base-FLT_RADIX digits in the floating-point significand, p */
#define HALF_MANT_DIG	11

/*
 * number of decimal digits, q, such that any floating-point number with
 * q decimal digits can be rounded into a floating-point number with
 * p radix b digits and back again without change to the q decimal
 * digits
 */
#define HALF_DIG	2

/*
 * minimum negative integer such that FLT_RADIX raised to that power
 * minus 1 is a normalized floating-point number, e_{min}
 */
#define HALF_MIN_EXP	-13

/*
 * minimum negative integer such that 10 raised to that power is in the
 * range of normalized floating-point numbers, (log_{10}b^{e_{min}-1})
 */
#define HALF_MIN_10_EXP	-4

/*
 * maximum integer such that FLT_RADIX raised to that power minus 1 is
 * a representable finite floating-point number, (e_{max})
 */
#define HALF_MAX_EXP	+16

/*
 * maximum integer such that 10 raised to that power is in the range of
 * representable finite floating-point numbers, (log_{10}((1-b^{-p}) * b^{e_{max}}))
 */
#define HALF_MAX_10_EXP	+4

/* maximum representable finite floating-point number, (1-b^{-p}) * b^{e_{max}}) */
#define HALF_MAX	65504.0F

/*
 * the difference between 1.0 and the least value greater than 1.0
 * that is representable in the given floating point type, b^{1-p}
 */
#define HALF_EPSILON	0.00097656F

/* minimum normalized positive floating-point number, b^{e_{min}-1} */
#define HALF_MIN	6.10352e-05F

#endif	/*  __HALF_H */
