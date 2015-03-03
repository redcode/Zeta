/* Q Kit API - ABIs/QHashFunctionABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_ABIs_QHashFunctionABI_H__
#define __Q_ABIs_QHashFunctionABI_H__

#include <Q/types/base.h>

typedef struct {
	qsize context_size;
	qsize result_size;

	void  (* initialize) (void* context);
	void  (* update	   ) (void* context, void* block, qsize block_size);
	void  (* finalize  ) (void* context);
	void* (* result	   ) (void* context, qsize* result_size);
} QHashFunctionABI;

#define Q_HASH_FUNCTION_ABI(p) ((QHashFunctionABI *)(p))

#endif /* __Q_ABIs_QHashFunctionABI_H__ */
