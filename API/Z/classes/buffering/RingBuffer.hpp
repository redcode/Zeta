/* Z Kit - classes/buffering/RingBuffer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_buffering_RingBuffer_HPP_
#define _Z_classes_buffering_RingBuffer_HPP_

#include <Z/types/base.hpp>
#include <Z/types/buffering.h>
#include <Z/functions/base/value.h>

#ifndef z_cpu_relax
#	define z_cpu_relax() asm volatile("pause\n": : :"memory")
#endif


namespace Zeta {struct RingBuffer : public ZRingBuffer {

	Z_INLINE RingBuffer() Z_DEFAULTED({})


	Z_INLINE RingBuffer(void *buffers, USize buffer_size, USize buffer_count)
		{initialize(buffers, buffer_size, buffer_count);}


	Z_INLINE void initialize(void *buffers, USize buffer_size, USize buffer_count)
		{
		this->buffers		= buffers;
		this->buffer_size	= buffer_size;
		this->buffer_count	= buffer_count;
		this->production_index	= 0;
		this->consumption_index = 0;
		this->fill_count	= 0;
		}


	Z_INLINE void *production_buffer() const
		{
		return buffer_count - fill_count
			? (UInt8 *)buffers + production_index * buffer_size
			: NULL;
		}


	Z_INLINE void *consumption_buffer() const
		{
		return fill_count
			? (UInt8 *)buffers + consumption_index * buffer_size
			: NULL;
		}


	Z_INLINE void *try_produce()
		{
		if (buffer_count == fill_count) return NULL;
		production_index = (production_index + 1) % buffer_count;
		z_type_atomic_increment_then_get(USIZE)(&fill_count);
		return (UInt8 *)buffers + production_index * buffer_size;
		}


	Z_INLINE void *try_consume()
		{
		if (!fill_count) return NULL;
		consumption_index = (consumption_index + 1) % buffer_count;
		z_type_atomic_decrement_then_get(USIZE)(&fill_count);
		return (UInt8 *)buffers + consumption_index * buffer_size;
		}


	Z_INLINE void *produce()
		{
		while (buffer_count == fill_count) z_cpu_relax();
		production_index = (production_index + 1) % buffer_count;
		z_type_atomic_increment_then_get(USIZE)(&fill_count);
		return (UInt8 *)buffers + production_index * buffer_size;
		}


	Z_INLINE void *consume()
		{
		if (!fill_count) z_cpu_relax();
		consumption_index = (consumption_index + 1) % buffer_count;
		z_type_atomic_decrement_then_get(USIZE)(&fill_count);
		return (UInt8 *)buffers + consumption_index * buffer_size;
		}
};}


#endif // _Z_classes_buffering_RingBuffer_HPP_
