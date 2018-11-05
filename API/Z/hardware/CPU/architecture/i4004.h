/* Z Kit - hardware/CPU/architecture/i4004.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_hardware_CPU_architecture_i4004_H_
#define _Z_hardware_CPU_architecture_i4004_H_

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

#endif /* _Z_hardware_CPU_architecture_i4004_H_ */