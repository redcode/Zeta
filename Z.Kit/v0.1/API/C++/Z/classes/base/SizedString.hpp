/* Z Kit C++ API - classes/base/SizedString.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_SizedString_HPP__
#define __Z_classes_base_SizedString_HPP__

#include <Z/types/base.hpp>


namespace Zeta {namespace Detail {namespace SizedString {

	template <Size I> class Element : Element<I - 1> {

		protected:
		Character _character;

		public:
		Z_CT_MEMBER(CPP11) Element(const Character *string)
		: Element<I - 1>(string), _character(string[I - 1]) {}
	};


	template <> class Element<0> {
		public:
		Z_CT_MEMBER(CPP11) Element(const Character *string) {}
	};
}}}


namespace Zeta {template <Size S> class SizedString : public Detail::SizedString::Element<S> {

	protected:
	Character _null_character;

	public:
	Z_CT_MEMBER(CPP11) SizedString(const Character *string)
	: Detail::SizedString::Element<S>(string), _null_character('\0') {}

	Z_CT_MEMBER(CPP11) operator const Character *() const {return (const Character *)this;}
};}


#endif // __Z_classes_base_SizedString_HPP__
