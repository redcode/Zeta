/* Z Kit C++ API - macros/language.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_language_HPP__
#define __Z_macros_language_HPP__

#include <Z/macros/language.h>

#if Z_LANGUAGE_HAS_SPECIFIER(CONSTANT_EXPRESSION)
#	define Z_CONSTANT_EXPRESSION constexpr
#else 
#	define Z_CONSTANT_EXPRESSION
#endif

#if Z_LANGUAGE_HAS_SPECIFIER(NO_EXCEPTION)
#	define Z_NO_EXCEPTION noexcept
#else
#	define Z_NO_EXCEPTION throw()
#endif

#endif // __Z_macros_language_HPP__
