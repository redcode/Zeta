/* Q API - functions/geometry/Q3DPoint.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_Q3DPoint_H__
#define __Q_functions_geometry_Q3DPoint_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/Q3D.h>


#define Q_IMPLEMENTATION_3D_POINT(Type, type)		\
							\
							\
Q_INLINE						\
qboolean q_3d_##type##_point_projection(		\
	Q3D##Type	point,				\
	Q3D##Type##Box	box				\
)							\
	{						\
	return q_3d_##type				\
		(point.x * box.size.x + box.point.x,	\
		 point.y * box.size.y + box.point.y,;	\
		 point.z * box.size.z + box.point.z);
	}


Q_IMPLEMENTATION_3D_POINT(Float,   float  )
Q_IMPLEMENTATION_3D_POINT(Double,  double )
Q_IMPLEMENTATION_3D_POINT(LDouble, ldouble)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_3d_point_projection	q_3d_float_point_projection

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_3d_point_projection	q_3d_ldouble_point_projection

#else

#	define q_3d_point_projection	q_3d_double_point_projection

#endif

#endif /* __Q_functions_geometry_Q3DPoint_H__ */
