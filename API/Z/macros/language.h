/* Z Kit - macros/language.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_language_H_
#define _Z_macros_language_H_

#include <Z/inspection/language.h>

/* MARK: - Attributes */

#if Z_COMPILER_HAS_ATTRIBUTE(NULL_TERMINATED)
#	define Z_NULL_TERMINATED Z_COMPILER_ATTRIBUTE(NULL_TERMINATED)
#else
#	define Z_NULL_TERMINATED
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(STRICT_SIZE_BEGIN) && Z_COMPILER_HAS_ATTRIBUTE(STRICT_SIZE_END)
#	define Z_STRICT_SIZE_BEGIN Z_COMPILER_ATTRIBUTE(STRICT_SIZE_BEGIN)
#	define Z_STRICT_SIZE_END   Z_COMPILER_ATTRIBUTE(STRICT_SIZE_END)
#else
#	define Z_STRICT_SIZE_BEGIN
#	define Z_STRICT_SIZE_END
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(PRIVATE)
#	define Z_PRIVATE Z_COMPILER_ATTRIBUTE(PRIVATE)
#elif Z_LANGUAGE_HAS_STORAGE_CLASS(C, STATIC)
#	define Z_PRIVATE static
#else
#	define Z_PRIVATE
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(PUBLIC)
#	define Z_PUBLIC Z_COMPILER_ATTRIBUTE(PUBLIC)
#else
#	define Z_PUBLIC
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(WEAK)
#	define Z_WEAK Z_COMPILER_ATTRIBUTE(WEAK)
#else
#	define Z_WEAK
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(API)
#	define Z_API Z_COMPILER_ATTRIBUTE(API)
#else
#	define Z_API
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(API_EXPORT)
#	define Z_API_EXPORT Z_COMPILER_ATTRIBUTE(API_EXPORT)
#else
#	define Z_API_EXPORT Z_PUBLIC
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(API_WEAK_EXPORT)
#	define Z_API_WEAK_EXPORT Z_COMPILER_ATTRIBUTE(API_WEAK_EXPORT)
#else
#	define Z_API_WEAK_EXPORT Z_API_EXPORT Z_WEAK
#endif

/* MARK: - Specifiers */

#if Z_COMPILER_HAS_ATTRIBUTE(INLINE)
#	define Z_INLINE Z_COMPILER_ATTRIBUTE(INLINE)

#elif Z_LANGUAGE_HAS_SPECIFIER(C, INLINE) || Z_LANGUAGE_HAS_SPECIFIER(CPP, INLINE)
#	define Z_INLINE inline
#else
#	define Z_INLINE
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(NO_RETURN)
#	define Z_NO_RETURN Z_COMPILER_ATTRIBUTE(NO_RETURN)

#elif Z_LANGUAGE_HAS_SPECIFIER(C, NO_RETURN)
#	define Z_NO_RETURN _Noreturn

#elif Z_LANGUAGE_HAS_ATTRIBUTE(CPP, NO_RETURN)
#	define Z_NO_RETURN [[noreturn]]

#else
#	define Z_NO_RETURN
#endif

/* MARK: - Storage classes */

#if Z_COMPILER_HAS_ATTRIBUTE(THREAD_LOCAL)
#	define Z_THREAD_LOCAL Z_COMPILER_ATTRIBUTE(THREAD_LOCAL)

#elif Z_LANGUAGE_HAS_STORAGE_CLASS(C, THREAD_LOCAL)
#	define Z_THREAD_LOCAL _Thread_local

#elif Z_LANGUAGE_HAS_STORAGE_CLASS(CPP, THREAD_LOCAL)
#	define Z_THREAD_LOCAL thread_local
#endif

/* MARK: - Built-in macros: Struture */

#if Z_COMPILER_HAS_MACRO(OFFSET_OF)
#	define Z_OFFSET_OF Z_COMPILER_MACRO(OFFSET_OF)
#else
#	define Z_OFFSET_OF(type, member) (((unsigned long int)&((type *)(1))->member) - 1)
#endif

/* MARK: - Informative macros */

#define Z_OUT
#define Z_INOUT

/* MARK: - Sections */

#ifdef __cplusplus
#	define Z_C_SYMBOLS_BEGIN extern "C" {
#	define Z_C_SYMBOLS_END	 }
#else
#	define Z_C_SYMBOLS_BEGIN
#	define Z_C_SYMBOLS_END
#endif

#endif /* _Z_macros_language_H_ */
