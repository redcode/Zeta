/* Z Kit - macros/pointer.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_pointer_H_
#define _Z_macros_pointer_H_

#include <Z/types/base.h>

/* MARK: - Logic operations */

#define Z_POINTER_AND(pointer, value) ((void *)( (zuintptr)pointer & (value)));
#define Z_POINTER_OR( pointer, value) ((void *)( (zuintptr)pointer | (value)));
#define Z_POINTER_XOR(pointer, value) ((void *)( (zuintptr)pointer ^ (value)));
#define Z_POINTER_NOT(pointer)	      ((void *)(~(zuintptr)pointer));

/* MARK: - Pointer from base + index */

#define Z_BIP(type, base, index) (((type)(base)) + (index))

/* MARK: - Pointer from base + offset */

#define Z_BOP(type, base, offset) ((type)(((zuint8 *)(base)) + (offset)))

/* MARK: - Index from base calculations */

#define Z_INDEX(type, base, pointer)		 ((zusize)(((zuintptr)pointer - (zuintptr)base) / sizeof(type)))
#define Z_BLOCK_INDEX(base, pointer, block_size) ((zusize)(((zuintptr)pointer - (zuintptr)base) / block_size))

#endif /* _Z_macros_pointer_H_ */
