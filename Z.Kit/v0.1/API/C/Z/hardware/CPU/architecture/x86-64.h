/* Z Kit C API - hardware/CPU/architecture/x86-64.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_x86_64_H__
#define __Z_hardware_CPU_architecture_x86_64_H__

#include <Z/keys/endianness.h>
#include <Z/keys/value.h>

#define Z_X86_64_HAS_MMU
#define Z_X86_64_HAS_FPU
#define Z_X86_64_HAS_64BIT_ARITHMETIC
#define Z_X86_64_HAS_128BIT_ARITHMETIC
#define Z_X86_64_IS_CAPABLE_OF_8BIT_ATOMICS
#define Z_X86_64_IS_CAPABLE_OF_16BIT_ATOMICS
#define Z_X86_64_IS_CAPABLE_OF_32BIT_ATOMICS
#define Z_X86_64_IS_CAPABLE_OF_64BIT_ATOMICS

#define Z_X86_64_MINIMUM_LOAD_BITS  8
#define Z_X86_64_MINIMUM_STORE_BITS 8
#define Z_X86_64_MINIMUM_COPY_BITS  8
#define Z_X86_64_MAXIMUM_LOAD_BITS  128
#define Z_X86_64_MAXIMUM_STORE_BITS 128
#define Z_X86_64_MAXIMUM_COPY_BITS  64
#define Z_X86_64_ADDRESSING_BITS    64
#define Z_X86_64_INTEGER_ENDIANNESS Z_ENDIANNESS_LITTLE
#define Z_X86_64_INTEGER_FORMAT	    Z_INTEGER_FORMAT_2S_COMPLEMENT

#endif /* __Z_hardware_CPU_architecture_x86_64_H__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_x86_64_H__INSPECTION
#	define __Z_hardware_CPU_architecture_x86_64_H__INSPECTION

#	define Z_INSERT_CPU_ARCHITECTURE(left, right) left##X86_64##right
#	define Z_INSERT_CPUArchitecture( left, right) left##X8664##right
#	define Z_INSERT_cpu_architecture(left, right) left##x86_64##right

#	define Z_IS_DEFINED_INSERT_CPU_ARCHITECTURE(left, right) \
		(defined left##X86_64##right)

#	endif /* __Z_hardware_CPU_architecture_x86_64_H__INSPECTION */

#else

#	ifndef __Z_hardware_CPU_architecture_x86_64_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_x86_64_H__NO_INSPECTION

#	endif /* __Z_hardware_CPU_architecture_x86_64_H__NO_INSPECTION */

#endif
