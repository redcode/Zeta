/* Z Kit C API - functions/geometry/ZSphere.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_ZSphere_H__
#define __Z_functions_geometry_ZSphere_H__

#include <Z/functions/geometry/constructors.h>
#include <Z/functions/base/Z3DValue.h>
#include <Z/constants/numbers.h>


#define Z_IMPLEMENTATION_SPHERE(Type, type, _)						\
											\
											\
Z_INLINE zboolean z_sphere_##type##_are_equal(ZSphere##Type a, ZSphere##Type b)		\
	{return a.radius == b.radius && z_3d_##type##_are_equal(a.point, b.point);}	\
											\
											\
Z_INLINE zboolean z_sphere_##type##_is_zero(ZSphere##Type object)			\
	{return object.radius == _(0.0) && z_3d_##type##_is_zero(object.point);}	\
											\
											\
Z_INLINE ZBox##Type z_sphere_##type##_inner_box(ZSphere##Type object)			\
	{										\
	z##type half_size = object.radius / _(Z_SQUARE_ROOT_3);				\
	z##type size = half_size * _(2.0);						\
											\
	return z_box_##type								\
		(object.point.x - half_size,						\
		 object.point.y - half_size,						\
		 object.point.z - half_size,						\
		 size, size, size);							\
	}										\
											\
											\
Z_INLINE ZBox##Type z_sphere_##type##_outer_box(ZSphere##Type object)			\
	{										\
	z##type size = object.radius * _(2.0);						\
											\
	return z_box_##type								\
		(object.point.x - object.radius,					\
		 object.point.y - object.radius,					\
		 object.point.z - object.radius,					\
		 size, size, size);							\
	}


Z_IMPLEMENTATION_SPHERE(Float,   float,	  Z_FLOAT  )
Z_IMPLEMENTATION_SPHERE(Double,  double,  Z_DOUBLE )
Z_IMPLEMENTATION_SPHERE(LDouble, ldouble, Z_LDOUBLE)


#define Z_JOIN_sphere_type_are_equal(type) Z_PASTE_3(z_sphere_, type, _are_equal)
#define Z_JOIN_sphere_type_is_zero(  type) Z_PASTE_3(z_sphere_, type, _is_zero	)
#define Z_JOIN_sphere_type_inner_box(type) Z_PASTE_3(z_sphere_, type, _inner_box)
#define Z_JOIN_sphere_type_outer_box(type) Z_PASTE_3(z_sphere_, type, _outer_box)


/* MARK: - Default real type definitions */


#define z_sphere_are_equal Z_JOIN_sphere_type_are_equal(Z_REAL_FIXED_TYPE_name)
#define z_sphere_is_zero   Z_JOIN_sphere_type_is_zero  (Z_REAL_FIXED_TYPE_name)
#define z_sphere_inner_box Z_JOIN_sphere_type_inner_box(Z_REAL_FIXED_TYPE_name)
#define z_sphere_outer_box Z_JOIN_sphere_type_outer_box(Z_REAL_FIXED_TYPE_name)


#endif /* __Z_functions_geometry_ZSphere_H__ */
