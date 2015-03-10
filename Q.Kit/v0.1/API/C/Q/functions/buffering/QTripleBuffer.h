/* Q Kit C API - functioms/buffering/QTripleBuffer.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2012 Remis.
Copyright © 2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_buffering_QTripleBuffer_H__
#define __Q_functions_buffering_QTripleBuffer_H__

#include <Q/types/buffering.h>
#include <Q/functions/base/value.h>


Q_INLINE void q_triple_buffer_initialize(
	QTripleBuffer* object,
	void*	       buffers,
	qsize	       buffer_size
)
	{
	object->buffers[0] = buffers;
	object->buffers[1] = (quint8 *)buffers + buffer_size;
	object->buffers[2] = (quint8 *)buffers + buffer_size * 2;
	object->flags	   = 6;
	}


Q_INLINE void *q_triple_buffer_production_buffer(QTripleBuffer *object)
	{return object->buffers[(object->flags & 48) >> 4];}


Q_INLINE void *q_triple_buffer_consumption_buffer(QTripleBuffer *object)
	{return object->buffers[object->flags & 3];}


Q_INLINE void *q_triple_buffer_produce(QTripleBuffer *object)
	{
	quint8 flags, new_flags;

	do	{
		flags = object->flags;

		new_flags =
		64 | ((flags & 12) << 2) | ((flags & 48) >> 2) | (flags & 3);
		}
	while (!q_uint8_atomic_set_if_equal(&object->flags, flags, new_flags));

	return object->buffers[(new_flags & 48) >> 4];
	}


Q_INLINE void *q_triple_buffer_consume(QTripleBuffer *object)
	{
	quint8 flags, new_flags;

	do	{
		if (!((flags = object->flags) & 64)) return NULL;

		new_flags =
		(flags & 48) | ((flags & 3) << 2) | ((flags & 12) >> 2);
		}
	while (!q_uint8_atomic_set_if_equal(&object->flags, flags, new_flags));

	return object->buffers[new_flags & 3];;
	}


#endif /* __Q_functions_buffering_QTripleBuffer_H__ */
