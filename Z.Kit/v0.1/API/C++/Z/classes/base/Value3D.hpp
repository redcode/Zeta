/* Z Kit C++ API - classes/base/Value3D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Value3D_HPP__
#define __Z_classes_base_Value3D_HPP__

#include <Z/macros/type selection.hpp>
#include <Z/functions/base/value.hpp>

namespace Zeta {template <class T> struct Value3D;}


template <class T> struct Zeta::Value3D {

	typedef typename ZTypeFixedNumber(Z3D, T) Base;

	T x, y, z;


	// MARK: - Constructors


	Z_INLINE_MEMBER Value3D() {}

	Z_CONSTANT_MEMBER(CPP11) Value3D(T x, T y, T z) : x(x),      y(y),	z(z)	  {}
	Z_CONSTANT_MEMBER(CPP11) Value3D(T scalar)	: x(scalar), y(scalar), z(scalar) {}

	Z_INLINE_MEMBER Value3D(const Base &value) {(*(Base *)this) = value;}


	// MARK: - Static functions


	// MARK: - Operators


	Z_CONSTANT_MEMBER(CPP11) operator Boolean() const {return x != T(0) || y != T(0) || z != T(0);}
	Z_INLINE_MEMBER		 operator Base&  () const {return *((Base *)this);}

	Z_CONSTANT_MEMBER(CPP11) Boolean operator ==(const Value3D &value) const {return x == value.x && y == value.y && z == value.z;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator !=(const Value3D &value) const {return x != value.x || y != value.y || z != value.z;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator <=(const Value3D &value) const {return x <= value.x && y <= value.y && z <= value.z;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator >=(const Value3D &value) const {return x >= value.x && y >= value.y && z >= value.z;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator  >(const Value3D &value) const {return x >  value.x && y >  value.y && z >  value.z;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator  <(const Value3D &value) const {return x <  value.x && y <  value.y && z <  value.z;}

	Z_CONSTANT_MEMBER(CPP11) Value3D operator +(const Value3D &value) const {return Value3D(x + value.x, y + value.y, z + value.z);}
	Z_CONSTANT_MEMBER(CPP11) Value3D operator -(const Value3D &value) const {return Value3D(x - value.x, y - value.y, z - value.z);}
	Z_CONSTANT_MEMBER(CPP11) Value3D operator *(const Value3D &value) const {return Value3D(x * value.x, y * value.y, z * value.z);}
	Z_CONSTANT_MEMBER(CPP11) Value3D operator /(const Value3D &value) const {return Value3D(x / value.x, y / value.y, z / value.z);}

	Z_INLINE_MEMBER Value3D &operator +=(const Value3D &value) {return *this = *this + value;}
	Z_INLINE_MEMBER Value3D &operator -=(const Value3D &value) {return *this = *this - value;}
	Z_INLINE_MEMBER Value3D &operator *=(const Value3D &value) {return *this = *this * value;}
	Z_INLINE_MEMBER Value3D &operator /=(const Value3D &value) {return *this = *this / value;}

	Z_CONSTANT_MEMBER(CPP11) Boolean operator ==(T scalar) const {return x == scalar && y == scalar && z == scalar;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator !=(T scalar) const {return x != scalar || y != scalar || z != scalar;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator <=(T scalar) const {return x <= scalar && y <= scalar && z <= scalar;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator >=(T scalar) const {return x >= scalar && y >= scalar && z >= scalar;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator  >(T scalar) const {return x >  scalar && y >	scalar && z >  scalar;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator  <(T scalar) const {return x <  scalar && y <	scalar && z <  scalar;}

	Z_CONSTANT_MEMBER(CPP11) Value3D operator +(T scalar) const {return Value3D(x + scalar, y + scalar, z + scalar);}
	Z_CONSTANT_MEMBER(CPP11) Value3D operator -(T scalar) const {return Value3D(x - scalar, y - scalar, z - scalar);}
	Z_CONSTANT_MEMBER(CPP11) Value3D operator *(T scalar) const {return Value3D(x * scalar, y * scalar, z * scalar);}
	Z_CONSTANT_MEMBER(CPP11) Value3D operator /(T scalar) const {return Value3D(x / scalar, y / scalar, z / scalar);}

	Z_INLINE_MEMBER Value3D &operator +=(T scalar) {return *this = *this + scalar;}
	Z_INLINE_MEMBER Value3D &operator -=(T scalar) {return *this = *this - scalar;}
	Z_INLINE_MEMBER Value3D &operator *=(T scalar) {return *this = *this * scalar;}
	Z_INLINE_MEMBER Value3D &operator /=(T scalar) {return *this = *this / scalar;}

	Z_INLINE_MEMBER T  operator[](int index) const {return ((T *)this)[index];}
	Z_INLINE_MEMBER T &operator[](int index)       {return ((T *)this)[index];}


	// MARK: - Interoperability
	// MARK: - Operations for natural, integer and real types
	// MARK: - Operations for integer and real types
	// MARK: - Operations for real types only

#ifndef Z_DECLARING_PARTIAL_VALUE_3D
};
#endif


#endif // __Z_classes_base_Value3D_HPP__
