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


/* MARK: - Template for natural, integer and real types */


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


/* MARK: - Template for integer and real types */


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



#define z_2d_value_is_negative(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_negative )
#define z_2d_value_has_negative(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_negative)
#define z_2d_value_negative(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _negative    )
#define z_2d_value_absolute(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _absolute    )


/* MARK: - Template for real types only */


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


#define z_2d_value_are_almost_equal( TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _are_almost_equal )
#define z_2d_value_are_perpendicular(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _are_perpendicular)
#define z_2d_value_lerp(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _lerp		 )
#define z_2d_value_inverse_lerp(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inverse_lerp	 )
#define z_2d_value_is_finite(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_finite	 )
#define z_2d_value_is_infinity(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_infinity	 )
#define z_2d_value_is_nan(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_nan		 )
#define z_2d_value_is_almost_zero(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_almost_zero	 )
#define z_2d_value_has_finite(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_finite	 )
#define z_2d_value_has_infinity(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_infinity	 )
#define z_2d_value_has_nan(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_nan		 )
#define z_2d_value_has_almost_zero(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_almost_zero	 )
#define z_2d_value_reciprocal(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _reciprocal	 )
#define z_2d_value_square_clamp_01(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _square_clamp_01	 )


/* MARK: - Implementations */


Z_IMPLEMENTATION_2D_NATURAL(UInt8,  uint8 )
Z_IMPLEMENTATION_2D_NATURAL(UInt16, uint16)
Z_IMPLEMENTATION_2D_NATURAL(UInt32, uint32)

#if Z_IS_AVAILABLE(UINT64)
	Z_IMPLEMENTATION_2D_NATURAL(UInt64, uint64)
#endif

#if Z_IS_AVAILABLE(UINT128)
	Z_IMPLEMENTATION_2D_NATURAL(UInt128, uint128)
#endif

Z_IMPLEMENTATION_2D_NATURAL(Int8,  int8	)
Z_IMPLEMENTATION_2D_INTEGER(Int8,  int8	)
Z_IMPLEMENTATION_2D_NATURAL(Int16, int16)
Z_IMPLEMENTATION_2D_INTEGER(Int16, int16)
Z_IMPLEMENTATION_2D_NATURAL(Int32, int32)
Z_IMPLEMENTATION_2D_INTEGER(Int32, int32)

#if Z_IS_AVAILABLE(INT64)
	Z_IMPLEMENTATION_2D_NATURAL(Int64, int64)
	Z_IMPLEMENTATION_2D_INTEGER(Int64, int64)
#endif

#if Z_IS_AVAILABLE(INT128)
	Z_IMPLEMENTATION_2D_NATURAL(Int128, int128)
	Z_IMPLEMENTATION_2D_INTEGER(Int128, int128)
#endif

#if Z_IS_AVAILABLE(FLOAT16)
	Z_IMPLEMENTATION_2D_NATURAL(Float16, float16)
	Z_IMPLEMENTATION_2D_INTEGER(Float16, float16)
	Z_IMPLEMENTATION_2D_REAL   (Float16, float16, Z_FLOAT16, Z_FLOAT16_EPSILON)
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	Z_IMPLEMENTATION_2D_NATURAL(Float24, float24)
	Z_IMPLEMENTATION_2D_INTEGER(Float24, float24)
	Z_IMPLEMENTATION_2D_REAL   (Float24, float24, Z_FLOAT24, Z_FLOAT24_EPSILON)
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	Z_IMPLEMENTATION_2D_NATURAL(Float32, float32)
	Z_IMPLEMENTATION_2D_INTEGER(Float32, float32)
	Z_IMPLEMENTATION_2D_REAL   (Float32, float32, Z_FLOAT32, Z_FLOAT32_EPSILON)
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	Z_IMPLEMENTATION_2D_NATURAL(Float48, float48)
	Z_IMPLEMENTATION_2D_INTEGER(Float48, float48)
	Z_IMPLEMENTATION_2D_REAL   (Float48, float48, Z_FLOAT48, Z_FLOAT48_EPSILON)
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	Z_IMPLEMENTATION_2D_NATURAL(Float64, float64)
	Z_IMPLEMENTATION_2D_INTEGER(Float64, float64)
	Z_IMPLEMENTATION_2D_REAL   (Float64, float64, Z_FLOAT64, Z_FLOAT64_EPSILON)
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	Z_IMPLEMENTATION_2D_NATURAL(Float72, float72)
	Z_IMPLEMENTATION_2D_INTEGER(Float72, float72)
	Z_IMPLEMENTATION_2D_REAL   (Float72, float72, Z_FLOAT72, Z_FLOAT72_EPSILON)
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	Z_IMPLEMENTATION_2D_NATURAL(Float80, float80)
	Z_IMPLEMENTATION_2D_INTEGER(Float80, float80)
	Z_IMPLEMENTATION_2D_REAL   (Float80, float80, Z_FLOAT80, Z_FLOAT80_EPSILON)
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	Z_IMPLEMENTATION_2D_NATURAL(Float96, float96)
	Z_IMPLEMENTATION_2D_INTEGER(Float96, float96)
	Z_IMPLEMENTATION_2D_REAL   (Float96, float96, Z_FLOAT96, Z_FLOAT96_EPSILON)
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	Z_IMPLEMENTATION_2D_NATURAL(Float128, float128)
	Z_IMPLEMENTATION_2D_INTEGER(Float128, float128)
	Z_IMPLEMENTATION_2D_REAL   (Float128, float128, Z_FLOAT128, Z_FLOAT128_EPSILON)
#endif


/* MARK: - Default real type definitions */


#define z_2d_are_equal		z_2d_value_are_equal	     (REAL)
#define z_2d_are_almost_equal	z_2d_value_are_almost_equal  (REAL)
#define z_2d_are_perpendicular	z_2d_value_are_perpendicular (REAL)
#define z_2d_swap		z_2d_value_swap		     (REAL)
#define z_2d_contains		z_2d_value_contains	     (REAL)
#define z_2d_add		z_2d_value_add		     (REAL)
#define z_2d_add_3		z_2d_value_add_3	     (REAL)
#define z_2d_add_4		z_2d_value_add_4	     (REAL)
#define z_2d_add_scalar		z_2d_value_add_scalar	     (REAL)
#define z_2d_subtract		z_2d_value_subtract	     (REAL)
#define z_2d_subtract_3		z_2d_value_subtract_3	     (REAL)
#define z_2d_subtract_4		z_2d_value_subtract_4	     (REAL)
#define z_2d_subtract_scalar	z_2d_value_subtract_scalar   (REAL)
#define z_2d_multiply		z_2d_value_multiply	     (REAL)
#define z_2d_multiply_3		z_2d_value_multiply_3	     (REAL)
#define z_2d_multiply_4		z_2d_value_multiply_4	     (REAL)
#define z_2d_multiply_by_scalar	z_2d_value_multiply_by_scalar(REAL)
#define z_2d_divide		z_2d_value_divide	     (REAL)
#define z_2d_divide_3		z_2d_value_divide_3	     (REAL)
#define z_2d_divide_4		z_2d_value_divide_4	     (REAL)
#define z_2d_divide_by_scalar	z_2d_value_divide_by_scalar  (REAL)
#define z_2d_dot_product	z_2d_value_dot_product	     (REAL)
#define z_2d_cross_product	z_2d_value_cross_product     (REAL)
#define z_2d_minimum		z_2d_value_minimum	     (REAL)
#define z_2d_maximum		z_2d_value_maximum	     (REAL)
#define z_2d_middle		z_2d_value_middle	     (REAL)
#define z_2d_fit		z_2d_value_fit		     (REAL)
#define z_2d_lerp		z_2d_value_lerp		     (REAL)
#define z_2d_inverse_lerp	z_2d_value_inverse_lerp	     (REAL)
#define z_2d_from_scalar	z_2d_value_from_scalar	     (REAL)
#define z_2d_is_finite		z_2d_value_is_finite	     (REAL)
#define z_2d_is_infinity	z_2d_value_is_infinity	     (REAL)
#define z_2d_is_nan		z_2d_value_is_nan	     (REAL)
#define z_2d_is_negative	z_2d_value_is_negative	     (REAL)
#define z_2d_is_zero		z_2d_value_is_zero	     (REAL)
#define z_2d_is_almost_zero	z_2d_value_is_almost_zero    (REAL)
#define z_2d_has_finite		z_2d_value_has_finite	     (REAL)
#define z_2d_has_infinity	z_2d_value_has_infinity	     (REAL)
#define z_2d_has_nan		z_2d_value_has_nan	     (REAL)
#define z_2d_has_negative	z_2d_value_has_negative	     (REAL)
#define z_2d_has_zero		z_2d_value_has_zero	     (REAL)
#define z_2d_has_almost_zero	z_2d_value_has_almost_zero   (REAL)
#define z_2d_negative		z_2d_value_negative	     (REAL)
#define z_2d_absolute		z_2d_value_absolute	     (REAL)
#define z_2d_reciprocal		z_2d_value_reciprocal	     (REAL)
#define z_2d_inner_sum		z_2d_value_inner_sum	     (REAL)
#define z_2d_inner_product	z_2d_value_inner_product     (REAL)
#define z_2d_inner_minimum	z_2d_value_inner_minimum     (REAL)
#define z_2d_inner_maximum	z_2d_value_inner_maximum     (REAL)
#define z_2d_inner_middle	z_2d_value_inner_middle	     (REAL)
#define z_2d_squared_length	z_2d_value_squared_length    (REAL)
#define z_2d_clamp		z_2d_value_clamp	     (REAL)
#define z_2d_square_clamp	z_2d_value_square_clamp	     (REAL)
#define z_2d_square_clamp_01	z_2d_value_square_clamp_01   (REAL)
#define z_2d_yx			z_2d_value_yx		     (REAL)
#define z_2d_xyn		z_2d_value_xyn		     (REAL)
#define z_2d_xny		z_2d_value_xny		     (REAL)
#define z_2d_nxy		z_2d_value_nxy		     (REAL)
#define z_2d_yxn		z_2d_value_yxn		     (REAL)
#define z_2d_ynx		z_2d_value_ynx		     (REAL)
#define z_2d_nyx		z_2d_value_nyx		     (REAL)


#endif /* __Z_functions_base_Z2DValue_H__ */
