/* Z Kit C API - functions/base/Z3DValue.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_Z3DValue_H__
#define __Z_functions_base_Z3DValue_H__

#include <Z/functions/base/constructors.h>
#include <Z/functions/base/value.h>


/* MARK: - Implementation for natural, integer and real types */


#define Z_IMPLEMENTATION_3D_NATURAL(Type, type)							\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_add(Z3D##Type a, Z3D##Type b)					\
	{return z_3d_##type(a.x + b.x, a.y + b.y, a.z + b.z);}					\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_add_3(Z3D##Type a, Z3D##Type b, Z3D##Type c)			\
	{											\
	return z_3d_##type									\
		(a.x + b.x + c.x, a.y + b.y + c.y, a.z + b.z + c.z);				\
	}											\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_add_4(Z3D##Type a, Z3D##Type b, Z3D##Type c, Z3D##Type d)	\
	{											\
	return z_3d_##type									\
		(a.x + b.x + c.x + d.x, a.y + b.y + c.y + d.y, a.z + b.z + c.z + d.z);		\
	}											\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_add_scalar(Z3D##Type object, z##type scalar)			\
	{return z_3d_##type(object.x + scalar, object.y + scalar, object.z + scalar);}		\
												\
												\
Z_INLINE zboolean z_3d_##type##_are_equal(Z3D##Type a, Z3D##Type b)				\
	{return a.x == b.x && a.y == b.y && a.z == b.z;}					\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_clamp(Z3D##Type object, Z3D##Type minimum, Z3D##Type maximum)	\
	{											\
	return z_3d_##type									\
		(z_##type##_clamp(object.x, minimum.x, maximum.x),				\
		 z_##type##_clamp(object.y, minimum.y, maximum.y),				\
		 z_##type##_clamp(object.z, minimum.z, maximum.z));				\
	}											\
												\
												\
Z_INLINE zboolean z_3d_##type##_contains(Z3D##Type object, Z3D##Type value)			\
	{return object.x >= value.x && object.y >= value.y && object.z >= value.z;}		\
												\
												\
Z_INLINE zboolean z_3d_##type##_contains_scalar(Z3D##Type object, z##type scalar)		\
	{return object.x >= scalar && object.y >= scalar && object.z >= scalar;}		\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_cross_product(Z3D##Type a, Z3D##Type b)			\
	{											\
	return z_3d_##type									\
		(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); 		\
	}											\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_cube_clamp(Z3D##Type object, z##type minimum, z##type maximum)	\
	{											\
	return z_3d_##type									\
		(z_##type##_clamp(object.x, minimum, maximum),					\
		 z_##type##_clamp(object.y, minimum, maximum),					\
		 z_##type##_clamp(object.z, minimum, maximum));					\
	}											\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_divide(Z3D##Type a, Z3D##Type b)				\
	{return z_3d_##type(a.x / b.x, a.y / b.y, a.z / b.z);}					\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_divide_3(Z3D##Type a, Z3D##Type b, Z3D##Type c)		\
	{return z_3d_##type(a.x / b.x / c.x, a.y / b.y / c.y, a.z / b.z / c.z);}		\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_divide_4(Z3D##Type a, Z3D##Type b, Z3D##Type c, Z3D##Type d)	\
	{											\
	return z_3d_##type									\
		(a.x / b.x / c.x / d.x, a.y / b.y / c.y / d.y, a.z / b.z / c.z / d.z);		\
	}											\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_divide_by_scalar(Z3D##Type object, z##type scalar)		\
	{return z_3d_##type(object.x / scalar, object.y / scalar, object.z / scalar);}		\
												\
												\
Z_INLINE z##type z_3d_##type##_dot_product(Z3D##Type a, Z3D##Type b)				\
	{return a.x * b.x + a.y * b.y + a.y * b.y;}						\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_fit(Z3D##Type a, Z3D##Type b)					\
	{											\
	return z_3d_##type##_zero;/*a.y / a.x > b.y / b.x					\
		? z_3d_##type(a.x * b.y / a.y, b.y)						\
		: z_3d_##type(b.x, a.y * b.x / a.x);*/						\
	} /* TO DO */										\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_from_scalar(z##type scalar)					\
	{return z_3d_##type(scalar, scalar, scalar);}						\
												\
												\
Z_INLINE zboolean z_3d_##type##_has_zero(Z3D##Type object)					\
	{return object.x == (z##type)0 || object.y == (z##type)0 || object.z == (z##type)0;}	\
												\
												\
Z_INLINE z##type z_3d_##type##_inner_maximum(Z3D##Type object)					\
	{return z_##type##_maximum(z_##type##_maximum(object.x, object.y), object.z);}		\
												\
												\
Z_INLINE z##type z_3d_##type##_inner_middle(Z3D##Type object)					\
	{return (object.x + object.y + object.z) / (z##type)3;}					\
												\
												\
Z_INLINE z##type z_3d_##type##_inner_minimum(Z3D##Type object)					\
	{return z_##type##_minimum(z_##type##_minimum(object.x, object.y), object.z);}		\
												\
												\
Z_INLINE z##type z_3d_##type##_inner_product(Z3D##Type object)					\
	{return object.x * object.y * object.z;}						\
												\
												\
Z_INLINE z##type z_3d_##type##_inner_sum(Z3D##Type object)					\
	{return object.x + object.y + object.z;}						\
												\
												\
Z_INLINE zboolean z_3d_##type##_is_zero(Z3D##Type object)					\
	{return object.x == (z##type)0 && object.y == (z##type)0 && object.z == (z##type)0;}	\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_maximum(Z3D##Type a, Z3D##Type b)				\
	{											\
	return z_3d_##type									\
		(z_##type##_maximum(a.x, b.x),							\
		 z_##type##_maximum(a.y, b.y),							\
		 z_##type##_maximum(a.z, b.z));							\
	}											\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_middle(Z3D##Type a, Z3D##Type b)				\
	{											\
	return z_3d_##type									\
		((a.x + b.x) / (z##type)2, (a.y + b.y) / (z##type)2, (a.z + b.z) / (z##type)2);	\
	}											\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_minimum(Z3D##Type a, Z3D##Type b)				\
	{											\
	return z_3d_##type									\
		(z_##type##_minimum(a.x, b.x),							\
		 z_##type##_minimum(a.y, b.y),							\
		 z_##type##_minimum(a.z, b.z));							\
	}											\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_multiply(Z3D##Type a, Z3D##Type b)				\
	{return z_3d_##type(a.x * b.x, a.y * b.y, a.z * b.z);}					\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_multiply_3(Z3D##Type a, Z3D##Type b, Z3D##Type c)		\
	{return z_3d_##type(a.x * b.x * c.x, a.y * b.y * c.y, a.z * b.z * c.z);}		\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_multiply_4(Z3D##Type a, Z3D##Type b, Z3D##Type c, Z3D##Type d)	\
	{											\
	return z_3d_##type									\
		(a.x * b.x * c.x * d.x, a.y * b.y * c.y * d.y, a.z * b.z * c.z * d.z);		\
	}											\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_multiply_by_scalar(Z3D##Type object, z##type scalar)		\
	{return z_3d_##type(object.x * scalar, object.y * scalar, object.z * scalar);}		\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_rotate_as_axes(Z3D##Type object, Z3DInt8 rotation)		\
	{											\
	if ((rotation.x % 4) & 1) z_##type##_swap(&object.y, &object.z);			\
	if ((rotation.y % 4) & 1) z_##type##_swap(&object.x, &object.z);			\
	if ((rotation.z % 4) & 1) z_##type##_swap(&object.x, &object.y);			\
	return object;										\
	}											\
												\
												\
Z_INLINE z##type z_3d_##type##_squared_length(Z3D##Type object)					\
	{return object.x * object.x + object.y * object.y + object.z * object.z;}		\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_subtract(Z3D##Type a, Z3D##Type b)				\
	{return z_3d_##type(a.x - b.x, a.y - b.y, a.z - b.z);}					\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_subtract_3(Z3D##Type a, Z3D##Type b, Z3D##Type c)		\
	{return z_3d_##type(a.x - b.x - c.x, a.y - b.y - c.y, a.z - b.z - c.z);}		\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_subtract_4(Z3D##Type a, Z3D##Type b, Z3D##Type c, Z3D##Type d)	\
	{											\
	return z_3d_##type									\
		(a.x - b.x - c.x - d.x, a.y - b.y - c.y - d.y, a.z - b.z - c.z - d.z);		\
	}											\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_subtract_scalar(Z3D##Type object, z##type scalar)		\
	{return z_3d_##type(object.x - scalar, object.y - scalar, object.z - scalar);}		\
												\
												\
Z_INLINE void z_3d_##type##_swap(Z3D##Type *a, Z3D##Type *b)					\
	{											\
	Z3D##Type t = *a;									\
												\
	*a = *b; *b = t;									\
	}											\
												\
												\
Z_INLINE Z2D##Type z_3d_##type##_xy(Z3D##Type object)						\
	{return z_2d_##type(object.x, object.y);}						\
												\
												\
Z_INLINE Z2D##Type z_3d_##type##_xz(Z3D##Type object)						\
	{return z_2d_##type(object.x, object.z);}						\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_xzy(Z3D##Type object)						\
	{return z_3d_##type(object.x, object.z, object.y);}					\
												\
												\
Z_INLINE Z2D##Type z_3d_##type##_yx(Z3D##Type object)						\
	{return z_2d_##type(object.y, object.x);}						\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_yxz(Z3D##Type object)						\
	{return z_3d_##type(object.y, object.x, object.z);}					\
												\
												\
Z_INLINE Z2D##Type z_3d_##type##_yz(Z3D##Type object)						\
	{return z_2d_##type(object.y, object.z);}						\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_yzx(Z3D##Type object)						\
	{return z_3d_##type(object.y, object.z, object.x);}					\
												\
												\
Z_INLINE Z2D##Type z_3d_##type##_zx(Z3D##Type object)						\
	{return z_2d_##type(object.z, object.x);}						\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_zxy(Z3D##Type object)						\
	{return z_3d_##type(object.z, object.x, object.y);}					\
												\
												\
Z_INLINE Z2D##Type z_3d_##type##_zy(Z3D##Type object)						\
	{return z_2d_##type(object.z, object.y);}						\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_zyx(Z3D##Type object)						\
	{return z_3d_##type(object.z, object.y, object.x);}


#define z_3d_type_add(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _add		  )
#define z_3d_type_add_3(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _add_3		  )
#define z_3d_type_add_4(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _add_4		  )
#define z_3d_type_add_scalar(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _add_scalar	  )
#define z_3d_type_are_equal(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _are_equal	  )
#define z_3d_type_clamp(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _clamp		  )
#define z_3d_type_contains(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _contains	  )
#define z_3d_type_contains_scalar(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _contains_scalar	  )
#define z_3d_type_cross_product(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _cross_product	  )
#define z_3d_type_cube_clamp(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _cube_clamp	  )
#define z_3d_type_divide(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _divide		  )
#define z_3d_type_divide_3(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _divide_3	  )
#define z_3d_type_divide_4(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _divide_4	  )
#define z_3d_type_divide_by_scalar(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _divide_by_scalar  )
#define z_3d_type_dot_product(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _dot_product	  )
#define z_3d_type_fit(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _fit		  )
#define z_3d_type_from_scalar(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _from_scalar	  )
#define z_3d_type_has_zero(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _has_zero	  )
#define z_3d_type_inner_maximum(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _inner_maximum	  )
#define z_3d_type_inner_middle(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _inner_middle	  )
#define z_3d_type_inner_minimum(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _inner_minimum	  )
#define z_3d_type_inner_product(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _inner_product	  )
#define z_3d_type_inner_sum(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _inner_sum	  )
#define z_3d_type_is_zero(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _is_zero		  )
#define z_3d_type_maximum(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _maximum		  )
#define z_3d_type_middle(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _middle		  )
#define z_3d_type_minimum(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _minimum		  )
#define z_3d_type_multiply(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _multiply	  )
#define z_3d_type_multiply_3(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _multiply_3	  )
#define z_3d_type_multiply_4(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _multiply_4	  )
#define z_3d_type_multiply_by_scalar(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _multiply_by_scalar)
#define z_3d_type_rotate_as_axes(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _rotate_as_axes	  )
#define z_3d_type_squared_length(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _squared_length	  )
#define z_3d_type_subtract(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _subtract	  )
#define z_3d_type_subtract_3(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _subtract_3	  )
#define z_3d_type_subtract_4(	     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _subtract_4	  )
#define z_3d_type_subtract_scalar(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _subtract_scalar	  )
#define z_3d_type_swap(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _swap		  )
#define z_3d_type_xy(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _xy		  )
#define z_3d_type_xz(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _xz		  )
#define z_3d_type_xzy(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _xzy		  )
#define z_3d_type_yx(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _yx		  )
#define z_3d_type_yxz(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _yxz		  )
#define z_3d_type_yz(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _yz		  )
#define z_3d_type_yzx(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _yzx		  )
#define z_3d_type_zx(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _zx		  )
#define z_3d_type_zxy(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _zxy		  )
#define z_3d_type_zy(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _zy		  )
#define z_3d_type_zyx(		     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _zyx		  )


/* MARK: - Implementation for integer and real types */


#define Z_IMPLEMENTATION_3D_INTEGER(Type, type)							\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_absolute(Z3D##Type object)					\
	{											\
	return z_3d_##type									\
		(z_##type##_absolute(object.x),							\
		 z_##type##_absolute(object.y),							\
		 z_##type##_absolute(object.z));						\
	}											\
												\
												\
Z_INLINE zboolean z_3d_##type##_has_negative(Z3D##Type object)					\
	{return object.x < (z##type)0 || object.y < (z##type)0 || object.z < (z##type)0;}	\
												\
												\
Z_INLINE zboolean z_3d_##type##_is_negative(Z3D##Type object)					\
	{return object.x < (z##type)0 && object.y < (z##type)0 && object.z < (z##type)0;}	\
												\
												\
Z_INLINE Z3D##Type z_3d_##type##_negative(Z3D##Type object)					\
	{return z_3d_##type(-object.x, -object.y, -object.z);}


#define z_3d_type_absolute(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _absolute    )
#define z_3d_type_has_negative(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _has_negative)
#define z_3d_type_is_negative( TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _is_negative )
#define z_3d_type_negative(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _negative    )


/* MARK: - Implementation for real types */


#define Z_IMPLEMENTATION_3D_REAL(Type, type, _, epsilon)				\
											\
											\
Z_INLINE zboolean z_3d_##type##_are_almost_equal(Z3D##Type a, Z3D##Type b)		\
	{										\
	return	z_##type##_are_almost_equal(a.x, b.x) &&				\
		z_##type##_are_almost_equal(a.y, b.y) &&				\
		z_##type##_are_almost_equal(a.z, b.z);					\
	}										\
											\
											\
Z_INLINE zboolean z_3d_##type##_are_perpendicular(Z3D##Type a, Z3D##Type b)		\
	{return z_##type##_absolute(z_3d_##type##_dot_product(a, b)) <= epsilon;}	\
											\
											\
Z_INLINE Z3D##Type z_3d_##type##_clamp_01(Z3D##Type object)				\
	{										\
	return z_3d_##type								\
		(z_##type##_clamp_01(object.x),						\
		 z_##type##_clamp_01(object.y),						\
		 z_##type##_clamp_01(object.z));					\
	}										\
											\
											\
Z_INLINE zboolean z_3d_##type##_has_almost_zero(Z3D##Type object)			\
	{										\
	return	z_##type##_is_almost_zero(object.x) ||					\
		z_##type##_is_almost_zero(object.y) ||					\
		z_##type##_is_almost_zero(object.z);					\
	}										\
											\
											\
Z_INLINE zboolean z_3d_##type##_has_finite(Z3D##Type object)				\
	{										\
	return	z_##type##_is_finite(object.x) ||					\
		z_##type##_is_finite(object.y) ||					\
		z_##type##_is_finite(object.z);						\
	}										\
											\
											\
Z_INLINE zboolean z_3d_##type##_has_infinity(Z3D##Type object)				\
	{										\
	return	z_##type##_is_infinity(object.x) ||					\
		z_##type##_is_infinity(object.y) ||					\
		z_##type##_is_infinity(object.z);					\
	}										\
											\
											\
Z_INLINE zboolean z_3d_##type##_has_nan(Z3D##Type object)				\
	{										\
	return	z_##type##_is_nan(object.x) ||						\
		z_##type##_is_nan(object.y) ||						\
		z_##type##_is_nan(object.z);						\
	}										\
											\
											\
Z_INLINE Z3D##Type z_3d_##type##_inverse_lerp(Z3D##Type a, Z3D##Type b, z##type t)	\
	{										\
	return z_3d_##type								\
		(z_##type##_inverse_lerp(a.x, b.x, t),					\
		 z_##type##_inverse_lerp(a.y, b.y, t),					\
		 z_##type##_inverse_lerp(a.z, b.z, t));					\
	}										\
											\
											\
Z_INLINE zboolean z_3d_##type##_is_almost_zero(Z3D##Type object)			\
	{										\
	return	z_##type##_is_almost_zero(object.x) &&					\
		z_##type##_is_almost_zero(object.y) &&					\
		z_##type##_is_almost_zero(object.z);					\
	}										\
											\
											\
Z_INLINE zboolean z_3d_##type##_is_finite(Z3D##Type object)				\
	{										\
	return	z_##type##_is_finite(object.x) &&					\
		z_##type##_is_finite(object.y) &&					\
		z_##type##_is_finite(object.z);						\
	}										\
											\
											\
Z_INLINE zboolean z_3d_##type##_is_infinity(Z3D##Type object)				\
	{										\
	return	z_##type##_is_infinity(object.x) &&					\
		z_##type##_is_infinity(object.y) &&					\
		z_##type##_is_infinity(object.z);					\
	}										\
											\
											\
Z_INLINE zboolean z_3d_##type##_is_nan(Z3D##Type object)				\
	{										\
	return	z_##type##_is_nan(object.x) &&						\
		z_##type##_is_nan(object.y) &&						\
		z_##type##_is_nan(object.z);						\
	}										\
											\
											\
Z_INLINE Z3D##Type z_3d_##type##_lerp(Z3D##Type a, Z3D##Type b, z##type t)		\
	{										\
	return z_3d_##type								\
		(z_##type##_lerp(a.x, b.x, t),						\
		 z_##type##_lerp(a.y, b.y, t),						\
		 z_##type##_lerp(a.z, b.z, t));						\
	}										\
											\
											\
Z_INLINE Z3D##Type z_3d_##type##_reciprocal(Z3D##Type object)				\
	{return z_3d_##type(_(1.0) / object.x, _(1.0) / object.y, _(1.0) / object.z);}


#define z_3d_type_are_almost_equal( VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _are_almost_equal )
#define z_3d_type_are_perpendicular(VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _are_perpendicular)
#define z_3d_type_clamp_01(	    VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _clamp_01	 )
#define z_3d_type_has_almost_zero(  VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _has_almost_zero  )
#define z_3d_type_has_finite(	    VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _has_finite	 )
#define z_3d_type_has_infinity(	    VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _has_infinity	 )
#define z_3d_type_has_nan(	    VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _has_nan		 )
#define z_3d_type_inverse_lerp(	    VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _inverse_lerp	 )
#define z_3d_type_is_almost_zero(   VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _is_almost_zero	 )
#define z_3d_type_is_finite(	    VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _is_finite	 )
#define z_3d_type_is_infinity(	    VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _is_infinity	 )
#define z_3d_type_is_nan(	    VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _is_nan		 )
#define z_3d_type_lerp(		    VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _lerp		 )
#define z_3d_type_reciprocal(	    VALUE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _reciprocal	 )


/* MARK: - Implementation expansions */


Z_IMPLEMENTATION_3D_NATURAL(UInt8,  uint8 )
Z_IMPLEMENTATION_3D_NATURAL(UInt16, uint16)
Z_IMPLEMENTATION_3D_NATURAL(UInt32, uint32)

#ifdef Z_UINT64
	Z_IMPLEMENTATION_3D_NATURAL(UInt64, uint64)
#endif

#ifdef Z_UINT128
	Z_IMPLEMENTATION_3D_NATURAL(UInt128, uint128)
#endif

Z_IMPLEMENTATION_3D_NATURAL(Int8,  int8 )
Z_IMPLEMENTATION_3D_INTEGER(Int8,  int8 )
Z_IMPLEMENTATION_3D_NATURAL(Int16, int16)
Z_IMPLEMENTATION_3D_INTEGER(Int16, int16)
Z_IMPLEMENTATION_3D_NATURAL(Int32, int32)
Z_IMPLEMENTATION_3D_INTEGER(Int32, int32)

#ifdef Z_INT64
	Z_IMPLEMENTATION_3D_NATURAL(Int64, int64)
	Z_IMPLEMENTATION_3D_INTEGER(Int64, int64)
#endif

#ifdef Z_INT128
	Z_IMPLEMENTATION_3D_NATURAL(Int128, int128)
	Z_IMPLEMENTATION_3D_INTEGER(Int128, int128)
#endif

#ifdef Z_FLOAT16
	Z_IMPLEMENTATION_3D_NATURAL(Float16, float16)
	Z_IMPLEMENTATION_3D_INTEGER(Float16, float16)
	Z_IMPLEMENTATION_3D_REAL   (Float16, float16, Z_FLOAT16, Z_FLOAT16_EPSILON)
#endif

#ifdef Z_FLOAT24
	Z_IMPLEMENTATION_3D_NATURAL(Float24, float24)
	Z_IMPLEMENTATION_3D_INTEGER(Float24, float24)
	Z_IMPLEMENTATION_3D_REAL   (Float24, float24, Z_FLOAT24, Z_FLOAT24_EPSILON)
#endif

#ifdef Z_FLOAT32
	Z_IMPLEMENTATION_3D_NATURAL(Float32, float32)
	Z_IMPLEMENTATION_3D_INTEGER(Float32, float32)
	Z_IMPLEMENTATION_3D_REAL   (Float32, float32, Z_FLOAT32, Z_FLOAT32_EPSILON)
#endif

#ifdef Z_FLOAT48
	Z_IMPLEMENTATION_3D_NATURAL(Float48, float48)
	Z_IMPLEMENTATION_3D_INTEGER(Float48, float48)
	Z_IMPLEMENTATION_3D_REAL   (Float48, float48, Z_FLOAT48, Z_FLOAT48_EPSILON)
#endif

#ifdef Z_FLOAT64
	Z_IMPLEMENTATION_3D_NATURAL(Float64, float64)
	Z_IMPLEMENTATION_3D_INTEGER(Float64, float64)
	Z_IMPLEMENTATION_3D_REAL   (Float64, float64, Z_FLOAT64, Z_FLOAT64_EPSILON)
#endif

#ifdef Z_FLOAT72
	Z_IMPLEMENTATION_3D_NATURAL(Float72, float72)
	Z_IMPLEMENTATION_3D_INTEGER(Float72, float72)
	Z_IMPLEMENTATION_3D_REAL   (Float72, float72, Z_FLOAT72, Z_FLOAT72_EPSILON)
#endif

#ifdef Z_FLOAT80
	Z_IMPLEMENTATION_3D_NATURAL(Float80, float80)
	Z_IMPLEMENTATION_3D_INTEGER(Float80, float80)
	Z_IMPLEMENTATION_3D_REAL   (Float80, float80, Z_FLOAT80, Z_FLOAT80_EPSILON)
#endif

#ifdef Z_FLOAT96
	Z_IMPLEMENTATION_3D_NATURAL(Float96, float96)
	Z_IMPLEMENTATION_3D_INTEGER(Float96, float96)
	Z_IMPLEMENTATION_3D_REAL   (Float96, float96, Z_FLOAT96, Z_FLOAT96_EPSILON)
#endif

#ifdef Z_FLOAT128
	Z_IMPLEMENTATION_3D_NATURAL(Float128, float128)
	Z_IMPLEMENTATION_3D_INTEGER(Float128, float128)
	Z_IMPLEMENTATION_3D_REAL   (Float128, float128, Z_FLOAT128, Z_FLOAT128_EPSILON)
#endif


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_3d_absolute	       z_3d_type_absolute	   (REAL)
#	define z_3d_add		       z_3d_type_add		   (REAL)
#	define z_3d_add_3	       z_3d_type_add_3		   (REAL)
#	define z_3d_add_4	       z_3d_type_add_4		   (REAL)
#	define z_3d_add_scalar	       z_3d_type_add_scalar	   (REAL)
#	define z_3d_are_almost_equal   z_3d_type_are_almost_equal  (REAL)
#	define z_3d_are_equal	       z_3d_type_are_equal	   (REAL)
#	define z_3d_are_perpendicular  z_3d_type_are_perpendicular (REAL)
#	define z_3d_clamp	       z_3d_type_clamp		   (REAL)
#	define z_3d_clamp_01	       z_3d_type_clamp_01	   (REAL)
#	define z_3d_contains	       z_3d_type_contains	   (REAL)
#	define z_3d_contains_scalar    z_3d_type_contains_scalar   (REAL)
#	define z_3d_cross_product      z_3d_type_cross_product	   (REAL)
#	define z_3d_cube_clamp	       z_3d_type_cube_clamp	   (REAL)
#	define z_3d_divide	       z_3d_type_divide		   (REAL)
#	define z_3d_divide_3	       z_3d_type_divide_3	   (REAL)
#	define z_3d_divide_4	       z_3d_type_divide_4	   (REAL)
#	define z_3d_divide_by_scalar   z_3d_type_divide_by_scalar  (REAL)
#	define z_3d_dot_product	       z_3d_type_dot_product	   (REAL)
#	define z_3d_fit		       z_3d_type_fit		   (REAL)
#	define z_3d_from_scalar	       z_3d_type_from_scalar	   (REAL)
#	define z_3d_has_almost_zero    z_3d_type_has_almost_zero   (REAL)
#	define z_3d_has_finite	       z_3d_type_has_finite	   (REAL)
#	define z_3d_has_infinity       z_3d_type_has_infinity	   (REAL)
#	define z_3d_has_nan	       z_3d_type_has_nan	   (REAL)
#	define z_3d_has_negative       z_3d_type_has_negative	   (REAL)
#	define z_3d_has_zero	       z_3d_type_has_zero	   (REAL)
#	define z_3d_inner_maximum      z_3d_type_inner_maximum	   (REAL)
#	define z_3d_inner_middle       z_3d_type_inner_middle	   (REAL)
#	define z_3d_inner_minimum      z_3d_type_inner_minimum	   (REAL)
#	define z_3d_inner_product      z_3d_type_inner_product	   (REAL)
#	define z_3d_inner_sum	       z_3d_type_inner_sum	   (REAL)
#	define z_3d_inverse_lerp       z_3d_type_inverse_lerp	   (REAL)
#	define z_3d_is_almost_zero     z_3d_type_is_almost_zero	   (REAL)
#	define z_3d_is_finite	       z_3d_type_is_finite	   (REAL)
#	define z_3d_is_infinity	       z_3d_type_is_infinity	   (REAL)
#	define z_3d_is_nan	       z_3d_type_is_nan		   (REAL)
#	define z_3d_is_negative	       z_3d_type_is_negative	   (REAL)
#	define z_3d_is_zero	       z_3d_type_is_zero	   (REAL)
#	define z_3d_lerp	       z_3d_type_lerp		   (REAL)
#	define z_3d_maximum	       z_3d_type_maximum	   (REAL)
#	define z_3d_middle	       z_3d_type_middle		   (REAL)
#	define z_3d_minimum	       z_3d_type_minimum	   (REAL)
#	define z_3d_multiply	       z_3d_type_multiply	   (REAL)
#	define z_3d_multiply_3	       z_3d_type_multiply_3	   (REAL)
#	define z_3d_multiply_4	       z_3d_type_multiply_4	   (REAL)
#	define z_3d_multiply_by_scalar z_3d_type_multiply_by_scalar(REAL)
#	define z_3d_negative	       z_3d_type_negative	   (REAL)
#	define z_3d_reciprocal	       z_3d_type_reciprocal	   (REAL)
#	define z_3d_rotate_as_axes     z_3d_type_rotate_as_axes	   (REAL)
#	define z_3d_squared_length     z_3d_type_squared_length	   (REAL)
#	define z_3d_subtract	       z_3d_type_subtract	   (REAL)
#	define z_3d_subtract_3	       z_3d_type_subtract_3	   (REAL)
#	define z_3d_subtract_4	       z_3d_type_subtract_4	   (REAL)
#	define z_3d_subtract_scalar    z_3d_type_subtract_scalar   (REAL)
#	define z_3d_swap	       z_3d_type_swap		   (REAL)
#	define z_3d_xy		       z_3d_type_xy		   (REAL)
#	define z_3d_xz		       z_3d_type_xz		   (REAL)
#	define z_3d_xzy		       z_3d_type_xzy		   (REAL)
#	define z_3d_yx		       z_3d_type_yx		   (REAL)
#	define z_3d_yxz		       z_3d_type_yxz		   (REAL)
#	define z_3d_yz		       z_3d_type_yz		   (REAL)
#	define z_3d_yzx		       z_3d_type_yzx		   (REAL)
#	define z_3d_zx		       z_3d_type_zx		   (REAL)
#	define z_3d_zxy		       z_3d_type_zxy		   (REAL)
#	define z_3d_zy		       z_3d_type_zy		   (REAL)
#	define z_3d_zyx		       z_3d_type_zyx		   (REAL)
#endif


#endif /* __Z_functions_base_Z3DValue_H__ */
