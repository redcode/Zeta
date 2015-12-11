/* Z Kit C API - types/mathematics.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_mathematics_H__
#define __Z_types_mathematics_H__

#include <Z/macros/templating.h>

#if Z_IS_AVAILABLE(FLOAT16)
	typedef struct {Z2DFloat16 a, b;}			Z2DLineFloat16;
	typedef struct {Z3DFloat16 a, b;}			Z3DLineFloat16;
	typedef struct {Z2DFloat16 point; zfloat16 angle;}	Z2DRayFloat16;
	typedef struct {Z3DFloat16 point; zfloat16 angle;}	Z3DRayFloat16;
	typedef struct {Z2DFloat16 point, size;}		ZRectangleFloat16;
	typedef struct {Z3DFloat16 point, size;}		ZBoxFloat16;
	typedef Z2DLineFloat16					ZAABRFloat16;
	typedef Z3DLineFloat16					ZAABBFloat16;
	typedef struct {Z2DFloat16 point; zfloat16 radius;}	ZCircleFloat16;
	typedef struct {Z3DFloat16 point; zfloat16 radius;}	ZSphereFloat16;
	typedef struct {Z3DFloat16 normal; zfloat16 offset;}	ZPlaneFloat16;
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	typedef struct {Z2DFloat24 a, b;}			Z2DLineFloat24;
	typedef struct {Z3DFloat24 a, b;}			Z3DLineFloat24;
	typedef struct {Z2DFloat24 point; zfloat24 angle;}	Z2DRayFloat24;
	typedef struct {Z3DFloat24 point; zfloat24 angle;}	Z3DRayFloat24;
	typedef struct {Z2DFloat24 point, size;}		ZRectangleFloat24;
	typedef struct {Z3DFloat24 point, size;}		ZBoxFloat24;
	typedef Z2DLineFloat24					ZAABRFloat24;
	typedef Z3DLineFloat24					ZAABBFloat24;
	typedef struct {Z2DFloat24 point; zfloat24 radius;}	ZCircleFloat24;
	typedef struct {Z3DFloat24 point; zfloat24 radius;}	ZSphereFloat24;
	typedef struct {Z3DFloat24 normal; zfloat24 offset;}	ZPlaneFloat24;
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	typedef struct {Z2DFloat32 a, b;}			Z2DLineFloat32;
	typedef struct {Z3DFloat32 a, b;}			Z3DLineFloat32;
	typedef struct {Z2DFloat32 point; zfloat32 angle;}	Z2DRayFloat32;
	typedef struct {Z3DFloat32 point; zfloat32 angle;}	Z3DRayFloat32;
	typedef struct {Z2DFloat32 point, size;}		ZRectangleFloat32;
	typedef struct {Z3DFloat32 point, size;}		ZBoxFloat32;
	typedef Z2DLineFloat32					ZAABRFloat32;
	typedef Z3DLineFloat32					ZAABBFloat32;
	typedef struct {Z2DFloat32 point; zfloat32 radius;}	ZCircleFloat32;
	typedef struct {Z3DFloat32 point; zfloat32 radius;}	ZSphereFloat32;
	typedef struct {Z3DFloat32 normal; zfloat32 offset;}	ZPlaneFloat32;
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	typedef struct {Z2DFloat48 a, b;}			Z2DLineFloat48;
	typedef struct {Z3DFloat48 a, b;}			Z3DLineFloat48;
	typedef struct {Z2DFloat48 point; zfloat48 angle;}	Z2DRayFloat48;
	typedef struct {Z3DFloat48 point; zfloat48 angle;}	Z3DRayFloat48;
	typedef struct {Z2DFloat48 point, size;}		ZRectangleFloat48;
	typedef struct {Z3DFloat48 point, size;}		ZBoxFloat48;
	typedef Z2DLineFloat48					ZAABRFloat48;
	typedef Z3DLineFloat48					ZAABBFloat48;
	typedef struct {Z2DFloat48 point; zfloat48 radius;}	ZCircleFloat48;
	typedef struct {Z3DFloat48 point; zfloat48 radius;}	ZSphereFloat48;
	typedef struct {Z3DFloat48 normal; zfloat48 offset;}	ZPlaneFloat48;
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	typedef struct {Z2DFloat64 a, b;}			Z2DLineFloat64;
	typedef struct {Z3DFloat64 a, b;}			Z3DLineFloat64;
	typedef struct {Z2DFloat64 point; zfloat64 angle;}	Z2DRayFloat64;
	typedef struct {Z3DFloat64 point; zfloat64 angle;}	Z3DRayFloat64;
	typedef struct {Z2DFloat64 point, size;}		ZRectangleFloat64;
	typedef struct {Z3DFloat64 point, size;}		ZBoxFloat64;
	typedef Z2DLineFloat64					ZAABRFloat64;
	typedef Z3DLineFloat64					ZAABBFloat64;
	typedef struct {Z2DFloat64 point; zfloat64 radius;}	ZCircleFloat64;
	typedef struct {Z3DFloat64 point; zfloat64 radius;}	ZSphereFloat64;
	typedef struct {Z3DFloat64 normal; zfloat64 offset;}	ZPlaneFloat64;
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	typedef struct {Z2DFloat72 a, b;}			Z2DLineFloat72;
	typedef struct {Z3DFloat72 a, b;}			Z3DLineFloat72;
	typedef struct {Z2DFloat72 point; zfloat72 angle;}	Z2DRayFloat72;
	typedef struct {Z3DFloat72 point; zfloat72 angle;}	Z3DRayFloat72;
	typedef struct {Z2DFloat72 point, size;}		ZRectangleFloat72;
	typedef struct {Z3DFloat72 point, size;}		ZBoxFloat72;
	typedef Z2DLineFloat72					ZAABRFloat72;
	typedef Z3DLineFloat72					ZAABBFloat72;
	typedef struct {Z2DFloat72 point; zfloat72 radius;}	ZCircleFloat72;
	typedef struct {Z3DFloat72 point; zfloat72 radius;}	ZSphereFloat72;
	typedef struct {Z3DFloat72 normal; zfloat72 offset;}	ZPlaneFloat72;
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	typedef struct {Z2DFloat80 a, b;}			Z2DLineFloat80;
	typedef struct {Z3DFloat80 a, b;}			Z3DLineFloat80;
	typedef struct {Z2DFloat80 point; zfloat80 angle;}	Z2DRayFloat80;
	typedef struct {Z3DFloat80 point; zfloat80 angle;}	Z3DRayFloat80;
	typedef struct {Z2DFloat80 point, size;}		ZRectangleFloat80;
	typedef struct {Z3DFloat80 point, size;}		ZBoxFloat80;
	typedef Z2DLineFloat80					ZAABRFloat80;
	typedef Z3DLineFloat80					ZAABBFloat80;
	typedef struct {Z2DFloat80 point; zfloat80 radius;}	ZCircleFloat80;
	typedef struct {Z3DFloat80 point; zfloat80 radius;}	ZSphereFloat80;
	typedef struct {Z3DFloat80 normal; zfloat80 offset;}	ZPlaneFloat80;
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	typedef struct {Z2DFloat96 a, b;}			Z2DLineFloat96;
	typedef struct {Z3DFloat96 a, b;}			Z3DLineFloat96;
	typedef struct {Z2DFloat96 point; zfloat96 angle;}	Z2DRayFloat96;
	typedef struct {Z3DFloat96 point; zfloat96 angle;}	Z3DRayFloat96;
	typedef struct {Z2DFloat96 point, size;}		ZRectangleFloat96;
	typedef struct {Z3DFloat96 point, size;}		ZBoxFloat96;
	typedef Z2DLineFloat96					ZAABRFloat96;
	typedef Z3DLineFloat96					ZAABBFloat96;
	typedef struct {Z2DFloat96 point; zfloat96 radius;}	ZCircleFloat96;
	typedef struct {Z3DFloat96 point; zfloat96 radius;}	ZSphereFloat96;
	typedef struct {Z3DFloat96 normal; zfloat96 offset;}	ZPlaneFloat96;
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	typedef struct {Z2DFloat128 a, b;}			Z2DLineFloat128;
	typedef struct {Z3DFloat128 a, b;}			Z3DLineFloat128;
	typedef struct {Z2DFloat128 point; zfloat128 angle;}	Z2DRayFloat128;
	typedef struct {Z3DFloat128 point; zfloat128 angle;}	Z3DRayFloat128;
	typedef struct {Z2DFloat128 point, size;}		ZRectangleFloat128;
	typedef struct {Z3DFloat128 point, size;}		ZBoxFloat128;
	typedef Z2DLineFloat128					ZAABRFloat128;
	typedef Z3DLineFloat128					ZAABBFloat128;
	typedef struct {Z2DFloat128 point; zfloat128 radius;}	ZCircleFloat128;
	typedef struct {Z3DFloat128 point; zfloat128 radius;}	ZSphereFloat128;
	typedef struct {Z3DFloat128 normal; zfloat128 offset;}	ZPlaneFloat128;
#endif

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

/* MARK: - Default real type definitions */

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

#endif /* __Z_types_mathematics_H__ */
