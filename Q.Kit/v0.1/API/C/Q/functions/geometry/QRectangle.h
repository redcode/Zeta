/* Q Kit C API - functions/geometry/QRectangle.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_QRectangle_H__
#define __Q_functions_geometry_QRectangle_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/base/Q2DValue.h>


#define Q_IMPLEMENTATION_RECTANGLE(Type, type, _)						\
												\
												\
Q_INLINE qboolean q_rectangle_##type##_are_equal(QRectangle##Type a, QRectangle##Type b)	\
	{											\
	return	q_2d_##type##_are_equal(a.point, b.point) &&					\
		q_2d_##type##_are_equal(a.size,  b.size );					\
	}											\
												\
												\
Q_INLINE qboolean q_rectangle_##type##_contains(QRectangle##Type a, QRectangle##Type b)		\
	{											\
	return	b.point.x	     >= a.point.x	     &&					\
		b.point.y	     >= a.point.y	     &&					\
		b.point.x + b.size.x <= a.point.x + a.size.x &&					\
		b.point.y + b.size.y <= a.point.y + a.size.y;					\
	}											\
												\
												\
Q_INLINE qboolean q_rectangle_##type##_collide(QRectangle##Type a, QRectangle##Type b)		\
	{											\
	return	a.point.x < b.point.x + b.size.x &&						\
		b.point.x < a.point.x + a.size.x &&						\
		a.point.y < b.point.y + b.size.y &&						\
		b.point.y < a.point.y + a.size.y;						\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_intersection(					\
	QRectangle##Type a,									\
	QRectangle##Type b									\
)												\
	{											\
	q##type x1, x2, y1, y2;									\
												\
	return	(x1 = q_##type##_maximum(a.point.x, b.point.x)) <=				\
		(x2 = q_##type##_minimum(a.point.x + a.size.x, b.point.x + b.size.x)) &&	\
		(y1 = q_##type##_maximum(a.point.y, b.point.y)) <=				\
		(y2 = q_##type##_minimum(a.point.y + a.size.y, b.point.y + b.size.y))		\
												\
		? q_rectangle_##type(x1, y1, x2 - x1, y2 - y1)					\
		: q_rectangle_##type##_zero;							\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_union(QRectangle##Type a, QRectangle##Type b)	\
	{											\
	QRectangle##Type result;								\
												\
	result.point = q_2d_##type##_minimum(a.point, b.point);					\
												\
	result.size.x =										\
	q_##type##_maximum(a.point.x + a.size.x, b.point.x + b.size.x) - result.point.x;	\
												\
	result.size.y =										\
	q_##type##_maximum(a.point.y + a.size.y, b.point.y + b.size.y) - result.point.y;	\
												\
	return result;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_from_vertices(Q2D##Type a, Q2D##Type b)		\
	{											\
	Q2D##Type minimum = q_2d_##type##_minimum(a, b);					\
	Q2D##Type maximum = q_2d_##type##_maximum(a, b);					\
												\
	return q_rectangle_##type								\
		(minimum.x,  minimum.y, maximum.x - minimum.x, maximum.y - minimum.y);		\
	}											\
												\
												\
Q_INLINE qboolean q_rectangle_##type##_is_zero(QRectangle##Type object)				\
	{return q_2d_##type##_is_zero(object.point) && q_2d_##type##_is_zero(object.size);}	\
												\
												\
Q_INLINE q##type q_rectangle_##type##_minimum_x(QRectangle##Type object)			\
	{return object.point.x;}								\
												\
												\
Q_INLINE q##type q_rectangle_##type##_minimum_y(QRectangle##Type object)			\
	{return object.point.y;}								\
												\
												\
Q_INLINE q##type q_rectangle_##type##_maximum_x(QRectangle##Type object)			\
	{return object.point.x + object.size.x;}						\
												\
												\
Q_INLINE q##type q_rectangle_##type##_maximum_y(QRectangle##Type object)			\
	{return object.point.y + object.size.y;}						\
												\
												\
Q_INLINE q##type q_rectangle_##type##_middle_x(QRectangle##Type object)				\
	{return object.point.x + object.size.x / _(2.0);}					\
												\
												\
Q_INLINE q##type q_rectangle_##type##_middle_y(QRectangle##Type object)				\
	{return object.point.y + object.size.y / _(2.0);}					\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_top_left(QRectangle##Type object)			\
	{return q_2d_##type(object.point.x, object.point.y + object.size.y);}			\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_top_right(QRectangle##Type object)			\
	{return q_2d_##type(object.point.x + object.size.x, object.point.y + object.size.y);}	\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_top_center(QRectangle##Type object)			\
	{											\
	return q_2d_##type									\
		(object.point.x + object.size.x / _(2.0), object.point.y + object.size.y);	\
	}											\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_bottom_left(QRectangle##Type object)			\
	{return object.point;}									\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_bottom_right(QRectangle##Type object)			\
	{return q_2d_##type(object.point.x + object.size.x, object.point.y);}			\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_bottom_center(QRectangle##Type object)			\
	{return q_2d_##type(object.point.x + object.size.x / _(2.0), object.point.y);}		\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_center_left(QRectangle##Type object)			\
	{return q_2d_##type(object.point.x, object.point.y + object.size.y / _(2.0));}		\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_center_right(QRectangle##Type object)			\
	{											\
	return q_2d_##type									\
		(object.point.x + object.size.x, object.point.y + object.size.y / _(2.0));	\
	}											\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_center(QRectangle##Type object)				\
	{											\
	return q_2d_##type									\
		(object.point.x + object.size.x / _(2.0),					\
		 object.point.y + object.size.y / _(2.0));					\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_correct(QRectangle##Type object)			\
	{											\
	if (object.size.x < _(0.0)) object.point.x -= (object.size.x = -object.size.x);		\
	if (object.size.y < _(0.0)) object.point.y -= (object.size.y = -object.size.y);		\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_top_half(QRectangle##Type object)		\
	{											\
	object.point.y += (object.size.y /= _(2.0));						\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_bottom_half(QRectangle##Type object)		\
	{											\
	object.size.y /= _(2.0);								\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_left_half(QRectangle##Type object)		\
	{											\
	object.size.x /= _(2.0);								\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_right_half(QRectangle##Type object)		\
	{											\
	object.point.x += (object.size.x /= _(2.0));						\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_top_left_quarter(QRectangle##Type object)	\
	{											\
	object.size.x  /= _(2.0);								\
	object.point.y += (object.size.y /= _(2.0));						\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_top_right_quarter(QRectangle##Type object)	\
	{											\
	object.point.x += (object.size.x /= _(2.0));						\
	object.point.y += (object.size.y /= _(2.0));						\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_bottom_left_quarter(QRectangle##Type object)	\
	{											\
	object.size.x /= _(2.0);								\
	object.size.y /= _(2.0);								\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_bottom_right_quarter(QRectangle##Type object)	\
	{											\
	object.point.x += (object.size.x /= _(2.0));						\
	object.size.y  /= _(2.0);								\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_align_in_top_left(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	object.point.y += object.size.y - size.y;						\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_align_in_top_right(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	object.point.x += object.size.x - size.x;						\
	object.point.y += object.size.y - size.y;						\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_align_in_top_center(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	object.point.x += (object.size.x - size.x) / _(2.0);					\
	object.point.y +=  object.size.y - size.y;						\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_align_in_bottom_left(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	object.size = size;									\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_align_in_bottom_right(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	object.point.x += object.size.x - size.x;						\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_align_in_bottom_center(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	object.point.x += (object.size.x - size.x) / _(2.0);					\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_align_in_center_left(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	object.point.y += (object.size.y - size.y) / _(2.0);					\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_align_in_center_right(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	object.point.x +=  object.size.x - size.x;						\
	object.point.y += (object.size.y - size.y) / _(2.0);					\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_align_in_center(					\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	object.point.x += (object.size.x - size.x) / _(2.0);					\
	object.point.y += (object.size.y - size.y) / _(2.0);					\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_fit_in_top_left(					\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	QRectangle##Type result;								\
												\
	result.size    = q_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x;							\
	result.point.y = object.point.y + object.size.y - result.size.y;			\
	return result;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_fit_in_top_right(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	QRectangle##Type result;								\
												\
	result.size    = q_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + object.size.x - result.size.x;			\
	result.point.y = object.point.y + object.size.y - result.size.y;			\
	return result;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_fit_in_top_center(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	QRectangle##Type result;								\
												\
	result.size    = q_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + (object.size.x - result.size.x) / _(2.0);		\
	result.point.y = object.point.y + object.size.y - result.size.y;			\
	return result;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_fit_in_bottom_left(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	object.size = q_2d_##type##_fit(size, object.size);					\
	return object;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_fit_in_bottom_right(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	QRectangle##Type result;								\
												\
	result.size    = q_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + object.size.x - result.size.x;			\
	result.point.y = object.point.y;							\
	return result;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_fit_in_bottom_center(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	QRectangle##Type result;								\
												\
	result.size    = q_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + (object.size.x - result.size.x) / _(2.0);		\
	result.point.y = object.point.y;							\
	return result;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_fit_in_center_left(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	QRectangle##Type result;								\
												\
	result.size    = q_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x;							\
	result.point.y = object.point.y + (object.size.y - result.size.y) / _(2.0);		\
	return result;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_fit_in_center_right(				\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	QRectangle##Type result;								\
												\
	result.size    = q_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + object.size.x - result.size.x;			\
	result.point.y = object.point.y + (object.size.y - result.size.y) / _(2.0);		\
	return result;										\
	}											\
												\
												\
Q_INLINE QRectangle##Type q_rectangle_##type##_fit_in_center(					\
	QRectangle##Type object,								\
	Q2D##Type	 size									\
)												\
	{											\
	QRectangle##Type result;								\
												\
	result.size    = q_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + (object.size.x - result.size.x) / _(2.0);		\
	result.point.y = object.point.y + (object.size.y - result.size.y) / _(2.0);		\
	return result;										\
	}											\
												\
												\
Q_INLINE QCircle##Type q_rectangle_##type##_inner_circle(QRectangle##Type object)		\
	{											\
	QCircle##Type result;									\
												\
	result.point  = q_rectangle_##type##_center(object);					\
	result.radius = q_##type##_minimum(object.size.x, object.size.y) / _(2.0);		\
	return result;										\
	}											\
												\
												\
Q_INLINE QAABR##Type q_rectangle_##type##_to_aabr(QRectangle##Type object)			\
	{											\
	return q_aabr_##type									\
		(object.point.x,  object.point.y,						\
		 object.point.x + object.size.x,						\
		 object.point.y + object.size.y);						\
	}											\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_absolute_point_to_unit(					\
	QRectangle##Type object,								\
	Q2D##Type	 point									\
												\
)												\
	{											\
	return q_2d_##type									\
		((point.x - object.point.x) / object.size.x,					\
		 (point.y - object.point.y) / object.size.y);					\
	}											\
												\
												\
Q_INLINE Q2D##Type q_rectangle_##type##_unit_point_to_absolute(					\
	QRectangle##Type object,								\
	Q2D##Type	 point									\
												\
)												\
	{											\
	return q_2d_##type									\
		(point.x * object.size.x + object.point.x,					\
		 point.y * object.size.y + object.point.y);					\
	}											\
												\
												\
Q_INLINE qboolean q_rectangle_##type##_contains_point(QRectangle##Type object, Q2D##Type point)	\
	{											\
	return	point.x >= object.point.x		  &&					\
		point.y >= object.point.y		  &&					\
		point.x <= object.point.x + object.size.x &&					\
		point.y <= object.point.y + object.size.y;					\
	}											\
												\
												\
Q_INLINE qboolean q_rectangle_##type##_contains_line_segment(					\
	QRectangle##Type object,								\
	Q2DLine##Type	 line_segment								\
)												\
	{											\
	return	q_rectangle_##type##_contains_point(object, line_segment.a) &&			\
		q_rectangle_##type##_contains_point(object, line_segment.b);			\
	}											\
												\
												\
Q_INLINE qboolean q_rectangle_##type##_contains_aabr(QRectangle##Type object, QAABR##Type aabr)	\
	{											\
	return	aabr.a.x >= object.point.x		   &&					\
		aabr.a.y >= object.point.y		   &&					\
		aabr.b.x <= object.point.x + object.size.x &&					\
		aabr.b.y <= object.point.y + object.size.y;					\
	}											\
												\
												\
Q_INLINE qboolean q_rectangle_##type##_contains_circle(						\
	QRectangle##Type object,								\
	QCircle##Type	 circle									\
)												\
	{											\
	return	circle.point.x - circle.radius >= object.point.x &&				\
		circle.point.y - circle.radius >= object.point.y &&				\
		circle.point.x + circle.radius <=						\
		object.point.x + object.size.x			 &&				\
		circle.point.y + circle.radius <=						\
		object.point.y + object.size.y;							\
	}


Q_IMPLEMENTATION_RECTANGLE(Float,   float,   Q_FLOAT  )
Q_IMPLEMENTATION_RECTANGLE(Double,  double,  Q_DOUBLE )
Q_IMPLEMENTATION_RECTANGLE(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#define q_rectangle_are_equal		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _are_equal		 )
#define q_rectangle_contains		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _contains		 )
#define q_rectangle_collide		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _collide		 )
#define q_rectangle_intersection	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _intersection		 )
#define q_rectangle_union		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _union		 )
#define q_rectangle_from_vertices	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _from_vertices	 )
#define q_rectangle_is_zero		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _is_zero		 )
#define q_rectangle_minimum_x		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _minimum_x		 )
#define q_rectangle_minimum_y		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _minimum_y		 )
#define q_rectangle_maximum_x		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _maximum_x		 )
#define q_rectangle_maximum_y		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _maximum_y		 )
#define q_rectangle_middle_x		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _middle_x		 )
#define q_rectangle_middle_y		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _middle_y		 )
#define q_rectangle_top_left		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _top_left		 )
#define q_rectangle_top_right		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _top_right		 )
#define q_rectangle_top_center		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _top_center		 )
#define q_rectangle_bottom_left		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _bottom_left		 )
#define q_rectangle_bottom_right	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _bottom_right		 )
#define q_rectangle_bottom_center	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _bottom_center	 )
#define q_rectangle_center_left		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _center_left		 )
#define q_rectangle_center_right	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _center_right		 )
#define q_rectangle_center		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _center		 )
#define q_rectangle_correct		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _correct		 )
#define q_rectangle_top_half		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _top_half		 )
#define q_rectangle_bottom_half		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _bottom_half		 )
#define q_rectangle_left_half		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _left_half		 )
#define q_rectangle_right_half		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _right_half		 )
#define q_rectangle_top_left_quarter	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _top_left_quarter	 )
#define q_rectangle_top_right_quarter	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _top_right_quarter	 )
#define q_rectangle_bottom_left_quarter	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _bottom_left_quarter	 )
#define q_rectangle_bottom_right_quarter   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _bottom_right_quarter	 )
#define q_rectangle_align_in_top_left	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _align_in_top_left	 )
#define q_rectangle_align_in_top_right	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _align_in_top_right	 )
#define q_rectangle_align_in_top_center	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _align_in_top_center	 )
#define q_rectangle_align_in_bottom_left   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _align_in_bottom_left	 )
#define q_rectangle_align_in_bottom_right  Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _align_in_bottom_right )
#define q_rectangle_align_in_bottom_center Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _align_in_bottom_center)
#define q_rectangle_align_in_center_left   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _align_in_center_left	 )
#define q_rectangle_align_in_center_right  Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _align_in_center_right )
#define q_rectangle_align_in_center	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _align_in_center	 )
#define q_rectangle_fit_in_top_left	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _fit_in_top_left	 )
#define q_rectangle_fit_in_top_right	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _fit_in_top_right	 )
#define q_rectangle_fit_in_top_center	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _fit_in_top_center	 )
#define q_rectangle_fit_in_bottom_left	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _fit_in_bottom_left	 )
#define q_rectangle_fit_in_bottom_right	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _fit_in_bottom_right	 )
#define q_rectangle_fit_in_bottom_center   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _fit_in_bottom_center	 )
#define q_rectangle_fit_in_center_left	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _fit_in_center_left	 )
#define q_rectangle_fit_in_center_right	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _fit_in_center_right	 )
#define q_rectangle_fit_in_center	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _fit_in_center	 )
#define q_rectangle_inner_circle	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _inner_circle		 )
#define q_rectangle_to_aabr		   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _to_aabr		 )
#define q_rectangle_absolute_point_to_unit Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _absolute_point_to_unit)
#define q_rectangle_unit_point_to_absolute Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _unit_point_to_absolute)
#define q_rectangle_contains_point	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _contains_point	 )
#define q_rectangle_contains_line_segment  Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _contains_line_segment )
#define q_rectangle_contains_aabr	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _contains_aabr	 )
#define q_rectangle_contains_circle	   Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _contains_circle	 )

#endif /* __Q_functions_geometry_QRectangle_H__ */
