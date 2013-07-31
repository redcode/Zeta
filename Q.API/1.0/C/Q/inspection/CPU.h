/* Q API - inspection/CPU.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_inspection_CPU_H__
#define __Q_inspection_CPU_H__

#pragma mark - Step 1: Identify CPU architecture

#if	defined(Q_USE_CPU_ARCHITECTURE_X86_64)
#	define Q_CPU_ARCHITECTURE_NAME x86-64

#elif	defined(Q_USE_CPU_ARCHITECTURE_X86_32)
#	define Q_CPU_ARCHITECTURE_NAME x86-32

#elif	defined(Q_USE_CPU_ARCHITECTURE_POWER_PC_64BIT)
#	define Q_CPU_ARCHITECTURE_NAME PowerPC 64-bit

#elif	defined(Q_USE_CPU_ARCHITECTURE_POWER_PC_32BIT)
#	define Q_CPU_ARCHITECTURE_NAME PowerPC 32-bit

#elif	defined(Q_USE_CPU_ARCHITECTURE_ARM)
#	define Q_CPU_ARCHITECTURE_NAME ARM

#elif	defined(Q_USE_CPU_ARCHITECTURE_68K)
#	define Q_CPU_ARCHITECTURE_NAME 68K

#elif	defined(Q_USE_CPU_ARCHITECTURE_ITANIUM)
#	define Q_CPU_ARCHITECTURE_NAME Itanium

#elif	defined(Q_USE_CPU_ARCHITECTURE_Alpha)
#	define Q_CPU_ARCHITECTURE_NAME Alpha

#elif	defined(Q_USE_CPU_ARCHITECTURE_MIPS)
#	define Q_CPU_ARCHITECTURE_NAME MIPS

#elif	defined(Q_USE_CPU_ARCHITECTURE_RS_6000)
#	define Q_CPU_ARCHITECTURE_NAME RS 6000

#elif	defined(Q_USE_CPU_ARCHITECTURE_SPARC)
#	define Q_CPU_ARCHITECTURE_NAME SPARC

#elif	defined(Q_USE_CPU_ARCHITECTURE_SUPER_H)
#	define Q_CPU_ARCHITECTURE_NAME SuperH

#elif	defined(Q_USE_CPU_ARCHITECTURE_SYSTEM_370)
#	define Q_CPU_ARCHITECTURE_NAME System 370

#elif	defined(Q_USE_CPU_ARCHITECTURE_SYSTEM_390)
#	define Q_CPU_ARCHITECTURE_NAME System 390

#elif	defined(Q_USE_CPU_ARCHITECTURE_Z_ARCHITECTURE)
#	define Q_CPU_ARCHITECTURE_NAME z Architecture

#else

#	if	defined(__amd64__)	|| \
		defined(__amd64)	|| \
		defined(__x86_64__)	|| \
		defined(__x86_64)	|| \
		defined(_M_X64)

#		define Q_CPU_ARCHITECTURE_NAME x86-64

#	elif	defined(i386)		|| \
		defined(__i386)		|| \
		defined(__i386__)	|| \
		defined(__i486__)	|| \
		defined(__i586__)	|| \
		defined(__i686__)	|| \
		defined(_X86_)		|| \
		defined(__X86__)	|| \
		defined(_M_IX86)	|| \
		defined(__THW_INTEL__)	|| \
		defined(__I86__)	|| \
		defined(__INTEL__)

#		define Q_CPU_ARCHITECTURE_NAME x86-32

#	elif	defined(__powerpc64__)	|| \
		defined(__ppc64__)	|| \
		defined(__PPC64__)	|| \
		defined(__PPU__)

#		define Q_CPU_ARCHITECTURE_NAME PowerPC 64-bit

#	elif	defined(__powerpc)	|| \
		defined(__powerpc__)	|| \
		defined(__POWERPC__)	|| \
		defined(__ppc__)	|| \
		defined(__PPC__)	|| \
		defined(_M_PPC)		|| \
		defined(_ARCH_PPC)

#		define Q_CPU_ARCHITECTURE_NAME PowerPC 32-bit

#	elif	defined(__arm__)		|| \
		defined(__thumb__)		|| \
		defined(__TARGET_ARCH_ARM)	|| \
		defined(__TARGET_ARCH_THUMB)	|| \
		defined(_ARM)

#		define Q_CPU_ARCHITECTURE_NAME ARM

#	elif	defined(__m68k__)	|| \
		defined(M68000)

#		define Q_CPU_ARCHITECTURE_NAME 68K

#	elif	defined(__ia64__)	|| \
		defined(_IA64)		|| \
		defined(__IA64__)	|| \
		defined(__ia64)		|| \
		defined(_M_IA64)

#		define Q_CPU_ARCHITECTURE_NAME Itanium

#	elif	defined(__alpha__)	|| \
		defined(__alpha)	|| \
		defined(_M_ALPHA)

#		define Q_CPU_ARCHITECTURE_NAME Alpha

#	elif	defined(__mips__)	|| \
		defined(mips)		|| \
		defined(__mips)		|| \
		defined(__MIPS__)

#		define Q_CPU_ARCHITECTURE_NAME MIPS

#	elif	defined(__hppa__)	|| \
		defined(__hppa)

#		define Q_CPU_ARCHITECTURE_NAME PA-RISC

#	elif	defined(__THW_RS6000)	|| \
		defined(_IBMR2)		|| \
		defined(_POWER)		|| \
		defined(_ARCH_PWR)	|| \
		defined(_ARCH_PWR2)

#		define Q_CPU_ARCHITECTURE_NAME RS 6000

#	elif	defined(__sparc__)	|| \
		defined(__sparc)

#		define Q_CPU_ARCHITECTURE_NAME SPARC

#	elif	defined(__sh__)

#		define Q_CPU_ARCHITECTURE_NAME SuperH

#	elif	defined(__370__)	|| \
		defined(__THW_370__)

#		define Q_CPU_ARCHITECTURE_NAME System 370

#	elif	defined(__s390__)	|| \
		defined(__s390x__)

#		define Q_CPU_ARCHITECTURE_NAME System 390

#	elif	defined(__SYSC_ZARCH__)

#		define Q_CPU_ARCHITECTURE_NAME z Architecture

#	else
#		error "Target Processor architecture not suported."
#	endif

#endif

#pragma mark - Step 2: Include related headers under inspection mode

#define Q_INSPECTING

#define  Q_CPU_ARCHITECTURE_HEADER <Q/hardware/CPU/architecture/Q_CPU_ARCHITECTURE_NAME.h>
#include Q_CPU_ARCHITECTURE_HEADER

#ifdef Q_CPU_MODEL_HEADER
#	include Q_CPU_MODEL_HEADER
#else
#	define Q_CPU_MODEL_TOKEN GENERIC_CPU_MODEL
#endif

#undef Q_INSPECTING

#pragma mark - Step 3: Define inspection macros

#include <Q/keys/hardware/CPU/architecture.h>
#include <Q/macros/preprocessor.h>

#define Q_CPU_ARCHITECTURE_PREFIX		Q_JOIN_3(Q_, Q_CPU_ARCHITECTURE_TOKEN, _)
#define Q_CPU_ARCHITECTURE			Q_JOIN_2(Q_CPU_ARCHITECTURE_, Q_CPU_ARCHITECTURE_TOKEN)
#define Q_CPU_ARCHITECTURE_STRING		Q_JOIN_2(Q_CPU_ARCHITECTURE_STRING_, Q_CPU_ARCHITECTURE_TOKEN)
#define Q_CPU_ARCHITECTURE_DEFINED(what)	Q_JOIN_2_DEFINED(Q_CPU_ARCHITECTURE_PREFIX, what)

#define Q_CPU_MODEL_PREFIX			Q_JOIN_3(Q_, Q_CPU_MODEL_TOKEN, _)
#define Q_CPU_MODEL_DEFINED(what)		Q_JOIN_2_DEFINED(Q_CPU_MODEL_PREFIX, what)

#define Q_CPU_DEFINED(what)			(Q_CPU_ARCHITECTURE_DEFINED(what) || Q_CPU_MODEL_DEFINED(what))

#define Q_CPU_HAS(what)				(Q_JOIN_3_DEFINED(Q_CPU_ARCHITECTURE_PREFIX, HAS_, what) || \
						 Q_JOIN_3_DEFINED(Q_CPU_MODEL_PREFIX,	     HAS_, what))

#define Q_CPU_IS_CAPABLE_OF(what)		(Q_JOIN_3_DEFINED(Q_CPU_ARCHITECTURE_PREFIX, IS_CAPABLE_OF_, what) || \
						 Q_JOIN_3_DEFINED(Q_CPU_MODEL_PREFIX,	     IS_CAPABLE_OF_, what))

#define Q_CPU(what)				Q_JOIN_2(Q_CPU_ARCHITECTURE_PREFIX, what)


#define Q_CPU_ENDIANNESS			Q_JOIN_2(Q_CPU_ARCHITECTURE_PREFIX, ENDIANNESS)

#if !Q_CPU_DEFINED(INTEGER_ENDIANNESS_16BIT)
#	define Q_CPU_INTEGER_ENDIANNESS_16BIT	Q_CPU_ENDIANNESS
#endif

#if !Q_CPU_DEFINED(INTEGER_ENDIANNESS_32BIT)
#	define Q_CPU_INTEGER_ENDIANNESS_32BIT	Q_CPU_ENDIANNESS
#endif

#if !Q_CPU_DEFINED(INTEGER_ENDIANNESS_64BIT)
#	define Q_CPU_INTEGER_ENDIANNESS_64BIT	Q_CPU_ENDIANNESS
#endif

#if !Q_CPU_DEFINED(INTEGER_ENDIANNESS_128BIT) \
    && Q_CPU_HAS(128BIT_ARITHMETIC)
#	define Q_CPU_INTEGER_ENDIANNESS_128BIT	Q_CPU_ENDIANNESS
#endif

#define Q_CPU_INTEGER_ENDIANNESS(bits)	Q_CPU_INTEGER_ENDIANNESS_##bits

#endif /* __Q_inspection_CPU_H__ */
