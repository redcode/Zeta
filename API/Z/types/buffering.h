/* Z Kit - types/buffering.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_buffering_H
#define Z_types_buffering_H

#include <Z/types/fundamental.h>

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

#endif /* Z_types_buffering_H */
