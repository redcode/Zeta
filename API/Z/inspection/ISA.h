/* Zeta API - Z/inspection/ISA.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_ISA_H
#define Z_inspection_ISA_H

#include <Z/keys/ISA.h>
#include <Z/keys/endianness.h>

#ifndef Z_ISA
#	include <Z/inspection/compiler.h>

#	ifdef Z_COMPILER_ISA
#		define Z_ISA Z_COMPILER_ISA
#	else
#		include <Z/inspection/ISA/detection.h>
#	endif
#endif

#ifndef Z_ISA
#	define Z_ISA			Z_ISA_UNKNOWN
#	define Z_ISA_IS_UNKNOWN		1
#	define Z_ISA_NAME		"unknown ISA"
#elif Z_ISA == Z_ISA_6502
#	define Z_ISA_IS_6502		1
#	define Z_ISA_NAME		Z_ISA_NAME_6502
#elif Z_ISA == Z_ISA_AARCH32
#	define Z_ISA_IS_AARCH32		1
#	define Z_ISA_NAME		Z_ISA_NAME_AARCH32
#elif Z_ISA == Z_ISA_AARCH64
#	define Z_ISA_IS_AARCH64		1
#	define Z_ISA_NAME		Z_ISA_NAME_AARCH64
#elif Z_ISA == Z_ISA_ALPHA
#	define Z_ISA_IS_ALPHA		1
#	define Z_ISA_NAME		Z_ISA_NAME_ALPHA
#elif Z_ISA == Z_ISA_ARC
#	define Z_ISA_IS_ARC		1
#	define Z_ISA_NAME		Z_ISA_NAME_ARC
#elif Z_ISA == Z_ISA_BLACKFIN
#	define Z_ISA_IS_BLACKFIN	1
#	define Z_ISA_NAME		Z_ISA_NAME_BLACKFIN
#elif Z_ISA == Z_ISA_CONVEX
#	define Z_ISA_IS_CONVEX		1
#	define Z_ISA_NAME		Z_ISA_NAME_CONVEX
#elif Z_ISA == Z_ISA_EPIPHANY
#	define Z_ISA_IS_EPIPHANY	1
#	define Z_ISA_NAME		Z_ISA_NAME_EPIPHANY
#elif Z_ISA == Z_ISA_ESA_370
#	define Z_ISA_IS_ESA_370		1
#	define Z_ISA_NAME		Z_ISA_NAME_ESA_370
#elif Z_ISA == Z_ISA_ESA_390
#	define Z_ISA_IS_ESA_390		1
#	define Z_ISA_NAME		Z_ISA_NAME_ESA_390
#elif Z_ISA == Z_ISA_HEXAGON
#	define Z_ISA_IS_HEXAGON		1
#	define Z_ISA_NAME		Z_ISA_NAME_HEXAGON
#elif Z_ISA == Z_ISA_IA_64
#	define Z_ISA_IS_IA_64		1
#	define Z_ISA_NAME		Z_ISA_NAME_IA_64
#elif Z_ISA == Z_ISA_LA32R
#	define Z_ISA_IS_LA32R		1
#	define Z_ISA_NAME		Z_ISA_NAME_LA32R
#elif Z_ISA == Z_ISA_LA32S
#	define Z_ISA_IS_LA32S		1
#	define Z_ISA_NAME		Z_ISA_NAME_LA32S
#elif Z_ISA == Z_ISA_LA64
#	define Z_ISA_IS_LA64		1
#	define Z_ISA_NAME		Z_ISA_NAME_LA64
#elif Z_ISA == Z_ISA_LANAI
#	define Z_ISA_IS_LANAI		1
#	define Z_ISA_NAME		Z_ISA_NAME_LANAI
#elif Z_ISA == Z_ISA_LATTICE_MICO_32
#	define Z_ISA_IS_LATTICE_MICO_32 1
#	define Z_ISA_NAME		Z_ISA_NAME_LATTICE_MICO_32
#elif Z_ISA == Z_ISA_M68K
#	define Z_ISA_IS_M68K		1
#	define Z_ISA_NAME		Z_ISA_NAME_M68K
#elif Z_ISA == Z_ISA_MIPS
#	define Z_ISA_IS_MIPS		1
#	define Z_ISA_NAME		Z_ISA_NAME_MIPS
#elif Z_ISA == Z_ISA_MIPS64
#	define Z_ISA_IS_MIPS64		1
#	define Z_ISA_NAME		Z_ISA_NAME_MIPS64
#elif Z_ISA == Z_ISA_MSP430
#	define Z_ISA_IS_MSP430		1
#	define Z_ISA_NAME		Z_ISA_NAME_MSP430
#elif Z_ISA == Z_ISA_PA_RISC
#	define Z_ISA_IS_PA_RISC		1
#	define Z_ISA_NAME		Z_ISA_NAME_PA_RISC
#elif Z_ISA == Z_ISA_PA_RISC_2
#	define Z_ISA_IS_PA_RISC_2	1
#	define Z_ISA_NAME		Z_ISA_NAME_PA_RISC_2
#elif Z_ISA == Z_ISA_POWERPC_32BIT
#	define Z_ISA_IS_POWERPC_32BIT	1
#	define Z_ISA_NAME		Z_ISA_NAME_POWERPC_32BIT
#elif Z_ISA == Z_ISA_POWERPC_64BIT
#	define Z_ISA_IS_POWERPC_64BIT	1
#	define Z_ISA_NAME		Z_ISA_NAME_POWERPC_64BIT
#elif Z_ISA == Z_ISA_RV32E
#	define Z_ISA_IS_RV32E		1
#	define Z_ISA_NAME		Z_ISA_NAME_RV32E
#elif Z_ISA == Z_ISA_RV32I
#	define Z_ISA_IS_RV32I		1
#	define Z_ISA_NAME		Z_ISA_NAME_RV32I
#elif Z_ISA == Z_ISA_RV64E
#	define Z_ISA_IS_RV64E		1
#	define Z_ISA_NAME		Z_ISA_NAME_RV64E
#elif Z_ISA == Z_ISA_RV64I
#	define Z_ISA_IS_RV64I		1
#	define Z_ISA_NAME		Z_ISA_NAME_RV64I
#elif Z_ISA == Z_ISA_RV128I
#	define Z_ISA_IS_RV128I		1
#	define Z_ISA_NAME		Z_ISA_NAME_RV128I
#elif Z_ISA == Z_ISA_SPARC
#	define Z_ISA_IS_SPARC		1
#	define Z_ISA_NAME		Z_ISA_NAME_SPARC
#elif Z_ISA == Z_ISA_SPARC_V9
#	define Z_ISA_IS_SPARC_V9	1
#	define Z_ISA_NAME		Z_ISA_NAME_SPARC_V9
#elif Z_ISA == Z_ISA_SUPERH
#	define Z_ISA_IS_SUPERH		1
#	define Z_ISA_NAME		Z_ISA_NAME_SUPERH
#elif Z_ISA == Z_ISA_SUPERH_5
#	define Z_ISA_IS_SUPERH_5	1
#	define Z_ISA_NAME		Z_ISA_NAME_SUPERH_5
#elif Z_ISA == Z_ISA_VAX
#	define Z_ISA_IS_VAX		1
#	define Z_ISA_NAME		Z_ISA_NAME_VAX
#elif Z_ISA == Z_ISA_WASM32
#	define Z_ISA_IS_WASM32		1
#	define Z_ISA_NAME		Z_ISA_NAME_WASM32
#elif Z_ISA == Z_ISA_WASM64
#	define Z_ISA_IS_WASM64		1
#	define Z_ISA_NAME		Z_ISA_NAME_WASM64
#elif Z_ISA == Z_ISA_X86_16
#	define Z_ISA_IS_X86_16		1
#	define Z_ISA_NAME		Z_ISA_NAME_X86_16
#elif Z_ISA == Z_ISA_X86_32
#	define Z_ISA_IS_X86_32		1
#	define Z_ISA_NAME		Z_ISA_NAME_X86_32
#elif Z_ISA == Z_ISA_X86_64
#	define Z_ISA_IS_X86_64		1
#	define Z_ISA_NAME		Z_ISA_NAME_X86_64
#elif Z_ISA == Z_ISA_XCORE
#	define Z_ISA_IS_XCORE		1
#	define Z_ISA_NAME		Z_ISA_NAME_XCORE
#elif Z_ISA == Z_ISA_Z_ARCHITECTURE
#	define Z_ISA_IS_Z_ARCHITECTURE	1
#	define Z_ISA_NAME		Z_ISA_NAME_Z_ARCHITECTURE
#elif Z_ISA == Z_ISA_Z80
#	define Z_ISA_IS_Z80		1
#	define Z_ISA_NAME		Z_ISA_NAME_Z80
#else
#	error "Invalid Z_ISA key."
#endif

#ifndef Z_ISA_INTEGRAL_ENDIANNESS
#	ifdef Z_COMPILER_ISA_INTEGRAL_ENDIANNESS
#		define Z_ISA_INTEGRAL_ENDIANNESS Z_COMPILER_ISA_INTEGRAL_ENDIANNESS

#	elif	Z_ISA == Z_ISA_6502	|| \
		Z_ISA == Z_ISA_BLACKFIN || \
		Z_ISA == Z_ISA_EPIPHANY || \
		Z_ISA == Z_ISA_HEXAGON	|| \
		Z_ISA == Z_ISA_LA32R	|| \
		Z_ISA == Z_ISA_LA32S	|| \
		Z_ISA == Z_ISA_LA64	|| \
		Z_ISA == Z_ISA_MSP430	|| \
		Z_ISA == Z_ISA_VAX	|| \
		Z_ISA == Z_ISA_WASM32	|| \
		Z_ISA == Z_ISA_WASM64	|| \
		Z_ISA == Z_ISA_X86_16	|| \
		Z_ISA == Z_ISA_X86_32	|| \
		Z_ISA == Z_ISA_X86_64	|| \
		Z_ISA == Z_ISA_XCORE	|| \
		Z_ISA == Z_ISA_Z80

#		define Z_ISA_INTEGRAL_ENDIANNESS Z_ENDIANNESS_LITTLE

#	elif	Z_ISA == Z_ISA_CONVEX	       || \
		Z_ISA == Z_ISA_ESA_370	       || \
		Z_ISA == Z_ISA_ESA_390	       || \
		Z_ISA == Z_ISA_LANAI	       || \
		Z_ISA == Z_ISA_LATTICE_MICO_32 || \
		Z_ISA == Z_ISA_M68K	       || \
		Z_ISA == Z_ISA_SPARC	       || \
		Z_ISA == Z_ISA_Z_ARCHITECTURE

#		define Z_ISA_INTEGRAL_ENDIANNESS Z_ENDIANNESS_BIG

#	elif Z_ISA == Z_ISA_UNKNOWN
#		error "It is necessary to define `Z_ISA_INTEGRAL_ENDIANNESS` for unknown ISAs."
#	else
#		error "It is necessary to define `Z_ISA_INTEGRAL_ENDIANNESS` for bi-endian ISAs not handled by the compiler driver."
#	endif
#endif

#define Z_ISA_IS(	   ISA ) Z_IS_TRUE(Z_ISA_IS_##ISA		 )
#define Z_ISA_HAS_INTEGRAL(bits) Z_IS_TRUE(Z_ISA_HAS_INTEGRAL_##bits##BIT)

#endif /* Z_inspection_ISA_H */
