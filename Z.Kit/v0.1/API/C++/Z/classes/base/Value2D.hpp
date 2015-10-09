/* Z Kit C++ API - classes/base/Value2D.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Value2D_HPP__
#define __Z_classes_base_Value2D_HPP__

#include <Z/macros/type selector.hpp>
#include <Z/macros/super.hpp>
#include <Z/macros/templating.h>
#include <Z/functions/base/value.hpp>

#define Z2DType(TYPE) Z_INSERT_##TYPE##_FixedType(Z2D,)

namespace ZKit {
	namespace Selectors {namespace BaseType {
		Z_TYPE_SELECTOR(Value2D, Z2DType)
	}}

	template <typename T> class Value2D;
}


template <typename T> struct
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


	// MARK: - Constructors


	inline Value2D<T>()	      {}
	inline Value2D<T>(T x, T y)   {this->x = x; this->y = y;}
	inline Value2D<T>(T scalar)   {this->x = scalar; this->y = scalar;}
	inline Value2D<T>(void *data) {*this = *(Value2D<T> *)data;}
	inline Value2D<T>(Base value) {*z_base = value;}

	static inline Value2D<T> zero() {return Value2D<T>(T(0), T(0));}
	static inline Value2D<T> unit() {return Value2D<T>(T(1), T(1));}


	static inline Value2D<T> minimum(Value2D<T> a, Value2D<T> b)
		{return Value2D<T>(ZKit::minimum<T>(a.x, b.x), ZKit::minimum<T>(a.y, b.y));}


	static inline Value2D<T> maximum(Value2D<T> a, Value2D<T> b)
		{return Value2D<T>(ZKit::maximum<T>(a.x, b.x), ZKit::maximum<T>(a.y, b.y));}


	static inline Value2D<T> middle(Value2D<T> a, Value2D<T> b)
		{return Value2D<T>((a.x + b.x) / T(2), (a.y + b.y) / T(2));}


	// MARK: - Operators


	inline Boolean operator ==(Value2D<T> value) const {return this->x == value.x && this->y == value.y;}
	inline Boolean operator <=(Value2D<T> value) const {return this->x <= value.x && this->y <= value.y;}
	inline Boolean operator >=(Value2D<T> value) const {return this->x >= value.x && this->y >= value.y;}
	inline Boolean operator  >(Value2D<T> value) const {return this->x >  value.x && this->y >  value.y;}
	inline Boolean operator  <(Value2D<T> value) const {return this->x <  value.x && this->y <  value.y;}

	inline Boolean operator ==(T scalar) const {return this->x == scalar && this->y == scalar;}
	inline Boolean operator <=(T scalar) const {return this->x <= scalar && this->y <= scalar;}
	inline Boolean operator >=(T scalar) const {return this->x >= scalar && this->y >= scalar;}
	inline Boolean operator  >(T scalar) const {return this->x >  scalar && this->y >  scalar;}
	inline Boolean operator  <(T scalar) const {return this->x <  scalar && this->y <  scalar;}

	inline Value2D<T> operator +(Value2D<T> value) const {return Value2D<T>(this->x + value.x, this->y + value.y);}
	inline Value2D<T> operator -(Value2D<T> value) const {return Value2D<T>(this->x - value.x, this->y - value.y);}
	inline Value2D<T> operator *(Value2D<T> value) const {return Value2D<T>(this->x * value.x, this->y * value.y);}
	inline Value2D<T> operator /(Value2D<T> value) const {return Value2D<T>(this->x / value.x, this->y / value.y);}

	inline Value2D<T> operator +(T scalar) const {return Value2D<T>(this->x + scalar, this->y + scalar);}
	inline Value2D<T> operator -(T scalar) const {return Value2D<T>(this->x - scalar, this->y - scalar);}
	inline Value2D<T> operator *(T scalar) const {return Value2D<T>(this->x * scalar, this->y * scalar);}
	inline Value2D<T> operator /(T scalar) const {return Value2D<T>(this->x / scalar, this->y / scalar);}

	inline Value2D<T> operator +=(Value2D<T> value) {return *this = *this + value;}
	inline Value2D<T> operator -=(Value2D<T> value) {return *this = *this - value;}
	inline Value2D<T> operator *=(Value2D<T> value) {return *this = *this * value;}
	inline Value2D<T> operator /=(Value2D<T> value) {return *this = *this / value;}

	inline Value2D<T> operator +=(T scalar) {return *this = *this + scalar;}
	inline Value2D<T> operator -=(T scalar) {return *this = *this - scalar;}
	inline Value2D<T> operator *=(T scalar) {return *this = *this * scalar;}
	inline Value2D<T> operator /=(T scalar) {return *this = *this / scalar;}

	inline T operator [](int index) {return ((T *)this)[index];}

	inline Boolean contains(Value2D<T> value) const {return this->x >= value.x && this->y >= value.y;}

	inline T dot_product  (Value2D<T> value) const {return this->x * value.x + this->y * value.y;}
	inline T cross_product(Value2D<T> value) const {return this->x * value.y - this->y * value.x;}


	inline Value2D<T> minimum(Value2D<T> value) const
		{return Value2D<T>(ZKit::minimum<T>(this->x, value.x), ZKit::minimum<T>(this->y, value.y));}


	inline Value2D<T> maximum(Value2D<T> value) const
		{return Value2D<T>(ZKit::maximum<T>(this->x, value.x), ZKit::maximum<T>(this->y, value.y));}


	inline Value2D<T> middle(Value2D<T> value) const
		{return Value2D<T>((this->x + value.x) / T(2), (this->y + value.y) / T(2));}


	inline Value2D<T> fit(Value2D<T> value) const
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


	inline Value2D<T> clamp(Value2D<T> minimum, Value2D<T> maximum) const
		{
		return Value2D
			(ZKit::clamp<T>(this->x, minimum.x, maximum.x),
			 ZKit::clamp<T>(this->y, minimum.y, maximum.y));
		}


	inline Value2D<T> clamp(T minimum, T maximum) const
		{
		return Value2D<T>
			(ZKit::clamp<T>(this->x, minimum, maximum),
			 ZKit::clamp<T>(this->y, minimum, maximum));
		}


	inline Value2D<T> yx() const {return Value2D<T>(this->y, this->x);}


	// MARK: - Operations for integer and real types


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_signed, Boolean>::type is_negative() const
		{return this->x < T(0) && this->y < T(0);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_signed, Boolean>::type has_negative() const
		{return this->x < T(0) || this->y < T(0);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_signed, Value2D<T> >::type negative() const
		{return Value2D<T>(-this->x, -this->y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_signed, Value2D<T> >::type absolute() const
		{return Value2D<T>(ZKit::absolute<T>(this->x), ZKit::absolute<T>(this->y));}


	// MARK: - Operations for real types only


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Boolean>::type is_almost_equal(Value2D<T> value) const
		{return are_almost_equal<T>(this->x, value.x) && are_almost_equal<T>(this->y, value.y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Boolean>::type is_perpendicular(Value2D<T> value) const
		{return ZKit::absolute<T>(dot_product(value)) <= Type<T>::epsilon;}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Value2D<T> >::type lerp(Value2D<T> value, T t) const
		{return Value2D<T>(ZKit::lerp<T>(this->x, value.x, t), ZKit::lerp<T>(this->y, value.y, t));}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Value2D<T> >::type inverse_lerp(Value2D<T> value, T t) const
		{
		return Value2D<T>
			(ZKit::inverse_lerp<T>(this->x, value.x, t),
			 ZKit::inverse_lerp<T>(this->y, value.y, t));
		 }


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Boolean>::type is_finite() const
		{return ZKit::is_finite<T>(this->x) && ZKit::is_finite<T>(this->y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Boolean>::type is_infinity() const
		{return ZKit::is_infinity<T>(this->x) && ZKit::is_infinity<T>(this->y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Boolean>::type is_nan() const
		{return ZKit::is_nan<T>(this->x) && ZKit::is_nan<T>(this->y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Boolean>::type is_almost_zero() const
		{return ZKit::is_almost_zero<T>(this->x) && ZKit::is_almost_zero<T>(this->y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Boolean>::type has_finite() const
		{return ZKit::is_finite<T>(this->x) || ZKit::is_finite<T>(this->y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Boolean>::type has_infinity() const
		{return ZKit::is_infinity<T>(this->x) || ZKit::is_infinity<T>(this->y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Boolean>::type has_nan() const
		{return ZKit::is_nan<T>(this->x) || ZKit::is_nan<T>(this->y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Boolean>::type has_almost_zero() const
		{return is_almost_zero<T>(this->x) || is_almost_zero<T>(this->y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Value2D<T> >::type reciprocal() const
		{return Value2D<T>(T(1.0) / this->x, T(1.0) / this->y);}


	template <typename TT = T>
	inline typename enable_if<Type<TT>::is_real, Value2D<T> >::type clamp_01() const
		{return Value2D<T>(clamp_01<T>(this->x), clamp_01<T>(this->y));}
};


#endif // __Z_classes_base_Value2D_HPP__
