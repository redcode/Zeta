/* Q API - functioms/buffering/QRingBuffer.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_buffering_QRingBuffer_H__
#define __Q_functions_buffering_QRingBuffer_H__

#include <Q/types/buffering.h>
#include <Q/functions/base/value.h>

#define q_cpu_relax() asm volatile("pause\n": : :"memory")


Q_INLINE void q_ring_buffer_initialize(
	QRingBuffer* object,
	void*	     buffers,
	qsize	     buffer_size,
	qsize	     buffer_count
)
	{
	object->buffers		  = buffers;
	object->buffer_size	  = buffer_size;
	object->buffer_count	  = buffer_count;
	object->production_index  = 0;
	object->consumption_index = 0;
	object->fill_count	  = 0;
	}


Q_INLINE void *q_ring_buffer_production_buffer(QRingBuffer *object)
	{
	return object->buffer_count - object->fill_count
		? object->buffers + object->production_index * object->buffer_size
		: NULL;
	}


Q_INLINE void *q_ring_buffer_consumption_buffer(QRingBuffer *object)
	{
	return object->fill_count
		? object->buffers + object->consumption_index * object->buffer_size
		: NULL;
	}


Q_INLINE void *q_ring_buffer_try_produce(QRingBuffer *object)
	{
	if (object->buffer_count == object->fill_count) return NULL;

	object->production_index =
	(object->production_index + 1) % object->buffer_count;

	q_value_atomic_increment_then_get(SIZE)(&object->fill_count);
	return object->buffers + object->production_index * object->buffer_size;
	}


Q_INLINE void *q_ring_buffer_try_consume(QRingBuffer *object)
	{
	if (!object->fill_count) return NULL;

	object->consumption_index =
	(object->consumption_index + 1) % object->buffer_count;

	q_value_atomic_decrement_then_get(SIZE)(&object->fill_count);
	return object->buffers + object->consumption_index * object->buffer_size;
	}


Q_INLINE void *q_ring_buffer_produce(QRingBuffer *object)
	{
	while (object->buffer_count == object->fill_count) q_cpu_relax();

	object->production_index =
	(object->production_index + 1) % object->buffer_count;

	q_value_atomic_increment_then_get(SIZE)(&object->fill_count);
	return object->buffers + object->production_index * object->buffer_size;
	}


Q_INLINE void *q_ring_buffer_consume(QRingBuffer *object)
	{
	if (!object->fill_count) q_cpu_relax();

	object->consumption_index =
	(object->consumption_index + 1) % object->buffer_count;

	q_value_atomic_decrement_then_get(SIZE)(&object->fill_count);
	return object->buffers + object->consumption_index * object->buffer_size;
	}


#endif /* __Q_functions_buffering_QRingBuffer_H__ */
