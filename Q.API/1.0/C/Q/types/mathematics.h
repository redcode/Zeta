/* Q API - types/mathematics.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_mathematics_H__
#define __Q_types_mathematics_H__

#include <Q/types/basics.h>

#pragma mark - Vector

typedef struct {Q2DFloat   a, b;}			Q2DFloatVector;
typedef struct {Q2DDouble  a, b;}			Q2DDoubleVector;
typedef struct {Q2DLDouble a, b;}			Q2DLDoubleVector;

typedef struct {Q3DFloat   a, b;}			Q3DFloatVector;
typedef struct {Q3DDouble  a, b;}			Q3DDoubleVector;
typedef struct {Q3DLDouble a, b;}			Q3DLDoubleVector;

#pragma mark - Line

typedef Q2DFloatVector					Q2DFloatLine;
typedef Q2DDoubleVector					Q2DDoubleLine;
typedef Q2DLDoubleVector				Q2DLDoubleLine;

typedef Q3DFloatVector					Q3DFloatLine;
typedef Q3DDoubleVector					Q3DDoubleLine;
typedef Q3DLDoubleVector				Q3DLDoubleLine;

#pragma mark - Triangle

typedef struct {Q2DFloat   a, b, c;}			QFloatTriangle;
typedef struct {Q2DDouble  a, b, c;}			QDoubleTriangle;
typedef struct {Q2DLDouble a, b, c;}			QLDoubleTriangle;

#pragma mark - Rectangle

typedef struct {Q2DFloat   point, size;}		QFloatRectangle;
typedef struct {Q2DDouble  point, size;}		QDoubleRectangle;
typedef struct {Q2DLDouble point, size;}		QLDoubleRectangle;

#pragma mark - Circle

typedef struct {Q2DFloat   point; qfloat   radius;}	QFloatCircle;
typedef struct {Q2DDouble  point; qdouble  radius;}	QDoubleCircle;
typedef struct {Q2DLDouble point; qldouble radius;}	QLDoubleCircle;

#pragma mark - Sphere

typedef struct {Q3DFloat   point; qfloat   radius;}	QFloatSphere;
typedef struct {Q3DDouble  point; qdouble  radius;}	QDoubleSphere;
typedef struct {Q3DLDouble point; qldouble radius;}	QLDoubleSphere;

#define q_2d	q_2d_real
#define q_3d	q_3d_real

#if defined(Q_USE_FLOAT_REAL)

	typedef qfloat			qreal;
	typedef Q2DFloat		Q2D;
	typedef Q2DFloatVector		Q2DVector;
	typedef Q2DFloatLine		Q2DLine;
	typedef QFloatTriangle		QTriangle;
	typedef QFloatRectangle		QRectangle;
	typedef QFloatCircle		QCircle;
	typedef Q3DFloat		Q3D;
	typedef	Q2DFloatVector		Q3DVector;
	typedef Q3DFloatLine		Q3DLine;
	typedef QFloatSphere		QSphere;

#elif defined(Q_USE_LDOUBLE_REAL)

	typedef qldouble		qreal;
	typedef Q2DLDouble		Q2D;
	typedef Q2DLDoubleVector	Q2DVector;
	typedef Q2DLDoubleLine		Q2DLine;
	typedef QLDoubleTriangle	QTriangle;
	typedef QLDoubleRectangle	QRectangle;
	typedef QLDoubleCircle		QCircle;
	typedef Q3DLDouble		Q3D;
	typedef	Q3DLDoubleVector	Q3DVector;
	typedef Q3DLDoubleLine		Q3DLine;
	typedef QLDoubleSphere		QSphere;

#else

	typedef qdouble			qreal;
	typedef Q2DDouble		Q2D;
	typedef Q2DDoubleVector		Q2DVector;
	typedef Q2DDoubleLine		Q2DLine;
	typedef QDoubleTriangle		QTriangle;
	typedef QDoubleRectangle	QRectangle;
	typedef QDoubleCircle		QCircle;
	typedef Q3DDouble		Q3D;
	typedef	Q3DDoubleVector		Q3DVector;
	typedef Q3DDoubleLine		Q3DLine;
	typedef QDoubleSphere		QSphere;

#endif

#endif /* __Q_types_mathematics_H__ */
