/* Z Kit - classes/TripleBuffer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2012 Remis.
Copyright (C) 2014-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_TripleBuffer_HPP
#define Z_classes_TripleBuffer_HPP

#include <Z/types/fundamental.hpp>
#include <Z/types/buffering.h>
#include <Z/functions/atomic.h>


namespace Zeta {struct TripleBuffer : public ZTripleBuffer {

	Z_INLINE TripleBuffer() Z_NOTHROW
		Z_DEFAULTED({})


	Z_INLINE TripleBuffer(void *buffers, USize buffer_size) Z_NOTHROW
		{initialize(buffers, buffer_size);}


	Z_INLINE void initialize(void *buffers, USize buffer_size) Z_NOTHROW
		{
		this->slots[0] = buffers;
		this->slots[1] = (UInt8 *)buffers + buffer_size;
		this->slots[2] = (UInt8 *)buffers + buffer_size * 2;
		this->flags	 = 6;
		}


	Z_INLINE void *production_buffer() const Z_NOTHROW
		{return slots[(flags & 48) >> 4];}


	Z_INLINE void *consumption_buffer() const Z_NOTHROW
		{return slots[flags & 3];}


	Z_INLINE void *produce() Z_NOTHROW
		{
		UInt8 flags, new_flags;

		do	{
			flags = this->flags;
			new_flags = 64 | ((flags & 12) << 2) | ((flags & 48) >> 2) | (flags & 3);
			}
		while (!z_uint8_atomic_set_if_equal(&this->flags, flags, new_flags));

		return this->slots[(new_flags & 48) >> 4];
		}


	Z_INLINE void *consume() Z_NOTHROW
		{
		UInt8 flags, new_flags;

		do	{
			if (!((flags = this->flags) & 64)) return NULL;
			new_flags = (flags & 48) | ((flags & 3) << 2) | ((flags & 12) >> 2);
			}
		while (!z_uint8_atomic_set_if_equal(&this->flags, flags, new_flags));

		return this->slots[new_flags & 3];;
		}
};}


#endif // Z_classes_TripleBuffer_HPP
