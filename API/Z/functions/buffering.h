/* Z Kit - functions/buffering.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2012 Remis.
Copyright (C) 2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_buffering_H
#define Z_functions_buffering_H

#include <Z/macros/language.h>
#include <Z/types/buffering.h>
#include <Z/functions/atomic.h>


static Z_INLINE
void z_triple_buffer_initialize(ZTripleBuffer* self, void *slots, zusize slot_size)
	{
	self->slots[0] = (zuchar *)slots;
	self->slots[1] = (zuchar *)slots + slot_size;
	self->slots[2] = (zuchar *)slots + slot_size * 2;
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
		new_flags = (zuchar)(64 | ((flags & 12) << 2) | ((flags & 48) >> 2) | (flags & 3));
		}
	while (!z_type_atomic_set_if_equal(UCHAR)(&self->flags, flags, new_flags));

	return self->slots[(new_flags & 48) >> 4];
	}


static Z_INLINE
void *z_triple_buffer_consume(ZTripleBuffer *self)
	{
	zuchar flags, new_flags;

	do	{
		if (!((flags = self->flags) & 64)) return NULL;
		new_flags = (zuchar)((flags & 48) | ((flags & 3) << 2) | ((flags & 12) >> 2));
		}
	while (!z_type_atomic_set_if_equal(UCHAR)(&self->flags, flags, new_flags));

	return self->slots[new_flags & 3];
	}


#endif /* Z_functions_buffering_H */
