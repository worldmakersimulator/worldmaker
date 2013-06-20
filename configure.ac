#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([worldmaker], [0.1], [worldmakersimulator@gmail.com])
AC_CONFIG_SRCDIR([src/worldmaker.cpp])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_AUX_DIR([config])

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_CC
AC_PROG_LIBTOOL
AC_PROG_AWK
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([errno.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([bzero])



AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_FILES(\
	Makefile	\
	src/Makefile	\
	src/common/Makefile	\
	src/kernel/Makefile	\
	src/mod_world/Makefile	\
	)

AC_OUTPUT