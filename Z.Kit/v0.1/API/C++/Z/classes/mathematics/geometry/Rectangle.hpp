/* Z Kit C++ API - classes/mathematics/geometry/Rectangle.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_mathematics_geometry_Rectangle_HPP__
#define __Z_classes_mathematics_geometry_Rectangle_HPP__

#include <Z/classes/base/Value2D.hpp>
#include <Z/types/mathematics.h>

namespace ZKit {
	namespace Selectors {Z_TYPE_SELECTOR_REAL(Rectangle, ZRectangleType)}
	template <typename T> struct Rectangle;
}


template <typename T> struct ZKit::Rectangle {

	typedef typename Selectors::Rectangle<T>::type Base;  // Not actual but compatible
	typedef typename Selectors::Rectangle<T>::type Super; // Not actual but compatible
	typedef		 Value2D<T>		       Content;
	typedef typename Value2D<T>::Base	       ContentBase;
	typedef		 T			       Value;

	Value2D<T> point, size;


	// MARK: - Constructors


	inline Rectangle<T>() {}


	inline Rectangle<T>(const Value2D<T> &point, const Value2D<T> &size)
		{
		this->point = point;
		this->size  = size;
		}


	inline Rectangle<T>(T x, T y, T size_x, T size_y)
		{
		point.x = x;
		point.y = y;
		size.x	= size_x;
		size.y	= size_y;
		}


	inline Rectangle<T>(T x, T y, const Value2D<T> &size)
		{
		point.x	   = x;
		point.y	   = y;
		this->size = size;
		}


	inline Rectangle<T>(const Value2D<T> &point, T size_x, T size_y)
		{
		this->point = point;
		size.x	    = size_x;
		size.y	    = size_y;
		}


	inline Rectangle<T>(T point, T size)
		{
		this->point.x = point;
		this->point.y = point;
		this->size.x  = size;
		this->size.y  = size;
		}


	inline Rectangle<T>(T point, const Value2D<T> &size)
		{
		this->point.x = point;
		this->point.y = point;
		this->size    = size;
		}


	inline Rectangle<T>(const Value2D<T> &point, T size)
		{
		this->point  = point;
		this->size.x = size;
		this->size.y = size;
		}


	inline Rectangle<T>(T scalar)
		{
		point.x = scalar;
		point.y = scalar;
		size.x	= scalar;
		size.y	= scalar;
		}


	inline Rectangle<T>(void *data) {*this = *(Rectangle<T> *)data;}
	inline Rectangle<T>(const Base &rectangle) {(*(Base *)this) = rectangle;}


#	ifdef Z_USE_CG_GEOMETRY_TYPES

		inline Rectangle<T>(const CGRect &rectangle)
			{
			point.x = rectangle.origin.x;
			point.y = rectangle.origin.y;
			size.x	= rectangle.size.width;
			size.y	= rectangle.size.height;
			}

#	endif


#	if	defined(Z_USE_NS_GEOMETRY_TYPES)		      && \
		(!defined(Z_USE_CG_GEOMETRY_TYPES)		      || \
		 (!defined(NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES) || \
		  !NSGEOMETRY_TYPES_SAME_AS_CGGEOMETRY_TYPES))

		inline Rectangle<T>(const NSRect &rectangle)
			{
			point.x = rectangle.origin.x;
			point.y = rectangle.origin.y;
			size.x	= rectangle.size.width;
			size.y	= rectangle.size.height;
			}

#	endif


	static inline Rectangle<T> from_vertices(const Value2D<T> &a, const Value2D<T> &b)
		{
		Value2D<T> minimum = Value2D<T>::minimum(a, b);
		Value2D<T> maximum = Value2D<T>::maximum(a, b);

		return Rectangle<T>(minimum, maximum - minimum);
		}


	// MARK: - Operators


	inline Boolean operator ==(const Rectangle<T> &rectangle) const
		{
		return	point.x == rectangle.point.x && point.y == rectangle.point.y &&
			size.x	== rectangle.size.x  && size.y	== rectangle.size.y;
		}


	inline Rectangle<T> operator &(const Rectangle<T> &rectangle) const
		{
		T x1, x2, y1, y2;

		return	(x1 = maximum<T>(point.x,	   rectangle.point.x)) <=
			(x2 = minimum<T>(point.x + size.x, rectangle.point.x + rectangle.size.x)) &&
			(y1 = maximum<T>(point.y,	   rectangle.point.y)) <=
			(y2 = minimum<T>(point.y + size.y, rectangle.point.y + rectangle.size.y))

			? Rectangle<T>(x1, y1, x2 - x1, y2 - y1)
			: Rectangle<T>(0, 0, 0, 0);
		}


	inline Rectangle<T> operator |(const Rectangle<T> &rectangle) const
		{
		Rectangle<T> result;

		result.point = point.minimum(rectangle.point);
		result.size  = (point + size).maximum(rectangle.point + rectangle.size) - result.point;

		return result;
		}


	inline T  operator[](int index) const {return ((T *)this)[index];}
	inline T &operator[](int index)	      {return ((T *)this)[index];}


	// MARK: - WIP


	inline Boolean contains(const Rectangle<T> &rectangle) const
		{
		return	rectangle.point.x		     >= point.x		 &&
			rectangle.point.y		     >= point.y		 &&
			rectangle.point.x + rectangle.size.x <= point.x + size.x &&
			rectangle.point.y + rectangle.size.y <= point.y + size.y;
		}


	inline Boolean collides(const Rectangle<T> &rectangle) const
		{
		return	point.x		 < rectangle.point.x + rectangle.size.x &&
			point.x + size.x > rectangle.point.x &&
			point.y		 < rectangle.point.y + rectangle.size.y &&
			point.y + size.y > rectangle.point.y;
		}


	inline Boolean is_zero() const {return point.is_zero() && size.is_zero();}


	inline T minimum_x() const {return point.x;}
	inline T minimum_y() const {return point.y;}
	inline T maximum_x() const {return point.x + size.x;}
	inline T maximum_y() const {return point.y + size.y;}
	inline T middle_x () const {return point.x + size.x / T(2);}
	inline T middle_y () const {return point.y + size.y / T(2);}

	inline Value2D<T> top_left     () const {return Value2D<T>(point.x, point.y + size.y);}
	inline Value2D<T> top_right    () const {return point + size;}
	inline Value2D<T> top_center   () const {return Value2D<T>(point.x + size.x / T(2), point.y + size.y);}
	inline Value2D<T> bottom_left  () const {return point;}
	inline Value2D<T> bottom_right () const {return Value2D<T>(point.x + size.x, point.y);}
	inline Value2D<T> bottom_center() const {return Value2D<T>(point.x + size.x / T(2), point.y);}
	inline Value2D<T> center_left  () const {return Value2D<T>(point.x, point.y + size.y / T(2));}
	inline Value2D<T> center_right () const {return Value2D<T>(point.x + size.x, point.y + size.y / T(2));}
	inline Value2D<T> center       () const {return point + size / T(2);}

	/*
	inline Rectangle<T> correct()
		{
		if ((object.size.x < T(0)) object.point.x -= (object.size.x = -object.size.x);
		if (object.size.y < T(0)) object.point.y -= (object.size.y = -object.size.y);
		return object;
		}*/


	inline Rectangle<T> top_half   () const {return Rectangle<T>(point.x, point.y + size.y / T(2), size.x, size.y / T(2));}
	inline Rectangle<T> bottom_half() const {return Rectangle<T>(point, size.x, size.y / T(2));}
	inline Rectangle<T> left_half  () const {return Rectangle<T>(point, size.x / T(2), size.y);}
	inline Rectangle<T> right_half () const {return Rectangle<T>(point.x + size.x / T(2), point.y, size.x / T(2), size.y);}

	inline Rectangle<T> top_left_quarter	() const {return Rectangle<T>(point.x, point.y + size.y / T(2), size / T(2));}
	inline Rectangle<T> top_right_quarter	() const {return Rectangle<T>(point + size / T(2), size / T(2));}
	inline Rectangle<T> bottom_left_quarter	() const {return Rectangle<T>(point, size / T(2));}
	inline Rectangle<T> bottom_right_quarter() const {return Rectangle<T>(point.x + size.x / T(2), point.y, size / T(2));}


	inline Rectangle<T> align_in_top_left(const Value2D<T> &size) const
		{Rectangle<T>(this->point.x, this->point.y + this->size.y - size.y, size);}


	inline Rectangle<T> align_in_top_right(const Value2D<T> &size) const
		{Rectangle<T>(this->point + this->size - size, size);}


	inline Rectangle<T> align_in_top_center(const Value2D<T> &size) const
		{
		Rectangle<T>
			(this->point.x + (this->size.x - size.x) / T(2),
			 this->point.y +  this->size.y - size.y,
			 size);
		 }


	inline Rectangle<T> align_in_bottom_left(const Value2D<T> &size) const
		{return Rectangle<T>(this->point, size);}


	inline Rectangle<T> align_in_bottom_right(const Value2D<T> &size) const
		{return Rectangle<T>(this->point.x + this->size.x - size.x, this->point.y, size);}


	inline Rectangle<T> align_in_bottom_center(const Value2D<T> &size) const
		{return Rectangle<T>(this->point.x + (this->size.x - size.x) / T(2), this->point.y, size);}


	inline Rectangle<T> align_in_center_left(const Value2D<T> &size) const
		{return Rectangle<T>(this->point.x, this->point.y + (this->size.y - size.y) / T(2), size);}


	inline Rectangle<T> align_in_center_right(const Value2D<T> &size) const
		{
		return Rectangle<T>
			(this->point.x +  this->size.x - size.x,
			 this->point.y + (this->size.y - size.y) / T(2),
			 size);
		}


	inline Rectangle<T> align_in_center(const Value2D<T> &size) const
		{return Rectangle<T>(this->point + (this->size - size) / T(2), size);}


	inline Rectangle<T> fit_in_top_left(const Value2D<T> &size) const
		{
		size = size.fit(this->size);
		return Rectangle<T>(this->point.x, this->point.y + this->size.y - size.y, size);
		}


	inline Rectangle<T> fit_in_top_right(const Value2D<T> &size) const
		{
		size = size.fit(this->size);
		return Rectangle<T>(this->point + this->size - size, size);
		}


	inline Rectangle<T> fit_in_top_center(const Value2D<T> &size) const
		{
		size = size.fit(this->size);

		return Rectangle<T>
			(this->point.x + (this->size.x - size.x) / T(2),
			 this->point.y +  this->size.y - size.y,
			 size);
		}


	inline Rectangle<T> fit_in_bottom_left(const Value2D<T> &size) const
		{return Value2D<T>(this->point, size.fit(this->size));}


	inline Rectangle<T> fit_in_bottom_right(const Value2D<T> &size) const
		{
		size = size.fit(this->size);
		return Rectangle<T>(this->point.x + this->size.x - size.x, this->point.y, size);
		}


	inline Rectangle<T> fit_in_bottom_center(const Value2D<T> &size) const
		{
		size = size.fit(this->size);
		return Rectangle<T>(this->point.x + (this->size.x - size.x) / T(2), this->point.y, size);
		}


	inline Rectangle<T> fit_in_center_left(const Value2D<T> &size) const
		{
		size = size.fit(this->size);
		return Rectangle<T>(this->point.x, this->point.y + (this->size.y - size.y) / T(2), size);
		}


	inline Rectangle<T> fit_in_center_right(const Value2D<T> &size) const
		{
		size = size.fit(this->size);

		return Rectangle<T>
			(this->point.x +  this->size.x - size.x,
			 this->point.y + (this->size.y - size.y) / T(2),
			 size);
		 }


	inline Rectangle<T> fit_in_center(const Value2D<T> &size) const
		{
		size = size.fit(this->size);
		return Rectangle<T>(this->point + (this->size - size) / T(2), size);
		}

		/*
	inline ZCircle##Type inner_circle(ZRectangle##Type object) const
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


	inline Value2D<T> absolute_point_to_unit(const Value2D<T> &point) const {return (point - this->point) / this->size;}
	inline Value2D<T> unit_point_to_absolute(const Value2D<T> &point) const {return point * this->size + this->point;}


	inline Boolean contains_point(const Value2D<T> &point) const
		{
		return	point	>= this->point			&&
			point.x <= this->point.x + this->size.x &&
			point.y <= this->point.y + this->size.y;
		}


/*	inline Boolean contains_line_segment(
		ZRectangle##Type object,
		Z2DLine##Type	 line_segment
	) const
		{
		return	z_rectangle_##type##_contains_point(object, line_segment.a) &&
			z_rectangle_##type##_contains_point(object, line_segment.b);
		}


	inline Boolean contains_aabr(ZRectangle##Type object, ZAABR##Type aabr) const
		{
		return	aabr.a.x >= object.point.x		   &&
			aabr.a.y >= object.point.y		   &&
			aabr.b.x <= object.point.x + object.size.x &&
			aabr.b.y <= object.point.y + object.size.y;
		}


	inline Boolean contains_circle(
		ZRectangle##Type object,
		ZCircle##Type	 circle
	) const
		{
		return	circle.point.x - circle.radius >= object.point.x		 &&
			circle.point.y - circle.radius >= object.point.y		 &&
			circle.point.x + circle.radius <= object.point.x + object.size.x &&
			circle.point.y + circle.radius <= object.point.y + object.size.y;
		}*/

#ifndef Z_DECLARING_PARTIAL_RECTANGLE
};
#endif


#endif // __Z_classes_mathematics_geometry_Rectangle_HPP__
