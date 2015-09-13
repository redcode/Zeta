/* Z Kit C++ API - classes/base/Value2D.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Value2D_HPP__
#define __Z_classes_base_Value2D_HPP__

#include <Z/types/base.hpp>
#include <Z/functions/geometry/ZRectangle.h>
#include <Z/macros/templating.hpp>

#define Z2DType(TYPE) Z_INSERT_##TYPE##_FixedType(Z2D,)

namespace ZKit {
	ZMetaTypeSelectorRealOnly(TypeSelector2D, Z2DType)
	template <typename T> class Value2D;
}

template <typename T> class ZKit::Value2D : public ZKit::TypeSelector2D<T>::V {

	public:

	inline Value2D() {}

	inline Value2D(T x, T y)
		{this->x = x; this->y = y;}

	inline Value2D(T scalar)
		{this->x = scalar; this->y = scalar;}

	inline Boolean operator ==(Value2D<T> value) const
		{return this->x == value.x && this->y == value.y;}

	inline Boolean operator ==(T scalar) const
		{return this->x == scalar && this->y == scalar;}

	inline Value2D<T> operator +(Value2D<T> value) const {return Value2D<T>(this->x + value.x, this->y + value.y);}
	inline Value2D<T> operator -(Value2D<T> value) const {return Value2D<T>(this->x - value.x, this->y - value.y);}
	inline Value2D<T> operator *(Value2D<T> value) const {return Value2D<T>(this->x * value.x, this->y * value.y);}
	inline Value2D<T> operator /(Value2D<T> value) const {return Value2D<T>(this->x / value.x, this->y / value.y);}

	inline Value2D<T> operator +(T scalar) const {return Value2D<T>(this->x + scalar, this->y + scalar);}
	inline Value2D<T> operator -(T scalar) const {return Value2D<T>(this->x - scalar, this->y - scalar);}
	inline Value2D<T> operator *(T scalar) const {return Value2D<T>(this->x * scalar, this->y * scalar);}
	inline Value2D<T> operator /(T scalar) const {return Value2D<T>(this->x / scalar, this->y / scalar);}

	inline Boolean contains(Value2D value) const
		{return this->x >= value.x && this->y >= value.y;}

	inline T dot_product(Value2D value) const
		{return this->x * value.x + this->y * value.y;}

	inline T cross_product(Value2D value) const
		{return this->x * value.y - this->y * value.x;}
/*
	inline Value2D minimum(Value2D value) const
		{return Value2D(z_minimum(x, value.x), z_minimum(y, value.y));}

	inline Value2D maximum(Value2D value) const
		{return Value2D(z_maximum(x, value.x), z_maximum(y, value.y));}

	inline Value2D middle(Value2D value) const
		{return Value2D((x + value.x) / 2, (y + value.y) / 2);}


	inline Value2D fit(Value2D value) const
		{
		return y / x > value.y / value.x
			? Value2D(x * value.y / y, value.y)
			: Value2D(value.x, y * value.x / x);
		}


	inline Boolean is_zero	     () const {return x == 0 && y == 0;}
	inline Boolean has_zero	     () const {return x == 0 || y == 0;}
	inline Real    inner_sum     () const {return x + y;}
	inline Real    inner_product () const {return x * y;}
	inline Real    inner_minimum () const {return z_minimum(x, y);}
	inline Real    inner_maximum () const {return z_maximum(x, y);}
	inline Real    inner_middle  () const {return (x + y) / 2;}
	inline Real    squared_length() const {return x * x + y * y;}


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
