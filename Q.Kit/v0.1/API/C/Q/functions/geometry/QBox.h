/* Q Kit C API - functions/geometry/QBox.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_QBox_H__
#define __Q_functions_geometry_QBox_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/base/Q3DValue.h>


#define Q_IMPLEMENTATION_BOX(Type, type, _)							\
												\
												\
Q_INLINE qboolean q_box_##type##_are_equal(QBox##Type a, QBox##Type b)				\
	{											\
	return	q_3d_##type##_are_equal(a.point, b.point) &&					\
		q_3d_##type##_are_equal(a.size,  b.size );					\
	}											\
												\
												\
Q_INLINE qboolean q_box_##type##_contains(QBox##Type a, QBox##Type b)				\
	{											\
	return	b.point.x	     >= a.point.x	     &&					\
		b.point.y	     >= a.point.y	     &&					\
		b.point.z	     >= a.point.z	     &&					\
		b.point.x + b.size.x <= a.point.x + a.size.x &&					\
		b.point.y + b.size.y <= a.point.y + a.size.y &&					\
		b.point.z + b.size.z <= a.point.z + a.size.z;					\
	}											\
												\
												\
Q_INLINE qboolean q_box_##type##_collide(QBox##Type a, QBox##Type b)				\
	{											\
	return	a.point.x < b.point.x + b.size.x &&						\
		b.point.x < a.point.x + a.size.x &&						\
		a.point.y < b.point.y + b.size.y &&						\
		b.point.y < a.point.y + a.size.y &&						\
		a.point.z < b.point.z + b.size.z &&						\
		b.point.z < a.point.z + a.size.z;						\
	}											\
												\
												\
Q_INLINE QBox##Type q_box_##type##_intersection(QBox##Type a, QBox##Type b)			\
	{											\
	q##type x1, x2, y1, y2, z1, z2;								\
												\
	return	(x1 = q_##type##_maximum(a.point.x, b.point.x)) <=				\
		(x2 = q_##type##_minimum(a.point.x + a.size.x, b.point.x + b.size.x)) &&	\
		(y1 = q_##type##_maximum(a.point.y, b.point.y)) <=				\
		(y2 = q_##type##_minimum(a.point.y + a.size.y, b.point.y + b.size.y)) &&	\
		(z1 = q_##type##_maximum(a.point.z, b.point.z)) <=				\
		(z2 = q_##type##_minimum(a.point.z + a.size.z, b.point.z + b.size.z))		\
												\
		? q_box_##type(x1, y1, z1, x2 - x1, y2 - y1, z2 - z1)				\
		: q_box_##type##_zero;								\
	}											\
												\
												\
Q_INLINE QBox##Type q_box_##type##_union(QBox##Type a, QBox##Type b)				\
	{											\
	QBox##Type result;									\
												\
	result.point = q_3d_##type##_minimum(a.point, b.point);					\
												\
	result.size.x =										\
	q_##type##_maximum(a.point.x + a.size.x, b.point.x + b.size.x) - result.point.x;	\
												\
	result.size.y =										\
	q_##type##_maximum(a.point.y + a.size.y, b.point.y + b.size.y) - result.point.y;	\
												\
	result.size.z =										\
	q_##type##_maximum(a.point.z + a.size.z, b.point.z + b.size.z) - result.point.z;	\
												\
	return result;										\
	}											\
												\
												\
Q_INLINE QBox##Type q_box_##type##_from_vertices(Q3D##Type a, Q3D##Type b)			\
	{											\
	Q3D##Type minimum = q_3d_##type##_minimum(a, b);					\
	Q3D##Type maximum = q_3d_##type##_maximum(a, b);					\
												\
	return q_box_##type									\
		(minimum.x,  minimum.y, minimum.z,						\
		 maximum.x - minimum.x, maximum.y - minimum.y, maximum.z - minimum.z);		\
	}											\
												\
												\
Q_INLINE qboolean q_box_##type##_is_zero(QBox##Type object)					\
	{return	q_3d_##type##_is_zero(object.point) && q_3d_##type##_is_zero(object.size);}	\
												\
												\
Q_INLINE Q3D##Type q_box_##type##_center(QBox##Type object)					\
	{											\
	return q_3d_##type									\
		(object.point.x + object.size.x / _(2.0),					\
		 object.point.y + object.size.y / _(2.0),					\
		 object.point.z + object.size.z / _(2.0));					\
	}											\
												\
												\
 Q_INLINE QBox##Type q_box_##type##_correct(QBox##Type object)					\
	{											\
	if (object.size.x < _(0.0)) object.point.x -= (object.size.x = -object.size.x);		\
	if (object.size.y < _(0.0)) object.point.y -= (object.size.y = -object.size.y);		\
	if (object.size.z < _(0.0)) object.point.z -= (object.size.z = -object.size.z);		\
 	return object;										\
	}											\
												\
												\
Q_INLINE QSphere##Type q_box_##type##_inner_sphere(QBox##Type object)				\
	{											\
	QSphere##Type result;									\
												\
	result.point = q_box_##type##_center(object);						\
												\
	result.radius =										\
	q_##type##_minimum(q_##type##_minimum(object.size.x, object.size.y), object.size.z)	\
	/ _(2.0);										\
												\
	return result;										\
	}											\
												\
												\
Q_INLINE QAABB##Type q_box_##type##_to_aabb(QBox##Type object)					\
	{											\
	return q_aabb_##type									\
		(object.point.x,  object.point.y, object.point.z,				\
		 object.point.x + object.size.x,						\
		 object.point.y + object.size.y,						\
		 object.point.z + object.size.z);						\
	}											\
												\
												\
Q_INLINE Q3D##Type q_box_##type##_absolute_point_to_unit(QBox##Type object, Q3D##Type point)	\
	{											\
	return q_3d_##type									\
		((point.x - object.point.x) / object.size.x,					\
		 (point.y - object.point.y) / object.size.y,					\
		 (point.z - object.point.z) / object.size.z);					\
	}											\
												\
												\
Q_INLINE Q3D##Type q_box_##type##_unit_point_to_absolute(QBox##Type object, Q3D##Type point)	\
	{											\
	return q_3d_##type									\
		(point.x * object.size.x + object.point.x,					\
		 point.y * object.size.y + object.point.y,					\
		 point.z * object.size.z + object.point.z);					\
	}											\
												\
												\
Q_INLINE qboolean q_box_##type##_contains_point(QBox##Type object, Q3D##Type point)		\
	{											\
	return	point.x >= object.point.x		  &&					\
		point.y >= object.point.y		  &&					\
		point.z >= object.point.z		  &&					\
		point.x <= object.point.x + object.size.x &&					\
		point.y <= object.point.y + object.size.y &&					\
		point.z <= object.point.z + object.size.z;					\
	}											\
												\
												\
Q_INLINE qboolean q_box_##type##_contains_line_segment(						\
	QBox##Type    object,									\
	Q3DLine##Type line_segment								\
)												\
	{											\
	return	q_box_##type##_contains_point(object, line_segment.a) &&			\
		q_box_##type##_contains_point(object, line_segment.b);				\
	}											\
												\
												\
Q_INLINE qboolean q_box_##type##_contains_aabb(QBox##Type object, QAABB##Type aabb)		\
	{											\
	return	aabb.a.x >= object.point.x		   &&					\
		aabb.a.y >= object.point.y		   &&					\
		aabb.a.z >= object.point.z		   &&					\
		aabb.b.x <= object.point.x + object.size.x &&					\
		aabb.b.y <= object.point.y + object.size.y &&					\
		aabb.b.z <= object.point.z + object.size.z;					\
	}											\
												\
												\
Q_INLINE qboolean q_box_##type##_contains_sphere(QBox##Type object, QSphere##Type sphere)	\
	{											\
	return	sphere.point.x - sphere.radius >= object.point.x		 &&		\
		sphere.point.y - sphere.radius >= object.point.y		 &&		\
		sphere.point.z - sphere.radius >= object.point.z		 &&		\
		sphere.point.x + sphere.radius <= object.point.x + object.size.x &&		\
		sphere.point.y + sphere.radius <= object.point.y + object.size.y &&		\
		sphere.point.z + sphere.radius <= object.point.z + object.size.z;		\
	}


Q_IMPLEMENTATION_BOX(Float,   float,   Q_FLOAT	)
Q_IMPLEMENTATION_BOX(Double,  double,  Q_DOUBLE	)
Q_IMPLEMENTATION_BOX(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#define q_box_are_equal		     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _are_equal	     )
#define q_box_contains		     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _contains		     )
#define q_box_collide		     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _collide		     )
#define q_box_intersection	     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _intersection	     )
#define q_box_union		     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _union		     )
#define q_box_from_vertices	     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _from_vertices	     )
#define q_box_is_zero		     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _is_zero		     )
#define q_box_center		     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _center		     )
#define q_box_correct		     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _correct		     )
#define q_box_inner_sphere	     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _inner_sphere	     )
#define q_box_to_aabb		     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _to_aabb		     )
#define q_box_absolute_point_to_unit Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _absolute_point_to_unit)
#define q_box_unit_point_to_absolute Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _unit_point_to_absolute)
#define q_box_contains_point	     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _contains_point	     )
#define q_box_contains_line_segment  Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _contains_line_segment )
#define q_box_contains_aabb	     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _contains_aabb	     )
#define q_box_contains_sphere	     Q_JOIN_3(q_box_, Q_REAL_FIXED_TYPE_name, _contains_sphere	     )

#endif /* __Q_functions_geometry_QBox_H__ */
