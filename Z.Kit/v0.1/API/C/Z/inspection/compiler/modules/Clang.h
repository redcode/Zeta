/* Z Kit C API - inspection/compiler/modules/Clang.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_compiler_modules_Clang_H__
#define __Z_inspection_compiler_modules_Clang_H__

/* MARK: - Identification */

#ifndef Z_COMPILER
#	include <Z/macros/version.h>

#	define Z_COMPILER		  Z_COMPILER_CLANG
#	define Z_COMPILER_STRING	  Z_COMPILER_STRING_CLANG
#	define Z_COMPILER_VERSION	  Z_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#	define Z_COMPILER_VERSION_STRING __clang_version__
#endif

#ifndef __has_extension
#	define __has_extension __has_feature /* Compatibility with Clang < v3.0 */
#endif

/* MARK: - CPU
.--------------------------------------------------.
| Reference: [Clang sources]/lib/Basic/Targets.cpp |
'-------------------------------------------------*/

#if	defined(__amd64	  ) || \
	defined(__amd64__ ) || \
	defined(__x86_64  ) || \
	defined(__x86_64__) || \
	defined(_M_AMD64  ) || \
	defined(_M_X64	  )

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_X86_64

#elif	defined(__INTEL__) || \
	defined(__i386	 ) || \
	defined(__i386__ ) || \
	defined(__i486	 ) || \
	defined(__i486__ ) || \
	defined(__i586	 ) || \
	defined(__i586__ ) || \
	defined(__i686	 ) || \
	defined(__i686__ ) || \
	defined(_M_IX86	 ) || \
	defined(_X86_	 ) || \
	defined(i386	 )

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_X86_32

#elif	defined(__aarch64__) ||	\
	defined(__arm64	   ) || \
	defined(__arm64__  )

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_AARCH64

#elif	defined(__arm__	 ) || \
	defined(__arm	 ) || \
	defined(__thumb__) || \
	defined(_ARM_	 ) || \
	defined(_M_ARM	 ) || \
	defined(_M_ARM_NT) || \
	defined(_M_ARMT	 ) || \
	defined(_M_THUMB )

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_AARCH32

#elif	defined(__HEXAGON_ARCH__) \
	defined(__QDSP6_ARCH__	) \
	defined(__hexagon__	) \
	defined(__qdsp6__	)

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_HEXAGON

#elif defined(__lanai__)
#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_LANAI

#elif	defined(__mips64  )		  || \
	defined(__mips64__)		  || \
	(defined(__mips) && __mips == 64) || \
	(defined(_MIPS_ISA) && defined(_MIPS_ISA_MIPS64) && _MIPS_ISA == _MIPS_ISA_MIPS64)

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_MIPS64

#elif	defined(__mips	) || \
	defined(__mips__) || \
	defined(_mips	) || \
	defined(mips	)

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_MIPS

#elif	defined(__MSP430__) || \
	defined(MSP430	  )

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_MSP430

#elif	defined(__PPC64__    ) || \
	defined(__powerpc64__) || \
	defined(__ppc64__    ) || \
	defined(_ARCH_PPC64  )

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_POWERPC_64BIT

#elif	defined(__POWERPC__) || \
	defined(__PPC__	   ) || \
	defined(__powerpc__) || \
	defined(__ppc__	   ) || \
	defined(_ARCH_PPC  )

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_POWERPC_32BIT

#elif	defined(__arch64__  ) || \
	defined(__sparc_v9__) || \
	defined(__sparc64__ ) || \
	defined(__sparcv9   ) || \
	defined(__sparcv9__ )

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_SPARC_V9

#elif	defined(__sparc	   ) || \
	defined(__sparc__  ) || \
	defined(__sparcv8  ) || \
	defined(__sparcv8__) || \
	defined(sparc	   )

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_SPARC

#elif	defined(__s390x__) || \
	defined(__zarch__)
	/*----------------------------------------------------------.
	| __s390__ is omitted in order to avoid conflicts with a    |
	| hypothetical future support for the ESA/390 architecture. |
	'----------------------------------------------------------*/

#	define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_Z_ARCHITECTURE

#endif

/* MARK: - Endianness and bit field order */

#ifdef __BYTE_ORDER__

#	if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#		define Z_COMPILER_INTEGER_ENDIANNESS Z_ENDIANNESS_LITTLE
#		define Z_COMPILER_BIT_FIELD_ORDER    Z_ORDER_REVERSED

#	elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#		define Z_COMPILER_INTEGER_ENDIANNESS Z_ENDIANNESS_BIG
#		define Z_COMPILER_BIT_FIELD_ORDER    Z_ORDER_NORMAL

#	elif __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__
#		define Z_COMPILER_INTEGER_ENDIANNESS Z_ENDIANNESS_PDP
#		define Z_COMPILER_BIT_FIELD_ORDER    Z_ORDER_NORMAL
#	endif

#elif	defined(__AARCH64EL__	 ) || \
	defined(__ARMEL__	 ) || \
	defined(__LITTLE_ENDIAN__) || \
	defined(__MIPSEL	 ) || \
	defined(__MIPSEL__	 ) || \
	defined(__THUMBEL__	 ) || \
	defined(_LITTLE_ENDIAN	 ) || \
	defined(_MIPSEL		 )

#	define Z_COMPILER_INTEGER_ENDIANNESS Z_ENDIANNESS_LITTLE
#	define Z_COMPILER_BIT_FIELD_ORDER    Z_ORDER_REVERSED

#elif	defined(__AARCH_BIG_ENDIAN) || \
	defined(__AARCH64EB__	  ) || \
	defined(__ARM_BIG_ENDIAN  ) || \
	defined(__ARMEB__	  ) || \
	defined(__MIPSEB	  ) || \
	defined(__MIPSEB__	  ) || \
	defined(_BIG_ENDIAN	  ) || \
	defined(_MIPSEB		  )

#	define Z_COMPILER_INTEGER_ENDIANNESS Z_ENDIANNESS_BIG
#	define Z_COMPILER_BIT_FIELD_ORDER    Z_ORDER_NORMAL
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

/* MARK: - OS
.--------------------------------------------------.
| Reference: [Clang sources]/lib/Basic/Targets.cpp |
'-------------------------------------------------*/

#if defined(__ANDROID__)
#	define Z_COMPILER_OS Z_OS_ANDROID

#elif	defined(__gnu_linux__) || \
	defined(__linux	     ) || \
	defined(__linux__    ) || \
	defined(linux	     )

#	define Z_COMPILER_OS Z_OS_LINUX

#elif defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)
#	define Z_COMPILER_OS Z_OS_IOS

#elif defined(__ENVIRONMENT_TV_OS_VERSION_MIN_REQUIRED__)
#	define Z_COMPILER_OS Z_OS_TVOS

#elif defined(__ENVIRONMENT_WATCH_OS_VERSION_MIN_REQUIRED__)
#	define Z_COMPILER_OS Z_OS_WATCHOS

#elif	defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) || \
	defined(__APPLE_CC__				     ) || \
	(defined(__APPLE__) && defined(__MACH__))

#	define Z_COMPILER_OS Z_OS_MAC_OS_X

#elif	defined(__WIN32	 ) || \
	defined(__WIN32__) || \
	defined(__WIN64	 ) || \
	defined(__WIN64__) || \
	defined(__WINNT	 ) || \
	defined(__WINNT__) || \
	defined(_WIN32	 ) || \
	defined(_WIN64	 ) || \
	defined(WIN32	 ) || \
	defined(WIN64	 ) || \
	defined(WINNT	 )

#	define Z_COMPILER_OS Z_OS_WINDOWS

#elif defined(__Bitrig__)
#	define Z_COMPILER_OS Z_OS_BITRIG

#elif defined(__CELLOS_LV2__)
#	define Z_COMPILER_OS Z_OS_CELL_OS

#elif defined(__DragonFly__)
#	define Z_COMPILER_OS Z_OS_DRAGONFLY_BSD

#elif	defined(__FreeBSD__	  ) || \
	defined(__FreeBSD_kernel__)

#	define Z_COMPILER_OS Z_OS_FREE_BSD

#elif defined(__HAIKU__)
#	define Z_COMPILER_OS Z_OS_HAIKU

#elif defined(__minix)
#	define Z_COMPILER_OS Z_OS_MINIX

#elif defined(__NetBSD__)
#	define Z_COMPILER_OS Z_OS_NET_BSD

#elif defined(__OpenBSD__)
#	define Z_COMPILER_OS Z_OS_OPEN_BSD

#elif defined(__ORBIS__)
#	define Z_COMPILER_OS Z_OS_ORBIS_OS

#elif	defined(__psp__) || \
	defined(_PSP   ) || \
	defined(PSP    )

#	define Z_COMPILER_OS Z_OS_PSP_SYSTEM_SOFTWARE

#elif	defined(__SVR4	) || \
	defined(__sun	) || \
	defined(__sun__	) || \
	defined(__svr4__) || \
	defined(sun	)

#	define Z_COMPILER_OS Z_OS_SOLARIS

#endif

/* MARK: - Data model */

#if defined(__LP64__) || defined(_LP64)
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LP64

#elif defined(__LP32__)
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LP32

#elif defined(_WIN64)
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LLP64

#elif defined(__ILP32__) || defined(_ILP32) || defined(_WIN32)
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_ILP32
#endif

/* MARK: - K&R C support */

#define Z_COMPILER_C_HAS_TYPE_FLOAT		TRUE
#define Z_COMPILER_C_HAS_TYPE_DOUBLE		TRUE
#define Z_COMPILER_C_HAS_STORAGE_CLASS_AUTO	TRUE
#define Z_COMPILER_C_HAS_STORAGE_CLASS_EXTERN	TRUE
#define Z_COMPILER_C_HAS_STORAGE_CLASS_REGISTER TRUE
#define Z_COMPILER_C_HAS_STORAGE_CLASS_STATIC	TRUE
#define Z_COMPILER_C_HAS_OPERATOR_SIZE_OF	TRUE

/* MARK: - C89 support */

#define Z_COMPILER_C_HAS_ENUMERATION		 TRUE
#define Z_COMPILER_C_HAS_VOID_POINTER		 TRUE
#define Z_COMPILER_C_HAS_TYPE_LDOUBLE		 TRUE
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_CONSTANT TRUE
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_VOLATILE TRUE

/* MARK: - C90 support */

/* MARK: - C94 support */

#define Z_COMPILER_C_HAS_DIGRAPH TRUE

/* MARK: - C99 support */

#define Z_COMPILER_C_HAS_INLINE_FUNCION		 TRUE
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_RESTRICT TRUE

#if defined(__UINTMAX_MAX__) && 0U - 1U == __UINTMAX_MAX__
#	define Z_COMPILER_C_HAS_PREPROCESSOR_ARITHMETIC_DONE_IN_MAXIMUM_INTEGER TRUE
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#	define Z_COMPILER_C_HAS_COMPOUND_LITERAL       TRUE
#	define Z_COMPILER_C_HAS_DESIGNATED_INITIALIZER TRUE
#	define Z_COMPILER_C_HAS_FLEXIBLE_ARRAY_MEMBER  TRUE

#	ifndef __STDC_NO_VLA__
#		define Z_COMPILER_C_HAS_VLA TRUE
#	endif
#endif

#if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)
#	define Z_COMPILER_C_HAS_CPP_STYLE_COMMENT	    TRUE
#	define Z_COMPILER_C_HAS_MIXED_DECLARATIONS_AND_CODE TRUE
#	define Z_COMPILER_C_HAS_SPECIFIER_INLINE	    TRUE
#endif

#if	(defined(__cplusplus) && __cplusplus >= 201103L) || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)

#	define Z_COMPILER_C_HAS_PREPROCESSOR_ARITHMETIC_DONE_IN_MAXIMUM_INTEGER TRUE
#	define Z_COMPILER_C_HAS_VARIADIC_MACRO					TRUE
#	define Z_COMPILER_C_HAS_TYPE_ULLONG					TRUE
#	define Z_COMPILER_C_HAS_TYPE_LLONG					TRUE
#endif

/* MARK: - C11 support */

#if Z_COMPILER_VERSION >= Z_VERSION(3, 1, 0)

#	if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#		define Z_COMPILER_C_HAS_ANONYMOUS_STRUCTURE TRUE // OK
#	endif

#	if (defined(__cplusplus) || defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
#		define Z_COMPILER_C_HAS_ANONYMOUS_UNION TRUE // OK
#	endif

#	define Z_COMPILER_C_HAS_SPECIFIER_NO_RETURN TRUE /* TODO: Check support in previous versions */

#endif

#if __has_feature(c_atomic) || __has_extension(c_atomic)
#	define Z_COMPILER_C_HAS_ATOMIC_OPERATIONS     TRUE
#	define Z_COMPILER_C_HAS_TYPE_QUALIFIER_ATOMIC TRUE
#	define Z_COMPILER_C_HAS_SPECIFIER_ATOMIC      TRUE
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L

#	if __has_feature(c_generic_selections) || __has_extension(c_generic_selections)
#		define Z_COMPILER_C_HAS_GENERIC_SELECTION TRUE
#	endif

#	if __has_feature(c_static_assert) || __has_extension(c_static_assert)
#		define Z_COMPILER_C_HAS_STATIC_ASSERTION TRUE
#	endif

#	if __has_feature(c_alignas) || __has_extension(c_alignas)
#		define Z_COMPILER_C_HAS_SPECIFIER_ALIGN_AS TRUE
#	endif

#	if __has_feature(c_alignof) || __has_extension(c_alignof)
#		define Z_COMPILER_C_HAS_OPERATOR_ALIGN_OF TRUE
#	endif

#endif

#if __has_feature(c_thread_local) || __has_extension(c_thread_local)
#	define Z_COMPILER_C_HAS_STORATE_CLASS_THREAD_LOCAL TRUE
#endif

/* MARK: - Apple C extensions support */

#if __has_extension(blocks)
#	define Z_COMPILER_C_HAS_CLOSURE TRUE
#endif

/* MARK: - C attributes */

#if __has_attribute(alias)
#	define Z_COMPILER_C_ATTRIBUTE_ALIAS(name) __attribute__((alias(name)))
#endif

#if __has_attribute(dllimport)
#	define Z_COMPILER_C_ATTRIBUTE_API __declspec(dllimport)
#endif

#if __has_attribute(dllexport)
#	define Z_COMPILER_C_ATTRIBUTE_API_EXPORT __declspec(dllexport)
#endif

/*#define Z_COMPILER_C_ATTRIBUTE_API_ALIAS*/
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

#if __has_extension(tls)
#	define Z_COMPILER_C_ATTRIBUTE_THREAD_LOCAL __thread
#endif

#if __has_attribute(weak)
#	define Z_COMPILER_C_ATTRIBUTE_WEAK __attribute__((weak))
#endif

#if defined(__cplusplus)

	/* MARK: - C++ support */

#	define Z_COMPILER_CPP_HAS_TYPE_BOOLEAN TRUE

	/* MARK: - C++11 support */

#	if __cplusplus >= 201103L

#		if Z_COMPILER_VERSION >= Z_VERSION(2, 9, 0)
#			define Z_COMPILER_CPP_HAS_C99_PREPROCESSOR  TRUE
#			define Z_COMPILER_CPP_HAS_EXPRESSION_SFINAE TRUE
#			define Z_COMPILER_CPP_HAS_TYPE_ULLONG	    TRUE
#			define Z_COMPILER_CPP_HAS_TYPE_LLONG	    TRUE
#		endif

#		if __has_feature(cxx_generalized_initializers)
#			define Z_COMPILER_CPP_HAS_INITIALIZER_LIST TRUE
#		endif

#		if __has_feature(cxx_nonstatic_member_init)
#			define Z_COMPILER_CPP_HAS_NON_STATIC_DATA_MEMBER_INITIALIZER TRUE
#		endif

#		if __has_feature(cxx_lambdas) || __has_extension(cxx_lambdas)
#			define Z_COMPILER_CPP_HAS_LAMBDA TRUE
#		endif

#		if __has_feature(cxx_range_for) || __has_extension(cxx_range_for)
#			define Z_COMPILER_CPP_HAS_RANGE_BASED_FOR TRUE
#		endif

#		if __has_feature(cxx_reference_qualified_functions) || __has_extension(cxx_reference_qualified_functions)
#			define Z_COMPILER_CPP_HAS_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION TRUE
#		endif

#		if __has_feature(cxx_rvalue_references) || __has_extension(cxx_rvalue_references)
#			define Z_COMPILER_CPP_HAS_RVALUE_REFERENCE TRUE
#		endif

		/*#define Z_COMPILER_CPP_HAS_STATIC_CONSTANT_DATA_MEMBER_INITIALIZER*/

#		if __has_feature(cxx_strong_enums) || __has_extension(cxx_strong_enums)
#			define Z_COMPILER_CPP_HAS_STRONGLY_TYPED_ENUMERATION TRUE
#		endif

#		if __has_feature(cxx_trailing_return) || __has_extension(cxx_trailing_return)
#			define Z_COMPILER_CPP_HAS_TRAILING_RETURN_TYPE TRUE
#		endif

#		if __has_feature(cxx_unrestricted_unions)
#			define Z_COMPILER_CPP_HAS_UNRESTRICTED_UNION TRUE
#		endif

#		if __has_feature(cxx_variadic_templates) || __has_extension(cxx_variadic_templates)
#			define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE			TRUE
#			define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE_EXTENDED_PARAMETERS TRUE
#		endif

#		if __has_feature(cxx_alignas) || __has_extension(cxx_alignas)
#			define Z_COMPILER_CPP_HAS_SPECIFIER_ALIGN_AS TRUE
#		endif

#		if __has_feature(cxx_auto_type) || __has_extension(cxx_auto_type)
#			define Z_COMPILER_CPP_HAS_SPECIFIER_AUTO TRUE
#		endif

#		if __has_feature(cxx_constexpr)
#			define Z_COMPILER_CPP_HAS_SPECIFIER_CONSTANT_EXPRESSION TRUE
#		endif

#		if __has_feature(cxx_decltype) || __has_extension(cxx_decltype)
#			define Z_COMPILER_CPP_HAS_SPECIFIER_DECLARED_TYPE TRUE
#		endif

#		if __has_feature(cxx_decltype_incomplete_return_types) || __has_extension(cxx_decltype_incomplete_return_types)
#			define Z_COMPILER_CPP_HAS_SPECIFIER_DECLARED_TYPE_INCOMPLETE_RETURN TRUE
#		endif

#		if __has_feature(cxx_noexcept) || __has_extension(cxx_noexcept)
#			define Z_COMPILER_CPP_HAS_SPECIFIER_NO_EXCEPTION TRUE
#		endif

#		if __has_feature(cxx_alignof) || __has_extension(cxx_alignof)
#			define Z_COMPILER_CPP_HAS_OPERATOR_ALIGN_OF TRUE
#		endif

#		if __has_feature(cxx_noexcept) || __has_extension(cxx_noexcept)
#			define Z_COMPILER_CPP_HAS_OPERATOR_NO_EXCEPTION TRUE
#		endif

#		if __has_feature(cxx_nullptr) || __has_extension(cxx_nullptr)
#			define Z_COMPILER_CPP_HAS_LITERAL_NULL_POINTER TRUE
#		endif

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

#if defined(__SIZEOF_INT__)
#	define Z_COMPILER_CONSTANT_UINT_BITS (__SIZEOF_INT__ * 8)
#	define Z_COMPILER_CONSTANT_UINT_SIZE  __SIZEOF_INT__
#	define Z_COMPILER_CONSTANT_INT_BITS  (__SIZEOF_INT__ * 8)
#	define Z_COMPILER_CONSTANT_INT_SIZE   __SIZEOF_INT__
#elif defined(_MIPS_SZINT)
#	define Z_COMPILER_CONSTANT_UINT_BITS _MIPS_SZINT
#	define Z_COMPILER_CONSTANT_UINT_SIZE (_MIPS_SZINT / 8)
#	define Z_COMPILER_CONSTANT_INT_BITS  _MIPS_SZINT
#	define Z_COMPILER_CONSTANT_INT_SIZE  (_MIPS_SZINT / 8)
#endif

#ifdef __INT_MAX__
#	define Z_COMPILER_CONSTANT_UINT_MAXIMUM ( __INT_MAX__ * 2 + 1)
#	define Z_COMPILER_CONSTANT_INT_MINIMUM	(-__INT_MAX__ - 1)
#	define Z_COMPILER_CONSTANT_INT_MAXIMUM	  __INT_MAX__
#endif

#if defined(__SIZEOF_LONG__)
#	define Z_COMPILER_CONSTANT_ULONG_BITS (__SIZEOF_LONG__ * 8)
#	define Z_COMPILER_CONSTANT_ULONG_SIZE  __SIZEOF_LONG__
#	define Z_COMPILER_CONSTANT_LONG_BITS  (__SIZEOF_LONG__ * 8)
#	define Z_COMPILER_CONSTANT_LONG_SIZE   __SIZEOF_LONG__
#elif defined(_MIPS_SZLONG)
#	define Z_COMPILER_CONSTANT_ULONG_BITS _MIPS_SZLONG
#	define Z_COMPILER_CONSTANT_ULONG_SIZE (_MIPS_SZLONG / 8)
#	define Z_COMPILER_CONSTANT_LONG_BITS  _MIPS_SZLONG
#	define Z_COMPILER_CONSTANT_LONG_SIZE  (_MIPS_SZLONG / 8)
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

#if __has_builtin(__builtin_huge_valf)
#	define Z_COMPILER_CONSTANT_FLOAT_INFINITY __builtin_huge_valf()
#elif __has_builtin(__builtin_inff)
#	define Z_COMPILER_CONSTANT_FLOAT_INFINITY __builtin_inff()
#endif

#if __has_builtin(__builtin_nanf)
#	define Z_COMPILER_CONSTANT_FLOAT_NAN __builtin_nanf("")
#endif

#ifdef __SIZEOF_DOUBLE__
#	define Z_COMPILER_CONSTANT_DOUBLE_BITS (__SIZEOF_DOUBLE__ * 8)
#	define Z_COMPILER_CONSTANT_DOUBLE_SIZE	__SIZEOF_DOUBLE__
#endif

#if __has_builtin(__builtin_huge_val)
#	define Z_COMPILER_CONSTANT_DOUBLE_INFINITY __builtin_huge_val()
#elif __has_builtin(__builtin_inf)
#	define Z_COMPILER_CONSTANT_DOUBLE_INFINITY __builtin_inf()
#endif

#if __has_builtin(__builtin_nan)
#	define Z_COMPILER_CONSTANT_DOUBLE_NAN __builtin_nan("")
#endif

#ifdef __SIZEOF_LONG_DOUBLE__
#	define Z_COMPILER_CONSTANT_LDOUBLE_BITS (__SIZEOF_LONG_DOUBLE__ * 8)
#	define Z_COMPILER_CONSTANT_LDOUBLE_SIZE	 __SIZEOF_LONG_DOUBLE__
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
#elif define(_MIPS_SZPTR)
#	define Z_COMPILER_CONSTANT_POINTER_BITS	 _MIPS_SZPTR
#	define Z_COMPILER_CONSTANT_POINTER_SIZE	(_MIPS_SZPTR / 8)
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

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT8_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_INT8_ATOMIC_NOT_THEN_GET*/

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_INT8_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	endif

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT16_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_INT16_ATOMIC_NOT_THEN_GET*/

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_INT16_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	endif

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT32_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_INT32_ATOMIC_NOT_THEN_GET*/

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_INT32_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	endif

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT64_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_INT64_ATOMIC_NOT_THEN_GET*/

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_INT64_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	endif

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_INCREMENT_THEN_GET( pointer) __sync_add_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_AND_THEN_GET  __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_DECREMENT_THEN_GET( pointer) __sync_sub_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_INCREMENT( pointer) __sync_fetch_and_add(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_AND  __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_DECREMENT( pointer) __sync_fetch_and_sub(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_NAND  __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_OR  __sync_fetch_and_or
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_XOR  __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_NAND_THEN_GET  __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT128_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_INT128_ATOMIC_NOT_THEN_GET*/

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_OR_THEN_GET  __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_SET_IF_EQUAL  __sync_bool_compare_and_swap
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_INT128_ATOMIC_XOR_THEN_GET  __sync_xor_and_fetch
#	endif

#endif

#endif /* __Z_inspection_compiler_modules_Clang_H__ */
