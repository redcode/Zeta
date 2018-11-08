/* Z Kit - ABIs/generic/hash function.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
-------------------------------------------------------------------------------
This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>.
---------------------------------------------------------------------------- */

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
