/* Z Kit - macros/pointer.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_pointer_H
#define Z_macros_pointer_H

#include <Z/types/integral.h>

/* MARK: - Pointer from base + index */

#define Z_BIP(type, base, index) \
	(((type)(base)) + (index))

/* MARK: - Pointer from base + offset */

#define Z_BOP(type, base, offset) \
	((type)(((zuint8 *)(void *)(base)) + (offset)))

/* MARK: - Index from base calculations */

#define Z_INDEX(type, base, pointer) \
	((zusize)(((zuintptr)pointer - (zuintptr)base) / sizeof(type)))

#define Z_BLOCK_INDEX(base, pointer, block_size) \
	((zusize)(((zuintptr)pointer - (zuintptr)base) / block_size))

#endif /* Z_macros_pointer_H */
