/* Q API - functions/geometry/QSphere.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_QSphere_H__
#define __Q_functions_geometry_QSphere_H__

#include <Q/types/geometry.h>
#include <Q/functions/Q3D.h>

#ifndef Q_SPHERE_EXPORT
#	define Q_SPHERE_EXPORT Q_INLINE
#endif

#if Q_C_HAS(COMPOUND_LITERAL)

#	define q_float_sphere(	x, y, z, radius) ((QFloatCircle	 ){{x, y, z}, radius})
#	define q_double_sphere(	x, y, z, radius) ((QDoubleCircle ){{x, y, z}, radius})
#	define q_ldouble_sphere(x, y, z, radius) ((QLDoubleCircle){{x, y, z}, radius})

#	define Q_SPHERE_NEW(Type, type)

#else

#	define Q_SPHERE_NEW(Type, type)				\
								\
	Q_INLINE Q##Type##Sphere q_##type##_sphere(		\
		q##type x,					\
		q##type y,					\
		q##type z,					\
		q##type radius					\
	)							\
		{						\
		Q##Type##Sphere sphere = {{x, y, z}, radius};	\
		return sphere;					\
		}

#endif

#define q_float_sphere_zero   q_float_sphere  (0.0F, 0.0F, 0.0F, 0.0F)
#define q_double_sphere_zero  q_double_sphere (0.0,  0.0,  0.0,	 0.0 )
#define q_ldouble_sphere_zero q_ldouble_sphere(0.0L, 0.0L, 0.0L, 0.0L)


#define Q_IMPLEMENTATION_SPHERE(Type, type)					\
										\
										\
Q_SPHERE_NEW(Type, type)							\
										\
										\
Q_SPHERE_EXPORT									\
qboolean q_##type##_sphere_are_equal(Q##Type##Sphere a, Q##Type##Sphere b)	\
	{									\
	return	a.radius == b.radius &&						\
		q_3d_##type##_are_equal(a.point, b.point);			\
	}


Q_IMPLEMENTATION_SPHERE(Float,   float  )
Q_IMPLEMENTATION_SPHERE(Double,  double )
Q_IMPLEMENTATION_SPHERE(LDouble, ldouble)
#undef Q_SPHERE_NEW


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_sphere			q_float_sphere
#	define q_sphere_zero		q_float_sphere_zero
#	define q_sphere_are_equal	q_float_sphere_are_equal

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_sphere			q_ldouble_sphere
#	define q_sphere_zero		q_ldouble_sphere_zero
#	define q_sphere_are_equal	q_ldouble_sphere_are_equal

#else

#	define q_sphere			q_double_sphere
#	define q_sphere_zero		q_double_sphere_zero
#	define q_sphere_are_equal	q_double_sphere_are_equal

#endif

#endif /* __Q_functions_geometry_QSphere_H__ */
