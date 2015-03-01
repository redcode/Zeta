/* Q API - hardware/CPU/architecture/PowerPC 32-bit.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_hardware_CPU_architecture_PowerPC_32_bit_Ha__
#define __Q_hardware_CPU_architecture_PowerPC_32_bit_Ha__

#include <Q/keys/endianness.h>

#define Q_POWER_PC_32BIT_HAS_MMU
#define Q_POWER_PC_32BIT_HAS_FPU
#define Q_POWER_PC_32BIT_HAS_32BIT_ARITHMETIC
#define Q_POWER_PC_32BIT_MINIMUM_LOAD_BITS	 8
#define Q_POWER_PC_32BIT_MINIMUM_STORE_BITS	 8
#define Q_POWER_PC_32BIT_MINIMUM_COPY_BITS	 8
#define Q_POWER_PC_32BIT_MAXIMUM_LOAD_BITS	32
#define Q_POWER_PC_32BIT_MAXIMUM_STORE_BITS	32
#define Q_POWER_PC_32BIT_MAXIMUM_COPY_BITS	32
#define Q_POWER_PC_32BIT_ADDRESSING_BITS	32
#define Q_POWER_PC_32BIT_ENDIANNESS		Q_ENDIANNESS_BIG

#endif /* __Q_hardware_CPU_architecture_PowerPC_32_bit_Ha__ */

#ifdef Q_INSPECTING

#	undef POWER_PC_32BIT
#	undef PowerPC32Bit
#	undef power_pc_32bit

#	define Q_CPU_ARCHITECTURE_NAME POWER_PC_32BIT
#	define Q_CPU_ARCHITECTURE_Name PowerPC32Bit
#	define Q_CPU_ARCHITECTURE_Name power_pc_32bit

#else

#	ifndef __Q_hardware_CPU_architecture_PowerPC_32_bit_Hb__
#	define __Q_hardware_CPU_architecture_PowerPC_32_bit_Hb__

#	endif /* __Q_hardware_CPU_architecture_PowerPC_32_bit_Hb__ */

#endif
