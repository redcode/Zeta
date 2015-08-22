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


#define Z_PASTE_2d_type_are_equal(	   type) Z_PASTE_3(z_2d_, type, _are_equal	   )
#define Z_PASTE_2d_type_swap(		   type) Z_PASTE_3(z_2d_, type, _swap		   )
#define Z_PASTE_2d_type_contains(	   type) Z_PASTE_3(z_2d_, type, _contains	   )
#define Z_PASTE_2d_type_add(		   type) Z_PASTE_3(z_2d_, type, _add		   )
#define Z_PASTE_2d_type_add_3(		   type) Z_PASTE_3(z_2d_, type, _add_3		   )
#define Z_PASTE_2d_type_add_4(		   type) Z_PASTE_3(z_2d_, type, _add_4		   )
#define Z_PASTE_2d_type_add_scalar(	   type) Z_PASTE_3(z_2d_, type, _add_scalar	   )
#define Z_PASTE_2d_type_subtract(	   type) Z_PASTE_3(z_2d_, type, _subtract	   )
#define Z_PASTE_2d_type_subtract_3(	   type) Z_PASTE_3(z_2d_, type, _subtract_3	   )
#define Z_PASTE_2d_type_subtract_4(	   type) Z_PASTE_3(z_2d_, type, _subtract_4	   )
#define Z_PASTE_2d_type_subtract_scalar(   type) Z_PASTE_3(z_2d_, type, _subtract_scalar   )
#define Z_PASTE_2d_type_multiply(	   type) Z_PASTE_3(z_2d_, type, _multiply	   )
#define Z_PASTE_2d_type_multiply_3(	   type) Z_PASTE_3(z_2d_, type, _multiply_3	   )
#define Z_PASTE_2d_type_multiply_4(	   type) Z_PASTE_3(z_2d_, type, _multiply_4	   )
#define Z_PASTE_2d_type_multiply_by_scalar(type) Z_PASTE_3(z_2d_, type, _multiply_by_scalar)
#define Z_PASTE_2d_type_divide(		   type) Z_PASTE_3(z_2d_, type, _divide		   )
#define Z_PASTE_2d_type_divide_3(	   type) Z_PASTE_3(z_2d_, type, _divide_3	   )
#define Z_PASTE_2d_type_divide_4(	   type) Z_PASTE_3(z_2d_, type, _divide_4	   )
#define Z_PASTE_2d_type_divide_by_scalar(  type) Z_PASTE_3(z_2d_, type, _divide_by_scalar  )
#define Z_PASTE_2d_type_dot_product(	   type) Z_PASTE_3(z_2d_, type, _dot_product	   )
#define Z_PASTE_2d_type_cross_product(	   type) Z_PASTE_3(z_2d_, type, _cross_product	   )
#define Z_PASTE_2d_type_minimum(	   type) Z_PASTE_3(z_2d_, type, _minimum	   )
#define Z_PASTE_2d_type_maximum(	   type) Z_PASTE_3(z_2d_, type, _maximum	   )
#define Z_PASTE_2d_type_middle(		   type) Z_PASTE_3(z_2d_, type, _middle		   )
#define Z_PASTE_2d_type_fit(		   type) Z_PASTE_3(z_2d_, type, _fit		   )
#define Z_PASTE_2d_type_from_scalar(	   type) Z_PASTE_3(z_2d_, type, _from_scalar	   )
#define Z_PASTE_2d_type_is_zero(	   type) Z_PASTE_3(z_2d_, type, _is_zero	   )
#define Z_PASTE_2d_type_has_zero(	   type) Z_PASTE_3(z_2d_, type, _has_zero	   )
#define Z_PASTE_2d_type_inner_sum(	   type) Z_PASTE_3(z_2d_, type, _inner_sum	   )
#define Z_PASTE_2d_type_inner_product(	   type) Z_PASTE_3(z_2d_, type, _inner_product	   )
#define Z_PASTE_2d_type_inner_minimum(	   type) Z_PASTE_3(z_2d_, type, _inner_minimum	   )
#define Z_PASTE_2d_type_inner_maximum(	   type) Z_PASTE_3(z_2d_, type, _inner_maximum	   )
#define Z_PASTE_2d_type_inner_middle(	   type) Z_PASTE_3(z_2d_, type, _inner_middle	   )
#define Z_PASTE_2d_type_squared_length(	   type) Z_PASTE_3(z_2d_, type, _squared_length	   )
#define Z_PASTE_2d_type_clamp(		   type) Z_PASTE_3(z_2d_, type, _clamp		   )
#define Z_PASTE_2d_type_square_clamp(	   type) Z_PASTE_3(z_2d_, type, _square_clamp	   )
#define Z_PASTE_2d_type_yx(		   type) Z_PASTE_3(z_2d_, type, _yx		   )
#define Z_PASTE_2d_type_xyn(		   type) Z_PASTE_3(z_2d_, type, _xyn		   )
#define Z_PASTE_2d_type_xny(		   type) Z_PASTE_3(z_2d_, type, _xny		   )
#define Z_PASTE_2d_type_nxy(		   type) Z_PASTE_3(z_2d_, type, _nxy		   )
#define Z_PASTE_2d_type_yxn(		   type) Z_PASTE_3(z_2d_, type, _yxn		   )
#define Z_PASTE_2d_type_ynx(		   type) Z_PASTE_3(z_2d_, type, _ynx		   )
#define Z_PASTE_2d_type_nyx(		   type) Z_PASTE_3(z_2d_, type, _nyx		   )

#define z_2d_value_are_equal(	      TYPE) Z_PASTE_2d_type_are_equal	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_swap(	      TYPE) Z_PASTE_2d_type_swap	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_contains(	      TYPE) Z_PASTE_2d_type_contains	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_add(		      TYPE) Z_PASTE_2d_type_add		      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_add_3(	      TYPE) Z_PASTE_2d_type_add_3	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_add_4(	      TYPE) Z_PASTE_2d_type_add_4	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_add_scalar(	      TYPE) Z_PASTE_2d_type_add_scalar	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_subtract(	      TYPE) Z_PASTE_2d_type_subtract	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_subtract_3(	      TYPE) Z_PASTE_2d_type_subtract_3	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_subtract_4(	      TYPE) Z_PASTE_2d_type_subtract_4	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_subtract_scalar(   TYPE) Z_PASTE_2d_type_subtract_scalar   (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_multiply(	      TYPE) Z_PASTE_2d_type_multiply	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_multiply_3(	      TYPE) Z_PASTE_2d_type_multiply_3	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_multiply_4(	      TYPE) Z_PASTE_2d_type_multiply_4	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_multiply_by_scalar(TYPE) Z_PASTE_2d_type_multiply_by_scalar(Z_##TYPE##_FIXED_TYPE_nam3)
#define z_2d_value_divide(	      TYPE) Z_PASTE_2d_type_divide	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_divide_3(	      TYPE) Z_PASTE_2d_type_divide_3	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_divide_4(	      TYPE) Z_PASTE_2d_type_divide_4	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_divide_by_scalar(  TYPE) Z_PASTE_2d_type_divide_by_scalar  (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_dot_product(	      TYPE) Z_PASTE_2d_type_dot_product	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_cross_product(     TYPE) Z_PASTE_2d_type_cross_product     (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_minimum(	      TYPE) Z_PASTE_2d_type_minimum	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_maximum(	      TYPE) Z_PASTE_2d_type_maximum	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_middle(	      TYPE) Z_PASTE_2d_type_middle	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_fit(		      TYPE) Z_PASTE_2d_type_fit		      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_from_scalar(	      TYPE) Z_PASTE_2d_type_from_scalar	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_is_zero(	      TYPE) Z_PASTE_2d_type_is_zero	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_has_zero(	      TYPE) Z_PASTE_2d_type_has_zero	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_inner_sum(	      TYPE) Z_PASTE_2d_type_inner_sum	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_inner_product(     TYPE) Z_PASTE_2d_type_inner_product     (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_inner_minimum(     TYPE) Z_PASTE_2d_type_inner_minimum     (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_inner_maximum(     TYPE) Z_PASTE_2d_type_inner_maximum     (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_inner_middle(      TYPE) Z_PASTE_2d_type_inner_middle      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_squared_length(    TYPE) Z_PASTE_2d_type_squared_length    (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_clamp(	      TYPE) Z_PASTE_2d_type_clamp	      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_square_clamp(      TYPE) Z_PASTE_2d_type_square_clamp      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_yx(		      TYPE) Z_PASTE_2d_type_yx		      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_xyn(		      TYPE) Z_PASTE_2d_type_xyn		      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_xny(		      TYPE) Z_PASTE_2d_type_xny		      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_nxy(		      TYPE) Z_PASTE_2d_type_nxy		      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_yxn(		      TYPE) Z_PASTE_2d_type_yxn		      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_ynx(		      TYPE) Z_PASTE_2d_type_ynx		      (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_nyx(		      TYPE) Z_PASTE_2d_type_nyx		      (Z_##TYPE##_FIXED_TYPE_name)


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


#define Z_PASTE_2d_type_is_negative( type) Z_PASTE_2d_type_is_negative (z_2d_, type, _is_negative )
#define Z_PASTE_2d_type_has_negative(type) Z_PASTE_2d_type_has_negative(z_2d_, type, _has_negative)
#define Z_PASTE_2d_type_negative(    type) Z_PASTE_2d_type_negative    (z_2d_, type, _negative	  )
#define Z_PASTE_2d_type_absolute(    type) Z_PASTE_2d_type_absolute    (z_2d_, type, _absolute	  )

#define z_2d_value_is_negative( TYPE) Z_PASTE_2d_type_is_negative (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_has_negative(TYPE) Z_PASTE_2d_type_has_negative(Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_negative(	TYPE) Z_PASTE_2d_type_negative	  (Z_##TYPE##_FIXED_TYPE_name)
#define z_2d_value_absolute(	TYPE) Z_PASTE_2d_type_absolute	  (Z_##TYPE##_FIXED_TYPE_name)


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


#define Z_PASTE_2d_type_are_almost_equal( type) Q_PASTE_3(z_2d_, type, _are_almost_equal )
#define Z_PASTE_2d_type_are_perpendicular(type) Q_PASTE_3(z_2d_, type, _are_perpendicular)
#define Z_PASTE_2d_type_lerp(		  type) Q_PASTE_3(z_2d_, type, _lerp		 )
#define Z_PASTE_2d_type_inverse_lerp(	  type) Q_PASTE_3(z_2d_, type, _inverse_lerp	 )
#define Z_PASTE_2d_type_is_finite(	  type) Q_PASTE_3(z_2d_, type, _is_finite	 )
#define Z_PASTE_2d_type_is_infinity(	  type) Q_PASTE_3(z_2d_, type, _is_infinity	 )
#define Z_PASTE_2d_type_is_nan(		  type) Q_PASTE_3(z_2d_, type, _is_nan		 )
#define Z_PASTE_2d_type_is_almost_zero(	  type) Q_PASTE_3(z_2d_, type, _is_almost_zero	 )
#define Z_PASTE_2d_type_has_finite(	  type) Q_PASTE_3(z_2d_, type, _has_finite	 )
#define Z_PASTE_2d_type_has_infinity(	  type) Q_PASTE_3(z_2d_, type, _has_infinity	 )
#define Z_PASTE_2d_type_has_nan(	  type) Q_PASTE_3(z_2d_, type, _has_nan		 )
#define Z_PASTE_2d_type_has_almost_zero(  type) Q_PASTE_3(z_2d_, type, _has_almost_zero	 )
#define Z_PASTE_2d_type_reciprocal(	  type) Q_PASTE_3(z_2d_, type, _reciprocal	 )
#define Z_PASTE_2d_type_square_clamp_01(  type) Q_PASTE_3(z_2d_, type, _square_clamp_01	 )


/* MARK: - Default real type definitions */


#define z_2d_are_equal		Z_PASTE_2d_type_are_equal(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_are_almost_equal	Z_PASTE_2d_type_are_almost_equal(  Z_REAL_FIXED_TYPE_name)
#define z_2d_are_perpendicular	Z_PASTE_2d_type_are_perpendicular( Z_REAL_FIXED_TYPE_name)
#define z_2d_swap		Z_PASTE_2d_type_swap(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_contains		Z_PASTE_2d_type_contains(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_add		Z_PASTE_2d_type_add(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_add_3		Z_PASTE_2d_type_add_3(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_add_4		Z_PASTE_2d_type_add_4(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_add_scalar		Z_PASTE_2d_type_add_scalar(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_subtract		Z_PASTE_2d_type_subtract(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_subtract_3		Z_PASTE_2d_type_subtract_3(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_subtract_4		Z_PASTE_2d_type_subtract_4(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_subtract_scalar	Z_PASTE_2d_type_subtract_scalar(   Z_REAL_FIXED_TYPE_name)
#define z_2d_multiply		Z_PASTE_2d_type_multiply(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_multiply_3		Z_PASTE_2d_type_multiply_3(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_multiply_4		Z_PASTE_2d_type_multiply_4(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_multiply_by_scalar	Z_PASTE_2d_type_multiply_by_scalar(Z_REAL_FIXED_TYPE_name)
#define z_2d_divide		Z_PASTE_2d_type_divide(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_divide_3		Z_PASTE_2d_type_divide_3(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_divide_4		Z_PASTE_2d_type_divide_4(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_divide_by_scalar	Z_PASTE_2d_type_divide_by_scalar(  Z_REAL_FIXED_TYPE_name)
#define z_2d_dot_product	Z_PASTE_2d_type_dot_product(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_cross_product	Z_PASTE_2d_type_cross_product(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_minimum		Z_PASTE_2d_type_minimum(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_maximum		Z_PASTE_2d_type_maximum(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_middle		Z_PASTE_2d_type_middle(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_fit		Z_PASTE_2d_type_fit(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_lerp		Z_PASTE_2d_type_lerp(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_inverse_lerp	Z_PASTE_2d_type_inverse_lerp(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_from_scalar	Z_PASTE_2d_type_from_scalar(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_is_finite		Z_PASTE_2d_type_is_finite(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_is_infinity	Z_PASTE_2d_type_is_infinity(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_is_nan		Z_PASTE_2d_type_is_nan(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_is_negative	Z_PASTE_2d_type_is_negative(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_is_zero		Z_PASTE_2d_type_is_zero(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_is_almost_zero	Z_PASTE_2d_type_is_almost_zero(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_has_finite		Z_PASTE_2d_type_has_finite(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_has_infinity	Z_PASTE_2d_type_has_infinity(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_has_nan		Z_PASTE_2d_type_has_nan(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_has_negative	Z_PASTE_2d_type_has_negative(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_has_zero		Z_PASTE_2d_type_has_zero(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_has_almost_zero	Z_PASTE_2d_type_has_almost_zero(   Z_REAL_FIXED_TYPE_name)
#define z_2d_negative		Z_PASTE_2d_type_negative(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_absolute		Z_PASTE_2d_type_absolute(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_reciprocal		Z_PASTE_2d_type_reciprocal(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_inner_sum		Z_PASTE_2d_type_inner_sum(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_inner_product	Z_PASTE_2d_type_inner_product(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_inner_minimum	Z_PASTE_2d_type_inner_minimum(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_inner_maximum	Z_PASTE_2d_type_inner_maximum(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_inner_middle	Z_PASTE_2d_type_inner_middle(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_squared_length	Z_PASTE_2d_type_squared_length(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_clamp		Z_PASTE_2d_type_clamp(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_square_clamp	Z_PASTE_2d_type_square_clamp(	   Z_REAL_FIXED_TYPE_name)
#define z_2d_square_clamp_01	Z_PASTE_2d_type_square_clamp_01(   Z_REAL_FIXED_TYPE_name)
#define z_2d_yx			Z_PASTE_2d_type_yx(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_xyn		Z_PASTE_2d_type_xyn(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_xny		Z_PASTE_2d_type_xny(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_nxy		Z_PASTE_2d_type_nxy(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_yxn		Z_PASTE_2d_type_yxn(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_ynx		Z_PASTE_2d_type_ynx(		   Z_REAL_FIXED_TYPE_name)
#define z_2d_nyx		Z_PASTE_2d_type_nyx(		   Z_REAL_FIXED_TYPE_name)


#endif /* __Z_functions_base_Z2DValue_H__ */
