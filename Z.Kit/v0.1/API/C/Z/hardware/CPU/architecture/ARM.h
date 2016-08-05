/* Z Kit C API - hardware/CPU/architecture/ARM.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_ARM_H__
#define __Z_hardware_CPU_architecture_ARM_H__

#include <Z/keys/endianness.h>

#define Z_ARM_HAS_MMU
#define Z_ARM_HAS_FPU
#define Z_ARM_HAS_64BIT_ARITHMETIC
#define Z_ARM_IS_CAPABLE_OF_8BIT_ATOMICS
#define Z_ARM_IS_CAPABLE_OF_16BIT_ATOMICS
#define Z_ARM_IS_CAPABLE_OF_32BIT_ATOMICS
#define Z_ARM_IS_CAPABLE_OF_64BIT_ATOMICS

#define Z_ARM_MINIMUM_INSTRUCTION_SIZE 4
#define Z_ARM_MINIMUM_LOAD_BITS	       8
#define Z_ARM_MINIMUM_STORE_BITS       8
#define Z_ARM_MINIMUM_COPY_BITS	       8
#define Z_ARM_MAXIMUM_LOAD_BITS	       512
#define Z_ARM_MAXIMUM_STORE_BITS       512
#define Z_ARM_MAXIMUM_COPY_BITS	       512
#define Z_ARM_ADDRESSING_BITS	       32
#define Z_ARM_ENDIANNESS	       Z_ENDIANNESS_LITTLE /* Z_ENDIANNESS_MIXED */

#endif /* __Z_hardware_CPU_architecture_x86_32_H__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_ARM_H__INSPECTION
#	define __Z_hardware_CPU_architecture_ARM_H__INSPECTION

#	define Z_INSERT_CPU_ARCHITECTURE(left, right) left##ARM##right
#	define Z_INSERT_CPUArchitecture( left, right) left##ARM##right
#	define Z_INSERT_cpu_architecture(left, right) left##arm##right

#	define Z_IS_DEFINED_INSERT_CPU_ARCHITECTURE(left, right) \
		(defined left##ARM##right)

#	endif /* __Z_hardware_CPU_architecture_ARM_H__INSPECTION */

#else

#	ifndef __Z_hardware_CPU_architecture_ARM_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_ARM_H__NO_INSPECTION

#	endif /* __Z_hardware_CPU_architecture_ARM_H__NO_INSPECTION */

#endif
