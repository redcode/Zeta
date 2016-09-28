/* Z Kit C API - inspection/CPU.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_CPU_H__
#define __Z_inspection_CPU_H__

#include <Z/keys/hardware/CPU/architecture.h>

#ifndef Z_CPU_ARCHITECTURE

#	include <Z/inspection/compiler.h>

#	if Z_COMPILER_HAS_KEY(CPU_ARCHITECTURE)
#		define Z_CPU_ARCHITECTURE Z_COMPILER_KEY(CPU_ARCHITECTURE)
#	else
#		include <Z/inspection/CPU/detection.h>
#	endif

#endif

#if !defined(Z_CPU_ARCHITECTURE)
#	error "Target Processor architecture not defined."

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_6502
#	include <Z/inspection/CPU/modules/6502.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_A_ARCH_32
#	include <Z/inspection/CPU/modules/AArch32.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_A_ARCH_64
#	include <Z/inspection/CPU/modules/AArch64.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_ALPHA
#	include <Z/inspection/CPU/modules/Alpha.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_BLACKFIN
#	include <Z/inspection/CPU/modules/Blackfin.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_CONVEX
#	include <Z/inspection/CPU/modules/Convex.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_EPIPHANY
#	include <Z/inspection/CPU/modules/Epiphany.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_ESA_370
#	include <Z/inspection/CPU/modules/ESA/370.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_ESA_390
#	include <Z/inspection/CPU/modules/ESA/390.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_HEXAGON
#	include <Z/inspection/CPU/modules/Hexagon.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_ITANIUM
#	include <Z/inspection/CPU/modules/Itanium.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_LANAI
#	include <Z/inspection/CPU/modules/Lanai.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_M68K
#	include <Z/inspection/CPU/modules/M68K.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_MIPS
#	include <Z/inspection/CPU/modules/MIPS.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_MIPS
#	include <Z/inspection/CPU/modules/MIPS64.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_MSP430
#	include <Z/inspection/CPU/modules/MSP430.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_PA_RISC
#	include <Z/inspection/CPU/modules/PA-RISC.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_PA_RISC_2
#	include <Z/inspection/CPU/modules/PA-RISC 2.0.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_POWER_PC_32BIT
#	include <Z/inspection/CPU/modules/PowerPC 32-bit.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_POWER_PC_64BIT
#	include <Z/inspection/CPU/modules/PowerPC 64-bit.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_SPARC
#	include <Z/inspection/CPU/modules/SPARC.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_SPARC_V9
#	include <Z/inspection/CPU/modules/SPARC V9.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_SUPER_H
#	include <Z/inspection/CPU/modules/SuperH.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_SUPER_H_5
#	include <Z/inspection/CPU/modules/SuperH 5.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_16
#	include <Z/inspection/CPU/modules/x86-16.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_32
#	include <Z/inspection/CPU/modules/x86-32.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_64
#	include <Z/inspection/CPU/modules/x86-64.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_Z_ARCHITECTURE
#	include <Z/inspection/CPU/modules/z/Architecture.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_Z80
#	include <Z/inspection/CPU/modules/Z80.h>

#endif

#define Z_CPU_FAMILY
#define Z_CPU_ARCHITECTURE_STRING      Z_INSERT_CPU_ARCHITECTURE(Z_CPU_ARCHITECTURE_STRING_,)
#define Z_CPU_VARIABLE(WHICH)	       Z_CPU_##WHICH
#define Z_CPU_HAS(     WHAT )	       Z_CPU_HAS_##WHAT
#define Z_CPU_HAS_ISA( WHICH)	       Z_CPU_HAS_ISA_##WHICH

#ifdef Z_CPU_ARCHITECTURE_INTEGER_ENDIANNESS

	/*----------------------------------------------------------.
	| The target endianness must be specified by the compiler   |
	| inspection system on architectures with mixed endianness. |
	'----------------------------------------------------------*/
#	if Z_CPU_ARCHITECTURE_INTEGER_ENDIANNESS == Z_ENDIANNESS_MIXED

#		if Z_COMPILER_HAS_KEY(INTEGER_ENDIANNESS)
#			define Z_CPU_INTEGER_ENDIANNESS(bits) Z_COMPILER_KEY(INTEGER_ENDIANNESS)
#		else
#			define Z_CPU_INTEGER_ENDIANNESS(bits) Z_COMPILER_KEY(INTEGER_ENDIANNESS_##bits##BIT)
#		endif

	/*------------------------------------------------------------------.
	| Architectures with the same endianness for every integer size	    |
	| must only define the Z_CPU_ARCHITECTURE_INTEGER_ENDIANNESS macro. |
	'------------------------------------------------------------------*/
#	else
#		define Z_CPU_INTEGER_ENDIANNESS(bits) Z_CPU_ARCHITECTURE_INTEGER_ENDIANNESS
#	endif

/*------------------------------------------------------------------------.
| Architectures with different endianness depending of the size of the	  |
| integer must define the Z_CPU_ARCHITECTURE_INTEGER_ENDIANNESS_<bits>BIT |
| macro for each integer size supported.				  |
'------------------------------------------------------------------------*/
#else
#	define Z_CPU_INTEGER_ENDIANNESS(bits) Z_CPU_ARCHITECTURE_INTEGER_ENDIANNESS_##bits##BIT
#endif

#if Z_CPU_ARCHITECTURE_INTEGER_FORMAT == Z_INTEGER_FORMAT_2S_COMPLEMENT
#	define Z_CPU_INTEGER_FORMAT(bits) Z_VALUE_FORMAT_##bits##BIT_2S_COMPLEMENT_INTEGER
#elif Z_CPU_ARCHITECTURE_INTEGER_FORMAT == Z_INTEGER_FORMAT_1S_COMPLEMENT
#	define Z_CPU_INTEGER_FORMAT(bits) Z_VALUE_FORMAT_##bits##BIT_1S_COMPLEMENT_INTEGER
#endif

#endif /* __Z_inspection_CPU_H__ */
