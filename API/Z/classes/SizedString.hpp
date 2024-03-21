/* Zeta API - Z/classes/SizedString.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_SizedString_HPP
#define Z_classes_SizedString_HPP

#include <Z/classes/StringView.hpp>
#include <utility>


namespace Zeta{namespace ZetaDetail {

	template <class t, USize s, class = std::make_index_sequence<s - 1> > struct SizedString;


	template <class t, USize s, std::size_t... i>
	struct SizedString<t, s, std::index_sequence<i...> > {
		t data[s];


		Z_CT(CPP11) SizedString(const t (&string)[s]) Z_NOTHROW
		: data{string[i]..., 0} {}


		Z_CT(CPP11) SizedString(const StringView<t> &string_view) Z_NOTHROW
		: data{string_view.data[i]..., 0} {}
	};
}}


namespace Zeta{template <class t, USize s> struct SizedString : ZetaDetail::SizedString<t, s> {

	Z_CT(CPP11) SizedString(const t (&string)[s]) Z_NOTHROW
	: ZetaDetail::SizedString<t, s>(string) {}


	Z_CT(CPP11) SizedString(const StringView<t> &string_view) Z_NOTHROW
	: ZetaDetail::SizedString<t, s>(string_view) {}


	Z_CT(CPP11) operator const t *() const Z_NOTHROW
		{return this->data;}


	Z_CT(CPP11) const t &operator [](USize index) const Z_NOTHROW
		{return this->data[index];}
};}


#endif // Z_classes_SizedString_HPP
