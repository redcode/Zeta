/* Z Kit C API - hardware/CPU/architecture/x86-32.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_x86_32_H__
#define __Z_hardware_CPU_architecture_x86_32_H__

#define Z_X86_32_MINIMUM_LOAD_BITS  8
#define Z_X86_32_MINIMUM_STORE_BITS 8
#define Z_X86_32_MINIMUM_COPY_BITS  8
#define Z_X86_32_MAXIMUM_LOAD_BITS  32
#define Z_X86_32_MAXIMUM_STORE_BITS 32
#define Z_X86_32_MAXIMUM_COPY_BITS  32
#define Z_X86_32_ADDRESSING_BITS    32

#endif /* __Z_hardware_CPU_architecture_x86_32_H__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_x86_32_H__INSPECTION
#	define __Z_hardware_CPU_architecture_x86_32_H__INSPECTION

#	include <Z/constants/base.h>
#	include <Z/keys/endianness.h>
#	include <Z/keys/value.h>

#	define Z_CPU_ARCHITECTURE_INTEGER_ENDIANNESS Z_ENDIANNESS_LITTLE
#	define Z_CPU_ARCHITECTURE_INTEGER_FORMAT     Z_INTEGER_FORMAT_2S_COMPLEMENT

#	define Z_CPU_ARCHITECTURE_HAS_MMU TRUE
#	define Z_CPU_ARCHITECTURE_HAS_FPU TRUE

#	ifdef __MMX__
#		define Z_CPU_HAS_ISA_MMX TRUE
#	else
#		define Z_CPU_HAS_ISA_MMX FALSE
#	endif

#	ifdef __SSE__
#		define Z_CPU_HAS_ISA_SSE TRUE
#	else
#		define Z_CPU_HAS_ISA_SSE FALSE
#	endif

#	ifdef __SSE2__
#		define Z_CPU_HAS_ISA_SSE2 TRUE
#	else
#		define Z_CPU_HAS_ISA_SSE2 FALSE
#	endif

#	endif /* __Z_hardware_CPU_architecture_x86_32_H__INSPECTION */

#else

#	ifndef __Z_hardware_CPU_architecture_x86_32_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_x86_32_H__NO_INSPECTION

#	endif /* __Z_hardware_CPU_architecture_x86_32_H__NO_INSPECTION */

#endif
