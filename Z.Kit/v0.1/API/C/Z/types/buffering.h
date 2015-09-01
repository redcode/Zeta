/* Z Kit C API - types/buffering.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_buffering_H__
#define __Z_types_buffering_H__

#include <Z/types/base.h>

typedef struct {
	void*		buffers[3];
	volatile zuint8 flags;
} ZTripleBuffer;

typedef struct {
	void*	       buffers;
	zsize	       buffer_size;
	zsize	       buffer_count;
	zsize	       consumption_index;
	zsize	       production_index;
	volatile zsize fill_count;
} ZRingBuffer;

#endif /* __Z_types_buffering_H__ */
