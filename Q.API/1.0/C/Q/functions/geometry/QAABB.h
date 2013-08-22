/* Q API - functions/geometry/QAABB.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_QAABB_H__
#define __Q_functions_geometry_QAABB_H__

#include <Q/functions/geometry/Q3DLine.h>

#define q_float_aabb_are_equal		q_3d_float_vector_are_equal
#define q_float_aabb_is_zero		q_3d_float_vector_is_zero
#define q_float_aabb_center		q_3d_float_line_segment_center

#define q_double_aabb_are_equal		q_3d_double_vector_are_equal
#define q_double_aabb_is_zero		q_3d_double_vector_is_zero
#define q_double_aabb_center		q_3d_double_line_segment_center

#define q_ldouble_aabb_are_equal	q_3d_ldouble_vector_are_equal
#define q_ldouble_aabb_is_zero		q_3d_ldouble_vector_is_zero
#define q_ldouble_aabb_center		q_3d_ldouble_line_segment_center

#define q_aabb_are_equal		q_3d_vector_are_equal
#define q_aabb_is_zero			q_3d_vector_is_zero
#define q_aabb_center			q_3d_line_segment_center

#ifndef Q_AABB_EXPORT
#	define Q_AABB_EXPORT Q_INLINE
#endif


#define Q_IMPLEMENTATION_AABB(Type, type, _)					\
										\
										\
Q_AABB_EXPORT									\
qboolean q_##type##_aabb_contains(Q##Type##AABB a, Q##Type##AABB b)		\
	{									\
	return	b.a.x >= a.a.x && b.a.y >= a.a.y && b.a.z >= a.a.z &&		\
		b.b.x <= a.b.x && b.b.y <= a.b.y && b.b.z <= a.b.z;		\
	}									\
										\
										\
Q_AABB_EXPORT									\
qboolean q_##type##_aabb_collision(Q##Type##AABB a, Q##Type##AABB b)		\
	{									\
	return	a.a.x < b.b.x && b.a.x < a.b.x &&				\
		a.a.y < b.b.y && b.a.y < a.b.y &&				\
		a.a.z < b.b.z && b.a.z < a.b.z;					\
	}									\
										\
										\
Q_AABB_EXPORT									\
Q##Type##AABB q_##type##_aabb_intersection(Q##Type##AABB a, Q##Type##AABB b)	\
	{									\
	q##type x1, x2, y1, y2, z1, z2;						\
										\
	return	(x1 = q_##type##_maximum(a.a.x, b.a.x)) <=			\
		(x2 = q_##type##_minimum(a.b.x, b.b.x)) &&			\
		(y1 = q_##type##_maximum(a.a.y, b.a.y))	<=			\
		(y2 = q_##type##_minimum(a.b.y, b.b.y)) &&			\
		(z1 = q_##type##_maximum(a.a.z, b.a.z))	<=			\
		(z2 = q_##type##_minimum(a.b.z, b.b.z))				\
										\
		? q_##type##_aabb(x1, y1, z1, x2, y2, z2)			\
		: q_##type##_aabb_zero;						\
	}									\
										\
										\
Q_AABB_EXPORT									\
Q##Type##AABB q_##type##_aabb_union(Q##Type##AABB a, Q##Type##AABB b)		\
	{									\
	Q##Type##AABB result;							\
										\
	result.a = q_3d_##type##_minimum(a.a, b.a);				\
	result.b = q_3d_##type##_maximum(a.b, b.b);				\
										\
	return result;								\
	}									\
										\
										\
Q_AABB_EXPORT									\
Q##Type##AABB q_##type##_aabb_from_vertices(Q3D##Type a, Q3D##Type b)		\
	{									\
	Q##Type##AABB result;							\
										\
	result.a = q_3d_##type##_minimum(a, b);					\
	result.b = q_3d_##type##_maximum(a, b);					\
										\
	return result;								\
	}									\
										\
										\
Q_AABB_EXPORT									\
Q3D##Type q_##type##_aabb_size(Q##Type##AABB aabb)				\
	{return q_3d_##type##_subtract(aabb.b, aabb.a);}			\
										\
										\
Q_AABB_EXPORT									\
q##type q_##type##_aabb_volume(Q##Type##AABB aabb)				\
	{									\
	return q_3d_##type##_inner_product					\
		(q_3d_##type##_subtract(aabb.b, aabb.a));			\
	}									\
										\
										\
Q_AABB_EXPORT									\
Q##Type##Sphere q_##type##_aabb_inner_sphere(Q##Type##AABB aabb)		\
	{									\
	Q##Type##Sphere result;							\
										\
	result.point = q_##type##_aabb_center(aabb);				\
										\
	result.radius =								\
	q_##type##_minimum							\
		(q_##type##_minimum(aabb.b.x - aabb.a.x, aabb.b.y - aabb.a.y),	\
		 aabb.b.z - aabb.a.z)						\
	/ _(2.0);								\
										\
	return result;								\
	}									\
										\
										\
Q_AABB_EXPORT									\
qboolean q_##type##_aabb_contains_point(Q##Type##AABB aabb, Q3D##Type point)	\
	{									\
	return	aabb.a.x <= point.x && point.x <= aabb.a.x &&			\
		aabb.a.y <= point.y && point.y <= aabb.a.y &&			\
		aabb.a.z <= point.z && point.z <= aabb.a.z;			\
	}									\
										\
										\
Q_AABB_EXPORT									\
qboolean q_##type##_aabb_contains_line_segment(					\
	Q##Type##AABB	aabb,							\
	Q3D##Type##Line segment							\
)										\
	{									\
	return	q_##type##_aabb_contains_point(aabb, segment.a) &&		\
		q_##type##_aabb_contains_point(aabb, segment.b);		\
	}									\
										\
										\
Q_AABB_EXPORT									\
qboolean q_##type##_aabb_contains_box(Q##Type##AABB aabb, Q##Type##Box box)	\
	{									\
	return	aabb.a.x <= box.point.x		     &&				\
		aabb.a.y <= box.point.y		     &&				\
		aabb.a.z <= box.point.z		     &&				\
		aabb.b.x >= box.point.x + box.size.x &&				\
		aabb.b.y >= box.point.y + box.size.y &&				\
		aabb.b.z >= box.point.z + box.size.z;				\
	}									\
										\
										\
Q_AABB_EXPORT									\
qboolean q_##type##_aabb_contains_sphere(					\
	Q##Type##AABB	aabb,							\
	Q##Type##Sphere sphere							\
)										\
	{									\
	return	sphere.point.x - sphere.radius >= aabb.a.x &&			\
		sphere.point.y - sphere.radius >= aabb.a.y &&			\
		sphere.point.z - sphere.radius >= aabb.a.z &&			\
		sphere.point.x + sphere.radius <= aabb.b.x &&			\
		sphere.point.y + sphere.radius <= aabb.b.y &&			\
		sphere.point.z + sphere.radius <= aabb.b.z;			\
	}


Q_IMPLEMENTATION_AABB(Float,   float,	Q_FLOAT	 )
Q_IMPLEMENTATION_AABB(Double,  double,	Q_DOUBLE )
Q_IMPLEMENTATION_AABB(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_aabb_contains			q_float_aabb_contains
#	define q_aabb_collision			q_float_aabb_collision
#	define q_aabb_intersection		q_float_aabb_intersection
#	define q_aabb_union			q_float_aabb_union
#	define q_aabb_from_vertices		q_float_aabb_from_vertices
#	define q_aabb_size			q_float_aabb_size
#	define q_aabb_volume			q_float_aabb_volume
#	define q_aabb_inner_sphere		q_float_aabb_inner_sphere
#	define q_aabb_contains_point		q_float_aabb_contains_point
#	define q_aabb_contains_line_segment	q_float_aabb_contains_line_segment
#	define q_aabb_contains_box		q_float_aabb_contains_box
#	define q_aabb_contains_sphere		q_float_aabb_contains_sphere

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_aabb_contains			q_ldouble_aabb_contains
#	define q_aabb_collision			q_ldouble_aabb_collision
#	define q_aabb_intersection		q_ldouble_aabb_intersection
#	define q_aabb_union			q_ldouble_aabb_union
#	define q_aabb_from_vertices		q_ldouble_aabb_from_vertices
#	define q_aabb_size			q_ldouble_aabb_size
#	define q_aabb_volume			q_ldouble_aabb_volume
#	define q_aabb_inner_sphere		q_ldouble_aabb_inner_sphere
#	define q_aabb_contains_point		q_ldouble_aabb_contains_point
#	define q_aabb_contains_line_segment	q_ldouble_aabb_contains_line_segment
#	define q_aabb_contains_box		q_ldouble_aabb_contains_box
#	define q_aabb_contains_sphere		q_ldouble_aabb_contains_sphere

#else

#	define q_aabb_contains			q_double_aabb_contains
#	define q_aabb_collision			q_double_aabb_collision
#	define q_aabb_intersection		q_double_aabb_intersection
#	define q_aabb_union			q_double_aabb_union
#	define q_aabb_from_vertices		q_double_aabb_from_vertices
#	define q_aabb_size			q_double_aabb_size
#	define q_aabb_volume			q_double_aabb_volume
#	define q_aabb_inner_sphere		q_double_aabb_inner_sphere
#	define q_aabb_contains_point		q_double_aabb_contains_point
#	define q_aabb_contains_line_segment	q_double_aabb_contains_line_segment
#	define q_aabb_contains_box		q_double_aabb_contains_box
#	define q_aabb_contains_sphere		q_double_aabb_contains_sphere

#endif

#endif /* __Q_functions_geometry_QAABB_H__ */
