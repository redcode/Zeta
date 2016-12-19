/* Z Kit C++ API - classes/base/Symbol.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Symbol_HPP__
#define __Z_classes_base_Symbol_HPP__

#include <Z/types/base.hpp>
#include <Z/macros/language.hpp>

namespace Zeta {struct Symbol;}


struct Zeta::Symbol {
	UInt64 hash;
	UInt16 size;


	Z_CONSTANT_MEMBER(CPP14) Symbol(const Character *string)
	: hash(Z_UINT64(14695981039346656037)), size(0)
		{
		while (*string)
			{
			hash = (hash ^ *string++) * Z_UINT64(109951162821);
			size++;
			}
		}


	Z_CONSTANT_MEMBER(CPP11) Boolean operator ==(Symbol symbol) const
		{return hash == symbol.hash && size == symbol.size;}


	Z_CONSTANT_MEMBER(CPP11) Boolean operator !=(Symbol symbol) const
		{return hash != symbol.hash && size != symbol.size;}
};


#endif // __Z_classes_base_Symbol_HPP__
