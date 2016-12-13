/* Z Kit C++ API - functions/base/type.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_type_HPP__
#define __Z_functions_base_type_HPP__

#include <Z/classes/base/SizedString.hpp>

namespace Zeta {


	template <class T>
	Z_CONSTANT(CPP14) zsize type_string_size()
		{
		Character const *p = __PRETTY_FUNCTION__;
		zsize size = 0;

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


	template <class T>
	Z_CONSTANT(CPP14) UInt64 type_id()
		{
		auto	   string      = type_string<T>();
		Size	   string_size = sizeof(string.data);
		Character* c	       = string.data;
		UInt64	   id	       = Z_UINT64(14695981039346656037);

		while (string_size--) id = (id ^ *c++) * Z_UINT64(109951162821);
		return id;
		}


}

#endif // __Z_functions_base_type_HPP__
