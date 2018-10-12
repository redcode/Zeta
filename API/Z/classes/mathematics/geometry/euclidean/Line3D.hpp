/* Z Kit - classes/mathematics/geometry/euclidean/Line3D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_mathematics_geometry_euclidean_Line3D_HPP_
#define _Z_classes_mathematics_geometry_euclidean_Line3D_HPP_

#include <Z/classes/base/Value3D.hpp>
#include <Z/types/mathematics.h>


#define Z_IMPLEMENTATION_COMMON									\
												\
typedef typename ZTypeFixedSigned(Z3DLine, T) Base;						\
Value3D<T> a, b;										\
												\
Z_INLINE Line3D() Z_DEFAULTED({})								\
												     \
Z_CT(CPP11) Line3D(const Value3D<T> &a, const Value3D<T> &b) : a(a),		 b(b)		  {} \
Z_CT(CPP11) Line3D(const Value3D<T> &a, T b_x, T b_y, T b_z) : a(a),		 b(b_x, b_y, b_z) {} \
Z_CT(CPP11) Line3D(const Value3D<T> &a, T b_xyz)	     : a(a),		 b(b_xyz)	  {} \
Z_CT(CPP11) Line3D(T a_x, T a_y, T a_z, const Value3D<T> &b) : a(a_x, a_y, a_z), b(b)		  {} \
Z_CT(CPP11) Line3D(T a_x, T a_y, T a_z, T b_x, T b_y, T b_z) : a(a_x, a_y, a_z), b(b_x, b_y, b_z) {} \
Z_CT(CPP11) Line3D(T a_xyz, T b_x, T b_y, T b_z)	     : a(a_xyz),	 b(b_x, b_y, b_z) {} \
Z_CT(CPP11) Line3D(T a_xyz, const Value3D<T> &b)	     : a(a_xyz),	 b(b)		  {} \
Z_CT(CPP11) Line3D(const Value3D<T> &b)			     : a(T(0)),		 b(b)		  {} \
Z_CT(CPP11) Line3D(T b_x, T b_y, T b_z)			     : a(T(0)),		 b(b_x, b_y, b_z) {} \
Z_CT(CPP11) Line3D(T b_xyz)				     : a(T(0)),		 b(b_xyz)	  {} \
												     \
Z_INLINE Line3D(const Base &line) {(*(Base *)this) = line;}					\
												\
Z_CT(CPP11) Boolean operator ==(const Line3D &line) const {return a == line.a && b == line.b;}	\
Z_CT(CPP11) Boolean operator !=(const Line3D &line) const {return a != line.a || b != line.b;}	\
												\
												\
Z_CT(CPP11) Boolean is_perpendicular(const Line3D &line) const					\
	{return ((a.b - a.a).is_perpendicular(line.b - line.a));}				\
												\
												\
Z_CT(CPP11) Boolean is_zero() const								\
	{return a.is_zero() && b.is_zero();}							\
												\
												\
Z_CT(CPP11) Line3D reverse() const								\
	{return Line3D(b, a);}									\
												\
												\
Z_INLINE void swap(Line3D &line)								\
	{Zeta::swap<Base>((Base *)this, (Base *)&line);}					\
												\
												\
Z_CT(CPP11) Value3D<T> segment_center() const							\
	{return a.middle(b);}


namespace Zeta {
	template <class T, UInt T_number_set = Type<T>::number_set> struct Line3D {};


	template <class T> struct Line3D<T, Z_NUMBER_SET_Z> {
		Z_IMPLEMENTATION_COMMON
	};


	template <class T> struct Line3D<T, Z_NUMBER_SET_R> {
		Z_IMPLEMENTATION_COMMON


		Z_CT(CPP11) Value3D<T> segment_lerp(T alpha) const
			{return a.lerp(b, alpha);}
	};
}


#undef Z_IMPLEMENTATION_COMMON

#endif // _Z_classes_mathematics_geometry_euclidean_Line3D_HPP_
