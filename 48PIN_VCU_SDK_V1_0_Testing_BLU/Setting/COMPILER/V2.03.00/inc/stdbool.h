/*
 * Copyright(c) 2017 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */

#ifndef	__STDBOOL_H
#define	__STDBOOL_H

#if (__STDC_VERSION__ >= 199901L)

#define bool _Bool
#define true 1
#define false 0
#define __bool_true_false_are_defined 1

#endif /* (__STDC_VERSION__ >= 199901L) */

#endif	/* __STDBOOL_H */
