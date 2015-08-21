/* Z Kit C API - functions/base/block.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_block_H__
#define __Z_functions_base_block_H__

#include <Z/types/base.h>


#define Z_IMPLEMENTATION_BLOCK_FIND(type)				\
									\
									\
Z_INLINE z##type *z_##type##_block_find_equal(				\
	z##type* block,							\
	zsize	 block_size,						\
	z##type  value							\
)									\
	{								\
	while (block_size--) if (*block++ == value) return block;	\
	return NULL;							\
	}								\
									\
									\
Z_INLINE z##type *z_##type##_block_find_equal_backwards(		\
	z##type* block,							\
	zsize	 block_size,						\
	z##type  value							\
)									\
	{								\
	while (block_size--) if (*block-- == value) return block;	\
	return NULL;							\
	}								\
									\
									\
Z_INLINE z##type *z_##type##_block_find_different(			\
	z##type* block,							\
	zsize	 block_size,						\
	z##type  value							\
)									\
	{								\
	while (block_size--) if (*block++ != value) return block;	\
	return NULL;							\
	}								\
									\
									\
Z_INLINE z##type *z_##type##_block_find_different_backwards(		\
	z##type* block,							\
	zsize	 block_size,						\
	z##type  value							\
)									\
	{								\
	while (block_size--) if (*block-- != value) return block;	\
	return NULL;							\
	}


Z_IMPLEMENTATION_BLOCK_FIND(uint8)
Z_IMPLEMENTATION_BLOCK_FIND(uint16)
Z_IMPLEMENTATION_BLOCK_FIND(uint32)
Z_IMPLEMENTATION_BLOCK_FIND(uint64)
Z_IMPLEMENTATION_BLOCK_FIND(int8)
Z_IMPLEMENTATION_BLOCK_FIND(int16)
Z_IMPLEMENTATION_BLOCK_FIND(int32)
Z_IMPLEMENTATION_BLOCK_FIND(int64)
Z_IMPLEMENTATION_BLOCK_FIND(float)
Z_IMPLEMENTATION_BLOCK_FIND(double)
Z_IMPLEMENTATION_BLOCK_FIND(ldouble)

#define z_value_block_find_equal(	       TYPE) Z_JOIN_3(z_, Z_##TYPE##_FIXED_TYPE_name, _block_find_equal		     )
#define z_value_block_find_equal_backwards(    TYPE) Z_JOIN_3(z_, Z_##TYPE##_FIXED_TYPE_name, _block_find_equal_backwards    )
#define z_value_block_find_different(	       TYPE) Z_JOIN_3(z_, Z_##TYPE##_FIXED_TYPE_name, _block_find_different	     )
#define z_value_block_find_different_backwards(TYPE) Z_JOIN_3(z_, Z_##TYPE##_FIXED_TYPE_name, _block_find_different_backwards)


#endif /* __Z_functions_base_block_H__ */
