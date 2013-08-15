/* Q API - functions/geometry/QRectangle.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_QRectangle_H__
#define __Q_functions_geometry_QRectangle_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/Q2D.h>

#ifndef Q_RECTANGLE_EXPORT
#	define Q_RECTANGLE_EXPORT Q_INLINE
#endif


#define Q_IMPLEMENTATION_RECTANGLE(Type, type, _)				\
										\
										\
Q_RECTANGLE_EXPORT								\
qboolean q_##type##_rectangle_are_equal(					\
	Q##Type##Rectangle a,							\
	Q##Type##Rectangle b							\
)										\
	{									\
	return	q_2d_##type##_are_equal(a.point, b.point) &&			\
		q_2d_##type##_are_equal(a.size,  b.size );			\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
qboolean q_##type##_rectangle_contains(						\
	Q##Type##Rectangle a,							\
	Q##Type##Rectangle b							\
)										\
	{									\
	return	b.point.x	     >= a.point.x	     &&			\
		b.point.y	     >= a.point.y	     &&			\
		b.point.x + b.size.x <= a.point.x + a.size.x &&			\
		b.point.y + b.size.y <= a.point.y + a.size.y;			\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
qboolean q_##type##_rectangle_collision(					\
	Q##Type##Rectangle a,							\
	Q##Type##Rectangle b							\
)										\
	{									\
	return !(a.point.x > b.point.x + b.size.x  ||				\
		 a.point.x + a.size.x  < b.point.x ||				\
		 a.point.y > b.point.y + b.size.y  ||				\
		 a.point.y + a.size.y  < b.point.y);				\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_intersection(				\
	Q##Type##Rectangle a,							\
	Q##Type##Rectangle b							\
)										\
	{									\
	q##type x1, x2, y1, y2;							\
										\
	return	(x1 = q_##type##_maximum(a.point.x, b.point.x))	      <=	\
		(x2 = q_##type##_minimum					\
			(a.point.x + a.size.x, b.point.x + b.size.x)) &&	\
		(y1 = q_##type##_maximum(a.point.y, b.point.y))	      <=	\
		(y2 = q_##type##_minimum					\
			(a.point.y + a.size.y, b.point.y + b.size.y))		\
										\
		? q_##type##_rectangle(x1, y1, x2 - x1, y2 - y1)		\
		: q_##type##_rectangle_zero;					\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_union(					\
	Q##Type##Rectangle a,							\
	Q##Type##Rectangle b							\
)										\
	{									\
	Q##Type##Rectangle rectangle;						\
										\
	rectangle.point = q_2d_##type##_minimum(a.point, b.point);		\
										\
	rectangle.size.x =							\
	q_##type##_maximum(a.point.x + a.size.x, b.point.x + b.size.x) -	\
	rectangle.point.x;							\
										\
	rectangle.size.y =							\
	q_##type##_maximum(a.point.y + a.size.y, b.point.y + b.size.y) -	\
	rectangle.point.y;							\
										\
	return rectangle;							\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_by_vertices(Q2D##Type a, Q2D##Type b)	\
	{									\
	Q2D##Type minimum = q_2d_##type##_minimum(a, b);			\
	Q2D##Type maximum = q_2d_##type##_maximum(a, b);			\
										\
	return q_##type##_rectangle						\
		(minimum.x,  minimum.y,						\
		 maximum.x - minimum.x, maximum.y - minimum.y);			\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
qboolean q_##type##_rectangle_is_zero(Q##Type##Rectangle rectangle)		\
	{									\
	return	q_2d_##type##_is_zero(rectangle.point) &&			\
		q_2d_##type##_is_zero(rectangle.size);				\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
q##type q_##type##_rectangle_minimum_x(Q##Type##Rectangle rectangle)		\
	{return rectangle.point.x;}						\
										\
										\
Q_RECTANGLE_EXPORT								\
q##type q_##type##_rectangle_minimum_y(Q##Type##Rectangle rectangle)		\
	{return rectangle.point.y;}						\
										\
										\
Q_RECTANGLE_EXPORT								\
q##type q_##type##_rectangle_maximum_x(Q##Type##Rectangle rectangle)		\
	{return rectangle.point.x + rectangle.size.x;}				\
										\
										\
Q_RECTANGLE_EXPORT								\
q##type q_##type##_rectangle_maximum_y(Q##Type##Rectangle rectangle)		\
	{return rectangle.point.y + rectangle.size.y;}				\
										\
										\
Q_RECTANGLE_EXPORT								\
q##type q_##type##_rectangle_middle_x(Q##Type##Rectangle rectangle)		\
	{return rectangle.point.x + rectangle.size.x / _(2.0);}			\
										\
										\
Q_RECTANGLE_EXPORT								\
q##type q_##type##_rectangle_middle_y(Q##Type##Rectangle rectangle)		\
	{return rectangle.point.y + rectangle.size.y / _(2.0);}			\
										\
										\
Q_RECTANGLE_EXPORT								\
Q2D##Type q_##type##_rectangle_top_left(Q##Type##Rectangle rectangle)		\
	{									\
	return q_2d_##type							\
		(rectangle.point.x,						\
		 rectangle.point.y + rectangle.size.y);				\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q2D##Type q_##type##_rectangle_top_right(Q##Type##Rectangle rectangle)		\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x,				\
		 rectangle.point.y + rectangle.size.y);				\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q2D##Type q_##type##_rectangle_top_center(Q##Type##Rectangle rectangle)		\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x / _(2.0),			\
		 rectangle.point.y + rectangle.size.y);				\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q2D##Type q_##type##_rectangle_bottom_left(Q##Type##Rectangle rectangle)	\
	{return rectangle.point;}						\
										\
										\
Q_RECTANGLE_EXPORT								\
Q2D##Type q_##type##_rectangle_bottom_right(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x,				\
		 rectangle.point.y);						\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q2D##Type q_##type##_rectangle_bottom_center(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x / _(2.0),			\
		 rectangle.point.y);						\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q2D##Type q_##type##_rectangle_center_left(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x,						\
		 rectangle.point.y + rectangle.size.y / _(2.0));		\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q2D##Type q_##type##_rectangle_center_right(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x,				\
		 rectangle.point.y + rectangle.size.y / _(2.0));		\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q2D##Type q_##type##_rectangle_center(Q##Type##Rectangle rectangle)		\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x / _(2.0),			\
		 rectangle.point.y + rectangle.size.y / _(2.0));		\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_top_half(				\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.point.y += (rectangle.size.y /= _(2.0));			\
	return rectangle;							\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_bottom_half(				\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.size.y /= _(2.0);						\
	return rectangle;							\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_left_half(				\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.size.x /= _(2.0);						\
	return rectangle;							\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_right_half(				\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.point.x += (rectangle.size.x /= _(2.0));			\
	return rectangle;							\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_top_left_quarter(			\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.size.x  /= _(2.0);						\
	rectangle.point.y += (rectangle.size.y /= _(2.0));			\
	return rectangle;							\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_top_right_quarter(			\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.point.x += (rectangle.size.x /= _(2.0));			\
	rectangle.point.y += (rectangle.size.y /= _(2.0));			\
	return rectangle;							\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_bottom_left_quarter(			\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.size.x /= _(2.0);						\
	rectangle.size.y /= _(2.0);						\
	return rectangle;							\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
Q##Type##Rectangle q_##type##_rectangle_bottom_right_quarter(			\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.point.x += (rectangle.size.x /= _(2.0));			\
	rectangle.size.y  /= _(2.0);						\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
qboolean q_##type##_rectangle_contains_point(					\
	Q##Type##Rectangle	rectangle,					\
	Q2D##Type		point						\
)										\
	{									\
	return	point.x >= rectangle.point.x			&&		\
		point.y >= rectangle.point.y			&&		\
		point.x <  rectangle.point.x + rectangle.size.x	&&		\
		point.y <  rectangle.point.y + rectangle.size.y;		\
	}									\
										\
										\
Q_RECTANGLE_EXPORT								\
qboolean q_##type##_rectangle_contains_line_segment(				\
	Q##Type##Rectangle	rectangle,					\
	Q2D##Type##Line		line_segment					\
)										\
	{									\
	return	q_##type##_rectangle_contains_point(rectangle, line_segment.a)	\
	    &&	q_##type##_rectangle_contains_point(rectangle, line_segment.b);	\
	}


Q_IMPLEMENTATION_RECTANGLE(Float,   float,   Q_FLOAT  )
Q_IMPLEMENTATION_RECTANGLE(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_RECTANGLE(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_rectangle_are_equal			q_float_rectangle_are_equal
#	define q_rectangle_contains			q_float_rectangle_contains
#	define q_rectangle_collision			q_float_rectangle_collision
#	define q_rectangle_intersection			q_float_rectangle_intersection
#	define q_rectangle_union			q_float_rectangle_union
#	define q_rectangle_by_vertices			q_float_rectangle_by_vertices
#	define q_rectangle_is_zero			q_float_rectangle_is_zero
#	define q_rectangle_minimum_x			q_float_rectangle_minimum_x
#	define q_rectangle_minimum_y			q_float_rectangle_minimum_y
#	define q_rectangle_maximum_x			q_float_rectangle_maximum_x
#	define q_rectangle_maximum_y			q_float_rectangle_maximum_y
#	define q_rectangle_middle_x			q_float_rectangle_middle_x
#	define q_rectangle_middle_y			q_float_rectangle_middle_y
#	define q_rectangle_top_left			q_float_rectangle_top_left
#	define q_rectangle_top_right			q_float_rectangle_top_right
#	define q_rectangle_top_center			q_float_rectangle_top_center
#	define q_rectangle_bottom_left			q_float_rectangle_bottom_left
#	define q_rectangle_bottom_right			q_float_rectangle_bottom_right
#	define q_rectangle_bottom_center		q_float_rectangle_bottom_center
#	define q_rectangle_center_left			q_float_rectangle_center_left
#	define q_rectangle_center_right			q_float_rectangle_center_right
#	define q_rectangle_center			q_float_rectangle_center
#	define q_rectangle_top_half			q_float_rectangle_top_half
#	define q_rectangle_bottom_half			q_float_rectangle_bottom_half
#	define q_rectangle_left_half			q_float_rectangle_left_half
#	define q_rectangle_right_half			q_float_rectangle_right_half
#	define q_rectangle_top_left_quarter		q_float_rectangle_top_left_quarter
#	define q_rectangle_top_right_quarter		q_float_rectangle_top_right_quarter
#	define q_rectangle_bottom_left_quarter		q_float_rectangle_bottom_left_quarter
#	define q_rectangle_bottom_right_quarter		q_float_rectangle_bottom_right_quarter
#	define q_rectangle_contains_point		q_float_rectangle_contains_point
#	define q_rectangle_contains_line_segment	q_float_rectangle_contains_line_segment

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_rectangle_are_equal			q_ldouble_rectangle_are_equal
#	define q_rectangle_contains			q_ldouble_rectangle_contains
#	define q_rectangle_collision			q_ldouble_rectangle_collision
#	define q_rectangle_intersection			q_ldouble_rectangle_intersection
#	define q_rectangle_union			q_ldouble_rectangle_union
#	define q_rectangle_by_vertices			q_ldouble_rectangle_by_vertices
#	define q_rectangle_is_zero			q_ldouble_rectangle_is_zero
#	define q_rectangle_minimum_x			q_ldouble_rectangle_minimum_x
#	define q_rectangle_minimum_y			q_ldouble_rectangle_minimum_y
#	define q_rectangle_maximum_x			q_ldouble_rectangle_maximum_x
#	define q_rectangle_maximum_y			q_ldouble_rectangle_maximum_y
#	define q_rectangle_middle_x			q_ldouble_rectangle_middle_x
#	define q_rectangle_middle_y			q_ldouble_rectangle_middle_y
#	define q_rectangle_top_left			q_ldouble_rectangle_top_left
#	define q_rectangle_top_right			q_ldouble_rectangle_top_right
#	define q_rectangle_top_center			q_ldouble_rectangle_top_center
#	define q_rectangle_bottom_left			q_ldouble_rectangle_bottom_left
#	define q_rectangle_bottom_right			q_ldouble_rectangle_bottom_right
#	define q_rectangle_bottom_center		q_ldouble_rectangle_bottom_center
#	define q_rectangle_center_left			q_ldouble_rectangle_center_left
#	define q_rectangle_center_right			q_ldouble_rectangle_center_right
#	define q_rectangle_center			q_ldouble_rectangle_center
#	define q_rectangle_top_half			q_ldouble_rectangle_top_half
#	define q_rectangle_bottom_half			q_ldouble_rectangle_bottom_half
#	define q_rectangle_left_half			q_ldouble_rectangle_left_half
#	define q_rectangle_right_half			q_ldouble_rectangle_right_half
#	define q_rectangle_top_left_quarter		q_ldouble_rectangle_top_left_quarter
#	define q_rectangle_top_right_quarter		q_ldouble_rectangle_top_right_quarter
#	define q_rectangle_bottom_left_quarter		q_ldouble_rectangle_bottom_left_quarter
#	define q_rectangle_bottom_right_quarter		q_ldouble_rectangle_bottom_right_quarter
#	define q_rectangle_contains_point		q_ldouble_rectangle_contains_point
#	define q_rectangle_contains_line_segment	q_ldouble_rectangle_contains_line_segment

#else

#	define q_rectangle_are_equal			q_double_rectangle_are_equal
#	define q_rectangle_contains			q_double_rectangle_contains
#	define q_rectangle_collision			q_double_rectangle_collision
#	define q_rectangle_intersection			q_double_rectangle_intersection
#	define q_rectangle_union			q_double_rectangle_union
#	define q_rectangle_by_vertices			q_double_rectangle_by_vertices
#	define q_rectangle_is_zero			q_double_rectangle_is_zero
#	define q_rectangle_minimum_x			q_double_rectangle_minimum_x
#	define q_rectangle_minimum_y			q_double_rectangle_minimum_y
#	define q_rectangle_maximum_x			q_double_rectangle_maximum_x
#	define q_rectangle_maximum_y			q_double_rectangle_maximum_y
#	define q_rectangle_middle_x			q_double_rectangle_middle_x
#	define q_rectangle_middle_y			q_double_rectangle_middle_y
#	define q_rectangle_top_left			q_double_rectangle_top_left
#	define q_rectangle_top_right			q_double_rectangle_top_right
#	define q_rectangle_top_center			q_double_rectangle_top_center
#	define q_rectangle_bottom_left			q_double_rectangle_bottom_left
#	define q_rectangle_bottom_right			q_double_rectangle_bottom_right
#	define q_rectangle_bottom_center		q_double_rectangle_bottom_center
#	define q_rectangle_center_left			q_double_rectangle_center_left
#	define q_rectangle_center_right			q_double_rectangle_center_right
#	define q_rectangle_center			q_double_rectangle_center
#	define q_rectangle_top_half			q_double_rectangle_top_half
#	define q_rectangle_bottom_half			q_double_rectangle_bottom_half
#	define q_rectangle_left_half			q_double_rectangle_left_half
#	define q_rectangle_right_half			q_double_rectangle_right_half
#	define q_rectangle_top_left_quarter		q_double_rectangle_top_left_quarter
#	define q_rectangle_top_right_quarter		q_double_rectangle_top_right_quarter
#	define q_rectangle_bottom_left_quarter		q_double_rectangle_bottom_left_quarter
#	define q_rectangle_bottom_right_quarter		q_double_rectangle_bottom_right_quarter
#	define q_rectangle_contains_point		q_double_rectangle_contains_point
#	define q_rectangle_contains_line_segment	q_double_rectangle_contains_line_segment

#endif

#endif /* __Q_functions_geometry_QRectangle_H__ */
