/*
 * common.h
 *
 *  Created on: 20/06/2013
 *      Author: Raul
 */

#ifndef COMMON_COMMON_H_
#define COMMON_COMMON_H_

#if HAVE_CONFIG_H
#	include <config.h>
#endif

#include <stdio.h>
#include <sys/types.h>

#if STDC_HEADERS
#	include <stdlib.h>
#	include <string.h>
#elif HAVE_STRINGS_H
#	include <unistd.h>
#endif /*STDC_HEADERS*/

#if HAVE_UNISTD_H
#	include <unistd.h>
#endif

#if HAVE_ERRNO_H
#	include <errno.h>
#endif	/*HAVE_ERRNO_H*/
#ifndef errno
/* Some systems #define this! */
extern int errno;
#endif

#ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS  0
#  define EXIT_FAILURE  1
#endif

#ifdef __cplusplus
#  define BEGIN_C_DECLS         extern "C" {
#  define END_C_DECLS           }
#else
#  define BEGIN_C_DECLS
#  define END_C_DECLS
#endif

#define XCALLOC(type, num)                                  \
        ((type *) xcalloc ((num), sizeof(type)))
#define XMALLOC(type, num)                                  \
        ((type *) xmalloc ((num) * sizeof(type)))
#define XREALLOC(type, p, num)                              \
        ((type *) xrealloc ((p), (num) * sizeof(type)))
#define XFREE(stale)                            do {        \
        if (stale) { free (stale);  stale = 0; }            \
                                                } while (0)

BEGIN_C_DECLS

extern void *xcalloc    (size_t num, size_t size);
extern void *xmalloc    (size_t num);
extern void *xrealloc   (void *p, size_t num);
extern char *xstrdup    (const char *string);
extern char *xstrerror  (int errnum);

END_C_DECLS

#endif /* COMMON_COMMON_H_ */
