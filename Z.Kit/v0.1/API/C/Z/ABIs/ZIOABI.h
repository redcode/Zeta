/* Z Kit C API - ABIs/ZIOABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_ZIOABI_H__
#define __Z_ABIs_ZIOABI_H__

#include <Z/types/base.h>

typedef void *(* ZRead)  (void *context, zsize size, void *buffer);
typedef void *(* ZWrite) (void *context, void *block, zsize block_size);

typedef struct {
	ZRead	read;
	ZWrite	write;
} ZIOABI;

#define Z_IO_ABI(p) ((ZIOABI *)(p))

#endif /* __Z_ABIs_ZIOABI_H__ */
