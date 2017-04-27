/* Z Kit C++ API - macros/language.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_language_HPP__
#define __Z_macros_language_HPP__

#include <Z/macros/language.h>

/* MARK: - Specifiers */

#if Z_COMPILER_CPP_HAS_ATTRIBUTE(INLINE_MEMBER)
#	define Z_INLINE_MEMBER Z_COMPILER_CPP_ATTRIBUTE(INLINE_MEMBER)
#else
	// TODO: is the "inline" specifier supported in all versions of C++?
#	define Z_INLINE_MEMBER inline
#endif

#if Z_LANGUAGE_HAS_SPECIFIER(CPP, CONSTANT_EXPRESSION)
#	define Z_CONSTANT_EXPRESSION constexpr
#	define Z_CONSTANT_N2235	     constexpr
#else 
#	define Z_CONSTANT_EXPRESSION
#	define Z_CONSTANT_N2235
#endif

#if Z_LANGUAGE_HAS(CPP, RELAXED_CONSTANT_EXPRESSION_FUNCTION)
#	define Z_CONSTANT_N3652 constexpr
#else
#	define Z_CONSTANT_N3652
#endif

#define Z_CONSTANT_CPP11 Z_CONSTANT_N2235
#define Z_CONSTANT_CPP14 Z_CONSTANT_N3652

#define Z_CONSTANT(	  REQUERIMENTS) Z_CONSTANT_##REQUERIMENTS Z_INLINE
#define Z_CONSTANT_MEMBER(REQUERIMENTS) Z_CONSTANT_##REQUERIMENTS Z_INLINE_MEMBER

#if Z_LANGUAGE_HAS_SPECIFIER(CPP, NO_EXCEPTION)
#	define Z_NO_EXCEPTION noexcept
#else
#	define Z_NO_EXCEPTION throw()
#endif

/* MARK: - Functions */
/*
#if Z_COMPILER_HAS_FUNCTION(CLASS_MEMBER_OFFSET)
#	define Z_CLASS_MEMBER_OFFSET Z_COMPILER_FUNCTION(CLASS_MEMBER_OFFSET)
#else
#	define Z_CLASS_MEMBER_OFFSET(type, member) ((unsigned long)&((type *)(0))->member)
#endif*/

#endif // __Z_macros_language_HPP__
