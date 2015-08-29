/* Z Kit C API - functions/geometry/ZBox.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_geometry_ZBox_H__
#define __Z_functions_geometry_ZBox_H__

#include <Z/functions/geometry/constructors.h>
#include <Z/functions/base/Z3DValue.h>


/* MARK: - Template */


#define Z_TEMPLATE_BOX(Type, type, _)								\
												\
												\
Z_INLINE zboolean z_box_##type##_are_equal(ZBox##Type a, ZBox##Type b)				\
	{											\
	return	z_3d_##type##_are_equal(a.point, b.point) &&					\
		z_3d_##type##_are_equal(a.size,  b.size );					\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_contains(ZBox##Type a, ZBox##Type b)				\
	{											\
	return	b.point.x	     >= a.point.x	     &&					\
		b.point.y	     >= a.point.y	     &&					\
		b.point.z	     >= a.point.z	     &&					\
		b.point.x + b.size.x <= a.point.x + a.size.x &&					\
		b.point.y + b.size.y <= a.point.y + a.size.y &&					\
		b.point.z + b.size.z <= a.point.z + a.size.z;					\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_collide(ZBox##Type a, ZBox##Type b)				\
	{											\
	return	a.point.x < b.point.x + b.size.x && b.point.x < a.point.x + a.size.x &&		\
		a.point.y < b.point.y + b.size.y && b.point.y < a.point.y + a.size.y &&		\
		a.point.z < b.point.z + b.size.z && b.point.z < a.point.z + a.size.z;		\
	}											\
												\
												\
Z_INLINE ZBox##Type z_box_##type##_intersection(ZBox##Type a, ZBox##Type b)			\
	{											\
	z##type x1, x2, y1, y2, z1, z2;								\
												\
	return	(x1 = z_##type##_maximum(a.point.x, b.point.x)) <=				\
		(x2 = z_##type##_minimum(a.point.x + a.size.x, b.point.x + b.size.x)) &&	\
		(y1 = z_##type##_maximum(a.point.y, b.point.y)) <=				\
		(y2 = z_##type##_minimum(a.point.y + a.size.y, b.point.y + b.size.y)) &&	\
		(z1 = z_##type##_maximum(a.point.z, b.point.z)) <=				\
		(z2 = z_##type##_minimum(a.point.z + a.size.z, b.point.z + b.size.z))		\
												\
		? z_box_##type(x1, y1, z1, x2 - x1, y2 - y1, z2 - z1)				\
		: z_box_##type##_zero;								\
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
		 maximum.x - minimum.x, maximum.y - minimum.y, maximum.z - minimum.z);		\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_is_zero(ZBox##Type object)					\
	{return	z_3d_##type##_is_zero(object.point) && z_3d_##type##_is_zero(object.size);}	\
												\
												\
Z_INLINE Z3D##Type z_box_##type##_center(ZBox##Type object)					\
	{											\
	return z_3d_##type									\
		(object.point.x + object.size.x / _(2.0),					\
		 object.point.y + object.size.y / _(2.0),					\
		 object.point.z + object.size.z / _(2.0));					\
	}											\
												\
												\
Z_INLINE ZBox##Type z_box_##type##_correct(ZBox##Type object)					\
	{											\
	if (object.size.x < _(0.0)) object.point.x -= (object.size.x = -object.size.x);		\
	if (object.size.y < _(0.0)) object.point.y -= (object.size.y = -object.size.y);		\
	if (object.size.z < _(0.0)) object.point.z -= (object.size.z = -object.size.z);		\
 	return object;										\
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
	/ _(2.0);										\
												\
	return result;										\
	}											\
												\
												\
Z_INLINE ZAABB##Type z_box_##type##_to_aabb(ZBox##Type object)					\
	{											\
	return z_aabb_##type									\
		(object.point.x,  object.point.y, object.point.z,				\
		 object.point.x + object.size.x,						\
		 object.point.y + object.size.y,						\
		 object.point.z + object.size.z);						\
	}											\
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
Z_INLINE Z3D##Type z_box_##type##_unit_point_to_absolute(ZBox##Type object, Z3D##Type point)	\
	{											\
	return z_3d_##type									\
		(point.x * object.size.x + object.point.x,					\
		 point.y * object.size.y + object.point.y,					\
		 point.z * object.size.z + object.point.z);					\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_contains_point(ZBox##Type object, Z3D##Type point)		\
	{											\
	return	point.x >= object.point.x		  &&					\
		point.y >= object.point.y		  &&					\
		point.z >= object.point.z		  &&					\
		point.x <= object.point.x + object.size.x &&					\
		point.y <= object.point.y + object.size.y &&					\
		point.z <= object.point.z + object.size.z;					\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_contains_line_segment(						\
	ZBox##Type    object,									\
	Z3DLine##Type line_segment								\
)												\
	{											\
	return	z_box_##type##_contains_point(object, line_segment.a) &&			\
		z_box_##type##_contains_point(object, line_segment.b);				\
	}											\
												\
												\
Z_INLINE zboolean z_box_##type##_contains_aabb(ZBox##Type object, ZAABB##Type aabb)		\
	{											\
	return	aabb.a.x >= object.point.x		   &&					\
		aabb.a.y >= object.point.y		   &&					\
		aabb.a.z >= object.point.z		   &&					\
		aabb.b.x <= object.point.x + object.size.x &&					\
		aabb.b.y <= object.point.y + object.size.y &&					\
		aabb.b.z <= object.point.z + object.size.z;					\
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
	}


#define z_box_type_are_equal(		  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _are_equal		    )
#define z_box_type_contains(		  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _contains		    )
#define z_box_type_collide(		  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _collide		    )
#define z_box_type_intersection(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _intersection	    )
#define z_box_type_union(		  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _union		    )
#define z_box_type_from_vertices(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _from_vertices	    )
#define z_box_type_is_zero(		  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _is_zero		    )
#define z_box_type_center(		  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _center		    )
#define z_box_type_correct(		  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _correct		    )
#define z_box_type_inner_sphere(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _inner_sphere	    )
#define z_box_type_to_aabb(		  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _to_aabb		    )
#define z_box_type_absolute_point_to_unit(TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _absolute_point_to_unit)
#define z_box_type_unit_point_to_absolute(TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _unit_point_to_absolute)
#define z_box_type_contains_point(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _contains_point	    )
#define z_box_type_contains_line_segment( TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _contains_line_segment )
#define z_box_type_contains_aabb(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _contains_aabb	    )
#define z_box_type_contains_sphere(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_, _contains_sphere	    )


/* MARK: - Implementations */


#if Z_IS_AVAILABLE(FLOAT16)
	Z_TEMPLATE_BOX(Float16, float16, Z_FLOAT16)
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	Z_TEMPLATE_BOX(Float24, float24, Z_FLOAT24)
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	Z_TEMPLATE_BOX(Float32, float32, Z_FLOAT32)
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	Z_TEMPLATE_BOX(Float48, float48, Z_FLOAT48)
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	Z_TEMPLATE_BOX(Float64, float64, Z_FLOAT64)
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	Z_TEMPLATE_BOX(Float72, float72, Z_FLOAT72)
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	Z_TEMPLATE_BOX(Float80, float80, Z_FLOAT80)
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	Z_TEMPLATE_BOX(Float96, float96, Z_FLOAT96)
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	Z_TEMPLATE_BOX(Float128, float128, Z_FLOAT128)
#endif


/* MARK: - Default real type definitions */


#define z_box_are_equal		     z_box_type_are_equal	      (REAL)
#define z_box_contains		     z_box_type_contains	      (REAL)
#define z_box_collide		     z_box_type_collide		      (REAL)
#define z_box_intersection	     z_box_type_intersection	      (REAL)
#define z_box_union		     z_box_type_union		      (REAL)
#define z_box_from_vertices	     z_box_type_from_vertices	      (REAL)
#define z_box_is_zero		     z_box_type_is_zero		      (REAL)
#define z_box_center		     z_box_type_center		      (REAL)
#define z_box_correct		     z_box_type_correct		      (REAL)
#define z_box_inner_sphere	     z_box_type_inner_sphere	      (REAL)
#define z_box_to_aabb		     z_box_type_to_aabb		      (REAL)
#define z_box_absolute_point_to_unit z_box_type_absolute_point_to_unit(REAL)
#define z_box_unit_point_to_absolute z_box_type_unit_point_to_absolute(REAL)
#define z_box_contains_point	     z_box_type_contains_point	      (REAL)
#define z_box_contains_line_segment  z_box_type_contains_line_segment (REAL)
#define z_box_contains_aabb	     z_box_type_contains_aabb	      (REAL)
#define z_box_contains_sphere	     z_box_type_contains_sphere	      (REAL)


#endif /* __Z_functions_geometry_ZBox_H__ */
