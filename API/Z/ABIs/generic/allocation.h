/* Z Kit - ABIs/generic/allocation.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library  is free software: you  can redistribute it and/or  modify it under
the terms  of the  GNU Lesser General  Public License as  published by  the Free
Software Foundation,  either version 3 of  the License, or (at  your option) any
later version.

This library is distributed in the hope  that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty  of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser  General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_ABIs_generic_allocation_H_
#define _Z_ABIs_generic_allocation_H_

#include <Z/types/base.h>

typedef void* (* ZAllocate)	(void*	context,
				 zusize size,
				 zusize alignment);

typedef void* (* ZAllocateClean)(void*	context,
				 zusize size,
				 zusize alignment);

typedef void* (* ZReallocate)	(void*	context,
				 void*	block,
				 zusize new_size,
				 zusize alignment);

typedef void  (* ZDeallocate)	(void*	context,
				 void*	block);

typedef struct {
	ZAllocate      allocate;
	ZAllocateClean allocate_clean;
	ZReallocate    reallocate;
	ZDeallocate    deallocate;
} ZAllocationABI;

#endif /* _Z_ABIs_generic_allocation_H_ */
