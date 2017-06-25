/* Z Kit C API - functions/mathematics/geometry/euclidean/Z3DLine.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_mathematics_geometry_euclidean_Z3DLine_H__
#define __Z_functions_mathematics_geometry_euclidean_Z3DLine_H__

#include <Z/functions/mathematics/geometry/euclidean/constructors.h>
#include <Z/functions/base/Z3DValue.h>


/* MARK: - Implementations */


#define Z_IMPLEMENTATION_3D_LINE(Type, type)						  \
											  \
											  \
Z_INLINE zboolean z_3d_line_##type##_are_equal(Z3DLine##Type a, Z3DLine##Type b)	  \
	{return z_3d_##type##_are_equal(a.a, b.a) && z_3d_##type##_are_equal(a.b, b.b);}  \
											  \
											  \
Z_INLINE zboolean z_3d_line_##type##_are_perpendicular(Z3DLine##Type a, Z3DLine##Type b)  \
	{										  \
	return z_3d_##type##_are_perpendicular						  \
		(z_3d_##type##_subtract(a.b, a.a),					  \
		 z_3d_##type##_subtract(b.b, b.a));					  \
	}										  \
											  \
											  \
Z_INLINE void z_3d_line_##type##_swap(Z3DLine##Type *a, Z3DLine##Type *b)		  \
	{										  \
	Z3DLine##Type t = *a;								  \
											  \
	*a = *b; *b = t;								  \
	}										  \
											  \
											  \
Z_INLINE zboolean z_3d_line_##type##_is_zero(Z3DLine##Type object)			  \
	{return z_3d_##type##_is_zero(object.a) && z_3d_##type##_is_zero(object.b);}	  \
											  \
											  \
Z_INLINE Z3DLine##Type z_3d_line_##type##_reverse(Z3DLine##Type object)			  \
	{										  \
	return z_3d_line_##type								  \
		(object.b.x, object.b.y, object.b.z, object.a.x, object.a.y, object.a.z); \
	}


#define z_3d_line_type_are_equal(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_, _are_equal	  )
#define z_3d_line_type_are_perpendicular(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_, _are_perpendicular)
#define z_3d_line_type_swap(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_, _swap		  )
#define z_3d_line_type_is_zero(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_, _is_zero	  )
#define z_3d_line_type_reverse(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_, _reverse	  )


#define Z_IMPLEMENTATION_3D_LINE_SEGMENT(Type, type)					\
											\
											\
Z_INLINE Z3D##Type z_3d_line_segment_##type##_center(Z3DLine##Type object)		\
	{return z_3d_##type##_middle(object.a, object.b);}				\
											\
											\
Z_INLINE Z3D##Type z_3d_line_segment_##type##_lerp(Z3DLine##Type object, z##type alpha)	\
	{return z_3d_##type##_lerp(object.a, object.b, alpha);}


#define z_3d_line_segment_type_center(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_segment_, _center)
#define z_3d_line_segment_type_lerp(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_segment_, _lerp  )


/* MARK: - Implementation expansions */


#ifdef Z_FLOAT16
	Z_IMPLEMENTATION_3D_LINE	(Float16, float16)
	Z_IMPLEMENTATION_3D_LINE_SEGMENT(Float16, float16)
#endif

#ifdef Z_FLOAT24
	Z_IMPLEMENTATION_3D_LINE	(Float24, float24)
	Z_IMPLEMENTATION_3D_LINE_SEGMENT(Float24, float24)
#endif

#ifdef Z_FLOAT32
	Z_IMPLEMENTATION_3D_LINE	(Float32, float32)
	Z_IMPLEMENTATION_3D_LINE_SEGMENT(Float32, float32)
#endif

#ifdef Z_FLOAT48
	Z_IMPLEMENTATION_3D_LINE	(Float48, float48)
	Z_IMPLEMENTATION_3D_LINE_SEGMENT(Float48, float48)
#endif

#ifdef Z_FLOAT64
	Z_IMPLEMENTATION_3D_LINE	(Float64, float64)
	Z_IMPLEMENTATION_3D_LINE_SEGMENT(Float64, float64)
#endif

#ifdef Z_FLOAT72
	Z_IMPLEMENTATION_3D_LINE	(Float72, float72)
	Z_IMPLEMENTATION_3D_LINE_SEGMENT(Float72, float72)
#endif

#ifdef Z_FLOAT80
	Z_IMPLEMENTATION_3D_LINE	(Float80, float80)
	Z_IMPLEMENTATION_3D_LINE_SEGMENT(Float80, float80)
#endif

#ifdef Z_FLOAT96
	Z_IMPLEMENTATION_3D_LINE	(Float96, float96)
	Z_IMPLEMENTATION_3D_LINE_SEGMENT(Float96, float96)
#endif

#ifdef Z_FLOAT128
	Z_IMPLEMENTATION_3D_LINE	(Float128, float128)
	Z_IMPLEMENTATION_3D_LINE_SEGMENT(Float128, float128)
#endif


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_3d_line_are_equal	   z_3d_line_type_are_equal	   (REAL)
#	define z_3d_line_are_perpendicular z_3d_line_type_are_perpendicular(REAL)
#	define z_3d_line_swap		   z_3d_line_type_swap		   (REAL)
#	define z_3d_line_is_zero	   z_3d_line_type_is_zero	   (REAL)
#	define z_3d_line_reverse	   z_3d_line_type_reverse	   (REAL)
#	define z_3d_line_segment_center	   z_3d_line_segment_type_center   (REAL)
#	define z_3d_line_segment_lerp	   z_3d_line_segment_type_lerp	   (REAL)
#endif


#endif /* __Z_functions_mathematics_geometry_euclidean_Z3DLine_H__ */
