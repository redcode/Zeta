/* Q Kit C++ API - classes/base/Value2D.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_classes_base_Value2D_HPP__
#define __Q_classes_base_Value2D_HPP__

#include <Q/types/base.hpp>

namespace QKit {class Value2D : public Q2D {


class QKit::Value2D : public Q2D {

	inline Value2D() {}

	inline Value2D(Real x, Real y)
		{this->x = x; this->y = y;}

	inline Value2D(Real scalar)
		{x = scalar; y = scalar;}

	inline Boolean operator ==(Value2D value) const
		{return x == value.x && y == value.y;}

	inline Boolean operator ==(Real scalar) const
		{return x == scalar && y == scalar;}

	inline Value2D operator +(Value2D value) const {return Value2D(x + value.x, y + value.y);}
	inline Value2D operator -(Value2D value) const {return Value2D(x - value.x, y - value.y);}
	inline Value2D operator *(Value2D value) const {return Value2D(x * value.x, y * value.y);}
	inline Value2D operator /(Value2D value) const {return Value2D(x / value.x, y / value.y);}

	inline Value2D operator +(Real scalar) const {return Value2D(x + scalar, y + scalar);}
	inline Value2D operator -(Real scalar) const {return Value2D(x - scalar, y - scalar);}
	inline Value2D operator *(Real scalar) const {return Value2D(x * scalar, y * scalar);}
	inline Value2D operator /(Real scalar) const {return Value2D(x / scalar, y / scalar);}

	inline Boolean contains(Value2D value) const
		{return x >= value.x && y >= value.y;}

	inline Real dot_product(Value2D value) const
		{return x * value.x + y * value.y;}

	inline Real cross_product(Value2D value) const
		{return x * value.y - y * value.x;}

	inline Value2D minimum(Value2D value) const
		{return Value2D(q_minimum(x, value.x), q_minimum(y, value.y));}

	inline Value2D maximum(Value2D value) const
		{return Value2D(q_maximum(x, value.x), q_maximum(y, value.y));}

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
	inline Real    inner_minimum () const {return q_minimum(x, y);}
	inline Real    inner_maximum () const {return q_maximum(x, y);}
	inline Real    inner_middle  () const {return (x + y) / 2;}
	inline Real    squared_length() const {return x * x + y * y;}


	inline Value2D clamp(Value2D minimum, Value2D maximum) const
		{
		return Value2D
			(q_clamp(x, minimum.x, maximum.x),
			 q_clamp(y, minimum.y, maximum.y));
		}


	inline Value2D square_clamp(Real minimum, Real maximum) const
		{
		return Value2D
			(q_clamp(x, minimum, maximum),
			 q_clamp(y, minimum, maximum));
		}


	inline Value2D yx()	   const {return Value2D(y, x);}
	inline Value3D xyn(Real n) const {return Value3D(x, y, n);}
 	inline Value3D xny(Real n) const {return Value3D(x, n, y);}
 	inline Value3D nxy(Real n) const {return Value3D(n, x, y);}
	inline Value3D yxn(Real n) const {return Value3D(y, x, n);}
	inline Value3D ynx(Real n) const {return Value3D(y, n, x);}
	inline Value3D nyx(Real n) const {return Value3D(n, y, x);}


	// MARK: - Operations for integer and real types

	inline Boolean is_negative () const {return x < 0 && y < 0;}
	inline Boolean has_negative() const {return x < 0 || y < 0;}
	inline Value2D negative	   () const {return Value2D(-x, -y);}
	inline Value2D absolute	   () const {return Value2D(q_absolute(x), q_absolute(y));}


	// MARK: - Operations for real types only

	static inline Boolean are_almost_equal(Value2D a, Value2D b)
		{return q_are_almost_equal(a.x, b.x) && q_are_almost_equal(a.y, b.y);}

	static inline Boolean are_perpendicular(Value2D a, Value2D b)
		{return q_absolute(q_2d_dot_product(a, b)) <= Q_EPSILON;}


	inline Value2D lerp(Value2D value, Real t) const
		{return Value(q_lerp(x, value.x, t), q_lerp(y, value.y, t));}


	inline Value2D inverse_lerp(Value2D value, Real t) const
		{return Value2D(q_inverse_lerp(a.x, b.x, t), q_inverse_lerp(a.y, b.y, t));}


	inline Boolean is_finite() const {return q_is_finite(x) && q_is_finite(y);}
	inline Boolean is_infinity() const {return q_is_infinity(x) && q_is_infinity(y);}
	inline Boolean is_nan() const {return q_is_nan(x) && q_is_nan(y);}
	inline Boolean is_almost_zero() const {return qis_almost_zero(x) && q_is_almost_zero(y);}
	inline Boolean has_finite() const {return q_is_finite(x) || q_is_finite(y);}
	inline Boolean has_infinity() const {return q_is_infinity(x) || q_is_infinity(y);}
	inline Boolean has_nan() const {return q_is_nan(x) || q_is_nan(y);}
	inline Boolean has_almost_zero() const {return q_is_almost_zero(x) || q_is_almost_zero(y);}

	inline Value2D reciprocal() const
		{return Value2D(1.0 / x, 1.0 / y);}

	inline Value2D square_clamp_01() const
		{return Value2D(q_clamp_01(x), q_clamp_01(y));}


};}


#endif // __Q_classes_base_Value2D_HPP__
