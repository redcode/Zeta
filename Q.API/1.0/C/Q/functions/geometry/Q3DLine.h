/* Q API - functions/geometry.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_H__
#define __Q_functions_geometry_H__

#include <Q/types/geometry.h>
#include <Q/functions/Q3D.h>

#ifndef Q_3D_LINE_EXPORT
#	define Q_3D_LINE_EXPORT Q_INLINE
#endif

#define q_3d_float_line			q_3d_float_vector
#define q_3d_float_line_zero		q_3d_float_vector_zero
#define q_3d_float_line_are_equal	q_3d_float_vector_are_equal
#define q_3d_double_line		q_3d_double_vector
#define q_3d_double_line_zero		q_3d_double_vector_zero
#define q_3d_double_line_are_equal	q_3d_double_vector_are_equal
#define q_3d_ldouble_line		q_3d_ldouble_vector
#define q_3d_ldouble_line_zero		q_3d_ldouble_vector_zero
#define q_3d_ldouble_line_are_equal	q_3d_ldouble_vector_are_equal


#define Q_IMPLEMENTATION_3D_LINE(Type, type, _)				\
									\
Q_3D_LINE_EXPORT							\
Q3D##Type q_3d_##type##_line_segment_center(Q3D##Type##Line segment)	\
	{								\
	return q_3d_##type						\
		((segment.b.x - segment.a.x) / _(2.0) + segment.a.x,	\
		 (segment.b.y - segment.a.y) / _(2.0) + segment.a.y,	\
		 (segment.b.z - segment.a.z) / _(2.0) + segment.a.z);	\
	}

Q_IMPLEMENTATION_3D_LINE(Float,   float,   Q_FLOAT  )
Q_IMPLEMENTATION_3D_LINE(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_3D_LINE(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_3d_line		q_3d_float_line
#	define q_3d_line_zero		q_3d_float_line_zero
#	define q_3d_line_are_equal	q_3d_float_line_are_equal
#	define q_3d_line_segment_center	q_3d_float_line_segment_center

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_3d_line		q_3d_ldouble_line
#	define q_3d_line_zero		q_3d_ldouble_line_zero
#	define q_3d_line_are_equal	q_3d_ldouble_line_are_equal
#	define q_3d_line_segment_center	q_3d_ldouble_line_segment_center

#else

#	define q_3d_line		q_3d_double_line
#	define q_3d_line_zero		q_3d_double_line_zero
#	define q_3d_line_are_equal	q_3d_double_line_are_equal
#	define q_3d_line_segment_center	q_3d_double_line_segment_center

#endif

#endif /* __Q_functions_geometry_H__ */
