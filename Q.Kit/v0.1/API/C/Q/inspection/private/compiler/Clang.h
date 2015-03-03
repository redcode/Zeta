/* Q Kit API - inspection/private/compiler/Clang.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_inspection_private_compiler_H__
#define __Q_inspection_private_compiler_H__

#include <Q/keys/compiler.h>
#include <Q/keys/bit field.h>
#include <Q/macros/version.h>

/* MARK: - Identification */

#define Q_COMPILER		  Q_COMPILER_CLANG
#define Q_COMPILER_STRING	  Q_COMPILER_STRING_CLANG
#define Q_COMPILER_VERSION	  Q_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#define Q_COMPILER_VERSION_STRING __clang_version__

/* __apple_build_version__ */

/* MARK: - Features */

#define Q_COMPILER_HAS_ALIAS

#if __has_feature(c_atomic) || __has_extension(c_atomic)
#	define Q_COMPILER_HAS_ATOMIC_OPERATIONS
#endif

#if __has_extension(blocks)
#	define Q_COMPILER_HAS_LANGUAGE_EXTENSION_CLOSURE
#endif

/* MARK: - Bit field encoding */

#define Q_COMPILER_LITTLE_ENDIAN_8BIT_FIELD_ENCODING Q_BIT_FIELD_ENCODING_REVERSED
#define Q_COMPILER_LITTLE_ENDIAN_BIT_FIELD_ENCODING  Q_BIT_FIELD_ENCODING_REVERSED
#define Q_COMPILER_BIG_ENDIAN_8BIT_FIELD_ENCODING    Q_BIT_FIELD_ENCODING_LITERAL
#define Q_COMPILER_BIG_ENDIAN_BIT_FIELD_ENCODING     Q_BIT_FIELD_ENCODING_LITERAL

/* MARK: - Built-in types */

#define Q_COMPILER_TYPE_UINT128 __uint128_t
#define Q_COMPILER_TYPE_INT128	__int128_t
#define Q_COMPILER_TYPE_VAL	__builtin_va_list

/* MARK: - Built-in functions - Struture */

#define Q_COMPILER_FUNCTION_OFFSETOF __builtin_offsetof

/* MARK: - Built-in functions - VAL */

#define Q_COMPILER_FUNCTION_VAL_INITIALIZE __builtin_va_start
#define Q_COMPILER_FUNCTION_VAL_FINALIZE   __builtin_va_end
#define Q_COMPILER_FUNCTION_VAL_READ	   __builtin_va_arg

#if __has_builtin(__builtin_va_copy)
#	define Q_COMPILER_FUNCTION_VAL_COPY(object, output) __builtin_va_copy(output, object)
#endif

/* MARK: - Built-in functions - Atomic operations */

#if __has_builtin(__sync_bool_compare_and_swap)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_SET_IF_EQUAL   __sync_bool_compare_and_swap
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#endif

#if __has_builtin(__sync_fetch_and_add)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_INCREMENT(  pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add

#endif

#if __has_builtin(__sync_fetch_and_sub)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_DECREMENT(  pointer) __sync_fetch_and_sub(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub

#endif

#if __has_builtin(__sync_fetch_and_and)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and

#endif

#if __has_builtin(__sync_fetch_and_or)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or

#endif

#if __has_builtin(__sync_fetch_and_xor)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor

#endif

#if __has_builtin(__sync_add_and_fetch)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_INCREMENT_THEN_GET(  pointer) __sync_add_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch

#endif

#if __has_builtin(__sync_sub_and_fetch)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_DECREMENT_THEN_GET(  pointer) __sync_sub_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch

#endif

#if __has_builtin(__sync_and_and_fetch)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch

#endif

#if __has_builtin(__sync_or_and_fetch)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch

#endif

#if __has_builtin(__sync_xor_and_fetch)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch

#endif

/* MARK: - Keywords and attributes */

#define Q_ASSEMBLY
#define Q_THREAD_LOCAL(type, identifier) type __thread identifier
#define Q_API
#define Q_PRIVATE			 __attribute__((visibility("hidden"))) static
#define Q_PUBLIC			 __attribute__((visibility("default"))
#define Q_ALIAS(name)			 __attribute__((weak, alias(name)))
#define Q_BEGIN_STRICT_SIZE
#define Q_END_STRICT_SIZE		 __attribute__((packed))

#if __GNUC__ >= 4
#	define Q_INLINE			 static __inline__ __attribute__((always_inline))
#else
#	define Q_INLINE			 static __inline__
#endif

#endif /* __Q_inspection_private_compiler_H__ */
