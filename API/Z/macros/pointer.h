/* Z Kit - macros/pointer.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

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
