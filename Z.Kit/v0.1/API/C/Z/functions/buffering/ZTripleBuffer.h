/* Z Kit C API - functioms/buffering/ZTripleBuffer.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2012 Remis.
Copyright © 2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_buffering_ZTripleBuffer_H__
#define __Z_functions_buffering_ZTripleBuffer_H__

#include <Z/types/buffering.h>
#include <Z/functions/base/value.h>


Z_INLINE void z_triple_buffer_initialize(
	ZTripleBuffer* object,
	void const*    buffers,
	zsize	       buffer_size
)
	{
	object->buffers[0] = (zuint8 *)buffers;
	object->buffers[1] = (zuint8 *)buffers + buffer_size;
	object->buffers[2] = (zuint8 *)buffers + buffer_size * 2;
	object->flags	   = 6;
	}


Z_INLINE void *z_triple_buffer_production_buffer(ZTripleBuffer const *object)
	{return object->buffers[(object->flags & 48) >> 4];}


Z_INLINE void *z_triple_buffer_consumption_buffer(ZTripleBuffer const *object)
	{return object->buffers[object->flags & 3];}


Z_INLINE void *z_triple_buffer_produce(ZTripleBuffer *object)
	{
	zuint8 flags, new_flags;

	do	{
		flags = object->flags;
		new_flags = 64 | ((flags & 12) << 2) | ((flags & 48) >> 2) | (flags & 3);
		}
	while (!z_uint8_atomic_set_if_equal(&object->flags, flags, new_flags));

	return object->buffers[(new_flags & 48) >> 4];
	}


Z_INLINE void *z_triple_buffer_consume(ZTripleBuffer *object)
	{
	zuint8 flags, new_flags;

	do	{
		if (!((flags = object->flags) & 64)) return NULL;
		new_flags = (flags & 48) | ((flags & 3) << 2) | ((flags & 12) >> 2);
		}
	while (!z_uint8_atomic_set_if_equal(&object->flags, flags, new_flags));

	return object->buffers[new_flags & 3];;
	}


#endif /* __Z_functions_buffering_ZTripleBuffer_H__ */
