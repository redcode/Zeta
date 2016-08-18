/* Z Kit C++ API - classes/base/Value2D.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Value2D_HPP__
#define __Z_classes_base_Value2D_HPP__

#include <Z/macros/type selection.hpp>
#include <Z/macros/super.hpp>
#include <Z/functions/base/value.hpp>

#if Z_MUST_SUPPORT(CG_GEOMETRY)
#	include <CoreGraphics/CGGeometry.h>
#endif

#if Z_MUST_SUPPORT(NS_GEOMETRY) && defined(Z_OBJECTIVE_C)
#	import <Foundation/NSGeometry.h>
#endif

namespace Zeta {template <class T> struct Value2D;}


template <class T> struct Zeta::Value2D : public ZNumberType(Z2D, T) {

	typedef typename ZNumberType(Z2D, T) Base;
	typedef typename ZNumberType(Z2D, T) Super;
	typedef		 T		     Value;


	// MARK: - Constructors


	Z_INLINE_MEMBER Value2D<T>()		      {}
	Z_INLINE_MEMBER Value2D<T>(T x, T y)	      {this->x = x; this->y = y;}
	Z_INLINE_MEMBER Value2D<T>(T scalar)	      {this->x = scalar; this->y = scalar;}
	Z_INLINE_MEMBER Value2D<T>(void *data)	      {*this = *(Value2D<T> *)data;}
	Z_INLINE_MEMBER Value2D<T>(const Base &value) {*z_base = value;}


	// MARK: - Static functions


	static Z_INLINE_MEMBER Value2D<T> minimum(const Value2D<T> &a, const Value2D<T> &b)
		{return Value2D<T>(Zeta::minimum<T>(a.x, b.x), Zeta::minimum<T>(a.y, b.y));}


	static Z_INLINE_MEMBER Value2D<T> maximum(const Value2D<T> &a, const Value2D<T> &b)
		{return Value2D<T>(Zeta::maximum<T>(a.x, b.x), Zeta::maximum<T>(a.y, b.y));}


	static Z_INLINE_MEMBER Value2D<T> middle(const Value2D<T> &a, const Value2D<T> &b)
		{return Value2D<T>((a.x + b.x) / T(2), (a.y + b.y) / T(2));}


	// MARK: - Operators


	Z_INLINE_MEMBER operator Boolean() const {return this->x != T(0) || this->y != T(0);}
	Z_INLINE_MEMBER operator Base	() const {return *z_base;}

	Z_INLINE_MEMBER Boolean operator ==(const Value2D<T> &value) const {return this->x == value.x && this->y == value.y;}
	Z_INLINE_MEMBER Boolean operator !=(const Value2D<T> &value) const {return this->x != value.x || this->y != value.y;}
	Z_INLINE_MEMBER Boolean operator <=(const Value2D<T> &value) const {return this->x <= value.x && this->y <= value.y;}
	Z_INLINE_MEMBER Boolean operator >=(const Value2D<T> &value) const {return this->x >= value.x && this->y >= value.y;}
	Z_INLINE_MEMBER Boolean operator  >(const Value2D<T> &value) const {return this->x >  value.x && this->y >  value.y;}
	Z_INLINE_MEMBER Boolean operator  <(const Value2D<T> &value) const {return this->x <  value.x && this->y <  value.y;}

	Z_INLINE_MEMBER Value2D<T> operator +(const Value2D<T> &value) const {return Value2D<T>(this->x + value.x, this->y + value.y);}
	Z_INLINE_MEMBER Value2D<T> operator -(const Value2D<T> &value) const {return Value2D<T>(this->x - value.x, this->y - value.y);}
	Z_INLINE_MEMBER Value2D<T> operator *(const Value2D<T> &value) const {return Value2D<T>(this->x * value.x, this->y * value.y);}
	Z_INLINE_MEMBER Value2D<T> operator /(const Value2D<T> &value) const {return Value2D<T>(this->x / value.x, this->y / value.y);}

	Z_INLINE_MEMBER Value2D<T> &operator +=(const Value2D<T> &value) {return *this = *this + value;}
	Z_INLINE_MEMBER Value2D<T> &operator -=(const Value2D<T> &value) {return *this = *this - value;}
	Z_INLINE_MEMBER Value2D<T> &operator *=(const Value2D<T> &value) {return *this = *this * value;}
	Z_INLINE_MEMBER Value2D<T> &operator /=(const Value2D<T> &value) {return *this = *this / value;}

	Z_INLINE_MEMBER Boolean operator ==(T scalar) const {return this->x == scalar && this->y == scalar;}
	Z_INLINE_MEMBER Boolean operator !=(T scalar) const {return this->x != scalar || this->y != scalar;}
	Z_INLINE_MEMBER Boolean operator <=(T scalar) const {return this->x <= scalar && this->y <= scalar;}
	Z_INLINE_MEMBER Boolean operator >=(T scalar) const {return this->x >= scalar && this->y >= scalar;}
	Z_INLINE_MEMBER Boolean operator  >(T scalar) const {return this->x >  scalar && this->y >  scalar;}
	Z_INLINE_MEMBER Boolean operator  <(T scalar) const {return this->x <  scalar && this->y <  scalar;}

	Z_INLINE_MEMBER Value2D<T> operator +(T scalar) const {return Value2D<T>(this->x + scalar, this->y + scalar);}
	Z_INLINE_MEMBER Value2D<T> operator -(T scalar) const {return Value2D<T>(this->x - scalar, this->y - scalar);}
	Z_INLINE_MEMBER Value2D<T> operator *(T scalar) const {return Value2D<T>(this->x * scalar, this->y * scalar);}
	Z_INLINE_MEMBER Value2D<T> operator /(T scalar) const {return Value2D<T>(this->x / scalar, this->y / scalar);}

	Z_INLINE_MEMBER Value2D<T> &operator +=(T scalar) {return *this = *this + scalar;}
	Z_INLINE_MEMBER Value2D<T> &operator -=(T scalar) {return *this = *this - scalar;}
	Z_INLINE_MEMBER Value2D<T> &operator *=(T scalar) {return *this = *this * scalar;}
	Z_INLINE_MEMBER Value2D<T> &operator /=(T scalar) {return *this = *this / scalar;}

	Z_INLINE_MEMBER T  operator[](int index) const {return ((T *)this)[index];}
	Z_INLINE_MEMBER T &operator[](int index)       {return ((T *)this)[index];}


	// MARK: - Interoperability


#	if Z_MUST_SUPPORT(CG_GEOMETRY)

		Z_INLINE_MEMBER Value2D<T>(const CGPoint &point) {this->x = point.x; this->y = point.y;}
		Z_INLINE_MEMBER Value2D<T>(const CGSize	 &size)	 {this->x = size.width; this->y = size.height;}


		Z_INLINE_MEMBER operator CGPoint() const
			{
			CGPoint result = {CGFloat(this->x), CGFloat(this->y)};
			return result;
			}


		Z_INLINE_MEMBER operator CGSize() const
			{
			CGSize result = {CGFloat(this->x), CGFloat(this->y)};
			return result;
			}

#	endif

#	if	Z_MUST_SUPPORT(NS_GEOMETRY) && defined(Z_OBJECTIVE_C) && \
		(!Z_MUST_SUPPORT(CG_GEOMETRY)			      || \
		 !defined(NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES)  || \
		  !NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES)

		Z_INLINE_MEMBER Value2D<T>(const NSSize	&size)	{this->x = size.width; this->y = size.height;}
		Z_INLINE_MEMBER Value2D<T>(const NSPoint &point) {this->x = point.x; this->y = point.y;}


		Z_INLINE_MEMBER operator NSPoint() const
			{
			NSPoint result = {CGFloat(this->x), CGFloat(this->y)};
			return result;
			}


		Z_INLINE_MEMBER operator NSSize() const
			{
			NSSize result = {CGFloat(this->x), CGFloat(this->y)};
			return result;
			}

#	endif


	// MARK: - Operations for natural, integer and real types


	Z_INLINE_MEMBER Boolean contains(const Value2D<T> &value) const
		{return this->x >= value.x && this->y >= value.y;}


	Z_INLINE_MEMBER T dot_product(const Value2D<T> &value) const
		{return this->x * value.x + this->y * value.y;}


	Z_INLINE_MEMBER T cross_product(const Value2D<T> &value) const
		{return this->x * value.y - this->y * value.x;}


	Z_INLINE_MEMBER Value2D<T> minimum(const Value2D<T> &value) const
		{
		return Value2D<T>
			(Zeta::minimum<T>(this->x, value.x),
			 Zeta::minimum<T>(this->y, value.y));
		 }


	Z_INLINE_MEMBER Value2D<T> maximum(const Value2D<T> &value) const
		{
		return Value2D<T>
			(Zeta::maximum<T>(this->x, value.x),
			 Zeta::maximum<T>(this->y, value.y));
		 }


	Z_INLINE_MEMBER Value2D<T> middle(const Value2D<T> &value) const
		{return Value2D<T>((this->x + value.x) / T(2), (this->y + value.y) / T(2));}


	Z_INLINE_MEMBER Value2D<T> fit(const Value2D<T> &value) const
		{
		return this->y / this->x > value.y / value.x
			? Value2D<T>(this->x * value.y / this->y, value.y)
			: Value2D<T>(value.x, this->y * value.x / this->x);
		}


	Z_INLINE_MEMBER Boolean is_zero () const {return this->x == T(0) && this->y == T(0);}
	Z_INLINE_MEMBER Boolean has_zero() const {return this->x == T(0) || this->y == T(0);}

	Z_INLINE_MEMBER T inner_sum	() const {return this->x + this->y;}
	Z_INLINE_MEMBER T inner_product () const {return this->x * this->y;}
	Z_INLINE_MEMBER T inner_minimum () const {return Zeta::minimum<T>(this->x, this->y);}
	Z_INLINE_MEMBER T inner_maximum () const {return Zeta::maximum<T>(this->x, this->y);}
	Z_INLINE_MEMBER T inner_middle	() const {return (this->x + this->y) / T(2);}
	Z_INLINE_MEMBER T squared_length() const {return this->x * this->x + this->y * this->y;}


	Z_INLINE_MEMBER Value2D<T> clamp(const Value2D<T> &minimum, const Value2D<T> &maximum) const
		{
		return Value2D
			(Zeta::clamp<T>(this->x, minimum.x, maximum.x),
			 Zeta::clamp<T>(this->y, minimum.y, maximum.y));
		}


	Z_INLINE_MEMBER Value2D<T> clamp(T minimum, T maximum) const
		{
		return Value2D<T>
			(Zeta::clamp<T>(this->x, minimum, maximum),
			 Zeta::clamp<T>(this->y, minimum, maximum));
		}


	Z_INLINE_MEMBER Value2D<T> yx() const
		{return Value2D<T>(this->y, this->x);}


	Z_INLINE_MEMBER void to_vertex_array(T *array) const
		{
		array[0] = array[1] = array[2] = array[7] = T(0);
		array[3] = array[5] = this->y;
		array[4] = array[6] = this->x;
		}


	Z_INLINE_MEMBER void to_vertex_array(Value2D<T> delta, T *array) const
		{
		array[0] = array[2] = delta.x;
		array[1] = array[7] = delta.y;
		array[3] = array[5] = delta.y + this->y;
		array[4] = array[6] = delta.x + this->x;
		}


	// MARK: - Operations for integer and real types


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_signed, Boolean>::type
	is_negative() const
		{return this->x < T(0) && this->y < T(0);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_signed, Boolean>::type
	has_negative() const
		{return this->x < T(0) || this->y < T(0);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_signed, Value2D<T> >::type
	negative() const
		{return Value2D<T>(-this->x, -this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_signed, Value2D<T> >::type
	absolute() const
		{return Value2D<T>(Zeta::absolute<T>(this->x), Zeta::absolute<T>(this->y));}


	// MARK: - Operations for real types only


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	is_almost_equal(const Value2D<T> &value) const
		{
		return	Zeta::are_almost_equal<T>(this->x, value.x) &&
			Zeta::are_almost_equal<T>(this->y, value.y);
		}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	is_perpendicular(const Value2D<T> &value) const
		{return Zeta::absolute<T>(dot_product(value)) <= Type<T>::epsilon();}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Value2D<T> >::type
	lerp(const Value2D<T> &value, T t) const
		{
		return Value2D<T>
			(Zeta::lerp<T>(this->x, value.x, t),
			 Zeta::lerp<T>(this->y, value.y, t));
		}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Value2D<T> >::type
	inverse_lerp(const Value2D<T> &value, T t) const
		{
		return Value2D<T>
			(Zeta::inverse_lerp<T>(this->x, value.x, t),
			 Zeta::inverse_lerp<T>(this->y, value.y, t));
		 }


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	is_finite() const
		{return Zeta::is_finite<T>(this->x) && Zeta::is_finite<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	is_infinity() const
		{return Zeta::is_infinity<T>(this->x) && Zeta::is_infinity<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	is_nan() const
		{return Zeta::is_nan<T>(this->x) && Zeta::is_nan<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	is_almost_zero() const
		{return Zeta::is_almost_zero<T>(this->x) && Zeta::is_almost_zero<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	has_finite() const
		{return Zeta::is_finite<T>(this->x) || Zeta::is_finite<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	has_infinity() const
		{return Zeta::is_infinity<T>(this->x) || Zeta::is_infinity<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	has_nan() const
		{return Zeta::is_nan<T>(this->x) || Zeta::is_nan<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	has_almost_zero() const
		{return Zeta::is_almost_zero<T>(this->x) || Zeta::is_almost_zero<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Value2D<T> >::type
	reciprocal() const
		{return Value2D<T>(T(1.0) / this->x, T(1.0) / this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Value2D<T> >::type
	clamp_01() const
		{return Value2D<T>(Zeta::clamp_01<T>(this->x), Zeta::clamp_01<T>(this->y));}

#ifndef Z_DECLARING_PARTIAL_VALUE_2D
};
#endif


#endif // __Z_classes_base_Value2D_HPP__
