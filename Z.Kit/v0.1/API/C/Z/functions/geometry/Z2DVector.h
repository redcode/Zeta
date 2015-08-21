/* Z Kit C API - functions/geometry/Z2DVector.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_Z2DVector_H__
#define __Z_functions_geometry_Z2DVector_H__

#include <Z/functions/geometry/constructors.h>
#include <Z/functions/base/Z2DValue.h>


#define Z_IMPLEMENTATION_2D_VECTOR(Type, type)							\
												\
												\
Z_INLINE zboolean z_2d_vector_##type##_are_equal(Z2DVector##Type a, Z2DVector##Type b)		\
	{return z_2d_##type##_are_equal(a.a, b.a) && z_2d_##type##_are_equal(a.b, b.b);}	\
												\
												\
Z_INLINE zboolean z_2d_vector_##type##_are_perpendicular(Z2DVector##Type a, Z2DVector##Type b)	\
	{											\
	return z_2d_##type##_are_perpendicular							\
		(z_2d_##type##_subtract(a.b, a.a), z_2d_##type##_subtract(b.b, b.a));		\
	}											\
												\
												\
Z_INLINE zboolean z_2d_vector_##type##_is_zero(Z2DVector##Type object)				\
	{return z_2d_##type##_is_zero(object.a) && z_2d_##type##_is_zero(object.b);}		\
												\
												\
Z_INLINE Z2DVector##Type z_2d_vector_##type##_reversed(Z2DVector##Type object)			\
	{return z_2d_vector_##type(object.b.x, object.b.y, object.a.x, object.a.y);}


Z_IMPLEMENTATION_2D_VECTOR(Float,   float  )
Z_IMPLEMENTATION_2D_VECTOR(Double,  double )
Z_IMPLEMENTATION_2D_VECTOR(LDouble, ldouble)


/* MARK: - Default real type definitions */

#define z_2d_vector_are_equal	      Z_JOIN_3(z_2d_vector_, Z_REAL_FIXED_TYPE_name, _are_equal	       )
#define z_2d_vector_are_perpendicular Z_JOIN_3(z_2d_vector_, Z_REAL_FIXED_TYPE_name, _are_perpendicular)
#define z_2d_vector_is_zero	      Z_JOIN_3(z_2d_vector_, Z_REAL_FIXED_TYPE_name, _is_zero	       )
#define z_2d_vector_reversed	      Z_JOIN_3(z_2d_vector_, Z_REAL_FIXED_TYPE_name, _reversed	       )

#endif /* __Z_functions_geometry_Z2DVector_H__ */
