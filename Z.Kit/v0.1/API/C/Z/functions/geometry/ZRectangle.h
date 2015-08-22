/* Z Kit C API - functions/geometry/ZRectangle.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_ZRectangle_H__
#define __Z_functions_geometry_ZRectangle_H__

#include <Z/functions/geometry/constructors.h>
#include <Z/functions/base/Z2DValue.h>


#define Z_IMPLEMENTATION_RECTANGLE(Type, type, _)						\
												\
												\
Z_INLINE zboolean z_rectangle_##type##_are_equal(ZRectangle##Type a, ZRectangle##Type b)	\
	{											\
	return	z_2d_##type##_are_equal(a.point, b.point) &&					\
		z_2d_##type##_are_equal(a.size,  b.size );					\
	}											\
												\
												\
Z_INLINE zboolean z_rectangle_##type##_contains(ZRectangle##Type a, ZRectangle##Type b)		\
	{											\
	return	b.point.x	     >= a.point.x	     &&					\
		b.point.y	     >= a.point.y	     &&					\
		b.point.x + b.size.x <= a.point.x + a.size.x &&					\
		b.point.y + b.size.y <= a.point.y + a.size.y;					\
	}											\
												\
												\
Z_INLINE zboolean z_rectangle_##type##_collide(ZRectangle##Type a, ZRectangle##Type b)		\
	{											\
	return	a.point.x < b.point.x + b.size.x && b.point.x < a.point.x + a.size.x &&		\
		a.point.y < b.point.y + b.size.y && b.point.y < a.point.y + a.size.y;		\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_intersection(					\
	ZRectangle##Type a,									\
	ZRectangle##Type b									\
)												\
	{											\
	z##type x1, x2, y1, y2;									\
												\
	return	(x1 = z_##type##_maximum(a.point.x, b.point.x)) <=				\
		(x2 = z_##type##_minimum(a.point.x + a.size.x, b.point.x + b.size.x)) &&	\
		(y1 = z_##type##_maximum(a.point.y, b.point.y)) <=				\
		(y2 = z_##type##_minimum(a.point.y + a.size.y, b.point.y + b.size.y))		\
												\
		? z_rectangle_##type(x1, y1, x2 - x1, y2 - y1)					\
		: z_rectangle_##type##_zero;							\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_union(ZRectangle##Type a, ZRectangle##Type b)	\
	{											\
	ZRectangle##Type result;								\
												\
	result.point = z_2d_##type##_minimum(a.point, b.point);					\
												\
	result.size.x =										\
	z_##type##_maximum(a.point.x + a.size.x, b.point.x + b.size.x) - result.point.x;	\
												\
	result.size.y =										\
	z_##type##_maximum(a.point.y + a.size.y, b.point.y + b.size.y) - result.point.y;	\
												\
	return result;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_from_vertices(Z2D##Type a, Z2D##Type b)		\
	{											\
	Z2D##Type minimum = z_2d_##type##_minimum(a, b);					\
	Z2D##Type maximum = z_2d_##type##_maximum(a, b);					\
												\
	return z_rectangle_##type								\
		(minimum.x,  minimum.y, maximum.x - minimum.x, maximum.y - minimum.y);		\
	}											\
												\
												\
Z_INLINE zboolean z_rectangle_##type##_is_zero(ZRectangle##Type object)				\
	{return z_2d_##type##_is_zero(object.point) && z_2d_##type##_is_zero(object.size);}	\
												\
												\
Z_INLINE z##type z_rectangle_##type##_minimum_x(ZRectangle##Type object)			\
	{return object.point.x;}								\
												\
												\
Z_INLINE z##type z_rectangle_##type##_minimum_y(ZRectangle##Type object)			\
	{return object.point.y;}								\
												\
												\
Z_INLINE z##type z_rectangle_##type##_maximum_x(ZRectangle##Type object)			\
	{return object.point.x + object.size.x;}						\
												\
												\
Z_INLINE z##type z_rectangle_##type##_maximum_y(ZRectangle##Type object)			\
	{return object.point.y + object.size.y;}						\
												\
												\
Z_INLINE z##type z_rectangle_##type##_middle_x(ZRectangle##Type object)				\
	{return object.point.x + object.size.x / _(2.0);}					\
												\
												\
Z_INLINE z##type z_rectangle_##type##_middle_y(ZRectangle##Type object)				\
	{return object.point.y + object.size.y / _(2.0);}					\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_top_left(ZRectangle##Type object)			\
	{return z_2d_##type(object.point.x, object.point.y + object.size.y);}			\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_top_right(ZRectangle##Type object)			\
	{return z_2d_##type(object.point.x + object.size.x, object.point.y + object.size.y);}	\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_top_center(ZRectangle##Type object)			\
	{											\
	return z_2d_##type									\
		(object.point.x + object.size.x / _(2.0), object.point.y + object.size.y);	\
	}											\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_bottom_left(ZRectangle##Type object)			\
	{return object.point;}									\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_bottom_right(ZRectangle##Type object)			\
	{return z_2d_##type(object.point.x + object.size.x, object.point.y);}			\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_bottom_center(ZRectangle##Type object)			\
	{return z_2d_##type(object.point.x + object.size.x / _(2.0), object.point.y);}		\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_center_left(ZRectangle##Type object)			\
	{return z_2d_##type(object.point.x, object.point.y + object.size.y / _(2.0));}		\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_center_right(ZRectangle##Type object)			\
	{											\
	return z_2d_##type									\
		(object.point.x + object.size.x, object.point.y + object.size.y / _(2.0));	\
	}											\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_center(ZRectangle##Type object)				\
	{											\
	return z_2d_##type									\
		(object.point.x + object.size.x / _(2.0),					\
		 object.point.y + object.size.y / _(2.0));					\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_correct(ZRectangle##Type object)			\
	{											\
	if (object.size.x < _(0.0)) object.point.x -= (object.size.x = -object.size.x);		\
	if (object.size.y < _(0.0)) object.point.y -= (object.size.y = -object.size.y);		\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_top_half(ZRectangle##Type object)		\
	{											\
	object.point.y += (object.size.y /= _(2.0));						\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_bottom_half(ZRectangle##Type object)		\
	{											\
	object.size.y /= _(2.0);								\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_left_half(ZRectangle##Type object)		\
	{											\
	object.size.x /= _(2.0);								\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_right_half(ZRectangle##Type object)		\
	{											\
	object.point.x += (object.size.x /= _(2.0));						\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_top_left_quarter(ZRectangle##Type object)	\
	{											\
	object.size.x  /= _(2.0);								\
	object.point.y += (object.size.y /= _(2.0));						\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_top_right_quarter(ZRectangle##Type object)	\
	{											\
	object.point.x += (object.size.x /= _(2.0));						\
	object.point.y += (object.size.y /= _(2.0));						\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_bottom_left_quarter(ZRectangle##Type object)	\
	{											\
	object.size.x /= _(2.0);								\
	object.size.y /= _(2.0);								\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_bottom_right_quarter(ZRectangle##Type object)	\
	{											\
	object.point.x += (object.size.x /= _(2.0));						\
	object.size.y  /= _(2.0);								\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_align_in_top_left(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.y += object.size.y - size.y;						\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_align_in_top_right(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.x += object.size.x - size.x;						\
	object.point.y += object.size.y - size.y;						\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_align_in_top_center(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.x += (object.size.x - size.x) / _(2.0);					\
	object.point.y +=  object.size.y - size.y;						\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_align_in_bottom_left(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.size = size;									\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_align_in_bottom_right(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.x += object.size.x - size.x;						\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_align_in_bottom_center(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.x += (object.size.x - size.x) / _(2.0);					\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_align_in_center_left(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.y += (object.size.y - size.y) / _(2.0);					\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_align_in_center_right(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.x +=  object.size.x - size.x;						\
	object.point.y += (object.size.y - size.y) / _(2.0);					\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_align_in_center(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.x += (object.size.x - size.x) / _(2.0);					\
	object.point.y += (object.size.y - size.y) / _(2.0);					\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_fit_in_top_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x;							\
	result.point.y = object.point.y + object.size.y - result.size.y;			\
	return result;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_fit_in_top_right(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + object.size.x - result.size.x;			\
	result.point.y = object.point.y + object.size.y - result.size.y;			\
	return result;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_fit_in_top_center(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + (object.size.x - result.size.x) / _(2.0);		\
	result.point.y = object.point.y + object.size.y - result.size.y;			\
	return result;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_fit_in_bottom_left(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.size = z_2d_##type##_fit(size, object.size);					\
	return object;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_fit_in_bottom_right(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + object.size.x - result.size.x;			\
	result.point.y = object.point.y;							\
	return result;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_fit_in_bottom_center(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + (object.size.x - result.size.x) / _(2.0);		\
	result.point.y = object.point.y;							\
	return result;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_fit_in_center_left(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x;							\
	result.point.y = object.point.y + (object.size.y - result.size.y) / _(2.0);		\
	return result;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_fit_in_center_right(				\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + object.size.x - result.size.x;			\
	result.point.y = object.point.y + (object.size.y - result.size.y) / _(2.0);		\
	return result;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_rectangle_##type##_fit_in_center(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + (object.size.x - result.size.x) / _(2.0);		\
	result.point.y = object.point.y + (object.size.y - result.size.y) / _(2.0);		\
	return result;										\
	}											\
												\
												\
Z_INLINE ZCircle##Type z_rectangle_##type##_inner_circle(ZRectangle##Type object)		\
	{											\
	ZCircle##Type result;									\
												\
	result.point  = z_rectangle_##type##_center(object);					\
	result.radius = z_##type##_minimum(object.size.x, object.size.y) / _(2.0);		\
	return result;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_rectangle_##type##_to_aabr(ZRectangle##Type object)			\
	{											\
	return z_aabr_##type									\
		(object.point.x, object.point.y,						\
		 object.point.x + object.size.x, object.point.y + object.size.y);		\
	}											\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_absolute_point_to_unit(					\
	ZRectangle##Type object,								\
	Z2D##Type	 point									\
												\
)												\
	{											\
	return z_2d_##type									\
		((point.x - object.point.x) / object.size.x,					\
		 (point.y - object.point.y) / object.size.y);					\
	}											\
												\
												\
Z_INLINE Z2D##Type z_rectangle_##type##_unit_point_to_absolute(					\
	ZRectangle##Type object,								\
	Z2D##Type	 point									\
												\
)												\
	{											\
	return z_2d_##type									\
		(point.x * object.size.x + object.point.x,					\
		 point.y * object.size.y + object.point.y);					\
	}											\
												\
												\
Z_INLINE zboolean z_rectangle_##type##_contains_point(ZRectangle##Type object, Z2D##Type point)	\
	{											\
	return	point.x >= object.point.x		  &&					\
		point.y >= object.point.y		  &&					\
		point.x <= object.point.x + object.size.x &&					\
		point.y <= object.point.y + object.size.y;					\
	}											\
												\
												\
Z_INLINE zboolean z_rectangle_##type##_contains_line_segment(					\
	ZRectangle##Type object,								\
	Z2DLine##Type	 line_segment								\
)												\
	{											\
	return	z_rectangle_##type##_contains_point(object, line_segment.a) &&			\
		z_rectangle_##type##_contains_point(object, line_segment.b);			\
	}											\
												\
												\
Z_INLINE zboolean z_rectangle_##type##_contains_aabr(ZRectangle##Type object, ZAABR##Type aabr)	\
	{											\
	return	aabr.a.x >= object.point.x		   &&					\
		aabr.a.y >= object.point.y		   &&					\
		aabr.b.x <= object.point.x + object.size.x &&					\
		aabr.b.y <= object.point.y + object.size.y;					\
	}											\
												\
												\
Z_INLINE zboolean z_rectangle_##type##_contains_circle(						\
	ZRectangle##Type object,								\
	ZCircle##Type	 circle									\
)												\
	{											\
	return	circle.point.x - circle.radius >= object.point.x		 &&		\
		circle.point.y - circle.radius >= object.point.y		 &&		\
		circle.point.x + circle.radius <= object.point.x + object.size.x &&		\
		circle.point.y + circle.radius <= object.point.y + object.size.y;		\
	}


Z_IMPLEMENTATION_RECTANGLE(Float,   float,   Z_FLOAT  )
Z_IMPLEMENTATION_RECTANGLE(Double,  double,  Z_DOUBLE )
Z_IMPLEMENTATION_RECTANGLE(LDouble, ldouble, Z_LDOUBLE)


#define Z_JOIN_rectangle_type_are_equal(	     type) Z_PASTE_3(z_rectangle_, type, _are_equal		)
#define Z_JOIN_rectangle_type_contains(		     type) Z_PASTE_3(z_rectangle_, type, _contains		)
#define Z_JOIN_rectangle_type_collide(		     type) Z_PASTE_3(z_rectangle_, type, _collide		)
#define Z_JOIN_rectangle_type_intersection(	     type) Z_PASTE_3(z_rectangle_, type, _intersection		)
#define Z_JOIN_rectangle_type_union(		     type) Z_PASTE_3(z_rectangle_, type, _union			)
#define Z_JOIN_rectangle_type_from_vertices(	     type) Z_PASTE_3(z_rectangle_, type, _from_vertices		)
#define Z_JOIN_rectangle_type_is_zero(		     type) Z_PASTE_3(z_rectangle_, type, _is_zero		)
#define Z_JOIN_rectangle_type_minimum_x(	     type) Z_PASTE_3(z_rectangle_, type, _minimum_x		)
#define Z_JOIN_rectangle_type_minimum_y(	     type) Z_PASTE_3(z_rectangle_, type, _minimum_y		)
#define Z_JOIN_rectangle_type_maximum_x(	     type) Z_PASTE_3(z_rectangle_, type, _maximum_x		)
#define Z_JOIN_rectangle_type_maximum_y(	     type) Z_PASTE_3(z_rectangle_, type, _maximum_y		)
#define Z_JOIN_rectangle_type_middle_x(		     type) Z_PASTE_3(z_rectangle_, type, _middle_x		)
#define Z_JOIN_rectangle_type_middle_y(		     type) Z_PASTE_3(z_rectangle_, type, _middle_y		)
#define Z_JOIN_rectangle_type_top_left(		     type) Z_PASTE_3(z_rectangle_, type, _top_left		)
#define Z_JOIN_rectangle_type_top_right(	     type) Z_PASTE_3(z_rectangle_, type, _top_right		)
#define Z_JOIN_rectangle_type_top_center(	     type) Z_PASTE_3(z_rectangle_, type, _top_center		)
#define Z_JOIN_rectangle_type_bottom_left(	     type) Z_PASTE_3(z_rectangle_, type, _bottom_left		)
#define Z_JOIN_rectangle_type_bottom_right(	     type) Z_PASTE_3(z_rectangle_, type, _bottom_right		)
#define Z_JOIN_rectangle_type_bottom_center(	     type) Z_PASTE_3(z_rectangle_, type, _bottom_center		)
#define Z_JOIN_rectangle_type_center_left(	     type) Z_PASTE_3(z_rectangle_, type, _center_left		)
#define Z_JOIN_rectangle_type_center_right(	     type) Z_PASTE_3(z_rectangle_, type, _center_right		)
#define Z_JOIN_rectangle_type_center(		     type) Z_PASTE_3(z_rectangle_, type, _center		)
#define Z_JOIN_rectangle_type_correct(		     type) Z_PASTE_3(z_rectangle_, type, _correct		)
#define Z_JOIN_rectangle_type_top_half(		     type) Z_PASTE_3(z_rectangle_, type, _top_half		)
#define Z_JOIN_rectangle_type_bottom_half(	     type) Z_PASTE_3(z_rectangle_, type, _bottom_half		)
#define Z_JOIN_rectangle_type_left_half(	     type) Z_PASTE_3(z_rectangle_, type, _left_half		)
#define Z_JOIN_rectangle_type_right_half(	     type) Z_PASTE_3(z_rectangle_, type, _right_half		)
#define Z_JOIN_rectangle_type_top_left_quarter(	     type) Z_PASTE_3(z_rectangle_, type, _top_left_quarter	)
#define Z_JOIN_rectangle_type_top_right_quarter(     type) Z_PASTE_3(z_rectangle_, type, _top_right_quarter	)
#define Z_JOIN_rectangle_type_bottom_left_quarter(   type) Z_PASTE_3(z_rectangle_, type, _bottom_left_quarter	)
#define Z_JOIN_rectangle_type_bottom_right_quarter(  type) Z_PASTE_3(z_rectangle_, type, _bottom_right_quarter	)
#define Z_JOIN_rectangle_type_align_in_top_left(     type) Z_PASTE_3(z_rectangle_, type, _align_in_top_left	)
#define Z_JOIN_rectangle_type_align_in_top_right(    type) Z_PASTE_3(z_rectangle_, type, _align_in_top_right	)
#define Z_JOIN_rectangle_type_align_in_top_center(   type) Z_PASTE_3(z_rectangle_, type, _align_in_top_center	)
#define Z_JOIN_rectangle_type_align_in_bottom_left(  type) Z_PASTE_3(z_rectangle_, type, _align_in_bottom_left	)
#define Z_JOIN_rectangle_type_align_in_bottom_right( type) Z_PASTE_3(z_rectangle_, type, _align_in_bottom_right	)
#define Z_JOIN_rectangle_type_align_in_bottom_center(type) Z_PASTE_3(z_rectangle_, type, _align_in_bottom_center)
#define Z_JOIN_rectangle_type_align_in_center_left(  type) Z_PASTE_3(z_rectangle_, type, _align_in_center_left	)
#define Z_JOIN_rectangle_type_align_in_center_right( type) Z_PASTE_3(z_rectangle_, type, _align_in_center_right	)
#define Z_JOIN_rectangle_type_align_in_center(	     type) Z_PASTE_3(z_rectangle_, type, _align_in_center	)
#define Z_JOIN_rectangle_type_fit_in_top_left(	     type) Z_PASTE_3(z_rectangle_, type, _fit_in_top_left	)
#define Z_JOIN_rectangle_type_fit_in_top_right(	     type) Z_PASTE_3(z_rectangle_, type, _fit_in_top_right	)
#define Z_JOIN_rectangle_type_fit_in_top_center(     type) Z_PASTE_3(z_rectangle_, type, _fit_in_top_center	)
#define Z_JOIN_rectangle_type_fit_in_bottom_left(    type) Z_PASTE_3(z_rectangle_, type, _fit_in_bottom_left	)
#define Z_JOIN_rectangle_type_fit_in_bottom_right(   type) Z_PASTE_3(z_rectangle_, type, _fit_in_bottom_right	)
#define Z_JOIN_rectangle_type_fit_in_bottom_center(  type) Z_PASTE_3(z_rectangle_, type, _fit_in_bottom_center	)
#define Z_JOIN_rectangle_type_fit_in_center_left(    type) Z_PASTE_3(z_rectangle_, type, _fit_in_center_left	)
#define Z_JOIN_rectangle_type_fit_in_center_right(   type) Z_PASTE_3(z_rectangle_, type, _fit_in_center_right	)
#define Z_JOIN_rectangle_type_fit_in_center(	     type) Z_PASTE_3(z_rectangle_, type, _fit_in_center		)
#define Z_JOIN_rectangle_type_inner_circle(	     type) Z_PASTE_3(z_rectangle_, type, _inner_circle		)
#define Z_JOIN_rectangle_type_to_aabr(		     type) Z_PASTE_3(z_rectangle_, type, _to_aabr		)
#define Z_JOIN_rectangle_type_absolute_point_to_unit(type) Z_PASTE_3(z_rectangle_, type, _absolute_point_to_unit)
#define Z_JOIN_rectangle_type_unit_point_to_absolute(type) Z_PASTE_3(z_rectangle_, type, _unit_point_to_absolute)
#define Z_JOIN_rectangle_type_contains_point(	     type) Z_PASTE_3(z_rectangle_, type, _contains_point	)
#define Z_JOIN_rectangle_type_contains_line_segment( type) Z_PASTE_3(z_rectangle_, type, _contains_line_segment	)
#define Z_JOIN_rectangle_type_contains_aabr(	     type) Z_PASTE_3(z_rectangle_, type, _contains_aabr		)
#define Z_JOIN_rectangle_type_contains_circle(	     type) Z_PASTE_3(z_rectangle_, type, _contains_circle	)


/* MARK: - Default real type definitions */


#define z_rectangle_are_equal		   Z_JOIN_rectangle_type_are_equal	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_contains		   Z_JOIN_rectangle_type_contains	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_collide		   Z_JOIN_rectangle_type_collide	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_intersection	   Z_JOIN_rectangle_type_intersection	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_union		   Z_JOIN_rectangle_type_union		       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_from_vertices	   Z_JOIN_rectangle_type_from_vertices	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_is_zero		   Z_JOIN_rectangle_type_is_zero	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_minimum_x		   Z_JOIN_rectangle_type_minimum_x	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_minimum_y		   Z_JOIN_rectangle_type_minimum_y	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_maximum_x		   Z_JOIN_rectangle_type_maximum_x	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_maximum_y		   Z_JOIN_rectangle_type_maximum_y	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_middle_x		   Z_JOIN_rectangle_type_middle_x	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_middle_y		   Z_JOIN_rectangle_type_middle_y	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_top_left		   Z_JOIN_rectangle_type_top_left	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_top_right		   Z_JOIN_rectangle_type_top_right	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_top_center		   Z_JOIN_rectangle_type_top_center	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_bottom_left		   Z_JOIN_rectangle_type_bottom_left	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_bottom_right	   Z_JOIN_rectangle_type_bottom_right	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_bottom_center	   Z_JOIN_rectangle_type_bottom_center	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_center_left		   Z_JOIN_rectangle_type_center_left	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_center_right	   Z_JOIN_rectangle_type_center_right	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_center		   Z_JOIN_rectangle_type_center		       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_correct		   Z_JOIN_rectangle_type_correct	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_top_half		   Z_JOIN_rectangle_type_top_half	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_bottom_half		   Z_JOIN_rectangle_type_bottom_half	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_left_half		   Z_JOIN_rectangle_type_left_half	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_right_half		   Z_JOIN_rectangle_type_right_half	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_top_left_quarter	   Z_JOIN_rectangle_type_top_left_quarter      (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_top_right_quarter	   Z_JOIN_rectangle_type_top_right_quarter     (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_bottom_left_quarter	   Z_JOIN_rectangle_type_bottom_left_quarter   (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_bottom_right_quarter   Z_JOIN_rectangle_type_bottom_right_quarter  (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_align_in_top_left	   Z_JOIN_rectangle_type_align_in_top_left     (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_align_in_top_right	   Z_JOIN_rectangle_type_align_in_top_right    (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_align_in_top_center	   Z_JOIN_rectangle_type_align_in_top_center   (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_align_in_bottom_left   Z_JOIN_rectangle_type_align_in_bottom_left  (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_align_in_bottom_right  Z_JOIN_rectangle_type_align_in_bottom_right (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_align_in_bottom_center Z_JOIN_rectangle_type_align_in_bottom_center(Z_REAL_FIXED_TYPE_name)
#define z_rectangle_align_in_center_left   Z_JOIN_rectangle_type_align_in_center_left  (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_align_in_center_right  Z_JOIN_rectangle_type_align_in_center_right (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_align_in_center	   Z_JOIN_rectangle_type_align_in_center       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_fit_in_top_left	   Z_JOIN_rectangle_type_fit_in_top_left       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_fit_in_top_right	   Z_JOIN_rectangle_type_fit_in_top_right      (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_fit_in_top_center	   Z_JOIN_rectangle_type_fit_in_top_center     (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_fit_in_bottom_left	   Z_JOIN_rectangle_type_fit_in_bottom_left    (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_fit_in_bottom_right	   Z_JOIN_rectangle_type_fit_in_bottom_right   (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_fit_in_bottom_center   Z_JOIN_rectangle_type_fit_in_bottom_center  (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_fit_in_center_left	   Z_JOIN_rectangle_type_fit_in_center_left    (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_fit_in_center_right	   Z_JOIN_rectangle_type_fit_in_center_right   (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_fit_in_center	   Z_JOIN_rectangle_type_fit_in_center	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_inner_circle	   Z_JOIN_rectangle_type_inner_circle	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_to_aabr		   Z_JOIN_rectangle_type_to_aabr	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_absolute_point_to_unit Z_JOIN_rectangle_type_absolute_point_to_unit(Z_REAL_FIXED_TYPE_name)
#define z_rectangle_unit_point_to_absolute Z_JOIN_rectangle_type_unit_point_to_absolute(Z_REAL_FIXED_TYPE_name)
#define z_rectangle_contains_point	   Z_JOIN_rectangle_type_contains_point	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_contains_line_segment  Z_JOIN_rectangle_type_contains_line_segment (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_contains_aabr	   Z_JOIN_rectangle_type_contains_aabr	       (Z_REAL_FIXED_TYPE_name)
#define z_rectangle_contains_circle	   Z_JOIN_rectangle_type_contains_circle       (Z_REAL_FIXED_TYPE_name)


#endif /* __Z_functions_geometry_ZRectangle_H__ */
