/* Z Kit C API - ABIs/ZHashFunctionABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_ZHashFunctionABI_H__
#define __Z_ABIs_ZHashFunctionABI_H__

#include <Z/types/base.h>

typedef struct {
	zsize context_size;
	zsize result_size;

	void  (* initialize) (void* context);
	void  (* update	   ) (void* context, void* block, zsize block_size);
	void  (* finalize  ) (void* context);
	void* (* result	   ) (void* context, zsize* result_size);
} ZHashFunctionABI;

#endif /* __Z_ABIs_ZHashFunctionABI_H__ */
