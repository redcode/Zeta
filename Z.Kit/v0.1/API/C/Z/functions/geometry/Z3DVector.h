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


/* MARK: - Template */


#define Z_TEMPLATE_3D_VECTOR(Type, type)							\
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


#define z_3d_vector_type_are_equal(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_vector_, _are_equal	      )
#define z_3d_vector_type_are_perpendicular(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_vector_, _are_perpendicular)
#define z_3d_vector_type_is_zero(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_vector_, _is_zero	      )
#define z_3d_vector_type_reversed(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_vector_, _reversed	      )


/* MARK: - Implementations */


#if Z_IS_AVAILABLE(FLOAT16)
	Z_TEMPLATE_3D_VECTOR(Float16, float16)
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	Z_TEMPLATE_3D_VECTOR(Float24, float24)
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	Z_TEMPLATE_3D_VECTOR(Float32, float32)
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	Z_TEMPLATE_3D_VECTOR(Float48, float48)
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	Z_TEMPLATE_3D_VECTOR(Float64, float64)
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	Z_TEMPLATE_3D_VECTOR(Float72, float72)
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	Z_TEMPLATE_3D_VECTOR(Float80, float80)
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	Z_TEMPLATE_3D_VECTOR(Float96, float96)
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	Z_TEMPLATE_3D_VECTOR(Float128, float128)
#endif


/* MARK: - Default real type definitions */


#define z_3d_vector_are_equal	      z_3d_vector_type_are_equal	(REAL)
#define z_3d_vector_are_perpendicular z_3d_vector_type_are_perpendicular(REAL)
#define z_3d_vector_is_zero	      z_3d_vector_type_is_zero		(REAL)
#define z_3d_vector_reversed	      z_3d_vector_type_reversed		(REAL)


#endif /* __Z_functions_geometry_Z3DVector_H__ */