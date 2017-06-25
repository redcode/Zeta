/* Z Kit C API - ABIs/generic/allocation.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_generic_allocation_H__
#define __Z_ABIs_generic_allocation_H__

#include <Z/types/base.h>

typedef void* (* ZAllocate)	(void* context,
				 zsize size,
				 zsize alignment);

typedef void* (* ZAllocateClean)(void* context,
				 zsize size,
				 zsize alignment);

typedef void* (* ZReallocate)	(void* context,
				 void* block,
				 zsize new_size,
				 zsize alignment);

typedef void  (* ZDeallocate)	(void* context,
				 void* block);

typedef struct {
	ZAllocate      allocate;
	ZAllocateClean allocate_clean;
	ZReallocate    reallocate;
	ZDeallocate    deallocate;
} ZAllocationABI;

#endif /* __Z_ABIs_generic_allocation_H__ */
