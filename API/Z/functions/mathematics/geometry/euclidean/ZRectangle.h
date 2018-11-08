/* Z Kit - functions/mathematics/geometry/euclidean/ZRectangle.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_mathematics_geometry_euclidean_ZRectangle_H_
#define _Z_functions_mathematics_geometry_euclidean_ZRectangle_H_

#include <Z/functions/mathematics/geometry/euclidean/constructors.h>
#include <Z/functions/base/Z2D.h>


/* MARK: - Common implementation */


#define Z_IMPLEMENTATION_COMMON(Type, type)							\
												\
static Z_INLINE											\
ZAABR##Type z_rectangle_##type##_aabr(ZRectangle##Type object)					\
	{											\
	return z_aabr_##type									\
		(object.point.x, object.point.y,						\
		 object.point.x + object.size.x, object.point.y + object.size.y);		\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_align_in_bottom_center(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.x += (object.size.x - size.x) / (z##type)2;				\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_align_in_bottom_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.size = size;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_align_in_bottom_right(					\
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
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_align_in_center(ZRectangle##Type object, Z2D##Type size)	\
	{											\
	object.point.x += (object.size.x - size.x) / (z##type)2;				\
	object.point.y += (object.size.y - size.y) / (z##type)2;				\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_align_in_center_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.y += (object.size.y - size.y) / (z##type)2;				\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_align_in_center_right(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.x +=  object.size.x - size.x;						\
	object.point.y += (object.size.y - size.y) / (z##type)2;				\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_align_in_top_center(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.point.x += (object.size.x - size.x) / (z##type)2;				\
	object.point.y +=  object.size.y - size.y;						\
	object.size	= size;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_align_in_top_left(					\
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
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_align_in_top_right(					\
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
static Z_INLINE											\
zboolean z_rectangle_##type##_are_equal(ZRectangle##Type a, ZRectangle##Type b)			\
	{											\
	return	z_2d_##type##_are_equal(a.point, b.point) &&					\
		z_2d_##type##_are_equal(a.size,	 b.size );					\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_bottom_center(ZRectangle##Type object)				\
	{return z_2d_##type(object.point.x + object.size.x / (z##type)2, object.point.y);}	\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_bottom_half(ZRectangle##Type object)			\
	{											\
	object.size.y /= (z##type)2;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_bottom_left(ZRectangle##Type object)				\
	{return object.point;}									\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_bottom_left_quarter(ZRectangle##Type object)		\
	{											\
	object.size.x /= (z##type)2;								\
	object.size.y /= (z##type)2;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_bottom_right(ZRectangle##Type object)				\
	{return z_2d_##type(object.point.x + object.size.x, object.point.y);}			\
												\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_center(ZRectangle##Type object)					\
	{											\
	return z_2d_##type									\
		(object.point.x + object.size.x / (z##type)2,					\
		 object.point.y + object.size.y / (z##type)2);					\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_center_left(ZRectangle##Type object)				\
	{return z_2d_##type(object.point.x, object.point.y + object.size.y / (z##type)2);}	\
												\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_center_right(ZRectangle##Type object)				\
	{											\
	return z_2d_##type									\
		(object.point.x + object.size.x, object.point.y + object.size.y / (z##type)2);	\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_rectangle_##type##_contains(ZRectangle##Type object, ZRectangle##Type other)		\
	{											\
	return	other.size.x		     != (z##type)0		       &&		\
		other.size.y		     != (z##type)0		       &&		\
		other.point.x		     >= object.point.x		       &&		\
		other.point.y		     >= object.point.y		       &&		\
		other.point.x + other.size.x <= object.point.x + object.size.x &&		\
		other.point.y + other.size.y <= object.point.y + object.size.y;			\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_rectangle_##type##_contains_aabr(ZRectangle##Type object, ZAABR##Type aabr)		\
	{											\
	return	aabr.a.x != aabr.b.x			   &&					\
		aabr.a.y != aabr.b.y			   &&					\
		aabr.a.x >= object.point.x		   &&					\
		aabr.a.y >= object.point.y		   &&					\
		aabr.b.x <= object.point.x + object.size.x &&					\
		aabr.b.y <= object.point.y + object.size.y;					\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_rectangle_##type##_contains_point(ZRectangle##Type object, Z2D##Type point)		\
	{											\
	return	point.x >= object.point.x		  &&					\
		point.y >= object.point.y		  &&					\
		point.x <  object.point.x + object.size.x &&					\
		point.y <  object.point.y + object.size.y;					\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_correct(ZRectangle##Type object)				\
	{											\
	if (object.size.x < (z##type)0) object.point.x -= (object.size.x = -object.size.x);	\
	if (object.size.y < (z##type)0) object.point.y -= (object.size.y = -object.size.y);	\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_fit_in_bottom_center(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + (object.size.x - result.size.x) / (z##type)2;		\
	result.point.y = object.point.y;							\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_fit_in_bottom_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	object.size = z_2d_##type##_fit(size, object.size);					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_fit_in_bottom_right(					\
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
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_fit_in_center(ZRectangle##Type object, Z2D##Type size)	\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + (object.size.x - result.size.x) / (z##type)2;		\
	result.point.y = object.point.y + (object.size.y - result.size.y) / (z##type)2;		\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_fit_in_center_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x;							\
	result.point.y = object.point.y + (object.size.y - result.size.y) / (z##type)2;		\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_fit_in_center_right(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + object.size.x - result.size.x;			\
	result.point.y = object.point.y + (object.size.y - result.size.y) / (z##type)2;		\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_fit_in_top_center(					\
	ZRectangle##Type object,								\
	Z2D##Type	 size									\
)												\
	{											\
	ZRectangle##Type result;								\
												\
	result.size    = z_2d_##type##_fit(size, object.size);					\
	result.point.x = object.point.x + (object.size.x - result.size.x) / (z##type)2;		\
	result.point.y = object.point.y + object.size.y - result.size.y;			\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_fit_in_top_left(ZRectangle##Type object, Z2D##Type size)	\
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
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_fit_in_top_right(ZRectangle##Type object, Z2D##Type size)	\
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
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_from_vertices(Z2D##Type a, Z2D##Type b)			\
	{											\
	Z2D##Type minimum = z_2d_##type##_minimum(a, b);					\
												\
	return z_rectangle_##type								\
		(minimum.x,  minimum.y,								\
		 z_##type##_maximum(a.x, b.x) - minimum.x,					\
		 z_##type##_maximum(a.y, b.y) - minimum.y);					\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_from_bottom_center(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x -= delta.x / (z##type)2;							\
	object.size.x  += delta.x;								\
	object.size.y  += delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_from_bottom_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.size.x += delta.x;								\
	object.size.y += delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_from_bottom_right(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x -= delta.x;								\
	object.size.x  += delta.x;								\
	object.size.y  += delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_from_center(						\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x -= delta.x / (z##type)2;							\
	object.point.y -= delta.y / (z##type)2;							\
	object.size.x  += delta.x;								\
	object.size.y  += delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_from_center_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.y -= delta.y / (z##type)2;							\
	object.size.x  += delta.x;								\
	object.size.y  += delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_from_center_right(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x -= delta.x;								\
	object.point.y -= delta.y / (z##type)2;							\
	object.size.x  += delta.x;								\
	object.size.y  += delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_from_top_center(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x -= delta.x / (z##type)2;							\
	object.point.y -= delta.y;								\
	object.size.x  += delta.x;								\
	object.size.y  += delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_from_top_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.y -= delta.y;								\
	object.size.x  += delta.x;								\
	object.size.y  += delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_from_top_right(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x -= delta.x;								\
	object.point.y -= delta.y;								\
	object.size.x  += delta.x;								\
	object.size.y  += delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_in_x_from_center(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.point.x -= delta / (z##type)2;							\
	object.size.x  += delta;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_in_x_from_left(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.size.x += delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_in_x_from_right(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.point.x -= delta;								\
	object.size.x  += delta;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_in_y_from_bottom(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.size.y += delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_in_y_from_center(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.point.y -= delta / (z##type)2;							\
	object.size.y  += delta;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_grow_in_y_from_top(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.point.y -= delta;								\
	object.size.y  += delta;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_rectangle_##type##_intersect(ZRectangle##Type a, ZRectangle##Type b)			\
	{											\
	return	a.size.x	     != (z##type)0	     &&					\
		a.size.y	     != (z##type)0	     &&					\
		b.size.x	     != (z##type)0	     &&					\
		b.size.y	     != (z##type)0	     &&					\
		b.point.x + b.size.x >	a.point.x	     &&					\
		b.point.y + b.size.y >	a.point.y	     &&					\
		b.point.x	     <	a.point.x + a.size.x &&					\
		b.point.y	     <	a.point.y + a.size.y;					\
	}											\
												\
												\
static Z_INLINE ZRectangle##Type z_rectangle_##type##_intersection(				\
	ZRectangle##Type a,									\
	ZRectangle##Type b									\
)												\
	{											\
	z##type x1, x2, y1, y2;									\
												\
	return	(x1 = z_##type##_maximum(a.point.x,	       b.point.x)) <			\
		(x2 = z_##type##_minimum(a.point.x + a.size.x, b.point.x + b.size.x)) &&	\
		(y1 = z_##type##_maximum(a.point.y,	       b.point.y)) <			\
		(y2 = z_##type##_minimum(a.point.y + a.size.y, b.point.y + b.size.y))		\
												\
		? z_rectangle_##type(x1, y1, x2 - x1, y2 - y1)					\
		: z_rectangle_##type##_zero;							\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_rectangle_##type##_is_zero(ZRectangle##Type object)					\
	{return z_2d_##type##_is_zero(object.point) && z_2d_##type##_is_zero(object.size);}	\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_left_half(ZRectangle##Type object)			\
	{											\
	object.size.x /= (z##type)2;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
z##type z_rectangle_##type##_maximum_x(ZRectangle##Type object)					\
	{return object.point.x + object.size.x;}						\
												\
												\
static Z_INLINE											\
z##type z_rectangle_##type##_maximum_y(ZRectangle##Type object)					\
	{return object.point.y + object.size.y;}						\
												\
												\
static Z_INLINE											\
z##type z_rectangle_##type##_middle_x(ZRectangle##Type object)					\
	{return object.point.x + object.size.x / (z##type)2;}					\
												\
												\
static Z_INLINE											\
z##type z_rectangle_##type##_middle_y(ZRectangle##Type object)					\
	{return object.point.y + object.size.y / (z##type)2;}					\
												\
												\
static Z_INLINE											\
z##type z_rectangle_##type##_minimum_x(ZRectangle##Type object)					\
	{return object.point.x;}								\
												\
												\
static Z_INLINE											\
z##type z_rectangle_##type##_minimum_y(ZRectangle##Type object)					\
	{return object.point.y;}								\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_from_bottom_center(				\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x += delta.x / (z##type)2;							\
	object.size.x  -= delta.x;								\
	object.size.y  -= delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_from_bottom_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.size.x -= delta.x;								\
	object.size.y -= delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_from_bottom_right(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x += delta.x;								\
	object.size.x  -= delta.x;								\
	object.size.y  -= delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_from_center(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x += delta.x / (z##type)2;							\
	object.point.y += delta.y / (z##type)2;							\
	object.size.x  -= delta.x;								\
	object.size.y  -= delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_from_center_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.y += delta.y / (z##type)2;							\
	object.size.x  -= delta.x;								\
	object.size.y  -= delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_from_center_right(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x += delta.x;								\
	object.point.y += delta.y / (z##type)2;							\
	object.size.x  -= delta.x;								\
	object.size.y  -= delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_from_top_center(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x += delta.x / (z##type)2;							\
	object.point.y += delta.y;								\
	object.size.x  -= delta.x;								\
	object.size.y  -= delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_from_top_left(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.y += delta.y;								\
	object.size.x  -= delta.x;								\
	object.size.y  -= delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_from_top_right(					\
	ZRectangle##Type object,								\
	Z2D##Type	 delta									\
)												\
	{											\
	object.point.x += delta.x;								\
	object.point.y += delta.y;								\
	object.size.x  -= delta.x;								\
	object.size.y  -= delta.y;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_in_x_from_center(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.point.x += delta / (z##type)2;							\
	object.size.x  -= delta;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_in_x_from_left(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.size.x -= delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_in_x_from_right(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.point.x += delta;								\
	object.size.x  -= delta;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_in_y_from_bottom(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.size.y -= delta;									\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_in_y_from_center(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.point.y += delta / (z##type)2;							\
	object.size.y  -= delta;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_shrink_in_y_from_top(					\
	ZRectangle##Type object,								\
	z##type		 delta									\
)												\
	{											\
	object.point.y += delta;								\
	object.size.y  -= delta;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
void z_rectangle_##type##_swap(ZRectangle##Type *a, ZRectangle##Type *b)			\
	{											\
	ZRectangle##Type t = *a;								\
												\
	*a = *b; *b = t;									\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_top_center(ZRectangle##Type object)				\
	{											\
	return z_2d_##type									\
		(object.point.x + object.size.x / (z##type)2, object.point.y + object.size.y);	\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_top_left(ZRectangle##Type object)				\
	{return z_2d_##type(object.point.x, object.point.y + object.size.y);}			\
												\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_top_right(ZRectangle##Type object)				\
	{return z_2d_##type(object.point.x + object.size.x, object.point.y + object.size.y);}	\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_union(ZRectangle##Type a, ZRectangle##Type b)		\
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
	}


#define z_rectangle_type_aabr(			   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _aabr		      )
#define z_rectangle_type_align_in_bottom_center(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _align_in_bottom_center   )
#define z_rectangle_type_align_in_bottom_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _align_in_bottom_left     )
#define z_rectangle_type_align_in_bottom_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _align_in_bottom_right    )
#define z_rectangle_type_align_in_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _align_in_center	      )
#define z_rectangle_type_align_in_center_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _align_in_center_left     )
#define z_rectangle_type_align_in_center_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _align_in_center_right    )
#define z_rectangle_type_align_in_top_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _align_in_top_center      )
#define z_rectangle_type_align_in_top_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _align_in_top_left	      )
#define z_rectangle_type_align_in_top_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _align_in_top_right	      )
#define z_rectangle_type_are_equal(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _are_equal		      )
#define z_rectangle_type_bottom_center(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _bottom_center	      )
#define z_rectangle_type_bottom_half(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _bottom_half	      )
#define z_rectangle_type_bottom_left(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _bottom_left	      )
#define z_rectangle_type_bottom_left_quarter(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _bottom_left_quarter      )
#define z_rectangle_type_bottom_right(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _bottom_right	      )
#define z_rectangle_type_center(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _center		      )
#define z_rectangle_type_center_left(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _center_left	      )
#define z_rectangle_type_center_right(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _center_right	      )
#define z_rectangle_type_contains(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _contains		      )
#define z_rectangle_type_contains_aabr(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _contains_aabr	      )
#define z_rectangle_type_contains_point(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _contains_point	      )
#define z_rectangle_type_correct(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _correct		      )
#define z_rectangle_type_fit_in_bottom_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _fit_in_bottom_center     )
#define z_rectangle_type_fit_in_bottom_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _fit_in_bottom_left	      )
#define z_rectangle_type_fit_in_bottom_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _fit_in_bottom_right      )
#define z_rectangle_type_fit_in_center(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _fit_in_center	      )
#define z_rectangle_type_fit_in_center_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _fit_in_center_left	      )
#define z_rectangle_type_fit_in_center_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _fit_in_center_right      )
#define z_rectangle_type_fit_in_top_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _fit_in_top_center	      )
#define z_rectangle_type_fit_in_top_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _fit_in_top_left	      )
#define z_rectangle_type_fit_in_top_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _fit_in_top_right	      )
#define z_rectangle_type_from_vertices(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _from_vertices	      )
#define z_rectangle_type_grow_from_bottom_center(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_from_bottom_center  )
#define z_rectangle_type_grow_from_bottom_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_from_bottom_left    )
#define z_rectangle_type_grow_from_bottom_right(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_from_bottom_right   )
#define z_rectangle_type_grow_from_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_from_center	      )
#define z_rectangle_type_grow_from_center_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_from_center_left    )
#define z_rectangle_type_grow_from_center_right(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_from_center_right   )
#define z_rectangle_type_grow_from_top_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_from_top_center     )
#define z_rectangle_type_grow_from_top_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_from_top_left	      )
#define z_rectangle_type_grow_from_top_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_from_top_right      )
#define z_rectangle_type_grow_in_x_from_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_in_x_from_center    )
#define z_rectangle_type_grow_in_x_from_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_in_x_from_left      )
#define z_rectangle_type_grow_in_x_from_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_in_x_from_right     )
#define z_rectangle_type_grow_in_y_from_bottom(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_in_y_from_bottom    )
#define z_rectangle_type_grow_in_y_from_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_in_y_from_center    )
#define z_rectangle_type_grow_in_y_from_top(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _grow_in_y_from_top	      )
#define z_rectangle_type_intersect(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _intersect		      )
#define z_rectangle_type_intersection(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _intersection	      )
#define z_rectangle_type_is_zero(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _is_zero		      )
#define z_rectangle_type_left_half(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _left_half		      )
#define z_rectangle_type_maximum_x(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _maximum_x		      )
#define z_rectangle_type_maximum_y(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _maximum_y		      )
#define z_rectangle_type_middle_x(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _middle_x		      )
#define z_rectangle_type_middle_y(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _middle_y		      )
#define z_rectangle_type_minimum_x(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _minimum_x		      )
#define z_rectangle_type_minimum_y(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _minimum_y		      )
#define z_rectangle_type_shrink_from_bottom_center(TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_from_bottom_center)
#define z_rectangle_type_shrink_from_bottom_left(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_from_bottom_left  )
#define z_rectangle_type_shrink_from_bottom_right( TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_from_bottom_right )
#define z_rectangle_type_shrink_from_center(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_from_center	      )
#define z_rectangle_type_shrink_from_center_left(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_from_center_left  )
#define z_rectangle_type_shrink_from_center_right( TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_from_center_right )
#define z_rectangle_type_shrink_from_top_center(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_from_top_center   )
#define z_rectangle_type_shrink_from_top_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_from_top_left     )
#define z_rectangle_type_shrink_from_top_right(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_from_top_right    )
#define z_rectangle_type_shrink_in_x_from_center(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_in_x_from_center  )
#define z_rectangle_type_shrink_in_x_from_left(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_in_x_from_left    )
#define z_rectangle_type_shrink_in_x_from_right(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_in_x_from_right   )
#define z_rectangle_type_shrink_in_y_from_bottom(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_in_y_from_bottom  )
#define z_rectangle_type_shrink_in_y_from_center(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_in_y_from_center  )
#define z_rectangle_type_shrink_in_y_from_top(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _shrink_in_y_from_top     )
#define z_rectangle_type_swap(			   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _swap		      )
#define z_rectangle_type_top_center(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _top_center		      )
#define z_rectangle_type_top_left(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _top_left		      )
#define z_rectangle_type_top_right(		   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _top_right		      )
#define z_rectangle_type_union(			   TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _union		      )


/* MARK: - Partial implementation for integer types */


#define Z_IMPLEMENTATION_INTEGER(Type, type)							\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_bottom_right_quarter(ZRectangle##Type object)		\
	{											\
	object.point.x += object.size.x / (z##type)2;						\
	object.size.x	= object.size.x - object.size.x / (z##type)2;				\
	object.size.y  /= (z##type)2;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_right_half(ZRectangle##Type object)			\
	{											\
	object.point.x += object.size.x / (z##type)2;						\
	object.size.x	= object.size.x - object.size.x / (z##type)2;				\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_top_half(ZRectangle##Type object)				\
	{											\
	object.point.y += object.size.y / (z##type)2;						\
	object.size.y	= object.size.y - object.size.y / (z##type)2;				\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_top_left_quarter(ZRectangle##Type object)			\
	{											\
	object.point.y += object.size.y / (z##type)2;						\
	object.size.x  /= (z##type)2;								\
	object.size.y	= object.size.y - object.size.y / (z##type)2;				\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_top_right_quarter(ZRectangle##Type object)		\
	{											\
	object.point.x += object.size.x / (z##type)2;						\
	object.point.y += object.size.y / (z##type)2;						\
	object.size.x	= object.size.x - object.size.x / (z##type)2;				\
	object.size.y	= object.size.y - object.size.y / (z##type)2;				\
	return object;										\
	}


/* MARK: - Partial implementation for real types */


#define Z_IMPLEMENTATION_REAL(Type, type)							\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_absolute_point_to_unit(ZRectangle##Type object, Z2D##Type point)	\
	{											\
	return z_2d_##type									\
		((point.x - object.point.x) / object.size.x,					\
		 (point.y - object.point.y) / object.size.y);					\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_bottom_right_quarter(ZRectangle##Type object)		\
	{											\
	object.point.x += (object.size.x /= (z##type)2);					\
	object.size.y  /= (z##type)2;								\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
zboolean z_rectangle_##type##_contains_circle(ZRectangle##Type object,ZCircle##Type circle)	\
	{											\
	return	circle.radius != (z##type)0					 &&		\
		circle.point.x - circle.radius >= object.point.x		 &&		\
		circle.point.y - circle.radius >= object.point.y		 &&		\
		circle.point.x + circle.radius <= object.point.x + object.size.x &&		\
		circle.point.y + circle.radius <= object.point.y + object.size.y;		\
	}											\
												\
												\
static Z_INLINE											\
ZCircle##Type z_rectangle_##type##_inner_circle(ZRectangle##Type object)			\
	{											\
	ZCircle##Type result;									\
												\
	result.point  = z_rectangle_##type##_center(object);					\
	result.radius = z_##type##_minimum(object.size.x, object.size.y) / (z##type)2;		\
	return result;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_right_half(ZRectangle##Type object)			\
	{											\
	object.point.x += (object.size.x /= (z##type)2);					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_top_half(ZRectangle##Type object)				\
	{											\
	object.point.y += (object.size.y /= (z##type)2);					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_top_left_quarter(ZRectangle##Type object)			\
	{											\
	object.size.x  /= (z##type)2;								\
	object.point.y += (object.size.y /= (z##type)2);					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
ZRectangle##Type z_rectangle_##type##_top_right_quarter(ZRectangle##Type object)		\
	{											\
	object.point.x += (object.size.x /= (z##type)2);					\
	object.point.y += (object.size.y /= (z##type)2);					\
	return object;										\
	}											\
												\
												\
static Z_INLINE											\
Z2D##Type z_rectangle_##type##_unit_point_to_absolute(ZRectangle##Type object, Z2D##Type point)	\
	{											\
	return z_2d_##type									\
		(point.x * object.size.x + object.point.x,					\
		 point.y * object.size.y + object.point.y);					\
	}


#define z_rectangle_type_absolute_point_to_unit(TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _absolute_point_to_unit)
#define z_rectangle_type_bottom_right_quarter(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _bottom_right_quarter	)
#define z_rectangle_type_contains_circle(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _contains_circle	)
#define z_rectangle_type_inner_circle(		TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _inner_circle		)
#define z_rectangle_type_right_half(		TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _right_half		)
#define z_rectangle_type_top_half(		TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _top_half		)
#define z_rectangle_type_top_left_quarter(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _top_left_quarter	)
#define z_rectangle_type_top_right_quarter(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _top_right_quarter	)
#define z_rectangle_type_unit_point_to_absolute(TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _unit_point_to_absolute)


/* MARK: - Implementation expansions */


Z_IMPLEMENTATION_COMMON (SInt8, sint8)
Z_IMPLEMENTATION_INTEGER(SInt8, sint8)

Z_IMPLEMENTATION_COMMON (SInt16, sint16)
Z_IMPLEMENTATION_INTEGER(SInt16, sint16)

Z_IMPLEMENTATION_COMMON (SInt32, sint32)
Z_IMPLEMENTATION_INTEGER(SInt32, sint32)

#ifdef Z_SINT64
	Z_IMPLEMENTATION_COMMON (SInt64, sint64)
	Z_IMPLEMENTATION_INTEGER(SInt64, sint64)
#endif

#ifdef Z_SINT128
	Z_IMPLEMENTATION_COMMON (SInt128, sint128)
	Z_IMPLEMENTATION_INTEGER(SInt128, sint128)
#endif

#ifdef Z_FLOAT16
	Z_IMPLEMENTATION_COMMON(Float16, float16)
	Z_IMPLEMENTATION_REAL  (Float16, float16)
#endif

#ifdef Z_FLOAT32
	Z_IMPLEMENTATION_COMMON(Float32, float32)
	Z_IMPLEMENTATION_REAL  (Float32, float32)
#endif

#ifdef Z_FLOAT64
	Z_IMPLEMENTATION_COMMON(Float64, float64)
	Z_IMPLEMENTATION_REAL  (Float64, float64)
#endif

#ifdef Z_FLOAT128
	Z_IMPLEMENTATION_COMMON(Float128, float128)
	Z_IMPLEMENTATION_REAL  (Float128, float128)
#endif

#ifdef Z_FLOAT80_X87
	Z_IMPLEMENTATION_COMMON(Float80_x87, float80_x87)
	Z_IMPLEMENTATION_REAL  (Float80_x87, float80_x87)
#endif

#ifdef Z_FLOAT96_X87
	Z_IMPLEMENTATION_COMMON(Float96_x87, float96_x87)
	Z_IMPLEMENTATION_REAL  (Float96_x87, float96_x87)
#endif

#ifdef Z_FLOAT128_X87
	Z_IMPLEMENTATION_COMMON(Float128_x87, float128_x87)
	Z_IMPLEMENTATION_REAL  (Float128_x87, float128_x87)
#endif


/* MARK: - Cleanup */


#undef Z_IMPLEMENTATION_COMMON
#undef Z_IMPLEMENTATION_INTEGER
#undef Z_IMPLEMENTATION_REAL


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_rectangle_aabr			     z_rectangle_type_aabr		       (REAL)
#	define z_rectangle_absolute_point_to_unit    z_rectangle_type_absolute_point_to_unit   (REAL)
#	define z_rectangle_align_in_bottom_center    z_rectangle_type_align_in_bottom_center   (REAL)
#	define z_rectangle_align_in_bottom_left	     z_rectangle_type_align_in_bottom_left     (REAL)
#	define z_rectangle_align_in_bottom_right     z_rectangle_type_align_in_bottom_right    (REAL)
#	define z_rectangle_align_in_center	     z_rectangle_type_align_in_center	       (REAL)
#	define z_rectangle_align_in_center_left	     z_rectangle_type_align_in_center_left     (REAL)
#	define z_rectangle_align_in_center_right     z_rectangle_type_align_in_center_right    (REAL)
#	define z_rectangle_align_in_top_center	     z_rectangle_type_align_in_top_center      (REAL)
#	define z_rectangle_align_in_top_left	     z_rectangle_type_align_in_top_left	       (REAL)
#	define z_rectangle_align_in_top_right	     z_rectangle_type_align_in_top_right       (REAL)
#	define z_rectangle_are_equal		     z_rectangle_type_are_equal		       (REAL)
#	define z_rectangle_bottom_center	     z_rectangle_type_bottom_center	       (REAL)
#	define z_rectangle_bottom_half		     z_rectangle_type_bottom_half	       (REAL)
#	define z_rectangle_bottom_left		     z_rectangle_type_bottom_left	       (REAL)
#	define z_rectangle_bottom_left_quarter	     z_rectangle_type_bottom_left_quarter      (REAL)
#	define z_rectangle_bottom_right		     z_rectangle_type_bottom_right	       (REAL)
#	define z_rectangle_bottom_right_quarter	     z_rectangle_type_bottom_right_quarter     (REAL)
#	define z_rectangle_center		     z_rectangle_type_center		       (REAL)
#	define z_rectangle_center_left		     z_rectangle_type_center_left	       (REAL)
#	define z_rectangle_center_right		     z_rectangle_type_center_right	       (REAL)
#	define z_rectangle_contains		     z_rectangle_type_contains		       (REAL)
#	define z_rectangle_contains_aabr	     z_rectangle_type_contains_aabr	       (REAL)
#	define z_rectangle_contains_circle	     z_rectangle_type_contains_circle	       (REAL)
#	define z_rectangle_contains_point	     z_rectangle_type_contains_point	       (REAL)
#	define z_rectangle_correct		     z_rectangle_type_correct		       (REAL)
#	define z_rectangle_fit_in_bottom_center	     z_rectangle_type_fit_in_bottom_center     (REAL)
#	define z_rectangle_fit_in_bottom_left	     z_rectangle_type_fit_in_bottom_left       (REAL)
#	define z_rectangle_fit_in_bottom_right	     z_rectangle_type_fit_in_bottom_right      (REAL)
#	define z_rectangle_fit_in_center	     z_rectangle_type_fit_in_center	       (REAL)
#	define z_rectangle_fit_in_center_left	     z_rectangle_type_fit_in_center_left       (REAL)
#	define z_rectangle_fit_in_center_right	     z_rectangle_type_fit_in_center_right      (REAL)
#	define z_rectangle_fit_in_top_center	     z_rectangle_type_fit_in_top_center	       (REAL)
#	define z_rectangle_fit_in_top_left	     z_rectangle_type_fit_in_top_left	       (REAL)
#	define z_rectangle_fit_in_top_right	     z_rectangle_type_fit_in_top_right	       (REAL)
#	define z_rectangle_from_vertices	     z_rectangle_type_from_vertices	       (REAL)
#	define z_rectangle_grow_from_bottom_center   z_rectangle_type_grow_from_bottom_center  (REAL)
#	define z_rectangle_grow_from_bottom_left     z_rectangle_type_grow_from_bottom_left    (REAL)
#	define z_rectangle_grow_from_bottom_right    z_rectangle_type_grow_from_bottom_right   (REAL)
#	define z_rectangle_grow_from_center	     z_rectangle_type_grow_from_center	       (REAL)
#	define z_rectangle_grow_from_center_left     z_rectangle_type_grow_from_center_left    (REAL)
#	define z_rectangle_grow_from_center_right    z_rectangle_type_grow_from_center_right   (REAL)
#	define z_rectangle_grow_from_top_center	     z_rectangle_type_grow_from_top_center     (REAL)
#	define z_rectangle_grow_from_top_left	     z_rectangle_type_grow_from_top_left       (REAL)
#	define z_rectangle_grow_from_top_right	     z_rectangle_type_grow_from_top_right      (REAL)
#	define z_rectangle_grow_in_x_from_center     z_rectangle_type_grow_in_x_from_center    (REAL)
#	define z_rectangle_grow_in_x_from_left	     z_rectangle_type_grow_in_x_from_left      (REAL)
#	define z_rectangle_grow_in_x_from_right	     z_rectangle_type_grow_in_x_from_right     (REAL)
#	define z_rectangle_grow_in_y_from_bottom     z_rectangle_type_grow_in_y_from_bottom    (REAL)
#	define z_rectangle_grow_in_y_from_center     z_rectangle_type_grow_in_y_from_center    (REAL)
#	define z_rectangle_grow_in_y_from_top	     z_rectangle_type_grow_in_y_from_top       (REAL)
#	define z_rectangle_inner_circle		     z_rectangle_type_inner_circle	       (REAL)
#	define z_rectangle_intersect		     z_rectangle_type_intersect		       (REAL)
#	define z_rectangle_intersection		     z_rectangle_type_intersection	       (REAL)
#	define z_rectangle_is_zero		     z_rectangle_type_is_zero		       (REAL)
#	define z_rectangle_left_half		     z_rectangle_type_left_half		       (REAL)
#	define z_rectangle_maximum_x		     z_rectangle_type_maximum_x		       (REAL)
#	define z_rectangle_maximum_y		     z_rectangle_type_maximum_y		       (REAL)
#	define z_rectangle_middle_x		     z_rectangle_type_middle_x		       (REAL)
#	define z_rectangle_middle_y		     z_rectangle_type_middle_y		       (REAL)
#	define z_rectangle_minimum_x		     z_rectangle_type_minimum_x		       (REAL)
#	define z_rectangle_minimum_y		     z_rectangle_type_minimum_y		       (REAL)
#	define z_rectangle_right_half		     z_rectangle_type_right_half	       (REAL)
#	define z_rectangle_shrink_from_bottom_center z_rectangle_type_shrink_from_bottom_center(REAL)
#	define z_rectangle_shrink_from_bottom_left   z_rectangle_type_shrink_from_bottom_left  (REAL)
#	define z_rectangle_shrink_from_bottom_right  z_rectangle_type_shrink_from_bottom_right (REAL)
#	define z_rectangle_shrink_from_center	     z_rectangle_type_shrink_from_center       (REAL)
#	define z_rectangle_shrink_from_center_left   z_rectangle_type_shrink_from_center_left  (REAL)
#	define z_rectangle_shrink_from_center_right  z_rectangle_type_shrink_from_center_right (REAL)
#	define z_rectangle_shrink_from_top_center    z_rectangle_type_shrink_from_top_center   (REAL)
#	define z_rectangle_shrink_from_top_left	     z_rectangle_type_shrink_from_top_left     (REAL)
#	define z_rectangle_shrink_from_top_right     z_rectangle_type_shrink_from_top_right    (REAL)
#	define z_rectangle_shrink_in_x_from_center   z_rectangle_type_shrink_in_x_from_center  (REAL)
#	define z_rectangle_shrink_in_x_from_left     z_rectangle_type_shrink_in_x_from_left    (REAL)
#	define z_rectangle_shrink_in_x_from_right    z_rectangle_type_shrink_in_x_from_right   (REAL)
#	define z_rectangle_shrink_in_y_from_bottom   z_rectangle_type_shrink_in_y_from_bottom  (REAL)
#	define z_rectangle_shrink_in_y_from_center   z_rectangle_type_shrink_in_y_from_center  (REAL)
#	define z_rectangle_shrink_in_y_from_top	     z_rectangle_type_shrink_in_y_from_top     (REAL)
#	define z_rectangle_swap			     z_rectangle_type_swap		       (REAL)
#	define z_rectangle_top_center		     z_rectangle_type_top_center	       (REAL)
#	define z_rectangle_top_half		     z_rectangle_type_top_half		       (REAL)
#	define z_rectangle_top_left		     z_rectangle_type_top_left		       (REAL)
#	define z_rectangle_top_left_quarter	     z_rectangle_type_top_left_quarter	       (REAL)
#	define z_rectangle_top_right		     z_rectangle_type_top_right		       (REAL)
#	define z_rectangle_top_right_quarter	     z_rectangle_type_top_right_quarter	       (REAL)
#	define z_rectangle_union		     z_rectangle_type_union		       (REAL)
#	define z_rectangle_unit_point_to_absolute    z_rectangle_type_unit_point_to_absolute   (REAL)
#endif


#endif /* _Z_functions_mathematics_geometry_euclidean_ZRectangle_H_ */
