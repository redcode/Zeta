/* Q API - types/mathematics.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_mathematics_H__
#define __Q_types_mathematics_H__

#include <Q/types/base.h>

/* MARK: - 2D - Vector */

typedef struct {Q2DFloat   a, b;}			Q2DFloatVector;
typedef struct {Q2DDouble  a, b;}			Q2DDoubleVector;
typedef struct {Q2DLDouble a, b;}			Q2DLDoubleVector;

/* MARK: - 2D - Line */

typedef Q2DFloatVector					Q2DFloatLine;
typedef Q2DDoubleVector					Q2DDoubleLine;
typedef Q2DLDoubleVector				Q2DLDoubleLine;

/* MARK: - 2D - Ray */

typedef struct {Q2DFloat   point; qfloat   angle;}	Q2DFloatRay;
typedef struct {Q2DDouble  point; qdouble  angle;}	Q2DDoubleRay;
typedef struct {Q2DLDouble point; qldouble angle;}	Q2DLDoubleRay;

/* MARK: - 2D - Triangle */

typedef struct {Q2DFloat   a, b, c;}			Q2DFloatTriangle;
typedef struct {Q2DDouble  a, b, c;}			Q2DDoubleTriangle;
typedef struct {Q2DLDouble a, b, c;}			Q2DLDoubleTriangle;

/* MARK: - 2D - Quadrangle; */

typedef struct {Q2DFloat   a, b, c, d;}			Q2DFloatQuadrangle;
typedef struct {Q2DDouble  a, b, c, d;}			Q2DDoubleQuadrangle;
typedef struct {Q2DLDouble a, b, c, d;}			Q2DLDoubleQuadrangle;

/* MARK: - 2D - Rectangle */

typedef struct {Q2DFloat   point, size;}		QFloatRectangle;
typedef struct {Q2DDouble  point, size;}		QDoubleRectangle;
typedef struct {Q2DLDouble point, size;}		QLDoubleRectangle;

/* MARK: - 2D - Axis-aligned bounding rectangle */

typedef Q2DFloatLine					QFloatAABR;
typedef Q2DDoubleLine					QDoubleAABR;
typedef Q2DLDoubleLine					QLDoubleAABR;

/* MARK: - 2D - Oriented bounding rectangle */

typedef struct {}					QFloatOBR;
typedef struct {}					QDoubleOBR;
typedef struct {}					QLDoubleOBR;

/* MARK: - 2D - Circle */

typedef struct {Q2DFloat   point; qfloat   radius;}	QFloatCircle;
typedef struct {Q2DDouble  point; qdouble  radius;}	QDoubleCircle;
typedef struct {Q2DLDouble point; qldouble radius;}	QLDoubleCircle;

/* MARK: - 3D - Vector */

typedef struct {Q3DFloat   a, b;}			Q3DFloatVector;
typedef struct {Q3DDouble  a, b;}			Q3DDoubleVector;
typedef struct {Q3DLDouble a, b;}			Q3DLDoubleVector;

/* MARK: - 3D - Line */

typedef Q3DFloatVector					Q3DFloatLine;
typedef Q3DDoubleVector					Q3DDoubleLine;
typedef Q3DLDoubleVector				Q3DLDoubleLine;

/* MARK: - 3D - Plane */

typedef struct {Q3DFloat   normal; qfloat   offset}	QFloatPlane;
typedef struct {Q3DDouble  normal; qdouble  offset}	QDoublePlane;
typedef struct {Q3DLDouble normal; qldouble offset}	QLDoublePlane;

/* MARK: - 3D - Ray */

typedef struct {Q3DFloat   point, angle;}		Q3DFloatRay;
typedef struct {Q3DDouble  point, angle;}		Q3DDoubleRay;
typedef struct {Q3DLDouble point, angle;}		Q3DLDoubleRay;

/* MARK: - 3D - Triangle */

typedef struct {Q3DFloat   a, b, c;}			Q3DFloatTriangle;
typedef struct {Q3DDouble  a, b, c;}			Q3DDoubleTriangle;
typedef struct {Q3DLDouble a, b, c;}			Q3DLDoubleTriangle;

/* MARK: - 3D - Quadrangle; */

typedef struct {Q3DFloat   a, b, c, d;}			Q3DFloatQuadrangle;
typedef struct {Q3DDouble  a, b, c, d;}			Q3DDoubleQuadrangle;
typedef struct {Q3DLDouble a, b, c, d;}			Q3DLDoubleQuadrangle;

/* MARK: - 3D - Box */

typedef struct {Q3DFloat   point, size;}		QFloatBox;
typedef struct {Q3DDouble  point, size;}		QDoubleBox;
typedef struct {Q3DLDouble point, size;}		QLDoubleBox;

/* MARK: - 3D - Axis-aligned bounding box */

typedef Q3DFloatLine					QFloatAABB;
typedef Q3DDoubleLine					QDoubleAABB;
typedef Q3DLDoubleLine					QLDoubleAABB;

/* MARK: - 3D - Oriented bounding box */

typedef struct {}					QFloatOBB;
typedef struct {}					QDoubleOBB;
typedef struct {}					QLDoubleOBB;

/* MARK: - 3D - Sphere */

typedef struct {Q3DFloat   point; qfloat   radius;}	QFloatSphere;
typedef struct {Q3DDouble  point; qdouble  radius;}	QDoubleSphere;
typedef struct {Q3DLDouble point; qldouble radius;}	QLDoubleSphere;

/* MARK: - Casts */

#define Q_2D_FLOAT_VECTOR(	p) ((Q2DFloatVector	  *)(p))
#define Q_2D_DOUBLE_VECTOR(	p) ((Q2DDoubleVector	  *)(p))
#define Q_2D_LDOUBLE_VECTOR(	p) ((Q2DLDoubleVector	  *)(p))
#define Q_2D_FLOAT_LINE(	p) ((Q2DFloatLine	  *)(p))
#define Q_2D_DOUBLE_LINE(	p) ((Q2DDoubleLine	  *)(p))
#define Q_2D_LDOUBLE_LINE(	p) ((Q2DLDoubleLine	  *)(p))
#define Q_2D_FLOAT_RAY(		p) ((Q2DFloatRay	  *)(p))
#define Q_2D_DOUBLE_RAY(	p) ((Q2DDoubleRay	  *)(p))
#define Q_2D_LDOUBLE_RAY(	p) ((Q2DLDoubleRay	  *)(p))
#define Q_2D_FLOAT_TRIANGLE(	p) ((Q2DFloatTriangle	  *)(p))
#define Q_2D_DOUBLE_TRIANGLE(	p) ((Q2DDoubleTriangle	  *)(p))
#define Q_2D_LDOUBLE_TRIANGLE(	p) ((Q2DLDoubleTriangle	  *)(p))
#define Q_2D_FLOAT_QUADRANGLE(	p) ((Q2DFloatQuadrangle	  *)(p))
#define Q_2D_DOUBLE_QUADRANGLE(	p) ((Q2DDoubleQuadrangle  *)(p))
#define Q_2D_LDOUBLE_QUADRANGLE(p) ((Q2DLDoubleQuadrangle *)(p))
#define Q_FLOAT_RECTANGLE(	p) ((QFloatRectangle	  *)(p))
#define Q_DOUBLE_RECTANGLE(	p) ((QDoubleRectangle	  *)(p))
#define Q_LDOUBLE_RECTANGLE(	p) ((QLDoubleRectangle	  *)(p))
#define Q_FLOAT_AABR(		p) ((QFloatAABR		  *)(p))
#define Q_DOUBLE_AABR(		p) ((QDoubleAABR	  *)(p))
#define Q_LDOUBLE_AABR(		p) ((QLDoubleAABR	  *)(p))
#define Q_FLOAT_OBR(		p) ((QFloatOBR		  *)(p))
#define Q_DOUBLE_OBR(		p) ((QDoubleOBR		  *)(p))
#define Q_LDOUBLE_OBR(		p) ((QLDoubleOBR	  *)(p))
#define Q_FLOAT_CIRCLE(		p) ((QFloatCircle	  *)(p))
#define Q_DOUBLE_CIRCLE(	p) ((QDoubleCircle	  *)(p))
#define Q_LDOUBLE_CIRCLE(	p) ((QLDoubleCircle	  *)(p))
#define Q_3D_FLOAT_VECTOR(	p) ((Q3DFloatVector	  *)(p))
#define Q_3D_DOUBLE_VECTOR(	p) ((Q3DDoubleVector	  *)(p))
#define Q_3D_LDOUBLE_VECTOR(	p) ((Q3DLDoubleVector	  *)(p))
#define Q_3D_FLOAT_LINE(	p) ((Q3DFloatLine	  *)(p))
#define Q_3D_DOUBLE_LINE(	p) ((Q3DDoubleLine	  *)(p))
#define Q_3D_LDOUBLE_LINE(	p) ((Q3DLDoubleLine	  *)(p))
#define Q_FLOAT_PLANE(		p) ((QFloatPlane	  *)(p))
#define Q_DOUBLE_PLANE(		p) ((QDoublePlane	  *)(p))
#define Q_LDOUBLE_PLANE(	p) ((QLDoublePlane	  *)(p))
#define Q_3D_FLOAT_RAY(		p) ((Q3DFloatRay	  *)(p))
#define Q_3D_DOUBLE_RAY(	p) ((Q3DDoubleRay	  *)(p))
#define Q_3D_LDOUBLE_RAY(	p) ((Q3DLDoubleRay	  *)(p))
#define Q_3D_FLOAT_TRIANGLE(	p) ((Q3DFloatTriangle	  *)(p))
#define Q_3D_DOUBLE_TRIANGLE(	p) ((Q3DDoubleTriangle	  *)(p))
#define Q_3D_LDOUBLE_TRIANGLE(	p) ((Q3DLDoubleTriangle	  *)(p))
#define Q_3D_FLOAT_QUADRANGLE(	p) ((Q3DFloatQuadrangle	  *)(p))
#define Q_3D_DOUBLE_QUADRANGLE(	p) ((Q3DDoubleQuadrangle  *)(p))
#define Q_3D_LDOUBLE_QUADRANGLE(p) ((Q3DLDoubleQuadrangle *)(p))
#define Q_FLOAT_BOX(		p) ((QFloatBox		  *)(p))
#define Q_DOUBLE_BOX(		p) ((QDoubleBox		  *)(p))
#define Q_LDOUBLE_BOX(		p) ((QLDoubleBox	  *)(p))
#define Q_FLOAT_AABB(		p) ((QFloatAABB		  *)(p))
#define Q_DOUBLE_AABB(		p) ((QDoubleAABB	  *)(p))
#define Q_LDOUBLE_AABB(		p) ((QLDoubleAABB	  *)(p))
#define Q_FLOAT_OBB(		p) ((QFloatOBB		  *)(p))
#define Q_DOUBLE_OBB(		p) ((QDoubleOBB		  *)(p))
#define Q_LDOUBLE_OBB(		p) ((QLDoubleOBB	  *)(p))
#define Q_FLOAT_SPHERE(		p) ((QFloatSphere	  *)(p))
#define Q_DOUBLE_SPHERE(	p) ((QDoubleSphere	  *)(p))
#define Q_LDOUBLE_SPHERE(	p) ((QLDoubleSphere	  *)(p))

/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

	typedef Q2DFloatVector		Q2DVector;
	typedef Q2DFloatLine		Q2DLine;
	typedef Q2DFloatRay		Q2DRay;
	typedef Q2DFloatTriangle	Q2DTriangle;
	typedef Q2DFloatQuadrangle	Q2DQuadrangle;
	typedef QFloatRectangle		QRectangle;
	typedef QFloatAABR		QAABR;
	typedef QFloatOBR		QOBR;
	typedef QFloatCircle		QCircle;
	typedef	Q3DFloatVector		Q3DVector;
	typedef Q3DFloatLine		Q3DLine;
	typedef QFloatPlane		QPlane;
	typedef Q3DFloatRay		Q3DRay;
	typedef Q3DFloatTriangle	Q3DTriangle;
	typedef Q3DFloatQuadrangle	Q3DQuadrangle;
	typedef QFloatBox		QBox;
	typedef QFloatAABB		QAABB;
	typedef QFloatOBB		QOBB;
	typedef QFloatSphere		QSphere;

#	define Q_2D_VECTOR		Q_2D_FLOAT_VECTOR
#	define Q_2D_LINE		Q_2D_FLOAT_LINE
#	define Q_2D_RAY			Q_2D_FLOAT_RAY
#	define Q_2D_TRIANGLE		Q_2D_FLOAT_TRIANGLE
#	define Q_2D_QUADRANGLE		Q_2D_FLOAT_QUADRANGLE
#	define Q_RECTANGLE		Q_FLOAT_RECTANGLE
#	define Q_AABR			Q_FLOAT_AABR
#	define Q_OBR			Q_FLOAT_OBR
#	define Q_CIRCLE			Q_FLOAT_CIRCLE
#	define Q_3D_VECTOR		Q_3D_FLOAT_VECTOR
#	define Q_3D_LINE		Q_3D_FLOAT_LINE
#	define Q_PLANE			Q_FLOAT_PLANE
#	define Q_3D_RAY			Q_3D_FLOAT_RAY
#	define Q_3D_TRIANGLE		Q_3D_FLOAT_TRIANGLE
#	define Q_3D_QUADRANGLE		Q_3D_FLOAT_QUADRANGLE
#	define Q_BOX			Q_FLOAT_BOX
#	define Q_AABB			Q_FLOAT_AABB
#	define Q_OBB			Q_FLOAT_OBB
#	define Q_SPHERE			Q_FLOAT_SPHERE

#elif defined(Q_USE_REAL_LDOUBLE)

	typedef Q2DLDoubleVector	Q2DVector;
	typedef Q2DLDoubleLine		Q2DLine;
	typedef Q2DLDoubleRay		Q2DRay;
	typedef Q2DLDoubleTriangle	Q2DTriangle;
	typedef Q2DLDoubleQuadrangle	Q2DQuadrangle;
	typedef QLDoubleRectangle	QRectangle;
	typedef QLDoubleAABR		QAABR;
	typedef QLDoubleOBR		QOBR;
	typedef QLDoubleCircle		QCircle;
	typedef	Q3DLDoubleVector	Q3DVector;
	typedef Q3DLDoubleLine		Q3DLine;
	typedef QLDoublePlane		QPlane;
	typedef Q3DLDoubleRay		Q3DRay;
	typedef Q3DLDoubleTriangle	Q3DTriangle;
	typedef Q3DLDoubleQuadrangle	Q3DQuadrangle;
	typedef QLDoubleBox		QBox;
	typedef QLDoubleAABB		QAABB;
	typedef QLDoubleOBB		QOBB;
	typedef QLDoubleSphere		QSphere;

#	define Q_2D_VECTOR		Q_2D_LDOUBLE_VECTOR
#	define Q_2D_LINE		Q_2D_LDOUBLE_LINE
#	define Q_2D_RAY			Q_2D_LDOUBLE_RAY
#	define Q_2D_TRIANGLE		Q_2D_LDOUBLE_TRIANGLE
#	define Q_2D_QUADRANGLE		Q_2D_LDOUBLE_QUADRANGLE
#	define Q_RECTANGLE		Q_LDOUBLE_RECTANGLE
#	define Q_AABR			Q_LDOUBLE_AABR
#	define Q_OBR			Q_LDOUBLE_OBR
#	define Q_CIRCLE			Q_LDOUBLE_CIRCLE
#	define Q_3D_VECTOR		Q_3D_LDOUBLE_VECTOR
#	define Q_3D_LINE		Q_3D_LDOUBLE_LINE
#	define Q_PLANE			Q_LDOUBLE_PLANE
#	define Q_3D_RAY			Q_3D_LDOUBLE_RAY
#	define Q_3D_TRIANGLE		Q_3D_LDOUBLE_TRIANGLE
#	define Q_3D_QUADRANGLE		Q_3D_LDOUBLE_QUADRANGLE
#	define Q_BOX			Q_LDOUBLE_BOX
#	define Q_AABB			Q_LDOUBLE_AABB
#	define Q_OBB			Q_LDOUBLE_OBB
#	define Q_SPHERE			Q_LDOUBLE_SPHERE

#else

	typedef Q2DDoubleVector		Q2DVector;
	typedef Q2DDoubleLine		Q2DLine;
	typedef Q2DDoubleRay		Q2DRay;
	typedef Q2DDoubleTriangle	Q2DTriangle;
	typedef Q2DDoubleQuadrangle	Q2DQuadrangle;
	typedef QDoubleRectangle	QRectangle;
	typedef QDoubleAABR		QAABR;
	typedef QDoubleOBR		QOBR;
	typedef QDoubleCircle		QCircle;
	typedef	Q3DDoubleVector		Q3DVector;
	typedef Q3DDoubleLine		Q3DLine;
	typedef QDoublePlane		QPlane;
	typedef Q3DDoubleRay		Q3DRay;
	typedef Q3DDoubleTriangle	Q3DTriangle;
	typedef Q3DDoubleQuadrangle	Q3DQuadrangle;
	typedef QDoubleBox		QBox;
	typedef QDoubleAABB		QAABB;
	typedef QDoubleOBB		QOBB;
	typedef QDoubleSphere		QSphere;

#	define Q_2D_VECTOR		Q_2D_DOUBLE_VECTOR
#	define Q_2D_LINE		Q_2D_DOUBLE_LINE
#	define Q_2D_RAY			Q_2D_DOUBLE_RAY
#	define Q_2D_TRIANGLE		Q_2D_DOUBLE_TRIANGLE
#	define Q_2D_QUADRANGLE		Q_2D_DOUBLE_QUADRANGLE
#	define Q_RECTANGLE		Q_DOUBLE_RECTANGLE
#	define Q_AABR			Q_DOUBLE_AABR
#	define Q_OBR			Q_DOUBLE_OBR
#	define Q_CIRCLE			Q_DOUBLE_CIRCLE
#	define Q_3D_VECTOR		Q_3D_DOUBLE_VECTOR
#	define Q_3D_LINE		Q_3D_DOUBLE_LINE
#	define Q_PLANE			Q_DOUBLE_PLANE
#	define Q_3D_RAY			Q_3D_DOUBLE_RAY
#	define Q_3D_TRIANGLE		Q_3D_DOUBLE_TRIANGLE
#	define Q_3D_QUADRANGLE		Q_3D_DOUBLE_QUADRANGLE
#	define Q_BOX			Q_DOUBLE_BOX
#	define Q_AABB			Q_DOUBLE_AABB
#	define Q_OBB			Q_DOUBLE_OBB
#	define Q_SPHERE			Q_DOUBLE_SPHERE

#endif

#endif /* __Q_types_mathematics_H__ */
