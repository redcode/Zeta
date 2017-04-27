/* Z Kit C API - hardware/CPU/architecture/i4004.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_architecture_i4004_H__
#define __Z_hardware_CPU_architecture_i4004_H__

#include <Z/types/base.h>

/* MARK: - Addresses */


/* MARK: - Values after power on */


/* MARK: - Values after reset */


/* MARK: - Information for emulation */


/* MARK: - State storage type */

typedef struct {
	zuint16	stack[4];
	zuint8  pc;
	zuint8	p[8];
	zuint8	a;
	zuint8	c;
} Zi4004State;

/* MARK: - State structure macros */

#endif /* __Z_hardware_CPU_architecture_i4004_H__ */