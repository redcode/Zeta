/* Q API - macros/pointer.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_pointer_H__
#define __Q_macros_pointer_H__

#include <Q/types/base.h>

/* MARK: - Logic operations */

#define Q_POINTER_AND(pointer, value) (pointer = (void *)( (quintptr)pointer & (value)));
#define Q_POINTER_OR( pointer, value) (pointer = (void *)( (quintptr)pointer | (value)));
#define Q_POINTER_XOR(pointer, value) (pointer = (void *)( (quintptr)pointer ^ (value)));
#define Q_POINTER_NOT(pointer)	      (pointer = (void *)(~(quintptr)pointer));

/* MARK: - Pointer from base + index */

#define Q_BIP(type, base, index) (((type)(base)) + (index))

/* MARK: - Pointer from base + offset */

#define Q_BOP(type, base, offset) ((type)(((void *)(base)) + (offset)))

/* MARK: - Index from base calculations */

#define Q_INDEX(type, base, pointer)		 ((qsize)(((quintptr)pointer - (quintptr)base) / sizeof(type)))
#define Q_BLOCK_INDEX(base, pointer, block_size) ((qsize)(((quintptr)pointer - (quintptr)base) / block_size))

/* MARK: - Value search */

#define Q_SKIP(	   criteria, pointer) while ( Q_IS_##criteria(*pointer)) pointer++
#define Q_SKIP_NON(criteria, pointer) while (!Q_IS_##criteria(*pointer)) pointer++

#endif /* __Q_macros_pointer_H__ */
