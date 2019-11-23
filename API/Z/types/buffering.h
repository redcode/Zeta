/* Z Kit - types/buffering.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_buffering_H
#define Z_types_buffering_H

#include <Z/types/integral.h>

typedef struct {
	void*		slots[3];
	zuchar volatile flags;
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
