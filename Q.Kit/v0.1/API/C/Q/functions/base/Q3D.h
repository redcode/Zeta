/* Q Kit C API - functions/base/Q3D.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_base_Q3D_H__
#define __Q_functions_base_Q3D_H__

#include <Q/functions/base/constructors.h>
#include <Q/functions/base/value.h>


/* MARK: - Operations for natural, integer and real types */


#define Q_IMPLEMENTATION_3D_NATURAL(Type, type)					\
										\
										\
Q_INLINE qboolean q_3d_##type##_are_equal(Q3D##Type a, Q3D##Type b)		\
	{return a.x == b.x && a.y == b.y && a.z == b.z;}			\
										\
										\
Q_INLINE void q_3d_##type##_swap(Q3D##Type *a, Q3D##Type *b)			\
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
Q_INLINE Q3D##Type q_3d_##type##_add_3(Q3D##Type a, Q3D##Type b, Q3D##Type c)	\
	{									\
	return q_3d_##type							\
		(a.x + b.x + c.x, a.y + b.y + c.y, a.z + b.z + c.z);		\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_add_4(						\
	Q3D##Type a,								\
	Q3D##Type b,								\
	Q3D##Type c,								\
	Q3D##Type d								\
)										\
	{									\
	return q_3d_##type							\
		(a.x + b.x + c.x + d.x,						\
		 a.y + b.y + c.y + d.y,						\
		 a.z + b.z + c.z + d.z);					\
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
Q_INLINE Q3D##Type q_3d_##type##_subtract(Q3D##Type a, Q3D##Type b)		\
	{return q_3d_##type(a.x - b.x, a.y - b.y, a.z - b.z);}			\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_subtract_3(Q3D##Type a, Q3D##Type b, Q3D##Type c)	\
	{									\
	return q_3d_##type							\
		(a.x - b.x - c.x, a.y - b.y - c.y, a.z - b.z - c.z);		\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_subtract_4(					\
	Q3D##Type a,								\
	Q3D##Type b,								\
	Q3D##Type c,								\
	Q3D##Type d								\
)										\
	{									\
	return q_3d_##type							\
		(a.x - b.x - c.x - d.x,						\
		 a.y - b.y - c.y - d.y,						\
		 a.z - b.z - c.z - d.z);					\
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
Q_INLINE Q3D##Type q_3d_##type##_multiply(Q3D##Type a, Q3D##Type b)		\
	{return q_3d_##type(a.x * b.x, a.y * b.y, a.z * b.z);}			\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_multiply_3(Q3D##Type a, Q3D##Type b, Q3D##Type c)	\
	{									\
	return q_3d_##type							\
		(a.x * b.x * c.x, a.y * b.y * c.y, a.z * b.z * c.z);}		\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_multiply_4(					\
	Q3D##Type a,								\
	Q3D##Type b,								\
	Q3D##Type c,								\
	Q3D##Type d								\
)										\
	{									\
	return q_3d_##type							\
		(a.x * b.x * c.x * d.x,						\
		 a.y * b.y * c.y * d.y,						\
		 a.z * b.z * c.z * d.z);					\
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
Q_INLINE Q3D##Type q_3d_##type##_divide(Q3D##Type a, Q3D##Type b)		\
	{return q_3d_##type(a.x / b.x, a.y / b.y, a.z / b.z);}			\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_divide_3(Q3D##Type a, Q3D##Type b, Q3D##Type c)		\
	{									\
	return q_3d_##type							\
		(a.x / b.x / c.x, a.y / b.y / c.y, a.z / b.z / c.z);		\
	}									\
										\
										\
Q_INLINE Q3D##Type q_3d_##type##_divide_4(					\
	Q3D##Type a,								\
	Q3D##Type b,								\
	Q3D##Type c,								\
	Q3D##Type d								\
)										\
	{									\
	return q_3d_##type							\
		(a.x / b.x / c.x / d.x,						\
		 a.y / b.y / c.y / d.y,						\
		 a.z / b.z / c.z / d.z);					\
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
Q_INLINE qboolean q_3d_##type##_has_zero(Q3D##Type magnitude)			\
	{									\
	return	magnitude.x == (q##type)0 ||					\
		magnitude.y == (q##type)0 ||					\
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


Q_IMPLEMENTATION_3D_NATURAL(UInt8,   uint8  )
Q_IMPLEMENTATION_3D_NATURAL(UInt16,  uint16 )
Q_IMPLEMENTATION_3D_NATURAL(UInt32,  uint32 )
Q_IMPLEMENTATION_3D_NATURAL(UInt64,  uint64 )
Q_IMPLEMENTATION_3D_NATURAL(Int8,    int8   )
Q_IMPLEMENTATION_3D_NATURAL(Int16,   int16  )
Q_IMPLEMENTATION_3D_NATURAL(Int32,   int32  )
Q_IMPLEMENTATION_3D_NATURAL(Int64,   int64  )
Q_IMPLEMENTATION_3D_NATURAL(Float,   float  )
Q_IMPLEMENTATION_3D_NATURAL(Double,  double )
Q_IMPLEMENTATION_3D_NATURAL(LDouble, ldouble)

#define q_3d_value_are_equal(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _are_equal	   )
#define q_3d_value_swap(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _swap		   )
#define q_3d_value_contains(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _contains	   )
#define q_3d_value_add(		      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _add		   )
#define q_3d_value_add_3(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _add_3		   )
#define q_3d_value_add_4(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _add_4		   )
#define q_3d_value_add_scalar(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _add_scalar	   )
#define q_3d_value_subtract(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _subtract	   )
#define q_3d_value_subtract_3(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _subtract_3	   )
#define q_3d_value_subtract_4(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _subtract_4	   )
#define q_3d_value_subtract_scalar(   TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _subtract_scalar   )
#define q_3d_value_multiply(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _multiply	   )
#define q_3d_value_multiply_3(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _multiply_3	   )
#define q_3d_value_multiply_4(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _multiply_4	   )
#define q_3d_value_multiply_by_scalar(TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _multiply_by_scalar)
#define q_3d_value_divide(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _divide		   )
#define q_3d_value_divide_3(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _divide_3	   )
#define q_3d_value_divide_4(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _divide_4	   )
#define q_3d_value_divide_by_scalar(  TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _divide_by_scalar  )
#define q_3d_value_dot_product(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _dot_product	   )
#define q_3d_value_cross_product(     TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _cross_product	   )
#define q_3d_value_minimum(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _minimum	   )
#define q_3d_value_maximum(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _maximum	   )
#define q_3d_value_middle(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _middle		   )
#define q_3d_value_fit(		      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _fit		   )
#define q_3d_value_from_scalar(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _from_scalar	   )
#define q_3d_value_is_zero(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _is_zero	   )
#define q_3d_value_has_zero(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _has_zero	   )
#define q_3d_value_inner_sum(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _inner_sum	   )
#define q_3d_value_inner_product(     TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _inner_product	   )
#define q_3d_value_inner_minimum(     TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _inner_minimum	   )
#define q_3d_value_inner_maximum(     TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _inner_maximum	   )
#define q_3d_value_inner_middle(      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _inner_middle	   )
#define q_3d_value_squared_length(    TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _squared_length	   )
#define q_3d_value_clamp(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _clamp		   )
#define q_3d_value_cube_clamp(	      TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _cube_clamp	   )
#define q_3d_value_rotated_as_axes(   TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _rotated_as_axes   )


/* MARK: - Operations for integer and real types */


#define Q_IMPLEMENTATION_3D_INTEGER(Type, type)				\
									\
									\
Q_INLINE qboolean q_3d_##type##_is_negative(Q3D##Type magnitude)	\
	{								\
	return	magnitude.x < (q##type)0 &&				\
		magnitude.y < (q##type)0 &&				\
		magnitude.z < (q##type)0;				\
	}								\
									\
									\
Q_INLINE qboolean q_3d_##type##_has_negative(Q3D##Type magnitude)	\
	{								\
	return	magnitude.x < (q##type)0 ||				\
		magnitude.y < (q##type)0 ||				\
		magnitude.z < (q##type)0;				\
	}								\
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


Q_IMPLEMENTATION_3D_INTEGER(Int8,    int8   )
Q_IMPLEMENTATION_3D_INTEGER(Int16,   int16  )
Q_IMPLEMENTATION_3D_INTEGER(Int32,   int32  )
Q_IMPLEMENTATION_3D_INTEGER(Int64,   int64  )
Q_IMPLEMENTATION_3D_INTEGER(Float,   float  )
Q_IMPLEMENTATION_3D_INTEGER(Double,  double )
Q_IMPLEMENTATION_3D_INTEGER(LDouble, ldouble)

#define q_3d_value_is_negative( TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _is_negative )
#define q_3d_value_has_negative(TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _has_negative)
#define q_3d_value_negative(	TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _negative    )
#define q_3d_value_absolute(	TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _absolute    )


/* MARK: - Operations for real types only */


#define Q_IMPLEMENTATION_3D_REAL(Type, type, _, epsilon)			\
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
Q_INLINE Q3D##Type q_3d_##type##_lerp(Q3D##Type a, Q3D##Type b, q##type t)	\
	{									\
	return q_3d_##type							\
		(q_##type##_lerp(a.x, b.x, t),					\
		 q_##type##_lerp(a.y, b.y, t),					\
		 q_##type##_lerp(a.z, b.z, t));					\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_inverse_lerp(Q3D##Type a, Q3D##Type b, q##type t)	\
	{									\
	return q_3d_##type							\
		(q_##type##_inverse_lerp(a.x, b.x, t),				\
		 q_##type##_inverse_lerp(a.y, b.y, t),				\
		 q_##type##_inverse_lerp(a.z, b.z, t));				\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_is_finite(Q3D##Type magnitude)			\
	{									\
	return	q_##type##_is_finite(magnitude.x) &&				\
		q_##type##_is_finite(magnitude.y) &&				\
		q_##type##_is_finite(magnitude.z);				\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_is_infinity(Q3D##Type magnitude)		\
	{									\
	return	q_##type##_is_infinity(magnitude.x) &&				\
		q_##type##_is_infinity(magnitude.y) &&				\
		q_##type##_is_infinity(magnitude.z);				\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_is_nan(Q3D##Type magnitude)			\
	{									\
	return	q_##type##_is_nan(magnitude.x) &&				\
		q_##type##_is_nan(magnitude.y) &&				\
		q_##type##_is_nan(magnitude.z);					\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_is_almost_zero(Q3D##Type magnitude)		\
	{									\
	return	q_##type##_is_almost_zero(magnitude.x) &&			\
		q_##type##_is_almost_zero(magnitude.y) &&			\
		q_##type##_is_almost_zero(magnitude.z);				\
	}									\
										\
										\
										\
Q_INLINE qboolean q_3d_##type##_has_infinity(Q3D##Type magnitude)		\
	{									\
	return	q_##type##_is_infinity(magnitude.x) ||				\
		q_##type##_is_infinity(magnitude.y) ||				\
		q_##type##_is_infinity(magnitude.z);				\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_has_nan(Q3D##Type magnitude)			\
	{									\
	return	q_##type##_is_nan(magnitude.x) ||				\
		q_##type##_is_nan(magnitude.y) ||				\
		q_##type##_is_nan(magnitude.z);					\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_has_almost_zero(Q3D##Type magnitude)		\
	{									\
	return	q_##type##_is_almost_zero(magnitude.x) ||			\
		q_##type##_is_almost_zero(magnitude.y) ||			\
		q_##type##_is_almost_zero(magnitude.z);				\
	}									\
										\
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


Q_IMPLEMENTATION_3D_REAL(Float,	  float,   Q_FLOAT,   Q_FLOAT_EPSILON  )
Q_IMPLEMENTATION_3D_REAL(Double,  double,  Q_DOUBLE,  Q_DOUBLE_EPSILON )
Q_IMPLEMENTATION_3D_REAL(LDouble, ldouble, Q_LDOUBLE, Q_LDOUBLE_EPSILON)


/* MARK: - Default real type definitions */

#define q_3d_are_equal		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _are_equal	   )
#define q_3d_are_almost_equal	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _are_almost_equal  )
#define q_3d_are_perpendicular	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _are_perpendicular )
#define q_3d_swap		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _swap		   )
#define q_3d_contains		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _contains	   )
#define q_3d_add		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _add		   )
#define q_3d_add_3		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _add_3		   )
#define q_3d_add_4		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _add_4		   )
#define q_3d_add_scalar		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _add_scalar	   )
#define q_3d_subtract		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _subtract	   )
#define q_3d_subtract_3		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _subtract_3	   )
#define q_3d_subtract_4		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _subtract_4	   )
#define q_3d_subtract_scalar	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _subtract_scalar   )
#define q_3d_multiply		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _multiply	   )
#define q_3d_multiply_3		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _multiply_3	   )
#define q_3d_multiply_4		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _multiply_4	   )
#define q_3d_multiply_by_scalar	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _multiply_by_scalar)
#define q_3d_divide		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _divide		   )
#define q_3d_divide_3		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _divide_3	   )
#define q_3d_divide_4		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _divide_4	   )
#define q_3d_divide_by_scalar	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _divide_by_scalar  )
#define q_3d_dot_product	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _dot_product	   )
#define q_3d_cross_product	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _cross_product	   )
#define q_3d_minimum		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _minimum	   )
#define q_3d_maximum		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _maximum	   )
#define q_3d_middle		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _middle		   )
#define q_3d_fit		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _fit		   )
#define q_3d_lerp		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _lerp		   )
#define q_3d_from_scalar	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _from_scalar	   )
#define q_3d_is_finite		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _is_finite	   )
#define q_3d_is_infinity	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _is_infinity	   )
#define q_3d_is_nan		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _is_nan		   )
#define q_3d_is_negative	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _is_negative	   )
#define q_3d_is_zero		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _is_zero	   )
#define q_3d_is_almost_zero	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _is_almost_zero	   )
#define q_3d_has_infinity	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _has_infinity	   )
#define q_3d_has_nan		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _has_nan	   )
#define q_3d_has_negative	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _has_negative	   )
#define q_3d_has_zero		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _has_zero	   )
#define q_3d_has_almost_zero	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _has_almost_zero   )
#define q_3d_negative		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _negative	   )
#define q_3d_absolute		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _absolute	   )
#define q_3d_reciprocal		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _reciprocal	   )
#define q_3d_inner_sum		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _inner_sum	   )
#define q_3d_inner_product	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _inner_product	   )
#define q_3d_inner_minimum	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _inner_minimum	   )
#define q_3d_inner_maximum	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _inner_maximum	   )
#define q_3d_inner_middle	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _inner_middle	   )
#define q_3d_squared_length	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _squared_length	   )
#define q_3d_clamp		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _clamp		   )
#define q_3d_cube_clamp		Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _cube_clamp	   )
#define q_3d_cube_clamp_01	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _cube_clamp_01	   )
#define q_3d_rotated_as_axes	Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _rotated_as_axes   )

#endif /* __Q_functions_base_Q3D_H__ */
