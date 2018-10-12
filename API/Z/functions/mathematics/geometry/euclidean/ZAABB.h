/* Z Kit - functions/mathematics/geometry/euclidean/ZAABB.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_mathematics_geometry_euclidean_ZAABB_H_
#define _Z_functions_mathematics_geometry_euclidean_ZAABB_H_

#include <Z/functions/mathematics/geometry/euclidean/Z3DLine.h>


/* MARK: - Common implementation */


#define Z_IMPLEMENTATION_COMMON(Type, type)							\
												\
static Z_INLINE											\
ZBox##Type z_aabb_##type##_box(ZAABB##Type object)						\
	{											\
	return z_box_##type									\
		(object.a.x, object.a.y, object.a.z,						\
		 object.b.x - object.a.x, object.b.y - object.a.y, object.b.z - object.a.z);	\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_aabb_##type##_contains(ZAABB##Type object, ZAABB##Type other)			\
	{											\
	return	other.a.x != other.b.x	&&							\
		other.a.y != other.b.y	&&							\
		other.a.z != other.b.z	&&							\
		other.a.x >= object.a.x &&							\
		other.a.y >= object.a.y &&							\
		other.a.z >= object.a.z &&							\
		other.b.x <= object.b.x &&							\
		other.b.y <= object.b.y &&							\
		other.b.z <= object.b.z;							\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_aabb_##type##_contains_box(ZAABB##Type object, ZBox##Type box)			\
	{											\
	return	box.size.x		 != (z##type)0 &&					\
		box.size.y		 != (z##type)0 &&					\
		box.size.z		 != (z##type)0 &&					\
		box.point.x		 >= object.a.x &&					\
		box.point.y		 >= object.a.y &&					\
		box.point.z		 >= object.a.z &&					\
		box.point.x + box.size.x <= object.b.x &&					\
		box.point.y + box.size.y <= object.b.y &&					\
		box.point.z + box.size.z <= object.b.z;						\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_aabb_##type##_contains_point(ZAABB##Type object, Z3D##Type point)			\
	{											\
	return	point.x >= object.a.x && point.y >= object.a.y && point.z >= object.a.z &&	\
		point.x <  object.b.x && point.y <  object.b.y && point.z <  object.b.z;	\
	}											\
												\
												\
static Z_INLINE											\
ZAABB##Type z_aabb_##type##_from_vertices(Z3D##Type a, Z3D##Type b)				\
	{											\
	ZAABB##Type result;									\
												\
	result.a = z_3d_##type##_minimum(a, b);							\
	result.b = z_3d_##type##_maximum(a, b);							\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_aabb_##type##_intersect(ZAABB##Type a, ZAABB##Type b)				\
	{											\
	return	a.a.x != a.b.x && a.a.y != a.b.y && a.a.z != a.b.z &&				\
		b.a.x != b.b.x && b.a.y != b.b.y && b.a.z != b.b.z &&				\
		b.b.x >  a.a.x && b.b.y >  a.a.y && b.b.z >  a.a.z &&				\
		b.a.x <  a.b.x && b.a.y <  a.b.y && b.a.z <  a.b.z;				\
	}											\
												\
												\
static Z_INLINE											\
ZAABB##Type z_aabb_##type##_intersection(ZAABB##Type a, ZAABB##Type b)				\
	{											\
	z##type x1, x2, y1, y2, z1, z2;								\
												\
	return	(x1 = z_##type##_maximum(a.a.x, b.a.x)) <					\
		(x2 = z_##type##_minimum(a.b.x, b.b.x)) &&					\
		(y1 = z_##type##_maximum(a.a.y, b.a.y))	<					\
		(y2 = z_##type##_minimum(a.b.y, b.b.y)) &&					\
		(z1 = z_##type##_maximum(a.a.z, b.a.z))	<					\
		(z2 = z_##type##_minimum(a.b.z, b.b.z))						\
												\
		? z_aabb_##type(x1, y1, z1, x2, y2, z2)						\
		: z_aabb_##type##_zero;								\
	}											\
												\
												\
static Z_INLINE											\
Z3D##Type z_aabb_##type##_size(ZAABB##Type object)						\
	{return z_3d_##type##_subtract(object.b, object.a);}					\
												\
												\
static Z_INLINE											\
ZAABB##Type z_aabb_##type##_union(ZAABB##Type a, ZAABB##Type b)					\
	{											\
	ZAABB##Type result;									\
												\
	result.a = z_3d_##type##_minimum(a.a, b.a);						\
	result.b = z_3d_##type##_maximum(a.b, b.b);						\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
z##type z_aabb_##type##_volume(ZAABB##Type object)						\
	{return z_3d_##type##_inner_product(z_3d_##type##_subtract(object.b, object.a));}


#define z_aabb_type_box(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _box	      )
#define z_aabb_type_contains(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _contains      )
#define z_aabb_type_contains_box(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _contains_box  )
#define z_aabb_type_contains_point(TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _contains_point)
#define z_aabb_type_from_vertices( TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _from_vertices )
#define z_aabb_type_intersect(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _intersect     )
#define z_aabb_type_intersection(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _intersection  )
#define z_aabb_type_size(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _size	      )
#define z_aabb_type_union(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _union	      )
#define z_aabb_type_volume(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _volume	      )


/* MARK: - Partial implementation for real types */


#define Z_IMPLEMENTATION_REAL(Type, type)							\
												\
static Z_INLINE											\
Z3D##Type z_aabb_##type##_absolute_point_to_unit(ZAABB##Type object, Z3D##Type point)		\
	{											\
	return z_3d_##type									\
		((point.x - object.a.x) / (object.b.x - object.a.x),				\
		 (point.y - object.a.y) / (object.b.y - object.a.y),				\
		 (point.z - object.a.z) / (object.b.z - object.a.z));				\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_aabb_##type##_contains_sphere(ZAABB##Type object, ZSphere##Type sphere)		\
	{											\
	return	sphere.radius != (z##type)0		     &&					\
		sphere.point.x - sphere.radius >= object.a.x &&					\
		sphere.point.y - sphere.radius >= object.a.y &&					\
		sphere.point.z - sphere.radius >= object.a.z &&					\
		sphere.point.x + sphere.radius <= object.b.x &&					\
		sphere.point.y + sphere.radius <= object.b.y &&					\
		sphere.point.z + sphere.radius <= object.b.z;					\
	}											\
												\
												\
static Z_INLINE											\
ZSphere##Type z_aabb_##type##_inner_sphere(ZAABB##Type object)					\
	{											\
	ZSphere##Type result;									\
												\
	result.point = z_aabb_##type##_center(object);						\
												\
	result.radius =										\
	z_##type##_minimum									\
		(z_##type##_minimum(object.b.x - object.a.x, object.b.y - object.a.y),		\
		 object.b.z - object.a.z)							\
	/ (z##type)2;										\
												\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
Z3D##Type z_aabb_##type##_unit_point_to_absolute(ZAABB##Type object, Z3D##Type point)		\
	{											\
	return z_3d_##type									\
		(point.x * (object.b.x - object.a.x) + object.a.x,				\
		 point.y * (object.b.y - object.a.y) + object.a.y,				\
		 point.z * (object.b.z - object.a.z) + object.a.z);				\
	}


#define z_aabb_type_absolute_point_to_unit(TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _absolute_point_to_unit)
#define z_aabb_type_contains_sphere(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _contains_sphere	      )
#define z_aabb_type_inner_sphere(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _inner_sphere	      )
#define z_aabb_type_unit_point_to_absolute(TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _unit_point_to_absolute)


/* MARK: - Implementation expansions */


#define z_aabb_sint8_are_equal z_3d_line_sint8_are_equal
#define z_aabb_sint8_center    z_3d_line_segment_sint8_center
#define z_aabb_sint8_is_zero   z_3d_line_sint8_is_zero
#define z_aabb_sint8_swap      z_3d_line_sint8_swap

Z_IMPLEMENTATION_COMMON(SInt8, sint8)

#define z_aabb_sint16_are_equal z_3d_line_sint16_are_equal
#define z_aabb_sint16_center	z_3d_line_segment_sint16_center
#define z_aabb_sint16_is_zero	z_3d_line_sint16_is_zero
#define z_aabb_sint16_swap	z_3d_line_sint16_swap

Z_IMPLEMENTATION_COMMON(SInt16, sint16)

#define z_aabb_sint32_are_equal z_3d_line_sint32_are_equal
#define z_aabb_sint32_center	z_3d_line_segment_sint32_center
#define z_aabb_sint32_is_zero	z_3d_line_sint32_is_zero
#define z_aabb_sint32_swap	z_3d_line_sint32_swap

Z_IMPLEMENTATION_COMMON(SInt32, sint32)

#ifdef Z_SINT64

#	define z_aabb_sint64_are_equal z_3d_line_sint64_are_equal
#	define z_aabb_sint64_center    z_3d_line_segment_sint64_center
#	define z_aabb_sint64_is_zero   z_3d_line_sint64_is_zero
#	define z_aabb_sint64_swap      z_3d_line_sint64_swap

	Z_IMPLEMENTATION_COMMON(SInt64, sint64)

#endif

#ifdef Z_SINT128

#	define z_aabb_sint128_are_equal z_3d_line_sint128_are_equal
#	define z_aabb_sint128_center	z_3d_line_segment_sint128_center
#	define z_aabb_sint128_is_zero	z_3d_line_sint128_is_zero
#	define z_aabb_sint128_swap	z_3d_line_sint128_swap

	Z_IMPLEMENTATION_COMMON(SInt128, sint128)

#endif

#ifdef Z_FLOAT16

#	define z_aabb_float16_are_equal	z_3d_line_float16_are_equal
#	define z_aabb_float16_center	z_3d_line_segment_float16_center
#	define z_aabb_float16_is_zero	z_3d_line_float16_is_zero
#	define z_aabb_float16_swap	z_3d_line_float16_swap

	Z_IMPLEMENTATION_COMMON(Float16, float16)
	Z_IMPLEMENTATION_REAL  (Float16, float16)

#endif

#ifdef Z_FLOAT32

#	define z_aabb_float32_are_equal	z_3d_line_float32_are_equal
#	define z_aabb_float32_center	z_3d_line_segment_float32_center
#	define z_aabb_float32_is_zero	z_3d_line_float32_is_zero
#	define z_aabb_float32_swap	z_3d_line_float32_swap

	Z_IMPLEMENTATION_COMMON(Float32, float32)
	Z_IMPLEMENTATION_REAL  (Float32, float32)

#endif

#ifdef Z_FLOAT64

#	define z_aabb_float64_are_equal	z_3d_line_float64_are_equal
#	define z_aabb_float64_center	z_3d_line_segment_float64_center
#	define z_aabb_float64_is_zero	z_3d_line_float64_is_zero
#	define z_aabb_float64_swap	z_3d_line_float64_swap

	Z_IMPLEMENTATION_COMMON(Float64, float64)
	Z_IMPLEMENTATION_REAL  (Float64, float64)

#endif

#ifdef Z_FLOAT128

#	define z_aabb_float128_are_equal z_3d_line_float128_are_equal
#	define z_aabb_float128_center	 z_3d_line_segment_float128_center
#	define z_aabb_float128_is_zero	 z_3d_line_float128_is_zero
#	define z_aabb_float128_swap	 z_3d_line_float128_swap

	Z_IMPLEMENTATION_COMMON(Float128, float128)
	Z_IMPLEMENTATION_REAL  (Float128, float128)

#endif

#ifdef Z_FLOAT80_X87

#	define z_aabb_float80_x87_are_equal z_3d_line_float80_x87_are_equal
#	define z_aabb_float80_x87_center    z_3d_line_segment_float80_x87_center
#	define z_aabb_float80_x87_is_zero   z_3d_line_float80_x87_is_zero
#	define z_aabb_float80_x87_swap	    z_3d_line_float80_x87_swap

	Z_IMPLEMENTATION_COMMON(Float80_x87, float80_x87)
	Z_IMPLEMENTATION_REAL  (Float80_x87, float80_x87)

#endif

#ifdef Z_FLOAT96_X87

#	define z_aabb_float96_x87_are_equal z_3d_line_float96_x87_are_equal
#	define z_aabb_float96_x87_center    z_3d_line_segment_float96_x87_center
#	define z_aabb_float96_x87_is_zero   z_3d_line_float96_x87_is_zero
#	define z_aabb_float96_x87_swap	    z_3d_line_float96_x87_swap

	Z_IMPLEMENTATION_COMMON(Float96_x87, float96_x87)
	Z_IMPLEMENTATION_REAL  (Float96_x87, float96_x87)

#endif

#ifdef Z_FLOAT128_X87

#	define z_aabb_float128_x87_are_equal z_3d_line_float128_x87_are_equal
#	define z_aabb_float128_x87_center    z_3d_line_segment_float128_x87_center
#	define z_aabb_float128_x87_is_zero   z_3d_line_float128_x87_is_zero
#	define z_aabb_float128_x87_swap	     z_3d_line_float128_x87_swap

	Z_IMPLEMENTATION_COMMON(Float128_x87, float128_x87)
	Z_IMPLEMENTATION_REAL  (Float128_x87, float128_x87)

#endif


/* MARK: - Cleanup */


#undef Z_IMPLEMENTATION_COMMON
#undef Z_IMPLEMENTATION_REAL


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_aabb_absolute_point_to_unit z_aabb_type_absolute_point_to_unit(REAL)
#	define z_aabb_are_equal		     z_3d_line_are_equal
#	define z_aabb_box		     z_aabb_type_box		       (REAL)
#	define z_aabb_center		     z_3d_line_segment_center
#	define z_aabb_contains		     z_aabb_type_contains	       (REAL)
#	define z_aabb_contains_box	     z_aabb_type_contains_box	       (REAL)
#	define z_aabb_contains_point	     z_aabb_type_contains_point	       (REAL)
#	define z_aabb_contains_sphere	     z_aabb_type_contains_sphere       (REAL)
#	define z_aabb_from_vertices	     z_aabb_type_from_vertices	       (REAL)
#	define z_aabb_inner_sphere	     z_aabb_type_inner_sphere	       (REAL)
#	define z_aabb_intersect		     z_aabb_type_intersect	       (REAL)
#	define z_aabb_intersection	     z_aabb_type_intersection	       (REAL)
#	define z_aabb_is_zero		     z_3d_line_is_zero
#	define z_aabb_size		     z_aabb_type_size		       (REAL)
#	define z_aabb_swap		     z_3d_line_swap
#	define z_aabb_union		     z_aabb_type_union		       (REAL)
#	define z_aabb_unit_point_to_absolute z_aabb_type_unit_point_to_absolute(REAL)
#	define z_aabb_volume		     z_aabb_type_volume		       (REAL)
#endif


#endif /* _Z_functions_mathematics_geometry_euclidean_ZAABB_H_ */
