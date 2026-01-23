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
   errno.h
*/

#ifndef __ERRNO_H
#define __ERRNO_H

#define errno (*_REL_errno())

#if defined(__PIC)
#pragma section text
#endif

extern int *_REL_errno(void);

#if defined(__PIC)
#pragma section default
#endif

#define	EDOM 33		/* Math arg out of domain of func */
#define	ERANGE 34	/* Math result not representable */

#endif /* __ERRNO_H */
