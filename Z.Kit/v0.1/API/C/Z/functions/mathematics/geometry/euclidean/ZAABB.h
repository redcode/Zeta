/* Z Kit C API - functions/mathematics/geometry/euclidean/ZAABB.h
 _____ 	_______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_mathematics_geometry_euclidean_ZAABB_H__
#define __Z_functions_mathematics_geometry_euclidean_ZAABB_H__

#include <Z/functions/mathematics/geometry/euclidean/Z3DLine.h>


/* MARK: - Implementation */


#define Z_IMPLEMENTATION_AABB(Type, type, _)							\
												\
												\
Z_INLINE zboolean z_aabb_##type##_contains(ZAABB##Type a, ZAABB##Type b)			\
	{											\
	return	b.a.x >= a.a.x && b.a.y >= a.a.y && b.a.z >= a.a.z &&				\
		b.b.x <= a.b.x && b.b.y <= a.b.y && b.b.z <= a.b.z;				\
	}											\
												\
												\
Z_INLINE zboolean z_aabb_##type##_collide(ZAABB##Type a, ZAABB##Type b)				\
	{											\
	return	a.a.x < b.b.x && b.a.x < a.b.x &&						\
		a.a.y < b.b.y && b.a.y < a.b.y &&						\
		a.a.z < b.b.z && b.a.z < a.b.z;							\
	}											\
												\
												\
Z_INLINE ZAABB##Type z_aabb_##type##_intersection(ZAABB##Type a, ZAABB##Type b)			\
	{											\
	z##type x1, x2, y1, y2, z1, z2;								\
												\
	return	(x1 = z_##type##_maximum(a.a.x, b.a.x)) <=					\
		(x2 = z_##type##_minimum(a.b.x, b.b.x)) &&					\
		(y1 = z_##type##_maximum(a.a.y, b.a.y))	<=					\
		(y2 = z_##type##_minimum(a.b.y, b.b.y)) &&					\
		(z1 = z_##type##_maximum(a.a.z, b.a.z))	<=					\
		(z2 = z_##type##_minimum(a.b.z, b.b.z))						\
												\
		? z_aabb_##type(x1, y1, z1, x2, y2, z2)						\
		: z_aabb_##type##_zero;								\
	}											\
												\
												\
Z_INLINE ZAABB##Type z_aabb_##type##_union(ZAABB##Type a, ZAABB##Type b)			\
	{											\
	ZAABB##Type result;									\
												\
	result.a = z_3d_##type##_minimum(a.a, b.a);						\
	result.b = z_3d_##type##_maximum(a.b, b.b);						\
	return result;										\
	}											\
												\
												\
Z_INLINE ZAABB##Type z_aabb_##type##_from_vertices(Z3D##Type a, Z3D##Type b)			\
	{											\
	ZAABB##Type result;									\
												\
	result.a = z_3d_##type##_minimum(a, b);							\
	result.b = z_3d_##type##_maximum(a, b);							\
	return result;										\
	}											\
												\
												\
Z_INLINE Z3D##Type z_aabb_##type##_size(ZAABB##Type object)					\
	{return z_3d_##type##_subtract(object.b, object.a);}					\
												\
												\
Z_INLINE z##type z_aabb_##type##_volume(ZAABB##Type object)					\
	{return z_3d_##type##_inner_product(z_3d_##type##_subtract(object.b, object.a));}	\
												\
												\
Z_INLINE ZSphere##Type z_aabb_##type##_inner_sphere(ZAABB##Type object)				\
	{											\
	ZSphere##Type result;									\
												\
	result.point = z_aabb_##type##_center(object);						\
												\
	result.radius =										\
	z_##type##_minimum									\
		(z_##type##_minimum(object.b.x - object.a.x, object.b.y - object.a.y),		\
		 object.b.z - object.a.z)							\
	/ _(2.0);										\
												\
	return result;										\
	}											\
												\
												\
Z_INLINE ZBox##Type z_aabb_##type##_to_box(ZAABB##Type object)					\
	{											\
	return z_box_##type									\
		(object.a.x, object.a.y, object.a.z,						\
		 object.b.x - object.a.x, object.b.y - object.a.y, object.b.z - object.a.z);	\
	}											\
												\
												\
Z_INLINE Z3D##Type z_aabb_##type##_absolute_point_to_unit(ZAABB##Type object, Z3D##Type point)	\
	{											\
	return z_3d_##type									\
		((point.x - object.a.x) / (object.b.x - object.a.x),				\
		 (point.y - object.a.y) / (object.b.y - object.a.y),				\
		 (point.z - object.a.z) / (object.b.z - object.a.z));				\
	}											\
												\
												\
Z_INLINE Z3D##Type z_aabb_##type##_unit_point_to_absolute(ZAABB##Type object, Z3D##Type point)	\
	{											\
	return z_3d_##type									\
		(point.x * (object.b.x - object.a.x) + object.a.x,				\
		 point.y * (object.b.y - object.a.y) + object.a.y,				\
		 point.z * (object.b.z - object.a.z) + object.a.z);				\
	}											\
												\
												\
Z_INLINE zboolean z_aabb_##type##_contains_point(ZAABB##Type object, Z3D##Type point)		\
	{											\
	return	object.a.x <= point.x && point.x <= object.a.x &&				\
		object.a.y <= point.y && point.y <= object.a.y &&				\
		object.a.z <= point.z && point.z <= object.a.z;					\
	}											\
												\
												\
Z_INLINE zboolean z_aabb_##type##_contains_line_segment(					\
	ZAABB##Type   object,									\
	Z3DLine##Type segment									\
)												\
	{											\
	return	z_aabb_##type##_contains_point(object, segment.a) &&				\
		z_aabb_##type##_contains_point(object, segment.b);				\
	}											\
												\
												\
Z_INLINE zboolean z_aabb_##type##_contains_box(ZAABB##Type object, ZBox##Type box)		\
	{											\
	return	object.a.x <= box.point.x	       &&					\
		object.a.y <= box.point.y	       &&					\
		object.a.z <= box.point.z	       &&					\
		object.b.x >= box.point.x + box.size.x &&					\
		object.b.y >= box.point.y + box.size.y &&					\
		object.b.z >= box.point.z + box.size.z;						\
	}											\
												\
												\
Z_INLINE zboolean z_aabb_##type##_contains_sphere(ZAABB##Type object, ZSphere##Type sphere)	\
	{											\
	return	sphere.point.x - sphere.radius >= object.a.x &&					\
		sphere.point.y - sphere.radius >= object.a.y &&					\
		sphere.point.z - sphere.radius >= object.a.z &&					\
		sphere.point.x + sphere.radius <= object.b.x &&					\
		sphere.point.y + sphere.radius <= object.b.y &&					\
		sphere.point.z + sphere.radius <= object.b.z;					\
	}


#define z_aabb_type_contains(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _contains	      )
#define z_aabb_type_collide(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _collide		      )
#define z_aabb_type_intersection(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _intersection	      )
#define z_aabb_type_union(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _union		      )
#define z_aabb_type_from_vertices(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _from_vertices	      )
#define z_aabb_type_size(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _size		      )
#define z_aabb_type_volume(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _volume		      )
#define z_aabb_type_inner_sphere(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _inner_sphere	      )
#define z_aabb_type_to_box(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _to_box		      )
#define z_aabb_type_absolute_point_to_unit(TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _absolute_point_to_unit)
#define z_aabb_type_unit_point_to_absolute(TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _unit_point_to_absolute)
#define z_aabb_type_contains_point(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _contains_point	      )
#define z_aabb_type_contains_line_segment( TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _contains_line_segment )
#define z_aabb_type_contains_box(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _contains_box	      )
#define z_aabb_type_contains_sphere(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_, _contains_sphere	      )


/* MARK: - Implementation expansions */


#ifdef Z_FLOAT16

#	define z_aabb_float16_are_equal	z_3d_line_float16_are_equal
#	define z_aabb_float16_is_zero	z_3d_line_float16_is_zero
#	define z_aabb_float16_center	z_3d_line_segment_float16_center

	Z_IMPLEMENTATION_AABB(Float16, float16, Z_FLOAT16)

#endif

#ifdef Z_FLOAT24

#	define z_aabb_float24_are_equal	z_3d_line_float24_are_equal
#	define z_aabb_float24_is_zero	z_3d_line_float24_is_zero
#	define z_aabb_float24_center	z_3d_line_segment_float24_center

	Z_IMPLEMENTATION_AABB(Float24, float24, Z_FLOAT24)

#endif

#ifdef Z_FLOAT32

#	define z_aabb_float32_are_equal	z_3d_line_float32_are_equal
#	define z_aabb_float32_is_zero	z_3d_line_float32_is_zero
#	define z_aabb_float32_center	z_3d_line_segment_float32_center

	Z_IMPLEMENTATION_AABB(Float32, float32, Z_FLOAT32)

#endif

#ifdef Z_FLOAT48

#	define z_aabb_float48_are_equal	z_3d_line_float48_are_equal
#	define z_aabb_float48_is_zero	z_3d_line_float48_is_zero
#	define z_aabb_float48_center	z_3d_line_segment_float48_center

	Z_IMPLEMENTATION_AABB(Float48, float48, Z_FLOAT48)

#endif

#ifdef Z_FLOAT64

#	define z_aabb_float64_are_equal	z_3d_line_float64_are_equal
#	define z_aabb_float64_is_zero	z_3d_line_float64_is_zero
#	define z_aabb_float64_center	z_3d_line_segment_float64_center

	Z_IMPLEMENTATION_AABB(Float64, float64, Z_FLOAT64)

#endif

#ifdef Z_FLOAT72

#	define z_aabb_float72_are_equal	z_3d_line_float72_are_equal
#	define z_aabb_float72_is_zero	z_3d_line_float72_is_zero
#	define z_aabb_float72_center	z_3d_line_segment_float72_center

	Z_IMPLEMENTATION_AABB(Float72, float72, Z_FLOAT72)

#endif

#ifdef Z_FLOAT80

#	define z_aabb_float80_are_equal	z_3d_line_float80_are_equal
#	define z_aabb_float80_is_zero	z_3d_line_float80_is_zero
#	define z_aabb_float80_center	z_3d_line_segment_float80_center

	Z_IMPLEMENTATION_AABB(Float80, float80, Z_FLOAT80)

#endif

#ifdef Z_FLOAT96

#	define z_aabb_float96_are_equal	z_3d_line_float96_are_equal
#	define z_aabb_float96_is_zero	z_3d_line_float96_is_zero
#	define z_aabb_float96_center	z_3d_line_segment_float96_center

	Z_IMPLEMENTATION_AABB(Float96, float96, Z_FLOAT96)

#endif

#ifdef Z_FLOAT128

#	define z_aabb_float128_are_equal z_3d_line_float128_are_equal
#	define z_aabb_float128_is_zero	 z_3d_line_float128_is_zero
#	define z_aabb_float128_center	 z_3d_line_segment_float128_center

	Z_IMPLEMENTATION_AABB(Float128, float128, Z_FLOAT128)

#endif


/* MARK: - Default real type definitions */


#ifdef Z_REAL

#	define z_aabb_are_equal z_3d_line_are_equal
#	define z_aabb_is_zero	z_3d_line_is_zero
#	define z_aabb_center	z_3d_line_segment_center

#	define z_aabb_contains		     z_aabb_type_contains	       (REAL)
#	define z_aabb_collide		     z_aabb_type_collide	       (REAL)
#	define z_aabb_intersection	     z_aabb_type_intersection	       (REAL)
#	define z_aabb_union		     z_aabb_type_union		       (REAL)
#	define z_aabb_from_vertices	     z_aabb_type_from_vertices	       (REAL)
#	define z_aabb_size		     z_aabb_type_size		       (REAL)
#	define z_aabb_volume		     z_aabb_type_volume		       (REAL)
#	define z_aabb_inner_sphere	     z_aabb_type_inner_sphere	       (REAL)
#	define z_aabb_to_box		     z_aabb_type_to_box		       (REAL)
#	define z_aabb_absolute_point_to_unit z_aabb_type_absolute_point_to_unit(REAL)
#	define z_aabb_unit_point_to_absolute z_aabb_type_unit_point_to_absolute(REAL)
#	define z_aabb_contains_point	     z_aabb_type_contains_point	       (REAL)
#	define z_aabb_contains_line_segment  z_aabb_type_contains_line_segment (REAL)
#	define z_aabb_contains_box	     z_aabb_type_contains_box	       (REAL)
#	define z_aabb_contains_sphere	     z_aabb_type_contains_sphere       (REAL)

#endif


#endif /* __Z_functions_mathematics_geometry_euclidean_ZAABB_H__ */
