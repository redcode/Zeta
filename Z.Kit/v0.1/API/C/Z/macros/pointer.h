/* Z Kit C API - macros/pointer.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_pointer_H__
#define __Z_macros_pointer_H__

#include <Z/types/base.h>

/* MARK: - Logic operations */

#define Z_POINTER_AND(pointer, value) (pointer = (void *)( (zuintptr)pointer & (value)));
#define Z_POINTER_OR( pointer, value) (pointer = (void *)( (zuintptr)pointer | (value)));
#define Z_POINTER_XOR(pointer, value) (pointer = (void *)( (zuintptr)pointer ^ (value)));
#define Z_POINTER_NOT(pointer)	      (pointer = (void *)(~(zuintptr)pointer));

/* MARK: - Pointer from base + index */

#define Z_BIP(type, base, index) (((type)(base)) + (index))

/* MARK: - Pointer from base + offset */

#define Z_BOP(type, base, offset) ((type)(((zuint8 *)(base)) + (offset)))

/* MARK: - Index from base calculations */

#define Z_INDEX(type, base, pointer)		 ((zsize)(((zuintptr)pointer - (zuintptr)base) / sizeof(type)))
#define Z_BLOCK_INDEX(base, pointer, block_size) ((zsize)(((zuintptr)pointer - (zuintptr)base) / block_size))

/* MARK: - Value search */

#define Z_SKIP(	   criteria, pointer) while ( Z_IS_##criteria(*pointer)) pointer++
#define Z_SKIP_NON(criteria, pointer) while (!Z_IS_##criteria(*pointer)) pointer++

#endif /* __Z_macros_pointer_H__ */
