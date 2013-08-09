/* Q API - ABIs/QAllocationABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_ABIs_QAllocationABI_H__
#define __Q_ABIs_QAllocationABI_H__

#include <Q/types/basics.h>

typedef void*	(* QAllocate)		(void* context,
					 qsize size);

typedef void*	(* QAllocateClean)	(void* context,
					 qsize size);

typedef void*	(* QReallocate)		(void* context,
					 void* block,
					 qsize new_size);

typedef void	(* QDeallocate)		(void* context,
					 void* block);

typedef struct {
	QAllocate	allocate;
	QAllocateClean	allocate_clean;
	QReallocate	reallocate;
	QDeallocate	deallocate;
} QAllocationABI;

#define Q_ALLOCATION_ABI(p) ((QAllocationABI *)(p))

#endif /* __Q_ABIs_QAllocationABI_H__ */
