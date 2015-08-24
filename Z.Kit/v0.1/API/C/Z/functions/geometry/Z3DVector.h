/* Z Kit C API - functions/geometry/Z3DVector.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_Z3DVector_H__
#define __Z_functions_geometry_Z3DVector_H__

#include <Z/functions/geometry/constructors.h>
#include <Z/functions/base/Z3DValue.h>


#define Z_IMPLEMENTATION_3D_VECTOR(Type, type)							\
												\
												\
Z_INLINE zboolean z_3d_vector_##type##_are_equal(Z3DVector##Type a, Z3DVector##Type b)		\
	{return z_3d_##type##_are_equal(a.a, b.a) && z_3d_##type##_are_equal(a.b, b.b);}	\
												\
												\
Z_INLINE zboolean z_3d_vector_##type##_are_perpendicular(Z3DVector##Type a, Z3DVector##Type b)	\
	{											\
	return z_3d_##type##_are_perpendicular							\
		(z_3d_##type##_subtract(a.b, a.a),						\
		 z_3d_##type##_subtract(b.b, b.a));						\
	}											\
												\
												\
Z_INLINE zboolean z_3d_vector_##type##_is_zero(Z3DVector##Type object)				\
	{return z_3d_##type##_is_zero(object.a) && z_3d_##type##_is_zero(object.b);}		\
												\
												\
Z_INLINE Z3DVector##Type z_3d_vector_##type##_reversed(Z3DVector##Type object)			\
	{											\
	return z_3d_vector_##type								\
		(object.b.x, object.b.y, object.b.z, object.a.x, object.a.y, object.a.z);	\
	}											\


Z_IMPLEMENTATION_3D_VECTOR(Float,   float  )
Z_IMPLEMENTATION_3D_VECTOR(Double,  double )
Z_IMPLEMENTATION_3D_VECTOR(LDouble, ldouble)


/* MARK: - Default real type definitions */


#define z_3d_vector_are_equal	      Z_INSERT_REAL_fixed_type(z_3d_vector_, _are_equal	       )
#define z_3d_vector_are_perpendicular Z_INSERT_REAL_fixed_type(z_3d_vector_, _are_perpendicular)
#define z_3d_vector_is_zero	      Z_INSERT_REAL_fixed_type(z_3d_vector_, _is_zero	       )
#define z_3d_vector_reversed	      Z_INSERT_REAL_fixed_type(z_3d_vector_, _reversed	       )


#endif /* __Z_functions_geometry_Z3DVector_H__ */
