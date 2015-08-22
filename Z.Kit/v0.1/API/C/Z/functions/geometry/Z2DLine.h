/* Z Kit C API - functions/geometry/Z2DLine.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_Z2DLine_H__
#define __Z_functions_geometry_Z2DLine_H__

#include <Z/functions/geometry/Z2DVector.h>

#define z_2d_line_float_are_equal	    z_2d_vector_float_are_equal
#define z_2d_line_float_are_perpendicular   z_2d_vector_float_are_perpendicular
#define z_2d_line_float_is_zero		    z_2d_vector_float_is_zero
#define z_2d_line_float_reversed	    z_2d_vector_float_reversed

#define z_2d_line_double_are_equal	    z_2d_vector_double_are_equal
#define z_2d_line_double_are_perpendicular  z_2d_vector_double_are_perpendicular
#define z_2d_line_double_is_zero	    z_2d_vector_double_is_zero
#define z_2d_line_double_reversed	    z_2d_vector_double_reversed

#define z_2d_line_ldouble_are_equal	    z_2d_vector_ldouble_are_equal
#define z_2d_line_ldouble_are_perpendicular z_2d_vector_ldouble_are_perpendicular
#define z_2d_line_ldouble_is_zero	    z_2d_vector_ldouble_is_zero
#define z_2d_line_ldouble_reversed	    z_2d_vector_ldouble_reversed


#define Z_IMPLEMENTATION_2D_LINE_SEGMENT(Type, type, _)					\
											\
											\
Z_INLINE zboolean z_2d_line_segment_##type##_collide(Z2DLine##Type a, Z2DLine##Type b)	\
	{										\
	Z2D##Type d  = z_2d_##type##_subtract(b.a, a.a);				\
	Z2D##Type va = z_2d_##type##_subtract(a.b, a.a);				\
	Z2D##Type vb = z_2d_##type##_subtract(b.b, b.a);				\
	z##type	  c  = z_2d_##type##_cross_product(va, vb);				\
	z##type	  t  = z_2d_##type##_cross_product(d, vb) / c;				\
	z##type	  u  = z_2d_##type##_cross_product(d, va) / c;				\
											\
	return t < _(0.0) || t > _(1.0) || u < _(0.0) || u > _(1.0) ? FALSE : TRUE;	\
	}										\
											\
											\
Z_INLINE Z2D##Type z_2d_line_segment_##type##_center(Z2DLine##Type object)		\
	{return z_2d_##type##_middle(object.a, object.b);}				\
											\
											\
Z_INLINE Z2D##Type z_2d_line_segment_##type##_lerp(Z2DLine##Type object, z##type alpha)	\
	{return z_2d_##type##_lerp(object.a, object.b, alpha);}


Z_IMPLEMENTATION_2D_LINE_SEGMENT(Float,   float,   Z_FLOAT  )
Z_IMPLEMENTATION_2D_LINE_SEGMENT(Double,  double,  Z_DOUBLE )
Z_IMPLEMENTATION_2D_LINE_SEGMENT(LDouble, ldouble, Z_LDOUBLE)


#define Z_JOIN_2d_line_segment_type_collide(type) Z_PASTE_3(z_2d_line_segment_, type, _collide)
#define Z_JOIN_2d_line_segment_type_center( type) Z_PASTE_3(z_2d_line_segment_, type, _center )
#define Z_JOIN_2d_line_segment_type_lerp(   type) Z_PASTE_3(z_2d_line_segment_, type, _lerp   )


/* MARK: - Default real type definitions */


#define z_2d_line_are_equal	    z_2d_vector_are_equal
#define z_2d_line_are_perpendicular z_2d_vector_are_perpendicular
#define z_2d_line_is_zero	    z_2d_vector_is_zero
#define z_2d_line_reversed	    z_2d_vector_reversed

#define z_2d_line_segment_collide   Z_JOIN_2d_line_segment_type_collide(Z_REAL_FIXED_TYPE_name)
#define z_2d_line_segment_center    Z_JOIN_2d_line_segment_type_center (Z_REAL_FIXED_TYPE_name)
#define z_2d_line_segment_lerp	    Z_JOIN_2d_line_segment_type_lerp   (Z_REAL_FIXED_TYPE_name)


#endif /* __Z_functions_geometry_Z2DLine_H__ */
