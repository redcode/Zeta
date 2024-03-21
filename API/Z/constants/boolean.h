/* Zeta API - Z/constants/boolean.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_constants_boolean_H
#define Z_constants_boolean_H

#ifndef TRUE
#	define TRUE 1
#endif

#ifndef FALSE
#	define FALSE 0
#endif

#ifdef Z_TRUE
#	undef Z_TRUE
#endif

#define Z_TRUE 1

#ifdef Z_FALSE
#	undef Z_FALSE
#endif

#define Z_FALSE 0

#endif /* Z_constants_boolean_H */
