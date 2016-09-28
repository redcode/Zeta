/* Z Kit C API - inspection/completions/CPU/x86-64.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_CPU_modules_x86_64_H__
#define __Z_inspection_CPU_modules_x86_64_H__

#define Z_INSERT_CPU_ARCHITECTURE(left, right) left##X86_64##right
#define Z_INSERT_CPUArchitecture( left, right) left##X8664##right
#define Z_INSERT_cpu_architecture(left, right) left##x86_64##right

#define Z_CPU_ARCHITECTURE_INTEGER_ENDIANNESS Z_ENDIANNESS_LITTLE
#define Z_CPU_ARCHITECTURE_INTEGER_FORMAT     Z_INTEGER_FORMAT_2S_COMPLEMENT

#define Z_CPU_MINIMUM_LOAD_BITS  8
#define Z_CPU_MINIMUM_STORE_BITS 8
#define Z_CPU_MINIMUM_COPY_BITS  8
#define Z_CPU_MAXIMUM_LOAD_BITS  64
#define Z_CPU_MAXIMUM_STORE_BITS 64
#define Z_CPU_MAXIMUM_COPY_BITS  64
#define Z_CPU_ADDRESSING_BITS    64

#define Z_CPU_ARCHITECTURE_HAS_MMU TRUE
#define Z_CPU_ARCHITECTURE_HAS_FPU TRUE

#ifndef Z_CPU_HAS_ISA_3D_NOW
#	define Z_CPU_HAS_ISA_3D_NOW FALSE
#endif

#ifndef Z_CPU_HAS_ISA_3D_NOW_PLUS
#	define Z_CPU_HAS_ISA_3D_NOW_PLUS FALSE
#endif

#ifndef Z_CPU_HAS_ISA_8086_8088
#	define Z_CPU_HAS_ISA_8086_8088 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_8087
#	define Z_CPU_HAS_ISA_8087 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_80186_80188
#	define Z_CPU_HAS_ISA_80186_80188 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_80286
#	define Z_CPU_HAS_ISA_80286 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_80287
#	define Z_CPU_HAS_ISA_80287 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_80386
#	define Z_CPU_HAS_ISA_80386 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_80387
#	define Z_CPU_HAS_ISA_80387 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_80486
#	define Z_CPU_HAS_ISA_80486 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_AES
#	define Z_CPU_HAS_ISA_AES FALSE
#endif

#ifndef Z_CPU_HAS_ISA_AMD
#	define Z_CPU_HAS_ISA_AMD FALSE
#endif

#ifndef Z_CPU_HAS_ISA_AMD_V
#	define Z_CPU_HAS_ISA_AMD_V FALSE
#endif

#ifndef Z_CPU_HAS_ISA_AVX
#	define Z_CPU_HAS_ISA_AVX FALSE
#endif

#ifndef Z_CPU_HAS_ISA_CLMUL
#	define Z_CPU_HAS_ISA_CLMUL FALSE
#endif

#ifndef Z_CPU_HAS_ISA_CYRIX
#	define Z_CPU_HAS_ISA_CYRIX FALSE
#endif

#ifndef Z_CPU_HAS_ISA_EMMI
#	define Z_CPU_HAS_ISA_EMMI FALSE
#endif

#ifndef Z_CPU_HAS_ISA_EMMX
#	define Z_CPU_HAS_ISA_EMMX FALSE
#endif

#ifndef Z_CPU_HAS_ISA_FMA3
#	define Z_CPU_HAS_ISA_FMA3 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_FMA4
#	define Z_CPU_HAS_ISA_FMA4 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_GEODE_GX
#	define Z_CPU_HAS_ISA_GEODE_GX FALSE
#endif

#ifndef Z_CPU_HAS_ISA_MMX_PLUS
#	define Z_CPU_HAS_ISA_MMX_PLUS FALSE
#endif

#ifndef Z_CPU_HAS_ISA_PAD_LOCK
#	define Z_CPU_HAS_ISA_PAD_LOCK FALSE
#endif

#ifndef Z_CPU_HAS_ISA_PENTIUM
#	define Z_CPU_HAS_ISA_PENTIUM FALSE
#endif

#ifndef Z_CPU_HAS_ISA_PENTIUM_MMX
#	define Z_CPU_HAS_ISA_PENTIUM_MMX FALSE
#endif

#ifndef Z_CPU_HAS_ISA_K6_2
#	define Z_CPU_HAS_ISA_K6_2 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_PENTIUM_PRO
#	define Z_CPU_HAS_ISA_PENTIUM_PRO FALSE
#endif

#ifndef Z_CPU_HAS_ISA_SSE
#	define Z_CPU_HAS_ISA_SSE FALSE
#endif

#ifndef Z_CPU_HAS_ISA_SSE2
#	define Z_CPU_HAS_ISA_SSE2 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_SSE3
#	define Z_CPU_HAS_ISA_SSE3 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_SSSE3
#	define Z_CPU_HAS_ISA_SSSE3 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_SSE4_1
#	define Z_CPU_HAS_ISA_SSE4_1 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_SSE4_2
#	define Z_CPU_HAS_ISA_SSE4_2 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_SSE4A
#	define Z_CPU_HAS_ISA_SSE4A FALSE
#endif

#ifndef Z_CPU_HAS_ISA_SSE5
#	define Z_CPU_HAS_ISA_SSE5 FALSE
#endif

#ifndef Z_CPU_HAS_ISA_SSM
#	define Z_CPU_HAS_ISA_SSM FALSE
#endif

#ifndef Z_CPU_HAS_ISA_SVM
#	define Z_CPU_HAS_ISA_SVM FALSE
#endif

#ifndef Z_CPU_HAS_ISA_VT_X
#	define Z_CPU_HAS_ISA_VT_X FALSE
#endif

#ifndef Z_CPU_HAS_ISA_X86_64
#	define Z_CPU_HAS_ISA_X86_64 FALSE
#endif

#endif /* __Z_inspection_CPU_modules_x86_64_H__ */
