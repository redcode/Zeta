/* Q API - ABIs/QAllocationABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_ABIs_QAllocationABI_H__
#define __Q_ABIs_QAllocationABI_H__

#include <Q/types/base.h>

typedef void* (* QAllocate)	 (void* context,
				  qsize size,
				  qsize alignment);

typedef void* (* QAllocateClean) (void* context,
				  qsize size,
				  qsize alignment);

typedef void* (* QReallocate)	 (void* context,
				  void* block,
				  qsize new_size,
				  qsize alignment);

typedef void  (* QDeallocate)	 (void* context,
				  void* block);

typedef struct {
	QAllocate      allocate;
	QAllocateClean allocate_clean;
	QReallocate    reallocate;
	QDeallocate    deallocate;
} QAllocationABI;

#define Q_ALLOCATION_ABI(p) ((QAllocationABI *)(p))

#endif /* __Q_ABIs_QAllocationABI_H__ */
