/* Z Kit - macros/language.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_language_HPP__
#define __Z_macros_language_HPP__

#include <Z/macros/language.h>

/* MARK: - Constants */

#if !Z_LANGUAGE_HAS_TYPE(CPP, BOOLEAN)
#	ifndef true
#		define true TRUE
#	endif

#	ifndef false
#		define false FALSE
#	endif
#endif

/* MARK: - Specifiers */

#if Z_LANGUAGE_HAS_SPECIFIER(CPP, CONSTANT_EXPRESSION)
#	define Z_CONSTANT constexpr
#	define Z_CT_N2235 constexpr
#else 
#	define Z_CONSTANT
#	define Z_CT_N2235
#endif

#if Z_LANGUAGE_HAS(CPP, RELAXED_CONSTANT_EXPRESSION_FUNCTION)
#	define Z_CT_N3652 constexpr
#else
#	define Z_CT_N3652
#endif

#define Z_CT_CPP11 Z_CT_N2235
#define Z_CT_CPP14 Z_CT_N3652

#define Z_CT(CONFORM_TO) Z_CT_##CONFORM_TO Z_INLINE

#if Z_LANGUAGE_HAS_SPECIFIER(CPP, EXPLICIT)
#	define Z_EXPLICIT explicit
#else
#	define Z_EXPLICIT
#endif

#if Z_LANGUAGE_HAS_SPECIFIER(CPP, NO_EXCEPTION)
#	define Z_NO_EXCEPTION noexcept
#else
#	define Z_NO_EXCEPTION throw()
#endif

/* MARK: - Defaulted functions */

#if Z_LANGUAGE_HAS(C, VARIADIC_MACRO) || Z_LANGUAGE_HAS(CPP, C99_PREPROCESSOR)
#	if Z_LANGUAGE_HAS(CPP, DEFAULTED_FUNCTION)
#		define Z_DEFAULTED(...) = default;
#	else
#		define Z_DEFAULTED(...) __VA_ARGS__
#	endif
#else
#	if Z_LANGUAGE_HAS(CPP, DEFAULTED_FUNCTION)
#		define Z_DEFAULTED(body) = default;
#	else
#		define Z_DEFAULTED(body) body
#	endif
#endif

#endif // __Z_macros_language_HPP__
