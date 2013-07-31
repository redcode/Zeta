/* Q API - functions/mathematics.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_mathematics_H__
#define __Q_functions_mathematics_H__

#include <Q/types/mathematics.h>
#include <Q/functions/Q2DValue.h>
#include <Q/functions/Q3DValue.h>


#pragma mark - 2D Line segment

#ifndef Q_2D_LINE_SEGMENT_EXPORT
#	define Q_2D_LINE_SEGMENT_EXPORT Q_INLINE
#endif


#define Q_IMPLEMENTATION_2D_LINE_SEGMENT(Type, type)				\
										\
										\
Q_2D_LINE_SEGMENT_EXPORT							\
Q2D##Type q_2d_##type##_line_segment_center(Q2D##Type##Line line_segment)	\
	{									\
	return q_2d_##type							\
		((line_segment.b.x - line_segment.a.x) /			\
		 2.0 + line_segment.a.x,					\
		 (line_segment.b.y - line_segment.a.y) /			\
		 2.0 + line_segment.a.y);					\
	}									\
										\
										\
Q_2D_LINE_SEGMENT_EXPORT							\
qboolean q_2d_##type##_line_segment_are_equal(					\
	Q2D##Type##Line a,							\
	Q2D##Type##Line b							\
)										\
	{									\
	return	q_2d_##type##_are_equal(a.a, b.a) &&				\
		q_2d_##type##_are_equal(a.b, b.b);				\
	}


Q_IMPLEMENTATION_2D_LINE_SEGMENT(Float,   float  )
Q_IMPLEMENTATION_2D_LINE_SEGMENT(Double,  double )
Q_IMPLEMENTATION_2D_LINE_SEGMENT(LDouble, ldouble)


#pragma mark - Rectangle


#ifndef Q_RECTANGLE_EXPORT
#	define Q_RECTANGLE_EXPORT	Q_INLINE
#endif

#define q_float_rectangle(  x, y, size_x, size_y)	((QFloatRectangle  ){{x, y}, {size_x, size_y}})
#define q_double_rectangle( x, y, size_x, size_y)	((QDoubleRectangle ){{x, y}, {size_x, size_y}})
#define q_ldouble_rectangle(x, y, size_x, size_y)	((QLDoubleRectangle){{x, y}, {size_x, size_y}})

#define q_float_rectangle_zero				q_float_rectangle  (0.0, 0.0, 0.0, 0.0)
#define q_double_rectangle_zero				q_double_rectangle (0.0, 0.0, 0.0, 0.0)
#define q_ldouble_rectangle_zero			q_ldouble_rectangle(0.0, 0.0, 0.0, 0.0)


#define Q_IMPLEMENTATION_RECTANGLE(Type, type)					\
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
	{return rectangle.point.x + rectangle.size.x * 0.5;}			\
										\
										\
Q_RECTANGLE_EXPORT								\
q##type q_##type##_rectangle_middle_y(Q##Type##Rectangle rectangle)		\
	{return rectangle.point.y + rectangle.size.y * 0.5;}			\
										\
										\
Q_RECTANGLE_EXPORT								\
Q2D##Type q_##type##_rectangle_center(Q##Type##Rectangle rectangle)		\
	{									\
	return q_2d_##type							\
		(q_##type##_rectangle_middle_x(rectangle),			\
		 q_##type##_rectangle_middle_y(rectangle));			\
	}									\
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
	}


Q_IMPLEMENTATION_RECTANGLE(Float,   float  )
Q_IMPLEMENTATION_RECTANGLE(Double,  double )
Q_IMPLEMENTATION_RECTANGLE(LDouble, ldouble)


#pragma mark - Circle

#ifndef Q_CIRCLE_EXPORT
#	define Q_CIRCLE_EXPORT Q_INLINE
#endif

#define q_float_circle(  x, y, radius)	((QFloatCircle  ){{x, y}, radius})
#define q_double_circle( x, y, radius)	((QDoubleCircle ){{x, y}, radius})
#define q_ldouble_circle(x, y, radius)	((QLDoubleCircle){{x, y}, radius})

#define q_float_circle_zero	q_float_circle  (0.0, 0.0, 0.0)
#define q_double_circle_zero	q_double_circle (0.0, 0.0, 0.0)
#define q_ldouble_circle_zero	q_ldouble_circle(0.0, 0.0, 0.0)


#define Q_IMPLEMENTATION_CIRCLE(Type, type)					\
										\
										\
Q_CIRCLE_EXPORT									\
qboolean q_##type##_circle_are_equal(Q##Type##Circle a, Q##Type##Circle b)	\
	{									\
	return	q_2d_##type##_are_equal(a.point, b.point) &&			\
		a.radius == b.radius;						\
	}


Q_IMPLEMENTATION_CIRCLE(Float,   float  )
Q_IMPLEMENTATION_CIRCLE(Double,  double )
Q_IMPLEMENTATION_CIRCLE(LDouble, ldouble)


#pragma mark - Default real type definitions

#define q_2d_zero		q_2d_real_zero
#define q_2d_are_equal		q_2d_real_are_equal
#define q_2d_contains		q_2d_real_contains
#define q_2d_add		q_2d_real_add
#define q_2d_subtract		q_2d_real_subtract
#define q_2d_multiply		q_2d_real_multiply
#define q_2d_divide		q_2d_real_divide
#define q_2d_dot_product	q_2d_real_dot_product
#define q_2d_cross_product	q_2d_real_cross_product
#define q_2d_minimum		q_2d_real_minimum
#define q_2d_maximum		q_2d_real_maximum
#define q_2d_middle		q_2d_real_middle
#define q_2d_fit		q_2d_real_fit
#define q_2d_is_zero		q_2d_real_is_zero
#define q_2d_negative		q_2d_real_negative
#define q_2d_area		q_2d_real_area
#define q_2d_square_length	q_2d_real_square_length
#define q_2d_multiply_by_scalar	q_2d_real_multiply_by_scalar
#define q_2d_divide_by_scalar	q_2d_real_divide_by_scalar


#if defined(Q_USE_FLOAT_REAL)

#	define q_rectangle		q_float_rectangle
#	define q_rectangle_zero		q_float_rectangle_zero
#	define q_rectangle_minimum_x	q_float_rectangle_minimum_x
#	define q_rectangle_minimum_y	q_float_rectangle_minimum_y
#	define q_rectangle_maximum_x	q_float_rectangle_maximum_x
#	define q_rectangle_maximum_y	q_float_rectangle_maximum_y
#	define q_rectangle_middle_x	q_float_rectangle_middle_x
#	define q_rectangle_middle_y	q_float_rectangle_middle_y
#	define q_rectangle_center	q_float_rectangle_center
#	define q_rectangle_are_equal	q_float_rectangle_are_equal

#	define q_circle			q_float_cirlce
#	define q_circle_zero		q_float_circle_zero
#	define q_circle_are_equal	q_float_circle_are_equal

#elif defined(Q_USE_LDOUBLE_REAL)

#	define q_rectangle		q_ldouble_rectangle
#	define q_rectangle_zero		q_ldouble_rectangle_zero
#	define q_rectangle_minimum_x	q_ldouble_rectangle_minimum_x
#	define q_rectangle_minimum_y	q_ldouble_rectangle_minimum_y
#	define q_rectangle_maximum_x	q_ldouble_rectangle_maximum_x
#	define q_rectangle_maximum_y	q_ldouble_rectangle_maximum_y
#	define q_rectangle_middle_x	q_ldouble_rectangle_middle_x
#	define q_rectangle_middle_y	q_ldouble_rectangle_middle_y
#	define q_rectangle_center	q_ldouble_rectangle_center
#	define q_rectangle_are_equal	q_ldouble_rectangle_are_equal

#	define q_circle			q_ldouble_cirlce
#	define q_circle_zero		q_ldouble_circle_zero
#	define q_circle_are_equal	q_ldouble_circle_are_equal

#else

#	define q_rectangle		q_double_rectangle
#	define q_rectangle_zero		q_double_rectangle_zero
#	define q_rectangle_minimum_x	q_double_rectangle_minimum_x
#	define q_rectangle_minimum_y	q_double_rectangle_minimum_y
#	define q_rectangle_maximum_x	q_double_rectangle_maximum_x
#	define q_rectangle_maximum_y	q_double_rectangle_maximum_y
#	define q_rectangle_middle_x	q_double_rectangle_middle_x
#	define q_rectangle_middle_y	q_double_rectangle_middle_y
#	define q_rectangle_center	q_double_rectangle_center
#	define q_rectangle_are_equal	q_double_rectangle_are_equal

#	define q_circle			q_double_cirlce
#	define q_circle_zero		q_double_circle_zero
#	define q_circle_are_equal	q_double_circle_are_equal

#endif

#endif /* __Q_functions_mathematics_H__ */
