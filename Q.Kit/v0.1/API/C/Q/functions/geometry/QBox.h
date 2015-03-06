/* Q C API - functions/geometry/QBox.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_QBox_H__
#define __Q_functions_geometry_QBox_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/base/Q3D.h>


#define Q_IMPLEMENTATION_BOX(Type, type, _)					\
										\
										\
Q_INLINE qboolean q_##type##_box_are_equal(Q##Type##Box a, Q##Type##Box b)	\
	{									\
	return	q_3d_##type##_are_equal(a.point, b.point) &&			\
		q_3d_##type##_are_equal(a.size,  b.size );			\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_box_contains(Q##Type##Box a, Q##Type##Box b)	\
	{									\
	return	b.point.x	     >= a.point.x	     &&			\
		b.point.y	     >= a.point.y	     &&			\
		b.point.z	     >= a.point.z	     &&			\
		b.point.x + b.size.x <= a.point.x + a.size.x &&			\
		b.point.y + b.size.y <= a.point.y + a.size.y &&			\
		b.point.z + b.size.z <= a.point.z + a.size.z;			\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_box_collide(Q##Type##Box a, Q##Type##Box b)	\
	{									\
	return	a.point.x < b.point.x + b.size.x &&				\
		b.point.x < a.point.x + a.size.x &&				\
		a.point.y < b.point.y + b.size.y &&				\
		b.point.y < a.point.y + a.size.y &&				\
		a.point.z < b.point.z + b.size.z &&				\
		b.point.z < a.point.z + a.size.z;				\
	}									\
										\
										\
Q_INLINE									\
Q##Type##Box q_##type##_box_intersection(Q##Type##Box a, Q##Type##Box b)	\
	{									\
	q##type x1, x2, y1, y2, z1, z2;						\
										\
	return	(x1 = q_##type##_maximum(a.point.x, b.point.x))	      <=	\
		(x2 = q_##type##_minimum					\
			(a.point.x + a.size.x, b.point.x + b.size.x)) &&	\
		(y1 = q_##type##_maximum(a.point.y, b.point.y))	      <=	\
		(y2 = q_##type##_minimum					\
			(a.point.y + a.size.y, b.point.y + b.size.y)) &&	\
		(z1 = q_##type##_maximum(a.point.z, b.point.z))	      <=	\
		(z2 = q_##type##_minimum					\
			(a.point.z + a.size.z, b.point.z + b.size.z))		\
										\
		? q_##type##_box(x1, y1, z1, x2 - x1, y2 - y1, z2 - z1)		\
		: q_##type##_box_zero;						\
	}									\
										\
										\
Q_INLINE Q##Type##Box q_##type##_box_union(Q##Type##Box a, Q##Type##Box b)	\
	{									\
	Q##Type##Box result;							\
										\
	result.point = q_3d_##type##_minimum(a.point, b.point);			\
										\
	result.size.x =								\
	q_##type##_maximum(a.point.x + a.size.x, b.point.x + b.size.x) -	\
	result.point.x;								\
										\
	result.size.y =								\
	q_##type##_maximum(a.point.y + a.size.y, b.point.y + b.size.y) -	\
	result.point.y;								\
										\
	result.size.z =								\
	q_##type##_maximum(a.point.z + a.size.z, b.point.z + b.size.z) -	\
	result.point.z;								\
										\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##Box q_##type##_box_from_vertices(Q3D##Type a, Q3D##Type b)	\
	{									\
	Q3D##Type minimum = q_3d_##type##_minimum(a, b);			\
	Q3D##Type maximum = q_3d_##type##_maximum(a, b);			\
										\
	return q_##type##_box							\
		(minimum.x,  minimum.y, minimum.z,				\
		 maximum.x - minimum.x,						\
		 maximum.y - minimum.y,						\
		 maximum.z - minimum.z);					\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_box_is_zero(Q##Type##Box box)			\
	{									\
	return	q_3d_##type##_is_zero(box.point) &&				\
		q_3d_##type##_is_zero(box.size);				\
	}									\
										\
										\
Q_INLINE Q3D##Type q_##type##_box_center(Q##Type##Box box)			\
	{									\
	return q_3d_##type							\
		(box.point.x + box.size.x / _(2.0),				\
		 box.point.y + box.size.y / _(2.0),				\
		 box.point.z + box.size.z / _(2.0));				\
	}									\
										\
										\
 Q_INLINE Q##Type##Box q_##type##_box_correct(Q##Type##Box box)			\
	{									\
	if (box.size.x < _(0.0)) box.point.x -= (box.size.x = -box.size.x);	\
	if (box.size.y < _(0.0)) box.point.y -= (box.size.y = -box.size.y);	\
	if (box.size.z < _(0.0)) box.point.z -= (box.size.z = -box.size.z);	\
 	return box;								\
	}									\
										\
										\
Q_INLINE Q##Type##Sphere q_##type##_box_inner_sphere(Q##Type##Box box)		\
	{									\
	Q##Type##Sphere result;							\
										\
	result.point = q_##type##_box_center(box);				\
										\
	result.radius =								\
	q_##type##_minimum							\
		(q_##type##_minimum(box.size.x, box.size.y), box.size.z)	\
	/ _(2.0);								\
										\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABB q_##type##_box_to_aabb(Q##Type##Box box)			\
	{									\
	return q_##type##_aabb							\
		(box.point.x,  box.point.y, box.point.z,			\
		 box.point.x + box.size.x,					\
		 box.point.y + box.size.y,					\
		 box.point.z + box.size.z);					\
	}									\
										\
										\
Q_INLINE Q3D##Type q_##type##_box_absolute_point_to_unit(			\
	Q##Type##Box	box,							\
	Q3D##Type	point							\
										\
)										\
	{									\
	return q_3d_##type							\
		((point.x - box.point.x) / box.size.x,				\
		 (point.y - box.point.y) / box.size.y,				\
		 (point.z - box.point.z) / box.size.z);				\
	}									\
										\
										\
Q_INLINE Q3D##Type q_##type##_box_unit_point_to_absolute(			\
	Q##Type##Box	box,							\
	Q3D##Type	point							\
										\
)										\
	{									\
	return q_3d_##type							\
		(point.x * box.size.x + box.point.x,				\
		 point.y * box.size.y + box.point.y,				\
		 point.z * box.size.z + box.point.z);				\
	}									\
										\
										\
Q_INLINE									\
qboolean q_##type##_box_contains_point(Q##Type##Box box, Q3D##Type point)	\
	{									\
	return	point.x >= box.point.x		    &&				\
		point.y >= box.point.y		    &&				\
		point.z >= box.point.z		    &&				\
		point.x <= box.point.x + box.size.x &&				\
		point.y <= box.point.y + box.size.y &&				\
		point.z <= box.point.z + box.size.z;				\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_box_contains_line_segment(				\
	Q##Type##Box	box,							\
	Q3D##Type##Line line_segment						\
)										\
	{									\
	return	q_##type##_box_contains_point(box, line_segment.a) &&		\
		q_##type##_box_contains_point(box, line_segment.b);		\
	}									\
										\
										\
Q_INLINE									\
qboolean q_##type##_box_contains_aabb(Q##Type##Box box, Q##Type##AABB aabb)	\
	{									\
	return	aabb.a.x >= box.point.x		     &&				\
		aabb.a.y >= box.point.y		     &&				\
		aabb.a.z >= box.point.z		     &&				\
		aabb.b.x <= box.point.x + box.size.x &&				\
		aabb.b.y <= box.point.y + box.size.y &&				\
		aabb.b.z <= box.point.z + box.size.z;				\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_box_contains_sphere(				\
	Q##Type##Box	box,							\
	Q##Type##Sphere sphere							\
)										\
	{									\
	return	sphere.point.x - sphere.radius >= box.point.x		   &&	\
		sphere.point.y - sphere.radius >= box.point.y		   &&	\
		sphere.point.z - sphere.radius >= box.point.z		   &&	\
		sphere.point.x + sphere.radius <= box.point.x + box.size.x &&	\
		sphere.point.y + sphere.radius <= box.point.y + box.size.y &&	\
		sphere.point.z + sphere.radius <= box.point.z + box.size.z;	\
	}


Q_IMPLEMENTATION_BOX(Float,   float,   Q_FLOAT	)
Q_IMPLEMENTATION_BOX(Double,  double,  Q_DOUBLE	)
Q_IMPLEMENTATION_BOX(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_box_are_equal			q_float_box_are_equal
#	define q_box_contains			q_float_box_contains
#	define q_box_collide			q_float_box_collide
#	define q_box_intersection		q_float_box_intersection
#	define q_box_union			q_float_box_union
#	define q_box_from_vertices		q_float_box_from_vertices
#	define q_box_is_zero			q_float_box_is_zero
#	define q_box_center			q_float_box_center
#	define q_box_correct			q_float_box_correct
#	define q_box_inner_sphere		q_float_box_inner_sphere
#	define q_box_to_aabb			q_float_box_to_aabb
#	define q_box_absolute_point_to_unit	q_float_box_absolute_point_to_unit
#	define q_box_unit_point_to_absolute	q_float_box_unit_point_to_absolute
#	define q_box_contains_point		q_float_box_contains_point
#	define q_box_contains_line_segment	q_float_box_contains_line_segment
#	define q_box_contains_aabb		q_float_box_contains_aabb
#	define q_box_contains_sphere		q_float_box_contains_sphere

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_box_are_equal			q_ldouble_box_are_equal
#	define q_box_contains			q_ldouble_box_contains
#	define q_box_collide			q_ldouble_box_collide
#	define q_box_intersection		q_ldouble_box_intersection
#	define q_box_union			q_ldouble_box_union
#	define q_box_from_vertices		q_ldouble_box_from_vertices
#	define q_box_is_zero			q_ldouble_box_is_zero
#	define q_box_center			q_ldouble_box_center
#	define q_box_correct			q_ldouble_box_correct
#	define q_box_inner_sphere		q_ldouble_box_inner_sphere
#	define q_box_to_aabb			q_ldouble_box_to_aabb
#	define q_box_absolute_point_to_unit	q_ldouble_box_absolute_point_to_unit
#	define q_box_unit_point_to_absolute	q_ldouble_box_unit_point_to_absolute
#	define q_box_contains_point		q_ldouble_box_contains_point
#	define q_box_contains_line_segment	q_ldouble_box_contains_line_segment
#	define q_box_contains_aabb		q_ldouble_box_contains_aabb
#	define q_box_contains_sphere		q_ldouble_box_contains_sphere

#else

#	define q_box_are_equal			q_double_box_are_equal
#	define q_box_contains			q_double_box_contains
#	define q_box_collide			q_double_box_collide
#	define q_box_intersection		q_double_box_intersection
#	define q_box_union			q_double_box_union
#	define q_box_from_vertices		q_double_box_from_vertices
#	define q_box_is_zero			q_double_box_is_zero
#	define q_box_center			q_double_box_center
#	define q_box_correct			q_double_box_correct
#	define q_box_inner_sphere		q_double_box_inner_sphere
#	define q_box_to_aabb			q_double_box_to_aabb
#	define q_box_absolute_point_to_unit	q_double_box_absolute_point_to_unit
#	define q_box_unit_point_to_absolute	q_double_box_unit_point_to_absolute
#	define q_box_contains_point		q_double_box_contains_point
#	define q_box_contains_line_segment	q_double_box_contains_line_segment
#	define q_box_contains_aabb		q_double_box_contains_aabb
#	define q_box_contains_sphere		q_double_box_contains_sphere

#endif

#endif /* __Q_functions_geometry_QBox_H__ */
