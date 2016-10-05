/* Z Kit C API - types/buffering.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_buffering_H__
#define __Z_types_buffering_H__

#include <Z/types/base.h>

typedef struct {
	void*		buffers[3];
	zuint8 volatile flags;
} ZTripleBuffer;

typedef struct {
	void*	       buffers;
	zsize	       buffer_size;
	zsize	       buffer_count;
	zsize	       consumption_index;
	zsize	       production_index;
	zsize volatile fill_count;
} ZRingBuffer;

#endif /* __Z_types_buffering_H__ */
