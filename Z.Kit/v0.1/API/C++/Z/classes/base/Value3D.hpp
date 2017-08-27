/* Z Kit C++ API - classes/base/Value3D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Value3D_HPP__
#define __Z_classes_base_Value3D_HPP__

#ifndef __Z_classes_base_Value2D_HPP__
#	include <Z/classes/base/Value2D.hpp>
#endif


namespace Zeta {namespace Mixins {namespace Value3D {

#	define Z_THIS ((Value3D *)this)

	template <class Value3D, class T, UInt T_number_set> struct Partial;


	// MARK: - Partial implementation for signed types


	template <class Value3D, class T>
	struct Signed {

		Z_CT_MEMBER(CPP11) Value3D absolute() const
			{
			return Value3D
				(Zeta::absolute<T>(Z_THIS->x),
				 Zeta::absolute<T>(Z_THIS->y),
				 Zeta::absolute<T>(Z_THIS->z));
			}


		Z_CT_MEMBER(CPP11) Boolean has_negative() const
			{return Z_THIS->x < T(0) || Z_THIS->y < T(0) || Z_THIS->z < T(0);}


		Z_CT_MEMBER(CPP11) Boolean is_negative() const
			{return Z_THIS->x < T(0) && Z_THIS->y < T(0) && Z_THIS->z < T(0);}


		Z_CT_MEMBER(CPP11) Value3D negative() const
			{return Value3D(-Z_THIS->x, -Z_THIS->y, -Z_THIS->z);}
	};


	// MARK: - Partial implementation for natural types


	template <class Value3D, class T>
	struct Partial<Value3D, T, Z_NUMBER_SET_N> {};


	// MARK: - Partial implementation for integer types


	template <class Value3D, class T>
	struct Partial<Value3D, T, Z_NUMBER_SET_Z> : Signed<Value3D, T> {

		Z_CT_MEMBER(CPP11) Boolean is_perpendicular(const Value3D &value) const
			{return !Zeta::absolute<T>(dot_product(value));}
	};


	// MARK: - Partial implementation for real types


	template <class Value3D, class T>
	struct Partial<Value3D, T, Z_NUMBER_SET_R> : Signed<Value3D, T> {

		Z_CT_MEMBER(CPP11) Value3D clamp_01() const
			{
			return Value3D
				(Zeta::clamp_01<T>(Z_THIS->x),
				 Zeta::clamp_01<T>(Z_THIS->y),
				 Zeta::clamp_01<T>(Z_THIS->z));
			}


		Z_CT_MEMBER(CPP11) Boolean has_almost_zero() const
			{
			return	Zeta::is_almost_zero<T>(Z_THIS->x) ||
				Zeta::is_almost_zero<T>(Z_THIS->y) ||
				Zeta::is_almost_zero<T>(Z_THIS->z);
			}


		Z_CT_MEMBER(CPP11) Boolean has_finite() const
			{
			return	Zeta::is_finite<T>(Z_THIS->x) ||
				Zeta::is_finite<T>(Z_THIS->y) ||
				Zeta::is_finite<T>(Z_THIS->z);
			}


		Z_CT_MEMBER(CPP11) Boolean has_infinity() const
			{
			return	Zeta::is_infinity<T>(Z_THIS->x) ||
				Zeta::is_infinity<T>(Z_THIS->y) ||
				Zeta::is_infinity<T>(Z_THIS->z);
			}


		Z_CT_MEMBER(CPP11) Boolean has_nan() const
			{
			return	Zeta::is_nan<T>(Z_THIS->x) ||
				Zeta::is_nan<T>(Z_THIS->y) ||
				Zeta::is_nan<T>(Z_THIS->z);
			}


		Z_CT_MEMBER(CPP11) Value3D inverse_lerp(const Value3D &value, T t) const
			{
			return Value3D
				(Zeta::inverse_lerp<T>(Z_THIS->x, value.x, t),
				 Zeta::inverse_lerp<T>(Z_THIS->y, value.y, t),
				 Zeta::inverse_lerp<T>(Z_THIS->z, value.z, t));
			}


		Z_CT_MEMBER(CPP11) Boolean is_almost_equal(const Value3D &value) const
			{
			return	Zeta::are_almost_equal<T>(Z_THIS->x, value.x) &&
				Zeta::are_almost_equal<T>(Z_THIS->y, value.y) &&
				Zeta::are_almost_equal<T>(Z_THIS->z, value.z);
			}


		Z_CT_MEMBER(CPP11) Boolean is_almost_zero() const
			{
			return	Zeta::is_almost_zero<T>(Z_THIS->x) &&
				Zeta::is_almost_zero<T>(Z_THIS->y) &&
				Zeta::is_almost_zero<T>(Z_THIS->z);
			}


		Z_CT_MEMBER(CPP11) Boolean is_finite() const
			{
			return	Zeta::is_finite<T>(Z_THIS->x) &&
				Zeta::is_finite<T>(Z_THIS->y) &&
				Zeta::is_finite<T>(Z_THIS->z);
			}


		Z_CT_MEMBER(CPP11) Boolean is_infinity() const
			{
			return	Zeta::is_infinity<T>(Z_THIS->x) &&
				Zeta::is_infinity<T>(Z_THIS->y) &&
				Zeta::is_infinity<T>(Z_THIS->z);
			}


		Z_CT_MEMBER(CPP11) Boolean is_nan() const
			{
			return	Zeta::is_nan<T>(Z_THIS->x) &&
				Zeta::is_nan<T>(Z_THIS->y) &&
				Zeta::is_nan<T>(Z_THIS->z);
			}


		Z_CT_MEMBER(CPP11) Boolean is_perpendicular(const Value3D &value) const
			{return Zeta::absolute<T>(dot_product(value)) <= Type<T>::epsilon();}


		Z_CT_MEMBER(CPP11) Value3D lerp(const Value3D &value, T t) const
			{
			return Value3D
				(Zeta::lerp<T>(Z_THIS->x, value.x, t),
				 Zeta::lerp<T>(Z_THIS->y, value.y, t),
				 Zeta::lerp<T>(Z_THIS->z, value.z, t));
			}


		Z_CT_MEMBER(CPP11) Value3D reciprocal() const
			{return Value3D(T(1) / Z_THIS->x, T(1) / Z_THIS->y, T(1) / Z_THIS->z);}
	};


#	undef Z_THIS
}}}


// MARK: - Common implementation


namespace Zeta {template <class T> struct Value3D : Mixins::Value3D::Partial<Value3D<T>, T, Type<T>::number_set> {

	typedef typename ZTypeFixedNumber(Z3D, T) Base;

	T x, y, z;


	Z_INLINE_MEMBER Value3D() {}
											
	Z_CT_MEMBER(CPP11) Value3D(T x, T y, T z)	      : x(x),	 y(y),	  z(z)	  {}
	Z_CT_MEMBER(CPP11) Value3D(T x, T y)		      : x(x),	 y(y),	  z(T(0)) {}
	Z_CT_MEMBER(CPP11) Value3D(T xyz)		      : x(xyz),	 y(xyz),  z(xyz)  {}
	Z_CT_MEMBER(CPP11) Value3D(const Value2D<T> &xy)      : x(xy.x), y(xy.y), z(T(0)) {}
	Z_CT_MEMBER(CPP11) Value3D(const Value2D<T> &xy, T z) : x(xy.x), y(xy.y), z(z)	  {}
	Z_CT_MEMBER(CPP11) Value3D(T x, const Value2D<T> &yz) : x(x),	 y(yz.x), z(yz.y) {}

	Z_INLINE_MEMBER Value3D(const Base &value) {(*(Base *)this) = value;}


	Z_CT_MEMBER(CPP11) operator Boolean() const {return x != T(0) || y != T(0) || z != T(0);}
	Z_INLINE_MEMBER    operator Base&  () const {return *((Base *)this);}

	Z_CT_MEMBER(CPP11) Boolean operator ==(const Value3D &value) const {return x == value.x && y == value.y && z == value.z;}
	Z_CT_MEMBER(CPP11) Boolean operator !=(const Value3D &value) const {return x != value.x || y != value.y || z != value.z;}
	Z_CT_MEMBER(CPP11) Boolean operator <=(const Value3D &value) const {return x <= value.x && y <= value.y && z <= value.z;}
	Z_CT_MEMBER(CPP11) Boolean operator >=(const Value3D &value) const {return x >= value.x && y >= value.y && z >= value.z;}
	Z_CT_MEMBER(CPP11) Boolean operator  >(const Value3D &value) const {return x >	value.x && y >	value.y && z >	value.z;}
	Z_CT_MEMBER(CPP11) Boolean operator  <(const Value3D &value) const {return x <	value.x && y <	value.y && z <	value.z;}

	Z_CT_MEMBER(CPP11) Value3D operator +(const Value3D &value) const {return Value3D(x + value.x, y + value.y, z + value.z);}
	Z_CT_MEMBER(CPP11) Value3D operator -(const Value3D &value) const {return Value3D(x - value.x, y - value.y, z - value.z);}
	Z_CT_MEMBER(CPP11) Value3D operator *(const Value3D &value) const {return Value3D(x * value.x, y * value.y, z * value.z);}
	Z_CT_MEMBER(CPP11) Value3D operator /(const Value3D &value) const {return Value3D(x / value.x, y / value.y, z / value.z);}

	Z_INLINE_MEMBER Value3D &operator +=(const Value3D &value) {return *this = *this + value;}
	Z_INLINE_MEMBER Value3D &operator -=(const Value3D &value) {return *this = *this - value;}
	Z_INLINE_MEMBER Value3D &operator *=(const Value3D &value) {return *this = *this * value;}
	Z_INLINE_MEMBER Value3D &operator /=(const Value3D &value) {return *this = *this / value;}

	Z_CT_MEMBER(CPP11) Boolean operator ==(T scalar) const {return x == scalar && y == scalar && z == scalar;}
	Z_CT_MEMBER(CPP11) Boolean operator !=(T scalar) const {return x != scalar || y != scalar || z != scalar;}
	Z_CT_MEMBER(CPP11) Boolean operator <=(T scalar) const {return x <= scalar && y <= scalar && z <= scalar;}
	Z_CT_MEMBER(CPP11) Boolean operator >=(T scalar) const {return x >= scalar && y >= scalar && z >= scalar;}
	Z_CT_MEMBER(CPP11) Boolean operator  >(T scalar) const {return x >  scalar && y >  scalar && z >  scalar;}
	Z_CT_MEMBER(CPP11) Boolean operator  <(T scalar) const {return x <  scalar && y <  scalar && z <  scalar;}

	Z_CT_MEMBER(CPP11) Value3D operator +(T scalar) const {return Value3D(x + scalar, y + scalar, z + scalar);}
	Z_CT_MEMBER(CPP11) Value3D operator -(T scalar) const {return Value3D(x - scalar, y - scalar, z - scalar);}
	Z_CT_MEMBER(CPP11) Value3D operator *(T scalar) const {return Value3D(x * scalar, y * scalar, z * scalar);}
	Z_CT_MEMBER(CPP11) Value3D operator /(T scalar) const {return Value3D(x / scalar, y / scalar, z / scalar);}

	Z_INLINE_MEMBER Value3D &operator +=(T scalar) {return *this = *this + scalar;}
	Z_INLINE_MEMBER Value3D &operator -=(T scalar) {return *this = *this - scalar;}
	Z_INLINE_MEMBER Value3D &operator *=(T scalar) {return *this = *this * scalar;}
	Z_INLINE_MEMBER Value3D &operator /=(T scalar) {return *this = *this / scalar;}

	Z_INLINE_MEMBER T  operator[](int index) const {return ((T *)this)[index];}
	Z_INLINE_MEMBER T &operator[](int index)       {return ((T *)this)[index];}


	Z_CT_MEMBER(CPP11) Value3D clamp(const Value3D &minimum, const Value3D &maximum) const
		{
		return Value3D
			(Zeta::clamp<T>(x, minimum.x, maximum.x),
			 Zeta::clamp<T>(y, minimum.y, maximum.y),
			 Zeta::clamp<T>(z, minimum.z, maximum.z));
		}


	Z_CT_MEMBER(CPP11) Value3D clamp(T minimum, T maximum) const
		{
		return Value3D
			(Zeta::clamp<T>(x, minimum, maximum),
			 Zeta::clamp<T>(y, minimum, maximum),
			 Zeta::clamp<T>(z, minimum, maximum));
		}


	Z_CT_MEMBER(CPP11) Value3D cross_product(const Value3D &value) const
		{
		return Value3D
			(y * value.z - z * value.y,
			 z * value.x - x * value.z,
			 x * value.y - y * value.x);
		}


	Z_CT_MEMBER(CPP11) T dot_product(const Value3D &value) const
		{return x * value.x + y * value.y + y * value.y;}


	Z_CT_MEMBER(CPP11) Value3D fit(const Value3D &value) const
		{return Value3D(T(0));} // TODO


	Z_CT_MEMBER(CPP11) Boolean has_zero() const
		{return x == T(0) || y == T(0) || z == T(0);}


	Z_CT_MEMBER(CPP11) T inner_maximum() const
		{return Zeta::maximum<T>(Zeta::maximum<T>(x, y), z);}


	Z_CT_MEMBER(CPP11) T inner_middle() const
		{return (x + y + z) / T(3);}


	Z_CT_MEMBER(CPP11) T inner_minimum() const
		{return Zeta::minimum<T>(Zeta::minimum<T>(x, y), z);}


	Z_CT_MEMBER(CPP11) T inner_product() const
		{return x * y * z;}


	Z_CT_MEMBER(CPP11) T inner_sum() const
		{return x + y + z;}


	Z_CT_MEMBER(CPP11) Boolean is_zero() const
		{return x == T(0) && y == T(0) && z == T(0);}


	Z_CT_MEMBER(CPP11) Value3D maximum(const Value3D &value) const
		{
		return Value3D
			(Zeta::maximum<T>(x, value.x),
			 Zeta::maximum<T>(y, value.y),
			 Zeta::maximum<T>(z, value.z));
		}


	Z_CT_MEMBER(CPP11) Value3D middle(const Value3D &value) const
		{
		return Value3D
			((x + value.x) / T(2),
			 (y + value.y) / T(2),
			 (z + value.z) / T(2));
		}


	Z_CT_MEMBER(CPP11) Value3D minimum(const Value3D &value) const
		{
		return Value3D
			(Zeta::minimum<T>(x, value.x),
			 Zeta::minimum<T>(y, value.y),
			 Zeta::minimum<T>(z, value.z));
		}


	Z_INLINE_MEMBER Value3D rotate_as_axes(Value3D<Int8> rotation) const
		{
		Value3D result = *this;

		if ((rotation.x % 4) & 1) Zeta::swap<T>(&result.y, &result.z);
		if ((rotation.y % 4) & 1) Zeta::swap<T>(&result.x, &result.z);
		if ((rotation.z % 4) & 1) Zeta::swap<T>(&result.x, &result.y);
		return result;
		}


	Z_CT_MEMBER(CPP11) T squared_length() const
		{return x * x + y * y + z * z;}


	Z_INLINE_MEMBER void swap(Value3D &value)
		{Zeta::swap<Base>((Base *)this, (Base *)&value);}


	Z_CT_MEMBER(CPP11) Value2D<T> xy() const
		{return Value2D<T>(x, y);}


	Z_CT_MEMBER(CPP11) Value2D<T> xz() const
		{return Value2D<T>(x, z);}


	Z_CT_MEMBER(CPP11) Value3D xzy() const
		{return Value3D(x, z, y);}


	Z_CT_MEMBER(CPP11) Value2D<T> yx() const
		{return Value2D<T>(y, x);}


	Z_CT_MEMBER(CPP11) Value3D yxz() const
		{return Value3D(y, x, z);}


	Z_CT_MEMBER(CPP11) Value2D<T> yz() const
		{return Value2D<T>(y, z);}


	Z_CT_MEMBER(CPP11) Value3D yzx() const
		{return Value3D(y, z, x);}


	Z_CT_MEMBER(CPP11) Value2D<T> zx() const
		{return Value2D<T>(z, x);}


	Z_CT_MEMBER(CPP11) Value3D zxy() const
		{return Value3D(z, x, y);}


	Z_CT_MEMBER(CPP11) Value2D<T> zy() const
		{return Value2D<T>(z, y);}


	Z_CT_MEMBER(CPP11) Value3D zyx() const
		{return Value3D(z, y, x);}
};}


#endif // __Z_classes_base_Value3D_HPP__
