/* Q API - functions/geometry/QCircle.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_QCircle_H__
#define __Q_functions_geometry_QCircle_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/base/Q2D.h>
#include <Q/constants/numbers.h>


#define Q_IMPLEMENTATION_CIRCLE(Type, type, _, suffix)				\
										\
										\
Q_INLINE									\
qboolean q_##type##_circle_are_equal(Q##Type##Circle a, Q##Type##Circle b)	\
	{									\
	return	a.radius == b.radius &&						\
		q_2d_##type##_are_equal(a.point, b.point);			\
	}									\
										\
										\
Q_INLINE									\
Q##Type##Rectangle q_##type##_circle_inner_rectangle(Q##Type##Circle circle)	\
	{									\
	q##type half_size = circle.radius / Q_JOIN_2(Q_SQUARE_ROOT_2, suffix);	\
	q##type size = half_size * _(2.0);					\
										\
	return q_##type##_rectangle						\
		(circle.point.x - half_size,					\
		 circle.point.y - half_size,					\
		 size, size);							\
	}									\
										\
										\
Q_INLINE									\
Q##Type##Rectangle q_##type##_circle_outer_rectangle(Q##Type##Circle circle)	\
	{									\
	q##type size = circle.radius * _(2.0);					\
										\
	return q_##type##_rectangle						\
		(circle.point.x - circle.radius,				\
		 circle.point.y - circle.radius,				\
		 size, size);							\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_circle_is_zero(Q##Type##Circle circle)		\
	{									\
	return	circle.radius == _(0.0) &&					\
		q_2d_##type##_is_zero(circle.point);				\
	}


Q_IMPLEMENTATION_CIRCLE(Float,   float,	  Q_FLOAT,   Q_FLOAT_SUFFIX  )
Q_IMPLEMENTATION_CIRCLE(Double,  double,  Q_DOUBLE,  Q_DOUBLE_SUFFIX )
Q_IMPLEMENTATION_CIRCLE(LDouble, ldouble, Q_LDOUBLE, Q_LDOUBLE_SUFFIX)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_circle_are_equal	q_float_circle_are_equal
#	define q_circle_is_zero		q_float_circle_is_zero
#	define q_circle_inner_rectangle	q_float_circle_inner_rectangle
#	define q_circle_outer_rectangle	q_float_circle_outer_rectangle

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_circle_are_equal	q_ldouble_circle_are_equal
#	define q_circle_is_zero		q_ldouble_circle_is_zero
#	define q_circle_inner_rectangle	q_ldouble_circle_inner_rectangle
#	define q_circle_outer_rectangle	q_ldouble_circle_outer_rectangle

#else

#	define q_circle_are_equal	q_double_circle_are_equal
#	define q_circle_is_zero		q_double_circle_is_zero
#	define q_circle_inner_rectangle	q_double_circle_inner_rectangle
#	define q_circle_outer_rectangle	q_double_circle_outer_rectangle

#endif

#endif /* __Q_functions_geometry_QCircle_H__ */
