/* Q API - functions/base/Q2D.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_base_Q2D_H__
#define __Q_functions_base_Q2D_H__

#include <Q/functions/base/value.h>


/* MARK: - Operations for natural, integer and real types */


#if Q_C_HAS(COMPOUND_LITERAL)

#	define q_2d_uint8(  x, y) ((Q2DUInt8  ){x, y})
#	define q_2d_uint16( x, y) ((Q2DUInt16 ){x, y})
#	define q_2d_uint32( x, y) ((Q2DUInt32 ){x, y})
#	define q_2d_uint64( x, y) ((Q2DUInt64 ){x, y})
#	define q_2d_int8(   x, y) ((Q2DInt8   ){x, y})
#	define q_2d_int16(  x, y) ((Q2DInt16  ){x, y})
#	define q_2d_int32(  x, y) ((Q2DInt32  ){x, y})
#	define q_2d_int64(  x, y) ((Q2DInt64  ){x, y})
#	define q_2d_float(  x, y) ((Q2DFloat  ){x, y})
#	define q_2d_double( x, y) ((Q2DDouble ){x, y})
#	define q_2d_ldouble(x, y) ((Q2DLDouble){x, y})

#	define Q_2D_NEW(Type, type)

#else

#	define Q_2D_NEW(Type, type)				  \
								  \
	Q_INLINE Q2D##Type q_2d_##type(q##type x, q##type y)	  \
		{Q2D##Type magnitude = {x, y}; return magnitude;}

#endif

#define q_2d_uint8_zero   q_2d_uint8  (0, 0)
#define q_2d_uint16_zero  q_2d_uint16 (0, 0)
#define q_2d_uint32_zero  q_2d_uint32 (0, 0)
#define q_2d_uint64_zero  q_2d_uint64 (0, 0)
#define q_2d_int8_zero	  q_2d_int8   (0, 0)
#define q_2d_int16_zero   q_2d_int16  (0, 0)
#define q_2d_int32_zero   q_2d_int32  (0, 0)
#define q_2d_int64_zero   q_2d_int64  (0, 0)
#define q_2d_float_zero   q_2d_float  (0.0F, 0.0F)
#define q_2d_double_zero  q_2d_double (0.0,  0.0 )
#define q_2d_ldouble_zero q_2d_ldouble(0.0L, 0.0L)


#define Q_IMPLEMENTATION_NATURAL_2D(Type, type)					\
										\
Q_2D_NEW(Type, type)								\
										\
										\
Q_INLINE									\
qboolean q_2d_##type##_are_equal(Q2D##Type a, Q2D##Type b)			\
	{return a.x == b.x && a.y == b.y;}					\
										\
										\
Q_INLINE									\
void q_##2d_##type##_swap(Q2D##Type *a, Q2D##Type *b)				\
	{									\
	Q2D##Type t = *a;							\
										\
	*a = *b;								\
	*b = t;									\
	}									\
										\
										\
Q_INLINE									\
qboolean q_2d_##type##_contains(Q2D##Type a, Q2D##Type b)			\
	{return b.x <= a.x && b.y <= a.y;}					\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_add(Q2D##Type a, Q2D##Type b)				\
	{return q_2d_##type(a.x + b.x, a.y + b.y);}				\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_subtract(Q2D##Type a, Q2D##Type b)			\
	{return q_2d_##type(a.x - b.x, a.y - b.y);}				\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_multiply(Q2D##Type a, Q2D##Type b)			\
	{return q_2d_##type(a.x * b.x, a.y * b.y);}				\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_divide(Q2D##Type a, Q2D##Type b)			\
	{return q_2d_##type(a.x / b.x, a.y / b.y);}				\
										\
										\
Q_INLINE									\
q##type q_2d_##type##_dot_product(Q2D##Type a, Q2D##Type b)			\
	{return a.x * b.x + a.y * b.y;}						\
										\
										\
Q_INLINE /* Area of the parallelogram between two vectors (OA and OB) */	\
q##type q_2d_##type##_cross_product(Q2D##Type a, Q2D##Type b)			\
	{return a.x * b.y - a.y * b.x;}						\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_minimum(Q2D##Type a, Q2D##Type b)			\
	{									\
	return q_2d_##type							\
		(q_##type##_minimum(a.x, b.x), q_##type##_minimum(a.y, b.y));	\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_maximum(Q2D##Type a, Q2D##Type b)			\
	{									\
	return q_2d_##type							\
		(q_##type##_maximum(a.x, b.x), q_##type##_maximum(a.y, b.y));	\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_middle(Q2D##Type a, Q2D##Type b)			\
	{									\
	return q_2d_##type							\
		((a.x + b.x) / (q##type)2, (a.y + b.y) / (q##type)2);		\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_fit(Q2D##Type a, Q2D##Type b)				\
	{									\
	return a.y / a.x > b.y / b.x						\
		? q_2d_##type(a.x * b.y / a.y, b.y)				\
		: q_2d_##type(b.x, a.y * b.x / a.x);				\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_from_scalar(q##type scalar)				\
	{return q_2d_##type(scalar, scalar);}					\
										\
										\
Q_INLINE									\
qboolean q_2d_##type##_is_zero(Q2D##Type magnitude)				\
	{return magnitude.x == (q##type)0 && magnitude.y == (q##type)0;}	\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_inverse(Q2D##Type magnitude)				\
	{return q_2d_##type(magnitude.y, magnitude.x);}				\
										\
										\
Q_INLINE									\
q##type q_2d_##type##_inner_sum(Q2D##Type magnitude)				\
	{return magnitude.x + magnitude.y;}					\
										\
										\
Q_INLINE									\
q##type q_2d_##type##_inner_product(Q2D##Type magnitude)			\
	{return magnitude.x * magnitude.y;}					\
										\
										\
Q_INLINE									\
q##type q_2d_##type##_inner_minimum(Q2D##Type magnitude)			\
	{return q_##type##_minimum(magnitude.x, magnitude.y);}			\
										\
										\
Q_INLINE									\
q##type q_2d_##type##_inner_maximum(Q2D##Type magnitude)			\
	{return q_##type##_maximum(magnitude.x, magnitude.y);}			\
										\
										\
Q_INLINE									\
q##type q_2d_##type##_inner_middle(Q2D##Type magnitude)				\
	{return (magnitude.x + magnitude.y) / (q##type)2;}			\
										\
										\
Q_INLINE									\
q##type q_2d_##type##_squared_length(Q2D##Type magnitude)			\
	{return magnitude.x * magnitude.x + magnitude.y * magnitude.y;}		\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_add_scalar(Q2D##Type magnitude, q##type scalar)		\
	{return q_2d_##type(magnitude.x + scalar, magnitude.y + scalar);}	\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_subtract_scalar(Q2D##Type magnitude, q##type scalar)	\
	{return q_2d_##type(magnitude.x - scalar, magnitude.y - scalar);}	\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_multiply_by_scalar(Q2D##Type magnitude, q##type scalar)	\
	{return q_2d_##type(magnitude.x * scalar, magnitude.y * scalar);}	\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_divide_by_scalar(Q2D##Type magnitude, q##type scalar)	\
	{return q_2d_##type(magnitude.x / scalar, magnitude.y / scalar);}	\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_clamp(							\
	Q2D##Type magnitude,							\
	Q2D##Type minimum,							\
	Q2D##Type maximum							\
)										\
	{									\
	return q_2d_##type							\
		(q_##type##_clamp(magnitude.x, minimum.x, maximum.x),		\
		 q_##type##_clamp(magnitude.y, minimum.y, maximum.y));		\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_square_clamp(						\
	Q2D##Type magnitude,							\
	q##type	  minimum,							\
	q##type	  maximum							\
)										\
	{									\
	return q_2d_##type							\
		(q_##type##_clamp(magnitude.x, minimum, maximum),		\
		 q_##type##_clamp(magnitude.y, minimum, maximum));		\
	}


Q_IMPLEMENTATION_NATURAL_2D(UInt8,   uint8  )
Q_IMPLEMENTATION_NATURAL_2D(UInt16,  uint16 )
Q_IMPLEMENTATION_NATURAL_2D(UInt32,  uint32 )
Q_IMPLEMENTATION_NATURAL_2D(UInt64,  uint64 )
Q_IMPLEMENTATION_NATURAL_2D(Int8,    int8   )
Q_IMPLEMENTATION_NATURAL_2D(Int16,   int16  )
Q_IMPLEMENTATION_NATURAL_2D(Int32,   int32  )
Q_IMPLEMENTATION_NATURAL_2D(Int64,   int64  )
Q_IMPLEMENTATION_NATURAL_2D(Float,   float  )
Q_IMPLEMENTATION_NATURAL_2D(Double,  double )
Q_IMPLEMENTATION_NATURAL_2D(LDouble, ldouble)
#undef Q_2D_NEW

#define q_2d_value(		      TYPE) Q_JOIN_2(q_2d_, Q_##TYPE##_FIXED_TYPE_name			   )
#define q_2d_value_zero(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _zero		   )
#define q_2d_value_are_equal(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _are_equal	   )
#define q_2d_value_swap(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _swap		   )
#define q_2d_value_contains(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _contains	   )
#define q_2d_value_add(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _add		   )
#define q_2d_value_subtract(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _subtract	   )
#define q_2d_value_multiply(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _multiply	   )
#define q_2d_value_divide(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _divide		   )
#define q_2d_value_dot_product(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _dot_product	   )
#define q_2d_value_cross_product(     TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _cross_product	   )
#define q_2d_value_minimum(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _minimum	   )
#define q_2d_value_maximum(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _maximum	   )
#define q_2d_value_middle(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _middle		   )
#define q_2d_value_fit(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _fit		   )
#define q_2d_value_from_scalar(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _from_scalar	   )
#define q_2d_value_is_zero(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _is_zero	   )
#define q_2d_value_inverse(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inverse	   )
#define q_2d_value_inner_sum(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inner_sum	   )
#define q_2d_value_inner_product(     TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inner_product	   )
#define q_2d_value_inner_minimum(     TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inner_minimum	   )
#define q_2d_value_inner_maximum(     TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inner_maximum	   )
#define q_2d_value_inner_middle(      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inner_middle	   )
#define q_2d_value_squared_length(    TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _squared_length	   )
#define q_2d_value_add_scalar(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _add_scalar	   )
#define q_2d_value_subtract_scalar(   TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _subtract_scalar   )
#define q_2d_value_multiply_by_scalar(TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _multiply_by_scalar)
#define q_2d_value_divide_by_scalar(  TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _divide_by_scalar  )
#define q_2d_value_clamp(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _clamp		   )
#define q_2d_value_square_clamp(      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _square_clamp	   )


/* MARK: - Operations for integer and real types */


#define Q_IMPLEMENTATION_INTEGER_2D(Type, type)			\
								\
								\
Q_INLINE							\
Q2D##Type q_2d_##type##_negative(Q2D##Type magnitude)		\
	{return q_2d_##type(-magnitude.x, -magnitude.y);}	\
								\
								\
Q_INLINE							\
Q2D##Type q_2d_##type##_absolute(Q2D##Type magnitude)		\
	{							\
	return q_2d_##type					\
		(q_##type##_absolute(magnitude.x),		\
		 q_##type##_absolute(magnitude.y));		\
	}


Q_IMPLEMENTATION_INTEGER_2D(Int8,    int8   )
Q_IMPLEMENTATION_INTEGER_2D(Int16,   int16  )
Q_IMPLEMENTATION_INTEGER_2D(Int32,   int32  )
Q_IMPLEMENTATION_INTEGER_2D(Int64,   int64  )
Q_IMPLEMENTATION_INTEGER_2D(Float,   float  )
Q_IMPLEMENTATION_INTEGER_2D(Double,  double )
Q_IMPLEMENTATION_INTEGER_2D(LDouble, ldouble)

#define q_2d_value_negative(TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _negative)
#define q_2d_value_absolute(TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _absolute)


/* MARK: - Operations for real types only */


#define Q_IMPLEMENTATION_REAL_2D(Type, type, _, epsilon)			\
										\
										\
Q_INLINE									\
qboolean q_2d_##type##_are_almost_equal(Q2D##Type a, Q2D##Type b)		\
	{									\
	return	q_##type##_are_almost_equal(a.x, b.x) &&			\
		q_##type##_are_almost_equal(a.y, b.y);				\
	}									\
										\
										\
Q_INLINE									\
qboolean q_2d_##type##_are_perpendicular(Q2D##Type a, Q2D##Type b)		\
	{									\
	return	q_##type##_absolute(q_2d_##type##_dot_product(a, b))		\
		<= epsilon;							\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_lerp(Q2D##Type a, Q2D##Type b, q##type alpha)		\
	{									\
	return q_2d_##type							\
		(q_##type##_lerp(a.x, b.x, alpha),				\
		 q_##type##_lerp(a.y, b.y, alpha));				\
	}									\
										\
										\
Q_INLINE									\
qboolean q_2d_##type##_is_near_zero(Q2D##Type magnitude)			\
	{									\
	return	q_##type##_is_near_zero(magnitude.x) &&				\
		q_##type##_is_near_zero(magnitude.y);				\
	}									\
										\
										\
Q_INLINE									\
qboolean q_2d_##type##_is_nan(Q2D##Type magnitude)				\
	{									\
	return	!(magnitude.x == magnitude.x) &&				\
		!(magnitude.y == magnitude.y);					\
	}									\
										\
										\
Q_INLINE									\
qboolean q_2d_##type##_has_nan(Q2D##Type magnitude)				\
	{									\
	return	!(magnitude.x == magnitude.x) ||				\
		!(magnitude.y == magnitude.y);					\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_reciprocal(Q2D##Type magnitude)				\
	{return q_2d_##type(_(1.0) / magnitude.x, _(1.0) / magnitude.y);}	\
										\
										\
Q_INLINE									\
Q2D##Type q_2d_##type##_square_clamp_01(Q2D##Type magnitude)			\
	{									\
	return q_2d_##type							\
		(q_##type##_clamp_01(magnitude.x),				\
		 q_##type##_clamp_01(magnitude.y));				\
	}


Q_IMPLEMENTATION_REAL_2D(Float,	  float,   Q_FLOAT,   Q_FLOAT_EPSILON  )
Q_IMPLEMENTATION_REAL_2D(Double,  double,  Q_DOUBLE,  Q_DOUBLE_EPSILON )
Q_IMPLEMENTATION_REAL_2D(LDouble, ldouble, Q_LDOUBLE, Q_LDOUBLE_EPSILON)


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_2d		       q_2d_float
#	define q_2d_zero	       q_2d_float_zero
#	define q_2d_are_equal	       q_2d_float_are_equal
#	define q_2d_are_almost_equal   q_2d_float_are_almost_equal
#	define q_2d_are_perpendicular  q_2d_float_are_perpendicular
#	define q_2d_swap	       q_2d_float_swap
#	define q_2d_contains	       q_2d_float_contains
#	define q_2d_add		       q_2d_float_add
#	define q_2d_subtract	       q_2d_float_subtract
#	define q_2d_multiply	       q_2d_float_multiply
#	define q_2d_divide	       q_2d_float_divide
#	define q_2d_dot_product        q_2d_float_dot_product
#	define q_2d_cross_product      q_2d_float_cross_product
#	define q_2d_minimum	       q_2d_float_minimum
#	define q_2d_maximum	       q_2d_float_maximum
#	define q_2d_middle	       q_2d_float_middle
#	define q_2d_fit		       q_2d_float_fit
#	define q_2d_lerp	       q_2d_float_lerp
#	define q_2d_from_scalar        q_2d_float_from_scalar
#	define q_2d_is_zero	       q_2d_float_is_zero
#	define q_2d_is_near_zero       q_2d_float_is_near_zero
#	define q_2d_is_nan	       q_2d_float_is_nan
#	define q_2d_has_nan	       q_2d_float_has_nan
#	define q_2d_negative	       q_2d_float_negative
#	define q_2d_absolute	       q_2d_float_absolute
#	define q_2d_reciprocal	       q_2d_float_reciprocal
#	define q_2d_inverse	       q_2d_float_inverse
#	define q_2d_inner_sum	       q_2d_float_inner_sum
#	define q_2d_inner_product      q_2d_float_inner_product
#	define q_2d_inner_minimum      q_2d_float_inner_minimum
#	define q_2d_inner_maximum      q_2d_float_inner_maximum
#	define q_2d_inner_middle       q_2d_float_inner_middle
#	define q_2d_squared_length     q_2d_float_squared_length
#	define q_2d_add_scalar	       q_2d_float_add_scalar
#	define q_2d_subtract_scalar    q_2d_float_subtract_scalar
#	define q_2d_multiply_by_scalar q_2d_float_multiply_by_scalar
#	define q_2d_divide_by_scalar   q_2d_float_divide_by_scalar
#	define q_2d_clamp	       q_2d_float_clamp
#	define q_2d_square_clamp       q_2d_float_square_clamp
#	define q_2d_square_clamp_01    q_2d_float_square_clamp_01

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_2d		       q_2d_ldouble
#	define q_2d_zero	       q_2d_ldouble_zero
#	define q_2d_are_equal	       q_2d_ldouble_are_equal
#	define q_2d_are_almost_equal   q_2d_ldouble_are_almost_equal
#	define q_2d_are_perpendicular  q_2d_ldouble_are_perpendicular
#	define q_2d_swap	       q_2d_ldouble_swap
#	define q_2d_contains	       q_2d_ldouble_contains
#	define q_2d_add		       q_2d_ldouble_add
#	define q_2d_subtract	       q_2d_ldouble_subtract
#	define q_2d_multiply	       q_2d_ldouble_multiply
#	define q_2d_divide	       q_2d_ldouble_divide
#	define q_2d_dot_product        q_2d_ldouble_dot_product
#	define q_2d_cross_product      q_2d_ldouble_cross_product
#	define q_2d_minimum	       q_2d_ldouble_minimum
#	define q_2d_maximum	       q_2d_ldouble_maximum
#	define q_2d_middle	       q_2d_ldouble_middle
#	define q_2d_fit		       q_2d_ldouble_fit
#	define q_2d_lerp	       q_2d_ldouble_lerp
#	define q_2d_from_scalar        q_2d_ldouble_from_scalar
#	define q_2d_is_zero	       q_2d_ldouble_is_zero
#	define q_2d_is_near_zero       q_2d_ldouble_is_near_zero
#	define q_2d_is_nan	       q_2d_ldouble_is_nan
#	define q_2d_has_nan	       q_2d_ldouble_has_nan
#	define q_2d_negative	       q_2d_ldouble_negative
#	define q_2d_absolute	       q_2d_ldouble_absolute
#	define q_2d_reciprocal	       q_2d_ldouble_reciprocal
#	define q_2d_inverse	       q_2d_ldouble_inverse
#	define q_2d_inner_sum	       q_2d_ldouble_inner_sum
#	define q_2d_inner_product      q_2d_ldouble_inner_product
#	define q_2d_inner_minimum      q_2d_ldouble_inner_minimum
#	define q_2d_inner_maximum      q_2d_ldouble_inner_maximum
#	define q_2d_inner_middle       q_2d_ldouble_inner_middle
#	define q_2d_squared_length     q_2d_ldouble_squared_length
#	define q_2d_add_scalar	       q_2d_ldouble_add_scalar
#	define q_2d_subtract_scalar    q_2d_ldouble_subtract_scalar
#	define q_2d_multiply_by_scalar q_2d_ldouble_multiply_by_scalar
#	define q_2d_divide_by_scalar   q_2d_ldouble_divide_by_scalar
#	define q_2d_clamp	       q_2d_ldouble_clamp
#	define q_2d_square_clamp       q_2d_ldouble_square_clamp
#	define q_2d_square_clamp_01    q_2d_ldouble_square_clamp_01

#else

#	define q_2d		       q_2d_double
#	define q_2d_zero	       q_2d_double_zero
#	define q_2d_are_equal	       q_2d_double_are_equal
#	define q_2d_are_almost_equal   q_2d_double_are_almost_equal
#	define q_2d_are_perpendicular  q_2d_double_are_perpendicular
#	define q_2d_swap	       q_2d_double_swap
#	define q_2d_contains	       q_2d_double_contains
#	define q_2d_add		       q_2d_double_add
#	define q_2d_subtract	       q_2d_double_subtract
#	define q_2d_multiply	       q_2d_double_multiply
#	define q_2d_divide	       q_2d_double_divide
#	define q_2d_dot_product        q_2d_double_dot_product
#	define q_2d_cross_product      q_2d_double_cross_product
#	define q_2d_minimum	       q_2d_double_minimum
#	define q_2d_maximum	       q_2d_double_maximum
#	define q_2d_middle	       q_2d_double_middle
#	define q_2d_fit		       q_2d_double_fit
#	define q_2d_lerp	       q_2d_double_lerp
#	define q_2d_from_scalar        q_2d_double_from_scalar
#	define q_2d_is_zero	       q_2d_double_is_zero
#	define q_2d_is_near_zero       q_2d_double_is_near_zero
#	define q_2d_is_nan	       q_2d_double_is_nan
#	define q_2d_has_nan	       q_2d_double_has_nan
#	define q_2d_negative	       q_2d_double_negative
#	define q_2d_absolute	       q_2d_double_absolute
#	define q_2d_reciprocal	       q_2d_double_reciprocal
#	define q_2d_inverse	       q_2d_double_inverse
#	define q_2d_inner_sum	       q_2d_double_inner_sum
#	define q_2d_inner_product      q_2d_double_inner_product
#	define q_2d_inner_minimum      q_2d_double_inner_minimum
#	define q_2d_inner_maximum      q_2d_double_inner_maximum
#	define q_2d_inner_middle       q_2d_double_inner_middle
#	define q_2d_squared_length     q_2d_double_squared_length
#	define q_2d_add_scalar	       q_2d_double_add_scalar
#	define q_2d_subtract_scalar    q_2d_double_subtract_scalar
#	define q_2d_multiply_by_scalar q_2d_double_multiply_by_scalar
#	define q_2d_divide_by_scalar   q_2d_double_divide_by_scalar
#	define q_2d_clamp	       q_2d_double_clamp
#	define q_2d_square_clamp       q_2d_double_square_clamp
#	define q_2d_square_clamp_01    q_2d_double_square_clamp_01

#endif

#endif /* __Q_functions_base_Q2D_H__ */
