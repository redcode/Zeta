/* Z Kit C++ API - classes/base/Value2D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
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


namespace Zeta {namespace Partials {namespace Value2D {

#	define Z_THIS ((Value2D *)this)

	template <class Base, class Value2D, class T, UInt T_number_set> struct Part;


	// MARK: - Partial implementation for signed types


	template <class Base, class Value2D, class T> struct Signed : Base {

#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_INLINE_MEMBER	   Signed()			 {}
			Z_CT_MEMBER(CPP11) Signed(T x, T y) : Base{x, y} {}
#		endif


		Z_CT_MEMBER(CPP11) Value2D absolute() const
			{return Value2D(Zeta::absolute<T>(this->x), Zeta::absolute<T>(this->y));}


		Z_CT_MEMBER(CPP11) Boolean has_negative() const
			{return this->x < T(0) || this->y < T(0);}


		Z_CT_MEMBER(CPP11) Boolean is_negative() const
			{return this->x < T(0) && this->y < T(0);}


		Z_CT_MEMBER(CPP11) Value2D negative() const
			{return Value2D(-this->x, -this->y);}
	};


	// MARK: - Partial implementation for natural types


	template <class Base, class Value2D, class T>
	struct Part<Base, Value2D, T, Z_NUMBER_SET_N> : Base {

#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_INLINE_MEMBER	   Part()		       {}
			Z_CT_MEMBER(CPP11) Part(T x, T y) : Base{x, y} {}
#		endif
	};


	// MARK: - Partial implementation for integer types


	template <class Base, class Value2D, class T>
	struct Part<Base, Value2D, T, Z_NUMBER_SET_Z> : Signed<Base, Value2D, T> {

#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_INLINE_MEMBER	   Part()					   {}
			Z_CT_MEMBER(CPP11) Part(T x, T y) : Signed<Base, Value2D, T>(x, y) {}
#		endif


		Z_CT_MEMBER(CPP11) Boolean is_perpendicular(const Value2D &other) const
			{return !Zeta::absolute<T>(Z_THIS->dot_product(other));}
	};


	// MARK: - Partial implementation for real types


	template <class Base, class Value2D, class T>
	struct Part<Base, Value2D, T, Z_NUMBER_SET_R> : Signed<Base, Value2D, T> {

#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_INLINE_MEMBER	   Part()					   {}
			Z_CT_MEMBER(CPP11) Part(T x, T y) : Signed<Base, Value2D, T>(x, y) {}
#		endif


		Z_CT_MEMBER(CPP11) Value2D clamp_01() const
			{return Value2D(Zeta::clamp_01<T>(this->x), Zeta::clamp_01<T>(this->y));}


		Z_CT_MEMBER(CPP11) Boolean has_almost_zero() const
			{return Zeta::is_almost_zero<T>(this->x) || Zeta::is_almost_zero<T>(this->y);}


		Z_CT_MEMBER(CPP11) Boolean has_finite() const
			{return Zeta::is_finite<T>(this->x) || Zeta::is_finite<T>(this->y);}


		Z_CT_MEMBER(CPP11) Boolean has_infinity() const
			{return Zeta::is_infinity<T>(this->x) || Zeta::is_infinity<T>(this->y);}


		Z_CT_MEMBER(CPP11) Boolean has_nan() const
			{return Zeta::is_nan<T>(this->x) || Zeta::is_nan<T>(this->y);}


		Z_CT_MEMBER(CPP11) Value2D inverse_lerp(const Value2D &other, T t) const
			{
			return Value2D
				(Zeta::inverse_lerp<T>(this->x, other.x, t),
				 Zeta::inverse_lerp<T>(this->y, other.y, t));
			}


		Z_CT_MEMBER(CPP11) Boolean is_almost_equal(const Value2D &other) const
			{
			return	Zeta::are_almost_equal<T>(this->x, other.x) &&
				Zeta::are_almost_equal<T>(this->y, other.y);
			}


		Z_CT_MEMBER(CPP11) Boolean is_almost_zero() const
			{return Zeta::is_almost_zero<T>(this->x) && Zeta::is_almost_zero<T>(this->y);}


		Z_CT_MEMBER(CPP11) Boolean is_finite() const
			{return Zeta::is_finite<T>(this->x) && Zeta::is_finite<T>(this->y);}


		Z_CT_MEMBER(CPP11) Boolean is_infinity() const
			{return Zeta::is_infinity<T>(this->x) && Zeta::is_infinity<T>(this->y);}


		Z_CT_MEMBER(CPP11) Boolean is_nan() const
			{return Zeta::is_nan<T>(this->x) && Zeta::is_nan<T>(this->y);}


		Z_CT_MEMBER(CPP11) Boolean is_perpendicular(const Value2D &other) const
			{return Zeta::absolute<T>(Z_THIS->dot_product(other)) <= Type<T>::epsilon();}


		Z_CT_MEMBER(CPP11) Value2D lerp(const Value2D &other, T t) const
			{
			return Value2D
				(Zeta::lerp<T>(this->x, other.x, t),
				 Zeta::lerp<T>(this->y, other.y, t));
			}


		Z_CT_MEMBER(CPP11) Value2D reciprocal() const
			{return Value2D(T(1) / this->x, T(1) / this->y);}
	};


#	undef Z_THIS
}}}


// MARK: - Common implementation


namespace Zeta {template <class T> struct Value2D
: Partials::Value2D::Part<typename ZTypeFixedNumber(Z2D, T), Value2D<T>, T, Type<T>::number_set> {

	typedef typename ZTypeFixedNumber(Z2D, T) Base;
	typedef Partials::Value2D::Part<Base, Value2D, T, Type<T>::number_set> Super;

	Z_INLINE_MEMBER Value2D() {}

#	if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
		Z_CT_MEMBER(CPP11) Value2D(T x, T y)		 : Super(x,    y   ) {}
		Z_CT_MEMBER(CPP11) Value2D(T xy)		 : Super(xy,   xy  ) {}
		Z_CT_MEMBER(CPP11) Value2D(const Value3D<T> &xy) : Super(xy.x, xy.y) {}
#	else
		Z_INLINE_MEMBER Value2D(T x, T y)	      {this->x = x;    this->y = y;   }
		Z_INLINE_MEMBER Value2D(T xy)		      {this->x = xy;   this->y = xy;  }
		Z_INLINE_MEMBER Value2D(const Value3D<T> &xy) {this->x = xy.x; this->y = xy.y;}
#	endif

	Z_CT_MEMBER(CPP11) operator Boolean() const {return this->x != T(0) || this->y != T(0);}

	Z_CT_MEMBER(CPP11) Boolean operator ==(const Value2D &rhs) const {return this->x == rhs.x && this->y == rhs.y;}
	Z_CT_MEMBER(CPP11) Boolean operator !=(const Value2D &rhs) const {return this->x != rhs.x || this->y != rhs.y;}
	Z_CT_MEMBER(CPP11) Boolean operator <=(const Value2D &rhs) const {return this->x <= rhs.x && this->y <= rhs.y;}
	Z_CT_MEMBER(CPP11) Boolean operator >=(const Value2D &rhs) const {return this->x >= rhs.x && this->y >= rhs.y;}
	Z_CT_MEMBER(CPP11) Boolean operator > (const Value2D &rhs) const {return this->x >  rhs.x && this->y >	rhs.y;}
	Z_CT_MEMBER(CPP11) Boolean operator < (const Value2D &rhs) const {return this->x <  rhs.x && this->y <	rhs.y;}

	Z_CT_MEMBER(CPP11) Value2D operator +(const Value2D &rhs) const {return Value2D(this->x + rhs.x, this->y + rhs.y);}
	Z_CT_MEMBER(CPP11) Value2D operator -(const Value2D &rhs) const {return Value2D(this->x - rhs.x, this->y - rhs.y);}
	Z_CT_MEMBER(CPP11) Value2D operator *(const Value2D &rhs) const {return Value2D(this->x * rhs.x, this->y * rhs.y);}
	Z_CT_MEMBER(CPP11) Value2D operator /(const Value2D &rhs) const {return Value2D(this->x / rhs.x, this->y / rhs.y);}

	Z_INLINE_MEMBER Value2D &operator +=(const Value2D &rhs) {return *this = *this + rhs;}
	Z_INLINE_MEMBER Value2D &operator -=(const Value2D &rhs) {return *this = *this - rhs;}
	Z_INLINE_MEMBER Value2D &operator *=(const Value2D &rhs) {return *this = *this * rhs;}
	Z_INLINE_MEMBER Value2D &operator /=(const Value2D &rhs) {return *this = *this / rhs;}

	Z_CT_MEMBER(CPP11) Boolean operator ==(T rhs) const {return this->x == rhs && this->y == rhs;}
	Z_CT_MEMBER(CPP11) Boolean operator !=(T rhs) const {return this->x != rhs || this->y != rhs;}
	Z_CT_MEMBER(CPP11) Boolean operator <=(T rhs) const {return this->x <= rhs && this->y <= rhs;}
	Z_CT_MEMBER(CPP11) Boolean operator >=(T rhs) const {return this->x >= rhs && this->y >= rhs;}
	Z_CT_MEMBER(CPP11) Boolean operator > (T rhs) const {return this->x >  rhs && this->y >  rhs;}
	Z_CT_MEMBER(CPP11) Boolean operator < (T rhs) const {return this->x <  rhs && this->y <  rhs;}

	Z_CT_MEMBER(CPP11) Value2D operator +(T rhs) const {return Value2D(this->x + rhs, this->y + rhs);}
	Z_CT_MEMBER(CPP11) Value2D operator -(T rhs) const {return Value2D(this->x - rhs, this->y - rhs);}
	Z_CT_MEMBER(CPP11) Value2D operator *(T rhs) const {return Value2D(this->x * rhs, this->y * rhs);}
	Z_CT_MEMBER(CPP11) Value2D operator /(T rhs) const {return Value2D(this->x / rhs, this->y / rhs);}

	Z_INLINE_MEMBER Value2D &operator +=(T rhs) {return *this = *this + rhs;}
	Z_INLINE_MEMBER Value2D &operator -=(T rhs) {return *this = *this - rhs;}
	Z_INLINE_MEMBER Value2D &operator *=(T rhs) {return *this = *this * rhs;}
	Z_INLINE_MEMBER Value2D &operator /=(T rhs) {return *this = *this / rhs;}

	Z_INLINE_MEMBER T  operator [](UInt index) const {return ((T *)this)[index];}
	Z_INLINE_MEMBER T &operator [](UInt index)	 {return ((T *)this)[index];}


#	ifdef Z_USE_CG_GEOMETRY

#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_CT_MEMBER(CPP11) Value2D(const CGPoint &point) : Super(point.x,    point.y	) {}
			Z_CT_MEMBER(CPP11) Value2D(const CGSize  &size ) : Super(size.width, size.height) {}
#		else
			Z_INLINE_MEMBER Value2D(const CGPoint &point) {this->x = point.x;    this->y = point.y;	   }
			Z_INLINE_MEMBER Value2D(const CGSize  &size ) {this->x = size.width; this->y = size.height;}
#		endif


		Z_CT_MEMBER(CPP14) operator CGPoint() const
			{
			CGPoint result = {CGFloat(this->x), CGFloat(this->y)};
			return result;
			}


		Z_CT_MEMBER(CPP14) operator CGSize() const
			{
			CGSize result = {CGFloat(this->x), CGFloat(this->y)};
			return result;
			}


		Z_CT_MEMBER(CPP14) operator CGRect() const
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

#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_CT_MEMBER(CPP11) Value2D(const NSPoint &point) : Super(point.x,    point.y	) {}
			Z_CT_MEMBER(CPP11) Value2D(const NSSize  &size ) : Super(size.width, size.height) {}
#		else
			Z_INLINE_MEMBER Value2D(const NSPoint &point) {this->x = point.x;    this->y = point.y;	   }
			Z_INLINE_MEMBER Value2D(const NSSize  &size ) {this->x = size.width; this->y = size.height;}
#		endif


		Z_CT_MEMBER(CPP14) operator NSPoint() const
			{
			NSPoint result = {CGFloat(this->x), CGFloat(this->y)};
			return result;
			}


		Z_CT_MEMBER(CPP14) operator NSSize() const
			{
			NSSize result = {CGFloat(this->x), CGFloat(this->y)};
			return result;
			}


		Z_CT_MEMBER(CPP14) operator NSRect() const
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
			{return cocos2d::Rect(0.0f, 0.0f, float(this->x), float(this->y));}

#	endif


	Z_CT_MEMBER(CPP11) Value2D clamp(const Value2D &minimum, const Value2D &maximum) const
		{
		return Value2D
			(Zeta::clamp<T>(this->x, minimum.x, maximum.x),
			 Zeta::clamp<T>(this->y, minimum.y, maximum.y));
		}


	Z_CT_MEMBER(CPP11) Value2D clamp(T minimum, T maximum) const
		{
		return Value2D
			(Zeta::clamp<T>(this->x, minimum, maximum),
			 Zeta::clamp<T>(this->y, minimum, maximum));
		}


	Z_CT_MEMBER(CPP11) T cross_product(const Value2D &other) const
		{return this->x * other.y - this->y * other.x;}


	Z_CT_MEMBER(CPP11) T dot_product(const Value2D &other) const
		{return this->x * other.x + this->y * other.y;}


	Z_CT_MEMBER(CPP11) Value2D fit(const Value2D &other) const
		{
		return this->y / this->x > other.y / other.x
			? Value2D(this->x * other.y / this->y, other.y)
			: Value2D(other.x, this->y * other.x / this->x);
		}


	Z_CT_MEMBER(CPP11) Boolean has_zero() const
		{return this->x == T(0) || this->y == T(0);}


	Z_CT_MEMBER(CPP11) T inner_maximum() const
		{return Zeta::maximum<T>(this->x, this->y);}


	Z_CT_MEMBER(CPP11) T inner_middle() const
		{return (this->x + this->y) / T(2);}


	Z_CT_MEMBER(CPP11) T inner_minimum() const
		{return Zeta::minimum<T>(this->x, this->y);}


	Z_CT_MEMBER(CPP11) T inner_product() const
		{return this->x * this->y;}


	Z_CT_MEMBER(CPP11) T inner_sum() const
		{return this->x + this->y;}


	Z_CT_MEMBER(CPP11) Boolean is_zero() const
		{return this->x == T(0) && this->y == T(0);}


	Z_CT_MEMBER(CPP11) Value2D maximum(const Value2D &other) const
		{
		return Value2D
			(Zeta::maximum<T>(this->x, other.x),
			 Zeta::maximum<T>(this->y, other.y));
		}


	Z_CT_MEMBER(CPP11) Value2D middle(const Value2D &other) const
		{return Value2D((this->x + other.x) / T(2), (this->y + other.y) / T(2));}


	Z_CT_MEMBER(CPP11) Value2D minimum(const Value2D &other) const
		{
		return Value2D
			(Zeta::minimum<T>(this->x, other.x),
			 Zeta::minimum<T>(this->y, other.y));
		}


	Z_CT_MEMBER(CPP11) Value3D<T> nxy(T n) const
		{return Value3D<T>(n, this->x, this->y);}


	Z_CT_MEMBER(CPP11) Value3D<T> nyx(T n) const
		{return Value3D<T>(n, this->y, this->x);}


	Z_CT_MEMBER(CPP11) T squared_length() const
		{return this->x * this->x + this->y * this->y;}


	Z_INLINE_MEMBER void swap(Value2D &other)
		{Zeta::swap<Base>(this, &other);}


	Z_CT_MEMBER(CPP11) Value3D<T> xny(T n) const
		{return Value3D<T>(this->x, n, this->y);}


	Z_CT_MEMBER(CPP11) Value3D<T> xyn(T n) const
		{return Value3D<T>(this->x, this->y, n);}


	Z_CT_MEMBER(CPP11) Value3D<T> ynx(T n) const
		{return Value3D<T>(this->y, n, this->x);}


	Z_CT_MEMBER(CPP11) Value2D yx() const
		{return Value2D(this->y, this->x);}


	Z_CT_MEMBER(CPP11) Value3D<T> yxn(T n) const
		{return Value3D<T>(this->y, this->x, n);}
};}


#ifndef __Z_classes_base_Value3D_HPP__
#	include <Z/classes/base/Value3D.hpp>
#endif

#endif // __Z_classes_base_Value2D_HPP__
