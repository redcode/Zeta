/* Q Kit C API - functions/geometry/QCircle.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_QCircle_H__
#define __Q_functions_geometry_QCircle_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/base/Q2DValue.h>
#include <Q/constants/numbers.h>


#define Q_IMPLEMENTATION_CIRCLE(Type, type, _)							\
												\
												\
Q_INLINE qboolean q_circle_##type##_are_equal(QCircle##Type a, QCircle##Type b)			\
	{return a.radius == b.radius && q_2d_##type##_are_equal(a.point, b.point);}		\
												\
												\
Q_INLINE QRectangle##Type q_circle_##type##_inner_rectangle(QCircle##Type object)		\
	{											\
	q##type half_size = object.radius / _(Q_SQUARE_ROOT_2);					\
	q##type size = half_size * _(2.0);							\
												\
	return q_rectangle_##type								\
		(object.point.x - half_size, object.point.y - half_size, size, size);		\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_circle_##type##_outer_rectangle(QCircle##Type object)		\
	{											\
	q##type size = object.radius * _(2.0);							\
												\
	return q_rectangle_##type								\
		(object.point.x - object.radius, object.point.y - object.radius, size, size);	\
	}											\
												\
												\
Q_INLINE qboolean q_circle_##type##_is_zero(QCircle##Type object)				\
	{return object.radius == _(0.0) && q_2d_##type##_is_zero(object.point);}


Q_IMPLEMENTATION_CIRCLE(Float,   float,	  Q_FLOAT  )
Q_IMPLEMENTATION_CIRCLE(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_CIRCLE(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#define q_circle_are_equal	 Q_JOIN_3(q_circle_, Q_REAL_FIXED_TYPE_name, _are_equal	     )
#define q_circle_is_zero	 Q_JOIN_3(q_circle_, Q_REAL_FIXED_TYPE_name, _is_zero	     )
#define q_circle_inner_rectangle Q_JOIN_3(q_circle_, Q_REAL_FIXED_TYPE_name, _inner_rectangle)
#define q_circle_outer_rectangle Q_JOIN_3(q_circle_, Q_REAL_FIXED_TYPE_name, _outer_rectangle)

#endif /* __Q_functions_geometry_QCircle_H__ */
