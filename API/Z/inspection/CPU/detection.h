/* Z Kit - inspection/CPU/detection.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#if	/*----------------------.						\
	| Clang			|						\
	| GCC			|						\
	| Oracle Solaris Studio |						\
	'----------------------*/						\
	defined(__amd64) ||							\
										\
	/*----------------------.						\
	| Clang			|						\
	| GCC			|						\
	| Oracle Solaris Studio |						\
	| PGI C/C++		|						\
	'----------------------*/						\
	defined(__amd64__) ||							\
										\
	/*----------------------.						\
	| Clang			|						\
	| GCC			|						\
	| Intel C++		|						\
	| Oracle Solaris Studio |						\
	'----------------------*/						\
	defined(__x86_64) ||							\
										\
	/*----------------------.						\
	| Clang			|						\
	| GCC			|						\
	| Intel C++		|						\
	| Oracle Solaris Studio |						\
	| PGI C/C++		|						\
	'----------------------*/						\
	defined(__x86_64__) ||							\
										\
	/*-----------.								\
	| Clang	     |								\
	| Intel C++  |								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_AMD64) ||							\
	defined(_M_X64	)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_X86_64

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
	| Clang	      |								\
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
	| Clang		|							\
	| GCC		|							\
	| Intel C++	|							\
	| MinGW		|							\
	| PGI C/C++	|							\
	| Stratus VOS C |							\
	| Sun Studio	|							\
	'--------------*/							\
	defined(__i386) ||							\
										\
	/*----------.								\
	| Clang	    |								\
	| GCC	    |								\
	| Intel C++ |								\
	| MinGW	    |								\
	| PGI C/C++ |								\
	'----------*/								\
	defined(__i386__) ||							\
										\
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__i486) ||							\
										\
	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__i486__) ||							\
										\
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__i586) ||							\
										\
	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__i586__) ||							\
										\
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__i686) ||							\
										\
	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__i686__) ||							\
										\
	/*------.								\
	| Clang |								\
	| MinGW |								\
	'------*/								\
	defined(_X86_) ||							\
										\
	/*-------------.							\
	| Watcom C/C++ |							\
	'-------------*/							\
	defined(M_I386) ||							\
										\
	/*----------------------.						\
	| Clang			|						\
	| GCC			|						\
	| Intel C++		|						\
	| MinGW			|						\
	| Oracle Solaris Studio |						\
	| PGI C/C++		|						\
	'----------------------*/						\
	defined(i386) ||							\
										\
	/*-------------.							\
	| Clang	       |							\
	| Digital Mars |							\
	| Intel C++    |							\
	| Visual C++   |							\
	| Watcom C/C++ |							\
	'-------------*/							\
	(defined(_M_IX86) && !defined(__WATCOMC__))

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_X86_32

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

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_X86_16

#elif	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__aarch64__) ||							\
										\
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__arm64) ||							\
	defined(__arm64__)							\
										\
	/*--------------------------------------------------------------.	\
	| Visual C++ (not implemented yet, found in the Windows 10 SDK) |	\
	'--------------------------------------------------------------*/	\
	defined(_M_ARM64)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_AARCH64

#elif	/*-------------------.							\
	| ARM C/C++ Compiler |							\
	'-------------------*/							\
	defined(__TARGET_ARCH_ARM  ) ||						\
	defined(__TARGET_ARCH_THUMB) ||						\
										\
	/*-------------------.							\
	| Clang		     |							\
	| GCC		     |							\
	| ARM C/C++ Compiler |							\
	'-------------------*/							\
	defined(__arm__) ||							\
										\
	/*-----------.								\
	| Clang	     |								\
	| Diab C/C++ |								\
	'-----------*/								\
	defined(__arm) ||							\
										\
	/*-------------------.							\
	| Clang		     |							\
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
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(_ARM_) ||							\
										\
	/*-----------.								\
	| Clang	     |								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_ARM) ||							\
										\
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(_M_ARM_NT) ||							\
										\
	/*-----------.								\
	| Clang	     |								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_ARMT) ||							\
										\
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(_M_THUMB)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_AARCH32

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

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_6502

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

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_ALPHA

#elif	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__BFIN__) ||							\
	defined(__bfin	)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_BLACKFIN

#elif	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__convex__)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_CONVEX

#elif	/*--.									\
	| ? |									\
	'--*/									\
	defined(__epiphany__)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_EPIPHANY

#elif	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__HEXAGON_ARCH__) ||						\
	defined(__QDSP6_ARCH__	) ||						\
	defined(__hexagon__	) ||						\
	defined(__qdsp6__	)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_HEXAGON

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

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_ITANIUM

#elif	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__lanai__)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_LANAI

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

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_M68K

#elif	/*------.								\
	| Clang |								\
	'------*/								\
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
	/*--------.								\
	| Clang	  |								\
	| MIPSpro |								\
	'--------*/								\
	(defined(_MIPS_ISA) &&							\
	 ((defined(_MIPS_ISA_MIPS64) && _MIPS_ISA == _MIPS_ISA_MIPS64) ||	\
 	  (defined(_MIPS_ISA_MIPS4 ) && _MIPS_ISA == _MIPS_ISA_MIPS4 ) ||	\
	  (defined(_MIPS_ISA_MIPS3 ) && _MIPS_ISA == _MIPS_ISA_MIPS3 )))

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_MIPS64

#elif	/*------------.								\
	| CodeWarrior |								\
	'------------*/								\
	defined(__MIPS__) ||							\
										\
	/*--------.								\
	| Clang	  |								\
	| GCC	  |								\
	| MIPSpro |								\
	'--------*/								\
	defined(__mips) ||							\
										\
	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__mips__) ||							\
										\
	/*-----------.								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_MRX000) ||							\
										\
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(_mips) ||							\
										\
	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(mips)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_MIPS

#elif	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__MSP430__) ||							\
	defined(MSP430	  )

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_MSP430

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

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_PA_RISC_2

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

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_PA_RISC

#elif	/*-------------.							\
	| Clang	       |							\
	| GCC	       |							\
	| IBM XL C/C++ |							\
	'-------------*/							\
	defined(__PPC64__    ) ||						\
	defined(__powerpc64__) ||						\
										\
	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__ppc64__) ||							\
										\
	/*-----------------.							\
	| Clang		   |							\
	| GCC		   |							\
	| IBM XL C/C++ (?) |							\
	'-----------------*/							\
	defined(_ARCH_PPC64)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_POWERPC_64BIT

#elif	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__POWERPC__) ||							\
										\
	/*-------------.							\
	| IBM XL C/C++ |							\
	'-------------*/							\
	defined(__PPC) ||							\
										\
	/*-------------.							\
	| Clang	       |							\
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
	| Clang	       |							\
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
	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__ppc__) ||							\
										\
	/*-----------------.							\
	| Clang		   |							\
	| GCC		   |							\
	| IBM XL C/C++ (?) |							\
	'-----------------*/							\
	defined(_ARCH_PPC) ||							\
										\
	/*-----------.								\
	| Visual C++ |								\
	'-----------*/								\
	defined(_M_PPC)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_POWERPC_32BIT

#elif	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__riscv_xlen) && __riscv_xlen == 64

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_RV64I

#elif	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__riscv_xlen) && __riscv_xlen == 32

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_RV32I

#elif	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__arch64__  ) ||						\
	defined(__sparc_v9__) ||						\
										\
	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__sparc64__) ||							\
										\
	/*-----------.								\
	| Clang	     |								\
	| Sun Studio |								\
	'-----------*/								\
	defined(__sparcv9) ||							\
										\
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__sparcv9__)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_SPARC_V9

#elif	/*-----------.								\
	| Clang	     |								\
	| GCC	     |								\
	| Sun Studio |								\
	'-----------*/								\
	defined(__sparc) ||							\
										\
	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__sparc__) ||							\
										\
	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__sparc_v8__) ||						\
										\
	/*-----------.								\
	| Clang	     |								\
	| Sun Studio |								\
	'-----------*/								\
	defined(__sparcv8) ||							\
										\
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__sparcv8__) ||							\
	defined(sparc	   )

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_SPARC

#elif	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__SH5__) && __SH5__ == 64

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_SUPERH_5

#elif	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__sh__)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_SUPERH

#elif	/*-------------------.							\
	| Dignus Systems/C   |							\
	| Dignus Systems/C++ |							\
	'-------------------*/							\
	defined(__SYSC_ZARCH__) ||						\
										\
	/*------.								\
	| Clang |								\
	| GCC	|								\
	'------*/								\
	defined(__s390x__) ||							\
										\
	/*------.								\
	| Clang |								\
	'------*/								\
	defined(__zarch__)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_Z_ARCHITECTURE

#elif	/*----.									\
	| GCC |									\
	'----*/									\
	defined(__s390__)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_ESA_390

#elif	/*-------------.							\
	| IBM XL C/C++ |							\
	'-------------*/							\
	defined(__370__	   ) ||							\
	defined(__THW_370__)

#	define Z_CPU_ARCHITECTURE Z_CPU_ARCHITECTURE_ESA_370

#endif

/* inspection/CPU/detection.h EOF */
