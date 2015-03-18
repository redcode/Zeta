/* Q Kit C++ API - classes/base/Range.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_classes_base_Range_HPP__
#define __Q_classes_base_Range_HPP__

#include <Q/types/base.hpp>
#include <Q/functions/base/value.h>


namespace QKit {class Range /*: public QRange*/ {

	public:
	Size index;
	Size size;

	inline Range(Size index, Size size) : index(index), size(size) {}


	inline Boolean contains(Range range)
		{return range.index >= index && range.index + range.size <= index + size;}


	inline Boolean collides(Range range)
		{return index < range.index + range.size && range.index < index + size;}


	inline Range intersection(Range range)
		{
		Size index = (this->index > range.index) ? this->index : range.index;

		Size minimum = q_value_minimum(SIZE)
			(this->index + this->size, range.index + range.size);

		return minimum > index ? Range(index, minimum - index) : Range(0, 0);
		}


	inline Range union_(Range range)
		{
		Size	index	  = (this->index < range.index) ? this->index : range.index,
			a_maximum = this->index + this->size,
			b_maximum = range.index + range.size;

		return Range(index, ((a_maximum > b_maximum) ? a_maximum : b_maximum) - index);
		}


	inline Boolean is_zero()
		{return index == 0 && size == 0;}


	inline Size end()
		{return index + size;}


	inline Boolean contains_index(Size index)
		{return index >= this->index && index < this->index + this->size;}


};}


#endif // __Q_classes_base_Range_HPP__
