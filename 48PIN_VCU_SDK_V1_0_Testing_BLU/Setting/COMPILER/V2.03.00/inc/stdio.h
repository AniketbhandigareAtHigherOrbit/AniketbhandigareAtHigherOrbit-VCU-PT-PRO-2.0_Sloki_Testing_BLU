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
   stdio.h
*/

#ifndef	__STDIO_H
#define	__STDIO_H

#ifndef __STDDEF_H
#include <stddef.h>
#endif
#ifndef __STDARG_H
#include <stdarg.h>
#endif

typedef	struct {
	int		mode;	/* with error descriptions */
	unsigned	handle;
	int		unget_c;
	} FILE;
typedef int	fpos_t;

#define	_IOFBF	1
#define	_IOLBF	2
#define	_IONBF	3

#define	BUFSIZ	1024

#define	EOF	(-1)

#define	FOPEN_MAX	0	/* only stdin, stdout and stderr */
#define	FILENAME_MAX	128
#define	L_tmpnam	128

#define	SEEK_SET	0
#define	SEEK_CUR	1
#define	SEEK_END	2

#define	TMPMAX	0
#define	TMP_MAX	0

#if defined(__PIC)
#pragma section text
#endif

extern	FILE*	_REL_stdin();
extern	FILE*	_REL_stdout();
extern	FILE*	_REL_stderr();
#define	stdin	(_REL_stdin())
#define	stdout	(_REL_stdout())
#define	stderr	(_REL_stderr())

extern	int fprintf(FILE *, const char *, ...);
extern	int fscanf(FILE *, const char *, ...);
extern	int printf(const char *, ...);
extern	int scanf(const char *, ...);
extern	int sprintf(char *, const char *, ...);
extern	int sscanf(const char *, const char *, ...);
extern	int vfprintf(FILE *, const char *, va_list);
extern	int vprintf(const char *, va_list);
extern	int vsprintf(char *, const char *, va_list);

extern	int fgetc(FILE *);
extern	char *fgets(char *, int, FILE *);
extern	int fputc(int, FILE *);
extern	int fputs(const char *, FILE *);
extern	int getc(FILE *);
extern	int getchar(void);
extern	char *gets(char *);
extern	int putc(int, FILE *);
extern	int putchar(int);
extern	int puts(const char *);
extern	int ungetc(int, FILE *);

extern	size_t fread(void *, size_t, size_t, FILE *);
extern	size_t fwrite(const void *, size_t, size_t,
		      FILE *);

extern	void rewind(FILE *);

extern	void perror(const char *);

#if defined(__PIC)
#pragma section default
#endif

#endif	/* __STDIO_H */
