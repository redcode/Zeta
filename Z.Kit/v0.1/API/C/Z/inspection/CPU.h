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
#include <Z/keys/endianness.h>
#include <Z/keys/value.h>

#ifdef Z_CPU_ARCHITECTURE
#	include <Z/constants/base.h>
#else
#	include <Z/inspection/compiler.h>

#	if Z_COMPILER_HAS_KEY(CPU_ARCHITECTURE)
#		define Z_CPU_ARCHITECTURE Z_COMPILER_KEY(CPU_ARCHITECTURE)
#	else
#		include <Z/inspection/CPU/detection.h>
#	endif
#endif

#if !defined(Z_CPU_ARCHITECTURE)
#	error "Target CPU architecture not defined."

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_6502
#	include <Z/inspection/CPU/modules/6502.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_AARCH32
#	include <Z/inspection/CPU/modules/AArch32.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_AARCH64
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

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_POWERPC_32BIT
#	include <Z/inspection/CPU/modules/PowerPC 32-bit.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_POWERPC_64BIT
#	include <Z/inspection/CPU/modules/PowerPC 64-bit.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_SPARC
#	include <Z/inspection/CPU/modules/SPARC.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_SPARC_V9
#	include <Z/inspection/CPU/modules/SPARC V9.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_SUPERH
#	include <Z/inspection/CPU/modules/SuperH.h>

#elif Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_SUPERH_5
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

#else
#	error "Target CPU architecture not supported."

#endif

#include <Z/inspection/CPU/completion.h>

#define Z_CPU_ARCHITECTURE_STRING Z_INSERT_CPU_ARCHITECTURE(Z_CPU_ARCHITECTURE_STRING_,)
#define Z_CPU_HAS(    WHAT )	  Z_CPU_HAS_##WHAT
#define Z_CPU_HAS_ISA(WHICH)	  Z_CPU_HAS_ISA_##WHICH
#define Z_CPU_BITS(   WHAT )	  Z_CPU_BITS_##WHAT

#ifdef Z_CPU_INTEGER_ENDIANNESS_ALL

	/*--------------------------------------------------------------.
	| On architectures with mixed endianness, the target endianness |
	| must be specified by the compiler inspection system.		|
	'--------------------------------------------------------------*/
#	if Z_CPU_INTEGER_ENDIANNESS_ALL == Z_ENDIANNESS_MIXED

#		if Z_COMPILER_HAS_KEY(INTEGER_ENDIANNESS_ALL)
#			define Z_CPU_INTEGER_ENDIANNESS(bits) Z_COMPILER_KEY(INTEGER_ENDIANNESS_ALL)
#		else
#			define Z_CPU_INTEGER_ENDIANNESS(bits) Z_COMPILER_KEY(INTEGER_ENDIANNESS_##bits##BIT)
#		endif

	/*--------------------------------------------------------------.
	| Architectures with the same endianness for every integer size	|
	| must only define the Z_CPU_INTEGER_ENDIANNESS_ALL macro.	|
	'--------------------------------------------------------------*/
#	else
#		define Z_CPU_INTEGER_ENDIANNESS(bits) Z_CPU_INTEGER_ENDIANNESS_ALL
#	endif

/*-----------------------------------------------------------------.
| Architectures with different endianness depending on the size of |
| the integer must define the Z_CPU_INTEGER_ENDIANNESS_<bits>BIT   |
| macro for each integer size supported.			   |
'-----------------------------------------------------------------*/
#else
#	define Z_CPU_INTEGER_ENDIANNESS(bits) Z_CPU_INTEGER_ENDIANNESS_##bits##BIT
#endif

/*-------------------------------------------------------------.
| Architectures with the same integer format for every integer |
| size must only define the Z_CPU_INTEGER_FORMAT_ALL macro.    |
'-------------------------------------------------------------*/
#ifdef Z_CPU_INTEGER_FORMAT_ALL

#	if Z_CPU_INTEGER_FORMAT_ALL == Z_INTEGER_FORMAT_2S_COMPLEMENT
#		define Z_CPU_INTEGER_FORMAT(bits) Z_VALUE_FORMAT_##bits##BIT_2S_COMPLEMENT_INTEGER
#	elif Z_CPU_INTEGER_FORMAT_ALL == Z_INTEGER_FORMAT_1S_COMPLEMENT
#		define Z_CPU_INTEGER_FORMAT(bits) Z_VALUE_FORMAT_##bits##BIT_1S_COMPLEMENT_INTEGER
#	endif

/*----------------------------------------------------------------------.
| Architectures with different integer formats depending on the size of |
| of the integer must define the Z_CPU_INTEGER_FORMAT_<bits>BIT macro	|
| for each integer size supported.					|
'----------------------------------------------------------------------*/
#else
#	define Z_CPU_INTEGER_FORMAT(bits) Z_CPU_INTEGER_FORMAT_##bits##BIT
#endif

#endif /* __Z_inspection_CPU_H__ */
