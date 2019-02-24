/* Z Kit - classes/Range.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Range_HPP
#define Z_classes_Range_HPP

#include <Z/macros/type selection.hpp>
#include <Z/functions/value.hpp>

#if defined(Z_USE_NS_RANGE) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
#	import <Foundation/NSRange.h>
#endif


namespace Zeta {template <class T> struct Range {
	typedef typename ZTypeFixedNatural(ZRange, T) Base;
	T index, size;


	Z_INLINE Range() Z_NOTHROW
		Z_DEFAULTED({})


	Z_CT(CPP11) Range(T size) Z_NOTHROW
	: index(0), size(size) {}


	Z_CT(CPP11) Range(T index, T size) Z_NOTHROW
	: index(index), size(size) {}


	Z_CT(CPP11) Range(const Base &other) Z_NOTHROW
	: index(other.index), size(other.size) {}


	Z_CT(CPP11) operator Boolean() const Z_NOTHROW
		{return !!size;}


	Z_INLINE operator Base&() const Z_NOTHROW
		{return *reinterpret_cast<Base *>(this);}


	Z_CT(CPP11) Boolean operator ==(const Range &rhs) const Z_NOTHROW
		{return index == rhs.index && size == rhs.size;}


	Z_CT(CPP11) Boolean operator !=(const Range &rhs) const Z_NOTHROW
		{return index != rhs.index || size != rhs.size;}


	Z_CT(CPP14) Range operator &(const Range &rhs) const Z_NOTHROW
		{
		T index = (this->index > rhs.index) ? this->index : rhs.index;
		T end	= minimum<T>(end(), rhs.end());

		return end > index ? Range(index, end - index) : Range(0);
		}


	Z_CT(CPP14) Range operator |(const Range &rhs) const Z_NOTHROW
		{
		T	index = (this->index < rhs.index) ? this->index : rhs.index,
			a_end = end(),
			b_end = rhs.end();

		return Range(index, ((a_end > b_end) ? a_end : b_end) - index);
		}


	Z_INLINE Range &operator &=(const Range &rhs) Z_NOTHROW
		{return *this = *this & rhs;}


	Z_INLINE Range &operator |=(const Range &rhs) Z_NOTHROW
		{return *this = *this | rhs;}


	Z_CT(CPP11) T operator [](T index) const Z_NOTHROW
		{return this->index + index;}


#	if defined(Z_USE_NS_RANGE) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

		Z_CT(CPP11) Range(const NSRange &range) Z_NOTHROW
		: index(range.location), size(range.length) {}


#		if Z_DIALECT_HAS(CPP, COPY_LIST_INITIALIZATION)
			Z_CT(CPP11) operator NSRange() const Z_NOTHROW
				{return {NSUInteger(index), NSUInteger(size)};}
#		else
			Z_CT(CPP14) operator NSRange() const Z_NOTHROW
				{
				NSRange result = {NSUInteger(index), NSUInteger(size)};
				return result;
				}
#		endif

#	endif


	Z_CT(CPP11) Boolean contains(const Range &other) const Z_NOTHROW
		{return other.index >= index && other.end() <= end();}


	Z_CT(CPP11) Boolean contains(T index) const Z_NOTHROW
		{return index >= this->index && index < end();}


	Z_CT(CPP11) T end() const Z_NOTHROW
		{return index + size;}


	Z_CT(CPP11) Boolean intersects(const Range &other) const Z_NOTHROW
		{return	index < other.end() && other.index < end();}


	Z_CT(CPP11) Boolean is_zero() const Z_NOTHROW
		{return !index && !size;}
};}


#endif // Z_classes_Range_HPP
