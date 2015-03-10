/* Q Kit C API - hardware/CPU/architecture/PowerPC 64-bit.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_hardware_CPU_architecture_PowerPC_64_bit_Ha__
#define __Q_hardware_CPU_architecture_PowerPC_64_bit_Ha__

#include <Q/keys/endianness.h>

#define Q_POWER_PC_64BIT_HAS_MMU
#define Q_POWER_PC_64BIT_HAS_FPU
#define Q_POWER_PC_64BIT_HAS_64BIT_ARITHMETIC
#define Q_POWER_PC_64BIT_MINIMUM_LOAD_BITS	  8
#define Q_POWER_PC_64BIT_MINIMUM_STORE_BITS	  8
#define Q_POWER_PC_64BIT_MINIMUM_COPY_BITS	  8
#define Q_POWER_PC_64BIT_MAXIMUM_LOAD_BITS	128
#define Q_POWER_PC_64BIT_MAXIMUM_STORE_BITS	128
#define Q_POWER_PC_64BIT_MAXIMUM_COPY_BITS	128
#define Q_POWER_PC_64BIT_ADDRESSING_BITS	 64
#define Q_POWER_PC_64BIT_ENDIANNESS		Q_ENDIANNESS_BIG

#endif /* __Q_hardware_CPU_architecture_PowerPC_64_bit_Ha__ */

#ifdef Q_INSPECTING_CPU_ARCHITECTURE

#	undef POWER_PC_64BIT
#	undef PowerPC64Bit
#	undef power_pc_64bit

#	define Q_CPU_ARCHITECTURE_NAME POWER_PC_64BIT
#	define Q_CPU_ARCHITECTURE_Name PowerPC64Bit
#	define Q_CPU_ARCHITECTURE_Name power_pc_64bit

#else

#	ifndef __Q_hardware_CPU_architecture_PowerPC_64_bit_Hb__
#	define __Q_hardware_CPU_architecture_PowerPC_64_bit_Hb__

#	endif /* __Q_hardware_CPU_architecture_PowerPC_64_bit_Hb__ */

#endif
