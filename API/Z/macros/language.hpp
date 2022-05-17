/* Zeta API - Z/macros/language.hpp
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_language_HPP
#define Z_macros_language_HPP

#include <Z/macros/language.h>

// MARK: - Constants

#if !Z_DIALECT_HAS_TYPE(CPP98, BOOL)
#	ifndef true
#		define true TRUE
#	endif

#	ifndef false
#		define false FALSE
#	endif
#endif

// MARK: - Specifiers

#if Z_DIALECT_HAS_SPECIFIER(CPP11, CONSTEXPR)
#	define Z_CONSTANT constexpr
#	define Z_CT_CPP11 constexpr
#else
#	define Z_CONSTANT const
#	define Z_CT_CPP11
#endif

#if Z_DIALECT_HAS(CPP14, CONSTEXPR_FUNCTION)
#	define Z_CT_CPP14 constexpr
#else
#	define Z_CT_CPP14
#endif

#define Z_CT(CONFORM_TO) Z_CT_##CONFORM_TO Z_INLINE

#if Z_DIALECT_HAS_SPECIFIER(CPP11, FINAL)
#	define Z_FINAL final
#else
#	define Z_FINAL
#endif

#if Z_DIALECT_HAS_SPECIFIER(CPP11, NOEXCEPT)
#	define Z_NOTHROW noexcept
#else
#	define Z_NOTHROW throw()
#endif

// MARK: - Defaulted functions

#if	!defined(Z_AVOID_VARIADIC_MACROS) && \
	(Z_DIALECT_HAS(C99, VARIADIC_MACRO) || Z_DIALECT_HAS(CPP11, C99_PREPROCESSOR))

#	if Z_DIALECT_HAS(CPP11, EXPLICITLY_DEFAULTED_SPECIAL_MEMBER_FUNCTION)
#		define Z_DEFAULTED(...) = default;
#	else
#		define Z_DEFAULTED(...) __VA_ARGS__
#	endif
#else
#	if Z_DIALECT_HAS(CPP11, EXPLICITLY_DEFAULTED_SPECIAL_MEMBER_FUNCTION)
#		define Z_DEFAULTED(body) = default;
#	else
#		define Z_DEFAULTED(body) body
#	endif
#endif

#endif // Z_macros_language_HPP
