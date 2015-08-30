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


/* MARK: - Template */


#define Z_TEMPLATE_2D_LINE_SEGMENT(Type, type, _)					\
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


#define z_2d_line_segment_type_collide(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_segment_, _collide)
#define z_2d_line_segment_type_center( TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_segment_, _center )
#define z_2d_line_segment_type_lerp(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_segment_, _lerp   )


/* MARK: - Implementations */


#if Z_IS_AVAILABLE(FLOAT16)

#	define z_2d_line_float16_are_equal	   z_2d_vector_float16_are_equal
#	define z_2d_line_float16_are_perpendicular z_2d_vector_float16_are_perpendicular
#	define z_2d_line_float16_is_zero	   z_2d_vector_float16_is_zero
#	define z_2d_line_float16_reversed	   z_2d_vector_float16_reversed

	Z_TEMPLATE_2D_LINE_SEGMENT(Float16, float16, Z_FLOAT16)

#endif

#if Z_IS_AVAILABLE(FLOAT24)

#	define z_2d_line_float24_are_equal	   z_2d_vector_float24_are_equal
#	define z_2d_line_float24_are_perpendicular z_2d_vector_float24_are_perpendicular
#	define z_2d_line_float24_is_zero	   z_2d_vector_float24_is_zero
#	define z_2d_line_float24_reversed	   z_2d_vector_float24_reversed

	Z_TEMPLATE_2D_LINE_SEGMENT(Float24, float24, Z_FLOAT24)

#endif

#if Z_IS_AVAILABLE(FLOAT32)

#	define z_2d_line_float32_are_equal	   z_2d_vector_float32_are_equal
#	define z_2d_line_float32_are_perpendicular z_2d_vector_float32_are_perpendicular
#	define z_2d_line_float32_is_zero	   z_2d_vector_float32_is_zero
#	define z_2d_line_float32_reversed	   z_2d_vector_float32_reversed

	Z_TEMPLATE_2D_LINE_SEGMENT(Float32, float32, Z_FLOAT32)

#endif

#if Z_IS_AVAILABLE(FLOAT48)

#	define z_2d_line_float48_are_equal	   z_2d_vector_float48_are_equal
#	define z_2d_line_float48_are_perpendicular z_2d_vector_float48_are_perpendicular
#	define z_2d_line_float48_is_zero	   z_2d_vector_float48_is_zero
#	define z_2d_line_float48_reversed	   z_2d_vector_float48_reversed

	Z_TEMPLATE_2D_LINE_SEGMENT(Float48, float48, Z_FLOAT48)

#endif

#if Z_IS_AVAILABLE(FLOAT64)

#	define z_2d_line_float64_are_equal	   z_2d_vector_float64_are_equal
#	define z_2d_line_float64_are_perpendicular z_2d_vector_float64_are_perpendicular
#	define z_2d_line_float64_is_zero	   z_2d_vector_float64_is_zero
#	define z_2d_line_float64_reversed	   z_2d_vector_float64_reversed

	Z_TEMPLATE_2D_LINE_SEGMENT(Float64, float64, Z_FLOAT64)

#endif

#if Z_IS_AVAILABLE(FLOAT72)

#	define z_2d_line_float72_are_equal	   z_2d_vector_float72_are_equal
#	define z_2d_line_float72_are_perpendicular z_2d_vector_float72_are_perpendicular
#	define z_2d_line_float72_is_zero	   z_2d_vector_float72_is_zero
#	define z_2d_line_float72_reversed	   z_2d_vector_float72_reversed

	Z_TEMPLATE_2D_LINE_SEGMENT(Float72, float72, Z_FLOAT72)

#endif

#if Z_IS_AVAILABLE(FLOAT80)

#	define z_2d_line_float80_are_equal	   z_2d_vector_float80_are_equal
#	define z_2d_line_float80_are_perpendicular z_2d_vector_float80_are_perpendicular
#	define z_2d_line_float80_is_zero	   z_2d_vector_float80_is_zero
#	define z_2d_line_float80_reversed	   z_2d_vector_float80_reversed

	Z_TEMPLATE_2D_LINE_SEGMENT(Float80, float80, Z_FLOAT80)

#endif

#if Z_IS_AVAILABLE(FLOAT96)

#	define z_2d_line_float96_are_equal	   z_2d_vector_float96_are_equal
#	define z_2d_line_float96_are_perpendicular z_2d_vector_float96_are_perpendicular
#	define z_2d_line_float96_is_zero	   z_2d_vector_float96_is_zero
#	define z_2d_line_float96_reversed	   z_2d_vector_float96_reversed

	Z_TEMPLATE_2D_LINE_SEGMENT(Float96, float96, Z_FLOAT96)

#endif

#if Z_IS_AVAILABLE(FLOAT128)

#	define z_2d_line_float128_are_equal	    z_2d_vector_float128_are_equal
#	define z_2d_line_float128_are_perpendicular z_2d_vector_float128_are_perpendicular
#	define z_2d_line_float128_is_zero	    z_2d_vector_float128_is_zero
#	define z_2d_line_float128_reversed	    z_2d_vector_float128_reversed

	Z_TEMPLATE_2D_LINE_SEGMENT(Float128, float128, Z_FLOAT128)

#endif


/* MARK: - Default real type definitions */


#define z_2d_line_are_equal	    z_2d_vector_are_equal
#define z_2d_line_are_perpendicular z_2d_vector_are_perpendicular
#define z_2d_line_is_zero	    z_2d_vector_is_zero
#define z_2d_line_reversed	    z_2d_vector_reversed

#define z_2d_line_segment_collide z_2d_line_segment_type_collide(REAL)
#define z_2d_line_segment_center  z_2d_line_segment_type_center	(REAL)
#define z_2d_line_segment_lerp	  z_2d_line_segment_type_lerp	(REAL)


#endif /* __Z_functions_geometry_Z2DLine_H__ */
