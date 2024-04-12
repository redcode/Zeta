/* Zeta API - Z/inspection/ISA/detection.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_ISA_detection_H
#define Z_inspection_ISA_detection_H

#if	defined(__amd64	  ) || \
	defined(__amd64__ ) || \
	defined(__x86_64  ) || \
	defined(__x86_64__) || \
	defined(_M_AMD64  ) || \
	defined(_M_X64	  )

#	define Z_ISA Z_ISA_X86_64

#elif	defined(__386	       ) || \
	defined(__386__	       ) || \
	defined(__I86__	       ) || \
	defined(__IA32__       ) || \
	defined(__INTEL__      ) || \
	defined(__THW_INTEL__  ) || \
	defined(__X86__	       ) || \
	defined(__WINDOWS_386__) || \
	defined(__i386	       ) || \
	defined(__i386__       ) || \
	defined(__i486	       ) || \
	defined(__i486__       ) || \
	defined(__i586	       ) || \
	defined(__i586__       ) || \
	defined(__i686	       ) || \
	defined(__i686__       ) || \
	defined(_X86_	       ) || \
	defined(M_I386	       ) || \
	defined(i386	       ) || \
	(defined(_M_IX86) && !defined(__WATCOMC__))

#	define Z_ISA Z_ISA_X86_32

#elif	defined(_M_I86 ) || \
	defined(_M_IX86)

#	define Z_ISA Z_ISA_X86_16

#elif	defined(__ARM_ARCH_ISA_A64) || \
	defined(__aarch64__	  ) || \
	defined(__arm64		  ) || \
	defined(__arm64__	  ) || \
	defined(_M_ARM64	  )

#	define Z_ISA Z_ISA_AARCH64

#elif	defined(__ARM_ARCH	   ) || \
	defined(__TARGET_ARCH_ARM  ) || \
	defined(__TARGET_ARCH_THUMB) || \
	defined(__arm__		   ) || \
	defined(__arm		   ) || \
	defined(__thumb__	   ) || \
	defined(_ARM		   ) || \
	defined(_ARM_		   ) || \
	defined(_M_ARM		   ) || \
	defined(_M_ARM_NT	   ) || \
	defined(_M_ARMT		   ) || \
	defined(_M_THUMB	   ) || \
	defined(arm		   )

#	define Z_ISA Z_ISA_AARCH32

#elif	defined(__APPLE2ENH__	) || \
	defined(__APPLE2__	) || \
	defined(__ATARI__	) || \
	defined(__ATARI2600__	) || \
	defined(__ATARI5200__	) || \
	defined(__ATMOS__	) || \
	defined(__CBM__		) || \
	defined(__CREATIVISION__) || \
	defined(__GAMATE__	) || \
	defined(__LYNX__	) || \
	defined(__NES__		) || \
	defined(__OSIC1P__	) || \
	defined(__PCE__		) || \
	defined(__SUPERVISION__	) || \
	defined(__TELESTRAT__	) || \
	(defined(__GEOS__) && defined(__C65__))

#	define Z_ISA Z_ISA_6502

#elif	defined(__alpha	 ) || \
	defined(__alpha__) || \
	defined(_M_ALPHA )

#	define Z_ISA Z_ISA_ALPHA

#elif defined(__arc__)
#	define Z_COMPILER_ISA Z_ISA_ARC

#elif	defined(__ADSPBLACKFIN__  ) || \
	defined(__ADSPLPBLACKFIN__) || \
	defined(__BFIN		  ) || \
	defined(__BFIN__	  ) || \
	defined(__bfin		  ) || \
	defined(__bfin__	  ) || \
	defined(BFIN		  ) || \
	defined(bfin		  )

#	define Z_ISA Z_ISA_BLACKFIN

#elif defined(__convex__)
#	define Z_ISA Z_ISA_CONVEX

#elif defined(__epiphany__)
#	define Z_ISA Z_ISA_EPIPHANY

#elif defined(__s390__)
#	define Z_ISA Z_ISA_ESA_390

#elif	defined(__370__	   ) || \
	defined(__THW_370__)

#	define Z_ISA Z_ISA_ESA_370

#elif	defined(__HEXAGON_ARCH__) || \
	defined(__QDSP6_ARCH__	) || \
	defined(__hexagon	) || \
	defined(__hexagon__	) || \
	defined(__qdsp6		) || \
	defined(__qdsp6__	) || \
	defined(hexagon		) || \
	defined(qdsp6		)

#	define Z_ISA Z_ISA_HEXAGON

#elif	defined(__IA64__   ) || \
	defined(__ia64__   ) || \
	defined(__ia64	   ) || \
	defined(__itanium__) || \
	defined(_IA64	   ) || \
	defined(_M_IA64	   ) || \
	defined(ia64	   )

#	define Z_ISA Z_ISA_IA_64

#elif defined(__loongarch64)
#	define Z_ISA Z_ISA_LA64

#elif defined(__loongarch__)
#	define Z_ISA Z_ISA_LA32S

#elif defined(__lanai__)
#	define Z_ISA Z_ISA_LANAI

#elif defined(__lm32__)
#	define Z_ISA Z_ISA_LATTICE_MICO_32

#elif	defined(__MC68K__) || \
	defined(__m68k__ ) || \
	defined(M68000	 )

#	define Z_ISA Z_ISA_M68K

#elif	defined(__mips64  ) ||						     \
	defined(__mips64__) ||						     \
	(defined(__mips) && (__mips == 64 || __mips == 4 || __mips == 3)) || \
	(defined(_MIPS_ISA) &&						     \
	 ((defined(_MIPS_ISA_MIPS64) && _MIPS_ISA == _MIPS_ISA_MIPS64) ||    \
	  (defined(_MIPS_ISA_MIPS4 ) && _MIPS_ISA == _MIPS_ISA_MIPS4 ) ||    \
	  (defined(_MIPS_ISA_MIPS3 ) && _MIPS_ISA == _MIPS_ISA_MIPS3 )))

#	define Z_ISA Z_ISA_MIPS64

#elif	defined(__MIPS__ ) || \
	defined(__mips	 ) || \
	defined(__mips__ ) || \
	defined(_M_MRX000) || \
	defined(_mips	 ) || \
	defined(mips	 )

#	define Z_ISA Z_ISA_MIPS

#elif	defined(__MSP430__) || \
	defined(MSP430	  )

#	define Z_ISA Z_ISA_MSP430

#elif	defined(__HPPA20__ ) || \
	defined(_PA_RISC2_0)

#	define Z_ISA Z_ISA_PA_RISC_2

#elif	defined(__HPPA__   ) || \
	defined(__HPPA11__ ) || \
	defined(__hppa	   ) || \
	defined(__hppa__   ) || \
	defined(_PA_RISC1_0) || \
	defined(_PA_RISC1_1)

#	define Z_ISA Z_ISA_PA_RISC

#elif	defined(__PPC64__    ) || \
	defined(__powerpc64__) || \
	defined(__ppc64__    ) || \
	defined(_ARCH_PPC64  )

#	define Z_ISA Z_ISA_POWERPC_64BIT

#elif	defined(__POWERPC__    ) || \
	defined(__PPC	       ) || \
	defined(__PPC__	       ) || \
	defined(__PPCBROADWAY__) || \
	defined(__PPCGECKO__   ) || \
	defined(__powerpc      ) || \
	defined(__powerpc__    ) || \
	defined(__ppc	       ) || \
	defined(__ppc__	       ) || \
	defined(_ARCH_PPC      ) || \
	defined(_M_PPC	       )

#	define Z_ISA Z_ISA_POWERPC_32BIT

#elif defined(__riscv_32e)
#	define Z_ISA Z_ISA_RV32E

#elif defined(__riscv_xlen) && __riscv_xlen == 32
#	define Z_ISA Z_ISA_RV32I

#elif defined(__riscv_xlen) && __riscv_xlen == 64
#	define Z_ISA Z_ISA_RV64I

#elif	defined(__arch64__  ) || \
	defined(__sparc_v9__) || \
	defined(__sparc64__ ) || \
	defined(__sparcv9   ) || \
	defined(__sparcv9__ )

#	define Z_ISA Z_ISA_SPARC_V9

#elif	defined(__sparc	    ) || \
	defined(__sparc__   ) || \
	defined(__sparc_v8__) || \
	defined(__sparcv8   ) || \
	defined(__sparcv8__ ) || \
	defined(sparc	    )

#	define Z_ISA Z_ISA_SPARC

#elif defined(__SH5__) && __SH5__ == 64
#	define Z_ISA Z_ISA_SUPERH_5

#elif defined(__sh__)
#	define Z_ISA Z_ISA_SUPERH

#elif defined(__vax__)
#	define Z_ISA Z_ISA_VAX

#elif	defined(__wasm64  ) || \
	defined(__wasm64__)

#	define Z_ISA Z_ISA_WASM64

#elif	defined(__wasm	  ) || \
	defined(__wasm__  ) || \
	defined(__wasm32  ) || \
	defined(__wasm32__)

#	define Z_ISA Z_ISA_WASM32

#elif defined(__XS1B__)
#	define Z_ISA Z_ISA_XCORE

#elif	defined(__SYSC_ZARCH__) || \
	defined(__s390x__     ) || \
	defined(__zarch__     )

#	define Z_ISA Z_ISA_Z_ARCHITECTURE
#endif

#endif /* Z_inspection_ISA_detection_H */
