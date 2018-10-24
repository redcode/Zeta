/* Z Kit - macros/language.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_language_HPP_
#define _Z_macros_language_HPP_

#include <Z/macros/language.h>

/* MARK: - Attributes */

#if Z_COMPILER_HAS_ATTRIBUTE(EBCO)
#	define Z_EBCO Z_COMPILER_ATTRIBUTE(EBCO)
#else
#	define Z_EBCO
#endif

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
#	define Z_CT_CPP11 constexpr
#else 
#	define Z_CONSTANT
#	define Z_CT_CPP11
#endif

#if Z_LANGUAGE_HAS(CPP, CPP14_RULES_ON_CONSTANT_EXPRESSION_FUNCTION)
#	define Z_CT_CPP14 constexpr
#else
#	define Z_CT_CPP14
#endif

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

#if	!defined(Z_AVOID_VARIADIC_MACROS) && \
	(Z_LANGUAGE_HAS(C, VARIADIC_MACRO) || Z_LANGUAGE_HAS(CPP, C99_PREPROCESSOR))

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

#endif // _Z_macros_language_HPP_
