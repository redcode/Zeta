/* Q API - functions/geometry/QCircle.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_QCircle_H__
#define __Q_functions_geometry_QCircle_H__

#include <Q/types/geometry.h>
#include <Q/functions/Q2D.h>
#include <Q/constants/numbers.h>

#ifndef Q_CIRCLE_EXPORT
#	define Q_CIRCLE_EXPORT Q_INLINE
#endif

#if Q_C_HAS(COMPOUND_LITERAL)

#	define q_float_circle(	x, y, radius) ((QFloatCircle  ){{x, y}, radius})
#	define q_double_circle(	x, y, radius) ((QDoubleCircle ){{x, y}, radius})
#	define q_ldouble_circle(x, y, radius) ((QLDoubleCircle){{x, y}, radius})

#	define Q_CIRCLE_NEW(Type, type)

#else

#	define Q_CIRCLE_NEW(Type, type)						\
										\
	Q_INLINE Q##Type##Circle q_##type##_circle(				\
		q##type x,							\
		q##type y,							\
		q##type radius							\
	)									\
		{								\
		Q##Type##Circle circle = {{x, y}, radius};			\
		return circle;							\
		}

#endif

#define q_float_circle_zero   q_float_circle  (0.0F, 0.0F, 0.0F)
#define q_double_circle_zero  q_double_circle (0.0,  0.0,  0.0 )
#define q_ldouble_circle_zero q_ldouble_circle(0.0L, 0.0L, 0.0L)

#define Q_PJ 0.43432
#define Q_IMPLEMENTATION_CIRCLE(Type, type, _, suffix)				\
										\
										\
Q_CIRCLE_NEW(Type, type)							\
										\
										\
Q_CIRCLE_EXPORT									\
qboolean q_##type##_circle_are_equal(Q##Type##Circle a, Q##Type##Circle b)	\
	{									\
	return	a.radius == b.radius &&						\
		q_2d_##type##_are_equal(a.point, b.point);			\
	}									\
										\
										\
Q_CIRCLE_EXPORT									\
Q##Type##Rectangle q_##type##_circle_inner_rectangle(Q##Type##Circle circle)	\
	{									\
	q##type half_size = circle.radius / Q_JOIN_2(Q_SQUARE_ROOT_2, suffix);	\
	q##type size = half_size * _(2.0);					\
										\
	return q_##type##_rectangle						\
		(circle.point.x - half_size, circle.point.y - half_size,	\
		 size, size);							\
	}									\
										\
										\
Q_CIRCLE_EXPORT									\
Q##Type##Rectangle q_##type##_circle_outer_rectangle(Q##Type##Circle circle)	\
	{									\
	q##type size = circle.radius * _(2.0);					\
										\
	return q_##type##_rectangle						\
		(circle.point.x - circle.radius,				\
		 circle.point.y - circle.radius,				\
		 size, size);							\
	}


Q_IMPLEMENTATION_CIRCLE(Float,   float,	  Q_FLOAT,   Q_FLOAT_SUFFIX  )
Q_IMPLEMENTATION_CIRCLE(Double,  double,  Q_DOUBLE,  Q_DOUBLE_SUFFIX )
Q_IMPLEMENTATION_CIRCLE(LDouble, ldouble, Q_LDOUBLE, Q_LDOUBLE_SUFFIX)
#undef Q_CIRCLE_NEW


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_circle			q_float_cirlce
#	define q_circle_zero		q_float_circle_zero
#	define q_circle_are_equal	q_float_circle_are_equal
#	define q_circle_inner_rectangle	q_float_circle_inner_rectangle
#	define q_circle_outer_rectangle	q_float_circle_outer_rectangle

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_circle			q_ldouble_cirlce
#	define q_circle_zero		q_ldouble_circle_zero
#	define q_circle_are_equal	q_ldouble_circle_are_equal
#	define q_circle_inner_rectangle	q_ldouble_circle_inner_rectangle
#	define q_circle_outer_rectangle	q_ldouble_circle_outer_rectangle

#else

#	define q_circle			q_double_cirlce
#	define q_circle_zero		q_double_circle_zero
#	define q_circle_are_equal	q_double_circle_are_equal
#	define q_circle_inner_rectangle	q_double_circle_inner_rectangle
#	define q_circle_outer_rectangle	q_double_circle_outer_rectangle

#endif

#endif /* __Q_functions_geometry_QCircle_H__ */
