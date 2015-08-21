/* Z Kit C API - functions/geometry/ZAABR.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_ZAABR_H__
#define __Z_functions_geometry_ZAABR_H__

#include <Z/functions/geometry/Z2DLine.h>

#define z_aabr_float_are_equal	 z_2d_line_float_are_equal
#define z_aabr_float_is_zero	 z_2d_line_float_is_zero
#define z_aabr_float_center	 z_2d_line_segment_float_center

#define z_aabr_double_are_equal	 z_2d_line_double_are_equal
#define z_aabr_double_is_zero	 z_2d_line_double_is_zero
#define z_aabr_double_center	 z_2d_line_segment_double_center

#define z_aabr_ldouble_are_equal z_2d_line_ldouble_are_equal
#define z_aabr_ldouble_is_zero	 z_2d_line_ldouble_is_zero
#define z_aabr_ldouble_center	 z_2d_line_segment_ldouble_center


#define Z_IMPLEMENTATION_AABR(Type, type, _)							\
												\
												\
Z_INLINE zboolean z_aabr_##type##_contains(ZAABR##Type a, ZAABR##Type b)			\
	{return b.a.x >= a.a.x && b.a.y >= a.a.y && b.b.x <= a.b.x && b.b.y <= a.b.y;}		\
												\
												\
Z_INLINE zboolean z_aabr_##type##_collide(ZAABR##Type a, ZAABR##Type b)				\
	{return a.a.x < b.b.x && b.a.x < a.b.x && a.a.y < b.b.y && b.a.y < a.b.y;}		\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_intersection(ZAABR##Type a, ZAABR##Type b)			\
	{											\
	z##type x1, x2, y1, y2;									\
												\
	return	(x1 = z_##type##_maximum(a.a.x, b.a.x)) <=					\
		(x2 = z_##type##_minimum(a.b.x, b.b.x)) &&					\
		(y1 = z_##type##_maximum(a.a.y, b.a.y))	<=					\
		(y2 = z_##type##_minimum(a.b.y, b.b.y))						\
												\
		? z_aabr_##type(x1, y1, x2, y2)							\
		: z_aabr_##type##_zero;								\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_union(ZAABR##Type a, ZAABR##Type b)			\
	{											\
	ZAABR##Type result;									\
												\
	result.a = z_2d_##type##_minimum(a.a, b.a);						\
	result.b = z_2d_##type##_maximum(a.b, b.b);						\
	return result;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_from_vertices(Z2D##Type a, Z2D##Type b)			\
	{											\
	ZAABR##Type result;									\
												\
	result.a = z_2d_##type##_minimum(a, b);							\
	result.b = z_2d_##type##_maximum(a, b);							\
	return result;										\
	}											\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_size(ZAABR##Type object)					\
	{return z_2d_##type##_subtract(object.b, object.a);}					\
												\
												\
Z_INLINE z##type z_aabr_##type##_area(ZAABR##Type object)					\
	{return z_2d_##type##_inner_product(z_2d_##type##_subtract(object.b, object.a));}	\
												\
												\
Z_INLINE z##type z_aabr_##type##_middle_x(ZAABR##Type object)					\
	{return (object.a.x + object.b.x) / _(2.0);}						\
												\
												\
Z_INLINE z##type z_aabr_##type##_middle_y(ZAABR##Type object)					\
	{return (object.a.y + object.b.y) / _(2.0);}						\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_top_left(ZAABR##Type object)					\
	{return z_2d_##type(object.a.x, object.b.y);}						\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_top_right(ZAABR##Type object)				\
	{return object.b;}									\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_top_center(ZAABR##Type object)				\
	{return z_2d_##type((object.a.x + object.b.x) / _(2.0), object.b.y);}			\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_bottom_left(ZAABR##Type object)				\
	{return object.a;}									\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_bottom_right(ZAABR##Type object)				\
	{return z_2d_##type(object.b.x, object.a.y);}						\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_bottom_center(ZAABR##Type object)				\
	{return z_2d_##type((object.a.x + object.b.x) / _(2.0), object.a.y);}			\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_center_left(ZAABR##Type object)				\
	{return z_2d_##type(object.a.x, (object.a.y + object.b.y) / _(2.0));}			\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_center_right(ZAABR##Type object)				\
	{return z_2d_##type(object.b.x, (object.a.y + object.b.y) / _(2.0));}			\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_top_half(ZAABR##Type object)				\
	{											\
	object.a.y = (object.a.y + object.b.y) / _(2.0);					\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_bottom_half(ZAABR##Type object)				\
	{											\
	object.b.y = (object.a.y + object.b.y) / _(2.0);					\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_left_half(ZAABR##Type object)				\
	{											\
	object.b.x = (object.a.x + object.b.x) / _(2.0);					\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_right_half(ZAABR##Type object)				\
	{											\
	object.a.x = (object.a.x + object.b.x) / _(2.0);					\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_top_left_quarter(ZAABR##Type object)			\
	{											\
	object.b.x = (object.a.x + object.b.x) / _(2.0);					\
	object.a.y = (object.a.y + object.b.y) / _(2.0);					\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_top_right_quarter(ZAABR##Type object)			\
	{											\
	object.a.x = (object.a.x + object.b.x) / _(2.0);					\
	object.a.y = (object.a.y + object.b.y) / _(2.0);					\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_bottom_left_quarter(ZAABR##Type object)			\
	{											\
	object.b.x = (object.a.x + object.b.x) / _(2.0);					\
	object.b.y = (object.a.y + object.b.y) / _(2.0);					\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_bottom_right_quarter(ZAABR##Type object)			\
	{											\
	object.a.x = (object.a.x + object.b.x) / _(2.0);					\
	object.b.y = (object.a.y + object.b.y) / _(2.0);					\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_top_left(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.a.y = object.b.y - size.y;							\
	object.b.x = object.a.x + size.x;							\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_top_right(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.a.x = object.b.x - size.x;							\
	object.a.y = object.b.y - size.y;							\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_top_center(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.a.y = object.b.y - size.y;							\
	object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / _(2.0)) + size.x;	\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_bottom_left(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.b.x = object.a.x + size.x;							\
	object.b.y = object.a.y + size.y;							\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_bottom_right(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.a.x = object.b.x - size.x;							\
	object.b.y = object.b.y + size.x;							\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_bottom_center(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / _(2.0)) + size.x;	\
	object.b.y = object.a.y + size.y;							\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_center_left(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.b.x = object.a.x + size.x;							\
	object.b.y = (object.a.y += (object.b.y - object.a.y - size.y) / _(2.0)) + size.y;	\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_center_right(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.a.x = object.b.x - size.x;							\
	object.b.y = (object.a.y += (object.b.y - object.a.y - size.y) / _(2.0)) + size.y;	\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_center(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / _(2.0)) + size.x;	\
	object.b.y = (object.a.y += (object.b.y - object.a.y - size.y) / _(2.0)) + size.y;	\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_fit_in_top_left(ZAABR##Type object, Z2D##Type size)	\
	{											\
	size = z_2d_##type##_fit(size, z_aabr_##type##_size(object));				\
												\
	object.a.y = object.b.y - size.y;							\
	object.b.x = object.a.x + size.x;							\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_fit_in_top_right(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.a = z_2d_##type##_subtract							\
		(object.b, z_2d_##type##_fit(size, z_aabr_##type##_size(object)));		\
												\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_fit_in_top_center(ZAABR##Type object, Z2D##Type size)	\
	{											\
	Z2D##Type old_size = z_aabr_##type##_size(object);					\
												\
	object.a.y = object.b.y - (size = z_2d_##type##_fit(size, old_size)).y;			\
	object.b.x = (object.a.x += (old_size.x - size.x) / _(2.0)) + size.x;			\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_fit_in_bottom_left(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.b = z_2d_##type##_add								\
		(object.a, z_2d_##type##_fit(size, z_aabr_##type##_size(object)));		\
												\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_fit_in_bottom_right(ZAABR##Type object, Z2D##Type size)	\
	{											\
	size = z_2d_##type##_fit(size, z_aabr_##type##_size(object));				\
	return z_aabr_##type(object.b.x - size.x, object.a.y, object.b.x, object.a.y + size.y);	\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_fit_in_bottom_center(ZAABR##Type object, Z2D##Type size)	\
	{											\
	Z2D##Type old_size = z_aabr_##type##_size(object);					\
												\
	object.b.y = object.a.y + (size = z_2d_##type##_fit(size, old_size)).y;			\
	object.b.x = (object.a.x += (old_size.x - size.x) / _(2.0)) + size.x;			\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_fit_in_center_left(ZAABR##Type object, Z2D##Type size)	\
	{											\
	Z2D##Type old_size = z_aabr_##type##_size(object);					\
												\
	object.b.x = object.a.x + (size = z_2d_##type##_fit(size, old_size)).x;			\
	object.b.y = (object.a.y += (old_size.y - size.y) / _(2.0)) + size.y;			\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_fit_in_center_right(ZAABR##Type object, Z2D##Type size)	\
	{											\
	Z2D##Type old_size = z_aabr_##type##_size(object);					\
												\
	object.a.x = object.b.x - (size = z_2d_##type##_fit(size, old_size)).x;			\
	object.b.y = (object.a.y += (old_size.y - size.y) / _(2.0)) + size.y;			\
	return object;										\
	}											\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_fit_in_center(ZAABR##Type object, Z2D##Type size)		\
	{											\
	Z2D##Type old_size = z_aabr_##type##_size(object);					\
												\
	size = z_2d_##type##_fit(size, old_size);						\
	object.b.x = (object.a.x += (old_size.x - size.x) / _(2.0)) + size.x;			\
	object.b.y = (object.a.y += (old_size.y - size.y) / _(2.0)) + size.y;			\
	return object;										\
	}											\
												\
												\
Z_INLINE ZCircle##Type z_aabr_##type##_inner_circle(ZAABR##Type object)				\
	{											\
	ZCircle##Type result;									\
												\
	result.point = z_aabr_##type##_center(object);						\
												\
	result.radius =										\
	z_2d_##type##_inner_minimum(z_2d_##type##_subtract(object.b, object.a)) / _(2.0);	\
												\
	return result;										\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_aabr_##type##_to_rectangle(ZAABR##Type object)			\
	{											\
	return z_rectangle_##type								\
		(object.a.x, object.a.y, object.b.x - object.a.x, object.b.y - object.a.y);	\
	}											\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_absolute_point_to_unit(ZAABR##Type object, Z2D##Type point)	\
	{											\
	return z_2d_##type									\
		((point.x - object.a.x) / (object.b.x - object.a.x),				\
		 (point.y - object.a.y) / (object.b.y - object.a.y));				\
	}											\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_unit_point_to_absolute(ZAABR##Type object, Z2D##Type point)	\
	{											\
	return z_2d_##type									\
		(point.x * (object.b.x - object.a.x) + object.a.x,				\
		 point.y * (object.b.y - object.a.y) + object.a.y);				\
	}											\
												\
												\
Z_INLINE zboolean z_aabr_##type##_contains_point(ZAABR##Type object, Z3D##Type point)		\
	{											\
	return	object.a.x <= point.x && point.x <= object.a.x &&				\
		object.a.y <= point.y && point.y <= object.a.y;					\
	}											\
												\
												\
Z_INLINE zboolean z_aabr_##type##_contains_line_segment(					\
	ZAABR##Type   object,									\
	Z3DLine##Type segment									\
)												\
	{											\
	return	z_aabr_##type##_contains_point(object, segment.a) &&				\
		z_aabr_##type##_contains_point(object, segment.b);				\
	}											\
												\
												\
Z_INLINE zboolean z_aabr_##type##_contains_rectangle(						\
	ZAABR##Type	 object,								\
	ZRectangle##Type rectangle								\
)												\
	{											\
	return	object.a.x <= rectangle.point.x			   &&				\
		object.a.y <= rectangle.point.y			   &&				\
		object.b.x >= rectangle.point.x + rectangle.size.x &&				\
		object.b.y >= rectangle.point.y + rectangle.size.y;				\
	}											\
												\
												\
Z_INLINE zboolean z_aabr_##type##_contains_circle(ZAABR##Type object, ZCircle##Type circle)	\
	{											\
	return	circle.point.x - circle.radius >= object.a.x &&					\
		circle.point.y - circle.radius >= object.a.y &&					\
		circle.point.x + circle.radius <= object.b.x &&					\
		circle.point.y + circle.radius <= object.b.y;					\
	}


Z_IMPLEMENTATION_AABR(Float,   float,	Z_FLOAT  )
Z_IMPLEMENTATION_AABR(Double,  double,	Z_DOUBLE )
Z_IMPLEMENTATION_AABR(LDouble, ldouble, Z_LDOUBLE)


/* MARK: - Default real type definitions */

#define z_aabr_are_equal	      z_2d_line_are_equal
#define z_aabr_is_zero		      z_2d_line_is_zero
#define z_aabr_center		      z_2d_line_segment_center

#define z_aabr_contains		      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _contains	       )
#define z_aabr_collide		      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _collide	       )
#define z_aabr_intersection	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _intersection	       )
#define z_aabr_union		      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _union		       )
#define z_aabr_from_vertices	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _from_vertices	       )
#define z_aabr_size		      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _size		       )
#define z_aabr_area		      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _area		       )
#define z_aabr_middle_x		      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _middle_x	       )
#define z_aabr_middle_y		      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _middle_y	       )
#define z_aabr_top_left		      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _top_left	       )
#define z_aabr_top_right	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _top_right	       )
#define z_aabr_top_center	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _top_center	       )
#define z_aabr_bottom_left	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _bottom_left	       )
#define z_aabr_bottom_right	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _bottom_right	       )
#define z_aabr_bottom_center	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _bottom_center	       )
#define z_aabr_center_left	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _center_left	       )
#define z_aabr_center_right	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _center_right	       )
#define z_aabr_top_half		      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _top_half	       )
#define z_aabr_bottom_half	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _bottom_half	       )
#define z_aabr_left_half	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _left_half	       )
#define z_aabr_right_half	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _right_half	       )
#define z_aabr_top_left_quarter	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _top_left_quarter      )
#define z_aabr_top_right_quarter      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _top_right_quarter     )
#define z_aabr_bottom_left_quarter    Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _bottom_left_quarter   )
#define z_aabr_bottom_right_quarter   Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _bottom_right_quarter  )
#define z_aabr_align_in_top_left      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _align_in_top_left     )
#define z_aabr_align_in_top_right     Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _align_in_top_right    )
#define z_aabr_align_in_top_center    Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _align_in_top_center   )
#define z_aabr_align_in_bottom_left   Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _align_in_bottom_left  )
#define z_aabr_align_in_bottom_right  Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _align_in_bottom_right )
#define z_aabr_align_in_bottom_center Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _align_in_bottom_center)
#define z_aabr_align_in_center_left   Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _align_in_center_left  )
#define z_aabr_align_in_center_right  Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _align_in_center_right )
#define z_aabr_align_in_center	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _align_in_center       )
#define z_aabr_fit_in_top_left	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _fit_in_top_left       )
#define z_aabr_fit_in_top_right	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _fit_in_top_right      )
#define z_aabr_fit_in_top_center      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _fit_in_top_center     )
#define z_aabr_fit_in_bottom_left     Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _fit_in_bottom_left    )
#define z_aabr_fit_in_bottom_right    Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _fit_in_bottom_right   )
#define z_aabr_fit_in_bottom_center   Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _fit_in_bottom_center  )
#define z_aabr_fit_in_center_left     Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _fit_in_center_left    )
#define z_aabr_fit_in_center_right    Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _fit_in_center_right   )
#define z_aabr_fit_in_center	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _fit_in_center	       )
#define z_aabr_inner_circle	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _inner_circle	       )
#define z_aabr_to_rectangle	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _to_rectangle	       )
#define z_aabr_absolute_point_to_unit Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _absolute_point_to_unit)
#define z_aabr_unit_point_to_absolute Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _unit_point_to_absolute)
#define z_aabr_contains_point	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _contains_point	       )
#define z_aabr_contains_line_segment  Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _contains_line_segment )
#define z_aabr_contains_rectangle     Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _contains_rectangle    )
#define z_aabr_contains_circle	      Z_JOIN_3(z_aabr_, Z_REAL_FIXED_TYPE_name, _contains_circle       )

#endif /* __Z_functions_geometry_ZAABR_H__ */
