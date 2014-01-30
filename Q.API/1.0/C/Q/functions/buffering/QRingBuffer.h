/* Q API - functioms/buffering/QRingBuffer.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_buffering_QRingBuffer_H__
#define __Q_functions_buffering_QRingBuffer_H__

#include <Q/types/buffering.h>
#include <Q/functions/base/value.h>

#define q_cpu_relax() asm volatile("pause\n": : :"memory")

Q_INLINE
void q_ring_buffer_initialize(
	QRingBuffer* object,
	void*	     data,
	qsize	     slot_size,
	qsize	     slot_count
)
	{
	object->data		  = data;
	object->slot_size	  = slot_size;
	object->slot_count	  = slot_count;
	object->production_index  = 0;
	object->consumption_index = 0;
	object->fill_count	  = 0;
	}


Q_INLINE
void* q_ring_buffer_production_slot(QRingBuffer *object)
	{
	return object->slot_count - object->fill_count
		? object->data + object->production_index * object->slot_size
		: NULL;
	}


Q_INLINE
void* q_ring_buffer_consumption_slot(QRingBuffer *object)
	{
	return object->fill_count
		? object->data + object->consumption_index * object->slot_size
		: NULL;
	}


Q_INLINE
void* q_ring_buffer_try_produce(QRingBuffer *object)
	{
	if (object->slot_count == object->fill_count) return NULL;

	object->production_index = (object->production_index + 1) % object->slot_count;
	q_value_atomic_increment_then_get(SIZE)(&object->fill_count);
	return object->data + object->production_index * object->slot_size;
	}


Q_INLINE
void* q_ring_buffer_try_consume(QRingBuffer *object)
	{
	if (!object->fill_count) return NULL;

	object->consumption_index = (object->consumption_index + 1) % object->slot_count;
	q_value_atomic_decrement_then_get(SIZE)(&object->fill_count);
	return object->data + object->consumption_index * object->slot_size;
	}


Q_INLINE
void* q_ring_buffer_produce(QRingBuffer *object)
	{
	while (object->slot_count == object->fill_count) q_cpu_relax();

	object->production_index = (object->production_index + 1) % object->slot_count;
	q_value_atomic_increment_then_get(SIZE)(&object->fill_count);
	return object->data + object->production_index * object->slot_size;
	}


Q_INLINE
void* q_ring_buffer_consume(QRingBuffer *object)
	{
	if (!object->fill_count) q_cpu_relax();

	object->consumption_index = (object->consumption_index + 1) % object->slot_count;
	q_value_atomic_decrement_then_get(SIZE)(&object->fill_count);
	return object->data + object->consumption_index * object->slot_size;
	}


#endif /* __Q_functions_buffering_QRingBuffer_H__ */
