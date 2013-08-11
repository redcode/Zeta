/* Q API - functions/geometry/QBox.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_QBox_H__
#define __Q_functions_geometry_QBox_H__

#include <Q/types/geometry.h>
#include <Q/functions/Q3D.h>

#ifndef Q_BOX_EXPORT
#	define Q_BOX_EXPORT Q_INLINE
#endif

#if Q_C_HAS(COMPOUND_LITERAL)

#	define	q_float_box(  x, y, z,	 size_x, size_y, size_z) \
		((QFloatBox){{x, y, z}, {size_x, size_y, size_z}})

#	define	q_double_box(  x, y, z,	  size_x, size_y, size_z) \
		((QDoubleBox){{x, y, z}, {size_x, size_y, size_z}})

#	define	q_ldouble_box(	x, y, z,   size_x, size_y, size_z) \
		((QLDoubleBox){{x, y, z}, {size_x, size_y, size_z}})

#	define Q_BOX_NEW(Type, type)

#else

#	define Q_BOX_NEW(Type, type)						\
										\
	Q_INLINE Q##Type##Box q_##type##_box(					\
		q##type x,							\
		q##type y,							\
		q##type z,							\
		q##type size_x,							\
		q##type size_y,							\
		q##type size_z							\
	)									\
		{								\
		Q##Type##Box box = {{x, y, z}, {size_x, size_y, size_z}};	\
		return box;							\
		}

#endif

#define q_float_box_zero   q_float_box  (0.0F, 0.0F, 0.0F, 0.0F, 0.0F)
#define q_double_box_zero  q_double_box (0.0,  0.0,  0.0,  0.0,	 0.0 )
#define q_ldouble_box_zero q_ldouble_box(0.0L, 0.0L, 0.0L, 0.0L, 0.0L)


#define Q_IMPLEMENTATION_BOX(Type, type, _)					\
										\
										\
Q_BOX_NEW(Type, type)								\
										\
										\
Q_BOX_EXPORT									\
qboolean q_##type##_box_are_equal(Q##Type##Box a, Q##Type##Box b)		\
	{									\
	return	q_3d_##type##_are_equal(a.point, b.point) &&			\
		q_3d_##type##_are_equal(a.size,  b.size );			\
	}									\
										\
										\
Q_BOX_EXPORT									\
qboolean q_##type##_box_contains(Q##Type##Box a, Q##Type##Box b)		\
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
Q_BOX_EXPORT									\
qboolean q_##type##_box_collision(Q##Type##Box a, Q##Type##Box b)		\
	{									\
	return !(a.point.x > b.point.x + b.size.x  ||				\
		 a.point.x + a.size.x  < b.point.x ||				\
		 a.point.y > b.point.y + b.size.y  ||				\
		 a.point.y + a.size.y  < b.point.y ||				\
		 a.point.z > b.point.z + b.size.z  ||				\
		 a.point.z + a.size.z  < b.point.z);				\
	}									\
										\
										\
/*Q_BOX_EXPORT									\
Q##Type##Box q_##type##_box_intersection(Q##Type##Box a, Q##Type##Box b)	\									\
	{									\
	q##type x1 = q_##type##_maximum(a.point.x, b.point.x),			\
		x2 = q_##type##_minimum						\
			(a.point.x + a.size.x, b.point.x + b.size.x);		\
										\
	if (x1 <= x2)								\
		{								\
		q##type y1 = q_##type##_maximum(a.point.y, b.point.y),		\
										\
			y2 = q_##type##_minimum					\
				(a.point.y + a.size.y, b.point.y + b.size.y);	\
										\
		if (y1 <= y2)							\
			return q_##type##_box(x1, y1, x2 - x1, y2 - y1);	\
		}								\
										\
	return q_##type##_box_zero;						\
	}*/									\
										\
										\
Q_BOX_EXPORT									\
Q##Type##Box q_##type##_box_union(Q##Type##Box a, Q##Type##Box b)		\
	{									\
	Q##Type##Box box;							\
										\
	box.point = q_3d_##type##_minimum(a.point, b.point);			\
										\
	box.size.x =								\
		q_##type##_maximum						\
			(a.point.x + a.size.x, b.point.x + b.size.x)		\
		- box.point.x;							\
										\
	box.size.y =								\
		q_##type##_maximum						\
			(a.point.y + a.size.y, b.point.y + b.size.y)		\
		- box.point.y;							\
										\
	box.size.z =								\
		q_##type##_maximum						\
			(a.point.z + a.size.z, b.point.z + b.size.z)		\
		- box.point.z;							\
										\
	return box;								\
	}									\
										\
										\
Q_BOX_EXPORT									\
Q##Type##Box q_##type##_box_by_vertices(Q3D##Type a, Q3D##Type b)		\
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
Q_BOX_EXPORT									\
Q3D##Type q_##type##_box_center(Q##Type##Box box)				\
	{									\
	return q_3d_##type							\
		(box.point.x + box.size.x / _(2.0),				\
		 box.point.y + box.size.y / _(2.0),				\
		 box.point.z + box.size.z / _(2.0));				\
	}									\
										\
										\
Q_BOX_EXPORT									\
qboolean q_##type##_box_contains_point(						\
	Q##Type##Box	box,							\
	Q3D##Type	point							\
)										\
	{									\
	return	point.x >= box.point.x		    &&				\
		point.y >= box.point.y		    &&				\
		point.z >= box.point.z		    &&				\
		point.x <  box.point.x + box.size.x &&				\
		point.y <  box.point.y + box.size.y &&				\
		point.z <  box.point.z + box.size.z;				\
	}									\
										\
										\
Q_BOX_EXPORT									\
qboolean q_##type##_box_contains_line_segment(					\
	Q##Type##Box	box,							\
	Q3D##Type##Line	line_segment						\
)										\
	{									\
	return	q_##type##_box_contains_point(box, line_segment.a) &&		\
		q_##type##_box_contains_point(box, line_segment.b);		\
	}


Q_IMPLEMENTATION_BOX(Float,   float,   Q_FLOAT	)
Q_IMPLEMENTATION_BOX(Double,  double,  Q_DOUBLE	)
Q_IMPLEMENTATION_BOX(LDouble, ldouble, Q_LDOUBLE)
#undef Q_BOX_NEW


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_box				q_float_box
#	define q_box_zero			q_float_box_zero
#	define q_box_are_equal			q_float_box_are_equal
#	define q_box_contains			q_float_box_contains
#	define q_box_collision			q_float_box_collision
#	define q_box_intersection		q_float_box_intersection
#	define q_box_union			q_float_box_union
#	define q_box_center			q_float_box_center
#	define q_box_contains_point		q_float_box_contains_point
#	define q_box_contains_line_segment	q_float_box_contains_line_segment

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_box				q_ldouble_box
#	define q_box_zero			q_ldouble_box_zero
#	define q_box_are_equal			q_ldouble_box_are_equal
#	define q_box_contains			q_ldouble_box_contains
#	define q_box_collision			q_ldouble_box_collision
#	define q_box_intersection		q_ldouble_box_intersection
#	define q_box_union			q_ldouble_box_union
#	define q_box_center			q_ldouble_box_center
#	define q_box_contains_point		q_ldouble_box_contains_point
#	define q_box_contains_line_segment	q_ldouble_box_contains_line_segment

#else

#	define q_box				q_double_box
#	define q_box_zero			q_double_box_zero
#	define q_box_are_equal			q_double_box_are_equal
#	define q_box_contains			q_double_box_contains
#	define q_box_collision			q_double_box_collision
#	define q_box_intersection		q_double_box_intersection
#	define q_box_union			q_double_box_union
#	define q_box_center			q_double_box_center
#	define q_box_contains_point		q_double_box_contains_point
#	define q_box_contains_line_segment	q_double_box_contains_line_segment

#endif

#endif /* __Q_functions_geometry_QBox_H__ */
