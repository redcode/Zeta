/* Z Kit - classes/Rectangle.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Rectangle_HPP
#define Z_classes_Rectangle_HPP

#include <Z/classes/XY.hpp>


#define Z_IMPLEMENTATION__APPLE_CONSTRUCTOR(Prefix)  \
						     \
Z_CT(CPP11) Rectangle(const Prefix##Rect &rectangle) \
: point(rectangle.origin), size(rectangle.size) {}   \
						     \
Z_CT(CPP11) Rectangle(const Prefix##Size &size_)     \
: point(0), size(size_) {}


#if Z_DIALECT_HAS(CPP, COPY_LIST_INITIALIZATION)

#	define Z_IMPLEMENTATION__APPLE_OPERATOR(Prefix)	      \
							      \
	Z_CT(CPP11) operator Prefix##Rect() const	      \
		{					      \
		return {{CGFloat(point.x), CGFloat(point.y)}, \
			{CGFloat(size.x),  CGFloat(size.y)}}; \
		}

#else

#	define Z_IMPLEMENTATION__APPLE_OPERATOR(Prefix)	      \
							      \
	Z_CT(CPP14) operator Prefix##Rect() const	      \
		{					      \
		CGRect result = {			      \
			{CGFloat(point.x), CGFloat(point.y)}, \
			{CGFloat(size.x),  CGFloat(size.y)}   \
		};					      \
							      \
		return result;				      \
		}

#endif


#ifdef Z_USE_CG_GEOMETRY

#	include <CoreGraphics/CGGeometry.h>

#	define Z_IMPLEMENTATION__CG_GEOMETRY		\
		Z_IMPLEMENTATION__APPLE_CONSTRUCTOR(CG) \
		Z_IMPLEMENTATION__APPLE_OPERATOR   (CG)

#else
#	define Z_IMPLEMENTATION__CG_GEOMETRY
#endif

#if defined(Z_USE_NS_GEOMETRY) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

#	import <Foundation/NSGeometry.h>

#	if	!defined(Z_USE_CG_GEOMETRY)			    || \
		!defined(NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES) || \
		!NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES

#		define Z_IMPLEMENTATION__NS_GEOMETRY	\
		Z_IMPLEMENTATION__APPLE_CONSTRUCTOR(NS) \
		Z_IMPLEMENTATION__APPLE_OPERATOR   (NS)

#	endif

#endif

#ifndef Z_IMPLEMENTATION__NS_GEOMETRY
#	define Z_IMPLEMENTATION__NS_GEOMETRY
#endif

#ifdef Z_USE_COCOS2D_X

#	include "cocos2d.h"

#	define Z_IMPLEMENTATION__COCOS2D_X		   \
							   \
	Z_INLINE Rectangle(const cocos2d::Rect &rectangle) \
	: point(rectangle.origin), size(rectangle.size) {} \
							   \
							   \
	Z_INLINE operator cocos2d::Rect() const		   \
		{					   \
		return cocos2d::Rect			   \
			(float(point.x), float(point.y),   \
			 float(size.x),  float(size.y));   \
		}

#else
#	define Z_IMPLEMENTATION__COCOS2D_X
#endif


namespace Zeta {template <class T> struct Rectangle {
	XY<T> point, size;

	Z_INLINE Rectangle() Z_NOTHROW
		Z_DEFAULTED({})

	Z_CT(CPP11) Rectangle(const XY<T> &point, const XY<T> &size) Z_NOTHROW
	: point(point), size(size) {}


	Z_CT(CPP11) Rectangle(const XY<T> &point, T size_x, T size_y) Z_NOTHROW
	: point(point), size(size_x, size_y) {}


	Z_CT(CPP11) Rectangle(const XY<T> &point, T size_xy) Z_NOTHROW
	: point(point), size(size_xy) {}


	Z_CT(CPP11) Rectangle(T point_x, T point_y, const XY<T> &size) Z_NOTHROW
	: point(point_x, point_y), size(size) {}


	Z_CT(CPP11) Rectangle(T point_x, T point_y, T size_x, T size_y) Z_NOTHROW
	: point(point_x, point_y), size(size_x, size_y) {}


	Z_CT(CPP11) Rectangle(T point_x, T point_y, T size_xy) Z_NOTHROW
	: point(point_x, point_y), size(size_xy) {}


	Z_CT(CPP11) Rectangle(T point_xy, const XY<T> &size) Z_NOTHROW
	: point(point_xy), size(size) {}


	Z_CT(CPP11) Rectangle(const XY<T> &size) Z_NOTHROW
	: point(T(0)), size(size) {}


	Z_CT(CPP11) Rectangle(T size_x, T size_y) Z_NOTHROW
	: point(T(0)), size(size_x, size_y) {}


	Z_CT(CPP11) Rectangle(T size_xy) Z_NOTHROW
	: point(T(0)), size(size_xy) {}


	static Z_CT(CPP14) Rectangle from_vertices(const XY<T> &a, const XY<T> &b) Z_NOTHROW
		{
		XY<T> minimum = a.minimum(b);

		return Rectangle(minimum, a.maximum(b) - minimum);
		}


	Z_CT(CPP11) operator Boolean() const {return point || size;}


	friend Z_CT(CPP11) Boolean operator ==(const Rectangle &lhs, const Rectangle &rhs) Z_NOTHROW
		{return lhs.point == rhs.point && lhs.size == rhs.size;}


	friend Z_CT(CPP11) Boolean operator !=(const Rectangle &lhs, const Rectangle &rhs) Z_NOTHROW
		{return lhs.point != rhs.point || lhs.size != rhs.size;}


	friend Z_CT(CPP14) Rectangle operator &(const Rectangle &lhs, const Rectangle &rhs) Z_NOTHROW
		{
		T x1, x2, y1, y2;

		return	(x1 = maximum<T>(lhs.point.x,		   rhs.point.x)) <
			(x2 = minimum<T>(lhs.point.x + lhs.size.x, rhs.point.x + rhs.size.x)) &&
			(y1 = maximum<T>(lhs.point.y,		   rhs.point.y)) <
			(y2 = minimum<T>(lhs.point.y + lhs.size.y, rhs.point.y + rhs.size.y))

			? Rectangle(x1, y1, x2 - x1, y2 - y1)
			: Rectangle(T(0));
		}


	friend Z_CT(CPP14) Rectangle operator |(const Rectangle &lhs, const Rectangle &rhs) Z_NOTHROW
		{
		Rectangle result;

		result.point = lhs.point.minimum(rhs.point);
		result.size  = (lhs.point + lhs.size).maximum(rhs.point + rhs.size) - result.point;
		return result;
		}


	friend Z_CT(CPP11) Rectangle operator +(const Rectangle &lhs, T rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size + rhs);}


	friend Z_CT(CPP11) Rectangle operator +(T lhs, const Rectangle &rhs) Z_NOTHROW
		{return Rectangle(rhs.point, rhs.size + lhs);}


	friend Z_CT(CPP11) Rectangle operator -(const Rectangle &lhs, T rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size - rhs);}


	friend Z_CT(CPP11) Rectangle operator *(const Rectangle &lhs, T rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size * rhs);}


	friend Z_CT(CPP11) Rectangle operator *(T lhs, const Rectangle &rhs) Z_NOTHROW
		{return Rectangle(rhs.point, rhs.size * lhs);}


	friend Z_CT(CPP11) Rectangle operator /(const Rectangle &lhs, T rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size / rhs);}


	friend Z_CT(CPP11) Rectangle operator +(const Rectangle &lhs, const XY<T> &rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size + rhs);}


	friend Z_CT(CPP11) Rectangle operator +(const XY<T> &lhs, const Rectangle &rhs) Z_NOTHROW
		{return Rectangle(rhs.point, rhs.size + lhs);}


	friend Z_CT(CPP11) Rectangle operator -(const Rectangle &lhs, const XY<T> &rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size - rhs);}


	friend Z_CT(CPP11) Rectangle operator *(const Rectangle &lhs, const XY<T> &rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size * rhs);}


	friend Z_CT(CPP11) Rectangle operator *(const XY<T> &lhs, const Rectangle &rhs) Z_NOTHROW
		{return Rectangle(rhs.point, rhs.size * lhs);}


	friend Z_CT(CPP11) Rectangle operator /(const Rectangle &lhs, const XY<T> &rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size / rhs);}


	Z_INLINE Rectangle &operator &=(const Rectangle &rhs) Z_NOTHROW {return *this = *this & rhs;}
	Z_INLINE Rectangle &operator |=(const Rectangle &rhs) Z_NOTHROW {return *this = *this | rhs;}

	Z_INLINE Rectangle &operator +=(const XY<T> &rhs) Z_NOTHROW {return *this = *this + rhs;}
	Z_INLINE Rectangle &operator -=(const XY<T> &rhs) Z_NOTHROW {return *this = *this - rhs;}
	Z_INLINE Rectangle &operator *=(const XY<T> &rhs) Z_NOTHROW {return *this = *this * rhs;}
	Z_INLINE Rectangle &operator /=(const XY<T> &rhs) Z_NOTHROW {return *this = *this / rhs;}

	Z_INLINE Rectangle &operator +=(T rhs) Z_NOTHROW {return *this = *this + rhs;}
	Z_INLINE Rectangle &operator -=(T rhs) Z_NOTHROW {return *this = *this - rhs;}
	Z_INLINE Rectangle &operator *=(T rhs) Z_NOTHROW {return *this = *this * rhs;}
	Z_INLINE Rectangle &operator /=(T rhs) Z_NOTHROW {return *this = *this / rhs;}


	Z_IMPLEMENTATION__CG_GEOMETRY
	Z_IMPLEMENTATION__NS_GEOMETRY
	Z_IMPLEMENTATION__COCOS2D_X


	Z_CT(CPP11) XY<T> bottom() const Z_NOTHROW
		{return XY<T>(point.x + size.x / T(2), point.y);}


	Z_CT(CPP11) XY<T> bottom(T (* round)(T)) const Z_NOTHROW
		{return XY<T>(round(point.x + size.x / T(2)), point.y);}


	Z_CT(CPP11) Rectangle bottom(const XY<T> &size_) const Z_NOTHROW
		{return Rectangle(point.x + (size.x - size_.x) / T(2), point.y, size_);}


	Z_CT(CPP11) Rectangle bottom(const XY<T> &size_, T (* round)(T)) const Z_NOTHROW
		{return Rectangle(round(point.x + (size.x - size_.x) / T(2)), point.y, size_);}


	Z_CT(CPP11) XY<T> bottom_left() const Z_NOTHROW
		{return point;}


	Z_CT(CPP11) Rectangle bottom_left(const XY<T> &size_) const Z_NOTHROW
		{return Rectangle(point, size_);}


	Z_CT(CPP11) XY<T> bottom_right() const Z_NOTHROW
		{return XY<T>(point.x + size.x, point.y);}


	Z_CT(CPP11) Rectangle bottom_right(const XY<T> &size_) const Z_NOTHROW
		{return Rectangle(point.x + size.x - size_.x, point.y, size_);}


	Z_CT(CPP11) XY<T> center() const Z_NOTHROW
		{return point + size / T(2);}


	Z_CT(CPP11) XY<T> center(T (* round)(T)) const Z_NOTHROW
		{return XY<T>(round(point.x + size.x / T(2)), round(point.y + size.y / T(2)));}


	Z_CT(CPP11) Rectangle center(const XY<T> &size_) const Z_NOTHROW
		{return Rectangle(point + (size - size_) / T(2), size_);}


	Z_CT(CPP11) Rectangle center(const XY<T> &size_, T (* round)(T)) const Z_NOTHROW
		{
		return Rectangle
			(round(point.x + (size.x - size_.x) / T(2)),
			 round(point.y + (size.y - size_.y) / T(2)),
			 size);
		}


	Z_CT(CPP11) XY<T> left() const Z_NOTHROW
		{return XY<T>(point.x, point.y + size.y / T(2));}


	Z_CT(CPP11) XY<T> left(T (* round)(T)) const Z_NOTHROW
		{return XY<T>(point.x, round(point.y + size.y / T(2)));}


	Z_CT(CPP11) Rectangle left(const XY<T> &size_) const Z_NOTHROW
		{return Rectangle(point.x, point.y + (size.y - size_.y) / T(2), size_);}


	Z_CT(CPP11) Rectangle left(const XY<T> &size_, T (* round)(T)) const Z_NOTHROW
		{return Rectangle(point.x, round(point.y + (size.y - size_.y) / T(2)), size_);}


	Z_CT(CPP11) XY<T> right() const Z_NOTHROW
		{return XY<T>(point.x + size.x, point.y + size.y / T(2));}


	Z_CT(CPP11) XY<T> right(T (* round)(T)) const Z_NOTHROW
		{return XY<T>(point.x + size.x, round(point.y + size.y / T(2)));}


	Z_CT(CPP11) Rectangle right(const XY<T> &size_) const Z_NOTHROW
		{
		return Rectangle
			(point.x +  size.x - size_.x,
			 point.y + (size.y - size_.y) / T(2),
			 size_);
		}


	Z_CT(CPP11) Rectangle right(const XY<T> &size_, T (* round)(T)) const Z_NOTHROW
		{
		return Rectangle
			(point.x +  size.x - size_.x,
			 round(point.y + (size.y - size_.y) / T(2)),
			 size_);
		}


	Z_CT(CPP11) XY<T> top() const Z_NOTHROW
		{return XY<T>(point.x + size.x / T(2), point.y + size.y);}


	Z_CT(CPP11) XY<T> top(T (* round)(T)) const Z_NOTHROW
		{return XY<T>(round(point.x + size.x / T(2)), point.y + size.y);}


	Z_CT(CPP11) Rectangle top(const XY<T> &size_) const Z_NOTHROW
		{
		return Rectangle
			(point.x + (size.x - size_.x) / T(2),
			 point.y +  size.y - size_.y,
			 size_);
		}


	Z_CT(CPP11) Rectangle top(const XY<T> &size_, T (* round)(T)) const Z_NOTHROW
		{
		return Rectangle
			(round(point.x + (size.x - size_.x) / T(2)),
			 point.y +  size.y - size_.y,
			 size_);
		}


	Z_CT(CPP11) XY<T> top_left() const Z_NOTHROW
		{return XY<T>(point.x, point.y + size.y);}


	Z_CT(CPP11) Rectangle top_left(const XY<T> &size_) const Z_NOTHROW
		{return Rectangle(point.x, point.y + size.y - size_.y, size_);}


	Z_CT(CPP11) XY<T> top_right() const Z_NOTHROW
		{return point + size;}


	Z_CT(CPP11) Rectangle top_right(const XY<T> &size_) const Z_NOTHROW
		{return Rectangle(point + size - size_, size_);}








	Z_CT(CPP11) Rectangle bottom_half() const Z_NOTHROW
		{return Rectangle(point, size.x, size.y / T(2));}


	Z_CT(CPP11) Rectangle bottom_left_quarter() const Z_NOTHROW
		{return Rectangle(point, size / T(2));}








	Z_CT(CPP11) Boolean contains(const Rectangle &other) const Z_NOTHROW
		{
		return	!other.size.has_zero()		  &&
			other.point		 >= point &&
			other.point + other.size <= point + size;
		}


	/*Z_CT(CPP11) Boolean contains(const AABR<T> &aabr) const
		{
		return	aabr.a.x != aabr.b.x &&
			aabr.a.y != aabr.b.y &&
			aabr.a	 >= point    &&
			aabr.b	 <= point + size;
		}*/


	Z_CT(CPP11) Boolean contains(const XY<T> &point) const Z_NOTHROW
		{return point >= this->point && point < this->point + this->size;}


	Z_INLINE Rectangle &correct() Z_NOTHROW
		{
		if (size.x < T(0)) point.x -= (size.x = -size.x);
		if (size.y < T(0)) point.y -= (size.y = -size.y);
		return *this;
		}


	Z_CT(CPP14) Rectangle fit_in_bottom_center(const XY<T> &size) const Z_NOTHROW
		{
		XY<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x + (this->size.x - fitting_size.x) / T(2), this->point.y,
			 fitting_size);
		}


	Z_CT(CPP11) Rectangle fit_in_bottom_left(const XY<T> &size) const Z_NOTHROW
		{return Rectangle(this->point, size.fit(this->size));}


	Z_CT(CPP14) Rectangle fit_in_bottom_right(const XY<T> &size) const Z_NOTHROW
		{
		XY<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x + this->size.x - fitting_size.x, this->point.y,
			 fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_in_center(const XY<T> &size) const Z_NOTHROW
		{
		XY<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point + (this->size - fitting_size) / T(2),
			 fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_in_center_left(const XY<T> &size) const Z_NOTHROW
		{
		XY<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x, this->point.y + (this->size.y - fitting_size.y) / T(2),
			 fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_in_center_right(const XY<T> &size) const Z_NOTHROW
		{
		XY<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x +  this->size.x - fitting_size.x,
			 this->point.y + (this->size.y - fitting_size.y) / T(2),
			 fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_in_top_center(const XY<T> &size) const Z_NOTHROW
		{
		XY<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x + (this->size.x - fitting_size.x) / T(2),
			 this->point.y +  this->size.y - fitting_size.y,
			 fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_in_top_left(const XY<T> &size) const Z_NOTHROW
		{
		XY<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x, this->point.y + this->size.y - fitting_size.y,
			 fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_in_top_right(const XY<T> &size) const Z_NOTHROW
		{
		XY<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point + this->size - fitting_size,
			 fitting_size);
		}


	Z_CT(CPP11) Rectangle grow_from_bottom_center(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x - delta.x / T(2), point.y, size + delta);}


	Z_CT(CPP11) Rectangle grow_from_bottom_left(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point, size + delta);}


	Z_CT(CPP11) Rectangle grow_from_bottom_right(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x - delta.x, point.y, size + delta);}


	Z_CT(CPP11) Rectangle grow_from_center(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point - delta / T(2), size + delta);}


	Z_CT(CPP11) Rectangle grow_from_center_left(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y - delta.y / T(2), size + delta);}


	Z_CT(CPP11) Rectangle grow_from_center_right(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x - delta.x, point.y - delta.y / T(2), size + delta);}


	Z_CT(CPP11) Rectangle grow_from_top_center(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x - delta.x / T(2), point.y - delta.y, size + delta);}


	Z_CT(CPP11) Rectangle grow_from_top_left(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y - delta.y, size + delta);}


	Z_CT(CPP11) Rectangle grow_from_top_right(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point - delta, size + delta);}


	Z_CT(CPP11) Rectangle grow_in_x_from_center(T delta) const Z_NOTHROW
		{return Rectangle(point.x - delta / T(2), point.y, size.x + delta, size.y);}


	Z_CT(CPP11) Rectangle grow_in_x_from_left(T delta) const Z_NOTHROW
		{return Rectangle(point, size.x + delta, size.y);}


	Z_CT(CPP11) Rectangle grow_in_x_from_right(T delta) const Z_NOTHROW
		{return Rectangle(point.x - delta, point.y, size.x + delta, size.y);}


	Z_CT(CPP11) Rectangle grow_in_y_from_bottom(T delta) const Z_NOTHROW
		{return Rectangle(point, size.x, size.y + delta);}


	Z_CT(CPP11) Rectangle grow_in_y_from_center(T delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y - delta / T(2), size.x, size.y + delta);}


	Z_CT(CPP11) Rectangle grow_in_y_from_top(T delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y - delta, size.x, size.y + delta);}


	Z_CT(CPP11) Boolean intersects(const Rectangle &other) const Z_NOTHROW
		{
		return	!size.has_zero()		 &&
			!other.size.has_zero()		 &&
			other.point + other.size > point &&
			other.point		 < point + size;
		}


	Z_CT(CPP11) Boolean is_zero() const Z_NOTHROW
		{return point.is_zero() && size.is_zero();}


	Z_CT(CPP11) Rectangle left_half	() const Z_NOTHROW
		{return Rectangle(point, size.x / T(2), size.y);}


	Z_CT(CPP11) T maximum_x() const Z_NOTHROW
		{return point.x + size.x;}


	Z_CT(CPP11) T maximum_y() const Z_NOTHROW
		{return point.y + size.y;}


	Z_CT(CPP11) T middle_x() const Z_NOTHROW
		{return point.x + size.x / T(2);}


	Z_CT(CPP11) T middle_y() const Z_NOTHROW
		{return point.y + size.y / T(2);}


	Z_CT(CPP11) T minimum_x() const Z_NOTHROW
		{return point.x;}


	Z_CT(CPP11) T minimum_y() const Z_NOTHROW
		{return point.y;}


	Z_CT(CPP11) Rectangle shrink_from_bottom_center(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x + delta.x / T(2), point.y, size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_bottom_left(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point, size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_bottom_right(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x + delta.x, point.y, size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_center(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point + delta / T(2), size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_center_left(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y + delta.y / T(2), size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_center_right(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x + delta.x, point.y + delta.y / T(2), size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_top_center(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x + delta.x / T(2), point.y + delta.y, size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_top_left(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y + delta.y, size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_top_right(const XY<T> &delta) const Z_NOTHROW
		{return Rectangle(point + delta, size - delta);}


	Z_CT(CPP11) Rectangle shrink_in_x_from_center(T delta) const Z_NOTHROW
		{return Rectangle(point.x + delta / T(2), point.y, size.x - delta, size.y);}


	Z_CT(CPP11) Rectangle shrink_in_x_from_left(T delta) const Z_NOTHROW
		{return Rectangle(point, size.x - delta, size.y);}


	Z_CT(CPP11) Rectangle shrink_in_x_from_right(T delta) const Z_NOTHROW
		{return Rectangle(point.x + delta, point.y, size.x  - delta, size.y);}


	Z_CT(CPP11) Rectangle shrink_in_y_from_bottom(T delta) const Z_NOTHROW
		{return Rectangle(point, size.x, size.y - delta);}


	Z_CT(CPP11) Rectangle shrink_in_y_from_center(T delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y + delta / T(2), size.x, size.y - delta);}


	Z_CT(CPP11) Rectangle shrink_in_y_from_top(T delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y + delta, size.x, size.y - delta);}

























	Z_CT(CPP11) XY<T> absolute_point_to_unit(const XY<T> &point) const Z_NOTHROW
		{return (point - this->point) / this->size;}


	Z_CT(CPP11) Rectangle bottom_right_quarter() const Z_NOTHROW
		{return Rectangle(point.x + size.x / T(2), point.y, size / T(2));}


	/*Z_CT(CPP11) Boolean contains(const Circle<T> &circle) const
		{
		return	circle.radius != T(0)		      &&
			circle.point - circle.radius >= point &&
			circle.point + circle.radius <= point + size;
		}*/


	/*Z_CT(CPP11) Circle<T> inner_circle() const
		{return Circle<T>(center(), size.inner_minimum() / T(2));}*/


	Z_CT(CPP11) Rectangle right_half() const Z_NOTHROW
		{return Rectangle(point.x + size.x / T(2), point.y, size.x / T(2), size.y);}


	Z_CT(CPP11) Rectangle top_half() const Z_NOTHROW
		{return Rectangle(point.x, point.y + size.y / T(2), size.x, size.y / T(2));}


	Z_CT(CPP11) Rectangle top_left_quarter() const Z_NOTHROW
		{return Rectangle(point.x, point.y + size.y / T(2), size / T(2));}


	Z_CT(CPP11) Rectangle top_right_quarter() const Z_NOTHROW
		{return Rectangle(point + size / T(2), size / T(2));}


	Z_CT(CPP11) XY<T> unit_point_to_absolute(const XY<T> &point) const Z_NOTHROW
		{return point * size + point;}
};}


#undef Z_IMPLEMENTATION__APPLE_CONSTRUCTOR
#undef Z_IMPLEMENTATION__APPLE_OPERATOR
#undef Z_IMPLEMENTATION__CG_GEOMETRY
#undef Z_IMPLEMENTATION__NS_GEOMETRY
#undef Z_IMPLEMENTATION__COCOS2D_X
#undef Z_IMPLEMENTATION__COMMON

#endif // Z_classes_Rectangle_HPP
