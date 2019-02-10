/* Z Kit - macros/language.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_language_H_
#define Z_macros_language_H_

#include <Z/inspection/language.h>

/* MARK: - Attributes */

#if Z_COMPILER_HAS_ATTRIBUTE(NULL_TERMINATED)
#	define Z_NULL_TERMINATED Z_COMPILER_ATTRIBUTE(NULL_TERMINATED)
#else
#	define Z_NULL_TERMINATED
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(PRIVATE)
#	define Z_PRIVATE Z_COMPILER_ATTRIBUTE(PRIVATE)
#elif Z_DIALECT_HAS_STORAGE_CLASS(C, STATIC)
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

#elif Z_DIALECT_HAS_SPECIFIER(C, INLINE) || Z_DIALECT_HAS_SPECIFIER(CPP, INLINE)
#	define Z_INLINE inline
#else
#	define Z_INLINE
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(NO_RETURN)
#	define Z_NO_RETURN Z_COMPILER_ATTRIBUTE(NO_RETURN)

#elif Z_DIALECT_HAS_SPECIFIER(C, NORETURN)
#	define Z_NO_RETURN _Noreturn

#elif Z_DIALECT_HAS_ATTRIBUTE(CPP, NORETURN)
#	define Z_NO_RETURN [[noreturn]]

#else
#	define Z_NO_RETURN
#endif

/* MARK: - Storage classes */

#if Z_COMPILER_HAS_ATTRIBUTE(THREAD_LOCAL)
#	define Z_THREAD_LOCAL Z_COMPILER_ATTRIBUTE(THREAD_LOCAL)

#elif Z_DIALECT_HAS_STORAGE_CLASS(C, THREAD_LOCAL)
#	define Z_THREAD_LOCAL _Thread_local

#elif Z_DIALECT_HAS_STORAGE_CLASS(CPP, THREAD_LOCAL)
#	define Z_THREAD_LOCAL thread_local
#endif

/* MARK: - Informative macros */

#define Z_OUT
#define Z_INOUT
#define Z_UNUSED(variable) (void)variable

/* MARK: - Linkage */

#ifdef __cplusplus
#	define Z_EXTERN_C	extern "C"
#	define Z_EXTERN_C_BEGIN extern "C" {
#	define Z_EXTERN_C_END	}
#else
#	define Z_EXTERN_C
#	define Z_EXTERN_C_BEGIN
#	define Z_EXTERN_C_END
#endif

#endif /* Z_macros_language_H_ */
