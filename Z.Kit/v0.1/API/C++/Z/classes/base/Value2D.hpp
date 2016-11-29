/* Z Kit C++ API - classes/base/Value2D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Value2D_HPP__
#define __Z_classes_base_Value2D_HPP__

#include <Z/macros/type selection.hpp>
#include <Z/macros/super.hpp>
#include <Z/functions/base/value.hpp>

#ifdef Z_USE_CG_GEOMETRY
#	include <CoreGraphics/CGGeometry.h>
#endif

#if defined(Z_USE_NS_GEOMETRY) && Z_LANGUAGE == Z_LANGUAGE_OBJECTIVE_CPP
#	import <Foundation/NSGeometry.h>
#endif

#ifdef Z_USE_COCOS2D_X
#	include "cocos2d.h"
#endif

namespace Zeta {template <class T> struct Value2D;}


template <class T> struct Zeta::Value2D : public ZNumberType(Z2D, T) {

	typedef typename ZNumberType(Z2D, T) Base;
	typedef typename ZNumberType(Z2D, T) Super;
	typedef	T			     Value;


	// MARK: - Constructors


	Z_INLINE_MEMBER Value2D()		   {}
	Z_INLINE_MEMBER Value2D(T x, T y)	   {this->x = x; this->y = y;}
	Z_INLINE_MEMBER Value2D(T scalar)	   {this->x = scalar; this->y = scalar;}
	Z_INLINE_MEMBER Value2D(const Base &value) {*z_base = value;}


	// MARK: - Static functions


	static Z_INLINE_MEMBER Value2D maximum(const Value2D &a, const Value2D &b)
		{return Value2D(Zeta::maximum<T>(a.x, b.x), Zeta::maximum<T>(a.y, b.y));}


	static Z_INLINE_MEMBER Value2D middle(const Value2D &a, const Value2D &b)
		{return Value2D((a.x + b.x) / T(2), (a.y + b.y) / T(2));}


	static Z_INLINE_MEMBER Value2D minimum(const Value2D &a, const Value2D &b)
		{return Value2D(Zeta::minimum<T>(a.x, b.x), Zeta::minimum<T>(a.y, b.y));}


	// MARK: - Operators


	Z_INLINE_MEMBER operator Boolean() const {return this->x != T(0) || this->y != T(0);}

	Z_INLINE_MEMBER Boolean operator ==(const Value2D &value) const {return this->x == value.x && this->y == value.y;}
	Z_INLINE_MEMBER Boolean operator !=(const Value2D &value) const {return this->x != value.x || this->y != value.y;}
	Z_INLINE_MEMBER Boolean operator <=(const Value2D &value) const {return this->x <= value.x && this->y <= value.y;}
	Z_INLINE_MEMBER Boolean operator >=(const Value2D &value) const {return this->x >= value.x && this->y >= value.y;}
	Z_INLINE_MEMBER Boolean operator  >(const Value2D &value) const {return this->x >  value.x && this->y >  value.y;}
	Z_INLINE_MEMBER Boolean operator  <(const Value2D &value) const {return this->x <  value.x && this->y <  value.y;}

	Z_INLINE_MEMBER Value2D operator +(const Value2D &value) const {return Value2D(this->x + value.x, this->y + value.y);}
	Z_INLINE_MEMBER Value2D operator -(const Value2D &value) const {return Value2D(this->x - value.x, this->y - value.y);}
	Z_INLINE_MEMBER Value2D operator *(const Value2D &value) const {return Value2D(this->x * value.x, this->y * value.y);}
	Z_INLINE_MEMBER Value2D operator /(const Value2D &value) const {return Value2D(this->x / value.x, this->y / value.y);}

	Z_INLINE_MEMBER Value2D &operator +=(const Value2D &value) {return *this = *this + value;}
	Z_INLINE_MEMBER Value2D &operator -=(const Value2D &value) {return *this = *this - value;}
	Z_INLINE_MEMBER Value2D &operator *=(const Value2D &value) {return *this = *this * value;}
	Z_INLINE_MEMBER Value2D &operator /=(const Value2D &value) {return *this = *this / value;}

	Z_INLINE_MEMBER Boolean operator ==(T scalar) const {return this->x == scalar && this->y == scalar;}
	Z_INLINE_MEMBER Boolean operator !=(T scalar) const {return this->x != scalar || this->y != scalar;}
	Z_INLINE_MEMBER Boolean operator <=(T scalar) const {return this->x <= scalar && this->y <= scalar;}
	Z_INLINE_MEMBER Boolean operator >=(T scalar) const {return this->x >= scalar && this->y >= scalar;}
	Z_INLINE_MEMBER Boolean operator  >(T scalar) const {return this->x >  scalar && this->y >  scalar;}
	Z_INLINE_MEMBER Boolean operator  <(T scalar) const {return this->x <  scalar && this->y <  scalar;}

	Z_INLINE_MEMBER Value2D operator +(T scalar) const {return Value2D(this->x + scalar, this->y + scalar);}
	Z_INLINE_MEMBER Value2D operator -(T scalar) const {return Value2D(this->x - scalar, this->y - scalar);}
	Z_INLINE_MEMBER Value2D operator *(T scalar) const {return Value2D(this->x * scalar, this->y * scalar);}
	Z_INLINE_MEMBER Value2D operator /(T scalar) const {return Value2D(this->x / scalar, this->y / scalar);}

	Z_INLINE_MEMBER Value2D &operator +=(T scalar) {return *this = *this + scalar;}
	Z_INLINE_MEMBER Value2D &operator -=(T scalar) {return *this = *this - scalar;}
	Z_INLINE_MEMBER Value2D &operator *=(T scalar) {return *this = *this * scalar;}
	Z_INLINE_MEMBER Value2D &operator /=(T scalar) {return *this = *this / scalar;}

	Z_INLINE_MEMBER T  operator[](int index) const {return ((T *)this)[index];}
	Z_INLINE_MEMBER T &operator[](int index)       {return ((T *)this)[index];}


	// MARK: - Interoperability


#	ifdef Z_USE_CG_GEOMETRY

		Z_INLINE_MEMBER Value2D(const CGPoint &point) {this->x = point.x;    this->y = point.y;	   }
		Z_INLINE_MEMBER Value2D(const CGSize  &size ) {this->x = size.width; this->y = size.height;}


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


		Z_INLINE_MEMBER operator CGRect() const
			{
			CGRect result = {CGFloat(0), CGFloat(0), CGFloat(this->x), CGFloat(this->y)};
			return result;
			}

#	endif


#	if	defined(Z_USE_NS_GEOMETRY)			     && \
		Z_LANGUAGE == Z_LANGUAGE_OBJECTIVE_CPP		     && \
		(!defined(Z_USE_CG_GEOMETRY)			     || \
		 !defined(NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES) || \
		  !NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES)

		Z_INLINE_MEMBER Value2D(const NSPoint &point) {this->x = point.x;    this->y = point.y;	   }
		Z_INLINE_MEMBER Value2D(const NSSize  &size ) {this->x = size.width; this->y = size.height;}


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


		Z_INLINE_MEMBER operator NSRect() const
			{
			NSRect result = {CGFloat(0), CGFloat(0), CGFloat(this->x), CGFloat(this->y)};
			return result;
			}

#	endif


#	ifdef Z_USE_COCOS2D_X

		Z_INLINE_MEMBER Value2D(const cocos2d::Vec2 &point) {this->x = point.x;    this->y = point.y;	 }
		Z_INLINE_MEMBER Value2D(const cocos2d::Size &size ) {this->x = size.width; this->y = size.height;}


		Z_INLINE_MEMBER operator cocos2d::Vec2() const
			{return cocos2d::Vec2(float(this->x), float(this->y));}


		Z_INLINE_MEMBER operator cocos2d::Size() const
			{return cocos2d::Size(float(this->x), float(this->y));}


		Z_INLINE_MEMBER operator cocos2d::Rect() const
			{return cocos2d::Rect(0.0f, 0.0f, float(this->x),  float(this->y));}

#	endif


	// MARK: - Functions for natural, integer and real types


	Z_INLINE_MEMBER Value2D clamp(const Value2D &minimum, const Value2D &maximum) const
		{
		return Value2D
			(Zeta::clamp<T>(this->x, minimum.x, maximum.x),
			 Zeta::clamp<T>(this->y, minimum.y, maximum.y));
		}


	Z_INLINE_MEMBER Value2D clamp(T minimum, T maximum) const
		{
		return Value2D
			(Zeta::clamp<T>(this->x, minimum, maximum),
			 Zeta::clamp<T>(this->y, minimum, maximum));
		}


	Z_INLINE_MEMBER Boolean contains(const Value2D &value) const
		{return this->x >= value.x && this->y >= value.y;}


	Z_INLINE_MEMBER T cross_product(const Value2D &value) const
		{return this->x * value.y - this->y * value.x;}


	Z_INLINE_MEMBER T dot_product(const Value2D &value) const
		{return this->x * value.x + this->y * value.y;}


	Z_INLINE_MEMBER Value2D fit(const Value2D &value) const
		{
		return this->y / this->x > value.y / value.x
			? Value2D(this->x * value.y / this->y, value.y)
			: Value2D(value.x, this->y * value.x / this->x);
		}


	Z_INLINE_MEMBER Boolean has_zero() const
		{return this->x == T(0) || this->y == T(0);}


	Z_INLINE_MEMBER T inner_maximum() const
		{return Zeta::maximum<T>(this->x, this->y);}


	Z_INLINE_MEMBER T inner_middle() const
		{return (this->x + this->y) / T(2);}


	Z_INLINE_MEMBER T inner_minimum() const
		{return Zeta::minimum<T>(this->x, this->y);}


	Z_INLINE_MEMBER T inner_product() const
		{return this->x * this->y;}


	Z_INLINE_MEMBER T inner_sum() const
		{return this->x + this->y;}


	Z_INLINE_MEMBER Boolean is_zero() const
		{return this->x == T(0) && this->y == T(0);}


	Z_INLINE_MEMBER Value2D maximum(const Value2D &value) const
		{
		return Value2D
			(Zeta::maximum<T>(this->x, value.x),
			 Zeta::maximum<T>(this->y, value.y));
		}


	Z_INLINE_MEMBER Value2D middle(const Value2D &value) const
		{return Value2D((this->x + value.x) / T(2), (this->y + value.y) / T(2));}


	Z_INLINE_MEMBER Value2D minimum(const Value2D &value) const
		{
		return Value2D
			(Zeta::minimum<T>(this->x, value.x),
			 Zeta::minimum<T>(this->y, value.y));
		}


	Z_INLINE_MEMBER T squared_length() const
		{return this->x * this->x + this->y * this->y;}


	Z_INLINE_MEMBER void swap(Value2D &value)
		{Zeta::swap<Base>(this, &value);}


	Z_INLINE_MEMBER void to_vertex_array(T *array) const
		{
		array[0] = array[1] = array[2] = array[7] = T(0);
		array[3] = array[5] = this->y;
		array[4] = array[6] = this->x;
		}


	Z_INLINE_MEMBER void to_vertex_array(const Value2D &delta, T *array) const
		{
		array[0] = array[2] = delta.x;
		array[1] = array[7] = delta.y;
		array[3] = array[5] = delta.y + this->y;
		array[4] = array[6] = delta.x + this->x;
		}


	Z_INLINE_MEMBER Value2D yx() const
		{return Value2D(this->y, this->x);}


	// MARK: - Functions for integer and real types


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_signed, Value2D>::type
	absolute() const
		{return Value2D(Zeta::absolute<T>(this->x), Zeta::absolute<T>(this->y));}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_signed, Boolean>::type
	has_negative() const
		{return this->x < T(0) || this->y < T(0);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_signed, Boolean>::type
	is_negative() const
		{return this->x < T(0) && this->y < T(0);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_signed, Value2D>::type
	negative() const
		{return Value2D(-this->x, -this->y);}


	// MARK: - Functions for real types only


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Value2D>::type
	clamp_01() const
		{return Value2D(Zeta::clamp_01<T>(this->x), Zeta::clamp_01<T>(this->y));}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	has_almost_zero() const
		{return Zeta::is_almost_zero<T>(this->x) || Zeta::is_almost_zero<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	has_finite() const
		{return Zeta::is_finite<T>(this->x) || Zeta::is_finite<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	has_infinity() const
		{return Zeta::is_infinity<T>(this->x) || Zeta::is_infinity<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	has_nan() const
		{return Zeta::is_nan<T>(this->x) || Zeta::is_nan<T>(this->y);}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Value2D>::type
	inverse_lerp(const Value2D &value, T t) const
		{
		return Value2D
			(Zeta::inverse_lerp<T>(this->x, value.x, t),
			 Zeta::inverse_lerp<T>(this->y, value.y, t));
		}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	is_almost_equal(const Value2D &value) const
		{
		return	Zeta::are_almost_equal<T>(this->x, value.x) &&
			Zeta::are_almost_equal<T>(this->y, value.y);
		}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Boolean>::type
	is_almost_zero() const
		{return Zeta::is_almost_zero<T>(this->x) && Zeta::is_almost_zero<T>(this->y);}


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
	is_perpendicular(const Value2D &value) const
		{return Zeta::absolute<T>(dot_product(value)) <= Type<T>::epsilon();}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Value2D>::type
	lerp(const Value2D &value, T t) const
		{
		return Value2D
			(Zeta::lerp<T>(this->x, value.x, t),
			 Zeta::lerp<T>(this->y, value.y, t));
		}


	Z_INLINE_MEMBER typename SaferEnableIf<Type<T>::is_real, Value2D>::type
	reciprocal() const
		{return Value2D(T(1.0) / this->x, T(1.0) / this->y);}


#ifndef Z_DECLARING_PARTIAL_VALUE_2D
};
#endif


#endif // __Z_classes_base_Value2D_HPP__
