/* Q Kit C API - functions/geometry/Q2DLine.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_Q2DLine_H__
#define __Q_functions_geometry_Q2DLine_H__

#include <Q/functions/geometry/Q2DVector.h>

#define q_2d_float_line_are_equal	    q_2d_float_vector_are_equal
#define q_2d_float_line_are_perpendicular   q_2d_float_vector_are_perpendicular
#define q_2d_float_line_is_zero		    q_2d_float_vector_is_zero
#define q_2d_float_line_reversed	    q_2d_float_vector_reversed

#define q_2d_double_line_are_equal	    q_2d_double_vector_are_equal
#define q_2d_double_line_are_perpendicular  q_2d_double_vector_are_perpendicular
#define q_2d_double_line_is_zero	    q_2d_double_vector_is_zero
#define q_2d_double_line_reversed	    q_2d_double_vector_reversed

#define q_2d_ldouble_line_are_equal	    q_2d_ldouble_vector_are_equal
#define q_2d_ldouble_line_are_perpendicular q_2d_ldouble_vector_are_perpendicular
#define q_2d_ldouble_line_is_zero	    q_2d_ldouble_vector_is_zero
#define q_2d_ldouble_line_reversed	    q_2d_ldouble_vector_reversed


#define Q_IMPLEMENTATION_2D_LINE_SEGMENT(Type, type, _)				\
										\
										\
Q_INLINE qboolean q_2d_##type##_line_segment_collide(				\
	Q2D##Type##Line a,							\
	Q2D##Type##Line b							\
)										\
	{									\
	Q2D##Type d  = q_2d_##type##_subtract(b.a, a.a);			\
	Q2D##Type va = q_2d_##type##_subtract(a.b, a.a);			\
	Q2D##Type vb = q_2d_##type##_subtract(b.b, b.a);			\
	q##type	  c  = q_2d_##type##_cross_product(va, vb);			\
	q##type	  t  = q_2d_##type##_cross_product(d, vb) / c;			\
	q##type	  u  = q_2d_##type##_cross_product(d, va) / c;			\
										\
	return t < _(0.0) || t > _(1.0) || u < _(0.0) || u > _(1.0)		\
		? FALSE : TRUE;							\
	}									\
										\
										\
Q_INLINE Q2D##Type q_2d_##type##_line_segment_center(Q2D##Type##Line segment)	\
	{return q_2d_##type##_middle(segment.a, segment.b);}			\
										\
										\
Q_INLINE Q2D##Type q_2d_##type##_line_segment_lerp(				\
	Q2D##Type##Line	segment,						\
	q##type		alpha							\
)										\
	{return q_2d_##type##_lerp(segment.a, segment.b, alpha);}


Q_IMPLEMENTATION_2D_LINE_SEGMENT(Float,   float,   Q_FLOAT  )
Q_IMPLEMENTATION_2D_LINE_SEGMENT(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_2D_LINE_SEGMENT(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#define q_2d_line_are_equal	    q_2d_vector_are_equal
#define q_2d_line_are_perpendicular q_2d_vector_are_perpendicular
#define q_2d_line_is_zero	    q_2d_vector_is_zero
#define q_2d_line_reversed	    q_2d_vector_reversed

#define q_2d_line_segment_collide   Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _line_segment_collide)
#define q_2d_line_segment_center    Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _line_segment_center )
#define q_2d_line_segment_lerp	    Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _line_segment_lerp	 )

#endif /* __Q_functions_geometry_Q2DLine_H__ */
