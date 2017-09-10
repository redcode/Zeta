/* Z Kit C++ API - classes/mathematics/geometry/euclidean/Line3D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_mathematics_geometry_euclidean_Line3D_HPP__
#define __Z_classes_mathematics_geometry_euclidean_Line3D_HPP__

#include <Z/classes/base/Value3D.hpp>
#include <Z/types/mathematics.h>


namespace Zeta {namespace Mixins {namespace Line3D {

#	define Z_THIS ((Line3D *)this)

	template <class Line3D, class T, UInt T_number_set> struct Partial;


	// MARK: - Partial implementation for integer types


	template <class Line3D, class T>
	struct Partial<Line3D, T, Z_NUMBER_SET_Z> {};


	// MARK: - Partial implementation for real types


	template <class Line3D, class T>
	struct Partial<Line3D, T, Z_NUMBER_SET_R> {

		Z_CT_MEMBER(CPP11) Zeta::Value3D<T> segment_lerp(T alpha) const
			{return Z_THIS->a.lerp(Z_THIS->b, alpha);}
	};


#	undef Z_THIS

}}}


namespace Zeta {template <class T> struct Line3D: Mixins::Line3D::Partial<Line3D<T>, T, Type<T>::number_set> {

	typedef typename ZTypeFixedSigned(Z3DLine, T) Base;

	Value3D<T> a, b;


	Z_INLINE_MEMBER Line3D() {}

	Z_CT_MEMBER(CPP11) Line3D(const Value3D<T> &a, const Value3D<T> &b) : a(a),		b(b)		 {}
	Z_CT_MEMBER(CPP11) Line3D(const Value3D<T> &a, T b_x, T b_y, T b_z) : a(a),		b(b_x, b_y, b_z) {}
	Z_CT_MEMBER(CPP11) Line3D(const Value3D<T> &a, T b_xyz)		    : a(a),		b(b_xyz)	 {}
	Z_CT_MEMBER(CPP11) Line3D(T a_x, T a_y, T a_z, const Value2D<T> &b) : a(a_x, a_y, a_z), b(b)		 {}
	Z_CT_MEMBER(CPP11) Line3D(T a_x, T a_y, T a_z, T b_x, T b_y, T b_z) : a(a_x, a_y, a_z), b(b_x, b_y, b_z) {}
	Z_CT_MEMBER(CPP11) Line3D(T a_xyz, T b_x, T b_y, T b_z)		    : a(a_xyz),		b(b_x, b_y, b_z) {}
	Z_CT_MEMBER(CPP11) Line3D(T a_xyz, const Value2D<T> &b)		    : a(a_xyz),		b(b)		 {}

	Z_INLINE_MEMBER Line3D(const Base &line) {(*(Base *)this) = line;}


	Z_CT_MEMBER(CPP11) Boolean operator ==(const Line3D &line) const
		{return a == line.a && b == line.b;}


	Z_CT_MEMBER(CPP11) Boolean operator !=(const Line3D &line) const
		{return a != line.a || b != line.b;}


	Z_CT_MEMBER(CPP11) Boolean is_perpendicular(const Line3D &line) const
		{return ((a.b - a.a).is_perpendicular(line.b - line.a));}


	Z_CT_MEMBER(CPP11) Boolean is_zero() const
		{return a.is_zero() && b.is_zero();}


	Z_CT_MEMBER(CPP11) Line3D reverse() const
		{return Line3D(b, a);}


	Z_INLINE_MEMBER void swap(Line3D &line)
		{Zeta::swap<Base>((Base *)this, (Base *)&line);}


	Z_CT_MEMBER(CPP11) Line3D segment_center() const
		{return a.middle(b);}
	};}


#endif // __Z_classes_mathematics_geometry_euclidean_Line3D_HPP__
