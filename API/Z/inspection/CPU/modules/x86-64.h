/* Z Kit - inspection/modules/CPU/x86-64.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_CPU_modules_x86_64_H_
#define _Z_inspection_CPU_modules_x86_64_H_

#define Z_APPEND_CPU_ARCHITECTURE(to)	       to##X86_64
#define Z_APPEND_CPUArchitecture( to)	       to##X8664
#define Z_APPEND_cpu_architecture(to)	       to##x86_64
#define Z_INSERT_CPU_ARCHITECTURE(left, right) left##X86_64##right
#define Z_INSERT_CPUArchitecture( left, right) left##X8664##right
#define Z_INSERT_cpu_architecture(left, right) left##x86_64##right

#define Z_CPU_HAS_MMU			 TRUE
#define Z_CPU_HAS_FPU			 TRUE
#define Z_CPU_HAS_INTEGER_8BIT		 TRUE
#define Z_CPU_HAS_INTEGER_16BIT		 TRUE
#define Z_CPU_HAS_INTEGER_32BIT		 TRUE
#define Z_CPU_HAS_INTEGER_64BIT		 TRUE
#define Z_CPU_HAS_REAL_IEEE_754_BINARY32 TRUE
#define Z_CPU_HAS_REAL_IEEE_754_BINARY64 TRUE

#define Z_CPU_INTEGER_ENDIANNESS Z_ENDIANNESS_LITTLE

#define Z_CPU_BITS_TOP_INTEGER 64
#define Z_CPU_BITS_ADDRESSING  64


/*#if	defined(__3dNOW__)

#	define Z_CPU_HAS_ISA_3D_NOW TRUE
#else
#	define Z_CPU_HAS_ISA_3D_NOW FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_3D_NOW_PLUS TRUE
#else
#	define Z_CPU_HAS_ISA_3D_NOW_PLUS FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_8086_8088 TRUE
#else
#	define Z_CPU_HAS_ISA_8086_8088 FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_8087 TRUE
#else
#	define Z_CPU_HAS_ISA_8087 FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_80186_80188 TRUE
#else
#	define Z_CPU_HAS_ISA_80186_80188 FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_80286 TRUE
#else
#	define Z_CPU_HAS_ISA_80286 FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_80287 TRUE
#else
#	define Z_CPU_HAS_ISA_80287 FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_80386 TRUE
#else
#	define Z_CPU_HAS_ISA_80386 FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_80387 TRUE
#else
#	define Z_CPU_HAS_ISA_80387 FALSE
#endif

#if	defined(__i486	) || \
	defined(__i486__)

#	define Z_CPU_HAS_ISA_80486 TRUE
#else
#	define Z_CPU_HAS_ISA_80486 FALSE
#endif

#if	defined(__AES__)

#	define Z_CPU_HAS_ISA_AES TRUE
#else
#	define Z_CPU_HAS_ISA_AES FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_AMD TRUE
#else
#	define Z_CPU_HAS_ISA_AMD FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_AMD_V TRUE
#else
#	define Z_CPU_HAS_ISA_AMD_V FALSE
#endif

#if	defined(__AVX__)

#	define Z_CPU_HAS_ISA_AVX TRUE
#else
#	define Z_CPU_HAS_ISA_AVX FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_CLMUL TRUE
#else
#	define Z_CPU_HAS_ISA_CLMUL FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_CYRIX TRUE
#else
#	define Z_CPU_HAS_ISA_CYRIX FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_EMMI TRUE
#else
#	define Z_CPU_HAS_ISA_EMMI FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_EMMX TRUE
#else
#	define Z_CPU_HAS_ISA_EMMX FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_FMA3 TRUE
#else
#	define Z_CPU_HAS_ISA_FMA3 FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_FMA4 TRUE
#else
#	define Z_CPU_HAS_ISA_FMA4 FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_GEODE_GX TRUE
#else
#	define Z_CPU_HAS_ISA_GEODE_GX FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_MMX_PLUS TRUE
#else
#	define Z_CPU_HAS_ISA_MMX_PLUS FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_PAD_LOCK TRUE
#else
#	define Z_CPU_HAS_ISA_PAD_LOCK FALSE
#endif

#if	defined(__i586) || \
	defined(__i586__) || \
	defined(__pentium) || \
	defined(__pentium__)

#	define Z_CPU_HAS_ISA_PENTIUM TRUE
#else
#	define Z_CPU_HAS_ISA_PENTIUM FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_PENTIUM_MMX TRUE
#else
#	define Z_CPU_HAS_ISA_PENTIUM_MMX FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_K6_2 TRUE
#else
#	define Z_CPU_HAS_ISA_K6_2 FALSE
#endif

#if	defined(__i686) || \
	defined(__i686__) || \
	defined(__pentiumpro) || \
	defined(__pentiumpro__) || \

#	define Z_CPU_HAS_ISA_PENTIUM_PRO TRUE
#else
#	define Z_CPU_HAS_ISA_PENTIUM_PRO FALSE
#endif

#if	defined(__SSE__)

#	define Z_CPU_HAS_ISA_SSE TRUE
#else
#	define Z_CPU_HAS_ISA_SSE FALSE
#endif

#if	defined(__SSE2__)

#	define Z_CPU_HAS_ISA_SSE2 TRUE
#else
#	define Z_CPU_HAS_ISA_SSE2 FALSE
#endif

#if	defined(__SSE3__)

#	define Z_CPU_HAS_ISA_SSE3 TRUE
#else
#	define Z_CPU_HAS_ISA_SSE3 FALSE
#endif

#if	defined(__SSSE3__)

#	define Z_CPU_HAS_ISA_SSSE3 TRUE
#else
#	define Z_CPU_HAS_ISA_SSSE3 FALSE
#endif

#if	defined(__SSE4_1__)

#	define Z_CPU_HAS_ISA_SSE4_1 TRUE
#else
#	define Z_CPU_HAS_ISA_SSE4_1 FALSE
#endif

#if	defined(__SSE4_2__)

#	define Z_CPU_HAS_ISA_SSE4_2 TRUE
#else
#	define Z_CPU_HAS_ISA_SSE4_2 FALSE
#endif

#if	defined(__SSE4A__)

#	define Z_CPU_HAS_ISA_SSE4A TRUE
#else
#	define Z_CPU_HAS_ISA_SSE4A FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_SSE5 TRUE
#else
#	define Z_CPU_HAS_ISA_SSE5 FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_SSM TRUE
#else
#	define Z_CPU_HAS_ISA_SSM FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_SVM TRUE
#else
#	define Z_CPU_HAS_ISA_SVM FALSE
#endif

#if	defined()

#	define Z_CPU_HAS_ISA_VT_X TRUE
#else
#	define Z_CPU_HAS_ISA_VT_X FALSE
#endif

#ifndef Z_CPU_HAS_ISA_X86_64
#	define Z_CPU_HAS_ISA_X86_64 TRUE
#else
#	define Z_CPU_HAS_ISA_X86_64 FALSE
#endif*/

#endif /* _Z_inspection_CPU_modules_x86_64_H_ */
