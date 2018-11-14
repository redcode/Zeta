/* Z Kit - inspection/compiler/modules/Clang.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2018 Ortega Sosa, Sofía.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_compiler_modules_Clang_H_
#define _Z_inspection_compiler_modules_Clang_H_

/* MARK: - Identification */

#ifndef Z_COMPILER
#	include <Z/macros/version.h>

#	define Z_COMPILER		 Z_COMPILER_CLANG
#	define Z_COMPILER_STRING	 Z_COMPILER_STRING_CLANG
#	define Z_COMPILER_VERSION	 Z_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#	define Z_COMPILER_VERSION_STRING __clang_version__
#endif

/* MARK: - Compatibility with old versions */

#ifndef __has_attribute
#	define __has_attribute(which) FALSE
#endif

#ifndef __has_builtin
#	define __has_builtin(which) FALSE
#endif

#ifndef __has_cpp_attribute /* v3.6 */
#	define __has_cpp_attribute(which) FALSE
#endif

#ifndef __has_extension /* v3.0 */
#	define __has_extension __has_feature
#endif

/* MARK: - CPU
.-------------------------------------------------.
| References:					  |
| [Clang sources]/lib/Basic/Targets.cpp		  |
| [Clang sources]/lib/Basic/Targets/<*> (>= v6.0) |
'------------------------------------------------*/

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

#elif defined(__riscv_xlen)

#	if __riscv_xlen == 64
#		define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_RV64I

#	elif __riscv_xlen == 32
#		define Z_COMPILER_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_RV32I
#	endif


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

/* MARK: - CPU endianness / bit field order */

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

#elif	defined(__AARCH64EL__	 ) || \
	defined(__ARMEL__	 ) || \
	defined(__LITTLE_ENDIAN__) || \
	defined(__MIPSEL	 ) || \
	defined(__MIPSEL__	 ) || \
	defined(__THUMBEL__	 ) || \
	defined(_LITTLE_ENDIAN	 ) || \
	defined(_MIPSEL		 )

#	define Z_COMPILER_CPU_INTEGER_ENDIANNESS Z_ENDIANNESS_LITTLE
#	define Z_COMPILER_BIT_FIELD_ORDER	 Z_ORDER_REVERSED

#elif	defined(__AARCH_BIG_ENDIAN) || \
	defined(__AARCH64EB__	  ) || \
	defined(__ARM_BIG_ENDIAN  ) || \
	defined(__ARMEB__	  ) || \
	defined(__MIPSEB	  ) || \
	defined(__MIPSEB__	  ) || \
	defined(_BIG_ENDIAN	  ) || \
	defined(_MIPSEB		  )

#	define Z_COMPILER_CPU_INTEGER_ENDIANNESS Z_ENDIANNESS_BIG
#	define Z_COMPILER_BIT_FIELD_ORDER	 Z_ORDER_NORMAL
#endif

/*#define Z_COMPIER_CPU_INTEGER_ENDIANNESS_8BIT*/
/*#define Z_COMPIER_CPU_INTEGER_ENDIANNESS_16BIT*/
/*#define Z_COMPIER_CPU_INTEGER_ENDIANNESS_32BIT*/
/*#define Z_COMPIER_CPU_INTEGER_ENDIANNESS_64BIT*/
/*#define Z_COMPIER_CPU_INTEGER_ENDIANNESS_128BIT*/

/*#define Z_COMPILER_BIT_FIELD_ORDER_8BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_16BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_32BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_64BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_128BIT*/

/* MARK: - Platform */

/*#define Z_COMPILER_PLATFORM*/

/* MARK: - OS
.-------------------------------------------------.
| References:					  |
| [Clang sources]/lib/Basic/Targets.cpp		  |
| [Clang sources]/lib/Basic/Targets/<*> (>= v6.0) |
'------------------------------------------------*/

#if defined(__ANDROID__)
#	define Z_COMPILER_OS Z_OS_ANDROID

#elif	defined(__gnu_linux__) || \
	defined(__linux	     ) || \
	defined(__linux__    ) || \
	defined(linux	     )

#	define Z_COMPILER_OS Z_OS_LINUX

#elif	defined(__APPLE_CC__) || \
	(defined(__APPLE__) && defined(__MACH__))

#	if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
#		define Z_COMPILER_OS Z_OS_MAC_OS_X

#	elif defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)
#		define Z_COMPILER_OS Z_OS_IOS

#	elif defined(__ENVIRONMENT_TV_OS_VERSION_MIN_REQUIRED__)
#		define Z_COMPILER_OS Z_OS_TVOS

#	elif defined(__ENVIRONMENT_WATCH_OS_VERSION_MIN_REQUIRED__)
#		define Z_COMPILER_OS Z_OS_WATCHOS
#	endif

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

#elif	defined(__CYGWIN__  ) || \
	defined(__CYGWIN32__) || \
	defined(__CYGWIN64__)

#	define Z_COMPILER_OS Z_OS_CYGWIN

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

#elif defined(__rtems__)
#	define Z_COMPILER_OS Z_OS_RTEMS

#elif	defined(__SVR4	) || \
	defined(__sun	) || \
	defined(__sun__	) || \
	defined(__svr4__) || \
	defined(sun	)

#	define Z_COMPILER_OS Z_OS_SOLARIS

#endif

/* MARK: - Data model */

#if	defined(__LP64__) || \
	defined(_LP64	)

#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LP64

#elif defined(__LP32__)
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LP32

#elif defined(_WIN64)
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LLP64

#elif	defined(__ILP32__) || \
	defined(_ILP32	 ) || \
	defined(_WIN32	 )

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

#define Z_COMPILER_C_HAS_DIGRAPHS TRUE

/* MARK: - C99 support */

#define Z_COMPILER_C_HAS_INLINE_FUNCION		      TRUE
#define Z_COMPILER_C_HAS_MAGIC_CONSTANT_FUNCTION_NAME TRUE
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_RESTRICT      TRUE

#if defined(__UINTMAX_MAX__) && 0U - 1U == __UINTMAX_MAX__
#	define Z_COMPILER_C_HAS_PREPROCESSOR_ARITHMETIC_DONE_IN_MAXIMUM_INTEGRAL TRUE
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
#	define Z_COMPILER_C_HAS_CPP_STYLE_COMMENT		   TRUE
#	define Z_COMPILER_C_HAS_MIXED_DECLARATIONS_AND_CODE	   TRUE
#	define Z_COMPILER_C_HAS_NON_CONSTANT_AGGREGATE_INITIALIZER TRUE
#	define Z_COMPILER_C_HAS_SPECIFIER_INLINE		   TRUE
#endif

#if	(defined(__cplusplus) && __cplusplus >= 201103L) || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)

#	define Z_COMPILER_C_HAS_PREPROCESSOR_ARITHMETIC_DONE_IN_MAXIMUM_INTEGRAL TRUE
#	define Z_COMPILER_C_HAS_VARIADIC_MACRO					 TRUE
#	define Z_COMPILER_C_HAS_TYPE_LLONG					 TRUE
#endif

/*-----------------------------------------------------------.
| It seems that Clang always recognizes _Bool, except in C++ |
| (until C++ supports C99, of course).			     |
'-----------------------------------------------------------*/
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined(__cplusplus)
#	define Z_COMPILER_C_HAS_TYPE_BOOLEAN TRUE
#endif

/* MARK: - C11 support */

#if Z_COMPILER_VERSION >= Z_VERSION(3, 1, 0)

#	if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#		define Z_COMPILER_C_HAS_ANONYMOUS_STRUCTURE TRUE
#	endif

#	if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
#		define Z_COMPILER_C_HAS_ANONYMOUS_UNION TRUE
#	endif

#	define Z_COMPILER_C_HAS_SPECIFIER_NO_RETURN TRUE /* Available in older versions? */

#endif

#if __has_feature(c_atomic)
#	define Z_COMPILER_C_HAS_ATOMIC_OPERATIONS     TRUE
#	define Z_COMPILER_C_HAS_SPECIFIER_ATOMIC      TRUE
#	define Z_COMPILER_C_HAS_TYPE_QUALIFIER_ATOMIC TRUE
#endif

#if __has_feature(c_generic_selections)
#	define Z_COMPILER_C_HAS_GENERIC_SELECTION TRUE
#endif

#if __has_feature(c_static_assert)
#	define Z_COMPILER_C_HAS_STATIC_ASSERTION TRUE
#endif

#if __has_feature(c_alignof)
#	define Z_COMPILER_C_HAS_OPERATOR_ALIGN_OF TRUE
#endif

#if __has_feature(c_alignas)
#	define Z_COMPILER_C_HAS_SPECIFIER_ALIGN_AS TRUE
#endif

#if __has_feature(c_thread_local)
#	define Z_COMPILER_C_HAS_STORATE_CLASS_THREAD_LOCAL TRUE
#endif

/* MARK: - C18 support */

/* MARK: - Apple C extensions support */

#if __has_extension(blocks)
#	define Z_COMPILER_C_HAS_CLOSURE TRUE
#endif

#ifdef __cplusplus

	/*---------------------------------------------------.
	| References:					     |
	| https://clang.llvm.org/cxx_status.html	     |
	| https://en.cppreference.com/w/cpp/compiler_support |
	| [Clang sources]/lib/Lex/PPMacroExpansion.cpp	     |
	'---------------------------------------------------*/

	/* MARK: - C++98 support */

#	define Z_COMPILER_CPP_HAS_SFINAE       TRUE
#	define Z_COMPILER_CPP_HAS_TYPE_BOOLEAN TRUE
#	define Z_COMPILER_CPP_HAS_TYPE_WCHAR   TRUE

	/* MARK: - C++03 support */

#	define Z_COMPILER_CPP_HAS_VALUE_INITIALIZATION TRUE

	/* MARK: - C++11 support */

#	if Z_COMPILER_VERSION >= Z_VERSION(2, 9, 0)
#		define Z_COMPILER_CPP_HAS_EXPRESSION_SFINAE	       TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_MAGIC_CONSTANT_FUNCTION_NAME TRUE /* v2.9 (Available in older versions?) */

#		if Z_COMPILER_VERSION >= Z_VERSION(3, 1, 0)
#			define Z_COMPILER_CPP_HAS_CPP11_RULES_ON_UNIVERSAL_CHARACTER_NAME TRUE /* v3.1 */
#		endif
#	endif

#	if __cplusplus >= 201103L && Z_COMPILER_VERSION >= Z_VERSION(2, 9, 0)
#		define Z_COMPILER_CPP_HAS_C99_PREPROCESSOR			   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_CONCURRENT_STATIC_LOCAL_VARIABLE	   TRUE /* v2.9 (Available in older standards?) */
#		define Z_COMPILER_CPP_HAS_CONDITIONALLY_SUPPORTED_BEHAVIOR	   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_EXTENDED_FRIEND_DECLARATION		   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_EXTERN_TEMPLATE			   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_INITIALIZATION_OF_CLASS_OBJECT_BY_RVALUE TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_RIGHT_ANGLE_BRACKETS			   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_LITERAL_CHAR16_CHARACTER		   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_LITERAL_CHAR16_STRING			   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_LITERAL_CHAR32_CHARACTER		   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_LITERAL_CHAR32_STRING			   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_TYPE_CHAR16				   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_TYPE_CHAR32				   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_TYPE_LLONG				   TRUE /* v2.9 */

#		if Z_COMPILER_VERSION >= Z_VERSION(3, 0, 0)
#			define Z_COMPILER_CPP_HAS_STANDARD_LAYOUT TRUE /* v3.0 */

#			if Z_COMPILER_VERSION >= Z_VERSION(3, 1, 0)
#				define Z_COMPILER_CPP_HAS_FORWARD_DECLARATION_OF_ENUMERATION	  TRUE /* v3.1 */
#				define Z_COMPILER_CPP_HAS_OPERATOR_SIZE_OF_NON_STATIC_DATA_MEMBER TRUE /* v3.1 */
#			endif
#		endif
#	endif

#	if __has_feature(cxx_generalized_initializers)
#		define Z_COMPILER_CPP_HAS_COPY_LIST_INITIALIZATION   TRUE /* v3.1 */
#		define Z_COMPILER_CPP_HAS_DIRECT_LIST_INITIALIZATION TRUE /* v3.1 */
#		define Z_COMPILER_CPP_HAS_INITIALIZER_LIST	     TRUE /* v3.1 */
#	endif

#	if	__has_feature(cxx_local_type_template_args) || \
		(__cplusplus >= 201103L			    && \
		 Z_COMPILER_VERSION >= Z_VERSION(2, 9, 0)   && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 1, 0))

#		define Z_COMPILER_CPP_HAS_LOCAL_TYPE_AS_TEMPLATE_ARGUMENT   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_UNNAMED_TYPE_AS_TEMPLATE_ARGUMENT TRUE /* v2.9 */
#	endif

#	if __has_feature(cxx_auto_type)
#		undef  Z_COMPILER_C_HAS_STORAGE_CLASS_AUTO
#		define Z_COMPILER_CPP_HAS_MULTI_DECLARATOR_AUTO		   TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_REMOVAL_OF_AUTO_AS_STORAGE_CLASS TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_SPECIFIER_AUTO		   TRUE /* v2.9 */
#	endif

#	if __has_feature(cxx_rvalue_references)
#		define Z_COMPILER_CPP_HAS_RVALUE_REFERENCE TRUE /* v2.9 */

#		if Z_COMPILER_VERSION >= Z_VERSION(3, 0, 0)
#			define Z_COMPILER_CPP_HAS_MOVE_SPECIAL_MEMBER_FUNCTIONS TRUE /* v3.0 */
#		endif
#	endif

#	if __has_feature(cxx_attributes)
#		define Z_COMPILER_CPP_HAS_STANDARDIZED_ATTRIBUTE_SYNTAX TRUE /* v3.3 */
#		define Z_COMPILER_CPP_HAS_ATTRIBUTE_CARRIES_DEPENDENCY	TRUE /* v3.3 */
#		define Z_COMPILER_CPP_HAS_ATTRIBUTE_NO_RETURN		TRUE /* v3.3 */
#	endif

#	if __has_feature(cxx_variadic_templates)
#		define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE			TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE_EXTENDED_PARAMETERS TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_OPERATOR_SIZE_OF_PARAMETER_PACK	TRUE /* v2.9 */
#	endif

#	if __has_feature(cxx_nonstatic_member_init)
#		define Z_COMPILER_CPP_HAS_DEFAULT_MEMBER_INITIALIZER TRUE /* v3.0 */
#	endif

#	if __has_feature(cxx_default_function_template_args)
#		define Z_COMPILER_CPP_HAS_DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE TRUE /* v2.9 */
#	endif

#	if	__has_feature(cxx_defaulted_functions)	    || \
		(__cplusplus >= 201103L			    && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 0, 0)   && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 1, 0))

#		define Z_COMPILER_CPP_HAS_DEFAULTED_FUNCTION TRUE /* v3.0 */
#	endif

#	if __has_feature(cxx_delegating_constructors)
#		define Z_COMPILER_CPP_HAS_DELEGATING_CONSTRUCTORS TRUE /* v3.0 */
#	endif

#	if __has_feature(cxx_deleted_functions)
#		define Z_COMPILER_CPP_HAS_DELETED_FUNCTION TRUE /* v2.9 */
#	endif

#	if __has_feature(cxx_explicit_conversions)
#		define Z_COMPILER_CPP_HAS_EXPLICIT_CONVERSION_FUNCTION TRUE /* v3.0 */
#	endif

#	if __has_feature(cxx_inheriting_constructors)
#		define Z_COMPILER_CPP_HAS_INHERITING_CONSTRUCTORS TRUE /* v3.3 */
#	endif

#	if __has_feature(cxx_inline_namespaces)
#		define Z_COMPILER_CPP_HAS_INLINE_NAMESPACE TRUE /* v2.9 */
#	endif

#	if __has_feature(cxx_lambdas)
#		define Z_COMPILER_CPP_HAS_LAMBDA TRUE /* v3.1 */
#	endif

#	if __has_feature(cxx_range_for)
#		define Z_COMPILER_CPP_HAS_RANGE_BASED_FOR TRUE /* v3.0 */
#	endif

#	if __has_feature(cxx_reference_qualified_functions)
#		define Z_COMPILER_CPP_HAS_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION TRUE /* v2.9 */
#	endif

#	if __has_feature(cxx_static_assert)
#		define Z_COMPILER_CPP_HAS_STATIC_ASSERTION TRUE /* v2.9 */
#	endif

#	if __has_feature(cxx_strong_enums)
#		define Z_COMPILER_CPP_HAS_STRONGLY_TYPED_ENUMERATION TRUE /* v2.9 */
#	endif

#	if __has_feature(cxx_alias_templates)
#		define Z_COMPILER_CPP_HAS_TEMPLATE_ALIAS TRUE /* v3.0 */
#	endif

#	if __has_feature(cxx_trailing_return)
#		define Z_COMPILER_CPP_HAS_TRAILING_RETURN_TYPE TRUE /* v2.9 */
#	endif

#	if __has_feature(cxx_unrestricted_unions)
#		define Z_COMPILER_CPP_HAS_UNRESTRICTED_UNION TRUE /* v3.1 */
#	endif

#	if __has_feature(cxx_nullptr)
#		define Z_COMPILER_CPP_HAS_LITERAL_NULL_POINTER TRUE /* v3.0 */
#	endif

#	if	__has_feature(cxx_raw_string_literals)	  || \
		(__cplusplus >= 201103L			  && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 0, 0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 1, 0))

#		define Z_COMPILER_CPP_HAS_LITERAL_RAW_STRING TRUE /* v3.0 */
#	endif

#	if	__has_feature(cxx_unicode_literals)	  || \
		(__cplusplus >= 201103L			  && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 0, 0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 1, 0))

#		define Z_COMPILER_CPP_HAS_LITERAL_UNICODE_STRING TRUE /* v3.0 */
#	endif

#	if __has_feature(cxx_user_literals)
#		define Z_COMPILER_CPP_HAS_LITERAL_USER_DEFINED TRUE /* v3.1 */
#	endif

#	if	__has_feature(cxx_alignof)		  || \
		(__cplusplus >= 201103L			  && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 3, 0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 6, 0))

#		define Z_COMPILER_CPP_HAS_OPERATOR_ALIGN_OF TRUE /* v3.3 */
#	endif

#	if __has_feature(cxx_noexcept)
#		define Z_COMPILER_CPP_HAS_OPERATOR_NO_EXCEPTION TRUE /* v3.0 */
#	endif

#	if __has_feature(cxx_alignas)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_ALIGN_AS TRUE /* v3.3 */
#	endif

#	if __has_feature(cxx_constexpr)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_CONSTANT_EXPRESSION TRUE /* v3.1 */
#	endif

#	if __has_feature(cxx_decltype)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_DECLARED_TYPE TRUE /* v2.9 */
#	endif

#	if __has_feature(cxx_decltype_incomplete_return_types)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_DECLARED_TYPE_OF_INCOMPLETE_RETURN TRUE /* v3.1 */
#	endif

#	if __has_feature(cxx_override_control)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_FINAL    TRUE /* v3.0 */
#		define Z_COMPILER_CPP_HAS_SPECIFIER_OVERRIDE TRUE /* v3.0 */
#	endif

#	if __has_feature(cxx_noexcept)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_NO_EXCEPTION TRUE /* v3.0 */
#	endif

	/*-----------------------------------------------.
	| IMPORTANT: STORATE_CLASS_THREAD_LOCAL requires |
	| a C++ runtime providing __cxa_thread_atexit.	 |
	'-----------------------------------------------*/
#	if __has_feature(cxx_thread_local)
#		define Z_COMPILER_CPP_HAS_STORATE_CLASS_THREAD_LOCAL TRUE /* v3.3 */
#	endif

	/* MARK: - C++14 support */

#	if	defined(__cpp_digit_separators)		  || \
		(__cplusplus >= 201402L			  && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 4, 0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 6, 0))

#		define Z_COMPILER_CPP_HAS_APOSTROPHE_AS_DIGIT_SEPARATOR TRUE /* v3.4 */
#	endif

#	if __has_feature(cxx_relaxed_constexpr)
#		define Z_COMPILER_CPP_HAS_CPP14_RULES_ON_CONSTANT_EXPRESSION_FUNCTION TRUE /* v3.4 */
#	endif

#	if __has_feature(cxx_contextual_conversions)
#		define Z_COMPILER_CPP_HAS_CPP14_RULES_ON_CONTEXTUAL_CONVERSION TRUE /* v3.4 */
#	endif

#	if __has_feature(cxx_aggregate_nsdmi)
#		define Z_COMPILER_CPP_HAS_DEFAULT_MEMBER_INITIALIZER_FOR_AGGREGATE TRUE /* v3.3 */
#	endif

#	if	__has_feature(cxx_generic_lambdas)	  || \
		(__cplusplus >= 201402L			  && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 4, 0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 5, 0))

#		define Z_COMPILER_CPP_HAS_GENERIC_LAMBDA TRUE /* v3.4 */
#	endif

#	if __has_feature(cxx_init_captures)
#		define Z_COMPILER_CPP_HAS_INITIALIZED_LAMBDA_CAPTURE TRUE /* v3.4 */
#	endif

#	if __has_feature(cxx_return_type_deduction)
#		define Z_COMPILER_CPP_HAS_RETURN_TYPE_DEDUCTION_FOR_NORMAL_FUNCTION TRUE /* v3.4 */
#	endif

	/*-----------------------------------------------------------------------.
	| IMPORTANT: In Clang v3.7 and later, SIZED_DEALLOCATION is only enabled |
	| if the user passes the -fsized-deallocation flag. The user must supply |
	| definitions of the sized deallocation functions, either by providing	 |
	| them explicitly or by using a C++ standard library that does.		 |
	'-----------------------------------------------------------------------*/
#	if	__cplusplus >= 201402L			 && \
		Z_COMPILER_VERSION >= Z_VERSION(3, 4, 0) && \
		Z_COMPILER_VERSION <  Z_VERSION(3, 7, 0)

#		define Z_COMPILER_CPP_HAS_SIZED_DEALLOCATION TRUE /* v3.4 */
#	endif

#	if __has_feature(cxx_variable_templates)
#		define Z_COMPILER_CPP_HAS_VARIABLE_TEMPLATE TRUE /* v3.4 */
#	endif

#	if	__has_cpp_attribute(deprecated)		  || \
		(__cplusplus >= 201402L			  && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 4, 0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 6, 0))

#		define Z_COMPILER_CPP_HAS_ATTRIBUTE_DEPRECATED TRUE /* v3.4 */
#	endif

#	if	__has_feature(cxx_binary_literals)	  || \
		(__cplusplus >= 201402L			  && \
		 Z_COMPILER_VERSION >= Z_VERSION(2, 9, 0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 3, 0))

#		define Z_COMPILER_CPP_HAS_LITERAL_BINARY TRUE /* v2.9 */
#	endif

#	if	__has_feature(cxx_decltype_auto)	  || \
		(__cplusplus >= 201402L			  && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 3, 0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 5, 0))

#		define Z_COMPILER_CPP_HAS_SPECIFIER_DECLARED_TYPE_OF_AUTO TRUE /* v3.3 */
#	endif

	/* MARK: - C++17 support */

	/*#define Z_COMPILER_CPP_HAS_AGGREGATE_WITH_BASE_CLASSES*/
	/*#define Z_COMPILER_CPP_HAS_ATTRIBUTES_FOR_ENUMERATION*/
	/*#define Z_COMPILER_CPP_HAS_ATTRIBUTES_FOR_NAMESPACE*/
	/*#define Z_COMPILER_CPP_HAS_ATTRIBUTE_USING_PREFIX*/
	/*#define Z_COMPILER_CPP_HAS_CONSTANT_EXPRESSION_IF*/
	/*#define Z_COMPILER_CPP_HAS_CONSTANT_EXPRESSION_LAMBDA*/
	/*#define Z_COMPILER_CPP_HAS_CPP17_RULES_ON_BRACED_INITIALIZATION*/
	/*#define Z_COMPILER_CPP_HAS_CPP17_RULES_ON_EXPRESSION_EVALUATION_ORDER*/
	/*#define Z_COMPILER_CPP_HAS_CPP17_RULES_ON_INHERITING_CONSTRUCTORS*/
	/*#define Z_COMPILER_CPP_HAS_CPP17_RULES_ON_NON_TYPE_TEMPLATE_ARGUMENTS*/
	/*#define Z_COMPILER_CPP_HAS_CPP17_RULES_ON_TEMPLATE_TEMPLATE_ARGUMENT_MATCHING*/
	/*#define Z_COMPILER_CPP_HAS_DIFFERING_BEGIN_AND_END_TYPES_IN_RANGE_BASED_FOR*/
	/*#define Z_COMPILER_CPP_HAS_DIRECT_LIST_INITIALIZATION_OF_ENUMERATION*/
	/*#define Z_COMPILER_CPP_HAS_EXCEPTION_SPECIFICATION_AS_PART_OF_THE_TYPE*/
	/*#define Z_COMPILER_CPP_HAS_FOLD_EXPRESSION*/
	/*#define Z_COMPILER_CPP_HAS_FOLD_EXPRESSION_SAFETY_WITH_EMPTY_PARAMETER_PACK*/
	/*#define Z_COMPILER_CPP_HAS_GUARANTEED_COPY_ELISION*/
	/*#define Z_COMPILER_CPP_HAS_IF_WITH_INITIALIZER*/
	/*#define Z_COMPILER_CPP_HAS_IGNORATION_OF_UNKNOWN_ATTRIBUTES*/
	/*#define Z_COMPILER_CPP_HAS_INLINE_VARIABLE*/
	/*#define Z_COMPILER_CPP_HAS_LAMBDA_CAPTURE_OF_THIS_OBJECT_BY_VALUE*/
	/*#define Z_COMPILER_CPP_HAS_LAUNDER*/
	/*#define Z_COMPILER_CPP_HAS_NESTED_NAMESPACE_DEFINITION*/
	/*#define Z_COMPILER_CPP_HAS_NON_TYPE_TEMPLATE_PARAMETER_WITH_AUTO_TYPE*/
	/*#define Z_COMPILER_CPP_HAS_OVER_ALIGNED_DYNAMIC_ALLOCATION*/
	/*#define Z_COMPILER_CPP_HAS_REMOVAL_OF_DYNAMIC_EXCEPTION_SPECIFICATION*/
	/*#define Z_COMPILER_CPP_HAS_REMOVAL_OF_INCREMENT_BOOLEAN_OPERATOR*/
	/*#define Z_COMPILER_CPP_HAS_REMOVAL_OF_REGISTER_AS_STORAGE_CLASS*/
	/*#define Z_COMPILER_CPP_HAS_REMOVAL_OF_TRIGRAPHS*/
	/*#define Z_COMPILER_CPP_HAS_STATIC_ASSERTION_WITH_NO_MESSAGE*/
	/*#define Z_COMPILER_CPP_HAS_STRUCTURED_BINDING*/
	/*#define Z_COMPILER_CPP_HAS_SWITCH_WITH_INITIALIZER*/
	/*#define Z_COMPILER_CPP_HAS_TEMPLATE_ARGUMENTS_DEDUCTION_FOR_CLASS_TEMPLATE*/
	/*#define Z_COMPILER_CPP_HAS_TYPENAME_IN_TEMPLATE_TEMPLATE_PARAMETER*/
	/*#define Z_COMPILER_CPP_HAS_VARIADIC_USING*/
	/*#define Z_COMPILER_CPP_HAS_ATTRIBUTE_FALL_THROUGH*/
	/*#define Z_COMPILER_CPP_HAS_ATTRIBUTE_MAYBE_UNUSED*/
	/*#define Z_COMPILER_CPP_HAS_ATTRIBUTE_NO_DISCARD*/

#if	__cplusplus >= 201703L
#		define Z_COMPILER_CPP_HAS_LITERAL_HEXADECIMAL_FLOATING_POINT TRUE /* All versions */
#	endif

	/*#define Z_COMPILER_CPP_HAS_LITERAL_UTF8_CHARACTER*/

#	define Z_COMPILER_CPP_HAS_PREPROCESSOR_OPERATOR_HAS_INCLUDE TRUE /* All versions */

#endif

/* MARK: - Attributes */

#if __has_attribute(alias)
#	define Z_COMPILER_ATTRIBUTE_ALIAS(name) __attribute__((alias(name)))
#endif

#if __has_attribute(dllimport)
#	define Z_COMPILER_ATTRIBUTE_API __declspec(dllimport)
#endif

#if __has_attribute(dllexport)
#	define Z_COMPILER_ATTRIBUTE_API_EXPORT __declspec(dllexport)
#endif

/*#define Z_COMPILER_ATTRIBUTE_API_ALIAS*/
/*#define Z_COMPILER_ATTRIBUTE_API_EXPORT_ALIAS*/
/*#define Z_COMPILER_ATTRIBUTE_API_WEAK_EXPORT*/
/*#define Z_COMPILER_ATTRIBUTE_EBCO*/

#if __has_attribute(always_inline)
#	define Z_COMPILER_ATTRIBUTE_INLINE __inline__ __attribute__((always_inline))
#else
#	define Z_COMPILER_ATTRIBUTE_INLINE __inline__
#endif

#if __has_attribute(noreturn)
#	define Z_COMPILER_ATTRIBUTE_NO_RETURN __attribute__((noreturn))
#endif

#if __has_attribute(sentinel)
#	define Z_COMPILER_ATTRIBUTE_NULL_TERMINATED __attribute__((sentinel))
#endif

#if __has_attribute(visibility)
#	define Z_COMPILER_ATTRIBUTE_PRIVATE __attribute__((visibility("hidden")))
#	define Z_COMPILER_ATTRIBUTE_PUBLIC  __attribute__((visibility("default")))
#endif

#if __has_attribute(packed)
#	define Z_COMPILER_ATTRIBUTE_STRICT_SIZE_BEGIN
#	define Z_COMPILER_ATTRIBUTE_STRICT_SIZE_END __attribute__((packed))
#endif

#if __has_extension(tls)
#	define Z_COMPILER_ATTRIBUTE_THREAD_LOCAL __thread
#endif

#if __has_attribute(weak)
#	define Z_COMPILER_ATTRIBUTE_WEAK __attribute__((weak))
#endif

/* MARK: - Built-in constants */

/*#define Z_COMPILER_CONSTANT_FLOAT16_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT16_NAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT32_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT32_NAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT64_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT64_NAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT128_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT128_NAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT80_X87_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT80_X87_NAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT96_X87_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT96_X87_NAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT128_X87_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT128_X87_NAN*/

#ifdef __CHAR_BIT__
#	define Z_COMPILER_CONSTANT_UCHAR_BITS __CHAR_BIT__
#	define Z_COMPILER_CONSTANT_SCHAR_BITS __CHAR_BIT__
#endif

#ifdef __SCHAR_MAX__
#	define Z_COMPILER_CONSTANT_SCHAR_MAXIMUM __SCHAR_MAX__
#endif

#ifdef __SIZEOF_SHORT__
#	define Z_COMPILER_CONSTANT_USHORT_SIZE __SIZEOF_SHORT__
#	define Z_COMPILER_CONSTANT_SSHORT_SIZE __SIZEOF_SHORT__
#endif

#ifdef __SHRT_MAX__
#	define Z_COMPILER_CONSTANT_SHORT_MAXIMUM __SHRT_MAX__
#endif

#ifdef __SIZEOF_INT__
#	define Z_COMPILER_CONSTANT_UINT_SIZE __SIZEOF_INT__
#	define Z_COMPILER_CONSTANT_SINT_SIZE __SIZEOF_INT__
#endif

#ifdef _MIPS_SZINT
#	define Z_COMPILER_CONSTANT_UINT_BITS _MIPS_SZINT
#	define Z_COMPILER_CONSTANT_SINT_BITS _MIPS_SZINT
#endif

#ifdef __INT_MAX__
#	define Z_COMPILER_CONSTANT_SINT_MAXIMUM __INT_MAX__
#endif

#ifdef __SIZEOF_LONG__
#	define Z_COMPILER_CONSTANT_ULONG_SIZE __SIZEOF_LONG__
#	define Z_COMPILER_CONSTANT_SLONG_SIZE __SIZEOF_LONG__
#endif

#ifdef _MIPS_SZLONG
#	define Z_COMPILER_CONSTANT_ULONG_BITS _MIPS_SZLONG
#	define Z_COMPILER_CONSTANT_SLONG_BITS _MIPS_SZLONG
#endif

/*#define Z_COMPILER_CONSTANT_ULONG_MAXIMUM*/

#ifdef __LONG_MAX__
#	define Z_COMPILER_CONSTANT_SLONG_MAXIMUM __LONG_MAX__
#endif

#ifdef __SIZEOF_LONG_LONG__
#	define Z_COMPILER_CONSTANT_ULLONG_SIZE __SIZEOF_LONG_LONG__
#	define Z_COMPILER_CONSTANT_SLLONG_SIZE __SIZEOF_LONG_LONG__
#endif

/*#define Z_COMPILER_CONSTANT_ULLONG_MAXIMUM*/

#ifdef __LONG_LONG_MAX__
#	define Z_COMPILER_CONSTANT_SLLONG_MAXIMUM __LONG_LONG_MAX__
#endif

#ifdef __SIZEOF_FLOAT__
#	define Z_COMPILER_CONSTANT_FLOAT_SIZE __SIZEOF_FLOAT__
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
#	define Z_COMPILER_CONSTANT_DOUBLE_SIZE __SIZEOF_DOUBLE__
#endif

#if __has_builtin(__builtin_huge_val)
#	define Z_COMPILER_CONSTANT_DOUBLE_INFINITY __builtin_huge_val()
#elif __has_builtin(__builtin_inf)
#	define Z_COMPILER_CONSTANT_DOUBLE_INFINITY __builtin_inf()
#endif

#if __has_builtin(__builtin_nan)
#	define Z_COMPILER_CONSTANT_DOUBLE_NAN __builtin_nan("")
#endif

#if defined(__LONG_DOUBLE_128__) || defined(__LONGDOUBLE128)
#	define Z_COMPILER_CONSTANT_LDOUBLE_PRECISION_BITS 128 /* TODO */
#endif

#ifdef __SIZEOF_LONG_DOUBLE__
#	define Z_COMPILER_CONSTANT_LDOUBLE_SIZE __SIZEOF_LONG_DOUBLE__
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
#	define Z_COMPILER_CONSTANT_SIZE_SIZE  __SIZEOF_SIZE_T__
#	define Z_COMPILER_CONSTANT_SSIZE_SIZE __SIZEOF_SIZE_T__
#elif defined(__SIZE_WIDTH__)
#	define Z_COMPILER_CONSTANT_SIZE_BITS  __SIZE_WIDTH__
#	define Z_COMPILER_CONSTANT_SSIZE_BITS __SIZE_WIDTH__
#endif

#if defined(__SIZEOF_POINTER__)
#	define Z_COMPILER_CONSTANT_POINTER_SIZE __SIZEOF_POINTER__
#elif defined(__UINTPTR_WIDTH__)
#	define Z_COMPILER_CONSTANT_POINTER_BITS __UINTPTR_WIDTH__
#elif defined(__INTPTR_WIDTH__)
#	define Z_COMPILER_CONSTANT_POINTER_BITS __INTPTR_WIDTH__
#elif define(_MIPS_SZPTR)
#	define Z_COMPILER_CONSTANT_POINTER_BITS _MIPS_SZPTR
#endif

/* MARK: - Built-in magic constants */

#define Z_COMPILER_MAGIC_CONSTANT_MANGLED_FUNCTION_NAME __PRETTY_FUNCTION__

/* MARK: - Built-in macros: Struture */

#pragma clang diagnostic ignored "-Wextended-offsetof"
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
/*#define Z_COMPILER_TYPE_FLOAT32*/
/*#define Z_COMPILER_TYPE_FLOAT64*/
/*#define Z_COMPILER_TYPE_FLOAT128*/
/*#define Z_COMPILER_TYPE_FLOAT80_X87*/
/*#define Z_COMPILER_TYPE_FLOAT96_X87*/
/*#define Z_COMPILER_TYPE_FLOAT128_X87*/

#ifdef __FLOAT128__
#	define Z_COMPILER_TYPE_FLOAT128 __float128
#endif

#define Z_COMPILER_TYPE_VAL __builtin_va_list

/* MARK: - Suffix macros for built-in types */

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
/*#define Z_COMPILER_LITERAL_FLOAT32*/
/*#define Z_COMPILER_LITERAL_FLOAT64*/
/*#define Z_COMPILER_LITERAL_FLOAT128*/
/*#define Z_COMPILER_LITERAL_FLOAT80_X87*/
/*#define Z_COMPILER_LITERAL_FLOAT96_X87*/
/*#define Z_COMPILER_LITERAL_FLOAT128_X87*/

/* MARK: - Built-in functions: Atomic operations */

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_ADD_THEN_GET		    __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_SUBTRACT_THEN_GET	    __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_SUBTRACT	    __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT8_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_SINT8_ATOMIC_NOT_THEN_GET*/

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	endif

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT16_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_SINT16_ATOMIC_NOT_THEN_GET*/

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT16_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_SINT16_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	endif

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT32_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_SINT32_ATOMIC_NOT_THEN_GET*/

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT32_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_SINT32_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	endif

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_ADD_THEN_GET		     __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_ADD		     __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_SUBTRACT	     __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT64_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_SINT64_ATOMIC_NOT_THEN_GET*/

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT64_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_SINT64_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	endif

#endif

#if __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16

#	if __has_builtin(__sync_add_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_ADD_THEN_GET		      __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_ADD_THEN_GET		      __sync_add_and_fetch
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_INCREMENT_THEN_GET(pointer) __sync_add_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_and_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_AND_THEN_GET __sync_and_and_fetch
#	endif

#	if __has_builtin(__sync_sub_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_SUBTRACT_THEN_GET	     __sync_sub_and_fetch
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_DECREMENT_THEN_GET(pointer) __sync_sub_and_fetch(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_add)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_ADD		      __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_ADD		      __sync_fetch_and_add
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_and)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_AND __sync_fetch_and_and
#	endif

#	if __has_builtin(__sync_fetch_and_sub)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SUBTRACT	      __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_SUBTRACT	      __sync_fetch_and_sub
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_DECREMENT(pointer) __sync_fetch_and_sub(pointer, 1)
#	endif

#	if __has_builtin(__sync_fetch_and_nand)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_NOT*/
	/*#define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_NOT*/

#	if __has_builtin(__sync_fetch_and_or)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_OR __sync_fetch_and_or
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SET*/
	/*#define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_SET*/

#	if __has_builtin(__sync_fetch_and_xor)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor
#	endif

#	if __has_builtin(__sync_nand_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch
#	endif

	/*#define Z_COMPILER_FUNCTION_UINT128_ATOMIC_NOT_THEN_GET*/
	/*#define Z_COMPILER_FUNCTION_SINT128_ATOMIC_NOT_THEN_GET*/

#	if __has_builtin(__sync_or_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_OR_THEN_GET __sync_or_and_fetch
#	endif

#	if __has_builtin(__sync_bool_compare_and_swap)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap
#	endif

#	if __has_builtin(__sync_xor_and_fetch)
#		define Z_COMPILER_FUNCTION_UINT128_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#		define Z_COMPILER_FUNCTION_SINT128_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch
#	endif

#endif

/* MARK: - Built-in traits */

#if __has_extension(has_virtual_destructor)
#	define Z_COMPILER_TRAIT_TYPE_HAS_VIRTUAL_DESTRUCTOR __has_virtual_destructor
#endif

#if __has_extension(is_abstract)
#	define Z_COMPILER_TRAIT_TYPE_IS_ABSTRACT __is_abstract
#endif

#if __has_extension(is_aggregate)
#	define Z_COMPILER_TRAIT_TYPE_IS_AGGREGATE __is_aggregate
#endif

#if __has_extension(is_assignable)
#	define Z_COMPILER_TRAIT_TYPE_IS_ASSIGNABLE __is_assignable
#endif

#if __has_extension(is_base_of)
#	define Z_COMPILER_TRAIT_TYPE_IS_BASE __is_base_of
#endif

#if __has_extension(is_class)
#	define Z_COMPILER_TRAIT_TYPE_IS_CLASS __is_class
#endif

#if __has_extension(is_constructible)
#	define Z_COMPILER_TRAIT_TYPE_IS_CONSTRUCTIBLE __is_constructible
#endif

#if __has_extension(is_convertible_to)
#	define Z_COMPILER_TRAIT_TYPE_IS_CONVERTIBLE __is_convertible_to
#endif

#if __has_extension(is_empty)
#	define Z_COMPILER_TRAIT_TYPE_IS_EMPTY __is_empty
#endif

#if __has_extension(is_enum)
#	define Z_COMPILER_TRAIT_TYPE_IS_ENUMERATION __is_enum
#endif

#if __has_extension(is_final)
#	define Z_COMPILER_TRAIT_TYPE_IS_FINAL __is_final
#endif

#if __has_extension(is_interface_class)
#	define Z_COMPILER_TRAIT_TYPE_IS_INTERFACE_CLASS __is_interface_class
#endif

#if __has_extension(is_literal_type)
#	define Z_COMPILER_TRAIT_TYPE_IS_LITERAL __is_literal_type
#elif __has_extension(is_literal)
#	define Z_COMPILER_TRAIT_TYPE_IS_LITERAL __is_literal
#endif

#if __has_extension(is_nothrow_assignable)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_ASSIGNABLE __is_nothrow_assignable
#endif

#if __has_extension(is_nothrow_constructible)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_CONSTRUCTIBLE __is_nothrow_constructible
#endif

#if __has_extension(has_nothrow_assign)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_COPY_ASSIGNABLE __has_nothrow_assign
#endif

#if __has_extension(has_nothrow_copy)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_COPY_CONSTRUCTIBLE __has_nothrow_copy
#endif

#if __has_extension(has_nothrow_constructor)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_DEFAULT_CONSTRUCTIBLE __has_nothrow_constructor
#endif

#if __has_extension(is_pod)
#	define Z_COMPILER_TRAIT_TYPE_IS_POD __is_pod
#endif

#if __has_extension(is_polymorphic)
#	define Z_COMPILER_TRAIT_TYPE_IS_POLYMORPHIC __is_polymorphic
#endif

#if __has_extension(is_standard_layout)
#	define Z_COMPILER_TRAIT_TYPE_IS_STANDARD_LAYOUT __is_standard_layout
#endif

#if __has_extension(is_trivial)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIAL __is_trivial
#endif

#if __has_extension(is_trivially_assignable)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_ASSIGNABLE __is_trivially_assignable
#endif

#if __has_extension(is_trivially_constructible)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_CONSTRUCTIBLE __is_trivially_constructible
#endif

#if __has_extension(has_trivial_assign)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_COPY_ASSIGNABLE __has_trivial_assign
#endif

#if __has_extension(has_trivial_copy)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE __has_trivial_copy
#endif

#if __has_extension(is_trivially_copyable)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_COPYABLE __is_trivially_copyable
#endif

#if __has_extension(has_trivial_constructor)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE __has_trivial_constructor
#endif

#if __has_extension(has_trivial_destructor)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_DESTRUCTIBLE __has_trivial_destructor
#endif

#if __has_extension(is_union)
#	define Z_COMPILER_TRAIT_TYPE_IS_UNION __is_union
#endif

#if __has_extension(underlying_type)
#	define Z_COMPILER_TRAIT_TYPE_UNDERLYING_TYPE __underlying_type
#endif

/*
#if __has_extension()
#	define Z_COMPILER_TRAIT_TYPE
#endif

__is_destructible
__is_nothrow_destructible
__reference_binds_to_temporary
*/

#endif /* _Z_inspection_compiler_modules_Clang_H_ */
