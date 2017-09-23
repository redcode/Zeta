/* Z Kit C API - functions/mathematics/geometry/euclidean/Z2DLine.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_mathematics_geometry_euclidean_Z2DLine_H__
#define __Z_functions_mathematics_geometry_euclidean_Z2DLine_H__

#include <Z/functions/mathematics/geometry/euclidean/constructors.h>
#include <Z/functions/base/Z2DValue.h>


/* MARK: - Common implementation */


#define Z_IMPLEMENTATION_2D_LINE_COMMON(Type, type)					 \
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
Z_INLINE Z2DLine##Type z_2d_line_##type##_reverse(Z2DLine##Type object)			 \
	{return z_2d_line_##type(object.b.x, object.b.y, object.a.x, object.a.y);}	 \
											 \
											 \
Z_INLINE void z_2d_line_##type##_swap(Z2DLine##Type *a, Z2DLine##Type *b)		 \
	{										 \
	Z2DLine##Type t = *a;								 \
											 \
	*a = *b; *b = t;								 \
	}										 \
											 \
											 \
Z_INLINE ZAABR##Type z_2d_line_segment_##type##_aabr(Z2DLine##Type object)		 \
	{										 \
	return z_aabr_##type								 \
		(z_##type##_minimum(object.a.x, object.b.x),				 \
		 z_##type##_minimum(object.a.y, object.b.y),				 \
		 z_##type##_maximum(object.a.x, object.b.x),				 \
		 z_##type##_maximum(object.a.y, object.b.y));		 		 \
	}										 \
											 \
											 \
Z_INLINE Z2D##Type z_2d_line_segment_##type##_center(Z2DLine##Type object)		 \
	{return z_2d_##type##_middle(object.a, object.b);}


#define z_2d_line_type_are_equal(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_,		_are_equal	  )
#define z_2d_line_type_are_perpendicular(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_,		_are_perpendicular)
#define z_2d_line_type_is_zero(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_,		_is_zero	  )
#define z_2d_line_type_reverse(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_,		_reverse	  )
#define z_2d_line_type_swap(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_,		_swap		  )
#define z_2d_line_segment_aabr(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_segment_, _aabr		  )
#define z_2d_line_segment_type_center(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_segment_, _center		  )


/* MARK: - Partial implementation for real types */


#define Z_IMPLEMENTATION_2D_LINE_REAL(Type, type)					\
											\
											\
Z_INLINE zboolean z_2d_line_segment_##type##_intersect(Z2DLine##Type a, Z2DLine##Type b)\
	{										\
	Z2D##Type d  = z_2d_##type##_subtract(b.a, a.a);				\
	Z2D##Type va = z_2d_##type##_subtract(a.b, a.a);				\
	Z2D##Type vb = z_2d_##type##_subtract(b.b, b.a);				\
	z##type	  c  = z_2d_##type##_cross_product(va, vb);				\
	z##type	  t  = z_2d_##type##_cross_product(d, vb) / c;				\
	z##type	  u  = z_2d_##type##_cross_product(d, va) / c;				\
											\
	return !(t < (z##type)0 || t > (z##type)1 || u < (z##type)0 || u > (z##type)1);	\
	}										\
											\
											\
Z_INLINE Z2D##Type z_2d_line_segment_##type##_lerp(Z2DLine##Type object, z##type alpha)	\
	{return z_2d_##type##_lerp(object.a, object.b, alpha);}


#define z_2d_line_segment_type_intersect(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_segment_, _intersect)
#define z_2d_line_segment_type_lerp(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_segment_, _lerp	  )


/* MARK: - Implementation expansions */


Z_IMPLEMENTATION_2D_LINE_COMMON(Int8,  int8 )
Z_IMPLEMENTATION_2D_LINE_COMMON(Int16, int16)
Z_IMPLEMENTATION_2D_LINE_COMMON(Int32, int32)

#ifdef Z_INT64
	Z_IMPLEMENTATION_2D_LINE_COMMON(Int64, int64)
#endif

#ifdef Z_INT128
	Z_IMPLEMENTATION_2D_LINE_COMMON(Int128, int128)
#endif

#ifdef Z_FLOAT16
	Z_IMPLEMENTATION_2D_LINE_COMMON(Float16, float16)
	Z_IMPLEMENTATION_2D_LINE_REAL  (Float16, float16)
#endif

#ifdef Z_FLOAT24
	Z_IMPLEMENTATION_2D_LINE_COMMON(Float24, float24)
	Z_IMPLEMENTATION_2D_LINE_REAL  (Float24, float24)
#endif

#ifdef Z_FLOAT32
	Z_IMPLEMENTATION_2D_LINE_COMMON(Float32, float32)
	Z_IMPLEMENTATION_2D_LINE_REAL  (Float32, float32)
#endif

#ifdef Z_FLOAT48
	Z_IMPLEMENTATION_2D_LINE_COMMON(Float48, float48)
	Z_IMPLEMENTATION_2D_LINE_REAL  (Float48, float48)
#endif

#ifdef Z_FLOAT64
	Z_IMPLEMENTATION_2D_LINE_COMMON(Float64, float64)
	Z_IMPLEMENTATION_2D_LINE_REAL  (Float64, float64)
#endif

#ifdef Z_FLOAT72
	Z_IMPLEMENTATION_2D_LINE_COMMON(Float72, float72)
	Z_IMPLEMENTATION_2D_LINE_REAL  (Float72, float72)
#endif

#ifdef Z_FLOAT80
	Z_IMPLEMENTATION_2D_LINE_COMMON(Float80, float80)
	Z_IMPLEMENTATION_2D_LINE_REAL  (Float80, float80)
#endif

#ifdef Z_FLOAT96
	Z_IMPLEMENTATION_2D_LINE_COMMON(Float96, float96)
	Z_IMPLEMENTATION_2D_LINE_REAL  (Float96, float96)
#endif

#ifdef Z_FLOAT128
	Z_IMPLEMENTATION_2D_LINE_COMMON(Float128, float128)
	Z_IMPLEMENTATION_2D_LINE_REAL  (Float128, float128)
#endif


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_2d_line_are_equal	   z_2d_line_type_are_equal	   (REAL)
#	define z_2d_line_are_perpendicular z_2d_line_type_are_perpendicular(REAL)
#	define z_2d_line_is_zero	   z_2d_line_type_is_zero	   (REAL)
#	define z_2d_line_reverse	   z_2d_line_type_reverse	   (REAL)
#	define z_2d_line_swap		   z_2d_line_type_swap		   (REAL)
#	define z_2d_line_segment_aabr	   z_2d_line_segment_type_aabr	   (REAL)
#	define z_2d_line_segment_center	   z_2d_line_segment_type_center   (REAL)
#	define z_2d_line_segment_intersect z_2d_line_segment_type_intersect(REAL)
#	define z_2d_line_segment_lerp	   z_2d_line_segment_type_lerp	   (REAL)
#endif


#endif /* __Z_functions_mathematics_geometry_euclidean_Z2DLine_H__ */
