/*
 * Copyright(c) 2012-2018 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */
#ifndef	__BUILTIN_H
#define	__BUILTIN_H

#if defined(__PIC)
#pragma section text
#endif

extern void __nop(void);
extern void __halt(void);

extern long __satadd(long, long);
extern long __satsub(long, long);

extern long __bsh(long);
extern long __bsw(long);
extern long __hsw(long);

extern long __mul32(long, long);
extern unsigned long __mul32u(unsigned long, unsigned long);

extern long __sch0l(long);
extern long __sch0r(long);
extern long __sch1l(long);
extern long __sch1r(long);

extern void __ldsr(long, unsigned long);
extern void __ldsr_rh(long, long, unsigned long);
extern unsigned long __stsr(long);
extern unsigned long __stsr_rh(long, long);

extern long __caxi(long*, long, long);

extern void __DI(void);
extern void __EI(void);
extern void __set_il_rh(long, void*);

extern void __clr1(unsigned char*, long);
extern void __set1(unsigned char*, long);
extern void __not1(unsigned char*, long);

extern long __ldlw(long*);
extern long __stcw(long*, long);

extern void __synce(void);
extern void __synci(void);
extern void __syncm(void);
extern void __syncp(void);

extern void __dbcp(void);
extern void __dbpush(long, long);
extern void __dbtag(long);

extern long __clipb(long);
extern unsigned long __clipbu(unsigned long);
extern long __cliph(long);
extern unsigned long __cliphu(unsigned long);

extern long __ldlbu(unsigned char*);
extern long __ldlhu(unsigned short*);
extern long __stcb(unsigned char*, unsigned char);
extern long __stch(unsigned short*, unsigned short);

#if defined(__PIC)
#pragma section default
#endif

#endif	/* __BUILTIN_H */
