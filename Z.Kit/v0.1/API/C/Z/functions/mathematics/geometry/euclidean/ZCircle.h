/* Z Kit C API - functions/mathematics/geometry/euclidean/ZCircle.h
 _____ 	_______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_mathematics_geometry_euclidean_ZCircle_H__
#define __Z_functions_mathematics_geometry_euclidean_ZCircle_H__

#include <Z/functions/mathematics/geometry/euclidean/constructors.h>
#include <Z/functions/base/Z2DValue.h>
#include <Z/constants/numbers.h>


/* MARK: - Implementation */


#define Z_IMPLEMENTATION_CIRCLE(Type, type, _)							\
												\
												\
Z_INLINE zboolean z_circle_##type##_are_equal(ZCircle##Type a, ZCircle##Type b)			\
	{return a.radius == b.radius && z_2d_##type##_are_equal(a.point, b.point);}		\
												\
												\
Z_INLINE zboolean z_circle_##type##_is_zero(ZCircle##Type object)				\
	{return object.radius == _(0.0) && z_2d_##type##_is_zero(object.point);}		\
												\
												\
Z_INLINE ZRectangle##Type z_circle_##type##_inner_rectangle(ZCircle##Type object)		\
	{											\
	z##type half_size = object.radius / _(Z_SQUARE_ROOT_2);					\
	z##type size = half_size * _(2.0);							\
												\
	return z_rectangle_##type								\
		(object.point.x - half_size, object.point.y - half_size, size, size);		\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_circle_##type##_outer_rectangle(ZCircle##Type object)		\
	{											\
	z##type size = object.radius * _(2.0);							\
												\
	return z_rectangle_##type								\
		(object.point.x - object.radius, object.point.y - object.radius, size, size);	\
	}


#define z_circle_type_are_equal(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _are_equal	    )
#define z_circle_type_is_zero(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _is_zero	    )
#define z_circle_type_inner_rectangle(TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _inner_rectangle)
#define z_circle_type_outer_rectangle(TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_, _outer_rectangle)


/* MARK: - Implementation expansions */


#ifdef Z_FLOAT16
	Z_IMPLEMENTATION_CIRCLE(Float16, float16, Z_FLOAT16)
#endif

#ifdef Z_FLOAT24
	Z_IMPLEMENTATION_CIRCLE(Float24, float24, Z_FLOAT24)
#endif

#ifdef Z_FLOAT32
	Z_IMPLEMENTATION_CIRCLE(Float32, float32, Z_FLOAT32)
#endif

#ifdef Z_FLOAT48
	Z_IMPLEMENTATION_CIRCLE(Float48, float48, Z_FLOAT48)
#endif

#ifdef Z_FLOAT64
	Z_IMPLEMENTATION_CIRCLE(Float64, float64, Z_FLOAT64)
#endif

#ifdef Z_FLOAT72
	Z_IMPLEMENTATION_CIRCLE(Float72, float72, Z_FLOAT72)
#endif

#ifdef Z_FLOAT80
	Z_IMPLEMENTATION_CIRCLE(Float80, float80, Z_FLOAT80)
#endif

#ifdef Z_FLOAT96
	Z_IMPLEMENTATION_CIRCLE(Float96, float96, Z_FLOAT96)
#endif

#ifdef Z_FLOAT128
	Z_IMPLEMENTATION_CIRCLE(Float128, float128, Z_FLOAT128)
#endif


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_circle_are_equal	z_circle_type_are_equal	     (REAL)
#	define z_circle_is_zero		z_circle_type_is_zero	     (REAL)
#	define z_circle_inner_rectangle z_circle_type_inner_rectangle(REAL)
#	define z_circle_outer_rectangle z_circle_type_outer_rectangle(REAL)
#endif


#endif /* __Z_functions_mathematics_geometry_euclidean_ZCircle_H__ */
