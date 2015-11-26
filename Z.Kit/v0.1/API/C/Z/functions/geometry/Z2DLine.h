/* Z Kit C API - functions/geometry/Z2DLine.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_Z2DLine_H__
#define __Z_functions_geometry_Z2DLine_H__

#include <Z/functions/geometry/constructors.h>
#include <Z/functions/base/Z2DValue.h>


/* MARK: - Templates */


#define Z_TEMPLATE_2D_LINE(Type, type)							 \
											 \
											 \
Z_INLINE zboolean z_2d_line_##type##_are_equal(Z2DLine##Type a, Z2DLine##Type b)	 \
	{return z_2d_##type##_are_equal(a.a, b.a) && z_2d_##type##_are_equal(a.b, b.b);} \
											 \
											 \
Z_INLINE zboolean z_2d_line_##type##_are_perpendicular(Z2DLine##Type a, Z2DLine##Type b) \
	{										 \
	return z_2d_##type##_are_perpendicular						 \
		(z_2d_##type##_subtract(a.b, a.a), z_2d_##type##_subtract(b.b, b.a));	 \
	}										 \
											 \
											 \
Z_INLINE zboolean z_2d_line_##type##_is_zero(Z2DLine##Type object)			 \
	{return z_2d_##type##_is_zero(object.a) && z_2d_##type##_is_zero(object.b);}	 \
											 \
											 \
Z_INLINE Z2DVector##Type z_2d_vector_##type##_reversed(Z2DLine##Type object)		 \
	{return z_2d_line_##type(object.b.x, object.b.y, object.a.x, object.a.y);}


#define z_2d_line_type_are_equal(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_linx_, _are_equal	  )
#define z_2d_line_type_are_perpendicular(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_linx_, _are_perpendicular)
#define z_2d_line_type_is_zero(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_linx_, _is_zero	  )
#define z_2d_line_type_reversed(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_linx_, _reversed	  )


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


/* MARK: - Template implementations */


#if Z_IS_AVAILABLE(FLOAT16)
	Z_TEMPLATE_2D_LINE	  (Float16, float16)
	Z_TEMPLATE_2D_LINE_SEGMENT(Float16, float16, Z_FLOAT16)
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	Z_TEMPLATE_2D_LINE	  (Float24, float24)
	Z_TEMPLATE_2D_LINE_SEGMENT(Float24, float24, Z_FLOAT24)
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	Z_TEMPLATE_2D_LINE	  (Float32, float32)
	Z_TEMPLATE_2D_LINE_SEGMENT(Float32, float32, Z_FLOAT32)
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	Z_TEMPLATE_2D_LINE	  (Float48, float48)
	Z_TEMPLATE_2D_LINE_SEGMENT(Float48, float48, Z_FLOAT48)
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	Z_TEMPLATE_2D_LINE	  (Float64, float64)
	Z_TEMPLATE_2D_LINE_SEGMENT(Float64, float64, Z_FLOAT64)
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	Z_TEMPLATE_2D_LINE	  (Float72, float72)
	Z_TEMPLATE_2D_LINE_SEGMENT(Float72, float72, Z_FLOAT72)
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	Z_TEMPLATE_2D_LINE	  (Float80, float80)
	Z_TEMPLATE_2D_LINE_SEGMENT(Float80, float80, Z_FLOAT80)
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	Z_TEMPLATE_2D_LINE	  (Float96, float96)
	Z_TEMPLATE_2D_LINE_SEGMENT(Float96, float96, Z_FLOAT96)
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	Z_TEMPLATE_2D_LINE	  (Float128, float128)
	Z_TEMPLATE_2D_LINE_SEGMENT(Float128, float128, Z_FLOAT128)
#endif


/* MARK: - Default real type definitions */


#define z_2d_line_are_equal	    z_2d_line_type_are_equal	    (REAL)
#define z_2d_line_are_perpendicular z_2d_line_type_are_perpendicular(REAL)
#define z_2d_line_is_zero	    z_2d_line_type_is_zero	    (REAL)
#define z_2d_line_reversed	    z_2d_line_type_reversed	    (REAL)
#define z_2d_line_segment_collide   z_2d_line_segment_type_collide  (REAL)
#define z_2d_line_segment_center    z_2d_line_segment_type_center   (REAL)
#define z_2d_line_segment_lerp	    z_2d_line_segment_type_lerp	    (REAL)


#endif /* __Z_functions_geometry_Z2DLine_H__ */
