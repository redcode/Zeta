/* Z Kit C API - inspection/private/compiler/Clang.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_private_compiler_Clang_H__
#define __Z_inspection_private_compiler_Clang_H__

#include <Z/keys/order.h>
#include <Z/macros/pasting.h>

/* MARK: - Identification */

#ifndef Z_COMPILER
#	include <Z/keys/compiler.h>
#	include <Z/macros/version.h>

#	define Z_COMPILER		  Z_COMPILER_CLANG
#	define Z_COMPILER_STRING	  Z_COMPILER_STRING_CLANG
#	define Z_COMPILER_VERSION	  Z_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#	define Z_COMPILER_VERSION_STRING __clang_version__
#endif

#ifndef __has_extension
#	define __has_extension __has_feature /* Compatibility with Clang < v3.0 */
#endif

/* MARK: - Data model */

/*#define Z_COMPILER_DATA_MODEL*/

/* MARK: - Bit field order */

#define Z_COMPILER_LITTLE_ENDIAN_8BIT_FIELD_ORDER Z_ORDER_REVERSED
#define Z_COMPILER_LITTLE_ENDIAN_BIT_FIELD_ORDER  Z_ORDER_REVERSED
#define Z_COMPILER_BIG_ENDIAN_8BIT_FIELD_ORDER	  Z_ORDER_NORMAL
#define Z_COMPILER_BIG_ENDIAN_BIT_FIELD_ORDER	  Z_ORDER_NORMAL

/* MARK: - K&R C support */

#define Z_COMPILER_C_HAS_TYPE_FLOAT
#define Z_COMPILER_C_HAS_TYPE_DOUBLE
#define Z_COMPILER_C_HAS_STORAGE_CLASS_AUTO
#define Z_COMPILER_C_HAS_STORAGE_CLASS_EXTERN
#define Z_COMPILER_C_HAS_STORAGE_CLASS_REGISTER
#define Z_COMPILER_C_HAS_STORAGE_CLASS_STATIC
#define Z_COMPILER_C_HAS_OPERATOR_SIZE_OF

/* MARK: - C89 support */

#define Z_COMPILER_C_HAS_ENUMERATION
#define Z_COMPILER_C_HAS_VOID_POINTER
#define Z_COMPILER_C_HAS_TYPE_LDOUBLE
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_CONSTANT
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_VOLATILE

/* MARK: - C90 support */

/* MARK: - C94 support */

#define Z_COMPILER_C_HAS_DIGRAPH

/* MARK: - C99 support */

#define Z_COMPILER_C_HAS_COMPOUND_LITERAL /* TODO: is this always supported? */
#define Z_COMPILER_C_HAS_CPP_STYLE_COMMENT
#define Z_COMPILER_C_HAS_DESIGNATED_INITIALIZER
/*#define Z_COMPILER_C_HAS_FLEXIBLE_ARRAY_MEMBER*/
#define Z_COMPILER_C_HAS_INLINE_FUNCION
/*#define Z_COMPILER_C_HAS_INTERMINGLED_DECLARATIONS_AND_CODE*/
#define Z_COMPILER_C_HAS_VARIADIC_MACRO
/*#define Z_COMPILER_C_HAS_VLA*/
#define Z_COMPILER_C_HAS_TYPE_ULLONG
#define Z_COMPILER_C_HAS_TYPE_LLONG
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_RESTRICT
#define Z_COMPILER_C_HAS_SPECIFIER_INLINE

/* MARK: - C11 support */

#if Z_COMPILER_VERSION >= Z_VERSION(3, 1, 0)
#	define Z_COMPILER_C_HAS_ANONYMOUS_STRUCTURE
#	define Z_COMPILER_C_HAS_ANONYMOUS_UNION
#else
#	define Z_COMPILER_C_LACKS_ANONYMOUS_STRUCTURE
#	define Z_COMPILER_C_LACS_ANONYMOUS_UNION
#endif

#if __has_feature(c_atomic) || __has_extension(c_atomic)
#	define Z_COMPILER_C_HAS_ATOMIC_OPERATIONS
#else
#	define Z_COMPILER_C_LACKS_ATOMIC_OPERATIONS
#endif

#if __has_feature(c_generic_selections) || __has_extension(c_generic_selections)
#	define Z_COMPILER_C_HAS_GENERIC_SELECTION
#else
#	define Z_COMPILER_C_LACKS_GENERIC_SELECTION
#endif

#if __has_feature(c_static_assert) || __has_extension(c_static_assert)
#	define Z_COMPILER_C_HAS_STATIC_ASSERTION
#else
#	define Z_COMPILER_C_LACKS_STATIC_ASSERTION
#endif

#if __has_feature(c_atomic) || __has_extension(c_atomic)
#	define Z_COMPILER_C_HAS_TYPE_QUALIFIER_ATOMIC
#else
#	define Z_COMPILER_C_LACKS_TYPE_QUALIFIER_ATOMIC
#endif

#if __has_feature(c_thread_local) || __has_extension(c_thread_local)
#	define Z_COMPILER_C_HAS_STORATE_CLASS_THREAD_LOCAL
#else
#	define Z_COMPILER_C_LACKS_STORATE_CLASS_THREAD_LOCAL
#endif

#if __has_feature(c_atomic) || __has_extension(c_atomic)
#	define Z_COMPILER_C_HAS_SPECIFIER_ATOMIC
#else
#	define Z_COMPILER_C_LACKS_SPECIFIER_ATOMIC
#endif

#if __has_feature(c_alignas) || __has_extension(c_alignas)
#	define Z_COMPILER_C_HAS_SPECIFIER_ALIGN_AS
#else
#	define Z_COMPILER_C_LACKS_SPECIFIER_ALIGN_AS
#endif

/*#define Z_COMPILER_C_HAS_SPECIFIER_NO_RETURN*/

#if __has_feature(c_alignof) || __has_extension(c_alignof)
#	define Z_COMPILER_C_HAS_OPERATOR_ALIGN_OF
#endif

/* MARK: - Apple C extensions support */

#if __has_extension(blocks)
#	define Z_COMPILER_C_HAS_CLOSURE
#else
#	define Z_COMPILER_C_HAS_CLOSURE
#endif

/* MARK: - C attributes */

#if __has_attribute(alias)
#	define Z_COMPILER_C_ATTRIBUTE_ALIAS(name) __attribute__((alias(name)))
#endif

/*#define Z_COMPILER_C_ATTRIBUTE_API*/
/*#define Z_COMPILER_C_ATTRIBUTE_API_ALIAS*/
/*#define Z_COMPILER_C_ATTRIBUTE_API_EXPORT*/
/*#define Z_COMPILER_C_ATTRIBUTE_API_EXPORT_ALIAS*/
/*#define Z_COMPILER_C_ATTRIBUTE_API_WEAK_EXPORT*/

#if __has_attribute(always_inline)
#	define Z_COMPILER_C_ATTRIBUTE_INLINE static __inline__ __attribute__((always_inline))
#else
#	define Z_COMPILER_C_ATTRIBUTE_INLINE static __inline__
#endif

#if __has_attribute(noreturn)
#	define Z_COMPILER_C_ATTRIBUTE_NO_RETURN __attribute__((noreturn))
#endif

#if __has_attribute(sentinel)
#	define Z_COMPILER_C_ATTRIBUTE_NULL_TERMINATED __attribute__((sentinel))
#endif

#if __has_attribute(visibility)
#	define Z_COMPILER_C_ATTRIBUTE_PRIVATE __attribute__((visibility("hidden"))) static
#	define Z_COMPILER_C_ATTRIBUTE_PUBLIC  __attribute__((visibility("default")))
#endif

#if __has_attribute(packed)
#	define Z_COMPILER_C_ATTRIBUTE_STRICT_SIZE_BEGIN
#	define Z_COMPILER_C_ATTRIBUTE_STRICT_SIZE_END __attribute__((packed))
#endif

#if __has_feature(c_thread_local) || __has_extension(c_thread_local)
#	define Z_COMPILER_C_ATTRIBUTE_THREAD_LOCAL _Thread_local
#elif __has_extension(tls)
#	define Z_COMPILER_C_ATTRIBUTE_THREAD_LOCAL __thread
#endif

#if __has_attribute(weak)
#	define Z_COMPILER_C_ATTRIBUTE_WEAK __attribute__((weak))
#endif

#if defined(__cplusplus)

	/* MARK: - C++11 support */

#	define Z_COMPILER_CPP_HAS_C99_PREPROCESSOR

	/*#define Z_COMPILER_CPP_HAS_EXPRESSION_SFINAE*/

#	if __has_feature(cxx_generalized_initializers)
#		define Z_COMPILER_CPP_HAS_INITIALIZER_LIST
#	else
#		define Z_COMPILER_CPP_LACKS_INITIALIZER_LIST
#	endif

#	if __has_feature(cxx_nonstatic_member_init)
#		define Z_COMPILER_CPP_HAS_NON_STATIC_DATA_MEMBER_INITIALIZER
#	else
#		define Z_COMPILER_CPP_LACKS_NON_STATIC_DATA_MEMBER_INITIALIZER
#	endif

#	if __has_feature(cxx_lambdas) || __has_extension(cxx_lambdas)
#		define Z_COMPILER_CPP_HAS_LAMBDA
#	else
#		define Z_COMPILER_CPP_LACKS_LAMBDA
#	endif

#	if __has_feature(cxx_reference_qualified_functions) || __has_extension(cxx_reference_qualified_functions)
#		define Z_COMPILER_CPP_HAS_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION
#	else
#		define Z_COMPILER_CPP_HAS_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION
#	endif

#	if __has_feature(cxx_rvalue_references) || __has_extension(cxx_rvalue_references)
#		define Z_COMPILER_CPP_HAS_RVALUE_REFERENCE
#	else
#		define Z_COMPILER_CPP_LACKS_RVALUE_REFERENCE
#	endif

	/*#define Z_COMPILER_CPP_HAS_STATIC_CONSTANT_DATA_MEMBER_INITIALIZER*/

#	if __has_feature(cxx_strong_enums) || __has_extension(cxx_strong_enums)
#		define Z_COMPILER_CPP_HAS_STRONGLY_TYPED_ENUMERATION
#	else
#		define Z_COMPILER_CPP_LACKS_STRONGLY_TYPED_ENUMERATION
#	endif

#	if __has_feature(cxx_trailing_return) || __has_extension(cxx_trailing_return)
#		define Z_COMPILER_CPP_HAS_TRAILING_RETURN_TYPE
#	else
#		define Z_COMPILER_CPP_HAS_TRAILING_RETURN_TYPE
#	endif

#	if __has_feature(cxx_variadic_templates) || __has_extension(cxx_variadic_templates)
#		define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE
#		define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE_EXTENDED_PARAMETERS
#	else
#		define Z_COMPILER_CPP_LACKS_VARIADIC_TEMPLATE
#		define Z_COMPILER_CPP_LACKS_VARIADIC_TEMPLATE_EXTENDED_PARAMETERS
#	endif

	#define Z_COMPILER_CPP_HAS_TYPE_ULLONG
	#define Z_COMPILER_CPP_HAS_TYPE_LLONG

#	if __has_feature(cxx_alignas) || __has_extension(cxx_alignas)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_ALIGN_AS
#	else
#		define Z_COMPILER_CPP_LACKS_SPECIFIER_ALIGN_AS
#	endif

#	if __has_feature(cxx_auto_type) || __has_extension(cxx_auto_type)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_AUTO
#	else
#		define Z_COMPILER_CPP_LACKS_SPECIFIER_AUTO
#	endif

#	if __has_feature(cxx_constexpr)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_CONSTANT_EXPRESSION
#	else
#		define Z_COMPILER_CPP_LACKS_SPECIFIER_CONSTANT_EXPRESSION
#	endif

#	if __has_feature(cxx_decltype) || __has_extension(cxx_decltype)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_DECLARED_TYPE
#	else
#		define Z_COMPILER_CPP_LACKS_SPECIFIER_DECLARED_TYPE
#	endif

#	if __has_feature(cxx_decltype_incomplete_return_types) || __has_extension(cxx_decltype_incomplete_return_types)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_DECLARED_TYPE_INCOMPLETE_RETURN
#	else
#		define Z_COMPILER_CPP_LACKS_SPECIFIER_DECLARED_TYPE_INCOMPLETE_RETURN
#	endif

#	if __has_feature(cxx_noexcept) || __has_extension(cxx_noexcept)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_NO_EXCEPTION
#	else
#		define Z_COMPILER_CPP_LACKS_SPECIFIER_NO_EXCEPTION
#	endif

#	if __has_feature(cxx_alignof) || __has_extension(cxx_alignof)
#		define Z_COMPILER_CPP_HAS_OPERATOR_ALIGN_OF
#	else
#		define Z_COMPILER_CPP_LACKS_OPERATOR_ALIGN_OF
#	endif

#	if __has_feature(cxx_noexcept) || __has_extension(cxx_noexcept)
#		define Z_COMPILER_CPP_HAS_OPERATOR_NO_EXCEPTION
#	else
#		define Z_COMPILER_CPP_LACKS_OPERATOR_NO_EXCEPTION
#	endif

#	if __has_feature(cxx_nullptr) || __has_extension(cxx_nullptr)
#		define Z_COMPILER_CPP_HAS_LITERAL_NULL_POINTER
#	else
#		define Z_COMPILER_CPP_LACKS_LITERAL_NULL_POINTER
#	endif

	/* MARK: - C++ attributes */

#	if __has_attribute(always_inline)
#		define Z_COMPILER_CPP_ATTRIBUTE_INLINE_MEMBER __inline__ __attribute__((always_inline))
#	else
#		define Z_COMPILER_CPP_ATTRIBUTE_INLINE_MEMBER __inline__
#	endif

#endif

/* MARK: - Built-in constants */

/*#define Z_COMPILER_CONSTANT_FLOAT16_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT16_NAN*/

/*#define Z_COMPILER_CONSTANT_FLOAT24_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT24_NAN*/

/*#define Z_COMPILER_CONSTANT_FLOAT32_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT32_NAN*/

/*#define Z_COMPILER_CONSTANT_FLOAT48_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT48_NAN*/

/*#define Z_COMPILER_CONSTANT_FLOAT64_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT64_NAN*/

/*#define Z_COMPILER_CONSTANT_FLOAT72_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT72_NAN*/

/*#define Z_COMPILER_CONSTANT_FLOAT80_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT80_NAN*/

/*#define Z_COMPILER_CONSTANT_FLOAT96_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT96_NAN*/

/*#define Z_COMPILER_CONSTANT_FLOAT128_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT128_NAN*/

#ifdef __CHAR_BIT__
#	define Z_COMPILER_CONSTANT_UCHAR_BITS  __CHAR_BIT__
#	define Z_COMPILER_CONSTANT_UCHAR_SIZE (__CHAR_BIT__ / 8)
#	define Z_COMPILER_CONSTANT_CHAR_BITS   __CHAR_BIT__
#	define Z_COMPILER_CONSTANT_CHAR_SIZE  (__CHAR_BIT__ / 8)
#endif

#ifdef __SCHAR_MAX__
#	define Z_COMPILER_CONSTANT_UCHAR_MAXIMUM ( __SCHAR_MAX__ * 2 + 1)
#	define Z_COMPILER_CONSTANT_CHAR_MINIMUM  (-__SCHAR_MAX__ - 1)
#	define Z_COMPILER_CONSTANT_CHAR_MAXIMUM	   __SCHAR_MAX__
#endif

#ifdef __SIZEOF_SHORT__
#	define Z_COMPILER_CONSTANT_USHORT_BITS (__SIZEOF_SHORT__ * 8)
#	define Z_COMPILER_CONSTANT_USHORT_SIZE	__SIZEOF_SHORT__
#	define Z_COMPILER_CONSTANT_SHORT_BITS  (__SIZEOF_SHORT__ * 8)
#	define Z_COMPILER_CONSTANT_SHORT_SIZE	__SIZEOF_SHORT__
#endif

#ifdef __SHRT_MAX__
#	define Z_COMPILER_CONSTANT_USHORT_MAXIMUM ( __SHRT_MAX__ * 2 + 1)
#	define Z_COMPILER_CONSTANT_SHORT_MINIMUM  (-__SHRT_MAX__ - 1)
#	define Z_COMPILER_CONSTANT_SHORT_MAXIMUM    __SHRT_MAX__
#endif

#ifdef __SIZEOF_INT__
#	define Z_COMPILER_CONSTANT_UINT_BITS (__SIZEOF_INT__ * 8)
#	define Z_COMPILER_CONSTANT_UINT_SIZE  __SIZEOF_INT__
#	define Z_COMPILER_CONSTANT_INT_BITS  (__SIZEOF_INT__ * 8)
#	define Z_COMPILER_CONSTANT_INT_SIZE   __SIZEOF_INT__
#endif

#ifdef __INT_MAX__
#	define Z_COMPILER_CONSTANT_UINT_MAXIMUM ( __INT_MAX__ * 2 + 1)
#	define Z_COMPILER_CONSTANT_INT_MINIMUM	(-__INT_MAX__ - 1)
#	define Z_COMPILER_CONSTANT_INT_MAXIMUM	  __INT_MAX__
#endif

#ifdef __SIZEOF_LONG__
#	define Z_COMPILER_CONSTANT_ULONG_BITS (__SIZEOF_LONG__ * 8)
#	define Z_COMPILER_CONSTANT_ULONG_SIZE  __SIZEOF_LONG__
#	define Z_COMPILER_CONSTANT_LONG_BITS  (__SIZEOF_LONG__ * 8)
#	define Z_COMPILER_CONSTANT_LONG_SIZE   __SIZEOF_LONG__
#endif

/*#define Z_COMPILER_CONSTANT_ULONG_MAXIMUM*/

#ifdef __LONG_MAX__
#	define Z_COMPILER_CONSTANT_LONG_MINIMUM (-__LONG_MAX__ - 1L)
#	define Z_COMPILER_CONSTANT_LONG_MAXIMUM	  __LONG_MAX__
#endif

#ifdef __SIZEOF_LONG_LONG__
#	define Z_COMPILER_CONSTANT_ULLONG_BITS (__SIZEOF_LONG_LONG__ * 8)
#	define Z_COMPILER_CONSTANT_ULLONG_SIZE	__SIZEOF_LONG_LONG__
#	define Z_COMPILER_CONSTANT_LLONG_BITS  (__SIZEOF_LONG_LONG__ * 8)
#	define Z_COMPILER_CONSTANT_LLONG_SIZE	__SIZEOF_LONG_LONG__
#endif

/*#define Z_COMPILER_CONSTANT_ULLONG_MAXIMUM*/

#ifdef __LONG_LONG_MAX__
#	define Z_COMPILER_CONSTANT_LLONG_MINIMUM (-__LONG_LONG_MAX__ - 1LL)
#	define Z_COMPILER_CONSTANT_LLONG_MAXIMUM   __LONG_LONG_MAX__
#endif

#ifdef __SIZEOF_FLOAT__
#	define Z_COMPILER_CONSTANT_FLOAT_BITS (__SIZEOF_FLOAT__ * 8)
#	define Z_COMPILER_CONSTANT_FLOAT_SIZE  __SIZEOF_FLOAT__
#endif

#ifdef __SIZEOF_DOUBLE__
#	define Z_COMPILER_CONSTANT_DOUBLE_BITS (__SIZEOF_DOUBLE__ * 8)
#	define Z_COMPILER_CONSTANT_DOUBLE_SIZE	__SIZEOF_DOUBLE__
#endif

#ifdef __SIZEOF_LONG_DOUBLE__
#	define Z_COMPILER_CONSTANT_LDOUBLE_BITS (__SIZEOF_LONG_DOUBLE__ * 8)
#	define Z_COMPILER_CONSTANT_LDOUBLE_SIZE	 __SIZEOF_LONG_DOUBLE__
#endif

#if __has_builtin(__builtin_huge_valf)
#	define Z_COMPILER_CONSTANT_FLOAT_INFINITY __builtin_huge_valf()
#elif __has_builtin(__builtin_inff)
#	define Z_COMPILER_CONSTANT_FLOAT_INFINITY __builtin_inff()
#endif

#if __has_builtin(__builtin_nanf)
#	define Z_COMPILER_CONSTANT_FLOAT_NAN __builtin_nanf("")
#endif

#if __has_builtin(__builtin_huge_val)
#	define Z_COMPILER_CONSTANT_DOUBLE_INFINITY __builtin_huge_val()
#elif __has_builtin(__builtin_inf)
#	define Z_COMPILER_CONSTANT_DOUBLE_INFINITY __builtin_inf()
#endif

#if __has_builtin(__builtin_nan)
#	define Z_COMPILER_CONSTANT_DOUBLE_NAN __builtin_nan("")
#endif

#if __has_builtin(__builtin_huge_vall)
#	define Z_COMPILER_CONSTANT_LDOUBLE_INFINITY __builtin_huge_vall()
#elif __has_builtin(__builtin_infl)
#	define Z_COMPILER_CONSTANT_LDOUBLE_INFINITY __builtin_infl()
#endif

#if __has_builtin(__builtin_nanl)
#	define Z_COMPILER_CONSTANT_LDOUBLE_NAN __builtin_nanl("")
#endif

#if defined(__SIZEOF_SIZE_T__)
#	define Z_COMPILER_CONSTANT_SIZE_BITS  (__SIZEOF_SIZE_T__ * 8)
#	define Z_COMPILER_CONSTANT_SIZE_SIZE   __SIZEOF_SIZE_T__
#	define Z_COMPILER_CONSTANT_SSIZE_BITS (__SIZEOF_SIZE_T__ * 8)
#	define Z_COMPILER_CONSTANT_SSIZE_SIZE  __SIZEOF_SIZE_T__
#elif defined(__SIZE_WIDTH__)
#	define Z_COMPILER_CONSTANT_SIZE_BITS   __SIZE_WIDTH__
#	define Z_COMPILER_CONSTANT_SIZE_SIZE  (__SIZE_WIDTH__ / 8)
#	define Z_COMPILER_CONSTANT_SSIZE_BITS  __SIZE_WIDTH__
#	define Z_COMPILER_CONSTANT_SSIZE_SIZE (__SIZE_WIDTH__ / 8)
#endif

#if defined(__SIZEOF_POINTER__)
#	define Z_COMPILER_CONSTANT_POINTER_BITS (__SIZEOF_POINTER__ * 8)
#	define Z_COMPILER_CONSTANT_POINTER_SIZE	 __SIZEOF_POINTER__
#elif defined(__UINTPTR_WIDTH__)
#	define Z_COMPILER_CONSTANT_POINTER_BITS	 __UINTPTR_WIDTH__
#	define Z_COMPILER_CONSTANT_POINTER_SIZE	(__UINTPTR_WIDTH__ / 8)
#elif defined(__INTPTR_WIDTH__)
#	define Z_COMPILER_CONSTANT_POINTER_BITS	 __INTPTR_WIDTH__
#	define Z_COMPILER_CONSTANT_POINTER_SIZE	(__INTPTR_WIDTH__ / 8)
#endif

/* MARK: - Built-in types */

/*#define Z_COMPILER_TYPE_UINT8*/
/*#define Z_COMPILER_TYPE_UINT16*/
/*#define Z_COMPILER_TYPE_UINT32*/
/*#define Z_COMPILER_TYPE_UINT64*/

/*#define Z_COMPILER_TYPE_INT8*/
/*#define Z_COMPILER_TYPE_INT16*/
/*#define Z_COMPILER_TYPE_INT32*/
/*#define Z_COMPILER_TYPE_INT64*/

#ifdef __SIZEOF_INT128__
#	define Z_COMPILER_TYPE_UINT128 __uint128_t
#	define Z_COMPILER_TYPE_INT128  __int128_t
#endif

/*#define Z_COMPILER_TYPE_FLOAT16*/
/*#define Z_COMPILER_TYPE_FLOAT24*/
/*#define Z_COMPILER_TYPE_FLOAT32*/
/*#define Z_COMPILER_TYPE_FLOAT48*/
/*#define Z_COMPILER_TYPE_FLOAT64*/
/*#define Z_COMPILER_TYPE_FLOAT72*/
/*#define Z_COMPILER_TYPE_FLOAT80*/
/*#define Z_COMPILER_TYPE_FLOAT96*/
/*#define Z_COMPILER_TYPE_FLOAT128*/

#define Z_COMPILER_TYPE_VAL __builtin_va_list

/* MARK: - Built-in literals */

/*#define Z_COMPILER_LITERAL_UINT8*/
/*#define Z_COMPILER_LITERAL_UINT16*/
/*#define Z_COMPILER_LITERAL_UINT32*/
/*#define Z_COMPILER_LITERAL_UINT64*/
/*#define Z_COMPILER_LITERAL_UINT128*/

/*#define Z_COMPILER_LITERAL_INT8*/
/*#define Z_COMPILER_LITERAL_INT16*/
/*#define Z_COMPILER_LITERAL_INT32*/
/*#define Z_COMPILER_LITERAL_INT64*/
/*#define Z_COMPILER_LITERAL_INT128*/

/*#define Z_COMPILER_LITERAL_FLOAT16*/
/*#define Z_COMPILER_LITERAL_FLOAT24*/
/*#define Z_COMPILER_LITERAL_FLOAT32*/
/*#define Z_COMPILER_LITERAL_FLOAT48*/
/*#define Z_COMPILER_LITERAL_FLOAT64*/
/*#define Z_COMPILER_LITERAL_FLOAT72*/
/*#define Z_COMPILER_LITERAL_FLOAT80*/
/*#define Z_COMPILER_LITERAL_FLOAT96*/
/*#define Z_COMPILER_LITERAL_FLOAT128*/

/* MARK: - Built-in macros: Struture */

#define Z_COMPILER_MACRO_OFFSET_OF __builtin_offsetof

/* MARK: - Built-in macros: VAL
.-----------------------------------------------------------------.
| Please, read the comments for this section in the GCC's header. |
'----------------------------------------------------------------*/

#define Z_COMPILER_MACRO_VAL_INITIALIZE __builtin_va_start
#define Z_COMPILER_MACRO_VAL_FINALIZE   __builtin_va_end
#define Z_COMPILER_MACRO_VAL_READ	__builtin_va_arg

#if __has_builtin(__builtin_va_copy)
#	define Z_COMPILER_MACRO_VAL_COPY(object, output) __builtin_va_copy(output, object)
#endif

/* MARK: - Built-in functions: Atomic operations */

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	endif

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT8_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_INT8_ATOMIC_NOT_THEN_GET*/

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	endif

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT16_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_INT16_ATOMIC_NOT_THEN_GET*/

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	endif

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT32_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_INT32_ATOMIC_NOT_THEN_GET*/

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	endif

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT64_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_INT64_ATOMIC_NOT_THEN_GET*/

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_ADD		      __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_ADD		      __sync_fetch_and_add
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SUBTRACT	      __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_SUBTRACT	      __sync_fetch_and_sub
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	endif

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_ADD_THEN_GET		      __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_ADD_THEN_GET		      __sync_add_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_SUBTRACT_THEN_GET	      __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_SUBTRACT_THEN_GET	      __sync_sub_and_fetch
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT128_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_INT128_ATOMIC_NOT_THEN_GET*/

#endif

#endif /* __Z_inspection_private_compiler_Clang_H__ */
