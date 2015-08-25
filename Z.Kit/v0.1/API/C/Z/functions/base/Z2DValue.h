/* Z Kit C API - functions/base/Z2DValue.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_Z2DValue_H__
#define __Z_functions_base_Z2DValue_H__

#include <Z/functions/base/constructors.h>
#include <Z/functions/base/value.h>


/* MARK: - Operations for natural, integer and real types */


#define Z_IMPLEMENTATION_2D_NATURAL(Type, type)							\
												\
												\
Z_INLINE zboolean z_2d_##type##_are_equal(Z2D##Type a, Z2D##Type b)				\
	{return a.x == b.x && a.y == b.y;}							\
												\
												\
Z_INLINE void z_2d_##type##_swap(Z2D##Type *a, Z2D##Type *b)					\
	{											\
	Z2D##Type t = *a;									\
												\
	*a = *b; *b = t;									\
	}											\
												\
												\
Z_INLINE zboolean z_2d_##type##_contains(Z2D##Type a, Z2D##Type b)				\
	{return a.x >= b.x && a.y >= b.y;}							\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_add(Z2D##Type a, Z2D##Type b)					\
	{return z_2d_##type(a.x + b.x, a.y + b.y);}						\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_add_3(Z2D##Type a, Z2D##Type b, Z2D##Type c)			\
	{return z_2d_##type(a.x + b.x + c.x, a.y + b.y + c.y);}					\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_add_4(Z2D##Type a, Z2D##Type b, Z2D##Type c, Z2D##Type d)	\
	{return z_2d_##type(a.x + b.x + c.x + d.x, a.y + b.y + c.y + d.y);}			\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_add_scalar(Z2D##Type object, z##type scalar)			\
	{return z_2d_##type(object.x + scalar, object.y + scalar);}				\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_subtract(Z2D##Type a, Z2D##Type b)				\
	{return z_2d_##type(a.x - b.x, a.y - b.y);}						\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_subtract_3(Z2D##Type a, Z2D##Type b, Z2D##Type c)		\
	{return z_2d_##type(a.x - b.x - c.x, a.y - b.y - c.y);}					\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_subtract_4(Z2D##Type a, Z2D##Type b, Z2D##Type c, Z2D##Type d)	\
	{return z_2d_##type(a.x - b.x - c.x - d.x, a.y - b.y - c.y - d.y);}			\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_subtract_scalar(Z2D##Type object, z##type scalar)		\
	{return z_2d_##type(object.x - scalar, object.y - scalar);}				\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_multiply(Z2D##Type a, Z2D##Type b)				\
	{return z_2d_##type(a.x * b.x, a.y * b.y);}						\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_multiply_3(Z2D##Type a, Z2D##Type b, Z2D##Type c)		\
	{return z_2d_##type(a.x * b.x * c.x, a.y * b.y * c.y);}					\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_multiply_4(Z2D##Type a, Z2D##Type b, Z2D##Type c, Z2D##Type d)	\
	{return z_2d_##type(a.x * b.x * c.x * d.x, a.y * b.y * c.y * d.y);}			\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_multiply_by_scalar(Z2D##Type object, z##type scalar)		\
	{return z_2d_##type(object.x * scalar, object.y * scalar);}				\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_divide(Z2D##Type a, Z2D##Type b)				\
	{return z_2d_##type(a.x / b.x, a.y / b.y);}						\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_divide_3(Z2D##Type a, Z2D##Type b, Z2D##Type c)		\
	{return z_2d_##type(a.x / b.x / c.x, a.y / b.y / c.x);}					\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_divide_4(Z2D##Type a, Z2D##Type b, Z2D##Type c, Z2D##Type d)	\
	{return z_2d_##type(a.x / b.x / c.x / d.x, a.y / b.y / c.y / d.y);}			\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_divide_by_scalar(Z2D##Type object, z##type scalar)		\
	{return z_2d_##type(object.x / scalar, object.y / scalar);}				\
												\
												\
Z_INLINE z##type z_2d_##type##_dot_product(Z2D##Type a, Z2D##Type b)				\
	{return a.x * b.x + a.y * b.y;}								\
												\
												\
/* Area of the parallelogram between two vectors (OA and OB) */					\
Z_INLINE z##type z_2d_##type##_cross_product(Z2D##Type a, Z2D##Type b)				\
	{return a.x * b.y - a.y * b.x;}								\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_minimum(Z2D##Type a, Z2D##Type b)				\
	{return z_2d_##type(z_##type##_minimum(a.x, b.x), z_##type##_minimum(a.y, b.y));}	\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_maximum(Z2D##Type a, Z2D##Type b)				\
	{return z_2d_##type(z_##type##_maximum(a.x, b.x), z_##type##_maximum(a.y, b.y));}	\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_middle(Z2D##Type a, Z2D##Type b)				\
	{return z_2d_##type((a.x + b.x) / (z##type)2, (a.y + b.y) / (z##type)2);}		\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_fit(Z2D##Type a, Z2D##Type b)					\
	{											\
	return a.y / a.x > b.y / b.x								\
		? z_2d_##type(a.x * b.y / a.y, b.y)						\
		: z_2d_##type(b.x, a.y * b.x / a.x);						\
	}											\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_from_scalar(z##type scalar)					\
	{return z_2d_##type(scalar, scalar);}							\
												\
												\
Z_INLINE zboolean z_2d_##type##_is_zero(Z2D##Type object)					\
	{return object.x == (z##type)0 && object.y == (z##type)0;}				\
												\
												\
Z_INLINE zboolean z_2d_##type##_has_zero(Z2D##Type object)					\
	{return object.x == (z##type)0 || object.y == (z##type)0;}				\
												\
												\
Z_INLINE z##type z_2d_##type##_inner_sum(Z2D##Type object)					\
	{return object.x + object.y;}								\
												\
												\
Z_INLINE z##type z_2d_##type##_inner_product(Z2D##Type object)					\
	{return object.x * object.y;}								\
												\
												\
Z_INLINE z##type z_2d_##type##_inner_minimum(Z2D##Type object)					\
	{return z_##type##_minimum(object.x, object.y);}					\
												\
												\
Z_INLINE z##type z_2d_##type##_inner_maximum(Z2D##Type object)					\
	{return z_##type##_maximum(object.x, object.y);}					\
												\
												\
Z_INLINE z##type z_2d_##type##_inner_middle(Z2D##Type object)					\
	{return (object.x + object.y) / (z##type)2;}						\
												\
												\
Z_INLINE z##type z_2d_##type##_squared_length(Z2D##Type object)					\
	{return object.x * object.x + object.y * object.y;}					\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_clamp(Z2D##Type object, Z2D##Type minimum, Z2D##Type maximum)	\
	{											\
	return z_2d_##type									\
		(z_##type##_clamp(object.x, minimum.x, maximum.x),				\
		 z_##type##_clamp(object.y, minimum.y, maximum.y));				\
	}											\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_square_clamp(Z2D##Type object,z##type minimum, z##type maximum)\
	{											\
	return z_2d_##type									\
		(z_##type##_clamp(object.x, minimum, maximum),					\
		 z_##type##_clamp(object.y, minimum, maximum));					\
	}											\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_yx(Z2D##Type object)						\
	{return z_2d_##type(object.y, object.x);}						\
												\
												\
Z_INLINE Z3D##Type z_2d_##type##_xyn(Z2D##Type object, z##type n)				\
	{return z_3d_##type(object.x, object.y, n);}						\
												\
												\
Z_INLINE Z3D##Type z_2d_##type##_xny(Z2D##Type object, z##type n)				\
	{return z_3d_##type(object.x, n, object.y);}						\
												\
												\
Z_INLINE Z3D##Type z_2d_##type##_nxy(Z2D##Type object, z##type n)				\
	{return z_3d_##type(n, object.x, object.y);}						\
												\
												\
Z_INLINE Z3D##Type z_2d_##type##_yxn(Z2D##Type object, z##type n)				\
	{return z_3d_##type(object.y, object.x, n);}						\
												\
												\
Z_INLINE Z3D##Type z_2d_##type##_ynx(Z2D##Type object, z##type n)				\
	{return z_3d_##type(object.y, n, object.x);}						\
												\
												\
Z_INLINE Z3D##Type z_2d_##type##_nyx(Z2D##Type object, z##type n)				\
	{return z_3d_##type(n, object.y, object.x);}


Z_IMPLEMENTATION_2D_NATURAL(UInt8,   uint8  )
Z_IMPLEMENTATION_2D_NATURAL(UInt16,  uint16 )
Z_IMPLEMENTATION_2D_NATURAL(UInt32,  uint32 )
Z_IMPLEMENTATION_2D_NATURAL(UInt64,  uint64 )
Z_IMPLEMENTATION_2D_NATURAL(Int8,    int8   )
Z_IMPLEMENTATION_2D_NATURAL(Int16,   int16  )
Z_IMPLEMENTATION_2D_NATURAL(Int32,   int32  )
Z_IMPLEMENTATION_2D_NATURAL(Int64,   int64  )
Z_IMPLEMENTATION_2D_NATURAL(Float,   float  )
Z_IMPLEMENTATION_2D_NATURAL(Double,  double )
Z_IMPLEMENTATION_2D_NATURAL(LDouble, ldouble)

#define z_2d_value_are_equal(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _are_equal	   )
#define z_2d_value_swap(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _swap		   )
#define z_2d_value_contains(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _contains	   )
#define z_2d_value_add(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _add		   )
#define z_2d_value_add_3(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _add_3		   )
#define z_2d_value_add_4(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _add_4		   )
#define z_2d_value_add_scalar(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _add_scalar	   )
#define z_2d_value_subtract(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _subtract	   )
#define z_2d_value_subtract_3(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _subtract_3	   )
#define z_2d_value_subtract_4(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _subtract_4	   )
#define z_2d_value_subtract_scalar(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _subtract_scalar   )
#define z_2d_value_multiply(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _multiply	   )
#define z_2d_value_multiply_3(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _multiply_3	   )
#define z_2d_value_multiply_4(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _multiply_4	   )
#define z_2d_value_multiply_by_scalar(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _multiply_by_scalar)
#define z_2d_value_divide(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _divide		   )
#define z_2d_value_divide_3(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _divide_3	   )
#define z_2d_value_divide_4(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _divide_4	   )
#define z_2d_value_divide_by_scalar(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _divide_by_scalar  )
#define z_2d_value_dot_product(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _dot_product	   )
#define z_2d_value_cross_product(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _cross_product	   )
#define z_2d_value_minimum(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _minimum	   )
#define z_2d_value_maximum(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _maximum	   )
#define z_2d_value_middle(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _middle		   )
#define z_2d_value_fit(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _fit		   )
#define z_2d_value_from_scalar(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _from_scalar	   )
#define z_2d_value_is_zero(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_zero	   )
#define z_2d_value_has_zero(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_zero	   )
#define z_2d_value_inner_sum(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inner_sum	   )
#define z_2d_value_inner_product(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inner_product	   )
#define z_2d_value_inner_minimum(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inner_minimum	   )
#define z_2d_value_inner_maximum(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inner_maximum	   )
#define z_2d_value_inner_middle(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inner_middle	   )
#define z_2d_value_squared_length(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _squared_length	   )
#define z_2d_value_clamp(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _clamp		   )
#define z_2d_value_square_clamp(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _square_clamp	   )
#define z_2d_value_yx(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _yx		   )
#define z_2d_value_xyn(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _xyn		   )
#define z_2d_value_xny(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _xny		   )
#define z_2d_value_nxy(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _nxy		   )
#define z_2d_value_yxn(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _yxn		   )
#define z_2d_value_ynx(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _ynx		   )
#define z_2d_value_nyx(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _nyx		   )


/* MARK: - Operations for integer and real types */


#define Z_IMPLEMENTATION_2D_INTEGER(Type, type)							\
												\
												\
Z_INLINE zboolean z_2d_##type##_is_negative(Z2D##Type object)					\
	{return object.x < (z##type)0 && object.y < (z##type)0;}				\
												\
												\
Z_INLINE zboolean z_2d_##type##_has_negative(Z2D##Type object)					\
	{return object.x < (z##type)0 || object.y < (z##type)0;}				\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_negative(Z2D##Type object)					\
	{return z_2d_##type(-object.x, -object.y);}						\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_absolute(Z2D##Type object)					\
	{return z_2d_##type(z_##type##_absolute(object.x), z_##type##_absolute(object.y));}


Z_IMPLEMENTATION_2D_INTEGER(Int8,    int8   )
Z_IMPLEMENTATION_2D_INTEGER(Int16,   int16  )
Z_IMPLEMENTATION_2D_INTEGER(Int32,   int32  )
Z_IMPLEMENTATION_2D_INTEGER(Int64,   int64  )
Z_IMPLEMENTATION_2D_INTEGER(Float,   float  )
Z_IMPLEMENTATION_2D_INTEGER(Double,  double )
Z_IMPLEMENTATION_2D_INTEGER(LDouble, ldouble)

#define z_2d_value_is_negative(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_negative )
#define z_2d_value_has_negative(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_negative)
#define z_2d_value_negative(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _negative    )
#define z_2d_value_absolute(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _absolute    )


/* MARK: - Operations for real types only */


#define Z_IMPLEMENTATION_2D_REAL(Type, type, _, epsilon)					\
												\
												\
Z_INLINE zboolean z_2d_##type##_are_almost_equal(Z2D##Type a, Z2D##Type b)			\
	{return z_##type##_are_almost_equal(a.x, b.x) && z_##type##_are_almost_equal(a.y, b.y);}\
												\
												\
Z_INLINE zboolean z_2d_##type##_are_perpendicular(Z2D##Type a, Z2D##Type b)			\
	{return z_##type##_absolute(z_2d_##type##_dot_product(a, b)) <= epsilon;}		\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_lerp(Z2D##Type a, Z2D##Type b, z##type t)			\
	{return z_2d_##type(z_##type##_lerp(a.x, b.x, t), z_##type##_lerp(a.y, b.y, t));}	\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_inverse_lerp(Z2D##Type a, Z2D##Type b, z##type t)		\
	{											\
	return z_2d_##type									\
		(z_##type##_inverse_lerp(a.x, b.x, t), z_##type##_inverse_lerp(a.y, b.y, t));	\
	}											\
												\
												\
Z_INLINE zboolean z_2d_##type##_is_finite(Z2D##Type object)					\
	{return z_##type##_is_finite(object.x) && z_##type##_is_finite(object.y);}		\
												\
												\
Z_INLINE zboolean z_2d_##type##_is_infinity(Z2D##Type object)					\
	{return z_##type##_is_infinity(object.x) && z_##type##_is_infinity(object.y);}		\
												\
												\
Z_INLINE zboolean z_2d_##type##_is_nan(Z2D##Type object)					\
	{return z_##type##_is_nan(object.x) && z_##type##_is_nan(object.y);}			\
												\
												\
Z_INLINE zboolean z_2d_##type##_is_almost_zero(Z2D##Type object)				\
	{return z_##type##_is_almost_zero(object.x) && z_##type##_is_almost_zero(object.y);}	\
												\
												\
Z_INLINE zboolean z_2d_##type##_has_finite(Z2D##Type object)					\
	{return z_##type##_is_finite(object.x) || z_##type##_is_finite(object.y);}		\
												\
												\
Z_INLINE zboolean z_2d_##type##_has_infinity(Z2D##Type object)					\
	{return z_##type##_is_infinity(object.x) || z_##type##_is_infinity(object.y);}		\
												\
												\
Z_INLINE zboolean z_2d_##type##_has_nan(Z2D##Type object)					\
	{return z_##type##_is_nan(object.x) || z_##type##_is_nan(object.y);}			\
												\
												\
Z_INLINE zboolean z_2d_##type##_has_almost_zero(Z2D##Type object)				\
	{return z_##type##_is_almost_zero(object.x) || z_##type##_is_almost_zero(object.y);}	\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_reciprocal(Z2D##Type object)					\
	{return z_2d_##type(_(1.0) / object.x, _(1.0) / object.y);}				\
												\
												\
Z_INLINE Z2D##Type z_2d_##type##_square_clamp_01(Z2D##Type object)				\
	{return z_2d_##type(z_##type##_clamp_01(object.x), z_##type##_clamp_01(object.y));}


Z_IMPLEMENTATION_2D_REAL(Float,	  float,   Z_FLOAT,   Z_FLOAT_EPSILON  )
Z_IMPLEMENTATION_2D_REAL(Double,  double,  Z_DOUBLE,  Z_DOUBLE_EPSILON )
Z_IMPLEMENTATION_2D_REAL(LDouble, ldouble, Z_LDOUBLE, Z_LDOUBLE_EPSILON)


/* MARK: - Default real type definitions */


#define z_2d_are_equal		Z_INSERT_REAL_fixed_type(z_2d_, _are_equal	     )
#define z_2d_are_almost_equal	Z_INSERT_REAL_fixed_type(z_2d_, _are_almost_equal    )
#define z_2d_are_perpendicular	Z_INSERT_REAL_fixed_type(z_2d_, _are_perpendicular   )
#define z_2d_swap		Z_INSERT_REAL_fixed_type(z_2d_, _swap		     )
#define z_2d_contains		Z_INSERT_REAL_fixed_type(z_2d_, _contains	     )
#define z_2d_add		Z_INSERT_REAL_fixed_type(z_2d_, _add		     )
#define z_2d_add_3		Z_INSERT_REAL_fixed_type(z_2d_, _add_3		     )
#define z_2d_add_4		Z_INSERT_REAL_fixed_type(z_2d_, _add_4		     )
#define z_2d_add_scalar		Z_INSERT_REAL_fixed_type(z_2d_, _add_scalar	     )
#define z_2d_subtract		Z_INSERT_REAL_fixed_type(z_2d_, _subtract	     )
#define z_2d_subtract_3		Z_INSERT_REAL_fixed_type(z_2d_, _subtract_3	     )
#define z_2d_subtract_4		Z_INSERT_REAL_fixed_type(z_2d_, _subtract_4	     )
#define z_2d_subtract_scalar	Z_INSERT_REAL_fixed_type(z_2d_, _subtract_scalar     )
#define z_2d_multiply		Z_INSERT_REAL_fixed_type(z_2d_, _multiply	     )
#define z_2d_multiply_3		Z_INSERT_REAL_fixed_type(z_2d_, _multiply_3	     )
#define z_2d_multiply_4		Z_INSERT_REAL_fixed_type(z_2d_, _multiply_4	     )
#define z_2d_multiply_by_scalar	Z_INSERT_REAL_fixed_type(z_2d_, _multiply_by_scalar  )
#define z_2d_divide		Z_INSERT_REAL_fixed_type(z_2d_, _divide		     )
#define z_2d_divide_3		Z_INSERT_REAL_fixed_type(z_2d_, _divide_3	     )
#define z_2d_divide_4		Z_INSERT_REAL_fixed_type(z_2d_, _divide_4	     )
#define z_2d_divide_by_scalar	Z_INSERT_REAL_fixed_type(z_2d_, _divide_by_scalar    )
#define z_2d_dot_product	Z_INSERT_REAL_fixed_type(z_2d_, _dot_product	     )
#define z_2d_cross_product	Z_INSERT_REAL_fixed_type(z_2d_, _cross_product	     )
#define z_2d_minimum		Z_INSERT_REAL_fixed_type(z_2d_, _minimum	     )
#define z_2d_maximum		Z_INSERT_REAL_fixed_type(z_2d_, _maximum	     )
#define z_2d_middle		Z_INSERT_REAL_fixed_type(z_2d_, _middle		     )
#define z_2d_fit		Z_INSERT_REAL_fixed_type(z_2d_, _fit		     )
#define z_2d_lerp		Z_INSERT_REAL_fixed_type(z_2d_, _lerp		     )
#define z_2d_inverse_lerp	Z_INSERT_REAL_fixed_type(z_2d_, _inverse_lerp	     )
#define z_2d_from_scalar	Z_INSERT_REAL_fixed_type(z_2d_, _from_scalar	     )
#define z_2d_is_finite		Z_INSERT_REAL_fixed_type(z_2d_, _is_finite	     )
#define z_2d_is_infinity	Z_INSERT_REAL_fixed_type(z_2d_, _is_infinity	     )
#define z_2d_is_nan		Z_INSERT_REAL_fixed_type(z_2d_, _is_nan		     )
#define z_2d_is_negative	Z_INSERT_REAL_fixed_type(z_2d_, _is_negative	     )
#define z_2d_is_zero		Z_INSERT_REAL_fixed_type(z_2d_, _is_zero	     )
#define z_2d_is_almost_zero	Z_INSERT_REAL_fixed_type(z_2d_, _is_almost_zero	     )
#define z_2d_has_finite		Z_INSERT_REAL_fixed_type(z_2d_, _has_finite	     )
#define z_2d_has_infinity	Z_INSERT_REAL_fixed_type(z_2d_, _has_infinity	     )
#define z_2d_has_nan		Z_INSERT_REAL_fixed_type(z_2d_, _has_nan	     )
#define z_2d_has_negative	Z_INSERT_REAL_fixed_type(z_2d_, _has_negative	     )
#define z_2d_has_zero		Z_INSERT_REAL_fixed_type(z_2d_, _has_zero	     )
#define z_2d_has_almost_zero	Z_INSERT_REAL_fixed_type(z_2d_, _has_almost_zero     )
#define z_2d_negative		Z_INSERT_REAL_fixed_type(z_2d_, _negative	     )
#define z_2d_absolute		Z_INSERT_REAL_fixed_type(z_2d_, _absolute	     )
#define z_2d_reciprocal		Z_INSERT_REAL_fixed_type(z_2d_, _reciprocal	     )
#define z_2d_inner_sum		Z_INSERT_REAL_fixed_type(z_2d_, _inner_sum	     )
#define z_2d_inner_product	Z_INSERT_REAL_fixed_type(z_2d_, _inner_product	     )
#define z_2d_inner_minimum	Z_INSERT_REAL_fixed_type(z_2d_, _inner_minimum	     )
#define z_2d_inner_maximum	Z_INSERT_REAL_fixed_type(z_2d_, _inner_maximum	     )
#define z_2d_inner_middle	Z_INSERT_REAL_fixed_type(z_2d_, _inner_middle	     )
#define z_2d_squared_length	Z_INSERT_REAL_fixed_type(z_2d_, _squared_length	     )
#define z_2d_clamp		Z_INSERT_REAL_fixed_type(z_2d_, _clamp		     )
#define z_2d_square_clamp	Z_INSERT_REAL_fixed_type(z_2d_, _square_clamp	     )
#define z_2d_square_clamp_01	Z_INSERT_REAL_fixed_type(z_2d_, _square_clamp_01     )
#define z_2d_yx			Z_INSERT_REAL_fixed_type(z_2d_, _yx		     )
#define z_2d_xyn		Z_INSERT_REAL_fixed_type(z_2d_, _xyn		     )
#define z_2d_xny		Z_INSERT_REAL_fixed_type(z_2d_, _xny		     )
#define z_2d_nxy		Z_INSERT_REAL_fixed_type(z_2d_, _nxy		     )
#define z_2d_yxn		Z_INSERT_REAL_fixed_type(z_2d_, _yxn		     )
#define z_2d_ynx		Z_INSERT_REAL_fixed_type(z_2d_, _ynx		     )
#define z_2d_nyx		Z_INSERT_REAL_fixed_type(z_2d_, _nyx		     )


#endif /* __Z_functions_base_Z2DValue_H__ */
