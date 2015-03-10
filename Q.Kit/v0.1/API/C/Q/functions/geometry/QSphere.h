/* Q Kit C API - functions/geometry/QSphere.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_QSphere_H__
#define __Q_functions_geometry_QSphere_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/base/Q3D.h>
#include <Q/constants/numbers.h>


#define Q_IMPLEMENTATION_SPHERE(Type, type, _, suffix)				\
										\
										\
Q_INLINE									\
qboolean q_##type##_sphere_are_equal(Q##Type##Sphere a, Q##Type##Sphere b)	\
	{									\
	return	a.radius == b.radius &&						\
		q_3d_##type##_are_equal(a.point, b.point);			\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_sphere_is_zero(Q##Type##Sphere sphere)		\
	{									\
	return	sphere.radius == _(0.0) &&					\
		q_3d_##type##_is_zero(sphere.point);				\
	}									\
										\
										\
Q_INLINE Q##Type##Box q_##type##_sphere_inner_box(Q##Type##Sphere sphere)	\
	{									\
	q##type half_size = sphere.radius / Q_JOIN_2(Q_SQUARE_ROOT_3, suffix);	\
	q##type size = half_size * _(2.0);					\
										\
	return q_##type##_box							\
		(sphere.point.x - half_size,					\
		 sphere.point.y - half_size,					\
		 sphere.point.z - half_size,					\
		 size, size, size);						\
	}									\
										\
										\
Q_INLINE Q##Type##Box q_##type##_sphere_outer_box(Q##Type##Sphere sphere)	\
	{									\
	q##type size = sphere.radius * _(2.0);					\
										\
	return q_##type##_box							\
		(sphere.point.x - sphere.radius,				\
		 sphere.point.y - sphere.radius,				\
		 sphere.point.z - sphere.radius,				\
		 size, size, size);						\
	}


Q_IMPLEMENTATION_SPHERE(Float,   float,	  Q_FLOAT,   Q_FLOAT_SUFFIX  )
Q_IMPLEMENTATION_SPHERE(Double,  double,  Q_DOUBLE,  Q_DOUBLE_SUFFIX )
Q_IMPLEMENTATION_SPHERE(LDouble, ldouble, Q_LDOUBLE, Q_LDOUBLE_SUFFIX)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_sphere_are_equal	q_float_sphere_are_equal
#	define q_sphere_is_zero		q_float_sphere_is_zero
#	define q_sphere_inner_box	q_float_sphere_inner_box
#	define q_sphere_outer_box	q_float_sphere_outer_box

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_sphere_are_equal	q_ldouble_sphere_are_equal
#	define q_sphere_is_zero		q_ldouble_sphere_is_zero
#	define q_sphere_inner_box	q_ldouble_sphere_inner_box
#	define q_sphere_outer_box	q_ldouble_sphere_outer_box

#else

#	define q_sphere_are_equal	q_double_sphere_are_equal
#	define q_sphere_is_zero		q_double_sphere_is_zero
#	define q_sphere_inner_box	q_double_sphere_inner_box
#	define q_sphere_outer_box	q_double_sphere_outer_box

#endif

#endif /* __Q_functions_geometry_QSphere_H__ */
