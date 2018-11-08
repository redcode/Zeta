/* Z Kit - classes/base/Value2D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_base_Value2D_HPP_
#define _Z_classes_base_Value2D_HPP_

#include <Z/macros/type selection.hpp>
#include <Z/functions/base/value.hpp>


#define Z_IMPLEMENTATION_FOUNDATION_CONSTRUCTORS(Prefix)					\
Z_CT(CPP11) Value2D(const Prefix##Point &point) : x(point.x),    y(point.y)     {}		\
Z_CT(CPP11) Value2D(const Prefix##Size  &size ) : x(size.width), y(size.height) {}


#if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)

#	define Z_IMPLEMENTATION_FOUNDATION_OPERATORS(Prefix)					\
	Z_CT(CPP11) operator Prefix##Point() const {return {CGFloat(x), CGFloat(y)};}		\
	Z_CT(CPP11) operator Prefix##Size () const {return {CGFloat(x), CGFloat(y)};}		\
	Z_CT(CPP11) operator Prefix##Rect () const {return {{0.0, 0.0}, {CGFloat(x), CGFloat(y)}};}

#else

#	define Z_IMPLEMENTATION_FOUNDATION_OPERATORS(Prefix)					\
												\
	Z_CT(CPP14) operator Prefix##Point() const						\
		{										\
		Prefix##Point result = {CGFloat(x), CGFloat(y)};				\
		return result;									\
		}										\
												\
												\
	Z_CT(CPP14) operator Prefix##Size() const						\
		{										\
		Prefix##Size result = {CGFloat(x), CGFloat(y)};					\
		return result;									\
		}										\
												\
												\
	Z_CT(CPP14) operator Prefix##Rect() const						\
		{										\
		Prefix##Rect result = {CGFloat(0), CGFloat(0), CGFloat(x), CGFloat(y)};		\
		return result;									\
		}

#endif


#ifdef Z_USE_CG_GEOMETRY

#	include <CoreGraphics/CGGeometry.h>

#	define Z_IMPLEMENTATION_CG_GEOMETRY		     \
		Z_IMPLEMENTATION_FOUNDATION_CONSTRUCTORS(CG) \
		Z_IMPLEMENTATION_FOUNDATION_OPERATORS	(CG)

#else
#	define Z_IMPLEMENTATION_CG_GEOMETRY
#endif

#if defined(Z_USE_NS_GEOMETRY) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

#	import <Foundation/NSGeometry.h>

#	if	!defined(Z_USE_CG_GEOMETRY)			    || \
		!defined(NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES) || \
		!NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES

#		define Z_IMPLEMENTATION_NS_GEOMETRY		     \
			Z_IMPLEMENTATION_FOUNDATION_CONSTRUCTORS(NS) \
			Z_IMPLEMENTATION_FOUNDATION_OPERATORS	(NS)

#	endif

#endif

#ifndef Z_IMPLEMENTATION_NS_GEOMETRY
#	define Z_IMPLEMENTATION_NS_GEOMETRY
#endif

#ifdef Z_USE_COCOS2D_X

#	include "cocos2d.h"

#	define Z_IMPLEMENTATION_COCOS2D_X							\
												\
	Z_INLINE Value2D(const cocos2d::Vec2 &point) : x(point.x),    y(point.y)     {}		\
	Z_INLINE Value2D(const cocos2d::Size &size ) : x(size.width), y(size.height) {}		\
												\
	Z_INLINE operator cocos2d::Vec2() const {return cocos2d::Vec2(float(x), float(y));}	\
	Z_INLINE operator cocos2d::Size() const {return cocos2d::Size(float(x), float(y));}	\
	Z_INLINE operator cocos2d::Rect() const {return cocos2d::Rect(0.0f, 0.0f, float(x), float(y));}

#else
#	define Z_IMPLEMENTATION_COCOS2D_X
#endif


#define Z_IMPLEMENTATION_COMMON									\
												\
typedef typename ZTypeFixedNumber(Z2D, T) Base;							\
T x, y;												\
												\
Z_INLINE Value2D() Z_DEFAULTED({})								\
												\
Z_CT(CPP11) Value2D(T x, T y)		  : x(x),	y(y)	   {}				\
Z_CT(CPP11) Value2D(T xy)		  : x(xy),	y(xy)	   {}				\
Z_CT(CPP11) Value2D(const Value3D<T> &xy) : x(xy.x),	y(xy.y)	   {}				\
Z_CT(CPP11) Value2D(const Base &other)    : x(other.x), y(other.y) {}				\
												\
Z_CT(CPP11) operator Boolean() const {return x != T(0) || y != T(0);}				\
Z_INLINE    operator Base&  () const {return *((Base *)this);}					\
												\
Z_CT(CPP11) Boolean operator ==(const Value2D &rhs) const {return x == rhs.x && y == rhs.y;}	\
Z_CT(CPP11) Boolean operator !=(const Value2D &rhs) const {return x != rhs.x || y != rhs.y;}	\
Z_CT(CPP11) Boolean operator <=(const Value2D &rhs) const {return x <= rhs.x && y <= rhs.y;}	\
Z_CT(CPP11) Boolean operator >=(const Value2D &rhs) const {return x >= rhs.x && y >= rhs.y;}	\
Z_CT(CPP11) Boolean operator > (const Value2D &rhs) const {return x >  rhs.x && y >  rhs.y;}	\
Z_CT(CPP11) Boolean operator < (const Value2D &rhs) const {return x <  rhs.x && y <  rhs.y;}	\
												\
Z_CT(CPP11) Value2D operator +(const Value2D &rhs) const {return Value2D(x + rhs.x, y + rhs.y);}\
Z_CT(CPP11) Value2D operator -(const Value2D &rhs) const {return Value2D(x - rhs.x, y - rhs.y);}\
Z_CT(CPP11) Value2D operator *(const Value2D &rhs) const {return Value2D(x * rhs.x, y * rhs.y);}\
Z_CT(CPP11) Value2D operator /(const Value2D &rhs) const {return Value2D(x / rhs.x, y / rhs.y);}\
												\
Z_INLINE Value2D &operator +=(const Value2D &rhs) {return *this = *this + rhs;}			\
Z_INLINE Value2D &operator -=(const Value2D &rhs) {return *this = *this - rhs;}			\
Z_INLINE Value2D &operator *=(const Value2D &rhs) {return *this = *this * rhs;}			\
Z_INLINE Value2D &operator /=(const Value2D &rhs) {return *this = *this / rhs;}			\
												\
Z_CT(CPP11) Boolean operator ==(T rhs) const {return x == rhs && y == rhs;}			\
Z_CT(CPP11) Boolean operator !=(T rhs) const {return x != rhs || y != rhs;}			\
Z_CT(CPP11) Boolean operator <=(T rhs) const {return x <= rhs && y <= rhs;}			\
Z_CT(CPP11) Boolean operator >=(T rhs) const {return x >= rhs && y >= rhs;}			\
Z_CT(CPP11) Boolean operator > (T rhs) const {return x >  rhs && y >  rhs;}			\
Z_CT(CPP11) Boolean operator < (T rhs) const {return x <  rhs && y <  rhs;}			\
												\
Z_CT(CPP11) Value2D operator +(T rhs) const {return Value2D(x + rhs, y + rhs);}			\
Z_CT(CPP11) Value2D operator -(T rhs) const {return Value2D(x - rhs, y - rhs);}			\
Z_CT(CPP11) Value2D operator *(T rhs) const {return Value2D(x * rhs, y * rhs);}			\
Z_CT(CPP11) Value2D operator /(T rhs) const {return Value2D(x / rhs, y / rhs);}			\
												\
Z_INLINE Value2D &operator +=(T rhs) {return *this = *this + rhs;}				\
Z_INLINE Value2D &operator -=(T rhs) {return *this = *this - rhs;}				\
Z_INLINE Value2D &operator *=(T rhs) {return *this = *this * rhs;}				\
Z_INLINE Value2D &operator /=(T rhs) {return *this = *this / rhs;}				\
												\
Z_INLINE T  operator [](UInt index) const {return ((T *)this)[index];}				\
Z_INLINE T &operator [](UInt index)	  {return ((T *)this)[index];}				\
												\
Z_IMPLEMENTATION_CG_GEOMETRY									\
Z_IMPLEMENTATION_NS_GEOMETRY									\
Z_IMPLEMENTATION_COCOS2D_X									\
												\
Z_CT(CPP11) Value2D    yx ()	const {return Value2D(y, x);}					\
Z_CT(CPP11) Value3D<T> nxy(T n) const {return Value3D<T>(n, x, y);}				\
Z_CT(CPP11) Value3D<T> nyx(T n) const {return Value3D<T>(n, y, x);}				\
Z_CT(CPP11) Value3D<T> xny(T n) const {return Value3D<T>(x, n, y);}				\
Z_CT(CPP11) Value3D<T> xyn(T n) const {return Value3D<T>(x, y, n);}				\
Z_CT(CPP11) Value3D<T> ynx(T n) const {return Value3D<T>(y, n, x);}				\
Z_CT(CPP11) Value3D<T> yxn(T n) const {return Value3D<T>(y, x, n);}				\
												\
												\
Z_CT(CPP11) Value2D clamp(const Value2D &minimum, const Value2D &maximum) const			\
	{											\
	return Value2D										\
		(Zeta::clamp<T>(x, minimum.x, maximum.x),					\
		 Zeta::clamp<T>(y, minimum.y, maximum.y));					\
	}											\
												\
												\
Z_CT(CPP11) Value2D clamp(T minimum, T maximum) const						\
	{											\
	return Value2D										\
		(Zeta::clamp<T>(x, minimum, maximum),						\
		 Zeta::clamp<T>(y, minimum, maximum));						\
	}											\
												\
												\
Z_CT(CPP11) T cross_product(const Value2D &other) const						\
	{return x * other.y - y * other.x;}							\
												\
												\
Z_CT(CPP11) T dot_product(const Value2D &other) const						\
	{return x * other.x + y * other.y;}							\
												\
												\
Z_CT(CPP11) Value2D fit(const Value2D &other) const						\
	{											\
	return y / x > other.y / other.x							\
		? Value2D(x * other.y / y, other.y)						\
		: Value2D(other.x, y * other.x / x);						\
	}											\
												\
												\
Z_CT(CPP11) Boolean has_zero() const								\
	{return x == T(0) || y == T(0);}							\
												\
												\
Z_CT(CPP11) T inner_maximum() const								\
	{return Zeta::maximum<T>(x, y);}							\
												\
												\
Z_CT(CPP11) T inner_middle() const								\
	{return (x + y) / T(2);}								\
												\
												\
Z_CT(CPP11) T inner_minimum() const								\
	{return Zeta::minimum<T>(x, y);}							\
												\
												\
Z_CT(CPP11) T inner_product() const								\
	{return x * y;}										\
												\
												\
Z_CT(CPP11) T inner_sum() const									\
	{return x + y;}										\
												\
												\
Z_CT(CPP11) Boolean is_zero() const								\
	{return x == T(0) && y == T(0);}							\
												\
												\
Z_CT(CPP11) Value2D maximum(const Value2D &other) const						\
	{return Value2D(Zeta::maximum<T>(x, other.x), Zeta::maximum<T>(y, other.y));}		\
												\
												\
Z_CT(CPP11) Value2D middle(const Value2D &other) const						\
	{return Value2D((x + other.x) / T(2), (y + other.y) / T(2));}				\
												\
												\
Z_CT(CPP11) Value2D minimum(const Value2D &other) const						\
	{return Value2D(Zeta::minimum<T>(x, other.x), Zeta::minimum<T>(y, other.y));}		\
												\
												\
Z_CT(CPP11) T squared_length() const								\
	{return x * x + y * y;}									\
												\
												\
Z_INLINE void swap(Value2D &other)								\
	{Zeta::swap<Base>(this, &other);}


#define Z_IMPLEMENTATION_SIGNED									\
												\
Z_CT(CPP11) Value2D absolute() const								\
	{return Value2D(Zeta::absolute<T>(x), Zeta::absolute<T>(y));}				\
												\
												\
Z_CT(CPP11) Boolean has_negative() const							\
	{return x < T(0) || y < T(0);}								\
												\
												\
Z_CT(CPP11) Boolean is_negative() const								\
	{return x < T(0) && y < T(0);}								\
												\
												\
Z_CT(CPP11) Value2D negative() const								\
	{return Value2D(-x, -y);}


namespace Zeta {

	template <class T, UInt T_number_set = Type<T>::number_set> struct Value2D;
	template <class T, UInt T_number_set = Type<T>::number_set> struct Value3D;


	template <class T> struct Value2D<T, Z_NUMBER_SET_Z> {
		Z_IMPLEMENTATION_COMMON
		Z_IMPLEMENTATION_SIGNED


		Z_CT(CPP11) Boolean is_perpendicular(const Value2D &other) const
			{return !Zeta::absolute<T>(dot_product(other));}


#		ifdef Z_EXTENSION_VALUE_2D_Z
			Z_EXTENSION_VALUE_2D_Z
#		endif
	};


	template <class T> struct Value2D<T, Z_NUMBER_SET_N> {
		Z_IMPLEMENTATION_COMMON


#		ifdef Z_EXTENSION_VALUE_2D_N
			Z_EXTENSION_VALUE_2D_N
#		endif
	};


	template <class T> struct Value2D<T, Z_NUMBER_SET_R> {
		Z_IMPLEMENTATION_COMMON
		Z_IMPLEMENTATION_SIGNED


		Z_CT(CPP11) Value2D clamp_01() const
			{return Value2D(Zeta::clamp_01<T>(x), Zeta::clamp_01<T>(y));}


		Z_CT(CPP11) Boolean has_almost_zero() const
			{return Zeta::is_almost_zero<T>(x) || Zeta::is_almost_zero<T>(y);}


		Z_CT(CPP11) Boolean has_finite() const
			{return Zeta::is_finite<T>(x) || Zeta::is_finite<T>(y);}


		Z_CT(CPP11) Boolean has_infinity() const
			{return Zeta::is_infinity<T>(x) || Zeta::is_infinity<T>(y);}


		Z_CT(CPP11) Boolean has_nan() const
			{return Zeta::is_nan<T>(x) || Zeta::is_nan<T>(y);}


		Z_CT(CPP11) Value2D inverse_lerp(const Value2D &other, T t) const
			{
			return Value2D
				(Zeta::inverse_lerp<T>(x, other.x, t),
				 Zeta::inverse_lerp<T>(y, other.y, t));
			}


		Z_CT(CPP11) Boolean is_almost_equal(const Value2D &other) const
			{
			return	Zeta::are_almost_equal<T>(x, other.x) &&
				Zeta::are_almost_equal<T>(y, other.y);
			}


		Z_CT(CPP11) Boolean is_almost_zero() const
			{return Zeta::is_almost_zero<T>(x) && Zeta::is_almost_zero<T>(y);}


		Z_CT(CPP11) Boolean is_finite() const
			{return Zeta::is_finite<T>(x) && Zeta::is_finite<T>(y);}


		Z_CT(CPP11) Boolean is_infinity() const
			{return Zeta::is_infinity<T>(x) && Zeta::is_infinity<T>(y);}


		Z_CT(CPP11) Boolean is_nan() const
			{return Zeta::is_nan<T>(x) && Zeta::is_nan<T>(y);}


		Z_CT(CPP11) Boolean is_perpendicular(const Value2D &other) const
			{return Zeta::absolute<T>(dot_product(other)) <= Type<T>::epsilon();}


		Z_CT(CPP11) Value2D lerp(const Value2D &other, T t) const
			{
			return Value2D
				(Zeta::lerp<T>(x, other.x, t),
				 Zeta::lerp<T>(y, other.y, t));
			}


		Z_CT(CPP11) Value2D reciprocal() const
			{return Value2D(T(1) / x, T(1) / y);}


#		ifdef Z_EXTENSION_VALUE_2D_R
			Z_EXTENSION_VALUE_2D_R
#		endif
	};
}


#undef Z_IMPLEMENTATION_FOUNDATION_CONSTRUCTORS
#undef Z_IMPLEMENTATION_FOUNDATION_OPERATORS
#undef Z_IMPLEMENTATION_CG_GEOMETRY
#undef Z_IMPLEMENTATION_NS_GEOMETRY
#undef Z_IMPLEMENTATION_COCOS2D_X
#undef Z_IMPLEMENTATION_COMMON
#undef Z_IMPLEMENTATION_SIGNED

#ifndef _Z_classes_base_Value3D_HPP_
#	include <Z/classes/base/Value3D.hpp>
#endif

#endif // _Z_classes_base_Value2D_HPP_
