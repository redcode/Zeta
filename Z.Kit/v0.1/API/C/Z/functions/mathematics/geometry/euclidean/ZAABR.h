/* Z Kit C API - functions/mathematics/geometry/euclidean/ZAABR.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_mathematics_geometry_euclidean_ZAABR_H__
#define __Z_functions_mathematics_geometry_euclidean_ZAABR_H__

#include <Z/functions/mathematics/geometry/euclidean/Z2DLine.h>


/* MARK: - Implementation */


#define Z_IMPLEMENTATION_AABR(Type, type, _)							\
												\
												\
Z_INLINE zboolean z_aabr_##type##_collide(ZAABR##Type a, ZAABR##Type b)				\
	{return a.a.x < b.b.x && b.a.x < a.b.x && a.a.y < b.b.y && b.a.y < a.b.y;}		\
												\
												\
Z_INLINE zboolean z_aabr_##type##_contains(ZAABR##Type a, ZAABR##Type b)			\
	{return b.a.x >= a.a.x && b.a.y >= a.a.y && b.b.x <= a.b.x && b.b.y <= a.b.y;}		\
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
Z_INLINE Z2D##Type z_aabr_##type##_absolute_point_to_unit(ZAABR##Type object, Z2D##Type point)	\
	{											\
	return z_2d_##type									\
		((point.x - object.a.x) / (object.b.x - object.a.x),				\
		 (point.y - object.a.y) / (object.b.y - object.a.y));				\
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
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_center(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / _(2.0)) + size.x;	\
	object.b.y = (object.a.y += (object.b.y - object.a.y - size.y) / _(2.0)) + size.y;	\
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
Z_INLINE ZAABR##Type z_aabr_##type##_align_in_top_center(ZAABR##Type object, Z2D##Type size)	\
	{											\
	object.a.y = object.b.y - size.y;							\
	object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / _(2.0)) + size.x;	\
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
Z_INLINE Z2D##Type z_aabr_##type##_bottom_center(ZAABR##Type object)				\
	{return z_2d_##type((object.a.x + object.b.x) / _(2.0), object.a.y);}			\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_bottom_half(ZAABR##Type object)				\
	{											\
	object.b.y = (object.a.y + object.b.y) / _(2.0);					\
	return object;										\
	}											\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_bottom_left(ZAABR##Type object)				\
	{return object.a;}									\
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
Z_INLINE Z2D##Type z_aabr_##type##_bottom_right(ZAABR##Type object)				\
	{return z_2d_##type(object.b.x, object.a.y);}						\
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
Z_INLINE Z2D##Type z_aabr_##type##_center_left(ZAABR##Type object)				\
	{return z_2d_##type(object.a.x, (object.a.y + object.b.y) / _(2.0));}			\
												\
												\
Z_INLINE Z2D##Type z_aabr_##type##_center_right(ZAABR##Type object)				\
	{return z_2d_##type(object.b.x, (object.a.y + object.b.y) / _(2.0));}			\
												\
												\
Z_INLINE zboolean z_aabr_##type##_contains_circle(ZAABR##Type object, ZCircle##Type circle)	\
	{											\
	return	circle.point.x - circle.radius >= object.a.x &&					\
		circle.point.y - circle.radius >= object.a.y &&					\
		circle.point.x + circle.radius <= object.b.x &&					\
		circle.point.y + circle.radius <= object.b.y;					\
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
Z_INLINE ZAABR##Type z_aabr_##type##_left_half(ZAABR##Type object)				\
	{											\
	object.b.x = (object.a.x + object.b.x) / _(2.0);					\
	return object;										\
	}											\
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
Z_INLINE ZRectangle##Type z_aabr_##type##_rectangle(ZAABR##Type object)				\
	{											\
	return z_rectangle_##type								\
		(object.a.x, object.a.y, object.b.x - object.a.x, object.b.y - object.a.y);	\
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
Z_INLINE Z2D##Type z_aabr_##type##_top_center(ZAABR##Type object)				\
	{return z_2d_##type((object.a.x + object.b.x) / _(2.0), object.b.y);}			\
												\
												\
Z_INLINE ZAABR##Type z_aabr_##type##_top_half(ZAABR##Type object)				\
	{											\
	object.a.y = (object.a.y + object.b.y) / _(2.0);					\
	return object;										\
	}											\
Z_INLINE Z2D##Type z_aabr_##type##_top_left(ZAABR##Type object)					\
	{return z_2d_##type(object.a.x, object.b.y);}						\
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
Z_INLINE Z2D##Type z_aabr_##type##_top_right(ZAABR##Type object)				\
	{return object.b;}									\
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
Z_INLINE Z2D##Type z_aabr_##type##_unit_point_to_absolute(ZAABR##Type object, Z2D##Type point)	\
	{											\
	return z_2d_##type									\
		(point.x * (object.b.x - object.a.x) + object.a.x,				\
		 point.y * (object.b.y - object.a.y) + object.a.y);				\
	}


#define z_aabr_type_collide(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _collide		      )
#define z_aabr_type_contains(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _contains	      )
#define z_aabr_type_intersection(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _intersection	      )
#define z_aabr_type_union(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _union		      )
#define z_aabr_type_from_vertices(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _from_vertices	      )
#define z_aabr_type_area(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _area		      )
#define z_aabr_type_absolute_point_to_unit(TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _absolute_point_to_unit)
#define z_aabr_type_align_in_bottom_center(TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_bottom_center)
#define z_aabr_type_align_in_bottom_left(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_bottom_left  )
#define z_aabr_type_align_in_bottom_right( TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_bottom_right )
#define z_aabr_type_align_in_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_center	      )
#define z_aabr_type_align_in_center_left(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_center_left  )
#define z_aabr_type_align_in_center_right( TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_center_right )
#define z_aabr_type_align_in_top_center(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_top_center   )
#define z_aabr_type_align_in_top_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_top_left     )
#define z_aabr_type_align_in_top_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_top_right    )
#define z_aabr_type_bottom_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_center	      )
#define z_aabr_type_bottom_half(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_half	      )
#define z_aabr_type_bottom_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_left	      )
#define z_aabr_type_bottom_left_quarter(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_left_quarter   )
#define z_aabr_type_bottom_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_right	      )
#define z_aabr_type_bottom_right_quarter(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_right_quarter  )
#define z_aabr_type_center_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _center_left	      )
#define z_aabr_type_center_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _center_right	      )
#define z_aabr_type_contains_circle(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _contains_circle	      )
#define z_aabr_type_contains_line_segment( TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _contains_line_segment )
#define z_aabr_type_contains_point(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _contains_point	      )
#define z_aabr_type_contains_rectangle(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _contains_rectangle    )
#define z_aabr_type_fit_in_bottom_center(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_bottom_center  )
#define z_aabr_type_fit_in_bottom_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_bottom_left    )
#define z_aabr_type_fit_in_bottom_right(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_bottom_right   )
#define z_aabr_type_fit_in_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_center	      )
#define z_aabr_type_fit_in_center_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_center_left    )
#define z_aabr_type_fit_in_center_right(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_center_right   )
#define z_aabr_type_fit_in_top_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_top_center     )
#define z_aabr_type_fit_in_top_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_top_left	      )
#define z_aabr_type_fit_in_top_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_top_right      )
#define z_aabr_type_inner_circle(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _inner_circle	      )
#define z_aabr_type_left_half(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _left_half	      )
#define z_aabr_type_middle_x(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _middle_x	      )
#define z_aabr_type_middle_y(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _middle_y	      )
#define z_aabr_type_rectangle(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _rectangle	      )
#define z_aabr_type_right_half(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _right_half	      )
#define z_aabr_type_size(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _size		      )
#define z_aabr_type_top_center(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_center	      )
#define z_aabr_type_top_half(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_half	      )
#define z_aabr_type_top_left(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_left	      )
#define z_aabr_type_top_left_quarter(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_left_quarter      )
#define z_aabr_type_top_right(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_right	      )
#define z_aabr_type_top_right_quarter(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_right_quarter     )
#define z_aabr_type_unit_point_to_absolute(TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _unit_point_to_absolute)


/* MARK: - Implementation expansions */


#ifdef Z_FLOAT16

#	define z_aabr_float16_are_equal	z_2d_line_float16_are_equal
#	define z_aabr_float16_swap	z_2d_line_float16_swap
#	define z_aabr_float16_center	z_2d_line_segment_float16_center
#	define z_aabr_float16_is_zero	z_2d_line_float16_is_zero

	Z_IMPLEMENTATION_AABR(Float16, float16, Z_FLOAT16)

#endif

#ifdef Z_FLOAT24

#	define z_aabr_float24_are_equal	z_2d_line_float24_are_equal
#	define z_aabr_float24_swap	z_2d_line_float24_swap
#	define z_aabr_float24_center	z_2d_line_segment_float24_center
#	define z_aabr_float24_is_zero	z_2d_line_float24_is_zero

	Z_IMPLEMENTATION_AABR(Float24, float24, Z_FLOAT24)

#endif

#ifdef Z_FLOAT32

#	define z_aabr_float32_are_equal	z_2d_line_float32_are_equal
#	define z_aabr_float32_swap	z_2d_line_float32_swap
#	define z_aabr_float32_center	z_2d_line_segment_float32_center
#	define z_aabr_float32_is_zero	z_2d_line_float32_is_zero

	Z_IMPLEMENTATION_AABR(Float32, float32, Z_FLOAT32)

#endif

#ifdef Z_FLOAT48

#	define z_aabr_float48_are_equal	z_2d_line_float48_are_equal
#	define z_aabr_float48_swap	z_2d_line_float48_swap
#	define z_aabr_float48_center	z_2d_line_segment_float48_center
#	define z_aabr_float48_is_zero	z_2d_line_float48_is_zero

	Z_IMPLEMENTATION_AABR(Float48, float48, Z_FLOAT48)

#endif

#ifdef Z_FLOAT64

#	define z_aabr_float64_are_equal	z_2d_line_float64_are_equal
#	define z_aabr_float64_swap	z_2d_line_float64_swap
#	define z_aabr_float64_center	z_2d_line_segment_float64_center
#	define z_aabr_float64_is_zero	z_2d_line_float64_is_zero

	Z_IMPLEMENTATION_AABR(Float64, float64, Z_FLOAT64)

#endif

#ifdef Z_FLOAT72

#	define z_aabr_float72_are_equal	z_2d_line_float72_are_equal
#	define z_aabr_float72_swap	z_2d_line_float72_swap
#	define z_aabr_float72_center	z_2d_line_segment_float72_center
#	define z_aabr_float72_is_zero	z_2d_line_float72_is_zero

	Z_IMPLEMENTATION_AABR(Float72, float72, Z_FLOAT72)

#endif

#ifdef Z_FLOAT80

#	define z_aabr_float80_are_equal	z_2d_line_float80_are_equal
#	define z_aabr_float80_swap	z_2d_line_float80_swap
#	define z_aabr_float80_center	z_2d_line_segment_float80_center
#	define z_aabr_float80_is_zero	z_2d_line_float80_is_zero

	Z_IMPLEMENTATION_AABR(Float80, float80, Z_FLOAT80)

#endif

#ifdef Z_FLOAT96

#	define z_aabr_float96_are_equal	z_2d_line_float96_are_equal
#	define z_aabr_float96_swap	z_2d_line_float96_swap
#	define z_aabr_float96_center	z_2d_line_segment_float96_center
#	define z_aabr_float96_is_zero	z_2d_line_float96_is_zero

	Z_IMPLEMENTATION_AABR(Float96, float96, Z_FLOAT96)

#endif

#ifdef Z_FLOAT128

#	define z_aabr_float128_are_equal z_2d_line_float128_are_equal
#	define z_aabr_float128_swap	 z_2d_line_float128_swap
#	define z_aabr_float128_center	 z_2d_line_segment_float128_center
#	define z_aabr_float128_is_zero	 z_2d_line_float128_is_zero

	Z_IMPLEMENTATION_AABR(Float128, float128, Z_FLOAT128)

#endif


/* MARK: - Default real type definitions */


#ifdef Z_REAL

#	define z_aabr_are_equal z_2d_line_are_equal
#	define z_aabr_swap	z_2d_line_swap
#	define z_aabr_center	z_2d_line_segment_center
#	define z_aabr_is_zero	z_2d_line_is_zero

#	define z_aabr_collide		     z_aabr_type_collide	       (REAL)
#	define z_aabr_contains		     z_aabr_type_contains	       (REAL)
#	define z_aabr_intersection	     z_aabr_type_intersection	       (REAL)
#	define z_aabr_union		     z_aabr_type_union		       (REAL)
#	define z_aabr_from_vertices	     z_aabr_type_from_vertices	       (REAL)
#	define z_aabr_area		     z_aabr_type_area		       (REAL)
#	define z_aabr_absolute_point_to_unit z_aabr_type_absolute_point_to_unit(REAL)
#	define z_aabr_align_in_bottom_center z_aabr_type_align_in_bottom_center(REAL)
#	define z_aabr_align_in_bottom_left   z_aabr_type_align_in_bottom_left  (REAL)
#	define z_aabr_align_in_bottom_right  z_aabr_type_align_in_bottom_right (REAL)
#	define z_aabr_align_in_center	     z_aabr_type_align_in_center       (REAL)
#	define z_aabr_align_in_center_left   z_aabr_type_align_in_center_left  (REAL)
#	define z_aabr_align_in_center_right  z_aabr_type_align_in_center_right (REAL)
#	define z_aabr_align_in_top_center    z_aabr_type_align_in_top_center   (REAL)
#	define z_aabr_align_in_top_left	     z_aabr_type_align_in_top_left     (REAL)
#	define z_aabr_align_in_top_right     z_aabr_type_align_in_top_right    (REAL)
#	define z_aabr_bottom_center	     z_aabr_type_bottom_center	       (REAL)
#	define z_aabr_bottom_half	     z_aabr_type_bottom_half	       (REAL)
#	define z_aabr_bottom_left	     z_aabr_type_bottom_left	       (REAL)
#	define z_aabr_bottom_left_quarter    z_aabr_type_bottom_left_quarter   (REAL)
#	define z_aabr_bottom_right	     z_aabr_type_bottom_right	       (REAL)
#	define z_aabr_bottom_right_quarter   z_aabr_type_bottom_right_quarter  (REAL)
#	define z_aabr_center_left	     z_aabr_type_center_left	       (REAL)
#	define z_aabr_center_right	     z_aabr_type_center_right	       (REAL)
#	define z_aabr_contains_circle	     z_aabr_type_contains_circle       (REAL)
#	define z_aabr_contains_line_segment  z_aabr_type_contains_line_segment (REAL)
#	define z_aabr_contains_point	     z_aabr_type_contains_point	       (REAL)
#	define z_aabr_contains_rectangle     z_aabr_type_contains_rectangle    (REAL)
#	define z_aabr_fit_in_bottom_center   z_aabr_type_fit_in_bottom_center  (REAL)
#	define z_aabr_fit_in_bottom_left     z_aabr_type_fit_in_bottom_left    (REAL)
#	define z_aabr_fit_in_bottom_right    z_aabr_type_fit_in_bottom_right   (REAL)
#	define z_aabr_fit_in_center	     z_aabr_type_fit_in_center	       (REAL)
#	define z_aabr_fit_in_center_left     z_aabr_type_fit_in_center_left    (REAL)
#	define z_aabr_fit_in_center_right    z_aabr_type_fit_in_center_right   (REAL)
#	define z_aabr_fit_in_top_center	     z_aabr_type_fit_in_top_center     (REAL)
#	define z_aabr_fit_in_top_left	     z_aabr_type_fit_in_top_left       (REAL)
#	define z_aabr_fit_in_top_right	     z_aabr_type_fit_in_top_right      (REAL)
#	define z_aabr_inner_circle	     z_aabr_type_inner_circle	       (REAL)
#	define z_aabr_left_half		     z_aabr_type_left_half	       (REAL)
#	define z_aabr_middle_x		     z_aabr_type_middle_x	       (REAL)
#	define z_aabr_middle_y		     z_aabr_type_middle_y	       (REAL)
#	define z_aabr_rectangle		     z_aabr_type_rectangle	       (REAL)
#	define z_aabr_right_half	     z_aabr_type_right_half	       (REAL)
#	define z_aabr_size		     z_aabr_type_size		       (REAL)
#	define z_aabr_top_center	     z_aabr_type_top_center	       (REAL)
#	define z_aabr_top_half		     z_aabr_type_top_half	       (REAL)
#	define z_aabr_top_left		     z_aabr_type_top_left	       (REAL)
#	define z_aabr_top_left_quarter	     z_aabr_type_top_left_quarter      (REAL)
#	define z_aabr_top_right		     z_aabr_type_top_right	       (REAL)
#	define z_aabr_top_right_quarter	     z_aabr_type_top_right_quarter     (REAL)
#	define z_aabr_unit_point_to_absolute z_aabr_type_unit_point_to_absolute(REAL)

#endif


#endif /* __Z_functions_mathematics_geometry_euclidean_ZAABR_H__ */
