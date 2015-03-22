/* Q Kit C API - functions/base/Q2DValue.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_base_Q2DValue_H__
#define __Q_functions_base_Q2DValue_H__

#include <Q/functions/base/constructors.h>
#include <Q/functions/base/value.h>


/* MARK: - Operations for natural, integer and real types */


#define Q_IMPLEMENTATION_2D_NATURAL(Type, type)							\
												\
												\
Q_INLINE qboolean q_2d_##type##_are_equal(Q2D##Type a, Q2D##Type b)				\
	{return a.x == b.x && a.y == b.y;}							\
												\
												\
Q_INLINE void q_2d_##type##_swap(Q2D##Type *a, Q2D##Type *b)					\
	{											\
	Q2D##Type t = *a;									\
												\
	*a = *b; *b = t;									\
	}											\
												\
												\
Q_INLINE qboolean q_2d_##type##_contains(Q2D##Type a, Q2D##Type b)				\
	{return a.x >= b.x && a.y >= b.y;}							\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_add(Q2D##Type a, Q2D##Type b)					\
	{return q_2d_##type(a.x + b.x, a.y + b.y);}						\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_add_3(Q2D##Type a, Q2D##Type b, Q2D##Type c)			\
	{return q_2d_##type(a.x + b.x + c.x, a.y + b.y + c.y);}					\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_add_4(Q2D##Type a, Q2D##Type b, Q2D##Type c, Q2D##Type d)	\
	{return q_2d_##type(a.x + b.x + c.x + d.x, a.y + b.y + c.y + d.y);}			\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_add_scalar(Q2D##Type object, q##type scalar)			\
	{return q_2d_##type(object.x + scalar, object.y + scalar);}				\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_subtract(Q2D##Type a, Q2D##Type b)				\
	{return q_2d_##type(a.x - b.x, a.y - b.y);}						\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_subtract_3(Q2D##Type a, Q2D##Type b, Q2D##Type c)		\
	{return q_2d_##type(a.x - b.x - c.x, a.y - b.y - c.y);}					\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_subtract_4(Q2D##Type a, Q2D##Type b, Q2D##Type c, Q2D##Type d)	\
	{return q_2d_##type(a.x - b.x - c.x - d.x, a.y - b.y - c.y - d.y);}			\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_subtract_scalar(Q2D##Type object, q##type scalar)		\
	{return q_2d_##type(object.x - scalar, object.y - scalar);}				\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_multiply(Q2D##Type a, Q2D##Type b)				\
	{return q_2d_##type(a.x * b.x, a.y * b.y);}						\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_multiply_3(Q2D##Type a, Q2D##Type b, Q2D##Type c)		\
	{return q_2d_##type(a.x * b.x * c.x, a.y * b.y * c.y);}					\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_multiply_4(Q2D##Type a, Q2D##Type b, Q2D##Type c, Q2D##Type d)	\
	{return q_2d_##type(a.x * b.x * c.x * d.x, a.y * b.y * c.y * d.y);}			\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_multiply_by_scalar(Q2D##Type object, q##type scalar)		\
	{return q_2d_##type(object.x * scalar, object.y * scalar);}				\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_divide(Q2D##Type a, Q2D##Type b)				\
	{return q_2d_##type(a.x / b.x, a.y / b.y);}						\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_divide_3(Q2D##Type a, Q2D##Type b, Q2D##Type c)		\
	{return q_2d_##type(a.x / b.x / c.x, a.y / b.y / c.x);}					\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_divide_4(Q2D##Type a, Q2D##Type b, Q2D##Type c, Q2D##Type d)	\
	{return q_2d_##type(a.x / b.x / c.x / d.x, a.y / b.y / c.y / d.y);}			\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_divide_by_scalar(Q2D##Type object, q##type scalar)		\
	{return q_2d_##type(object.x / scalar, object.y / scalar);}				\
												\
												\
Q_INLINE q##type q_2d_##type##_dot_product(Q2D##Type a, Q2D##Type b)				\
	{return a.x * b.x + a.y * b.y;}								\
												\
												\
/* Area of the parallelogram between two vectors (OA and OB) */					\
Q_INLINE q##type q_2d_##type##_cross_product(Q2D##Type a, Q2D##Type b)				\
	{return a.x * b.y - a.y * b.x;}								\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_minimum(Q2D##Type a, Q2D##Type b)				\
	{return q_2d_##type(q_##type##_minimum(a.x, b.x), q_##type##_minimum(a.y, b.y));}	\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_maximum(Q2D##Type a, Q2D##Type b)				\
	{return q_2d_##type(q_##type##_maximum(a.x, b.x), q_##type##_maximum(a.y, b.y));}	\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_middle(Q2D##Type a, Q2D##Type b)				\
	{return q_2d_##type((a.x + b.x) / (q##type)2, (a.y + b.y) / (q##type)2);}		\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_fit(Q2D##Type a, Q2D##Type b)					\
	{											\
	return a.y / a.x > b.y / b.x								\
		? q_2d_##type(a.x * b.y / a.y, b.y)						\
		: q_2d_##type(b.x, a.y * b.x / a.x);						\
	}											\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_from_scalar(q##type scalar)					\
	{return q_2d_##type(scalar, scalar);}							\
												\
												\
Q_INLINE qboolean q_2d_##type##_is_zero(Q2D##Type object)					\
	{return object.x == (q##type)0 && object.y == (q##type)0;}				\
												\
												\
Q_INLINE qboolean q_2d_##type##_has_zero(Q2D##Type object)					\
	{return object.x == (q##type)0 || object.y == (q##type)0;}				\
												\
												\
Q_INLINE q##type q_2d_##type##_inner_sum(Q2D##Type object)					\
	{return object.x + object.y;}								\
												\
												\
Q_INLINE q##type q_2d_##type##_inner_product(Q2D##Type object)					\
	{return object.x * object.y;}								\
												\
												\
Q_INLINE q##type q_2d_##type##_inner_minimum(Q2D##Type object)					\
	{return q_##type##_minimum(object.x, object.y);}					\
												\
												\
Q_INLINE q##type q_2d_##type##_inner_maximum(Q2D##Type object)					\
	{return q_##type##_maximum(object.x, object.y);}					\
												\
												\
Q_INLINE q##type q_2d_##type##_inner_middle(Q2D##Type object)					\
	{return (object.x + object.y) / (q##type)2;}						\
												\
												\
Q_INLINE q##type q_2d_##type##_squared_length(Q2D##Type object)					\
	{return object.x * object.x + object.y * object.y;}					\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_clamp(Q2D##Type object, Q2D##Type minimum, Q2D##Type maximum)	\
	{											\
	return q_2d_##type									\
		(q_##type##_clamp(object.x, minimum.x, maximum.x),				\
		 q_##type##_clamp(object.y, minimum.y, maximum.y));				\
	}											\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_square_clamp(Q2D##Type object,q##type minimum, q##type maximum)\
	{											\
	return q_2d_##type									\
		(q_##type##_clamp(object.x, minimum, maximum),					\
		 q_##type##_clamp(object.y, minimum, maximum));					\
	}											\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_yx(Q2D##Type object)						\
	{return q_2d_##type(object.y, object.x);}						\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_xy0(Q2D##Type object)						\
	{return q_3d_##type(object.x, object.y, (q##type)0);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_xy1(Q2D##Type object)						\
	{return q_3d_##type(object.x, object.y, (q##type)1);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_xyn(Q2D##Type object, q##type n)				\
	{return q_3d_##type(object.x, object.y, n);}						\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_x0y(Q2D##Type object)						\
	{return q_3d_##type(object.x, (q##type)0, object.y);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_x1y(Q2D##Type object)						\
	{return q_3d_##type(object.x, (q##type)1, object.y);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_xny(Q2D##Type object, q##type n)				\
	{return q_3d_##type(object.x, n, object.y);}						\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_0xy(Q2D##Type object)						\
	{return q_3d_##type((q##type)0, object.x, object.y);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_1xy(Q2D##Type object)						\
	{return q_3d_##type((q##type)1, object.x, object.y);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_nxy(Q2D##Type object, q##type n)				\
	{return q_3d_##type(n, object.x, object.y);}						\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_yx0(Q2D##Type object)						\
	{return q_3d_##type(object.y, object.x, (q##type)0);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_yx1(Q2D##Type object)						\
	{return q_3d_##type(object.y, object.x, (q##type)1);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_yxn(Q2D##Type object, q##type n)				\
	{return q_3d_##type(object.y, object.x, n);}						\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_y0x(Q2D##Type object)						\
	{return q_3d_##type(object.y, (q##type)0, object.x);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_y1x(Q2D##Type object)						\
	{return q_3d_##type(object.y, (q##type)1, object.x);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_ynx(Q2D##Type object, q##type n)				\
	{return q_3d_##type(object.y, n, object.x);}						\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_0yx(Q2D##Type object)						\
	{return q_3d_##type((q##type)0, object.y, object.x);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_1yx(Q2D##Type object)						\
	{return q_3d_##type((q##type)1, object.y, object.x);}					\
												\
												\
Q_INLINE Q3D##Type q_2d_##type##_nyx(Q2D##Type object, q##type n)				\
	{return q_3d_##type(n, object.y, object.x);}


Q_IMPLEMENTATION_2D_NATURAL(UInt8,   uint8  )
Q_IMPLEMENTATION_2D_NATURAL(UInt16,  uint16 )
Q_IMPLEMENTATION_2D_NATURAL(UInt32,  uint32 )
Q_IMPLEMENTATION_2D_NATURAL(UInt64,  uint64 )
Q_IMPLEMENTATION_2D_NATURAL(Int8,    int8   )
Q_IMPLEMENTATION_2D_NATURAL(Int16,   int16  )
Q_IMPLEMENTATION_2D_NATURAL(Int32,   int32  )
Q_IMPLEMENTATION_2D_NATURAL(Int64,   int64  )
Q_IMPLEMENTATION_2D_NATURAL(Float,   float  )
Q_IMPLEMENTATION_2D_NATURAL(Double,  double )
Q_IMPLEMENTATION_2D_NATURAL(LDouble, ldouble)

#define q_2d_value_are_equal(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _are_equal	   )
#define q_2d_value_swap(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _swap		   )
#define q_2d_value_contains(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _contains	   )
#define q_2d_value_add(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _add		   )
#define q_2d_value_add_3(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _add_3		   )
#define q_2d_value_add_4(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _add_4		   )
#define q_2d_value_add_scalar(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _add_scalar	   )
#define q_2d_value_subtract(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _subtract	   )
#define q_2d_value_subtract_3(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _subtract_3	   )
#define q_2d_value_subtract_4(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _subtract_4	   )
#define q_2d_value_subtract_scalar(   TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _subtract_scalar   )
#define q_2d_value_multiply(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _multiply	   )
#define q_2d_value_multiply_3(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _multiply_3	   )
#define q_2d_value_multiply_4(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _multiply_4	   )
#define q_2d_value_multiply_by_scalar(TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _multiply_by_scalar)
#define q_2d_value_divide(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _divide		   )
#define q_2d_value_divide_3(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _divide_3	   )
#define q_2d_value_divide_4(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _divide_4	   )
#define q_2d_value_divide_by_scalar(  TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _divide_by_scalar  )
#define q_2d_value_dot_product(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _dot_product	   )
#define q_2d_value_cross_product(     TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _cross_product	   )
#define q_2d_value_minimum(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _minimum	   )
#define q_2d_value_maximum(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _maximum	   )
#define q_2d_value_middle(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _middle		   )
#define q_2d_value_fit(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _fit		   )
#define q_2d_value_from_scalar(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _from_scalar	   )
#define q_2d_value_is_zero(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _is_zero	   )
#define q_2d_value_has_zero(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _has_zero	   )
#define q_2d_value_inner_sum(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inner_sum	   )
#define q_2d_value_inner_product(     TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inner_product	   )
#define q_2d_value_inner_minimum(     TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inner_minimum	   )
#define q_2d_value_inner_maximum(     TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inner_maximum	   )
#define q_2d_value_inner_middle(      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _inner_middle	   )
#define q_2d_value_squared_length(    TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _squared_length	   )
#define q_2d_value_clamp(	      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _clamp		   )
#define q_2d_value_square_clamp(      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _square_clamp	   )
#define q_2d_value_yx(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _yx		   )
#define q_2d_value_xy0(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _xy0		   )
#define q_2d_value_xy1(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _xy1		   )
#define q_2d_value_xyn(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _xyn		   )
#define q_2d_value_x0y(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _x0y		   )
#define q_2d_value_x1y(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _x1y		   )
#define q_2d_value_xny(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _xny		   )
#define q_2d_value_0xy(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _0xy		   )
#define q_2d_value_1xy(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _1xy		   )
#define q_2d_value_nxy(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _nxy		   )
#define q_2d_value_yx0(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _yx0		   )
#define q_2d_value_yx1(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _yx1		   )
#define q_2d_value_yxn(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _yxn		   )
#define q_2d_value_y0x(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _y0x		   )
#define q_2d_value_y1x(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _y1x		   )
#define q_2d_value_ynx(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _ynx		   )
#define q_2d_value_0yx(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _0yx		   )
#define q_2d_value_1yx(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _1yx		   )
#define q_2d_value_nyx(		      TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _nyx		   )


/* MARK: - Operations for integer and real types */


#define Q_IMPLEMENTATION_2D_INTEGER(Type, type)							\
												\
												\
Q_INLINE qboolean q_2d_##type##_is_negative(Q2D##Type object)					\
	{return object.x < (q##type)0 && object.y < (q##type)0;}				\
												\
												\
Q_INLINE qboolean q_2d_##type##_has_negative(Q2D##Type object)					\
	{return object.x < (q##type)0 || object.y < (q##type)0;}				\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_negative(Q2D##Type object)					\
	{return q_2d_##type(-object.x, -object.y);}						\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_absolute(Q2D##Type object)					\
	{return q_2d_##type(q_##type##_absolute(object.x), q_##type##_absolute(object.y));}


Q_IMPLEMENTATION_2D_INTEGER(Int8,    int8   )
Q_IMPLEMENTATION_2D_INTEGER(Int16,   int16  )
Q_IMPLEMENTATION_2D_INTEGER(Int32,   int32  )
Q_IMPLEMENTATION_2D_INTEGER(Int64,   int64  )
Q_IMPLEMENTATION_2D_INTEGER(Float,   float  )
Q_IMPLEMENTATION_2D_INTEGER(Double,  double )
Q_IMPLEMENTATION_2D_INTEGER(LDouble, ldouble)

#define q_2d_value_is_negative( TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _is_negative )
#define q_2d_value_has_negative(TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _has_negative)
#define q_2d_value_negative(	TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _negative    )
#define q_2d_value_absolute(	TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _absolute    )


/* MARK: - Operations for real types only */


#define Q_IMPLEMENTATION_2D_REAL(Type, type, _, epsilon)					\
												\
												\
Q_INLINE qboolean q_2d_##type##_are_almost_equal(Q2D##Type a, Q2D##Type b)			\
	{return q_##type##_are_almost_equal(a.x, b.x) && q_##type##_are_almost_equal(a.y, b.y);}\
												\
												\
Q_INLINE qboolean q_2d_##type##_are_perpendicular(Q2D##Type a, Q2D##Type b)			\
	{return q_##type##_absolute(q_2d_##type##_dot_product(a, b)) <= epsilon;}		\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_lerp(Q2D##Type a, Q2D##Type b, q##type t)			\
	{return q_2d_##type(q_##type##_lerp(a.x, b.x, t), q_##type##_lerp(a.y, b.y, t));}	\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_inverse_lerp(Q2D##Type a, Q2D##Type b, q##type t)		\
	{											\
	return q_2d_##type									\
		(q_##type##_inverse_lerp(a.x, b.x, t), q_##type##_inverse_lerp(a.y, b.y, t));	\
	}											\
												\
												\
Q_INLINE qboolean q_2d_##type##_is_finite(Q2D##Type object)					\
	{return q_##type##_is_finite(object.x) && q_##type##_is_finite(object.y);}		\
												\
												\
Q_INLINE qboolean q_2d_##type##_is_infinity(Q2D##Type object)					\
	{return q_##type##_is_infinity(object.x) && q_##type##_is_infinity(object.y);}		\
												\
												\
Q_INLINE qboolean q_2d_##type##_is_nan(Q2D##Type object)					\
	{return q_##type##_is_nan(object.x) && q_##type##_is_nan(object.y);}			\
												\
												\
Q_INLINE qboolean q_2d_##type##_is_almost_zero(Q2D##Type object)				\
	{return q_##type##_is_almost_zero(object.x) && q_##type##_is_almost_zero(object.y);}	\
												\
												\
Q_INLINE qboolean q_2d_##type##_has_finite(Q2D##Type object)					\
	{return q_##type##_is_finite(object.x) || q_##type##_is_finite(object.y);}		\
												\
												\
Q_INLINE qboolean q_2d_##type##_has_infinity(Q2D##Type object)					\
	{return q_##type##_is_infinity(object.x) || q_##type##_is_infinity(object.y);}		\
												\
												\
Q_INLINE qboolean q_2d_##type##_has_nan(Q2D##Type object)					\
	{return q_##type##_is_nan(object.x) || q_##type##_is_nan(object.y);}			\
												\
												\
Q_INLINE qboolean q_2d_##type##_has_almost_zero(Q2D##Type object)				\
	{return q_##type##_is_almost_zero(object.x) || q_##type##_is_almost_zero(object.y);}	\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_reciprocal(Q2D##Type object)					\
	{return q_2d_##type(_(1.0) / object.x, _(1.0) / object.y);}				\
												\
												\
Q_INLINE Q2D##Type q_2d_##type##_square_clamp_01(Q2D##Type object)				\
	{return q_2d_##type(q_##type##_clamp_01(object.x), q_##type##_clamp_01(object.y));}


Q_IMPLEMENTATION_2D_REAL(Float,	  float,   Q_FLOAT,   Q_FLOAT_EPSILON  )
Q_IMPLEMENTATION_2D_REAL(Double,  double,  Q_DOUBLE,  Q_DOUBLE_EPSILON )
Q_IMPLEMENTATION_2D_REAL(LDouble, ldouble, Q_LDOUBLE, Q_LDOUBLE_EPSILON)


/* MARK: - Default real type definitions */

#define q_2d_are_equal		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _are_equal	   )
#define q_2d_are_almost_equal	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _are_almost_equal  )
#define q_2d_are_perpendicular	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _are_perpendicular )
#define q_2d_swap		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _swap		   )
#define q_2d_contains		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _contains	   )
#define q_2d_add		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _add		   )
#define q_2d_add_3		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _add_3		   )
#define q_2d_add_4		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _add_4		   )
#define q_2d_add_scalar		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _add_scalar	   )
#define q_2d_subtract		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _subtract	   )
#define q_2d_subtract_3		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _subtract_3	   )
#define q_2d_subtract_4		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _subtract_4	   )
#define q_2d_subtract_scalar	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _subtract_scalar   )
#define q_2d_multiply		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _multiply	   )
#define q_2d_multiply_3		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _multiply_3	   )
#define q_2d_multiply_4		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _multiply_4	   )
#define q_2d_multiply_by_scalar	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _multiply_by_scalar)
#define q_2d_divide		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _divide		   )
#define q_2d_divide_3		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _divide_3	   )
#define q_2d_divide_4		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _divide_4	   )
#define q_2d_divide_by_scalar	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _divide_by_scalar  )
#define q_2d_dot_product	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _dot_product	   )
#define q_2d_cross_product	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _cross_product	   )
#define q_2d_minimum		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _minimum	   )
#define q_2d_maximum		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _maximum	   )
#define q_2d_middle		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _middle		   )
#define q_2d_fit		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _fit		   )
#define q_2d_lerp		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _lerp		   )
#define q_2d_inverse_lerp	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _inverse_lerp	   )
#define q_2d_from_scalar	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _from_scalar	   )
#define q_2d_is_finite		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _is_finite	   )
#define q_2d_is_infinity	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _is_infinity	   )
#define q_2d_is_nan		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _is_nan		   )
#define q_2d_is_negative	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _is_negative	   )
#define q_2d_is_zero		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _is_zero	   )
#define q_2d_is_almost_zero	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _is_almost_zero	   )
#define q_2d_has_infinity	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _has_infinity	   )
#define q_2d_has_nan		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _has_nan	   )
#define q_2d_has_negative	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _has_negative	   )
#define q_2d_has_zero		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _has_zero	   )
#define q_2d_has_almost_zero	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _has_almost_zero   )
#define q_2d_negative		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _negative	   )
#define q_2d_absolute		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _absolute	   )
#define q_2d_reciprocal		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _reciprocal	   )
#define q_2d_inner_sum		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _inner_sum	   )
#define q_2d_inner_product	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _inner_product	   )
#define q_2d_inner_minimum	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _inner_minimum	   )
#define q_2d_inner_maximum	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _inner_maximum	   )
#define q_2d_inner_middle	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _inner_middle	   )
#define q_2d_squared_length	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _squared_length	   )
#define q_2d_clamp		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _clamp		   )
#define q_2d_square_clamp	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _square_clamp	   )
#define q_2d_square_clamp_01	Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _square_clamp_01   )
#define q_2d_yx			Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _yx		   )
#define q_2d_xy0		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _xy0		   )
#define q_2d_xy1		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _xy1		   )
#define q_2d_xyn		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _xyn		   )
#define q_2d_x0y		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _x0y		   )
#define q_2d_x1y		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _x1y		   )
#define q_2d_xny		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _xny		   )
#define q_2d_0xy		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _0xy		   )
#define q_2d_1xy		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _1xy		   )
#define q_2d_nxy		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _nxy		   )
#define q_2d_yx0		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _yx0		   )
#define q_2d_yx1		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _yx1		   )
#define q_2d_yxn		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _yxn		   )
#define q_2d_y0x		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _y0x		   )
#define q_2d_y1x		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _y1x		   )
#define q_2d_ynx		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _ynx		   )
#define q_2d_0yx		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _0yx		   )
#define q_2d_1yx		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _1yx		   )
#define q_2d_nyx		Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _nyx		   )

#endif /* __Q_functions_base_Q2DValue_H__ */
