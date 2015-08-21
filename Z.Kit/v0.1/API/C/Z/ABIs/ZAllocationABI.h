/* Z Kit C API - ABIs/ZAllocationABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_ZAllocationABI_H__
#define __Z_ABIs_ZAllocationABI_H__

#include <Z/types/base.h>

typedef void* (* ZAllocate)	 (void* context,
				  zsize size,
				  zsize alignment);

typedef void* (* ZAllocateClean) (void* context,
				  zsize size,
				  zsize alignment);

typedef void* (* ZReallocate)	 (void* context,
				  void* block,
				  zsize new_size,
				  zsize alignment);

typedef void  (* ZDeallocate)	 (void* context,
				  void* block);

typedef struct {
	ZAllocate      allocate;
	ZAllocateClean allocate_clean;
	ZReallocate    reallocate;
	ZDeallocate    deallocate;
} ZAllocationABI;

#define Z_ALLOCATION_ABI(p) ((ZAllocationABI *)(p))

#endif /* __Z_ABIs_ZAllocationABI_H__ */
