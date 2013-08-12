/* Q API - functions/geometry/Q2DLine.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_Q2DLine_H__
#define __Q_functions_geometry_Q2DLine_H__

#include <Q/functions/geometry/Q2DVector.h>

#ifndef Q_2D_LINE_EXPORT
#	define Q_2D_LINE_EXPORT Q_INLINE
#endif

#define q_2d_float_line_are_equal	q_2d_float_vector_are_equal
#define q_2d_float_line_is_zero		q_2d_float_vector_is_zero

#define q_2d_double_line_are_equal	q_2d_double_vector_are_equal
#define q_2d_double_line_is_zero	q_2d_double_vector_is_zero

#define q_2d_ldouble_line_are_equal	q_2d_ldouble_vector_are_equal
#define q_2d_ldouble_line_is_zero	q_2d_ldouble_vector_is_zero

#define q_2d_line_are_equal		q_2d_vector_are_equal
#define q_2d_line_is_zero		q_2d_vector_is_zero


#define Q_IMPLEMENTATION_2D_LINE(Type, type, _)				\
									\
									\
Q_2D_LINE_EXPORT							\
Q2D##Type##Line q_2d_##type##_line_reversed(Q2D##Type##Line line)	\
	{return q_2d_##type##_line(line.b, line.a);}			\
									\
									\
Q_2D_LINE_EXPORT							\
Q2D##Type q_2d_##type##_line_segment_center(Q2D##Type##Line segment)	\
	{								\
	return q_2d_##type						\
		((segment.b.x - segment.a.x) / _(2.0) + segment.a.x,	\
		 (segment.b.y - segment.a.y) / _(2.0) + segment.a.y);	\
	}								\
									\
									\
Q_2D_LINE_EXPORT							\
Q2D##Type q_2d_##type##_line_segment_lerp(				\
	Q2D##Type##Line	segment,					\
	q##type		alpha						\
)									\
	{return q_2d_##type##_lerp(segment.a, segment.b, alpha)}


Q_IMPLEMENTATION_2D_LINE(Float,   float,   Q_FLOAT  )
Q_IMPLEMENTATION_2D_LINE(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_2D_LINE(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_2d_line_reversed	q_2d_float_line_reversed
#	define q_2d_line_segment_center	q_2d_float_line_segment_center
#	define q_2d_line_segment_lerp	q_2d_float_line_segment_lerp

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_2d_line_reversed	q_2d_ldouble_line_reversed
#	define q_2d_line_segment_center	q_2d_ldouble_line_segment_center
#	define q_2d_line_segment_lerp	q_2d_ldouble_line_segment_lerp

#else

#	define q_2d_line_reversed	q_2d_double_line_reversed
#	define q_2d_line_segment_center	q_2d_double_line_segment_center
#	define q_2d_line_segment_lerp	q_2d_double_line_segment_lerp

#endif

#endif /* __Q_functions_geometry_Q2DLine_H__ */
