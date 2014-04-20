/* Q API - functions/base/block.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_base_block_H__
#define __Q_functions_base_block_H__

#include <Q/types/base.h>


#define Q_IMPLEMENTATION_BLOCK_FIND(type)				\
									\
									\
Q_INLINE q##type *q_##type##_block_find_equal(				\
	q##type* block,							\
	qsize	 block_size,						\
	q##type  value							\
)									\
	{								\
	while (block_size--) if (*block++ == value) return block;	\
									\
	return NULL;							\
	}								\
									\
									\
Q_INLINE q##type *q_##type##_block_find_equal_backwards(		\
	q##type* block,							\
	qsize	 block_size,						\
	q##type  value							\
)									\
	{								\
	while (block_size--) if (*block-- == value) return block;	\
									\
	return NULL;							\
	}								\
									\
									\
Q_INLINE q##type *q_##type##_block_find_different(			\
	q##type* block,							\
	qsize	 block_size,						\
	q##type  value							\
)									\
	{								\
	while (block_size--) if (*block++ != value) return block;	\
									\
	return NULL;							\
	}								\
									\
									\
Q_INLINE q##type *q_##type##_block_find_different_backwards(		\
	q##type* block,							\
	qsize	 block_size,						\
	q##type  value							\
)									\
	{								\
	while (block_size--) if (*block-- != value) return block;	\
									\
	return NULL;							\
	}



Q_IMPLEMENTATION_BLOCK_FIND(uint8)
Q_IMPLEMENTATION_BLOCK_FIND(uint16)
Q_IMPLEMENTATION_BLOCK_FIND(uint32)
Q_IMPLEMENTATION_BLOCK_FIND(uint64)
Q_IMPLEMENTATION_BLOCK_FIND(int8)
Q_IMPLEMENTATION_BLOCK_FIND(int16)
Q_IMPLEMENTATION_BLOCK_FIND(int32)
Q_IMPLEMENTATION_BLOCK_FIND(int64)
Q_IMPLEMENTATION_BLOCK_FIND(float)
Q_IMPLEMENTATION_BLOCK_FIND(double)
Q_IMPLEMENTATION_BLOCK_FIND(ldouble)

#define q_value_block_find_equal(	       TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _block_find_equal		     )
#define q_value_block_find_equal_backwards(    TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _block_find_equal_backwards    )
#define q_value_block_find_different(	       TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _block_find_different	     )
#define q_value_block_find_different_backwards(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _block_find_different_backwards)

#endif /* __Q_functions_base_block_H__ */
