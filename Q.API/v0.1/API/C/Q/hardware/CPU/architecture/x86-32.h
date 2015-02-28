/* Q API - hardware/CPU/architecture/x86-32.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_hardware_CPU_architecture_x86_32_Ha__
#define __Q_hardware_CPU_architecture_x86_32_Ha__

#include <Q/keys/endianness.h>

#define Q_X86_32_HAS_MMU
#define Q_X86_32_HAS_FPU
#define Q_X86_32_HAS_64BIT_ARITHMETIC
#define Q_X86_32_IS_CAPABLE_OF_8BIT_ATOMICS
#define Q_X86_32_IS_CAPABLE_OF_16BIT_ATOMICS
#define Q_X86_32_IS_CAPABLE_OF_32BIT_ATOMICS
#define Q_X86_32_IS_CAPABLE_OF_64BIT_ATOMICS
#define Q_X86_32_MINIMUM_LOAD_BITS		 8
#define Q_X86_32_MINIMUM_STORE_BITS		 8
#define Q_X86_32_MINIMUM_COPY_BITS		 8
#define Q_X86_32_MAXIMUM_LOAD_BITS		64
#define Q_X86_32_MAXIMUM_STORE_BITS		64
#define Q_X86_32_MAXIMUM_COPY_BITS		64
#define Q_X86_32_ADDRESSING_BITS		32
#define Q_X86_32_ENDIANNESS			Q_ENDIANNESS_LITTLE

#endif /* __Q_hardware_CPU_architecture_x86_32_Ha__ */

#ifdef Q_INSPECTING

#	undef X86_32
#	undef X8632
#	undef x86_32

#	define Q_CPU_ARCHITECTURE_NAME X86_32
#	define Q_CPU_ARCHITECTURE_Name X8632
#	define Q_CPU_ARCHITECTURE_name x86_32

#else

#	ifndef __Q_hardware_CPU_architecture_x86_32_Hb__
#	define __Q_hardware_CPU_architecture_x86_32_Hb__

#	endif /* __Q_hardware_CPU_architecture_x86_32_Hb__ */

#endif
