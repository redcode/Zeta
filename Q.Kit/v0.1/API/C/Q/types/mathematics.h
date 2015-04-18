/* Q Kit C API - types/mathematics.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_types_mathematics_H__
#define __Q_types_mathematics_H__

#include <Q/types/base.h>

/* MARK: - 2D geometry */

typedef struct {Q2DFloat   a, b;}			Q2DVectorFloat;
typedef struct {Q2DDouble  a, b;}			Q2DVectorDouble;
typedef struct {Q2DLDouble a, b;}			Q2DVectorLDouble;

typedef Q2DVectorFloat					Q2DLineFloat;
typedef Q2DVectorDouble					Q2DLineDouble;
typedef Q2DVectorLDouble				Q2DLineLDouble;

typedef struct {Q2DFloat   point; qfloat   angle;}	Q2DRayFloat;
typedef struct {Q2DDouble  point; qdouble  angle;}	Q2DRayDouble;
typedef struct {Q2DLDouble point; qldouble angle;}	Q2DRayLDouble;

typedef struct {Q2DFloat   point, size;}		QRectangleFloat;
typedef struct {Q2DDouble  point, size;}		QRectangleDouble;
typedef struct {Q2DLDouble point, size;}		QRectangleLDouble;

typedef Q2DLineFloat					QAABRFloat;
typedef Q2DLineDouble					QAABRDouble;
typedef Q2DLineLDouble					QAABRLDouble;

typedef struct {}					QOBRFloat;
typedef struct {}					QOBRDouble;
typedef struct {}					QOBRLDouble;

typedef struct {Q2DFloat   point; qfloat   radius;}	QCircleFloat;
typedef struct {Q2DDouble  point; qdouble  radius;}	QCircleDouble;
typedef struct {Q2DLDouble point; qldouble radius;}	QCircleLDouble;

/* MARK: - 3D geometry */

typedef struct {Q3DFloat   a, b;}			Q3DVectorFloat;
typedef struct {Q3DDouble  a, b;}			Q3DVectorDouble;
typedef struct {Q3DLDouble a, b;}			Q3DVectorLDouble;

typedef Q3DVectorFloat					Q3DLineFloat;
typedef Q3DVectorDouble					Q3DLineDouble;
typedef Q3DVectorLDouble				Q3DLineLDouble;

typedef struct {Q3DFloat   point, angle;}		Q3DRayFloat;
typedef struct {Q3DDouble  point, angle;}		Q3DRayDouble;
typedef struct {Q3DLDouble point, angle;}		Q3DRayLDouble;

typedef struct {Q3DFloat   point, size;}		QBoxFloat;
typedef struct {Q3DDouble  point, size;}		QBoxDouble;
typedef struct {Q3DLDouble point, size;}		QBoxLDouble;

typedef Q3DLineFloat					QAABBFloat;
typedef Q3DLineDouble					QAABBDouble;
typedef Q3DLineLDouble					QAABBLDouble;

typedef struct {}					QOBBFloat;
typedef struct {}					QOBBDouble;
typedef struct {}					QOBBLDouble;

typedef struct {Q3DFloat   point; qfloat   radius;}	QSphereFloat;
typedef struct {Q3DDouble  point; qdouble  radius;}	QSphereDouble;
typedef struct {Q3DLDouble point; qldouble radius;}	QSphereLDouble;

typedef struct {Q3DFloat   normal; qfloat   offset;}	QPlaneFloat;
typedef struct {Q3DDouble  normal; qdouble  offset;}	QPlaneDouble;
typedef struct {Q3DLDouble normal; qldouble offset;}	QPlaneLDouble;

/* MARK: - Default real type definitions */

typedef Q_JOIN_2(Q2DVector,  Q_REAL_FIXED_TYPE_Name) Q2DVector;
typedef Q_JOIN_2(Q2DLine,    Q_REAL_FIXED_TYPE_Name) Q2DLine;
typedef Q_JOIN_2(Q2DRay,     Q_REAL_FIXED_TYPE_Name) Q2DRay;
typedef Q_JOIN_2(QRectangle, Q_REAL_FIXED_TYPE_Name) QRectangle;
typedef Q_JOIN_2(QAABR,	     Q_REAL_FIXED_TYPE_Name) QAABR;
typedef Q_JOIN_2(QOBR,	     Q_REAL_FIXED_TYPE_Name) QOBR;
typedef Q_JOIN_2(QCircle,    Q_REAL_FIXED_TYPE_Name) QCircle;
typedef	Q_JOIN_2(Q3DVector,  Q_REAL_FIXED_TYPE_Name) Q3DVector;
typedef Q_JOIN_2(Q3DLine,    Q_REAL_FIXED_TYPE_Name) Q3DLine;
typedef Q_JOIN_2(Q3DRay,     Q_REAL_FIXED_TYPE_Name) Q3DRay;
typedef Q_JOIN_2(QBox,	     Q_REAL_FIXED_TYPE_Name) QBox;
typedef Q_JOIN_2(QAABB,	     Q_REAL_FIXED_TYPE_Name) QAABB;
typedef Q_JOIN_2(QOBB,	     Q_REAL_FIXED_TYPE_Name) QOBB;
typedef Q_JOIN_2(QSphere,    Q_REAL_FIXED_TYPE_Name) QSphere;
typedef Q_JOIN_2(QPlane,     Q_REAL_FIXED_TYPE_Name) QPlane;

/* MARK: - Casts */

#define Q_2D_VECTOR_FLOAT(  p) ((Q2DVectorFloat	   *)(p))
#define Q_2D_VECTOR_DOUBLE( p) ((Q2DVectorDouble   *)(p))
#define Q_2D_VECTOR_LDOUBLE(p) ((Q2DVectorLDouble  *)(p))
#define Q_2D_VECTOR(	    p) ((Q2DVector	   *)(p))
#define Q_2D_LINE_FLOAT(    p) ((Q2DLineFloat	   *)(p))
#define Q_2D_LINE_DOUBLE(   p) ((Q2DLineDouble	   *)(p))
#define Q_2D_LINE_LDOUBLE(  p) ((Q2DLineLDouble	   *)(p))
#define Q_2D_LINE(	    p) ((Q2Dine		   *)(p))
#define Q_2D_RAY_FLOAT(     p) ((Q2DRayFloat	   *)(p))
#define Q_2D_RAY_DOUBLE(    p) ((Q2DRayDouble	   *)(p))
#define Q_2D_RAY_LDOUBLE(   p) ((Q2DRayLDouble	   *)(p))
#define Q_2D_RAY(	    p) ((Q2DRay		   *)(p))
#define Q_RECTANGLE_FLOAT(  p) ((QRectangleFloat   *)(p))
#define Q_RECTANGLE_DOUBLE( p) ((QRectangleDouble  *)(p))
#define Q_RECTANGLE_LDOUBLE(p) ((QRectangleLDouble *)(p))
#define Q_RECTANGLE(	    p) ((QRectangle	   *)(p))
#define Q_AABR_FLOAT(	    p) ((QAABRFloat	   *)(p))
#define Q_AABR_DOUBLE(	    p) ((QAABRDouble	   *)(p))
#define Q_AABR_LDOUBLE(     p) ((QAABRLDouble	   *)(p))
#define Q_AABR(		    p) ((QAABR		   *)(p))
#define Q_OBR_FLOAT(	    p) ((QOBRFloat	   *)(p))
#define Q_OBR_DOUBLE(	    p) ((QOBRDouble	   *)(p))
#define Q_OBR_LDOUBLE(	    p) ((QOBRLDouble	   *)(p))
#define Q_OBR(		    p) ((QOBR		   *)(p))
#define Q_CIRCLE_FLOAT(     p) ((QCircleFloat	   *)(p))
#define Q_CIRCLE_DOUBLE(    p) ((QCircleDouble	   *)(p))
#define Q_CIRCLE_LDOUBLE(   p) ((QCircleLDouble    *)(p))
#define Q_CIRCLE(	    p) ((QCircle	   *)(p))
#define Q_3D_VECTOR_FLOAT(  p) ((Q3DVectorFloat    *)(p))
#define Q_3D_VECTOR_DOUBLE( p) ((Q3DVectorDouble   *)(p))
#define Q_3D_VECTOR_LDOUBLE(p) ((Q3DVectorLDouble  *)(p))
#define Q_3D_VECTOR(	    p) ((Q3DVector	   *)(p))
#define Q_3D_LINE_FLOAT(    p) ((Q3DLineFloat	   *)(p))
#define Q_3D_LINE_DOUBLE(   p) ((Q3DLineDouble	   *)(p))
#define Q_3D_LINE_LDOUBLE(  p) ((Q3DLineLDouble    *)(p))
#define Q_3D_LINE(	    p) ((Q3DLine	   *)(p))
#define Q_3D_RAY_FLOAT(     p) ((Q3DRayFloat	   *)(p))
#define Q_3D_RAY_DOUBLE(    p) ((Q3DRayDouble	   *)(p))
#define Q_3D_RAY_LDOUBLE(   p) ((Q3DRayLDouble	   *)(p))
#define Q_3D_RAY(	    p) ((Q3DRay		   *)(p))
#define Q_BOX_FLOAT(	    p) ((QBoxFloat	   *)(p))
#define Q_BOX_DOUBLE(	    p) ((QBoxDouble	   *)(p))
#define Q_BOX_LDOUBLE(	    p) ((QBoxLDouble	   *)(p))
#define Q_BOX(		    p) ((QBox		   *)(p))
#define Q_AABB_FLOAT(	    p) ((QAABBFloat	   *)(p))
#define Q_AABB_DOUBLE(	    p) ((QAABBDouble	   *)(p))
#define Q_AABB_LDOUBLE(     p) ((QAABBLDouble	   *)(p))
#define Q_AABB(		    p) ((QAABB		   *)(p))
#define Q_OBB_FLOAT(	    p) ((QOBBFloat	   *)(p))
#define Q_OBB_DOUBLE(	    p) ((QOBBDouble	   *)(p))
#define Q_OBB_LDOUBLE(	    p) ((QOBBLDouble	   *)(p))
#define Q_OBB(		    p) ((QOBB		   *)(p))
#define Q_SPHERE_FLOAT(     p) ((QSphereFloat	   *)(p))
#define Q_SPHERE_DOUBLE(    p) ((QSphereDouble	   *)(p))
#define Q_SPHERE_LDOUBLE(   p) ((QSphereLDouble	   *)(p))
#define Q_SPHERE(	    p) ((QSphere	   *)(p))
#define Q_PLANE_FLOAT(	    p) ((QPlaneFloat	   *)(p))
#define Q_PLANE_DOUBLE(     p) ((QPlaneDouble	   *)(p))
#define Q_PLANE_LDOUBLE(    p) ((QPlaneLDouble	   *)(p))
#define Q_PLANE(	    p) ((QPlane		   *)(p))

#endif /* __Q_types_mathematics_H__ */
