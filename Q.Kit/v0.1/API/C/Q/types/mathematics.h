/* Q Kit API - types/mathematics.h
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

typedef struct {Q2DFloat   a, b;}			Q2DFloatVector;
typedef struct {Q2DDouble  a, b;}			Q2DDoubleVector;
typedef struct {Q2DLDouble a, b;}			Q2DLDoubleVector;

typedef Q2DFloatVector					Q2DFloatLine;
typedef Q2DDoubleVector					Q2DDoubleLine;
typedef Q2DLDoubleVector				Q2DLDoubleLine;

typedef struct {Q2DFloat   point; qfloat   angle;}	Q2DFloatRay;
typedef struct {Q2DDouble  point; qdouble  angle;}	Q2DDoubleRay;
typedef struct {Q2DLDouble point; qldouble angle;}	Q2DLDoubleRay;

typedef struct {Q2DFloat   point, size;}		QFloatRectangle;
typedef struct {Q2DDouble  point, size;}		QDoubleRectangle;
typedef struct {Q2DLDouble point, size;}		QLDoubleRectangle;

typedef Q2DFloatLine					QFloatAABR;
typedef Q2DDoubleLine					QDoubleAABR;
typedef Q2DLDoubleLine					QLDoubleAABR;

typedef struct {}					QFloatOBR;
typedef struct {}					QDoubleOBR;
typedef struct {}					QLDoubleOBR;

typedef struct {Q2DFloat   point; qfloat   radius;}	QFloatCircle;
typedef struct {Q2DDouble  point; qdouble  radius;}	QDoubleCircle;
typedef struct {Q2DLDouble point; qldouble radius;}	QLDoubleCircle;

/* MARK: - 3D geometry */

typedef struct {Q3DFloat   a, b;}			Q3DFloatVector;
typedef struct {Q3DDouble  a, b;}			Q3DDoubleVector;
typedef struct {Q3DLDouble a, b;}			Q3DLDoubleVector;

typedef Q3DFloatVector					Q3DFloatLine;
typedef Q3DDoubleVector					Q3DDoubleLine;
typedef Q3DLDoubleVector				Q3DLDoubleLine;

typedef struct {Q3DFloat   point, angle;}		Q3DFloatRay;
typedef struct {Q3DDouble  point, angle;}		Q3DDoubleRay;
typedef struct {Q3DLDouble point, angle;}		Q3DLDoubleRay;

typedef struct {Q3DFloat   point, size;}		QFloatBox;
typedef struct {Q3DDouble  point, size;}		QDoubleBox;
typedef struct {Q3DLDouble point, size;}		QLDoubleBox;

typedef Q3DFloatLine					QFloatAABB;
typedef Q3DDoubleLine					QDoubleAABB;
typedef Q3DLDoubleLine					QLDoubleAABB;

typedef struct {}					QFloatOBB;
typedef struct {}					QDoubleOBB;
typedef struct {}					QLDoubleOBB;

typedef struct {Q3DFloat   point; qfloat   radius;}	QFloatSphere;
typedef struct {Q3DDouble  point; qdouble  radius;}	QDoubleSphere;
typedef struct {Q3DLDouble point; qldouble radius;}	QLDoubleSphere;

typedef struct {Q3DFloat   normal; qfloat   offset;}	QFloatPlane;
typedef struct {Q3DDouble  normal; qdouble  offset;}	QDoublePlane;
typedef struct {Q3DLDouble normal; qldouble offset;}	QLDoublePlane;

/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

	typedef Q2DFloatVector	  Q2DVector;
	typedef Q2DFloatLine	  Q2DLine;
	typedef Q2DFloatRay	  Q2DRay;
	typedef QFloatRectangle   QRectangle;
	typedef QFloatAABR	  QAABR;
	typedef QFloatOBR	  QOBR;
	typedef QFloatCircle	  QCircle;
	typedef	Q3DFloatVector	  Q3DVector;
	typedef Q3DFloatLine	  Q3DLine;
	typedef Q3DFloatRay	  Q3DRay;
	typedef QFloatBox	  QBox;
	typedef QFloatAABB	  QAABB;
	typedef QFloatOBB	  QOBB;
	typedef QFloatSphere	  QSphere;
	typedef QFloatPlane	  QPlane;

#elif defined(Q_USE_REAL_LDOUBLE)

	typedef Q2DLDoubleVector  Q2DVector;
	typedef Q2DLDoubleLine	  Q2DLine;
	typedef Q2DLDoubleRay	  Q2DRay;
	typedef QLDoubleRectangle QRectangle;
	typedef QLDoubleAABR	  QAABR;
	typedef QLDoubleOBR	  QOBR;
	typedef QLDoubleCircle	  QCircle;
	typedef	Q3DLDoubleVector  Q3DVector;
	typedef Q3DLDoubleLine	  Q3DLine;
	typedef Q3DLDoubleRay	  Q3DRay;
	typedef QLDoubleBox	  QBox;
	typedef QLDoubleAABB	  QAABB;
	typedef QLDoubleOBB	  QOBB;
	typedef QLDoubleSphere	  QSphere;
	typedef QLDoublePlane	  QPlane;

#else

	typedef Q2DDoubleVector   Q2DVector;
	typedef Q2DDoubleLine	  Q2DLine;
	typedef Q2DDoubleRay	  Q2DRay;
	typedef QDoubleRectangle  QRectangle;
	typedef QDoubleAABR	  QAABR;
	typedef QDoubleOBR	  QOBR;
	typedef QDoubleCircle	  QCircle;
	typedef	Q3DDoubleVector	  Q3DVector;
	typedef Q3DDoubleLine	  Q3DLine;
	typedef Q3DDoubleRay	  Q3DRay;
	typedef QDoubleBox	  QBox;
	typedef QDoubleAABB	  QAABB;
	typedef QDoubleOBB	  QOBB;
	typedef QDoubleSphere	  QSphere;
	typedef QDoublePlane	  QPlane;

#endif


/* MARK: - Casts */

#define Q_2D_FLOAT_VECTOR(  p) ((Q2DFloatVector	   *)(p))
#define Q_2D_DOUBLE_VECTOR( p) ((Q2DDoubleVector   *)(p))
#define Q_2D_LDOUBLE_VECTOR(p) ((Q2DLDoubleVector  *)(p))
#define Q_2D_VECTOR(	    p) ((Q2DVector	   *)(p))
#define Q_2D_FLOAT_LINE(    p) ((Q2DFloatLine	   *)(p))
#define Q_2D_DOUBLE_LINE(   p) ((Q2DDoubleLine	   *)(p))
#define Q_2D_LDOUBLE_LINE(  p) ((Q2DLDoubleLine	   *)(p))
#define Q_2D_LINE(	    p) ((Q2Dine		   *)(p))
#define Q_2D_FLOAT_RAY(     p) ((Q2DFloatRay	   *)(p))
#define Q_2D_DOUBLE_RAY(    p) ((Q2DDoubleRay	   *)(p))
#define Q_2D_LDOUBLE_RAY(   p) ((Q2DLDoubleRay	   *)(p))
#define Q_2D_RAY(	    p) ((Q2DRay		   *)(p))
#define Q_FLOAT_RECTANGLE(  p) ((QFloatRectangle   *)(p))
#define Q_DOUBLE_RECTANGLE( p) ((QDoubleRectangle  *)(p))
#define Q_LDOUBLE_RECTANGLE(p) ((QLDoubleRectangle *)(p))
#define Q_RECTANGLE(	    p) ((QRectangle	   *)(p))
#define Q_FLOAT_AABR(	    p) ((QFloatAABR	   *)(p))
#define Q_DOUBLE_AABR(	    p) ((QDoubleAABR	   *)(p))
#define Q_LDOUBLE_AABR(     p) ((QLDoubleAABR	   *)(p))
#define Q_AABR(		    p) ((QAABR		   *)(p))
#define Q_FLOAT_OBR(	    p) ((QFloatOBR	   *)(p))
#define Q_DOUBLE_OBR(	    p) ((QDoubleOBR	   *)(p))
#define Q_LDOUBLE_OBR(	    p) ((QLDoubleOBR	   *)(p))
#define Q_OBR(		    p) ((QOBR		   *)(p))
#define Q_FLOAT_CIRCLE(     p) ((QFloatCircle	   *)(p))
#define Q_DOUBLE_CIRCLE(    p) ((QDoubleCircle	   *)(p))
#define Q_LDOUBLE_CIRCLE(   p) ((QLDoubleCircle    *)(p))
#define Q_CIRCLE(	    p) ((QCircle	   *)(p))
#define Q_3D_FLOAT_VECTOR(  p) ((Q3DFloatVector    *)(p))
#define Q_3D_DOUBLE_VECTOR( p) ((Q3DDoubleVector   *)(p))
#define Q_3D_LDOUBLE_VECTOR(p) ((Q3DLDoubleVector  *)(p))
#define Q_3D_VECTOR(	    p) ((Q3DVector	   *)(p))
#define Q_3D_FLOAT_LINE(    p) ((Q3DFloatLine	   *)(p))
#define Q_3D_DOUBLE_LINE(   p) ((Q3DDoubleLine	   *)(p))
#define Q_3D_LDOUBLE_LINE(  p) ((Q3DLDoubleLine    *)(p))
#define Q_3D_LINE(	    p) ((Q3DLine	   *)(p))
#define Q_3D_FLOAT_RAY(     p) ((Q3DFloatRay	   *)(p))
#define Q_3D_DOUBLE_RAY(    p) ((Q3DDoubleRay	   *)(p))
#define Q_3D_LDOUBLE_RAY(   p) ((Q3DLDoubleRay	   *)(p))
#define Q_3D_RAY(	    p) ((Q3DRay		   *)(p))
#define Q_FLOAT_BOX(	    p) ((QFloatBox	   *)(p))
#define Q_DOUBLE_BOX(	    p) ((QDoubleBox	   *)(p))
#define Q_LDOUBLE_BOX(	    p) ((QLDoubleBox	   *)(p))
#define Q_BOX(		    p) ((QBox		   *)(p))
#define Q_FLOAT_AABB(	    p) ((QFloatAABB	   *)(p))
#define Q_DOUBLE_AABB(	    p) ((QDoubleAABB	   *)(p))
#define Q_LDOUBLE_AABB(     p) ((QLDoubleAABB	   *)(p))
#define Q_AABB(		    p) ((QAABB		   *)(p))
#define Q_FLOAT_OBB(	    p) ((QFloatOBB	   *)(p))
#define Q_DOUBLE_OBB(	    p) ((QDoubleOBB	   *)(p))
#define Q_LDOUBLE_OBB(	    p) ((QLDoubleOBB	   *)(p))
#define Q_OBB(		    p) ((QOBB		   *)(p))
#define Q_FLOAT_SPHERE(     p) ((QFloatSphere	   *)(p))
#define Q_DOUBLE_SPHERE(    p) ((QDoubleSphere	   *)(p))
#define Q_LDOUBLE_SPHERE(   p) ((QLDoubleSphere	   *)(p))
#define Q_SPHERE(	    p) ((QSphere	   *)(p))
#define Q_FLOAT_PLANE(	    p) ((QFloatPlane	   *)(p))
#define Q_DOUBLE_PLANE(     p) ((QDoublePlane	   *)(p))
#define Q_LDOUBLE_PLANE(    p) ((QLDoublePlane	   *)(p))
#define Q_PLANE(	    p) ((QPlane		   *)(p))

#endif /* __Q_types_mathematics_H__ */
