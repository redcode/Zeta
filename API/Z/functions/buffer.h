/* Zeta API - Z/functions/buffer.h
 ______ ______________  ___
|__   /|  ___|___  ___|/   \
  /  /_|  __|   |  |  /  -  \
 /_____|_____|  |__| /__/ \__\
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
	self->flags    = 6;
	}


static Z_INLINE
void *z_triple_buffer_production_slot(ZTripleBuffer const *self)
	{return self->slots[(self->flags & 48) >> 4];}


static Z_INLINE
void *z_triple_buffer_consumption_slot(ZTripleBuffer const *self)
	{return self->slots[self->flags & 3];}


static Z_INLINE
void *z_triple_buffer_produce(ZTripleBuffer *self)
	{
	zuchar flags, new_flags;

	do	{
		flags = self->flags;
		new_flags = (zuchar)(
			64		    |
			((flags & 48) >> 2) |
			((flags & 12) << 2) |
			 (flags & 3));
		}
	while (!z_T_atomic_set_if_equal(UCHAR)(&self->flags, flags, new_flags));

	return self->slots[(new_flags & 48) >> 4];
	}


static Z_INLINE
void *z_triple_buffer_consume(ZTripleBuffer *self)
	{
	zuchar flags, new_flags;

	do	{
		if (!((flags = self->flags) & 64)) return Z_NULL;

		new_flags = (zuchar)(
			 (flags & 48)	    |
			((flags & 12) >> 2) |
			((flags &  3) << 2));
		}
	while (!z_T_atomic_set_if_equal(UCHAR)(&self->flags, flags, new_flags));

	return self->slots[new_flags & 3];
	}


#endif /* Z_functions_buffer_H */
