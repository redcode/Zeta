/* Zeta API - Z/classes/Iterator.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Iterator_HPP
#define Z_classes_Iterator_HPP


namespace Zeta{template <class t> struct Iterator {
	t&		      data_source;
	typename t::size_type index;


	Z_CT(CPP11) Iterator(t &data_source_, typename t::size_type index_)
	: data_source(data_source_), index(index_) {}


	friend Z_CT(CPP11) Boolean operator !=(const Iterator &lhs, const Iterator &rhs) Z_NOTHROW
		{return lhs.index != rhs.index;}


	Z_CT(CPP11) const typename t::element_type &operator *() const Z_NOTHROW
		{return data_source[index];}


	Z_INLINE Iterator const &operator ++() Z_NOTHROW
		{
		index++;
		return *this;
		}
};}


#endif // Z_classes_Iterator_HPP
