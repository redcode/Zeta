/* Zeta API - Z/classes/XY.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_XY_HPP
#define Z_classes_XY_HPP

#include <Z/functions/math.hpp>

#ifdef Z_WITH_CORE_FOUNDATION
#	include <CoreGraphics/CGGeometry.h>
#endif

#if defined(Z_WITH_FOUNDATION) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
#	import <Foundation/NSGeometry.h>
#endif

#ifdef Z_WITH_COCOS2D_X
#	include "cocos2d.h"
#endif

#ifdef Z_WITH_QT
#	include <QPoint>
#	include <QSize>
#	include <QRect>
#endif

namespace Zeta {template <class t> struct XYZ;}


namespace Zeta {template <class t> struct XY {
	t x, y;

	Z_INLINE XY() Z_NOTHROW Z_DEFAULTED({})

	Z_CT(CPP11) XY(t x_, t y_) Z_NOTHROW
	: x(x_), y(y_) {}


	Z_CT(CPP11) XY(t xy) Z_NOTHROW
	: x(xy), y(xy) {}


	Z_CT(CPP11) XY(const XYZ<t> &xy) Z_NOTHROW
	: x(xy.x), y(xy.y) {}


#	if	Z_DIALECT_HAS(CPP98, SFINAE) && \
		Z_DIALECT_HAS(CPP11, DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE)

		template <class other_t, class e = typename TypeIf<!TypeIsSame<t, other_t>::value>::type>
		Z_CT(CPP11) XY(const XY<other_t> &other) Z_NOTHROW
		: x(t(other.x)), y(t(other.y)) {}
#	endif


	Z_CT(CPP11) operator Boolean() const Z_NOTHROW
		{return x != t(0) || y != t(0);}


	friend Z_CT(CPP11) Boolean operator ==(const XY &lhs, const XY &rhs) Z_NOTHROW
		{return lhs.x == rhs.x && lhs.y == rhs.y;}


	friend Z_CT(CPP11) Boolean operator !=(const XY &lhs, const XY &rhs) Z_NOTHROW
		{return lhs.x != rhs.x || lhs.y != rhs.y;}


	friend Z_CT(CPP11) Boolean operator >=(const XY &lhs, const XY &rhs) Z_NOTHROW
		{return lhs.x >= rhs.x && lhs.y >= rhs.y;}


	friend Z_CT(CPP11) Boolean operator <=(const XY &lhs, const XY &rhs) Z_NOTHROW
		{return lhs.x <= rhs.x && lhs.y <= rhs.y;}


	friend Z_CT(CPP11) Boolean operator >(const XY &lhs, const XY &rhs) Z_NOTHROW
		{return lhs.x > rhs.x && lhs.y > rhs.y;}


	friend Z_CT(CPP11) Boolean operator <(const XY &lhs, const XY &rhs) Z_NOTHROW
		{return lhs.x < rhs.x && lhs.y < rhs.y;}


	friend Z_CT(CPP11) XY operator +(const XY &lhs, const XY &rhs) Z_NOTHROW
		{return XY(lhs.x + rhs.x, lhs.y + rhs.y);}


	friend Z_CT(CPP11) XY operator -(const XY &lhs, const XY &rhs) Z_NOTHROW
		{return XY(lhs.x - rhs.x, lhs.y - rhs.y);}


	friend Z_CT(CPP11) XY operator *(const XY &lhs, const XY &rhs) Z_NOTHROW
		{return XY(lhs.x * rhs.x, lhs.y * rhs.y);}


	friend Z_CT(CPP11) XY operator /(const XY &lhs, const XY &rhs) Z_NOTHROW
		{return XY(lhs.x / rhs.x, lhs.y / rhs.y);}


	friend Z_CT(CPP11) Boolean operator ==(const XY &lhs, t rhs) Z_NOTHROW
		{return lhs.x == rhs && lhs.y == rhs;}


	friend Z_CT(CPP11) Boolean operator !=(const XY &lhs, t rhs) Z_NOTHROW
		{return lhs.x != rhs || lhs.y != rhs;}


	friend Z_CT(CPP11) Boolean operator >=(const XY &lhs, t rhs) Z_NOTHROW
		{return lhs.x >= rhs && lhs.y >= rhs;}


	friend Z_CT(CPP11) Boolean operator <=(const XY &lhs, t rhs) Z_NOTHROW
		{return lhs.x <= rhs && lhs.y <= rhs;}


	friend Z_CT(CPP11) Boolean operator >(const XY &lhs, t rhs) Z_NOTHROW
		{return lhs.x > rhs && lhs.y > rhs;}


	friend Z_CT(CPP11) Boolean operator <(const XY &lhs, t rhs) Z_NOTHROW
		{return lhs.x < rhs && lhs.y < rhs;}


	friend Z_CT(CPP11) XY operator +(const XY &lhs, t rhs) Z_NOTHROW
		{return XY(lhs.x + rhs, lhs.y + rhs);}


	friend Z_CT(CPP11) XY operator -(const XY &lhs, t rhs) Z_NOTHROW
		{return XY(lhs.x - rhs, lhs.y - rhs);}


	friend Z_CT(CPP11) XY operator *(const XY &lhs, t rhs) Z_NOTHROW
		{return XY(lhs.x * rhs, lhs.y * rhs);}


	friend Z_CT(CPP11) XY operator /(const XY &lhs, t rhs) Z_NOTHROW
		{return XY(lhs.x / rhs, lhs.y / rhs);}


	friend Z_CT(CPP11) Boolean operator ==(t lhs, const XY &rhs) Z_NOTHROW
		{return lhs == rhs.x && lhs == rhs.y;}


	friend Z_CT(CPP11) Boolean operator !=(t lhs, const XY &rhs) Z_NOTHROW
		{return lhs != rhs.x || lhs != rhs.y;}


	friend Z_CT(CPP11) Boolean operator >=(t lhs, const XY &rhs) Z_NOTHROW
		{return lhs >= rhs.x && lhs >= rhs.y;}


	friend Z_CT(CPP11) Boolean operator <=(t lhs, const XY &rhs) Z_NOTHROW
		{return lhs <= rhs.x && lhs <= rhs.y;}


	friend Z_CT(CPP11) Boolean operator >(t lhs, const XY &rhs) Z_NOTHROW
		{return lhs > rhs.x && lhs > rhs.y;}


	friend Z_CT(CPP11) Boolean operator <(t lhs, const XY &rhs) Z_NOTHROW
		{return lhs < rhs.x && lhs < rhs.y;}


	friend Z_CT(CPP11) XY operator +(t lhs, const XY &rhs) Z_NOTHROW
		{return XY(lhs + rhs.x, lhs + rhs.y);}


	friend Z_CT(CPP11) XY operator *(t lhs, const XY &rhs) Z_NOTHROW
		{return XY(lhs * rhs.x, lhs * rhs.y);}


	Z_INLINE XY &operator +=(const XY &rhs) Z_NOTHROW {return *this = *this + rhs;}
	Z_INLINE XY &operator -=(const XY &rhs) Z_NOTHROW {return *this = *this - rhs;}
	Z_INLINE XY &operator *=(const XY &rhs) Z_NOTHROW {return *this = *this * rhs;}
	Z_INLINE XY &operator /=(const XY &rhs) Z_NOTHROW {return *this = *this / rhs;}

	Z_INLINE XY &operator +=(t rhs) Z_NOTHROW {return *this = *this + rhs;}
	Z_INLINE XY &operator -=(t rhs) Z_NOTHROW {return *this = *this - rhs;}
	Z_INLINE XY &operator *=(t rhs) Z_NOTHROW {return *this = *this * rhs;}
	Z_INLINE XY &operator /=(t rhs) Z_NOTHROW {return *this = *this / rhs;}

	Z_INLINE t  operator [](UInt index) const Z_NOTHROW {return ((t *)this)[index];}
	Z_INLINE t &operator [](UInt index)	  Z_NOTHROW {return ((t *)this)[index];}

	Z_CT(CPP11) XY	   yx ()    const Z_NOTHROW {return XY(y, x);}
	Z_CT(CPP11) XYZ<t> nxy(t n) const Z_NOTHROW {return XYZ<t>(n, x, y);}
	Z_CT(CPP11) XYZ<t> nyx(t n) const Z_NOTHROW {return XYZ<t>(n, y, x);}
	Z_CT(CPP11) XYZ<t> xny(t n) const Z_NOTHROW {return XYZ<t>(x, n, y);}
	Z_CT(CPP11) XYZ<t> xyn(t n) const Z_NOTHROW {return XYZ<t>(x, y, n);}
	Z_CT(CPP11) XYZ<t> ynx(t n) const Z_NOTHROW {return XYZ<t>(y, n, x);}
	Z_CT(CPP11) XYZ<t> yxn(t n) const Z_NOTHROW {return XYZ<t>(y, x, n);}


	Z_INLINE XY apply(t (* function)(t)) const Z_NOTHROW
		{return XY(function(x), function(y));}


	Z_CT(CPP11) XY clamp(const XY &minimum, const XY &maximum) const Z_NOTHROW
		{
		return XY(
			Zeta::clamp<t>(x, minimum.x, maximum.x),
			Zeta::clamp<t>(y, minimum.y, maximum.y));
		}


	Z_CT(CPP11) XY clamp(t minimum, t maximum) const Z_NOTHROW
		{
		return XY(
			Zeta::clamp<t>(x, minimum, maximum),
			Zeta::clamp<t>(y, minimum, maximum));
		}


	Z_CT(CPP11) t cross_product(const XY &other) const Z_NOTHROW
		{return x * other.y - y * other.x;}


	Z_CT(CPP11) t dot_product(const XY &other) const Z_NOTHROW
		{return x * other.x + y * other.y;}


	Z_CT(CPP11) XY fit(const XY &other) const Z_NOTHROW
		{
		return y / x > other.y / other.x
			? XY(x * other.y / y, other.y)
			: XY(other.x, y * other.x / x);
		}


	Z_CT(CPP11) Boolean has_zero() const Z_NOTHROW
		{return x == t(0) || y == t(0);}


	Z_CT(CPP11) t inner_maximum() const Z_NOTHROW
		{return Zeta::maximum<t>(x, y);}


	Z_CT(CPP11) t inner_middle() const Z_NOTHROW
		{return (x + y) / t(2);}


	Z_CT(CPP11) t inner_minimum() const Z_NOTHROW
		{return Zeta::minimum<t>(x, y);}


	Z_CT(CPP11) t inner_product() const Z_NOTHROW
		{return x * y;}


	Z_CT(CPP11) t inner_sum() const Z_NOTHROW
		{return x + y;}


	Z_CT(CPP11) Boolean is_zero() const Z_NOTHROW
		{return x == t(0) && y == t(0);}


	Z_CT(CPP11) XY maximum(const XY &other) const Z_NOTHROW
		{return XY(Zeta::maximum<t>(x, other.x), Zeta::maximum<t>(y, other.y));}


	Z_CT(CPP11) XY middle(const XY &other) const Z_NOTHROW
		{return XY((x + other.x) / t(2), (y + other.y) / t(2));}


	Z_CT(CPP11) XY minimum(const XY &other) const Z_NOTHROW
		{return XY(Zeta::minimum<t>(x, other.x), Zeta::minimum<t>(y, other.y));}


	Z_CT(CPP11) t squared_length() const Z_NOTHROW
		{return x * x + y * y;}


	// MARK: - Signed


	Z_CT(CPP11) XY absolute() const Z_NOTHROW
		{return XY(Zeta::absolute<t>(x), Zeta::absolute<t>(y));}


	Z_CT(CPP11) Boolean has_negative() const Z_NOTHROW
		{return x < t(0) || y < t(0);}


	Z_CT(CPP11) Boolean is_negative() const Z_NOTHROW
		{return x < t(0) && y < t(0);}


	Z_CT(CPP11) XY negative() const Z_NOTHROW
		{return XY(-x, -y);}


	// MARK: - Integer


//	Z_CT(CPP11) Boolean is_perpendicular(const XY &other) const Z_NOTHROW
//		{return !Zeta::absolute<t>(dot_product(other));}


	// MARK: - Real


	Z_CT(CPP11) XY clamp_01() const Z_NOTHROW
		{return XY(Zeta::clamp_01<t>(x), Zeta::clamp_01<t>(y));}


	Z_CT(CPP11) Boolean has_almost_zero() const Z_NOTHROW
		{return Zeta::is_almost_zero<t>(x) || Zeta::is_almost_zero<t>(y);}


	Z_CT(CPP11) Boolean has_finite() const Z_NOTHROW
		{return Zeta::is_finite<t>(x) || Zeta::is_finite<t>(y);}


	Z_CT(CPP11) Boolean has_infinity() const Z_NOTHROW
		{return Zeta::is_infinity<t>(x) || Zeta::is_infinity<t>(y);}


	Z_CT(CPP11) Boolean has_nan() const Z_NOTHROW
		{return Zeta::is_nan<t>(x) || Zeta::is_nan<t>(y);}


	Z_CT(CPP11) XY inverse_lerp(const XY &other, t v) const Z_NOTHROW
		{
		return XY(
			Zeta::inverse_lerp<t>(x, other.x, v),
			Zeta::inverse_lerp<t>(y, other.y, v));
		}


	Z_CT(CPP11) Boolean is_almost_equal(const XY &other) const Z_NOTHROW
		{
		return	Zeta::are_almost_equal<t>(x, other.x) &&
			Zeta::are_almost_equal<t>(y, other.y);
		}


	Z_CT(CPP11) Boolean is_almost_zero() const Z_NOTHROW
		{return Zeta::is_almost_zero<t>(x) && Zeta::is_almost_zero<t>(y);}


	Z_CT(CPP11) Boolean is_finite() const Z_NOTHROW
		{return Zeta::is_finite<t>(x) && Zeta::is_finite<t>(y);}


	Z_CT(CPP11) Boolean is_infinity() const Z_NOTHROW
		{return Zeta::is_infinity<t>(x) && Zeta::is_infinity<t>(y);}


	Z_CT(CPP11) Boolean is_nan() const Z_NOTHROW
		{return Zeta::is_nan<t>(x) && Zeta::is_nan<t>(y);}


	Z_CT(CPP11) Boolean is_perpendicular(const XY &other) const Z_NOTHROW
		{return Zeta::absolute<t>(dot_product(other)) <= Type<t>::epsilon();}


	Z_CT(CPP11) XY lerp(const XY &other, t v) const Z_NOTHROW
		{
		return XY(
			Zeta::lerp<t>(x, other.x, v),
			Zeta::lerp<t>(y, other.y, v));
		}


	Z_CT(CPP11) XY reciprocal() const Z_NOTHROW
		{return XY(t(1) / x, t(1) / y);}


#	if defined(Z_WITH_CORE_FOUNDATION) || defined(Z_WITH_FOUNDATION)

#		define Z_z_APPLE_CONSTRUCTORS(Prefix)			     \
									     \
			Z_CT(CPP11) XY(const Prefix##Point &point) Z_NOTHROW \
			: x(t(point.x)), y(t(point.y)) {}		     \
									     \
									     \
			Z_CT(CPP11) XY(const Prefix##Size &size) Z_NOTHROW   \
			: x(t(size.width)), y(t(size.height)) {}


#		if Z_DIALECT_HAS(CPP11, COPY_LIST_INITIALIZATION)

#			define Z_z_APPLE_OPERATORS(Prefix)				 \
											 \
				Z_CT(CPP11) operator Prefix##Point() const Z_NOTHROW	 \
					{return {CGFloat(x), CGFloat(y)};}		 \
											 \
											 \
				Z_CT(CPP11) operator Prefix##Size() const Z_NOTHROW	 \
					{return {CGFloat(x), CGFloat(y)};}		 \
											 \
											 \
				Z_CT(CPP11) operator Prefix##Rect() const Z_NOTHROW	 \
					{return {{0.0, 0.0}, {CGFloat(x), CGFloat(y)}};}

#		else
#			define Z_z_APPLE_OPERATORS(Prefix)							\
														\
				Z_CT(CPP14) operator Prefix##Point() const Z_NOTHROW				\
					{									\
					Prefix##Point result = {CGFloat(x), CGFloat(y)};			\
					return result;								\
					}									\
														\
														\
				Z_CT(CPP14) operator Prefix##Size() const Z_NOTHROW				\
					{									\
					Prefix##Size result = {CGFloat(x), CGFloat(y)};				\
					return result;								\
					}									\
														\
														\
				Z_CT(CPP14) operator Prefix##Rect() const Z_NOTHROW				\
					{									\
					Prefix##Rect result = {CGFloat(0), CGFloat(0), CGFloat(x), CGFloat(y)};	\
					return result;								\
					}
#		endif


#		ifdef Z_WITH_CORE_FOUNDATION
			Z_z_APPLE_CONSTRUCTORS(CG)
			Z_z_APPLE_OPERATORS   (CG)
#		endif

#		if	defined(Z_WITH_FOUNDATION)	   &&		       \
			Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) &&		       \
		       (!defined(Z_WITH_CORE_FOUNDATION)		    || \
			!defined(NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES) || \
			!NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES)

			Z_z_APPLE_CONSTRUCTORS(NS)
			Z_z_APPLE_OPERATORS   (NS)
#		endif

#		undef Z_z_APPLE_CONSTRUCTORS
#		undef Z_z_APPLE_OPERATORS

#	endif


#	ifdef Z_WITH_COCOS2D_X

		Z_CT(CPP11) XY(const cocos2d::Vec2 &point) Z_NOTHROW
		: x(point.x), y(point.y) {}


		Z_CT(CPP11) XY(const cocos2d::Size &size) Z_NOTHROW
		: x(size.width), y(size.height) {}


		Z_INLINE operator cocos2d::Vec2() const Z_NOTHROW
			{return cocos2d::Vec2(float(x), float(y));}


		Z_INLINE operator cocos2d::Size() const Z_NOTHROW
			{return cocos2d::Size(float(x), float(y));}


		Z_INLINE operator cocos2d::Rect() const Z_NOTHROW
			{return cocos2d::Rect(0.0f, 0.0f, float(x), float(y));}

#	endif


#	ifdef Z_WITH_QT

		Z_CT(CPP11) XY(const QPoint &point) Z_NOTHROW
		: x(t(point.x())), y(t(point.y())) {}


		Z_CT(CPP11) XY(const QSize  &size) Z_NOTHROW
		: x(t(size.width())), y(t(size.height())) {}


		Z_CT(CPP11) operator QPoint() const Z_NOTHROW
			{return QPoint(int(x), int(y));}


		Z_CT(CPP11) operator QSize() const Z_NOTHROW
			{return QSize(int(x), int(y));}


		Z_CT(CPP11) operator QRect() const Z_NOTHROW
			{return QRect(0, 0, int(x), int(y));}

#	endif
};}


#ifndef Z_classes_XYZ_HPP
#	include <Z/classes/XYZ.hpp>
#endif

#endif // Z_classes_XY_HPP
