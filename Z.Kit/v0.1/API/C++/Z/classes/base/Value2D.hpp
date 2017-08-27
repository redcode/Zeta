/* Z Kit C++ API - classes/base/Value2D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Value2D_HPP__
#define __Z_classes_base_Value2D_HPP__

#include <Z/macros/type selection.hpp>
#include <Z/functions/base/value.hpp>

#ifdef Z_USE_CG_GEOMETRY
#	include <CoreGraphics/CGGeometry.h>
#endif

#if defined(Z_USE_NS_GEOMETRY) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
#	import <Foundation/NSGeometry.h>
#endif

#ifdef Z_USE_COCOS2D_X
#	include "cocos2d.h"
#endif

namespace Zeta {template <class T> struct Value3D;}


namespace Zeta {namespace Mixins {namespace Value2D {

#	define Z_THIS ((Value2D *)this)

	template <class Value2D, class T, UInt T_number_set> struct Partial;


	// MARK: - Partial implementation for signed types


	template <class Value2D, class T>
	struct Signed {

		Z_CT_MEMBER(CPP11) Value2D absolute() const
			{return Value2D(Zeta::absolute<T>(Z_THIS->x), Zeta::absolute<T>(Z_THIS->y));}


		Z_CT_MEMBER(CPP11) Boolean has_negative() const
			{return Z_THIS->x < T(0) || Z_THIS->y < T(0);}


		Z_CT_MEMBER(CPP11) Boolean is_negative() const
			{return Z_THIS->x < T(0) && Z_THIS->y < T(0);}


		Z_CT_MEMBER(CPP11) Value2D negative() const
			{return Value2D(-Z_THIS->x, -Z_THIS->y);}
	};


	// MARK: - Partial implementation for natural types


	template <class Value2D, class T>
	struct Partial<Value2D, T, Z_NUMBER_SET_N> {};


	// MARK: - Partial implementation for integer types


	template <class Value2D, class T>
	struct Partial<Value2D, T, Z_NUMBER_SET_Z> : Signed<Value2D, T> {

		Z_CT_MEMBER(CPP11) Boolean is_perpendicular(const Value2D &value) const
			{return !Zeta::absolute<T>(Z_THIS->dot_product(value));}

	};


	// MARK: - Partial implementation for real types


	template <class Value2D, class T>
	struct Partial<Value2D, T, Z_NUMBER_SET_R> : Signed<Value2D, T> {

		Z_CT_MEMBER(CPP11) Value2D clamp_01() const
			{return Value2D(Zeta::clamp_01<T>(Z_THIS->x), Zeta::clamp_01<T>(Z_THIS->y));}


		Z_CT_MEMBER(CPP11) Boolean has_almost_zero() const
			{return Zeta::is_almost_zero<T>(Z_THIS->x) || Zeta::is_almost_zero<T>(Z_THIS->y);}


		Z_CT_MEMBER(CPP11) Boolean has_finite() const
			{return Zeta::is_finite<T>(Z_THIS->x) || Zeta::is_finite<T>(Z_THIS->y);}


		Z_CT_MEMBER(CPP11) Boolean has_infinity() const
			{return Zeta::is_infinity<T>(Z_THIS->x) || Zeta::is_infinity<T>(Z_THIS->y);}


		Z_CT_MEMBER(CPP11) Boolean has_nan() const
			{return Zeta::is_nan<T>(Z_THIS->x) || Zeta::is_nan<T>(Z_THIS->y);}


		Z_CT_MEMBER(CPP11) Value2D inverse_lerp(const Value2D &value, T t) const
			{
			return Value2D
				(Zeta::inverse_lerp<T>(Z_THIS->x, value.x, t),
				 Zeta::inverse_lerp<T>(Z_THIS->y, value.y, t));
			}


		Z_CT_MEMBER(CPP11) Boolean is_almost_equal(const Value2D &value) const
			{
			return	Zeta::are_almost_equal<T>(Z_THIS->x, value.x) &&
				Zeta::are_almost_equal<T>(Z_THIS->y, value.y);
			}


		Z_CT_MEMBER(CPP11) Boolean is_almost_zero() const
			{return Zeta::is_almost_zero<T>(Z_THIS->x) && Zeta::is_almost_zero<T>(Z_THIS->y);}


		Z_CT_MEMBER(CPP11) Boolean is_finite() const
			{return Zeta::is_finite<T>(Z_THIS->x) && Zeta::is_finite<T>(Z_THIS->y);}


		Z_CT_MEMBER(CPP11) Boolean is_infinity() const
			{return Zeta::is_infinity<T>(Z_THIS->x) && Zeta::is_infinity<T>(Z_THIS->y);}


		Z_CT_MEMBER(CPP11) Boolean is_nan() const
			{return Zeta::is_nan<T>(Z_THIS->x) && Zeta::is_nan<T>(Z_THIS->y);}


		Z_CT_MEMBER(CPP11) Boolean is_perpendicular(const Value2D &value) const
			{return Zeta::absolute<T>(Z_THIS->dot_product(value)) <= Type<T>::epsilon();}


		Z_CT_MEMBER(CPP11) Value2D lerp(const Value2D &value, T t) const
			{
			return Value2D
				(Zeta::lerp<T>(Z_THIS->x, value.x, t),
				 Zeta::lerp<T>(Z_THIS->y, value.y, t));
			}


		Z_CT_MEMBER(CPP11) Value2D reciprocal() const
			{return Value2D(T(1) / Z_THIS->x, T(1) / Z_THIS->y);}
	};


#	undef Z_THIS
}}}


// MARK: - Common implementation


namespace Zeta {template <class T> struct Value2D : Mixins::Value2D::Partial<Value2D<T>, T, Type<T>::number_set> {

	typedef typename ZTypeFixedNumber(Z2D, T) Base;

	T x, y;


	Z_INLINE_MEMBER Value2D() {}

	Z_CT_MEMBER(CPP11) Value2D(T x, T y)		 : x(x),    y(y)    {}
	Z_CT_MEMBER(CPP11) Value2D(T xy)		 : x(xy),   y(xy)   {}
	Z_CT_MEMBER(CPP11) Value2D(const Value3D<T> &xy) : x(xy.x), y(xy.y) {}

	Z_INLINE_MEMBER Value2D(const Base &value) {(*(Base *)this) = value;}


	Z_CT_MEMBER(CPP11) operator Boolean() const {return x != T(0) || y != T(0);}
	Z_INLINE_MEMBER    operator Base&  () const {return *((Base *)this);}

	Z_CT_MEMBER(CPP11) Boolean operator ==(const Value2D &value) const {return x == value.x && y == value.y;}
	Z_CT_MEMBER(CPP11) Boolean operator !=(const Value2D &value) const {return x != value.x || y != value.y;}
	Z_CT_MEMBER(CPP11) Boolean operator <=(const Value2D &value) const {return x <= value.x && y <= value.y;}
	Z_CT_MEMBER(CPP11) Boolean operator >=(const Value2D &value) const {return x >= value.x && y >= value.y;}
	Z_CT_MEMBER(CPP11) Boolean operator  >(const Value2D &value) const {return x >	value.x && y >	value.y;}
	Z_CT_MEMBER(CPP11) Boolean operator  <(const Value2D &value) const {return x <	value.x && y <	value.y;}

	Z_CT_MEMBER(CPP11) Value2D operator +(const Value2D &value) const {return Value2D(x + value.x, y + value.y);}
	Z_CT_MEMBER(CPP11) Value2D operator -(const Value2D &value) const {return Value2D(x - value.x, y - value.y);}
	Z_CT_MEMBER(CPP11) Value2D operator *(const Value2D &value) const {return Value2D(x * value.x, y * value.y);}
	Z_CT_MEMBER(CPP11) Value2D operator /(const Value2D &value) const {return Value2D(x / value.x, y / value.y);}

	Z_INLINE_MEMBER Value2D &operator +=(const Value2D &value) {return *this = *this + value;}
	Z_INLINE_MEMBER Value2D &operator -=(const Value2D &value) {return *this = *this - value;}
	Z_INLINE_MEMBER Value2D &operator *=(const Value2D &value) {return *this = *this * value;}
	Z_INLINE_MEMBER Value2D &operator /=(const Value2D &value) {return *this = *this / value;}

	Z_CT_MEMBER(CPP11) Boolean operator ==(T scalar) const {return x == scalar && y == scalar;}
	Z_CT_MEMBER(CPP11) Boolean operator !=(T scalar) const {return x != scalar || y != scalar;}
	Z_CT_MEMBER(CPP11) Boolean operator <=(T scalar) const {return x <= scalar && y <= scalar;}
	Z_CT_MEMBER(CPP11) Boolean operator >=(T scalar) const {return x >= scalar && y >= scalar;}
	Z_CT_MEMBER(CPP11) Boolean operator  >(T scalar) const {return x >  scalar && y >  scalar;}
	Z_CT_MEMBER(CPP11) Boolean operator  <(T scalar) const {return x <  scalar && y <  scalar;}

	Z_CT_MEMBER(CPP11) Value2D operator +(T scalar) const {return Value2D(x + scalar, y + scalar);}
	Z_CT_MEMBER(CPP11) Value2D operator -(T scalar) const {return Value2D(x - scalar, y - scalar);}
	Z_CT_MEMBER(CPP11) Value2D operator *(T scalar) const {return Value2D(x * scalar, y * scalar);}
	Z_CT_MEMBER(CPP11) Value2D operator /(T scalar) const {return Value2D(x / scalar, y / scalar);}

	Z_INLINE_MEMBER Value2D &operator +=(T scalar) {return *this = *this + scalar;}
	Z_INLINE_MEMBER Value2D &operator -=(T scalar) {return *this = *this - scalar;}
	Z_INLINE_MEMBER Value2D &operator *=(T scalar) {return *this = *this * scalar;}
	Z_INLINE_MEMBER Value2D &operator /=(T scalar) {return *this = *this / scalar;}

	Z_INLINE_MEMBER T  operator[](int index) const {return ((T *)this)[index];}
	Z_INLINE_MEMBER T &operator[](int index)       {return ((T *)this)[index];}


#	ifdef Z_USE_CG_GEOMETRY

		Z_CT_MEMBER(CPP11) Value2D(const CGPoint &point) : x(point.x),	  y(point.y)	 {}
		Z_CT_MEMBER(CPP11) Value2D(const CGSize  &size ) : x(size.width), y(size.height) {}


		Z_CT_MEMBER(CPP14) operator CGPoint() const
			{
			CGPoint result = {CGFloat(x), CGFloat(y)};
			return result;
			}


		Z_CT_MEMBER(CPP14) operator CGSize() const
			{
			CGSize result = {CGFloat(x), CGFloat(y)};
			return result;
			}


		Z_CT_MEMBER(CPP14) operator CGRect() const
			{
			CGRect result = {CGFloat(0), CGFloat(0), CGFloat(x), CGFloat(y)};
			return result;
			}

#	endif


#	if	defined(Z_USE_NS_GEOMETRY)			     && \
		Z_LANGUAGE == Z_LANGUAGE_OBJECTIVE_CPP		     && \
		(!defined(Z_USE_CG_GEOMETRY)			     || \
		 !defined(NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES) || \
		  !NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES)

		Z_CT_MEMBER(CPP11) Value2D(const NSPoint &point) : x(point.x),	  y(point.y)	 {}
		Z_CT_MEMBER(CPP11) Value2D(const NSSize  &size ) : x(size.width), y(size.height) {}


		Z_CT_MEMBER(CPP14) operator NSPoint() const
			{
			NSPoint result = {CGFloat(x), CGFloat(y)};
			return result;
			}


		Z_CT_MEMBER(CPP14) operator NSSize() const
			{
			NSSize result = {CGFloat(x), CGFloat(y)};
			return result;
			}


		Z_CT_MEMBER(CPP14) operator NSRect() const
			{
			NSRect result = {CGFloat(0), CGFloat(0), CGFloat(x), CGFloat(y)};
			return result;
			}

#	endif


#	ifdef Z_USE_COCOS2D_X

		Z_INLINE_MEMBER Value2D(const cocos2d::Vec2 &point) : x(point.x),    y(point.y)	    {}
		Z_INLINE_MEMBER Value2D(const cocos2d::Size &size ) : x(size.width), y(size.height) {}


		Z_INLINE_MEMBER operator cocos2d::Vec2() const
			{return cocos2d::Vec2(float(x), float(y));}


		Z_INLINE_MEMBER operator cocos2d::Size() const
			{return cocos2d::Size(float(x), float(y));}


		Z_INLINE_MEMBER operator cocos2d::Rect() const
			{return cocos2d::Rect(0.0f, 0.0f, float(x),  float(y));}

#	endif


	Z_CT_MEMBER(CPP11) Value2D clamp(const Value2D &minimum, const Value2D &maximum) const
		{
		return Value2D
			(Zeta::clamp<T>(x, minimum.x, maximum.x),
			 Zeta::clamp<T>(y, minimum.y, maximum.y));
		}


	Z_CT_MEMBER(CPP11) Value2D clamp(T minimum, T maximum) const
		{
		return Value2D
			(Zeta::clamp<T>(x, minimum, maximum),
			 Zeta::clamp<T>(y, minimum, maximum));
		}


	Z_CT_MEMBER(CPP11) T cross_product(const Value2D &value) const
		{return x * value.y - y * value.x;}


	Z_CT_MEMBER(CPP11) T dot_product(const Value2D &value) const
		{return x * value.x + y * value.y;}


	Z_CT_MEMBER(CPP11) Value2D fit(const Value2D &value) const
		{
		return y / x > value.y / value.x
			? Value2D(x * value.y / y, value.y)
			: Value2D(value.x, y * value.x / x);
		}


	Z_CT_MEMBER(CPP11) Boolean has_zero() const
		{return x == T(0) || y == T(0);}


	Z_CT_MEMBER(CPP11) T inner_maximum() const
		{return Zeta::maximum<T>(x, y);}


	Z_CT_MEMBER(CPP11) T inner_middle() const
		{return (x + y) / T(2);}


	Z_CT_MEMBER(CPP11) T inner_minimum() const
		{return Zeta::minimum<T>(x, y);}


	Z_CT_MEMBER(CPP11) T inner_product() const
		{return x * y;}


	Z_CT_MEMBER(CPP11) T inner_sum() const
		{return x + y;}


	Z_CT_MEMBER(CPP11) Boolean is_zero() const
		{return x == T(0) && y == T(0);}


	Z_CT_MEMBER(CPP11) Value2D maximum(const Value2D &value) const
		{
		return Value2D
			(Zeta::maximum<T>(x, value.x),
			 Zeta::maximum<T>(y, value.y));
		}


	Z_CT_MEMBER(CPP11) Value2D middle(const Value2D &value) const
		{return Value2D((x + value.x) / T(2), (y + value.y) / T(2));}


	Z_CT_MEMBER(CPP11) Value2D minimum(const Value2D &value) const
		{
		return Value2D
			(Zeta::minimum<T>(x, value.x),
			 Zeta::minimum<T>(y, value.y));
		}


	Z_CT_MEMBER(CPP11) Value3D<T> nxy(T n) const
		{return Value3D<T>(n, x, y);}


	Z_CT_MEMBER(CPP11) Value3D<T> nyx(T n) const
		{return Value3D<T>(n, y, x);}


	Z_CT_MEMBER(CPP11) T squared_length() const
		{return x * x + y * y;}


	Z_INLINE_MEMBER void swap(Value2D &value)
		{Zeta::swap<Base>((Base *)this, (Base *)&value);}


	Z_CT_MEMBER(CPP11) Value3D<T> xny(T n) const
		{return Value3D<T>(x, n, y);}


	Z_CT_MEMBER(CPP11) Value3D<T> xyn(T n) const
		{return Value3D<T>(x, y, n);}


	Z_CT_MEMBER(CPP11) Value3D<T> ynx(T n) const
		{return Value3D<T>(y, n, x);}


	Z_CT_MEMBER(CPP11) Value2D yx() const
		{return Value2D(y, x);}


	Z_CT_MEMBER(CPP11) Value3D<T> yxn(T n) const
		{return Value3D<T>(y, x, n);}
};}


#ifndef __Z_classes_base_Value3D_HPP__
#	include <Z/classes/base/Value3D.hpp>
#endif

#endif // __Z_classes_base_Value2D_HPP__
