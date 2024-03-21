/* Zeta API - Z/macros/array.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_array_H
#define Z_macros_array_H

#define Z_ARRAY_SIZE(array) \
	(sizeof((array)) / sizeof((array)[0]))

#endif /* Z_macros_array_H */
