/* Zeta API - Z/inspection/ISA.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_ISA_H
#define Z_inspection_ISA_H

#include <Z/keys/ISA.h>
#include <Z/keys/endianness.h>
#include <Z/keys/number.h>

#ifdef Z_ISA_HEADER
#	include Z_ISA_HEADER

#else
#	ifndef Z_ISA
#		include <Z/inspection/compiler.h>

#		ifdef Z_COMPILER_ISA
#			define Z_ISA Z_COMPILER_ISA
#		else
#			include <Z/inspection/ISA/detection.h>

#			ifndef Z_ISA
#				error "Z_ISA not defined."
#			endif
#		endif
#	endif

#	if Z_ISA == Z_ISA_6502
#		include <Z/inspection/ISA/modules/6502.h>

#	elif Z_ISA == Z_ISA_AARCH32
#		include <Z/inspection/ISA/modules/AArch32.h>

#	elif Z_ISA == Z_ISA_AARCH64
#		include <Z/inspection/ISA/modules/AArch64.h>

#	elif Z_ISA == Z_ISA_ALPHA
#		include <Z/inspection/ISA/modules/Alpha.h>

#	elif Z_ISA == Z_ISA_ARC
#		include <Z/inspection/ISA/modules/ARC.h>

#	elif Z_ISA == Z_ISA_BLACKFIN
#		include <Z/inspection/ISA/modules/Blackfin.h>

#	elif Z_ISA == Z_ISA_CONVEX
#		include <Z/inspection/ISA/modules/Convex.h>

#	elif Z_ISA == Z_ISA_EPIPHANY
#		include <Z/inspection/ISA/modules/Epiphany.h>

#	elif Z_ISA == Z_ISA_ESA_370
#		include <Z/inspection/ISA/modules/ESA-370.h>

#	elif Z_ISA == Z_ISA_ESA_390
#		include <Z/inspection/ISA/modules/ESA-390.h>

#	elif Z_ISA == Z_ISA_HEXAGON
#		include <Z/inspection/ISA/modules/Hexagon.h>

#	elif Z_ISA == Z_ISA_IA_64
#		include <Z/inspection/ISA/modules/IA-64.h>

#	elif Z_ISA == Z_ISA_LANAI
#		include <Z/inspection/ISA/modules/Lanai.h>

#	elif Z_ISA == Z_ISA_LATTICE_MICO_32
#		include <Z/Inspection/ISA/modules/LatticeMico32.h>

#	elif Z_ISA == Z_ISA_M68K
#		include <Z/inspection/ISA/modules/M68K.h>

#	elif Z_ISA == Z_ISA_MIPS
#		include <Z/inspection/ISA/modules/MIPS.h>

#	elif Z_ISA == Z_ISA_MIPS64
#		include <Z/inspection/ISA/modules/MIPS64.h>

#	elif Z_ISA == Z_ISA_MSP430
#		include <Z/inspection/ISA/modules/MSP430.h>

#	elif Z_ISA == Z_ISA_PA_RISC
#		include <Z/inspection/ISA/modules/PA-RISC.h>

#	elif Z_ISA == Z_ISA_PA_RISC_2
#		include <Z/inspection/ISA/modules/PA-RISC 2.0.h>

#	elif Z_ISA == Z_ISA_POWERPC_32BIT
#		include <Z/inspection/ISA/modules/PowerPC 32-bit.h>

#	elif Z_ISA == Z_ISA_POWERPC_64BIT
#		include <Z/inspection/ISA/modules/PowerPC 64-bit.h>

#	elif Z_ISA == Z_ISA_RV32E
#		include <Z/inspection/ISA/modules/RV32E.h>

#	elif Z_ISA == Z_ISA_RV32I
#		include <Z/inspection/ISA/modules/RV32I.h>

#	elif Z_ISA == Z_ISA_RV64I
#		include <Z/inspection/ISA/modules/RV64I.h>

#	elif Z_ISA == Z_ISA_RV128I
#		include <Z/inspection/ISA/modules/RV128I.h>

#	elif Z_ISA == Z_ISA_SPARC
#		include <Z/inspection/ISA/modules/SPARC.h>

#	elif Z_ISA == Z_ISA_SPARC_V9
#		include <Z/inspection/ISA/modules/SPARC V9.h>

#	elif Z_ISA == Z_ISA_SUPERH
#		include <Z/inspection/ISA/modules/SuperH.h>

#	elif Z_ISA == Z_ISA_SUPERH_5
#		include <Z/inspection/ISA/modules/SuperH 5.h>

#	elif Z_ISA == Z_ISA_WASM32
#		include <Z/inspection/ISA/modules/Wasm32.h>

#	elif Z_ISA == Z_ISA_WASM64
#		include <Z/inspection/ISA/modules/Wasm64.h>

#	elif Z_ISA == Z_ISA_X86_16
#		include <Z/inspection/ISA/modules/x86-16.h>

#	elif Z_ISA == Z_ISA_X86_32
#		include <Z/inspection/ISA/modules/x86-32.h>

#	elif Z_ISA == Z_ISA_X86_64
#		include <Z/inspection/ISA/modules/x86-64.h>

#	elif Z_ISA == Z_ISA_XCORE
#		include <Z/inspection/ISA/modules/xCORE.h>

#	elif Z_ISA == Z_ISA_Z_ARCHITECTURE
#		include <Z/inspection/ISA/modules/z-Architecture.h>

#	elif Z_ISA == Z_ISA_Z80
#		include <Z/inspection/ISA/modules/Z80.h>

#	else
#		error "Invalid Z_ISA key."
#	endif
#endif

#define Z_ISA_IS(	   ISA	  ) Z_IS_TRUE(Z_ISA_IS_##ISA		    )
#define Z_ISA_HAS_INTEGRAL(bits	  ) Z_IS_TRUE(Z_ISA_HAS_INTEGRAL_##bits##BIT)
#define Z_ISA_HAS_REAL(	   FORMAT ) Z_IS_TRUE(Z_ISA_HAS_REAL_##FORMAT	    )
#define Z_ISA_BITS(	   OF_WHAT) Z_ISA_BITS_##OF_WHAT

#ifndef Z_ISA_INTEGRAL_ENDIANNESS
#	ifdef Z_COMPILER_ISA_INTEGRAL_ENDIANNESS
#		define Z_ISA_INTEGRAL_ENDIANNESS Z_COMPILER_ISA_INTEGRAL_ENDIANNESS
#	else
#		error ""
#	endif
#endif

#endif /* Z_inspection_ISA_H */
