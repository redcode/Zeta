/* Zeta API - Z/macros/language.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_language_H
#define Z_macros_language_H

#include <Z/macros/casting.h>
#include <Z/inspection/language.h>

/* MARK: - Attributes */

#if Z_COMPILER_HAS_ATTRIBUTE(API_EXPORT)
#	define Z_API_EXPORT Z_COMPILER_ATTRIBUTE(API_EXPORT)
#else
#	define Z_API_EXPORT Z_PUBLIC
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(API_IMPORT)
#	define Z_API_IMPORT Z_COMPILER_ATTRIBUTE(API_IMPORT)
#else
#	define Z_API_IMPORT
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(API_WEAK_EXPORT)
#	define Z_API_WEAK_EXPORT Z_COMPILER_ATTRIBUTE(API_WEAK_EXPORT)
#else
#	define Z_API_WEAK_EXPORT Z_API_EXPORT Z_WEAK
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(MICROSOFT_STD_CALL)
#	define Z_MICROSOFT_STD_CALL Z_COMPILER_ATTRIBUTE(MICROSOFT_STD_CALL)
#endif

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

/* MARK: - Specifiers */

#if Z_COMPILER_HAS_ATTRIBUTE(INLINE)
#	define Z_INLINE Z_COMPILER_ATTRIBUTE(INLINE)
#elif defined(__cplusplus) || Z_DIALECT_HAS_SPECIFIER(C99, INLINE)
#	define Z_INLINE inline
#else
#	define Z_INLINE
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(ALWAYS_INLINE)
#	define Z_ALWAYS_INLINE Z_COMPILER_ATTRIBUTE(ALWAYS_INLINE)
#else
#	define Z_ALWAYS_INLINE Z_INLINE
#endif

#if Z_COMPILER_HAS_ATTRIBUTE(NO_RETURN)
#	define Z_NO_RETURN Z_COMPILER_ATTRIBUTE(NO_RETURN)
#elif Z_DIALECT_HAS_ATTRIBUTE(CPP11, NORETURN)
#	define Z_NO_RETURN [[noreturn]]
#elif Z_DIALECT_HAS_SPECIFIER(C11, NORETURN)
#	define Z_NO_RETURN _Noreturn
#else
#	define Z_NO_RETURN
#endif

/* MARK: - Storage classes */

#if Z_COMPILER_HAS_ATTRIBUTE(THREAD_LOCAL)
#	define Z_THREAD_LOCAL Z_COMPILER_ATTRIBUTE(THREAD_LOCAL)
#elif Z_DIALECT_HAS_STORAGE_CLASS(CPP11, THREAD_LOCAL)
#	define Z_THREAD_LOCAL thread_local
#elif Z_DIALECT_HAS_STORAGE_CLASS(C11, THREAD_LOCAL)
#	define Z_THREAD_LOCAL _Thread_local
#endif

/* MARK: - Informative macros */

#define Z_OUT
#define Z_INOUT
#define Z_UNUSED(variable) (void)variable;

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

/* MARK: - Packed constructs */

/* struct <type> {<body>} */

#define Z_PACKED_NAMED_STRUCTURE_BEGIN(type)		       \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_STRUCT struct \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_TYPE	type   \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_BODY

#define Z_PACKED_NAMED_STRUCTURE_END \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_AFTER_BODY

/* union <type> {<body>} */

#define Z_PACKED_NAMED_UNION_BEGIN(type)		 \
	Z_COMPILER_PACKED_NAMED_UNION_BEFORE_UNION union \
	Z_COMPILER_PACKED_NAMED_UNION_BEFORE_TYPE  type	 \
	Z_COMPILER_PACKED_NAMED_UNION_BEFORE_BODY

#define Z_PACKED_NAMED_UNION_END \
	Z_COMPILER_PACKED_NAMED_UNION_AFTER_BODY

/* struct {<body>} */

#define Z_PACKED_STRUCTURE_BEGIN			 \
	Z_COMPILER_PACKED_STRUCTURE_BEFORE_STRUCT struct \
	Z_COMPILER_PACKED_STRUCTURE_BEFORE_BODY

#define Z_PACKED_STRUCTURE_END \
	Z_COMPILER_PACKED_STRUCTURE_AFTER_BODY

/* union {<body>} */

#define Z_PACKED_UNION_BEGIN			   \
	Z_COMPILER_PACKED_UNION_BEFORE_UNION union \
	Z_COMPILER_PACKED_UNION_BEFORE_BODY

#define Z_PACKED_UNION_END \
	Z_COMPILER_PACKED_UNION_AFTER_BODY

/* FAM */

#if Z_DIALECT_HAS(C99, FLEXIBLE_ARRAY_MEMBER)
#	define Z_FAM(member) member
#else
#	define Z_FAM(member)
#endif

#endif /* Z_macros_language_H */
