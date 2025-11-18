## This file is part of the chess engine lisco.
##
## Copyright (C) 2002-2025 Guido Flohr.
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.

## Process this file with automake to produce Makefile.in.

AUTOMAKE_OPTIONS = 1.5 gnits

SUBDIRS = . tests

lib_LTLIBRARIES = libnu.la
libnu_la_SOURCES = nu.h chi-internal.h \
	piece-chars.c

libnu_la_LDFLAGS = -version-info 0:0:0

libnu_la_LDFLAGS += -no-undefined
libnu_la_LIBADD = ../lib/liblisco.la

AM_CPPFLAGS = -I. -I$(srcdir) -I.. -I$(top_srcdir)/lib

# *Never* add -lchi here (bootstrapping problem).

include_HEADERS = nu.h

