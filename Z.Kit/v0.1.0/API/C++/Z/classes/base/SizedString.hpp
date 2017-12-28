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

	template <Size I> class Element : public Element<I - 1> {
		protected:
		Character _character;

		public:
		Z_CT_MEMBER(CPP11) Element(const Character *string)
		: Element<I - 1>(string), _character(string[I]) {}
	};


	template <> class Element<0> {
		protected:
		Character _character;

		public:
		Z_CT_MEMBER(CPP11) Element(const Character *string)
		: _character(string[0]) {}
	};
}}}


namespace Zeta {

	template <Size S> class SizedString : public Detail::SizedString::Element<S - 1> {
		protected:
		Character _null_character;

		public:
		Z_CT_MEMBER(CPP11) SizedString(const Character *string)
		: Detail::SizedString::Element<S - 1>(string), _null_character('\0') {}

		Z_INLINE_MEMBER operator const Character *() const
			{return &this->Detail::SizedString::Element<0>::_character;}
	};


	template <> class SizedString<0> {
		protected:
		Character _null_character;

		public:
		Z_CT_MEMBER(CPP11) SizedString(const Character *string)
		: _null_character('\0') {}

		Z_INLINE_MEMBER operator const Character *() const
			{return &_null_character;}
	};
}


#endif // __Z_classes_base_SizedString_HPP__
