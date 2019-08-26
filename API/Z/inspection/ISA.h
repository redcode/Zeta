/* Z Kit - inspection/ISA.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_ISA_H
#define Z_inspection_ISA_H

#include <Z/keys/ISA.h>
#include <Z/keys/endianness.h>
#include <Z/keys/number.h>
#include <Z/inspection/compiler.h>

#ifndef Z_ISA

#	ifdef Z_COMPILER_ISA
#		define Z_ISA Z_COMPILER_ISA
#	else
#		include <Z/inspection/ISA/detection.h>

#		ifndef Z_ISA
#			error "Z_ISA not defined."
#		endif
#	endif

#endif

#if Z_ISA == Z_ISA_6502
#	include <Z/inspection/ISA/modules/6502.h>

#elif Z_ISA == Z_ISA_AARCH32
#	include <Z/inspection/ISA/modules/AArch32.h>

#elif Z_ISA == Z_ISA_AARCH64
#	include <Z/inspection/ISA/modules/AArch64.h>

#elif Z_ISA == Z_ISA_ALPHA
#	include <Z/inspection/ISA/modules/Alpha.h>

#elif Z_ISA == Z_ISA_BLACKFIN
#	include <Z/inspection/ISA/modules/Blackfin.h>

#elif Z_ISA == Z_ISA_CONVEX
#	include <Z/inspection/ISA/modules/Convex.h>

#elif Z_ISA == Z_ISA_EPIPHANY
#	include <Z/inspection/ISA/modules/Epiphany.h>

#elif Z_ISA == Z_ISA_ESA_370
#	include <Z/inspection/ISA/modules/ESA-370.h>

#elif Z_ISA == Z_ISA_ESA_390
#	include <Z/inspection/ISA/modules/ESA-390.h>

#elif Z_ISA == Z_ISA_HEXAGON
#	include <Z/inspection/ISA/modules/Hexagon.h>

#elif Z_ISA == Z_ISA_ITANIUM
#	include <Z/inspection/ISA/modules/Itanium.h>

#elif Z_ISA == Z_ISA_LANAI
#	include <Z/inspection/ISA/modules/Lanai.h>

#elif Z_ISA == Z_ISA_M68K
#	include <Z/inspection/ISA/modules/M68K.h>

#elif Z_ISA == Z_ISA_MIPS
#	include <Z/inspection/ISA/modules/MIPS.h>

#elif Z_ISA == Z_ISA_MIPS64
#	include <Z/inspection/ISA/modules/MIPS64.h>

#elif Z_ISA == Z_ISA_MSP430
#	include <Z/inspection/ISA/modules/MSP430.h>

#elif Z_ISA == Z_ISA_PA_RISC
#	include <Z/inspection/ISA/modules/PA-RISC.h>

#elif Z_ISA == Z_ISA_PA_RISC_2
#	include <Z/inspection/ISA/modules/PA-RISC 2.0.h>

#elif Z_ISA == Z_ISA_POWERPC_32BIT
#	include <Z/inspection/ISA/modules/PowerPC 32-bit.h>

#elif Z_ISA == Z_ISA_POWERPC_64BIT
#	include <Z/inspection/ISA/modules/PowerPC 64-bit.h>

#elif Z_ISA == Z_ISA_RV32E
#	include <Z/inspection/ISA/modules/RV32E.h>

#elif Z_ISA == Z_ISA_RV32I
#	include <Z/inspection/ISA/modules/RV32I.h>

#elif Z_ISA == Z_ISA_RV64I
#	include <Z/inspection/ISA/modules/RV64I.h>

#elif Z_ISA == Z_ISA_RV128I
#	include <Z/inspection/ISA/modules/RV128I.h>

#elif Z_ISA == Z_ISA_SPARC
#	include <Z/inspection/ISA/modules/SPARC.h>

#elif Z_ISA == Z_ISA_SPARC_V9
#	include <Z/inspection/ISA/modules/SPARC V9.h>

#elif Z_ISA == Z_ISA_SUPERH
#	include <Z/inspection/ISA/modules/SuperH.h>

#elif Z_ISA == Z_ISA_SUPERH_5
#	include <Z/inspection/ISA/modules/SuperH 5.h>

#elif Z_ISA == Z_ISA_X86_16
#	include <Z/inspection/ISA/modules/x86-16.h>

#elif Z_ISA == Z_ISA_X86_32
#	include <Z/inspection/ISA/modules/x86-32.h>

#elif Z_ISA == Z_ISA_X86_64
#	include <Z/inspection/ISA/modules/x86-64.h>

#elif Z_ISA == Z_ISA_XCORE
#	include <Z/inspection/ISA/modules/xCORE.h>

#elif Z_ISA == Z_ISA_Z_ARCHITECTURE
#	include <Z/inspection/ISA/modules/z-Architecture.h>

#elif Z_ISA == Z_ISA_Z80
#	include <Z/inspection/ISA/modules/Z80.h>

#else
#	error "Invalid Z_ISA key."
#endif

#include <Z/inspection/ISA/completion.h>

#define Z_ISA_HAS_INTEGRAL(bits	 ) Z_ISA_HAS_INTEGRAL_##bits##BIT
#define Z_ISA_HAS_REAL(	  FORMAT ) Z_ISA_HAS_REAL_##FORMAT
#define Z_ISA_BITS(	  OF_WHAT) Z_ISA_BITS_##OF_WHAT

#if defined(Z_ISA_INTEGRAL_ENDIANNESS_ALL)
#	define Z_ISA_INTEGRAL_ENDIANNESS(bits) Z_ISA_INTEGRAL_ENDIANNESS_ALL

#elif defined(Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_ALL)
#	define Z_ISA_INTEGRAL_ENDIANNESS(bits) Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_ALL

#else
#	if !defined(Z_ISA_INTEGRAL_ENDIANNESS_16BIT) && defined(Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_16BIT)
#		define Z_ISA_INTEGRAL_ENDIANNESS_16BIT Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_16BIT
#	endif

#	if !defined(Z_ISA_INTEGRAL_ENDIANNESS_24BIT) && defined(Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_24BIT)
#		define Z_ISA_INTEGRAL_ENDIANNESS_24BIT Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_24BIT
#	endif

#	if !defined(Z_ISA_INTEGRAL_ENDIANNESS_32BIT) && defined(Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_32BIT)
#		define Z_ISA_INTEGRAL_ENDIANNESS_32BIT Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_32BIT
#	endif

#	if !defined(Z_ISA_INTEGRAL_ENDIANNESS_40BIT) && defined(Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_40BIT)
#		define Z_ISA_INTEGRAL_ENDIANNESS_40BIT Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_40BIT
#	endif

#	if !defined(Z_ISA_INTEGRAL_ENDIANNESS_48BIT) && defined(Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_48BIT)
#		define Z_ISA_INTEGRAL_ENDIANNESS_48BIT Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_48BIT
#	endif

#	if !defined(Z_ISA_INTEGRAL_ENDIANNESS_56BIT) && defined(Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_56BIT)
#		define Z_ISA_INTEGRAL_ENDIANNESS_56BIT Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_56BIT
#	endif

#	if !defined(Z_ISA_INTEGRAL_ENDIANNESS_64BIT) && defined(Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_64BIT)
#		define Z_ISA_INTEGRAL_ENDIANNESS_64BIT Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_64BIT
#	endif

#	if !defined(Z_ISA_INTEGRAL_ENDIANNESS_128BIT) && defined(Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_128BIT)
#		define Z_ISA_INTEGRAL_ENDIANNESS_128BIT Z_COMPILER_ISA_INTEGRAL_ENDIANNESS_128BIT
#	endif

#	define Z_ISA_INTEGRAL_ENDIANNESS(bits) Z_ISA_INTEGRAL_ENDIANNESS_##bits##BIT
#endif

#if defined(Z_ISA_INTEGER_FORMAT_ALL)

#	if Z_ISA_INTEGER_FORMAT_ALL == Z_INTEGER_FORMAT_2S_COMPLEMENT
#		define Z_ISA_INTEGER_FORMAT(bits) Z_NUMBER_FORMAT_2S_COMPLEMENT_##bits##BIT_INTEGER

#	elif Z_ISA_INTEGER_FORMAT_ALL == Z_INTEGER_FORMAT_1S_COMPLEMENT
#		define Z_ISA_INTEGER_FORMAT(bits) Z_NUMBER_FORMAT_1S_COMPLEMENT_##bits##BIT_INTEGER
#	endif

#elif defined(Z_COMPILER_ISA_INTEGER_FORMAT_ALL)

#	if Z_COMPILER_ISA_INTEGER_FORMAT_ALL == Z_INTEGER_FORMAT_2S_COMPLEMENT
#		define Z_ISA_INTEGER_FORMAT(bits) Z_NUMBER_FORMAT_2S_COMPLEMENT_##bits##BIT_INTEGER

#	elif Z_COMPILER_ISA_INTEGER_FORMAT_ALL == Z_INTEGER_FORMAT_1S_COMPLEMENT
#		define Z_ISA_INTEGER_FORMAT(bits) Z_NUMBER_FORMAT_1S_COMPLEMENT_##bits##BIT_INTEGER
#	endif

#else
#	if !defined(Z_ISA_INTEGER_FORMAT_8BIT) && defined(Z_COMPILER_ISA_INTEGER_FORMAT_8BIT)
#		define Z_ISA_INTEGER_FORMAT_8BIT Z_COMPILER_ISA_INTEGER_FORMAT_8BIT
#	endif

#	if !defined(Z_ISA_INTEGER_FORMAT_16BIT) && defined(Z_COMPILER_ISA_INTEGER_FORMAT_16BIT)
#		define Z_ISA_INTEGER_FORMAT_16BIT Z_COMPILER_ISA_INTEGER_FORMAT_16BIT
#	endif

#	if !defined(Z_ISA_INTEGER_FORMAT_24BIT) && defined(Z_COMPILER_ISA_INTEGER_FORMAT_24BIT)
#		define Z_ISA_INTEGER_FORMAT_24BIT Z_COMPILER_ISA_INTEGER_FORMAT_24BIT
#	endif

#	if !defined(Z_ISA_INTEGER_FORMAT_32BIT) && defined(Z_COMPILER_ISA_INTEGER_FORMAT_32BIT)
#		define Z_ISA_INTEGER_FORMAT_32BIT Z_COMPILER_ISA_INTEGER_FORMAT_32BIT
#	endif

#	if !defined(Z_ISA_INTEGER_FORMAT_40BIT) && defined(Z_COMPILER_ISA_INTEGER_FORMAT_40BIT)
#		define Z_ISA_INTEGER_FORMAT_40BIT Z_COMPILER_ISA_INTEGER_FORMAT_40BIT
#	endif

#	if !defined(Z_ISA_INTEGER_FORMAT_48BIT) && defined(Z_COMPILER_ISA_INTEGER_FORMAT_48BIT)
#		define Z_ISA_INTEGER_FORMAT_48BIT Z_COMPILER_ISA_INTEGER_FORMAT_48BIT
#	endif

#	if !defined(Z_ISA_INTEGER_FORMAT_56BIT) && defined(Z_COMPILER_ISA_INTEGER_FORMAT_56BIT)
#		define Z_ISA_INTEGER_FORMAT_56BIT Z_COMPILER_ISA_INTEGER_FORMAT_56BIT
#	endif

#	if !defined(Z_ISA_INTEGER_FORMAT_64BIT) && defined(Z_COMPILER_ISA_INTEGER_FORMAT_64BIT)
#		define Z_ISA_INTEGER_FORMAT_64BIT Z_COMPILER_ISA_INTEGER_FORMAT_64BIT
#	endif

#	if !defined(Z_ISA_INTEGER_FORMAT_128BIT) && defined(Z_COMPILER_ISA_INTEGER_FORMAT_128BIT)
#		define Z_ISA_INTEGER_FORMAT_128BIT Z_COMPILER_ISA_INTEGER_FORMAT_128BIT
#	endif

#	define Z_ISA_INTEGER_FORMAT(bits) Z_ISA_INTEGER_FORMAT_##bits##BIT
#endif

#endif /* Z_inspection_ISA_H */
