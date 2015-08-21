/* Z Kit C API - functions/geometry/constructors.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_constructors_H__
#define __Z_functions_geometry_constructors_H__

#include <Z/types/mathematics.h>

#if Z_LANGUAGE_HAS(COMPOUND_LITERAL)

#	define z_2d_vector_float(  a_x, a_y, b_x, b_y)		 ((Z2DVectorFloat  ){{a_x, a_y}, {b_x, b_y}})
#	define z_2d_vector_double( a_x, a_y, b_x, b_y)		 ((Z2DVectorDouble ){{a_x, a_y}, {b_x, b_y}})
#	define z_2d_vector_ldouble(a_x, a_y, b_x, b_y)		 ((Z2DVectorLDouble){{a_x, a_y}, {b_x, b_y}})

#	define z_circle_float(	x, y, radius)			 ((ZCircleFloat  ){{x, y}, radius})
#	define z_circle_double(	x, y, radius)			 ((ZCircleDouble ){{x, y}, radius})
#	define z_circle_ldouble(x, y, radius)			 ((ZCircleLDouble){{x, y}, radius})

#	define z_rectangle_float(  x, y, size_x, size_y)	 ((ZRectangleFloat  ){{x, y}, {size_x, size_y}})
#	define z_rectangle_double( x, y, size_x, size_y)	 ((ZRectangleDouble ){{x, y}, {size_x, size_y}})
#	define z_rectangle_ldouble(x, y, size_x, size_y)	 ((ZRectangleLDouble){{x, y}, {size_x, size_y}})

#	define z_3d_vector_float(  a_x, a_y, a_z, b_x, b_y, b_z) ((Z3DVectorFloat  ){{a_x, a_y, a_z}, {b_x, b_y, b_z}})
#	define z_3d_vector_double( a_x, a_y, a_z, b_x, b_y, b_z) ((Z3DVectorDouble ){{a_x, a_y, a_z}, {b_x, b_y, b_z}})
#	define z_3d_vector_ldouble(a_x, a_y, a_z, b_x, b_y, b_z) ((Z3DVectorLDouble){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#	define z_sphere_float(	x, y, z, radius)		 ((ZCircleFloat  ){{x, y, z}, radius})
#	define z_sphere_double(	x, y, z, radius)		 ((ZCircleDouble ){{x, y, z}, radius})
#	define z_sphere_ldouble(x, y, z, radius)		 ((ZCircleLDouble){{x, y, z}, radius})

#	define z_box_float(  x, y, z, size_x, size_y, size_z)	 ((ZBoxFloat  ){{x, y, z}, {size_x, size_y, size_z}})
#	define z_box_double( x, y, z, size_x, size_y, size_z)	 ((ZBoxDouble ){{x, y, z}, {size_x, size_y, size_z}})
#	define z_box_ldouble(x, y, z, size_x, size_y, size_z)	 ((ZBoxLDouble){{x, y, z}, {size_x, size_y, size_z}})

#else

#	define Z_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(Type, type)		\
										\
										\
	Z_INLINE Z2DVector##Type z_2d_vector_##type(				\
		z##type a_x,							\
		z##type a_y,							\
		z##type b_x,							\
		z##type b_y							\
	)									\
		{								\
		Z2DVector##Type vector = {{a_x, a_y}, {b_x, b_y}};		\
		return vector;							\
		}								\
										\
										\
	Z_INLINE ZCircle##Type z_circle_##type(					\
		z##type x,							\
		z##type y,							\
		z##type radius							\
	)									\
		{								\
		ZCircle##Type circle = {{x, y}, radius};			\
		return circle;							\
		}								\
										\
										\
	Z_INLINE ZRectangle##Type z_rectangle_##type(				\
		z##type x,							\
		z##type y,							\
		z##type size_x,							\
		z##type size_y							\
	)									\
		{								\
		ZRectangle##Type rectangle = {{x, y}, {size_x, size_y}};	\
		return rectangle;						\
		}								\
										\
										\
	Z_INLINE Z3DVector##Type z_3d_vector_##type(				\
		z##type a_x,							\
		z##type a_y,							\
		z##type a_z,							\
		z##type b_x,							\
		z##type b_y,							\
		z##type b_z							\
	)									\
		{								\
		Z3DVector##Type vector = {{a_x, a_y, a_z}, {b_x, b_y, b_z}};	\
		return vector;							\
		}								\
										\
										\
	Z_INLINE ZSphere##Type z_sphere_##type(					\
		z##type x,							\
		z##type y,							\
		z##type z,							\
		z##type radius							\
	)									\
		{								\
		ZSphere##Type sphere = {{x, y, z}, radius};			\
		return sphere;							\
		}								\
										\
										\
	Z_INLINE ZBox##Type z_box_##type(					\
		z##type x,							\
		z##type y,							\
		z##type z,							\
		z##type size_x,							\
		z##type size_y,							\
		z##type size_z							\
	)									\
		{								\
		ZBox##Type box = {{x, y, z}, {size_x, size_y, size_z}};		\
		return box;							\
		}


	Z_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(Float,	float  )
	Z_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(Double,	double )
	Z_IMPLEMENTATION_GEOMETRY_CONSTRUCTORS(LDouble, ldouble)

#endif

#define z_2d_line_float	 	 z_2d_vector_float
#define z_2d_line_double	 z_2d_vector_double
#define z_2d_line_ldouble	 z_2d_vector_ldouble

#define z_aabr_float		 z_2d_line_float
#define z_aabr_double		 z_2d_line_double
#define z_aabr_ldouble		 z_2d_line_ldouble

#define z_3d_line_float		 z_3d_vector_float
#define z_3d_line_double	 z_3d_vector_double
#define z_3d_line_ldouble	 z_3d_vector_ldouble

#define z_aabb_float		 z_3d_line_float
#define z_aabb_double		 z_3d_line_double
#define z_aabb_ldouble		 z_3d_line_ldouble

#define z_2d_vector_float_zero	 z_2d_vector_float  (0.0F, 0.0F, 0.0F, 0.0F)
#define z_2d_vector_double_zero	 z_2d_vector_double (0.0,  0.0,  0.0,  0.0 )
#define z_2d_vector_ldouble_zero z_2d_vector_ldouble(0.0L, 0.0L, 0.0L, 0.0L)

#define z_2d_line_float_zero	 z_2d_vector_float_zero
#define z_2d_line_double_zero	 z_2d_vector_double_zero
#define z_2d_line_ldouble_zero	 z_2d_vector_ldouble_zero

#define z_rectangle_float_zero	 z_rectangle_float  (0.0F, 0.0F, 0.0F, 0.0F)
#define z_rectangle_double_zero	 z_rectangle_double (0.0,  0.0,  0.0,  0.0 )
#define z_rectangle_ldouble_zero z_rectangle_ldouble(0.0L, 0.0L, 0.0L, 0.0L)

#define z_aabr_float_zero	 z_2d_line_float_zero
#define z_aabr_double_zero	 z_2d_line_double_zero
#define z_aabr_ldouble_zero	 z_2d_line_ldouble_zero

#define z_circle_float_zero	 z_circle_float  (0.0F, 0.0F, 0.0F)
#define z_circle_double_zero	 z_circle_double (0.0,	0.0,  0.0 )
#define z_circle_ldouble_zero	 z_circle_ldouble(0.0L, 0.0L, 0.0L)

#define z_3d_vector_float_zero	 z_3d_vector_float  (0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F)
#define z_3d_vector_double_zero	 z_3d_vector_double (0.0,  0.0,  0.0,  0.0,  0.0,  0.0 )
#define z_3d_vector_ldouble_zero z_3d_vector_ldouble(0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L)

#define z_3d_line_float_zero	 z_3d_vector_float_zero
#define z_3d_line_double_zero	 z_3d_vector_double_zero
#define z_3d_line_ldouble_zero	 z_3d_vector_ldouble_zero

#define z_box_float_zero	 z_box_float  (0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F)
#define z_box_double_zero	 z_box_double (0.0,  0.0,  0.0,  0.0,  0.0,  0.0 )
#define z_box_ldouble_zero	 z_box_ldouble(0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L)

#define z_aabb_float_zero	 z_3d_line_float_zero
#define z_aabb_double_zero	 z_3d_line_double_zero
#define z_aabb_ldouble_zero	 z_3d_line_ldouble_zero

#define z_sphere_float_zero	 z_sphere_float  (0.0F, 0.0F, 0.0F, 0.0F)
#define z_sphere_double_zero	 z_sphere_double (0.0,	0.0,  0.0,  0.0 )
#define z_sphere_ldouble_zero	 z_sphere_ldouble(0.0L, 0.0L, 0.0L, 0.0L)

/* MARK: - Default real type definitions */

#define z_2d_vector	 Z_JOIN_2(z_2d_vector_, Z_REAL_FIXED_TYPE_name)
#define z_circle	 Z_JOIN_2(z_circle_,	Z_REAL_FIXED_TYPE_name)
#define z_rectangle	 Z_JOIN_2(z_rectangle_, Z_REAL_FIXED_TYPE_name)
#define z_3d_vector	 Z_JOIN_2(z_3d_vector_, Z_REAL_FIXED_TYPE_name)
#define z_box		 Z_JOIN_2(z_box_,	Z_REAL_FIXED_TYPE_name)
#define z_sphere	 Z_JOIN_2(z_sphere_,	Z_REAL_FIXED_TYPE_name)
#define z_2d_line	 z_2d_vector
#define z_aabr		 z_2d_line
#define z_3d_line	 z_3d_vector
#define z_aabb		 z_3d_line
#define z_2d_vector_zero Z_JOIN_3(z_2d_vector_, Z_REAL_FIXED_TYPE_name, _zero)
#define z_circle_zero	 Z_JOIN_3(z_circle_,	Z_REAL_FIXED_TYPE_name, _zero)
#define z_rectangle_zero Z_JOIN_3(z_rectangle_, Z_REAL_FIXED_TYPE_name, _zero)
#define z_3d_vector_zero Z_JOIN_3(z_3d_vector_, Z_REAL_FIXED_TYPE_name, _zero)
#define z_box_zero	 Z_JOIN_3(z_box_,	Z_REAL_FIXED_TYPE_name, _zero)
#define z_sphere_zero	 Z_JOIN_3(z_sphere_,	Z_REAL_FIXED_TYPE_name, _zero)
#define z_2d_line_zero	 z_2d_vector_zero
#define z_aabr_zero	 z_2d_line_zero
#define z_3d_line_zero	 z_3d_vector_zero
#define z_aabb_zero	 z_3d_line_zero

#endif /* __Z_functions_geometry_constructors_H__ */
