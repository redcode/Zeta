/* Zeta API - Z/types/buffer.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_buffer_H
#define Z_types_buffer_H

#include <Z/types/integral.h>

typedef struct {
	void*		data[3];
	zuchar volatile flags;
} ZTripleBuffer;

typedef struct {
	void*		data;
	zusize		slot_size;
	zusize		slot_count;
	zusize		consumption_index;
	zusize		production_index;
	zusize volatile fill_count;
} ZRingBuffer;

#endif /* Z_types_buffer_H */
