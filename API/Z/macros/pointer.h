/* Zeta API - Z/macros/pointer.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2023 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_pointer_H
#define Z_macros_pointer_H

#include <Z/types/integral.h>

#define Z_BIP(type, base, index) \
	(((type)(base)) + (index))

#define Z_BOP(type, base, offset) \
	((type)(((zchar *)(void *)(base)) + (offset)))

#define Z_INDEX(type, base, pointer) \
	((zusize)(((zuintptr)pointer - (zuintptr)base) / sizeof(type)))

#define Z_BLOCK_INDEX(base, pointer, block_size) \
	((zusize)(((zuintptr)pointer - (zuintptr)base) / block_size))

#endif /* Z_macros_pointer_H */
