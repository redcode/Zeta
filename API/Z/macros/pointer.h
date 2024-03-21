/* Zeta API - Z/macros/pointer.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_pointer_H
#define Z_macros_pointer_H

#include <Z/types/integral.h>

#define Z_AT(type, base, offset) \
	((type *)(((zchar *)(void *)(base)) + (offset)))

#define Z_AT_CONST(type, base, offset) \
	((type const *)(((zchar const *)(void const *)(base)) + (offset)))

#endif /* Z_macros_pointer_H */
