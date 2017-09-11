/* Z Kit C++ API - classes/mathematics/geometry/euclidean/Line2D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_mathematics_geometry_euclidean_Line2D_HPP__
#define __Z_classes_mathematics_geometry_euclidean_Line2D_HPP__

#include <Z/classes/base/Value2D.hpp>
#include <Z/types/mathematics.h>


namespace Zeta {namespace Mixins {namespace Line2D {

#	define Z_THIS ((Line2D *)this)

	template <class Line2D, class T, UInt T_number_set> struct Partial;


	// MARK: - Partial implementation for integer types


	template <class Line2D, class T>
	struct Partial<Line2D, T, Z_NUMBER_SET_Z> {};


	// MARK: - Partial implementation for real types


	template <class Line2D, class T>
	struct Partial<Line2D, T, Z_NUMBER_SET_R> {

		Z_CT_MEMBER(CPP14) Boolean segment_intersects(Line2D line_segment) const
			{
			Zeta::Value2D<T> d  = line_segment.a - Z_THIS->a;
			Zeta::Value2D<T> va = Z_THIS->b - Z_THIS->a;
			Zeta::Value2D<T> vb = line_segment.b - line_segment.a;
			T		 c  = va.cross_product(vb);
			T		 t  = d.cross_product(vb) / c;
			T		 u  = d.cross_product(va) / c;

			return !(t < T(0) || t > T(1) || u < T(0) || u > T(1));
			}


		Z_CT_MEMBER(CPP11) Zeta::Value2D<T> segment_lerp(T alpha) const
			{return Z_THIS->a.lerp(Z_THIS->b, alpha);}
	};


#	undef Z_THIS

}}}


namespace Zeta {template <class T> struct Line2D : Mixins::Line2D::Partial<Line2D<T>, T, Type<T>::number_set> {

	typedef typename ZTypeFixedSigned(Z2DLine, T) Base;

	Value2D<T> a, b;


	Z_INLINE_MEMBER Line2D() {}

	Z_CT_MEMBER(CPP11) Line2D(const Value2D<T> &a, const Value2D<T> &b) : a(a),	   b(b)	       {}
	Z_CT_MEMBER(CPP11) Line2D(const Value2D<T> &a, T b_x, T b_y)	    : a(a),	   b(b_x, b_y) {}
	Z_CT_MEMBER(CPP11) Line2D(const Value2D<T> &a, T b_xy)		    : a(a),	   b(b_xy)     {}
	Z_CT_MEMBER(CPP11) Line2D(T a_x, T a_y, const Value2D<T> &b)	    : a(a_x, a_y), b(b)	       {}
	Z_CT_MEMBER(CPP11) Line2D(T a_x, T a_y, T b_x, T b_y)		    : a(a_x, a_y), b(b_x, b_y) {}
	Z_CT_MEMBER(CPP11) Line2D(T a_xy, T b_x, T b_y)			    : a(a_xy),	   b(b_x, b_y) {}
	Z_CT_MEMBER(CPP11) Line2D(T a_xy, const Value2D<T> &b)		    : a(a_xy),	   b(b)	       {}
	Z_CT_MEMBER(CPP11) Line2D(const Value2D<T> &b)			    : a(T(0)),	   b(b)	       {}
	Z_CT_MEMBER(CPP11) Line2D(T b_x, T b_y)				    : a(T(0)),	   b(b_x, b_y) {}
	Z_CT_MEMBER(CPP11) Line2D(T b_xy)				    : a(T(0)),	   b(b_xy)     {}

	Z_INLINE_MEMBER Line2D(const Base &line) {(*(Base *)this) = line;}


	Z_CT_MEMBER(CPP11) Boolean operator ==(const Line2D &line) const
		{return a == line.a && b == line.b;}


	Z_CT_MEMBER(CPP11) Boolean operator !=(const Line2D &line) const
		{return a != line.a || b != line.b;}


	Z_CT_MEMBER(CPP11) Boolean is_perpendicular(const Line2D &line) const
		{return ((a.b - a.a).is_perpendicular(line.b - line.a));}


	Z_CT_MEMBER(CPP11) Boolean is_zero() const
		{return a.is_zero() && b.is_zero();}


	Z_CT_MEMBER(CPP11) Line2D reverse() const
		{return Line2D(b, a);}


	Z_INLINE_MEMBER void swap(Line2D &line)
		{Zeta::swap<Base>((Base *)this, (Base *)&line);}


	Z_CT_MEMBER(CPP11) Line2D segment_center() const
		{return a.middle(b);}
	};}


#endif // __Z_classes_mathematics_geometry_euclidean_Line2D_HPP__
