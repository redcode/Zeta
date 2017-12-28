/* Z Kit C++ API - classes/buffering/RingBuffer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_buffering_RingBuffer_HPP__
#define __Z_classes_buffering_RingBuffer_HPP__

#include <Z/types/base.hpp>
#include <Z/types/buffering.h>
#include <Z/functions/base/value.h>

#ifndef z_cpu_relax
#	define z_cpu_relax() asm volatile("pause\n": : :"memory")
#endif


namespace Zeta {struct RingBuffer : public ZRingBuffer {

	Z_INLINE_MEMBER RingBuffer() {}


	Z_INLINE_MEMBER RingBuffer(void *buffers, Size buffer_size, Size buffer_count)
		{initialize(buffers, buffer_size, buffer_count);}


	Z_INLINE_MEMBER void initialize(void *buffers, Size buffer_size, Size buffer_count)
		{
		this->buffers		= buffers;
		this->buffer_size	= buffer_size;
		this->buffer_count	= buffer_count;
		this->production_index  = 0;
		this->consumption_index = 0;
		this->fill_count	= 0;
		}


	Z_INLINE_MEMBER void *production_buffer() const
		{
		return buffer_count - fill_count
			? (UInt8 *)buffers + production_index * buffer_size
			: NULL;
		}


	Z_INLINE_MEMBER void *consumption_buffer() const
		{
		return fill_count
			? (UInt8 *)buffers + consumption_index * buffer_size
			: NULL;
		}


	Z_INLINE_MEMBER void *try_produce()
		{
		if (buffer_count == fill_count) return NULL;
		production_index = (production_index + 1) % buffer_count;
		z_type_atomic_increment_then_get(SIZE)(&fill_count);
		return (UInt8 *)buffers + production_index * buffer_size;
		}


	Z_INLINE_MEMBER void *try_consume()
		{
		if (!fill_count) return NULL;
		consumption_index = (consumption_index + 1) % buffer_count;
		z_type_atomic_decrement_then_get(SIZE)(&fill_count);
		return (UInt8 *)buffers + consumption_index * buffer_size;
		}


	Z_INLINE_MEMBER void *produce()
		{
		while (buffer_count == fill_count) z_cpu_relax();
		production_index = (production_index + 1) % buffer_count;
		z_type_atomic_increment_then_get(SIZE)(&fill_count);
		return (UInt8 *)buffers + production_index * buffer_size;
		}


	Z_INLINE_MEMBER void *consume()
		{
		if (!fill_count) z_cpu_relax();
		consumption_index = (consumption_index + 1) % buffer_count;
		z_type_atomic_decrement_then_get(SIZE)(&fill_count);
		return (UInt8 *)buffers + consumption_index * buffer_size;
		}
};}


#endif // __Z_classes_buffering_RingBuffer_HPP__
