/* Z Kit C API - inspection/private/compiler/GCC.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_private_compiler_GCC_H__
#define __Z_inspection_private_compiler_GCC_H__

/* MARK: - Identification */

#ifndef Z_COMPILER
#	include <Z/keys/compiler.h>
#	include <Z/macros/version.h>

#	define Z_COMPILER		  Z_COMPILER_GCC
#	define Z_COMPILER_STRING	  Z_COMPILER_STRING_GCC
#	define Z_COMPILER_VERSION	  Z_VERSION(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#	define Z_COMPILER_VERSION_STRING __VERSION__
#endif

/* MARK: - Bit field encoding */

#include <Z/keys/order.h>

#define Z_COMPILER_LITTLE_ENDIAN_8BIT_FIELD_ORDER Z_ORDER_REVERSED
#define Z_COMPILER_LITTLE_ENDIAN_BIT_FIELD_ORDER  Z_ORDER_REVERSED
#define Z_COMPILER_BIG_ENDIAN_8BIT_FIELD_ORDER    Z_ORDER_NORMAL
#define Z_COMPILER_BIG_ENDIAN_BIT_FIELD_ORDER     Z_ORDER_NORMAL

/* MARK: - C features */

#ifdef __BLOCKS__
#	define Z_COMPILER_C_HAS_CLOSURE
#endif

/* MARK: - C types */

#define Z_COMPILER_C_HAS_TYPE_LLONG
#define Z_COMPILER_C_HAS_TYPE_LDOUBLE

/* MARK: - C attributes */

#define Z_COMPILER_C_ATTRIBUTE_ALIAS(name)	 __attribute__((alias(name)))

#if __GNUC__ >= 4
#	define Z_COMPILER_C_ATTRIBUTE_INLINE	 static __inline__ __attribute__((always_inline))
#else
#	define Z_COMPILER_C_ATTRIBUTE_INLINE	 static __inline__
#endif

#define Z_COMPILER_C_ATTRIBUTE_THREAD_LOCAL	 __thread
#define Z_COMPILER_C_ATTRIBUTE_PRIVATE		 __attribute__((visibility("hidden"))) static
#define Z_COMPILER_C_ATTRIBUTE_PUBLIC		 __attribute__((visibility("default")))
#define Z_COMPILER_C_ATTRIBUTE_STRICT_SIZE_BEGIN
#define Z_COMPILER_C_ATTRIBUTE_STRICT_SIZE_END	 __attribute__((packed))
#define Z_COMPILER_C_ATTRIBUTE_WEAK		 __attribute__((weak))

/* MARK: - Built-in constants */

/* MARK: - Built-in types */

#ifdef __SIZEOF_INT128__
#	define Z_COMPILER_TYPE_UINT128 __uint128_t
#	define Z_COMPILER_TYPE_INT128  __int128_t
#endif

#define Z_COMPILER_TYPE_VAL __builtin_va_list

/* MARK: - Built-in functions: Struture */

#define Z_COMPILER_FUNCTION_OFFSETOF __builtin_offsetof

/* MARK: - Built-in functions: VAL */

#define Z_COMPILER_FUNCTION_VAL_INITIALIZE __builtin_va_start
#define Z_COMPILER_FUNCTION_VAL_FINALIZE   __builtin_va_end
#define Z_COMPILER_FUNCTION_VAL_READ	   __builtin_va_arg

#if __STDC_VERSION__ >= 199900L || !defined(__STRICT_ANSI__)
#	define Z_COMPILER_FUNCTION_VAL_COPY(object, output) __builtin_va_copy(output, object)
#endif

/* MARK: - Built-in functions: Atomic operations */

#if Z_COMPILER_VERSION >= Z_VERSION(4, 1, 0)

#	ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SET_IF_EQUAL	     __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_SET_IF_EQUAL	     __sync_bool_compare_and_swap
#	endif

#	ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SET_IF_EQUAL	     __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_SET_IF_EQUAL	     __sync_bool_compare_and_swap
#	endif

#	ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SET_IF_EQUAL	     __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_SET_IF_EQUAL	     __sync_bool_compare_and_swap
#	endif

#	ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SET_IF_EQUAL	     __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_SET_IF_EQUAL	     __sync_bool_compare_and_swap
#	endif

#	ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_SET_IF_EQUAL	     __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_SET_IF_EQUAL	     __sync_bool_compare_and_swap
#	endif

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_INCREMENT(  pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_DECREMENT(  pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_AND		     __sync_fetch_and_and

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_OR		     __sync_fetch_and_or

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_XOR		     __sync_fetch_and_xor

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_INCREMENT_THEN_GET(  pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_DECREMENT_THEN_GET(  pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_AND_THEN_GET		     __sync_and_and_fetch

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_OR_THEN_GET		     __sync_or_and_fetch

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_XOR_THEN_GET		     __sync_xor_and_fetch

#endif

#endif /* __Z_inspection_private_compiler_GCC_H__ */
