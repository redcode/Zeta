/* Z Kit C++ API - classes/base/SizedString.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_SizedString_HPP__
#define __Z_classes_base_SizedString_HPP__

#include <Z/types/base.hpp>
#include <Z/macros/language.hpp>


namespace Zeta {template <Size S> struct SizedString {
	Character data[S + 1];


	Z_CONSTANT_MEMBER(CPP11) SizedString() : data{0} {}


	Z_INLINE_MEMBER SizedString(const Character *string)
		{
		Size size = S;
		Character *data = this->data;

		while (size-- && *string) *data++ = *string++;
		*data = '\0';
		}


	Z_CONSTANT_MEMBER(CPP11) operator const Character *() const {return data;}
};}


#endif // __Z_classes_base_SizedString_HPP__
