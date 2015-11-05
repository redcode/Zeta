/* Z Kit C API - hardware/CPU/architecture/M68K.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_M68K_H__
#define __Z_hardware_CPU_architecture_M68K_H__

#include <Z/keys/endianness.h>

#endif /* __Z_hardware_CPU_architecture_M68K_H__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_M68K_H__INSPECTION
#	define __Z_hardware_CPU_architecture_M68K_H__INSPECTION

#	define Z_INSERT_CPU_ARCHITECTURE(left, right) left##M68K##right
#	define Z_INSERT_CPUArchitecture Z_INSERT_CPU_ARCHITECTURE
#	define Z_INSERT_cpu_architecture(left, right) left##m68k##right

#	define Z_IS_DEFINED_INSERT_CPU_ARCHITECTURE(left, right) \
		(defined left##M68K##right)

#	endif /* __Z_hardware_CPU_architecture_M68K_H__INSPECTION */

#else

#	ifndef __Z_hardware_CPU_architecture_M68K_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_M68K_H__NO_INSPECTION

#	endif /* __Z_hardware_CPU_architecture_M68K_H__NO_INSPECTION */

#endif
