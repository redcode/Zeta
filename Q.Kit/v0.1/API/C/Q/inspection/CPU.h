/* Q Kit C API - inspection/CPU.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_inspection_CPU_H__
#define __Q_inspection_CPU_H__

#define Q_INSPECTING_CPU_ARCHITECTURE

#	if defined(Q_USE_CPU_ARCHITECTURE_X86_64)
#		include <Q/hardware/CPU/architecture/x86-64.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_X86_32)
#		include <Q/hardware/CPU/architecture/x86-32.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_POWER_PC_64BIT)
#		include <Q/hardware/CPU/architecture/PowerPC 64-bit.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_POWER_PC_32BIT)
#		include <Q/hardware/CPU/architecture/PowerPC 32-bit.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_ARM)
#		include <Q/hardware/CPU/architecture/ARM.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_68K)
#		include <Q/hardware/CPU/architecture/68K.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_ITANIUM)
#		include <Q/hardware/CPU/architecture/Itanium.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_Alpha)
#		include <Q/hardware/CPU/architecture/Alpha.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_MIPS)
#		include <Q/hardware/CPU/architecture/MIPS.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_RS_6000)
#		include <Q/hardware/CPU/architecture/RS 6000.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_SPARC)
#		include <Q/hardware/CPU/architecture/SPARC.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_SUPER_H)
#		include <Q/hardware/CPU/architecture/SuperH.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_SYSTEM_370)
#		include <Q/hardware/CPU/architecture/System 370.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_SYSTEM_390)
#		include <Q/hardware/CPU/architecture/System 390.h>

#	elif defined(Q_USE_CPU_ARCHITECTURE_Z_ARCHITECTURE)
#		include <Q/hardware/CPU/architecture/z Architecture.h>

#	else
#		if	defined(__amd64__)  || \
			defined(__amd64)    || \
			defined(__x86_64__) || \
			defined(__x86_64)   || \
			defined(_M_X64)	    || \
			defined(_M_AMD64)
#			include <Q/hardware/CPU/architecture/x86-64.h>

#		elif	defined(i386)	       || \
			defined(__i386)	       || \
			defined(__i386__)      || \
			defined(__i486__)      || \
			defined(__i586__)      || \
			defined(__i686__)      || \
			defined(_X86_)	       || \
			defined(__X86__)       || \
			defined(_M_IX86)       || \
			defined(__THW_INTEL__) || \
			defined(__I86__)       || \
			defined(__INTEL__)
#			include <Q/hardware/CPU/architecture/x86-32.h>

#		elif	defined(__powerpc64__) || \
			defined(__ppc64__)     || \
			defined(__PPC64__)     || \
			defined(__PPU__)
#			include <Q/hardware/CPU/architecture/PowerPC 64-bit.h>

#		elif	defined(__powerpc)   || \
			defined(__powerpc__) || \
			defined(__POWERPC__) || \
			defined(__ppc__)     || \
			defined(__PPC__)     || \
			defined(_M_PPC)	     || \
			defined(_ARCH_PPC)
#			include <Q/hardware/CPU/architecture/PowerPC 32-bit.h>

#		elif	defined(__arm__)	     || \
			defined(__thumb__)	     || \
			defined(__TARGET_ARCH_ARM)   || \
			defined(__TARGET_ARCH_THUMB) || \
			defined(_ARM)
#			include <Q/hardware/CPU/architecture/ARM.h>

#		elif	defined(__m68k__) || \
			defined(M68000)
#			include <Q/hardware/CPU/architecture/68K.h>

#		elif	defined(__ia64__) || \
			defined(_IA64)	  || \
			defined(__IA64__) || \
			defined(__ia64)	  || \
			defined(_M_IA64)
#			include <Q/hardware/CPU/architecture/Itanium.h>

#		elif	defined(__alpha__) || \
			defined(__alpha)   || \
			defined(_M_ALPHA)
#			include <Q/hardware/CPU/architecture/Alpha.h>

#		elif	defined(__mips__) || \
			defined(mips)	  || \
			defined(__mips)	  || \
			defined(__MIPS__)
#			include <Q/hardware/CPU/architecture/MIPS.h>

#		elif	defined(__hppa__) || \
			defined(__hppa)
#			include <Q/hardware/CPU/architecture/PA-RISC.h>

#		elif	defined(__THW_RS6000) || \
			defined(_IBMR2)	      || \
			defined(_POWER)	      || \
			defined(_ARCH_PWR)    || \
			defined(_ARCH_PWR2)
#			include <Q/hardware/CPU/architecture/RS 6000.h>

#		elif	defined(__sparc__) || \
			defined(__sparc)
#			include <Q/hardware/CPU/architecture/SPARC.h>

#		elif	defined(__sh__)
#			include <Q/hardware/CPU/architecture/SuperH.h>

#		elif	defined(__370__) || \
			defined(__THW_370__)
#			include <Q/hardware/CPU/architecture/System 370.h>

#		elif	defined(__s390__) || \
			defined(__s390x__)
#			include <Q/hardware/CPU/architecture/System 390.h>

#		elif	defined(__SYSC_ZARCH__)
#			include <Q/hardware/CPU/architecture/z Architecture.h>

#		else
#			error "Target Processor architecture not suported."
#		endif
#	endif

#	ifdef Q_CPU_MODEL_HEADER
#		include Q_CPU_MODEL_HEADER
#	else
#		define Q_CPU_MODEL_NAME GENERIC_CPU_MODEL
#		define Q_CPU_MODEL_Name GenericCPUModel
#		define Q_CPU_MODEL_name generic_cpu_model
#	endif

#undef Q_INSPECTING_CPU_ARCHITECTURE

#include <Q/keys/hardware/CPU/architecture.h>
#include <Q/macros/preprocessor.h>

#undef HAS_
#undef IS_CAPABLE_OF_
#undef ENDIANNESS

#define Q_CPU_ARCHITECTURE_PREFIX		Q_JOIN_2(Q_, Q_SUFFIX_UNDERSCORE(Q_CPU_ARCHITECTURE_NAME))
#define Q_CPU_ARCHITECTURE			Q_JOIN_2(Q_CPU_ARCHITECTURE_, Q_CPU_ARCHITECTURE_NAME)
#define Q_CPU_ARCHITECTURE_STRING		Q_JOIN_2(Q_CPU_ARCHITECTURE_STRING_, Q_CPU_ARCHITECTURE_NAME)
#define Q_CPU_ARCHITECTURE_DEFINED(WHAT)	Q_JOIN_2_DEFINED(Q_CPU_ARCHITECTURE_PREFIX, WHAT)
#define Q_CPU_MODEL_PREFIX			Q_JOIN_2(Q_, Q_SUFFIX_UNDERSCORE(Q_CPU_MODEL_NAME))
#define Q_CPU_MODEL_DEFINED(WHAT)		Q_JOIN_2_DEFINED(Q_CPU_MODEL_PREFIX, WHAT)
#define Q_CPU_DEFINED(WHAT)			(Q_CPU_ARCHITECTURE_DEFINED(WHAT) || Q_CPU_MODEL_DEFINED(WHAT))

#define Q_CPU_HAS(WHAT)				(Q_JOIN_3_DEFINED(Q_CPU_ARCHITECTURE_PREFIX, HAS_, WHAT) || \
						 Q_JOIN_3_DEFINED(Q_CPU_MODEL_PREFIX,	     HAS_, WHAT))

#define Q_CPU_IS_CAPABLE_OF(WHAT)		(Q_JOIN_3_DEFINED(Q_CPU_ARCHITECTURE_PREFIX, IS_CAPABLE_OF_, WHAT) || \
						 Q_JOIN_3_DEFINED(Q_CPU_MODEL_PREFIX,	     IS_CAPABLE_OF_, WHAT))

#define Q_CPU(WHAT)				Q_JOIN_2(Q_CPU_ARCHITECTURE_PREFIX, WHAT)
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

#if !Q_CPU_DEFINED(INTEGER_ENDIANNESS_128BIT) && Q_CPU_HAS(128BIT_ARITHMETIC)
#	define Q_CPU_INTEGER_ENDIANNESS_128BIT	Q_CPU_ENDIANNESS
#endif

#define Q_CPU_INTEGER_ENDIANNESS(BITS)		Q_CPU_INTEGER_ENDIANNESS_##BITS

#endif /* __Q_inspection_CPU_H__ */
