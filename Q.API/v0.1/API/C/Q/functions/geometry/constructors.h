/* Q API - functions/geometry/constructors.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_constructors_H__
#define __Q_functions_geometry_constructors_H__

#include <Q/types/mathematics.h>

#if Q_C_HAS(COMPOUND_LITERAL)

#	define q_2d_float_vector(  a_x, a_y, b_x, b_y)		 ((Q2DFloatVector  ){{a_x, a_y}, {b_x, b_y}})
#	define q_2d_double_vector( a_x, a_y, b_x, b_y)		 ((Q2DDoubleVector ){{a_x, a_y}, {b_x, b_y}})
#	define q_2d_ldouble_vector(a_x, a_y, b_x, b_y)		 ((Q2DLDoubleVector){{a_x, a_y}, {b_x, b_y}})

#	define q_float_circle(	x, y, radius)			 ((QFloatCircle  ){{x, y}, radius})
#	define q_double_circle(	x, y, radius)			 ((QDoubleCircle ){{x, y}, radius})
#	define q_ldouble_circle(x, y, radius)			 ((QLDoubleCircle){{x, y}, radius})

#	define q_float_rectangle(  x, y, size_x, size_y)	 ((QFloatRectangle  ){{x, y}, {size_x, size_y}})
#	define q_double_rectangle( x, y, size_x, size_y)	 ((QDoubleRectangle ){{x, y}, {size_x, size_y}})
#	define q_ldouble_rectangle(x, y, size_x, size_y)	 ((QLDoubleRectangle){{x, y}, {size_x, size_y}})

#	define q_3d_float_vector(  a_x, a_y, a_z, b_x, b_y, b_z) ((Q3DFloatVector  ){{a_x, a_y, a_z}, {b_x, b_y, b_z}})
#	define q_3d_double_vector( a_x, a_y, a_z, b_x, b_y, b_z) ((Q3DDoubleVector ){{a_x, a_y, a_z}, {b_x, b_y, b_z}})
#	define q_3d_ldouble_vector(a_x, a_y, a_z, b_x, b_y, b_z) ((Q3DLDoubleVector){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#	define q_float_sphere(	x, y, z, radius)		 ((QFloatCircle  ){{x, y, z}, radius})
#	define q_double_sphere(	x, y, z, radius)		 ((QDoubleCircle ){{x, y, z}, radius})
#	define q_ldouble_sphere(x, y, z, radius)		 ((QLDoubleCircle){{x, y, z}, radius})

#	define q_float_box(  x, y, z, size_x, size_y, size_z)	 ((QFloatBox  ){{x, y, z}, {size_x, size_y, size_z}})
#	define q_double_box( x, y, z, size_x, size_y, size_z)	 ((QDoubleBox ){{x, y, z}, {size_x, size_y, size_z}})
#	define q_ldouble_box(x, y, z, size_x, size_y, size_z)	 ((QLDoubleBox){{x, y, z}, {size_x, size_y, size_z}})

#else

#	define Q_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(Type, type)		\
										\
										\
	Q_INLINE								\
	Q2D##Type##Vector q_2d_##type##_vector(					\
		q##type a_x,							\
		q##type a_y,							\
		q##type b_x,							\
		q##type b_y							\
	)									\
		{								\
		Q2D##Type##Vector vector = {{a_x, a_y}, {b_x, b_y}};		\
		return vector;							\
		}								\
										\
										\
	Q_INLINE								\
	Q##Type##Circle q_##type##_circle(q##type x, q##type y, q##type radius)	\
		{								\
		Q##Type##Circle circle = {{x, y}, radius};			\
		return circle;							\
		}								\
										\
										\
	Q_INLINE								\
	Q##Type##Rectangle q_##type##_rectangle(				\
		q##type x,							\
		q##type y,							\
		q##type size_x,							\
		q##type size_y							\
	)									\
		{								\
		Q##Type##Rectangle rectangle = {{x, y}, {size_x, size_y}};	\
		return rectangle;						\
		}								\
										\
										\
	Q_INLINE								\
	Q3D##Type##Vector q_3d_##type##_vector(					\
		q##type a_x,							\
		q##type a_y,							\
		q##type a_z,							\
		q##type b_x,							\
		q##type b_y,							\
		q##type b_z							\
	)									\
		{								\
		Q3D##Type##Vector vector = {{a_x, a_y, a_z}, {b_x, b_y, b_z}};	\
		return vector;							\
		}								\
										\
										\
	Q_INLINE								\
	Q##Type##Sphere q_##type##_sphere(					\
		q##type x,							\
		q##type y,							\
		q##type z,							\
		q##type radius							\
	)									\
		{								\
		Q##Type##Sphere sphere = {{x, y, z}, radius};			\
		return sphere;							\
		}								\
										\
										\
	Q_INLINE								\
	Q##Type##Box q_##type##_box(						\
		q##type x,							\
		q##type y,							\
		q##type z,							\
		q##type size_x,							\
		q##type size_y,							\
		q##type size_z							\
	)									\
		{								\
		Q##Type##Box box = {{x, y, z}, {size_x, size_y, size_z}};	\
		return box;							\
		}


	Q_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(Float,	float  )
	Q_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(Double,	double )
	Q_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(LDouble, ldouble)

#endif

#define q_2d_float_line	 	 q_2d_float_vector
#define q_2d_double_line	 q_2d_double_vector
#define q_2d_ldouble_line	 q_2d_ldouble_vector

#define q_float_aabr		 q_2d_float_line
#define q_double_aabr		 q_2d_double_line
#define q_ldouble_aabr		 q_2d_ldouble_line

#define q_3d_float_line		 q_3d_float_vector
#define q_3d_double_line	 q_3d_double_vector
#define q_3d_ldouble_line	 q_3d_ldouble_vector

#define q_float_aabb		 q_3d_float_line
#define q_double_aabb		 q_3d_double_line
#define q_ldouble_aabb		 q_3d_ldouble_line

#define q_2d_float_vector_zero	 q_2d_float_vector  (0.0F, 0.0F, 0.0F, 0.0F)
#define q_2d_double_vector_zero	 q_2d_double_vector (0.0,  0.0,  0.0,  0.0 )
#define q_2d_ldouble_vector_zero q_2d_ldouble_vector(0.0L, 0.0L, 0.0L, 0.0L)

#define q_2d_float_line_zero	 q_2d_float_vector_zero
#define q_2d_double_line_zero	 q_2d_double_vector_zero
#define q_2d_ldouble_line_zero	 q_2d_ldouble_vector_zero

#define q_float_rectangle_zero	 q_float_rectangle  (0.0F, 0.0F, 0.0F, 0.0F)
#define q_double_rectangle_zero	 q_double_rectangle (0.0,  0.0,  0.0,  0.0 )
#define q_ldouble_rectangle_zero q_ldouble_rectangle(0.0L, 0.0L, 0.0L, 0.0L)

#define q_float_aabr_zero	 q_2d_float_line_zero
#define q_double_aabr_zero	 q_2d_double_line_zero
#define q_ldouble_aabr_zero	 q_2d_ldouble_line_zero

#define q_float_circle_zero	 q_float_circle  (0.0F, 0.0F, 0.0F)
#define q_double_circle_zero	 q_double_circle (0.0,	0.0,  0.0 )
#define q_ldouble_circle_zero	 q_ldouble_circle(0.0L, 0.0L, 0.0L)

#define q_3d_float_vector_zero	 q_3d_float_vector  (0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F)
#define q_3d_double_vector_zero	 q_3d_double_vector (0.0,  0.0,  0.0,  0.0,  0.0,  0.0 )
#define q_3d_ldouble_vector_zero q_3d_ldouble_vector(0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L)

#define q_3d_float_line_zero	 q_3d_float_vector_zero
#define q_3d_double_line_zero	 q_3d_double_vector_zero
#define q_3d_ldouble_line_zero	 q_3d_ldouble_vector_zero

#define q_float_box_zero	 q_float_box  (0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F)
#define q_double_box_zero	 q_double_box (0.0,  0.0,  0.0,  0.0,  0.0,  0.0 )
#define q_ldouble_box_zero	 q_ldouble_box(0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L)

#define q_float_aabb_zero	 q_3d_float_line_zero
#define q_double_aabb_zero	 q_3d_double_line_zero
#define q_ldouble_aabb_zero	 q_3d_ldouble_line_zero

#define q_float_sphere_zero	 q_float_sphere  (0.0F, 0.0F, 0.0F, 0.0F)
#define q_double_sphere_zero	 q_double_sphere (0.0,	0.0,  0.0,  0.0 )
#define q_ldouble_sphere_zero	 q_ldouble_sphere(0.0L, 0.0L, 0.0L, 0.0L)

/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_2d_vector	q_2d_float_vector
#	define q_2d_circle	q_2d_float_circle
#	define q_rectangle	q_float_rectangle
#	define q_3d_vector	q_3d_float_vector
#	define q_box		q_float_box
#	define q_sphere		q_float_sphere

#	define q_2d_vector_zero	q_2d_float_vector_zero
#	define q_2d_circle_zero	q_2d_float_circle_zero
#	define q_rectangle_zero	q_float_rectangle_zero
#	define q_3d_vector_zero	q_3d_float_vector_zero
#	define q_box_zero	q_float_box_zero
#	define q_sphere_zero	q_float_sphere_zero

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_2d_vector	q_2d_ldouble_vector
#	define q_2d_circle	q_2d_ldouble_circle
#	define q_rectangle	q_ldouble_rectangle
#	define q_3d_vector	q_3d_ldouble_vector
#	define q_box		q_ldouble_box
#	define q_sphere		q_ldouble_sphere

#	define q_2d_vector_zero	q_2d_ldouble_vector_zero
#	define q_2d_circle_zero	q_2d_ldouble_circle_zero
#	define q_rectangle_zero	q_ldouble_rectangle_zero
#	define q_3d_vector_zero	q_3d_ldouble_vector_zero
#	define q_box_zero	q_ldouble_box_zero
#	define q_sphere_zero	q_ldouble_sphere_zero

#else

#	define q_2d_vector	q_2d_double_vector
#	define q_2d_circle	q_2d_double_circle
#	define q_rectangle	q_double_rectangle
#	define q_3d_vector	q_3d_double_vector
#	define q_box		q_double_box
#	define q_sphere		q_double_sphere

#	define q_2d_vector_zero	q_2d_double_vector_zero
#	define q_2d_circle_zero	q_2d_double_circle_zero
#	define q_rectangle_zero	q_double_rectangle_zero
#	define q_3d_vector_zero	q_3d_double_vector_zero
#	define q_box_zero	q_double_box_zero
#	define q_sphere_zero	q_double_sphere_zero

#endif

#define q_2d_line	q_2d_vector
#define q_aabr		q_2d_line
#define q_3d_line	q_3d_vector
#define q_aabb		q_3d_line

#define q_2d_line_zero	q_2d_vector_zero
#define q_aabr_zero	q_2d_line_zero
#define q_3d_line_zero	q_3d_vector_zero
#define q_aabb_zero	q_3d_line_zero

#endif /* __Q_functions_geometry_constructors_H__ */
