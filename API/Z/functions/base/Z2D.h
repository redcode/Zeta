/* Z Kit - functions/base/Z2D.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_base_Z2D_H_
#define _Z_functions_base_Z2D_H_

#include <Z/functions/base/constructors.h>
#include <Z/functions/base/value.h>


/* MARK: - Common implementation */


#define Z_IMPLEMENTATION_COMMON(Type, type)							\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_add(Z2D##Type a, Z2D##Type b)						\
	{return z_2d_##type(a.x + b.x, a.y + b.y);}						\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_add_3(Z2D##Type a, Z2D##Type b, Z2D##Type c)				\
	{return z_2d_##type(a.x + b.x + c.x, a.y + b.y + c.y);}					\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_add_4(Z2D##Type a, Z2D##Type b, Z2D##Type c, Z2D##Type d)		\
	{return z_2d_##type(a.x + b.x + c.x + d.x, a.y + b.y + c.y + d.y);}			\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_add_scalar(Z2D##Type object, z##type scalar)				\
	{return z_2d_##type(object.x + scalar, object.y + scalar);}				\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_are_equal(Z2D##Type a, Z2D##Type b)					\
	{return a.x == b.x && a.y == b.y;}							\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_clamp(Z2D##Type object, Z2D##Type minimum, Z2D##Type maximum)		\
	{											\
	return z_2d_##type									\
		(z_##type##_clamp(object.x, minimum.x, maximum.x),				\
		 z_##type##_clamp(object.y, minimum.y, maximum.y));				\
	}											\
												\
												\
/* Area of the parallelogram between two vectors (OA and OB) */					\
static Z_INLINE											\
z##type z_2d_##type##_cross_product(Z2D##Type a, Z2D##Type b)					\
	{return a.x * b.y - a.y * b.x;}								\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_divide(Z2D##Type a, Z2D##Type b)					\
	{return z_2d_##type(a.x / b.x, a.y / b.y);}						\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_divide_3(Z2D##Type a, Z2D##Type b, Z2D##Type c)				\
	{return z_2d_##type(a.x / b.x / c.x, a.y / b.y / c.x);}					\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_divide_4(Z2D##Type a, Z2D##Type b, Z2D##Type c, Z2D##Type d)		\
	{return z_2d_##type(a.x / b.x / c.x / d.x, a.y / b.y / c.y / d.y);}			\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_divide_by_scalar(Z2D##Type object, z##type scalar)			\
	{return z_2d_##type(object.x / scalar, object.y / scalar);}				\
												\
												\
static Z_INLINE											\
z##type z_2d_##type##_dot_product(Z2D##Type a, Z2D##Type b)					\
	{return a.x * b.x + a.y * b.y;}								\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_fit(Z2D##Type object, Z2D##Type other)					\
	{											\
	return object.y / object.x > other.y / other.x						\
		? z_2d_##type(object.x * other.y / object.y, other.y)				\
		: z_2d_##type(other.x, object.y * other.x / object.x);				\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_from_scalar(z##type scalar)						\
	{return z_2d_##type(scalar, scalar);}							\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_has_zero(Z2D##Type object)						\
	{return object.x == (z##type)0 || object.y == (z##type)0;}				\
												\
												\
static Z_INLINE											\
z##type z_2d_##type##_inner_maximum(Z2D##Type object)						\
	{return z_##type##_maximum(object.x, object.y);}					\
												\
												\
static Z_INLINE											\
z##type z_2d_##type##_inner_middle(Z2D##Type object)						\
	{return (object.x + object.y) / (z##type)2;}						\
												\
												\
static Z_INLINE											\
z##type z_2d_##type##_inner_minimum(Z2D##Type object)						\
	{return z_##type##_minimum(object.x, object.y);}					\
												\
												\
static Z_INLINE											\
z##type z_2d_##type##_inner_product(Z2D##Type object)						\
	{return object.x * object.y;}								\
												\
												\
static Z_INLINE											\
z##type z_2d_##type##_inner_sum(Z2D##Type object)						\
	{return object.x + object.y;}								\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_is_zero(Z2D##Type object)						\
	{return object.x == (z##type)0 && object.y == (z##type)0;}				\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_maximum(Z2D##Type a, Z2D##Type b)					\
	{return z_2d_##type(z_##type##_maximum(a.x, b.x), z_##type##_maximum(a.y, b.y));}	\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_middle(Z2D##Type a, Z2D##Type b)					\
	{return z_2d_##type((a.x + b.x) / (z##type)2, (a.y + b.y) / (z##type)2);}		\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_minimum(Z2D##Type a, Z2D##Type b)					\
	{return z_2d_##type(z_##type##_minimum(a.x, b.x), z_##type##_minimum(a.y, b.y));}	\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_multiply(Z2D##Type a, Z2D##Type b)					\
	{return z_2d_##type(a.x * b.x, a.y * b.y);}						\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_multiply_3(Z2D##Type a, Z2D##Type b, Z2D##Type c)			\
	{return z_2d_##type(a.x * b.x * c.x, a.y * b.y * c.y);}					\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_multiply_4(Z2D##Type a, Z2D##Type b, Z2D##Type c, Z2D##Type d)		\
	{return z_2d_##type(a.x * b.x * c.x * d.x, a.y * b.y * c.y * d.y);}			\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_multiply_by_scalar(Z2D##Type object, z##type scalar)			\
	{return z_2d_##type(object.x * scalar, object.y * scalar);}				\
												\
												\
static Z_INLINE											\
Z3D##Type z_2d_##type##_nxy(Z2D##Type object, z##type n)					\
	{return z_3d_##type(n, object.x, object.y);}						\
												\
												\
static Z_INLINE											\
Z3D##Type z_2d_##type##_nyx(Z2D##Type object, z##type n)					\
	{return z_3d_##type(n, object.y, object.x);}						\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_square_clamp(Z2D##Type object, z##type minimum,z##type maximum)		\
	{											\
	return z_2d_##type									\
		(z_##type##_clamp(object.x, minimum, maximum),					\
		 z_##type##_clamp(object.y, minimum, maximum));					\
	}											\
												\
												\
static Z_INLINE											\
z##type z_2d_##type##_squared_length(Z2D##Type object)						\
	{return object.x * object.x + object.y * object.y;}					\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_subtract(Z2D##Type a, Z2D##Type b)					\
	{return z_2d_##type(a.x - b.x, a.y - b.y);}						\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_subtract_3(Z2D##Type a, Z2D##Type b, Z2D##Type c)			\
	{return z_2d_##type(a.x - b.x - c.x, a.y - b.y - c.y);}					\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_subtract_4(Z2D##Type a, Z2D##Type b, Z2D##Type c, Z2D##Type d)		\
	{return z_2d_##type(a.x - b.x - c.x - d.x, a.y - b.y - c.y - d.y);}			\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_subtract_scalar(Z2D##Type object, z##type scalar)			\
	{return z_2d_##type(object.x - scalar, object.y - scalar);}				\
												\
												\
static Z_INLINE											\
void z_2d_##type##_swap(Z2D##Type *a, Z2D##Type *b)						\
	{											\
	Z2D##Type t = *a;									\
												\
	*a = *b; *b = t;									\
	}											\
												\
												\
static Z_INLINE											\
Z3D##Type z_2d_##type##_xny(Z2D##Type object, z##type n)					\
	{return z_3d_##type(object.x, n, object.y);}						\
												\
												\
static Z_INLINE											\
Z3D##Type z_2d_##type##_xyn(Z2D##Type object, z##type n)					\
	{return z_3d_##type(object.x, object.y, n);}						\
												\
												\
static Z_INLINE											\
Z3D##Type z_2d_##type##_ynx(Z2D##Type object, z##type n)					\
	{return z_3d_##type(object.y, n, object.x);}						\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_yx(Z2D##Type object)							\
	{return z_2d_##type(object.y, object.x);}						\
												\
												\
static Z_INLINE											\
Z3D##Type z_2d_##type##_yxn(Z2D##Type object, z##type n)					\
	{return z_3d_##type(object.y, object.x, n);}


#define z_2d_type_add(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _add		  )
#define z_2d_type_add_3(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _add_3		  )
#define z_2d_type_add_4(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _add_4		  )
#define z_2d_type_add_scalar(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _add_scalar	  )
#define z_2d_type_are_equal(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _are_equal	  )
#define z_2d_type_clamp(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _clamp		  )
#define z_2d_type_cross_product(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _cross_product	  )
#define z_2d_type_divide(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _divide		  )
#define z_2d_type_divide_3(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _divide_3	  )
#define z_2d_type_divide_4(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _divide_4	  )
#define z_2d_type_divide_by_scalar(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _divide_by_scalar  )
#define z_2d_type_dot_product(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _dot_product	  )
#define z_2d_type_fit(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _fit		  )
#define z_2d_type_from_scalar(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _from_scalar	  )
#define z_2d_type_has_zero(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_zero	  )
#define z_2d_type_inner_maximum(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inner_maximum	  )
#define z_2d_type_inner_middle(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inner_middle	  )
#define z_2d_type_inner_minimum(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inner_minimum	  )
#define z_2d_type_inner_product(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inner_product	  )
#define z_2d_type_inner_sum(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inner_sum	  )
#define z_2d_type_is_zero(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_zero		  )
#define z_2d_type_maximum(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _maximum		  )
#define z_2d_type_middle(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _middle		  )
#define z_2d_type_minimum(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _minimum		  )
#define z_2d_type_multiply(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _multiply	  )
#define z_2d_type_multiply_3(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _multiply_3	  )
#define z_2d_type_multiply_4(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _multiply_4	  )
#define z_2d_type_multiply_by_scalar(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _multiply_by_scalar)
#define z_2d_type_nxy(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _nxy		  )
#define z_2d_type_nyx(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _nyx		  )
#define z_2d_type_square_clamp(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _square_clamp	  )
#define z_2d_type_squared_length(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _squared_length	  )
#define z_2d_type_subtract(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _subtract	  )
#define z_2d_type_subtract_3(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _subtract_3	  )
#define z_2d_type_subtract_4(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _subtract_4	  )
#define z_2d_type_subtract_scalar(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _subtract_scalar   )
#define z_2d_type_swap(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _swap		  )
#define z_2d_type_xny(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _xny		  )
#define z_2d_type_xyn(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _xyn		  )
#define z_2d_type_ynx(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _ynx		  )
#define z_2d_type_yx(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _yx		  )
#define z_2d_type_yxn(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _yxn		  )


/* MARK: - Partial implementation for signed types */


#define Z_IMPLEMENTATION_SIGNED(Type, type)							\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_absolute(Z2D##Type object)						\
	{return z_2d_##type(z_##type##_absolute(object.x), z_##type##_absolute(object.y));}	\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_has_negative(Z2D##Type object)						\
	{return object.x < (z##type)0 || object.y < (z##type)0;}				\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_is_negative(Z2D##Type object)						\
	{return object.x < (z##type)0 && object.y < (z##type)0;}				\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_negative(Z2D##Type object)						\
	{return z_2d_##type(-object.x, -object.y);}


#define z_2d_type_absolute(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _absolute    )
#define z_2d_type_has_negative(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_negative)
#define z_2d_type_is_negative( TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_negative )
#define z_2d_type_negative(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _negative    )


/* MARK: - Partial implementation for integer types */


#define Z_IMPLEMENTATION_INTEGER(Type, type)							\
												\
static Z_INLINE											\
zboolean z_2d_##type##_are_perpendicular(Z2D##Type a, Z2D##Type b)				\
	{return !z_##type##_absolute(z_2d_##type##_dot_product(a, b));}


#define z_2d_type_are_perpendicular(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _are_perpendicular)


/* MARK: - Partial implementation for real types */


#define Z_IMPLEMENTATION_REAL(Type, type, epsilon)						\
												\
static Z_INLINE											\
zboolean z_2d_##type##_are_almost_equal(Z2D##Type a, Z2D##Type b)				\
	{return z_##type##_are_almost_equal(a.x, b.x) && z_##type##_are_almost_equal(a.y, b.y);}\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_are_perpendicular(Z2D##Type a, Z2D##Type b)				\
	{return z_##type##_absolute(z_2d_##type##_dot_product(a, b)) <= epsilon;}		\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_clamp_01(Z2D##Type object)						\
	{return z_2d_##type(z_##type##_clamp_01(object.x), z_##type##_clamp_01(object.y));}	\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_has_almost_zero(Z2D##Type object)					\
	{return z_##type##_is_almost_zero(object.x) || z_##type##_is_almost_zero(object.y);}	\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_has_finite(Z2D##Type object)						\
	{return z_##type##_is_finite(object.x) || z_##type##_is_finite(object.y);}		\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_has_infinity(Z2D##Type object)						\
	{return z_##type##_is_infinity(object.x) || z_##type##_is_infinity(object.y);}		\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_has_nan(Z2D##Type object)						\
	{return z_##type##_is_nan(object.x) || z_##type##_is_nan(object.y);}			\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_inverse_lerp(Z2D##Type a, Z2D##Type b, z##type t)			\
	{											\
	return z_2d_##type									\
		(z_##type##_inverse_lerp(a.x, b.x, t), z_##type##_inverse_lerp(a.y, b.y, t));	\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_is_almost_zero(Z2D##Type object)						\
	{return z_##type##_is_almost_zero(object.x) && z_##type##_is_almost_zero(object.y);}	\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_is_finite(Z2D##Type object)						\
	{return z_##type##_is_finite(object.x) && z_##type##_is_finite(object.y);}		\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_is_infinity(Z2D##Type object)						\
	{return z_##type##_is_infinity(object.x) && z_##type##_is_infinity(object.y);}		\
												\
												\
static Z_INLINE											\
zboolean z_2d_##type##_is_nan(Z2D##Type object)							\
	{return z_##type##_is_nan(object.x) && z_##type##_is_nan(object.y);}			\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_lerp(Z2D##Type a, Z2D##Type b, z##type t)				\
	{return z_2d_##type(z_##type##_lerp(a.x, b.x, t), z_##type##_lerp(a.y, b.y, t));}	\
												\
												\
static Z_INLINE											\
Z2D##Type z_2d_##type##_reciprocal(Z2D##Type object)						\
	{return z_2d_##type(((z##type)1) / object.x, ((z##type)1) / object.y);}


#define z_2d_type_are_almost_equal(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _are_almost_equal)
#define z_2d_type_clamp_01(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _clamp_01	      )
#define z_2d_type_has_almost_zero( TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_almost_zero )
#define z_2d_type_has_finite(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_finite      )
#define z_2d_type_has_infinity(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_infinity    )
#define z_2d_type_has_nan(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _has_nan	      )
#define z_2d_type_inverse_lerp(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _inverse_lerp    )
#define z_2d_type_is_almost_zero(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_almost_zero  )
#define z_2d_type_is_finite(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_finite	      )
#define z_2d_type_is_infinity(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_infinity     )
#define z_2d_type_is_nan(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _is_nan	      )
#define z_2d_type_lerp(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _lerp	      )
#define z_2d_type_reciprocal(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _reciprocal      )


/* MARK: - Implementation expansions */


Z_IMPLEMENTATION_COMMON (UInt8,  uint8 )
Z_IMPLEMENTATION_COMMON (SInt8,  sint8 )
Z_IMPLEMENTATION_SIGNED (SInt8,  sint8 )
Z_IMPLEMENTATION_INTEGER(SInt8,  sint8 )
Z_IMPLEMENTATION_COMMON (UInt16, uint16)
Z_IMPLEMENTATION_COMMON (SInt16, sint16)
Z_IMPLEMENTATION_SIGNED (SInt16, sint16)
Z_IMPLEMENTATION_INTEGER(SInt16, sint16)
Z_IMPLEMENTATION_COMMON (UInt32, uint32)
Z_IMPLEMENTATION_COMMON (SInt32, sint32)
Z_IMPLEMENTATION_SIGNED (SInt32, sint32)
Z_IMPLEMENTATION_INTEGER(SInt32, sint32)

#ifdef Z_UINT64
	Z_IMPLEMENTATION_COMMON(UInt64, uint64)
#endif

#ifdef Z_SINT64
	Z_IMPLEMENTATION_COMMON (SInt64, sint64)
	Z_IMPLEMENTATION_SIGNED (SInt64, sint64)
	Z_IMPLEMENTATION_INTEGER(SInt64, sint64)
#endif

#ifdef Z_UINT128
	Z_IMPLEMENTATION_COMMON(UInt128, uint128)
#endif

#ifdef Z_SINT128
	Z_IMPLEMENTATION_COMMON (SInt128, sint128)
	Z_IMPLEMENTATION_SIGNED (SInt128, sint128)
	Z_IMPLEMENTATION_INTEGER(SInt128, sint128)
#endif

#ifdef Z_FLOAT16
	Z_IMPLEMENTATION_COMMON(Float16, float16)
	Z_IMPLEMENTATION_SIGNED(Float16, float16)
	Z_IMPLEMENTATION_REAL  (Float16, float16, Z_FLOAT16_EPSILON)
#endif

#ifdef Z_FLOAT32
	Z_IMPLEMENTATION_COMMON(Float32, float32)
	Z_IMPLEMENTATION_SIGNED(Float32, float32)
	Z_IMPLEMENTATION_REAL  (Float32, float32, Z_FLOAT32_EPSILON)
#endif

#ifdef Z_FLOAT64
	Z_IMPLEMENTATION_COMMON(Float64, float64)
	Z_IMPLEMENTATION_SIGNED(Float64, float64)
	Z_IMPLEMENTATION_REAL  (Float64, float64, Z_FLOAT64_EPSILON)
#endif

#ifdef Z_FLOAT128
	Z_IMPLEMENTATION_COMMON(Float128, float128)
	Z_IMPLEMENTATION_SIGNED(Float128, float128)
	Z_IMPLEMENTATION_REAL  (Float128, float128, Z_FLOAT128_EPSILON)
#endif

#ifdef Z_FLOAT80_X87
	Z_IMPLEMENTATION_COMMON(Float80_x87, float80_x87)
	Z_IMPLEMENTATION_SIGNED(Float80_x87, float80_x87)
	Z_IMPLEMENTATION_REAL  (Float80_x87, float80_x87, Z_FLOAT80_X87_EPSILON)
#endif

#ifdef Z_FLOAT96_X87
	Z_IMPLEMENTATION_COMMON(Float96_x87, float96_x87)
	Z_IMPLEMENTATION_SIGNED(Float96_x87, float96_x87)
	Z_IMPLEMENTATION_REAL  (Float96_x87, float96_x87, Z_FLOAT96_X87_EPSILON)
#endif

#ifdef Z_FLOAT128_X87
	Z_IMPLEMENTATION_COMMON(Float128_x87, float128_x87)
	Z_IMPLEMENTATION_SIGNED(Float128_x87, float128_x87)
	Z_IMPLEMENTATION_REAL  (Float128_x87, float128_x87, Z_FLOAT128_X87_EPSILON)
#endif


/* MARK: - Cleanup */


#undef Z_IMPLEMENTATION_COMMON
#undef Z_IMPLEMENTATION_SIGNED
#undef Z_IMPLEMENTATION_INTEGER
#undef Z_IMPLEMENTATION_REAL


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_2d_absolute	       z_2d_type_absolute	   (REAL)
#	define z_2d_add		       z_2d_type_add		   (REAL)
#	define z_2d_add_3	       z_2d_type_add_3		   (REAL)
#	define z_2d_add_4	       z_2d_type_add_4		   (REAL)
#	define z_2d_add_scalar	       z_2d_type_add_scalar	   (REAL)
#	define z_2d_are_almost_equal   z_2d_type_are_almost_equal  (REAL)
#	define z_2d_are_equal	       z_2d_type_are_equal	   (REAL)
#	define z_2d_are_perpendicular  z_2d_type_are_perpendicular (REAL)
#	define z_2d_clamp	       z_2d_type_clamp		   (REAL)
#	define z_2d_clamp_01	       z_2d_type_clamp_01	   (REAL)
#	define z_2d_cross_product      z_2d_type_cross_product	   (REAL)
#	define z_2d_divide	       z_2d_type_divide		   (REAL)
#	define z_2d_divide_3	       z_2d_type_divide_3	   (REAL)
#	define z_2d_divide_4	       z_2d_type_divide_4	   (REAL)
#	define z_2d_divide_by_scalar   z_2d_type_divide_by_scalar  (REAL)
#	define z_2d_dot_product	       z_2d_type_dot_product	   (REAL)
#	define z_2d_fit		       z_2d_type_fit		   (REAL)
#	define z_2d_from_scalar	       z_2d_type_from_scalar	   (REAL)
#	define z_2d_has_almost_zero    z_2d_type_has_almost_zero   (REAL)
#	define z_2d_has_finite	       z_2d_type_has_finite	   (REAL)
#	define z_2d_has_infinity       z_2d_type_has_infinity	   (REAL)
#	define z_2d_has_nan	       z_2d_type_has_nan	   (REAL)
#	define z_2d_has_negative       z_2d_type_has_negative	   (REAL)
#	define z_2d_has_zero	       z_2d_type_has_zero	   (REAL)
#	define z_2d_inner_maximum      z_2d_type_inner_maximum	   (REAL)
#	define z_2d_inner_middle       z_2d_type_inner_middle	   (REAL)
#	define z_2d_inner_minimum      z_2d_type_inner_minimum	   (REAL)
#	define z_2d_inner_product      z_2d_type_inner_product	   (REAL)
#	define z_2d_inner_sum	       z_2d_type_inner_sum	   (REAL)
#	define z_2d_inverse_lerp       z_2d_type_inverse_lerp	   (REAL)
#	define z_2d_is_almost_zero     z_2d_type_is_almost_zero	   (REAL)
#	define z_2d_is_finite	       z_2d_type_is_finite	   (REAL)
#	define z_2d_is_infinity	       z_2d_type_is_infinity	   (REAL)
#	define z_2d_is_nan	       z_2d_type_is_nan		   (REAL)
#	define z_2d_is_negative	       z_2d_type_is_negative	   (REAL)
#	define z_2d_is_zero	       z_2d_type_is_zero	   (REAL)
#	define z_2d_lerp	       z_2d_type_lerp		   (REAL)
#	define z_2d_maximum	       z_2d_type_maximum	   (REAL)
#	define z_2d_middle	       z_2d_type_middle		   (REAL)
#	define z_2d_minimum	       z_2d_type_minimum	   (REAL)
#	define z_2d_multiply	       z_2d_type_multiply	   (REAL)
#	define z_2d_multiply_3	       z_2d_type_multiply_3	   (REAL)
#	define z_2d_multiply_4	       z_2d_type_multiply_4	   (REAL)
#	define z_2d_multiply_by_scalar z_2d_type_multiply_by_scalar(REAL)
#	define z_2d_negative	       z_2d_type_negative	   (REAL)
#	define z_2d_nxy		       z_2d_type_nxy		   (REAL)
#	define z_2d_nyx		       z_2d_type_nyx		   (REAL)
#	define z_2d_reciprocal	       z_2d_type_reciprocal	   (REAL)
#	define z_2d_square_clamp       z_2d_type_square_clamp	   (REAL)
#	define z_2d_squared_length     z_2d_type_squared_length	   (REAL)
#	define z_2d_subtract	       z_2d_type_subtract	   (REAL)
#	define z_2d_subtract_3	       z_2d_type_subtract_3	   (REAL)
#	define z_2d_subtract_4	       z_2d_type_subtract_4	   (REAL)
#	define z_2d_subtract_scalar    z_2d_type_subtract_scalar   (REAL)
#	define z_2d_swap	       z_2d_type_swap		   (REAL)
#	define z_2d_xny		       z_2d_type_xny		   (REAL)
#	define z_2d_xyn		       z_2d_type_xyn		   (REAL)
#	define z_2d_ynx		       z_2d_type_ynx		   (REAL)
#	define z_2d_yx		       z_2d_type_yx		   (REAL)
#	define z_2d_yxn		       z_2d_type_yxn		   (REAL)
#endif


#endif /* _Z_functions_base_Z2D_H_ */
