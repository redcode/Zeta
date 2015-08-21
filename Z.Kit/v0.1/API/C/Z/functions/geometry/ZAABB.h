/* Z Kit C API - functions/geometry/ZAABB.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_ZAABB_H__
#define __Z_functions_geometry_ZAABB_H__

#include <Z/functions/geometry/Z3DLine.h>

#define z_aabb_float_are_equal	 z_3d_line_float_are_equal
#define z_aabb_float_is_zero	 z_3d_line_float_is_zero
#define z_aabb_float_center	 z_3d_line_segment_float_center

#define z_aabb_double_are_equal	 z_3d_line_double_are_equal
#define z_aabb_double_is_zero	 z_3d_line_double_is_zero
#define z_aabb_double_center	 z_3d_line_segment_double_center

#define z_aabb_ldouble_are_equal z_3d_line_ldouble_are_equal
#define z_aabb_ldouble_is_zero	 z_3d_line_ldouble_is_zero
#define z_aabb_ldouble_center	 z_3d_line_segment_ldouble_center


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


Z_IMPLEMENTATION_AABB(Float,   float,	Z_FLOAT	 )
Z_IMPLEMENTATION_AABB(Double,  double,	Z_DOUBLE )
Z_IMPLEMENTATION_AABB(LDouble, ldouble, Z_LDOUBLE)


/* MARK: - Default real type definitions */

#define z_aabb_are_equal	      z_3d_line_are_equal
#define z_aabb_is_zero		      z_3d_line_is_zero
#define z_aabb_center		      z_3d_line_segment_center

#define z_aabb_contains		      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _contains	       )
#define z_aabb_collide		      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _collide	       )
#define z_aabb_intersection	      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _intersection	       )
#define z_aabb_union		      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _union		       )
#define z_aabb_from_vertices	      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _from_vertices	       )
#define z_aabb_size		      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _size		       )
#define z_aabb_volume		      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _volume		       )
#define z_aabb_inner_sphere	      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _inner_sphere	       )
#define z_aabb_to_box		      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _to_box		       )
#define z_aabb_absolute_point_to_unit Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _absolute_point_to_unit)
#define z_aabb_unit_point_to_absolute Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _unit_point_to_absolute)
#define z_aabb_contains_point	      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _contains_point	       )
#define z_aabb_contains_line_segment  Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _contains_line_segment )
#define z_aabb_contains_box	      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _contains_box	       )
#define z_aabb_contains_sphere	      Z_JOIN_3(z_aabb_, Z_REAL_FIXED_TYPE_name, _contains_sphere       )

#endif /* __Z_functions_geometry_ZAABB_H__ */
