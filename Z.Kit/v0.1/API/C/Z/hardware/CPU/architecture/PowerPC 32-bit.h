/* Z Kit C API - hardware/CPU/architecture/PowerPC 32-bit.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_PowerPC_32_bit_Ha__
#define __Z_hardware_CPU_architecture_PowerPC_32_bit_Ha__

#include <Z/keys/endianness.h>

#define Z_POWER_PC_32BIT_HAS_MMU
#define Z_POWER_PC_32BIT_HAS_FPU
#define Z_POWER_PC_32BIT_HAS_32BIT_ARITHMETIC
#define Z_POWER_PC_32BIT_MINIMUM_LOAD_BITS	 8
#define Z_POWER_PC_32BIT_MINIMUM_STORE_BITS	 8
#define Z_POWER_PC_32BIT_MINIMUM_COPY_BITS	 8
#define Z_POWER_PC_32BIT_MAXIMUM_LOAD_BITS	32
#define Z_POWER_PC_32BIT_MAXIMUM_STORE_BITS	32
#define Z_POWER_PC_32BIT_MAXIMUM_COPY_BITS	32
#define Z_POWER_PC_32BIT_ADDRESSING_BITS	32
#define Z_POWER_PC_32BIT_ENDIANNESS		Z_ENDIANNESS_BIG

#endif /* __Z_hardware_CPU_architecture_PowerPC_32_bit_Ha__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	undef POWER_PC_32BIT
#	undef PowerPC32Bit
#	undef power_pc_32bit

#	define Z_CPU_ARCHITECTURE_NAME POWER_PC_32BIT
#	define Z_CPU_ARCHITECTURE_Name PowerPC32Bit
#	define Z_CPU_ARCHITECTURE_Name power_pc_32bit

#else

#	ifndef __Z_hardware_CPU_architecture_PowerPC_32_bit_Hb__
#	define __Z_hardware_CPU_architecture_PowerPC_32_bit_Hb__

#	endif /* __Z_hardware_CPU_architecture_PowerPC_32_bit_Hb__ */

#endif
