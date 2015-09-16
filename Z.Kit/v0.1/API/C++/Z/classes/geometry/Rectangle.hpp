/* Z Kit C++ API - classes/geometry/Rectangle.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_geometry_Rectangle_HPP__
#define __Z_classes_geometry_Rectangle_HPP__

#include <Z/classes/base/Value2D.hpp>
#include <Z/types/mathematics.h>
#include <Z/macros/super.hpp>

namespace ZKit {
	namespace BaseTypeSelectors {ZDefineTypeSelectorReal(Rectangle, ZRectangleType)};
	template <typename T> class Rectangle;
};

template <typename T> class
#ifdef __ZMathematics_geometry_Rectangle_HPP__
	ZKit::BaseRectangle {
#else
	ZKit::Rectangle {
#endif
	public:

	typedef typename BaseTypeSelectors::Rectangle<T>::type Base;  // Not actual but compatible
	typedef typename BaseTypeSelectors::Rectangle<T>::type Super; // Not actual but compatible
	typedef		 Value2D<T>			       Content;
	typedef typename Value2D<T>::Base		       ContentBase;
	typedef		 T				       Value;

	Value2D<T> point, size;

	inline Rectangle<T>() {}


	inline Rectangle<T>(ContentBase point, ContentBase size)
		{
		this->point = point;
		this->size = size;
		}


	inline Rectangle<T>(T x, T y, T size_x, T size_y)
		{
		point.x = x;
		point.y = y;
		size.x = size_x;
		size.y = size_y;
		}


	inline Rectangle<T>(T x, T y, ContentBase size)
		{
		point.x = x;
		point.y = y;
		this->size;
		}


	inline Rectangle<T>(ContentBase point, T size_x, T size_y)
		{
		this->point = point;
		size.x = size_x;
		size.y = size_y;
		}


	inline Boolean operator ==(Rectangle<T> rectangle) const
		{
		return	this->point.x == rectangle.point.x && this->point.y == rectangle.point.y &&
			this->size.x  == rectangle.size.x  && this->size.y  == rectangle.size.y;
		}


	inline Rectangle<T> operator &(Rectangle<T> rectangle) const
		{
		T x1, x2, y1, y2;

		return	(x1 = maximum<T>(this->point.x,		       rectangle.point.x)) <=
			(x2 = minimum<T>(this->point.x + this->size.x, rectangle.point.x + rectangle.size.x)) &&
			(y1 = maximum<T>(this->point.y,		       rectangle.point.y)) <=
			(y2 = minimum<T>(this->point.y + this->size.y, rectangle.point.y + rectangle.size.y))

			? Rectangle<T>(x1, y1, x2 - x1, y2 - y1)
			: Rectangle<T>(0, 0, 0, 0);
		}

		/*
	inline Rectangle<T> operator |(Rectangle<T> rectangle) const
		{
			Rectangle<T>()

		ZRectangle##Type result;
		result.point = z_2d_##type##_minimum(a.point, b.point);

		result.size = (this->point + this->size).maximum(b.point + b.size) - result.point;

		result.size.x =	maximum<T>(this->point.x + this->size.x, b.point.x + b.size.x) - result.point.x;
		result.size.y = maximum<T>(this->point.y + this->size.y, b.point.y + b.size.y) - result.point.y;

		return result;
		}*/


	inline Boolean containts(Rectangle<T> rectangle)
		{
		return	rectangle.point.x		     >= this->point.x		     &&
			rectangle.point.y		     >= this->point.y		     &&
			rectangle.point.x + rectangle.size.x <= this->point.x + this->size.x &&
			rectangle.point.y + rectangle.size.y <= this->point.y + this->size.y;
		}


	inline Boolean collides(Rectangle<T> rectangle)
		{
		return	this->point.x		     < rectangle.point.x + rectangle.size.x &&
			this->point.x + this->size.x > rectangle.point.x &&
			this->point.y		     < rectangle.point.y + rectangle.size.y &&
			this->point.y + this->size.y > rectangle.point.y;
		}


};

#endif // __Z_classes_geometry_Rectangle_HPP__
