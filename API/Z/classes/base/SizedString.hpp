/* Z Kit - classes/base/SizedString.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_classes_base_SizedString_HPP_
#define _Z_classes_base_SizedString_HPP_

#include <Z/types/base.hpp>


namespace Zeta {namespace Detail {namespace SizedString {

	template <USize I> class Element : public Element<I - 1> {
		protected:
		Char _character;

		public:
		Z_CT(CPP11) Element(const Char *string)
		: Element<I - 1>(string), _character(string[I]) {}
	};


	template <> class Element<0> {
		protected:
		Char _character;

		public:
		Z_CT(CPP11) Element(const Char *string)
		: _character(string[0]) {}
	};
}}}


namespace Zeta {

	template <USize S> class SizedString : public Detail::SizedString::Element<S - 1> {
		protected:
		Char _null_character;

		public:
		Z_CT(CPP11) SizedString(const Char *string)
		: Detail::SizedString::Element<S - 1>(string), _null_character('\0') {}

		Z_INLINE operator const Char *() const
			{return &this->Detail::SizedString::Element<0>::_character;}
	};


	template <> class SizedString<0> {
		protected:
		Char _null_character;

		public:
		Z_CT(CPP11) SizedString(const Char *string)
		: _null_character('\0') {}

		Z_INLINE operator const Char *() const
			{return &_null_character;}
	};
}


#endif // _Z_classes_base_SizedString_HPP_
