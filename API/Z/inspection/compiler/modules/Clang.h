/* Z Kit - inspection/compiler/modules/Clang.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2018 Sofía Ortega Sosa.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_compiler_modules_Clang_H
#define Z_inspection_compiler_modules_Clang_H

/* MARK: - Private helpers */

#ifdef __has_attribute /* v2.9 */
#	define Z__HAS_ATTRIBUTE __has_attribute
#else
#	define Z__HAS_ATTRIBUTE(which) FALSE
#endif

#ifdef __has_cpp_attribute /* v3.6 */
#	define Z__HAS_CPP_ATTRIBUTE __has_cpp_attribute
#else
#	define Z__HAS_CPP_ATTRIBUTE(which) FALSE
#endif

#ifdef __has_extension /* v3.0 */
#	define Z__HAS_EXTENSION __has_extension
#else
#	define Z__HAS_EXTENSION __has_feature
#endif

/* MARK: - Identification */

#define Z_COMPILER_NAME Z_COMPILER_NAME_CLANG

#if defined(__clang_version__) /* v2.8 */
#	define Z_COMPILER_VERSION	 Z_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#	define Z_COMPILER_VERSION_STRING __clang_version__

#elif defined(__SIZE_WIDTH__) /* v2.7 */
#	define Z_COMPILER_VERSION	 Z_VERSION(2, 7, 0)
#	define Z_COMPILER_VERSION_STRING "2.7"
#else
#	define Z_COMPILER_VERSION	 Z_VERSION(2, 6, 0)
#	define Z_COMPILER_VERSION_STRING "2.6"
#endif

/* MARK: - ISA */

#if	defined(__amd64	  ) /* v2.6 */ || \
	defined(__amd64__ ) /* v2.6 */ || \
	defined(__x86_64  ) /* v2.6 */ || \
	defined(__x86_64__) /* v2.6 */ || \
	defined(_M_AMD64  ) /* v2.9 */ || \
	defined(_M_X64	  ) /* v2.7 */

#	define Z_COMPILER_ISA Z_ISA_X86_64

#elif	defined(__INTEL__) /* v2.8 */ || \
	defined(__i386	 ) /* v2.6 */ || \
	defined(__i386__ ) /* v2.6 */ || \
	defined(__i486	 ) /* v3.0 */ || \
	defined(__i486__ ) /* v3.0 */ || \
	defined(__i586	 ) /* v3.0 */ || \
	defined(__i586__ ) /* v3.0 */ || \
	defined(__i686	 ) /* v3.0 */ || \
	defined(__i686__ ) /* v3.0 */ || \
	defined(_M_IX86	 ) /* v2.7 */ || \
	defined(_X86_	 ) /* v2.6 */ || \
	defined(i386	 ) /* v2.6 */

#	define Z_COMPILER_ISA Z_ISA_X86_32

#elif	defined(__aarch64__) /* v3.3 */ || \
	defined(__arm64	   ) /* v3.5 */ || \
	defined(__arm64__  ) /* v3.5 */

#	define Z_COMPILER_ISA Z_ISA_AARCH64

#elif	defined(__ARM_ARCH) /* v3.2 */ || \
	defined(__arm	  ) /* v2.6 */ || \
	defined(__arm__	  ) /* v2.6 */ || \
	defined(__thumb__ ) /* v2.7 */ || \
	defined(_ARM_	  ) /* v3.8 */ || \
	defined(_M_ARM	  ) /* v3.5 */ || \
	defined(_M_ARM_NT ) /* v3.5 */ || \
	defined(_M_ARMT	  ) /* v3.5 */ || \
	defined(_M_THUMB  ) /* v3.5 */

#	define Z_COMPILER_ISA Z_ISA_AARCH32

#elif	defined(__HEXAGON_ARCH__) /* v3.1 */ \
	defined(__QDSP6_ARCH__	) /* v3.1 */ \
	defined(__hexagon	) /* v3.1 */ \
	defined(__hexagon__	) /* v3.1 */ \
	defined(__qdsp6		) /* v3.1 */ \
	defined(__qdsp6__	) /* v3.1 */ \
	defined(hexagon		) /* v3.1 */ \
	defined(qdsp6		) /* v3.1 */

#	define Z_COMPILER_ISA Z_ISA_HEXAGON

#elif	defined(__ADSPBLACKFIN__  ) /* v2.6 */ || \
	defined(__ADSPLPBLACKFIN__) /* v2.6 */ || \
	defined(__BFIN		  ) /* v2.6 */ || \
	defined(__BFIN__	  ) /* v2.6 */ || \
	defined(__bfin		  ) /* v2.6 */ || \
	defined(__bfin__	  ) /* v2.6 */ || \
	defined(BFIN		  ) /* v2.6 */ || \
	defined(bfin		  ) /* v2.6 */

#	define Z_COMPILER_ISA Z_ISA_BLACKFIN

#elif defined(__lanai__)
#	define Z_COMPILER_ISA Z_ISA_LANAI

#elif	defined(__mips64  )		  /* v3.2 */ || \
	defined(__mips64__)		  /* v3.2 */ || \
	(defined(__mips) && __mips == 64) /* v3.5 */ || \
	(defined(_MIPS_ISA) && defined(_MIPS_ISA_MIPS64) && _MIPS_ISA == _MIPS_ISA_MIPS64) /* v3.5 */

#	define Z_COMPILER_ISA Z_ISA_MIPS64

#elif	defined(__mips	) /* v2.7 */ || \
	defined(__mips__) /* v2.7 */ || \
	defined(_mips	) /* v2.7 */ || \
	defined(mips	) /* v2.7 */

#	define Z_COMPILER_ISA Z_ISA_MIPS

#elif	defined(__MSP430__) /* v2.6 */ || \
	defined(MSP430	  ) /* v2.6 */

#	define Z_COMPILER_ISA Z_ISA_MSP430

#elif	defined(__PPC64__    ) /* v3.4 */ || \
	defined(__powerpc64__) /* v2.7 */ || \
	defined(__ppc64__    ) /* v2.6 */ || \
	defined(_ARCH_PPC64  ) /* v2.6 */

#	define Z_COMPILER_ISA Z_ISA_POWERPC_64BIT

#elif	defined(__POWERPC__) /* v2.6 */ || \
	defined(__PPC__	   ) /* v2.8 */ || \
	defined(__powerpc__) /* v2.7 */ || \
	defined(__ppc__	   ) /* v2.6 */ || \
	defined(_ARCH_PPC  ) /* v2.6 */

#	define Z_COMPILER_ISA Z_ISA_POWERPC_32BIT

#elif defined(__riscv_xlen) /* v7.0 */

#	if __riscv_xlen == 64 /* v7.0 */
#		define Z_COMPILER_ISA Z_ISA_RV64I

#	elif __riscv_xlen == 32 /* v7.0 */
#		define Z_COMPILER_ISA Z_ISA_RV32I
#	endif

#elif	defined(__arch64__  ) /* v3.3 */ || \
	defined(__sparc_v9__) /* v3.3 */ || \
	defined(__sparc64__ ) /* v3.3 */ || \
	defined(__sparcv9   ) /* v3.3 */ || \
	defined(__sparcv9__ ) /* v3.3 */

#	define Z_COMPILER_ISA Z_ISA_SPARC_V9

#elif	defined(__sparc	   ) /* v2.6 */ || \
	defined(__sparc__  ) /* v2.6 */ || \
	defined(__sparcv8  ) /* v2.6 */ || \
	defined(__sparcv8__) /* v3.8 */ || \
	defined(sparc	   ) /* v2.6 */

#	define Z_COMPILER_ISA Z_ISA_SPARC

#elif defined(__XS1B__) /* v3.4 */
#	define Z_COMPILER_ISA Z_ISA_XCORE

#elif   defined(__s390__ ) /* v2.6 */ || \
	defined(__s390x__) /* v2.6 */ || \
	defined(__zarch__) /* v3.3 */

#	define Z_COMPILER_ISA Z_ISA_Z_ARCHITECTURE

#endif

/* MARK: - ISA: Integral endianness / Bit field order */

#ifdef __BYTE_ORDER__ /* v3.2 */

#	if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ /* v3.2 */
#		define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_ALL Z_ENDIANNESS_LITTLE
#		define Z_COMPILER_BIT_FIELD_ORDER_ALL	      Z_ORDER_REVERSED

#	elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ /* v3.2 */
#		define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_ALL Z_ENDIANNESS_BIG
#		define Z_COMPILER_BIT_FIELD_ORDER_ALL	      Z_ORDER_NORMAL
#	endif

#elif	defined(__AARCH64EL__	 ) /* v3.3 */ || \
	defined(__ARMEL__	 ) /* v2.6 */ || \
	defined(__ENDIAN_LITTLE__) /* v4.0 */ || \
	defined(__LITTLE_ENDIAN__) /* v2.6 */ || \
	defined(__MIPSEL	 ) /* v2.7 */ || \
	defined(__MIPSEL__	 ) /* v2.7 */ || \
	defined(__THUMBEL__	 ) /* v2.7 */ || \
	defined(_LITTLE_ENDIAN	 ) /* v3.4 */ || \
	defined(_MIPSEL		 ) /* v2.7 */ || \
	defined(MIPSEL		 ) /* v2.7 */

#	define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_ALL Z_ENDIANNESS_LITTLE
#	define Z_COMPILER_BIT_FIELD_ORDER_ALL	      Z_ORDER_REVERSED

#elif	defined(__AARCH_BIG_ENDIAN) /* v3.4 */ || \
	defined(__AARCH64EB__	  ) /* v3.5 */ || \
	defined(__ARM_BIG_ENDIAN  ) /* v3.3 */ || \
	defined(__ARMEB__	  ) /* v3.5 */ || \
	defined(__BIG_ENDIAN__	  ) /* v2.6 */ || \
	defined(__MIPSEB	  ) /* v2.7 */ || \
	defined(__MIPSEB__	  ) /* v2.7 */ || \
	defined(_BIG_ENDIAN	  ) /* v2.6 */ || \
	defined(_MIPSEB		  ) /* v2.7 */ || \
	defined(MIPSEB		  ) /* v2.7 */

#	define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_ALL Z_ENDIANNESS_BIG
#	define Z_COMPILER_BIT_FIELD_ORDER_ALL	      Z_ORDER_NORMAL
#endif

/*#define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_8BIT*/
/*#define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_16BIT*/
/*#define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_24BIT*/
/*#define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_32BIT*/
/*#define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_40BIT*/
/*#define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_48BIT*/
/*#define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_56BIT*/
/*#define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_64BIT*/
/*#define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_128BIT*/

/*#define Z_COMPILER_BIT_FIELD_ORDER_8BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_16BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_32BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_64BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_128BIT*/

/* MARK: - ISA: Integer format */

/*#define Z_COMPILER_ISA_INTEGER_FORMAT_ALL*/
/*#define Z_COMPILER_ISA_INTEGER_FORMAT_8BIT*/
/*#define Z_COMPILER_ISA_INTEGER_FORMAT_16BIT*/
/*#define Z_COMPILER_ISA_INTEGER_FORMAT_24BIT*/
/*#define Z_COMPILER_ISA_INTEGER_FORMAT_32BIT*/
/*#define Z_COMPILER_ISA_INTEGER_FORMAT_40BIT*/
/*#define Z_COMPILER_ISA_INTEGER_FORMAT_48BIT*/
/*#define Z_COMPILER_ISA_INTEGER_FORMAT_56BIT*/
/*#define Z_COMPILER_ISA_INTEGER_FORMAT_64BIT*/
/*#define Z_COMPILER_ISA_INTEGER_FORMAT_128BIT*/

/* MARK: - Platform / OS */

#if defined(__ANDROID__) /* v3.2 */
#	define Z_COMPILER_OS Z_OS_ANDROID

#elif	defined(__gnu_linux__) /* v2.6 */ || \
	defined(__linux	     ) /* v2.6 */ || \
	defined(__linux__    ) /* v2.6 */ || \
	defined(linux	     ) /* v2.6 */

#	define Z_COMPILER_OS Z_OS_LINUX

#elif	defined(__APPLE_CC__) /* v2.6 */ || \
	(defined(__APPLE__)   /* v2.6 */ && \
	 defined(__MACH__ ))  /* v2.6 */

#	if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) /* v2.6 */
#		define Z_COMPILER_OS Z_OS_MAC_OS_X

#	elif defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) /* v2.6 */
#		define Z_COMPILER_OS Z_OS_IOS

#	elif defined(__ENVIRONMENT_TV_OS_VERSION_MIN_REQUIRED__) /* v3.8 */
#		define Z_COMPILER_OS Z_OS_TVOS

#	elif defined(__ENVIRONMENT_WATCH_OS_VERSION_MIN_REQUIRED__) /* v3.8 */
#		define Z_COMPILER_OS Z_OS_WATCHOS
#	endif

#elif	defined(__WIN32	 ) /* v2.6 */ || \
	defined(__WIN32__) /* v2.6 */ || \
	defined(__WIN64	 ) /* v2.7 */ || \
	defined(__WIN64__) /* v2.7 */ || \
	defined(__WINNT	 ) /* v2.6 */ || \
	defined(__WINNT__) /* v2.6 */ || \
	defined(_WIN32	 ) /* v2.6 */ || \
	defined(_WIN64	 ) /* v2.7 */ || \
	defined(WIN32	 ) /* v2.6 */ || \
	defined(WIN64	 ) /* v2.7 */ || \
	defined(WINNT	 ) /* v2.6 */

#	define Z_COMPILER_OS Z_OS_WINDOWS

#elif defined(__Ananas__) /* v5.0 */
#	define Z_OS Z_OS_ANANAS_OS

#elif defined(__Bitrig__) /* v3.2 */
#	define Z_COMPILER_OS Z_OS_BITRIG

#elif defined(__CELLOS_LV2__) /* v2.7 (Revisar, puede que sólo para la PPU) */
#	define Z_COMPILER_PLATFORM Z_PLATFORM_PS3
#	define Z_COMPILER_OS	   Z_OS_CELL_OS

#elif	defined(__CYGWIN__  ) /* v2.7 */ || \
	defined(__CYGWIN32__) /* v2.7 */ || \
	defined(__CYGWIN64__) /* v3.8 */

#	define Z_COMPILER_OS Z_OS_CYGWIN

#elif defined(__DragonFly__) /* v2.6 */
#	define Z_COMPILER_OS Z_OS_DRAGONFLY_BSD

#elif	defined(__FreeBSD__	  ) /* v2.6 */ || \
	defined(__FreeBSD_kernel__) /* v3.4 */

#	define Z_COMPILER_OS Z_OS_FREE_BSD

#elif defined(__Fuchsia__) /* v4.0 */
#	define Z_COMPILER_OS Z_OS_FUCHSIA

#elif defined(__HAIKU__) /* v2.8 */
#	define Z_COMPILER_OS Z_OS_HAIKU

#elif defined(__minix) /* v2.8 */
#	define Z_COMPILER_OS Z_OS_MINIX

#elif defined(__NetBSD__) /* v2.6 */
#	define Z_COMPILER_OS Z_OS_NET_BSD

#elif defined(__OpenBSD__) /* v2.6 */
#	define Z_COMPILER_OS Z_OS_OPEN_BSD

#elif defined(__ORBIS__) /* v3.9 */
#	define Z_COMPILER_PLATFORM Z_PLATFORM_PS4
#	define Z_COMPILER_OS	   Z_OS_ORBIS_OS

#elif	defined(__psp__) /* v2.7 */ || \
	defined(_PSP   ) /* v2.7 */ || \
	defined(PSP    ) /* v2.7 */

#	define Z_COMPILER_PLATFORM Z_PLATFORM_PSP
#	define Z_COMPILER_OS	   Z_OS_PSP_SYSTEM_SOFTWARE

#elif defined(__rtems__) /* v3.0 */
#	define Z_COMPILER_OS Z_OS_RTEMS

#elif	defined(__SVR4	) /* v2.6 */ || \
	defined(__sun	) /* v2.6 */ || \
	defined(__sun__	) /* v2.6 */ || \
	defined(__svr4__) /* v2.6 */ || \
	defined(sun	) /* v2.6 */

#	define Z_COMPILER_OS Z_OS_SOLARIS

#endif

/* MARK: - Data model */

#if	defined(__LP64__) /* v2.6 */ || \
	defined(_LP64	) /* v2.6 */

#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LP64

#elif defined(__LP32__) /* v2.7 */
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LP32

#elif defined(_WIN64) /* v2.7 */
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LLP64

#elif	defined(__ILP32__) /* v3.5 */ || \
	defined(_ILP32	 ) /* v3.5 */ || \
	defined(_WIN32	 ) /* v2.6 */

#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_ILP32
#endif

/* MARK: - Language: K&R C */

#define Z_COMPILER_C_HAS_OLD_STYLE_FUNCTION	TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_OPERATOR_SIZEOF	TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_STORAGE_CLASS_AUTO	TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_STORAGE_CLASS_EXTERN	TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_STORAGE_CLASS_REGISTER TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_STORAGE_CLASS_STATIC	TRUE /* v2.6 */

#ifdef __DBL_MAX__ /* v2.6 */
#	define Z_COMPILER_C_HAS_TYPE_DOUBLE TRUE /* v2.6 */
#endif

#ifdef __FLT_MAX__ /* v2.6 */
#	define Z_COMPILER_C_HAS_TYPE_FLOAT TRUE /* v2.6 */
#endif

/* MARK: - Language: C89 */

#define Z_COMPILER_C_HAS_CONSTRUCT_AS_FUNCTION_ARGUMENT		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_CONSTRUCT_AS_RETURN_TYPE		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_CONSTRUCT_ASSIGNMENT			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_CONSTRUCT_NAMESPACE			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_ENUMERATION				TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_FUNCTION_POINTER_AUTODEREFERENCING	TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_FUNCTION_PROTOTYPE			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_INTEGRAL_SWITCH			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_LOCAL_AGGREGATE_CONSTANT_INITIALZATION TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_PREPROCESSOR_INDENTATION		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_REMOVAL_OF_ENTRY_AS_KEYWORD		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_REMOVAL_OF_LONG_FLOAT_AS_TYPE		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_STRING_LITERAL_CONCATENATION		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_TRIGRAPHS				TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_UNION_CONSTANT_INITIALIZATION		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_VALUE_PRESERVING_UNSIGNED_CONVERSION	TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_ESCAPE_SEQUENCE_ALERT			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_ESCAPE_SEQUENCE_HEXADECIMAL		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_ESCAPE_SEQUENCE_VERTICAL_TAB		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_LITERAL_UNSIGNED			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_OPERATOR_UNARY_PLUS			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_PREPROCESSOR_DIRECTIVE_NULL		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_PREPROCESSOR_DIRECTIVE_ELIF		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_PREPROCESSOR_DIRECTIVE_ERROR		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_PREPROCESSOR_DIRECTIVE_LINE		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_PREPROCESSOR_DIRECTIVE_PRAGMA		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_PREPROCESSOR_OPERATOR_DEFINED		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_PREPROCESSOR_OPERATOR_PASTING		TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_PREPROCESSOR_OPERATOR_STRINGIZING	TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_TYPE_UNSIGNED_CHAR			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_TYPE_UNSIGNED_LONG			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_TYPE_UNSIGNED_SHORT			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_TYPE_VOID				TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_TYPE_VOID_POINTER			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_TYPE_MODIFIER_SIGNED			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_CONST			TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER_VOLATILE		TRUE /* v2.6 */

#ifdef __FLT_MAX__ /* v2.6 */
#	define Z_COMPILER_C_HAS_LITERAL_FLOAT TRUE /* v2.6 */
#endif

#ifdef __LDBL_MAX__ /* v2.6 */
#	define Z_COMPILER_C_HAS_TYPE_LONG_DOUBLE    TRUE /* v2.6 */
#endif

/* MARK: - Language: C95 */

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199409L
#	define Z_COMPILER_C_HAS_DIGRAPHS TRUE /* v2.6 */
#endif

/* MARK: - Language: C99 */

#define Z_COMPILER_C_HAS_RELIABLE_INTEGER_DIVISION		  TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_REMOVAL_OF_ILL_FORMED_RETURN		  TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_REMOVAL_OF_IMPLICIT_FUNCTION_DECLARATION TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_REMOVAL_OF_IMPLICIT_INT		  TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_IDENTIFIER_FUNC			  TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_LITERAL_WCHAR_T_CHARACTER		  TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_LITERAL_WCHAR_T_STRING			  TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_STANDARD_PRAGMA_CX_LIMITED_RANGE	  TRUE /* v2.6 */
#define Z_COMPILER_C_HAS_STANDARD_PRAGMA_FP_CONTRACT		  TRUE /* v2.6 */

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#	define Z_COMPILER_C_HAS_COMPOUND_LITERAL			       TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_DESIGNATED_INITIALIZER			       TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_FLEXIBLE_ARRAY_MEMBER			       TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_STATIC_IN_ARRAY_PARAMETER_DECLARATION	       TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_TYPE_QUALIFIERS_IN_ARRAY_PARAMETER_DECLARATION TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_TYPE_QUALIFIER_RESTRICT			       TRUE /* v2.6 */

#	ifndef __STDC_NO_VLA__ /* Not found in Clang's sources. */
#		define Z_COMPILER_C_HAS_VLA TRUE /* v2.6 */
#	endif
#endif

#if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)
#	define Z_COMPILER_C_HAS_CONVERSION_OF_NON_LVALUE_ARRAY_TO_POINTER   TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_CPP_STYLE_COMMENT			    TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_FOR_WITH_DECLARATION			    TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_LOCAL_AGGREGATE_NON_CONSTANT_INITIALIZATION TRUE
#	define Z_COMPILER_C_HAS_MIXED_DECLARATIONS_AND_CODE		    TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_UNIVERSAL_CHARACTER_NAMES		    TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_SPECIFIER_INLINE			    TRUE /* v2.6 */
#endif

#if	Z_COMPILER_VERSION >= Z_VERSION(3, 3, 0) && \
	(defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L))

#	define Z_COMPILER_C_HAS_EXTENDED_IDENTIFIER TRUE /* v3.3 */
#endif

#if	(defined(__cplusplus	 ) && __cplusplus      >= 201103L) || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)

#	define Z_COMPILER_C_HAS_EMPTY_MACRO_ARGUMENT		      TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_TRAILING_COMMA_ALLOWED_IN_ENUMERATION TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_VARIADIC_MACRO			      TRUE /* v2.6 */
#	define Z_COMPILER_C_HAS_TYPE_LONG_LONG			      TRUE /* v2.6 */
#endif

/* Not sure, investigate / __UINTMAX_MAX__ was not available until v3.5 */
#if	(defined(__cplusplus	 ) && __cplusplus      >= 201103L	 ) || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L	 ) || \
	(defined(__UINTMAX_MAX__ ) && 0U - 1U	       == __UINTMAX_MAX__)

#	define Z_COMPILER_C_HAS_PREPROCESSOR_ARITHMETIC_DONE_IN_INTMAX TRUE
#endif

#if	(defined(__cplusplus	 ) && __cplusplus      >= 201703L) || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)

#	define Z_COMPILER_C_HAS_LITERAL_HEXADECIMAL_FLOATING_POINT TRUE /* v2.6 */
#endif

/*#define Z_COMPILER_C_HAS_PREPROCESSOR_OPERATOR_PRAGMA TRUE*/ /* v2.6 */

/*----------------------------------------------------.
| BUG: _Bool is always available in C but not in C++. |
| In v2.6 and v2.7 was available in C++ by mistake.   |
'----------------------------------------------------*/
#if	Z_COMPILER_VERSION == Z_VERSION(2, 6, 0) || \
	Z_COMPILER_VERSION == Z_VERSION(2, 7, 0) || \
	!defined(__cplusplus)

#	define Z_COMPILER_C_HAS_TYPE_BOOL TRUE /* v2.6 */
#endif

#ifndef __STDC_NO_COMPLEX__ /* Not found in Clang's sources. */
#	define Z_COMPILER_C_HAS_TYPE_MODIFIER_COMPLEX TRUE /* v2.6 */

#	ifdef __DBL_MAX__ /* v2.6 */
#		define Z_COMPILER_C_HAS_TYPE_DOUBLE_COMPLEX TRUE /* v2.6 */
#	endif

#	ifdef __FLT_MAX__ /* v2.6 */
#		define Z_COMPILER_C_HAS_TYPE_FLOAT_COMPLEX TRUE /* v2.6 */
#	endif

#	ifdef __LDBL_MAX__ /* v2.6 */
#		define Z_COMPILER_C_HAS_TYPE_LONG_DOUBLE_COMPLEX TRUE /* v2.6 */
#	endif
#endif

/*-----------------------------------------------------.
| IDEMPOTENT_TYPE_QUALIFIERS always generate warnings. |
'-----------------------------------------------------*/
/*#define Z_COMPILER_C_HAS_IDEMPOTENT_TYPE_QUALIFIERS*/

/*---------------------------------------.
| FENV_ACCESS ON is not implemented yet. |
'---------------------------------------*/
/*#define Z_COMPILER_C_HAS_STANDARD_PRAGMA_FENV_ACCESS*/

/*------------------------------------------------------------.
| _Imaginary is recognized as a keyword but it is not usable. |
'------------------------------------------------------------*/
/*#define Z_COMPILER_C_HAS_TYPE_DOUBLE_IMAGINARY*/
/*#define Z_COMPILER_C_HAS_TYPE_FLOAT_IMAGINARY*/
/*#define Z_COMPILER_C_HAS_TYPE_LONG_DOUBLE_IMAGINARY*/
/*#define Z_COMPILER_C_HAS_TYPE_MODIFIER_IMAGINARY*/

/* MARK: - Language: C11 */

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#	define Z_COMPILER_C_HAS_ANONYMOUS_STRUCTURE_AS_MEMBER TRUE /* v2.6? */
#endif

#if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
#	define Z_COMPILER_C_HAS_ANONYMOUS_UNION_AS_MEMBER TRUE /* v2.6? */
#	define Z_COMPILER_C_HAS_TYPEDEF_REDECLARATION	  TRUE /* v2.6 */
#endif

#if __has_feature(c_generic_selections) /* v3.0 */
#	define Z_COMPILER_C_HAS_GENERIC_SELECTION TRUE /* v3.0 */
#endif

#if __has_feature(c_static_assert) /* v3.0 */
#	define Z_COMPILER_C_HAS_STATIC_ASSERTION TRUE /* v3.0 */
#endif

#if	(Z_COMPILER_VERSION >= Z_VERSION(2, 9, 0) /* NOT SURE */ && \
	 defined(__cplusplus) && __cplusplus >= 201103L) || \
	(Z_COMPILER_VERSION >= Z_VERSION(3, 1, 0)	 && \
	 defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)

#	define Z_COMPILER_C_HAS_LITERAL_CHAR16_T_CHARACTER TRUE /* v3.3 */
#	define Z_COMPILER_C_HAS_LITERAL_CHAR16_T_STRING	   TRUE /* v3.3 */
#	define Z_COMPILER_C_HAS_LITERAL_CHAR32_T_CHARACTER TRUE /* v3.3 */
#	define Z_COMPILER_C_HAS_LITERAL_CHAR32_T_STRING	   TRUE /* v3.3 */
#	define Z_COMPILER_C_HAS_LITERAL_UTF8_STRING	   TRUE /* v3.3 */
#endif

#if __has_feature(c_alignof) /* v3.6 */
#	define Z_COMPILER_C_HAS_OPERATOR_ALIGNOF TRUE /* v3.2 */
#endif

#if Z_COMPILER_VERSION >= Z_VERSION(3, 3, 0)

	/*----------------------------------------------------------------------.
	| BUG?: Since v3.3, __has_feature(c_thread_local) returns TRUE in C11	|
	| and later, but _Thread_local always works without generating warnings |
	| in any version of C or C++.						|
	'----------------------------------------------------------------------*/
#	define Z_COMPILER_C_HAS_STORAGE_CLASS_THREAD_LOCAL TRUE /* v3.3 */

	/*------------------------------------------------------------------------.
	| BUG: Since v3.0, __has_extension(c_alignas) ALWAYS returns TRUE, and	  |
	| __has_feature(c_alignas) returns TRUE in C11 and later. Despite this,   |
	| any EXPLICIT usage of _Alignas() when declaring an identifier generates |
	| an error in C++, and the same happens in C between v3.0 and v3.2.	  |
	| However, using _Alignas() within a type definition seems to be safe.	  |
	'------------------------------------------------------------------------*/
#	if __has_feature(c_alignas) /* v3.0 */
#		define Z_COMPILER_C_HAS_SPECIFIER_ALIGNAS TRUE /* v3.3 */
#	endif

#	if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#		define Z_COMPILER_C_HAS_SPECIFIER_NORETURN TRUE /* v3.3 */
#	endif

	/*----------------------------------------------------------------.
	| BUG: Since v3.1, __has_extension(c_atomic) ALWAYS returns TRUE, |
	| but _Atomic was not supported as a type qualifier until v3.3.	  |
	'----------------------------------------------------------------*/
#	if Z__HAS_EXTENSION(c_atomic) /* v3.1 */
#		define Z_COMPILER_C_HAS_TYPE_QUALIFIER_ATOMIC TRUE /* v3.3 */
#	endif

#endif

#if Z__HAS_EXTENSION(c_atomic) /* v3.1 */
#	define Z_COMPILER_C_HAS_TYPE_MODIFIER_ATOMIC TRUE /* v3.0? */
#endif

/* MARK: - Language: Apple C extensions */

#if	Z__HAS_EXTENSION(blocks) || /* v2.6 */ \
	defined(__BLOCKS__)	    /* v2.6 */

#	define Z_COMPILER_C_HAS_BLOCK_OBJECT TRUE /* v2.6 */
#endif

#ifdef __cplusplus

	/*-----------------------------------------------------.
	| Reference:					       |
	| <https://clang.llvm.org/cxx_status.html>	       |
	| <https://en.cppreference.com/w/cpp/compiler_support> |
	'-----------------------------------------------------*/

	/* MARK: - Language: C++98 */

#	define Z_COMPILER_CPP_HAS_SFINAE       TRUE /* v2.6 */
#	define Z_COMPILER_CPP_HAS_TYPE_BOOL    TRUE /* v2.6 */
#	define Z_COMPILER_CPP_HAS_TYPE_WCHAR_T TRUE /* v2.6 */

	/* MARK: - Language: C++03 */

#	define Z_COMPILER_CPP_HAS_VALUE_INITIALIZATION TRUE /* v2.6 */

	/* MARK: - Language: C++11 */

/*#	define Z_COMPILER_CPP_HAS_C99_PREPROCESSOR*/
/*#	define Z_COMPILER_CPP_HAS_CONCURRENT_STATIC_LOCAL_VARIABLE*/
/*#	define Z_COMPILER_CPP_HAS_CONDITIONALLY_SUPPORTED_BEHAVIOR*/
/*#	define Z_COMPILER_CPP_HAS_COPY_LIST_INITIALIZATION*/
/*#	define Z_COMPILER_CPP_HAS_CPP11_RULES_ON_UNIVERSAL_CHARACTER_NAMES*/

#	if	__has_feature(cxx_nonstatic_member_init)	   /* v3.0 */ || \
		(defined(__cpp_nsdmi) && (__cpp_nsdmi >= 200809L)) /* v3.6 */

#		define Z_COMPILER_CPP_HAS_DEFAULT_MEMBER_INITIALIZER TRUE /* v3.0 */ // RN
#	endif

#	if __has_feature(cxx_default_function_template_args) /* v2.9 */
#		define Z_COMPILER_CPP_HAS_DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE TRUE /* v2.9 */
#	endif

/*#	define Z_COMPILER_CPP_HAS_DEFAULTED_FUNCTION*/

#	if	__has_feature(cxx_delegating_constructors)					     /* v3.0 */ || \
		(defined(__cpp_delegating_constructors) && __cpp_delegating_constructors >= 200604L) /* v3.6 */

#		define Z_COMPILER_CPP_HAS_DELEGATING_CONSTRUCTORS TRUE /* v3.0 */ // RN
#	endif

#	if __has_feature(cxx_deleted_functions) /* v2.7 */
#		define Z_COMPILER_CPP_HAS_DELETED_FUNCTION TRUE /* v2.6? */
#	endif

/*#	define Z_COMPILER_CPP_HAS_DIRECT_LIST_INITIALIZATION*/
/*#	define Z_COMPILER_CPP_HAS_EXPRESSION_SFINAE*/
/*#	define Z_COMPILER_CPP_HAS_EXTENDED_FRIEND_DECLARATION*/
/*#	define Z_COMPILER_CPP_HAS_EXTERN_TEMPLATE*/

#	if	__has_feature(cxx_inheriting_constructors)					     /* v3.3 */ || \
		(defined(__cpp_inheriting_constructors) && __cpp_inheriting_constructors >= 200802L) /* v3.6 */

#		define Z_COMPILER_CPP_HAS_INHERITING_CONSTRUCTORS TRUE /* v3.3 */ // RN
#	endif

/*#	define Z_COMPILER_CPP_HAS_INITIALIZATION_OF_CLASS_OBJECT_BY_RVALUE*/
/*#	define Z_COMPILER_CPP_HAS_INITIALIZER_LIST*/

#	if	__has_feature(cxx_lambdas)			     /* v3.1 */ || \
		(defined(__cpp_lambdas) && __cpp_lambdas >= 200907L) /* v3.4 */

#		define Z_COMPILER_CPP_HAS_LAMBDA TRUE /* v3.1 */ // RN
#	endif

/*#	define Z_COMPILER_CPP_HAS_LOCAL_TYPE_AS_TEMPLATE_ARGUMENT*/
/*#	define Z_COMPILER_CPP_HAS_MOVE_SPECIAL_MEMBER_FUNCTIONS*/
/*#	define Z_COMPILER_CPP_HAS_MULTI_DECLARATOR_AUTO*/
/*#	define Z_COMPILER_CPP_HAS_OPAQUE_ENUMERATION_DECLARATION*/

#	if	__has_feature(cxx_range_for)					     /* v3.0 */ || \
		(defined(__cpp_range_based_for) && __cpp_range_based_for >= 200907L) /* v3.6 */

#		define Z_COMPILER_CPP_HAS_RANGE_BASED_FOR TRUE /* v3.0 */ // RN
#	endif

#	if	__has_feature(cxx_reference_qualified_functions)		 /* v2.9 */ || \
		defined(__cpp_ref_qualifiers) && __cpp_ref_qualifiers >= 200710L /* v3.6 */

#		define Z_COMPILER_CPP_HAS_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION TRUE /* v2.9 */
#	endif

/*#	define Z_COMPILER_CPP_HAS_REMOVAL_OF_AUTO_AS_STORAGE_CLASS*/
/*#	define Z_COMPILER_CPP_HAS_RIGHT_ANGLE_BRACKETS*/
/*#	define Z_COMPILER_CPP_HAS_RVALUE_REFERENCE*/
/*#	define Z_COMPILER_CPP_HAS_STANDARD_LAYOUT*/
/*#	define Z_COMPILER_CPP_HAS_STANDARDIZED_ATTRIBUTE_SYNTAX*/

#	if	__has_feature(cxx_static_assert)				 /* v2.7 */ || \
		(defined(__cpp_static_assert) && __cpp_static_assert >= 200410L) /* v3.4 */

#		define Z_COMPILER_CPP_HAS_STATIC_ASSERTION TRUE /* v2.6? */
#	endif

#	if __has_feature(cxx_strong_enums) /* v2.9 */
#		define Z_COMPILER_CPP_HAS_STRONGLY_TYPED_ENUMERATION TRUE /* v2.9 */
#	endif

#	if	__has_feature(cxx_alias_templates)				     /* v3.0 */ || \
		(defined(__cpp_alias_templates) && __cpp_alias_templates >= 200704L) /* v3.6 */

#		define Z_COMPILER_CPP_HAS_TEMPLATE_ALIAS TRUE /* v3.0 */ // RN
#	endif

#	if __has_feature(cxx_trailing_return) /* v2.9 */
#		define Z_COMPILER_CPP_HAS_TRAILING_RETURN_TYPE TRUE /* v2.9 */
#	endif

/*#	define Z_COMPILER_CPP_HAS_UNNAMED_TYPE_AS_TEMPLATE_ARGUMENT*/

#	if __has_feature(cxx_unrestricted_unions) /* v3.1 */
#		define Z_COMPILER_CPP_HAS_UNRESTRICTED_UNION TRUE /* v3.1 */ // RN
#	endif

/*#	define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE*/
/*#	define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE_EXTENDED_PARAMETERS*/
/*#	define Z_COMPILER_CPP_HAS_ATTRIBUTE_CARRIES_DEPENDENCY*/
/*#	define Z_COMPILER_CPP_HAS_ATTRIBUTE_NORETURN*/
/*#	define Z_COMPILER_CPP_HAS_IDENTIFIER_FUNC*/
/*#	define Z_COMPILER_CPP_HAS_LITERAL_CHAR16_T_CHARACTER*/
/*#	define Z_COMPILER_CPP_HAS_LITERAL_CHAR16_T_STRING*/
/*#	define Z_COMPILER_CPP_HAS_LITERAL_CHAR32_T_CHARACTER*/
/*#	define Z_COMPILER_CPP_HAS_LITERAL_CHAR32_T_STRING*/

#	if __has_feature(cxx_nullptr) /* v3.0 */
#		define Z_COMPILER_CPP_HAS_LITERAL_NULLPTR TRUE /* v3.0 (v2.6?) */ // RN
#	endif

/*#	define Z_COMPILER_CPP_HAS_LITERAL_RAW_STRING*/

#	if	__has_feature(cxx_user_literals)						 /* v3.1 */ || \
		(defined(__cpp_user_defined_literals) && __cpp_user_defined_literals >= 200809L) /* v3.4 */

#		define Z_COMPILER_CPP_HAS_LITERAL_USER_DEFINED TRUE /* v3.1 (v3.0?) */ // RN
#	endif

/*#	define Z_COMPILER_CPP_HAS_LITERAL_UTF8_STRING*/
/*#	define Z_COMPILER_CPP_HAS_OPERATOR_ALIGNOF*/

#	if __has_feature(cxx_noexcept)
#		define Z_COMPILER_CPP_HAS_OPERATOR_NOEXCEPT TRUE /* v3.0 */ // RN
#	endif

/*#	define Z_COMPILER_CPP_HAS_OPERATOR_CASE_SIZEOF_NON_STATIC_DATA_MEMBER*/
/*#	define Z_COMPILER_CPP_HAS_OPERATOR_CASE_SIZEOF_PARAMETER_PACK*/

#	if __has_feature(cxx_alignas)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_ALIGNAS TRUE /* v3.3 */ // RN
#	endif

#	if __has_feature(cxx_constexpr)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_CONSTEXPR TRUE /* v3.1 */ // RN
#	endif

#	if __has_feature(cxx_decltype)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_DECLTYPE TRUE /* v2.9 (v2.6?) */
#	endif

/*#	define Z_COMPILER_CPP_HAS_SPECIFIER_FINAL*/

#	if __has_feature(cxx_noexcept)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_NOEXCEPT TRUE /* v3.0 */ // RN
#	endif

/*#	define Z_COMPILER_CPP_HAS_SPECIFIER_OVERRIDE*/

#	if __has_feature(cxx_decltype_incomplete_return_types)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_CASE_DECLTYPE_INCOMPLETE_RETURN TRUE /* v3.1 */
#	endif

#	if __has_feature(cxx_explicit_conversions)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_CASE_EXPLICIT_CONVERSION_FUNCTION TRUE /* v3.0 */
#	endif

#	if __has_feature(cxx_inline_namespaces)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_CASE_INLINE_NAMESPACE TRUE /* v2.9 */
#	endif

	/*-----------------------------------------------.
	| IMPORTANT: STORAGE_CLASS_THREAD_LOCAL requires |
	| a C++ runtime providing __cxa_thread_atexit.	 |
	'-----------------------------------------------*/
#	if __has_feature(cxx_thread_local)
#		define Z_COMPILER_CPP_HAS_STORAGE_CLASS_THREAD_LOCAL TRUE /* v3.3 */ // RN
#	endif

/*#	define Z_COMPILER_CPP_HAS_TYPE_AUTO*/
/*#	define Z_COMPILER_CPP_HAS_TYPE_CHAR16_T*/
/*#	define Z_COMPILER_CPP_HAS_TYPE_CHAR32_T*/
/*#	define Z_COMPILER_CPP_HAS_TYPE_LONG_LONG*/














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
//#		define Z_COMPILER_CPP_HAS_LITERAL_CHAR16_T_CHARACTER		   TRUE /* v2.9 */
//#		define Z_COMPILER_CPP_HAS_LITERAL_CHAR16_T_STRING		   TRUE /* v2.9 (v2.6?) */
//#		define Z_COMPILER_CPP_HAS_LITERAL_CHAR32_T_CHARACTER		   TRUE /* v2.9 (v2.6?) */
//#		define Z_COMPILER_CPP_HAS_LITERAL_CHAR32_T_STRING		   TRUE /* v2.9 */
//#		define Z_COMPILER_CPP_HAS_TYPE_CHAR16_T				   TRUE /* v2.9 (v2.6?) */
//#		define Z_COMPILER_CPP_HAS_TYPE_CHAR32_T				   TRUE /* v2.9 (v2.6?) */
#		define Z_COMPILER_CPP_HAS_TYPE_LONG_LONG			   TRUE /* v2.9 */

#		if Z_COMPILER_VERSION >= Z_VERSION(3, 0, 0)
#			define Z_COMPILER_CPP_HAS_STANDARD_LAYOUT TRUE /* v3.0 */

#			if Z_COMPILER_VERSION >= Z_VERSION(3, 1, 0)
#				define Z_COMPILER_CPP_HAS_OPAQUE_ENUMERATION_DECLARATION	      TRUE /* v3.1 */
#				define Z_COMPILER_CPP_HAS_OPERATOR_CASE_SIZEOF_NON_STATIC_DATA_MEMBER TRUE /* v3.1 */
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
#		define Z_COMPILER_CPP_HAS_ATTRIBUTE_NORETURN		TRUE /* v3.3 */
#	endif

#	if __has_feature(cxx_variadic_templates)
#		define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE			TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_VARIADIC_TEMPLATE_EXTENDED_PARAMETERS TRUE /* v2.9 */
#		define Z_COMPILER_CPP_HAS_OPERATOR_CASE_SIZEOF_PARAMETER_PACK	TRUE /* v2.9 */
#	endif

#	if	__has_feature(cxx_defaulted_functions)	    || \
		(__cplusplus >= 201103L			    && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 0, 0)   && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 1, 0))

#		define Z_COMPILER_CPP_HAS_DEFAULTED_FUNCTION TRUE /* v3.0 */
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

#	if	__has_feature(cxx_alignof)		  || \
		(__cplusplus >= 201103L			  && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 3, 0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 6, 0))

#		define Z_COMPILER_CPP_HAS_OPERATOR_ALIGNOF TRUE /* v3.3 */
#	endif

#	if __has_feature(cxx_override_control)
#		define Z_COMPILER_CPP_HAS_SPECIFIER_FINAL    TRUE /* v3.0 */
#		define Z_COMPILER_CPP_HAS_SPECIFIER_OVERRIDE TRUE /* v3.0 */
#	endif

















	/* MARK: - Language: C++14 */

/*#	define Z_COMPILER_CPP_HAS_APOSTROPHE_AS_DIGIT_SEPARATOR*/
/*#	define Z_COMPILER_CPP_HAS_CPP14_RULES_ON_CONSTEXPR_FUNCTION*/
/*#	define Z_COMPILER_CPP_HAS_CPP14_RULES_ON_CONTEXTUAL_CONVERSION*/
/*#	define Z_COMPILER_CPP_HAS_DEFAULT_MEMBER_INITIALIZER_FOR_AGGREGATE*/
/*#	define Z_COMPILER_CPP_HAS_GENERIC_LAMBDA*/
/*#	define Z_COMPILER_CPP_HAS_INITIALIZED_LAMBDA_CAPTURE*/
/*#	define Z_COMPILER_CPP_HAS_RETURN_TYPE_DEDUCTION_FOR_NORMAL_FUNCTION*/
/*#	define Z_COMPILER_CPP_HAS_SIZED_DEALLOCATION*/
/*#	define Z_COMPILER_CPP_HAS_VARIABLE_TEMPLATE*/
/*#	define Z_COMPILER_CPP_HAS_ATTRIBUTE_DEPRECATED*/
/*#	define Z_COMPILER_CPP_HAS_LITERAL_BINARY_INTEGRAL*/
/*#	define Z_COMPILER_CPP_HAS_SPECIFIER_CASE_DECLTYPE_AUTO*/

#	if	defined(__cpp_digit_separators)		  || \
		(__cplusplus >= 201402L			  && \
		 Z_COMPILER_VERSION >= Z_VERSION(3, 4, 0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3, 6, 0))

#		define Z_COMPILER_CPP_HAS_APOSTROPHE_AS_DIGIT_SEPARATOR TRUE /* v3.4 */
#	endif

#	if __has_feature(cxx_relaxed_constexpr)
#		define Z_COMPILER_CPP_HAS_CPP14_RULES_ON_CONSTEXPR_FUNCTION TRUE /* v3.4 */
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

	/*---------------------------------------------------------------------.
	| IMPORTANT: In v3.7 and later, SIZED_DEALLOCATION is only enabled if  |
	| the user passes the -fsized-deallocation flag. The user must supply  |
	| definitions of the sized deallocation functions, either by providing |
	| them explicitly or by using a C++ standard library that does.	       |
	'---------------------------------------------------------------------*/
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

#		define Z_COMPILER_CPP_HAS_SPECIFIER_CASE_DECLTYPE_AUTO TRUE /* v3.3 */
#	endif

	/* MARK: - Language: C++17 */

/*#	define Z_COMPILER_CPP_HAS_AGGREGATE_INITIALIZATION_FOR_DERIVED_CLASS*/
/*#	define Z_COMPILER_CPP_HAS_ATTRIBUTES_FOR_ENUMERATION*/
/*#	define Z_COMPILER_CPP_HAS_ATTRIBUTES_FOR_NAMESPACE*/
/*#	define Z_COMPILER_CPP_HAS_ATTRIBUTE_USING_PREFIX*/
/*#	define Z_COMPILER_CPP_HAS_CPP17_RULES_ON_AUTO_AND_BRACED_INITIALIZATION*/
/*#	define Z_COMPILER_CPP_HAS_CPP17_RULES_ON_EXPRESSION_EVALUATION_ORDER*/
/*#	define Z_COMPILER_CPP_HAS_CPP17_RULES_ON_INHERITING_CONSTRUCTORS*/
/*#	define Z_COMPILER_CPP_HAS_CPP17_RULES_ON_NON_TYPE_TEMPLATE_ARGUMENTS*/
/*#	define Z_COMPILER_CPP_HAS_CPP17_RULES_ON_TEMPLATE_TEMPLATE_ARGUMENT_MATCHING*/
/*#	define Z_COMPILER_CPP_HAS_DIFFERING_BEGIN_AND_END_TYPES_IN_RANGE_BASED_FOR*/
/*#	define Z_COMPILER_CPP_HAS_DIRECT_LIST_INITIALIZATION_FOR_ENUMERATION*/
/*#	define Z_COMPILER_CPP_HAS_NOEXCEPT_AS_PART_OF_THE_TYPE*/
/*#	define Z_COMPILER_CPP_HAS_FOLD_EXPRESSION*/
/*#	define Z_COMPILER_CPP_HAS_FOLD_EXPRESSION_SAFETY_WITH_EMPTY_PARAMETER_PACK*/
/*#	define Z_COMPILER_CPP_HAS_GUARANTEED_COPY_ELISION*/
/*#	define Z_COMPILER_CPP_HAS_IF_WITH_INITIALIZER*/
/*#	define Z_COMPILER_CPP_HAS_IGNORATION_OF_UNKNOWN_ATTRIBUTES*/
/*#	define Z_COMPILER_CPP_HAS_LAMBDA_CAPTURE_OF_THIS_OBJECT_BY_VALUE*/
/*#	define Z_COMPILER_CPP_HAS_LAUNDER*/
/*#	define Z_COMPILER_CPP_HAS_NESTED_NAMESPACE_DEFINITION*/
/*#	define Z_COMPILER_CPP_HAS_NON_TYPE_TEMPLATE_PARAMETER_WITH_AUTO_TYPE*/
/*#	define Z_COMPILER_CPP_HAS_OVER_ALIGNED_DYNAMIC_ALLOCATION*/
/*#	define Z_COMPILER_CPP_HAS_REMOVAL_OF_DYNAMIC_EXCEPTION_SPECIFICATION*/
/*#	define Z_COMPILER_CPP_HAS_REMOVAL_OF_INCREMENT_OPERATOR_WITH_BOOL_OPERAND*/
/*#	define Z_COMPILER_CPP_HAS_REMOVAL_OF_REGISTER_AS_STORAGE_CLASS*/
/*#	define Z_COMPILER_CPP_HAS_REMOVAL_OF_TRIGRAPHS*/
/*#	define Z_COMPILER_CPP_HAS_STATIC_ASSERTION_WITH_NO_MESSAGE*/
/*#	define Z_COMPILER_CPP_HAS_STRUCTURED_BINDING*/
/*#	define Z_COMPILER_CPP_HAS_SWITCH_WITH_INITIALIZER*/
/*#	define Z_COMPILER_CPP_HAS_TEMPLATE_ARGUMENT_DEDUCTION_FOR_CLASS_TEMPLATE*/
/*#	define Z_COMPILER_CPP_HAS_TYPENAME_IN_TEMPLATE_TEMPLATE_PARAMETER*/
/*#	define Z_COMPILER_CPP_HAS_VARIADIC_USING*/
/*#	define Z_COMPILER_CPP_HAS_ATTRIBUTE_FALLTHROUGH*/
/*#	define Z_COMPILER_CPP_HAS_ATTRIBUTE_MAYBE_UNUSED*/
/*#	define Z_COMPILER_CPP_HAS_ATTRIBUTE_NODISCARD*/
/*#	define Z_COMPILER_CPP_HAS_LITERAL_HEXADECIMAL_FLOATING_POINT*/
/*#	define Z_COMPILER_CPP_HAS_LITERAL_UTF8_CHARACTER*/
/*#	define Z_COMPILER_CPP_HAS_PREPROCESSOR_OPERATOR_HAS_INCLUDE*/
/*#	define Z_COMPILER_CPP_HAS_SPECIFIER_CASE_CONSTEXPR_IF*/
/*#	define Z_COMPILER_CPP_HAS_SPECIFIER_CASE_CONSTEXPR_LAMBDA*/
/*#	define Z_COMPILER_CPP_HAS_SPECIFIER_CASE_INLINE_VARIABLE*/

#if	__cplusplus >= 201703L
#		define Z_COMPILER_CPP_HAS_LITERAL_HEXADECIMAL_FLOATING_POINT TRUE /* All versions? */
#	endif

	/*#define Z_COMPILER_CPP_HAS_LITERAL_UTF8_CHARACTER*/

#	define Z_COMPILER_CPP_HAS_PREPROCESSOR_OPERATOR_HAS_INCLUDE TRUE /* All versions? (NO) */

#endif

/* MARK: - Language: Attributes */

#if __has_attribute(alias)
#	define Z_COMPILER_ATTRIBUTE_ALIAS(name) __attribute__((alias(name))) /* v2.6 */
#endif

#if __has_attribute(dllimport)
#	define Z_COMPILER_ATTRIBUTE_API __declspec(dllimport) /* v2.6 */
#endif

#if __has_attribute(dllexport)
#	define Z_COMPILER_ATTRIBUTE_API_EXPORT __declspec(dllexport) /* v2.6 */
#endif

/*#define Z_COMPILER_ATTRIBUTE_API_ALIAS*/
/*#define Z_COMPILER_ATTRIBUTE_API_EXPORT_ALIAS*/
/*#define Z_COMPILER_ATTRIBUTE_API_WEAK_EXPORT*/
/*#define Z_COMPILER_ATTRIBUTE_EBCO*/

#if __has_attribute(always_inline)
#	define Z_COMPILER_ATTRIBUTE_INLINE __inline__ __attribute__((always_inline)) /* v2.6 */
#else
#	define Z_COMPILER_ATTRIBUTE_INLINE __inline__ /* v2.6 */
#endif

#if __has_attribute(noreturn)
#	define Z_COMPILER_ATTRIBUTE_NO_RETURN __attribute__((noreturn)) /* v2.6 */
#endif

#if __has_attribute(sentinel)
#	define Z_COMPILER_ATTRIBUTE_NULL_TERMINATED __attribute__((sentinel)) /* v2.6 */
#endif

#if __has_attribute(visibility)
#	define Z_COMPILER_ATTRIBUTE_PRIVATE __attribute__((visibility("hidden")))  /* v2.6 */
#	define Z_COMPILER_ATTRIBUTE_PUBLIC  __attribute__((visibility("default"))) /* v2.6 */
#endif

#if __has_extension(tls)
#	define Z_COMPILER_ATTRIBUTE_THREAD_LOCAL __thread /* v2.6 */
#endif

#if __has_attribute(weak)
#	define Z_COMPILER_ATTRIBUTE_WEAK __attribute__((weak)) /* v2.6 */
#endif

/* MARK: - Language: Padding modifiers */

#if __has_attribute(packed)							 /* v2.6 */
#	define Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_TYPE	    __attribute__((packed))
#	define Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_TYPE	    __attribute__((packed))
#	define Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_TYPE	    __attribute__((packed))
#	define Z_COMPILER_PACKED_NAMED_UNION_BEFORE_TYPE	    __attribute__((packed))
#	define Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_IDENTIFIER __attribute__((packed))
#	define Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_IDENTIFIER    __attribute__((packed))
#endif

/*#define Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_TYPEDEF*/
/*#define Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_STRUCT*/
/*#define Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_BODY*/
/*#define Z_COMPILER_DEFINE_PACKED_STRUCTURE_AFTER_TYPE*/
/*#define Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_TYPEDEF*/
/*#define Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_UNION*/
/*#define Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_BODY*/
/*#define Z_COMPILER_DEFINE_PACKED_UNION_AFTER_TYPE*/
/*#define Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_STRUCT*/
/*#define Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_BODY*/
/*#define Z_COMPILER_PACKED_NAMED_STRUCTURE_AFTER_BODY*/
/*#define Z_COMPILER_PACKED_NAMED_UNION_BEFORE_UNION*/
/*#define Z_COMPILER_PACKED_NAMED_UNION_BEFORE_BODY*/
/*#define Z_COMPILER_PACKED_NAMED_UNION_AFTER_BODY*/
/*#define Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_STRUCT*/
/*#define Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_BODY*/
/*#define Z_COMPILER_PACKED_UNNAMED_STRUTURE_AFTER_IDENTIFIER*/
/*#define Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_STRUCT*/
/*#define Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_BODY*/
/*#define Z_COMPILER_PACKED_UNNAMED_UNION_AFTER_IDENTIFIER*/

/* MARK: - Built-in constants */

#ifdef __CHAR_BIT__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_CHAR_BITS __CHAR_BIT__
#endif

#ifdef __SCHAR_MAX__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_SCHAR_MAXIMUM __SCHAR_MAX__
#endif

#if defined(__SIZEOF_SHORT__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_SHORT_SIZE __SIZEOF_SHORT__
#elif defined(_EM_SSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_SHORT_SIZE _EM_SSIZE
#endif

#ifdef __SHRT_MAX__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_SSHORT_MAXIMUM __SHRT_MAX__
#endif

#ifdef _MIPS_SZINT /* v3.1 */
#	define Z_COMPILER_CONSTANT_INT_BITS _MIPS_SZINT
#endif

#if defined(__SIZEOF_INT__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_INT_SIZE __SIZEOF_INT__

#elif defined(_EM_WSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_INT_SIZE _EM_WSIZE
#endif

#ifdef __INT_MAX__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_SINT_MAXIMUM __INT_MAX__
#endif

#ifdef _MIPS_SZLONG /* v3.1 */
#	define Z_COMPILER_CONSTANT_LONG_BITS _MIPS_SZLONG
#endif

#if defined(__SIZEOF_LONG__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_LONG_SIZE __SIZEOF_LONG__
#elif defined(_EM_LSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_LONG_SIZE _EM_LSIZE
#endif

#ifdef __LONG_MAX__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_SLONG_MAXIMUM __LONG_MAX__
#endif

#ifdef __SIZEOF_LONG_LONG__ /* v2.8 */
#	define Z_COMPILER_CONSTANT_LLONG_SIZE __SIZEOF_LONG_LONG__
#endif

#ifdef __LONG_LONG_MAX__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_SLLONG_MAXIMUM __LONG_LONG_MAX__
#endif

#if defined(__SIZEOF_FLOAT__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_FLOAT_SIZE __SIZEOF_FLOAT__

#elif defined(_EM_FSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_FLOAT_SIZE _EM_FSIZE
#endif

#if __has_builtin(__builtin_huge_valf)
#	define Z_COMPILER_CONSTANT_FLOAT_INFINITY __builtin_huge_valf() /* v2.6 */
#elif __has_builtin(__builtin_inff)
#	define Z_COMPILER_CONSTANT_FLOAT_INFINITY __builtin_inff() /* v2.6 */
#endif

#if __has_builtin(__builtin_nanf)
#	define Z_COMPILER_CONSTANT_FLOAT_NAN __builtin_nanf("") /* v2.6 */
#endif

#if defined(__SIZEOF_DOUBLE__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_DOUBLE_SIZE __SIZEOF_DOUBLE__

#elif defined(_EM_DSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_DOUBLE_SIZE _EM_DSIZE
#endif

#if __has_builtin(__builtin_huge_val)
#	define Z_COMPILER_CONSTANT_DOUBLE_INFINITY __builtin_huge_val() /* v2.6 */

#elif __has_builtin(__builtin_inf)
#	define Z_COMPILER_CONSTANT_DOUBLE_INFINITY __builtin_inf() /* v2.6 */
#endif

#if __has_builtin(__builtin_nan)
#	define Z_COMPILER_CONSTANT_DOUBLE_NAN __builtin_nan("") /* v2.6 */
#endif

#ifdef __SIZEOF_LONG_DOUBLE__ /* v2.8 */
#	define Z_COMPILER_CONSTANT_LDOUBLE_SIZE __SIZEOF_LONG_DOUBLE__
#endif

#if __has_builtin(__builtin_huge_vall)
#	define Z_COMPILER_CONSTANT_LDOUBLE_INFINITY __builtin_huge_vall() /* v2.6 */

#elif __has_builtin(__builtin_infl)
#	define Z_COMPILER_CONSTANT_LDOUBLE_INFINITY __builtin_infl() /* v2.6 */
#endif

#if __has_builtin(__builtin_nanl)
#	define Z_COMPILER_CONSTANT_LDOUBLE_NAN __builtin_nanl("") /* v2.6 */
#endif

#ifdef __WCHAR_WIDTH__  /* v2.7 */
#	define Z_COMPILER_CONSTANT_WCHAR_BITS __WCHAR_WIDTH__
#endif

#ifdef __SIZEOF_WCHAR_T__ /* v2.8 */
#	define Z_COMPILER_CONSTANT_WCHAR_SIZE __SIZEOF_WCHAR_T__
#endif

#ifdef __WCHAR_MAX__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_WCHAR_MAXIMUM __WCHAR_MAX__
#endif

#ifdef __SIZE_WIDTH__ /* v2.7 */
#	define Z_COMPILER_CONSTANT_SIZE_BITS __SIZE_WIDTH__
#endif

#ifdef __SIZEOF_SIZE_T__ /* v2.8 */
#	define Z_COMPILER_CONSTANT_SIZE_SIZE __SIZEOF_SIZE_T__
#endif

#ifdef __SIZE_MAX__ /* v3.3 */
#	define Z_COMPILER_CONSTANT_USIZE_MAXIMUM __SIZE_MAX__
#endif

#ifdef __UINTMAX_WIDTH__ /* v3.5 */
#	define Z_COMPILER_CONSTANT_UINTMAX_BITS __UINTMAX_WIDTH__
#endif

#ifdef __UINTMAX_MAX__ /* v3.5 */
#	define Z_COMPILER_CONSTANT_UINTMAX_MAXIMUM __UINTMAX_MAX__
#endif

#ifdef __INTMAX_WIDTH__ /* v2.7 */
#	define Z_COMPILER_CONSTANT_SINTMAX_BITS __INTMAX_WIDTH__
#endif

#ifdef __INTMAX_MAX__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_SINTMAX_MAXIMUM __INTMAX_MAX__
#endif

#if defined(__POINTER_WIDTH__) /* v2.6 */
#	define Z_COMPILER_CONSTANT_INTPTR_BITS	__POINTER_WIDTH__
#	define Z_COMPILER_CONSTANT_POINTER_BITS __POINTER_WIDTH__

#elif defined(__UINTPTR_WIDTH__) /* v3.5 */
#	define Z_COMPILER_CONSTANT_INTPTR_BITS	__UINTPTR_WIDTH__
#	define Z_COMPILER_CONSTANT_POINTER_BITS __UINTPTR_WIDTH__

#elif defined(__INTPTR_WIDTH__) /* v2.7 */
#	define Z_COMPILER_CONSTANT_INTPTR_BITS	__INTPTR_WIDTH__
#	define Z_COMPILER_CONSTANT_POINTER_BITS __INTPTR_WIDTH__

#elif defined(_MIPS_SZPTR) /* v3.1 */
#	define Z_COMPILER_CONSTANT_INTPTR_BITS	_MIPS_SZPTR
#	define Z_COMPILER_CONSTANT_POINTER_BITS _MIPS_SZPTR
#endif

#if defined(__SIZEOF_POINTER__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_INTPTR_SIZE	__SIZEOF_POINTER__
#	define Z_COMPILER_CONSTANT_POINTER_SIZE __SIZEOF_POINTER__

#elif defined(_EM_PSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_INTPTR_SIZE	_EM_PSIZE
#	define Z_COMPILER_CONSTANT_POINTER_SIZE _EM_PSIZE
#endif

#ifdef __UINTPTR_MAX__ /* v3.5 */
#	define Z_COMPILER_CONSTANT_UINTPTR_MAXIMUM __UINTPTR_MAX__
#endif

#ifdef __INTPTR_MAX__ /* v3.5 */
#	define Z_COMPILER_CONSTANT_SINTPTR_MAXIMUM __INTPTR_MAX__
#endif

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
/*#define Z_COMPILER_CONSTANT_UCHAR_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SCHAR_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_SHORT_BITS*/
/*#define Z_COMPILER_CONSTANT_USHORT_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SSHORT_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_UINT_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SINT_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_ULONG_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SLONG_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_LLONG_BITS*/
/*#define Z_COMPILER_CONSTANT_ULLONG_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SLLONG_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_FLOAT_BITS*/
/*#define Z_COMPILER_CONSTANT_DOUBLE_BITS*/
/*#define Z_COMPILER_CONSTANT_SSIZE_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_SSIZE_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_UINTMAX_SIZE*/
/*#define Z_COMPILER_CONSTANT_SINTMAX_SIZE*/
/*#define Z_COMPILER_CONSTANT_SINTMAX_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_SINTPTR_MINIMUM*/

/* MARK: - Built-in magic constants */

#define Z_COMPILER_MAGIC_CONSTANT_MANGLED_FUNCTION_NAME __PRETTY_FUNCTION__ /* v2.6 */

/* MARK: - Built-in macros: Struture */

#pragma clang diagnostic ignored "-Wextended-offsetof"
#define Z_COMPILER_MACRO_OFFSET_OF __builtin_offsetof /* v2.6 */

/* MARK: - Built-in macros: VAL
.-----------------------------------------------------------------.
| Please, read the comments for this section in the GCC's header. |
'----------------------------------------------------------------*/

#define Z_COMPILER_MACRO_VAL_INITIALIZE __builtin_va_start /* v2.6 */
#define Z_COMPILER_MACRO_VAL_FINALIZE   __builtin_va_end   /* v2.6 */
#define Z_COMPILER_MACRO_VAL_READ	__builtin_va_arg   /* v2.6 */

#if __has_builtin(__builtin_va_copy)
#	define Z_COMPILER_MACRO_VAL_COPY(object, output) __builtin_va_copy(output, object) /* v2.6 */
#endif

/* MARK: - Built-in types */

#ifdef __INT8_TYPE__ /* v2.6 */
#	define Z_COMPILER_TYPE_UINT8 unsigned __INT8_TYPE__
#	define Z_COMPILER_TYPE_SINT8   signed __INT8_TYPE__
#endif

#ifdef __INT16_TYPE__ /* v2.6 */
#	define Z_COMPILER_TYPE_UINT16 unsigned __INT16_TYPE__
#	define Z_COMPILER_TYPE_SINT16	signed __INT16_TYPE__
#endif

#ifdef __INT32_TYPE__ /* v2.6 */
#	define Z_COMPILER_TYPE_UINT32 unsigned __INT32_TYPE__
#	define Z_COMPILER_TYPE_SINT32	signed __INT32_TYPE__
#endif

#ifdef __INT64_TYPE__ /* v2.6 */
#	define Z_COMPILER_TYPE_UINT64 unsigned __INT64_TYPE__
#	define Z_COMPILER_TYPE_SINT64	signed __INT64_TYPE__
#endif

#ifdef __SIZEOF_INT128__ /* v3.3 */
#	define Z_COMPILER_TYPE_UINT128 __uint128_t /* v2.6 */
#	define Z_COMPILER_TYPE_SINT128 __int128_t  /* v2.6 */
#endif

#ifdef __FLOAT128__ /* v3.9 */
#	define Z_COMPILER_TYPE_FLOAT128 __float128 /* v3.9 */
#endif

#define Z_COMPILER_TYPE_VAL __builtin_va_list /* v2.6 */

/*#define Z_COMPILER_TYPE_UINT8*/
/*#define Z_COMPILER_TYPE_SINT8*/
/*#define Z_COMPILER_TYPE_UINT16*/
/*#define Z_COMPILER_TYPE_SINT16*/
/*#define Z_COMPILER_TYPE_UINT32*/
/*#define Z_COMPILER_TYPE_SINT32*/
/*#define Z_COMPILER_TYPE_UINT64*/
/*#define Z_COMPILER_TYPE_SINT64*/
/*#define Z_COMPILER_TYPE_UINT128*/
/*#define Z_COMPILER_TYPE_SINT128*/


#ifdef __ARM_FP16_FORMAT_IEEE
/*#define Z_COMPILER_TYPE_FLOAT16*/
#endif





/*#define Z_COMPILER_TYPE_FLOAT32*/
/*#define Z_COMPILER_TYPE_FLOAT64*/
/*#define Z_COMPILER_TYPE_FLOAT128*/
/*#define Z_COMPILER_TYPE_FLOAT80_X87*/
/*#define Z_COMPILER_TYPE_FLOAT96_X87*/
/*#define Z_COMPILER_TYPE_FLOAT128_X87*/
/*#define Z_COMPILER_TYPE_VAL*/

/* MARK: - Suffix macros for built-in types */

/*#define Z_COMPILER_LITERAL_UINT8*/
/*#define Z_COMPILER_LITERAL_SINT8*/
/*#define Z_COMPILER_LITERAL_UINT16*/
/*#define Z_COMPILER_LITERAL_SINT16*/
/*#define Z_COMPILER_LITERAL_UINT32*/
/*#define Z_COMPILER_LITERAL_SINT32*/
/*#define Z_COMPILER_LITERAL_UINT64*/
/*#define Z_COMPILER_LITERAL_SINT64*/
/*#define Z_COMPILER_LITERAL_UINT128*/
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
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add	     /* v2.6 */
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_ADD		    __sync_fetch_and_add	     /* v2.6 */
#		define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1) /* v2.6 */
#		define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_INCREMENT(pointer) __sync_fetch_and_add(pointer, 1) /* v2.6 */
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

/*__is_destructible (not correctly implemented? not available?) */ /* v3.5 (partially implemented), v3.8 (fully implemented) */
/*__is_sealed*/ /* v3.4 */
/*__is_trivially_destructible*/ /* v5.0 */
/*__is_nothrow_destructible (not correctly implemented? not available?) */ /* v3.5 (partially implemented), v3.8 (fully implemented) */
/*__has_nothrow_move_assign*/ /* v3.3 */
/*__has_trivial_move_assign*/ /* v3.3 */
/*__has_trivial_move_constructor*/ /* v3.3 */
/*__has_unique_object_representations*/ /* v6.0 */
/*__reference_binds_to_temporary*/ /* 7.0 */
/*__is_lvalue_expr (operator? specifier?) */ /* v3.0 */
/*__is_rvalue_expr (operator? specifier?) */ /* v3.0 */
/*__is_arithmetic*/ /* v3.0 */
/*__is_floating_point*/ /* v3.0 */
/*__is_integral*/ /* v3.0 */
/*__is_complete_type*/ /* v3.0 */
/*__is_void*/ /* v3.0 */
/*__is_array*/ /* v3.0 */
/*__is_function*/ /* v3.0 */
/*__is_reference*/ /* v3.0 */
/*__is_lvalue_reference*/ /* v3.0 */
/*__is_rvalue_reference*/ /* v3.0 */
/*__is_fundamental*/ /* v3.0 */
/*__is_object*/ /* v3.0 */
/*__is_scalar*/ /* v3.0 */
/*__is_compound*/ /* v3.0 */
/*__is_pointer*/ /* v3.0 */
/*__is_member_object_pointer*/ /* v3.0 */
/*__is_member_function_pointer*/ /* v3.0 */
/*__is_member_pointer*/ /* v3.0 */
/*__is_const*/ /* v3.0 */
/*__is_volatile*/ /* v3.0 */
/*__is_signed*/ /* v3.0 */
/*__is_unsigned*/ /* v3.0 */
/*__is_same*/ /* v3.0 */
/*__is_convertible (?) Embarcadero */ /* v3.0 */
/*__array_rank*/ /* v3.0 */
/*__array_extent*/ /* v3.0 */
/*__builtin_omp_required_simd_align*/ /* v3.7 */


#ifdef __cplusplus

#	if Z_COMPILER_VERSION >= Z_VERSION(3, 5, 0)
#		define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_ASSIGNABLE    __is_nothrow_assignable	 /* v3.5 */
#		define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_CONSTRUCTIBLE __is_nothrow_constructible /* v3.5 */

#		if Z_COMPILER_VERSION >= Z_VERSION(3, 9, 0)
#			define Z_COMPILER_TRAIT_TYPE_IS_ASSIGNABLE __is_assignable /* v3.9 */

#			if Z_COMPILER_VERSION >= Z_VERSION(5, 0, 0)
#				define Z_COMPILER_TRAIT_TYPE_IS_AGGREGATE __is_aggregate /* v5.0 */
#			endif
#		endif
#	endif
#endif

#if __has_extension(has_virtual_destructor)
#	define Z_COMPILER_TRAIT_TYPE_HAS_VIRTUAL_DESTRUCTOR __has_virtual_destructor /* v2.6 */
#endif

#if __has_extension(is_abstract)
#	define Z_COMPILER_TRAIT_TYPE_IS_ABSTRACT __is_abstract /* v2.6 */
#endif

#if __has_extension(is_base_of)
#	define Z_COMPILER_TRAIT_TYPE_IS_BASE __is_base_of /* v2.6 */
#endif

#if __has_extension(is_constructible)
#	define Z_COMPILER_TRAIT_TYPE_IS_CONSTRUCTIBLE __is_constructible /* v3.5 */
#endif

#if __has_extension(is_convertible_to)
#	define Z_COMPILER_TRAIT_TYPE_IS_CONVERTIBLE __is_convertible_to /* v2.9 */
#endif

#if __has_extension(is_empty)
#	define Z_COMPILER_TRAIT_TYPE_IS_EMPTY __is_empty /* v2.6 */
#endif

#if __has_extension(is_enum)
#	define Z_COMPILER_TRAIT_TYPE_IS_ENUMERATION __is_enum /* v2.6 */
#endif

#if __has_extension(is_final)
#	define Z_COMPILER_TRAIT_TYPE_IS_FINAL __is_final /* v3.1 */
#endif

#if __has_extension(is_interface_class)
#	define Z_COMPILER_TRAIT_TYPE_IS_INTERFACE_CLASS __is_interface_class /* v3.2 (not detectable with __has_extension?) */
#endif

#if __has_extension(is_literal)
#	define Z_COMPILER_TRAIT_TYPE_IS_LITERAL __is_literal /* v2.7 */

#elif defined(__cplusplus) && Z_COMPILER_VERSION >= Z_VERSION(3, 0, 0)
#	define Z_COMPILER_TRAIT_TYPE_IS_LITERAL __is_literal_type /* v3.0 */
#endif

#if __has_extension(has_nothrow_assign)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_COPY_ASSIGNABLE __has_nothrow_assign /* v2.6 */
#endif

#if __has_extension(has_nothrow_copy)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_COPY_CONSTRUCTIBLE __has_nothrow_copy /* v2.6 */
#endif

#if __has_extension(has_nothrow_constructor)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_DEFAULT_CONSTRUCTIBLE __has_nothrow_constructor /* v2.6 */
#endif

#if __has_extension(is_pod)
#	define Z_COMPILER_TRAIT_TYPE_IS_POD __is_pod /* v2.6 */
#endif

#if __has_extension(is_polymorphic)
#	define Z_COMPILER_TRAIT_TYPE_IS_POLYMORPHIC __is_polymorphic /* v2.6 */
#endif

#if __has_extension(is_standard_layout)
#	define Z_COMPILER_TRAIT_TYPE_IS_STANDARD_LAYOUT __is_standard_layout /* v3.0 */
#endif

#if __has_extension(is_class)
#	define Z_COMPILER_TRAIT_TYPE_IS_STRUCTURE __is_class /* v2.6 */
#endif

#if __has_extension(is_trivial)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIAL __is_trivial /* v3.0 */
#endif

#if __has_extension(is_trivially_assignable)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_ASSIGNABLE __is_trivially_assignable /* v3.1 */
#endif

#if __has_extension(is_trivially_constructible)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_CONSTRUCTIBLE __is_trivially_constructible /* v3.1 */
#endif

#if __has_extension(has_trivial_assign)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_COPY_ASSIGNABLE __has_trivial_assign /* v2.6 */
#endif

#if __has_extension(has_trivial_copy)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE __has_trivial_copy /* v2.6 */
#endif

#if __has_extension(is_trivially_copyable)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_COPYABLE __is_trivially_copyable /* v3.0 */
#endif

#if __has_extension(has_trivial_constructor)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE __has_trivial_constructor /* v2.6 */
#endif

#if __has_extension(has_trivial_destructor)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_DESTRUCTIBLE __has_trivial_destructor /* v2.6 */
#endif

#if __has_extension(is_union)
#	define Z_COMPILER_TRAIT_TYPE_IS_UNION __is_union /* v2.6 */
#endif

#if __has_extension(underlying_type)
#	define Z_COMPILER_TRAIT_TYPE_UNDERLYING_TYPE __underlying_type /* v3.0 */
#endif

#if	defined(__LONG_DOUBLE_128__) /* v2.6 */ || \
	defined(__LONGDOUBLE128	   ) /* v5.0 */

#	define Z_COMPILER_CONSTANT_LDOUBLE_PRECISION_BITS 128 /* TODO */
#endif

/* MARK: - Private helpers clean-up */

#undef z__has_attribute
#undef z__has_builtin
#undef z__has_cpp_attribute
#undef z__has_extension
#undef z__has_feature












/* MARK: - Floating point number format */

#ifdef __LDBL_MANT_DIG__ /* v2.6 */

#	if __LDBL_MANT_DIG__ == 53
#		define Z_COMPILER_FLOATING_POINT_NUMBER_FORMAT_LDOUBLE Z_NUMBER_FORMAT_IEEE_754_BINARY64

#	elif __LDBL_MANT_DIG__ == 64
#		define Z_COMPILER_FLOATING_POINT_NUMBER_FORMAT_LDOUBLE Z_NUMBER_FORMAT_X87_BINARY80

#	elif __LDBL_MANT_DIG__ == 106
#		define Z_COMPILER_FLOATING_POINT_NUMBER_FORMAT_LDOUBLE Z_NUMBER_FORMAT_IBM_DOUBLE_DOUBLE

#	elif __LDBL_MANT_DIG__ == 113
#		define Z_COMPILER_FLOATING_POINT_NUMBER_FORMAT_LDOUBLE Z_NUMBER_FORMAT_IEEE_754_BINARY128
#	endif

#endif


#endif /* Z_inspection_compiler_modules_Clang_H */
