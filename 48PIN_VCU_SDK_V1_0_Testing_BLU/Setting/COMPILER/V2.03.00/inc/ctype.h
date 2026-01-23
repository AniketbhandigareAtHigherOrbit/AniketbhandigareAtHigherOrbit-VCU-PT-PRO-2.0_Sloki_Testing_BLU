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
   ctype.h
*/

#ifndef	__CTYPE_H
#define	__CTYPE_H

#if defined(__PIC)
#pragma section text
#endif

extern	int isalnum(int);
extern	int isalpha(int);
extern	int iscntrl(int);
extern	int isdigit(int);
extern	int isgraph(int);
extern	int islower(int);
extern	int isprint(int);
extern	int ispunct(int);
extern	int isspace(int);
extern	int isupper(int);
extern	int isxdigit(int);
extern	int tolower(int);
extern	int toupper(int);

extern	int isascii(int);

#if defined(__PIC)
#pragma section default
#endif

#define	_U	01
#define	_L	02
#define	_N	04
#define	_S	010
#define	_P	020
#define	_C	040
#define	_X	0100
#define	_B	0200

#pragma section const
extern const char	_ctype_[];
#pragma section default

#define	isalnum(_c)	(_ctype_[((_c)+1)& 0xff] & (_U|_L|_N))
#define	isalpha(_c)	(_ctype_[((_c)+1) & 0xff] & (_U|_L))
#define	iscntrl(_c)	(_ctype_[((_c)+1) & 0xff] & _C)
#define	isdigit(_c)	(_ctype_[((_c)+1) & 0xff] & _N)
#define	isgraph(_c)	(_ctype_[((_c)+1) & 0xff] & (_P|_U|_L|_N))
#define	islower(_c)	(_ctype_[((_c)+1) & 0xff] & _L)
#define	isprint(_c)	(_ctype_[((_c)+1) & 0xff] & (_P|_U|_L|_N|_B))
#define	ispunct(_c)	(_ctype_[((_c)+1) & 0xff] & _P)
#define	isspace(_c)	(_ctype_[((_c)+1) & 0xff] & _S)
#define	isupper(_c)	(_ctype_[((_c)+1) & 0xff] & _U)
#define	isxdigit(_c)	(_ctype_[((_c)+1) & 0xff] & (_X|_N))

#define	tolower(_c)	(isupper(_c)? (_c)-'A'+'a': (_c))
#define	toupper(_c)	(islower(_c)? (_c)-'a'+'A': (_c))

#define	isascii(_c)	((unsigned)(_c) <= 0177)

#endif /* __CTYPE_H */
