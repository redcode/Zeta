/* Z Kit - functions/mathematics/geometry/euclidean/ZSphere.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_mathematics_geometry_euclidean_ZSphere_H_
#define _Z_functions_mathematics_geometry_euclidean_ZSphere_H_

#include <Z/functions/mathematics/geometry/euclidean/constructors.h>
#include <Z/functions/base/Z3D.h>
#include <Z/constants/numbers.h>


/* MARK: - Implementation */


#define Z_IMPLEMENTATION(Type, type, _)								\
												\
static Z_INLINE											\
zboolean z_sphere_##type##_are_equal(ZSphere##Type a, ZSphere##Type b)				\
	{return a.radius == b.radius && z_3d_##type##_are_equal(a.point, b.point);}		\
												\
												\
static Z_INLINE											\
ZAABB##Type z_sphere_##type##_inner_aabb(ZSphere##Type object)					\
	{											\
	z##type half_size = object.radius / _(Z_SQUARE_ROOT_3);					\
												\
	return z_aabb_##type									\
		(object.point.x - half_size,							\
		 object.point.y - half_size,							\
		 object.point.z - half_size,							\
		 object.point.x + half_size,							\
		 object.point.y + half_size,							\
		 object.point.z + half_size);							\
	}											\
												\
												\
static Z_INLINE											\
ZBox##Type z_sphere_##type##_inner_box(ZSphere##Type object)					\
	{											\
	z##type half_size = object.radius / _(Z_SQUARE_ROOT_3);					\
	z##type size = half_size * _(2.0);							\
												\
	return z_box_##type									\
		(object.point.x - half_size,							\
		 object.point.y - half_size,							\
		 object.point.z - half_size,							\
		 size, size, size);								\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_sphere_##type##_is_zero(ZSphere##Type object)					\
	{return object.radius == _(0.0) && z_3d_##type##_is_zero(object.point);}		\
												\
												\
static Z_INLINE											\
ZAABB##Type z_sphere_##type##_outer_aabb(ZSphere##Type object)					\
	{											\
	return z_aabb_##type									\
		(object.point.x - object.radius,						\
		 object.point.y - object.radius,						\
		 object.point.z - object.radius,						\
		 object.point.x + object.radius,						\
		 object.point.y + object.radius,						\
		 object.point.z + object.radius);						\
	}											\
												\
												\
static Z_INLINE											\
ZBox##Type z_sphere_##type##_outer_box(ZSphere##Type object)					\
	{											\
	z##type size = object.radius * _(2.0);							\
												\
	return z_box_##type									\
		(object.point.x - object.radius,						\
		 object.point.y - object.radius,						\
		 object.point.z - object.radius,						\
		 size, size, size);								\
	}											\
												\
												\
static Z_INLINE											\
void z_sphere_##type##_swap(ZSphere##Type *a, ZSphere##Type *b)					\
	{											\
	ZSphere##Type t = *a;									\
												\
	*a = *b; *b = t;									\
	}


#define z_sphere_type_are_equal( TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _are_equal )
#define z_sphere_type_inner_aabb(TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _inner_aabb)
#define z_sphere_type_inner_box( TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _inner_box )
#define z_sphere_type_is_zero(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _is_zero	  )
#define z_sphere_type_outer_aabb(TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _outer_aabb)
#define z_sphere_type_outer_box( TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _outer_box )
#define z_sphere_type_swap(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _swap	  )


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
#	define z_sphere_are_equal  z_sphere_type_are_equal (REAL)
#	define z_sphere_inner_aabb z_sphere_type_inner_aabb(REAL)
#	define z_sphere_inner_box  z_sphere_type_inner_box (REAL)
#	define z_sphere_is_zero	   z_sphere_type_is_zero   (REAL)
#	define z_sphere_outer_aabb z_sphere_type_outer_aabb(REAL)
#	define z_sphere_outer_box  z_sphere_type_outer_box (REAL)
#	define z_sphere_swap	   z_sphere_type_swap	   (REAL)
#endif


#endif /* _Z_functions_mathematics_geometry_euclidean_ZSphere_H_ */
