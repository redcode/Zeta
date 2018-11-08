/* Z Kit - classes/buffering/TripleBuffer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2012 Remis.
Copyright (C) 2014-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_buffering_TripleBuffer_HPP_
#define _Z_classes_buffering_TripleBuffer_HPP_

#include <Z/types/base.hpp>
#include <Z/types/buffering.h>
#include <Z/functions/base/value.h>


namespace Zeta {struct TripleBuffer : public ZTripleBuffer {

	Z_INLINE TripleBuffer() Z_DEFAULTED({})


	Z_INLINE TripleBuffer(void *buffers, USize buffer_size)
		{initialize(buffers, buffer_size);}


	Z_INLINE void initialize(void *buffers, USize buffer_size)
		{
		this->buffers[0] = buffers;
		this->buffers[1] = (UInt8 *)buffers + buffer_size;
		this->buffers[2] = (UInt8 *)buffers + buffer_size * 2;
		this->flags	 = 6;
		}


	Z_INLINE void *production_buffer () const {return buffers[(flags & 48) >> 4];}
	Z_INLINE void *consumption_buffer() const {return buffers[flags & 3];}


	Z_INLINE void *produce()
		{
		UInt8 flags, new_flags;

		do	{
			flags = this->flags;
			new_flags = 64 | ((flags & 12) << 2) | ((flags & 48) >> 2) | (flags & 3);
			}
		while (!z_uint8_atomic_set_if_equal(&this->flags, flags, new_flags));

		return this->buffers[(new_flags & 48) >> 4];
		}


	Z_INLINE void *consume()
		{
		UInt8 flags, new_flags;

		do	{
			if (!((flags = this->flags) & 64)) return NULL;
			new_flags = (flags & 48) | ((flags & 3) << 2) | ((flags & 12) >> 2);
			}
		while (!z_uint8_atomic_set_if_equal(&this->flags, flags, new_flags));

		return this->buffers[new_flags & 3];;
		}
};}


#endif // _Z_classes_buffering_TripleBuffer_HPP_
