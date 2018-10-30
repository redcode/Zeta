/* Z Kit - types/buffering.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_types_buffering_H_
#define _Z_types_buffering_H_

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

#endif /* _Z_types_buffering_H_ */
