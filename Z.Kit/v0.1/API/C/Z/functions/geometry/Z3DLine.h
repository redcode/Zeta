/* Z Kit C API - functions/geometry/Z3DLine.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_Z3DLine_H__
#define __Z_functions_geometry_Z3DLine_H__

#include <Z/functions/geometry/Z3DVector.h>

#define z_3d_line_float_are_equal	    z_3d_vector_float_are_equal
#define z_3d_line_float_are_perpendicular   z_3d_vector_float_are_perpendicular
#define z_3d_line_float_is_zero		    z_3d_vector_float_is_zero
#define z_3d_line_float_reversed	    z_3d_vector_float_reversed

#define z_3d_line_double_are_equal	    z_3d_vector_double_are_equal
#define z_3d_line_double_are_perpendicular  z_3d_vector_double_are_perpendicular
#define z_3d_line_double_is_zero	    z_3d_vector_double_is_zero
#define z_3d_line_double_reversed	    z_3d_vector_double_reversed

#define z_3d_line_ldouble_are_equal	    z_3d_vector_ldouble_are_equal
#define z_3d_line_ldouble_are_perpendicular z_3d_vector_ldouble_are_perpendicular
#define z_3d_line_ldouble_is_zero	    z_3d_vector_ldouble_is_zero
#define z_3d_line_ldouble_reversed	    z_3d_vector_ldouble_reversed


#define Z_IMPLEMENTATION_3D_LINE_SEGMENT(Type, type, _)					\
											\
											\
Z_INLINE Z3D##Type z_3d_line_segment_##type##_center(Z3DLine##Type object)		\
	{return z_3d_##type##_middle(object.a, object.b);}				\
											\
											\
Z_INLINE Z3D##Type z_3d_line_segment_##type##_lerp(Z3DLine##Type object, z##type alpha)	\
	{return z_3d_##type##_lerp(object.a, object.b, alpha);}


Z_IMPLEMENTATION_3D_LINE_SEGMENT(Float,   float,   Z_FLOAT  )
Z_IMPLEMENTATION_3D_LINE_SEGMENT(Double,  double,  Z_DOUBLE )
Z_IMPLEMENTATION_3D_LINE_SEGMENT(LDouble, ldouble, Z_LDOUBLE)


/* MARK: - Default real type definitions */


#define z_3d_line_are_equal	    z_3d_vector_are_equal
#define z_3d_line_are_perpendicular z_3d_vector_are_perpendicular
#define z_3d_line_is_zero	    z_3d_vector_is_zero
#define z_3d_line_reversed	    z_3d_vector_reversed

#define z_3d_line_segment_center Z_INSERT_REAL_fixed_type(z_3d_line_segment_, _center)
#define z_3d_line_segment_lerp	 Z_INSERT_REAL_fixed_type(z_3d_line_segment_, _lerp  )


#endif /* __Z_functions_geometry_Z3DLine_H__ */
