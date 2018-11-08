/* Z Kit - functions/mathematics/geometry/euclidean/ZCircle.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_mathematics_geometry_euclidean_ZCircle_H_
#define _Z_functions_mathematics_geometry_euclidean_ZCircle_H_

#include <Z/functions/mathematics/geometry/euclidean/constructors.h>
#include <Z/functions/base/Z2D.h>
#include <Z/constants/numbers.h>


/* MARK: - Implementation */


#define Z_IMPLEMENTATION(Type, type, _)								\
												\
static Z_INLINE											\
zboolean z_circle_##type##_are_equal(ZCircle##Type a, ZCircle##Type b)				\
	{return a.radius == b.radius && z_2d_##type##_are_equal(a.point, b.point);}		\
												\
												\
static Z_INLINE											\
ZAABR##Type z_circle_##type##_inner_aabr(ZCircle##Type object)					\
	{											\
	z##type half_size = object.radius / _(Z_SQUARE_ROOT_2);					\
												\
	return z_aabr_##type									\
		(object.point.x - half_size, object.point.y - half_size,			\
		 object.point.x + half_size, object.point.x + half_size);			\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_circle_##type##_inner_rectangle(ZCircle##Type object)			\
	{											\
	z##type half_size = object.radius / _(Z_SQUARE_ROOT_2);					\
	z##type size = half_size * _(2.0);							\
												\
	return z_rectangle_##type								\
		(object.point.x - half_size, object.point.y - half_size, size, size);		\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_circle_##type##_is_zero(ZCircle##Type object)					\
	{return object.radius == _(0.0) && z_2d_##type##_is_zero(object.point);}		\
												\
												\
static Z_INLINE											\
ZAABR##Type z_circle_##type##_outer_aabr(ZCircle##Type object)					\
	{											\
	return z_aabr_##type									\
		(object.point.x - object.radius, object.point.y - object.radius,		\
		 object.point.x + object.radius, object.point.y + object.radius);		\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_circle_##type##_outer_rectangle(ZCircle##Type object)			\
	{											\
	z##type size = object.radius * _(2.0);							\
												\
	return z_rectangle_##type								\
		(object.point.x - object.radius, object.point.y - object.radius, size, size);	\
	}											\
												\
												\
static Z_INLINE											\
void z_circle_##type##_swap(ZCircle##Type *a, ZCircle##Type *b)					\
	{											\
	ZCircle##Type t = *a;									\
												\
	*a = *b; *b = t;									\
	}


#define z_circle_type_are_equal(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _are_equal	    )
#define z_circle_type_inner_aabr(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _inner_aabr	    )
#define z_circle_type_inner_rectangle(TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _inner_rectangle)
#define z_circle_type_is_zero(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _is_zero	    )
#define z_circle_type_outer_aabr(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _outer_aabr	    )
#define z_circle_type_outer_rectangle(TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _outer_rectangle)
#define z_circle_type_swap(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _swap	    )


/* MARK: - Implementation expansions */


#ifdef Z_FLOAT16
	Z_IMPLEMENTATION(Float16, float16, Z_FLOAT16)
#endif

#ifdef Z_FLOAT32
	Z_IMPLEMENTATION(Float32, float32, Z_FLOAT32)
#endif

#ifdef Z_FLOAT64
	Z_IMPLEMENTATION(Float64, float64, Z_FLOAT64)
#endif

#ifdef Z_FLOAT128
	Z_IMPLEMENTATION(Float128, float128, Z_FLOAT128)
#endif

#ifdef Z_FLOAT80_X87
	Z_IMPLEMENTATION(Float80_x87, float80_x87, Z_FLOAT80_X87)
#endif

#ifdef Z_FLOAT96_X87
	Z_IMPLEMENTATION(Float96_x87, float96_x87, Z_FLOAT96_X87)
#endif

#ifdef Z_FLOAT128_X87
	Z_IMPLEMENTATION(Float128_x87, float128_x87, Z_FLOAT128_X87)
#endif


/* MARK: - Cleanup */


#undef Z_IMPLEMENTATION


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_circle_are_equal	z_circle_type_are_equal	     (REAL)
#	define z_circle_inner_aabr	z_circle_type_inner_aabr     (REAL)
#	define z_circle_inner_rectangle z_circle_type_inner_rectangle(REAL)
#	define z_circle_is_zero		z_circle_type_is_zero	     (REAL)
#	define z_circle_outer_aabr	z_circle_type_outer_aabr     (REAL)
#	define z_circle_outer_rectangle z_circle_type_outer_rectangle(REAL)
#	define z_circle_swap		z_circle_type_swap	     (REAL)
#endif


#endif /* _Z_functions_mathematics_geometry_euclidean_ZCircle_H_ */
