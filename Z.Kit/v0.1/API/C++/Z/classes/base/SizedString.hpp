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

namespace Zeta {template <unsigned int S> struct SizedString;}


template <unsigned int S> struct Zeta::SizedString {
	//typedef struct {
		Character data[S + 1];
	//} Data;

	//Data data;

	Z_CONSTANT_MEMBER(CPP11) SizedString() : data{0} {}
	//constexpr SizedString(const Character *string) : data(*(Data *)string), null(0) {}
	Z_CONSTANT_MEMBER(CPP11) Character const *c() const {return data;}
};


#endif // __Z_classes_base_SizedString_HPP__
