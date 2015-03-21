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
#include <Q/functions/base/Q3DValue.h>
#include <Q/constants/numbers.h>


#define Q_IMPLEMENTATION_SPHERE(Type, type, _, suffix)					\
											\
											\
Q_INLINE qboolean q_##type##_sphere_are_equal(Q##Type##Sphere a, Q##Type##Sphere b)	\
	{return a.radius == b.radius && q_3d_##type##_are_equal(a.point, b.point);}	\
											\
											\
Q_INLINE qboolean q_##type##_sphere_is_zero(Q##Type##Sphere object)			\
	{return object.radius == _(0.0) && q_3d_##type##_is_zero(object.point);}	\
											\
											\
Q_INLINE Q##Type##Box q_##type##_sphere_inner_box(Q##Type##Sphere object)		\
	{										\
	q##type half_size = object.radius / Q_JOIN_2(Q_SQUARE_ROOT_3, suffix);		\
	q##type size = half_size * _(2.0);						\
											\
	return q_##type##_box								\
		(object.point.x - half_size,						\
		 object.point.y - half_size,						\
		 object.point.z - half_size,						\
		 size, size, size);							\
	}										\
											\
											\
Q_INLINE Q##Type##Box q_##type##_sphere_outer_box(Q##Type##Sphere object)		\
	{										\
	q##type size = object.radius * _(2.0);						\
											\
	return q_##type##_box								\
		(object.point.x - object.radius,					\
		 object.point.y - object.radius,					\
		 object.point.z - object.radius,					\
		 size, size, size);							\
	}


Q_IMPLEMENTATION_SPHERE(Float,   float,	  Q_FLOAT,   Q_FLOAT_SUFFIX  )
Q_IMPLEMENTATION_SPHERE(Double,  double,  Q_DOUBLE,  Q_DOUBLE_SUFFIX )
Q_IMPLEMENTATION_SPHERE(LDouble, ldouble, Q_LDOUBLE, Q_LDOUBLE_SUFFIX)


/* MARK: - Default real type definitions */

#define q_sphere_are_equal Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _sphere_are_equal)
#define q_sphere_is_zero   Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _sphere_is_zero	 )
#define q_sphere_inner_box Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _sphere_inner_box)
#define q_sphere_outer_box Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _sphere_outer_box)

#endif /* __Q_functions_geometry_QSphere_H__ */
