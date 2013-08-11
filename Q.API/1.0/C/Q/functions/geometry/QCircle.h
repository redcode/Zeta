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


#define Q_IMPLEMENTATION_CIRCLE(Type, type)					\
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
	}


Q_IMPLEMENTATION_CIRCLE(Float,   float  )
Q_IMPLEMENTATION_CIRCLE(Double,  double )
Q_IMPLEMENTATION_CIRCLE(LDouble, ldouble)
#undef Q_CIRCLE_NEW


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_circle			q_float_cirlce
#	define q_circle_zero		q_float_circle_zero
#	define q_circle_are_equal	q_float_circle_are_equal

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_circle			q_ldouble_cirlce
#	define q_circle_zero		q_ldouble_circle_zero
#	define q_circle_are_equal	q_ldouble_circle_are_equal

#else

#	define q_circle			q_double_cirlce
#	define q_circle_zero		q_double_circle_zero
#	define q_circle_are_equal	q_double_circle_are_equal

#endif

#endif /* __Q_functions_geometry_QCircle_H__ */
