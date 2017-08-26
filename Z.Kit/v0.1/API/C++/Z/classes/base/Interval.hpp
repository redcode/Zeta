/* Z Kit C++ API - classes/base/Interval.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Interval_HPP__
#define __Z_classes_base_Interval_HPP__

#include <Z/macros/type selection.hpp>
#include <Z/functions/base/value.hpp>


namespace Zeta {template <class T> struct Interval {

	T a, b;

	Z_INLINE_MEMBER Range() {}

	Z_CT_MEMBER(CPP11) Interval(T a, T b) : a(a), b(b) {}

	Z_CT_MEMBER(CPP11) operator Boolean() const {return index || size;}
	Z_INLINE_MEMBER    operator Base&  () const {return *((Base *)this);}


	Z_CT_MEMBER(CPP11) Boolean operator ==(const Interval &interval) const
		{return a == interval.a && b == interval.b;}


	Z_CT_MEMBER(CPP11) Boolean operator !=(const Interval &interval) const
		{return a != interval.a || b != interval.b;}


	Z_CT_MEMBER(CPP11) Boolean operator ==(T number) const
		{return index == number && size == number;}


	Z_CT_MEMBER(CPP11) Boolean operator !=(T number) const
		{return index != number || size != number;}


	Z_CT_MEMBER(CPP14) Range operator &(const Range &range) const
		{
		T index = (this->index > range.index) ? this->index : range.index;
		T end	= Zeta::minimum<T>(this->index + this->size, range.index + range.size);

		return end > index ? Range(index, end - index) : Range(0);
		}


	Z_CT_MEMBER(CPP14) Range operator |(const Range &range) const
		{
		T	index = (this->index < range.index) ? this->index : range.index,
			a_end = this->index + this->size,
			b_end = range.index + range.size;

		return Range(index, ((a_end > b_end) ? a_end : b_end) - index);
		}


	Z_INLINE_MEMBER Range &operator &=(const Range &range) {return *this = *this & range;}
	Z_INLINE_MEMBER Range &operator |=(const Range &range) {return *this = *this | range;}


#	if defined(Z_USE_NS_RANGE) && Z_LANGUAGE == Z_LANGUAGE_OBJECTIVE_CPP

		Z_CT_MEMBER(CPP11) Range(const NSRange &range)
		: index(range.location), size(range.length) {}


		Z_CT_MEMBER(CPP14) operator NSRange() const
			{
			NSRange result = {NSUInteger(index), NSUInteger(size)};
			return result;
			}

#	endif


	Z_CT_MEMBER(CPP11) Boolean collides(const Range &range) const
		{
		return	index	    < range.index + range.size &&
			range.index < index + size;
		}


	Z_CT_MEMBER(CPP11) Boolean contains(const Range &range) const
		{
		return	range.index		 >= index &&
			range.index + range.size <= index + size;
		}


	Z_CT_MEMBER(CPP11) Boolean contains(T index) const
		{return index >= this->index && index < this->index + this->size;}


	Z_CT_MEMBER(CPP11) T end() const
		{return index + size;}


	Z_CT_MEMBER(CPP11) Boolean is_zero() const
		{return !index && !size;}


	Z_INLINE_MEMBER void swap(Range &range)
		{Zeta::swap<Base>((Base *)this, (Base *)&range);}
};}


#endif // __Z_classes_base_Interval_HPP__
