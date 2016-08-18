/* Z Kit C++ API - classes/mathematics/geometry/euclidean/Rectangle.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_mathematics_geometry_euclidean_Rectangle_HPP__
#define __Z_classes_mathematics_geometry_euclidean_Rectangle_HPP__

#include <Z/classes/base/Value2D.hpp>
#include <Z/types/mathematics.h>

namespace Zeta {template <class T> struct Rectangle;}


template <class T> struct Zeta::Rectangle {

	typedef typename ZRealType(ZRectangle, T) Base;  // Not actual but compatible
	typedef typename ZRealType(ZRectangle, T) Super; // Not actual but compatible
	typedef		 Value2D<T>		  Content;
	typedef typename Value2D<T>::Base	  ContentBase;
	typedef		 T			  Value;

	Value2D<T> point, size;


	// MARK: - Constructors


	Z_INLINE_MEMBER Rectangle<T>() {}

	Z_INLINE_MEMBER Rectangle<T>(const Value2D<T> &point, const Value2D<T> &size) : point(point), size(size)	   {}
	Z_INLINE_MEMBER Rectangle<T>(const Value2D<T> &point, T size_x, T size_y)     : point(point), size(size_x, size_y) {}
	Z_INLINE_MEMBER Rectangle<T>(const Value2D<T> &point, T size)		      : point(point), size(size)	   {}
	Z_INLINE_MEMBER Rectangle<T>(T x, T y, const Value2D<T> &size)		      : point(x, y),  size(size)	   {}
	Z_INLINE_MEMBER Rectangle<T>(T x, T y, T size_x, T size_y)		      : point(x, y),  size(size_x, size_y) {}
	Z_INLINE_MEMBER Rectangle<T>(T x, T y, T size)				      : point(x, y),  size(size)	   {}
	Z_INLINE_MEMBER Rectangle<T>(T point, const Value2D<T> &size)		      : point(point), size(size)	   {}
	Z_INLINE_MEMBER Rectangle<T>(const Value2D<T> &size)			      : point(T(0)),  size(size)	   {}
	Z_INLINE_MEMBER Rectangle<T>(T size_x, T size_y)			      : point(T(0)),  size(size_x, size_y) {}
	Z_INLINE_MEMBER Rectangle<T>(T size)					      : point(T(0)),  size(size)	   {}

	Z_INLINE_MEMBER Rectangle<T>(void *data) {*this = *(Rectangle<T> *)data;}
	Z_INLINE_MEMBER Rectangle<T>(const Base &rectangle) {(*(Base *)this) = rectangle;}


	// MARK: - Operators


	Z_INLINE_MEMBER operator Boolean() const {return this->point || this->size;}
	Z_INLINE_MEMBER operator Base   () const {return *z_base;}


	Z_INLINE_MEMBER Boolean operator ==(const Rectangle<T> &rectangle) const
		{
		return	point.x == rectangle.point.x && point.y == rectangle.point.y &&
			size.x	== rectangle.size.x  && size.y	== rectangle.size.y;
		}


	Z_INLINE_MEMBER Boolean operator !=(const Rectangle<T> &rectangle) const
		{
		return	point.x != rectangle.point.x || point.y != rectangle.point.y ||
			size.x	!= rectangle.size.x  || size.y	!= rectangle.size.y;
		}


	// Intersection
	Z_INLINE_MEMBER Rectangle<T> operator &(const Rectangle<T> &rectangle) const
		{
		T x1, x2, y1, y2;

		return	(x1 = maximum<T>(point.x,	   rectangle.point.x)) <=
			(x2 = minimum<T>(point.x + size.x, rectangle.point.x + rectangle.size.x)) &&
			(y1 = maximum<T>(point.y,	   rectangle.point.y)) <=
			(y2 = minimum<T>(point.y + size.y, rectangle.point.y + rectangle.size.y))

			? Rectangle<T>(x1, y1, x2 - x1, y2 - y1)
			: Rectangle<T>(T(0));
		}


	// Union
	Z_INLINE_MEMBER Rectangle<T> operator |(const Rectangle<T> &rectangle) const
		{
		Rectangle<T> result;

		result.point = point.minimum(rectangle.point);
		result.size  = (point + size).maximum(rectangle.point + rectangle.size) - result.point;

		return result;
		}


	Z_INLINE_MEMBER Rectangle<T> &operator &=(const Rectangle<T> &rectangle) {return *this = *this & rectangle;}
	Z_INLINE_MEMBER Rectangle<T> &operator |=(const Rectangle<T> &rectangle) {return *this = *this | rectangle;}

	Z_INLINE_MEMBER Rectangle<T> operator +(const Value2D<T> &value) const {return Rectangle<T>(point, size + value);}
	Z_INLINE_MEMBER Rectangle<T> operator -(const Value2D<T> &value) const {return Rectangle<T>(point, size - value);}
	Z_INLINE_MEMBER Rectangle<T> operator *(const Value2D<T> &value) const {return Rectangle<T>(point, size * value);}
	Z_INLINE_MEMBER Rectangle<T> operator /(const Value2D<T> &value) const {return Rectangle<T>(point, size / value);}

	Z_INLINE_MEMBER Rectangle<T> &operator +=(const Value2D<T> &value) {return *this = *this + value;}
	Z_INLINE_MEMBER Rectangle<T> &operator -=(const Value2D<T> &value) {return *this = *this - value;}
	Z_INLINE_MEMBER Rectangle<T> &operator *=(const Value2D<T> &value) {return *this = *this * value;}
	Z_INLINE_MEMBER Rectangle<T> &operator /=(const Value2D<T> &value) {return *this = *this / value;}

	Z_INLINE_MEMBER Rectangle<T> operator +(T scalar) const {return Value2D<T>(point, size + scalar);}
	Z_INLINE_MEMBER Rectangle<T> operator -(T scalar) const {return Value2D<T>(point, size - scalar);}
	Z_INLINE_MEMBER Rectangle<T> operator *(T scalar) const {return Value2D<T>(point, size * scalar);}
	Z_INLINE_MEMBER Rectangle<T> operator /(T scalar) const {return Value2D<T>(point, size / scalar);}

	Z_INLINE_MEMBER Rectangle<T> &operator +=(T scalar) {return *this = *this + scalar;}
	Z_INLINE_MEMBER Rectangle<T> &operator -=(T scalar) {return *this = *this - scalar;}
	Z_INLINE_MEMBER Rectangle<T> &operator *=(T scalar) {return *this = *this * scalar;}
	Z_INLINE_MEMBER Rectangle<T> &operator /=(T scalar) {return *this = *this / scalar;}

	Z_INLINE_MEMBER T  operator[](int index) const {return ((T *)this)[index];}
	Z_INLINE_MEMBER T &operator[](int index)	      {return ((T *)this)[index];}


	// MARK: - Interoperability


#	if Z_MUST_SUPPORT(CG_GEOMETRY)

		Z_INLINE_MEMBER Rectangle<T>(const CGRect &rectangle)
		: point(rectangle.origin), size(rectangle.size) {}


		Z_INLINE_MEMBER operator CGRect() const
			{
			CGRect result = {
				{CGFloat(point.x), CGFloat(point.y)},
				{CGFloat(size.x),  CGFloat(size.y)}
			};

			return result;
			}

#	endif

#	if	Z_MUST_SUPPORT(NS_GEOMETRY) && defined(Z_OBJECTIVE_C) && \
		(!Z_MUST_SUPPORT(CG_GEOMETRY)			      || \
		 !defined(NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES)  || \
		  !NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES)

		Z_INLINE_MEMBER Rectangle<T>(const NSRect &rectangle)
		: point(rectangle.origin), size(rectangle.size) {}


		Z_INLINE_MEMBER operator NSRect() const
			{
			NSRect result = {
				{CGFloat(point.x), CGFloat(point.y)},
				{CGFloat(size.x),  CGFloat(size.y)}
			};

			return result;
			}

#	endif


	static Z_INLINE_MEMBER Rectangle<T> from_vertices(const Value2D<T> &a, const Value2D<T> &b)
		{
		Value2D<T> minimum = Value2D<T>::minimum(a, b);

		return Rectangle<T>(minimum, Value2D<T>::maximum(a, b) - minimum);
		}


	// MARK: - WIP


	Z_INLINE_MEMBER Boolean contains(const Rectangle<T> &rectangle) const
		{
		return	rectangle.point.x		     >= point.x		 &&
			rectangle.point.y		     >= point.y		 &&
			rectangle.point.x + rectangle.size.x <= point.x + size.x &&
			rectangle.point.y + rectangle.size.y <= point.y + size.y;
		}


	Z_INLINE_MEMBER Boolean contains(const Value2D<T> &point) const
		{
		return	point	>= this->point			&&
			point.x <= this->point.x + this->size.x &&
			point.y <= this->point.y + this->size.y;
		}


	Z_INLINE_MEMBER Boolean collides(const Rectangle<T> &rectangle) const
		{
		return	point.x		 < rectangle.point.x + rectangle.size.x &&
			point.x + size.x > rectangle.point.x &&
			point.y		 < rectangle.point.y + rectangle.size.y &&
			point.y + size.y > rectangle.point.y;
		}


	Z_INLINE_MEMBER Boolean is_zero() const {return point.is_zero() && size.is_zero();}


	Z_INLINE_MEMBER T minimum_x() const {return point.x;}
	Z_INLINE_MEMBER T minimum_y() const {return point.y;}
	Z_INLINE_MEMBER T maximum_x() const {return point.x + size.x;}
	Z_INLINE_MEMBER T maximum_y() const {return point.y + size.y;}
	Z_INLINE_MEMBER T middle_x () const {return point.x + size.x / T(2);}
	Z_INLINE_MEMBER T middle_y () const {return point.y + size.y / T(2);}

	Z_INLINE_MEMBER Value2D<T> top_left	() const {return Value2D<T>(point.x, point.y + size.y);}
	Z_INLINE_MEMBER Value2D<T> top_right	() const {return point + size;}
	Z_INLINE_MEMBER Value2D<T> top_center	() const {return Value2D<T>(point.x + size.x / T(2), point.y + size.y);}
	Z_INLINE_MEMBER Value2D<T> bottom_left	() const {return point;}
	Z_INLINE_MEMBER Value2D<T> bottom_right	() const {return Value2D<T>(point.x + size.x, point.y);}
	Z_INLINE_MEMBER Value2D<T> bottom_center() const {return Value2D<T>(point.x + size.x / T(2), point.y);}
	Z_INLINE_MEMBER Value2D<T> center_left	() const {return Value2D<T>(point.x, point.y + size.y / T(2));}
	Z_INLINE_MEMBER Value2D<T> center_right	() const {return Value2D<T>(point.x + size.x, point.y + size.y / T(2));}
	Z_INLINE_MEMBER Value2D<T> center	() const {return point + size / T(2);}


	/* inline Rectangle<T> correct()
		{
		if ((object.size.x < T(0)) object.point.x -= (object.size.x = -object.size.x);
		if (object.size.y < T(0)) object.point.y -= (object.size.y = -object.size.y);
		return object;
		}*/


	Z_INLINE_MEMBER Rectangle<T> top_half() const
		{return Rectangle<T>(point.x, point.y + size.y / T(2), size.x, size.y / T(2));}


	Z_INLINE_MEMBER Rectangle<T> bottom_half() const
		{return Rectangle<T>(point, size.x, size.y / T(2));}


	Z_INLINE_MEMBER Rectangle<T> left_half() const
		{return Rectangle<T>(point, size.x / T(2), size.y);}


	Z_INLINE_MEMBER Rectangle<T> right_half() const
		{return Rectangle<T>(point.x + size.x / T(2), point.y, size.x / T(2), size.y);}


	Z_INLINE_MEMBER Rectangle<T> top_left_quarter() const
		{return Rectangle<T>(point.x, point.y + size.y / T(2), size / T(2));}


	Z_INLINE_MEMBER Rectangle<T> top_right_quarter() const
		{return Rectangle<T>(point + size / T(2), size / T(2));}


	Z_INLINE_MEMBER Rectangle<T> bottom_left_quarter() const
		{return Rectangle<T>(point, size / T(2));}


	Z_INLINE_MEMBER Rectangle<T> bottom_right_quarter() const
		{return Rectangle<T>(point.x + size.x / T(2), point.y, size / T(2));}


	Z_INLINE_MEMBER Rectangle<T> align_in_top_left(const Value2D<T> &size) const
		{Rectangle<T>(this->point.x, this->point.y + this->size.y - size.y, size);}


	Z_INLINE_MEMBER Rectangle<T> align_in_top_right(const Value2D<T> &size) const
		{Rectangle<T>(this->point + this->size - size, size);}


	Z_INLINE_MEMBER Rectangle<T> align_in_top_center(const Value2D<T> &size) const
		{
		Rectangle<T>
			(this->point.x + (this->size.x - size.x) / T(2),
			 this->point.y +  this->size.y - size.y,
			 size);
		 }


	Z_INLINE_MEMBER Rectangle<T> align_in_bottom_left(const Value2D<T> &size) const
		{return Rectangle<T>(this->point, size);}


	Z_INLINE_MEMBER Rectangle<T> align_in_bottom_right(const Value2D<T> &size) const
		{
		return Rectangle<T>
			(this->point.x + this->size.x - size.x,
			 this->point.y,
			 size);}


	Z_INLINE_MEMBER Rectangle<T> align_in_bottom_center(const Value2D<T> &size) const
		{
		return Rectangle<T>
			(this->point.x + (this->size.x - size.x) / T(2),
			 this->point.y,
			 size);}


	Z_INLINE_MEMBER Rectangle<T> align_in_center_left(const Value2D<T> &size) const
		{
		return Rectangle<T>
			(this->point.x,
			 this->point.y + (this->size.y - size.y) / T(2),
			 size);}


	Z_INLINE_MEMBER Rectangle<T> align_in_center_right(const Value2D<T> &size) const
		{
		return Rectangle<T>
			(this->point.x +  this->size.x - size.x,
			 this->point.y + (this->size.y - size.y) / T(2),
			 size);
		}


	Z_INLINE_MEMBER Rectangle<T> align_in_center(const Value2D<T> &size) const
		{return Rectangle<T>(this->point + (this->size - size) / T(2), size);}


	Z_INLINE_MEMBER Rectangle<T> fit_in_top_left(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle<T>
			(this->point.x, this->point.y + this->size.y - fitting_size.y,
			 fitting_size);
		}


	Z_INLINE_MEMBER Rectangle<T> fit_in_top_right(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);
		return Rectangle<T>(this->point + this->size - fitting_size, fitting_size);
		}


	Z_INLINE_MEMBER Rectangle<T> fit_in_top_center(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle<T>
			(this->point.x + (this->size.x - fitting_size.x) / T(2),
			 this->point.y +  this->size.y - fitting_size.y,
			 fitting_size);
		}


	Z_INLINE_MEMBER Rectangle<T> fit_in_bottom_left(const Value2D<T> &size) const
		{return Value2D<T>(this->point, size.fit(this->size));}


	Z_INLINE_MEMBER Rectangle<T> fit_in_bottom_right(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle<T>
			(this->point.x + this->size.x - fitting_size.x, this->point.y,
			 fitting_size);
		}


	Z_INLINE_MEMBER Rectangle<T> fit_in_bottom_center(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle<T>
			(this->point.x + (this->size.x - fitting_size.x) / T(2), this->point.y,
			 fitting_size);
		}


	Z_INLINE_MEMBER Rectangle<T> fit_in_center_left(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle<T>
			(this->point.x, this->point.y + (this->size.y - fitting_size.y) / T(2),
			 fitting_size);
		}


	Z_INLINE_MEMBER Rectangle<T> fit_in_center_right(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle<T>
			(this->point.x +  this->size.x - fitting_size.x,
			 this->point.y + (this->size.y - fitting_size.y) / T(2),
			 fitting_size);
		 }


	Z_INLINE_MEMBER Rectangle<T> fit_in_center(const Value2D<T> &size) const
		{
		Value2D<T> fitting_size = size.fit(this->size);

		return Rectangle<T>
			(this->point + (this->size - fitting_size) / T(2),
			 fitting_size);
		}

		/*
	inline Circle<T> inner_circle() const
		{
		ZCircle##Type result;

		result.point  = z_rectangle_##type##_center(object);
		result.radius = z_##type##_minimum(object.size.x, object.size.y) / _(2.0);
		return result;
		}


	inline ZAABR##Type to_aabr(ZRectangle##Type object) const
		{
		return z_aabr_##type
			(object.point.x, object.point.y,
			 object.point.x + object.size.x, object.point.y + object.size.y);
		}*/


	Z_INLINE_MEMBER Value2D<T> absolute_point_to_unit(const Value2D<T> &point) const
		{return (point - this->point) / this->size;}


	Z_INLINE_MEMBER Value2D<T> unit_point_to_absolute(const Value2D<T> &point) const
		{return point * this->size + this->point;}


/*	inline Boolean contains_line_segment(const Z2DLine##Type &line_segment) const
		{return contains_point(segment.a) && contains_point(segment.b);}


	inline Boolean contains_aabr(const ZAABR##Type &aabr) const
		{
		return	aabr.a.x >= point.x	     && aabr.a.y >= point.y &&
			aabr.b.x <= point.x + size.x && aabr.b.y <= point.y + size.y;
		}


	inline Boolean contains_circle(const ZCircle##Type &circle) const
		{
		return	circle.point.x - circle.radius >= point.x		  &&
			circle.point.y - circle.radius >= point.y		  &&
			circle.point.x + circle.radius <= point.x + object.size.x &&
			circle.point.y + circle.radius <= point.y + object.size.y;
		}*/

#ifndef Z_DECLARING_PARTIAL_RECTANGLE
};
#endif


#endif // __Z_classes_mathematics_geometry_euclidean_Rectangle_HPP__
