/* Z Kit - functions/mathematics/geometry/euclidean/Z3DLine.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_mathematics_geometry_euclidean_Z3DLine_H_
#define _Z_functions_mathematics_geometry_euclidean_Z3DLine_H_

#include <Z/functions/mathematics/geometry/euclidean/constructors.h>
#include <Z/functions/base/Z3D.h>


/* MARK: - Common implementation */


#define Z_IMPLEMENTATION_COMMON(Type, type)							\
												\
static Z_INLINE											\
zboolean z_3d_line_##type##_are_equal(Z3DLine##Type a, Z3DLine##Type b)				\
	{return z_3d_##type##_are_equal(a.a, b.a) && z_3d_##type##_are_equal(a.b, b.b);}	\
												\
												\
static Z_INLINE											\
zboolean z_3d_line_##type##_are_perpendicular(Z3DLine##Type a, Z3DLine##Type b)			\
	{											\
	return z_3d_##type##_are_perpendicular							\
		(z_3d_##type##_subtract(a.b, a.a), z_3d_##type##_subtract(b.b, b.a));		\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_3d_line_##type##_is_zero(Z3DLine##Type object)					\
	{return z_3d_##type##_is_zero(object.a) && z_3d_##type##_is_zero(object.b);}		\
												\
												\
static Z_INLINE											\
Z3DLine##Type z_3d_line_##type##_reverse(Z3DLine##Type object)					\
	{											\
	return z_3d_line_##type									\
		(object.b.x, object.b.y, object.b.z, object.a.x, object.a.y, object.a.z);	\
	}											\
												\
												\
static Z_INLINE											\
void z_3d_line_##type##_swap(Z3DLine##Type *a, Z3DLine##Type *b)				\
	{											\
	Z3DLine##Type t = *a;									\
												\
	*a = *b; *b = t;									\
	}											\
												\
												\
static Z_INLINE											\
ZAABB##Type z_3d_line_segment_##type##_aabb(Z3DLine##Type object)				\
	{											\
	return z_aabb_##type									\
		(z_##type##_minimum(object.a.x, object.b.x),					\
		 z_##type##_minimum(object.a.y, object.b.y),					\
		 z_##type##_minimum(object.a.z, object.b.z),					\
		 z_##type##_maximum(object.a.x, object.b.x),					\
		 z_##type##_maximum(object.a.y, object.b.y),					\
		 z_##type##_maximum(object.a.z, object.b.z));					\
	}											\
												\
												\
static Z_INLINE											\
Z3D##Type z_3d_line_segment_##type##_center(Z3DLine##Type object)				\
	{return z_3d_##type##_middle(object.a, object.b);}


#define z_3d_line_type_are_equal(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_,		_are_equal	  )
#define z_3d_line_type_are_perpendicular(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_,		_are_perpendicular)
#define z_3d_line_type_is_zero(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_,		_is_zero	  )
#define z_3d_line_type_reverse(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_,		_reverse	  )
#define z_3d_line_type_swap(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_,		_swap		  )
#define z_2d_line_segment_aabb(		 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_segment_, _aabb		  )
#define z_3d_line_segment_type_center(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_segment_, _center		  )


/* MARK: - Partial implementation for real types */


#define Z_IMPLEMENTATION_REAL(Type, type)							\
												\
static Z_INLINE											\
Z3D##Type z_3d_line_segment_##type##_lerp(Z3DLine##Type object, z##type alpha)			\
	{return z_3d_##type##_lerp(object.a, object.b, alpha);}


#define z_3d_line_segment_type_lerp(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_segment_, _lerp)


/* MARK: - Implementation expansions */


Z_IMPLEMENTATION_COMMON(SInt8,	sint8 )
Z_IMPLEMENTATION_COMMON(SInt16, sint16)
Z_IMPLEMENTATION_COMMON(SInt32, sint32)

#ifdef Z_SINT64
	Z_IMPLEMENTATION_COMMON(SInt64, sint64)
#endif

#ifdef Z_SINT128
	Z_IMPLEMENTATION_COMMON(SInt128, sint128)
#endif

#ifdef Z_FLOAT16
	Z_IMPLEMENTATION_COMMON(Float16, float16)
	Z_IMPLEMENTATION_REAL  (Float16, float16)
#endif

#ifdef Z_FLOAT32
	Z_IMPLEMENTATION_COMMON(Float32, float32)
	Z_IMPLEMENTATION_REAL  (Float32, float32)
#endif

#ifdef Z_FLOAT64
	Z_IMPLEMENTATION_COMMON(Float64, float64)
	Z_IMPLEMENTATION_REAL  (Float64, float64)
#endif

#ifdef Z_FLOAT128
	Z_IMPLEMENTATION_COMMON(Float128, float128)
	Z_IMPLEMENTATION_REAL  (Float128, float128)
#endif

#ifdef Z_FLOAT80_X87
	Z_IMPLEMENTATION_COMMON(Float80_x87, float80_x87)
	Z_IMPLEMENTATION_REAL  (Float80_x87, float80_x87)
#endif

#ifdef Z_FLOAT96_X87
	Z_IMPLEMENTATION_COMMON(Float96_x87, float96_x87)
	Z_IMPLEMENTATION_REAL  (Float96_x87, float96_x87)
#endif

#ifdef Z_FLOAT128_X87
	Z_IMPLEMENTATION_COMMON(Float128_x87, float128_x87)
	Z_IMPLEMENTATION_REAL  (Float128_x87, float128_x87)
#endif


/* MARK: - Cleanup */


#undef Z_IMPLEMENTATION_COMMON
#undef Z_IMPLEMENTATION_REAL


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_3d_line_are_equal	   z_3d_line_type_are_equal	   (REAL)
#	define z_3d_line_are_perpendicular z_3d_line_type_are_perpendicular(REAL)
#	define z_3d_line_is_zero	   z_3d_line_type_is_zero	   (REAL)
#	define z_3d_line_reverse	   z_3d_line_type_reverse	   (REAL)
#	define z_3d_line_swap		   z_3d_line_type_swap		   (REAL)
#	define z_2d_line_segment_aabb	   z_2d_line_segment_type_aabb	   (REAL)
#	define z_3d_line_segment_center	   z_3d_line_segment_type_center   (REAL)
#	define z_3d_line_segment_lerp	   z_3d_line_segment_type_lerp	   (REAL)
#endif


#endif /* _Z_functions_mathematics_geometry_euclidean_Z3DLine_H_ */
