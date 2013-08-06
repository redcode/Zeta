/* Q API - inspection/private/compiler/Clang.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_inspection_private_compiler_H__
#define __Q_inspection_private_compiler_H__

#include <Q/constants/basics.h>
#include <Q/keys/compiler.h>
#include <Q/keys/bit field.h>

/* MARK: - Identification */

#define Q_COMPILER						Q_COMPILER_CLANG
#define Q_COMPILER_STRING					Q_COMPILER_STRING_CLANG
#define Q_COMPILER_VERSION
#define Q_COMPILER_VERSION_STRING

/* MARK: - Extensions */

#define Q_COMPILER_HAS_ALIAS

#if __has_extension(blocks)
#	define Q_COMPILER_HAS_LANGUAGE_EXTENSION_CLOSURE
#endif

/* MARK: - Bit field encoding */

#define Q_COMPILER_LITTLE_ENDIAN_8BIT_FIELD_ENCODING		Q_BIT_FIELD_ENCODING_REVERSED
#define Q_COMPILER_LITTLE_ENDIAN_BIT_FIELD_ENCODING		Q_BIT_FIELD_ENCODING_REVERSED
#define Q_COMPILER_BIG_ENDIAN_8BIT_FIELD_ENCODING		Q_BIT_FIELD_ENCODING_LITERAL
#define Q_COMPILER_BIG_ENDIAN_BIT_FIELD_ENCODING		Q_BIT_FIELD_ENCODING_LITERAL

/* MARK: - Built-in types */

#define Q_COMPILER_TYPE_UINT128					__uint128_t
#define Q_COMPILER_TYPE_INT128					__int128_t
#define Q_COMPILER_TYPE_VAL					__builtin_va_list

/* MARK: - Built-in functions (VAL) */

#define Q_COMPILER_FUNCTION_VAL_INITIALIZE			__builtin_va_start
#define Q_COMPILER_FUNCTION_VAL_FINALIZE			__builtin_va_end
#define Q_COMPILER_FUNCTION_VAL_READ				__builtin_va_arg

#if	__STDC_VERSION__ >= 199900L || \
	!defined(__STRICT_ANSI__)

#	define Q_COMPILER_FUNCTION_VAL_COPY(object, output)	__builtin_va_copy(output, object)

#endif

#if	(__GNUC__ == 3 && __GNUC_MINOR__ >= 5) || \
	 __GNUC__ >  3

#	define Q_COMPILER_FUNCTION_OFFSETOF			__builtin_offsetof

#endif

/* MARK: - Keywords and attributes */

#define Q_ASSEMBLY
#define Q_THREAD_LOCAL(type, identifier)			type __thread identifier
#define Q_API
#define Q_PRIVATE						__attribute__((visibility("hidden"))) static
#define Q_PUBLIC						__attribute__((visibility("default"))
#define Q_ALIAS(name)						__attribute__((weak, alias(name)))
#define Q_STRICT_SIZE_BEGIN
#define Q_STRICT_SIZE_END					__attribute__((packed))

#if __GNUC__ >= 4
#	define Q_INLINE						static __inline__ __attribute__((always_inline))
#else
#	define Q_INLINE						static __inline__
#endif

#endif /* __Q_inspection_private_compiler_H__ */
