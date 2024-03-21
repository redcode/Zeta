/* Zeta API - Z/functions/type.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_type_HPP
#define Z_functions_type_HPP

#include <Z/classes/SizedString.hpp>


namespace Zeta {

#	if Z_COMPILER_IS(GCC) || Z_COMPILER_IS(CLANG) || Z_COMPILER_IS(APPLE_CLANG)

		template <class t>
		static Z_CT(CPP14) USize type_string_size() Z_NOTHROW
			{
			const Char *input = __PRETTY_FUNCTION__;
			USize size = 0;
			USize bracket_count = 0;

			while (*input++ != '=');
			while (*++input != ']' || bracket_count)
				{
				if (*input == '[') bracket_count++; else
				if (*input == ']') bracket_count--;
				size++;
				}

			return size;
			}


		template <class t, USize s = type_string_size<t>() + 1>
		static Z_CT(CPP14) SizedString<Char, s> type_string() Z_NOTHROW
			{
			const Char *input = __PRETTY_FUNCTION__;

			while (*input++ != '=');
			return SizedString<Char, s>(StringView<Char>(input + 1, s));
			}


#	elif Z_COMPILER_IS(MSVC)

#	endif
}


#endif // Z_functions_type_HPP
