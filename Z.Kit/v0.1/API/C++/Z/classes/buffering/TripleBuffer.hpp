/* Z Kit C++ API - classes/buffering/TripleBuffer.hpp
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2012 Remis.
Copyright © 2014-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_buffering_TripleBuffer_HPP__
#define __Z_classes_buffering_TripleBuffer_HPP__

#include <Z/types/base.hpp>
#include <Z/types/buffering.h>
#include <Z/macros/language.hpp>
#include <Z/functions/base/value.h>

namespace Zeta {struct TripleBuffer;}


struct Zeta::TripleBuffer : public ZTripleBuffer {

	Z_INLINE_MEMBER TripleBuffer() {}


	Z_INLINE_MEMBER TripleBuffer(void *buffers, Size buffer_size)
		{initialize(buffers, buffer_size);}


	Z_INLINE_MEMBER void initialize(void *buffers, Size buffer_size)
		{
		this->buffers[0] = buffers;
		this->buffers[1] = (UInt8 *)buffers + buffer_size;
		this->buffers[2] = (UInt8 *)buffers + buffer_size * 2;
		this->flags	 = 6;
		}


	Z_INLINE_MEMBER void *production_buffer () const {return buffers[(flags & 48) >> 4];}
	Z_INLINE_MEMBER void *consumption_buffer() const {return buffers[flags & 3];}


	Z_INLINE_MEMBER void *produce()
		{
		UInt8 flags, new_flags;

		do	{
			flags = this->flags;
			new_flags = 64 | ((flags & 12) << 2) | ((flags & 48) >> 2) | (flags & 3);
			}
		while (!z_uint8_atomic_set_if_equal(&this->flags, flags, new_flags));

		return this->buffers[(new_flags & 48) >> 4];
		}


	Z_INLINE_MEMBER void *consume()
		{
		UInt8 flags, new_flags;

		do	{
			if (!((flags = this->flags) & 64)) return NULL;
			new_flags = (flags & 48) | ((flags & 3) << 2) | ((flags & 12) >> 2);
			}
		while (!z_uint8_atomic_set_if_equal(&this->flags, flags, new_flags));

		return this->buffers[new_flags & 3];;
		}
};


#endif // __Z_classes_buffering_TripleBuffer_HPP__
