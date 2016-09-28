/* Z Kit C API - hardware/CPU/architecture/PowerPC 64-bit.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_PowerPC_64_bit_H__
#define __Z_hardware_CPU_architecture_PowerPC_64_bit_H__

#include <Z/keys/endianness.h>

#define Z_POWER_PC_64BIT_HAS_MMU
#define Z_POWER_PC_64BIT_HAS_FPU
#define Z_POWER_PC_64BIT_HAS_64BIT_ARITHMETIC

#define Z_POWER_PC_64BIT_MINIMUM_LOAD_BITS    8
#define Z_POWER_PC_64BIT_MINIMUM_STORE_BITS   8
#define Z_POWER_PC_64BIT_MINIMUM_COPY_BITS    8
#define Z_POWER_PC_64BIT_MAXIMUM_LOAD_BITS  128
#define Z_POWER_PC_64BIT_MAXIMUM_STORE_BITS 128
#define Z_POWER_PC_64BIT_MAXIMUM_COPY_BITS  128
#define Z_POWER_PC_64BIT_ADDRESSING_BITS     64
#define Z_POWER_PC_64BIT_ENDIANNESS	    Z_ENDIANNESS_BIG

#endif /* __Z_hardware_CPU_architecture_PowerPC_64_bit_H__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_PowerPC_64_bit_H__INSPECTION
#	define __Z_hardware_CPU_architecture_PowerPC_64_bit_H__INSPECTION

#	endif /* __Z_hardware_CPU_architecture_PowerPC_64_bit_H__INSPECTION */

#else

#	ifndef __Z_hardware_CPU_architecture_PowerPC_64_bit_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_PowerPC_64_bit_H__NO_INSPECTION

#	endif /* __Z_hardware_CPU_architecture_PowerPC_64_bit_H__NO_INSPECTION */

#endif
