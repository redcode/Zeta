/* Q Kit C API - functions/geometry/Q3DLine.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_Q3DLine_H__
#define __Q_functions_geometry_Q3DLine_H__

#include <Q/functions/geometry/Q3DVector.h>

#define q_3d_float_line_are_equal		q_3d_float_vector_are_equal
#define q_3d_float_line_are_perpendicular	q_3d_float_vector_are_perpendicular
#define q_3d_float_line_is_zero			q_3d_float_vector_is_zero
#define q_3d_float_line_reversed		q_3d_float_vector_reversed

#define q_3d_double_line_are_equal		q_3d_double_vector_are_equal
#define q_3d_double_line_are_perpendicular	q_3d_double_vector_are_perpendicular
#define q_3d_double_line_is_zero		q_3d_double_vector_is_zero
#define q_3d_double_line_reversed		q_3d_double_vector_reversed

#define q_3d_ldouble_line_are_equal		q_3d_ldouble_vector_are_equal
#define q_3d_ldouble_line_are_perpendicular	q_3d_ldouble_vector_are_perpendicular
#define q_3d_ldouble_line_is_zero		q_3d_ldouble_vector_is_zero
#define q_3d_ldouble_line_reversed		q_3d_ldouble_vector_reversed

#define q_3d_line_are_equal			q_3d_vector_are_equal
#define q_3d_line_are_perpendicular		q_3d_vector_are_perpendicular
#define q_3d_line_is_zero			q_3d_vector_is_zero
#define q_3d_line_reversed			q_3d_vector_reversed


#define Q_IMPLEMENTATION_3D_LINE(Type, type, _)				\
									\
									\
Q_INLINE								\
Q3D##Type q_3d_##type##_line_segment_center(Q3D##Type##Line segment)	\
	{return q_3d_##type##_middle(segment.a, segment.b);}		\
									\
									\
Q_INLINE Q3D##Type q_3d_##type##_line_segment_lerp(			\
	Q3D##Type##Line	segment,					\
	q##type		alpha						\
)									\
	{return q_3d_##type##_lerp(segment.a, segment.b, alpha);}


Q_IMPLEMENTATION_3D_LINE(Float,   float,   Q_FLOAT  )
Q_IMPLEMENTATION_3D_LINE(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_3D_LINE(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#define q_3d_line_segment_center Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _line_segment_center)
#define q_3d_line_segment_lerp	 Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _line_segment_lerp  )

#endif /* __Q_functions_geometry_Q3DLine_H__ */
