/* Z Kit - macros/language.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_language_HPP
#define Z_macros_language_HPP

#include <Z/macros/language.h>

// MARK: - Attributes

#if Z_COMPILER_HAS_ATTRIBUTE(EBCO)
#	define Z_EBCO Z_COMPILER_ATTRIBUTE(EBCO)
#else
#	define Z_EBCO
#endif

// MARK: - Constants

#if !Z_DIALECT_HAS_TYPE(CPP, BOOL)
#	ifndef true
#		define true TRUE
#	endif

#	ifndef false
#		define false FALSE
#	endif
#endif

// MARK: - Specifiers

#if Z_DIALECT_HAS_SPECIFIER(CPP, CONSTEXPR)
#	define Z_CONSTANT constexpr
#	define Z_CT_CPP11 constexpr
#else
#	define Z_CONSTANT const
#	define Z_CT_CPP11
#endif

#if Z_DIALECT_HAS(CPP, CPP14_RULES_ON_CONSTEXPR_FUNCTION)
#	define Z_CT_CPP14 constexpr
#else
#	define Z_CT_CPP14
#endif

#define Z_CT(CONFORM_TO) Z_CT_##CONFORM_TO Z_INLINE

#if Z_DIALECT_HAS_SPECIFIER(CPP, EXPLICIT)
#	define Z_EXPLICIT explicit
#else
#	define Z_EXPLICIT
#endif

#if Z_DIALECT_HAS_SPECIFIER(CPP, NOEXCEPT)
#	define Z_NOTHROW /*noexcept*/
#else
#	define Z_NOTHROW throw()
#endif

// MARK: - Defaulted functions

#if	!defined(Z_AVOID_VARIADIC_MACROS) && \
	(Z_DIALECT_HAS(C, VARIADIC_MACRO) || Z_DIALECT_HAS(CPP, C99_PREPROCESSOR))

#	if Z_DIALECT_HAS(CPP, DEFAULTED_FUNCTION)
#		define Z_DEFAULTED(...) = default;
#	else
#		define Z_DEFAULTED(...) __VA_ARGS__
#	endif
#else
#	if Z_DIALECT_HAS(CPP, DEFAULTED_FUNCTION)
#		define Z_DEFAULTED(body) = default;
#	else
#		define Z_DEFAULTED(body) body
#	endif
#endif

#endif // Z_macros_language_HPP
