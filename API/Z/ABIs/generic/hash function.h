/* Z Kit - ABIs/generic/hash function.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_ABIs_generic_hash_function_H_
#define _Z_ABIs_generic_hash_function_H_

#include <Z/types/base.h>

void  (* ZHashFunctionInitialize)(void*	      context);

void  (* ZHashFunctionUpdate)	 (void*	      context,
				  void*	      block,
				  zusize      block_size);

void  (* ZHashFunctionFinalize)	 (void*	      context);

void* (* ZHashFunctionResult)	 (void const* context,
				  zusize*     result_size);

typedef struct {
	ZHashFunctionInitialize initialize;
	ZHashFunctionUpdate	update;
	ZHashFunctionFinalize	finalize;
	ZHashFunctionResult	result;
	zusize			context_size;
	zusize			result_size;
} ZHashFunctionABI;

#endif /* _Z_ABIs_generic_hash_function_H_ */
