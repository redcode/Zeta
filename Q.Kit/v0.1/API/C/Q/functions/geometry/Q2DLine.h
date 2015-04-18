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

#define q_2d_line_float_are_equal	    q_2d_vector_float_are_equal
#define q_2d_line_float_are_perpendicular   q_2d_vector_float_are_perpendicular
#define q_2d_line_float_is_zero		    q_2d_vector_float_is_zero
#define q_2d_line_float_reversed	    q_2d_vector_float_reversed

#define q_2d_line_double_are_equal	    q_2d_vector_double_are_equal
#define q_2d_line_double_are_perpendicular  q_2d_vector_double_are_perpendicular
#define q_2d_line_double_is_zero	    q_2d_vector_double_is_zero
#define q_2d_line_double_reversed	    q_2d_vector_double_reversed

#define q_2d_line_ldouble_are_equal	    q_2d_vector_ldouble_are_equal
#define q_2d_line_ldouble_are_perpendicular q_2d_vector_ldouble_are_perpendicular
#define q_2d_line_ldouble_is_zero	    q_2d_vector_ldouble_is_zero
#define q_2d_line_ldouble_reversed	    q_2d_vector_ldouble_reversed


#define Q_IMPLEMENTATION_2D_LINE_SEGMENT(Type, type, _)					\
											\
											\
Q_INLINE qboolean q_2d_line_segment_##type##_collide(Q2DLine##Type a, Q2DLine##Type b)	\
	{										\
	Q2D##Type d  = q_2d_##type##_subtract(b.a, a.a);				\
	Q2D##Type va = q_2d_##type##_subtract(a.b, a.a);				\
	Q2D##Type vb = q_2d_##type##_subtract(b.b, b.a);				\
	q##type	  c  = q_2d_##type##_cross_product(va, vb);				\
	q##type	  t  = q_2d_##type##_cross_product(d, vb) / c;				\
	q##type	  u  = q_2d_##type##_cross_product(d, va) / c;				\
											\
	return t < _(0.0) || t > _(1.0) || u < _(0.0) || u > _(1.0) ? FALSE : TRUE;	\
	}										\
											\
											\
Q_INLINE Q2D##Type q_2d_line_segment_##type##_center(Q2DLine##Type object)		\
	{return q_2d_##type##_middle(object.a, object.b);}				\
											\
											\
Q_INLINE Q2D##Type q_2d_line_segment_##type##_lerp(Q2DLine##Type object, q##type alpha)	\
	{return q_2d_##type##_lerp(object.a, object.b, alpha);}


Q_IMPLEMENTATION_2D_LINE_SEGMENT(Float,   float,   Q_FLOAT  )
Q_IMPLEMENTATION_2D_LINE_SEGMENT(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_2D_LINE_SEGMENT(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#define q_2d_line_are_equal	    q_2d_vector_are_equal
#define q_2d_line_are_perpendicular q_2d_vector_are_perpendicular
#define q_2d_line_is_zero	    q_2d_vector_is_zero
#define q_2d_line_reversed	    q_2d_vector_reversed

#define q_2d_line_segment_collide   Q_JOIN_3(q_2d_line_segment_, Q_REAL_FIXED_TYPE_name, _collide)
#define q_2d_line_segment_center    Q_JOIN_3(q_2d_line_segment_, Q_REAL_FIXED_TYPE_name, _center )
#define q_2d_line_segment_lerp	    Q_JOIN_3(q_2d_line_segment_, Q_REAL_FIXED_TYPE_name, _lerp	 )

#endif /* __Q_functions_geometry_Q2DLine_H__ */
