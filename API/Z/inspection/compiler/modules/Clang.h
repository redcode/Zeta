/* Zeta API - Z/inspection/compiler/modules/Clang.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.------------------------------------------------------------------------------.
|	  Compiler: Clang						       |
|     Last version: v10.0						       |
| Language support: C89 - C17, C++98 - C++17				       |
|          Options: -pedantic -Wall -Wextra				       |
|------------------------------------------------------------------------------|
|									       |
| 2. VERSION NOTATION							       |
| -------------------							       |
|									       |
| N -> Release Notes							       |
| S -> C++ Status							       |
| T -> Tested								       |
| Tw -> Tested and generate warnings					       |
| T! -> Tested and doesn't generate warnings				       |
|									       |
| 3. COMMONLY USED PREDEFINED MACROS					       |
| ----------------------------------					       |
|									       |
| Macro			     |   Value | Since | Meaning		       |
| ---------------------------+---------+-------+------------------------------ |
| __STDC_VERSION__	     | 199409L |  v2.6 | C95			       |
| __STDC_VERSION__	     | 199901L |  v2.6 | C99			       |
| __STDC_VERSION__	     | 201112L |  v3.1 | C11			       |
| __STDC_VERSION__	     | 201710L |  v6.0 | C17			       |
| __STRICT_ANSI__	     |	     1 |  v2.6 |			       |
| __GXX_EXPERIMENTAL_CXX0X__ |	     1 |  v2.6 | C++11 (experimental)	       |
| __cplusplus		     |	     1 |       | GNU++11		       |
| __cplusplus		     | 199711L |  v2.6 | C++98/C++03		       |
| __cplusplus		     | 201103L |  v3.0 | C++11			       |
| __cplusplus		     | 201305L |  v3.3 | C++14 (experimental)	       |
| __cplusplus		     | 201402L |  v3.5 | C++14			       |
| __cplusplus		     | 201406L |  v3.5 | C++17 (experimental)	       |
| __cplusplus		     | 201703L |  v5.0 | C++17			       |
| __cplusplus		     | 201707L |  v5.0 | C++20 (experimental)	       |
| __cplusplus		     | 202002L | v10.0 | C++20			       |
|									       |
|
| -std=gnu++11 causes __cplusplus be predefined as 1 instead of 201103L in versions
| prior to v3.2.
|
| C++11 feature test macros not used (for now):
|  __has_feature(cxx_access_control_sfinae)
|  __has_feature(cxx_implicit_moves)
'=============================================================================*/

#ifndef Z_inspection_compiler_modules_Clang_H
#define Z_inspection_compiler_modules_Clang_H

/* MARK: - Identification */

#define Z_COMPILER_IS_CLANG 1
#define Z_COMPILER_NAME	    Z_COMPILER_NAME_CLANG

#if defined(__clang_version__) /* v2.8 */
#	define Z_COMPILER_VERSION	 Z_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#	define Z_COMPILER_VERSION_STRING __clang_version__

#elif defined(__SIZE_WIDTH__) /* v2.7 */
#	define Z_COMPILER_VERSION	 Z_VERSION(2,7,0)
#	define Z_COMPILER_VERSION_STRING "2.7"

#else
#	define Z_COMPILER_VERSION	 Z_VERSION(2,6,0)
#	define Z_COMPILER_VERSION_STRING "2.6"
#endif

/* MARK: - Private macros */

#ifdef __has_attribute /* v2.9 */
#	define Z_z_HAS_ATTRIBUTE __has_attribute
#else
#	define Z_z_HAS_ATTRIBUTE(which) 0
#endif

#ifdef __has_cpp_attribute /* v3.6 */
#	define Z_z_HAS_CPP_ATTRIBUTE __has_cpp_attribute
#else
#	define Z_z_HAS_CPP_ATTRIBUTE(which) 0
#endif

#ifdef __has_extension /* v3.0 */
#	define Z_z_HAS_EXTENSION __has_extension
#else
#	define Z_z_HAS_EXTENSION __has_feature
#endif

/*---------------------------------------------------------------------------.
| IMPORTANT: There is no well-defined way to know if the MSVC compatibility  |
| mode is enabled. The following method is based on certain macros that are  |
| known to be predefined or not when this mode is used. This could change in |
| future versions of Clang...						     |
'===========================================================================*/
#if	(Z_COMPILER_VERSION >= Z_VERSION(3,1,0) && !defined(__GNUC__	       )) || \
	(Z_COMPILER_VERSION == Z_VERSION(3,0,0) &&  defined(__PRETTY_FUNCTION__)) || \
	(Z_COMPILER_VERSION <  Z_VERSION(3,0,0) && !defined(__STDC__	       ))

#	define Z_z_HAS_MSVC_COMPATIBILITY 1
#else
#	define Z_z_HAS_MSVC_COMPATIBILITY 0
#endif

/*-------------------------------------------------------------------------.
| IMPORTANT: Since v3.5, there is no way to know if the GNU extensions are |
| enabled when using the MSVC compatibility mode. However, this may not be |
| a serious problem, as ideally both things should be mutually exclusive.  |
'=========================================================================*/
#if	!defined(__STRICT_ANSI__) &&		     \
	((Z_COMPILER_VERSION <  Z_VERSION(3,5,0)) || \
	 (Z_COMPILER_VERSION >= Z_VERSION(3,5,0) && !Z_z_HAS_MSVC_COMPATIBILITY))

#	define Z_z_HAS_GNU_EXTENSIONS 1
#else
#	define Z_z_HAS_GNU_EXTENSIONS 0
#endif

#if Z_COMPILER_VERSION >= Z_VERSION(10,0,0)
#	define Z_z_HAS_TRAIT(which) \
	(__has_builtin(__##which) || !__is_identifier(__##which) || __has_extension(which))

#elif Z_COMPILER_VERSION >= Z_VERSION(6,0,0)
#	define Z_z_HAS_TRAIT(which) \
	(!__is_identifier(__##which) || __has_extension(which))

#else
#	define Z_z_HAS_TRAIT Z_z_HAS_EXTENSION
#endif

/* MARK: - ISA / Bit field order */

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

#elif	defined(__ARM_ARCH_ISA_A64) /* v3.4 */ || \
	defined(__aarch64__	  ) /* v3.3 */ || \
	defined(__arm64		  ) /* v3.5 */ || \
	defined(__arm64__	  ) /* v3.5 */ || \
	defined(_M_ARM64	  ) /* v5.0 */

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

#elif defined(__arc__) /* v8.0 */
#	define Z_COMPILER_ISA Z_ISA_ARC

#elif	defined(__HEXAGON_ARCH__) /* v3.1 */ || \
	defined(__QDSP6_ARCH__	) /* v3.1 */ || \
	defined(__hexagon	) /* v3.1 */ || \
	defined(__hexagon__	) /* v3.1 */ || \
	defined(__qdsp6		) /* v3.1 */ || \
	defined(__qdsp6__	) /* v3.1 */ || \
	defined(hexagon		) /* v3.1 */ || \
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

#elif defined(__loongarch64) /* v16.0 */
#	define Z_COMPILER_ISA Z_ISA_LA64

#elif defined(__loongarch__) /* v16.0 */
#	define Z_COMPILER_ISA Z_ISA_LA32S

#elif defined(__lanai__) /* v3.9 */
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

#elif	defined(__wasm64  ) || \
	defined(__wasm64__)

#	define Z_COMPILER_ISA Z_ISA_WASM64

#elif	defined(__wasm	  ) || \
	defined(__wasm__  ) || \
	defined(__wasm32  ) || \
	defined(__wasm32__)

#	define Z_COMPILER_ISA Z_ISA_WASM32

#elif defined(__XS1B__) /* v3.4 */
#	define Z_COMPILER_ISA Z_ISA_XCORE

#elif   defined(__s390__ ) /* v2.6 */ || \
	defined(__s390x__) /* v2.6 */ || \
	defined(__zarch__) /* v3.3 */

#	define Z_COMPILER_ISA Z_ISA_Z_ARCHITECTURE
#endif

#ifdef __BYTE_ORDER__ /* v3.2 */
#	if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ /* v3.2 */
#		define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS Z_ENDIANNESS_LITTLE
#		define Z_COMPILER_BIT_FIELD_ORDER_ALL	  Z_ORDER_REVERSED

#	elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ /* v3.2 */
#		define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS Z_ENDIANNESS_BIG
#		define Z_COMPILER_BIT_FIELD_ORDER_ALL	  Z_ORDER_NORMAL
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

#	define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS Z_ENDIANNESS_LITTLE
#	define Z_COMPILER_BIT_FIELD_ORDER_ALL	  Z_ORDER_REVERSED

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

#	define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS Z_ENDIANNESS_BIG
#	define Z_COMPILER_BIT_FIELD_ORDER_ALL	  Z_ORDER_NORMAL

#else
#	error "Clang module: Can not detect the endianness of the integral types."
#endif

/*#define Z_COMPILER_BIT_FIELD_ORDER_8BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_16BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_32BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_64BIT*/
/*#define Z_COMPILER_BIT_FIELD_ORDER_128BIT*/

/* MARK: - Platform / OS */

#if defined(__ANDROID__) /* v3.2 */
#	define Z_COMPILER_OS Z_OS_ANDROID

#elif	defined(__gnu_linux__) /* v2.6 */ || \
	defined(__linux	     ) /* v2.6 */ || \
	defined(__linux__    ) /* v2.6 */ || \
	defined(linux	     ) /* v2.6 */

#	define Z_COMPILER_OS Z_OS_LINUX

#elif	defined(__APPLE_CC__)  /* v2.6 */ || \
       (defined(__APPLE__   )  /* v2.6 */ && \
	defined(__MACH__    )) /* v2.6 */

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

#elif defined(_AIX) /* v9.0 */
#	define Z_COMPILER_OS Z_OS_AIX

#elif defined(__Ananas__) /* v5.0 */
#	define Z_COMPILER_OS Z_OS_ANANAS_OS

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

#elif defined(__gnu_hurd__) /* v8.0 */
#	define Z_COMPILER_OS Z_OS_GNU_HURD

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

/* TODO: z-OS */

#endif

/* MARK: - Data model */

#if	defined(__ILP32__) /* v3.5 */ || \
	defined(_ILP32	 ) /* v3.5 */ || \
	defined(_WIN32	 ) /* v2.6 */

#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_ILP32

#elif defined(_WIN64) /* v2.7 */
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LLP64

#elif defined(__LP32__) /* v2.7 */
#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LP32

#elif	defined(__LP64__) /* v2.6 */ || \
	defined(_LP64	) /* v2.6 */

#	define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_LP64
#endif

/* MARK: - Floating-point */

#ifdef __FLT_MANT_DIG__ /* v2.6 */
#	if   __FLT_MANT_DIG__ == 11
#		define Z_COMPILER_FIXED_FUNDAMENTAL_FLOAT Z_FUNDAMENTAL_BFP16

#	elif __FLT_MANT_DIG__ == 24
#		define Z_COMPILER_FIXED_FUNDAMENTAL_FLOAT Z_FUNDAMENTAL_BFP32

#	elif __FLT_MANT_DIG__ == 53
#		define Z_COMPILER_FIXED_FUNDAMENTAL_FLOAT Z_FUNDAMENTAL_BFP64

#	elif
#		error "Clang module: Can not detect the format of the float type."
#	endif
#endif

#ifdef __DBL_MANT_DIG__ /* v2.6 */
#	if   __DBL_MANT_DIG__ == 11
#		define Z_COMPILER_FIXED_FUNDAMENTAL_DOUBLE Z_FUNDAMENTAL_BFP16

#	elif __DBL_MANT_DIG__ == 24
#		define Z_COMPILER_FIXED_FUNDAMENTAL_DOUBLE Z_FUNDAMENTAL_BFP32

#	elif __DBL_MANT_DIG__ == 53
#		define Z_COMPILER_FIXED_FUNDAMENTAL_DOUBLE Z_FUNDAMENTAL_BFP64

#	else
#		error "Clang module: Can not detect the format of the double type."
#	endif
#endif

#ifdef __LDBL_MANT_DIG__ /* v2.6 */
#	if __LDBL_MANT_DIG__ == 11
#		define Z_COMPILER_FIXED_FUNDAMENTAL_LDOUBLE Z_FUNDAMENTAL_BFP16

#	elif __LDBL_MANT_DIG__ == 24
#		define Z_COMPILER_FIXED_FUNDAMENTAL_LDOUBLE Z_FUNDAMENTAL_BFP32

#	elif __LDBL_MANT_DIG__ == 53
#		define Z_COMPILER_FIXED_FUNDAMENTAL_LDOUBLE Z_FUNDAMENTAL_BFP64

#	elif __LDBL_MANT_DIG__ == 64
#		ifdef __SIZEOF_LONG_DOUBLE__ /* v2.8 */
#			if   __SIZEOF_LONG_DOUBLE__ == 12
#				define Z_COMPILER_FIXED_FUNDAMENTAL_LDOUBLE Z_FUNDAMENTAL_X87_DE96

#			elif __SIZEOF_LONG_DOUBLE__ == 16
#				define Z_COMPILER_FIXED_FUNDAMENTAL_LDOUBLE Z_FUNDAMENTAL_X87_DE128
#			endif

#		elif Z_COMPILER_VERSION < Z_VERSION(2,8,0)
#			include <Z/keys/ISA.h>
#			include <Z/keys/OS.h>

#			if	(defined(Z_COMPILER_ISA) && Z_COMPILER_ISA == Z_ISA_X86_64 ) || \
				(defined(Z_COMPILER_OS ) && Z_COMPILER_OS  == Z_OS_MAC_OS_X)

#				define Z_COMPILER_FIXED_FUNDAMENTAL_LDOUBLE Z_FUNDAMENTAL_X87_DE128

#			elif defined(Z_COMPILER_ISA) && Z_COMPILER_ISA == Z_ISA_X86_32
#				define Z_COMPILER_FIXED_FUNDAMENTAL_LDOUBLE Z_FUNDAMENTAL_X87_DE96
#			else
#				error "Clang module: Can not detect the format of the long double type."
#			endif
#		endif

#	elif __LDBL_MANT_DIG__ == 106
#		define Z_COMPILER_FIXED_FUNDAMENTAL_LDOUBLE Z_FUNDAMENTAL_IBM_ED

#	elif __LDBL_MANT_DIG__ == 113
#		define Z_COMPILER_FIXED_FUNDAMENTAL_LDOUBLE Z_FUNDAMENTAL_BFP128

#	else
#		error "Clang module: Can not detect the format of the long double type."
#	endif
#endif

/*#define Z_COMPILER_FIXED_FUNDAMENTAL_FLOAT32X*/
/*#define Z_COMPILER_FIXED_FUNDAMENTAL_FLOAT64X*/
/*#define Z_COMPILER_FIXED_FUNDAMENTAL_FLOAT128X*/
/*#define Z_COMPILER_FIXED_FUNDAMENTAL_DECIMAL64X*/
/*#define Z_COMPILER_FIXED_FUNDAMENTAL_DECIMAL128X*/

/* MARK: - Language: C78 */

#define Z_COMPILER_HAS_C_OLD_STYLE_FUNCTION   1 /* v2.6 */
#define Z_COMPILER_HAS_C_OPERATOR_SIZEOF      1 /* v2.6 */
#define Z_COMPILER_HAS_C_STORAGE_CLASS_EXTERN 1 /* v2.6 */
#define Z_COMPILER_HAS_C_STORAGE_CLASS_STATIC 1 /* v2.6 */

#if __has_feature(cxx_auto_type) /* v2.7 */
#	define Z_COMPILER_HAS_C_STORAGE_CLASS_AUTO 1 /* v2.6 */
#endif

#if	!defined(__cplusplus) || __cplusplus < 201103L || \
	Z_COMPILER_VERSION < Z_VERSION(3,4,0)

#	define Z_COMPILER_HAS_C_STORAGE_CLASS_REGISTER 1 /* v2.6 */
#endif

#ifdef __DBL_MAX__ /* v2.6 */
#	define Z_COMPILER_HAS_C_TYPE_DOUBLE 1 /* v2.6 */
#endif

#ifdef __FLT_MAX__ /* v2.6 */
#	define Z_COMPILER_HAS_C_TYPE_FLOAT 1 /* v2.6 */
#endif

/* MARK: - Language: C89 */

#define Z_COMPILER_HAS_C89_CONSTANT_INITIALIZATION_FOR_LOCAL_AGGREGATE 1 /* v2.6 */
#define Z_COMPILER_HAS_C89_CONSTANT_INITIALIZATION_FOR_UNION	       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_CONSTRUCT_AS_FUNCTION_ARGUMENT	       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_CONSTRUCT_RETURN			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_CONSTRUCT_ASSIGNMENT			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_CONSTRUCT_NAMESPACE			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_ENUMERATION				       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_FUNCTION_POINTER_AUTODEREFERENCING	       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_FUNCTION_PROTOTYPE			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_INTEGRAL_SWITCH			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_PREPROCESSOR_INDENTATION		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_REMOVAL_OF_ENTRY_AS_KEYWORD		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_REMOVAL_OF_LONG_FLOAT_AS_TYPE	       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_STRING_LITERAL_CONCATENATION		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_VALUE_PRESERVING_UNSIGNED_CONVERSION	       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_ESCAPE_SEQUENCE_ALERT		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_ESCAPE_SEQUENCE_HEXADECIMAL		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_ESCAPE_SEQUENCE_VERTICAL_TAB		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_LITERAL_UNSIGNED			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_LITERAL_WCHAR_T_CHARACTER		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_LITERAL_WCHAR_T_STRING		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_OPERATOR_UNARY_PLUS			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_PREPROCESSOR_DIRECTIVE_NULL		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_PREPROCESSOR_DIRECTIVE_ELIF		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_PREPROCESSOR_DIRECTIVE_ERROR		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_PREPROCESSOR_DIRECTIVE_LINE		       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_PREPROCESSOR_DIRECTIVE_PRAGMA	       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_PREPROCESSOR_OPERATOR_DEFINED	       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_PREPROCESSOR_OPERATOR_PASTING	       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_PREPROCESSOR_OPERATOR_STRINGIZING	       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_TYPE_UNSIGNED_CHAR			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_TYPE_UNSIGNED_LONG			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_TYPE_UNSIGNED_SHORT			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_TYPE_VOID				       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_TYPE_VOID_POINTER			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_TYPE_MODIFIER_SIGNED			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_TYPE_QUALIFIER_CONST			       1 /* v2.6 */
#define Z_COMPILER_HAS_C89_TYPE_QUALIFIER_VOLATILE		       1 /* v2.6 */

#ifdef __FLT_MAX__ /* v2.6 */
#	define Z_COMPILER_HAS_C89_LITERAL_FLOAT 1 /* v2.6 */
#endif

#ifdef __LDBL_MAX__ /* v2.6 */
#	define Z_COMPILER_HAS_C89_TYPE_LONG_DOUBLE 1 /* v2.6 */
#endif

/*#define Z_COMPILER_HAS_C89_TRIGRAPHS*/ /* Always generate warnings/errors. */

/* MARK: - Language: C95 */

#if	defined(__cplusplus)   || \
	Z_z_HAS_GNU_EXTENSIONS || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199409L)

#	define Z_COMPILER_HAS_C95_DIGRAPHS 1 /* v2.6 */
#endif

/* MARK: - Language: C99 */

#define Z_COMPILER_HAS_C99_PREPROCESSOR_ARITHMETIC_DONE_IN_INTMAX   1 /* v2.6? */
#define Z_COMPILER_HAS_C99_RELIABLE_INTEGER_DIVISION		    1 /* v2.6 */
#define Z_COMPILER_HAS_C99_REMOVAL_OF_ILL_FORMED_RETURN		    1 /* v2.6 */
#define Z_COMPILER_HAS_C99_REMOVAL_OF_IMPLICIT_FUNCTION_DECLARATION 1 /* v2.6 */
#define Z_COMPILER_HAS_C99_REMOVAL_OF_IMPLICIT_INT		    1 /* v2.6 */
#define Z_COMPILER_HAS_C99_IDENTIFIER_FUNC			    1 /* v2.6 */
#define Z_COMPILER_HAS_C99_PREPROCESSOR_OPERATOR_PRAGMA		    1 /* v2.6 */
#define Z_COMPILER_HAS_C99_STD_PRAGMA_CX_LIMITED_RANGE		    1 /* v2.6 */
#define Z_COMPILER_HAS_C99_STD_PRAGMA_FP_CONTRACT		    1 /* v2.6 */

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#	define Z_COMPILER_HAS_C99_COMPOUND_LITERAL				 1 /* v2.6 */
#	define Z_COMPILER_HAS_C99_DESIGNATED_INITIALIZATION			 1 /* v2.6 */
#	define Z_COMPILER_HAS_C99_FLEXIBLE_ARRAY_MEMBER				 1 /* v2.6 */
#	define Z_COMPILER_HAS_C99_STATIC_IN_ARRAY_PARAMETER_DECLARATION		 1 /* v2.6 */
#	define Z_COMPILER_HAS_C99_TYPE_QUALIFIERS_IN_ARRAY_PARAMETER_DECLARATION 1 /* v2.6 */
#	define Z_COMPILER_HAS_C99_TYPE_QUALIFIER_RESTRICT			 1 /* v2.6 */

#	ifndef __STDC_NO_VLA__ /* Not found in Clang's sources. */
#		define Z_COMPILER_HAS_C99_VLA 1 /* v2.6 */
#	endif
#endif

#if	defined(__cplusplus) || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)

#	define Z_COMPILER_HAS_C99_CONVERSION_OF_NON_LVALUE_ARRAY_TO_POINTER	  1 /* v2.6 */
#	define Z_COMPILER_HAS_C99_FOR_WITH_DECLARATION				  1 /* v2.6 */
#	define Z_COMPILER_HAS_C99_MIXED_DECLARATIONS_AND_CODE			  1 /* v2.6 */
#	define Z_COMPILER_HAS_C99_NON_CONSTANT_INITIALIZATION_FOR_LOCAL_AGGREGATE 1
#	define Z_COMPILER_HAS_C99_UNIVERSAL_CHARACTER_NAME			  1 /* v2.6 */
#	define Z_COMPILER_HAS_C99_SPECIFIER_INLINE				  1 /* v2.6 */
#endif

#if	defined(__cplusplus)   || \
	Z_z_HAS_GNU_EXTENSIONS || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)

#	define Z_COMPILER_HAS_C99_CPP_STYLE_COMMENT 1 /* v2.6 */
#endif

#if	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || \
	(Z_COMPILER_VERSION >= Z_VERSION(2,9,0) &&		      \
	 defined(__cplusplus) && (__cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)))

#	define Z_COMPILER_HAS_C99_EMPTY_MACRO_ARGUMENT 1 /* v2.6 (C99), v2.9 (C++11 S) */
#	define Z_COMPILER_HAS_C99_VARIADIC_MACRO       1 /* v2.6 (C99), v2.9 (C++11 S) */
#	define Z_COMPILER_HAS_C99_TYPE_LONG_LONG       1 /* v2.6 (C99), v2.9 (C++11 S) */
#endif

#if	Z_COMPILER_VERSION >= Z_VERSION(3,3,0) && \
	(defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L))

#	define Z_COMPILER_HAS_C99_EXTENDED_IDENTIFIER 1 /* v3.3 (RN-T) */
#endif

#if	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || \
	(defined(__cplusplus) && (__cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)))

#	define Z_COMPILER_HAS_C99_TRAILING_COMMA_ALLOWED_IN_ENUMERATION 1 /* v2.6 */
#endif

#if	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)	      || \
	(defined(__cpp_hex_float ) && __cpp_hex_float  >= 201603L) /* v4.0 */ || \
	(Z_COMPILER_VERSION >= Z_VERSION(3,9,0) &&				 \
	 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&				 \
	 defined(__cplusplus) && __cplusplus >= 201406L)

#	define Z_COMPILER_HAS_C99_LITERAL_HEXADECIMAL_FLOATING_POINT 1 /* v2.6 (C99), v3.9 (C++17 T!) */
#endif

/*---------------------------------------------------------------------.
| BUG: _Bool has always been available in all versions of C but not in |
| C++, although it was available in C++ by mistake in v2.6 and v2.7.   | MAL, mirar
'=====================================================================*/
#if	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || \
	(!defined(__cplusplus) && Z_COMPILER_VERSION <= Z_VERSION(9,1,0))

#	define Z_COMPILER_HAS_C99_TYPE_BOOL 1 /* v2.6 */
#endif

#ifndef __STDC_NO_COMPLEX__ /* Not found in Clang's sources. */
#	define Z_COMPILER_HAS_C99_TYPE_MODIFIER_COMPLEX 1 /* v2.6 */

#	ifdef __DBL_MAX__ /* v2.6 */
#		define Z_COMPILER_HAS_C99_TYPE_DOUBLE_COMPLEX 1 /* v2.6 */
#	endif

#	ifdef __FLT_MAX__ /* v2.6 */
#		define Z_COMPILER_HAS_C99_TYPE_FLOAT_COMPLEX 1 /* v2.6 */
#	endif

#	ifdef __LDBL_MAX__ /* v2.6 */
#		define Z_COMPILER_HAS_C99_TYPE_LONG_DOUBLE_COMPLEX 1 /* v2.6 */
#	endif
#endif

/*#define Z_COMPILER_HAS_C99_IDEMPOTENT_TYPE_QUALIFIERS*/  /* Always generate warnings.		   */
/*#define Z_COMPILER_HAS_C99_STD_PRAGMA_FENV_ACCESS*/	   /* FENV_ACCESS ON is not implemented.   */
/*#define Z_COMPILER_HAS_C99_TYPE_DOUBLE_IMAGINARY*/	   /* _Imaginary recognized, but unusable. */
/*#define Z_COMPILER_HAS_C99_TYPE_FLOAT_IMAGINARY*/	   /* _Imaginary recognized, but unusable. */
/*#define Z_COMPILER_HAS_C99_TYPE_LONG_DOUBLE_IMAGINARY*/  /* _Imaginary recognized, but unusable. */
/*#define Z_COMPILER_HAS_C99_TYPE_MODIFIER_IMAGINARY*/	   /* _Imaginary recognized, but unusable. */

/* MARK: - Language: C11 */

#if Z_COMPILER_VERSION >= Z_VERSION(3,1,0)
#	if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#		define Z_COMPILER_HAS_C11_ANONYMOUS_STRUCTURE_AS_MEMBER 1 /* v3.1 (N-T!) */
#	endif

#	if Z_COMPILER_VERSION >= Z_VERSION(3,3,0)
		/*----------------------------------------------------------------------------.
		| NOTE: Since v3.3, __has_feature(c_thread_local) only returns 1 in C11 and   |
		| later, but _Thread_local compiles without warnings in any version of C/C++. |
		'============================================================================*/
/*#		if __has_feature(c_thread_local)*/ /* v3.3 */
#			define Z_COMPILER_HAS_C11_STORAGE_CLASS_THREAD_LOCAL 1 /* v3.3 (T) */
/*#		endif*/

		/*---------------------------------------------------------------------.
		| BUG: Since v3.0, __has_extension(c_alignas) always returns 1, and    |
		| __has_feature(c_alignas) returns 1 in C11 and later. Despite this,   |
		| explicitly using _Alignas() when declaring an identifier generates   |
		| errors in C++, and the same happens in C between v3.0 and v3.2.      |
		| However, using _Alignas() within a type definition seems to be safe. |
		'======================================================================*/
#		if __has_feature(c_alignas) /* v3.0 */
#			define Z_COMPILER_HAS_C11_SPECIFIER_ALIGNAS 1 /* v3.0 (N), v3.3 (T) */
#		endif

#		if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#			define Z_COMPILER_HAS_C11_SPECIFIER_NORETURN 1 /* v3.3 (T) */
#		endif

		/*--------------------------------------------------------------.
		| BUG: Since v3.1, __has_extension(c_atomic) always returns 1,  |
		| but _Atomic was not supported as a type qualifier until v3.3.	|
		'==============================================================*/
#		if __has_feature(c_atomic) /* v3.1 */
#			define Z_COMPILER_HAS_C11_TYPE_QUALIFIER_ATOMIC 1 /* v3.3 (T) */
#		endif
#	endif
#endif

#if	defined(__cplusplus) || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)

#	define Z_COMPILER_HAS_C11_ANONYMOUS_UNION_AS_MEMBER 1 /* v2.6? (C++), v3.1 (C11 N-T!) */
#endif

#if __has_feature(c_generic_selections) /* v3.0 */
#	define Z_COMPILER_HAS_C11_GENERIC_SELECTION 1 /* v3.0 (N-T) */
#endif

#if __has_feature(c_static_assert) /* v3.0 */
#	define Z_COMPILER_HAS_C11_STATIC_ASSERTION 1 /* v3.0 (N-T) */
#endif

#if	defined(__cplusplus)	   || \
	Z_z_HAS_MSVC_COMPATIBILITY || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)

#	define Z_COMPILER_HAS_C11_TYPEDEF_REDECLARATION 1 /* v2.6? (C++, MSVC), v3.1 (C11 T) */
#endif

#if	(defined(__cpp_unicode_characters) && __cpp_unicode_characters >= 200704L) /* v3.4 */		     || \
	(Z_COMPILER_VERSION <  Z_VERSION(3,4,0) && defined(__cplusplus	   ) && __cplusplus	 >= 201103L) || \
	(Z_COMPILER_VERSION >= Z_VERSION(3,3,0) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)

#	define Z_COMPILER_HAS_C11_LITERAL_CHAR16_T_CHARACTER 1 /* v2.9 (C++11 S), v3.0 (C++11 RN), v3.3 (C11 T) */
#	define Z_COMPILER_HAS_C11_LITERAL_CHAR16_T_STRING    1 /* v2.9 (C++11 S), v3.0 (C++11 RN), v3.3 (C11 T) */
#	define Z_COMPILER_HAS_C11_LITERAL_CHAR32_T_CHARACTER 1 /* v2.9 (C++11 S), v3.0 (C++11 RN), v3.3 (C11 T) */
#	define Z_COMPILER_HAS_C11_LITERAL_CHAR32_T_STRING    1 /* v2.9 (C++11 S), v3.0 (C++11 RN), v3.3 (C11 T) */
#endif

#if	(Z_COMPILER_VERSION >= Z_VERSION(3,3,0) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) || \
	(defined(__cpp_unicode_literals) && __cpp_unicode_literals >= 200710L) /* v3.4 */		     || \
	(defined(__cplusplus) &&										\
	 (__has_feature(cxx_unicode_literals) /* v3.1 */ ||							\
	  (Z_COMPILER_VERSION == Z_VERSION(3,0,0) && __cplusplus >= 201103L)))

#	define Z_COMPILER_HAS_C11_LITERAL_UTF8_STRING 1 /* v3.0 (C++11 N-S-T), v3.3 (C11 T) */
#endif

#if	__has_feature(c_alignof) /* v3.6 */ ||	   \
	(Z_COMPILER_VERSION >= Z_VERSION(3,2,0) && \
	 Z_COMPILER_VERSION <  Z_VERSION(3,6,0) && \
	 defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)

#	define Z_COMPILER_HAS_C11_OPERATOR_ALIGNOF 1 /* v3.2 (N-T) */
#endif

#if __has_feature(c_atomic) /* v3.1 */
#	define Z_COMPILER_HAS_C11_TYPE_MODIFIER_ATOMIC 1 /* v3.1 (T) */
#endif

/* MARK: - Language: Apple C extensions */

#if	Z_z_HAS_EXTENSION(blocks) /* v2.6 */ || \
	defined(__BLOCKS__)	  /* v2.6 */

#	define Z_COMPILER_HAS_APPLE_C_BLOCK_OBJECT 1 /* v2.6 */
#endif

/* MARK: - Language: Clang C extensions */

#if Z_COMPILER_VERSION >= Z_VERSION(2,7,0)
#	define Z_COMPILER_HAS_CLANG_C_PREPROCESSOR_OPERATOR_HAS_INCLUDE 1 /* v2.7 */
#endif

#ifdef __cplusplus

	/* MARK: - Language: C++98 */

#	define Z_COMPILER_HAS_CPP98_SFINAE       1 /* v2.6 */
#	define Z_COMPILER_HAS_CPP98_TYPE_BOOL    1 /* v2.6 */
#	define Z_COMPILER_HAS_CPP98_TYPE_WCHAR_T 1 /* v2.6 */

#	if	defined(_M_IX86	) || /* v2.7 */ \
		defined(_M_X64	) || /* v2.7 */ \
		defined(_M_ARM64)    /* v5.0 */

		/*-----------------------------------------------------------------------.
		| NOTE: According to Clang's documentation, support for C++ exceptions	 |
		| compatible with the MSVC C++ ABI was not "mostly complete" until v3.9. |
		'=======================================================================*/
#		if defined(_CPPUNWIND) /* v2.9 */ && Z_COMPILER_VERSION >= Z_VERSION(3,9,0)
#			define Z_COMPILER_HAS_CPP98_EXCEPTIONS 1 /* v3.9 */
#		endif

#		ifdef _CPPRTTI /* v3.0 */
#			define Z_COMPILER_HAS_CPP98_RTTI 1 /* v3.0? */
#		endif

#	else
#		if	(defined(__cpp_exceptions) && __cpp_exceptions >= 199711L) /* v3.6 */ || \
			 __has_feature(cxx_exceptions)				   /* v2.7 */ || \
			 defined(__EXCEPTIONS)					   /* v2.6 */ /* IMPORTANT: READ 3.5 Release Notes, bevaiour changed. */

#			define Z_COMPILER_HAS_CPP98_EXCEPTIONS 1 /* v2.6 */
#		endif

#		if	defined(__cpp_rtti) && __cpp_rtti >= 199711L /* v3.6 */ || \
			__has_feature(cxx_rtti)			     /* v2.7 */ || \
			defined(__GXX_RTTI)			     /* v2.8 */

#			define Z_COMPILER_HAS_CPP98_RTTI 1 /* v2.7 (S?) */
#		endif
#	endif

	/* MARK: - Language: C++03 */

#	define Z_COMPILER_HAS_CPP03_VALUE_INITIALIZATION 1 /* v2.6 */

	/* MARK: - Language: C++11 */

#	define Z_COMPILER_HAS_CPP11_IDENTIFIER_FUNC 1 /* v2.6?, v2.9 (S) */

#	if Z_COMPILER_VERSION >= Z_VERSION(2,9,0)
#		define Z_COMPILER_HAS_CPP11_EXPRESSION_SFINAE 1 /* v2.9 (S) */

#		if __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)
#			define Z_COMPILER_HAS_CPP11_C99_PREPROCESSOR		1 /* v2.9 (S) */
#			define Z_COMPILER_HAS_CPP11_EXTENDED_FRIEND_DECLARATION 1 /* v2.9 (S) */
#			define Z_COMPILER_HAS_CPP11_TYPE_LONG_LONG		1 /* v2.9 (S) */

			/*-----------------------------------------------------------------------------.
			| NOTE: In v3.0 (and possibly v2.9), extern templates compile without warnings |
			| in any version of C++. Z only recognizes this feature in C++11 and later.    |
			'=============================================================================*/
#			define Z_COMPILER_HAS_CPP11_EXTERN_TEMPLATE 1 /* v2.9 (S) */
#		endif

#		if	__cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__) || \
			Z_z_HAS_MSVC_COMPATIBILITY

#			define Z_COMPILER_HAS_CPP11_INITIALIZATION_OF_CLASS_OBJECT_BY_RVALUE 1 /* v2.9 (S) */
#		endif

#		if __has_feature(cxx_auto_type) /* v2.7 */
#			define Z_COMPILER_HAS_CPP11_MULTI_DECLARATOR_AUTO 1 /* v2.7?, v2.9 (S) */
#			define Z_COMPILER_HAS_CPP11_TYPE_AUTO		  1 /* v2.7?, v2.9 (S) */

			/*-----------------------------------------------------------------.
			| BUG: In v3.0 (and possibly earlier versions), using `auto` as a  |
			| storage class generates warnings in C++03 and earlier. This must |
			| be tolerated to not break compatibility with existing software.  |
			'=================================================================*/
#			define Z_COMPILER_HAS_CPP11_REMOVAL_OF_AUTO_AS_STORAGE_CLASS 1 /* v2.7?, v2.9 (S) */
#		endif

#		if Z_COMPILER_VERSION >= Z_VERSION(3,0,0)
#			if __cplusplus >= 201103L
#				define Z_COMPILER_HAS_CPP11_MOVE_SPECIAL_MEMBER_FUNCTIONS		1 /* v3.0 (S-T)		*/
#				define Z_COMPILER_HAS_CPP11_OPERATOR_CASE_SIZEOF_NON_STATIC_DATA_MEMBER 1 /* v3.0 (T), v3.1 (S) */
#			endif

#			if Z_COMPILER_VERSION >= Z_VERSION(3,1,0)
#				if __cplusplus >= 201103L
#					define Z_COMPILER_HAS_CPP11_UNIVERSAL_CHARACTER_NAME 1 /* v3.1 (S-T) */

					/*------------------------------------------------------------.
					| BUG: DR1206 14.5.1.4 Enumeration members of class templates |
					| TODO: Read v3.9 release notes (related?)		      |
					'============================================================*/
#					define Z_COMPILER_HAS_CPP11_OPAQUE_ENUMERATION_DECLARATION 1 /* v3.1 (N-S-T), v3.2 (N) */
#				endif

				/*-----------------------------------------------------------------------.
				| BUG: Since v3.0, __has_feature(cxx_explicit_conversions) returns 1 in	 |
				| C++11 and later, but this feature did not work properly until v3.1.	 |
				'=======================================================================*/
#				if __has_feature(cxx_explicit_conversions) /* v3.0 */
#					define Z_COMPILER_HAS_CPP11_EXPLICIT_CONVERSION_OPERATOR 1 /* v3.0 (S), v3.1 (T) */
#				endif

#				if Z_COMPILER_VERSION >= Z_VERSION(3,2,0) && __cplusplus >= 201103L
#					define Z_COMPILER_HAS_CPP11_STD_LAYOUT 1 /* v3.0 (S), v3.2? (T!?) *//* TODO: More tests. */
#				endif
#			endif
#		endif
#	endif

#	if	__has_feature(cxx_local_type_template_args) /* v3.1 */		   || \
		(Z_COMPILER_VERSION == Z_VERSION(3,0,0) && __cplusplus >= 201103L) || \
		(Z_COMPILER_VERSION == Z_VERSION(2,9,0) && defined(__GXX_EXPERIMENTAL_CXX0X__))

#		define Z_COMPILER_HAS_CPP11_ANONYMOUS_TYPE_AS_TEMPLATE_ARGUMENT 1 /* v2.9 (S) */
#		define Z_COMPILER_HAS_CPP11_LOCAL_TYPE_AS_TEMPLATE_ARGUMENT	1 /* v2.9 (S) */
#	endif

#	if	(defined(__cpp_initializer_lists) && __cpp_initializer_lists >= 200806L) /* v3.6 */ || \
		__has_feature(cxx_generalized_initializers)				 /* v3.1 */

#		define Z_COMPILER_HAS_CPP11_COPY_LIST_INITIALIZATION   1 /* v3.1 (N-S-T) */
#		define Z_COMPILER_HAS_CPP11_DIRECT_LIST_INITIALIZATION 1 /* v3.1 (N-S-T) */
#		define Z_COMPILER_HAS_CPP11_INITIALIZER_LIST	       1 /* v3.1 (N-S-T) [No library support until v3.3?] */
#	endif

#	if	(defined(__cpp_nsdmi) && (__cpp_nsdmi >= 200809L)) /* v3.6 */ || \
		__has_feature(cxx_nonstatic_member_init)	   /* v3.0 */

#		define Z_COMPILER_HAS_CPP11_DEFAULT_MEMBER_INITIALIZER 1 /* v3.0 (N-S-T) */
#	endif

#	if __has_feature(cxx_default_function_template_args) /* v2.9 */
#		define Z_COMPILER_HAS_CPP11_DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE 1 /* v2.9 (S) */
#	endif

#	if	(defined(__cpp_delegating_constructors) && __cpp_delegating_constructors >= 200604L) /* v3.6 */ || \
		__has_feature(cxx_delegating_constructors)					     /* v3.0 */

#		define Z_COMPILER_HAS_CPP11_DELEGATING_CONSTRUCTORS 1 /* v3.0 (N-S-T) */
#	endif

#	if __has_feature(cxx_deleted_functions) /* v2.7 */
#		define Z_COMPILER_HAS_CPP11_DELETED_FUNCTION 1 /* v2.6 (S), v2.9 (S) */
#	endif

#	if	__has_feature(cxx_defaulted_functions) /* v3.1 */ || \
		(Z_COMPILER_VERSION == Z_VERSION(3,0,0) && __cplusplus >= 201103L)

#		define Z_COMPILER_HAS_CPP11_EXPLICITLY_DEFAULTED_SPECIAL_MEMBER_FUNCTION 1 /* v3.0 (N-S-T) */
#	endif

#	if	(defined(__cpp_variadic_templates) && __cpp_variadic_templates >= 200704L) /* v3.4 */ || \
		__has_feature(cxx_variadic_templates)					   /* v2.9 */

#		define Z_COMPILER_HAS_CPP11_EXTENDED_VARIADIC_TEMPLATE_TEMPLATE_PARAMETERS 1 /* v2.9 (S)   */
#		define Z_COMPILER_HAS_CPP11_VARIADIC_TEMPLATE				   1 /* v2.9 (N-S) */
#		define Z_COMPILER_HAS_CPP11_OPERATOR_CASE_SIZEOF_PARAMETER_PACK		   1 /* v2.9 (S)   */
#	endif

#	if __has_feature(cxx_strong_enums) /* v2.9 */
#		define Z_COMPILER_HAS_CPP11_FIXED_ENUMERATION  1 /* v2.9 (S) */
#		define Z_COMPILER_HAS_CPP11_SCOPED_ENUMERATION 1 /* v2.9 (S) */
#	endif

	/*-----------------------------------------------------------------------.
	| NOTE: Inheriting constructors seem to work in v3.0 (but not in v3.1 or |
	| v3.2). However, since the implementation of that version is perhaps	 |
	| unstable, Z only detects this feature using the appropriate macros.	 |
	'=======================================================================*/
#	if	(defined(__cpp_inheriting_constructors) && __cpp_inheriting_constructors >= 200802L) /* v3.6 */ || \
		__has_feature(cxx_inheriting_constructors)					     /* v3.3 */

#		define Z_COMPILER_HAS_CPP11_INHERITING_CONSTRUCTORS 1 /* v3.3 (N-S-T) */
#	endif

	/*------------------------------------------------------.
	| NOTE: According to Clang's sources, inline namespaces |
	| seem to be implemented since v2.8.			|
	'======================================================*/
#	if __has_feature(cxx_inline_namespaces) /* v2.8 */
#		define Z_COMPILER_HAS_CPP11_INLINE_NAMESPACE 1 /* v2.9 (S) */
#	endif

#	if	(defined(__cpp_lambdas) && __cpp_lambdas >= 200907L) /* v3.4 */ || \
		__has_feature(cxx_lambdas)			     /* v3.1 */

#		define Z_COMPILER_HAS_CPP11_LAMBDA 1 /* v3.1 (N-S-T) */
#	endif

#	if	(defined(__cpp_range_based_for) && __cpp_range_based_for >= 200907L) /* v3.6 */ || \
		__has_feature(cxx_range_for)					     /* v3.0 */

#		define Z_COMPILER_HAS_CPP11_RANGE_BASED_FOR 1 /* v3.0 (N-S-T) */
#	endif

#	if	(defined(__cpp_ref_qualifiers) && __cpp_ref_qualifiers >= 200710L) /* v3.6 */ || \
		__has_feature(cxx_reference_qualified_functions)		   /* v2.9 */

#		define Z_COMPILER_HAS_CPP11_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION 1 /* v2.9 (N-S) */
#	endif

#	if __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)
#		define Z_COMPILER_HAS_CPP11_RIGHT_ANGLE_BRACKETS		  1 /* v2.6 (S), v2.9 (S) */
#		define Z_COMPILER_HAS_CPP11_TRAILING_COMMA_ALLOWED_IN_ENUMERATION 1 /* v2.6?		  */
#	endif

#	if	(defined(__cpp_rvalue_references) && __cpp_rvalue_references >= 200610L) /* v3.4 */ || \
		__has_feature(cxx_rvalue_references)					 /* v2.9 */

#		define Z_COMPILER_HAS_CPP11_RVALUE_REFERENCE 1 /* v2.9 (N-S) */
#	endif

	/*----------------------------------------------------------------------------.
	| NOTE: According to Clang's documentation, the standardized attribute syntax |
	| was added in v3.3, but this feature seems to have been present since v2.7.  |
	| The [[carries_dependency]] attribute is recognized but has no effect, and   |
	| its use within a parameter-declaration did not fully conform to the C++11   |
	| standard until v3.1.							      |
	'============================================================================*/
#	if	(defined(__cpp_attributes) && __cpp_attributes >= 200809L) /* v3.4 */ || \
		__has_feature(cxx_attributes)				   /* v2.7 */

#		define Z_COMPILER_HAS_CPP11_STANDARDIZED_ATTRIBUTE_SYNTAX 1 /* v2.7?, v3.3 (N-S) */
#		define Z_COMPILER_HAS_CPP11_ATTRIBUTE_NORETURN		  1 /* v2.7?, v3.3 (N-S) */

#		if Z_COMPILER_VERSION >= Z_VERSION(3,1,0)
#			define Z_COMPILER_HAS_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY 1 /* v3.1 (T), v3.3 (N-S) */
#		endif
#	endif

	/*-----------------------------------------------------------------------------.
	| NOTE: Since v9.0, static assertions compile without warnings in any version  |
	| of C++ when the MSVC compatibility mode is enabled. However, Z only detects  |
	| this feature using the appropriate macros, as this behaviour could change in |
	| future versions of Clang.						       |
	'=============================================================================*/
#	if	(defined(__cpp_static_assert) && __cpp_static_assert >= 200410L) /* v3.4 */ || \
		__has_feature(cxx_static_assert)				 /* v2.7 */

#		define Z_COMPILER_HAS_CPP11_STATIC_ASSERTION 1 /* v2.6 (S), v2.9 (S) */
#	endif

	/*-----------------------------------------------------------------------------.
	| IMPORTANT:
	'=============================================================================*/
#	if defined(__cpp_threadsafe_static_init) && __cpp_threadsafe_static_init >= 200806L /* v5.0 */
#		define Z_COMPILER_HAS_CPP11_THREAD_SAFE_STATIC_INITIALIZATION 1 /* v2.6?, v2.9 (S*) */
#	endif

#	if __has_feature(cxx_trailing_return) /* v2.9 */
#		define Z_COMPILER_HAS_CPP11_TRAILING_RETURN_TYPE 1 /* v2.9 (S) */
#	endif

#	if	(defined(__cpp_alias_templates) && __cpp_alias_templates >= 200704L) /* v3.6 */ || \
		__has_feature(cxx_alias_templates)				     /* v3.0 */

#		define Z_COMPILER_HAS_CPP11_TYPE_ALIAS		1 /* v3.0 (N-S-T) */
#		define Z_COMPILER_HAS_CPP11_TYPE_ALIAS_TEMPLATE 1 /* v3.0 (N-S-T) */
#	endif

#	if __has_feature(cxx_unrestricted_unions) /* v3.1 */
#		define Z_COMPILER_HAS_CPP11_UNRESTRICTED_UNION 1 /* v3.0 (T?), v3.1 (N-S) *//* TODO: More tests. */
#	endif

#	if __has_feature(cxx_nullptr) /* v3.0 */
#		define Z_COMPILER_HAS_CPP11_LITERAL_NULLPTR 1 /* v3.0 (N-S-T) */
#	endif

#	if	(defined(__cpp_raw_strings) && __cpp_raw_strings >= 200710L) /* v3.4 */ || \
		__has_feature(cxx_raw_string_literals)			     /* v3.1 */ || \
		(Z_COMPILER_VERSION == Z_VERSION(3,0,0) && __cplusplus >= 201103L)

#		define Z_COMPILER_HAS_CPP11_LITERAL_RAW_STRING 1 /* v3.0 (N-S-T) */
#	endif

#	if	(defined(__cpp_user_defined_literals) && __cpp_user_defined_literals >= 200809L) /* v3.4 */ || \
		__has_feature(cxx_user_literals)						 /* v3.1 */

#		define Z_COMPILER_HAS_CPP11_LITERAL_USER_DEFINED 1 /* v3.1 (N-S-T) */
#	endif

#	if	(defined(__cpp_unicode_literals) && __cpp_unicode_literals >= 200710L) /* v3.4 */ || \
		__has_feature(cxx_unicode_literals)				       /* v3.1 */ || \
		(Z_COMPILER_VERSION == Z_VERSION(3,0,0) && __cplusplus >= 201103L)

#		define Z_COMPILER_HAS_CPP11_LITERAL_UTF8_STRING 1 /* v3.0 (N-S-T) */
#	endif

#	if	__has_feature(cxx_alignof) /* v3.6 */ ||   \
		(Z_COMPILER_VERSION >= Z_VERSION(3,0,0) && \
		 Z_COMPILER_VERSION <  Z_VERSION(3,6,0) && \
		 __cplusplus	    >= 201103L)

#		define Z_COMPILER_HAS_CPP11_OPERATOR_ALIGNOF 1 /* v3.0 (N-S-T), v3.3 (S) */
#	endif

#	if __has_feature(cxx_noexcept) /* v3.0 */
#		define Z_COMPILER_HAS_CPP11_OPERATOR_NOEXCEPT  1 /* v2.9 (S), v3.0 (N-S) */
#		define Z_COMPILER_HAS_CPP11_SPECIFIER_NOEXCEPT 1 /* v2.9 (S), v3.0 (N-S) */
#	endif

#	if __has_feature(cxx_alignas) /* v3.0 */
#		define Z_COMPILER_HAS_CPP11_SPECIFIER_ALIGNAS 1 /* v3.0 (N-S-T), v3.3 (N-S) */
#	endif

#	if	(defined(__cpp_constexpr) && __cpp_constexpr >= 200704L) /* v3.4 */ || \
		__has_feature(cxx_constexpr)				 /* v3.1 */

#		define Z_COMPILER_HAS_CPP11_SPECIFIER_CONSTEXPR 1 /* v3.1 (N-S-T) */
#	endif

#	if	(defined(__cpp_decltype) && __cpp_decltype >= 200707L) /* v3.4 */ || \
		__has_feature(cxx_decltype)			       /* v2.7 */

#		define Z_COMPILER_HAS_CPP11_SPECIFIER_DECLTYPE 1 /* v2.6 (S), v2.9 (S) */
#	endif

#	if __has_feature(cxx_override_control) /* v3.0 */
#		define Z_COMPILER_HAS_CPP11_SPECIFIER_FINAL    1 /* v3.0 (S-T)   */
#		define Z_COMPILER_HAS_CPP11_SPECIFIER_OVERRIDE 1 /* v3.0 (N-S-T) */
#	endif

#	if __has_feature(cxx_decltype_incomplete_return_types) /* v3.1 */
#		define Z_COMPILER_HAS_CPP11_SPECIFIER_CASE_DECLTYPE_INCOMPLETE_RETURN_TYPE 1 /* v3.1 (S-T) */
#	endif

	/*-------------------------------------------------------.
	| IMPORTANT: thread_local support requires a C++ runtime |
	| library providing the __cxa_thread_atexit function.	 |
	'=======================================================*/
#	if __has_feature(cxx_thread_local) /* v3.3 */
#		define Z_COMPILER_HAS_CPP11_STORAGE_CLASS_THREAD_LOCAL 1 /* v3.3 (N-S-T) */
#	endif

#	if	(defined(__cpp_unicode_characters) && __cpp_unicode_characters >= 200704L) /* v3.4 */ || \
		(Z_COMPILER_VERSION < Z_VERSION(3,4,0) && __cplusplus >= 201103L)

		// TODO: Fails with -fms-compatibility on Apple Clang (Z_z_HAS_MSVC_COMPATIBILITY)
#		if !Z_z_HAS_MSVC_COMPATIBILITY
#			define Z_COMPILER_HAS_CPP11_TYPE_CHAR16_T 1 /* v2.9 (S), v3.0 (N) */
#			define Z_COMPILER_HAS_CPP11_TYPE_CHAR32_T 1 /* v2.9 (S), v3.0 (N) */
#		endif
#	endif

	/* MARK: - Language: C++14 */

#	if	(defined(__cpp_digit_separators) && __cpp_digit_separators >= 201309L) /* v3.6 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,4,0) &&					     \
		 Z_COMPILER_VERSION <  Z_VERSION(3,6,0) &&					     \
		 __cplusplus	    >= 201305L)

#		define Z_COMPILER_HAS_CPP14_APOSTROPHE_AS_DIGIT_SEPARATOR 1 /* v3.4 (N-S-T) */
#	endif

#	if	(defined(__cpp_constexpr) && __cpp_constexpr >= 201304L) /* v3.4 */ || \
		__has_feature(cxx_relaxed_constexpr)			 /* v3.4 */

#		define Z_COMPILER_HAS_CPP14_CONSTEXPR_FUNCTION 1 /* v3.4 (N-S-T) */
#	endif

#	if __has_feature(cxx_contextual_conversions) /* v3.4 */
#		define Z_COMPILER_HAS_CPP14_CONTEXTUAL_CONVERSION 1 /* v3.4 (S-T) */
#	endif

#	if	(defined(__cpp_aggregate_nsdmi) && __cpp_aggregate_nsdmi >= 201304L) /* v3.4 */ || \
		__has_feature(cxx_aggregate_nsdmi)				     /* v3.3 */

#		define Z_COMPILER_HAS_CPP14_DEFAULT_MEMBER_INITIALIZER_FOR_AGGREGATE 1 /* v3.3 (N-S-T) */
#	endif

#	if	(defined(__cpp_generic_lambdas) && __cpp_generic_lambdas >= 201304L) /* v3.4 */ || \
		__has_feature(cxx_generic_lambdas)				     /* v3.5 */

#		define Z_COMPILER_HAS_CPP14_GENERIC_LAMBDA 1 /* v3.4 (N-S-T) */
#	endif

#	if	(defined(__cpp_init_captures) && __cpp_init_captures >= 201304L) /* v3.4 */ || \
		__has_feature(cxx_init_captures)				 /* v3.4 */

#		define Z_COMPILER_HAS_CPP14_INITIALIZED_LAMBDA_CAPTURE 1 /* v3.4 (N-S-T) */
#	endif

	/*-------------------------------------------------------------.
	| NOTE: Based on testing, the return type deduction for normal |
	| functions seems to work in v3.3, but the documentation for   |
	| that version specifies that the implementation is partial.   |
	'=============================================================*/
#	if	(defined(__cpp_return_type_deduction) && __cpp_return_type_deduction >= 201304L) /* v3.4 */   || \
		__has_feature(cxx_return_type_deduction)					 /* v3.4 *//* || \
		(Z_COMPILER_VERSION == Z_VERSION(3,3,0) && __cplusplus >= 201305L)*/

#		define Z_COMPILER_HAS_CPP14_RETURN_TYPE_DEDUCTION_FOR_NORMAL_FUNCTION 1 /* v3.3 (T?), v3.4 (N-S-T) */
#	endif

	/*---------------------------------------------------------------------.
	| IMPORTANT: In v3.7 and later, sized deallocation is only enabled if  |
	| the user passes the -fsized-deallocation flag. The user must supply  |
	| definitions of the sized deallocation functions, either by providing |
	| them explicitly or by using a C++ standard library that does.	       |
	'=====================================================================*/
#	if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L /* v3.6 */
#		define Z_COMPILER_HAS_CPP14_SIZED_DEALLOCATION 1 /* v3.4 (N-S) *//* TODO: Test. */
#	endif

	/*----------------------------------------------------------------------.
	| BUG: Variable templates may produce warnings between v3.4 and v3.4.2. |
	| e.g.: <https://bugs.llvm.org/show_bug.cgi?id=19558>			|
	'======================================================================*/
#	if	Z_COMPILER_VERSION >= Z_VERSION(3,5,0) &&						  \
		((defined(__cpp_variable_templates) && __cpp_variable_templates >= 201304L) /* v3.4 */ || \
		 __has_feature(cxx_variable_templates))					    /* v3.4 */

#		define Z_COMPILER_HAS_CPP14_VARIABLE_TEMPLATE 1 /* v3.4 (N-S-Tw), v3.5 (T!) */
#	endif

	/*----------------------------------------------------------------------------.
	| BUG: Since v3.6, __has_cpp_attribute(deprecated) is >= 201309L in C++11 and |
	| later, but starting from v3.7 [[deprecated]] generates warnings in C++11.   |
	| [[deprecated]] compiles without warnings in C++11 between v3.4 and v3.6.2.  |
	'============================================================================*/
#	if	(Z_z_HAS_CPP_ATTRIBUTE(deprecated) >= 201309L /* v3.6 */ && __cplusplus >= 201402L) || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,4,0) &&					       \
		 Z_COMPILER_VERSION <= Z_VERSION(3,6,2) &&					       \
		 __cplusplus >= 201103L)

#		define Z_COMPILER_HAS_CPP14_ATTRIBUTE_DEPRECATED 1 /* v3.4 (N-S-T) */
#	endif

#	if	(defined(__cpp_binary_literals) && __cpp_binary_literals >= 201304L) /* v3.4 */ || \
		__has_feature(cxx_binary_literals)				     /* v3.3 */

#		define Z_COMPILER_HAS_CPP14_LITERAL_BINARY_INTEGRAL 1 /* v2.9 (S), v3.3 (N-T!) */
#	endif

#	if	(defined(__cpp_decltype_auto) && __cpp_decltype_auto >= 201304L) /* v3.4 */ || \
		__has_feature(cxx_decltype_auto)				 /* v3.5 */ || \
		(Z_COMPILER_VERSION == Z_VERSION(3,3,0) && __cplusplus >= 201305L)

#		define Z_COMPILER_HAS_CPP14_SPECIFIER_CASE_DECLTYPE_AUTO 1 /* v3.3 (N-S-T) */
#	endif

	/* MARK: - Language: C++17 */

#	if __cplusplus >= 201103L
#		if Z_COMPILER_VERSION >= Z_VERSION(3,8,0)
#			define Z_COMPILER_HAS_CPP17_AUTO_DEDUCTION_FROM_LIST_INITIALIZATION 1 /* v3.8 (S-T) */
#		endif

#		if __cplusplus >= 201406L
#			if Z_COMPILER_VERSION >= Z_VERSION(3,5,0)
#				define Z_COMPILER_HAS_CPP17_TYPENAME_IN_TEMPLATE_TEMPLATE_PARAMETER 1 /* v3.5 (N-S-T) */

#				if Z_COMPILER_VERSION >= Z_VERSION(3,6,0)
#					define Z_COMPILER_HAS_CPP17_LITERAL_UTF8_CHARACTER 1 /* v3.6 (N-S-T) */

#					if Z_COMPILER_VERSION >= Z_VERSION(3,9,0)
#						define Z_COMPILER_HAS_CPP17_ATTRIBUTE_USING_PREFIX			     1 /* v3.9 (S-T)   */
#						define Z_COMPILER_HAS_CPP17_DIRECT_LIST_INITIALIZATION_FOR_FIXED_ENUMERATION 1 /* v3.9 (N-S-T) */

						/*-----------------------------------------------------------------.
						| NOTE: In v3.9 and v3.9.1, selection statements with initializer  |
						| do not seem to generate warnings in any version of C++. However, |
						| Z only recognizes these features in C++17 and later.		   |
						'=================================================================*/
#						define Z_COMPILER_HAS_CPP17_IF_WITH_INITIALIZER	    1 /* v3.9 (S-T) */
#						define Z_COMPILER_HAS_CPP17_SWITCH_WITH_INITIALIZER 1 /* v3.9 (S-T) */

#						if Z_COMPILER_VERSION >= Z_VERSION(4,0,0)
#							define Z_COMPILER_HAS_CPP17_EXPRESSION_EVALUATION_ORDER		       1 /* v4.0 (S) *//* TODO: Test. */
#							define Z_COMPILER_HAS_CPP17_REMOVAL_OF_DYNAMIC_EXCEPTION_SPECIFICATION 1 /* v4.0 (S-T) */
#						endif
#					endif
#				endif
#			endif

#			if Z_z_HAS_CPP_ATTRIBUTE(fallthrough) >= 201603L /* v3.9 */
#				define Z_COMPILER_HAS_CPP17_ATTRIBUTE_FALLTHROUGH 1 /* v3.9 (N-S-T) */
#			endif

#			if Z_z_HAS_CPP_ATTRIBUTE(maybe_unused) >= 201603L /* v3.9 */
#				define Z_COMPILER_HAS_CPP17_ATTRIBUTE_MAYBE_UNUSED 1 /* v3.9 (N-S-T) */
#			endif

#			if Z_z_HAS_CPP_ATTRIBUTE(nodiscard) >= 201603L /* v3.9 */
#				define Z_COMPILER_HAS_CPP17_ATTRIBUTE_NODISCARD 1 /* v3.9 (N-S-T) */
#			endif
#		endif
#	endif

#	if	(defined(__cpp_aggregate_bases) && __cpp_aggregate_bases >= 201603L) /* v4.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,9,0) &&					   \
		 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&					   \
		 __cplusplus	    >= 201406L)

#		define Z_COMPILER_HAS_CPP17_AGGREGATE_INITIALIZATION_FOR_DERIVED_CLASS 1 /* v3.9 (N-S-T) */
#	endif

	/*---------------------------------------------------------------.
	| NOTE: Attributes for enumerators and namespaces do not seem to |
	| generate warnings in C++11 and C++14 between v3.6 and v5.0.2.  |
	| However, Z only recognizes these features in C++17 and later.	 |
	'===============================================================*/
#	if	(defined(__cpp_enumerator_attributes) && __cpp_enumerator_attributes >= 201411L) /* v4.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,6,0) &&						       \
		 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&						       \
		 __cplusplus	    >= 201406L)

#		define Z_COMPILER_HAS_CPP17_ATTRIBUTES_FOR_ENUMERATOR 1 /* v3.6 (N-S-T) */
#	endif

#	if	(defined(__cpp_namespace_attributes) && __cpp_namespace_attributes >= 201411L) /* v4.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,6,0) &&						     \
		 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&						     \
		 __cplusplus	    >= 201406L)

#		define Z_COMPILER_HAS_CPP17_ATTRIBUTES_FOR_NAMESPACE 1 /* v3.6 (N-S-T) */
#	endif

#	if	(defined(__cpp_if_constexpr) && __cpp_if_constexpr >= 201606L) /* v4.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,9,0) &&				     \
		 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&				     \
		 __cplusplus	    >= 201406L)

#		define Z_COMPILER_HAS_CPP17_CONSTEXPR_IF 1 /* v3.9 (S-T) */
#	endif

#	if defined(__cpp_constexpr) && __cpp_constexpr >= 201603L /* v5.0 */
#		define Z_COMPILER_HAS_CPP17_CONSTEXPR_LAMBDA 1 /* v5.0 (S-T) */
#	endif

#	if defined(__cpp_deduction_guides) && __cpp_deduction_guides >= 201703L /* TODO: Investigate macro value. */
#		define Z_COMPILER_HAS_CPP17_DEDUCTION_GUIDES_FOR_CLASS_TEMPLATE 1 /* TODO: Investigate acceptable version. */
#	endif

#	if	(defined(__cpp_range_based_for) && __cpp_range_based_for >= 201603L) /* v4.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,9,0) &&					   \
		 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&					   \
		 __cplusplus	    >= 201406L)

#		define Z_COMPILER_HAS_CPP17_DIFFERING_BEGIN_AND_END_TYPES_IN_RANGE_BASED_FOR 1 /* v3.9 (N-S-T) */
#	endif

#	if defined(__cpp_fold_expressions) && __cpp_fold_expressions >= 201411L /* v4.0 */
#		define Z_COMPILER_HAS_CPP17_FOLD_EXPRESSION 1 /* v3.6 (N-S) */

#		if __cpp_fold_expressions >= 201603L /* v4.0 */
#			define Z_COMPILER_HAS_CPP17_SAFE_UNARY_FOLD_EXPRESSION 1 /* v3.9 (N-S) */
#		endif
#	endif

#	if	(defined(__cpp_guaranteed_copy_elision) && __cpp_guaranteed_copy_elision >= 201606L) /* v7.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(4,0,0) &&							   \
		 Z_COMPILER_VERSION <  Z_VERSION(7,0,0) &&							   \
		 __cplusplus	    >= 201406L)

#		define Z_COMPILER_HAS_CPP17_GUARANTEED_COPY_ELISION 1 /* v4.0 (S) *//* TODO: Test. */
#	endif

#	if	(defined(__cpp_inheriting_constructors) && __cpp_inheriting_constructors >= 201511L) /* v4.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,9,0) &&							   \
		 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&							   \
		 __cplusplus	    >= 201103L)

#		define Z_COMPILER_HAS_CPP17_INHERITING_CONSTRUCTORS 1 /* v3.9 (S-T) */
#	endif

#	if	(defined(__cpp_inline_variables) && __cpp_inline_variables >= 201606L) /* v4.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,9,0) &&					     \
		 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&					     \
		 __cplusplus	    >= 201406L)

#		define Z_COMPILER_HAS_CPP17_INLINE_VARIABLE 1 /* v3.9 (S-T) */
#	endif

#	if	(defined(__cpp_capture_star_this) && __cpp_capture_star_this >= 201603L) /* v4.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,9,0) &&					       \
		 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&					       \
		 __cplusplus	    >= 201406L)

#		define Z_COMPILER_HAS_CPP17_LAMBDA_CAPTURE_OF_STAR_THIS_BY_VALUE 1 /* v3.9 (N-S-T) */
#	endif

#	if	(defined(__cpp_nested_namespace_definitions) && __cpp_nested_namespace_definitions >= 201411L) /* v4.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,6,0) &&								     \
		 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&								     \
		 __cplusplus	    >= 201406L)

#		define Z_COMPILER_HAS_CPP17_NESTED_NAMESPACE_DEFINITION 1 /* v3.6 (N-S-T) */
#	endif

#	if defined(__cpp_noexcept_function_type) && __cpp_noexcept_function_type >= 201510L /* v4.0 */
#		define Z_COMPILER_HAS_CPP17_NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE 1 /* v4.0 (S-T) */
#	endif

	/*------------------------------------------------------------------.
	| NOTE: According to Clang's documentation, constant evaluation for |
	| all non-type template arguments was added in v3.6, but tests show |
	| that non-generic lambdas with no lambda-capture (i.e. convertible |
	| to pointer to function with external linkage) were not accepted   |
	| as non-type template arguments until v4.0.			    |
	'==================================================================*/
#	if defined(__cpp_nontype_template_args) && __cpp_nontype_template_args >= 201411L /* v4.0 */
#		define Z_COMPILER_HAS_CPP17_NON_TYPE_TEMPLATE_ARGUMENTS 1 /* v3.6 (N-S), v4.0 (T) */
#	endif

#	if	(defined(__cpp_nontype_template_parameter_auto) && __cpp_nontype_template_parameter_auto >= 201606L) /* v7.0 */ || \
		(defined(__cpp_template_auto		      ) && __cpp_template_auto			 >= 201606L) /* v4.0 */

#		define Z_COMPILER_HAS_CPP17_NON_TYPE_TEMPLATE_PARAMETER_WITH_AUTO_TYPE 1 /* v4.0 (S-T) */
#	endif

#	if defined(__cpp_aligned_new) && __cpp_aligned_new >= 201606L /* v4.0 */
#		define Z_COMPILER_HAS_CPP17_OVER_ALIGNED_DYNAMIC_MEMORY_ALLOCATION 1 /* v4.0 (S) *//* TODO: Test. */
#	endif

#	define Z_COMPILER_HAS_CPP17_REMOVAL_OF_BOOL_INCREMENT 1 /* v3.8 (S-Tr) */

#	ifndef Z_COMPILER_HAS_C_STORAGE_CLASS_REGISTER
#		define Z_COMPILER_HAS_CPP17_REMOVAL_OF_REGISTER_AS_STORAGE_CLASS 1 /* v3.8 (S-Tr) */
#	endif

#	ifndef Z_COMPILER_HAS_C89_TRIGRAPHS
#		define Z_COMPILER_HAS_CPP17_REMOVAL_OF_TRIGRAPHS 1 /* v3.5 (N-S-Tr) */
#	endif

#	if	(defined(__cpp_static_assert) && __cpp_static_assert >= 201411L) /* v4.0 */ || \
		(Z_COMPILER_VERSION >= Z_VERSION(3,5,0) &&				       \
		 Z_COMPILER_VERSION <  Z_VERSION(4,0,0) &&				       \
		 __cplusplus	    >= 201406L)

#		define Z_COMPILER_HAS_CPP17_STATIC_ASSERTION_WITH_NO_MESSAGE 1 /* v3.5 (N-S-T) */
#	endif

#	if defined(__cpp_structured_bindings) && __cpp_structured_bindings >= 201606L /* v4.0 */
#		define Z_COMPILER_HAS_CPP17_STRUCTURED_BINDING 1 /* v4.0 (S) */
#	endif

#	if defined(__cpp_template_template_args) && __cpp_template_template_args >= 201611L /* v7.0 */
#		define Z_COMPILER_HAS_CPP17_TEMPLATE_TEMPLATE_ARGUMENT_MATCHING 1
#	endif

#	if defined(__cpp_variadic_using) && __cpp_variadic_using >= 201611L /* v4.0 */
#		define Z_COMPILER_HAS_CPP17_VARIADIC_USING 1 /* v4.0 (S-T) */
#	endif

#	ifdef Z_COMPILER_HAS_C99_LITERAL_HEXADECIMAL_FLOATING_POINT
#		define Z_COMPILER_HAS_CPP17_LITERAL_HEXADECIMAL_FLOATING_POINT 1 /* v3.9 (T!) */
#	endif

#	ifdef Z_COMPILER_HAS_CLANG_C_PREPROCESSOR_OPERATOR_HAS_INCLUDE
#		define Z_COMPILER_HAS_CPP17_PREPROCESSOR_OPERATOR_HAS_INCLUDE 1 /* v2.7 */
#	endif

/*#	define Z_COMPILER_HAS_CPP17_IGNORING_OF_UNKNOWN_ATTRIBUTES*/ /* Always generate warnings. */

#endif

/* MARK: - Language: Implementation-defined */

#if (~0 >> 1) == ~0
#	define Z_COMPILER_HAS_ARITHMETIC_RIGHT_SHIFT 1
#endif

/* MARK: - Non-standard language: Attributes */

#if __has_attribute(alias)
#	define Z_COMPILER_ATTRIBUTE_ALIAS(name) __attribute__((alias(name))) /* v2.6 */
#endif

#if __has_attribute(dllexport)
#	define Z_COMPILER_ATTRIBUTE_API_EXPORT __declspec(dllexport) /* v2.6 */
#endif

#if __has_attribute(dllimport)
#	define Z_COMPILER_ATTRIBUTE_API_IMPORT __declspec(dllimport) /* v2.6 */
#endif

#if __has_attribute(stdcall)
#	define Z_COMPILER_ATTRIBUTE_MICROSOFT_STD_CALL __attribute__((stdcall)) /* TODO */
#endif

#if __has_attribute(always_inline)
#	define Z_COMPILER_ATTRIBUTE_ALWAYS_INLINE __inline__ __attribute__((always_inline)) /* v2.6 */
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

/*#define Z_COMPILER_ATTRIBUTE_EBCO*/
/*#define Z_COMPILER_ATTRIBUTE_API_WEAK_EXPORT*/

/* MARK: - Non-standard language: Structure padding */

#if __has_attribute(packed)				     /* v2.6 */
#	define Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_TYPE __attribute__((packed))
#	define Z_COMPILER_PACKED_NAMED_UNION_BEFORE_TYPE     __attribute__((packed))
#	define Z_COMPILER_PACKED_STRUCTURE_AFTER_BODY	     __attribute__((packed))
#	define Z_COMPILER_PACKED_UNION_AFTER_BODY	     __attribute__((packed))
#endif

/*#define Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_STRUCT*/
/*#define Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_BODY*/
/*#define Z_COMPILER_PACKED_NAMED_STRUCTURE_AFTER_BODY*/
/*#define Z_COMPILER_PACKED_NAMED_UNION_BEFORE_UNION*/
/*#define Z_COMPILER_PACKED_NAMED_UNION_BEFORE_BODY*/
/*#define Z_COMPILER_PACKED_NAMED_UNION_AFTER_BODY*/
/*#define Z_COMPILER_PACKED_STRUCTURE_BEFORE_STRUCT*/
/*#define Z_COMPILER_PACKED_STRUCTURE_BEFORE_BODY*/
/*#define Z_COMPILER_PACKED_UNION_BEFORE_UNION*/
/*#define Z_COMPILER_PACKED_UNION_BEFORE_BODY*/

/* MARK: - Built-ins: Types and literal suffixes */

#ifdef __UINT8_TYPE__
#	define Z_COMPILER_TYPE_UINT8 __typeof(__extension__ (__UINT8_TYPE__)1)
#endif

#ifdef __INT8_TYPE__ /* v2.6 */
#	define Z_COMPILER_TYPE_SINT8 __typeof(__extension__ (__INT8_TYPE__)1)

#	ifndef __UINT8_TYPE__
#		define Z_COMPILER_TYPE_UINT8 __typeof(__extension__ (unsigned __INT8_TYPE__)1)
#	endif
#endif

#ifdef __UINT16_TYPE__
#	define Z_COMPILER_TYPE_UINT16 __typeof(__extension__ (__UINT16_TYPE__)1)
#endif

#ifdef __INT16_TYPE__ /* v2.6 */
#	define Z_COMPILER_TYPE_SINT16 __typeof(__extension__ (__INT16_TYPE__)1)

#	ifndef __UINT16_TYPE__
#		define Z_COMPILER_TYPE_UINT16 __typeof(__extension__ (unsigned __INT16_TYPE__)1)
#	endif
#endif

#ifdef __UINT32_TYPE__
#	define Z_COMPILER_TYPE_UINT32 __typeof(__extension__ (__UINT32_TYPE__)1)
#endif

#ifdef __INT32_TYPE__ /* v2.6 */
#	define Z_COMPILER_TYPE_SINT32 __typeof(__extension__ (__INT32_TYPE__)1)

#	ifndef __UINT32_TYPE__
#		define Z_COMPILER_TYPE_UINT32 __typeof(__extension__ (unsigned __INT32_TYPE__)1)
#	endif
#endif

#ifdef __UINT64_TYPE__
#	define Z_COMPILER_TYPE_UINT64 __typeof(__extension__ (__UINT64_TYPE__)1)
#endif

#ifdef __INT64_TYPE__ /* v2.6 */
#	define Z_COMPILER_TYPE_SINT64 __typeof(__extension__ (__INT64_TYPE__)1)

#	ifndef __UINT64_TYPE__
#		define Z_COMPILER_TYPE_UINT64 __typeof(__extension__ (unsigned __INT64_TYPE__)1)
#	endif
#endif

#ifdef __SIZEOF_INT128__ /* v3.3 */
#	define Z_COMPILER_TYPE_UINT128 __uint128_t /* v2.6 */
#	define Z_COMPILER_TYPE_SINT128 __int128_t  /* v2.6 */
#endif

#define Z_COMPILER_TYPE_VAL __builtin_va_list /* v2.6 */

#ifdef __UINT16_C_SUFFIX__ /* v3.5 */
#	define Z_COMPILER_LITERAL_UINT16(number) (__extension__ Z_JOIN_2(number, __UINT16_C_SUFFIX__))
#endif

#ifdef __INT16_C_SUFFIX__ /* v3.5 */
#	define Z_COMPILER_LITERAL_SINT16(number) (__extension__ Z_JOIN_2(number, __INT16_C_SUFFIX__))
#endif

#ifdef __UINT32_C_SUFFIX__ /* v3.5 */
#	define Z_COMPILER_LITERAL_UINT32(number) (__extension__ Z_JOIN_2(number, __UINT32_C_SUFFIX__))
#endif

#ifdef __INT32_C_SUFFIX__ /* v3.5 */
#	define Z_COMPILER_LITERAL_SINT32(number) (__extension__ Z_JOIN_2(number, __INT32_C_SUFFIX__))
#endif

#ifdef __UINT64_C_SUFFIX__ /* v3.5 */
#	define Z_COMPILER_LITERAL_UINT64(number) (__extension__ Z_JOIN_2(number, __UINT64_C_SUFFIX__))
#endif

#ifdef __INT64_C_SUFFIX__ /* v2.7 */
#	define Z_COMPILER_LITERAL_SINT64(number) (__extension__ Z_JOIN_2(number, __INT64_C_SUFFIX__))

#	ifndef __UINT64_C_SUFFIX__
#		define Z_COMPILER_LITERAL_SINT64(number) (__extension__ Z_JOIN_2(Z_SUFFIX_U(number), __INT64_C_SUFFIX__))
#	endif
#endif

/*#define Z_COMPILER_TYPE_UINT24*/
/*#define Z_COMPILER_TYPE_SINT24*/
/*#define Z_COMPILER_TYPE_UINT40*/
/*#define Z_COMPILER_TYPE_SINT40*/
/*#define Z_COMPILER_TYPE_UINT48*/
/*#define Z_COMPILER_TYPE_SINT48*/
/*#define Z_COMPILER_TYPE_UINT56*/
/*#define Z_COMPILER_TYPE_SINT56*/
/*#define Z_COMPILER_TYPE_BFP16*/
/*#define Z_COMPILER_TYPE_BFP32*/
/*#define Z_COMPILER_TYPE_BFP64*/
/*#define Z_COMPILER_TYPE_BFP128*/
/*#define Z_COMPILER_TYPE_DFP32*/
/*#define Z_COMPILER_TYPE_DFP64*/
/*#define Z_COMPILER_TYPE_DFP128*/
/*#define Z_COMPILER_TYPE_X87_DE80*/
/*#define Z_COMPILER_TYPE_X87_DE96*/
/*#define Z_COMPILER_TYPE_X87_DE128*/
/*#define Z_COMPILER_TYPE_IBM_ED*/
/*#define Z_COMPILER_TYPE_BFLOAT16*/
/*#define Z_COMPILER_LITERAL_UINT8(number)*/
/*#define Z_COMPILER_LITERAL_SINT8(number)*/
/*#define Z_COMPILER_LITERAL_UINT24(number)*/
/*#define Z_COMPILER_LITERAL_SINT24(number)*/
/*#define Z_COMPILER_LITERAL_UINT40(number)*/
/*#define Z_COMPILER_LITERAL_SINT40(number)*/
/*#define Z_COMPILER_LITERAL_UINT48(number)*/
/*#define Z_COMPILER_LITERAL_SINT48(number)*/
/*#define Z_COMPILER_LITERAL_UINT56(number)*/
/*#define Z_COMPILER_LITERAL_SINT56(number)*/
/*#define Z_COMPILER_LITERAL_UINT128(number)*/
/*#define Z_COMPILER_LITERAL_SINT128(number)*/
/*#define Z_COMPILER_LITERAL_BFP16(number)*/
/*#define Z_COMPILER_LITERAL_BFP32(number)*/
/*#define Z_COMPILER_LITERAL_BFP64(number)*/
/*#define Z_COMPILER_LITERAL_BFP128(number)*/
/*#define Z_COMPILER_LITERAL_DFP32(number)*/
/*#define Z_COMPILER_LITERAL_DFP64(number)*/
/*#define Z_COMPILER_LITERAL_DFP128(number)*/
/*#define Z_COMPILER_LITERAL_X87_DE80(number)*/
/*#define Z_COMPILER_LITERAL_X87_DE96(number)*/
/*#define Z_COMPILER_LITERAL_X87_DE128(number)*/
/*#define Z_COMPILER_LITERAL_IBM_ED(number)*/
/*#define Z_COMPILER_LITERAL_BFLOAT16(number)*/

/* TODO */
/*#ifdef __FLOAT128__*/ /* v3.9 */
/*#	define Z_COMPILER_TYPE_FLOAT128 __float128*/ /* v3.9 */
/*#endif*/

/*#ifdef __ARM_FP16_FORMAT_IEEE
#endif*/

/* MARK: - Built-ins: Constants */

#ifdef __CHAR_BIT__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_CHAR_WIDTH __CHAR_BIT__
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

#if defined(__SIZEOF_INT__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_INT_SIZE __SIZEOF_INT__
#elif defined(_EM_WSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_INT_SIZE _EM_WSIZE
#endif

#ifdef _MIPS_SZINT /* v3.1 */
#	define Z_COMPILER_CONSTANT_INT_WIDTH _MIPS_SZINT
#endif

#ifdef __INT_MAX__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_SINT_MAXIMUM __INT_MAX__
#endif

#if defined(__SIZEOF_LONG__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_LONG_SIZE __SIZEOF_LONG__
#elif defined(_EM_LSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_LONG_SIZE _EM_LSIZE
#endif

#ifdef _MIPS_SZLONG /* v3.1 */
#	define Z_COMPILER_CONSTANT_LONG_WIDTH _MIPS_SZLONG
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

#ifdef __SIZEOF_WCHAR_T__ /* v2.8 */
#	define Z_COMPILER_CONSTANT_WCHAR_SIZE __SIZEOF_WCHAR_T__
#endif

#ifdef __WCHAR_WIDTH__  /* v2.7 */
#	define Z_COMPILER_CONSTANT_WCHAR_WIDTH __WCHAR_WIDTH__
#endif

#ifdef __WCHAR_MAX__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_WCHAR_MAXIMUM __WCHAR_MAX__
#endif

#ifdef __SIZEOF_SIZE_T__ /* v2.8 */
#	define Z_COMPILER_CONSTANT_SIZE_SIZE __SIZEOF_SIZE_T__
#endif

#ifdef __SIZE_WIDTH__ /* v2.7 */
#	define Z_COMPILER_CONSTANT_SIZE_WIDTH __SIZE_WIDTH__
#endif

#ifdef __SIZE_MAX__ /* v3.3 */
#	define Z_COMPILER_CONSTANT_USIZE_MAXIMUM __SIZE_MAX__
#endif

#ifdef __UINTMAX_WIDTH__ /* v3.5 */
#	define Z_COMPILER_CONSTANT_UINTMAX_WIDTH __UINTMAX_WIDTH__
#endif

#ifdef __UINTMAX_MAX__ /* v3.5 */
#	define Z_COMPILER_CONSTANT_UINTMAX_MAXIMUM __UINTMAX_MAX__
#endif

#ifdef __INTMAX_WIDTH__ /* v2.7 */
#	define Z_COMPILER_CONSTANT_SINTMAX_WIDTH __INTMAX_WIDTH__
#endif

#ifdef __INTMAX_MAX__ /* v2.6 */
#	define Z_COMPILER_CONSTANT_SINTMAX_MAXIMUM __INTMAX_MAX__
#endif

#ifdef __UINTPTR_WIDTH__ /* v3.5 */
#	define Z_COMPILER_CONSTANT_UINTPTR_WIDTH __UINTPTR_WIDTH__
#endif

#ifdef __UINTPTR_MAX__ /* v3.5 */
#	define Z_COMPILER_CONSTANT_UINTPTR_MAXIMUM __UINTPTR_MAX__
#endif

#ifdef __INTPTR_WIDTH__ /* v2.7 */
#	define Z_COMPILER_CONSTANT_SINTPTR_WIDTH __INTPTR_WIDTH__
#endif

#ifdef __INTPTR_MAX__ /* v3.5 */
#	define Z_COMPILER_CONSTANT_SINTPTR_MAXIMUM __INTPTR_MAX__
#endif

#if defined(__SIZEOF_FLOAT__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_FLOAT_SIZE __SIZEOF_FLOAT__
#elif defined(_EM_FSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_FLOAT_SIZE _EM_FSIZE
#endif

#if __has_builtin(__builtin_huge_valf)
#	define Z_COMPILER_CONSTANT_FLOAT_HUGE __builtin_huge_valf() /* v2.6 */
#endif

#if __has_builtin(__builtin_inff)
#	define Z_COMPILER_CONSTANT_FLOAT_INFINITY __builtin_inff() /* v2.6 */
#endif

#if __has_builtin(__builtin_nanf)
#	define Z_COMPILER_CONSTANT_FLOAT_QNAN __builtin_nanf("") /* v2.6 */
#endif

#if __has_builtin(__builtin_nansf)
#	define Z_COMPILER_CONSTANT_FLOAT_SNAN __builtin_nansf("") /* v2.6 */
#endif

#if defined(__SIZEOF_DOUBLE__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_DOUBLE_SIZE __SIZEOF_DOUBLE__
#elif defined(_EM_DSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_DOUBLE_SIZE _EM_DSIZE
#endif

#if __has_builtin(__builtin_huge_val)
#	define Z_COMPILER_CONSTANT_DOUBLE_HUGE __builtin_huge_val() /* v2.6 */
#endif

#if __has_builtin(__builtin_inf)
#	define Z_COMPILER_CONSTANT_DOUBLE_INFINITY __builtin_inf() /* v2.6 */
#endif

#if __has_builtin(__builtin_nan)
#	define Z_COMPILER_CONSTANT_DOUBLE_QNAN __builtin_nan("") /* v2.6 */
#endif

#if __has_builtin(__builtin_nans)
#	define Z_COMPILER_CONSTANT_DOUBLE_SNAN __builtin_nans("") /* v2.6 */
#endif

#ifdef __SIZEOF_LONG_DOUBLE__ /* v2.8 */
#	define Z_COMPILER_CONSTANT_LDOUBLE_SIZE __SIZEOF_LONG_DOUBLE__
#endif

#if __has_builtin(__builtin_huge_vall)
#	define Z_COMPILER_CONSTANT_LDOUBLE_HUGE __builtin_huge_vall() /* v2.6 */
#endif

#if __has_builtin(__builtin_infl)
#	define Z_COMPILER_CONSTANT_LDOUBLE_INFINITY __builtin_infl() /* v2.6 */
#endif

#if __has_builtin(__builtin_nanl)
#	define Z_COMPILER_CONSTANT_LDOUBLE_QNAN __builtin_nanl("") /* v2.6 */
#endif

#if __has_builtin(__builtin_nansl)
#	define Z_COMPILER_CONSTANT_LDOUBLE_SNAN __builtin_nansl("") /* v2.6 */
#endif

#if defined(__SIZEOF_POINTER__) /* v2.8 */
#	define Z_COMPILER_CONSTANT_POINTER_SIZE __SIZEOF_POINTER__
#elif defined(_EM_PSIZE) /* v2.8 */
#	define Z_COMPILER_CONSTANT_POINTER_SIZE _EM_PSIZE
#endif

#if defined(__POINTER_WIDTH__) /* v2.6 */
#	define Z_COMPILER_CONSTANT_POINTER_WIDTH __POINTER_WIDTH__
#elif defined(_MIPS_SZPTR) /* v3.1 */
#	define Z_COMPILER_CONSTANT_POINTER_WIDTH _MIPS_SZPTR
#endif

/*#define Z_COMPILER_CONSTANT_UCHAR_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SCHAR_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_SHORT_WIDTH*/
/*#define Z_COMPILER_CONSTANT_USHORT_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SSHORT_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_UINT_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SINT_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_ULONG_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SLONG_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_LLONG_WIDTH*/
/*#define Z_COMPILER_CONSTANT_ULLONG_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SLLONG_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_WCHAR_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_SSIZE_MAXIMUM*/
/*#define Z_COMPILER_CONSTANT_SSIZE_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_UINTMAX_SIZE*/
/*#define Z_COMPILER_CONSTANT_SINTMAX_SIZE*/
/*#define Z_COMPILER_CONSTANT_SINTMAX_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_UINTPTR_SIZE*/
/*#define Z_COMPILER_CONSTANT_SINTPTR_SIZE*/
/*#define Z_COMPILER_CONSTANT_SINTPTR_MINIMUM*/
/*#define Z_COMPILER_CONSTANT_FLOAT_WIDTH*/
/*#define Z_COMPILER_CONSTANT_DOUBLE_WIDTH*/
/*#define Z_COMPILER_CONSTANT_LDOUBLE_WIDTH*/
/*#define Z_COMPILER_CONSTANT_FLOAT16_HUGE*/
/*#define Z_COMPILER_CONSTANT_FLOAT16_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT16_QNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT16_SNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT32_HUGE*/
/*#define Z_COMPILER_CONSTANT_FLOAT32_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT32_QNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT32_SNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT64_HUGE*/
/*#define Z_COMPILER_CONSTANT_FLOAT64_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT64_QNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT64_SNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT128_HUGE*/
/*#define Z_COMPILER_CONSTANT_FLOAT128_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT128_QNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT128_SNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT32X_HUGE*/
/*#define Z_COMPILER_CONSTANT_FLOAT32X_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT32X_QNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT32X_SNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT64X_HUGE*/
/*#define Z_COMPILER_CONSTANT_FLOAT64X_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT64X_QNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT64X_SNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT128X_HUGE*/
/*#define Z_COMPILER_CONSTANT_FLOAT128X_INFINITY*/
/*#define Z_COMPILER_CONSTANT_FLOAT128X_QNAN*/
/*#define Z_COMPILER_CONSTANT_FLOAT128X_SNAN*/
/*#define Z_COMPILER_CONSTANT_DECIMAL32_HUGE*/
/*#define Z_COMPILER_CONSTANT_DECIMAL32_INFINITY*/
/*#define Z_COMPILER_CONSTANT_DECIMAL32_QNAN*/
/*#define Z_COMPILER_CONSTANT_DECIMAL32_SNAN*/
/*#define Z_COMPILER_CONSTANT_DECIMAL64_HUGE*/
/*#define Z_COMPILER_CONSTANT_DECIMAL64_INFINITY*/
/*#define Z_COMPILER_CONSTANT_DECIMAL64_QNAN*/
/*#define Z_COMPILER_CONSTANT_DECIMAL64_SNAN*/
/*#define Z_COMPILER_CONSTANT_DECIMAL128_HUGE*/
/*#define Z_COMPILER_CONSTANT_DECIMAL128_INFINITY*/
/*#define Z_COMPILER_CONSTANT_DECIMAL128_QNAN*/
/*#define Z_COMPILER_CONSTANT_DECIMAL128_SNAN*/
/*#define Z_COMPILER_CONSTANT_DECIMAL64X_HUGE*/
/*#define Z_COMPILER_CONSTANT_DECIMAL64X_INFINITY*/
/*#define Z_COMPILER_CONSTANT_DECIMAL64X_QNAN*/
/*#define Z_COMPILER_CONSTANT_DECIMAL64X_SNAN*/
/*#define Z_COMPILER_CONSTANT_DECIMAL128X_HUGE*/
/*#define Z_COMPILER_CONSTANT_DECIMAL128X_INFINITY*/
/*#define Z_COMPILER_CONSTANT_DECIMAL128X_QNAN*/
/*#define Z_COMPILER_CONSTANT_DECIMAL128X_SNAN*/
/*#define Z_COMPILER_CONSTANT_BFP16_HUGE*/
/*#define Z_COMPILER_CONSTANT_BFP16_INFINITY*/
/*#define Z_COMPILER_CONSTANT_BFP16_QNAN*/
/*#define Z_COMPILER_CONSTANT_BFP16_SNAN*/
/*#define Z_COMPILER_CONSTANT_BFP32_HUGE*/
/*#define Z_COMPILER_CONSTANT_BFP32_INFINITY*/
/*#define Z_COMPILER_CONSTANT_BFP32_QNAN*/
/*#define Z_COMPILER_CONSTANT_BFP32_SNAN*/
/*#define Z_COMPILER_CONSTANT_BFP64_HUGE*/
/*#define Z_COMPILER_CONSTANT_BFP64_INFINITY*/
/*#define Z_COMPILER_CONSTANT_BFP64_QNAN*/
/*#define Z_COMPILER_CONSTANT_BFP64_SNAN*/
/*#define Z_COMPILER_CONSTANT_BFP128_HUGE*/
/*#define Z_COMPILER_CONSTANT_BFP128_INFINITY*/
/*#define Z_COMPILER_CONSTANT_BFP128_QNAN*/
/*#define Z_COMPILER_CONSTANT_BFP128_SNAN*/
/*#define Z_COMPILER_CONSTANT_DFP32_HUGE*/
/*#define Z_COMPILER_CONSTANT_DFP32_INFINITY*/
/*#define Z_COMPILER_CONSTANT_DFP32_QNAN*/
/*#define Z_COMPILER_CONSTANT_DFP32_SNAN*/
/*#define Z_COMPILER_CONSTANT_DFP64_HUGE*/
/*#define Z_COMPILER_CONSTANT_DFP64_INFINITY*/
/*#define Z_COMPILER_CONSTANT_DFP64_QNAN*/
/*#define Z_COMPILER_CONSTANT_DFP64_SNAN*/
/*#define Z_COMPILER_CONSTANT_DFP128_HUGE*/
/*#define Z_COMPILER_CONSTANT_DFP128_INFINITY*/
/*#define Z_COMPILER_CONSTANT_DFP128_QNAN*/
/*#define Z_COMPILER_CONSTANT_DFP128_SNAN*/
/*#define Z_COMPILER_CONSTANT_X87_DE80_HUGE*/
/*#define Z_COMPILER_CONSTANT_X87_DE80_INFINITY*/
/*#define Z_COMPILER_CONSTANT_X87_DE80_QNAN*/
/*#define Z_COMPILER_CONSTANT_X87_DE80_SNAN*/
/*#define Z_COMPILER_CONSTANT_X87_DE96_HUGE*/
/*#define Z_COMPILER_CONSTANT_X87_DE96_INFINITY*/
/*#define Z_COMPILER_CONSTANT_X87_DE96_QNAN*/
/*#define Z_COMPILER_CONSTANT_X87_DE96_SNAN*/
/*#define Z_COMPILER_CONSTANT_X87_DE128_HUGE*/
/*#define Z_COMPILER_CONSTANT_X87_DE128_INFINITY*/
/*#define Z_COMPILER_CONSTANT_X87_DE128_QNAN*/
/*#define Z_COMPILER_CONSTANT_X87_DE128_SNAN*/
/*#define Z_COMPILER_CONSTANT_IBM_ED_HUGE*/
/*#define Z_COMPILER_CONSTANT_IBM_ED_INFINITY*/
/*#define Z_COMPILER_CONSTANT_IBM_ED_QNAN*/
/*#define Z_COMPILER_CONSTANT_IBM_ED_SNAN*/
/*#define Z_COMPILER_CONSTANT_BFLOAT16_HUGE*/
/*#define Z_COMPILER_CONSTANT_BFLOAT16_INFINITY*/
/*#define Z_COMPILER_CONSTANT_BFLOAT16_QNAN*/
/*#define Z_COMPILER_CONSTANT_BFLOAT16_SNAN*/

/* MARK: - Built-ins: Macros */

#if	Z_COMPILER_VERSION >= Z_VERSION(3,1,0) && \
	Z_COMPILER_VERSION <= Z_VERSION(5,0,2)

	/* Multi-level: offsetof(Type, member.field.field); Fails in 3.0 */
#	pragma clang diagnostic ignored "-Wextended-offsetof"
#endif

#define Z_COMPILER_MACRO_MEMBER_OFFSET(type, member) (__extension__ __builtin_offsetof(type, member)) /* v2.6 */


#define Z_COMPILER_MACRO_VAL_INITIALIZE __builtin_va_start /* v2.6 */
#define Z_COMPILER_MACRO_VAL_FINALIZE   __builtin_va_end   /* v2.6 */
#define Z_COMPILER_MACRO_VAL_READ	__builtin_va_arg   /* v2.6 */

#if __has_builtin(__builtin_va_copy)
#	define Z_COMPILER_MACRO_VAL_COPY(self, output) __builtin_va_copy(output, self) /* v2.6 */
#endif

/* MARK: - Built-ins: Functions */

#if __has_builtin(__sync_add_and_fetch_1)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_ADD_THEN_GET __sync_add_and_fetch_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_ADD_THEN_GET __sync_add_and_fetch_1
#endif

#if __has_builtin(__sync_and_and_fetch_1)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_AND_THEN_GET __sync_and_and_fetch_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_AND_THEN_GET __sync_and_and_fetch_1
#endif

#if __has_builtin(__sync_fetch_and_add_1)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD __sync_fetch_and_add_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_ADD __sync_fetch_and_add_1
#endif

#if __has_builtin(__sync_fetch_and_and_1)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_AND __sync_fetch_and_and_1
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_AND __sync_fetch_and_and_1
#endif

#if __has_builtin(__sync_fetch_and_nand_1)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand_1
#endif

#if __has_builtin(__sync_fetch_and_or_1)		   /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_OR __sync_fetch_and_or_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_OR __sync_fetch_and_or_1
#endif

#if __has_builtin(__sync_val_compare_and_swap_1)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SET_IF_EQUAL __sync_val_compare_and_swap_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_SET_IF_EQUAL __sync_val_compare_and_swap_1
#endif

#if __has_builtin(__sync_fetch_and_sub_1)			 /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub_1
#endif

#if __has_builtin(__sync_fetch_and_xor_1)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor_1
#endif

#if __has_builtin(__sync_nand_and_fetch_1)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch_1
#endif

#if __has_builtin(__sync_or_and_fetch_1)		   /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_OR_THEN_GET __sync_or_and_fetch_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_OR_THEN_GET __sync_or_and_fetch_1
#endif

#if __has_builtin(__sync_bool_compare_and_swap_1)	     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap_1
#endif

#if __has_builtin(__sync_sub_and_fetch_1)			 /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch_1
#endif

#if __has_builtin(__sync_xor_and_fetch_1)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT8_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch_1
#	define Z_COMPILER_FUNCTION_SINT8_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch_1
#endif

#if __has_builtin(__sync_add_and_fetch_2)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_ADD_THEN_GET __sync_add_and_fetch_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_ADD_THEN_GET __sync_add_and_fetch_2
#endif

#if __has_builtin(__sync_and_and_fetch_2)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_AND_THEN_GET __sync_and_and_fetch_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_AND_THEN_GET __sync_and_and_fetch_2
#endif

#if __has_builtin(__sync_fetch_and_add_2)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_ADD __sync_fetch_and_add_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_ADD __sync_fetch_and_add_2
#endif

#if __has_builtin(__sync_fetch_and_and_2)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_AND __sync_fetch_and_and_2
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_AND __sync_fetch_and_and_2
#endif

#if __has_builtin(__sync_fetch_and_nand_2)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand_2
#endif

#if __has_builtin(__sync_fetch_and_or_2)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_OR __sync_fetch_and_or_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_OR __sync_fetch_and_or_2
#endif

#if __has_builtin(__sync_val_compare_and_swap_2)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SET_IF_EQUAL __sync_val_compare_and_swap_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_SET_IF_EQUAL __sync_val_compare_and_swap_2
#endif

#if __has_builtin(__sync_fetch_and_sub_2)			  /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub_2
#endif

#if __has_builtin(__sync_fetch_and_xor_2)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor_2
#endif

#if __has_builtin(__sync_nand_and_fetch_2)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch_2
#endif

#if __has_builtin(__sync_or_and_fetch_2)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_OR_THEN_GET __sync_or_and_fetch_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_OR_THEN_GET __sync_or_and_fetch_2
#endif

#if __has_builtin(__sync_bool_compare_and_swap_2)	      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap_2
#endif

#if __has_builtin(__sync_sub_and_fetch_2)			  /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch_2
#endif

#if __has_builtin(__sync_xor_and_fetch_2)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT16_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch_2
#	define Z_COMPILER_FUNCTION_SINT16_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch_2
#endif

#if __has_builtin(__sync_add_and_fetch_4)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_ADD_THEN_GET __sync_add_and_fetch_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_ADD_THEN_GET __sync_add_and_fetch_4
#endif

#if __has_builtin(__sync_and_and_fetch_4)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_AND_THEN_GET __sync_and_and_fetch_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_AND_THEN_GET __sync_and_and_fetch_4
#endif

#if __has_builtin(__sync_fetch_and_add_4)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_ADD __sync_fetch_and_add_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_ADD __sync_fetch_and_add_4
#endif

#if __has_builtin(__sync_fetch_and_and_4)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_AND __sync_fetch_and_and_4
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_AND __sync_fetch_and_and_4
#endif

#if __has_builtin(__sync_fetch_and_nand_4)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand_4
#endif

#if __has_builtin(__sync_fetch_and_or_4)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_OR __sync_fetch_and_or_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_OR __sync_fetch_and_or_4
#endif

#if __has_builtin(__sync_val_compare_and_swap_4)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SET_IF_EQUAL __sync_val_compare_and_swap_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_SET_IF_EQUAL __sync_val_compare_and_swap_4
#endif

#if __has_builtin(__sync_fetch_and_sub_4)			  /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub_4
#endif

#if __has_builtin(__sync_fetch_and_xor_4)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor_4
#endif

#if __has_builtin(__sync_nand_and_fetch_4)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch_4
#endif

#if __has_builtin(__sync_or_and_fetch_4)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_OR_THEN_GET __sync_or_and_fetch_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_OR_THEN_GET __sync_or_and_fetch_4
#endif

#if __has_builtin(__sync_bool_compare_and_swap_4)	      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap_4
#endif

#if __has_builtin(__sync_sub_and_fetch_4)			  /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch_4
#endif

#if __has_builtin(__sync_xor_and_fetch_4)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT32_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch_4
#	define Z_COMPILER_FUNCTION_SINT32_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch_4
#endif

#if __has_builtin(__sync_add_and_fetch_8)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_ADD_THEN_GET __sync_add_and_fetch_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_ADD_THEN_GET __sync_add_and_fetch_8
#endif

#if __has_builtin(__sync_and_and_fetch_8)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_AND_THEN_GET __sync_and_and_fetch_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_AND_THEN_GET __sync_and_and_fetch_8
#endif

#if __has_builtin(__sync_fetch_and_add_8)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_ADD __sync_fetch_and_add_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_ADD __sync_fetch_and_add_8
#endif

#if __has_builtin(__sync_fetch_and_and_8)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_AND __sync_fetch_and_and_8
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_AND __sync_fetch_and_and_8
#endif

#if __has_builtin(__sync_fetch_and_nand_8)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand_8
#endif

#if __has_builtin(__sync_fetch_and_or_8)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_OR __sync_fetch_and_or_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_OR __sync_fetch_and_or_8
#endif

#if __has_builtin(__sync_val_compare_and_swap_8)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SET_IF_EQUAL __sync_val_compare_and_swap_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_SET_IF_EQUAL __sync_val_compare_and_swap_8
#endif

#if __has_builtin(__sync_fetch_and_sub_8)			  /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub_8
#endif

#if __has_builtin(__sync_fetch_and_xor_8)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor_8
#endif

#if __has_builtin(__sync_nand_and_fetch_8)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch_8
#endif

#if __has_builtin(__sync_or_and_fetch_8)		    /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_OR_THEN_GET __sync_or_and_fetch_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_OR_THEN_GET __sync_or_and_fetch_8
#endif

#if __has_builtin(__sync_bool_compare_and_swap_8)	      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap_8
#endif

#if __has_builtin(__sync_sub_and_fetch_8)			  /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch_8
#endif

#if __has_builtin(__sync_xor_and_fetch_8)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT64_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch_8
#	define Z_COMPILER_FUNCTION_SINT64_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch_8
#endif

#if __has_builtin(__sync_add_and_fetch_16)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_ADD_THEN_GET __sync_add_and_fetch_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_ADD_THEN_GET __sync_add_and_fetch_16
#endif

#if __has_builtin(__sync_and_and_fetch_16)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_AND_THEN_GET __sync_and_and_fetch_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_AND_THEN_GET __sync_and_and_fetch_16
#endif

#if __has_builtin(__sync_fetch_and_add_16)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_ADD __sync_fetch_and_add_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_ADD __sync_fetch_and_add_16
#endif

#if __has_builtin(__sync_fetch_and_and_16)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_AND __sync_fetch_and_and_16
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_AND __sync_fetch_and_and_16
#endif

#if __has_builtin(__sync_fetch_and_nand_16)		       /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_NAND __sync_fetch_and_nand_16
#endif

#if __has_builtin(__sync_fetch_and_or_16)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_OR __sync_fetch_and_or_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_OR __sync_fetch_and_or_16
#endif

#if __has_builtin(__sync_val_compare_and_swap_16)		       /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SET_IF_EQUAL __sync_val_compare_and_swap_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_SET_IF_EQUAL __sync_val_compare_and_swap_16
#endif

#if __has_builtin(__sync_fetch_and_sub_16)			   /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_SUBTRACT __sync_fetch_and_sub_16
#endif

#if __has_builtin(__sync_fetch_and_xor_16)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_GET_THEN_XOR __sync_fetch_and_xor_16
#endif

#if __has_builtin(__sync_nand_and_fetch_16)		       /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_NAND_THEN_GET __sync_nand_and_fetch_16
#endif

#if __has_builtin(__sync_or_and_fetch_16)		     /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_OR_THEN_GET __sync_or_and_fetch_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_OR_THEN_GET __sync_or_and_fetch_16
#endif

#if __has_builtin(__sync_bool_compare_and_swap_16)	       /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_SET_IF_EQUAL __sync_bool_compare_and_swap_16
#endif

#if __has_builtin(__sync_sub_and_fetch_16)			   /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_SUBTRACT_THEN_GET __sync_sub_and_fetch_16
#endif

#if __has_builtin(__sync_xor_and_fetch_16)		      /* v2.6 */
#	define Z_COMPILER_FUNCTION_UINT128_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch_16
#	define Z_COMPILER_FUNCTION_SINT128_ATOMIC_XOR_THEN_GET __sync_xor_and_fetch_16
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

#	if __has_builtin(__type_pack_element) /* v3.9 */
#		pragma clang diagnostic push
#		pragma clang diagnostic ignored "-Weverything"
#		define Z_COMPILER_TRAIT_SELECT_TYPE(I, ...) __type_pack_element<I, __VA_ARGS__> /* v3.9 */
#		pragma clang diagnostic pop
#	endif

#	if Z_COMPILER_VERSION >= Z_VERSION(3,5,0)
#		define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_ASSIGNABLE    __is_nothrow_assignable	 /* v3.5 */
#		define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_CONSTRUCTIBLE __is_nothrow_constructible /* v3.5 */

#		if Z_COMPILER_VERSION >= Z_VERSION(3,9,0)
#			define Z_COMPILER_TRAIT_TYPE_IS_ASSIGNABLE __is_assignable /* v3.9 */

#			if Z_COMPILER_VERSION >= Z_VERSION(5,0,0)
#				define Z_COMPILER_TRAIT_TYPE_IS_AGGREGATE __is_aggregate /* v5.0 */
#			endif
#		endif
#	endif

#endif

#if Z_z_HAS_TRAIT(has_virtual_destructor)
#	define Z_COMPILER_TRAIT_TYPE_HAS_VIRTUAL_DESTRUCTOR __has_virtual_destructor /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_abstract)
#	define Z_COMPILER_TRAIT_TYPE_IS_ABSTRACT __is_abstract /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_base_of)
#	define Z_COMPILER_TRAIT_TYPE_IS_BASE __is_base_of /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_constructible)
#	define Z_COMPILER_TRAIT_TYPE_IS_CONSTRUCTIBLE __is_constructible /* v3.5 */
#endif

#if Z_z_HAS_TRAIT(is_convertible_to)
#	define Z_COMPILER_TRAIT_TYPE_IS_CONVERTIBLE __is_convertible_to /* v2.9 */
#endif

#if Z_z_HAS_TRAIT(is_empty)
#	define Z_COMPILER_TRAIT_TYPE_IS_EMPTY __is_empty /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_enum)
#	define Z_COMPILER_TRAIT_TYPE_IS_ENUMERATION __is_enum /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_final)
#	define Z_COMPILER_TRAIT_TYPE_IS_FINAL __is_final /* v3.1 */
#endif

#if Z_z_HAS_TRAIT(is_interface_class)
#	define Z_COMPILER_TRAIT_TYPE_IS_INTERFACE_CLASS __is_interface_class /* v3.2 (not detectable with __has_extension?) */
#endif

#if Z_z_HAS_TRAIT(is_literal)
#	define Z_COMPILER_TRAIT_TYPE_IS_LITERAL __is_literal /* v2.7 */

#elif defined(__cplusplus) && Z_COMPILER_VERSION >= Z_VERSION(3,0,0)
#	define Z_COMPILER_TRAIT_TYPE_IS_LITERAL __is_literal_type /* v3.0 */
#endif

#if Z_z_HAS_TRAIT(has_nothrow_assign)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_COPY_ASSIGNABLE __has_nothrow_assign /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(has_nothrow_copy)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_COPY_CONSTRUCTIBLE __has_nothrow_copy /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(has_nothrow_constructor)
#	define Z_COMPILER_TRAIT_TYPE_IS_NOTHROW_DEFAULT_CONSTRUCTIBLE __has_nothrow_constructor /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_pod)
#	define Z_COMPILER_TRAIT_TYPE_IS_POD __is_pod /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_polymorphic)
#	define Z_COMPILER_TRAIT_TYPE_IS_POLYMORPHIC __is_polymorphic /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_std_layout)
#	define Z_COMPILER_TRAIT_TYPE_IS_STD_LAYOUT __is_standard_layout /* v3.0 */
#endif

#if Z_z_HAS_TRAIT(is_class)
#	define Z_COMPILER_TRAIT_TYPE_IS_STRUCTURE __is_class /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_trivial)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIAL __is_trivial /* v3.0 */
#endif

#if Z_z_HAS_TRAIT(is_trivially_assignable)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_ASSIGNABLE __is_trivially_assignable /* v3.1 */
#endif

#if Z_z_HAS_TRAIT(is_trivially_constructible)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_CONSTRUCTIBLE __is_trivially_constructible /* v3.1 */
#endif

/*--------------------------------------------------.
| See:						    |
| https://github.com/abseil/abseil-cpp/issues/1201  |
| https://reviews.llvm.org/D127593		    |
| https://github.com/llvm/llvm-project/issues/33063 |
'==================================================*/

#if Z_z_HAS_TRAIT(has_trivial_assign) && Z_COMPILER_VERSION < Z_VERSION(10,0,0) /* Check version */
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_COPY_ASSIGNABLE __has_trivial_assign /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_trivially_copyable)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE __is_trivially_copyable
#elif Z_z_HAS_TRAIT(has_trivial_copy)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE __has_trivial_copy /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_trivially_copyable)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_COPYABLE __is_trivially_copyable /* v3.0 */
#endif

#if Z_z_HAS_TRAIT(is_trivially_constructible)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE __is_trivially_constructible
#elif Z_z_HAS_TRAIT(has_trivial_constructor)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE __has_trivial_constructor /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_trivially_destructible)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_DESTRUCTIBLE __is_trivially_destructible
#elif Z_z_HAS_TRAIT(has_trivial_destructor)
#	define Z_COMPILER_TRAIT_TYPE_IS_TRIVIALLY_DESTRUCTIBLE __has_trivial_destructor /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(is_union)
#	define Z_COMPILER_TRAIT_TYPE_IS_UNION __is_union /* v2.6 */
#endif

#if Z_z_HAS_TRAIT(underlying_type)
#	define Z_COMPILER_TRAIT_TYPE_UNDERLYING_TYPE __underlying_type /* v3.0 */
#endif

/* MARK: - Private macros clean-up */

#undef Z_z_HAS_ATTRIBUTE
#undef Z_z_HAS_CPP_ATTRIBUTE
#undef Z_z_HAS_EXTENSION
#undef Z_z_HAS_GNU_EXTENSIONS
#undef Z_z_HAS_MSVC_COMPATIBILITY
#undef Z_z_HAS_TRAIT

#define Z_COMPILER_HAS_MAGIC_CONSTANT_MANGLED_FUNCTION_NAME 1

#endif /* Z_inspection_compiler_modules_Clang_H */
