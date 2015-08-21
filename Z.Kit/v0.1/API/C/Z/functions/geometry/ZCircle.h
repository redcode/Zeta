/* Z Kit C API - functions/geometry/ZCircle.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_ZCircle_H__
#define __Z_functions_geometry_ZCircle_H__

#include <Z/functions/geometry/constructors.h>
#include <Z/functions/base/Z2DValue.h>
#include <Z/constants/numbers.h>


#define Z_IMPLEMENTATION_CIRCLE(Type, type, _)							\
												\
												\
Z_INLINE zboolean z_circle_##type##_are_equal(ZCircle##Type a, ZCircle##Type b)			\
	{return a.radius == b.radius && z_2d_##type##_are_equal(a.point, b.point);}		\
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
	}											\
												\
												\
Z_INLINE zboolean z_circle_##type##_is_zero(ZCircle##Type object)				\
	{return object.radius == _(0.0) && z_2d_##type##_is_zero(object.point);}


Z_IMPLEMENTATION_CIRCLE(Float,   float,	  Z_FLOAT  )
Z_IMPLEMENTATION_CIRCLE(Double,  double,  Z_DOUBLE )
Z_IMPLEMENTATION_CIRCLE(LDouble, ldouble, Z_LDOUBLE)


/* MARK: - Default real type definitions */

#define z_circle_are_equal	 Z_JOIN_3(z_circle_, Z_REAL_FIXED_TYPE_name, _are_equal	     )
#define z_circle_is_zero	 Z_JOIN_3(z_circle_, Z_REAL_FIXED_TYPE_name, _is_zero	     )
#define z_circle_inner_rectangle Z_JOIN_3(z_circle_, Z_REAL_FIXED_TYPE_name, _inner_rectangle)
#define z_circle_outer_rectangle Z_JOIN_3(z_circle_, Z_REAL_FIXED_TYPE_name, _outer_rectangle)

#endif /* __Z_functions_geometry_ZCircle_H__ */
