/* Q API - functions/geometry/QRectangle.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_QRectangle_H__
#define __Q_functions_geometry_QRectangle_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/base/Q2D.h>


#define Q_IMPLEMENTATION_RECTANGLE(Type, type, _)				\
										\
										\
Q_INLINE qboolean q_##type##_rectangle_are_equal(				\
	Q##Type##Rectangle a,							\
	Q##Type##Rectangle b							\
)										\
	{									\
	return	q_2d_##type##_are_equal(a.point, b.point) &&			\
		q_2d_##type##_are_equal(a.size,  b.size );			\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_rectangle_contains(				\
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
Q_INLINE qboolean q_##type##_rectangle_collide(					\
	Q##Type##Rectangle a,							\
	Q##Type##Rectangle b							\
)										\
	{									\
	return	a.point.x < b.point.x + b.size.x &&				\
		b.point.x < a.point.x + a.size.x &&				\
		a.point.y < b.point.y + b.size.y &&				\
		b.point.y < a.point.y + a.size.y;				\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_intersection(			\
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
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_union(				\
	Q##Type##Rectangle a,							\
	Q##Type##Rectangle b							\
)										\
	{									\
	Q##Type##Rectangle result;						\
										\
	result.point = q_2d_##type##_minimum(a.point, b.point);			\
										\
	result.size.x =								\
	q_##type##_maximum(a.point.x + a.size.x, b.point.x + b.size.x) -	\
	result.point.x;								\
										\
	result.size.y =								\
	q_##type##_maximum(a.point.y + a.size.y, b.point.y + b.size.y) -	\
	result.point.y;								\
										\
	return result;								\
	}									\
										\
										\
Q_INLINE									\
Q##Type##Rectangle q_##type##_rectangle_from_vertices(Q2D##Type a, Q2D##Type b)	\
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
Q_INLINE qboolean q_##type##_rectangle_is_zero(Q##Type##Rectangle rectangle)	\
	{									\
	return	q_2d_##type##_is_zero(rectangle.point) &&			\
		q_2d_##type##_is_zero(rectangle.size);				\
	}									\
										\
										\
Q_INLINE q##type q_##type##_rectangle_minimum_x(Q##Type##Rectangle rectangle)	\
	{return rectangle.point.x;}						\
										\
										\
Q_INLINE q##type q_##type##_rectangle_minimum_y(Q##Type##Rectangle rectangle)	\
	{return rectangle.point.y;}						\
										\
										\
Q_INLINE q##type q_##type##_rectangle_maximum_x(Q##Type##Rectangle rectangle)	\
	{return rectangle.point.x + rectangle.size.x;}				\
										\
										\
Q_INLINE q##type q_##type##_rectangle_maximum_y(Q##Type##Rectangle rectangle)	\
	{return rectangle.point.y + rectangle.size.y;}				\
										\
										\
Q_INLINE q##type q_##type##_rectangle_middle_x(Q##Type##Rectangle rectangle)	\
	{return rectangle.point.x + rectangle.size.x / _(2.0);}			\
										\
										\
Q_INLINE q##type q_##type##_rectangle_middle_y(Q##Type##Rectangle rectangle)	\
	{return rectangle.point.y + rectangle.size.y / _(2.0);}			\
										\
										\
Q_INLINE Q2D##Type q_##type##_rectangle_top_left(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x,						\
		 rectangle.point.y + rectangle.size.y);				\
	}									\
										\
										\
Q_INLINE Q2D##Type q_##type##_rectangle_top_right(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x,				\
		 rectangle.point.y + rectangle.size.y);				\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_##type##_rectangle_top_center(Q##Type##Rectangle rectangle)		\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x / _(2.0),			\
		 rectangle.point.y + rectangle.size.y);				\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_##type##_rectangle_bottom_left(Q##Type##Rectangle rectangle)	\
	{return rectangle.point;}						\
										\
										\
Q_INLINE									\
Q2D##Type q_##type##_rectangle_bottom_right(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x,				\
		 rectangle.point.y);						\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_##type##_rectangle_bottom_center(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x / _(2.0),			\
		 rectangle.point.y);						\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_##type##_rectangle_center_left(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x,						\
		 rectangle.point.y + rectangle.size.y / _(2.0));		\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type q_##type##_rectangle_center_right(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x,				\
		 rectangle.point.y + rectangle.size.y / _(2.0));		\
	}									\
										\
										\
Q_INLINE Q2D##Type q_##type##_rectangle_center(Q##Type##Rectangle rectangle)	\
	{									\
	return q_2d_##type							\
		(rectangle.point.x + rectangle.size.x / _(2.0),			\
		 rectangle.point.y + rectangle.size.y / _(2.0));		\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_correct(			\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	if (rectangle.size.x < _(0.0))						\
		rectangle.point.x -= (rectangle.size.x = -rectangle.size.x);	\
										\
	if (rectangle.size.y < _(0.0))						\
		rectangle.point.y -= (rectangle.size.y = -rectangle.size.y);	\
										\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_top_half(			\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.point.y += (rectangle.size.y /= _(2.0));			\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_bottom_half(			\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.size.y /= _(2.0);						\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_left_half(			\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.size.x /= _(2.0);						\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_right_half(			\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.point.x += (rectangle.size.x /= _(2.0));			\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_top_left_quarter(		\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.size.x  /= _(2.0);						\
	rectangle.point.y += (rectangle.size.y /= _(2.0));			\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_top_right_quarter(		\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.point.x += (rectangle.size.x /= _(2.0));			\
	rectangle.point.y += (rectangle.size.y /= _(2.0));			\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_bottom_left_quarter(		\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.size.x /= _(2.0);						\
	rectangle.size.y /= _(2.0);						\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_bottom_right_quarter(		\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	rectangle.point.x += (rectangle.size.x /= _(2.0));			\
	rectangle.size.y  /= _(2.0);						\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_align_in_top_left(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	rectangle.point.y += rectangle.size.y - size.y;				\
	rectangle.size = size;							\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_align_in_top_right(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	rectangle.point.x += rectangle.size.x - size.x;				\
	rectangle.point.y += rectangle.size.y - size.y;				\
	rectangle.size = size;							\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_align_in_top_center(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	rectangle.point.x += (rectangle.size.x - size.x) / _(2.0);		\
	rectangle.point.y +=  rectangle.size.y - size.y;			\
	rectangle.size = size;							\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_align_in_bottom_left(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	rectangle.size = size;							\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_align_in_bottom_right(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	rectangle.point.x += rectangle.size.x - size.x;				\
	rectangle.size = size;							\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_align_in_bottom_center(	\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	rectangle.point.x += (rectangle.size.x - size.x) / _(2.0);		\
	rectangle.size = size;							\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_align_in_center_left(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	rectangle.point.y += (rectangle.size.y - size.y) / _(2.0);		\
	rectangle.size = size;							\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_align_in_center_right(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	rectangle.point.x +=  rectangle.size.x - size.x;			\
	rectangle.point.y += (rectangle.size.y - size.y) / _(2.0);		\
	rectangle.size = size;							\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_align_in_center(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	rectangle.point.x += (rectangle.size.x - size.x) / _(2.0);		\
	rectangle.point.y += (rectangle.size.y - size.y) / _(2.0);		\
	rectangle.size = size;							\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_fit_in_top_left(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	Q##Type##Rectangle result;						\
										\
	result.size = q_2d_##type##_fit(size, rectangle.size);			\
	result.point.x = rectangle.point.x;					\
	result.point.y = rectangle.point.y + rectangle.size.y - result.size.y;	\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_fit_in_top_right(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	Q##Type##Rectangle result;						\
										\
	result.size = q_2d_##type##_fit(size, rectangle.size);			\
	result.point.x = rectangle.point.x + rectangle.size.x - result.size.x;	\
	result.point.y = rectangle.point.y + rectangle.size.y - result.size.y;	\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_fit_in_top_center(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	Q##Type##Rectangle result;						\
										\
	result.size = q_2d_##type##_fit(size, rectangle.size);			\
										\
	result.point.x =							\
		rectangle.point.x +						\
		(rectangle.size.x - result.size.x) / _(2.0);			\
										\
	result.point.y = rectangle.point.y + rectangle.size.y - result.size.y;	\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_fit_in_bottom_left(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	rectangle.size = q_2d_##type##_fit(size, rectangle.size);		\
	return rectangle;							\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_fit_in_bottom_right(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	Q##Type##Rectangle result;						\
										\
	result.size = q_2d_##type##_fit(size, rectangle.size);			\
	result.point.x = rectangle.point.x + rectangle.size.x - result.size.x;	\
	result.point.y = rectangle.point.y;					\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_fit_in_bottom_center(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	Q##Type##Rectangle result;						\
										\
	result.size = q_2d_##type##_fit(size, rectangle.size);			\
										\
	result.point.x =							\
		rectangle.point.x +						\
		(rectangle.size.x - result.size.x) / _(2.0);			\
										\
	result.point.y = rectangle.point.y;					\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_fit_in_center_left(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	Q##Type##Rectangle result;						\
										\
	result.size = q_2d_##type##_fit(size, rectangle.size);			\
	result.point.x = rectangle.point.x;					\
										\
	result.point.y =							\
		rectangle.point.y +						\
		(rectangle.size.y - result.size.y) / _(2.0);			\
										\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_fit_in_center_right(		\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	Q##Type##Rectangle result;						\
										\
	result.size = q_2d_##type##_fit(size, rectangle.size);			\
	result.point.x = rectangle.point.x + rectangle.size.x - result.size.x;	\
										\
	result.point.y =							\
		rectangle.point.y +						\
		(rectangle.size.y - result.size.y) / _(2.0);			\
										\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_rectangle_fit_in_center(			\
	Q##Type##Rectangle rectangle,						\
	Q##2D##Type	   size							\
)										\
	{									\
	Q##Type##Rectangle result;						\
										\
	result.size = q_2d_##type##_fit(size, rectangle.size);			\
										\
	result.point.x =							\
		rectangle.point.x +						\
		(rectangle.size.x - result.size.x) / _(2.0);			\
										\
	result.point.y =							\
		rectangle.point.y +						\
		(rectangle.size.y - result.size.y) / _(2.0);			\
										\
	return result;								\
	}									\
										\
										\
Q_INLINE									\
Q##Type##Circle q_##type##_rectangle_inner_circle(Q##Type##Rectangle rectangle)	\
	{									\
	Q##Type##Circle result;							\
										\
	result.point = q_##type##_rectangle_center(rectangle);			\
										\
	result.radius =								\
	q_##type##_minimum(rectangle.size.x, rectangle.size.y) / _(2.0);	\
										\
	return result;								\
	}									\
										\
										\
Q_INLINE									\
Q##Type##AABR q_##type##_rectangle_to_aabr(Q##Type##Rectangle rectangle)	\
	{									\
	return q_##type##_aabr							\
		(rectangle.point.x,  rectangle.point.y,				\
		 rectangle.point.x + rectangle.size.x,				\
		 rectangle.point.y + rectangle.size.y);				\
	}									\
										\
										\
Q_INLINE Q2D##Type q_##type##_rectangle_absolute_point_to_unit(			\
	Q##Type##Rectangle rectangle,						\
	Q2D##Type	   point						\
										\
)										\
	{									\
	return q_2d_##type							\
		((point.x - rectangle.point.x) / rectangle.size.x,		\
		 (point.y - rectangle.point.y) / rectangle.size.y);		\
	}									\
										\
										\
Q_INLINE Q2D##Type q_##type##_rectangle_unit_point_to_absolute(			\
	Q##Type##Rectangle rectangle,						\
	Q2D##Type	   point						\
										\
)										\
	{									\
	return q_2d_##type							\
		(point.x * rectangle.size.x + rectangle.point.x,		\
		 point.y * rectangle.size.y + rectangle.point.y);		\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_rectangle_contains_point(				\
	Q##Type##Rectangle rectangle,						\
	Q2D##Type	   point						\
)										\
	{									\
	return	point.x >= rectangle.point.x			&&		\
		point.y >= rectangle.point.y			&&		\
		point.x <= rectangle.point.x + rectangle.size.x	&&		\
		point.y <= rectangle.point.y + rectangle.size.y;		\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_rectangle_contains_line_segment(			\
	Q##Type##Rectangle rectangle,						\
	Q2D##Type##Line	   line_segment						\
)										\
	{									\
	return	q_##type##_rectangle_contains_point(rectangle, line_segment.a)	\
	    &&	q_##type##_rectangle_contains_point(rectangle, line_segment.b);	\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_rectangle_contains_aabr(				\
	Q##Type##Rectangle rectangle,						\
	Q##Type##AABR	   aabr							\
)										\
	{									\
	return	aabr.a.x >= rectangle.point.x			 &&		\
		aabr.a.y >= rectangle.point.y			 &&		\
		aabr.b.x <= rectangle.point.x + rectangle.size.x &&		\
		aabr.b.y <= rectangle.point.y + rectangle.size.y;		\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_rectangle_contains_circle(				\
	Q##Type##Rectangle rectangle,						\
	Q##Type##Circle	   circle						\
)										\
	{									\
	return	circle.point.x - circle.radius >= rectangle.point.x &&		\
		circle.point.y - circle.radius >= rectangle.point.y &&		\
		circle.point.x + circle.radius <=				\
		rectangle.point.x + rectangle.size.x		    &&		\
		circle.point.y + circle.radius <=				\
		rectangle.point.y + rectangle.size.y;				\
	}


Q_IMPLEMENTATION_RECTANGLE(Float,   float,   Q_FLOAT  )
Q_IMPLEMENTATION_RECTANGLE(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_RECTANGLE(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_rectangle_are_equal			q_float_rectangle_are_equal
#	define q_rectangle_contains			q_float_rectangle_contains
#	define q_rectangle_collide			q_float_rectangle_collide
#	define q_rectangle_intersection			q_float_rectangle_intersection
#	define q_rectangle_union			q_float_rectangle_union
#	define q_rectangle_from_vertices		q_float_rectangle_from_vertices
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
#	define q_rectangle_correct			q_float_rectangle_correct
#	define q_rectangle_top_half			q_float_rectangle_top_half
#	define q_rectangle_bottom_half			q_float_rectangle_bottom_half
#	define q_rectangle_left_half			q_float_rectangle_left_half
#	define q_rectangle_right_half			q_float_rectangle_right_half
#	define q_rectangle_top_left_quarter		q_float_rectangle_top_left_quarter
#	define q_rectangle_top_right_quarter		q_float_rectangle_top_right_quarter
#	define q_rectangle_bottom_left_quarter		q_float_rectangle_bottom_left_quarter
#	define q_rectangle_bottom_right_quarter		q_float_rectangle_bottom_right_quarter
#	define q_rectangle_align_in_top_left		q_float_rectangle_align_in_top_left
#	define q_rectangle_align_in_top_right		q_float_rectangle_align_in_top_right
#	define q_rectangle_align_in_top_center		q_float_rectangle_align_in_top_center
#	define q_rectangle_align_in_bottom_left		q_float_rectangle_align_in_bottom_left
#	define q_rectangle_align_in_bottom_right	q_float_rectangle_align_in_bottom_right
#	define q_rectangle_align_in_bottom_center	q_float_rectangle_align_in_bottom_center
#	define q_rectangle_align_in_center_left		q_float_rectangle_align_in_center_left
#	define q_rectangle_align_in_center_right	q_float_rectangle_align_in_center_right
#	define q_rectangle_align_in_center		q_float_rectangle_align_in_center
#	define q_rectangle_fit_in_top_left		q_float_rectangle_fit_in_top_left
#	define q_rectangle_fit_in_top_right		q_float_rectangle_fit_in_top_right
#	define q_rectangle_fit_in_top_center		q_float_rectangle_fit_in_top_center
#	define q_rectangle_fit_in_bottom_left		q_float_rectangle_fit_in_bottom_left
#	define q_rectangle_fit_in_bottom_right		q_float_rectangle_fit_in_bottom_right
#	define q_rectangle_fit_in_bottom_center		q_float_rectangle_fit_in_bottom_center
#	define q_rectangle_fit_in_center_left		q_float_rectangle_fit_in_center_left
#	define q_rectangle_fit_in_center_right		q_float_rectangle_fit_in_center_right
#	define q_rectangle_fit_in_center		q_float_rectangle_fit_in_center
#	define q_rectangle_inner_circle			q_float_rectangle_inner_circle
#	define q_rectangle_to_aabr			q_float_rectangle_to_aabr
#	define q_rectangle_absolute_point_to_unit	q_float_rectangle_absolute_point_to_unit
#	define q_rectangle_unit_point_to_absolute	q_float_rectangle_unit_point_to_absolute
#	define q_rectangle_contains_point		q_float_rectangle_contains_point
#	define q_rectangle_contains_line_segment	q_float_rectangle_contains_line_segment
#	define q_rectangle_contains_aabr		q_float_rectangle_contains_aabr
#	define q_rectangle_contains_circle		q_float_rectangle_contains_circle

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_rectangle_are_equal			q_ldouble_rectangle_are_equal
#	define q_rectangle_contains			q_ldouble_rectangle_contains
#	define q_rectangle_collide			q_ldouble_rectangle_collide
#	define q_rectangle_intersection			q_ldouble_rectangle_intersection
#	define q_rectangle_union			q_ldouble_rectangle_union
#	define q_rectangle_from_vertices		q_ldouble_rectangle_from_vertices
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
#	define q_rectangle_correct			q_ldouble_rectangle_correct
#	define q_rectangle_top_half			q_ldouble_rectangle_top_half
#	define q_rectangle_bottom_half			q_ldouble_rectangle_bottom_half
#	define q_rectangle_left_half			q_ldouble_rectangle_left_half
#	define q_rectangle_right_half			q_ldouble_rectangle_right_half
#	define q_rectangle_top_left_quarter		q_ldouble_rectangle_top_left_quarter
#	define q_rectangle_top_right_quarter		q_ldouble_rectangle_top_right_quarter
#	define q_rectangle_bottom_left_quarter		q_ldouble_rectangle_bottom_left_quarter
#	define q_rectangle_bottom_right_quarter		q_ldouble_rectangle_bottom_right_quarter
#	define q_rectangle_align_in_top_left		q_ldouble_rectangle_align_in_top_left
#	define q_rectangle_align_in_top_right		q_ldouble_rectangle_align_in_top_right
#	define q_rectangle_align_in_top_center		q_ldouble_rectangle_align_in_top_center
#	define q_rectangle_align_in_bottom_left		q_ldouble_rectangle_align_in_bottom_left
#	define q_rectangle_align_in_bottom_right	q_ldouble_rectangle_align_in_bottom_right
#	define q_rectangle_align_in_bottom_center	q_ldouble_rectangle_align_in_bottom_center
#	define q_rectangle_align_in_center_left		q_ldouble_rectangle_align_in_center_left
#	define q_rectangle_align_in_center_right	q_ldouble_rectangle_align_in_center_right
#	define q_rectangle_align_in_center		q_ldouble_rectangle_align_in_center
#	define q_rectangle_fit_in_top_left		q_ldouble_rectangle_fit_in_top_left
#	define q_rectangle_fit_in_top_right		q_ldouble_rectangle_fit_in_top_right
#	define q_rectangle_fit_in_top_center		q_ldouble_rectangle_fit_in_top_center
#	define q_rectangle_fit_in_bottom_left		q_ldouble_rectangle_fit_in_bottom_left
#	define q_rectangle_fit_in_bottom_right		q_ldouble_rectangle_fit_in_bottom_right
#	define q_rectangle_fit_in_bottom_center		q_ldouble_rectangle_fit_in_bottom_center
#	define q_rectangle_fit_in_center_left		q_ldouble_rectangle_fit_in_center_left
#	define q_rectangle_fit_in_center_right		q_ldouble_rectangle_fit_in_center_right
#	define q_rectangle_fit_in_center		q_ldouble_rectangle_fit_in_center
#	define q_rectangle_inner_circle			q_ldouble_rectangle_inner_circle
#	define q_rectangle_to_aabr			q_ldouble_rectangle_to_aabr
#	define q_rectangle_absolute_point_to_unit	q_ldouble_rectangle_absolute_point_to_unit
#	define q_rectangle_unit_point_to_absolute	q_ldouble_rectangle_unit_point_to_absolute
#	define q_rectangle_contains_point		q_ldouble_rectangle_contains_point
#	define q_rectangle_contains_line_segment	q_ldouble_rectangle_contains_line_segment
#	define q_rectangle_contains_aabr		q_ldouble_rectangle_contains_aabr
#	define q_rectangle_contains_circle		q_ldouble_rectangle_contains_circle

#else

#	define q_rectangle_are_equal			q_double_rectangle_are_equal
#	define q_rectangle_contains			q_double_rectangle_contains
#	define q_rectangle_collide			q_double_rectangle_collide
#	define q_rectangle_intersection			q_double_rectangle_intersection
#	define q_rectangle_union			q_double_rectangle_union
#	define q_rectangle_from_vertices		q_double_rectangle_from_vertices
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
#	define q_rectangle_correct			q_double_rectangle_correct
#	define q_rectangle_top_half			q_double_rectangle_top_half
#	define q_rectangle_bottom_half			q_double_rectangle_bottom_half
#	define q_rectangle_left_half			q_double_rectangle_left_half
#	define q_rectangle_right_half			q_double_rectangle_right_half
#	define q_rectangle_top_left_quarter		q_double_rectangle_top_left_quarter
#	define q_rectangle_top_right_quarter		q_double_rectangle_top_right_quarter
#	define q_rectangle_bottom_left_quarter		q_double_rectangle_bottom_left_quarter
#	define q_rectangle_bottom_right_quarter		q_double_rectangle_bottom_right_quarter
#	define q_rectangle_align_in_top_left		q_double_rectangle_align_in_top_left
#	define q_rectangle_align_in_top_right		q_double_rectangle_align_in_top_right
#	define q_rectangle_align_in_top_center		q_double_rectangle_align_in_top_center
#	define q_rectangle_align_in_bottom_left		q_double_rectangle_align_in_bottom_left
#	define q_rectangle_align_in_bottom_right	q_double_rectangle_align_in_bottom_right
#	define q_rectangle_align_in_bottom_center	q_double_rectangle_align_in_bottom_center
#	define q_rectangle_align_in_center_left		q_double_rectangle_align_in_center_left
#	define q_rectangle_align_in_center_right	q_double_rectangle_align_in_center_right
#	define q_rectangle_align_in_center		q_double_rectangle_align_in_center
#	define q_rectangle_fit_in_top_left		q_double_rectangle_fit_in_top_left
#	define q_rectangle_fit_in_top_right		q_double_rectangle_fit_in_top_right
#	define q_rectangle_fit_in_top_center		q_double_rectangle_fit_in_top_center
#	define q_rectangle_fit_in_bottom_left		q_double_rectangle_fit_in_bottom_left
#	define q_rectangle_fit_in_bottom_right		q_double_rectangle_fit_in_bottom_right
#	define q_rectangle_fit_in_bottom_center		q_double_rectangle_fit_in_bottom_center
#	define q_rectangle_fit_in_center_left		q_double_rectangle_fit_in_center_left
#	define q_rectangle_fit_in_center_right		q_double_rectangle_fit_in_center_right
#	define q_rectangle_fit_in_center		q_double_rectangle_fit_in_center
#	define q_rectangle_inner_circle			q_double_rectangle_inner_circle
#	define q_rectangle_to_aabr			q_double_rectangle_to_aabr
#	define q_rectangle_absolute_point_to_unit	q_double_rectangle_absolute_point_to_unit
#	define q_rectangle_unit_point_to_absolute	q_double_rectangle_unit_point_to_absolute
#	define q_rectangle_contains_point		q_double_rectangle_contains_point
#	define q_rectangle_contains_line_segment	q_double_rectangle_contains_line_segment
#	define q_rectangle_contains_aabr		q_double_rectangle_contains_aabr
#	define q_rectangle_contains_circle		q_double_rectangle_contains_circle

#endif

#endif /* __Q_functions_geometry_QRectangle_H__ */
