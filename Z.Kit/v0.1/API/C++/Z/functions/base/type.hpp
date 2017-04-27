/* Z Kit C++ API - functions/base/type.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_type_HPP__
#define __Z_functions_base_type_HPP__

#include <Z/classes/base/SizedString.hpp>

namespace Zeta {


	template <class T>
	Z_CONSTANT(CPP14) Size type_string_size()
		{
		Character const *p = __PRETTY_FUNCTION__;
		Size size = 0;

		while (*p++ != '=');
		while (*++p != ']') size++;
		return size;
		}


	template <class T>
	Z_CONSTANT(CPP14) SizedString<type_string_size<T>()> type_string()
		{
		SizedString<type_string_size<T>()> string;
		Character const* s = __PRETTY_FUNCTION__;
		Character *o = string.data;

		while (*s++ != '=');
		while (*++s != ']') *o++ = *s;
		return string;
		}


}

#endif // __Z_functions_base_type_HPP__
