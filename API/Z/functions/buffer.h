/* Zeta API - Z/functions/buffer.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2012 Remis.
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_buffer_H
#define Z_functions_buffer_H

#include <Z/constants/pointer.h>
#include <Z/macros/language.h>
#include <Z/types/buffer.h>
#include <Z/functions/atomic.h>


static Z_INLINE
void z_triple_buffer_initialize(
	ZTripleBuffer* self,
	void*	       slot_0,
	void*	       slot_1,
	void*	       slot_2
)
	{
	self->slots[0] = slot_0;
	self->slots[1] = slot_1;
	self->slots[2] = slot_2;
	self->f	       = 6;
	}


static Z_INLINE
void *z_triple_buffer_consume(ZTripleBuffer *self)
	{
	zuchar fi, fo;

	do	{
		if (!((fi = self->f) & 64)) return Z_NULL;
		fo = (zuchar)((fi & 48) | ((fi & 12) >> 2) | ((fi & 3) << 2));
		}
	while (!z_T_atomic_set_if_equal(UCHAR)(&self->f, fi, fo));

	return self->slots[fo & 3];
	}


static Z_INLINE
void *z_triple_buffer_consumption(ZTripleBuffer const *self)
	{return self->slots[self->f & 3];}


static Z_INLINE
zuchar z_triple_buffer_consumption_index(ZTripleBuffer const *self)
	{return self->f & 3;}


static Z_INLINE
void *z_triple_buffer_produce(ZTripleBuffer *self)
	{
	zuchar fi, fo;

	do	{
		fi = self->f;
		fo = (zuchar)(64 | ((fi & 48) >> 2) | ((fi & 12) << 2) | (fi & 3));
		}
	while (!z_T_atomic_set_if_equal(UCHAR)(&self->f, fi, fo));

	return self->slots[(fo & 48) >> 4];
	}


static Z_INLINE
void *z_triple_buffer_production(ZTripleBuffer const *self)
	{return self->slots[(self->f & 48) >> 4];}


static Z_INLINE
zuchar z_triple_buffer_production_index(ZTripleBuffer const *self)
	{return (self->f & 48) >> 4;}


#endif /* Z_functions_buffer_H */
