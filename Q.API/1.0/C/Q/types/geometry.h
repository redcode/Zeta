/* Q API - types/geometry.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_geometry_H__
#define __Q_types_geometry_H__

#include <Q/types/basics.h>

/* MARK: - Vector */

typedef struct {Q2DFloat   a, b;}			Q2DFloatVector;
typedef struct {Q2DDouble  a, b;}			Q2DDoubleVector;
typedef struct {Q2DLDouble a, b;}			Q2DLDoubleVector;

typedef struct {Q3DFloat   a, b;}			Q3DFloatVector;
typedef struct {Q3DDouble  a, b;}			Q3DDoubleVector;
typedef struct {Q3DLDouble a, b;}			Q3DLDoubleVector;

/* MARK: - Line */

typedef Q2DFloatVector					Q2DFloatLine;
typedef Q2DDoubleVector					Q2DDoubleLine;
typedef Q2DLDoubleVector				Q2DLDoubleLine;

typedef Q3DFloatVector					Q3DFloatLine;
typedef Q3DDoubleVector					Q3DDoubleLine;
typedef Q3DLDoubleVector				Q3DLDoubleLine;

/* MARK: - Triangle */

typedef struct {Q2DFloat   a, b, c;}			Q2DFloatTriangle;
typedef struct {Q2DDouble  a, b, c;}			Q2DDoubleTriangle;
typedef struct {Q2DLDouble a, b, c;}			Q2DLDoubleTriangle;

typedef struct {Q3DFloat   a, b, c;}			Q3DFloatTriangle;
typedef struct {Q3DDouble  a, b, c;}			Q3DDoubleTriangle;
typedef struct {Q3DLDouble a, b, c;}			Q3DLDoubleTriangle;

/* MARK: - Quadrangle; */

typedef struct {Q2DFloat   a, b, c, d;}			Q2DFloatQuadrangle;
typedef struct {Q2DDouble  a, b, c, d;}			Q2DDoubleQuadrangle;
typedef struct {Q2DLDouble a, b, c, d;}			Q2DLDoubleQuadrangle;

typedef struct {Q3DFloat   a, b, c, d;}			Q3DFloatQuadrangle;
typedef struct {Q3DDouble  a, b, c, d;}			Q3DDoubleQuadrangle;
typedef struct {Q3DLDouble a, b, c, d;}			Q3DLDoubleQuadrangle;

/* MARK: - Rectangle */

typedef struct {Q2DFloat   point, size;}		QFloatRectangle;
typedef struct {Q2DDouble  point, size;}		QDoubleRectangle;
typedef struct {Q2DLDouble point, size;}		QLDoubleRectangle;

/* MARK: - Box */

typedef struct {Q3DFloat   point, size;}		QFloatBox;
typedef struct {Q3DDouble  point, size;}		QDoubleBox;
typedef struct {Q3DLDouble point, size;}		QLDoubleBox;

/* MARK: - Circle */

typedef struct {Q2DFloat   point; qfloat   radius;}	QFloatCircle;
typedef struct {Q2DDouble  point; qdouble  radius;}	QDoubleCircle;
typedef struct {Q2DLDouble point; qldouble radius;}	QLDoubleCircle;

/* MARK: - Sphere */

typedef struct {Q3DFloat   point; qfloat   radius;}	QFloatSphere;
typedef struct {Q3DDouble  point; qdouble  radius;}	QDoubleSphere;
typedef struct {Q3DLDouble point; qldouble radius;}	QLDoubleSphere;

/* MARK: - Casts */

#define Q_2D_FLOAT_VECTOR(	p) ((Q2DFloatVector	  *)(p))
#define Q_2D_DOUBLE_VECTOR(	p) ((Q2DDoubleVector	  *)(p))
#define Q_2D_LDOUBLE_VECTOR(	p) ((Q2DLDoubleVector	  *)(p))
#define Q_3D_FLOAT_VECTOR(	p) ((Q3DFloatVector	  *)(p))
#define Q_3D_DOUBLE_VECTOR(	p) ((Q3DDoubleVector	  *)(p))
#define Q_3D_LDOUBLE_VECTOR(	p) ((Q3DLDoubleVector	  *)(p))
#define Q_2D_FLOAT_LINE(	p) ((Q2DFloatLine	  *)(p))
#define Q_2D_DOUBLE_LINE(	p) ((Q2DDoubleLine	  *)(p))
#define Q_2D_LDOUBLE_LINE(	p) ((Q2DLDoubleLine	  *)(p))
#define Q_3D_FLOAT_LINE(	p) ((Q3DFloatLine	  *)(p))
#define Q_3D_DOUBLE_LINE(	p) ((Q3DDoubleLine	  *)(p))
#define Q_3D_LDOUBLE_LINE(	p) ((Q3DLDoubleLine	  *)(p))
#define Q_2D_FLOAT_TRIANGLE(	p) ((Q2DFloatTriangle	  *)(p))
#define Q_2D_DOUBLE_TRIANGLE(	p) ((Q2DDoubleTriangle	  *)(p))
#define Q_2D_LDOUBLE_TRIANGLE(	p) ((Q2DLDoubleTriangle	  *)(p))
#define Q_3D_FLOAT_TRIANGLE(	p) ((Q3DFloatTriangle	  *)(p))
#define Q_3D_DOUBLE_TRIANGLE(	p) ((Q3DDoubleTriangle	  *)(p))
#define Q_3D_LDOUBLE_TRIANGLE(	p) ((Q3DLDoubleTriangle	  *)(p))
#define Q_2D_FLOAT_QUADRANGLE(	p) ((Q2DFloatQuadrangle	  *)(p))
#define Q_2D_DOUBLE_QUADRANGLE(	p) ((Q2DDoubleQuadrangle  *)(p))
#define Q_2D_LDOUBLE_QUADRANGLE(p) ((Q2DLDoubleQuadrangle *)(p))
#define Q_3D_FLOAT_QUADRANGLE(	p) ((Q3DFloatQuadrangle	  *)(p))
#define Q_3D_DOUBLE_QUADRANGLE(	p) ((Q3DDoubleQuadrangle  *)(p))
#define Q_3D_LDOUBLE_QUADRANGLE(p) ((Q3DLDoubleQuadrangle *)(p))
#define Q_FLOAT_RECTANGLE(	p) ((QFloatRectangle	  *)(p))
#define Q_DOUBLE_RECTANGLE(	p) ((QDoubleRectangle	  *)(p))
#define Q_LDOUBLE_RECTANGLE(	p) ((QLDoubleRectangle	  *)(p))
#define Q_FLOAT_BOX(		p) ((QFloatBox		  *)(p))
#define Q_DOUBLE_BOX(		p) ((QDoubleBox		  *)(p))
#define Q_LDOUBLE_BOX(		p) ((QLDoubleBox	  *)(p))
#define Q_FLOAT_CIRCLE(		p) ((QFloatCircle	  *)(p))
#define Q_DOUBLE_CIRCLE(	p) ((QDoubleCircle	  *)(p))
#define Q_LDOUBLE_CIRCLE(	p) ((QLDoubleCircle	  *)(p))
#define Q_FLOAT_SPHERE(		p) ((QFloatSphere	  *)(p))
#define Q_DOUBLE_SPHERE(	p) ((QDoubleSphere	  *)(p))
#define Q_LDOUBLE_SPHERE(	p) ((QLDoubleSphere	  *)(p))

/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

	typedef Q2DFloatVector		Q2DVector;
	typedef	Q2DFloatVector		Q3DVector;
	typedef Q2DFloatLine		Q2DLine;
	typedef Q3DFloatLine		Q3DLine;
	typedef Q2DFloatTriangle	Q2DTriangle;
	typedef Q3DFloatTriangle	Q2DTriangle;
	typedef Q2DFloatQuadrangle	Q2DQuadrangle;
	typedef Q3DFloatQuadrangle	Q3DQuadrangle;
	typedef QFloatRectangle		QRectangle;
	typedef QFloatBox		QBox;
	typedef QFloatCircle		QCircle;
	typedef QFloatSphere		QSphere;

#	define Q_2D_VECTOR		Q_2D_FLOAT_VECTOR
#	define Q_3D_VECTOR		Q_3D_FLOAT_VECTOR
#	define Q_2D_LINE		Q_2D_FLOAT_LINE
#	define Q_3D_LINE		Q_3D_FLOAT_LINE
#	define Q_2D_TRIANGLE		Q_2D_FLOAT_TRIANGLE
#	define Q_3D_TRIANGLE		Q_3D_FLOAT_TRIANGLE
#	define Q_2D_QUADRANGLE		Q_2D_FLOAT_QUADRANGLE
#	define Q_3D_QUADRANGLE		Q_3D_FLOAT_QUADRANGLE
#	define Q_RECTANGLE		Q_FLOAT_RECTANGLE
#	define Q_BOX			Q_FLOAT_BOX
#	define Q_CIRCLE			Q_FLOAT_CIRCLE
#	define Q_SPHERE			Q_FLOAT_SPHERE

#elif defined(Q_USE_REAL_LDOUBLE)

	typedef Q2DLDoubleVector	Q2DVector;
	typedef	Q2DLDoubleVector	Q3DVector;
	typedef Q2DLDoubleLine		Q2DLine;
	typedef Q3DLDoubleLine		Q3DLine;
	typedef Q2DLDoubleTriangle	Q2DTriangle;
	typedef Q3DLDoubleTriangle	Q2DTriangle;
	typedef Q2DLDoubleQuadrangle	Q2DQuadrangle;
	typedef Q3DLDoubleQuadrangle	Q3DQuadrangle;
	typedef QLDoubleRectangle	QRectangle;
	typedef QLDoubleBox		QBox;
	typedef QLDoubleCircle		QCircle;
	typedef QLDoubleSphere		QSphere;

#	define Q_2D_VECTOR		Q_2D_LDOUBLE_VECTOR
#	define Q_3D_VECTOR		Q_3D_LDOUBLE_VECTOR
#	define Q_2D_LINE		Q_2D_LDOUBLE_LINE
#	define Q_3D_LINE		Q_3D_LDOUBLE_LINE
#	define Q_2D_TRIANGLE		Q_2D_LDOUBLE_TRIANGLE
#	define Q_3D_TRIANGLE		Q_3D_LDOUBLE_TRIANGLE
#	define Q_2D_QUADRANGLE		Q_2D_LDOUBLE_QUADRANGLE
#	define Q_3D_QUADRANGLE		Q_3D_LDOUBLE_QUADRANGLE
#	define Q_RECTANGLE		Q_LDOUBLE_RECTANGLE
#	define Q_BOX			Q_LDOUBLE_BOX
#	define Q_CIRCLE			Q_LDOUBLE_CIRCLE
#	define Q_SPHERE			Q_LDOUBLE_SPHERE

#else

	typedef Q2DLDoubleVector	Q2DVector;
	typedef	Q2DLDoubleVector	Q3DVector;
	typedef Q2DDoubleLine		Q2DLine;
	typedef Q3DDoubleLine		Q3DLine;
	typedef Q2DDoubleTriangle	Q2DTriangle;
	typedef Q3DDoubleTriangle	Q3DTriangle;
	typedef Q2DDoubleQuadrangle	Q2DQuadrangle;
	typedef Q3DDoubleQuadrangle	Q3DQuadrangle;
	typedef QDoubleRectangle	QRectangle;
	typedef QLDoubleBox		QBox;
	typedef QDoubleCircle		QCircle;
	typedef QDoubleSphere		QSphere;

#	define Q_2D_VECTOR		Q_2D_DOUBLE_VECTOR
#	define Q_3D_VECTOR		Q_3D_DOUBLE_VECTOR
#	define Q_2D_LINE		Q_2D_DOUBLE_LINE
#	define Q_3D_LINE		Q_3D_DOUBLE_LINE
#	define Q_2D_TRIANGLE		Q_2D_DOUBLE_TRIANGLE
#	define Q_3D_TRIANGLE		Q_3D_DOUBLE_TRIANGLE
#	define Q_2D_QUADRANGLE		Q_2D_DOUBLE_QUADRANGLE
#	define Q_3D_QUADRANGLE		Q_3D_DOUBLE_QUADRANGLE
#	define Q_RECTANGLE		Q_DOUBLE_RECTANGLE
#	define Q_BOX			Q_DOUBLE_BOX
#	define Q_CIRCLE			Q_DOUBLE_CIRCLE
#	define Q_SPHERE			Q_DOUBLE_SPHERE

#endif

#endif /* __Q_types_geometry_H__ */
