/* Z Kit C++ API - classes/base/Symbol.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Symbol_HPP__
#define __Z_classes_base_Symbol_HPP__

#include <Z/types/base.hpp>
#include <Z/macros/language.hpp>


namespace Zeta {struct Symbol {
	UInt64 id;

	Z_INLINE_MEMBER Symbol() {}

	Z_CONSTANT_MEMBER(CPP11) Symbol(UInt64 id)
	: id(id) {}

	Z_CONSTANT_MEMBER(CPP14) Symbol(const Character *string)
	: id(Z_UINT64(14695981039346656037))
		{while (*string) id = (id ^ *string++) * Z_UINT64(109951162821);}

	Z_CONSTANT_MEMBER(CPP11) operator UInt64() const {return id;}

	Z_CONSTANT_MEMBER(CPP11) Boolean operator ==(UInt64 id) const {return this->id == id;}
	Z_CONSTANT_MEMBER(CPP11) Boolean operator !=(UInt64 id) const {return this->id != id;}
};}


#endif // __Z_classes_base_Symbol_HPP__
