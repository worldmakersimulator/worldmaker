ACLOCAL_AMFLAGS = -I m4

SUBDIRS = common kernel mod_world

lib_LTLIBRARIES = libwm.la
libwm_la_SOURCES = wm.h
libwm_la_LIBADD = 	$(top_builddir)/src/common/libwmcommon.la \
					$(top_builddir)/src/kernel/libwmkernel.la \
					$(top_builddir)/src/mod_world/libwmmodworld.la
					

bin_PROGRAMS = worldmaker
worldmaker_SOURCES = worldmaker.cpp
worldmaker_LDADD = libwm.la


INCLUDES = 	-I$(top_builddir)/src/common \
			-I$(top_builddir)/src/kernel \
			-I$(top_builddir)/src/mod_world 