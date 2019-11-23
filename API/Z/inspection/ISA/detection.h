/* Z Kit - inspection/ISA/detection.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_ISA_detection_H
#define Z_inspection_ISA_detection_H

/* MARK: - x86-64 */

#if	/*----------------------.						\
	| Clang v2.6		|						\
	| GCC			|						\
	| Oracle Solaris Studio |						\
	'----------------------*/						\
	defined(__amd64) ||							\
										\
	/*----------------------.						\
	| Clang v2.6		|						\
	| GCC			|						\
	| Oracle Solaris Studio |						\
	| PGI C/C++		|						\
	'----------------------*/						\
	defined(__amd64__) ||							\
										\
	/*----------------------.						\
	| Clang v2.6		|						\
	| GCC			|						\
	| Intel C++		|						\
	| Oracle Solaris Studio |						\
	'----------------------*/						\
	defined(__x86_64) ||							\
										\
	/*----------------------.						\
	| Clang v2.6		|						\
	| GCC			|						\
	| Intel C++		|						\
	| Oracle Solaris Studio |						\
	| PGI C/C++		|						\
	'----------------------*/						\
	defined(__x86_64__) ||							\
										\
	/*-----------.								\
	| Clang v2.9 |								\
	| Intel C++  |								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_AMD64) ||							\
										\
	/*-----------.								\
	| Clang v2.7 |								\
	| Intel C++  |								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_X64	)

#	define Z_ISA Z_ISA_X86_64

/* MARK: - x86-32 */

#elif	/*-----------.								\
	| Diab C/C++ |								\
	'-----------*/								\
	defined(__386) ||							\
										\
	/*-------------.							\
	| Watcom C/C++ |							\
	'-------------*/							\
	defined(__386__) ||							\
										\
	/*-------------.							\
	| Digital Mars |							\
	'-------------*/							\
	defined(__I86__) ||							\
										\
	/*--------------.							\
	| Stratus VOS C |							\
	'--------------*/							\
	defined(__IA32__) ||							\
										\
	/*------------.								\
	| Clang v2.8  |								\
	| CodeWarrior |								\
	'------------*/								\
	defined(__INTEL__) ||							\
										\
	/*-------------.							\
	| IBM XL C/C++ |							\
	'-------------*/							\
	defined(__THW_INTEL__) ||						\
										\
	/*-------------.							\
	| Watcom C/C++ |							\
	'-------------*/							\
	defined(__X86__	       ) ||						\
	defined(__WINDOWS_386__) ||						\
										\
	/*--------------.							\
	| Clang v2.6	|							\
	| GCC		|							\
	| Intel C++	|							\
	| MinGW		|							\
	| PGI C/C++	|							\
	| Stratus VOS C |							\
	| Sun Studio	|							\
	'--------------*/							\
	defined(__i386) ||							\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	| GCC	     |								\
	| Intel C++  |								\
	| MinGW	     |								\
	| PGI C/C++  |								\
	'-----------*/								\
	defined(__i386__) ||							\
										\
	/*-----------.								\
	| Clang v3.0 |								\
	'-----------*/								\
	defined(__i486) ||							\
										\
	/*-----------.								\
	| Clang v3.0 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__i486__) ||							\
										\
	/*-----------.								\
	| Clang v3.0 |								\
	'-----------*/								\
	defined(__i586) ||							\
										\
	/*-----------.								\
	| Clang v3.0 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__i586__) ||							\
										\
	/*-----------.								\
	| Clang v3.0 |								\
	'-----------*/								\
	defined(__i686) ||							\
										\
	/*-----------.								\
	| Clang v3.0 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__i686__) ||							\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	| MinGW	     |								\
	'-----------*/								\
	defined(_X86_) ||							\
										\
	/*-------------.							\
	| Watcom C/C++ |							\
	'-------------*/							\
	defined(M_I386) ||							\
										\
	/*----------------------.						\
	| Clang v2.6		|						\
	| GCC			|						\
	| Intel C++		|						\
	| MinGW			|						\
	| Oracle Solaris Studio |						\
	| PGI C/C++		|						\
	'----------------------*/						\
	defined(i386) ||							\
										\
	/*-------------.							\
	| Clang v2.7   |							\
	| Digital Mars |							\
	| Intel C++    |							\
	| Visual C++   |							\
	| Watcom C/C++ |							\
	'-------------*/							\
	(defined(_M_IX86) && !defined(__WATCOMC__))

#	define Z_ISA Z_ISA_X86_32

/* MARK: - x86-16 */

#elif	/*-------------.							\
	| Digital Mars |							\
	| Visual C++   |							\
	| Watcom C/C++ |							\
	'-------------*/							\
	defined(_M_I86 ) ||							\
										\
	/*-------------.							\
	| Watcom C/C++ |							\
	'-------------*/							\
	defined(_M_IX86)

#	define Z_ISA Z_ISA_X86_16

/* MARK: - AArch64 */

#elif	/*-----------.								\
	| Clang v3.3 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__aarch64__) ||							\
										\
	/*-----------.								\
	| Clang v3.5 |								\
	'-----------*/								\
	defined(__arm64) ||							\
	defined(__arm64__)							\
										\
	/*--------------------------------------------------------------.	\
	| Visual C++ (not implemented yet, found in the Windows 10 SDK) |	\
	'--------------------------------------------------------------*/	\
	defined(_M_ARM64)

#	define Z_ISA Z_ISA_AARCH64

/* MARK: - AArch32 */

#elif	/*-----------.								\
	| Clang v3.2 |								\
	'-----------*/								\
	defined(__ARM_ARCH) ||							\
										\
	/*-------------------.							\
	| ARM C/C++ Compiler |							\
	'-------------------*/							\
	defined(__TARGET_ARCH_ARM  ) ||						\
	defined(__TARGET_ARCH_THUMB) ||						\
										\
	/*-------------------.							\
	| Clang v2.6	     |							\
	| GCC		     |							\
	| ARM C/C++ Compiler |							\
	'-------------------*/							\
	defined(__arm__) ||							\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	| Diab C/C++ |								\
	'-----------*/								\
	defined(__arm) ||							\
										\
	/*-------------------.							\
	| Clang v2.7	     |							\
	| GCC		     |							\
	| ARM C/C++ Compiler |							\
	'-------------------*/							\
	defined(__thumb__) ||							\
										\
	/*-------------.							\
	| ImageCraft C |							\
	'-------------*/							\
	defined(_ARM) ||							\
										\
	/*-----------.								\
	| Clang v3.8 |								\
	'-----------*/								\
	defined(_ARM_) ||							\
										\
	/*-----------.								\
	| Clang v3.5 |								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_ARM) ||							\
										\
	/*-----------.								\
	| Clang v3.5 |								\
	'-----------*/								\
	defined(_M_ARM_NT) ||							\
										\
	/*-----------.								\
	| Clang v3.5 |								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_ARMT) ||							\
										\
	/*-----------.								\
	| Clang v3.5 |								\
	'-----------*/								\
	defined(_M_THUMB)

#	define Z_ISA Z_ISA_AARCH32

/* MARK: - 6502 */

#elif	/*-----.								\
	| cc65 |								\
	'-----*/								\
	defined(__APPLE2ENH__	) ||						\
	defined(__APPLE2__	) ||						\
	defined(__ATARI__	) ||						\
	defined(__ATARI2600__	) ||						\
	defined(__ATARI5200__	) ||						\
	defined(__ATMOS__	) ||						\
	defined(__CBM__		) ||						\
	defined(__CREATIVISION__) ||						\
	defined(__GAMATE__	) ||						\
	defined(__LYNX__	) ||						\
	defined(__NES__		) ||						\
	defined(__OSIC1P__	) ||						\
	defined(__PCE__		) ||						\
	defined(__SUPERVISION__	) ||						\
	defined(__TELESTRAT__	) ||						\
	(defined(__GEOS__) && defined(__C65__))

#	define Z_ISA Z_ISA_6502

/* MARK: - Alpha */

#elif	/*----------.								\
	| DEC C (?) |								\
	'----------*/								\
	defined(__alpha) ||							\
										\
	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__alpha__) ||							\
										\
	/*-----------.								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_ALPHA)

#	define Z_ISA Z_ISA_ALPHA

/* MARK: - Blackfin */

#elif	/*-----------.								\
	| Clang v2.6 |								\
	'-----------*/								\
	defined(__ADSPBLACKFIN__  )						\
	defined(__ADSPLPBLACKFIN__)						\
	defined(__BFIN		  )						\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__BFIN__)							\
	defined(__bfin	)							\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	'-----------*/								\
	defined(__bfin__)							\
	defined(BFIN	)							\
	defined(bfin	)

#	define Z_ISA Z_ISA_BLACKFIN

/* MARK: - Convex */

#elif	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__convex__)

#	define Z_ISA Z_ISA_CONVEX

/* MARK: - Epiphany */

#elif	/*--.									\
	| ? |									\
	'--*/									\
	defined(__epiphany__)

#	define Z_ISA Z_ISA_EPIPHANY

/* MARK: - Hexagon */

#elif	/*-----------.								\
	| Clang v3.1 |								\
	'-----------*/								\
	defined(__HEXAGON_ARCH__)						\
	defined(__QDSP6_ARCH__	)						\
	defined(__hexagon	)						\
	defined(__hexagon__	)						\
	defined(__qdsp6		)						\
	defined(__qdsp6__	)						\
	defined(hexagon		)						\
	defined(qdsp6		)

#	define Z_ISA Z_ISA_HEXAGON

/* MARK: - Itanium */

#elif	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__IA64__) ||							\
										\
	/*----------.								\
	| GCC	    |								\
	| Intel C++ |								\
	'----------*/								\
	defined(__ia64__) ||							\
										\
	/*----------.								\
	| GCC	    |								\
	| HP aC++   |								\
	| Intel C++ |								\
	'----------*/								\
	defined(__ia64) ||							\
										\
	/*----------.								\
	| GCC	    |								\
	| Intel C++ |								\
	'----------*/								\
	defined(__itanium__) ||							\
										\
	/*----.									\
	| GCC |									\
	'----*/									\
	defined(_IA64) ||							\
										\
	/*-----------.								\
	| Intel C++  |								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_IA64) ||							\
										\
	/*----------.								\
	| Indel C++ |								\
	'----------*/								\
	defined(ia64)

#	define Z_ISA Z_ISA_ITANIUM

/* MARK: - Lanai */

#elif	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__lanai__)

#	define Z_ISA Z_ISA_LANAI

/* MARK: - M68K */

#elif	/*--------------.							\
	| Stratus VOS C |							\
	'--------------*/							\
	defined(__MC68K__) ||							\
										\
	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__m68k__) ||							\
										\
	/*------.								\
	| SAS/C |								\
	'------*/								\
	defined(M68000)

#	define Z_ISA Z_ISA_M68K

/* MARK: - MIPS64 */

#elif	/*-----------.								\
	| Clang v3.2 |								\
	'-----------*/								\
	defined(__mips64  ) ||							\
	defined(__mips64__) ||							\
										\
	/*------------.								\
	| Clang	      |								\
	| GCC	      |								\
	| MIPSpro (?) |								\
	'------------*/								\
	(defined(__mips) && (__mips == 64 || __mips == 4 || __mips == 3)) ||	\
										\
	/*-----------.								\
	| Clang v3.5 |								\
	| MIPSpro    |								\
	'-----------*/								\
	(defined(_MIPS_ISA) &&							\
	 ((defined(_MIPS_ISA_MIPS64) && _MIPS_ISA == _MIPS_ISA_MIPS64) ||	\
										\
	  /*--------.								\
	  | MIPSpro |								\
	  '--------*/								\
 	  (defined(_MIPS_ISA_MIPS4 ) && _MIPS_ISA == _MIPS_ISA_MIPS4 ) ||	\
	  (defined(_MIPS_ISA_MIPS3 ) && _MIPS_ISA == _MIPS_ISA_MIPS3 )))

#	define Z_ISA Z_ISA_MIPS64

/* MARK: - MIPS */

#elif	/*------------.								\
	| CodeWarrior |								\
	'------------*/								\
	defined(__MIPS__) ||							\
										\
	/*-----------.								\
	| Clang v2.7 |								\
	| GCC	     |								\
	| MIPSpro    |								\
	'-----------*/								\
	defined(__mips) ||							\
										\
	/*-----------.								\
	| Clang v2.7 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__mips__) ||							\
										\
	/*-----------.								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_MRX000) ||							\
										\
	/*-----------.								\
	| Clang v2.7 |								\
	'-----------*/								\
	defined(_mips) ||							\
										\
	/*-----------.								\
	| Clang v2.7 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(mips)

#	define Z_ISA Z_ISA_MIPS

/* MARK: - MSP430 */

#elif	/*-----------.								\
	| Clang v2.6 |								\
	'-----------*/								\
	defined(__MSP430__) ||							\
	defined(MSP430	  )

#	define Z_ISA Z_ISA_MSP430

/* MARK: - PA-RISC 2.0 */

#elif	/*-----------------------.						\
	| Stratus VOS Standard C |						\
	'-----------------------*/						\
	defined(__HPPA20__) ||							\
										\
	/*-----------------------.						\
	| GCC			 |						\
	| Stratus VOS Standard C |						\
	'-----------------------*/						\
	defined(_PA_RISC2_0)

#	define Z_ISA Z_ISA_PA_RISC_2

/* MARK: - PA-RISC */

#elif	/*-----------------------.						\
	| Stratus VOS Standard C |						\
	'-----------------------*/						\
	defined(__HPPA__  ) ||							\
	defined(__HPPA11__) ||							\
										\
	/*--.									\
	| ? |									\
	'--*/									\
	defined(__hppa) ||							\
										\
	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__hppa__   ) ||							\
	defined(_PA_RISC1_0) ||							\
										\
	/*-----------------------.						\
	| GCC			 |						\
	| Stratus VOS Standard C |						\
	'-----------------------*/						\
	defined(_PA_RISC1_1)

#	define Z_ISA Z_ISA_PA_RISC

/* MARK: - PowerPC 64-bit */

#elif	/*-------------.							\
	| Clang v3.4   |							\
	| GCC	       |							\
	| IBM XL C/C++ |							\
	'-------------*/							\
	defined(__PPC64__    ) ||						\
	defined(__powerpc64__) ||						\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__ppc64__) ||							\
										\
	/*-----------------.							\
	| Clang v2.6	   |							\
	| GCC		   |							\
	| IBM XL C/C++ (?) |							\
	'-----------------*/							\
	defined(_ARCH_PPC64)

#	define Z_ISA Z_ISA_POWERPC_64BIT

/* MARK: - PowerPC 32-bit */

#elif	/*-----------.								\
	| Clang v2.6 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__POWERPC__) ||							\
										\
	/*-------------.							\
	| IBM XL C/C++ |							\
	'-------------*/							\
	defined(__PPC) ||							\
										\
	/*-------------.							\
	| Clang v2.8   |							\
	| GCC	       |							\
	| IBM XL C/C++ |							\
	'-------------*/							\
	defined(__PPC__) ||							\
										\
	/*------------.								\
	| CodeWarrior |								\
	'------------*/								\
	defined(__PPCBROADWAY__) ||						\
	defined(__PPCGECKO__   ) ||						\
										\
	/*-------------.							\
	| GCC	       |							\
	| IBM XL C/C++ |							\
	'-------------*/							\
	defined(__powerpc) ||							\
										\
	/*-------------.							\
	| Clang v2.7   |							\
	| GCC	       |							\
	| IBM XL C/C++ |							\
	'-------------*/							\
	defined(__powerpc__) ||							\
										\
	/*-----------.								\
	| Diab C/C++ |								\
	'-----------*/								\
	defined(__ppc) ||							\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__ppc__) ||							\
										\
	/*-----------------.							\
	| Clang v2.6	   |							\
	| GCC		   |							\
	| IBM XL C/C++ (?) |							\
	'-----------------*/							\
	defined(_ARCH_PPC) ||							\
										\
	/*-----------.								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_PPC)

#	define Z_ISA Z_ISA_POWERPC_32BIT

/* MARK: - RV64I */

#elif	/*-----------.								\
	| Clang v7.0 |								\
	'-----------*/								\
	defined(__riscv_xlen) && __riscv_xlen == 64

#	define Z_ISA Z_ISA_RV64I

/* MARK: - RV32I */

#elif	/*-----------.								\
	| Clang v7.0 |								\
	'-----------*/								\
	defined(__riscv_xlen) && __riscv_xlen == 32

#	define Z_ISA Z_ISA_RV32I

/* MARK: - SPARC V9 */

#elif	/*-----------.								\
	| Clang v3.3 |								\
	'-----------*/								\
	defined(__arch64__  ) ||						\
	defined(__sparc_v9__) ||						\
										\
	/*-----------.								\
	| Clang v3.3 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__sparc64__) ||							\
										\
	/*-----------.								\
	| Clang v3.3 |								\
	| Sun Studio |								\
	'-----------*/								\
	defined(__sparcv9) ||							\
										\
	/*-----------.								\
	| Clang v3.3 |								\
	'-----------*/								\
	defined(__sparcv9__)

#	define Z_ISA Z_ISA_SPARC_V9

/* MARK: - SPARC */

#elif	/*-----------.								\
	| Clang v2.6 |								\
	| GCC	     |								\
	| Sun Studio |								\
	'-----------*/								\
	defined(__sparc) ||							\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__sparc__) ||							\
										\
	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__sparc_v8__) ||						\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	| Sun Studio |								\
	'-----------*/								\
	defined(__sparcv8) ||							\
										\
	/*-----------.								\
	| Clang v3.8 |								\
	'-----------*/								\
	defined(__sparcv8__) ||							\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	'-----------*/								\
	defined(sparc)

#	define Z_ISA Z_ISA_SPARC

/* MARK: - SuperH 5 */

#elif	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__SH5__) && __SH5__ == 64

#	define Z_ISA Z_ISA_SUPERH_5

/* MARK: - SuperH */

#elif	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__sh__)

#	define Z_ISA Z_ISA_SUPERH

/* MARK: - xCORE */

#elif	/*-----------.								\
	| Clang v3.4 |								\
	'-----------*/								\
	defined(__XS1B__)

#	define Z_ISA Z_ISA_XCORE

/* MARK: - z/Architecture */

#elif	/*-------------------.							\
	| Dignus Systems/C   |							\
	| Dignus Systems/C++ |							\
	'-------------------*/							\
	defined(__SYSC_ZARCH__) ||						\
										\
	/*-----------.								\
	| Clang v2.6 |								\
	| GCC	     |								\
	'-----------*/								\
	defined(__s390x__) ||							\
										\
	/*-----------.								\
	| Clang v3.3 |								\
	'-----------*/								\
	defined(__zarch__)

#	define Z_ISA Z_ISA_Z_ARCHITECTURE

/* MARK: - ESA/390 */

#elif	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__s390__)

#	define Z_ISA Z_ISA_ESA_390

/* MARK: - ESA/370 */

#elif	/*-------------.							\
	| IBM XL C/C++ |							\
	'-------------*/							\
	defined(__370__	   ) ||							\
	defined(__THW_370__)

#	define Z_ISA Z_ISA_ESA_370

#endif

#endif /* Z_inspection_ISA_detection_H */
