/* Z Kit C API - types/mathematics.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_mathematics_H__
#define __Z_types_mathematics_H__

#include <Z/types/base.h>

/* MARK: - Euclidean geometry */

#define Z_TYPES_EUCLIDEAN_GEOMETRY(Type, type)			     \
typedef struct {Z2D##Type a, b;}		   Z2DLine##Type;    \
typedef struct {Z3D##Type a, b;}		   Z3DLine##Type;    \
typedef struct {Z2D##Type point; z##type angle;}   Z2DRay##Type;     \
typedef struct {Z3D##Type point; z##type angle;}   Z3DRay##Type;     \
typedef struct {Z2D##Type point, size;}		   ZRectangle##Type; \
typedef struct {Z3D##Type point, size;}		   ZBox##Type;	     \
typedef Z2DLine##Type				   ZAABR##Type;	     \
typedef Z3DLine##Type				   ZAABB##Type;	     \
typedef struct {Z2D##Type point; z##type radius;}  ZCircle##Type;    \
typedef struct {Z3D##Type point; z##type radius;}  ZSphere##Type;    \
typedef struct {Z3D##Type normal; z##type offset;} ZPlane##Type;

#define Z2DLineType(   TYPE) Z_INSERT_##TYPE##_FixedType(Z2DLine,   )
#define Z3DLineType(   TYPE) Z_INSERT_##TYPE##_FixedType(Z3DLine,   )
#define Z2DRayType(    TYPE) Z_INSERT_##TYPE##_FixedType(Z2DRay,    )
#define Z3DRayType(    TYPE) Z_INSERT_##TYPE##_FixedType(Z3DRay,    )
#define ZRectangleType(TYPE) Z_INSERT_##TYPE##_FixedType(ZRectangle,)
#define ZBoxType(      TYPE) Z_INSERT_##TYPE##_FixedType(ZBox,	    )
#define ZAABRType(     TYPE) Z_INSERT_##TYPE##_FixedType(ZAABR,	    )
#define ZAABBType(     TYPE) Z_INSERT_##TYPE##_FixedType(ZAABB,	    )
#define ZCircleType(   TYPE) Z_INSERT_##TYPE##_FixedType(ZCircle,   )
#define ZSphereType(   TYPE) Z_INSERT_##TYPE##_FixedType(ZSphere,   )
#define ZPlaneType(    TYPE) Z_INSERT_##TYPE##_FixedType(ZPlane,    )

#ifdef Z_FLOAT16
	Z_TYPES_EUCLIDEAN_GEOMETRY(Float16, float16)
#endif

#ifdef Z_FLOAT24
	Z_TYPES_EUCLIDEAN_GEOMETRY(Float24, float24)
#endif

#ifdef Z_FLOAT32
	Z_TYPES_EUCLIDEAN_GEOMETRY(Float32, float32)
#endif

#ifdef Z_FLOAT48
	Z_TYPES_EUCLIDEAN_GEOMETRY(Float48, float48)
#endif

#ifdef Z_FLOAT64
	Z_TYPES_EUCLIDEAN_GEOMETRY(Float64, float64)
#endif

#ifdef Z_FLOAT72
	Z_TYPES_EUCLIDEAN_GEOMETRY(Float72, float72)
#endif

#ifdef Z_FLOAT80
	Z_TYPES_EUCLIDEAN_GEOMETRY(Float80, float80)
#endif

#ifdef Z_FLOAT96
	Z_TYPES_EUCLIDEAN_GEOMETRY(Float96, float96)
#endif

#ifdef Z_FLOAT128
	Z_TYPES_EUCLIDEAN_GEOMETRY(Float128, float128)
#endif

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
	zsize	  size;
	ZSetNode* last_node;
};

struct ZSetElement {
	ZSetNode* first_node;
	zsize	  set_count;
	ZSetNode* last_node;
};

/* MARK: - Default real type definitions */

#ifdef Z_REAL
	typedef Z2DLineType   (REAL) Z2DLine;
	typedef Z3DLineType   (REAL) Z3DLine;
	typedef Z2DRayType    (REAL) Z2DRay;
	typedef Z3DRayType    (REAL) Z3DRay;
	typedef ZRectangleType(REAL) ZRectangle;
	typedef ZBoxType      (REAL) ZBox;
	typedef ZAABRType     (REAL) ZAABR;
	typedef ZAABBType     (REAL) ZAABB;
	typedef ZCircleType   (REAL) ZCircle;
	typedef ZSphereType   (REAL) ZSphere;
	typedef ZPlaneType    (REAL) ZPlane;
#endif

#endif /* __Z_types_mathematics_H__ */
