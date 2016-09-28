/* Z Kit C API - hardware/CPU/architecture/PowerPC 32-bit.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_PowerPC_32_bit_H__
#define __Z_hardware_CPU_architecture_PowerPC_32_bit_H__

#include <Z/keys/endianness.h>
#include <Z/keys/value.h>

#define Z_POWER_PC_32BIT_MINIMUM_LOAD_BITS   8
#define Z_POWER_PC_32BIT_MINIMUM_STORE_BITS  8
#define Z_POWER_PC_32BIT_MINIMUM_COPY_BITS   8
#define Z_POWER_PC_32BIT_MAXIMUM_LOAD_BITS  32
#define Z_POWER_PC_32BIT_MAXIMUM_STORE_BITS 32
#define Z_POWER_PC_32BIT_MAXIMUM_COPY_BITS  32
#define Z_POWER_PC_32BIT_ADDRESSING_BITS    32

#endif /* __Z_hardware_CPU_architecture_PowerPC_32_bit_H__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_PowerPC_32_bit_H__INSPECTION
#	define __Z_hardware_CPU_architecture_PowerPC_32_bit_H__INSPECTION

#	endif /* __Z_hardware_CPU_architecture_PowerPC_32_bit_H__INSPECTION */

#else

#	ifndef __Z_hardware_CPU_architecture_PowerPC_32_bit_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_PowerPC_32_bit_H__NO_INSPECTION

#	endif /* __Z_hardware_CPU_architecture_PowerPC_32_bit_H__NO_INSPECTION */

#endif
