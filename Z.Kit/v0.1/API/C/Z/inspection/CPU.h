/* Z Kit C API - inspection/CPU.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_CPU_H__
#define __Z_inspection_CPU_H__

#define Z_INSPECTING_CPU_ARCHITECTURE

#	if defined(Z_USE_CPU_ARCHITECTURE_X86_64)
#		include <Z/hardware/CPU/architecture/x86-64.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_X86_32)
#		include <Z/hardware/CPU/architecture/x86-32.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_POWER_PC_64BIT)
#		include <Z/hardware/CPU/architecture/PowerPC 64-bit.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_POWER_PC_32BIT)
#		include <Z/hardware/CPU/architecture/PowerPC 32-bit.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_ARM)
#		include <Z/hardware/CPU/architecture/ARM.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_68K)
#		include <Z/hardware/CPU/architecture/68K.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_ITANIUM)
#		include <Z/hardware/CPU/architecture/Itanium.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_Alpha)
#		include <Z/hardware/CPU/architecture/Alpha.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_MIPS)
#		include <Z/hardware/CPU/architecture/MIPS.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_RS_6000)
#		include <Z/hardware/CPU/architecture/RS 6000.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_SPARC)
#		include <Z/hardware/CPU/architecture/SPARC.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_SUPER_H)
#		include <Z/hardware/CPU/architecture/SuperH.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_SYSTEM_370)
#		include <Z/hardware/CPU/architecture/System 370.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_SYSTEM_390)
#		include <Z/hardware/CPU/architecture/System 390.h>

#	elif defined(Z_USE_CPU_ARCHITECTURE_Z_ARCHITECTURE)
#		include <Z/hardware/CPU/architecture/z Architecture.h>

#	else
#		if	defined(__amd64__ ) || \
			defined(__amd64	  ) || \
			defined(__x86_64__) || \
			defined(__x86_64  ) || \
			defined(_M_X64	  ) || \
			defined(_M_AMD64  )
#			include <Z/hardware/CPU/architecture/x86-64.h>

#		elif	defined(i386	     ) || \
			defined(__i386	     ) || \
			defined(__i386__     ) || \
			defined(__i486__     ) || \
			defined(__i586__     ) || \
			defined(__i686__     ) || \
			defined(_X86_	     ) || \
			defined(__X86__	     ) || \
			defined(_M_IX86	     ) || \
			defined(__THW_INTEL__) || \
			defined(__I86__	     ) || \
			defined(__INTEL__    )
#			include <Z/hardware/CPU/architecture/x86-32.h>

#		elif	defined(__powerpc64__) || \
			defined(__ppc64__    ) || \
			defined(__PPC64__    ) || \
			defined(__PPU__	     )
#			include <Z/hardware/CPU/architecture/PowerPC 64-bit.h>

#		elif	defined(__powerpc  ) || \
			defined(__powerpc__) || \
			defined(__POWERPC__) || \
			defined(__ppc__	   ) || \
			defined(__PPC__	   ) || \
			defined(_M_PPC	   ) || \
			defined(_ARCH_PPC  )
#			include <Z/hardware/CPU/architecture/PowerPC 32-bit.h>

#		elif	defined(__arm__		   ) || \
			defined(__thumb__	   ) || \
			defined(__TARGET_ARCH_ARM  ) || \
			defined(__TARGET_ARCH_THUMB) || \
			defined(_ARM		   )
#			include <Z/hardware/CPU/architecture/ARM.h>

#		elif	defined(__m68k__) || \
			defined(M68000	)
#			include <Z/hardware/CPU/architecture/68K.h>

#		elif	defined(__ia64__) || \
			defined(_IA64	) || \
			defined(__IA64__) || \
			defined(__ia64	) || \
			defined(_M_IA64	)
#			include <Z/hardware/CPU/architecture/Itanium.h>

#		elif	defined(__alpha__) || \
			defined(__alpha	 ) || \
			defined(_M_ALPHA )
#			include <Z/hardware/CPU/architecture/Alpha.h>

#		elif	defined(__mips__) || \
			defined(mips	) || \
			defined(__mips	) || \
			defined(__MIPS__)
#			include <Z/hardware/CPU/architecture/MIPS.h>

#		elif	defined(__hppa__) || \
			defined(__hppa)
#			include <Z/hardware/CPU/architecture/PA-RISC.h>

#		elif	defined(__THW_RS6000) || \
			defined(_IBMR2	    ) || \
			defined(_POWER	    ) || \
			defined(_ARCH_PWR   ) || \
			defined(_ARCH_PWR2  )
#			include <Z/hardware/CPU/architecture/RS 6000.h>

#		elif	defined(__sparc__) || \
			defined(__sparc	 )
#			include <Z/hardware/CPU/architecture/SPARC.h>

#		elif	defined(__sh__)
#			include <Z/hardware/CPU/architecture/SuperH.h>

#		elif	defined(__370__	   ) || \
			defined(__THW_370__)
#			include <Z/hardware/CPU/architecture/System 370.h>

#		elif	defined(__s390__ ) || \
			defined(__s390x__)
#			include <Z/hardware/CPU/architecture/System 390.h>

#		elif	defined(__SYSC_ZARCH__)
#			include <Z/hardware/CPU/architecture/z Architecture.h>

#		else
#			error "Target Processor architecture not suported."
#		endif
#	endif

#	ifdef Z_CPU_MODEL_HEADER
#		include Z_CPU_MODEL_HEADER
#	else
#		define Z_CPU_MODEL_NAME GENERIC_CPU_MODEL
#		define Z_CPU_MODEL_Name GenericCPUModel
#		define Z_CPU_MODEL_name generic_cpu_model
#	endif

#undef Z_INSPECTING_CPU_ARCHITECTURE

#include <Z/keys/hardware/CPU/architecture.h>
#include <Z/macros/preprocessor.h>

#undef HAS_
#undef IS_CAPABLE_OF_
#undef ENDIANNESS

#define Z_CPU_ARCHITECTURE_PREFIX		Z_JOIN_2(Z_, Z_SUFFIX_UNDERSCORE(Z_CPU_ARCHITECTURE_NAME))
#define Z_CPU_ARCHITECTURE			Z_JOIN_2(Z_CPU_ARCHITECTURE_, Z_CPU_ARCHITECTURE_NAME)
#define Z_CPU_ARCHITECTURE_STRING		Z_JOIN_2(Z_CPU_ARCHITECTURE_STRING_, Z_CPU_ARCHITECTURE_NAME)
#define Z_CPU_ARCHITECTURE_DEFINED(WHAT)	Z_JOIN_2_DEFINED(Z_CPU_ARCHITECTURE_PREFIX, WHAT)
#define Z_CPU_MODEL_PREFIX			Z_JOIN_2(Z_, Z_SUFFIX_UNDERSCORE(Z_CPU_MODEL_NAME))
#define Z_CPU_MODEL_DEFINED(WHAT)		Z_JOIN_2_DEFINED(Z_CPU_MODEL_PREFIX, WHAT)
#define Z_CPU_DEFINED(WHAT)			(Z_CPU_ARCHITECTURE_DEFINED(WHAT) || Z_CPU_MODEL_DEFINED(WHAT))

#define Z_CPU_HAS(WHAT)				(Z_JOIN_3_DEFINED(Z_CPU_ARCHITECTURE_PREFIX, HAS_, WHAT) || \
						 Z_JOIN_3_DEFINED(Z_CPU_MODEL_PREFIX,	     HAS_, WHAT))

#define Z_CPU_IS_CAPABLE_OF(WHAT)		(Z_JOIN_3_DEFINED(Z_CPU_ARCHITECTURE_PREFIX, IS_CAPABLE_OF_, WHAT) || \
						 Z_JOIN_3_DEFINED(Z_CPU_MODEL_PREFIX,	     IS_CAPABLE_OF_, WHAT))

#define Z_CPU(WHAT)				Z_JOIN_2(Z_CPU_ARCHITECTURE_PREFIX, WHAT)
#define Z_CPU_ENDIANNESS			Z_JOIN_2(Z_CPU_ARCHITECTURE_PREFIX, ENDIANNESS)

#if !Z_CPU_DEFINED(INTEGER_ENDIANNESS_16BIT)
#	define Z_CPU_INTEGER_ENDIANNESS_16BIT	Z_CPU_ENDIANNESS
#endif

#if !Z_CPU_DEFINED(INTEGER_ENDIANNESS_32BIT)
#	define Z_CPU_INTEGER_ENDIANNESS_32BIT	Z_CPU_ENDIANNESS
#endif

#if !Z_CPU_DEFINED(INTEGER_ENDIANNESS_64BIT)
#	define Z_CPU_INTEGER_ENDIANNESS_64BIT	Z_CPU_ENDIANNESS
#endif

#if !Z_CPU_DEFINED(INTEGER_ENDIANNESS_128BIT) && Z_CPU_HAS(128BIT_ARITHMETIC)
#	define Z_CPU_INTEGER_ENDIANNESS_128BIT	Z_CPU_ENDIANNESS
#endif

#define Z_CPU_INTEGER_ENDIANNESS(BITS)		Z_CPU_INTEGER_ENDIANNESS_##BITS

#endif /* __Z_inspection_CPU_H__ */
