/* Z Kit - functions/base/type.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_base_type_HPP_
#define _Z_functions_base_type_HPP_

#include <Z/classes/base/SizedString.hpp>

#if Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME)

	namespace Zeta {

#		if	Z_COMPILER == Z_COMPILER_GCC   || \
			Z_COMPILER == Z_COMPILER_CLANG || \
			Z_COMPILER == Z_COMPILER_APPLE_LLVM


			template <class T>
			static Z_CT(CPP14) USize type_string_size()
				{
				const Char *input = __PRETTY_FUNCTION__;
				USize size = 0;
				USize bracket_count = 0;

				while (*input++ != '=');
				while (*++input != ']' || bracket_count)
					{
					if	(*input == '[') bracket_count++;
					else if (*input == ']') bracket_count--;

					size++;
					}

				return size;
				}


			template <class T, USize S = type_string_size<T>()>
			static Z_CT(CPP14) SizedString<S> type_string()
				{
				const Char *input = __PRETTY_FUNCTION__;

				while (*input++ != '=');
				return SizedString<S>(input + 1);
				}


#		elif Z_COMPILER == Z_COMPILER_VISUAL_CPP

#		endif

	}

#endif

#endif // _Z_functions_base_type_HPP_
