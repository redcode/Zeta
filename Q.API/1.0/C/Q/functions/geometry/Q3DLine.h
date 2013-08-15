/* Q API - functions/geometry/Q3DLine.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_Q3DLine_H__
#define __Q_functions_geometry_Q3DLine_H__

#include <Q/functions/geometry/Q3DVector.h>

#ifndef Q_3D_LINE_EXPORT
#	define Q_3D_LINE_EXPORT Q_INLINE
#endif

#define q_3d_float_line_are_equal	q_3d_float_vector_are_equal
#define q_3d_float_line_is_zero		q_3d_float_vector_is_zero
#define q_3d_float_line_reversed	q_3d_float_vector_reversed

#define q_3d_double_line_are_equal	q_3d_double_vector_are_equal
#define q_3d_double_line_is_zero	q_3d_double_vector_is_zero
#define q_3d_double_line_reversed	q_3d_double_vector_reversed

#define q_3d_ldouble_line_are_equal	q_3d_ldouble_vector_are_equal
#define q_3d_ldouble_line_is_zero	q_3d_ldouble_vector_is_zero
#define q_3d_ldouble_line_reversed	q_3d_ldouble_vector_reversed

#define q_3d_line_are_equal		q_3d_vector_are_equal
#define q_3d_line_is_zero		q_3d_vector_is_zero
#define q_3d_line_reversed		q_3d_vector_reversed


#define Q_IMPLEMENTATION_3D_LINE(Type, type, _)				\
									\
									\
Q_3D_LINE_EXPORT							\
Q3D##Type q_3d_##type##_line_segment_center(Q3D##Type##Line segment)	\
	{return q_3d_##type##_middle(segment.a, segment.b);}		\
									\
									\
Q_3D_LINE_EXPORT							\
Q3D##Type q_3d_##type##_line_segment_lerp(				\
	Q3D##Type##Line	segment,					\
	q##type		alpha						\
)									\
	{return q_3d_##type##_lerp(segment.a, segment.b, alpha);}


Q_IMPLEMENTATION_3D_LINE(Float,   float,   Q_FLOAT  )
Q_IMPLEMENTATION_3D_LINE(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_3D_LINE(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_3d_line_segment_center	q_3d_float_line_segment_center
#	define q_3d_line_segment_lerp	q_3d_float_line_segment_lerp

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_3d_line_segment_center	q_3d_ldouble_line_segment_center
#	define q_3d_line_segment_lerp	q_3d_ldouble_line_segment_lerp

#else

#	define q_3d_line_segment_center	q_3d_double_line_segment_center
#	define q_3d_line_segment_lerp	q_3d_double_line_segment_lerp

#endif

#endif /* __Q_functions_geometry_Q3DLine_H__ */