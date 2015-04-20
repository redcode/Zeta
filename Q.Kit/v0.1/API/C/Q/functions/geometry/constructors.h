/* Q Kit C API - functions/geometry/constructors.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_constructors_H__
#define __Q_functions_geometry_constructors_H__

#include <Q/types/mathematics.h>

#if Q_LANGUAGE_HAS(COMPOUND_LITERAL)

#	define q_2d_vector_float(  a_x, a_y, b_x, b_y)		 ((Q2DVectorFloat  ){{a_x, a_y}, {b_x, b_y}})
#	define q_2d_vector_double( a_x, a_y, b_x, b_y)		 ((Q2DVectorDouble ){{a_x, a_y}, {b_x, b_y}})
#	define q_2d_vector_ldouble(a_x, a_y, b_x, b_y)		 ((Q2DVectorLDouble){{a_x, a_y}, {b_x, b_y}})

#	define q_circle_float(	x, y, radius)			 ((QCircleFloat  ){{x, y}, radius})
#	define q_circle_double(	x, y, radius)			 ((QCircleDouble ){{x, y}, radius})
#	define q_circle_ldouble(x, y, radius)			 ((QCircleLDouble){{x, y}, radius})

#	define q_rectangle_float(  x, y, size_x, size_y)	 ((QRectangleFloat  ){{x, y}, {size_x, size_y}})
#	define q_rectangle_double( x, y, size_x, size_y)	 ((QRectangleDouble ){{x, y}, {size_x, size_y}})
#	define q_rectangle_ldouble(x, y, size_x, size_y)	 ((QRectangleLDouble){{x, y}, {size_x, size_y}})

#	define q_3d_vector_float(  a_x, a_y, a_z, b_x, b_y, b_z) ((Q3DVectorFloat  ){{a_x, a_y, a_z}, {b_x, b_y, b_z}})
#	define q_3d_vector_double( a_x, a_y, a_z, b_x, b_y, b_z) ((Q3DVectorDouble ){{a_x, a_y, a_z}, {b_x, b_y, b_z}})
#	define q_3d_vector_ldouble(a_x, a_y, a_z, b_x, b_y, b_z) ((Q3DVectorLDouble){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#	define q_sphere_float(	x, y, z, radius)		 ((QCircleFloat  ){{x, y, z}, radius})
#	define q_sphere_double(	x, y, z, radius)		 ((QCircleDouble ){{x, y, z}, radius})
#	define q_sphere_ldouble(x, y, z, radius)		 ((QCircleLDouble){{x, y, z}, radius})

#	define q_box_float(  x, y, z, size_x, size_y, size_z)	 ((QBoxFloat  ){{x, y, z}, {size_x, size_y, size_z}})
#	define q_box_double( x, y, z, size_x, size_y, size_z)	 ((QBoxDouble ){{x, y, z}, {size_x, size_y, size_z}})
#	define q_box_ldouble(x, y, z, size_x, size_y, size_z)	 ((QBoxLDouble){{x, y, z}, {size_x, size_y, size_z}})

#else

#	define Q_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(Type, type)		\
										\
										\
	Q_INLINE Q2DVector##Type q_2d_vector_##type(				\
		q##type a_x,							\
		q##type a_y,							\
		q##type b_x,							\
		q##type b_y							\
	)									\
		{								\
		Q2DVector##Type vector = {{a_x, a_y}, {b_x, b_y}};		\
		return vector;							\
		}								\
										\
										\
	Q_INLINE QCircle##Type q_circle_##type(					\
		q##type x,							\
		q##type y,							\
		q##type radius							\
	)									\
		{								\
		QCircle##Type circle = {{x, y}, radius};			\
		return circle;							\
		}								\
										\
										\
	Q_INLINE QRectangle##Type q_rectangle_##type(				\
		q##type x,							\
		q##type y,							\
		q##type size_x,							\
		q##type size_y							\
	)									\
		{								\
		QRectangle##Type rectangle = {{x, y}, {size_x, size_y}};	\
		return rectangle;						\
		}								\
										\
										\
	Q_INLINE Q3DVector##Type q_3d_vector_##type(				\
		q##type a_x,							\
		q##type a_y,							\
		q##type a_z,							\
		q##type b_x,							\
		q##type b_y,							\
		q##type b_z							\
	)									\
		{								\
		Q3DVector##Type vector = {{a_x, a_y, a_z}, {b_x, b_y, b_z}};	\
		return vector;							\
		}								\
										\
										\
	Q_INLINE QSphere##Type q_sphere_##type(					\
		q##type x,							\
		q##type y,							\
		q##type z,							\
		q##type radius							\
	)									\
		{								\
		QSphere##Type sphere = {{x, y, z}, radius};			\
		return sphere;							\
		}								\
										\
										\
	Q_INLINE QBox##Type q_box_##type(					\
		q##type x,							\
		q##type y,							\
		q##type z,							\
		q##type size_x,							\
		q##type size_y,							\
		q##type size_z							\
	)									\
		{								\
		QBox##Type box = {{x, y, z}, {size_x, size_y, size_z}};		\
		return box;							\
		}


	Q_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(Float,	float  )
	Q_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(Double,	double )
	Q_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(LDouble, ldouble)

#endif

#define q_2d_line_float	 	 q_2d_vector_float
#define q_2d_line_double	 q_2d_vector_double
#define q_2d_line_ldouble	 q_2d_vector_ldouble

#define q_aabr_float		 q_2d_line_float
#define q_aabr_double		 q_2d_line_double
#define q_aabr_ldouble		 q_2d_line_ldouble

#define q_3d_line_float		 q_3d_vector_float
#define q_3d_line_double	 q_3d_vector_double
#define q_3d_line_ldouble	 q_3d_vector_ldouble

#define q_aabb_float		 q_3d_line_float
#define q_aabb_double		 q_3d_line_double
#define q_aabb_ldouble		 q_3d_line_ldouble

#define q_2d_vector_float_zero	 q_2d_vector_float  (0.0F, 0.0F, 0.0F, 0.0F)
#define q_2d_vector_double_zero	 q_2d_vector_double (0.0,  0.0,  0.0,  0.0 )
#define q_2d_vector_ldouble_zero q_2d_vector_ldouble(0.0L, 0.0L, 0.0L, 0.0L)

#define q_2d_line_float_zero	 q_2d_vector_float_zero
#define q_2d_line_double_zero	 q_2d_vector_double_zero
#define q_2d_line_ldouble_zero	 q_2d_vector_ldouble_zero

#define q_rectangle_float_zero	 q_rectangle_float  (0.0F, 0.0F, 0.0F, 0.0F)
#define q_rectangle_double_zero	 q_rectangle_double (0.0,  0.0,  0.0,  0.0 )
#define q_rectangle_ldouble_zero q_rectangle_ldouble(0.0L, 0.0L, 0.0L, 0.0L)

#define q_aabr_float_zero	 q_2d_line_float_zero
#define q_aabr_double_zero	 q_2d_line_double_zero
#define q_aabr_ldouble_zero	 q_2d_line_ldouble_zero

#define q_circle_float_zero	 q_circle_float  (0.0F, 0.0F, 0.0F)
#define q_circle_double_zero	 q_circle_double (0.0,	0.0,  0.0 )
#define q_circle_ldouble_zero	 q_circle_ldouble(0.0L, 0.0L, 0.0L)

#define q_3d_vector_float_zero	 q_3d_vector_float  (0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F)
#define q_3d_vector_double_zero	 q_3d_vector_double (0.0,  0.0,  0.0,  0.0,  0.0,  0.0 )
#define q_3d_vector_ldouble_zero q_3d_vector_ldouble(0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L)

#define q_3d_line_float_zero	 q_3d_vector_float_zero
#define q_3d_line_double_zero	 q_3d_vector_double_zero
#define q_3d_line_ldouble_zero	 q_3d_vector_ldouble_zero

#define q_box_float_zero	 q_box_float  (0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F)
#define q_box_double_zero	 q_box_double (0.0,  0.0,  0.0,  0.0,  0.0,  0.0 )
#define q_box_ldouble_zero	 q_box_ldouble(0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L)

#define q_aabb_float_zero	 q_3d_line_float_zero
#define q_aabb_double_zero	 q_3d_line_double_zero
#define q_aabb_ldouble_zero	 q_3d_line_ldouble_zero

#define q_sphere_float_zero	 q_sphere_float  (0.0F, 0.0F, 0.0F, 0.0F)
#define q_sphere_double_zero	 q_sphere_double (0.0,	0.0,  0.0,  0.0 )
#define q_sphere_ldouble_zero	 q_sphere_ldouble(0.0L, 0.0L, 0.0L, 0.0L)

/* MARK: - Default real type definitions */

#define q_2d_vector	 Q_JOIN_2(q_2d_vector_, Q_REAL_FIXED_TYPE_name)
#define q_circle	 Q_JOIN_2(q_circle_,	Q_REAL_FIXED_TYPE_name)
#define q_rectangle	 Q_JOIN_2(q_rectangle_, Q_REAL_FIXED_TYPE_name)
#define q_3d_vector	 Q_JOIN_2(q_3d_vector_, Q_REAL_FIXED_TYPE_name)
#define q_box		 Q_JOIN_2(q_box_,	Q_REAL_FIXED_TYPE_name)
#define q_sphere	 Q_JOIN_2(q_sphere_,	Q_REAL_FIXED_TYPE_name)
#define q_2d_line	 q_2d_vector
#define q_aabr		 q_2d_line
#define q_3d_line	 q_3d_vector
#define q_aabb		 q_3d_line
#define q_2d_vector_zero Q_JOIN_3(q_2d_vector_, Q_REAL_FIXED_TYPE_name, _zero)
#define q_circle_zero	 Q_JOIN_3(q_circle_,	Q_REAL_FIXED_TYPE_name, _zero)
#define q_rectangle_zero Q_JOIN_3(q_rectangle_, Q_REAL_FIXED_TYPE_name, _zero)
#define q_3d_vector_zero Q_JOIN_3(q_3d_vector_, Q_REAL_FIXED_TYPE_name, _zero)
#define q_box_zero	 Q_JOIN_3(q_box_,	Q_REAL_FIXED_TYPE_name, _zero)
#define q_sphere_zero	 Q_JOIN_3(q_sphere_,	Q_REAL_FIXED_TYPE_name, _zero)
#define q_2d_line_zero	 q_2d_vector_zero
#define q_aabr_zero	 q_2d_line_zero
#define q_3d_line_zero	 q_3d_vector_zero
#define q_aabb_zero	 q_3d_line_zero

#endif /* __Q_functions_geometry_constructors_H__ */
