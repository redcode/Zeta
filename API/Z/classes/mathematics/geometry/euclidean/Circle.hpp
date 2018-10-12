/* Z Kit - classes/mathematics/geometry/euclidean/Rectangle.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_mathematics_geometry_euclidean_Rectangle_HPP_
#define _Z_classes_mathematics_geometry_euclidean_Rectangle_HPP_

#include <Z/classes/base/Value2D.hpp>
#include <Z/types/mathematics.h>


namespace Zeta {template <class T> struct Circle {

	typedef typename ZTypeFixedReal(ZCircle, T) Base;

	Value2D<T> point;
	T radius;


	Z_INLINE Circle() Z_DEFAULTED({})

	Z_CT(CPP11) Circle(const Value2D<T> &point, T radius) : point(point), radius(radius) {}
	Z_CT(CPP11) Circle(T x, T y, T radius)		      : point(x, y),  radius(radius) {}

	Z_INLINE Circle(const Base &circle) {(*(Base *)this) = circle;}


	Z_CT(CPP11) Boolean operator ==(const Circle &circle) const
		{return point.x == circle.point.x && point.y == circle.point.y && radius == circle.radius;}


	Z_CT(CPP11) Boolean operator !=(const Circle &circle) const
		{return point.x != circle.point.x || point.y != circle.point.y || radius != circle.radius;}




Z_INLINE ZAABR##Type z_circle_##type##_inner_aabr(ZCircle##Type object)				\
	{											\
	z##type half_size = object.radius / _(Z_SQUARE_ROOT_2);					\
												\
	return z_aabr_##type									\
		(object.point.x - half_size, object.point.y - half_size,			\
		 object.point.x + half_size, object.point.x + half_size);			\
	}											\
												\
												\
Z_INLINE ZRectangle##Type z_circle_##type##_inner_rectangle(ZCircle##Type object)		\
	{											\
	z##type half_size = object.radius / _(Z_SQUARE_ROOT_2);					\
	z##type size = half_size * _(2.0);							\
												\
	return z_rectangle_##type								\
		(object.point.x - half_size, object.point.y - half_size, size, size);		\
	}											\
												\
												\


	Z_CT(CPP11) Boolean is_zero() const
		{return radius == T(0) && point.is_zero();}


	Z_CT(CPP11) AABR<T> outer_aabr() const
		{return AABR<T>(point - radius, point + radius);}


	Z_CT(CPP11) Rectangle<T> outer_rectangle() const
		{return Rectangle<T>(point - radius, radius * T(2));}


	Z_INLINE void swap(Circle &circle)
		{Zeta::swap<Base>((Base *)this, (Base *)&circle);}
};}


#endif // _Z_classes_mathematics_geometry_euclidean_Rectangle_HPP_
