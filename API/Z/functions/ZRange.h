/* Z Kit - functions/base/ZRange.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_base_ZRange_H_
#define _Z_functions_base_ZRange_H_

#include <Z/functions/base/constructors.h>
#include <Z/functions/base/value.h>


#if Z_LANGUAGE_HAS(C, COMPOUND_LITERAL)

#	define z_range_uint8(index, size)  ((ZRangeUInt8 ){index, size})
#	define z_range_uint16(index, size) ((ZRangeUInt16){index, size})
#	define z_range_uint32(index, size) ((ZRangeUInt32){index, size})

#	ifdef Z_UINT64
#		define z_range_uint64(index, size) ((ZRangeUInt64){index, size})
#	endif

#	ifdef Z_UINT128
#		define z_range_uint128(index, size) ((ZRangeUInt128){index, size})
#	endif

#else

#	define Z_IMPLEMENTATION(Type, type)			 \
								 \
	static Z_INLINE						 \
	ZRange##Type z_range_##type(z##type index, z##type size) \
		{						 \
		ZRange##Type object;				 \
								 \
		object.index = index;				 \
		object.size  = size;				 \
		return object;					 \
		}


	Z_IMPLEMENTATION(UInt8,	 uint8 )
	Z_IMPLEMENTATION(UInt16, uint16)
	Z_IMPLEMENTATION(UInt32, uint32)

#	ifdef Z_UINT64
		Z_IMPLEMENTATION(UInt64, uint64)
#	endif

#	ifdef Z_UINT128
		Z_IMPLEMENTATION(UInt128, uint128)
#	endif

#	undef Z_IMPLEMENTATION

#endif

#define z_range_uint8_zero  z_range_uint8 (0, 0)
#define z_range_uint16_zero z_range_uint16(0, 0)
#define z_range_uint32_zero z_range_uint32(0, 0)

#ifdef Z_UINT64
#	define z_range_uint64_zero z_range_uint64(0, 0)
#endif

#ifdef Z_UINT128
#	define z_range_uint128_zero z_range_uint128(0, 0)
#endif


#define Z_IMPLEMENTATION(Type, type)								\
												\
static Z_INLINE											\
zboolean z_range_##type##_are_equal(ZRange##Type a, ZRange##Type b)				\
	{return a.index == b.index && a.size == b.size;}					\
												\
												\
static Z_INLINE											\
zboolean z_range_##type##_contains(ZRange##Type object, ZRange##Type other)			\
	{											\
	return	object.index		   <= other.index &&					\
		object.index + object.size >= other.index + other.size;				\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_range_##type##_contains_index(ZRange##Type object, z##type index)			\
	{return index >= object.index && index < object.index + object.size;}			\
												\
												\
static Z_INLINE											\
zusize z_range_##type##_end(ZRange##Type object)						\
	{return object.index + object.size;}							\
												\
												\
static Z_INLINE											\
ZRange##Type z_range_##type##_from_indices(z##type a, z##type b)				\
	{return a < b ? z_range_##type(a, b - a) : z_range_##type(b, a - b);}			\
												\
												\
static Z_INLINE											\
zboolean z_range_##type##_intersect(ZRange##Type a, ZRange##Type b)				\
	{return a.index < b.index + b.size && b.index < a.index + a.size;}			\
												\
												\
static Z_INLINE											\
ZRange##Type z_range_##type##_intersection(ZRange##Type a, ZRange##Type b)			\
	{											\
	z##type index = (a.index > b.index) ? a.index : b.index,				\
		end   = z_##type##_minimum(a.index + a.size, b.index + b.size);			\
												\
	return end > index ? z_range_##type(index, end - index) : z_range_##type##_zero;	\
	}											\
												\
												\
static Z_INLINE											\
ZRange##Type z_range_##type##_union(ZRange##Type a, ZRange##Type b)				\
	{											\
	z##type	index = (a.index < b.index) ? a.index : b.index,				\
		a_end = a.index + a.size,							\
		b_end = b.index + b.size;							\
												\
        return z_range_##type(index, ((a_end > b_end) ? a_end : b_end) - index);		\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_range_##type##_is_zero(ZRange##Type object)						\
	{return object.index == 0 && object.size == 0;}


#define z_range_type(		    TYPE) Z_APPEND_##TYPE##_fixed_type(z_range_			)
#define z_range_type_are_equal(	    TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _are_equal	)
#define z_range_type_contains(	    TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _contains	)
#define z_range_type_contains_index(TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _contains_index)
#define z_range_type_end(	    TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _end		)
#define z_range_type_from_indices(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _from_indices	)
#define z_range_type_intersect(	    TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _intersect	)
#define z_range_type_intersection(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _intersection	)
#define z_range_type_is_zero(	    TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _is_zero	)
#define z_range_type_union(	    TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _union		)
#define z_range_type_zero(	    TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _zero		)

Z_IMPLEMENTATION(UInt8,  uint8 )
Z_IMPLEMENTATION(UInt16, uint16)
Z_IMPLEMENTATION(UInt32, uint32)

#ifdef Z_UINT64
	Z_IMPLEMENTATION(UInt64, uint64)
#endif

#ifdef Z_UINT128
	Z_IMPLEMENTATION(UInt128, uint128)
#endif

#undef Z_IMPLEMENTATION

#define z_range		       z_range_type		  (USIZE)
#define z_range_are_equal      z_range_type_are_equal	  (USIZE)
#define z_range_contains       z_range_type_contains	  (USIZE)
#define z_range_contains_index z_range_type_contains_index(USIZE)
#define z_range_end	       z_range_type_end		  (USIZE)
#define z_range_from_indices   z_range_type_from_indices  (USIZE)
#define z_range_intersect      z_range_type_intersect	  (USIZE)
#define z_range_intersection   z_range_type_intersection  (USIZE)
#define z_range_is_zero	       z_range_type_is_zero	  (USIZE)
#define z_range_union	       z_range_type_union	  (USIZE)
#define z_range_zero	       z_range_type_zero	  (USIZE)


#endif /* _Z_functions_base_ZRange_H_ */
