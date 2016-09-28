/* Z Kit C API - hardware/CPU/architecture/i4004.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_i4004_H__
#define __Z_hardware_CPU_architecture_i4004_H__

#include <Z/keys/endianness.h>

/* MARK: - Addresses */


/* MARK: - Values after power on */


/* MARK: - Values after reset */


/* MARK: - Information for emulation */


#endif /* __Z_hardware_CPU_architecture_i4004_H__ */

#ifndef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_i4004_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_i4004_H__NO_INSPECTION

#	include <Z/types/base.h>

	/* MARK: - State storage type */

	typedef struct {
		zuint16	stack[4];
		zuint8  pc;
		zuint8	p[8];
		zuint8	a;
		zuint8	c;
	} Zi4004State;

	/* MARK: - State structure macros */

#	endif /* __Z_hardware_CPU_architecture_i4004_H__NO_INSPECTION */

#endif
