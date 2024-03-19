/* Zeta API - Z/types/buffer.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_buffer_H
#define Z_types_buffer_H

#include <Z/types/integral.h>

typedef struct {
	void *slots[3];
	zuchar volatile f;
} ZTripleBuffer;

#endif /* Z_types_buffer_H */
