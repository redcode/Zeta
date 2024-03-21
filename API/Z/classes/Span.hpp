/* Zeta API - Z/classes/Span.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Span_HPP
#define Z_classes_Span_HPP

#include <Z/constants/pointer.h>
#include <Z/classes/Range.hpp>
#include <Z/classes/Iterator.hpp>


namespace Zeta {template <class t> struct Span {
	typedef const t*				const_pointer;
	typedef const t&				const_reference;
	typedef PtrDiff					difference_type;
	typedef t					element_type;
//	typedef Iterator<Span>				iterator;
	typedef t*					pointer;
	typedef t&					reference;
//	typedef Iterator<t*>				reverse_iterator;
	typedef USize					size_type;
	typedef typename Type<t>::remove_const_volatile value_type;

	t*    data;
	USize size;


	Z_CT(CPP11) Span(t *first, USize size_) Z_NOTHROW
	: data(first), size(size_) {}


	Z_CT(CPP11) Span(t *first, t *last) Z_NOTHROW
	: data(first), size(last - first) {}


	Z_CT(CPP11) t &operator [](USize index) const Z_NOTHROW
		{return data[index];}


	Z_CT(CPP11) t &first() const Z_NOTHROW
		{return data[0];}


	Z_CT(CPP11) t &last() const Z_NOTHROW
		{return data[size - 1];}


	Z_CT(CPP11) Span head(USize head_size) const Z_NOTHROW
		{return Span(data, head_size);}


	Z_CT(CPP11) Span tail(USize tail_size) const Z_NOTHROW
		{return Span(&data[size - tail_size], tail_size);}


	Z_CT(CPP11) Span range(USize range_index, USize range_size) const Z_NOTHROW
		{return Span(&data[range_index], range_size);}


	Z_CT(CPP11) Span range(const Range<USize> &range) const Z_NOTHROW
		{return Span(&data[range.index], range.size);}


/*	Z_CT(CPP11) Iterator<Span> begin() const Z_NOTHROW
		{return Iterator<Span>(*this, 0);}


	Z_CT(CPP11) Iterator<Span> end() const Z_NOTHROW
		{return Iterator<Span>(*this, size);}*/
};}


#endif // Z_classes_Span_HPP
