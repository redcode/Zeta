/* Zeta API - Z/functions/buffer.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2012 Remis.
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_buffer_H
#define Z_functions_buffer_H

#include <Z/constants/pointer.h>
#include <Z/macros/language.h>
#include <Z/types/buffer.h>
#include <Z/functions/atomic.h>


static Z_INLINE
void z_triple_buffer_initialize(ZTripleBuffer* self, void *data, zusize slot_size)
	{
	self->data[0] = (zchar *)data;
	self->data[1] = (zchar *)data + slot_size;
	self->data[2] = (zchar *)data + slot_size * 2;
	self->flags   = 6;
	}


static Z_INLINE
void *z_triple_buffer_production_slot(ZTripleBuffer const *self)
	{return self->data[(self->flags & 48) >> 4];}


static Z_INLINE
void *z_triple_buffer_consumption_slot(ZTripleBuffer const *self)
	{return self->data[self->flags & 3];}


static Z_INLINE
void *z_triple_buffer_produce(ZTripleBuffer *self)
	{
	zuchar flags, new_flags;

	do	{
		flags = self->flags;
		new_flags = (zuchar)(
			64		    |
			((flags & 12) << 2) |
			((flags & 48) >> 2) |
			 (flags & 3));
		}
	while (!z_T_atomic_set_if_equal(UCHAR)(&self->flags, flags, new_flags));

	return self->data[(new_flags & 48) >> 4];
	}


static Z_INLINE
void *z_triple_buffer_consume(ZTripleBuffer *self)
	{
	zuchar flags, new_flags;

	do	{
		if (!((flags = self->flags) & 64)) return Z_NULL;

		new_flags = (zuchar)(
			 (flags & 48)	    |
			((flags &  3) << 2) |
			((flags & 12) >> 2));
		}
	while (!z_T_atomic_set_if_equal(UCHAR)(&self->flags, flags, new_flags));

	return self->data[new_flags & 3];
	}


#endif /* Z_functions_buffer_H */
