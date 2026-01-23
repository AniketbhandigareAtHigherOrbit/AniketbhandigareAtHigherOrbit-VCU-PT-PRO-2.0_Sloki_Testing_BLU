/*
 * Copyright(c) 2012-2019 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */
/* 
   assert.h
*/

#undef	assert
#ifdef NDEBUG
  #define assert(test) ((void)0)
#else
  #include <stdio.h>
  #include <stdlib.h>
  #if (__STDC_VERSION__ >= 199901L)
    #define assert(_test) ((_test)?(void)0:(fprintf(stderr, "Assertion failed : %s, function %s, file %s, line %d\n", #_test, __func__, __FILE__, __LINE__), abort(), (void)0))
  #else
    #define assert(_test) ((_test)?(void)0:(fprintf(stderr, "Assertion failed : %s, file %s, line %d\n", #_test, __FILE__, __LINE__), abort(), (void)0))
  #endif /* (__STDC_VERSION__ >= 199901L) */
#endif
