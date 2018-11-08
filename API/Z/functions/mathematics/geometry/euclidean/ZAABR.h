/* Z Kit - functions/mathematics/geometry/euclidean/ZAABR.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_mathematics_geometry_euclidean_ZAABR_H_
#define _Z_functions_mathematics_geometry_euclidean_ZAABR_H_

#include <Z/functions/mathematics/geometry/euclidean/Z2DLine.h>


/* MARK: - Common implementation */


#define Z_IMPLEMENTATION_COMMON(Type, type)							\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_align_in_bottom_center(ZAABR##Type object, Z2D##Type size)		\
	{											\
	object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / (z##type)2) + size.x;	\
	object.b.y = object.a.y + size.y;							\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_align_in_bottom_left(ZAABR##Type object, Z2D##Type size)		\
	{											\
	object.b.x = object.a.x + size.x;							\
	object.b.y = object.a.y + size.y;							\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_align_in_bottom_right(ZAABR##Type object, Z2D##Type size)		\
	{											\
	object.a.x = object.b.x - size.x;							\
	object.b.y = object.b.y + size.x;							\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_align_in_center(ZAABR##Type object, Z2D##Type size)			\
	{											\
	object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / (z##type)2) + size.x;	\
	object.b.y = (object.a.y += (object.b.y - object.a.y - size.y) / (z##type)2) + size.y;	\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_align_in_center_left(ZAABR##Type object, Z2D##Type size)		\
	{											\
	object.b.x = object.a.x + size.x;							\
	object.b.y = (object.a.y += (object.b.y - object.a.y - size.y) / (z##type)2) + size.y;	\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_align_in_center_right(ZAABR##Type object, Z2D##Type size)		\
	{											\
	object.a.x = object.b.x - size.x;							\
	object.b.y = (object.a.y += (object.b.y - object.a.y - size.y) / (z##type)2) + size.y;	\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_align_in_top_center(ZAABR##Type object, Z2D##Type size)		\
	{											\
	object.a.y = object.b.y - size.y;							\
	object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / (z##type)2) + size.x;	\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_align_in_top_left(ZAABR##Type object, Z2D##Type size)		\
	{											\
	object.a.y = object.b.y - size.y;							\
	object.b.x = object.a.x + size.x;							\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_align_in_top_right(ZAABR##Type object, Z2D##Type size)		\
	{											\
	object.a.x = object.b.x - size.x;							\
	object.a.y = object.b.y - size.y;							\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
z##type z_aabr_##type##_area(ZAABR##Type object)						\
	{return z_2d_##type##_inner_product(z_2d_##type##_subtract(object.b, object.a));}	\
												\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_bottom_center(ZAABR##Type object)					\
	{return z_2d_##type((object.a.x + object.b.x) / (z##type)2, object.a.y);}		\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_bottom_half(ZAABR##Type object)					\
	{											\
	object.b.y = (object.a.y + object.b.y) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_bottom_left(ZAABR##Type object)					\
	{return object.a;}									\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_bottom_left_quarter(ZAABR##Type object)				\
	{											\
	object.b.x = (object.a.x + object.b.x) / (z##type)2;					\
	object.b.y = (object.a.y + object.b.y) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_bottom_right(ZAABR##Type object)					\
	{return z_2d_##type(object.b.x, object.a.y);}						\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_bottom_right_quarter(ZAABR##Type object)				\
	{											\
	object.a.x = (object.a.x + object.b.x) / (z##type)2;					\
	object.b.y = (object.a.y + object.b.y) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_center_left(ZAABR##Type object)					\
	{return z_2d_##type(object.a.x, (object.a.y + object.b.y) / (z##type)2);}		\
												\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_center_right(ZAABR##Type object)					\
	{return z_2d_##type(object.b.x, (object.a.y + object.b.y) / (z##type)2);}		\
												\
												\
static Z_INLINE											\
zboolean z_aabr_##type##_contains(ZAABR##Type object, ZAABR##Type other)			\
	{											\
	return	other.a.x != other.b.x	&& other.a.y != other.b.y  &&				\
		other.a.x >= object.a.x && other.a.y >= object.a.y &&				\
		other.b.x <= object.b.x && other.b.y <= object.b.y;				\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_aabr_##type##_contains_point(ZAABR##Type object, Z2D##Type point)			\
	{											\
	return	point.x >= object.a.x && point.y >= object.a.y &&				\
		point.x <  object.b.x && point.y <  object.b.y;					\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_aabr_##type##_contains_rectangle(ZAABR##Type object, ZRectangle##Type rectangle)	\
	{											\
	return	rectangle.size.x		     != (z##type)0 &&				\
		rectangle.size.y		     != (z##type)0 &&				\
		rectangle.point.x		     >= object.a.x &&				\
		rectangle.point.y		     >= object.a.y &&				\
		rectangle.point.x + rectangle.size.x <= object.b.x &&				\
		rectangle.point.y + rectangle.size.y <= object.b.y;				\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_size(ZAABR##Type object)						\
	{return z_2d_##type##_subtract(object.b, object.a);}					\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_fit_in_bottom_center(ZAABR##Type object, Z2D##Type size)		\
	{											\
	Z2D##Type old_size = z_aabr_##type##_size(object);					\
												\
	object.b.y = object.a.y + (size = z_2d_##type##_fit(size, old_size)).y;			\
	object.b.x = (object.a.x += (old_size.x - size.x) / (z##type)2) + size.x;		\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_fit_in_bottom_left(ZAABR##Type object, Z2D##Type size)		\
	{											\
	object.b = z_2d_##type##_add								\
		(object.a, z_2d_##type##_fit(size, z_aabr_##type##_size(object)));		\
												\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_fit_in_bottom_right(ZAABR##Type object, Z2D##Type size)		\
	{											\
	size = z_2d_##type##_fit(size, z_aabr_##type##_size(object));				\
	return z_aabr_##type(object.b.x - size.x, object.a.y, object.b.x, object.a.y + size.y);	\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_fit_in_center(ZAABR##Type object, Z2D##Type size)			\
	{											\
	Z2D##Type old_size = z_aabr_##type##_size(object);					\
												\
	size = z_2d_##type##_fit(size, old_size);						\
	object.b.x = (object.a.x += (old_size.x - size.x) / (z##type)2) + size.x;		\
	object.b.y = (object.a.y += (old_size.y - size.y) / (z##type)2) + size.y;		\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_fit_in_center_left(ZAABR##Type object, Z2D##Type size)		\
	{											\
	Z2D##Type old_size = z_aabr_##type##_size(object);					\
												\
	object.b.x = object.a.x + (size = z_2d_##type##_fit(size, old_size)).x;			\
	object.b.y = (object.a.y += (old_size.y - size.y) / (z##type)2) + size.y;		\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_fit_in_center_right(ZAABR##Type object, Z2D##Type size)		\
	{											\
	Z2D##Type old_size = z_aabr_##type##_size(object);					\
												\
	object.a.x = object.b.x - (size = z_2d_##type##_fit(size, old_size)).x;			\
	object.b.y = (object.a.y += (old_size.y - size.y) / (z##type)2) + size.y;		\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_fit_in_top_center(ZAABR##Type object, Z2D##Type size)		\
	{											\
	Z2D##Type old_size = z_aabr_##type##_size(object);					\
												\
	object.a.y = object.b.y - (size = z_2d_##type##_fit(size, old_size)).y;			\
	object.b.x = (object.a.x += (old_size.x - size.x) / (z##type)2) + size.x;		\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_fit_in_top_left(ZAABR##Type object, Z2D##Type size)			\
	{											\
	size = z_2d_##type##_fit(size, z_aabr_##type##_size(object));				\
												\
	object.a.y = object.b.y - size.y;							\
	object.b.x = object.a.x + size.x;							\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_fit_in_top_right(ZAABR##Type object, Z2D##Type size)		\
	{											\
	object.a = z_2d_##type##_subtract							\
		(object.b, z_2d_##type##_fit(size, z_aabr_##type##_size(object)));		\
												\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_from_vertices(Z2D##Type a, Z2D##Type b)				\
	{											\
	ZAABR##Type result;									\
												\
	result.a = z_2d_##type##_minimum(a, b);							\
	result.b = z_2d_##type##_maximum(a, b);							\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_from_bottom_center(ZAABR##Type object, Z2D##Type delta)	\
	{											\
	z##type size_x = object.b.x - object.a.x;						\
												\
	object.b.x  = (object.a.x -= delta.x / (z##type)2) + size_x + delta.x;			\
	object.b.y += delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_from_bottom_left(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	object.b.x += delta.x;									\
	object.b.y += delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_from_bottom_right(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	object.a.x -= delta.x;									\
	object.b.y += delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_from_center(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	z##type size_x = object.b.x - object.a.x;						\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.b.x = (object.a.x -= delta.x / (z##type)2) + size_x + delta.x;			\
	object.b.y = (object.a.y -= delta.y / (z##type)2) + size_y + delta.y;			\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_from_center_left(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.b.x += delta.x;									\
	object.b.y  = (object.a.y -= delta.y / (z##type)2) + size_y + delta.y;			\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_from_center_right(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.a.x -= delta.x;									\
	object.b.y  = (object.a.y -= delta.y / (z##type)2) + size_y + delta.y;			\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_from_top_center(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	z##type size_x = object.b.x - object.a.x;						\
												\
	object.b.x  = (object.a.x -= delta.x / (z##type)2) + size_x + delta.x;			\
	object.a.y -= delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_from_top_left(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	object.b.x += delta.x;									\
	object.a.y -= delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_from_top_right(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	object.a.x -= delta.x;									\
	object.a.y -= delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_in_x_from_center(ZAABR##Type object, z##type delta)		\
	{											\
	z##type size_x = object.b.x - object.a.x;						\
												\
	object.b.x = (object.a.x -= delta / (z##type)2) + size_x + delta;			\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_in_x_from_left(ZAABR##Type object, z##type delta)		\
	{											\
	object.b.x += delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_in_x_from_right(ZAABR##Type object, z##type delta)		\
	{											\
	object.a.x -= delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_in_y_from_bottom(ZAABR##Type object, z##type delta)		\
	{											\
	object.b.y += delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_in_y_from_center(ZAABR##Type object, z##type delta)		\
	{											\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.b.y = (object.a.y -= delta / (z##type)2) + size_y + delta;			\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_grow_in_y_from_top(ZAABR##Type object, z##type delta)		\
	{											\
	object.a.y -= delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_aabr_##type##_intersect(ZAABR##Type a, ZAABR##Type b)				\
	{											\
	return	a.a.x != a.b.x && a.a.y != a.b.y && b.a.x != b.b.x && b.a.y != b.b.y &&		\
		b.b.x >  a.a.x && b.b.y >  a.a.y && b.a.x <  a.b.x && b.a.y <  a.b.y;		\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_intersection(ZAABR##Type a, ZAABR##Type b)				\
	{											\
	z##type x1, x2, y1, y2;									\
												\
	return	(x1 = z_##type##_maximum(a.a.x, b.a.x)) <					\
		(x2 = z_##type##_minimum(a.b.x, b.b.x)) &&					\
		(y1 = z_##type##_maximum(a.a.y, b.a.y))	<					\
		(y2 = z_##type##_minimum(a.b.y, b.b.y))						\
												\
		? z_aabr_##type(x1, y1, x2, y2)							\
		: z_aabr_##type##_zero;								\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_left_half(ZAABR##Type object)					\
	{											\
	object.b.x = (object.a.x + object.b.x) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
z##type z_aabr_##type##_maximum_x(ZAABR##Type object)						\
	{return object.b.x;}									\
												\
												\
static Z_INLINE											\
z##type z_aabr_##type##_maximum_y(ZAABR##Type object)						\
	{return object.b.y;}									\
												\
												\
static Z_INLINE											\
z##type z_aabr_##type##_middle_x(ZAABR##Type object)						\
	{return (object.a.x + object.b.x) / (z##type)2;}					\
												\
												\
static Z_INLINE											\
z##type z_aabr_##type##_middle_y(ZAABR##Type object)						\
	{return (object.a.y + object.b.y) / (z##type)2;}					\
												\
												\
static Z_INLINE											\
z##type z_aabr_##type##_minimum_x(ZAABR##Type object)						\
	{return object.a.x;}									\
												\
												\
static Z_INLINE											\
z##type z_aabr_##type##_minimum_y(ZAABR##Type object)						\
	{return object.a.y;}									\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_aabr_##type##_rectangle(ZAABR##Type object)					\
	{											\
	return z_rectangle_##type								\
		(object.a.x, object.a.y, object.b.x - object.a.x, object.b.y - object.a.y);	\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_right_half(ZAABR##Type object)					\
	{											\
	object.a.x = (object.a.x + object.b.x) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_from_bottom_center(ZAABR##Type object, Z2D##Type delta)	\
	{											\
	z##type size_x = object.b.x - object.a.x;						\
												\
	object.b.x  = (object.a.x += delta.x / (z##type)2) + size_x - delta.x;			\
	object.b.y -= delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_from_bottom_left(ZAABR##Type object, Z2D##Type delta)	\
	{											\
	object.b.x -= delta.x;									\
	object.b.y -= delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_from_bottom_right(ZAABR##Type object,Z2D##Type delta)	\
	{											\
	object.a.x += delta.x;									\
	object.b.y -= delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_from_center(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	z##type size_x = object.b.x - object.a.x;						\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.b.x = (object.a.x += delta.x / (z##type)2) + size_x - delta.x;			\
	object.b.y = (object.a.y += delta.y / (z##type)2) + size_y - delta.y;			\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_from_center_left(ZAABR##Type object, Z2D##Type delta)	\
	{											\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.b.x -= delta.x;									\
	object.b.y  = (object.a.y += delta.y / (z##type)2) + size_y - delta.y;			\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_from_center_right(ZAABR##Type object, Z2D##Type delta)	\
	{											\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.a.x += delta.x;									\
	object.b.y  = (object.a.y += delta.y / (z##type)2) + size_y - delta.y;			\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_from_top_center(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	z##type size_x = object.b.x - object.a.x;						\
												\
	object.b.x  = (object.a.x += delta.x / (z##type)2) + size_x - delta.x;			\
	object.a.y += delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_from_top_left(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	object.b.x -= delta.x;									\
	object.a.y += delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_from_top_right(ZAABR##Type object, Z2D##Type delta)		\
	{											\
	object.a.x += delta.x;									\
	object.a.y += delta.y;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_in_x_from_center(ZAABR##Type object, z##type delta)		\
	{											\
	z##type size_x = object.b.x - object.a.x;						\
												\
	object.b.x = (object.a.x += delta / (z##type)2) + size_x - delta;			\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_in_x_from_left(ZAABR##Type object, z##type delta)		\
	{											\
	object.b.x -= delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_in_x_from_right(ZAABR##Type object, z##type delta)		\
	{											\
	object.a.x += delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_in_y_from_bottom(ZAABR##Type object, z##type delta)		\
	{											\
	object.b.y -= delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_in_y_from_center(ZAABR##Type object, z##type delta)		\
	{											\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.b.y = (object.a.y += delta / (z##type)2) + size_y - delta;			\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_shrink_in_y_from_top(ZAABR##Type object, z##type delta)		\
	{											\
	object.a.y += delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_top_center(ZAABR##Type object)					\
	{return z_2d_##type((object.a.x + object.b.x) / (z##type)2, object.b.y);}		\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_top_half(ZAABR##Type object)					\
	{											\
	object.a.y = (object.a.y + object.b.y) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_top_left(ZAABR##Type object)						\
	{return z_2d_##type(object.a.x, object.b.y);}						\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_top_left_quarter(ZAABR##Type object)				\
	{											\
	object.b.x = (object.a.x + object.b.x) / (z##type)2;					\
	object.a.y = (object.a.y + object.b.y) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_top_right(ZAABR##Type object)						\
	{return object.b;}									\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_top_right_quarter(ZAABR##Type object)				\
	{											\
	object.a.x = (object.a.x + object.b.x) / (z##type)2;					\
	object.a.y = (object.a.y + object.b.y) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZAABR##Type z_aabr_##type##_union(ZAABR##Type a, ZAABR##Type b)					\
	{											\
	ZAABR##Type result;									\
												\
	result.a = z_2d_##type##_minimum(a.a, b.a);						\
	result.b = z_2d_##type##_maximum(a.b, b.b);						\
	return result;										\
	}


#define z_aabr_type_align_in_bottom_center(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_bottom_center   )
#define z_aabr_type_align_in_bottom_left(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_bottom_left	    )
#define z_aabr_type_align_in_bottom_right(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_bottom_right    )
#define z_aabr_type_align_in_center(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_center	    )
#define z_aabr_type_align_in_center_left(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_center_left	    )
#define z_aabr_type_align_in_center_right(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_center_right    )
#define z_aabr_type_align_in_top_center(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_top_center	    )
#define z_aabr_type_align_in_top_left(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_top_left	    )
#define z_aabr_type_align_in_top_right(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _align_in_top_right	    )
#define z_aabr_type_area(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _area			    )
#define z_aabr_type_bottom_center(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_center	    )
#define z_aabr_type_bottom_half(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_half		    )
#define z_aabr_type_bottom_left(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_left		    )
#define z_aabr_type_bottom_left_quarter(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_left_quarter	    )
#define z_aabr_type_bottom_right(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_right		    )
#define z_aabr_type_bottom_right_quarter(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _bottom_right_quarter	    )
#define z_aabr_type_center_left(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _center_left		    )
#define z_aabr_type_center_right(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _center_right		    )
#define z_aabr_type_contains(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _contains		    )
#define z_aabr_type_contains_point(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _contains_point	    )
#define z_aabr_type_contains_rectangle(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _contains_rectangle	    )
#define z_aabr_type_fit_in_bottom_center(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_bottom_center	    )
#define z_aabr_type_fit_in_bottom_left(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_bottom_left	    )
#define z_aabr_type_fit_in_bottom_right(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_bottom_right	    )
#define z_aabr_type_fit_in_center(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_center	    )
#define z_aabr_type_fit_in_center_left(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_center_left	    )
#define z_aabr_type_fit_in_center_right(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_center_right	    )
#define z_aabr_type_fit_in_top_center(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_top_center	    )
#define z_aabr_type_fit_in_top_left(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_top_left	    )
#define z_aabr_type_fit_in_top_right(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _fit_in_top_right	    )
#define z_aabr_type_from_vertices(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _from_vertices	    )
#define z_aabr_type_grow_from_bottom_center(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_from_bottom_center  )
#define z_aabr_type_grow_from_bottom_left(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_from_bottom_left    )
#define z_aabr_type_grow_from_bottom_right(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_from_bottom_right   )
#define z_aabr_type_grow_from_center(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_from_center	    )
#define z_aabr_type_grow_from_center_left(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_from_center_left    )
#define z_aabr_type_grow_from_center_right(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_from_center_right   )
#define z_aabr_type_grow_from_top_center(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_from_top_center	    )
#define z_aabr_type_grow_from_top_left(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_from_top_left	    )
#define z_aabr_type_grow_from_top_right(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_from_top_right	    )
#define z_aabr_type_grow_in_x_from_center(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_in_x_from_center    )
#define z_aabr_type_grow_in_x_from_left(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_in_x_from_left	    )
#define z_aabr_type_grow_in_x_from_right(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_in_x_from_right	    )
#define z_aabr_type_grow_in_y_from_bottom(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_in_y_from_bottom    )
#define z_aabr_type_grow_in_y_from_center(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_in_y_from_center    )
#define z_aabr_type_grow_in_y_from_top(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _grow_in_y_from_top	    )
#define z_aabr_type_intersect(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _intersect		    )
#define z_aabr_type_intersection(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _intersection		    )
#define z_aabr_type_left_half(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _left_half		    )
#define z_aabr_type_maximum_x(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _maximum_x		    )
#define z_aabr_type_maximum_y(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _maximum_y		    )
#define z_aabr_type_middle_x(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _middle_x		    )
#define z_aabr_type_middle_y(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _middle_y		    )
#define z_aabr_type_minimum_x(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _minimum_x		    )
#define z_aabr_type_minimum_y(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _minimum_y		    )
#define z_aabr_type_rectangle(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _rectangle		    )
#define z_aabr_type_right_half(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _right_half		    )
#define z_aabr_type_size(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _size			    )
#define z_abbr_type_shrink_from_bottom_center(TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_from_bottom_center)
#define z_abbr_type_shrink_from_bottom_left(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_from_bottom_left  )
#define z_abbr_type_shrink_from_bottom_right( TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_from_bottom_right )
#define z_abbr_type_shrink_from_center(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_from_center	    )
#define z_abbr_type_shrink_from_center_left(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_from_center_left  )
#define z_abbr_type_shrink_from_center_right( TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_from_center_right )
#define z_abbr_type_shrink_from_top_center(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_from_top_center   )
#define z_abbr_type_shrink_from_top_left(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_from_top_left	    )
#define z_abbr_type_shrink_from_top_right(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_from_top_right    )
#define z_abbr_type_shrink_in_x_from_center(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_in_x_from_center  )
#define z_abbr_type_shrink_in_x_from_left(    TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_in_x_from_left    )
#define z_abbr_type_shrink_in_x_from_right(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_in_x_from_right   )
#define z_abbr_type_shrink_in_y_from_bottom(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_in_y_from_bottom  )
#define z_abbr_type_shrink_in_y_from_center(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_in_y_from_center  )
#define z_abbr_type_shrink_in_y_from_top(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_abbr_, _shrink_in_y_from_top	    )
#define z_aabr_type_top_center(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_center		    )
#define z_aabr_type_top_half(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_half		    )
#define z_aabr_type_top_left(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_left		    )
#define z_aabr_type_top_left_quarter(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_left_quarter	    )
#define z_aabr_type_top_right(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_right		    )
#define z_aabr_type_top_right_quarter(	      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _top_right_quarter	    )
#define z_aabr_type_union(		      TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _union		    )


/* MARK: - Partial implementation for real types */


#define Z_IMPLEMENTATION_REAL(Type, type)							\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_absolute_point_to_unit(ZAABR##Type object, Z2D##Type point)		\
	{											\
	return z_2d_##type									\
		((point.x - object.a.x) / (object.b.x - object.a.x),				\
		 (point.y - object.a.y) / (object.b.y - object.a.y));				\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_aabr_##type##_contains_circle(ZAABR##Type object, ZCircle##Type circle)		\
	{											\
	return	circle.point.x - circle.radius >= object.a.x &&					\
		circle.point.y - circle.radius >= object.a.y &&					\
		circle.point.x + circle.radius <= object.b.x &&					\
		circle.point.y + circle.radius <= object.b.y;					\
	}											\
												\
												\
static Z_INLINE											\
ZCircle##Type z_aabr_##type##_inner_circle(ZAABR##Type object)					\
	{											\
	ZCircle##Type result;									\
												\
	result.point = z_aabr_##type##_center(object);						\
												\
	result.radius =										\
	z_2d_##type##_inner_minimum(z_2d_##type##_subtract(object.b, object.a)) / (z##type)2;	\
												\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_aabr_##type##_unit_point_to_absolute(ZAABR##Type object, Z2D##Type point)		\
	{											\
	return z_2d_##type									\
		(point.x * (object.b.x - object.a.x) + object.a.x,				\
		 point.y * (object.b.y - object.a.y) + object.a.y);				\
	}


#define z_aabr_type_absolute_point_to_unit(TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _absolute_point_to_unit)
#define z_aabr_type_contains_circle(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _contains_circle	      )
#define z_aabr_type_inner_circle(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _inner_circle	      )
#define z_aabr_type_unit_point_to_absolute(TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_, _unit_point_to_absolute)


/* MARK: - Implementation expansions */


#define z_aabr_sint8_are_equal z_2d_line_sint8_are_equal
#define z_aabr_sint8_center    z_2d_line_segment_sint8_center
#define z_aabr_sint8_is_zero   z_2d_line_sint8_is_zero
#define z_aabr_sint8_swap      z_2d_line_sint8_swap

Z_IMPLEMENTATION_COMMON(SInt8, sint8)

#define z_aabr_sint16_are_equal z_2d_line_sint16_are_equal
#define z_aabr_sint16_center	z_2d_line_segment_sint16_center
#define z_aabr_sint16_is_zero	z_2d_line_sint16_is_zero
#define z_aabr_sint16_swap	z_2d_line_sint16_swap

Z_IMPLEMENTATION_COMMON(SInt16, sint16)

#define z_aabr_sint32_are_equal z_2d_line_sint32_are_equal
#define z_aabr_sint32_center	z_2d_line_segment_sint32_center
#define z_aabr_sint32_is_zero	z_2d_line_sint32_is_zero
#define z_aabr_sint32_swap	z_2d_line_sint32_swap

Z_IMPLEMENTATION_COMMON(SInt32, sint32)

#ifdef Z_SINT64

#	define z_aabr_sint64_are_equal z_2d_line_sint64_are_equal
#	define z_aabr_sint64_center    z_2d_line_segment_sint64_center
#	define z_aabr_sint64_is_zero   z_2d_line_sint64_is_zero
#	define z_aabr_sint64_swap      z_2d_line_sint64_swap

	Z_IMPLEMENTATION_COMMON(SInt64, sint64)

#endif

#ifdef Z_SINT128

#	define z_aabr_sint128_are_equal z_2d_line_sint128_are_equal
#	define z_aabr_sint128_center	z_2d_line_segment_sint128_center
#	define z_aabr_sint128_is_zero	z_2d_line_sint128_is_zero
#	define z_aabr_sint128_swap	z_2d_line_sint128_swap

	Z_IMPLEMENTATION_COMMON(SInt128, sint128)

#endif

#ifdef Z_FLOAT16

#	define z_aabr_float16_are_equal	z_2d_line_float16_are_equal
#	define z_aabr_float16_center	z_2d_line_segment_float16_center
#	define z_aabr_float16_is_zero	z_2d_line_float16_is_zero
#	define z_aabr_float16_swap	z_2d_line_float16_swap

	Z_IMPLEMENTATION_COMMON(Float16, float16)
	Z_IMPLEMENTATION_REAL  (Float16, float16)

#endif

#ifdef Z_FLOAT32

#	define z_aabr_float32_are_equal	z_2d_line_float32_are_equal
#	define z_aabr_float32_center	z_2d_line_segment_float32_center
#	define z_aabr_float32_is_zero	z_2d_line_float32_is_zero
#	define z_aabr_float32_swap	z_2d_line_float32_swap

	Z_IMPLEMENTATION_COMMON(Float32, float32)
	Z_IMPLEMENTATION_REAL  (Float32, float32)

#endif

#ifdef Z_FLOAT64

#	define z_aabr_float64_are_equal	z_2d_line_float64_are_equal
#	define z_aabr_float64_center	z_2d_line_segment_float64_center
#	define z_aabr_float64_is_zero	z_2d_line_float64_is_zero
#	define z_aabr_float64_swap	z_2d_line_float64_swap

	Z_IMPLEMENTATION_COMMON(Float64, float64)
	Z_IMPLEMENTATION_REAL  (Float64, float64)

#endif

#ifdef Z_FLOAT128

#	define z_aabr_float128_are_equal z_2d_line_float128_are_equal
#	define z_aabr_float128_center	 z_2d_line_segment_float128_center
#	define z_aabr_float128_is_zero	 z_2d_line_float128_is_zero
#	define z_aabr_float128_swap	 z_2d_line_float128_swap

	Z_IMPLEMENTATION_COMMON(Float128, float128)
	Z_IMPLEMENTATION_REAL  (Float128, float128)

#endif

#ifdef Z_FLOAT80_X87

#	define z_aabr_float80_x87_are_equal z_2d_line_float80_x87_are_equal
#	define z_aabr_float80_x87_center    z_2d_line_segment_float80_x87_center
#	define z_aabr_float80_x87_is_zero   z_2d_line_float80_x87_is_zero
#	define z_aabr_float80_x87_swap	    z_2d_line_float80_x87_swap

	Z_IMPLEMENTATION_COMMON(Float80_x87, float80_x87)
	Z_IMPLEMENTATION_REAL  (Float80_x87, float80_x87)

#endif

#ifdef Z_FLOAT96_X87

#	define z_aabr_float96_x87_are_equal z_2d_line_float96_x87_are_equal
#	define z_aabr_float96_x87_center    z_2d_line_segment_float96_x87_center
#	define z_aabr_float96_x87_is_zero   z_2d_line_float96_x87_is_zero
#	define z_aabr_float96_x87_swap	    z_2d_line_float96_x87_swap

	Z_IMPLEMENTATION_COMMON(Float96_x87, float96_x87)
	Z_IMPLEMENTATION_REAL  (Float96_x87, float96_x87)

#endif

#ifdef Z_FLOAT128_X87

#	define z_aabr_float128_x87_are_equal z_2d_line_float128_x87_are_equal
#	define z_aabr_float128_x87_center    z_2d_line_segment_float128_x87_center
#	define z_aabr_float128_x87_is_zero   z_2d_line_float128_x87_is_zero
#	define z_aabr_float128_x87_swap	     z_2d_line_float128_x87_swap

	Z_IMPLEMENTATION_COMMON(Float128_x87, float128_x87)
	Z_IMPLEMENTATION_REAL  (Float128_x87, float128_x87)

#endif


/* MARK: - Cleanup */


#undef Z_IMPLEMENTATION_COMMON
#undef Z_IMPLEMENTATION_REAL


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_aabr_absolute_point_to_unit	z_aabr_type_absolute_point_to_unit   (REAL)
#	define z_aabr_align_in_bottom_center	z_aabr_type_align_in_bottom_center   (REAL)
#	define z_aabr_align_in_bottom_left	z_aabr_type_align_in_bottom_left     (REAL)
#	define z_aabr_align_in_bottom_right	z_aabr_type_align_in_bottom_right    (REAL)
#	define z_aabr_align_in_center		z_aabr_type_align_in_center	     (REAL)
#	define z_aabr_align_in_center_left	z_aabr_type_align_in_center_left     (REAL)
#	define z_aabr_align_in_center_right	z_aabr_type_align_in_center_right    (REAL)
#	define z_aabr_align_in_top_center	z_aabr_type_align_in_top_center	     (REAL)
#	define z_aabr_align_in_top_left		z_aabr_type_align_in_top_left	     (REAL)
#	define z_aabr_align_in_top_right	z_aabr_type_align_in_top_right	     (REAL)
#	define z_aabr_are_equal			z_2d_line_are_equal
#	define z_aabr_area			z_aabr_type_area		     (REAL)
#	define z_aabr_bottom_center		z_aabr_type_bottom_center	     (REAL)
#	define z_aabr_bottom_half		z_aabr_type_bottom_half		     (REAL)
#	define z_aabr_bottom_left		z_aabr_type_bottom_left		     (REAL)
#	define z_aabr_bottom_left_quarter	z_aabr_type_bottom_left_quarter	     (REAL)
#	define z_aabr_bottom_right		z_aabr_type_bottom_right	     (REAL)
#	define z_aabr_bottom_right_quarter	z_aabr_type_bottom_right_quarter     (REAL)
#	define z_aabr_center			z_2d_line_segment_center
#	define z_aabr_center_left		z_aabr_type_center_left		     (REAL)
#	define z_aabr_center_right		z_aabr_type_center_right	     (REAL)
#	define z_aabr_contains			z_aabr_type_contains		     (REAL)
#	define z_aabr_contains_circle		z_aabr_type_contains_circle	     (REAL)
#	define z_aabr_contains_point		z_aabr_type_contains_point	     (REAL)
#	define z_aabr_contains_rectangle	z_aabr_type_contains_rectangle	     (REAL)
#	define z_aabr_fit_in_bottom_center	z_aabr_type_fit_in_bottom_center     (REAL)
#	define z_aabr_fit_in_bottom_left	z_aabr_type_fit_in_bottom_left	     (REAL)
#	define z_aabr_fit_in_bottom_right	z_aabr_type_fit_in_bottom_right	     (REAL)
#	define z_aabr_fit_in_center		z_aabr_type_fit_in_center	     (REAL)
#	define z_aabr_fit_in_center_left	z_aabr_type_fit_in_center_left	     (REAL)
#	define z_aabr_fit_in_center_right	z_aabr_type_fit_in_center_right	     (REAL)
#	define z_aabr_fit_in_top_center		z_aabr_type_fit_in_top_center	     (REAL)
#	define z_aabr_fit_in_top_left		z_aabr_type_fit_in_top_left	     (REAL)
#	define z_aabr_fit_in_top_right		z_aabr_type_fit_in_top_right	     (REAL)
#	define z_aabr_from_vertices		z_aabr_type_from_vertices	     (REAL)
#	define z_aabr_grow_from_bottom_center	z_aabr_type_grow_from_bottom_center  (REAL)
#	define z_aabr_grow_from_bottom_left	z_aabr_type_grow_from_bottom_left    (REAL)
#	define z_aabr_grow_from_bottom_right	z_aabr_type_grow_from_bottom_right   (REAL)
#	define z_aabr_grow_from_center		z_aabr_type_grow_from_center	     (REAL)
#	define z_aabr_grow_from_center_left	z_aabr_type_grow_from_center_left    (REAL)
#	define z_aabr_grow_from_center_right	z_aabr_type_grow_from_center_right   (REAL)
#	define z_aabr_grow_from_top_center	z_aabr_type_grow_from_top_center     (REAL)
#	define z_aabr_grow_from_top_left	z_aabr_type_grow_from_top_left	     (REAL)
#	define z_aabr_grow_from_top_right	z_aabr_type_grow_from_top_right	     (REAL)
#	define z_aabr_grow_in_x_from_center	z_aabr_type_grow_in_x_from_center    (REAL)
#	define z_aabr_grow_in_x_from_left	z_aabr_type_grow_in_x_from_left	     (REAL)
#	define z_aabr_grow_in_x_from_right	z_aabr_type_grow_in_x_from_right     (REAL)
#	define z_aabr_grow_in_y_from_bottom	z_aabr_type_grow_in_y_from_bottom    (REAL)
#	define z_aabr_grow_in_y_from_center	z_aabr_type_grow_in_y_from_center    (REAL)
#	define z_aabr_grow_in_y_from_top	z_aabr_type_grow_in_y_from_top	     (REAL)
#	define z_aabr_inner_circle		z_aabr_type_inner_circle	     (REAL)
#	define z_aabr_intersect			z_aabr_type_intersect		     (REAL)
#	define z_aabr_intersection		z_aabr_type_intersection	     (REAL)
#	define z_aabr_is_zero			z_2d_line_is_zero
#	define z_aabr_left_half			z_aabr_type_left_half		     (REAL)
#	define z_aabr_maximum_x			z_aabr_type_maximum_x		     (REAL)
#	define z_aabr_maximum_y			z_aabr_type_maximum_y		     (REAL)
#	define z_aabr_middle_x			z_aabr_type_middle_x		     (REAL)
#	define z_aabr_middle_y			z_aabr_type_middle_y		     (REAL)
#	define z_aabr_minimum_x			z_aabr_type_minimum_x		     (REAL)
#	define z_aabr_minimum_y			z_aabr_type_minimum_y		     (REAL)
#	define z_aabr_rectangle			z_aabr_type_rectangle		     (REAL)
#	define z_aabr_right_half		z_aabr_type_right_half		     (REAL)
#	define z_aabr_size			z_aabr_type_size		     (REAL)
#	define z_abbr_shrink_from_bottom_center	z_abbr_type_shrink_from_bottom_center(REAL)
#	define z_abbr_shrink_from_bottom_left	z_abbr_type_shrink_from_bottom_left  (REAL)
#	define z_abbr_shrink_from_bottom_right	z_abbr_type_shrink_from_bottom_right (REAL)
#	define z_abbr_shrink_from_center	z_abbr_type_shrink_from_center	     (REAL)
#	define z_abbr_shrink_from_center_left	z_abbr_type_shrink_from_center_left  (REAL)
#	define z_abbr_shrink_from_center_right	z_abbr_type_shrink_from_center_right (REAL)
#	define z_abbr_shrink_from_top_center	z_abbr_type_shrink_from_top_center   (REAL)
#	define z_abbr_shrink_from_top_left	z_abbr_type_shrink_from_top_left     (REAL)
#	define z_abbr_shrink_from_top_right	z_abbr_type_shrink_from_top_right    (REAL)
#	define z_abbr_shrink_in_x_from_center	z_abbr_type_shrink_in_x_from_center  (REAL)
#	define z_abbr_shrink_in_x_from_left	z_abbr_type_shrink_in_x_from_left    (REAL)
#	define z_abbr_shrink_in_x_from_right	z_abbr_type_shrink_in_x_from_right   (REAL)
#	define z_abbr_shrink_in_y_from_bottom	z_abbr_type_shrink_in_y_from_bottom  (REAL)
#	define z_abbr_shrink_in_y_from_center	z_abbr_type_shrink_in_y_from_center  (REAL)
#	define z_abbr_shrink_in_y_from_top	z_abbr_type_shrink_in_y_from_top     (REAL)
#	define z_aabr_swap			z_2d_line_swap
#	define z_aabr_top_center		z_aabr_type_top_center		     (REAL)
#	define z_aabr_top_half			z_aabr_type_top_half		     (REAL)
#	define z_aabr_top_left			z_aabr_type_top_left		     (REAL)
#	define z_aabr_top_left_quarter		z_aabr_type_top_left_quarter	     (REAL)
#	define z_aabr_top_right			z_aabr_type_top_right		     (REAL)
#	define z_aabr_top_right_quarter		z_aabr_type_top_right_quarter	     (REAL)
#	define z_aabr_union			z_aabr_type_union		     (REAL)
#	define z_aabr_unit_point_to_absolute	z_aabr_type_unit_point_to_absolute   (REAL)
#endif


#endif /* _Z_functions_mathematics_geometry_euclidean_ZAABR_H_ */
