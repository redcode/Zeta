/* Z Kit - ABIs/generic/allocator.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_ABIs_generic_allocator_H
#define Z_ABIs_generic_allocator_H

#include <Z/types/fundamental.h>

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
} ZAllocatorABI;

#endif /* Z_ABIs_generic_allocator_H */
