/* Z Kit C++ API - classes/mathematics/geometry/euclidean/Rectangle.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_mathematics_geometry_euclidean_Rectangle_HPP__
#define __Z_classes_mathematics_geometry_euclidean_Rectangle_HPP__

#include <Z/classes/base/Value2D.hpp>
#include <Z/types/mathematics.h>


namespace Zeta {namespace Partials {namespace Rectangle {

#	define Z_THIS ((Rectangle *)this)

	template <class Rectangle, class T, UInt T_number_set> struct Part;


	template <class Rectangle, class T>
	struct Part<Rectangle, T, Z_NUMBER_SET_Z> {

		Zeta::Value2D<T> point, size;

		Z_CT_MEMBER(CPP11) Part(const Zeta::Value2D &point, const Zeta::Value2D &size)
		: point(point), size(size) {}


		Z_CT_MEMBER(CPP11) Rectangle bottom_right_quarter() const
			{
			return Rectangle
				(point.x + size.x / T(2), point.y,
				 size.x	 - size.x / T(2), size.y / T(2));
			}


		Z_CT_MEMBER(CPP11) Rectangle right_half() const
			{
			return Rectangle
				(point.x + size.x / T(2), point.y,
				 size.x	 - size.x / T(2), size.y);
			}


		Z_CT_MEMBER(CPP11) Rectangle top_half() const
			{
			return Rectangle
				(point.x, point.y + size.y / T(2),
				 size.x,  size.y  - size.y / T(2));
			}


		Z_CT_MEMBER(CPP11) Rectangle top_left_quarter() const
			{
			return Rectangle
				(point.x,	point.y + size.y / T(2),
				 size.x / T(2), size.y	- size.y / T(2));
			}


		Z_CT_MEMBER(CPP11) Rectangle top_right_quarter() const
			{
			return Rectangle
				(point + size / T(2),
				 size  - size / T(2));
			}
	};


	template <class Rectangle, class T>
	struct Part<Rectangle, T, Z_NUMBER_SET_R> {

		Zeta::Value2D<T> point, size;

		Z_CT_MEMBER(CPP11) Part(const Zeta::Value2D &point, const Zeta::Value2D &size)
		: point(point), size(size) {}


		Z_CT_MEMBER(CPP11) Zeta::Value2D<T> absolute_point_to_unit(const Zeta::Value2D<T> &point) const
			{return (point - this->point) / this->size;}


		Z_CT_MEMBER(CPP11) Rectangle bottom_right_quarter() const
			{
			return Rectangle
				(point.x + size.x / T(2), point.y,
				 size / T(2));
			}


		/*Z_CT_MEMBER(CPP11) Boolean contains(const Circle<T> &circle) const
			{
			return	circle.radius != T(0)		      &&
				circle.point - circle.radius >= point &&
				circle.point + circle.radius <= point + size;
			}*/


		/*Z_CT_MEMBER(CPP11) Circle<T> inner_circle() const
			{return Circle<T>(Z_THIS->center(), Z_THIS->size.inner_minimum() / T(2));}*/


		Z_CT_MEMBER(CPP11) Rectangle right_half() const
			{
			return Rectangle
				(point.x + size.x / T(2), point.y,
					   size.x / T(2), size.y);
			}


		Z_CT_MEMBER(CPP11) Rectangle top_half() const
			{
			return Rectangle
				(point.x, point.y + size.y / T(2),
				 size.x,	    size.y / T(2));
			}


		Z_CT_MEMBER(CPP11) Rectangle top_left_quarter() const
			{
			return Rectangle
				(point.x, point.y + size.y / T(2),
				 size / T(2));
			}


		Z_CT_MEMBER(CPP11) Rectangle top_right_quarter() const
			{
			return Rectangle
				(point + size / T(2),
					 size / T(2));
			}


		Z_CT_MEMBER(CPP11) Zeta::Value2D<T> unit_point_to_absolute(const Zeta::Value2D<T> &point) const
			{return point * size + point;}
	};


#	undef Z_THIS
}}}


namespace Zeta {template <class T> struct Rectangle : Partials::Rectangle::Part<Rectangle<T>, T, Type<T>::number_set> {

	typedef typename ZTypeFixedSigned(ZRectangle, T) Base;
	typedef Partials::Rectangle::Part<Rectangle, T, Type<T>::number_set> Super;

	Z_INLINE_MEMBER Rectangle() {}

	Z_CT_MEMBER(CPP11) Rectangle(const Value2D<T> &point, const Value2D<T> &size) : Super(point,			    size		      ) {}
	Z_CT_MEMBER(CPP11) Rectangle(const Value2D<T> &point, T size_x, T size_y)     : Super(point,			    Value2D<T>(size_x, size_y)) {}
	Z_CT_MEMBER(CPP11) Rectangle(const Value2D<T> &point, T size_xy)	      : Super(point,			    size_xy		      ) {}
	Z_CT_MEMBER(CPP11) Rectangle(T point_x, T point_y, const Value2D<T> &size)    : Super(Value2D<T>(point_x, point_y), size		      ) {}
	Z_CT_MEMBER(CPP11) Rectangle(T point_x, T point_y, T size_x, T size_y)	      : Super(Value2D<T>(point_x, point_y), Value2D<T>(size_x, size_y)) {}
	Z_CT_MEMBER(CPP11) Rectangle(T point_x, T point_y, T size_xy)		      : Super(Value2D<T>(point_x, point_y), size_xy		      ) {}
	Z_CT_MEMBER(CPP11) Rectangle(T point_xy, const Value2D<T> &size)	      : Super(point_xy,			    size		      ) {}
	Z_CT_MEMBER(CPP11) Rectangle(const Value2D<T> &size)			      : Super(T(0),			    size		      ) {}
	Z_CT_MEMBER(CPP11) Rectangle(T size_x, T size_y)			      : Super(T(0),			    Value2D<T>(size_x, size_y)) {}
	Z_CT_MEMBER(CPP11) Rectangle(T size_xy)					      : Super(T(0),			    size_xy		      ) {}
	Z_CT_MEMBER(CPP11) Rectangle(const Base &rectangle)			      : Super(rectangle.point,		    rectangle.size	      ) {}


	static Z_CT_MEMBER(CPP14) Rectangle from_vertices(const Value2D<T> &a, const Value2D<T> &b)
		{
		Value2D<T> minimum = a.minimum(b);

		return Rectangle(minimum, a.maximum(b) - minimum);
		}


	Z_CT_MEMBER(CPP11) operator Boolean() const {return this->point || this->size;}
	Z_INLINE_MEMBER    operator Base&  () const {return *((Base *)this);}


	Z_CT_MEMBER(CPP11) Boolean operator ==(const Rectangle &rhs) const
		{return	this->point == rhs.point && this->size == rhs.size;}


	Z_CT_MEMBER(CPP11) Boolean operator !=(const Rectangle &rhs) const
		{return	this->point != rhs.point || this->size != rhs.size;}


	// Intersection
	Z_CT_MEMBER(CPP14) Rectangle operator &(const Rectangle &rhs) const
		{
		T x1, x2, y1, y2;

		return	(x1 = maximum<T>(this->point.x,		 rhs.point.x)) <
			(x2 = minimum<T>(this->point.x + size.x, rhs.point.x + rhs.size.x)) &&
			(y1 = maximum<T>(this->point.y,		 rhs.point.y)) <
			(y2 = minimum<T>(this->point.y + size.y, rhs.point.y + rhs.size.y))

			? Rectangle(x1, y1, x2 - x1, y2 - y1)
			: Rectangle(T(0));
		}


	// Union
	Z_CT_MEMBER(CPP14) Rectangle operator |(const Rectangle &rhs) const
		{
		Rectangle result;

		result.point = this->point.minimum(rhs.point);
		result.size  = (this->point + this->size).maximum(rhs.point + rhs.size) - result.point;

		return result;
		}


	Z_INLINE_MEMBER Rectangle &operator &=(const Rectangle &rhs) {return *this = *this & rhs;}
	Z_INLINE_MEMBER Rectangle &operator |=(const Rectangle &rhs) {return *this = *this | rhs;}

	Z_CT_MEMBER(CPP11) Rectangle operator +(const Value2D<T> &rhs) const {return Rectangle(this->point + rhs, this->size);}
	Z_CT_MEMBER(CPP11) Rectangle operator -(const Value2D<T> &rhs) const {return Rectangle(this->point - rhs, this->size);}
	Z_CT_MEMBER(CPP11) Rectangle operator *(const Value2D<T> &rhs) const {return Rectangle(this->point * rhs, this->size);}
	Z_CT_MEMBER(CPP11) Rectangle operator /(const Value2D<T> &rhs) const {return Rectangle(this->point / rhs, this->size);}

	Z_INLINE_MEMBER Rectangle &operator +=(const Value2D<T> &rhs) {return *this = *this + rhs;}
	Z_INLINE_MEMBER Rectangle &operator -=(const Value2D<T> &rhs) {return *this = *this - rhs;}
	Z_INLINE_MEMBER Rectangle &operator *=(const Value2D<T> &rhs) {return *this = *this * rhs;}
	Z_INLINE_MEMBER Rectangle &operator /=(const Value2D<T> &rhs) {return *this = *this / rhs;}

	Z_CT_MEMBER(CPP11) Rectangle operator +(T rhs) const {return Value2D<T>(this->point + rhs, this->size);}
	Z_CT_MEMBER(CPP11) Rectangle operator -(T rhs) const {return Value2D<T>(this->point - rhs, this->size);}
	Z_CT_MEMBER(CPP11) Rectangle operator *(T rhs) const {return Value2D<T>(this->point * rhs, this->size);}
	Z_CT_MEMBER(CPP11) Rectangle operator /(T rhs) const {return Value2D<T>(this->point / rhs, this->size);}

	Z_INLINE_MEMBER Rectangle &operator +=(T rhs) {return *this = *this + rhs;}
	Z_INLINE_MEMBER Rectangle &operator -=(T rhs) {return *this = *this - rhs;}
	Z_INLINE_MEMBER Rectangle &operator *=(T rhs) {return *this = *this * rhs;}
	Z_INLINE_MEMBER Rectangle &operator /=(T rhs) {return *this = *this / rhs;}


#	ifdef Z_USE_CG_GEOMETRY

		Z_CT_MEMBER(CPP11) Rectangle(const CGRect &rectangle)
		: Super(rectangle.origin, rectangle.size) {}


		Z_CT_MEMBER(CPP14) operator CGRect() const
			{
			CGRect result = {
				{CGFloat(this->point.x), CGFloat(this->point.y)},
				{CGFloat(this->size.x),  CGFloat(this->size.y)}
			};

			return result;
			}
#	endif


#	if	defined(Z_USE_NS_GEOMETRY)			     && \
		Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)		     && \
		(!defined(Z_USE_CG_GEOMETRY)			     || \
		 !defined(NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES) || \
		  !NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES)

		Z_CT_MEMBER(CPP11) Rectangle(const NSRect &rectangle)
		: Super(rectangle.origin, rectangle.size) {}


		Z_CT_MEMBER(CPP14) operator NSRect() const
			{
			NSRect result = {
				{CGFloat(this->point.x), CGFloat(this->point.y)},
				{CGFloat(this->size.x),	 CGFloat(this->size.y)}
			};

			return result;
			}
#	endif


#	ifdef Z_USE_COCOS2D_X

		Z_INLINE_MEMBER Rectangle(const cocos2d::Rect &rectangle)
		: Super(rectangle.origin, rectangle.size) {}


		Z_INLINE_MEMBER operator cocos2d::Rect() const
			{
			return cocos2d::Rect
				(float(this->point.x), float(this->point.y),
				 float(this->size.x),  float(this->size.y));
			}
#	endif


	Z_CT_MEMBER(CPP11) Rectangle align_in_bottom_center(const Value2D<T> &size) const
		{
		return Rectangle
			(this->point.x + (this->size.x - size.x) / T(2), this->point.y,
			 size);
		}


	Z_CT_MEMBER(CPP11) Rectangle align_in_bottom_left(const Value2D<T> &size) const
		{
		return Rectangle
			(this->point,
			 size);
		}


	Z_CT_MEMBER(CPP11) Rectangle align_in_bottom_right(const Value2D<T> &size) const
		{
		return Rectangle
			(this->point.x + this->size.x - size.x, this->point.y,
			 size);
		}


	Z_CT_MEMBER(CPP11) Rectangle align_in_center(const Value2D<T> &size) const
		{
		return Rectangle
			(this->point + (this->size - size) / T(2),
			 size);
		}


	Z_CT_MEMBER(CPP11) Rectangle align_in_center_left(const Value2D<T> &size) const
		{
		return Rectangle
			(this->point.x, this->point.y + (this->size.y - size.y) / T(2),
			 size);
		}


	Z_CT_MEMBER(CPP11) Rectangle align_in_center_right(const Value2D<T> &size) const
		{
		return Rectangle
			(this->point.x +  this->size.x - size.x,
			 this->point.y + (this->size.y - size.y) / T(2),
			 size);
		}


	Z_CT_MEMBER(CPP11) Rectangle align_in_top_center(const Value2D<T> &size) const
		{
		return Rectangle
			(this->point.x + (this->size.x - size.x) / T(2),
			 this->point.y +  this->size.y - size.y,
			 size);
		}


	Z_CT_MEMBER(CPP11) Rectangle align_in_top_left(const Value2D<T> &size) const
		{
		return Rectangle
			(this->point.x, this->point.y + this->size.y - size.y,
			 size);
		}


	Z_CT_MEMBER(CPP11) Rectangle align_in_top_right(const Value2D<T> &size) const
		{
		return Rectangle
			(this->point + this->size - size,
			 size);
		}


	Z_CT_MEMBER(CPP11) Value2D<T> bottom_center() const
		{return Value2D<T>(this->point.x + this->size.x / T(2), this->point.y);}


	Z_CT_MEMBER(CPP11) Rectangle bottom_half() const
		{
		return Rectangle
			(this->point,
			 this->size.x, this->size.y / T(2));
		}


	Z_CT_MEMBER(CPP11) Value2D<T> bottom_left() const
		{return this->point;}


	Z_CT_MEMBER(CPP11) Rectangle bottom_left_quarter() const
		{
		return Rectangle
			(this->point,
			 this->size / T(2));
		}


	Z_CT_MEMBER(CPP11) Value2D<T> bottom_right() const
		{return Value2D<T>(this->point.x + this->size.x, this->point.y);}


	Z_CT_MEMBER(CPP11) Value2D<T> center() const
		{return this->point + this->size / T(2);}


	Z_CT_MEMBER(CPP11) Value2D<T> center_left() const
		{return Value2D<T>(this->point.x, this->point.y + this->size.y / T(2));}


	Z_CT_MEMBER(CPP11) Value2D<T> center_right() const
		{return Value2D<T>(this->point.x + this->size.x, this->point.y + this->size.y / T(2));}


	Z_CT_MEMBER(CPP11) Boolean contains(const Rectangle &other) const
		{
		return	!other.size.has_zero()		        &&
			other.point		 >= this->point &&
			other.point + other.size <= this->point + this->size;
		}


	/*Z_CT_MEMBER(CPP11) Boolean contains(const AABR<T> &aabr) const
		{
		return	aabr.a.x != aabr.b.x	&&
			aabr.a.y != aabr.b.y	&&
			aabr.a	 >= this->point &&
			aabr.b	 <= this->point + this->size;
		}*/


	Z_CT_MEMBER(CPP11) Boolean contains(const Value2D<T> &point) const
		{return point >= this->point && point < this->point + this->size;}


	Z_INLINE_MEMBER Rectangle &correct()
		{
		if (this->size.x < T(0)) this->point.x -= (this->size.x = -this->size.x);
		if (this->size.y < T(0)) this->point.y -= (this->size.y = -this->size.y);
		return *this;
		}


	Z_CT_MEMBER(CPP14) Rectangle fit_in_bottom_center(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x + (this->size.x - fitting_size.x) / T(2), this->point.y,
			 fitting_size);
		}


	Z_CT_MEMBER(CPP11) Rectangle fit_in_bottom_left(const Value2D<T> &size) const
		{
		return Rectangle
			(this->point,
			 size.fit(this->size));
		}


	Z_CT_MEMBER(CPP14) Rectangle fit_in_bottom_right(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x + this->size.x - fitting_size.x, this->point.y,
			 fitting_size);
		}


	Z_CT_MEMBER(CPP14) Rectangle fit_in_center(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point + (this->size - fitting_size) / T(2),
			 fitting_size);
		}


	Z_CT_MEMBER(CPP14) Rectangle fit_in_center_left(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x, this->point.y + (this->size.y - fitting_size.y) / T(2),
			 fitting_size);
		}


	Z_CT_MEMBER(CPP14) Rectangle fit_in_center_right(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x +  this->size.x - fitting_size.x,
			 this->point.y + (this->size.y - fitting_size.y) / T(2),
			 fitting_size);
		}


	Z_CT_MEMBER(CPP14) Rectangle fit_in_top_center(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x + (this->size.x - fitting_size.x) / T(2),
			 this->point.y +  this->size.y - fitting_size.y,
			 fitting_size);
		}


	Z_CT_MEMBER(CPP14) Rectangle fit_in_top_left(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point.x, this->point.y + this->size.y - fitting_size.y,
			 fitting_size);
		}


	Z_CT_MEMBER(CPP14) Rectangle fit_in_top_right(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle
			(this->point + this->size - fitting_size,
			 fitting_size);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_from_bottom_center(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x - delta.x / T(2), this->point.y,
			 this->size + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_from_bottom_left(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point,
			 this->size + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_from_bottom_right(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x - delta.x, this->point.y,
			 this->size + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_from_center(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point - delta / T(2),
			 this->size  + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_from_center_left(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x, this->point.y - delta.y / T(2),
			 this->size + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_from_center_right(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x - delta.x, this->point.y - delta.y / T(2),
			 this->size + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_from_top_center(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x - delta.x / T(2), this->point.y - delta.y,
			 this->size + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_from_top_left(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x, this->point.y - delta.y,
			 this->size + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_from_top_right(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point - delta,
			 this->size  + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_in_x_from_center(T delta) const
		{
		return Rectangle
			(this->point.x - delta / T(2), this->point.y,
			 this->size.x  + delta,	       this->size.y);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_in_x_from_left(T delta) const
		{
		return Rectangle
			(this->point,
			 this->size.x + delta, this->size.y);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_in_x_from_right(T delta) const
		{
		return Rectangle
			(this->point.x - delta, this->point.y,
			 this->size.x  + delta, this->size.y);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_in_y_from_bottom(T delta) const
		{
		return Rectangle
			(this->point,
			 this->size.x, this->size.y + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_in_y_from_center(T delta) const
		{
		return Rectangle
			(this->point.x, this->point.y - delta / T(2),
			 this->size.x,	this->size.y  + delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle grow_in_y_from_top(T delta) const
		{
		return Rectangle
			(this->point.x, this->point.y - delta,
			 this->size.x,	this->size.y  + delta);
		}


	Z_CT_MEMBER(CPP11) Boolean intersects(const Rectangle &other) const
		{
		return	!size.has_zero()		       &&
			!other.size.has_zero()		       &&
			other.point + other.size > this->point &&
			other.point		 < this->point + this->size;
		}


	Z_CT_MEMBER(CPP11) Boolean is_zero() const
		{return this->point.is_zero() && this->size.is_zero();}


	Z_CT_MEMBER(CPP11) Rectangle left_half() const
		{
		return Rectangle
			(this->point,
			 this->size.x / T(2), this->size.y);
		}


	Z_CT_MEMBER(CPP11) T maximum_x() const {return this->point.x + this->size.x;}
	Z_CT_MEMBER(CPP11) T maximum_y() const {return this->point.y + this->size.y;}
	Z_CT_MEMBER(CPP11) T middle_x () const {return this->point.x + this->size.x / T(2);}
	Z_CT_MEMBER(CPP11) T middle_y () const {return this->point.y + this->size.y / T(2);}
	Z_CT_MEMBER(CPP11) T minimum_x() const {return this->point.x;}
	Z_CT_MEMBER(CPP11) T minimum_y() const {return this->point.y;}


	Z_CT_MEMBER(CPP11) Rectangle shrink_from_bottom_center(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x + delta.x / T(2), this->point.y,
			 this->size - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_from_bottom_left(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point,
			 this->size - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_from_bottom_right(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x + delta.x, this->point.y,
			 this->size - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_from_center(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point + delta / T(2),
			 this->size  - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_from_center_left(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x, this->point.y + delta.y / T(2),
			 this->size - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_from_center_right(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x + delta.x, this->point.y + delta.y / T(2),
			 this->size - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_from_top_center(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x + delta.x / T(2), this->point.y + delta.y,
			 this->size - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_from_top_left(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point.x, this->point.y + delta.y,
			 this->size - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_from_top_right(const Value2D<T> &delta) const
		{
		return Rectangle
			(this->point + delta,
			 this->size  - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_in_x_from_center(T delta) const
		{
		return Rectangle
			(this->point.x + delta / T(2), this->point.y,
			 this->size.x  - delta,	       this->size.y);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_in_x_from_left(T delta) const
		{
		return Rectangle
			(this->point,
			 this->size.x - delta, this->size.y);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_in_x_from_right(T delta) const
		{
		return Rectangle
			(this->point.x + delta, this->point.y,
			 this->size.x  - delta, this->size.y);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_in_y_from_bottom(T delta) const
		{
		return Rectangle
			(this->point,
			 this->size.x, this->size.y - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_in_y_from_center(T delta) const
		{
		return Rectangle
			(this->point.x, this->point.y + delta / T(2),
			 this->size.x,	this->size.y  - delta);
		}


	Z_CT_MEMBER(CPP11) Rectangle shrink_in_y_from_top(T delta) const
		{
		return Rectangle
			(this->point.x, this->point.y + delta,
			 this->size.x,	this->size.y  - delta);
		}


	Z_INLINE_MEMBER void swap(Rectangle &other)
		{Zeta::swap<Base>((Base *)this, (Base *)&other);}


	Z_CT_MEMBER(CPP11) Value2D<T> top_center() const
		{
		return Value2D<T>
			(this->point.x + this->size.x / T(2),
			 this->point.y + this->size.y);
		}


	Z_CT_MEMBER(CPP11) Value2D<T> top_left() const
		{return Value2D<T>(this->point.x, this->point.y + this->size.y);}


	Z_CT_MEMBER(CPP11) Value2D<T> top_right() const
		{return this->point + this->size;}
};}


#endif // __Z_classes_mathematics_geometry_euclidean_Rectangle_HPP__
