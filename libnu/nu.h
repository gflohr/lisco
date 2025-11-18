/* This file is part of the chess engine lisco.
 *
 * Copyright (C) 2002-2025 Guido Flohr.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LISCO_H
# define LISCO_H        /* Allow multiple inclusion.  */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifndef BITV64
# define BITV64 unsigned long long
#endif

typedef BITV64 bitv64;

/* Boolean values. */
typedef enum lisco_bool {
	lisco_false = 0,
#define lisco_false lisco_false
	lisco_true = 1
#define lisco_true lisco_true
} lisco_bool;

#ifdef __cplusplus
# define LISCO_BEGIN_DECLS extern "C" {
# define LISCO_END_DECLS }
#else
# define LISCO_BEGIN_DECLS /* empty */
# define LISCO_END_DECLS /* empty */
#endif

#endif
