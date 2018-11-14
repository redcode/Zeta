/* Z Kit - inspection/modules/compiler/GCC.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_modules_compiler_GCC_H_
#define _Z_inspection_modules_compiler_GCC_H_

#include <Z/macros/version.h>
#include <Z/keys/order.h>

/* MARK: - Identification */

#define Z_COMPILER		  Z_COMPILER_GCC
#define Z_COMPILER_STRING	  Z_COMPILER_STRING_GCC
#define Z_COMPILER_VERSION	  Z_VERSION(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#define Z_COMPILER_VERSION_STRING __VERSION__

/* MARK: - Bit field order */

/* MARK: - OS */

#if	defined(__gnu_linux) || \
	defined(__linux	   ) || \
	defined(__linux__  ) || \
	defined(linux	   )

#	define Z_COMPILER_OS Z_OS_LINUX

#elif defined(__FreeBSD__)
#	define Z_COMPILER_OS Z_OS_FREE_BSD

#elif defined(__NetBSD__)
#	define Z_COMPILER_OS Z_OS_NET_BSD

#elif defined(__OpenBSD__)
#	define Z_COMPILER_OS Z_OS_OPEN_BSD

#elif	defined(__WIN32	 ) || \
	defined(__WIN32__) || \
	defined(__WIN64  ) || \
	defined(__WIN64__) || \
	defined(__WINNT  ) || \
	defined(__WINNT__) || \
	defined(_WIN32	 ) || \
	defined(_WIN64	 ) || \
	defined(WIN32	 ) || \
	defined(WIN64	 ) || \
	defined(WINNT	 )

#	define Z_COMPILER_OS Z_OS_WINDOWS

#elif defined(_AIX)
#	define Z_COMPILER_OS Z_OS_AIX

#elif defined(__amigaos__)
#	define Z_COMPILER_OS Z_OS_AMIGA_OS

#elif defined(__bg__)
#	define Z_COMPILER_OS Z_OS_BLUE_GENE

#elif defined(__hpux) || defined(hpux)
#	define Z_COMPILER_OS Z_OS_HP_UX

#elif defined(__netware__)
#	define Z_COMPILER_OS Z_OS_NETWARE

#elif defined(__palmos__)
#	define Z_COMPILER_OS Z_OS_PALM_OS

#elif defined(M_XENIX)
#	define Z_COMPILER_OS Z_OS_SCO_UNIX_SYSTEM_V

#elif	defined(__sun  ) || \
	defined(__sun__) || \
	defined(sun    )

#	if	defined(__svr4__) || \
		defined(__SVR4	)

#		define Z_COMPILER_OS Z_COMPILER_OS_SOLARIS
#	else
#		define Z_COMPILER_OS Z_COMPILER_OS_SUN_OS
#	endif

#elif	defined(__vxworks  ) || \
	defined(__VXWORKS__)

#	define Z_COMPILER_OS Z_OS_VX_WORKS

#endif

/* MARK: - CPU */

#if	defined(__amd64	  ) || \
	defined(__amd64__ ) || \
	defined(__x86_64  ) || \
	defined(__x86_64__) || \
	defined(_M_AMD64  ) || \
	defined(_M_X64	  )

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_X86_64

#elif	defined(__386__	) || \
	defined(__i386	) || \
	defined(__i386__) || \
	defined(_M_IX86	) || \
	defined(i386	)

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_X86_32

#endif

/* MARK: - Endianness and Bit field order */

#ifdef __BYTE_ORDER__

#	if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#		define Z_COMPILER_CPU_INTEGER_ENDIANNESS Z_ENDIANNESS_LITTLE
#		define Z_COMPILER_BIT_FIELD_ORDER	 Z_ORDER_REVERSED

#	elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#		define Z_COMPILER_CPU_INTEGER_ENDIANNESS Z_ENDIANNESS_BIG
#		define Z_COMPILER_BIT_FIELD_ORDER	 Z_ORDER_NORMAL

#	elif __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__
#		define Z_COMPILER_CPU_INTEGER_ENDIANNESS Z_ENDIANNESS_PDP
#		define Z_COMPILER_BIT_FIELD_ORDER	 Z_ORDER_NORMAL
#	endif

#endif

/*#define Z_COMPIER_INTEGER_ENDIANNESS_8BIT*/
/*#define Z_COMPIER_INTEGER_ENDIANNESS_16BIT*/
/*#define Z_COMPIER_INTEGER_ENDIANNESS_32BIT*/
/*#define Z_COMPIER_INTEGER_ENDIANNESS_64BIT*/
/*#define Z_COMPIER_INTEGER_ENDIANNESS_128BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_8BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_16BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_32BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_64BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_128BIT*/

/* MARK: - Data model */

#if defined(__LP64__) || defined(_LP64)
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LP64

#elif defined(_WIN64)
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LLP64

#elif defined(__ILP32__) || defined(_ILP32) || defined(_WIN32)
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_ILP32
#endif

/* MARK: - K&R C support */

#define Z_COMPILER_C_HAS_OPERATOR_SIZE_OF	TRUE
#define Z_COMPILER_C_HAS_STORAGE_CLASS_AUTO	TRUE
#define Z_COMPILER_C_HAS_STORAGE_CLASS_EXTERN	TRUE
#define Z_COMPILER_C_HAS_STORAGE_CLASS_REGISTER TRUE
#define Z_COMPILER_C_HAS_STORAGE_CLASS_STATIC	TRUE
#define Z_COMPILER_C_HAS_TYPE_FLOAT		TRUE
#define Z_COMPILER_C_HAS_TYPE_DOUBLE		TRUE

/* MARK: - C89 support */

#define Z_COMPILER_C_HAS_ENUMERATION		 TRUE
#define Z_COMPILER_C_HAS_VOID_POINTER		 TRUE
#define Z_COMPILER_C_HAS_TYPE_LDOUBLE		 TRUE
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_CONSTANT TRUE
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_VOLATILE TRUE

/* MARK: - C90 support */

/* MARK: - C94 support */

#if Z_COMPILER_VERSION >= Z_VERSION(2, 7, 0)
#	define Z_COMPILER_C_HAS_DIGRAPHS TRUE
#endif

/* MARK: - C99 support
.---------------------------------------------------------------------------.
| GCC implements several features of C99 as extensions in C90 and in C++98, |
| but some of them generate warnings with "-pedantic" when compiling using  |
| a standard previous to C99.						    |
| Reference: http://gcc.gnu.org/c99status.html				    |
'--------------------------------------------------------------------------*/

#if Z_COMPILER_VERSION >= Z_VERSION(1, 21, 0)
#	define Z_COMPILER_C_HAS_INLINE_FUNCION TRUE
#endif

#if defined(__UINTMAX_MAX__) && 0U - 1U == __UINTMAX_MAX__
#	define Z_COMPILER_C_HAS_PREPROCESSOR_ARITHMETIC_DONE_IN_MAXIMUM_INTEGRAL TRUE
#endif

#if Z_COMPILER_VERSION >= Z_VERSION(2, 95, 0)
#	define Z_COMPILER_C_HAS_TYPE_QUALIFIER_RESTRICT TRUE
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L

#	if /*Z_COMPILER_VERSION >= Z_VERSION(0, 9, 0) &&*/ !defined(__STDC_NO_VLA__)
#		define Z_COMPILER_C_HAS_VLA TRUE
#	endif

#	if Z_COMPILER_VERSION >= Z_VERSION(3, 0, 0)
#		define Z_COMPILER_C_HAS_DESIGNATED_INITIALIZER TRUE
#		define Z_COMPILER_C_HAS_FLEXIBLE_ARRAY_MEMBER  TRUE
#	endif

#	if Z_COMPILER_VERSION >= Z_VERSION(3, 1, 0)
#		define Z_COMPILER_C_HAS_COMPOUND_LITERAL TRUE
#	endif

#endif

#if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)

#	if Z_COMPILER_VERSION >= Z_VERSION(2, 7, 0)
#		define Z_COMPILER_C_HAS_CPP_STYLE_COMMENT TRUE
#	endif

#	if Z_COMPILER_VERSION >= Z_VERSION(3, 0, 0)
#		define Z_COMPILER_C_HAS_MIXED_DECLARATIONS_AND_CODE TRUE
#	endif

#	if Z_COMPILER_VERSION >= Z_VERSION(4, 3, 0)
#		define Z_COMPILER_C_HAS_SPECIFIER_INLINE TRUE
#	endif

#endif

#if	(defined(__cplusplus) && __cplusplus >= 201103L) || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)

#	if Z_COMPILER_VERSION >= Z_VERSION(1, 27, 0) && !defined(__DARWIN_NO_LONG_LONG)
#		define Z_COMPILER_C_HAS_TYPE_ULLONG TRUE
#		define Z_COMPILER_C_HAS_TYPE_LLONG  TRUE
#	endif

#	if Z_COMPILER_VERSION >= Z_VERSION(2, 95, 0)
#		define Z_COMPILER_C_HAS_VARIADIC_MACRO TRUE
#	endif

#	if	!defined(Z_COMPILER_C_HAS_PREPROCESSOR_ARITHMETIC_DONE_IN_MAXIMUM_INTEGRAL) && \
		Z_COMPILER_VERSION >= Z_VERSION(3, 3, 0)

#		define Z_COMPILER_C_HAS_PREPROCESSOR_ARITHMETIC_DONE_IN_MAXIMUM_INTEGRAL TRUE
#	endif

#endif

/* MARK: - C11 support
.----------------------------------------------.
| Reference: http://gcc.gnu.org/wiki/C11Status |
'---------------------------------------------*/

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L

#	if Z_COMPILER_VERSION >= Z_VERSION(4, 6, 0)
#		define Z_COMPILER_C_HAS_ANONYMOUS_STRUCTURE TRUE
#		define Z_COMPILER_C_HAS_STATIC_ASSERTION    TRUE

#		if Z_COMPILER_VERSION >= Z_VERSION(4, 7, 0)
#			define Z_COMPILER_C_HAS_OPERATOR_ALIGN_OF   TRUE
#			define Z_COMPILER_C_HAS_SPECIFIER_ALIGN_AS  TRUE
#			define Z_COMPILER_C_HAS_SPECIFIER_NO_RETURN TRUE

#			if Z_COMPILER_VERSION >= Z_VERSION(4, 9, 0)
#				define Z_COMPILER_C_HAS_GENERIC_SELECTION	   TRUE
#				define Z_COMPILER_C_HAS_STORATE_CLASS_THREAD_LOCAL TRUE

#				ifndef __STDC_NO_ATOMICS__
#					define Z_COMPILER_C_HAS_ATOMIC_OPERATIONS     TRUE
#					define Z_COMPILER_C_HAS_SPECIFIER_ATOMIC      TRUE
#					define Z_COMPILER_C_HAS_TYPE_QUALIFIER_ATOMIC TRUE
#				endif
#			endif
#		endif
#	endif
#endif

#if	Z_COMPILER_VERSION >= Z_VERSION(4, 6, 0) && \
	(defined(__cplusplus) || defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)

#	define Z_COMPILER_C_HAS_ANONYMOUS_UNION TRUE
#endif

/* MARK: - C18 support */

/* MARK: - Apple C extensions support */

#ifdef __BLOCKS__
#	define Z_COMPILER_C_HAS_CLOSURE TRUE
#endif

#if defined(__cplusplus)

	/* MARK: - C++98 support */

#	if __cplusplus >= 199711L
#		define Z_COMPILER_CPP_HAS_SFINAE       TRUE /* TODO: from version...? */
#		define Z_COMPILER_CPP_HAS_TYPE_BOOLEAN TRUE /* TODO: from version...? */
#	endif

	/* MARK: - C++11 support */

#	if __cplusplus >= 201103L

#		if Z_COMPILER_VERSION >= Z_VERSION(4, 3, 0)
#			define Z_COMPILER_CPP_HAS_C99_PREPROCESSOR				   TRUE
#			define Z_COMPILER_CPP_HAS_CONCURRENT_STATIC_LOCAL_VARIABLE		   TRUE
#			define Z_COMPILER_CPP_HAS_DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE TRUE
#			define Z_COMPILER_CPP_HAS_RVALUE_REFERENCE				   TRUE
#			define Z_COMPILER_CPP_HAS_SPECIFIER_DECLARED_TYPE			   TRUE
#			define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE				   TRUE
#			define Z_COMPILER_CPP_HAS_TYPE_ULLONG					   TRUE
#			define Z_COMPILER_CPP_HAS_TYPE_LLONG					   TRUE

#			if Z_COMPILER_VERSION >= Z_VERSION(4, 4, 0)
#				define Z_COMPILER_CPP_HAS_COPY_LIST_INITIALIZATION		TRUE
#				define Z_COMPILER_CPP_HAS_DIRECT_LIST_INITIALIZATION		TRUE
#				define Z_COMPILER_CPP_HAS_INITIALIZER_LIST			TRUE
#				define Z_COMPILER_CPP_HAS_STRONGLY_TYPED_ENUMERATION		TRUE
#				define Z_COMPILER_CPP_HAS_TRAILING_RETURN_TYPE			TRUE
#				define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE_EXTENDED_PARAMETERS TRUE
#				define Z_COMPILER_CPP_HAS_SPECIFIER_AUTO			TRUE

#				if Z_COMPILER_VERSION >= Z_VERSION(4, 5, 0)
#					define Z_COMPILER_CPP_HAS_EXPLICIT_CONVERSION TRUE
#					define Z_COMPILER_CPP_HAS_EXPRESSION_SFINAE   TRUE
#					define Z_COMPILER_CPP_HAS_LAMBDA	      TRUE
#					define Z_COMPILER_CPP_HAS_OPERATOR_ALIGN_OF   TRUE

#					if Z_COMPILER_VERSION >= Z_VERSION(4, 6, 0)
#						define Z_COMPILER_CPP_HAS_RANGE_BASED_FOR		TRUE
#						define Z_COMPILER_CPP_HAS_UNRESTRICTED_UNION		TRUE
#						define Z_COMPILER_CPP_HAS_MOVE_SPECIAL_MEMBER_FUNCTIONS TRUE
#						define Z_COMPILER_CPP_HAS_LITERAL_NULL_POINTER		TRUE
#						define Z_COMPILER_CPP_HAS_OPERATOR_NO_EXCEPTION		TRUE
#						define Z_COMPILER_CPP_HAS_SPECIFIER_CONSTANT_EXPRESSION TRUE
#						define Z_COMPILER_CPP_HAS_SPECIFIER_NO_EXCEPTION	TRUE

#						if Z_COMPILER_VERSION >= Z_VERSION(4, 7, 0)
#							define Z_COMPILER_CPP_HAS_DEFAULT_MEMBER_INITIALIZER TRUE
#							define Z_COMPILER_CPP_HAS_TEMPLATE_ALIAS	     TRUE

#							if Z_COMPILER_VERSION >= Z_VERSION(4, 8, 0)
#								define Z_COMPILER_CPP_HAS_INHERITING_CONSTRUCTORS TRUE
#								define Z_COMPILER_CPP_HAS_SPECIFIER_ALIGN_AS	  TRUE

#								if Z_COMPILER_VERSION >= Z_VERSION(4, 8 ,1)
#									define Z_COMPILER_CPP_HAS_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION TRUE
#									define Z_COMPILER_CPP_HAS_SPECIFIER_DECLARED_TYPE_OF_INCOMPLETE_RETURN	 TRUE
#								endif
#							endif
#						endif
#					endif
#				endif
#			endif
#		endif

#	endif

#endif

/* MARK: - Attributes
.---------------------------------------------------------------------------.
| There is no official documentation where to consult since what version is |
| available each attribute. The following list has been used as reference:  |
| https://ohse.de/uwe/articles/gcc-attributes.html			    |
'--------------------------------------------------------------------------*/

/*#define Z_COMPILER_ATTRIBUTE_API_ALIAS*/
/*#define Z_COMPILER_ATTRIBUTE_API_EXPORT_ALIAS*/
/*#define Z_COMPILER_ATTRIBUTE_API_WEAK_EXPORT*/

#if Z_COMPILER_VERSION >= Z_VERSION(2, 3, 0)
#	define Z_COMPILER_ATTRIBUTE_STRICT_SIZE_BEGIN
#	define Z_COMPILER_ATTRIBUTE_STRICT_SIZE_END __attribute__((packed))
#endif

#if Z_COMPILER_VERSION >= Z_VERSION(2, 5, 0)
#	define Z_COMPILER_ATTRIBUTE_NO_RETURN __attribute__((noreturn))
#endif

#if Z_COMPILER_VERSION >= Z_VERSION(2, 7, 0)
#	define Z_COMPILER_ATTRIBUTE_ALIAS(name) __attribute__((alias(name)))
#	define Z_COMPILER_ATTRIBUTE_WEAK	__attribute__((weak))
#endif

#if	Z_COMPILER_VERSION >= Z_VERSION(2, 8, 0) && \
	defined(Z_COMPILER_OS) && Z_COMPILER_OS == Z_OS_WINDOWS

#	define Z_COMPILER_ATTRIBUTE_API	       __attribute__((dllimport))
#	define Z_COMPILER_ATTRIBUTE_API_EXPORT __attribute__((dllexport))
#endif

#if Z_COMPILER_VERSION >= Z_VERSION(3, 1, 0)
#	define Z_COMPILER_ATTRIBUTE_INLINE __inline__ __attribute__((always_inline))

#elif Z_COMPILER_VERSION >= Z_VERSION(1, 21, 0)
#	define Z_COMPILER_ATTRIBUTE_INLINE __inline__
#endif

#if Z_COMPILER_VERSION >= Z_VERSION(3, 3, 0)

#	define Z_COMPILER_ATTRIBUTE_PRIVATE __attribute__((visibility("hidden")))
#	define Z_COMPILER_ATTRIBUTE_PUBLIC  __attribute__((visibility("default")))

	/*----------------------------------------------------------.
	| See: http://gcc.gnu.org/ml/gcc-help/2006-08/msg00232.html |
	'----------------------------------------------------------*/
#	if	defined(Z_COMPILER_CPU_ARCHITECTURE)			  && \
		(Z_COMPILER_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_32 || \
		 Z_COMPILER_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_64)

#		define Z_COMPILER_ATTRIBUTE_THREAD_LOCAL __thread
#	endif

#endif

/*----------------------------------------------------------------------.
| "sentinel" first appeared in the documentation of GCC v4.0.0:		|
| https://gcc.gnu.org/onlinedocs/gcc-4.0.0/gcc/Function-Attributes.html |
'----------------------------------------------------------------------*/
#if Z_COMPILER_VERSION >= Z_VERSION(4, 0, 0)
#	define Z_COMPILER_ATTRIBUTE_NULL_TERMINATED __attribute__((sentinel))
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

/*#define Z_COMPILER_TYPE_SINT8*/
/*#define Z_COMPILER_TYPE_SINT16*/
/*#define Z_COMPILER_TYPE_SINT32*/
/*#define Z_COMPILER_TYPE_SINT64*/

#ifdef __SIZEOF_INT128__
#	define Z_COMPILER_TYPE_UINT128 __uint128_t
#	define Z_COMPILER_TYPE_SINT128 __int128_t
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

/*#define Z_COMPILER_LITERAL_SINT8*/
/*#define Z_COMPILER_LITERAL_SINT16*/
/*#define Z_COMPILER_LITERAL_SINT32*/
/*#define Z_COMPILER_LITERAL_SINT64*/
/*#define Z_COMPILER_LITERAL_SINT128*/

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

#endif /* _Z_inspection_modules_compiler_Clang_H_ */

































































/* MARK: - Built-in types */

#ifdef __SIZEOF_INT128__
#	define Z_COMPILER_TYPE_UINT128 __uint128_t
#	define Z_COMPILER_TYPE_INT128  __int128_t
#endif

#define Z_COMPILER_TYPE_VAL __builtin_va_list

/* MARK: - Built-in macros: Struture */

#define Z_COMPILER_MACRO_OFFSET_OF __builtin_offsetof

/* MARK: - Built-in macros: VAL
.------------------------------------------------------------------------------.
| GCC has a BIG __BUG__ which breaks the CDECL calling convention on x86-32.   |
| This makes necessary to always use the GCC's internal built-in macros for    |
| dealing with variable argument lists.					       |
|									       |
| Read the complete story:						       |
| https://gcc.gnu.org/bugzilla/show_bug.cgi?id=45249			       |
|									       |
| This should not be a problem, after all the built-in macros work well, but   |
| some versions of GCC create dependencies with the C standard library under   |
| certain conditions if they are used. The way to fix this is to use the       |
| "-fno-builtin" option to make GCC, paradoxically, generate true built-ins.   |
'-----------------------------------------------------------------------------*/

#define Z_COMPILER_MACRO_VAL_INITIALIZE	__builtin_va_start
#define Z_COMPILER_MACRO_VAL_FINALIZE	__builtin_va_end
#define Z_COMPILER_MACRO_VAL_READ	__builtin_va_arg

#if __STDC_VERSION__ >= 199900L || !defined(__STRICT_ANSI__)
#	define Z_COMPILER_MACRO_VAL_COPY(object, output) __builtin_va_copy(output, object)
#endif

/* MARK: - Built-in functions: Atomic operations */

#if Z_COMPILER_VERSION >= Z_VERSION(4, 1, 0)

#	ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

#	ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

#	ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

#	ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

#	ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_INCREMENT(  pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD  __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_ADD __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_ADD __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_ADD __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_ADD   __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_ADD  __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_ADD  __sync_fetch_and_add
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_ADD  __sync_fetch_and_add

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_DECREMENT(  pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SUBTRACT  __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SUBTRACT   __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SUBTRACT  __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SUBTRACT  __sync_fetch_and_sub
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SUBTRACT  __sync_fetch_and_sub

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_AND   __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_AND  __sync_fetch_and_and

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_OR   __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_OR  __sync_fetch_and_or

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_XOR   __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_INCREMENT_THEN_GET(  pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_ADD_THEN_GET  __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_ADD_THEN_GET __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_ADD_THEN_GET __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_ADD_THEN_GET __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_ADD_THEN_GET   __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_ADD_THEN_GET  __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_ADD_THEN_GET  __sync_add_and_fetch
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_ADD_THEN_GET  __sync_add_and_fetch

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_DECREMENT_THEN_GET(  pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SUBTRACT_THEN_GET  __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_SUBTRACT_THEN_GET   __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_SUBTRACT_THEN_GET  __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_SUBTRACT_THEN_GET  __sync_sub_and_fetch
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_SUBTRACT_THEN_GET  __sync_sub_and_fetch

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_AND_THEN_GET   __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_AND_THEN_GET  __sync_and_and_fetch

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_OR_THEN_GET   __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_OR_THEN_GET  __sync_or_and_fetch

#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_INT8_ATOMIC_XOR_THEN_GET   __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_INT16_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_INT32_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	define Z_COMPILER_FUNCTION_INT64_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch

#endif

#endif /* _Z_inspection_modules_compiler_GCC_H_ */
