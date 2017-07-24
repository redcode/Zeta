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

				while (*input++ != '=');
				while (*++input != ']') size++;
				return size;
				}


			template <class T>
			Z_CT(CPP14) SizedString<type_string_size<T>()> type_string()
				{
				SizedString<type_string_size<T>()> string;
				const Character *input = __PRETTY_FUNCTION__;
				Character *output = string.data;

				while (*input++ != '=');
				while (*++input != ']') *output++ = *input;
				return string;
				}


#		elif Z_COMPILER == Z_COMPILER_VISUAL_CPP

#		endif

	}

#endif

#endif // __Z_functions_base_type_HPP__
