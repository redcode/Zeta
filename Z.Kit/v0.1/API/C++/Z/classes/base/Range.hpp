/* Z Kit C++ API - classes/base/Range.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Range_HPP__
#define __Z_classes_base_Range_HPP__

#include <Z/macros/type selector.hpp>
#include <Z/macros/super.hpp>
#include <Z/functions/base/value.hpp>

#if Z_MUST_SUPPORT(NS_RANGE) && defined(Z_OBJECTIVE_C)
#	import <Foundation/NSRange.h>
#endif

namespace ZKit {
	namespace Selectors {Z_TYPE_SELECTOR_NATURAL(Range, ZRangeType)}
	template <typename T> struct Range;
}


template <typename T> struct ZKit::Range : public ZKit::Selectors::Range<T>::type {

	typedef typename Selectors::Range<T>::type Base;
	typedef typename Selectors::Range<T>::type Super;
	typedef		 T			   Value;

	inline Range<T>() {}
	inline Range<T>(T size) {this->index = 0; this->size = size;}
	inline Range<T>(T index, T size) {this->index = index; this->size = size;}
	inline Range<T>(void *data) {*this = *(Range<T> *)data;}
	inline Range<T>(const Base &range) {*z_base = range;}

	inline operator Boolean() const {return this->index && this->size;}
	inline operator Base   () const {return *z_base;}


	inline Boolean operator ==(const Range<T> &range) const
		{return this->index == range.index && this->size == range.size;}


	inline Boolean operator !=(const Range<T> &range) const
		{return this->index != range.index || this->size != range.size;}


	inline Boolean operator ==(T number) const
		{return this->index == number && this->size == number;}


	inline Boolean operator !=(T number) const
		{return this->index != number || this->size != number;}


	inline Range<T> operator &(const Range<T> &range) const
		{
		T index = (this->index > range.index) ? this->index : range.index;
		T end	= ZKit::minimum<T>(this->index + this->size, range.index + range.size);

		return end > index ? Range(index, end - index) : Range<T>(0, 0);
		}


	inline Range<T> operator |(const Range<T> &range) const
		{
		T	index = (this->index < range.index) ? this->index : range.index,
			a_end = this->index + this->size,
			b_end = range.index + range.size;

		return Range<T>(index, ((a_end > b_end) ? a_end : b_end) - index);
		}


	inline Range<T> &operator &=(const Range<T> &range) {return *this = *this & range;}
	inline Range<T> &operator |=(const Range<T> &range) {return *this = *this | range;}


#	if Z_MUST_SUPPORT(NS_RANGE) && defined(Z_OBJECTIVE_C)

		inline Range<T>(const NSRange &range)
			{this->index = range.location; this->size = range.length;}


		inline operator NSRange() const
			{
			NSRange result = {NSUInteger(this->index), NSUInteger(this->size)};
			return result;
			}

#	endif


	inline Boolean contains(const Range<T> &range) const
		{
		return	range.index >= this->index &&
			range.index + range.size <= this->index + this->size;
		}


	inline Boolean contains(T index) const
		{return this->index >= this->index && this->index < this->index + this->size;}


	inline Boolean collides(const Range<T> &range) const
		{
		return	this->index < range.index + range.size &&
			range.index < this->index + this->size;
		}


	inline Boolean is_zero() const
		{return !this->index && !this->size;}


	inline T end() const
		{return this->index + this->size;}

};


#endif // __Z_classes_base_Range_HPP__
