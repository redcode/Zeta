/* Z Kit C++ API - functions/base/type.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_type_HPP__
#define __Z_functions_base_type_HPP__

#include <Z/classes/base/SizedString.hpp>

#if Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME)

	namespace Zeta {

#		if	Z_COMPILER == Z_COMPILER_GCC   || \
			Z_COMPILER == Z_COMPILER_CLANG || \
			Z_COMPILER == Z_COMPILER_APPLE_LLVM


			template <class T>
			Z_CT(CPP14) Size type_string_size()
				{
				const Character *input = __PRETTY_FUNCTION__;
				Size size = 0;
				Size bracket_count = 0;

				while (*input++ != '=');
				while (*++input != ']' || bracket_count)
					{
					if	(*input == '[') bracket_count++;
					else if (*input == ']') bracket_count--;

					size++;
					}

				return size;
				}


			template <class T, Size S = type_string_size<T>()>
			Z_CT(CPP14) SizedString<S> type_string()
				{
				const Character *input = __PRETTY_FUNCTION__;

				while (*input++ != '=');
				return SizedString<S>(input + 1);
				}


#		elif Z_COMPILER == Z_COMPILER_VISUAL_CPP

#		endif

	}

#endif

#endif // __Z_functions_base_type_HPP__
