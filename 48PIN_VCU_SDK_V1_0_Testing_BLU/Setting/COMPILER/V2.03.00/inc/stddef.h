/*
 * Copyright(c) 1997-2019 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */
/* 
   stddef.h
*/

#ifndef __STDDEF_H
#define __STDDEF_H

typedef	int	ptrdiff_t;
typedef	unsigned long	size_t;

#define offsetof(_type,_member)  ((size_t)&(((_type*)0)->_member))

#ifndef NULL
#define	NULL	((void *) 0)
#endif	/* NULL */

#endif	/* __STDDEF_H */
