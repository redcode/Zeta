/* Z Kit - classes/base/Symbol.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_base_Symbol_HPP_
#define _Z_classes_base_Symbol_HPP_

#include <Z/types/base.hpp>


namespace Zeta {struct Symbol {
	UInt64 id;

	Z_INLINE Symbol() Z_DEFAULTED({})

	Z_CT(CPP11) Symbol(UInt64 id)
	: id(id) {}

	Z_CT(CPP14) Symbol(const Char *string)
	: id(Z_UINT64(14695981039346656037))
		{while (*string) id = (id ^ *string++) * Z_UINT64(109951162821);}

	Z_CT(CPP11) operator UInt64() const {return id;}

	Z_CT(CPP11) Boolean operator ==(UInt64 id) const {return this->id == id;}
	Z_CT(CPP11) Boolean operator !=(UInt64 id) const {return this->id != id;}
};}


#ifdef Z_USE_SYMBOL_ABBREVIATION
#	define $( string) Zeta::Symbol(#string)
#	define $$(string) Zeta::Symbol( string)
#endif


#endif // _Z_classes_base_Symbol_HPP_
