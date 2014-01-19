/* Q API - functioms/QTripleBuffer.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2012 Remis.
Copyright © 2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_QTripleBuffer_H__
#define __Q_functions_QTripleBuffer_H__

#include <Q/types/buffering.h>


Q_INLINE
void q_triple_buffer_initialize(
	QTripleBuffer* object,
	void*	       data,
	qsize	       buffer_size
)
	{
	object->slots[0] = data;
	object->slots[1] = data + buffer_size;
	object->slots[2] = data + buffer_size * 2;
	object->flags	 = 6;
	}


Q_INLINE
void *q_triple_buffer_consumption_slot(QTripleBuffer *object)
	{return object->slots[object->flags & 3];}


Q_INLINE
void *q_triple_buffer_production_slot(QTripleBuffer *object)
	{return object->slots[(object->flags & 0x30) >> 4];}


Q_INLINE
void* q_triple_buffer_produce(QTripleBuffer *object)
	{
	quint8 flags, new_flags;

	do	{
		flags = object->flags;
		new_flags = 0x40 | ((flags & 0xC) << 2) | ((flags & 0x30) >> 2) | (flags & 0x3);
		}
	while (!__sync_bool_compare_and_swap(&object->flags, flags, new_flags));

	return object->slots[(new_flags & 0x30) >> 4];
	}


Q_INLINE
void *q_triple_buffer_consume(QTripleBuffer *object)
	{
	quint8 flags, new_flags;

	do	{
		if (!((flags = object->flags) & 0x40)) return NULL;
		new_flags = (flags & 0x30) | ((flags & 0x3) << 2) | ((flags & 0xC) >> 2);
		}
	while (!__sync_bool_compare_and_swap(&object->flags, flags, new_flags));

	return object->slots[new_flags & 3];;
	}


#endif /* __Q_functions_QTripleBuffer_H__ */
