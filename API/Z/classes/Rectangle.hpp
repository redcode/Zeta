/* Zeta API - Z/classes/Rectangle.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Rectangle_HPP
#define Z_classes_Rectangle_HPP

#include <Z/classes/XY.hpp>

#ifdef Z_WITH_COCOS2D_X
#	include "cocos2d.h"
#endif

#ifdef Z_WITH_CORE_FOUNDATION
#	include <CoreGraphics/CGGeometry.h>
#endif

#if defined(Z_WITH_FOUNDATION) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
#	import <Foundation/NSGeometry.h>
#endif

#ifdef Z_WITH_QT
#	include <QRect>
#endif


namespace Zeta {template <class t> struct Rectangle {
	XY<t> point, size;


	Z_INLINE Rectangle() Z_NOTHROW
		Z_DEFAULTED({})


	Z_CT(CPP11) Rectangle(const XY<t> &point_, const XY<t> &size_) Z_NOTHROW
	: point(point_), size(size_) {}


	Z_CT(CPP11) Rectangle(const XY<t> &point_, t size_x, t size_y) Z_NOTHROW
	: point(point_), size(size_x, size_y) {}


	Z_CT(CPP11) Rectangle(const XY<t> &point_, t size_xy) Z_NOTHROW
	: point(point_), size(size_xy) {}


	Z_CT(CPP11) Rectangle(t point_x, t point_y, const XY<t> &size_) Z_NOTHROW
	: point(point_x, point_y), size(size_) {}


	Z_CT(CPP11) Rectangle(t point_x, t point_y, t size_x, t size_y) Z_NOTHROW
	: point(point_x, point_y), size(size_x, size_y) {}


	Z_CT(CPP11) Rectangle(t point_x, t point_y, t size_xy) Z_NOTHROW
	: point(point_x, point_y), size(size_xy) {}


	Z_CT(CPP11) Rectangle(t point_xy, const XY<t> &size_) Z_NOTHROW
	: point(point_xy), size(size_) {}


	Z_CT(CPP11) Rectangle(const XY<t> &size_) Z_NOTHROW
	: point(t(0)), size(size_) {}


	Z_CT(CPP11) Rectangle(t size_x, t size_y) Z_NOTHROW
	: point(t(0)), size(size_x, size_y) {}


	Z_CT(CPP11) Rectangle(t size_xy) Z_NOTHROW
	: point(t(0)), size(size_xy) {}


#	if	Z_DIALECT_HAS(CPP98, SFINAE) && \
		Z_DIALECT_HAS(CPP11, DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE)

		template <class other_t, class e = typename TypeIf<!TypeIsSame<t, other_t>::value>::type>
		Z_CT(CPP11) Rectangle(const Rectangle<other_t> &other) Z_NOTHROW
		: point(other.point), size(other.size) {}
#	endif


	static Z_CT(CPP14) Rectangle from_vertices(const XY<t> &a, const XY<t> &b) Z_NOTHROW
		{
		XY<t> minimum = a.minimum(b);

		return Rectangle(minimum, a.maximum(b) - minimum);
		}


	Z_CT(CPP11) operator Boolean() const Z_NOTHROW
		{return point || size;}


	friend Z_CT(CPP11) Boolean operator ==(const Rectangle &lhs, const Rectangle &rhs) Z_NOTHROW
		{return lhs.point == rhs.point && lhs.size == rhs.size;}


	friend Z_CT(CPP11) Boolean operator !=(const Rectangle &lhs, const Rectangle &rhs) Z_NOTHROW
		{return lhs.point != rhs.point || lhs.size != rhs.size;}


	friend Z_CT(CPP14) Rectangle operator &(const Rectangle &lhs, const Rectangle &rhs) Z_NOTHROW
		{
		t x1, x2, y1, y2;

		return	(x1 = maximum<t>(lhs.point.x,		   rhs.point.x)) <
			(x2 = minimum<t>(lhs.point.x + lhs.size.x, rhs.point.x + rhs.size.x)) &&
			(y1 = maximum<t>(lhs.point.y,		   rhs.point.y)) <
			(y2 = minimum<t>(lhs.point.y + lhs.size.y, rhs.point.y + rhs.size.y))

			? Rectangle(x1, y1, x2 - x1, y2 - y1)
			: Rectangle(t(0));
		}


	friend Z_CT(CPP14) Rectangle operator |(const Rectangle &lhs, const Rectangle &rhs) Z_NOTHROW
		{
		Rectangle result;

		result.point = lhs.point.minimum(rhs.point);
		result.size  = (lhs.point + lhs.size).maximum(rhs.point + rhs.size) - result.point;
		return result;
		}


	friend Z_CT(CPP11) Rectangle operator +(const Rectangle &lhs, const XY<t> &rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size + rhs);}


	friend Z_CT(CPP11) Rectangle operator +(const XY<t> &lhs, const Rectangle &rhs) Z_NOTHROW
		{return Rectangle(rhs.point, rhs.size + lhs);}


	friend Z_CT(CPP11) Rectangle operator +(const Rectangle &lhs, t rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size + rhs);}


	friend Z_CT(CPP11) Rectangle operator +(t lhs, const Rectangle &rhs) Z_NOTHROW
		{return Rectangle(rhs.point, rhs.size + lhs);}


	friend Z_CT(CPP11) Rectangle operator -(const Rectangle &lhs, const XY<t> &rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size - rhs);}


	friend Z_CT(CPP11) Rectangle operator -(const Rectangle &lhs, t rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size - rhs);}


	friend Z_CT(CPP11) Rectangle operator *(const Rectangle &lhs, const XY<t> &rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size * rhs);}


	friend Z_CT(CPP11) Rectangle operator *(const XY<t> &lhs, const Rectangle &rhs) Z_NOTHROW
		{return Rectangle(rhs.point, rhs.size * lhs);}


	friend Z_CT(CPP11) Rectangle operator *(const Rectangle &lhs, t rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size * rhs);}


	friend Z_CT(CPP11) Rectangle operator *(t lhs, const Rectangle &rhs) Z_NOTHROW
		{return Rectangle(rhs.point, rhs.size * lhs);}


	friend Z_CT(CPP11) Rectangle operator /(const Rectangle &lhs, const XY<t> &rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size / rhs);}


	friend Z_CT(CPP11) Rectangle operator /(const Rectangle &lhs, t rhs) Z_NOTHROW
		{return Rectangle(lhs.point, lhs.size / rhs);}


	Z_INLINE Rectangle &operator &=(const Rectangle &rhs) Z_NOTHROW {return *this = *this & rhs;}
	Z_INLINE Rectangle &operator |=(const Rectangle &rhs) Z_NOTHROW {return *this = *this | rhs;}

	Z_INLINE Rectangle &operator +=(const XY<t> &rhs) Z_NOTHROW {return *this = *this + rhs;}
	Z_INLINE Rectangle &operator -=(const XY<t> &rhs) Z_NOTHROW {return *this = *this - rhs;}
	Z_INLINE Rectangle &operator *=(const XY<t> &rhs) Z_NOTHROW {return *this = *this * rhs;}
	Z_INLINE Rectangle &operator /=(const XY<t> &rhs) Z_NOTHROW {return *this = *this / rhs;}

	Z_INLINE Rectangle &operator +=(t rhs) Z_NOTHROW {return *this = *this + rhs;}
	Z_INLINE Rectangle &operator -=(t rhs) Z_NOTHROW {return *this = *this - rhs;}
	Z_INLINE Rectangle &operator *=(t rhs) Z_NOTHROW {return *this = *this * rhs;}
	Z_INLINE Rectangle &operator /=(t rhs) Z_NOTHROW {return *this = *this / rhs;}


	Z_CT(CPP11) XY<t> bottom() const Z_NOTHROW
		{return XY<t>(point.x + size.x / t(2), point.y);}


	Z_CT(CPP11) XY<t> bottom(t (* round)(t)) const Z_NOTHROW
		{return XY<t>(round(point.x + size.x / t(2)), point.y);}


	Z_CT(CPP11) Rectangle bottom(const XY<t> &size_) const Z_NOTHROW
		{return Rectangle(point.x + (size.x - size_.x) / t(2), point.y, size_);}


	Z_CT(CPP11) Rectangle bottom(const XY<t> &size_, t (* round)(t)) const Z_NOTHROW
		{return Rectangle(round(point.x + (size.x - size_.x) / t(2)), point.y, size_);}


	Z_CT(CPP11) XY<t> bottom_left() const Z_NOTHROW
		{return point;}


	Z_CT(CPP11) Rectangle bottom_left(const XY<t> &size_) const Z_NOTHROW
		{return Rectangle(point, size_);}


	Z_CT(CPP11) XY<t> bottom_right() const Z_NOTHROW
		{return XY<t>(point.x + size.x, point.y);}


	Z_CT(CPP11) Rectangle bottom_right(const XY<t> &size_) const Z_NOTHROW
		{return Rectangle(point.x + size.x - size_.x, point.y, size_);}


	Z_CT(CPP11) XY<t> center() const Z_NOTHROW
		{return point + size / t(2);}


	Z_CT(CPP11) XY<t> center(t (* round)(t)) const Z_NOTHROW
		{return XY<t>(round(point.x + size.x / t(2)), round(point.y + size.y / t(2)));}


	Z_CT(CPP11) Rectangle center(const XY<t> &size_) const Z_NOTHROW
		{return Rectangle(point + (size - size_) / t(2), size_);}


	Z_CT(CPP11) Rectangle center(const XY<t> &size_, t (* round)(t)) const Z_NOTHROW
		{
		return Rectangle(
			round(point.x + (size.x - size_.x) / t(2)),
			round(point.y + (size.y - size_.y) / t(2)),
			size);
		}


	Z_CT(CPP11) XY<t> left() const Z_NOTHROW
		{return XY<t>(point.x, point.y + size.y / t(2));}


	Z_CT(CPP11) XY<t> left(t (* round)(t)) const Z_NOTHROW
		{return XY<t>(point.x, round(point.y + size.y / t(2)));}


	Z_CT(CPP11) Rectangle left(const XY<t> &size_) const Z_NOTHROW
		{return Rectangle(point.x, point.y + (size.y - size_.y) / t(2), size_);}


	Z_CT(CPP11) Rectangle left(const XY<t> &size_, t (* round)(t)) const Z_NOTHROW
		{return Rectangle(point.x, round(point.y + (size.y - size_.y) / t(2)), size_);}


	Z_CT(CPP11) XY<t> right() const Z_NOTHROW
		{return XY<t>(point.x + size.x, point.y + size.y / t(2));}


	Z_CT(CPP11) XY<t> right(t (* round)(t)) const Z_NOTHROW
		{return XY<t>(point.x + size.x, round(point.y + size.y / t(2)));}


	Z_CT(CPP11) Rectangle right(const XY<t> &size_) const Z_NOTHROW
		{
		return Rectangle(
			point.x +  size.x - size_.x,
			point.y + (size.y - size_.y) / t(2),
			size_);
		}


	Z_CT(CPP11) Rectangle right(const XY<t> &size_, t (* round)(t)) const Z_NOTHROW
		{
		return Rectangle(
			point.x +  size.x - size_.x,
			round(point.y + (size.y - size_.y) / t(2)),
			size_);
		}


	Z_CT(CPP11) XY<t> top() const Z_NOTHROW
		{return XY<t>(point.x + size.x / t(2), point.y + size.y);}


	Z_CT(CPP11) XY<t> top(t (* round)(t)) const Z_NOTHROW
		{return XY<t>(round(point.x + size.x / t(2)), point.y + size.y);}


	Z_CT(CPP11) Rectangle top(const XY<t> &size_) const Z_NOTHROW
		{
		return Rectangle(
			point.x + (size.x - size_.x) / t(2),
			point.y +  size.y - size_.y,
			size_);
		}


	Z_CT(CPP11) Rectangle top(const XY<t> &size_, t (* round)(t)) const Z_NOTHROW
		{
		return Rectangle(
			round(point.x + (size.x - size_.x) / t(2)),
			point.y +  size.y - size_.y,
			size_);
		}


	Z_CT(CPP11) XY<t> top_left() const Z_NOTHROW
		{return XY<t>(point.x, point.y + size.y);}


	Z_CT(CPP11) Rectangle top_left(const XY<t> &size_) const Z_NOTHROW
		{return Rectangle(point.x, point.y + size.y - size_.y, size_);}


	Z_CT(CPP11) XY<t> top_right() const Z_NOTHROW
		{return point + size;}


	Z_CT(CPP11) Rectangle top_right(const XY<t> &size_) const Z_NOTHROW
		{return Rectangle(point + size - size_, size_);}








	Z_CT(CPP11) Rectangle bottom_half() const Z_NOTHROW
		{return Rectangle(point, size.x, size.y / t(2));}


	Z_CT(CPP11) Rectangle bottom_left_quarter() const Z_NOTHROW
		{return Rectangle(point, size / t(2));}








	Z_CT(CPP11) Boolean contains(const Rectangle &other) const Z_NOTHROW
		{
		return	!other.size.has_zero()		  &&
			other.point		 >= point &&
			other.point + other.size <= point + size;
		}


	Z_CT(CPP11) Boolean contains(const XY<t> &point_) const Z_NOTHROW
		{return point_ >= point && point_ < point + size;}


	Z_INLINE Rectangle &correct() Z_NOTHROW
		{
		if (size.x < t(0)) point.x -= (size.x = -size.x);
		if (size.y < t(0)) point.y -= (size.y = -size.y);
		return *this;
		}


	Z_CT(CPP14) Rectangle fit_bottom(const XY<t> &size_) const Z_NOTHROW
		{
		XY<t> fitting_size = size_.fit(size);

		return Rectangle(point.x + (size.x - fitting_size.x) / t(2), point.y, fitting_size);
		}


	Z_CT(CPP11) Rectangle fit_bottom_left(const XY<t> &size_) const Z_NOTHROW
		{return Rectangle(point, size_.fit(size));}


	Z_CT(CPP14) Rectangle fit_bottom_right(const XY<t> &size_) const Z_NOTHROW
		{
		XY<t> fitting_size = size_.fit(size);

		return Rectangle(point.x + size.x - fitting_size.x, point.y, fitting_size);
		}


	Z_CT(CPP14) Rectangle fit(const XY<t> &size_) const Z_NOTHROW
		{
		XY<t> fitting_size = size_.fit(size);

		return Rectangle(point + (size - fitting_size) / t(2), fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_left(const XY<t> &size_) const Z_NOTHROW
		{
		XY<t> fitting_size = size_.fit(size);

		return Rectangle(point.x, point.y + (size.y - fitting_size.y) / t(2), fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_right(const XY<t> &size_) const Z_NOTHROW
		{
		XY<t> fitting_size = size_.fit(size);

		return Rectangle(
			point.x +  size.x - fitting_size.x,
			point.y + (size.y - fitting_size.y) / t(2),
			fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_top(const XY<t> &size_) const Z_NOTHROW
		{
		XY<t> fitting_size = size_.fit(size);

		return Rectangle(
			point.x + (size.x - fitting_size.x) / t(2),
			point.y +  size.y - fitting_size.y,
			fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_top_left(const XY<t> &size_) const Z_NOTHROW
		{
		XY<t> fitting_size = size_.fit(size);

		return Rectangle(point.x, point.y + size.y - fitting_size.y, fitting_size);
		}


	Z_CT(CPP14) Rectangle fit_top_right(const XY<t> &size_) const Z_NOTHROW
		{
		XY<t> fitting_size = size_.fit(size);

		return Rectangle(point + size - fitting_size, fitting_size);
		}


	Z_CT(CPP11) Rectangle grow_from_bottom_center(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x - delta.x / t(2), point.y, size + delta);}


	Z_CT(CPP11) Rectangle grow_from_bottom_left(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point, size + delta);}


	Z_CT(CPP11) Rectangle grow_from_bottom_right(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x - delta.x, point.y, size + delta);}


	Z_CT(CPP11) Rectangle grow_from_center(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point - delta / t(2), size + delta);}


	Z_CT(CPP11) Rectangle grow_from_center_left(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y - delta.y / t(2), size + delta);}


	Z_CT(CPP11) Rectangle grow_from_center_right(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x - delta.x, point.y - delta.y / t(2), size + delta);}


	Z_CT(CPP11) Rectangle grow_from_top_center(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x - delta.x / t(2), point.y - delta.y, size + delta);}


	Z_CT(CPP11) Rectangle grow_from_top_left(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y - delta.y, size + delta);}


	Z_CT(CPP11) Rectangle grow_from_top_right(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point - delta, size + delta);}


	Z_CT(CPP11) Rectangle grow_in_x_from_center(t delta) const Z_NOTHROW
		{return Rectangle(point.x - delta / t(2), point.y, size.x + delta, size.y);}


	Z_CT(CPP11) Rectangle grow_in_x_from_left(t delta) const Z_NOTHROW
		{return Rectangle(point, size.x + delta, size.y);}


	Z_CT(CPP11) Rectangle grow_in_x_from_right(t delta) const Z_NOTHROW
		{return Rectangle(point.x - delta, point.y, size.x + delta, size.y);}


	Z_CT(CPP11) Rectangle grow_in_y_from_bottom(t delta) const Z_NOTHROW
		{return Rectangle(point, size.x, size.y + delta);}


	Z_CT(CPP11) Rectangle grow_in_y_from_center(t delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y - delta / t(2), size.x, size.y + delta);}


	Z_CT(CPP11) Rectangle grow_in_y_from_top(t delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y - delta, size.x, size.y + delta);}


	Z_CT(CPP11) Boolean intersects(const Rectangle &other) const Z_NOTHROW
		{
		return	!size.has_zero()		 &&
			!other.size.has_zero()		 &&
			other.point + other.size > point &&
			other.point < point + size;
		}


	Z_CT(CPP11) Boolean is_zero() const Z_NOTHROW
		{return point.is_zero() && size.is_zero();}


	Z_CT(CPP11) Rectangle left_half	() const Z_NOTHROW
		{return Rectangle(point, size.x / t(2), size.y);}


	Z_CT(CPP11) t maximum_x() const Z_NOTHROW {return point.x + size.x;}
	Z_CT(CPP11) t maximum_y() const Z_NOTHROW {return point.y + size.y;}
	Z_CT(CPP11) t middle_x () const Z_NOTHROW {return point.x + size.x / t(2);}
	Z_CT(CPP11) t middle_y () const Z_NOTHROW {return point.y + size.y / t(2);}
	Z_CT(CPP11) t minimum_x() const Z_NOTHROW {return point.x;}
	Z_CT(CPP11) t minimum_y() const Z_NOTHROW {return point.y;}


	Z_CT(CPP11) Rectangle shrink_from_bottom_center(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x + delta.x / t(2), point.y, size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_bottom_left(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point, size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_bottom_right(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x + delta.x, point.y, size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_center(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point + delta / t(2), size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_center_left(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y + delta.y / t(2), size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_center_right(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x + delta.x, point.y + delta.y / t(2), size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_top_center(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x + delta.x / t(2), point.y + delta.y, size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_top_left(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y + delta.y, size - delta);}


	Z_CT(CPP11) Rectangle shrink_from_top_right(const XY<t> &delta) const Z_NOTHROW
		{return Rectangle(point + delta, size - delta);}


	Z_CT(CPP11) Rectangle shrink_in_x_from_center(t delta) const Z_NOTHROW
		{return Rectangle(point.x + delta / t(2), point.y, size.x - delta, size.y);}


	Z_CT(CPP11) Rectangle shrink_in_x_from_left(t delta) const Z_NOTHROW
		{return Rectangle(point, size.x - delta, size.y);}


	Z_CT(CPP11) Rectangle shrink_in_x_from_right(t delta) const Z_NOTHROW
		{return Rectangle(point.x + delta, point.y, size.x  - delta, size.y);}


	Z_CT(CPP11) Rectangle shrink_in_y_from_bottom(t delta) const Z_NOTHROW
		{return Rectangle(point, size.x, size.y - delta);}


	Z_CT(CPP11) Rectangle shrink_in_y_from_center(t delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y + delta / t(2), size.x, size.y - delta);}


	Z_CT(CPP11) Rectangle shrink_in_y_from_top(t delta) const Z_NOTHROW
		{return Rectangle(point.x, point.y + delta, size.x, size.y - delta);}

























	Z_CT(CPP11) XY<t> absolute_point_to_unit(const XY<t> &point_) const Z_NOTHROW
		{return (point_ - point) / size;}


	Z_CT(CPP11) Rectangle bottom_right_quarter() const Z_NOTHROW
		{return Rectangle(point.x + size.x / t(2), point.y, size / t(2));}


	Z_CT(CPP11) Rectangle right_half() const Z_NOTHROW
		{return Rectangle(point.x + size.x / t(2), point.y, size.x / t(2), size.y);}


	Z_CT(CPP11) Rectangle top_half() const Z_NOTHROW
		{return Rectangle(point.x, point.y + size.y / t(2), size.x, size.y / t(2));}


	Z_CT(CPP11) Rectangle top_left_quarter() const Z_NOTHROW
		{return Rectangle(point.x, point.y + size.y / t(2), size / t(2));}


	Z_CT(CPP11) Rectangle top_right_quarter() const Z_NOTHROW
		{return Rectangle(point + size / t(2), size / t(2));}


	Z_CT(CPP11) XY<t> unit_point_to_absolute(const XY<t> &point_) const Z_NOTHROW
		{return point + point_ * size;}



#	ifdef Z_WITH_COCOS2D_X

		Z_INLINE Rectangle(const cocos2d::Rect &rectangle)
		: point(rectangle.origin), size(rectangle.size) {}


		Z_INLINE operator cocos2d::Rect() const
			{return cocos2d::Rect(float(point.x), float(point.y), float(size.x),  float(size.y));}

#	endif


#	if defined(Z_WITH_CORE_FOUNDATION) || defined(Z_WITH_FOUNDATION)

#		define Z_z_APPLE_CONSTRUCTORS(Prefix)				       \
										       \
			Z_CT(CPP11) Rectangle(const Prefix##Rect &rectangle) Z_NOTHROW \
			: point(rectangle.origin), size(rectangle.size) {}	       \
										       \
										       \
			Z_CT(CPP11) Rectangle(const Prefix##Point &point_) Z_NOTHROW   \
			: point(t(0)), size(point_) {}				       \
										       \
										       \
			Z_CT(CPP11) Rectangle(const Prefix##Size &size_) Z_NOTHROW     \
			: point(t(0)), size(size_) {}


#		if Z_DIALECT_HAS(CPP11, COPY_LIST_INITIALIZATION)

#			define Z_z_APPLE_OPERATORS(Prefix)			      \
										      \
				Z_CT(CPP11) operator Prefix##Rect() const Z_NOTHROW   \
					{					      \
					return {{CGFloat(point.x), CGFloat(point.y)}, \
						{CGFloat(size.x),  CGFloat(size.y)}}; \
					}

#		else
#			define Z_z_APPLE_OPERATORS(Prefix)			      \
										      \
				Z_CT(CPP14) operator Prefix##Rect() const Z_NOTHROW   \
					{					      \
					Prefix##Rect result = {			      \
						{CGFloat(point.x), CGFloat(point.y)}, \
						{CGFloat(size.x),  CGFloat(size.y)}}; \
										      \
					return result;				      \
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


#	ifdef Z_WITH_QT

		Z_CT(CPP11) Rectangle(const QRect &rectangle) Z_NOTHROW
		: point(rectangle.topLeft()), size(rectangle.size()) {}


		Z_CT(CPP11) Rectangle(const QPoint &point_) Z_NOTHROW
		: point(t(0)), size(point) {}


		Z_CT(CPP11) Rectangle(const QSize &size_) Z_NOTHROW
		: point(t(0)), size(size_) {}


		Z_CT(CPP11) operator QRect() const Z_NOTHROW
			{return QRect(int(point.x), int(point.y), int(size.x), int(size.y));}

#	endif
};}


#endif // Z_classes_Rectangle_HPP
