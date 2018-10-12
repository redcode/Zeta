/* Z Kit - classes/mathematics/geometry/euclidean/Rectangle.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_mathematics_geometry_euclidean_Rectangle_HPP_
#define _Z_classes_mathematics_geometry_euclidean_Rectangle_HPP_

#include <Z/classes/base/Value2D.hpp>
#include <Z/types/mathematics.h>


#define Z_IMPLEMENTATION_FOUNDATION_CONSTRUCTOR(Prefix)						\
Z_CT(CPP11) Rectangle(const Prefix##Rect &rectangle)						\
: point(rectangle.origin), size(rectangle.size) {}


#if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)

#	define Z_IMPLEMENTATION_FOUNDATION_OPERATOR(Prefix)					\
												\
	Z_CT(CPP11) operator Prefix##Rect() const						\
		{										\
		return {{CGFloat(point.x), CGFloat(point.y)},					\
			{CGFloat(size.x),  CGFloat(size.y)}};					\
		}

#else

#	define Z_IMPLEMENTATION_FOUNDATION_OPERATOR(Prefix)					\
												\
	Z_CT(CPP14) operator Prefix##Rect() const						\
		{										\
		CGRect result = {								\
			{CGFloat(point.x), CGFloat(point.y)},					\
			{CGFloat(size.x),  CGFloat(size.y)}					\
		};										\
												\
		return result;									\
		}

#endif


#ifdef Z_USE_CG_GEOMETRY

#	include <CoreGraphics/CGGeometry.h>

#	define Z_IMPLEMENTATION_CG_GEOMETRY		    \
		Z_IMPLEMENTATION_FOUNDATION_CONSTRUCTOR(CG) \
		Z_IMPLEMENTATION_FOUNDATION_OPERATOR   (CG)

#else
#	define Z_IMPLEMENTATION_CG_GEOMETRY
#endif

#if defined(Z_USE_NS_GEOMETRY) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

#	import <Foundation/NSGeometry.h>

#	if	!defined(Z_USE_CG_GEOMETRY)			    || \
		!defined(NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES) || \
		!NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES

#		define Z_IMPLEMENTATION_NS_GEOMETRY		    \
			Z_IMPLEMENTATION_FOUNDATION_CONSTRUCTOR(NS) \
			Z_IMPLEMENTATION_FOUNDATION_OPERATOR   (NS)

#	endif

#endif

#ifndef Z_IMPLEMENTATION_NS_GEOMETRY
#	define Z_IMPLEMENTATION_NS_GEOMETRY
#endif

#ifdef Z_USE_COCOS2D_X

#	include "cocos2d.h"

#	define Z_IMPLEMENTATION_COCOS2D_X							\
												\
	Z_INLINE Rectangle(const cocos2d::Rect &rectangle)					\
	: point(rectangle.origin), size(rectangle.size) {}					\
												\
												\
	Z_INLINE operator cocos2d::Rect() const							\
		{										\
		return cocos2d::Rect								\
			(float(point.x), float(point.y),					\
			 float(size.x),  float(size.y));					\
		}

#else
#	define Z_IMPLEMENTATION_COCOS2D_X
#endif


#define Z_IMPLEMENTATION_COMMON									\
												\
typedef typename ZTypeFixedSigned(ZRectangle, T) Base;						\
Value2D<T> point, size;										\
												\
Z_INLINE Rectangle() Z_DEFAULTED({})								\
												\
												\
Z_CT(CPP11) Rectangle(const Value2D<T> &point, const Value2D<T> &size)				\
: point(point), size(size) {}									\
												\
												\
Z_CT(CPP11) Rectangle(const Value2D<T> &point, T size_x, T size_y)				\
: point(point), size(size_x, size_y) {}								\
												\
												\
Z_CT(CPP11) Rectangle(const Value2D<T> &point, T size_xy)					\
: point(point), size(size_xy) {}								\
												\
												\
Z_CT(CPP11) Rectangle(T point_x, T point_y, const Value2D<T> &size)				\
: point(point_x, point_y), size(size) {}							\
												\
												\
Z_CT(CPP11) Rectangle(T point_x, T point_y, T size_x, T size_y)					\
: point(point_x, point_y), size(size_x, size_y) {}						\
												\
												\
Z_CT(CPP11) Rectangle(T point_x, T point_y, T size_xy)						\
: point(point_x, point_y), size(size_xy) {}							\
												\
												\
Z_CT(CPP11) Rectangle(T point_xy, const Value2D<T> &size)					\
: point(point_xy), size(size) {}								\
												\
												\
Z_CT(CPP11) Rectangle(const Value2D<T> &size)							\
: point(T(0)), size(size) {}									\
												\
												\
Z_CT(CPP11) Rectangle(T size_x, T size_y)							\
: point(T(0)), size(size_x, size_y) {}								\
												\
												\
Z_CT(CPP11) Rectangle(T size_xy)								\
: point(T(0)), size(size_xy) {}									\
												\
												\
Z_CT(CPP11) Rectangle(const Base &rectangle)							\
: point(rectangle.point), size(rectangle.size) {}						\
												\
												\
static Z_CT(CPP14) Rectangle from_vertices(const Value2D<T> &a, const Value2D<T> &b)		\
	{											\
	Value2D<T> minimum = a.minimum(b);							\
												\
	return Rectangle(minimum, a.maximum(b) - minimum);					\
	}											\
												\
												\
Z_CT(CPP11) operator Boolean() const {return point || size;}					\
Z_INLINE    operator Base&  () const {return *((Base *)this);}					\
												\
												\
Z_CT(CPP11) Boolean operator ==(const Rectangle &rhs) const					\
	{return point == rhs.point && size == rhs.size;}					\
												\
												\
Z_CT(CPP11) Boolean operator !=(const Rectangle &rhs) const					\
	{return point != rhs.point || size != rhs.size;}					\
												\
												\
/* Intersection */										\
Z_CT(CPP14) Rectangle operator &(const Rectangle &rhs) const					\
	{											\
	T x1, x2, y1, y2;									\
												\
	return	(x1 = maximum<T>(point.x,	   rhs.point.x)) <				\
		(x2 = minimum<T>(point.x + size.x, rhs.point.x + rhs.size.x)) &&		\
		(y1 = maximum<T>(point.y,	   rhs.point.y)) <				\
		(y2 = minimum<T>(point.y + size.y, rhs.point.y + rhs.size.y))			\
												\
		? Rectangle(x1, y1, x2 - x1, y2 - y1)						\
		: Rectangle(T(0));								\
	}											\
												\
												\
/* Union */											\
Z_CT(CPP14) Rectangle operator |(const Rectangle &rhs) const					\
	{											\
	Rectangle result;									\
												\
	result.point = point.minimum(rhs.point);						\
	result.size  = (point + size).maximum(rhs.point + rhs.size) - result.point;		\
	return result;										\
	}											\
												\
												\
Z_INLINE Rectangle &operator &=(const Rectangle &rhs) {return *this = *this & rhs;}		\
Z_INLINE Rectangle &operator |=(const Rectangle &rhs) {return *this = *this | rhs;}		\
												     \
Z_CT(CPP11) Rectangle operator +(const Value2D<T> &rhs) const {return Rectangle(point + rhs, size);} \
Z_CT(CPP11) Rectangle operator -(const Value2D<T> &rhs) const {return Rectangle(point - rhs, size);} \
Z_CT(CPP11) Rectangle operator *(const Value2D<T> &rhs) const {return Rectangle(point * rhs, size);} \
Z_CT(CPP11) Rectangle operator /(const Value2D<T> &rhs) const {return Rectangle(point / rhs, size);} \
												     \
Z_INLINE Rectangle &operator +=(const Value2D<T> &rhs) {return *this = *this + rhs;}		\
Z_INLINE Rectangle &operator -=(const Value2D<T> &rhs) {return *this = *this - rhs;}		\
Z_INLINE Rectangle &operator *=(const Value2D<T> &rhs) {return *this = *this * rhs;}		\
Z_INLINE Rectangle &operator /=(const Value2D<T> &rhs) {return *this = *this / rhs;}		\
												\
Z_CT(CPP11) Rectangle operator +(T rhs) const {return Value2D<T>(point + rhs, size);}		\
Z_CT(CPP11) Rectangle operator -(T rhs) const {return Value2D<T>(point - rhs, size);}		\
Z_CT(CPP11) Rectangle operator *(T rhs) const {return Value2D<T>(point * rhs, size);}		\
Z_CT(CPP11) Rectangle operator /(T rhs) const {return Value2D<T>(point / rhs, size);}		\
												\
Z_INLINE Rectangle &operator +=(T rhs) {return *this = *this + rhs;}				\
Z_INLINE Rectangle &operator -=(T rhs) {return *this = *this - rhs;}				\
Z_INLINE Rectangle &operator *=(T rhs) {return *this = *this * rhs;}				\
Z_INLINE Rectangle &operator /=(T rhs) {return *this = *this / rhs;}				\
												\
Z_IMPLEMENTATION_CG_GEOMETRY									\
Z_IMPLEMENTATION_NS_GEOMETRY									\
Z_IMPLEMENTATION_COCOS2D_X									\
												\
												\
Z_CT(CPP11) Rectangle align_in_bottom_center(const Value2D<T> &size) const			\
	{return Rectangle(this->point.x + (this->size.x - size.x) / T(2), this->point.y, size);}\
												\
												\
Z_CT(CPP11) Rectangle align_in_bottom_left(const Value2D<T> &size) const			\
	{return Rectangle(this->point, size);}							\
												\
												\
Z_CT(CPP11) Rectangle align_in_bottom_right(const Value2D<T> &size) const			\
	{return Rectangle(this->point.x + this->size.x - size.x, this->point.y, size);}		\
												\
												\
Z_CT(CPP11) Rectangle align_in_center(const Value2D<T> &size) const				\
	{return Rectangle(this->point + (this->size - size) / T(2), size);}			\
												\
												\
Z_CT(CPP11) Rectangle align_in_center_left(const Value2D<T> &size) const			\
	{return Rectangle(this->point.x, this->point.y + (this->size.y - size.y) / T(2), size);}\
												\
												\
Z_CT(CPP11) Rectangle align_in_center_right(const Value2D<T> &size) const			\
	{											\
	return Rectangle									\
		(this->point.x +  this->size.x - size.x,					\
		 this->point.y + (this->size.y - size.y) / T(2),				\
		 size);										\
	}											\
												\
												\
Z_CT(CPP11) Rectangle align_in_top_center(const Value2D<T> &size) const				\
	{											\
	return Rectangle									\
		(this->point.x + (this->size.x - size.x) / T(2),				\
		 this->point.y +  this->size.y - size.y,					\
		 size);										\
	}											\
												\
												\
Z_CT(CPP11) Rectangle align_in_top_left(const Value2D<T> &size) const				\
	{return Rectangle(this->point.x, this->point.y + this->size.y - size.y, size);}		\
												\
												\
Z_CT(CPP11) Rectangle align_in_top_right(const Value2D<T> &size) const				\
	{return Rectangle(this->point + this->size - size, size);}				\
												\
												\
Z_CT(CPP11) Value2D<T> bottom_center() const							\
	{return Value2D<T>(point.x + size.x / T(2), point.y);}					\
												\
												\
Z_CT(CPP11) Rectangle bottom_half() const							\
	{return Rectangle(point, size.x, size.y / T(2));}					\
												\
												\
Z_CT(CPP11) Value2D<T> bottom_left() const							\
	{return point;}										\
												\
												\
Z_CT(CPP11) Rectangle bottom_left_quarter() const						\
	{return Rectangle(point, size / T(2));}							\
												\
												\
Z_CT(CPP11) Value2D<T> bottom_right() const							\
	{return Value2D<T>(point.x + size.x, point.y);}						\
												\
												\
Z_CT(CPP11) Value2D<T> center() const								\
	{return point + size / T(2);}								\
												\
												\
Z_CT(CPP11) Value2D<T> center_left() const							\
	{return Value2D<T>(point.x, point.y + size.y / T(2));}					\
												\
												\
Z_CT(CPP11) Value2D<T> center_right() const							\
	{return Value2D<T>(point.x + size.x, point.y + size.y / T(2));}				\
												\
												\
Z_CT(CPP11) Boolean contains(const Rectangle &other) const					\
	{											\
	return	!other.size.has_zero()		  &&						\
		other.point		 >= point &&						\
		other.point + other.size <= point + size;					\
	}											\
												\
												\
/*Z_CT(CPP11) Boolean contains(const AABR<T> &aabr) const					\
	{											\
	return	aabr.a.x != aabr.b.x &&								\
		aabr.a.y != aabr.b.y &&								\
		aabr.a	 >= point    &&								\
		aabr.b	 <= point + size;							\
	}*/											\
												\
												\
Z_CT(CPP11) Boolean contains(const Value2D<T> &point) const					\
	{return point >= this->point && point < this->point + this->size;}			\
												\
												\
Z_INLINE Rectangle &correct()									\
	{											\
	if (size.x < T(0)) point.x -= (size.x = -size.x);					\
	if (size.y < T(0)) point.y -= (size.y = -size.y);					\
	return *this;										\
	}											\
												\
												\
Z_CT(CPP14) Rectangle fit_in_bottom_center(const Value2D<T> &size) const			\
	{											\
	Value2D<T> fitting_size = size.fit(this->size);						\
												\
	return Rectangle									\
		(this->point.x + (this->size.x - fitting_size.x) / T(2), this->point.y,		\
		 fitting_size);									\
	}											\
												\
												\
Z_CT(CPP11) Rectangle fit_in_bottom_left(const Value2D<T> &size) const				\
	{return Rectangle(this->point, size.fit(this->size));}					\
												\
												\
Z_CT(CPP14) Rectangle fit_in_bottom_right(const Value2D<T> &size) const				\
	{											\
	Value2D<T> fitting_size = size.fit(this->size);						\
												\
	return Rectangle									\
		(this->point.x + this->size.x - fitting_size.x, this->point.y, fitting_size);	\
	}											\
												\
												\
Z_CT(CPP14) Rectangle fit_in_center(const Value2D<T> &size) const				\
	{											\
	Value2D<T> fitting_size = size.fit(this->size);						\
												\
	return Rectangle(this->point + (this->size - fitting_size) / T(2), fitting_size);	\
	}											\
												\
												\
Z_CT(CPP14) Rectangle fit_in_center_left(const Value2D<T> &size) const				\
	{											\
	Value2D<T> fitting_size = size.fit(this->size);						\
												\
	return Rectangle									\
		(this->point.x, this->point.y + (this->size.y - fitting_size.y) / T(2),		\
		 fitting_size);									\
	}											\
												\
												\
Z_CT(CPP14) Rectangle fit_in_center_right(const Value2D<T> &size) const				\
	{											\
	Value2D<T> fitting_size = size.fit(this->size);						\
												\
	return Rectangle									\
		(this->point.x +  this->size.x - fitting_size.x,				\
		 this->point.y + (this->size.y - fitting_size.y) / T(2),			\
		 fitting_size);									\
	}											\
												\
												\
Z_CT(CPP14) Rectangle fit_in_top_center(const Value2D<T> &size) const				\
	{											\
	Value2D<T> fitting_size = size.fit(this->size);						\
												\
	return Rectangle									\
		(this->point.x + (this->size.x - fitting_size.x) / T(2),			\
		 this->point.y +  this->size.y - fitting_size.y,				\
		 fitting_size);									\
	}											\
												\
												\
Z_CT(CPP14) Rectangle fit_in_top_left(const Value2D<T> &size) const				\
	{											\
	Value2D<T> fitting_size = size.fit(this->size);						\
												\
	return Rectangle									\
		(this->point.x, this->point.y + this->size.y - fitting_size.y, fitting_size);	\
	}											\
												\
												\
Z_CT(CPP14) Rectangle fit_in_top_right(const Value2D<T> &size) const				\
	{											\
	Value2D<T> fitting_size = size.fit(this->size);						\
												\
	return Rectangle(this->point + this->size - fitting_size, fitting_size);		\
	}											\
												\
												\
Z_CT(CPP11) Rectangle grow_from_bottom_center(const Value2D<T> &delta) const			\
	{return Rectangle(point.x - delta.x / T(2), point.y, size + delta);}			\
												\
												\
Z_CT(CPP11) Rectangle grow_from_bottom_left(const Value2D<T> &delta) const			\
	{return Rectangle(point, size + delta);}						\
												\
												\
Z_CT(CPP11) Rectangle grow_from_bottom_right(const Value2D<T> &delta) const			\
	{return Rectangle(point.x - delta.x, point.y, size + delta);}				\
												\
												\
Z_CT(CPP11) Rectangle grow_from_center(const Value2D<T> &delta) const				\
	{return Rectangle(point - delta / T(2), size + delta);}					\
												\
												\
Z_CT(CPP11) Rectangle grow_from_center_left(const Value2D<T> &delta) const			\
	{return Rectangle(point.x, point.y - delta.y / T(2), size + delta);}			\
												\
												\
Z_CT(CPP11) Rectangle grow_from_center_right(const Value2D<T> &delta) const			\
	{return Rectangle(point.x - delta.x, point.y - delta.y / T(2), size + delta);}		\
												\
												\
Z_CT(CPP11) Rectangle grow_from_top_center(const Value2D<T> &delta) const			\
	{return Rectangle(point.x - delta.x / T(2), point.y - delta.y, size + delta);}		\
												\
												\
Z_CT(CPP11) Rectangle grow_from_top_left(const Value2D<T> &delta) const				\
	{return Rectangle(point.x, point.y - delta.y, size + delta);}				\
												\
												\
Z_CT(CPP11) Rectangle grow_from_top_right(const Value2D<T> &delta) const			\
	{return Rectangle(point - delta, size + delta);}					\
												\
												\
Z_CT(CPP11) Rectangle grow_in_x_from_center(T delta) const					\
	{return Rectangle(point.x - delta / T(2), point.y, size.x + delta, size.y);}		\
												\
												\
Z_CT(CPP11) Rectangle grow_in_x_from_left(T delta) const					\
	{return Rectangle(point, size.x + delta, size.y);}					\
												\
												\
Z_CT(CPP11) Rectangle grow_in_x_from_right(T delta) const					\
	{return Rectangle(point.x - delta, point.y, size.x + delta, size.y);}			\
												\
												\
Z_CT(CPP11) Rectangle grow_in_y_from_bottom(T delta) const					\
	{return Rectangle(point, size.x, size.y + delta);}					\
												\
												\
Z_CT(CPP11) Rectangle grow_in_y_from_center(T delta) const					\
	{return Rectangle(point.x, point.y - delta / T(2), size.x, size.y + delta);}		\
												\
												\
Z_CT(CPP11) Rectangle grow_in_y_from_top(T delta) const						\
	{return Rectangle(point.x, point.y - delta, size.x, size.y + delta);}			\
												\
												\
Z_CT(CPP11) Boolean intersects(const Rectangle &other) const					\
	{											\
	return	!size.has_zero()		 &&						\
		!other.size.has_zero()		 &&						\
		other.point + other.size > point &&						\
		other.point		 < point + size;					\
	}											\
												\
												\
Z_CT(CPP11) Boolean is_zero() const								\
	{return point.is_zero() && size.is_zero();}						\
												\
												\
Z_CT(CPP11) Rectangle left_half	() const							\
	{return Rectangle(point, size.x / T(2), size.y);}					\
												\
												\
Z_CT(CPP11) T maximum_x() const									\
	{return point.x + size.x;}								\
												\
												\
Z_CT(CPP11) T maximum_y() const									\
	{return point.y + size.y;}								\
												\
												\
Z_CT(CPP11) T middle_x() const									\
	{return point.x + size.x / T(2);}							\
												\
												\
Z_CT(CPP11) T middle_y() const									\
	{return point.y + size.y / T(2);}							\
												\
												\
Z_CT(CPP11) T minimum_x()									\
	const {return point.x;}									\
												\
												\
Z_CT(CPP11) T minimum_y()									\
	const {return point.y;}									\
												\
												\
Z_CT(CPP11) Rectangle shrink_from_bottom_center(const Value2D<T> &delta) const			\
	{return Rectangle(point.x + delta.x / T(2), point.y, size - delta);}			\
												\
												\
Z_CT(CPP11) Rectangle shrink_from_bottom_left(const Value2D<T> &delta) const			\
	{return Rectangle(point, size - delta);}						\
												\
												\
Z_CT(CPP11) Rectangle shrink_from_bottom_right(const Value2D<T> &delta) const			\
	{return Rectangle(point.x + delta.x, point.y, size - delta);}				\
												\
												\
Z_CT(CPP11) Rectangle shrink_from_center(const Value2D<T> &delta) const				\
	{return Rectangle(point + delta / T(2), size - delta);}					\
												\
												\
Z_CT(CPP11) Rectangle shrink_from_center_left(const Value2D<T> &delta) const			\
	{return Rectangle(point.x, point.y + delta.y / T(2), size - delta);}			\
												\
												\
Z_CT(CPP11) Rectangle shrink_from_center_right(const Value2D<T> &delta) const			\
	{return Rectangle(point.x + delta.x, point.y + delta.y / T(2), size - delta);}		\
												\
												\
Z_CT(CPP11) Rectangle shrink_from_top_center(const Value2D<T> &delta) const			\
	{return Rectangle(point.x + delta.x / T(2), point.y + delta.y, size - delta);}		\
												\
												\
Z_CT(CPP11) Rectangle shrink_from_top_left(const Value2D<T> &delta) const			\
	{return Rectangle(point.x, point.y + delta.y, size - delta);}				\
												\
												\
Z_CT(CPP11) Rectangle shrink_from_top_right(const Value2D<T> &delta) const			\
	{return Rectangle(point + delta, size - delta);}					\
												\
												\
Z_CT(CPP11) Rectangle shrink_in_x_from_center(T delta) const					\
	{return Rectangle(point.x + delta / T(2), point.y, size.x - delta, size.y);}		\
												\
												\
Z_CT(CPP11) Rectangle shrink_in_x_from_left(T delta) const					\
	{return Rectangle(point, size.x - delta, size.y);}					\
												\
												\
Z_CT(CPP11) Rectangle shrink_in_x_from_right(T delta) const					\
	{return Rectangle(point.x + delta, point.y, size.x  - delta, size.y);}			\
												\
												\
Z_CT(CPP11) Rectangle shrink_in_y_from_bottom(T delta) const					\
	{return Rectangle(point, size.x, size.y - delta);}					\
												\
												\
Z_CT(CPP11) Rectangle shrink_in_y_from_center(T delta) const					\
	{return Rectangle(point.x, point.y + delta / T(2), size.x, size.y - delta);}		\
												\
												\
Z_CT(CPP11) Rectangle shrink_in_y_from_top(T delta) const					\
	{return Rectangle(point.x, point.y + delta, size.x, size.y - delta);}			\
												\
												\
Z_INLINE void swap(Rectangle &other)								\
	{Zeta::swap<Base>((Base *)this, (Base *)&other);}					\
												\
												\
Z_CT(CPP11) Value2D<T> top_center() const							\
	{return Value2D<T>(point.x + size.x / T(2), point.y + size.y);}				\
												\
												\
Z_CT(CPP11) Value2D<T> top_left() const								\
	{return Value2D<T>(point.x, point.y + size.y);}						\
												\
												\
Z_CT(CPP11) Value2D<T> top_right() const							\
	{return point + size;}




namespace Zeta {
	template <class T, UInt T_number_set = Type<T>::number_set> struct Rectangle {};


	template <class T> struct Rectangle<T, Z_NUMBER_SET_Z> {
		Z_IMPLEMENTATION_COMMON


		Z_CT(CPP11) Rectangle bottom_right_quarter() const
			{return Rectangle(point.x + size.x / T(2), point.y, size.x - size.x / T(2), size.y / T(2));}


		Z_CT(CPP11) Rectangle right_half() const
			{return Rectangle(point.x + size.x / T(2), point.y, size.x - size.x / T(2), size.y);}


		Z_CT(CPP11) Rectangle top_half() const
			{return Rectangle(point.x, point.y + size.y / T(2), size.x, size.y - size.y / T(2));}


		Z_CT(CPP11) Rectangle top_left_quarter() const
			{return Rectangle(point.x, point.y + size.y / T(2), size.x / T(2), size.y - size.y / T(2));}


		Z_CT(CPP11) Rectangle top_right_quarter() const
			{return Rectangle(point + size / T(2), size - size / T(2));}
	};


	template <class T> struct Rectangle<T, Z_NUMBER_SET_R> {
		Z_IMPLEMENTATION_COMMON


		Z_CT(CPP11) Value2D<T> absolute_point_to_unit(const Value2D<T> &point) const
			{return (point - this->point) / this->size;}


		Z_CT(CPP11) Rectangle bottom_right_quarter() const
			{return Rectangle(point.x + size.x / T(2), point.y, size / T(2));}


		/*Z_CT(CPP11) Boolean contains(const Circle<T> &circle) const
			{
			return	circle.radius != T(0)		      &&
				circle.point - circle.radius >= point &&
				circle.point + circle.radius <= point + size;
			}*/


		/*Z_CT(CPP11) Circle<T> inner_circle() const
			{return Circle<T>(center(), size.inner_minimum() / T(2));}*/


		Z_CT(CPP11) Rectangle right_half() const
			{return Rectangle(point.x + size.x / T(2), point.y, size.x / T(2), size.y);}


		Z_CT(CPP11) Rectangle top_half() const
			{return Rectangle(point.x, point.y + size.y / T(2), size.x, size.y / T(2));}


		Z_CT(CPP11) Rectangle top_left_quarter() const
			{return Rectangle(point.x, point.y + size.y / T(2), size / T(2));}


		Z_CT(CPP11) Rectangle top_right_quarter() const
			{return Rectangle(point + size / T(2), size / T(2));}


		Z_CT(CPP11) Value2D<T> unit_point_to_absolute(const Value2D<T> &point) const
			{return point * size + point;}
	};
}


#undef Z_IMPLEMENTATION_FOUNDATION_CONSTRUCTOR
#undef Z_IMPLEMENTATION_FOUNDATION_OPERATOR
#undef Z_IMPLEMENTATION_CG_GEOMETRY
#undef Z_IMPLEMENTATION_NS_GEOMETRY
#undef Z_IMPLEMENTATION_COCOS2D_X
#undef Z_IMPLEMENTATION_COMMON

#endif // _Z_classes_mathematics_geometry_euclidean_Rectangle_HPP_
