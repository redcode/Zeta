/* Z Kit C API - hardware/CPU/architecture/i8008.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_i8008_H__
#define __Z_hardware_CPU_architecture_i8008_H__

#include <Z/keys/endianness.h>

/* MARK: - Addresses */


/* MARK: - Values after power on */


/* MARK: - Values after reset */


/* MARK: - Information for emulation */


#endif /* __Z_hardware_CPU_architecture_i8008_H__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_i8008_H__INSPECTION
#	define __Z_hardware_CPU_architecture_i8008_H__INSPECTION

#	define Z_INSERT_CPU_ARCHITECTURE(left, right) left##I8008##right
#	define Z_INSERT_CPUArchitecture( left, right) left##i8008##right
#	define Z_INSERT_cpu_architecture Z_INSERT_CPUArchitecture

#	define Z_IS_DEFINED_INSERT_CPU_ARCHITECTURE(left, right) \
		(defined left##I8008##right)

#	endif /* __Z_hardware_CPU_architecture_i8008_H__INSPECTION */

#else

#	ifndef __Z_hardware_CPU_architecture_i8008_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_i8008_H__NO_INSPECTION

#	include <Z/types/base.h>

	/* MARK: - State storage type */

	typedef struct {
	} Zi8008State;

	/* MARK: - State structure macros */

#	endif /* __Z_hardware_CPU_architecture_i8008_H__NO_INSPECTION */

#endif
