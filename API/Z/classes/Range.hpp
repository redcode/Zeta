/* Zeta API - Z/classes/Range.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Range_HPP
#define Z_classes_Range_HPP

#include <Z/functions/math.hpp>

#if defined(Z_WITH_FOUNDATION) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
#	import <Foundation/NSRange.h>
#endif


namespace Zeta {template <class t> struct Range {
	t index, size;


	Z_INLINE Range() Z_NOTHROW
		Z_DEFAULTED({})


	Z_CT(CPP11) Range(t size_) Z_NOTHROW
	: index(0), size(size_) {}


	Z_CT(CPP11) Range(t index_, t size_) Z_NOTHROW
	: index(index_), size(size_) {}


	Z_CT(CPP11) operator Boolean() const Z_NOTHROW
		{return !!size;}


	friend Z_CT(CPP11) Boolean operator ==(const Range &lhs, const Range &rhs) Z_NOTHROW
		{return lhs.index == rhs.index && lhs.size == rhs.size;}


	friend Z_CT(CPP11) Boolean operator !=(const Range &lhs, const Range &rhs) Z_NOTHROW
		{return lhs.index != rhs.index || lhs.size != rhs.size;}


	friend Z_CT(CPP14) Range operator &(const Range &lhs, const Range &rhs) Z_NOTHROW
		{
		t index = (lhs.index > rhs.index) ? lhs.index : rhs.index;
		t end	= minimum<t>(lhs.end(), rhs.end());

		return end > index ? Range(index, end - index) : Range(0);
		}


	friend Z_CT(CPP14) Range operator |(const Range &lhs, const Range &rhs) Z_NOTHROW
		{
		t index   = (lhs.index < rhs.index) ? lhs.index : rhs.index;
		t lhs_end = lhs.end();
		t rhs_end = rhs.end();

		return Range(index, ((lhs_end > rhs_end) ? lhs_end : rhs_end) - index);
		}


	friend Z_CT(CPP11) Range operator +(const Range &lhs, t rhs) Z_NOTHROW
		{return Range(lhs.index, lhs.size + rhs);}


	friend Z_CT(CPP11) Range operator +(t lhs, const Range &rhs) Z_NOTHROW
		{return Range(rhs.index, rhs.size + lhs);}


	friend Z_CT(CPP11) Range operator -(const Range &lhs, t rhs) Z_NOTHROW
		{return Range(lhs.index, lhs.size - rhs);}


	Z_CT(CPP11) Range operator >>(t rhs) const Z_NOTHROW {return Range(index + rhs, size);}
	Z_CT(CPP11) Range operator <<(t rhs) const Z_NOTHROW {return Range(index - rhs, size);}

	Z_INLINE Range &operator &=(const Range &rhs) Z_NOTHROW {return *this = *this & rhs;}
	Z_INLINE Range &operator |=(const Range &rhs) Z_NOTHROW {return *this = *this | rhs;}

	Z_INLINE Range &operator  +=(t rhs) Z_NOTHROW {return *this = *this +  rhs;}
	Z_INLINE Range &operator  -=(t rhs) Z_NOTHROW {return *this = *this -  rhs;}
	Z_INLINE Range &operator >>=(t rhs) Z_NOTHROW {return *this = *this >> rhs;}
	Z_INLINE Range &operator <<=(t rhs) Z_NOTHROW {return *this = *this << rhs;}

	Z_CT(CPP11) t operator [](t index_) const Z_NOTHROW {return index + index_;}


	Z_CT(CPP11) Boolean contains(const Range &other) const Z_NOTHROW
		{return other.index >= index && other.end() <= end();}


	Z_CT(CPP11) Boolean contains(t index_) const Z_NOTHROW
		{return index_ >= index && index_ < end();}


	Z_CT(CPP11) t end() const Z_NOTHROW
		{return index + size;}


	Z_CT(CPP11) Boolean intersects(const Range &other) const Z_NOTHROW
		{return	index < other.end() && other.index < end();}


	Z_CT(CPP11) Boolean is_zero() const Z_NOTHROW
		{return !index && !size;}


#	if defined(Z_WITH_FOUNDATION) && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

		Z_CT(CPP11) Range(const NSRange &range) Z_NOTHROW
		: index(t(range.location)), size(t(range.length)) {}


#		if Z_DIALECT_HAS(CPP11, COPY_LIST_INITIALIZATION)

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
};}


#endif // Z_classes_Range_HPP
