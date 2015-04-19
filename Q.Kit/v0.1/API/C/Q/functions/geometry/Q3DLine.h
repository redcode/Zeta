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

#define q_3d_line_float_are_equal	    q_3d_vector_float_are_equal
#define q_3d_line_float_are_perpendicular   q_3d_vector_float_are_perpendicular
#define q_3d_line_float_is_zero		    q_3d_vector_float_is_zero
#define q_3d_line_float_reversed	    q_3d_vector_float_reversed

#define q_3d_line_double_are_equal	    q_3d_vector_double_are_equal
#define q_3d_line_double_are_perpendicular  q_3d_vector_double_are_perpendicular
#define q_3d_line_double_is_zero	    q_3d_vector_double_is_zero
#define q_3d_line_double_reversed	    q_3d_vector_double_reversed

#define q_3d_line_ldouble_are_equal	    q_3d_vector_ldouble_are_equal
#define q_3d_line_ldouble_are_perpendicular q_3d_vector_ldouble_are_perpendicular
#define q_3d_line_ldouble_is_zero	    q_3d_vector_ldouble_is_zero
#define q_3d_line_ldouble_reversed	    q_3d_vector_ldouble_reversed


#define Q_IMPLEMENTATION_3D_LINE_SEGMENT(Type, type, _)					\
											\
											\
Q_INLINE Q3D##Type q_3d_line_segment_##type##_center(Q3DLine##Type object)		\
	{return q_3d_##type##_middle(object.a, object.b);}				\
											\
											\
Q_INLINE Q3D##Type q_3d_line_segment_##type##_lerp(Q3DLine##Type object, q##type alpha)	\
	{return q_3d_##type##_lerp(object.a, object.b, alpha);}


Q_IMPLEMENTATION_3D_LINE_SEGMENT(Float,   float,   Q_FLOAT  )
Q_IMPLEMENTATION_3D_LINE_SEGMENT(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_3D_LINE_SEGMENT(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#define q_3d_line_are_equal	    q_3d_vector_are_equal
#define q_3d_line_are_perpendicular q_3d_vector_are_perpendicular
#define q_3d_line_is_zero	    q_3d_vector_is_zero
#define q_3d_line_reversed	    q_3d_vector_reversed

#define q_3d_line_segment_center    Q_JOIN_3(q_3d_line_segment_, Q_REAL_FIXED_TYPE_name, _center)
#define q_3d_line_segment_lerp	    Q_JOIN_3(q_3d_line_segment_, Q_REAL_FIXED_TYPE_name, _lerp	)

#endif /* __Q_functions_geometry_Q3DLine_H__ */
