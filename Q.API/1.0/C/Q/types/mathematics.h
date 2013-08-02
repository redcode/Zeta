/* Q API - types/mathematics.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_mathematics_H__
#define __Q_types_mathematics_H__

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

/* MARK: - Circle */

typedef struct {Q2DFloat   point; qfloat   radius;}	QFloatCircle;
typedef struct {Q2DDouble  point; qdouble  radius;}	QDoubleCircle;
typedef struct {Q2DLDouble point; qldouble radius;}	QLDoubleCircle;

/* MARK: - Sphere */

typedef struct {Q3DFloat   point; qfloat   radius;}	QFloatSphere;
typedef struct {Q3DDouble  point; qdouble  radius;}	QDoubleSphere;
typedef struct {Q3DLDouble point; qldouble radius;}	QLDoubleSphere;

/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

	typedef Q2DFloat		Q2D;
	typedef Q3DFloat		Q3D;
	typedef Q2DFloatVector		Q2DVector;
	typedef	Q2DFloatVector		Q3DVector;
	typedef Q2DFloatLine		Q2DLine;
	typedef Q3DFloatLine		Q3DLine;
	typedef Q2DFloatTriangle	Q2DTriangle;
	typedef Q3DFloatTriangle	Q2DTriangle;
	typedef Q2DFloatQuadrangle	Q2DQuadrangle;
	typedef Q3DFloatQuadrangle	Q3DQuadrangle;
	typedef QFloatRectangle		QRectangle;
	typedef QFloatCircle		QCircle;
	typedef QFloatSphere		QSphere;

#elif defined(Q_USE_REAL_LDOUBLE)

	typedef Q2DLDouble		Q2D;
	typedef Q3DLDouble		Q3D;
	typedef Q2DLDoubleVector	Q2DVector;
	typedef	Q2DLDoubleVector	Q3DVector;
	typedef Q2DLDoubleLine		Q2DLine;
	typedef Q3DLDoubleLine		Q3DLine;
	typedef Q2DLDoubleTriangle	Q2DTriangle;
	typedef Q3DLDoubleTriangle	Q2DTriangle;
	typedef Q2DLDoubleQuadrangle	Q2DQuadrangle;
	typedef Q3DLDoubleQuadrangle	Q3DQuadrangle;
	typedef QLDoubleRectangle	QRectangle;
	typedef QLDoubleCircle		QCircle;
	typedef QLDoubleSphere		QSphere;

#else

	typedef Q2DDouble		Q2D;
	typedef Q3DDouble		Q3D;
	typedef Q2DLDoubleVector	Q2DVector;
	typedef	Q2DLDoubleVector	Q3DVector;
	typedef Q2DDoubleLine		Q2DLine;
	typedef Q3DDoubleLine		Q3DLine;
	typedef Q2DDoubleTriangle	Q2DTriangle;
	typedef Q3DDoubleTriangle	Q2DTriangle;
	typedef Q2DDoubleQuadrangle	Q2DQuadrangle;
	typedef Q3DDoubleQuadrangle	Q3DQuadrangle;
	typedef QDoubleRectangle	QRectangle;
	typedef QDoubleCircle		QCircle;
	typedef QDoubleSphere		QSphere;

#endif

#endif /* __Q_types_mathematics_H__ */
