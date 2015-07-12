/* Q Kit C++ API - classes/buffering/RingBuffer.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_classes_buffering_RingBuffer_HPP__
#define __Q_classes_buffering_RingBuffer_HPP__

#include <Q/types/buffering.h>
#include <Q/functions/base/value.h>

#ifndef q_cpu_relax
#	define q_cpu_relax() asm volatile("pause\n": : :"memory")
#endif

namespace QKit {class RingBuffer;}


class QKit::RingBuffer : public QRingBuffer {

	public:
	inline RingBuffer() {}


	inline RingBuffer(void *buffers, Size buffer_size, Size buffer_count)
		{
		this->buffers		= buffers;
		this->buffer_size	= buffer_size;
		this->buffer_count	= buffer_count;
		this->production_index  = 0;
		this->consumption_index = 0;
		this->fill_count	= 0;
		}


	inline void *production_buffer()
		{
		return buffer_count - fill_count
			? (UInt8 *)buffers + production_index * buffer_size
			: NULL;
		}


	inline void *consumption_buffer()
		{
		return fill_count
			? (UInt8 *)buffers + consumption_index * buffer_size
			: NULL;
		}


	inline void *try_produce()
		{
		if (buffer_count == fill_count) return NULL;
		production_index = (production_index + 1) % buffer_count;
		q_value_atomic_increment_then_get(SIZE)(&fill_count);
		return (UInt8 *)buffers + production_index * buffer_size;
		}


	inline void *try_consume()
		{
		if (!fill_count) return NULL;
		consumption_index = (consumption_index + 1) % buffer_count;
		q_value_atomic_decrement_then_get(SIZE)(&fill_count);
		return (UInt8 *)buffers + consumption_index * buffer_size;
		}


	inline void *produce()
		{
		while (buffer_count == fill_count) q_cpu_relax();
		production_index = (production_index + 1) % buffer_count;
		q_value_atomic_increment_then_get(SIZE)(&fill_count);
		return (quint8 *)buffers + production_index * buffer_size;
		}


	inline void *consume()
		{
		if (!fill_count) q_cpu_relax();
		consumption_index = (consumption_index + 1) % buffer_count;
		q_value_atomic_decrement_then_get(SIZE)(&fill_count);
		return (UInt8 *)buffers + consumption_index * buffer_size;
		}
};


#endif // __Q_classes_buffering_RingBuffer_HPP__
