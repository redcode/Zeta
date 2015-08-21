/* Z Kit C API - types/mathematics.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_mathematics_H__
#define __Z_types_mathematics_H__

#include <Z/types/base.h>

/* MARK: - 2D geometry */

typedef struct {Z2DFloat   a, b;}			Z2DVectorFloat;
typedef struct {Z2DDouble  a, b;}			Z2DVectorDouble;
typedef struct {Z2DLDouble a, b;}			Z2DVectorLDouble;

typedef Z2DVectorFloat					Z2DLineFloat;
typedef Z2DVectorDouble					Z2DLineDouble;
typedef Z2DVectorLDouble				Z2DLineLDouble;

typedef struct {Z2DFloat   point; zfloat   angle;}	Z2DRayFloat;
typedef struct {Z2DDouble  point; zdouble  angle;}	Z2DRayDouble;
typedef struct {Z2DLDouble point; zldouble angle;}	Z2DRayLDouble;

typedef struct {Z2DFloat   point, size;}		ZRectangleFloat;
typedef struct {Z2DDouble  point, size;}		ZRectangleDouble;
typedef struct {Z2DLDouble point, size;}		ZRectangleLDouble;

typedef Z2DLineFloat					ZAABRFloat;
typedef Z2DLineDouble					ZAABRDouble;
typedef Z2DLineLDouble					ZAABRLDouble;

typedef struct {}					ZOBRFloat;
typedef struct {}					ZOBRDouble;
typedef struct {}					ZOBRLDouble;

typedef struct {Z2DFloat   point; zfloat   radius;}	ZCircleFloat;
typedef struct {Z2DDouble  point; zdouble  radius;}	ZCircleDouble;
typedef struct {Z2DLDouble point; zldouble radius;}	ZCircleLDouble;

/* MARK: - 3D geometry */

typedef struct {Z3DFloat   a, b;}			Z3DVectorFloat;
typedef struct {Z3DDouble  a, b;}			Z3DVectorDouble;
typedef struct {Z3DLDouble a, b;}			Z3DVectorLDouble;

typedef Z3DVectorFloat					Z3DLineFloat;
typedef Z3DVectorDouble					Z3DLineDouble;
typedef Z3DVectorLDouble				Z3DLineLDouble;

typedef struct {Z3DFloat   point, angle;}		Z3DRayFloat;
typedef struct {Z3DDouble  point, angle;}		Z3DRayDouble;
typedef struct {Z3DLDouble point, angle;}		Z3DRayLDouble;

typedef struct {Z3DFloat   point, size;}		ZBoxFloat;
typedef struct {Z3DDouble  point, size;}		ZBoxDouble;
typedef struct {Z3DLDouble point, size;}		ZBoxLDouble;

typedef Z3DLineFloat					ZAABBFloat;
typedef Z3DLineDouble					ZAABBDouble;
typedef Z3DLineLDouble					ZAABBLDouble;

typedef struct {}					ZOBBFloat;
typedef struct {}					ZOBBDouble;
typedef struct {}					ZOBBLDouble;

typedef struct {Z3DFloat   point; zfloat   radius;}	ZSphereFloat;
typedef struct {Z3DDouble  point; zdouble  radius;}	ZSphereDouble;
typedef struct {Z3DLDouble point; zldouble radius;}	ZSphereLDouble;

typedef struct {Z3DFloat   normal; zfloat   offset;}	ZPlaneFloat;
typedef struct {Z3DDouble  normal; zdouble  offset;}	ZPlaneDouble;
typedef struct {Z3DLDouble normal; zldouble offset;}	ZPlaneLDouble;

/* MARK: - Default real type definitions */

typedef Z_JOIN_2(Z2DVector,  Z_REAL_FIXED_TYPE_Name) Z2DVector;
typedef Z_JOIN_2(Z2DLine,    Z_REAL_FIXED_TYPE_Name) Z2DLine;
typedef Z_JOIN_2(Z2DRay,     Z_REAL_FIXED_TYPE_Name) Z2DRay;
typedef Z_JOIN_2(ZRectangle, Z_REAL_FIXED_TYPE_Name) ZRectangle;
typedef Z_JOIN_2(ZAABR,	     Z_REAL_FIXED_TYPE_Name) ZAABR;
typedef Z_JOIN_2(ZOBR,	     Z_REAL_FIXED_TYPE_Name) ZOBR;
typedef Z_JOIN_2(ZCircle,    Z_REAL_FIXED_TYPE_Name) ZCircle;
typedef	Z_JOIN_2(Z3DVector,  Z_REAL_FIXED_TYPE_Name) Z3DVector;
typedef Z_JOIN_2(Z3DLine,    Z_REAL_FIXED_TYPE_Name) Z3DLine;
typedef Z_JOIN_2(Z3DRay,     Z_REAL_FIXED_TYPE_Name) Z3DRay;
typedef Z_JOIN_2(ZBox,	     Z_REAL_FIXED_TYPE_Name) ZBox;
typedef Z_JOIN_2(ZAABB,	     Z_REAL_FIXED_TYPE_Name) ZAABB;
typedef Z_JOIN_2(ZOBB,	     Z_REAL_FIXED_TYPE_Name) ZOBB;
typedef Z_JOIN_2(ZSphere,    Z_REAL_FIXED_TYPE_Name) ZSphere;
typedef Z_JOIN_2(ZPlane,     Z_REAL_FIXED_TYPE_Name) ZPlane;

/* MARK: - Casts */

#define Z_2D_VECTOR_FLOAT(  p) ((Z2DVectorFloat	   *)(p))
#define Z_2D_VECTOR_DOUBLE( p) ((Z2DVectorDouble   *)(p))
#define Z_2D_VECTOR_LDOUBLE(p) ((Z2DVectorLDouble  *)(p))
#define Z_2D_VECTOR(	    p) ((Z2DVector	   *)(p))
#define Z_2D_LINE_FLOAT(    p) ((Z2DLineFloat	   *)(p))
#define Z_2D_LINE_DOUBLE(   p) ((Z2DLineDouble	   *)(p))
#define Z_2D_LINE_LDOUBLE(  p) ((Z2DLineLDouble	   *)(p))
#define Z_2D_LINE(	    p) ((Z2Dine		   *)(p))
#define Z_2D_RAY_FLOAT(     p) ((Z2DRayFloat	   *)(p))
#define Z_2D_RAY_DOUBLE(    p) ((Z2DRayDouble	   *)(p))
#define Z_2D_RAY_LDOUBLE(   p) ((Z2DRayLDouble	   *)(p))
#define Z_2D_RAY(	    p) ((Z2DRay		   *)(p))
#define Z_RECTANGLE_FLOAT(  p) ((ZRectangleFloat   *)(p))
#define Z_RECTANGLE_DOUBLE( p) ((ZRectangleDouble  *)(p))
#define Z_RECTANGLE_LDOUBLE(p) ((ZRectangleLDouble *)(p))
#define Z_RECTANGLE(	    p) ((ZRectangle	   *)(p))
#define Z_AABR_FLOAT(	    p) ((ZAABRFloat	   *)(p))
#define Z_AABR_DOUBLE(	    p) ((ZAABRDouble	   *)(p))
#define Z_AABR_LDOUBLE(     p) ((ZAABRLDouble	   *)(p))
#define Z_AABR(		    p) ((ZAABR		   *)(p))
#define Z_OBR_FLOAT(	    p) ((ZOBRFloat	   *)(p))
#define Z_OBR_DOUBLE(	    p) ((ZOBRDouble	   *)(p))
#define Z_OBR_LDOUBLE(	    p) ((ZOBRLDouble	   *)(p))
#define Z_OBR(		    p) ((ZOBR		   *)(p))
#define Z_CIRCLE_FLOAT(     p) ((ZCircleFloat	   *)(p))
#define Z_CIRCLE_DOUBLE(    p) ((ZCircleDouble	   *)(p))
#define Z_CIRCLE_LDOUBLE(   p) ((ZCircleLDouble    *)(p))
#define Z_CIRCLE(	    p) ((ZCircle	   *)(p))
#define Z_3D_VECTOR_FLOAT(  p) ((Z3DVectorFloat    *)(p))
#define Z_3D_VECTOR_DOUBLE( p) ((Z3DVectorDouble   *)(p))
#define Z_3D_VECTOR_LDOUBLE(p) ((Z3DVectorLDouble  *)(p))
#define Z_3D_VECTOR(	    p) ((Z3DVector	   *)(p))
#define Z_3D_LINE_FLOAT(    p) ((Z3DLineFloat	   *)(p))
#define Z_3D_LINE_DOUBLE(   p) ((Z3DLineDouble	   *)(p))
#define Z_3D_LINE_LDOUBLE(  p) ((Z3DLineLDouble    *)(p))
#define Z_3D_LINE(	    p) ((Z3DLine	   *)(p))
#define Z_3D_RAY_FLOAT(     p) ((Z3DRayFloat	   *)(p))
#define Z_3D_RAY_DOUBLE(    p) ((Z3DRayDouble	   *)(p))
#define Z_3D_RAY_LDOUBLE(   p) ((Z3DRayLDouble	   *)(p))
#define Z_3D_RAY(	    p) ((Z3DRay		   *)(p))
#define Z_BOX_FLOAT(	    p) ((ZBoxFloat	   *)(p))
#define Z_BOX_DOUBLE(	    p) ((ZBoxDouble	   *)(p))
#define Z_BOX_LDOUBLE(	    p) ((ZBoxLDouble	   *)(p))
#define Z_BOX(		    p) ((ZBox		   *)(p))
#define Z_AABB_FLOAT(	    p) ((ZAABBFloat	   *)(p))
#define Z_AABB_DOUBLE(	    p) ((ZAABBDouble	   *)(p))
#define Z_AABB_LDOUBLE(     p) ((ZAABBLDouble	   *)(p))
#define Z_AABB(		    p) ((ZAABB		   *)(p))
#define Z_OBB_FLOAT(	    p) ((ZOBBFloat	   *)(p))
#define Z_OBB_DOUBLE(	    p) ((ZOBBDouble	   *)(p))
#define Z_OBB_LDOUBLE(	    p) ((ZOBBLDouble	   *)(p))
#define Z_OBB(		    p) ((ZOBB		   *)(p))
#define Z_SPHERE_FLOAT(     p) ((ZSphereFloat	   *)(p))
#define Z_SPHERE_DOUBLE(    p) ((ZSphereDouble	   *)(p))
#define Z_SPHERE_LDOUBLE(   p) ((ZSphereLDouble	   *)(p))
#define Z_SPHERE(	    p) ((ZSphere	   *)(p))
#define Z_PLANE_FLOAT(	    p) ((ZPlaneFloat	   *)(p))
#define Z_PLANE_DOUBLE(     p) ((ZPlaneDouble	   *)(p))
#define Z_PLANE_LDOUBLE(    p) ((ZPlaneLDouble	   *)(p))
#define Z_PLANE(	    p) ((ZPlane		   *)(p))

#endif /* __Z_types_mathematics_H__ */
