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

#	if Z_IS_AVAILABLE(FLOAT16)

#		define z_2d_vector_float16(a_x, a_y, b_x, b_y) \
			((Z2DVectorFloat16){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_vector_float16(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DVectorFloat16){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_rectangle_float16(x, y, size_x, size_y) \
			((ZRectangleFloat16){{x, y}, {size_x, size_y}})

#		define z_box_float16(x, y, z, size_x, size_y, size_z) \
			((ZBoxFloat16){{x, y, z}, {size_x, size_y, size_z}})

#		define z_circle_float16(x, y, radius) \
			((ZCircleFloat16){{x, y}, radius})

#		define z_sphere_float16(x, y, z, radius) \
			((ZCircleFloat16){{x, y, z}, radius})

#	endif

#	if Z_IS_AVAILABLE(FLOAT24)

#		define z_2d_vector_float24(a_x, a_y, b_x, b_y) \
			((Z2DVectorFloat24){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_vector_float24(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DVectorFloat24){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_rectangle_float24(x, y, size_x, size_y) \
			((ZRectangleFloat24){{x, y}, {size_x, size_y}})

#		define z_box_float24(x, y, z, size_x, size_y, size_z) \
			((ZBoxFloat24){{x, y, z}, {size_x, size_y, size_z}})

#		define z_circle_float24(x, y, radius) \
			((ZCircleFloat24){{x, y}, radius})

#		define z_sphere_float24(x, y, z, radius) \
			((ZCircleFloat24){{x, y, z}, radius})

#	endif

#	if Z_IS_AVAILABLE(FLOAT32)

#		define z_2d_vector_float32(a_x, a_y, b_x, b_y) \
			((Z2DVectorFloat32){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_vector_float32(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DVectorFloat32){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_rectangle_float32(x, y, size_x, size_y) \
			((ZRectangleFloat32){{x, y}, {size_x, size_y}})

#		define z_box_float32(x, y, z, size_x, size_y, size_z) \
			((ZBoxFloat32){{x, y, z}, {size_x, size_y, size_z}})

#		define z_circle_float32(x, y, radius) \
			((ZCircleFloat32){{x, y}, radius})

#		define z_sphere_float32(x, y, z, radius) \
			((ZCircleFloat32){{x, y, z}, radius})

#	endif

#	if Z_IS_AVAILABLE(FLOAT48)

#		define z_2d_vector_float48(a_x, a_y, b_x, b_y) \
			((Z2DVectorFloat48){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_vector_float48(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DVectorFloat48){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_rectangle_float48(x, y, size_x, size_y) \
			((ZRectangleFloat48){{x, y}, {size_x, size_y}})

#		define z_box_float48(x, y, z, size_x, size_y, size_z) \
			((ZBoxFloat48){{x, y, z}, {size_x, size_y, size_z}})

#		define z_circle_float48(x, y, radius) \
			((ZCircleFloat48){{x, y}, radius})

#		define z_sphere_float48(x, y, z, radius) \
			((ZCircleFloat48){{x, y, z}, radius})

#	endif

#	if Z_IS_AVAILABLE(FLOAT64)

#		define z_2d_vector_float64(a_x, a_y, b_x, b_y) \
			((Z2DVectorFloat64){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_vector_float64(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DVectorFloat64){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_rectangle_float64(x, y, size_x, size_y) \
			((ZRectangleFloat64){{x, y}, {size_x, size_y}})

#		define z_box_float64(x, y, z, size_x, size_y, size_z) \
			((ZBoxFloat64){{x, y, z}, {size_x, size_y, size_z}})

#		define z_circle_float64(x, y, radius) \
			((ZCircleFloat64){{x, y}, radius})

#		define z_sphere_float64(x, y, z, radius) \
			((ZCircleFloat64){{x, y, z}, radius})

#	endif

#	if Z_IS_AVAILABLE(FLOAT72)

#		define z_2d_vector_float72(a_x, a_y, b_x, b_y) \
			((Z2DVectorFloat72){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_vector_float72(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DVectorFloat72){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_rectangle_float72(x, y, size_x, size_y) \
			((ZRectangleFloat72){{x, y}, {size_x, size_y}})

#		define z_box_float72(x, y, z, size_x, size_y, size_z) \
			((ZBoxFloat72){{x, y, z}, {size_x, size_y, size_z}})

#		define z_circle_float72(x, y, radius) \
			((ZCircleFloat72){{x, y}, radius})

#		define z_sphere_float72(x, y, z, radius) \
			((ZCircleFloat72){{x, y, z}, radius})

#	endif

#	if Z_IS_AVAILABLE(FLOAT80)

#		define z_2d_vector_float80(a_x, a_y, b_x, b_y) \
			((Z2DVectorFloat80){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_vector_float80(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DVectorFloat80){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_rectangle_float80(x, y, size_x, size_y) \
			((ZRectangleFloat80){{x, y}, {size_x, size_y}})

#		define z_box_float80(x, y, z, size_x, size_y, size_z) \
			((ZBoxFloat80){{x, y, z}, {size_x, size_y, size_z}})

#		define z_circle_float80(x, y, radius) \
			((ZCircleFloat80){{x, y}, radius})

#		define z_sphere_float80(x, y, z, radius) \
			((ZCircleFloat80){{x, y, z}, radius})

#	endif

#	if Z_IS_AVAILABLE(FLOAT96)

#		define z_2d_vector_float96(a_x, a_y, b_x, b_y) \
			((Z2DVectorFloat96){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_vector_float96(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DVectorFloat96){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_rectangle_float96(x, y, size_x, size_y) \
			((ZRectangleFloat96){{x, y}, {size_x, size_y}})

#		define z_box_float96(x, y, z, size_x, size_y, size_z) \
			((ZBoxFloat96){{x, y, z}, {size_x, size_y, size_z}})

#		define z_circle_float96(x, y, radius) \
			((ZCircleFloat96){{x, y}, radius})

#		define z_sphere_float96(x, y, z, radius) \
			((ZCircleFloat96){{x, y, z}, radius})

#	endif

#	if Z_IS_AVAILABLE(FLOAT128)

#		define z_2d_vector_float128(a_x, a_y, b_x, b_y) \
			((Z2DVectorFloat128){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_vector_float128(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DVectorFloat128){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_rectangle_float128(x, y, size_x, size_y) \
			((ZRectangleFloat128){{x, y}, {size_x, size_y}})

#		define z_box_float128(x, y, z, size_x, size_y, size_z) \
			((ZBoxFloat128){{x, y, z}, {size_x, size_y, size_z}})

#		define z_circle_float128(x, y, radius) \
			((ZCircleFloat128){{x, y}, radius})

#		define z_sphere_float128(x, y, z, radius) \
			((ZCircleFloat128){{x, y, z}, radius})

#	endif

#else

#	define Z_TEMPLATE_GEOMETRY_CONSTRUCTORS(Type, type)			\
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
	Z_INLINE ZSphere##Type z_sphere_##type(					\
		z##type x,							\
		z##type y,							\
		z##type z,							\
		z##type radius							\
	)									\
		{								\
		ZSphere##Type sphere = {{x, y, z}, radius};			\
		return sphere;							\
		}


#	if Z_IS_AVAILABLE(FLOAT16)
		Z_TEMPLATE_GEOMETRY_CONSTRUCTORS(Float16, float16)
#	endif

#	if Z_IS_AVAILABLE(FLOAT32)
		Z_TEMPLATE_GEOMETRY_CONSTRUCTORS(Float32, float32)
#	endif

#	if Z_IS_AVAILABLE(FLOAT48)
		Z_TEMPLATE_GEOMETRY_CONSTRUCTORS(Float48, float48)
#	endif

#	if Z_IS_AVAILABLE(FLOAT64)
		Z_TEMPLATE_GEOMETRY_CONSTRUCTORS(Float64, float64)
#	endif

#	if Z_IS_AVAILABLE(FLOAT72)
		Z_TEMPLATE_GEOMETRY_CONSTRUCTORS(Float72, float72)
#	endif

#	if Z_IS_AVAILABLE(FLOAT80)
		Z_TEMPLATE_GEOMETRY_CONSTRUCTORS(Float80, float80)
#	endif

#	if Z_IS_AVAILABLE(FLOAT96)
		Z_TEMPLATE_GEOMETRY_CONSTRUCTORS(Float96, float96)
#	endif

#	if Z_IS_AVAILABLE(FLOAT128)
		Z_TEMPLATE_GEOMETRY_CONSTRUCTORS(Float128, float128)
#	endif

#endif

#if Z_IS_AVAILABLE(FLOAT16)

#	define z_2d_line_float16 z_2d_vector_float16
#	define z_3d_line_float16 z_3d_vector_float16
#	define z_aabr_float16	 z_2d_line_float16
#	define z_aabb_float16	 z_3d_line_float16

#	define z_2d_vector_float16_zero z_2d_vector_float16(0.0, 0.0, 0.0, 0.0)
#	define z_3d_vector_float16_zero z_3d_vector_float16(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_2d_line_float16_zero	z_2d_vector_float16_zero
#	define z_3d_line_float16_zero	z_3d_vector_float16_zero
#	define z_rectangle_float16_zero z_rectangle_float16(0.0, 0.0, 0.0, 0.0)
#	define z_box_float16_zero	z_box_float16	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabr_float16_zero	z_2d_line_float16_zero
#	define z_aabb_float16_zero	z_3d_line_float16_zero
#	define z_circle_float16_zero	z_circle_float16   (0.0, 0.0, 0.0)
#	define z_sphere_float16_zero	z_sphere_float16   (0.0, 0.0, 0.0, 0.0)

#endif

#if Z_IS_AVAILABLE(FLOAT24)

#	define z_2d_line_float24 z_2d_vector_float24
#	define z_3d_line_float24 z_3d_vector_float24
#	define z_aabr_float24	 z_2d_line_float24
#	define z_aabb_float24	 z_3d_line_float24

#	define z_2d_vector_float24_zero z_2d_vector_float24(0.0, 0.0, 0.0, 0.0)
#	define z_3d_vector_float24_zero z_3d_vector_float24(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_2d_line_float24_zero	z_2d_vector_float24_zero
#	define z_3d_line_float24_zero	z_3d_vector_float24_zero
#	define z_rectangle_float24_zero z_rectangle_float24(0.0, 0.0, 0.0, 0.0)
#	define z_box_float24_zero	z_box_float24	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabr_float24_zero	z_2d_line_float24_zero
#	define z_aabb_float24_zero	z_3d_line_float24_zero
#	define z_circle_float24_zero	z_circle_float24   (0.0, 0.0, 0.0)
#	define z_sphere_float24_zero	z_sphere_float24   (0.0, 0.0, 0.0, 0.0)

#endif

#if Z_IS_AVAILABLE(FLOAT32)

#	define z_2d_line_float32 z_2d_vector_float32
#	define z_3d_line_float32 z_3d_vector_float32
#	define z_aabr_float32	 z_2d_line_float32
#	define z_aabb_float32	 z_3d_line_float32

#	define z_2d_vector_float32_zero z_2d_vector_float32(0.0, 0.0, 0.0, 0.0)
#	define z_3d_vector_float32_zero z_3d_vector_float32(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_2d_line_float32_zero	z_2d_vector_float32_zero
#	define z_3d_line_float32_zero	z_3d_vector_float32_zero
#	define z_rectangle_float32_zero z_rectangle_float32(0.0, 0.0, 0.0, 0.0)
#	define z_box_float32_zero	z_box_float32	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabr_float32_zero	z_2d_line_float32_zero
#	define z_aabb_float32_zero	z_3d_line_float32_zero
#	define z_circle_float32_zero	z_circle_float32   (0.0, 0.0, 0.0)
#	define z_sphere_float32_zero	z_sphere_float32   (0.0, 0.0, 0.0, 0.0)

#endif

#if Z_IS_AVAILABLE(FLOAT48)

#	define z_2d_line_float48 z_2d_vector_float48
#	define z_3d_line_float48 z_3d_vector_float48
#	define z_aabr_float48	 z_2d_line_float48
#	define z_aabb_float48	 z_3d_line_float48

#	define z_2d_vector_float48_zero z_2d_vector_float48(0.0, 0.0, 0.0, 0.0)
#	define z_3d_vector_float48_zero z_3d_vector_float48(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_2d_line_float48_zero	z_2d_vector_float48_zero
#	define z_3d_line_float48_zero	z_3d_vector_float48_zero
#	define z_rectangle_float48_zero z_rectangle_float48(0.0, 0.0, 0.0, 0.0)
#	define z_box_float48_zero	z_box_float48	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabr_float48_zero	z_2d_line_float48_zero
#	define z_aabb_float48_zero	z_3d_line_float48_zero
#	define z_circle_float48_zero	z_circle_float48   (0.0, 0.0, 0.0)
#	define z_sphere_float48_zero	z_sphere_float48   (0.0, 0.0, 0.0, 0.0)

#endif

#if Z_IS_AVAILABLE(FLOAT64)

#	define z_2d_line_float64 z_2d_vector_float64
#	define z_3d_line_float64 z_3d_vector_float64
#	define z_aabr_float64	 z_2d_line_float64
#	define z_aabb_float64	 z_3d_line_float64

#	define z_2d_vector_float64_zero z_2d_vector_float64(0.0, 0.0, 0.0, 0.0)
#	define z_3d_vector_float64_zero z_3d_vector_float64(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_2d_line_float64_zero	z_2d_vector_float64_zero
#	define z_3d_line_float64_zero	z_3d_vector_float64_zero
#	define z_rectangle_float64_zero z_rectangle_float64(0.0, 0.0, 0.0, 0.0)
#	define z_box_float64_zero	z_box_float64	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabr_float64_zero	z_2d_line_float64_zero
#	define z_aabb_float64_zero	z_3d_line_float64_zero
#	define z_circle_float64_zero	z_circle_float64   (0.0, 0.0, 0.0)
#	define z_sphere_float64_zero	z_sphere_float64   (0.0, 0.0, 0.0, 0.0)

#endif

#if Z_IS_AVAILABLE(FLOAT72)

#	define z_2d_line_float72 z_2d_vector_float72
#	define z_3d_line_float72 z_3d_vector_float72
#	define z_aabr_float72	 z_2d_line_float72
#	define z_aabb_float72	 z_3d_line_float72

#	define z_2d_vector_float72_zero z_2d_vector_float72(0.0, 0.0, 0.0, 0.0)
#	define z_3d_vector_float72_zero z_3d_vector_float72(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_2d_line_float72_zero	z_2d_vector_float72_zero
#	define z_3d_line_float72_zero	z_3d_vector_float72_zero
#	define z_rectangle_float72_zero z_rectangle_float72(0.0, 0.0, 0.0, 0.0)
#	define z_box_float72_zero	z_box_float72	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabr_float72_zero	z_2d_line_float72_zero
#	define z_aabb_float72_zero	z_3d_line_float72_zero
#	define z_circle_float72_zero	z_circle_float72   (0.0, 0.0, 0.0)
#	define z_sphere_float72_zero	z_sphere_float72   (0.0, 0.0, 0.0, 0.0)

#endif

#if Z_IS_AVAILABLE(FLOAT80)

#	define z_2d_line_float80 z_2d_vector_float80
#	define z_3d_line_float80 z_3d_vector_float80
#	define z_aabr_float80	 z_2d_line_float80
#	define z_aabb_float80	 z_3d_line_float80

#	define z_2d_vector_float80_zero z_2d_vector_float80(0.0, 0.0, 0.0, 0.0)
#	define z_3d_vector_float80_zero z_3d_vector_float80(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_2d_line_float80_zero	z_2d_vector_float80_zero
#	define z_3d_line_float80_zero	z_3d_vector_float80_zero
#	define z_rectangle_float80_zero z_rectangle_float80(0.0, 0.0, 0.0, 0.0)
#	define z_box_float80_zero	z_box_float80	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabr_float80_zero	z_2d_line_float80_zero
#	define z_aabb_float80_zero	z_3d_line_float80_zero
#	define z_circle_float80_zero	z_circle_float80   (0.0, 0.0, 0.0)
#	define z_sphere_float80_zero	z_sphere_float80   (0.0, 0.0, 0.0, 0.0)

#endif

#if Z_IS_AVAILABLE(FLOAT96)

#	define z_2d_line_float96 z_2d_vector_float96
#	define z_3d_line_float96 z_3d_vector_float96
#	define z_aabr_float96	 z_2d_line_float96
#	define z_aabb_float96	 z_3d_line_float96

#	define z_2d_vector_float96_zero z_2d_vector_float96(0.0, 0.0, 0.0, 0.0)
#	define z_3d_vector_float96_zero z_3d_vector_float96(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_2d_line_float96_zero	z_2d_vector_float96_zero
#	define z_3d_line_float96_zero	z_3d_vector_float96_zero
#	define z_rectangle_float96_zero z_rectangle_float96(0.0, 0.0, 0.0, 0.0)
#	define z_box_float96_zero	z_box_float96	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabr_float96_zero	z_2d_line_float96_zero
#	define z_aabb_float96_zero	z_3d_line_float96_zero
#	define z_circle_float96_zero	z_circle_float96   (0.0, 0.0, 0.0)
#	define z_sphere_float96_zero	z_sphere_float96   (0.0, 0.0, 0.0, 0.0)

#endif

#if Z_IS_AVAILABLE(FLOAT128)

#	define z_2d_line_float128 z_2d_vector_float128
#	define z_3d_line_float128 z_3d_vector_float128
#	define z_aabr_float128	  z_2d_line_float128
#	define z_aabb_float128	  z_3d_line_float128

#	define z_2d_vector_float128_zero z_2d_vector_float128(0.0, 0.0, 0.0, 0.0)
#	define z_3d_vector_float128_zero z_3d_vector_float128(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_2d_line_float128_zero	 z_2d_vector_float128_zero
#	define z_3d_line_float128_zero	 z_3d_vector_float128_zero
#	define z_rectangle_float128_zero z_rectangle_float128(0.0, 0.0, 0.0, 0.0)
#	define z_box_float128_zero	 z_box_float128	     (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabr_float128_zero	 z_2d_line_float128_zero
#	define z_aabb_float128_zero	 z_3d_line_float128_zero
#	define z_circle_float128_zero	 z_circle_float128   (0.0, 0.0, 0.0)
#	define z_sphere_float128_zero	 z_sphere_float128   (0.0, 0.0, 0.0, 0.0)

#endif

#define z_2d_vector_type(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_vector_,)
#define z_3d_vector_type(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_vector_,)
#define z_2d_line_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_,	 )
#define z_3d_line_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_,	 )
#define z_rectangle_type(TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_,)
#define z_box_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_type,	 )
#define z_aabr_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_,	 )
#define z_aabb_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_,	 )
#define z_circle_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_,	 )
#define z_sphere_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_,	 )

#define z_2d_vector_type_zero(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_vector_, _zero)
#define z_3d_vector_type_zero(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_vector_, _zero)
#define z_2d_line_type_zero(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_,   _zero)
#define z_3d_line_type_zero(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_,   _zero)
#define z_rectangle_type_zero(TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _zero)
#define z_box_type_zero(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_,       _zero)
#define z_aabr_type_zero(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_,      _zero)
#define z_aabb_type_zero(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_,      _zero)
#define z_circle_type_zero(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_,    _zero)
#define z_sphere_type_zero(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_,    _zero)

/* MARK: - Default real type definitions */

#define z_2d_vector	 z_2d_vector_type(REAL)
#define z_3d_vector	 z_3d_vector_type(REAL)
#define z_2d_line	 z_2d_vector
#define z_3d_line	 z_3d_vector
#define z_rectangle	 z_rectangle_type(REAL)
#define z_box		 z_box_type	 (REAL)
#define z_aabr		 z_2d_line
#define z_aabb		 z_3d_line
#define z_circle	 z_circle_type	 (REAL)
#define z_sphere	 z_sphere_type	 (REAL)

#define z_2d_vector_zero z_2d_vector_type_zero(REAL)
#define z_3d_vector_zero z_3d_vector_type_zero(REAL)
#define z_2d_line_zero	 z_2d_vector_zero
#define z_3d_line_zero	 z_3d_vector_zero
#define z_rectangle_zero z_rectangle_type_zero(REAL)
#define z_box_zero	 z_box_type_zero      (REAL)
#define z_aabr_zero	 z_2d_line_zero
#define z_aabb_zero	 z_3d_line_zero
#define z_circle_zero	 z_circle_type_zero   (REAL)
#define z_sphere_zero	 z_sphere_type_zero   (REAL)

#endif /* __Z_functions_geometry_constructors_H__ */
