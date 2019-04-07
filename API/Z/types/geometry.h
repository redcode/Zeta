/* Z Kit - types/geometry.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_geometry_H
#define Z_types_geometry_H

#include <Z/types/integral.h>
#include <Z/types/real.h>

#define Z_TYPES_SIGNED(Type, type)			  \
typedef struct {Z2D##Type point, size;} ZRectangle##Type; \
typedef struct {Z3D##Type point, size;} ZBox##Type;	  \
typedef struct {Z2D##Type a, b;}	Z2DLine##Type;    \
typedef struct {Z3D##Type a, b;}	Z3DLine##Type;	  \
typedef Z2DLine##Type			ZAABR##Type;	  \
typedef Z3DLine##Type			ZAABB##Type;

#define Z2DLineType(   TYPE) Z_APPEND_##TYPE##_FixedType(Z2DLine   )
#define Z3DLineType(   TYPE) Z_APPEND_##TYPE##_FixedType(Z3DLine   )
#define ZAABRType(     TYPE) Z_APPEND_##TYPE##_FixedType(ZAABR	   )
#define ZAABBType(     TYPE) Z_APPEND_##TYPE##_FixedType(ZAABB	   )
#define ZRectangleType(TYPE) Z_APPEND_##TYPE##_FixedType(ZRectangle)
#define ZBoxType(      TYPE) Z_APPEND_##TYPE##_FixedType(ZBox	   )

#define Z_TYPES_REAL(Type, type)				  \
typedef struct {Z2D##Type point; z##type radius;}  ZCircle##Type; \
typedef struct {Z3D##Type point; z##type radius;}  ZSphere##Type; \
typedef struct {Z2D##Type point; z##type angle;}   Z2DRay##Type;  \
typedef struct {Z3D##Type point; z##type angle;}   Z3DRay##Type;  \
typedef struct {Z3D##Type normal; z##type offset;} ZPlane##Type;

#define Z2DRayType( TYPE) Z_APPEND_##TYPE##_FixedType(Z2DRay )
#define Z3DRayType( TYPE) Z_APPEND_##TYPE##_FixedType(Z3DRay )
#define ZCircleType(TYPE) Z_APPEND_##TYPE##_FixedType(ZCircle)
#define ZSphereType(TYPE) Z_APPEND_##TYPE##_FixedType(ZSphere)
#define ZPlaneType( TYPE) Z_APPEND_##TYPE##_FixedType(ZPlane )

Z_TYPES_SIGNED(SInt8,  sint8 )
Z_TYPES_SIGNED(SInt16, sint16)
Z_TYPES_SIGNED(SInt32, sint32)

#ifdef Z_SINT64
	Z_TYPES_SIGNED(SInt64, sint64)
#endif

#ifdef Z_SINT128
	Z_TYPES_SIGNED(SInt128, sint128)
#endif

#ifdef Z_FLOAT16
	Z_TYPES_SIGNED(Float16, float16)
	Z_TYPES_REAL  (Float16, float16)
#endif

#ifdef Z_FLOAT32
	Z_TYPES_SIGNED(Float32, float32)
	Z_TYPES_REAL  (Float32, float32)
#endif

#ifdef Z_FLOAT64
	Z_TYPES_SIGNED(Float64, float64)
	Z_TYPES_REAL  (Float64, float64)
#endif

#ifdef Z_FLOAT128
	Z_TYPES_SIGNED(Float128, float128)
	Z_TYPES_REAL  (Float128, float128)
#endif

#ifdef Z_FLOAT80_X87
	Z_TYPES_SIGNED(Float80_x87, float80_x87)
	Z_TYPES_REAL  (Float80_x87, float80_x87)
#endif

#ifdef Z_FLOAT96_X87
	Z_TYPES_SIGNED(Float96_x87, float96_x87)
	Z_TYPES_REAL  (Float96_x87, float96_x87)
#endif

#ifdef Z_FLOAT128_X87
	Z_TYPES_SIGNED(Float128_x87, float128_x87)
	Z_TYPES_REAL  (Float128_x87, float128_x87)
#endif

#undef Z_TYPES_SIGNED
#undef Z_TYPES_REAL

#ifdef Z_REAL
	typedef Z2DLineType   (REAL) Z2DLine;
	typedef Z2DRayType    (REAL) Z2DRay;
	typedef Z3DLineType   (REAL) Z3DLine;
	typedef Z3DRayType    (REAL) Z3DRay;
	typedef ZAABBType     (REAL) ZAABB;
	typedef ZAABRType     (REAL) ZAABR;
	typedef ZBoxType      (REAL) ZBox;
	typedef ZCircleType   (REAL) ZCircle;
	typedef ZPlaneType    (REAL) ZPlane;
	typedef ZRectangleType(REAL) ZRectangle;
	typedef ZSphereType   (REAL) ZSphere;
#endif

#if Z_DIALECT_HAS(C, COMPOUND_LITERAL)

#	define z_2d_line_sint8(a_x, a_y, b_x, b_y) \
		((Z2DLineSInt8){{a_x, a_y}, {b_x, b_y}})

#	define z_3d_line_sint8(a_x, a_y, a_z, b_x, b_y, b_z) \
		((Z3DLineSInt8){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#	define z_box_sint8(point_x, point_y, point_z, size_x, size_y, size_z) \
		((ZBoxSInt8){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#	define z_rectangle_sint8(point_x, point_y, size_x, size_y) \
		((ZRectangleSInt8){{point_x, point_y}, {size_x, size_y}})

#	define z_2d_line_sint16(a_x, a_y, b_x, b_y) \
		((Z2DLineSInt16){{a_x, a_y}, {b_x, b_y}})

#	define z_3d_line_sint16(a_x, a_y, a_z, b_x, b_y, b_z) \
		((Z3DLineSInt16){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#	define z_box_sint16(point_x, point_y, point_z, size_x, size_y, size_z) \
		((ZBoxSInt16){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#	define z_rectangle_sint16(point_x, point_y, size_x, size_y) \
		((ZRectangleSInt16){{point_x, point_y}, {size_x, size_y}})

#	define z_2d_line_sint32(a_x, a_y, b_x, b_y) \
		((Z2DLineSInt32){{a_x, a_y}, {b_x, b_y}})

#	define z_3d_line_sint32(a_x, a_y, a_z, b_x, b_y, b_z) \
		((Z3DLineSInt32){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#	define z_box_sint32(point_x, point_y, point_z, size_x, size_y, size_z) \
		((ZBoxSInt32){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#	define z_rectangle_sint32(point_x, point_y, size_x, size_y) \
		((ZRectangleSInt32){{point_x, point_y}, {size_x, size_y}})

#	ifdef Z_SINT64

#		define z_2d_line_sint64(a_x, a_y, b_x, b_y) \
			((Z2DLineSInt64){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_line_sint64(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DLineSInt64){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_box_sint64(point_x, point_y, point_z, size_x, size_y, size_z) \
			((ZBoxSInt64){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#		define z_rectangle_sint64(point_x, point_y, size_x, size_y) \
			((ZRectangleSInt64){{point_x, point_y}, {size_x, size_y}})

#	endif

#	ifdef Z_SINT128

#		define z_2d_line_sint128(a_x, a_y, b_x, b_y) \
			((Z2DLineSInt128){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_line_sint128(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DLineSInt128){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_box_sint128(point_x, point_y, point_z, size_x, size_y, size_z) \
			((ZBoxSInt128){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#		define z_rectangle_sint128(point_x, point_y, size_x, size_y) \
			((ZRectangleSInt128){{point_x, point_y}, {size_x, size_y}})

#	endif

#	ifdef Z_FLOAT16

#		define z_2d_line_float16(a_x, a_y, b_x, b_y) \
			((Z2DLineFloat16){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_line_float16(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DLineFloat16){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_box_float16(point_x, point_y, point_z, size_x, size_y, size_z) \
			((ZBoxFloat16){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#		define z_circle_float16(point_x, point_y, radius) \
			((ZCircleFloat16){{point_x, point_y}, radius})

#		define z_rectangle_float16(point_x, point_y, size_x, size_y) \
			((ZRectangleFloat16){{point_x, point_y}, {size_x, size_y}})

#		define z_sphere_float16(point_x, point_y, point_z, radius) \
			((ZCircleFloat16){{point_x, point_y, point_z}, radius})

#	endif

#	ifdef Z_FLOAT32

#		define z_2d_line_float32(a_x, a_y, b_x, b_y) \
			((Z2DLineFloat32){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_line_float32(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DLineFloat32){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_box_float32(point_x, point_y, point_z, size_x, size_y, size_z) \
			((ZBoxFloat32){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#		define z_circle_float32(point_x, point_y, radius) \
			((ZCircleFloat32){{point_x, point_y}, radius})

#		define z_rectangle_float32(point_x, point_y, size_x, size_y) \
			((ZRectangleFloat32){{point_x, point_y}, {size_x, size_y}})

#		define z_sphere_float32(point_x, point_y, point_z, radius) \
			((ZCircleFloat32){{point_x, point_y, point_z}, radius})

#	endif

#	ifdef Z_FLOAT64

#		define z_2d_line_float64(a_x, a_y, b_x, b_y) \
			((Z2DLineFloat64){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_line_float64(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DLineFloat64){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_box_float64(point_x, point_y, point_z, size_x, size_y, size_z) \
			((ZBoxFloat64){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#		define z_circle_float64(point_x, point_y, radius) \
			((ZCircleFloat64){{point_x, point_y}, radius})

#		define z_rectangle_float64(point_x, point_y, size_x, size_y) \
			((ZRectangleFloat64){{point_x, point_y}, {size_x, size_y}})

#		define z_sphere_float64(point_x, point_y, point_z, radius) \
			((ZCircleFloat64){{point_x, point_y, point_z}, radius})

#	endif

#	ifdef Z_FLOAT128

#		define z_2d_line_float128(a_x, a_y, b_x, b_y) \
			((Z2DLineFloat128){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_line_float128(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DLineFloat128){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_box_float128(point_x, point_y, point_z, size_x, size_y, size_z) \
			((ZBoxFloat128){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#		define z_circle_float128(point_x, point_y, radius) \
			((ZCircleFloat128){{point_x, point_y}, radius})

#		define z_rectangle_float128(point_x, point_y, size_x, size_y) \
			((ZRectangleFloat128){{point_x, point_y}, {size_x, size_y}})

#		define z_sphere_float128(point_x, point_y, point_z, radius) \
			((ZCircleFloat128){{point_x, point_y, point_z}, radius})

#	endif

#	ifdef Z_FLOAT80_X87

#		define z_2d_line_float80_x87(a_x, a_y, b_x, b_y) \
			((Z2DLineFloat80_x87){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_line_float80_x87(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DLineFloat80_x87){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_box_float80_x87(point_x, point_y, point_z, size_x, size_y, size_z) \
			((ZBoxFloat80_x87){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#		define z_circle_float80_x87(point_x, point_y, radius) \
			((ZCircleFloat80_x87){{point_x, point_y}, radius})

#		define z_rectangle_float80_x87(point_x, point_y, size_x, size_y) \
			((ZRectangleFloat80_x87){{point_x, point_y}, {size_x, size_y}})

#		define z_sphere_float80_x87(point_x, point_y, point_z, radius) \
			((ZCircleFloat80_x87){{point_x, point_y, point_z}, radius})

#	endif

#	ifdef Z_FLOAT96_X87

#		define z_2d_line_float96_x87(a_x, a_y, b_x, b_y) \
			((Z2DLineFloat96_x87){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_line_float96_x87(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DLineFloat96_x87){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_box_float96_x87(point_x, point_y, point_z, size_x, size_y, size_z) \
			((ZBoxFloat96_x87){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#		define z_circle_float96_x87(point_x, point_y, radius) \
			((ZCircleFloat96_x87){{point_x, point_y}, radius})

#		define z_rectangle_float96_x87(point_x, point_y, size_x, size_y) \
			((ZRectangleFloat96_x87){{point_x, point_y}, {size_x, size_y}})

#		define z_sphere_float96_x87(point_x, point_y, point_z, radius) \
			((ZCircleFloat96_x87){{point_x, point_y, point_z}, radius})

#	endif

#	ifdef Z_FLOAT128_X87

#		define z_2d_line_float128_x87(a_x, a_y, b_x, b_y) \
			((Z2DLineFloat128_x87){{a_x, a_y}, {b_x, b_y}})

#		define z_3d_line_float128_x87(a_x, a_y, a_z, b_x, b_y, b_z) \
			((Z3DLineFloat128_x87){{a_x, a_y, a_z}, {b_x, b_y, b_z}})

#		define z_box_float128_x87(point_x, point_y, point_z, size_x, size_y, size_z) \
			((ZBoxFloat128_x87){{point_x, point_y, point_z}, {size_x, size_y, size_z}})

#		define z_circle_float128_x87(point_x, point_y, radius) \
			((ZCircleFloat128_x87){{point_x, point_y}, radius})

#		define z_rectangle_float128_x87(point_x, point_y, size_x, size_y) \
			((ZRectangleFloat128_x87){{point_x, point_y}, {size_x, size_y}})

#		define z_sphere_float128_x87(point_x, point_y, point_z, radius) \
			((ZCircleFloat128_x87){{point_x, point_y, point_z}, radius})

#	endif

#else

#	define Z_CONSTRUCTORS_INTEGER(Type, type)	     \
							     \
	static Z_INLINE Z2DLine##Type z_2d_line_##type(	     \
		z##type a_x,				     \
		z##type a_y,				     \
		z##type b_x,				     \
		z##type b_y				     \
	)						     \
		{					     \
		Z2DLine##Type object;			     \
							     \
		object.a.x = a_x;			     \
		object.a.y = a_y;			     \
		object.b.x = b_x;			     \
		object.b.y = b_y;			     \
		return object;				     \
		}					     \
							     \
							     \
	static Z_INLINE Z3DLine##Type z_3d_line_##type(	     \
		z##type a_x,				     \
		z##type a_y,				     \
		z##type a_z,				     \
		z##type b_x,				     \
		z##type b_y,				     \
		z##type b_z				     \
	)						     \
		{					     \
		Z3DLine##Type object;			     \
							     \
		object.a.x = a_x;			     \
		object.a.y = a_y;			     \
		object.a.z = a_z;			     \
		object.b.x = b_x;			     \
		object.b.y = b_y;			     \
		object.b.z = b_z;			     \
		return object;				     \
		}					     \
							     \
							     \
	static Z_INLINE ZBox##Type z_box_##type(	     \
		z##type point_x,			     \
		z##type point_y,			     \
		z##type point_z,			     \
		z##type size_x,				     \
		z##type size_y,				     \
		z##type size_z				     \
	)						     \
		{					     \
		ZBox##Type object;			     \
							     \
		object.point.x = point_x;		     \
		object.point.y = point_y;		     \
		object.point.z = point_z;		     \
		object.size.x  = size_x;		     \
		object.size.y  = size_y;		     \
		object.size.z  = size_z;		     \
		return object;				     \
		}					     \
							     \
							     \
	static Z_INLINE ZRectangle##Type z_rectangle_##type( \
		z##type point_x,			     \
		z##type point_y,			     \
		z##type size_x,				     \
		z##type size_y				     \
	)						     \
		{					     \
		ZRectangle##Type object;		     \
							     \
		object.point.x = point_x;		     \
		object.point.y = point_y;		     \
		object.size.x  = size_x;		     \
		object.size.y  = size_y;		     \
		return object;				     \
		}


#	define Z_CONSTRUCTORS_REAL(Type, type)	       \
						       \
	static Z_INLINE ZCircle##Type z_circle_##type( \
		z##type point_x,		       \
		z##type point_y,		       \
		z##type radius			       \
	)					       \
		{				       \
		ZCircle##Type object;		       \
						       \
		object.point.x = point_x;	       \
		object.point.y = point_y;	       \
		object.radius  = radius;	       \
		return object;			       \
		}				       \
						       \
						       \
	static Z_INLINE ZSphere##Type z_sphere_##type( \
		z##type point_x,		       \
		z##type point_y,		       \
		z##type point_z,		       \
		z##type radius			       \
	)					       \
		{				       \
		ZSphere##Type object;		       \
						       \
		object.point.x = point_x;	       \
		object.point.y = point_y;	       \
		object.point.z = point_z;	       \
		object.radius  = radius;	       \
		return object;			       \
		}


	Z_CONSTRUCTORS_INTEGER(SInt8,  sint8 )
	Z_CONSTRUCTORS_INTEGER(SInt16, sint16)
	Z_CONSTRUCTORS_INTEGER(SInt32, sint32)

#	ifdef Z_SINT64
		Z_CONSTRUCTORS_INTEGER(SInt64, sint64)
#	endif

#	ifdef Z_SINT128
		Z_CONSTRUCTORS_INTEGER(SInt128, sint128)
#	endif

#	ifdef Z_FLOAT16
		Z_CONSTRUCTORS_INTEGER(Float16, float16)
		Z_CONSTRUCTORS_REAL   (Float16, float16)
#	endif

#	ifdef Z_FLOAT32
		Z_CONSTRUCTORS_INTEGER(Float32, float32)
		Z_CONSTRUCTORS_REAL   (Float32, float32)
#	endif

#	ifdef Z_FLOAT64
		Z_CONSTRUCTORS_INTEGER(Float64, float64)
		Z_CONSTRUCTORS_REAL   (Float64, float64)
#	endif

#	ifdef Z_FLOAT128
		Z_CONSTRUCTORS_INTEGER(Float128, float128)
		Z_CONSTRUCTORS_REAL   (Float128, float128)
#	endif

#	ifdef Z_FLOAT80_X87
		Z_CONSTRUCTORS_INTEGER(Float80_x87, float80_x87)
		Z_CONSTRUCTORS_REAL   (Float80_x87, float80_x87)
#	endif

#	ifdef Z_FLOAT96_X87
		Z_CONSTRUCTORS_INTEGER(Float96_x87, float96_x87)
		Z_CONSTRUCTORS_REAL   (Float96_x87, float96_x87)
#	endif

#	ifdef Z_FLOAT128_X87
		Z_CONSTRUCTORS_INTEGER(Float128_x87, float128_x87)
		Z_CONSTRUCTORS_REAL   (Float128_x87, float128_x87)
#	endif

#	undef Z_CONSTRUCTORS_INTEGER
#	undef Z_CONSTRUCTORS_REAL

#endif

#define z_2d_line_sint8_0   z_2d_line_sint8  (0.0, 0.0, 0.0, 0.0)
#define z_3d_line_sint8_0   z_3d_line_sint8  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_box_sint8_0	    z_box_sint8	     (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_rectangle_sint8_0 z_rectangle_sint8(0.0, 0.0, 0.0, 0.0)
#define z_aabb_sint8	    z_3d_line_sint8
#define z_aabb_sint8_0	    z_3d_line_sint8_0
#define z_aabr_sint8	    z_2d_line_sint8
#define z_aabr_sint8_0	    z_2d_line_sint8_0

#define z_2d_line_sint16_0   z_2d_line_sint16  (0.0, 0.0, 0.0, 0.0)
#define z_3d_line_sint16_0   z_3d_line_sint16  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_box_sint16_0	     z_box_sint16      (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_rectangle_sint16_0 z_rectangle_sint16(0.0, 0.0, 0.0, 0.0)
#define z_aabb_sint16	     z_3d_line_sint16
#define z_aabb_sint16_0	     z_3d_line_sint16_0
#define z_aabr_sint16	     z_2d_line_sint16
#define z_aabr_sint16_0	     z_2d_line_sint16_0

#define z_2d_line_sint32_0   z_2d_line_sint32  (0.0, 0.0, 0.0, 0.0)
#define z_3d_line_sint32_0   z_3d_line_sint32  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_box_sint32_0	     z_box_sint32      (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_rectangle_sint32_0 z_rectangle_sint32(0.0, 0.0, 0.0, 0.0)
#define z_aabb_sint32	     z_3d_line_sint32
#define z_aabb_sint32_0	     z_3d_line_sint32_0
#define z_aabr_sint32	     z_2d_line_sint32
#define z_aabr_sint32_0	     z_2d_line_sint32_0

#ifdef Z_SINT64
#	define z_2d_line_sint64_0   z_2d_line_sint64  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_sint64_0   z_3d_line_sint64  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_box_sint64_0	    z_box_sint64      (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_rectangle_sint64_0 z_rectangle_sint64(0.0, 0.0, 0.0, 0.0)
#	define z_aabb_sint64	    z_3d_line_sint64
#	define z_aabb_sint64_0	    z_3d_line_sint64_0
#	define z_aabr_sint64	    z_2d_line_sint64
#	define z_aabr_sint64_0	    z_2d_line_sint64_0
#endif

#ifdef Z_SINT128
#	define z_2d_line_sint128_0   z_2d_line_sint128	(0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_sint128_0   z_3d_line_sint128	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_box_sint128_0	     z_box_sint128	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_rectangle_sint128_0 z_rectangle_sint128(0.0, 0.0, 0.0, 0.0)
#	define z_aabb_sint128	     z_3d_line_sint128
#	define z_aabb_sint128_0	     z_3d_line_sint128_0
#	define z_aabr_sint128	     z_2d_line_sint128
#	define z_aabr_sint128_0	     z_2d_line_sint128_0
#endif

#ifdef Z_FLOAT16
#	define z_2d_line_float16_0   z_2d_line_float16	(0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float16_0   z_3d_line_float16	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_box_float16_0	     z_box_float16	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float16_0    z_circle_float16	(0.0, 0.0, 0.0)
#	define z_rectangle_float16_0 z_rectangle_float16(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float16_0    z_sphere_float16	(0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float16	     z_3d_line_float16
#	define z_aabb_float16_0	     z_3d_line_float16_0
#	define z_aabr_float16	     z_2d_line_float16
#	define z_aabr_float16_0	     z_2d_line_float16_0
#endif

#ifdef Z_FLOAT32
#	define z_2d_line_float32_0   z_2d_line_float32	(0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float32_0   z_3d_line_float32	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_box_float32_0	     z_box_float32	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float32_0    z_circle_float32	(0.0, 0.0, 0.0)
#	define z_rectangle_float32_0 z_rectangle_float32(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float32_0    z_sphere_float32	(0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float32	     z_3d_line_float32
#	define z_aabb_float32_0	     z_3d_line_float32_0
#	define z_aabr_float32	     z_2d_line_float32
#	define z_aabr_float32_0	     z_2d_line_float32_0
#endif

#ifdef Z_FLOAT64
#	define z_2d_line_float64_0   z_2d_line_float64	(0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float64_0   z_3d_line_float64	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_box_float64_0	     z_box_float64	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float64_0    z_circle_float64	(0.0, 0.0, 0.0)
#	define z_rectangle_float64_0 z_rectangle_float64(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float64_0    z_sphere_float64	(0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float64	     z_3d_line_float64
#	define z_aabb_float64_0	     z_3d_line_float64_0
#	define z_aabr_float64	     z_2d_line_float64
#	define z_aabr_float64_0	     z_2d_line_float64_0
#endif

#ifdef Z_FLOAT128
#	define z_2d_line_float128_0   z_2d_line_float128  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float128_0   z_3d_line_float128  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_box_float128_0	      z_box_float128	  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float128_0    z_circle_float128	  (0.0, 0.0, 0.0)
#	define z_rectangle_float128_0 z_rectangle_float128(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float128_0    z_sphere_float128	  (0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float128	      z_3d_line_float128
#	define z_aabb_float128_0      z_3d_line_float128_0
#	define z_aabr_float128	      z_2d_line_float128
#	define z_aabr_float128_0      z_2d_line_float128_0
#endif

#ifdef Z_FLOAT80_X87
#	define z_2d_line_float80_x87_0	 z_2d_line_float80_x87	(0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float80_x87_0	 z_3d_line_float80_x87	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_box_float80_x87_0	 z_box_float80_x87	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float80_x87_0	 z_circle_float80_x87	(0.0, 0.0, 0.0)
#	define z_rectangle_float80_x87_0 z_rectangle_float80_x87(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float80_x87_0	 z_sphere_float80_x87	(0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float80_x87	 z_3d_line_float80_x87
#	define z_aabb_float80_x87_0	 z_3d_line_float80_x87_0
#	define z_aabr_float80_x87	 z_2d_line_float80_x87
#	define z_aabr_float80_x87_0	 z_2d_line_float80_x87_0
#endif

#ifdef Z_FLOAT96_X87
#	define z_2d_line_float96_x87_0	 z_2d_line_float96_x87	(0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float96_x87_0	 z_3d_line_float96_x87	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_box_float96_x87_0	 z_box_float96_x87	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float96_x87_0	 z_circle_float96_x87	(0.0, 0.0, 0.0)
#	define z_rectangle_float96_x87_0 z_rectangle_float96_x87(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float96_x87_0	 z_sphere_float96_x87	(0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float96_x87	 z_3d_line_float96_x87
#	define z_aabb_float96_x87_0	 z_3d_line_float96_x87_0
#	define z_aabr_float96_x87	 z_2d_line_float96_x87
#	define z_aabr_float96_x87_0	 z_2d_line_float96_x87_0
#endif

#ifdef Z_FLOAT128_X87
#	define z_2d_line_float128_x87_0	  z_2d_line_float128_x87  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float128_x87_0	  z_3d_line_float128_x87  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_box_float128_x87_0	  z_box_float128_x87	  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float128_x87_0	  z_circle_float128_x87	  (0.0, 0.0, 0.0)
#	define z_rectangle_float128_x87_0 z_rectangle_float128_x87(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float128_x87_0	  z_sphere_float128_x87	  (0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float128_x87	  z_3d_line_float128_x87
#	define z_aabb_float128_x87_0	  z_3d_line_float128_x87_0
#	define z_aabr_float128_x87	  z_2d_line_float128_x87
#	define z_aabr_float128_x87_0	  z_2d_line_float128_x87_0
#endif

#define z_2d_line_type(	   TYPE) Z_APPEND_##TYPE##_fixed_type(z_2d_line_      )
#define z_2d_line_type_0(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_,   _0)
#define z_3d_line_type(	   TYPE) Z_APPEND_##TYPE##_fixed_type(z_3d_line_      )
#define z_3d_line_type_0(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_,   _0)
#define z_aabb_type(	   TYPE) Z_APPEND_##TYPE##_fixed_type(z_aabb_	      )
#define z_aabb_type_0(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_,      _0)
#define z_aabr_type(	   TYPE) Z_APPEND_##TYPE##_fixed_type(z_aabr_	      )
#define z_aabr_type_0(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_,      _0)
#define z_box_type(	   TYPE) Z_APPEND_##TYPE##_fixed_type(z_box_type      )
#define z_box_type_0(	   TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_,       _0)
#define z_circle_type(	   TYPE) Z_APPEND_##TYPE##_fixed_type(z_circle_	      )
#define z_circle_type_0(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_,    _0)
#define z_rectangle_type(  TYPE) Z_APPEND_##TYPE##_fixed_type(z_rectangle_    )
#define z_rectangle_type_0(TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _0)
#define z_sphere_type(	   TYPE) Z_APPEND_##TYPE##_fixed_type(z_sphere_	      )
#define z_sphere_type_0(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_,    _0)

/* MARK: - Default real type definitions */

#ifdef Z_REAL
#	define z_2d_line     z_2d_line_type    (REAL)
#	define z_2d_line_0   z_2d_line_type_0  (REAL)
#	define z_3d_line     z_3d_line_type    (REAL)
#	define z_3d_line_0   z_3d_line_type_0  (REAL)
#	define z_box	     z_box_type	       (REAL)
#	define z_box_0	     z_box_type_0      (REAL)
#	define z_circle	     z_circle_type     (REAL)
#	define z_circle_0    z_circle_type_0   (REAL)
#	define z_rectangle   z_rectangle_type  (REAL)
#	define z_rectangle_0 z_rectangle_type_0(REAL)
#	define z_sphere	     z_sphere_type     (REAL)
#	define z_sphere_0    z_sphere_type_0   (REAL)
#	define z_aabb	     z_3d_line
#	define z_aabb_0	     z_3d_line_0
#	define z_aabr	     z_2d_line
#	define z_aabr_0	     z_2d_line_0
#endif

#endif /* Z_types_geometry_H */
