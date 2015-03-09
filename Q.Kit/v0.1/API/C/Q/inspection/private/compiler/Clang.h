/* Q C API - inspection/private/compiler/Clang.h
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

/* MARK: - Bit field encoding */

#define Q_COMPILER_LITTLE_ENDIAN_8BIT_FIELD_ENCODING Q_BIT_FIELD_ENCODING_REVERSED
#define Q_COMPILER_LITTLE_ENDIAN_BIT_FIELD_ENCODING  Q_BIT_FIELD_ENCODING_REVERSED
#define Q_COMPILER_BIG_ENDIAN_8BIT_FIELD_ENCODING    Q_BIT_FIELD_ENCODING_LITERAL
#define Q_COMPILER_BIG_ENDIAN_BIT_FIELD_ENCODING     Q_BIT_FIELD_ENCODING_LITERAL

/* MARK: - C Features */

#ifndef __has_extension
#	define __has_extension __has_feature /* Compatibility with Clang < v3.0 */
#endif

/*#define Q_COMPILER_HAS_ANONYMOUS_FUNCTION*/
/*#define Q_COMPILER_HAS_ANONYMOUS_STRUCTURE*/
/*#define Q_COMPILER_HAS_ANONYMOUS_UNION*/

#if __has_extension(c_atomic)
#	define Q_COMPILER_C_HAS_ATOMIC_OPERATIONS
#endif

#if __has_extension(blocks)
#	define Q_COMPILER_C_HAS_CLOSURE
#endif

/*#define Q_COMPILER_HAS_COMPOUND_LITERAL*/

#if __has_extension(c_generic_selections)
#	define Q_COMPILER_C_HAS_GENERIC_SELECTION
#endif

/* MARK: - C Attributes */

#if __has_attribute(alias)
#	define Q_COMPILER_C_ATTRIBUTE_ALIAS(name) __attribute__((alias(name)))
#endif

/*#define Q_COMPILER_C_ATTRIBUTE_API*/
/*#define Q_COMPILER_C_ATTRIBUTE_API_ALIAS*/

#if __has_attribute(always_inline)
#	define Q_COMPILER_C_ATTRIBUTE_INLINE static __inline__ __attribute__((always_inline))
#else
#	define Q_COMPILER_C_ATTRIBUTE_INLINE static __inline__
#endif

#if __has_attribute(visibility)
#	define Q_COMPILER_C_ATTRIBUTE_PRIVATE __attribute__((visibility("hidden"))) static
#	define Q_COMPILER_C_ATTRIBUTE_PUBLIC  __attribute__((visibility("default"))
#endif

#if __has_attribute(packed)
#	define Q_COMPILER_C_ATTRIBUTE_STRICT_SIZE_BEGIN
#	define Q_COMPILER_C_ATTRIBTE_STRICT_SIZE_END __attribute__((packed))
#endif

#if __has_extension(c_thread_local)
#	define Q_COMPILER_C_ATTRIBUTE_THREAD_LOCAL _Thread_local
#elif __has_extension(tls)
#	define Q_COMPILER_C_ATTRIBUTE_THREAD_LOCAL __thread
#endif

#if __has_attribute(weak)
#	define Q_COMPILER_C_ATTRIBUTE_WEAK __attribute__((weak))
#endif

/* MARK: - Built-in constants */

#ifdef __CHAR_BIT__
#	define Q_COMPILER_CONSTANT_UCHAR_BITS __CHAR_BIT__
#	define Q_COMPILER_CONSTANT_CHAR_BITS  __CHAR_BIT__
#endif

#ifdef __SCHAR_MAX__
#	define Q_COMPILER_CONSTANT_CHAR_MAXIMUM __SCHAR_MAX__
#endif

#ifdef __SIZEOF_SHORT__
#	define Q_COMPILER_CONSTANT_USHORT_SIZE __SIZEOF_SHORT__
#	define Q_COMPILER_CONSTANT_SHORT_SIZE __SIZEOF_SHORT__
#endif

#ifdef __SHRT_MAX__
#	define Q_COMPILER_CONSTANT_SHORT_MAXIMUM __SHRT_MAX__
#endif

#ifdef __SIZEOF_INT__
#	define Q_COMPILER_CONSTANT_UINT_SIZE __SIZEOF_INT__
#	define Q_COMPILER_CONSTANT_INT_SIZE  __SIZEOF_INT__
#endif

#ifdef __INT_MAX__
#	define Q_COMPILER_CONSTANT_INT_MAXIMUM __INT_MAX__
#endif

#ifdef __SIZEOF_LONG__
#	define Q_COMPILER_CONSTANT_ULONG_SIZE __SIZEOF_LONG__
#	define Q_COMPILER_CONSTANT_LONG_SIZE  __SIZEOF_LONG__
#endif

#ifdef __LONG_MAX__
#	define Q_COMPILER_CONSTANT_LONG_MAXIMUM __LONG_MAX__
#endif

#ifdef __SIZEOF_LONG_LONG__
#	define Q_COMPILER_CONSTANT_ULLONG_SIZE __SIZEOF_LONG_LONG__
#	define Q_COMPILER_CONSTANT_LLONG_SIZE  __SIZEOF_LONG_LONG__
#endif

#ifdef __LONG_LONG_MAX__
#	define Q_COMPILER_CONSTANT_LLONG_MAXIMUM __LONG_LONG_MAX__
#endif

#ifdef __SIZEOF_FLOAT__
#	define Q_COMPILER_CONSTANT_FLOAT_SIZE __SIZEOF_FLOAT__
#endif

#ifdef __FLT_EPSILON__
#	define Q_COMPILER_CONSTANT_FLOAT_EPSILON __FLT_EPSILON__
#endif

#ifdef __FLT_MIN__
#	define Q_COMPILER_CONSTANT_FLOAT_MINIMUM __FLT_MIN__
#endif

#ifdef __FLT_MAX__
#	define Q_COMPILER_CONSTANT_FLOAT_MAXIMUM __FLT_MAX__
#endif

#ifdef __FLT_DIG__
#	define Q_COMPILER_CONSTANT_FLOAT_DECIMAL_DIGITS __FLT_DIG__
#endif

#ifdef __FLT_MANT_DIG__
#	define Q_COMPILER_CONSTANT_FLOAT_MANTISSA_DIGITS __FLT_MANT_DIG__
#endif

#ifdef __FLT_RADIX__
#	define Q_COMPILER_CONSTANT_FLOAT_EXPONENT_RADIX __FLT_RADIX__
#endif

#ifdef __FLT_MIN_EXP__
#	define Q_COMPILER_CONSTANT_FLOAT_EXPONENT_MINIMUM __FLT_MIN_EXP__
#endif

#ifdef __FLT_MAX_EXP__
#	define Q_COMPILER_CONSTANT_FLOAT_EXPONENT_MAXIMUM __FLT_MAX_EXP__
#endif

#ifdef __FLT_MIN_10_EXP__
#	define Q_COMPILER_CONSTANT_FLOAT_EXPONENT_10_MINIMUM __FLT_MIN_10_EXP__
#endif

#ifdef __FLT_MAX_10_EXP__
#	define Q_COMPILER_CONSTANT_FLOAT_EXPONENT_10_MAXIMUM __FLT_MAX_10_EXP__
#endif

#ifdef __SIZEOF_DOUBLE__
#	define Q_COMPILER_CONSTANT_DOUBLE_SIZE __SIZEOF_DOUBLE__
#endif

#ifdef __DBL_EPSILON__
#	define Q_COMPILER_CONSTANT_DOUBLE_EPSILON __DBL_EPSILON__
#endif

#ifdef __DBL_MIN__
#	define Q_COMPILER_CONSTANT_DOUBLE_MINIMUM __DBL_MIN__
#endif

#ifdef __DBL_MAX__
#	define Q_COMPILER_CONSTANT_DOUBLE_MAXIMUM __DBL_MAX__
#endif

#ifdef __DBL_DIG__
#	define Q_COMPILER_CONSTANT_DOUBLE_DECIMAL_DIGITS __DBL_DIG__
#endif

#ifdef __DBL_MANT_DIG__
#	define Q_COMPILER_CONSTANT_DOUBLE_MANTISSA_DIGITS __DBL_MANT_DIG__
#endif

#ifdef __DBL_RADIX__
#	define Q_COMPILER_CONSTANT_DOUBLE_EXPONENT_RADIX __DBL_RADIX__
#endif

#ifdef __DBL_MIN_EXP__
#	define Q_COMPILER_CONSTANT_DOUBLE_EXPONENT_MINIMUM __DBL_MIN_EXP__
#endif

#ifdef __DBL_MAX_EXP__
#	define Q_COMPILER_CONSTANT_DOUBLE_EXPONENT_MAXIMUM __DBL_MAX_EXP__
#endif

#ifdef __DBL_MIN_10_EXP__
#	define Q_COMPILER_CONSTANT_DOUBLE_EXPONENT_10_MINIMUM __DBL_MIN_10_EXP__
#endif

#ifdef __DBL_MAX_10_EXP__
#	define Q_COMPILER_CONSTANT_DOUBLE_EXPONENT_10_MAXIMUM __DBL_MAX_10_EXP__
#endif

#ifdef __SIZEOF_LONG_DOUBLE__
#	define Q_COMPILER_CONSTANT_LDOUBLE_SIZE __SIZEOF_LONG_DOUBLE__
#endif

#ifdef __LDBL_EPSILON__
#	define Q_COMPILER_CONSTANT_LDOUBLE_EPSILON __LDBL_EPSILON__
#endif

#ifdef __LDBL_MIN__
#	define Q_COMPILER_CONSTANT_LDOUBLE_MINIMUM __LDBL_MIN__
#endif

#ifdef __LDBL_MAX__
#	define Q_COMPILER_CONSTANT_LDOUBLE_MAXIMUM __LDBL_MAX__
#endif

#ifdef __LDBL_DIG__
#	define Q_COMPILER_CONSTANT_LDOUBLE_DECIMAL_DIGITS __LDBL_DIG__
#endif

#ifdef __LDBL_MANT_DIG__
#	define Q_COMPILER_CONSTANT_LDOUBLE_MANTISSA_DIGITS __LDBL_MANT_DIG__
#endif

#ifdef __LDBL_RADIX__
#	define Q_COMPILER_CONSTANT_LDOUBLE_EXPONENT_RADIX __LDBL_RADIX__
#endif

#ifdef __LDBL_MIN_EXP__
#	define Q_COMPILER_CONSTANT_LDOUBLE_EXPONENT_MINIMUM __LDBL_MIN_EXP__
#endif

#ifdef __LDBL_MAX_EXP__
#	define Q_COMPILER_CONSTANT_LDOUBLE_EXPONENT_MAXIMUM __LDBL_MAX_EXP__
#endif

#ifdef __LDBL_MIN_10_EXP__
#	define Q_COMPILER_CONSTANT_LDOUBLE_EXPONENT_10_MINIMUM __LDBL_MIN_10_EXP__
#endif

#ifdef __LDBL_MAX_10_EXP__
#	define Q_COMPILER_CONSTANT_LDOUBLE_EXPONENT_10_MAXIMUM __LDBL_MAX_10_EXP__
#endif

#ifdef __SIZE_WIDTH__
#	define Q_COMPILER_CONSTANT_SIZE_BITS  __SIZE_WIDTH__
#	define Q_COMPILER_CONSTANT_SSIZE_BITS __SIZE_WIDTH__
#endif

#ifdef __SIZEOF_SIZE_T__
#	define Q_COMPILER_CONSTANT_SIZE_SIZE  __SIZEOF_SIZE_T__
#	define Q_COMPILER_CONSTANT_SSIZE_SIZE __SIZEOF_SIZE_T__
#endif

#ifdef __SIZE_MAX__
#	define Q_COMPILER_CONSTANT_SIZE_MAXIMUM __SIZE_MAX__
#endif

#ifdef __INTMAX_WIDTH__
#	define Q_COMPILER_CONSTANT_UINTMAX_BITS __INTMAX_WIDTH__
#	define Q_COMPILER_CONSTANT_INTMAX_BITS	__INTMAX_WIDTH__
#endif

#ifdef __INTMAX_MAX__
#	define Q_COMPILER_CONSTANT_INTMAX_MAXIMUM __INTMAX_MAX__
#endif

#if defined(__INTPTR_WIDTH__)
#	define Q_COMPILER_CONSTANT_UINTPTR_BITS __INTPTR_WIDTH__
#	define Q_COMPILER_CONSTANT_INTPTR_BITS	__INTPTR_WIDTH__
#elif defined(__POINTER_WIDTH__)
#	define Q_COMPILER_CONSTANT_UINTPTR_BITS __POINTER_WIDTH__
#	define Q_COMPILER_CONSTANT_INTPTR_BITS	__POINTER_WIDTH__
#endif

#ifdef __SIZEOF_POINTER__
#	define Q_COMPILER_CONSTANT_UINTPTR_SIZE __SIZEOF_POINTER__
#	define Q_COMPILER_CONSTANT_INTPTR_SIZE	__SIZEOF_POINTER__
#endif

/* MARK: - Built-in types */

#ifdef __UINT8_TYPE__
#	define Q_COMPILER_TYPE_UINT8 unsigned __UINT8_TYPE__
#	define Q_COMPILER_TYPE_INT8  signed   __UINT8_TYPE__
#endif

#ifdef __UINT16_TYPE__
#	define Q_COMPILER_TYPE_UINT16 unsigned __UINT16_TYPE__
#	define Q_COMPILER_TYPE_INT16  signed   __UINT16_TYPE__
#endif

#ifdef __UINT32_TYPE__
#	define Q_COMPILER_TYPE_UINT32 unsigned __UINT32_TYPE__
#	define Q_COMPILER_TYPE_INT32  signed   __UINT32_TYPE__
#endif

#ifdef __UINT64_TYPE__
#	define Q_COMPILER_TYPE_UINT64 unsigned __UINT64_TYPE__
#	define Q_COMPILER_TYPE_INT64  signed   __UINT64_TYPE__
#endif

#ifdef __SIZEOF_INT128__
#	define Q_COMPILER_TYPE_UINT128 __uint128_t
#	define Q_COMPILER_TYPE_INT128  __int128_t
#endif

#ifdef __SIZE_TYPE__
#	define Q_COMPILER_TYPE_SIZE __SIZE_TYPE__
/*#	define Q_COMPILER_TYPE_SSIZE*/
#endif

#ifdef __INTMAX_TYPE__
#	define Q_COMPILER_TYPE_UINTMAX unsigned __INTMAX_TYPE__
#	define Q_COMPILER_TYPE_INTMAX  signed	__INTMAX_TYPE__
#endif

#ifdef __INTPTR_TYPE__
#	define Q_COMPILER_TYPE_UINTPTR unsigned __INTPTR_TYPE__
#	define Q_COMPILER_TYPE_INTPTR  signed	__INTPTR_TYPE__
#endif

#define Q_COMPILER_TYPE_VAL __builtin_va_list

/* MARK: - Built-in functions: Struture */

#define Q_COMPILER_FUNCTION_OFFSETOF __builtin_offsetof

/* MARK: - Built-in functions: VAL */

#define Q_COMPILER_FUNCTION_VAL_INITIALIZE __builtin_va_start
#define Q_COMPILER_FUNCTION_VAL_FINALIZE   __builtin_va_end
#define Q_COMPILER_FUNCTION_VAL_READ	   __builtin_va_arg

#if __has_builtin(__builtin_va_copy)
#	define Q_COMPILER_FUNCTION_VAL_COPY(object, output) __builtin_va_copy(output, object)
#endif

/* MARK: - Built-in functions: Atomic operations */

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

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SET
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SET
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SET
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SET
#	define Q_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SET
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SET
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SET
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SET
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SET
#	define Q_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_SET

#if __has_builtin(__sync_fetch_and_add)
#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_INCREMENT(  pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD  __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_ADD __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_ADD __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_ADD __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_ADD   __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_ADD  __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_ADD  __sync_fetch_and_add
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_ADD  __sync_fetch_and_add
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

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SUBTRACT  __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SUBTRACT   __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SUBTRACT  __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SUBTRACT  __sync_fetch_and_sub
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SUBTRACT  __sync_fetch_and_sub
#endif

#if __has_builtin(__sync_fetch_and_and)
#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_AND   __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#endif

#if __has_builtin(__sync_fetch_and_or)
#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_OR   __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#endif

#if __has_builtin(__sync_fetch_and_xor)
#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_XOR   __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#endif

#if __has_builtin(__sync_fetch_and_nand)
#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_NAND   __sync_fetch_and_nand
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
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

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_ADD_THEN_GET  __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_ADD_THEN_GET __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_ADD_THEN_GET __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_ADD_THEN_GET __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_ADD_THEN_GET   __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_ADD_THEN_GET  __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_ADD_THEN_GET  __sync_add_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_ADD_THEN_GET  __sync_add_and_fetch
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

#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_SUBTRACT_THEN_GET  __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_SUBTRACT_THEN_GET   __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_SUBTRACT_THEN_GET  __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_SUBTRACT_THEN_GET  __sync_sub_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_SUBTRACT_THEN_GET  __sync_sub_and_fetch
#endif

#if __has_builtin(__sync_and_and_fetch)
#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_AND_THEN_GET   __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#endif

#if __has_builtin(__sync_or_and_fetch)
#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_OR_THEN_GET   __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#endif

#if __has_builtin(__sync_xor_and_fetch)
#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_XOR_THEN_GET   __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#endif

#if __has_builtin(__sync_nand_and_fetch)
#	define Q_COMPILER_FUNCTION_UINT8_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	define Q_COMPILER_FUNCTION_UINT16_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#	define Q_COMPILER_FUNCTION_UINT32_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#	define Q_COMPILER_FUNCTION_UINT64_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#	define Q_COMPILER_FUNCTION_INT8_ATOMIC_NAND_THEN_GET   __sync_nand_and_fetch
#	define Q_COMPILER_FUNCTION_INT16_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	define Q_COMPILER_FUNCTION_INT32_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	define Q_COMPILER_FUNCTION_INT64_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#endif

#endif /* __Q_inspection_private_compiler_H__ */
