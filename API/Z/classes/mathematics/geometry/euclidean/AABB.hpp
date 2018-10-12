/* Z Kit - classes/mathematics/geometry/euclidean/AABB.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_mathematics_geometry_euclidean_AABB_HPP_
#define _Z_classes_mathematics_geometry_euclidean_AABB_HPP_

#include <Z/classes/mathematics/geometry/euclidean/Line3D.hpp>


namespace Zeta {namespace Partials {namespace AABB {

#	define Z_THIS ((AABB *)this)

	template <class AABB, class T, UInt T_number_set> struct Part;


	// MARK: - Partial implementation for integer types


	template <class AABB, class T>
	struct Part<AABB, T, Z_NUMBER_SET_Z> {
	};


	// MARK: - Partial implementation for real types


	template <class AABB, class T>
	struct Part<AABB, T, Z_NUMBER_SET_R> {

		Z_CT(CPP11) Zeta::Value3D<T> absolute_point_to_unit(const Zeta::Value3D<T> &point)
			{return (point - Z_THIS->a) / (Z_THIS->b - Z_THIS->a);}


		/*Z_CT(CPP11) Boolean contains(const Circle<T> circle)
			{
			return	circle.point - circle.radius >= Z_THIS->a &&
				circle.point + circle.radius <= Z_THIS->b;
			}*/


		/*Z_CT(CPP11) Circle<T> inner_circle()
			{return Circle<T>(Z_THIS->center(), (b - a).inner_minimum() / T(2));}*/


		Z_CT(CPP11) Zeta::Value3D<T> unit_point_to_absolute(Zeta::Value3D<T> point)
			{return point * (object.b - object.a) + object.a;}
	};


#	undef Z_THIS

}}}


namespace Zeta {template <class T> struct AABB : Line3D<T>, Partials::Rectangle::Part<AABB<T>, T, Type<T>::number_set> {

	typedef typename ZTypeFixedSigned(ZAABR, T) Base;


	Z_INLINE AABR() {}

	Z_CT(CPP11) AABR(const Value2D<T> &a, const Value2D<T> &b) : Line2D<T>(a, b)		   {}
	Z_CT(CPP11) AABR(const Value2D<T> &a, T b_x, T b_y)	   : Line2D<T>(a, b_x, b_y)	   {}
	Z_CT(CPP11) AABR(const Value2D<T> &a, T b_xy)		   : Line2D<T>(a, b_xy)		   {}
	Z_CT(CPP11) AABR(T a_x, T a_y, const Value2D<T> &b)	   : Line2D<T>(a_x, a_y, b)	   {}
	Z_CT(CPP11) AABR(T a_x, T a_y, T b_x, T b_y)		   : Line2D<T>(a_x, a_y, b_x, b_y) {}
	Z_CT(CPP11) AABR(T a_xy, T b_x, T b_y)			   : Line2D<T>(a_xy, b_x, b_y)	   {}
	Z_CT(CPP11) AABR(T a_xy, const Value2D<T> &b)		   : Line2D<T>(a_xy, b)		   {}
	Z_CT(CPP11) AABR(T b_x, T b_y)				   : Line2D<T>(b_x, b_y)	   {}
	Z_CT(CPP11) AABR(T b_xy)				   : Line2D<T>(b_xy)		   {}

	Z_INLINE AABR(const Base &aabr) {(*(Base *)this) = aabr;}
};}


#endif // _Z_classes_mathematics_geometry_euclidean_AABR_HPP_
