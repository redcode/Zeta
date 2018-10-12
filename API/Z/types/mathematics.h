/* Z Kit - types/mathematics.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_types_mathematics_H_
#define _Z_types_mathematics_H_

#include <Z/types/base.h>

/* MARK: - Euclidean geometry */

#define Z_TYPES_SIGNED(Type, type)			  \
typedef struct {Z2D##Type a, b;}	Z2DLine##Type;    \
typedef struct {Z3D##Type a, b;}	Z3DLine##Type;	  \
typedef Z2DLine##Type			ZAABR##Type;	  \
typedef Z3DLine##Type			ZAABB##Type;	  \
typedef struct {Z2D##Type point, size;}	ZRectangle##Type; \
typedef struct {Z3D##Type point, size;}	ZBox##Type;

#define Z2DLineType(   TYPE) Z_APPEND_##TYPE##_FixedType(Z2DLine   )
#define Z3DLineType(   TYPE) Z_APPEND_##TYPE##_FixedType(Z3DLine   )
#define ZAABRType(     TYPE) Z_APPEND_##TYPE##_FixedType(ZAABR	   )
#define ZAABBType(     TYPE) Z_APPEND_##TYPE##_FixedType(ZAABB	   )
#define ZRectangleType(TYPE) Z_APPEND_##TYPE##_FixedType(ZRectangle)
#define ZBoxType(      TYPE) Z_APPEND_##TYPE##_FixedType(ZBox	   )

#define Z_TYPES_REAL(Type, type)				  \
typedef struct {Z2D##Type point;  z##type radius;} ZCircle##Type; \
typedef struct {Z3D##Type point;  z##type radius;} ZSphere##Type; \
typedef struct {Z2D##Type point;  z##type angle; } Z2DRay##Type;  \
typedef struct {Z3D##Type point;  z##type angle; } Z3DRay##Type;  \
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

/* MARK: - Set theory */

typedef struct ZSet	   ZSet;
typedef struct ZSetElement ZSetElement;

Z_DEFINE_STRUCTURE_WITH_NAME (ZSetNode,
	ZSetNode*    x_next;
	ZSetNode*    x_previous;
	ZSetNode*    y_next;
	ZSetNode*    y_previous;
	ZSet*	     set;
	ZSetElement* element;
);

struct ZSet {
	ZSetNode* first_node;
	zusize	  size;
	ZSetNode* last_node;
};

struct ZSetElement {
	ZSetNode* first_node;
	zusize	  set_count;
	ZSetNode* last_node;
};

/* MARK: - Default real type definitions */

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

#endif /* _Z_types_mathematics_H_ */
