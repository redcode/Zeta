/* Z Kit C API - macros/language.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_language_H__
#define __Z_macros_language_H__

#include <Z/inspection/language.h>

#ifndef AND
#	define AND &&
#endif

#ifndef OR
#	define OR ||
#endif

#ifndef DOT
#	define DOT .
#endif

#ifndef COMMA
#	define COMMA ,
#endif

/* MARK: - Type qualifiers */

#if Z_COMPILER_HAS_C_ATTRIBUTE(THREAD_LOCAL)
#	define Z_THREAD_LOCAL Z_COMPILER_C_ATTRIBUTE(THREAD_LOCAL)
#elif Z_LANGUAGE_HAS_TYPE_QUALIFIER(THREAD_LOCAL)
#	define Z_THREAD_LOCAL _Thread_local
#endif

/* MARK: - Storage classes */

#if Z_COMPILER_HAS_C_ATTRIBUTE(PRIVATE)
#	define Z_PRIVATE Z_COMPILER_C_ATTRIBUTE(PRIVATE)
#elif Z_LANGUAGE_HAS_STORAGE_CLASS(STATIC)
#	define Z_PRIVATE static
#else
#	define Z_PRIVATE
#endif

#if Z_COMPILER_HAS_C_ATTRIBUTE(PUBLIC)
#	define Z_PUBLIC Z_COMPILER_C_ATTRIBUTE(PUBLIC)
#else
#	define Z_PUBLIC
#endif

#if Z_COMPILER_HAS_C_ATTRIBUTE(API)
#	define Z_API Z_COMPILER_C_ATTRIBUTE(API)
#else
#	define Z_API Z_PUBLIC
#endif

#if Z_COMPILER_HAS_C_ATTRIBUTE(API_EXPORT)
#	define Z_API_EXPORT Z_COMPILER_C_ATTRIBUTE(API_EXPORT)
#else
#	define Z_API_EXPORT Z_PUBLIC
#endif

/* MARK: - Specifiers */

#if Z_COMPILER_HAS_C_ATTRIBUTE(INLINE)
#	define Z_INLINE Z_COMPILER_C_ATTRIBUTE(INLINE)
#elif Z_LANGUAGE_HAS_SPECIFIER(INLINE)
#	define Z_INLINE inline
#endif

#if Z_COMPILER_HAS_C_ATTRIBUTE(NO_RETURN)
#	define Z_NO_RETURN Z_COMPILER_C_ATTRIBUTE(NO_RETURN)
#elif Z_LANGUAGE_HAS_SPECIFIER(NO_RETURN)
#	define Z_NO_RETURN _Noreturn
#else
#	define Z_NO_RETURN
#endif

/* MARK: - Operators */

#if Z_COMPILER_HAS_MACRO(OFFSET_OF)
#	define Z_OFFSET_OF Z_COMPILER_MACRO(OFFSET_OF)
#elif Z_LANGUAGE_HAS_OPERATOR(OFFSET_OF)
#	define Z_OFFSET_OF offsetof
#else
#	define Z_OFFSET_OF(type, member) ((unsigned long)&((type *)(0))->member)
#endif

/* MARK: - Attributes */

#if Z_COMPILER_HAS_C_ATTRIBUTE(STRICT_SIZE_BEGIN)
#	define Z_STRICT_SIZE_BEGIN Z_COMPILER_C_ATTRIBUTE(STRICT_SIZE_BEGIN)
#	define Z_STRICT_SIZE_END   Z_COMPILER_C_ATTRIBUTE(STRICT_SIZE_END)
#else
#	define Z_STRICT_SIZE_BEGIN
#	define Z_STRICT_SIZE_END
#endif

#if Z_COMPILER_HAS_C_ATTRIBUTE(NULL_TERMINATED)
#	define Z_NULL_TERMINATED Z_COMPILER_C_ATTRIBUTE(NULL_TERMINATED)
#else
#	define Z_NULL_TERMINATED
#endif

#define Z_OUT
#define Z_INOUT

/* MARK: - Sections */

#ifdef __cplusplus
#	define Z_C_SYMBOLS_BEGIN extern "C" {
#	define Z_C_SYMBOLS_END   }
#else
#	define Z_C_SYMBOLS_BEGIN
#	define Z_C_SYMBOLS_END
#endif

#endif /* __Z_macros_language_H__ */
