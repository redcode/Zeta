/* Q API - functions/base/Q3D.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_base_Q3D_H__
#define __Q_functions_base_Q3D_H__

#include <Q/functions/base/constructors.h>
#include <Q/functions/base/value.h>


/* MARK: - Operations for natural, integer and real types */


#define Q_IMPLEMENTATION_NATURAL_3D(Type, type)					\
										\
										\
Q_INLINE qboolean q_3d_##type##_are_equal(Q3D##Type a, Q3D##Type b)		\
	{return a.x == b.x && a.y == b.y && a.z == b.z;}			\
										\
										\
Q_INLINE void q_##3d_##type##_swap(Q3D##Type *a, Q3D##Type *b)			\
	{									\
	Q3D##Type t = *a;							\
										\
	*a = *b;								\
	*b = t;									\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_contains(Q3D##Type a, Q3D##Type b)		\
	{return b.x <= a.x && b.y <= a.y && b.z <= a.z;}			\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_add(Q3D##Type a, Q3D##Type b)			\
	{return q_3d_##type(a.x + b.x, a.y + b.y, a.z + b.z);}			\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_subtract(Q3D##Type a, Q3D##Type b)		\
	{return q_3d_##type(a.x - b.x, a.y - b.y, a.z - b.z);}			\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_multiply(Q3D##Type a, Q3D##Type b)		\
	{return q_3d_##type(a.x * b.x, a.y * b.y, a.z * b.z);}			\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_divide(Q3D##Type a, Q3D##Type b)		\
	{return q_3d_##type(a.x / b.x, a.y / b.y, a.z / b.z);}			\
										\
										\
Q_INLINE q##type q_3d_##type##_dot_product(Q3D##Type a, Q3D##Type b)		\
	{return a.x * b.x + a.y * b.y + a.y * b.y;}				\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_cross_product(Q3D##Type a, Q3D##Type b)	\
	{									\
	return q_3d_##type							\
		(a.y * b.z - a.z * b.y,						\
		 a.z * b.x - a.x * b.z,						\
		 a.x * b.y - a.y * b.x); 					\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_minimum(Q3D##Type a, Q3D##Type b)		\
	{									\
	return q_3d_##type							\
		(q_##type##_minimum(a.x, b.x),					\
		 q_##type##_minimum(a.y, b.y),					\
		 q_##type##_minimum(a.z, b.z));					\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_maximum(Q3D##Type a, Q3D##Type b)		\
	{									\
	return q_3d_##type							\
		(q_##type##_maximum(a.x, b.x),					\
		 q_##type##_maximum(a.y, b.y),					\
		 q_##type##_maximum(a.z, b.z));					\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_middle(Q3D##Type a, Q3D##Type b)		\
	{									\
	return q_3d_##type							\
		((a.x + b.x) / (q##type)2,					\
		 (a.y + b.y) / (q##type)2,					\
		 (a.z + b.z) / (q##type)2);					\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_fit(Q3D##Type a, Q3D##Type b)			\
	{									\
	return q_3d_##type##_zero;/*a.y / a.x > b.y / b.x			\
		? q_3d_##type(a.x * b.y / a.y, b.y)				\
		: q_3d_##type(b.x, a.y * b.x / a.x);*/				\
	} /* Terminar */							\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_from_scalar(q##type scalar)			\
	{return q_3d_##type(scalar, scalar, scalar);}				\
										\
										\
Q_INLINE qboolean q_3d_##type##_is_zero(Q3D##Type magnitude)			\
	{									\
	return	magnitude.x == (q##type)0 &&					\
		magnitude.y == (q##type)0 &&					\
		magnitude.z == (q##type)0;					\
	}									\
										\
										\
Q_INLINE q##type q_3d_##type##_inner_sum(Q3D##Type magnitude)			\
	{return magnitude.x + magnitude.y + magnitude.z;}			\
										\
										\
Q_INLINE q##type q_3d_##type##_inner_product(Q3D##Type magnitude)		\
	{return magnitude.x * magnitude.y * magnitude.z;}			\
										\
										\
Q_INLINE q##type q_3d_##type##_inner_minimum(Q3D##Type magnitude)		\
	{									\
	return q_##type##_minimum						\
		(q_##type##_minimum(magnitude.x, magnitude.y),			\
		 magnitude.z);							\
	}									\
										\
										\
Q_INLINE q##type q_3d_##type##_inner_maximum(Q3D##Type magnitude)		\
	{									\
	return q_##type##_maximum						\
		(q_##type##_maximum(magnitude.x, magnitude.y),			\
		 magnitude.z);							\
	}									\
										\
										\
Q_INLINE q##type q_3d_##type##_inner_middle(Q3D##Type magnitude)		\
	{return (magnitude.x + magnitude.y + magnitude.z) / (q##type)3;}	\
										\
										\
Q_INLINE q##type q_3d_##type##_squared_length(Q3D##Type magnitude)		\
	{									\
	return	magnitude.x * magnitude.x +					\
		magnitude.y * magnitude.y +					\
		magnitude.z * magnitude.z;					\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_add_scalar(Q3D##Type magnitude, q##type scalar)		\
	{									\
	return q_3d_##type							\
		(magnitude.x + scalar,						\
		 magnitude.y + scalar,						\
		 magnitude.z + scalar);						\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_subtract_scalar(Q3D##Type magnitude, q##type scalar)	\
	{									\
	return q_3d_##type							\
		(magnitude.x - scalar,						\
		 magnitude.y - scalar,						\
		 magnitude.z - scalar);						\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_multiply_by_scalar(Q3D##Type magnitude, q##type scalar)	\
	{									\
	return q_3d_##type							\
		(magnitude.x * scalar,						\
		 magnitude.y * scalar,						\
		 magnitude.z * scalar);						\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_divide_by_scalar(Q3D##Type magnitude, q##type scalar)	\
	{									\
	return q_3d_##type							\
		(magnitude.x / scalar,						\
		 magnitude.y / scalar,						\
		 magnitude.z / scalar);						\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_clamp(						\
	Q3D##Type magnitude,							\
	Q3D##Type minimum,							\
	Q3D##Type maximum							\
)										\
	{									\
	return q_3d_##type							\
		(q_##type##_clamp(magnitude.x, minimum.x, maximum.x),		\
		 q_##type##_clamp(magnitude.y, minimum.y, maximum.y),		\
		 q_##type##_clamp(magnitude.z, minimum.z, maximum.z));		\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_cube_clamp(					\
	Q3D##Type magnitude,							\
	q##type	  minimum,							\
	q##type	  maximum							\
)										\
	{									\
	return q_3d_##type							\
		(q_##type##_clamp(magnitude.x, minimum, maximum),		\
		 q_##type##_clamp(magnitude.y, minimum, maximum),		\
		 q_##type##_clamp(magnitude.z, minimum, maximum));		\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_rotated_as_axes(Q3D##Type magnitude, Q3DInt8 rotation)	\
	{									\
	if ((rotation.x % 4) & 1) q_##type##_swap(&magnitude.y, &magnitude.z);	\
	if ((rotation.y % 4) & 1) q_##type##_swap(&magnitude.x, &magnitude.z);	\
	if ((rotation.z % 4) & 1) q_##type##_swap(&magnitude.x, &magnitude.y);	\
										\
	return magnitude;							\
	}


Q_IMPLEMENTATION_NATURAL_3D(UInt8,   uint8  )
Q_IMPLEMENTATION_NATURAL_3D(UInt16,  uint16 )
Q_IMPLEMENTATION_NATURAL_3D(UInt32,  uint32 )
Q_IMPLEMENTATION_NATURAL_3D(UInt64,  uint64 )
Q_IMPLEMENTATION_NATURAL_3D(Int8,    int8   )
Q_IMPLEMENTATION_NATURAL_3D(Int16,   int16  )
Q_IMPLEMENTATION_NATURAL_3D(Int32,   int32  )
Q_IMPLEMENTATION_NATURAL_3D(Int64,   int64  )
Q_IMPLEMENTATION_NATURAL_3D(Float,   float  )
Q_IMPLEMENTATION_NATURAL_3D(Double,  double )
Q_IMPLEMENTATION_NATURAL_3D(LDouble, ldouble)

#define q_3d_value_are_equal(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _are_equal	   )
#define q_3d_value_swap(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _swap		   )
#define q_3d_value_contains(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _contains	   )
#define q_3d_value_add(		      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _add		   )
#define q_3d_value_subtract(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _subtract	   )
#define q_3d_value_multiply(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _multiply	   )
#define q_3d_value_divide(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _divide		   )
#define q_3d_value_dot_product(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _dot_product	   )
#define q_3d_value_cross_product(     TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _cross_product	   )
#define q_3d_value_minimum(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _minimum	   )
#define q_3d_value_maximum(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _maximum	   )
#define q_3d_value_middle(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _middle		   )
#define q_3d_value_fit(		      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _fit		   )
#define q_3d_value_from_scalar(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _from_scalar	   )
#define q_3d_value_is_zero(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _is_zero	   )
#define q_3d_value_inner_sum(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _inner_sum	   )
#define q_3d_value_inner_product(     TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _inner_product	   )
#define q_3d_value_inner_minimum(     TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _inner_minimum	   )
#define q_3d_value_inner_maximum(     TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _inner_maximum	   )
#define q_3d_value_inner_middle(      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _inner_middle	   )
#define q_3d_value_squared_length(    TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _squared_length	   )
#define q_3d_value_add_scalar(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _add_scalar	   )
#define q_3d_value_subtract_scalar(   TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _subtract_scalar   )
#define q_3d_value_multiply_by_scalar(TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _multiply_by_scalar)
#define q_3d_value_divide_by_scalar(  TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _divide_by_scalar  )
#define q_3d_value_clamp(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _clamp		   )
#define q_3d_value_cube_clamp(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _cube_clamp	   )
#define q_3d_value_rotated_as_axes(   TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _rotated_as_axes   )


/* MARK: - Operations for integer and real types */


#define Q_IMPLEMENTATION_INTEGER_3D(Type, type)				\
									\
									\
Q_INLINE Q3D##Type q_3d_##type##_negative(Q3D##Type magnitude)		\
	{return q_3d_##type(-magnitude.x, -magnitude.y, -magnitude.z);}	\
									\
									\
Q_INLINE Q3D##Type q_3d_##type##_absolute(Q3D##Type magnitude)		\
	{								\
	return q_3d_##type						\
		(q_##type##_absolute(magnitude.x),			\
		 q_##type##_absolute(magnitude.y),			\
		 q_##type##_absolute(magnitude.z));			\
	}


Q_IMPLEMENTATION_INTEGER_3D(Int8,    int8   )
Q_IMPLEMENTATION_INTEGER_3D(Int16,   int16  )
Q_IMPLEMENTATION_INTEGER_3D(Int32,   int32  )
Q_IMPLEMENTATION_INTEGER_3D(Int64,   int64  )
Q_IMPLEMENTATION_INTEGER_3D(Float,   float  )
Q_IMPLEMENTATION_INTEGER_3D(Double,  double )
Q_IMPLEMENTATION_INTEGER_3D(LDouble, ldouble)

#define q_3d_value_negative(TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _negative)
#define q_3d_value_absolute(TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _absolute)


/* MARK: - Operations for real types only */


#define Q_IMPLEMENTATION_REAL_3D(Type, type, _, epsilon)			\
										\
										\
Q_INLINE qboolean q_3d_##type##_are_almost_equal(Q3D##Type a, Q3D##Type b)	\
	{									\
	return	q_##type##_are_almost_equal(a.x, b.x) &&			\
		q_##type##_are_almost_equal(a.y, b.y) &&			\
		q_##type##_are_almost_equal(a.z, b.z);				\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_are_perpendicular(Q3D##Type a, Q3D##Type b)	\
	{									\
	return	q_##type##_absolute(q_3d_##type##_dot_product(a, b))		\
		<= epsilon;							\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_lerp(Q3D##Type a, Q3D##Type b, q##type alpha)	\
	{									\
	return q_3d_##type							\
		(q_##type##_lerp(a.x, b.x, alpha),				\
		 q_##type##_lerp(a.y, b.y, alpha),				\
		 q_##type##_lerp(a.z, b.z, alpha));				\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_is_near_zero(Q3D##Type magnitude)		\
	{									\
	return	q_##type##_is_near_zero(magnitude.x) &&				\
		q_##type##_is_near_zero(magnitude.y) &&				\
		q_##type##_is_near_zero(magnitude.z);				\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_is_nan(Q3D##Type magnitude)			\
	{									\
	return	!(magnitude.x == magnitude.x) &&				\
		!(magnitude.y == magnitude.y) &&				\
		!(magnitude.z == magnitude.z);					\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_has_nan(Q3D##Type magnitude)			\
	{									\
	return	!(magnitude.x == magnitude.x) ||				\
		!(magnitude.y == magnitude.y) ||				\
		!(magnitude.z == magnitude.z);					\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_reciprocal(Q3D##Type magnitude)		\
	{									\
	return q_3d_##type							\
		(_(1.0) / magnitude.x,						\
		 _(1.0) / magnitude.y,						\
		 _(1.0) / magnitude.z);						\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_cube_clamp_01(Q3D##Type magnitude)		\
	{									\
	return q_3d_##type							\
		(q_##type##_clamp_01(magnitude.x),				\
		 q_##type##_clamp_01(magnitude.y),				\
		 q_##type##_clamp_01(magnitude.z));				\
	}


Q_IMPLEMENTATION_REAL_3D(Float,	  float,   Q_FLOAT,   Q_FLOAT_EPSILON  )
Q_IMPLEMENTATION_REAL_3D(Double,  double,  Q_DOUBLE,  Q_DOUBLE_EPSILON )
Q_IMPLEMENTATION_REAL_3D(LDouble, ldouble, Q_LDOUBLE, Q_LDOUBLE_EPSILON)


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_3d_are_equal	       q_3d_float_are_equal
#	define q_3d_are_almost_equal   q_3d_float_are_almost_equal
#	define q_3d_are_perpendicular  q_3d_float_are_perpendicular
#	define q_3d_swap	       q_3d_float_swap
#	define q_3d_contains	       q_3d_float_contains
#	define q_3d_add		       q_3d_float_add
#	define q_3d_subtract	       q_3d_float_subtract
#	define q_3d_multiply	       q_3d_float_multiply
#	define q_3d_divide	       q_3d_float_divide
#	define q_3d_dot_product        q_3d_float_dot_product
#	define q_3d_cross_product      q_3d_float_cross_product
#	define q_3d_minimum	       q_3d_float_minimum
#	define q_3d_maximum	       q_3d_float_maximum
#	define q_3d_middle	       q_3d_float_middle
#	define q_3d_fit		       q_3d_float_fit
#	define q_3d_lerp	       q_3d_float_lerp
#	define q_3d_from_scalar        q_3d_float_from_scalar
#	define q_3d_is_zero	       q_3d_float_is_zero
#	define q_3d_is_near_zero       q_3d_float_is_near_zero
#	define q_3d_is_nan	       q_3d_float_is_nan
#	define q_3d_has_nan	       q_3d_float_has_nan
#	define q_3d_negative	       q_3d_float_negative
#	define q_3d_absolute	       q_3d_float_absolute
#	define q_3d_reciprocal	       q_3d_float_reciprocal
#	define q_3d_inner_sum	       q_3d_float_inner_sum
#	define q_3d_inner_product      q_3d_float_inner_product
#	define q_3d_inner_minimum      q_3d_float_inner_minimum
#	define q_3d_inner_maximum      q_3d_float_inner_maximum
#	define q_3d_inner_middle       q_3d_float_inner_middle
#	define q_3d_squared_length     q_3d_float_squared_length
#	define q_3d_add_scalar	       q_3d_float_add_scalar
#	define q_3d_subtract_scalar    q_3d_float_subtract_scalar
#	define q_3d_multiply_by_scalar q_3d_float_multiply_by_scalar
#	define q_3d_divide_by_scalar   q_3d_float_divide_by_scalar
#	define q_3d_clamp	       q_3d_float_clamp
#	define q_3d_cube_clamp	       q_3d_float_cube_clamp
#	define q_3d_cube_clamp_01      q_3d_float_cube_clamp_01
#	define q_3d_rotated_as_axes    q_3d_float_rotated_as_axes

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_3d_are_equal	       q_3d_ldouble_are_equal
#	define q_3d_are_almost_equal   q_3d_ldouble_are_almost_equal
#	define q_3d_are_perpendicular  q_3d_ldouble_are_perpendicular
#	define q_3d_swap	       q_3d_ldouble_swap
#	define q_3d_contains	       q_3d_ldouble_contains
#	define q_3d_add		       q_3d_ldouble_add
#	define q_3d_subtract	       q_3d_ldouble_subtract
#	define q_3d_multiply	       q_3d_ldouble_multiply
#	define q_3d_divide	       q_3d_ldouble_divide
#	define q_3d_dot_product        q_3d_ldouble_dot_product
#	define q_3d_cross_product      q_3d_ldouble_cross_product
#	define q_3d_minimum	       q_3d_ldouble_minimum
#	define q_3d_maximum	       q_3d_ldouble_maximum
#	define q_3d_middle	       q_3d_ldouble_middle
#	define q_3d_fit		       q_3d_ldouble_fit
#	define q_3d_lerp	       q_3d_ldouble_lerp
#	define q_3d_from_scalar        q_3d_ldouble_from_scalar
#	define q_3d_is_zero	       q_3d_ldouble_is_zero
#	define q_3d_is_near_zero       q_3d_ldouble_is_near_zero
#	define q_3d_is_nan	       q_3d_ldouble_is_nan
#	define q_3d_has_nan	       q_3d_ldouble_has_nan
#	define q_3d_negative	       q_3d_ldouble_negative
#	define q_3d_absolute	       q_3d_ldouble_absolute
#	define q_3d_reciprocal	       q_3d_ldouble_reciprocal
#	define q_3d_inner_sum	       q_3d_ldouble_inner_sum
#	define q_3d_inner_product      q_3d_ldouble_inner_product
#	define q_3d_inner_minimum      q_3d_ldouble_inner_minimum
#	define q_3d_inner_maximum      q_3d_ldouble_inner_maximum
#	define q_3d_inner_middle       q_3d_ldouble_inner_middle
#	define q_3d_squared_length     q_3d_ldouble_squared_length
#	define q_3d_add_scalar	       q_3d_ldouble_add_scalar
#	define q_3d_subtract_scalar    q_3d_ldouble_subtract_scalar
#	define q_3d_multiply_by_scalar q_3d_ldouble_multiply_by_scalar
#	define q_3d_divide_by_scalar   q_3d_ldouble_divide_by_scalar
#	define q_3d_clamp	       q_3d_ldouble_clamp
#	define q_3d_cube_clamp	       q_3d_ldouble_cube_clamp
#	define q_3d_cube_clamp_01      q_3d_ldouble_cube_clamp_01
#	define q_3d_rotated_as_axes    q_3d_ldouble_rotated_as_axes

#else

#	define q_3d_are_equal	       q_3d_double_are_equal
#	define q_3d_are_almost_equal   q_3d_double_are_almost_equal
#	define q_3d_are_perpendicular  q_3d_double_are_perpendicular
#	define q_3d_swap	       q_3d_double_swap
#	define q_3d_contains	       q_3d_double_contains
#	define q_3d_add		       q_3d_double_add
#	define q_3d_subtract	       q_3d_double_subtract
#	define q_3d_multiply	       q_3d_double_multiply
#	define q_3d_divide	       q_3d_double_divide
#	define q_3d_dot_product        q_3d_double_dot_product
#	define q_3d_cross_product      q_3d_double_cross_product
#	define q_3d_minimum	       q_3d_double_minimum
#	define q_3d_maximum	       q_3d_double_maximum
#	define q_3d_middle	       q_3d_double_middle
#	define q_3d_fit		       q_3d_double_fit
#	define q_3d_lerp	       q_3d_double_lerp
#	define q_3d_from_scalar        q_3d_double_from_scalar
#	define q_3d_is_zero	       q_3d_double_is_zero
#	define q_3d_is_near_zero       q_3d_double_is_near_zero
#	define q_3d_is_nan	       q_3d_double_is_nan
#	define q_3d_has_nan	       q_3d_double_has_nan
#	define q_3d_negative	       q_3d_double_negative
#	define q_3d_absolute	       q_3d_double_absolute
#	define q_3d_reciprocal	       q_3d_double_reciprocal
#	define q_3d_inner_sum	       q_3d_double_inner_sum
#	define q_3d_inner_product      q_3d_double_inner_product
#	define q_3d_inner_minimum      q_3d_double_inner_minimum
#	define q_3d_inner_maximum      q_3d_double_inner_maximum
#	define q_3d_inner_middle       q_3d_double_inner_middle
#	define q_3d_squared_length     q_3d_double_squared_length
#	define q_3d_add_scalar	       q_3d_double_add_scalar
#	define q_3d_subtract_scalar    q_3d_double_subtract_scalar
#	define q_3d_multiply_by_scalar q_3d_double_multiply_by_scalar
#	define q_3d_divide_by_scalar   q_3d_double_divide_by_scalar
#	define q_3d_clamp	       q_3d_double_clamp
#	define q_3d_cube_clamp	       q_3d_double_cube_clamp
#	define q_3d_cube_clamp_01      q_3d_double_cube_clamp_01
#	define q_3d_rotated_as_axes    q_3d_double_rotated_as_axes

#endif

#endif /* __Q_functions_base_Q3D_H__ */
