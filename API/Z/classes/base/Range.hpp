/* Z Kit - classes/base/Range.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_base_Range_HPP_
#define _Z_classes_base_Range_HPP_

#include <Z/macros/type selection.hpp>
#include <Z/functions/base/value.hpp>

#if defined(Z_USE_NS_RANGE) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
#	import <Foundation/NSRange.h>
#endif


namespace Zeta {template <class T> struct Range {
	typedef typename ZTypeFixedNatural(ZRange, T) Base;
	T index, size;

	Z_INLINE Range() Z_DEFAULTED({})

	Z_CT(CPP11) Range(T size)	     : index(0),	   size(size)	    {}
	Z_CT(CPP11) Range(T index, T size)   : index(index),	   size(size)	    {}
	Z_CT(CPP11) Range(const Base &other) : index(other.index), size(other.size) {}

	Z_CT(CPP11) operator Boolean() const {return !!size;}
	Z_INLINE    operator Base&  () const {return *((Base *)this);}


	Z_CT(CPP11) Boolean operator ==(const Range &rhs) const
		{return index == rhs.index && size == rhs.size;}


	Z_CT(CPP11) Boolean operator !=(const Range &rhs) const
		{return index != rhs.index || size != rhs.size;}


	Z_CT(CPP14) Range operator &(const Range &rhs) const
		{
		T index = (this->index > rhs.index) ? this->index : rhs.index;
		T end	= minimum<T>(end(), rhs.end());

		return end > index ? Range(index, end - index) : Range(0);
		}


	Z_CT(CPP14) Range operator |(const Range &rhs) const
		{
		T	index = (this->index < rhs.index) ? this->index : rhs.index,
			a_end = end(),
			b_end = rhs.end();

		return Range(index, ((a_end > b_end) ? a_end : b_end) - index);
		}


	Z_INLINE Range &operator &=(const Range &rhs) {return *this = *this & rhs;}
	Z_INLINE Range &operator |=(const Range &rhs) {return *this = *this | rhs;}

	Z_CT(CPP11) T operator [](T index) const {return this->index + index;}


#	if defined(Z_USE_NS_RANGE) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

		Z_CT(CPP11) Range(const NSRange &range)
		: index(range.location), size(range.length) {}


#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_CT(CPP11) operator NSRange() const
				{return NSRange{NSUInteger(index), NSUInteger(size)};}
#		else
			Z_CT(CPP14) operator NSRange() const
				{
				NSRange result = {NSUInteger(index), NSUInteger(size)};
				return result;
				}
#		endif

#	endif


	Z_CT(CPP11) Boolean contains(const Range &other) const
		{return other.index >= index && other.end() <= end();}


	Z_CT(CPP11) Boolean contains(T index) const
		{return index >= this->index && index < end();}


	Z_CT(CPP11) T end() const
		{return index + size;}


	Z_CT(CPP11) Boolean intersects(const Range &other) const
		{return	index < other.end() && other.index < end();}


	Z_CT(CPP11) Boolean is_zero() const
		{return !index && !size;}


	Z_INLINE void swap(Range &other)
		{Zeta::swap<Base>(this, &other);}
};}


#endif // _Z_classes_base_Range_HPP_
