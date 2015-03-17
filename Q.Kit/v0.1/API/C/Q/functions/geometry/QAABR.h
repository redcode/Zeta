/* Q Kit C API - functions/geometry/QAABR.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_QAABR_H__
#define __Q_functions_geometry_QAABR_H__

#include <Q/functions/geometry/Q2DLine.h>

#define q_float_aabr_are_equal	 q_2d_float_line_are_equal
#define q_float_aabr_is_zero	 q_2d_float_line_is_zero
#define q_float_aabr_center	 q_2d_float_line_segment_center

#define q_double_aabr_are_equal	 q_2d_double_line_are_equal
#define q_double_aabr_is_zero	 q_2d_double_line_is_zero
#define q_double_aabr_center	 q_2d_double_line_segment_center

#define q_ldouble_aabr_are_equal q_2d_ldouble_line_are_equal
#define q_ldouble_aabr_is_zero	 q_2d_ldouble_line_is_zero
#define q_ldouble_aabr_center	 q_2d_ldouble_line_segment_center


#define Q_IMPLEMENTATION_AABR(Type, type, _)					\
										\
										\
Q_INLINE qboolean q_##type##_aabr_contains(Q##Type##AABR a, Q##Type##AABR b)	\
	{									\
	return	b.a.x >= a.a.x && b.a.y >= a.a.y &&				\
		b.b.x <= a.b.x && b.b.y <= a.b.y;				\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_aabr_collide(Q##Type##AABR a, Q##Type##AABR b)	\
	{									\
	return	a.a.x < b.b.x && b.a.x < a.b.x &&				\
		a.a.y < b.b.y && b.a.y < a.b.y;					\
	}									\
										\
										\
Q_INLINE									\
Q##Type##AABR q_##type##_aabr_intersection(Q##Type##AABR a, Q##Type##AABR b)	\
	{									\
	q##type x1, x2, y1, y2, z1, z2;						\
										\
	return	(x1 = q_##type##_maximum(a.a.x, b.a.x)) <=			\
		(x2 = q_##type##_minimum(a.b.x, b.b.x)) &&			\
		(y1 = q_##type##_maximum(a.a.y, b.a.y))	<=			\
		(y2 = q_##type##_minimum(a.b.y, b.b.y))				\
										\
		? q_##type##_aabr(x1, y1, x2, y2)				\
		: q_##type##_aabr_zero;						\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_union(Q##Type##AABR a, Q##Type##AABR b)	\
	{									\
	Q##Type##AABR result;							\
										\
	result.a = q_2d_##type##_minimum(a.a, b.a);				\
	result.b = q_2d_##type##_maximum(a.b, b.b);				\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_from_vertices(Q2D##Type a, Q2D##Type b)	\
	{									\
	Q##Type##AABR result;							\
										\
	result.a = q_2d_##type##_minimum(a, b);					\
	result.b = q_2d_##type##_maximum(a, b);					\
	return result;								\
	}									\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_size(Q##Type##AABR aabr)			\
	{return q_2d_##type##_subtract(aabr.b, aabr.a);}			\
										\
										\
Q_INLINE q##type q_##type##_aabr_area(Q##Type##AABR aabr)			\
	{									\
	return q_2d_##type##_inner_product					\
		(q_2d_##type##_subtract(aabr.b, aabr.a));			\
	}									\
										\
										\
Q_INLINE q##type q_##type##_aabr_middle_x(Q##Type##AABR aabr)			\
	{return (aabr.a.x + aabr.b.x) / _(2.0);}				\
										\
										\
Q_INLINE q##type q_##type##_aabr_middle_y(Q##Type##AABR aabr)			\
	{return (aabr.a.y + aabr.b.y) / _(2.0);}				\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_top_left(Q##Type##AABR aabr)			\
	{return q_2d_##type(aabr.a.x, aabr.b.y);}				\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_top_right(Q##Type##AABR aabr)		\
	{return aabr.b;}							\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_top_center(Q##Type##AABR aabr)		\
	{return q_2d_##type((aabr.a.x + aabr.b.x) / _(2.0), aabr.b.y);}		\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_bottom_left(Q##Type##AABR aabr)		\
	{return aabr.a;}							\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_bottom_right(Q##Type##AABR aabr)		\
	{return q_2d_##type(aabr.b.x, aabr.a.y);}				\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_bottom_center(Q##Type##AABR aabr)		\
	{return q_2d_##type((aabr.a.x + aabr.b.x) / _(2.0), aabr.a.y);}		\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_center_left(Q##Type##AABR aabr)		\
	{return q_2d_##type(aabr.a.x, (aabr.a.y + aabr.b.y) / _(2.0));}		\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_center_right(Q##Type##AABR aabr)		\
	{return q_2d_##type(aabr.b.x, (aabr.a.y + aabr.b.y) / _(2.0));}		\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_top_half(Q##Type##AABR aabr)		\
	{									\
	aabr.a.y = (aabr.a.y + aabr.b.y) / _(2.0);				\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_bottom_half(Q##Type##AABR aabr)		\
	{									\
	aabr.b.y = (aabr.a.y + aabr.b.y) / _(2.0);				\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_left_half(Q##Type##AABR aabr)		\
	{									\
	aabr.b.x = (aabr.a.x + aabr.b.x) / _(2.0);				\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_right_half(Q##Type##AABR aabr)		\
	{									\
	aabr.a.x = (aabr.a.x + aabr.b.x) / _(2.0);				\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_top_left_quarter(Q##Type##AABR aabr)	\
	{									\
	aabr.b.x = (aabr.a.x + aabr.b.x) / _(2.0);				\
	aabr.a.y = (aabr.a.y + aabr.b.y) / _(2.0);				\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_top_right_quarter(Q##Type##AABR aabr)	\
	{									\
	aabr.a.x = (aabr.a.x + aabr.b.x) / _(2.0);				\
	aabr.a.y = (aabr.a.y + aabr.b.y) / _(2.0);				\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_bottom_left_quarter(Q##Type##AABR aabr)	\
	{									\
	aabr.b.x = (aabr.a.x + aabr.b.x) / _(2.0);				\
	aabr.b.y = (aabr.a.y + aabr.b.y) / _(2.0);				\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_bottom_right_quarter(Q##Type##AABR aabr)	\
	{									\
	aabr.a.x = (aabr.a.x + aabr.b.x) / _(2.0);				\
	aabr.b.y = (aabr.a.y + aabr.b.y) / _(2.0);				\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_align_in_top_left(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.a.y = aabr.b.y - size.y;						\
	aabr.b.x = aabr.a.x + size.x;						\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_align_in_top_right(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.a.x = aabr.b.x - size.x;						\
	aabr.a.y = aabr.b.y - size.y;						\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_align_in_top_center(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.a.y = aabr.b.y - size.y;						\
										\
	aabr.b.x =								\
	(aabr.a.x += (aabr.b.x - aabr.a.x - size.x) / _(2.0)) + size.x;		\
										\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_align_in_bottom_left(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.b.x = aabr.a.x + size.x;						\
	aabr.b.y = aabr.a.y + size.y;						\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_align_in_bottom_right(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.a.x = aabr.b.x - size.x;						\
	aabr.b.y = aabr.b.y + size.x;						\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_align_in_bottom_center(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.b.x =								\
	(aabr.a.x += (aabr.b.x - aabr.a.x - size.x) / _(2.0)) + size.x;		\
										\
	aabr.b.y = aabr.a.y + size.y;						\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_align_in_center_left(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.b.x = aabr.a.x + size.x;						\
										\
	aabr.b.y =								\
	(aabr.a.y += (aabr.b.y - aabr.a.y - size.y) / _(2.0)) + size.y;		\
										\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_align_in_center_right(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.a.x = aabr.b.x - size.x;						\
										\
	aabr.b.y =								\
	(aabr.a.y += (aabr.b.y - aabr.a.y - size.y) / _(2.0)) + size.y;		\
										\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_align_in_center(				\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.b.x =								\
	(aabr.a.x += (aabr.b.x - aabr.a.x - size.x) / _(2.0)) + size.x;		\
										\
	aabr.b.y =								\
	(aabr.a.y += (aabr.b.y - aabr.a.y - size.y) / _(2.0)) + size.y;		\
										\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_fit_in_top_left(				\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	size = q_2d_##type##_fit(size, q_##type##_aabr_size(aabr));		\
										\
	aabr.a.y = aabr.b.y - size.y;						\
	aabr.b.x = aabr.a.x + size.x;						\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_fit_in_top_right(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.a = q_2d_##type##_subtract						\
		(aabr.b, q_2d_##type##_fit(size, q_##type##_aabr_size(aabr)));	\
										\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_fit_in_top_center(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	Q##2D##Type old_size = q_##type##_aabr_size(aabr);			\
										\
	aabr.a.y = aabr.b.y - (size = q_2d_##type##_fit(size, old_size)).y;	\
	aabr.b.x = (aabr.a.x += (old_size.x - size.x) / _(2.0)) + size.x;	\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_fit_in_bottom_left(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	aabr.b = q_2d_##type##_add						\
		(aabr.a, q_2d_##type##_fit(size, q_##type##_aabr_size(aabr)));	\
										\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_fit_in_bottom_right(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	size = q_2d_##type##_fit(size, q_##type##_aabr_size(aabr));		\
										\
	return q_##type##_aabr							\
		(aabr.b.x - size.x, aabr.a.y,					\
		 aabr.b.x,	    aabr.a.y + size.y);				\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_fit_in_bottom_center(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	Q##2D##Type old_size = q_##type##_aabr_size(aabr);			\
										\
	aabr.b.y = aabr.a.y + (size = q_2d_##type##_fit(size, old_size)).y;	\
	aabr.b.x = (aabr.a.x += (old_size.x - size.x) / _(2.0)) + size.x;	\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_fit_in_center_left(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	Q##2D##Type old_size = q_##type##_aabr_size(aabr);			\
										\
	aabr.b.x = aabr.a.x + (size = q_2d_##type##_fit(size, old_size)).x;	\
	aabr.b.y = (aabr.a.y += (old_size.y - size.y) / _(2.0)) + size.y;	\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_fit_in_center_right(			\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	Q##2D##Type old_size = q_##type##_aabr_size(aabr);			\
										\
	aabr.a.x = aabr.b.x - (size = q_2d_##type##_fit(size, old_size)).x;	\
	aabr.b.y = (aabr.a.y += (old_size.y - size.y) / _(2.0)) + size.y;	\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##AABR q_##type##_aabr_fit_in_center(				\
	Q##Type##AABR aabr,							\
	Q##2D##Type   size							\
)										\
	{									\
	Q##2D##Type old_size = q_##type##_aabr_size(aabr);			\
										\
	size = q_2d_##type##_fit(size, old_size);				\
	aabr.b.x = (aabr.a.x += (old_size.x - size.x) / _(2.0)) + size.x;	\
	aabr.b.y = (aabr.a.y += (old_size.y - size.y) / _(2.0)) + size.y;	\
	return aabr;								\
	}									\
										\
										\
Q_INLINE Q##Type##Circle q_##type##_aabr_inner_circle(Q##Type##AABR aabr)	\
	{									\
	Q##Type##Circle result;							\
										\
	result.point = q_##type##_aabr_center(aabr);				\
										\
	result.radius =								\
	q_2d_##type##_inner_minimum(q_2d_##type##_subtract(aabr.b, aabr.a))	\
	/ _(2.0);								\
										\
	return result;								\
	}									\
										\
										\
Q_INLINE Q##Type##Rectangle q_##type##_aabr_to_rectangle(Q##Type##AABR aabr)	\
	{									\
	return q_##type##_rectangle						\
		(aabr.a.x, aabr.a.y,						\
		 aabr.b.x - aabr.a.x, aabr.b.y - aabr.a.y);			\
	}									\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_absolute_point_to_unit(			\
	Q##Type##AABR aabr,							\
	Q2D##Type     point							\
										\
)										\
	{									\
	return q_2d_##type							\
		((point.x - aabr.a.x) / (aabr.b.x - aabr.a.x),			\
		 (point.y - aabr.a.y) / (aabr.b.y - aabr.a.y));			\
	}									\
										\
										\
Q_INLINE Q2D##Type q_##type##_aabr_unit_point_to_absolute(			\
	Q##Type##AABR aabr,							\
	Q2D##Type     point							\
)										\
	{									\
	return q_2d_##type							\
		(point.x * (aabr.b.x - aabr.a.x) + aabr.a.x,			\
		 point.y * (aabr.b.y - aabr.a.y) + aabr.a.y);			\
	}									\
										\
										\
Q_INLINE									\
qboolean q_##type##_aabr_contains_point(Q##Type##AABR aabr, Q3D##Type point)	\
	{									\
	return	aabr.a.x <= point.x && point.x <= aabr.a.x &&			\
		aabr.a.y <= point.y && point.y <= aabr.a.y;			\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_aabr_contains_line_segment(			\
	Q##Type##AABR	aabr,							\
	Q3D##Type##Line segment							\
)										\
	{									\
	return	q_##type##_aabr_contains_point(aabr, segment.a) &&		\
		q_##type##_aabr_contains_point(aabr, segment.b);		\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_aabr_contains_rectangle(				\
	Q##Type##AABR	   aabr,						\
	Q##Type##Rectangle rectangle						\
)										\
	{									\
	return	aabr.a.x <= rectangle.point.x			 &&		\
		aabr.a.y <= rectangle.point.y			 &&		\
		aabr.b.x >= rectangle.point.x + rectangle.size.x &&		\
		aabr.b.y >= rectangle.point.y + rectangle.size.y;		\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_aabr_contains_circle(				\
	Q##Type##AABR	aabr,							\
	Q##Type##Circle circle							\
)										\
	{									\
	return	circle.point.x - circle.radius >= aabr.a.x &&			\
		circle.point.y - circle.radius >= aabr.a.y &&			\
		circle.point.x + circle.radius <= aabr.b.x &&			\
		circle.point.y + circle.radius <= aabr.b.y;			\
	}


Q_IMPLEMENTATION_AABR(Float,   float,	Q_FLOAT  )
Q_IMPLEMENTATION_AABR(Double,  double,	Q_DOUBLE )
Q_IMPLEMENTATION_AABR(LDouble, ldouble, Q_LDOUBLE)


/* MARK: - Default real type definitions */

#define q_aabr_are_equal	      q_2d_line_are_equal
#define q_aabr_is_zero		      q_2d_line_is_zero
#define q_aabr_center		      q_2d_line_segment_center

#define q_aabr_contains		      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_contains	       )
#define q_aabr_collide		      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_collide	       )
#define q_aabr_intersection	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_intersection	       )
#define q_aabr_union		      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_union		       )
#define q_aabr_from_vertices	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_from_vertices	       )
#define q_aabr_size		      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_size		       )
#define q_aabr_area		      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_area		       )
#define q_aabr_middle_x		      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_middle_x	       )
#define q_aabr_middle_y		      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_middle_y	       )
#define q_aabr_top_left		      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_top_left	       )
#define q_aabr_top_right	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_top_right	       )
#define q_aabr_top_center	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_top_center	       )
#define q_aabr_bottom_left	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_bottom_left	       )
#define q_aabr_bottom_right	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_bottom_right	       )
#define q_aabr_bottom_center	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_bottom_center	       )
#define q_aabr_center_left	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_center_left	       )
#define q_aabr_center_right	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_center_right	       )
#define q_aabr_top_half		      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_top_half	       )
#define q_aabr_bottom_half	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_bottom_half	       )
#define q_aabr_left_half	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_left_half	       )
#define q_aabr_right_half	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_right_half	       )
#define q_aabr_top_left_quarter	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_top_left_quarter      )
#define q_aabr_top_right_quarter      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_top_right_quarter     )
#define q_aabr_bottom_left_quarter    Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_bottom_left_quarter   )
#define q_aabr_bottom_right_quarter   Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_bottom_right_quarter  )
#define q_aabr_align_in_top_left      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_align_in_top_left     )
#define q_aabr_align_in_top_right     Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_align_in_top_right    )
#define q_aabr_align_in_top_center    Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_align_in_top_center   )
#define q_aabr_align_in_bottom_left   Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_align_in_bottom_left  )
#define q_aabr_align_in_bottom_right  Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_align_in_bottom_right )
#define q_aabr_align_in_bottom_center Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_align_in_bottom_center)
#define q_aabr_align_in_center_left   Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_align_in_center_left  )
#define q_aabr_align_in_center_right  Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_align_in_center_right )
#define q_aabr_align_in_center	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_align_in_center       )
#define q_aabr_fit_in_top_left	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_fit_in_top_left       )
#define q_aabr_fit_in_top_right	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_fit_in_top_right      )
#define q_aabr_fit_in_top_center      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_fit_in_top_center     )
#define q_aabr_fit_in_bottom_left     Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_fit_in_bottom_left    )
#define q_aabr_fit_in_bottom_right    Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_fit_in_bottom_right   )
#define q_aabr_fit_in_bottom_center   Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_fit_in_bottom_center  )
#define q_aabr_fit_in_center_left     Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_fit_in_center_left    )
#define q_aabr_fit_in_center_right    Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_fit_in_center_right   )
#define q_aabr_fit_in_center	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_fit_in_center	       )
#define q_aabr_inner_circle	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_inner_circle	       )
#define q_aabr_to_rectangle	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_to_rectangle	       )
#define q_aabr_absolute_point_to_unit Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_absolute_point_to_unit)
#define q_aabr_unit_point_to_absolute Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_unit_point_to_absolute)
#define q_aabr_contains_point	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_contains_point	       )
#define q_aabr_contains_line_segment  Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_contains_line_segment )
#define q_aabr_contains_rectangle     Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_contains_rectangle    )
#define q_aabr_contains_circle	      Q_JOIN_3(q_, Q_REAL_FIXED_TYPE_name, _aabr_contains_circle       )

#endif /* __Q_functions_geometry_QAABR_H__ */
