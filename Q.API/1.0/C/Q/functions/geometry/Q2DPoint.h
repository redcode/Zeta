/* Q API - functions/geometry/Q2DPoint.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_Q2DPoint_H__
#define __Q_functions_geometry_Q2DPoint_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/Q2D.h>


#define Q_IMPLEMENTATION_2D_POINT(Type, type)				\
									\
									\
Q_INLINE								\
qboolean q_2d_##type##_point_project(					\
	Q2D##Type		point,					\
	Q2D##Type##Rectangle	rectangle				\
)									\
	{								\
	return q_2d_##type						\
		(point.x * rectangle.size.x + rectangle.point.x,	\
		 point.y * rectangle.size.y + rectangle.point.y);	\
	}


Q_IMPLEMENTATION_2D_POINT(Float,   float  )
Q_IMPLEMENTATION_2D_POINT(Double,  double )
Q_IMPLEMENTATION_2D_POINT(LDouble, ldouble)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_2d_point_project	q_2d_float_point_project

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_2d_point_project	q_2d_ldouble_point_project

#else

#	define q_2d_point_project	q_2d_double_point_project

#endif

#endif /* __Q_functions_geometry_Q2DPoint_H__ */
