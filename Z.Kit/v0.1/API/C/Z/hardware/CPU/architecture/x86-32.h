/* Z Kit C API - hardware/CPU/architecture/x86-32.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_x86_32_Ha__
#define __Z_hardware_CPU_architecture_x86_32_Ha__

#include <Z/keys/endianness.h>

#define Z_X86_32_HAS_MMU
#define Z_X86_32_HAS_FPU
#define Z_X86_32_HAS_64BIT_ARITHMETIC
#define Z_X86_32_IS_CAPABLE_OF_8BIT_ATOMICS
#define Z_X86_32_IS_CAPABLE_OF_16BIT_ATOMICS
#define Z_X86_32_IS_CAPABLE_OF_32BIT_ATOMICS
#define Z_X86_32_IS_CAPABLE_OF_64BIT_ATOMICS
#define Z_X86_32_MINIMUM_LOAD_BITS		 8
#define Z_X86_32_MINIMUM_STORE_BITS		 8
#define Z_X86_32_MINIMUM_COPY_BITS		 8
#define Z_X86_32_MAXIMUM_LOAD_BITS		64
#define Z_X86_32_MAXIMUM_STORE_BITS		64
#define Z_X86_32_MAXIMUM_COPY_BITS		64
#define Z_X86_32_ADDRESSING_BITS		32
#define Z_X86_32_ENDIANNESS			Z_ENDIANNESS_LITTLE

#endif /* __Z_hardware_CPU_architecture_x86_32_Ha__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	undef X86_32
#	undef X8632
#	undef x86_32

#	define Z_CPU_ARCHITECTURE_NAME X86_32
#	define Z_CPU_ARCHITECTURE_Name X8632
#	define Z_CPU_ARCHITECTURE_name x86_32

#else

#	ifndef __Z_hardware_CPU_architecture_x86_32_Hb__
#	define __Z_hardware_CPU_architecture_x86_32_Hb__

#	endif /* __Z_hardware_CPU_architecture_x86_32_Hb__ */

#endif
