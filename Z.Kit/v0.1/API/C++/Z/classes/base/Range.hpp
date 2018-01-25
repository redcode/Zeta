/* Z Kit C++ API - classes/base/Range.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Range_HPP__
#define __Z_classes_base_Range_HPP__

#include <Z/macros/type selection.hpp>
#include <Z/functions/base/value.hpp>

#if defined(Z_USE_NS_RANGE) && Z_LANGUAGE == Z_LANGUAGE_OBJECTIVE_CPP
#	import <Foundation/NSRange.h>
#endif


namespace Zeta {template <class T> struct Range {

	typedef typename ZTypeFixedNatural(ZRange, T) Base;

	T index, size;


	Z_INLINE_MEMBER Range() {}

	Z_CT_MEMBER(CPP11) Range(T size)	  : index(0),	  size(size) {}
	Z_CT_MEMBER(CPP11) Range(T index, T size) : index(index), size(size) {}

	Z_INLINE_MEMBER Range(const Base &range) {(*(Base *)this) = range;}


	Z_CT_MEMBER(CPP11) operator Boolean() const {return !!size;}
	Z_INLINE_MEMBER	   operator Base&  () const {return *((Base *)this);}


	Z_CT_MEMBER(CPP11) Boolean operator ==(const Range &rhs) const
		{return index == rhs.index && size == rhs.size;}


	Z_CT_MEMBER(CPP11) Boolean operator !=(const Range &rhs) const
		{return index != rhs.index || size != rhs.size;}


	Z_CT_MEMBER(CPP14) Range operator &(const Range &rhs) const
		{
		T index = (this->index > rhs.index) ? this->index : rhs.index;
		T end	= Zeta::minimum<T>(this->index + this->size, rhs.index + rhs.size);

		return end > index ? Range(index, end - index) : Range(0);
		}


	Z_CT_MEMBER(CPP14) Range operator |(const Range &rhs) const
		{
		T	index = (this->index < rhs.index) ? this->index : rhs.index,
			a_end = this->index + this->size,
			b_end = rhs.index + rhs.size;

		return Range(index, ((a_end > b_end) ? a_end : b_end) - index);
		}


	Z_INLINE_MEMBER Range &operator &=(const Range &rhs) {return *this = *this & rhs;}
	Z_INLINE_MEMBER Range &operator |=(const Range &rhs) {return *this = *this | rhs;}

	Z_CT_MEMBER(CPP11) T  operator [](T index) const {return this->index + index;}

#	if defined(Z_USE_NS_RANGE) && Z_LANGUAGE == Z_LANGUAGE_OBJECTIVE_CPP

		Z_CT_MEMBER(CPP11) Range(const NSRange &range)
		: index(range.location), size(range.length) {}


		Z_CT_MEMBER(CPP14) operator NSRange() const
			{
			NSRange result = {NSUInteger(index), NSUInteger(size)};
			return result;
			}

#	endif


	Z_CT_MEMBER(CPP11) Boolean contains(const Range &other) const
		{return other.index >= index && other.index + other.size <= index + size;}


	Z_CT_MEMBER(CPP11) Boolean contains(T index) const
		{return index >= this->index && index < this->index + this->size;}


	Z_CT_MEMBER(CPP11) T end() const
		{return index + size;}


	Z_CT_MEMBER(CPP11) Boolean intersects(const Range &other) const
		{return index < other.index + other.size && other.index < index + size;}


	Z_CT_MEMBER(CPP11) Boolean is_zero() const
		{return !index && !size;}


	Z_INLINE_MEMBER void swap(Range &other)
		{Zeta::swap<Base>((Base *)this, (Base *)&other);}
};}


#endif // __Z_classes_base_Range_HPP__
