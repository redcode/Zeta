/* Z Kit C API - types/buffering.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_buffering_H__
#define __Z_types_buffering_H__

#include <Z/types/base.h>

typedef struct {
	void*		buffers[3];
	zuint8 volatile flags;
} ZTripleBuffer;

typedef struct {
	void*		buffers;
	zusize		buffer_size;
	zusize		buffer_count;
	zusize		consumption_index;
	zusize		production_index;
	zusize volatile fill_count;
} ZRingBuffer;

#endif /* __Z_types_buffering_H__ */
