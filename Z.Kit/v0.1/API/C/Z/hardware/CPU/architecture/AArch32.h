/* Z Kit C API - hardware/CPU/architecture/AArch32.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_AArch32_H__
#define __Z_hardware_CPU_architecture_AArch32_H__

#include <Z/keys/endianness.h>

#define Z_A_ARCH_32_HAS_MMU
#define Z_A_ARCH_32_HAS_FPU
#define Z_A_ARCH_32_HAS_64BIT_ARITHMETIC
#define Z_A_ARCH_32_IS_CAPABLE_OF_8BIT_ATOMICS
#define Z_A_ARCH_32_IS_CAPABLE_OF_16BIT_ATOMICS
#define Z_A_ARCH_32_IS_CAPABLE_OF_32BIT_ATOMICS
#define Z_A_ARCH_32_IS_CAPABLE_OF_64BIT_ATOMICS

#define Z_A_ARCH_32_MINIMUM_INSTRUCTION_SIZE 4
#define Z_A_ARCH_32_MINIMUM_LOAD_BITS	     8
#define Z_A_ARCH_32_MINIMUM_STORE_BITS	     8
#define Z_A_ARCH_32_MINIMUM_COPY_BITS	     8
#define Z_A_ARCH_32_MAXIMUM_LOAD_BITS	     512
#define Z_A_ARCH_32_MAXIMUM_STORE_BITS	     512
#define Z_A_ARCH_32_MAXIMUM_COPY_BITS	     512
#define Z_A_ARCH_32_ADDRESSING_BITS	     32
#define Z_A_ARCH_32_ENDIANNESS		     Z_ENDIANNESS_LITTLE /* Z_ENDIANNESS_MIXED */

#endif /* __Z_hardware_CPU_architecture_AArch32_H__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_AArch32_H__INSPECTION
#	define __Z_hardware_CPU_architecture_AArch32_H__INSPECTION

#	define Z_INSERT_CPU_ARCHITECTURE(left, right) left##A_ARCH_32##right
#	define Z_INSERT_CPUArchitecture( left, right) left##AArch32##right
#	define Z_INSERT_cpu_architecture(left, right) left##a_arch_32##right

#	define Z_IS_DEFINED_INSERT_CPU_ARCHITECTURE(left, right) \
		(defined left##A_ARCH_32##right)

#	endif /* __Z_hardware_CPU_architecture_AArch32_H__INSPECTION */

#else

#	ifndef __Z_hardware_CPU_architecture_AArch32_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_AArch32_H__NO_INSPECTION

#	endif /* __Z_hardware_CPU_architecture_AArch32_H__NO_INSPECTION */

#endif
