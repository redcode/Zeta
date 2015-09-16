/* Z Kit C++ API - classes/base/Value2D.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Value2D_HPP__
#define __Z_classes_base_Value2D_HPP__

#include <Z/traits/Type.hpp>
#include <Z/macros/trait.hpp>
#include <Z/macros/super.hpp>
#include <Z/macros/templating.h>
#include <Z/functions/base/value.hpp>
#include <stdio.h>
#define Z2DType(TYPE) Z_INSERT_##TYPE##_FixedType(Z2D,)

namespace ZKit {
	namespace Selectors {namespace BaseType {
		ZDefineTypeSelector(Value2D, Z2DType)
	}}

	template <typename T> class Value2D;
};

template <typename T> class
#ifdef __ZMathematics_base_Value2D_HPP__
	ZKit::BaseValue2D
#else
	ZKit::Value2D
#endif
: public ZKit::Selectors::BaseType::Value2D<T>::type {
	public:

	typedef typename Selectors::BaseType::Value2D<T>::type Base;
	typedef typename Selectors::BaseType::Value2D<T>::type Super;
	typedef		 T				       Value;

	inline Base  base () {return *z_base ;}
	inline Super super() {return *z_super;}

	inline Value2D<T>() {}
	inline Value2D<T>(T x, T y) {this->x = x; this->y = y;}
	inline Value2D<T>(T scalar) {this->x = scalar; this->y = scalar;}
	inline Value2D<T>(Base value) {*z_base = value;}

	inline Boolean operator ==(Base value) const {return this->x == value.x && this->y == value.y;}
	inline Boolean operator <=(Base value) const {return this->x <= value.x && this->y <= value.y;}
	inline Boolean operator >=(Base value) const {return this->x >= value.x && this->y >= value.y;}

	inline Boolean operator ==(T scalar) const {return this->x == scalar && this->y == scalar;}
	inline Boolean operator <=(T scalar) const {return this->x <= scalar && this->y <= scalar;}
	inline Boolean operator >=(T scalar) const {return this->x >= scalar && this->y >= scalar;}

	inline Value2D<T> operator +(Base value) const {return Value2D<T>(this->x + value.x, this->y + value.y);}
	inline Value2D<T> operator -(Base value) const {return Value2D<T>(this->x - value.x, this->y - value.y);}
	inline Value2D<T> operator *(Base value) const {return Value2D<T>(this->x * value.x, this->y * value.y);}
	inline Value2D<T> operator /(Base value) const {return Value2D<T>(this->x / value.x, this->y / value.y);}

	inline Value2D<T> operator +(T scalar) const {return Value2D<T>(this->x + scalar, this->y + scalar);}
	inline Value2D<T> operator -(T scalar) const {return Value2D<T>(this->x - scalar, this->y - scalar);}
	inline Value2D<T> operator *(T scalar) const {return Value2D<T>(this->x * scalar, this->y * scalar);}
	inline Value2D<T> operator /(T scalar) const {return Value2D<T>(this->x / scalar, this->y / scalar);}

	inline Value2D<T> operator +=(Base value) {return *this = *this + value;}
	inline Value2D<T> operator -=(Base value) {return *this = *this - value;}
	inline Value2D<T> operator *=(Base value) {return *this = *this * value;}
	inline Value2D<T> operator /=(Base value) {return *this = *this / value;}

	inline Value2D<T> operator +=(T scalar) {return *this = *this + scalar;}
	inline Value2D<T> operator -=(T scalar) {return *this = *this - scalar;}
	inline Value2D<T> operator *=(T scalar) {return *this = *this * scalar;}
	inline Value2D<T> operator /=(T scalar) {return *this = *this / scalar;}

	inline T operator [](int index) {return ((T *)this)[index];}

	inline Boolean contains(Base value) const {return this->x >= value.x && this->y >= value.y;}

	inline T dot_product  (Base value) const {return this->x * value.x + this->y * value.y;}
	inline T cross_product(Base value) const {return this->x * value.y - this->y * value.x;}


	inline Value2D<T> minimum(Base value) const
		{return Value2D<T>(ZKit::minimum<T>(this->x, value.x), ZKit::minimum<T>(this->y, value.y));}


	inline Value2D<T> maximum(Base value) const
		{return Value2D<T>(ZKit::maximum<T>(this->x, value.x), ZKit::maximum<T>(this->y, value.y));}


	inline Value2D<T> middle(Base value) const
		{return Value2D<T>((this->x + value.x) / T(2), (this->y + value.y) / T(2));}


	inline Value2D<T> fit(Base value) const
		{
		return this->y / this->x > value.y / value.x
			? Value2D<T>(this->x * value.y / this->y, value.y)
			: Value2D<T>(value.x, this->y * value.x / this->x);
		}


	inline Boolean is_zero () const {return this->x == T(0) && this->y == T(0);}
	inline Boolean has_zero() const {return this->x == T(0) || this->y == T(0);}

	inline T inner_sum     () const {return this->x + this->y;}
	inline T inner_product () const {return this->x * this->y;}
	inline T inner_minimum () const {return ZKit::minimum<T>(this->x, this->y);}
	inline T inner_maximum () const {return ZKit::maximum<T>(this->x, this->y);}
	inline T inner_middle  () const {return (this->x + this->y) / T(2);}
	inline T squared_length() const {return this->x * this->x + this->y * this->y;}


	/*typename std::enable_if<Type<T>::is_real, Real>::type clamp_01()
		{return 0.4;}*/

/*
	inline Value2D clamp(Value2D minimum, Value2D maximum) const
		{
		return Value2D
			(z_clamp(x, minimum.x, maximum.x),
			 z_clamp(y, minimum.y, maximum.y));
		}


	inline Value2D square_clamp(Real minimum, Real maximum) const
		{
		return Value2D
			(z_clamp(x, minimum, maximum),
			 z_clamp(y, minimum, maximum));
		}


	inline Value2D yx()	   const {return Value2D(y, x);}

	// MARK: - Operations for integer and real types

	inline Boolean is_negative () const {return x < 0 && y < 0;}
	inline Boolean has_negative() const {return x < 0 || y < 0;}
	inline Value2D negative	   () const {return Value2D(-x, -y);}
	inline Value2D absolute	   () const {return Value2D(z_absolute(x), z_absolute(y));}


	// MARK: - Operations for real types only

	static inline Boolean are_almost_equal(Value2D a, Value2D b)
		{return z_are_almost_equal(a.x, b.x) && z_are_almost_equal(a.y, b.y);}

	static inline Boolean are_perpendicular(Value2D a, Value2D b)
		{return z_absolute(z_2d_dot_product(a, b)) <= Z_EPSILON;}


	inline Value2D lerp(Value2D value, Real t) const
		{return Value(z_lerp(x, value.x, t), z_lerp(y, value.y, t));}


	inline Value2D inverse_lerp(Value2D value, Real t) const
		{return Value2D(z_inverse_lerp(a.x, b.x, t), z_inverse_lerp(a.y, b.y, t));}


	inline Boolean is_finite() const {return z_is_finite(x) && z_is_finite(y);}
	inline Boolean is_infinity() const {return z_is_infinity(x) && z_is_infinity(y);}
	inline Boolean is_nan() const {return z_is_nan(x) && z_is_nan(y);}
	inline Boolean is_almost_zero() const {return z_is_almost_zero(x) && z_is_almost_zero(y);}
	inline Boolean has_finite() const {return z_is_finite(x) || z_is_finite(y);}
	inline Boolean has_infinity() const {return z_is_infinity(x) || z_is_infinity(y);}
	inline Boolean has_nan() const {return z_is_nan(x) || z_is_nan(y);}
	inline Boolean has_almost_zero() const {return z_is_almost_zero(x) || z_is_almost_zero(y);}

	inline Value2D reciprocal() const
		{return Value2D(1.0 / x, 1.0 / y);}

	inline Value2D square_clamp_01() const
		{return Value2D(z_clamp_01(x), z_clamp_01(y));}*/


};

#endif // __Z_classes_base_Value2D_HPP__
