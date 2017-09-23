/* Z Kit C API - functions/mathematics/geometry/euclidean/ZBox.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_mathematics_geometry_euclidean_ZBox_H__
#define __Z_functions_mathematics_geometry_euclidean_ZBox_H__

#include <Z/functions/mathematics/geometry/euclidean/constructors.h>
#include <Z/functions/base/Z3DValue.h>


/* MARK: - Common implementation */


#define Z_IMPLEMENTATION_BOX_COMMON(Type, type)							\
												\
												\
Z_INLINE ZAABB##Type z_box_##type##_aabb(ZBox##Type object)					\
	{											\
	return z_aabb_##type									\
		(object.point.x, object.point.y, object.point.z,				\
		 object.point.x + object.size.x,						\
		 object.point.y + object.size.y,						\
		 object.point.z + object.size.z);						\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_are_equal(ZBox##Type a, ZBox##Type b)				\
	{											\
	return	z_3d_##type##_are_equal(a.point, b.point) &&					\
		z_3d_##type##_are_equal(a.size,  b.size );					\
	}											\
												\
												\
Z_INLINE Z3D##Type z_box_##type##_center(ZBox##Type object)					\
	{											\
	return z_3d_##type									\
		(object.point.x + object.size.x / (z##type)2,					\
		 object.point.y + object.size.y / (z##type)2,					\
		 object.point.z + object.size.z / (z##type)2);					\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_contains(ZBox##Type object, ZBox##Type other)			\
	{											\
	return	other.size.x		     != (z##type)0		       &&		\
		other.size.y		     != (z##type)0		       &&		\
		other.size.z		     != (z##type)0		       &&		\
		other.point.x		     >= object.point.x		       &&		\
		other.point.y		     >= object.point.y		       &&		\
		other.point.z		     >= object.point.z		       &&		\
		other.point.x + other.size.x <= object.point.x + object.size.x &&		\
		other.point.y + other.size.y <= object.point.y + object.size.y &&		\
		other.point.z + other.size.z <= object.point.z + object.size.z;			\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_contains_aabb(ZBox##Type object, ZAABB##Type aabb)		\
	{											\
	return	aabb.a.x != aabb.b.x			   &&					\
		aabb.a.y != aabb.b.y			   &&					\
		aabb.a.z != aabb.b.z			   &&					\
		aabb.a.x >= object.point.x		   &&					\
		aabb.a.y >= object.point.y		   &&					\
		aabb.a.z >= object.point.z		   &&					\
		aabb.b.x <= object.point.x + object.size.x &&					\
		aabb.b.y <= object.point.y + object.size.y &&					\
		aabb.b.z <= object.point.z + object.size.z;					\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_contains_point(ZBox##Type object, Z3D##Type point)		\
	{											\
	return	point.x >= object.point.x		  &&					\
		point.y >= object.point.y		  &&					\
		point.z >= object.point.z		  &&					\
		point.x <  object.point.x + object.size.x &&					\
		point.y <  object.point.y + object.size.y &&					\
		point.z <  object.point.z + object.size.z;					\
	}											\
												\
												\
Z_INLINE ZBox##Type z_box_##type##_correct(ZBox##Type object)					\
	{											\
	if (object.size.x < (z##type)0) object.point.x -= (object.size.x = -object.size.x);	\
	if (object.size.y < (z##type)0) object.point.y -= (object.size.y = -object.size.y);	\
	if (object.size.z < (z##type)0) object.point.z -= (object.size.z = -object.size.z);	\
 	return object;										\
	}											\
												\
												\
Z_INLINE ZBox##Type z_box_##type##_from_vertices(Z3D##Type a, Z3D##Type b)			\
	{											\
	Z3D##Type minimum = z_3d_##type##_minimum(a, b);					\
	Z3D##Type maximum = z_3d_##type##_maximum(a, b);					\
												\
	return z_box_##type									\
		(minimum.x,  minimum.y, minimum.z,						\
		 z_##type##_maximum(a.x, b.x) - minimum.x,					\
		 z_##type##_maximum(a.y, b.y) - minimum.y,					\
		 z_##type##_maximum(a.z, b.z) - minimum.z);					\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_intersect(ZBox##Type a, ZBox##Type b)				\
	{											\
	return	a.size.x	     != (z##type)0	     &&					\
		a.size.y	     != (z##type)0	     &&					\
		a.size.z	     != (z##type)0	     &&					\
		b.size.x	     != (z##type)0	     &&					\
		b.size.y	     != (z##type)0	     &&					\
		b.size.z	     != (z##type)0	     &&					\
		b.point.x + b.size.x >	a.point.x	     &&					\
		b.point.y + b.size.y >	a.point.y	     &&					\
		b.point.z + b.size.z >	a.point.z	     &&					\
		b.point.x	     <	a.point.x + a.size.x &&					\
		b.point.y	     <	a.point.y + a.size.y &&					\
		b.point.z	     <	a.point.z + a.size.z;					\
	}											\
												\
												\
Z_INLINE ZBox##Type z_box_##type##_intersection(ZBox##Type a, ZBox##Type b)			\
	{											\
	z##type x1, x2, y1, y2, z1, z2;								\
												\
	return	(x1 = z_##type##_maximum(a.point.x,	       b.point.x)) <			\
		(x2 = z_##type##_minimum(a.point.x + a.size.x, b.point.x + b.size.x)) &&	\
		(y1 = z_##type##_maximum(a.point.y,	       b.point.y)) <			\
		(y2 = z_##type##_minimum(a.point.y + a.size.y, b.point.y + b.size.y)) &&	\
		(z1 = z_##type##_maximum(a.point.z,	       b.point.z)) <			\
		(z2 = z_##type##_minimum(a.point.z + a.size.z, b.point.z + b.size.z))		\
												\
		? z_box_##type(x1, y1, z1, x2 - x1, y2 - y1, z2 - z1)				\
		: z_box_##type##_zero;								\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_is_zero(ZBox##Type object)					\
	{return	z_3d_##type##_is_zero(object.point) && z_3d_##type##_is_zero(object.size);}	\
												\
												\
Z_INLINE void z_box_##type##_swap(ZBox##Type *a, ZBox##Type *b)					\
	{											\
	ZBox##Type t = *a;									\
												\
	*a = *b; *b = t;									\
	}											\
												\
												\
Z_INLINE ZBox##Type z_box_##type##_union(ZBox##Type a, ZBox##Type b)				\
	{											\
	ZBox##Type result;									\
												\
	result.point = z_3d_##type##_minimum(a.point, b.point);					\
												\
	result.size.x =										\
	z_##type##_maximum(a.point.x + a.size.x, b.point.x + b.size.x) - result.point.x;	\
												\
	result.size.y =										\
	z_##type##_maximum(a.point.y + a.size.y, b.point.y + b.size.y) - result.point.y;	\
												\
	result.size.z =										\
	z_##type##_maximum(a.point.z + a.size.z, b.point.z + b.size.z) - result.point.z;	\
												\
	return result;										\
	}


#define z_box_type_aabb(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _aabb	    )
#define z_box_type_are_equal(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _are_equal	    )
#define z_box_type_center(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _center	    )
#define z_box_type_contains(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _contains	    )
#define z_box_type_contains_aabb( TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _contains_aabb )
#define z_box_type_contains_point(TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _contains_point)
#define z_box_type_correct(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _correct	    )
#define z_box_type_from_vertices( TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _from_vertices )
#define z_box_type_intersect(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _intersect	    )
#define z_box_type_intersection(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _intersection  )
#define z_box_type_is_zero(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _is_zero	    )
#define z_box_type_swap(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _swap	    )
#define z_box_type_union(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _union	    )


/* MARK: - Partial implementation for real types */


#define Z_IMPLEMENTATION_BOX_REAL(Type, type)							\
												\
												\
Z_INLINE Z3D##Type z_box_##type##_absolute_point_to_unit(ZBox##Type object, Z3D##Type point)	\
	{											\
	return z_3d_##type									\
		((point.x - object.point.x) / object.size.x,					\
		 (point.y - object.point.y) / object.size.y,					\
		 (point.z - object.point.z) / object.size.z);					\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_contains_sphere(ZBox##Type object, ZSphere##Type sphere)	\
	{											\
	return	sphere.point.x - sphere.radius >= object.point.x		 &&		\
		sphere.point.y - sphere.radius >= object.point.y		 &&		\
		sphere.point.z - sphere.radius >= object.point.z		 &&		\
		sphere.point.x + sphere.radius <= object.point.x + object.size.x &&		\
		sphere.point.y + sphere.radius <= object.point.y + object.size.y &&		\
		sphere.point.z + sphere.radius <= object.point.z + object.size.z;		\
	}											\
												\
												\
Z_INLINE ZSphere##Type z_box_##type##_inner_sphere(ZBox##Type object)				\
	{											\
	ZSphere##Type result;									\
												\
	result.point = z_box_##type##_center(object);						\
												\
	result.radius =										\
	z_##type##_minimum(z_##type##_minimum(object.size.x, object.size.y), object.size.z)	\
	/ (z##type)2;										\
												\
	return result;										\
	}											\
												\
												\
Z_INLINE Z3D##Type z_box_##type##_unit_point_to_absolute(ZBox##Type object, Z3D##Type point)	\
	{											\
	return z_3d_##type									\
		(point.x * object.size.x + object.point.x,					\
		 point.y * object.size.y + object.point.y,					\
		 point.z * object.size.z + object.point.z);					\
	}


#define z_box_type_absolute_point_to_unit(TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _absolute_point_to_unit)
#define z_box_type_contains_sphere(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _contains_sphere	    )
#define z_box_type_inner_sphere(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _inner_sphere	    )
#define z_box_type_unit_point_to_absolute(TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _unit_point_to_absolute)


/* MARK: - Implementation expansions */


Z_IMPLEMENTATION_BOX_COMMON(Int8,  int8 )
Z_IMPLEMENTATION_BOX_COMMON(Int16, int16)
Z_IMPLEMENTATION_BOX_COMMON(Int32, int32)

#ifdef Z_INT64
	Z_IMPLEMENTATION_BOX_COMMON(Int64, int64)
#endif

#ifdef Z_INT128
	Z_IMPLEMENTATION_BOX_COMMON(Int128, int128)
#endif

#ifdef Z_FLOAT16
	Z_IMPLEMENTATION_BOX_COMMON(Float16, float16)
	Z_IMPLEMENTATION_BOX_REAL  (Float16, float16)
#endif

#ifdef Z_FLOAT24
	Z_IMPLEMENTATION_BOX_COMMON(Float24, float24)
	Z_IMPLEMENTATION_BOX_REAL  (Float24, float24)
#endif

#ifdef Z_FLOAT32
	Z_IMPLEMENTATION_BOX_COMMON(Float32, float32)
	Z_IMPLEMENTATION_BOX_REAL  (Float32, float32)
#endif

#ifdef Z_FLOAT48
	Z_IMPLEMENTATION_BOX_COMMON(Float48, float48)
	Z_IMPLEMENTATION_BOX_REAL  (Float48, float48)
#endif

#ifdef Z_FLOAT64
	Z_IMPLEMENTATION_BOX_COMMON(Float64, float64)
	Z_IMPLEMENTATION_BOX_REAL  (Float64, float64)
#endif

#ifdef Z_FLOAT72
	Z_IMPLEMENTATION_BOX_COMMON(Float72, float72)
	Z_IMPLEMENTATION_BOX_REAL  (Float72, float72)
#endif

#ifdef Z_FLOAT80
	Z_IMPLEMENTATION_BOX_COMMON(Float80, float80)
	Z_IMPLEMENTATION_BOX_REAL  (Float80, float80)
#endif

#ifdef Z_FLOAT96
	Z_IMPLEMENTATION_BOX_COMMON(Float96, float96)
	Z_IMPLEMENTATION_BOX_REAL  (Float96, float96)
#endif

#ifdef Z_FLOAT128
	Z_IMPLEMENTATION_BOX_COMMON(Float128, float128)
	Z_IMPLEMENTATION_BOX_REAL  (Float128, float128)
#endif


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_box_aabb		    z_box_type_aabb		     (REAL)
#	define z_box_absolute_point_to_unit z_box_type_absolute_point_to_unit(REAL)
#	define z_box_are_equal		    z_box_type_are_equal	     (REAL)
#	define z_box_center		    z_box_type_center		     (REAL)
#	define z_box_contains		    z_box_type_contains		     (REAL)
#	define z_box_contains_aabb	    z_box_type_contains_aabb	     (REAL)
#	define z_box_contains_point	    z_box_type_contains_point	     (REAL)
#	define z_box_contains_sphere	    z_box_type_contains_sphere	     (REAL)
#	define z_box_correct		    z_box_type_correct		     (REAL)
#	define z_box_from_vertices	    z_box_type_from_vertices	     (REAL)
#	define z_box_inner_sphere	    z_box_type_inner_sphere	     (REAL)
#	define z_box_intersect		    z_box_type_intersect	     (REAL)
#	define z_box_intersection	    z_box_type_intersection	     (REAL)
#	define z_box_is_zero		    z_box_type_is_zero		     (REAL)
#	define z_box_swap		    z_box_type_swap		     (REAL)
#	define z_box_union		    z_box_type_union		     (REAL)
#	define z_box_unit_point_to_absolute z_box_type_unit_point_to_absolute(REAL)
#endif


#endif /* __Z_functions_mathematics_geometry_euclidean_ZBox_H__ */
