/* Z Kit C++ API - classes/base/Range.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Range_HPP__
#define __Z_classes_base_Range_HPP__

#include <Z/types/base.hpp>
#include <Z/macros/super.hpp>
#include <Z/functions/base/value.hpp>

#if defined(Z_USE_NS_RANGE_TYPE) && defined(Z_OBJECTIVE_C)
#	import <Foundation/NSRange.h>
#endif

namespace ZKit {struct Range;}


struct ZKit::Range : public ZRange {

	typedef ZRange Base;
	typedef ZRange Super;

	inline Range() {}
	inline Range(Size size) {this->index = 0; this->size = size;}
	inline Range(Size index, Size size) {this->index = index; this->size = size;}
	inline Range(const Base &range) {*z_base = range;}

#	ifdef Z_USE_NS_RANGE_TYPE
		inline Range(const NSRange &range) {index = range.location; size = range.length;}
#	endif

	inline Boolean contains(const Range &range) const
		{return range.index >= index && range.index + range.size <= index + size;}


	inline Boolean collides(const Range &range) const
		{return index < range.index + range.size && range.index < index + size;}


	inline Boolean is_zero() const
		{return index == 0 && size == 0;}


	inline Size end() const
		{return index + size;}


	inline Boolean contains_index(Size index) const
		{return index >= this->index && index < this->index + this->size;}


	inline Boolean operator ==(const Range &range) const
		{return index == range.index && size == range.size;}


	inline Boolean operator ==(Size number) const
		{return index == number && size == number;}


	inline Range operator &(const Range &range) const
		{
		Size index = (this->index > range.index) ? this->index : range.index;
		Size minimum = ZKit::minimum<Size>(this->index + this->size, range.index + range.size);

		return minimum > index ? Range(index, minimum - index) : Range(0, 0);
		}


	inline Range operator |(const Range &range) const
		{
		Size	index	  = (this->index < range.index) ? this->index : range.index,
			a_maximum = this->index + this->size,
			b_maximum = range.index + range.size;

		return Range(index, ((a_maximum > b_maximum) ? a_maximum : b_maximum) - index);
		}


	inline Range &operator &=(Range range) {return *this = *this & range;}
	inline Range &operator |=(Range range) {return *this = *this | range;}
};


#endif // __Z_classes_base_Range_HPP__
