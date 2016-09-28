/* Z Kit C API - hardware/CPU/architecture/AArch32.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_AArch32_H__
#define __Z_hardware_CPU_architecture_AArch32_H__

#define Z_A_ARCH_32_MINIMUM_INSTRUCTION_SIZE 4
#define Z_A_ARCH_32_MINIMUM_LOAD_BITS	     8
#define Z_A_ARCH_32_MINIMUM_STORE_BITS	     8
#define Z_A_ARCH_32_MINIMUM_COPY_BITS	     8
#define Z_A_ARCH_32_MAXIMUM_LOAD_BITS	     512
#define Z_A_ARCH_32_MAXIMUM_STORE_BITS	     512
#define Z_A_ARCH_32_MAXIMUM_COPY_BITS	     512
#define Z_A_ARCH_32_ADDRESSING_BITS	     32

#endif /* __Z_hardware_CPU_architecture_AArch32_H__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_AArch32_H__INSPECTION
#	define __Z_hardware_CPU_architecture_AArch32_H__INSPECTION

#	include <Z/constants/base.h>
#	include <Z/keys/endianness.h>
#	include <Z/keys/value.h>

#	define Z_CPU_ARCHITECTURE_INTEGER_ENDIANNESS Z_ENDIANNESS_MIXED
#	define Z_CPU_ARCHITECTURE_INTEGER_FORMAT     Z_INTEGER_FORMAT_2S_COMPLEMENT

#	define Z_CPU_ARCHITECTURE_HAS_MMU TRUE
#	define Z_CPU_ARCHITECTURE_HAS_FPU TRUE

#	endif /* __Z_hardware_CPU_architecture_AArch32_H__INSPECTION */

#else

#	ifndef __Z_hardware_CPU_architecture_AArch32_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_AArch32_H__NO_INSPECTION

#	endif /* __Z_hardware_CPU_architecture_AArch32_H__NO_INSPECTION */

#endif
