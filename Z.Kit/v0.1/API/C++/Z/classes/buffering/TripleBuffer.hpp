/* Z Kit C++ API - classes/buffering/TripleBuffer.hpp

Copyright © 2012 Remis.
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_buffering_TripleBuffer_HPP__
#define __Z_classes_buffering_TripleBuffer_HPP__

#include <Z/types/buffering.h>
#include <Z/functions/base/value.h>

namespace ZKit {class TripleBuffer;}


class ZKit::TripleBuffer : public ZTripleBuffer {

	public:
	inline TripleBuffer() {}


	inline TripleBuffer(void *buffers, Size buffer_size)
		{
		this->buffers[0] = buffers;
		this->buffers[1] = (UInt8 *)buffers + buffer_size;
		this->buffers[2] = (UInt8 *)buffers + buffer_size * 2;
		this->flags	 = 6;
		}


	inline void *production_buffer()  {return buffers[(flags & 48) >> 4];}
	inline void *consumption_buffer() {return buffers[flags & 3];}


	inline void *produce()
		{
		UInt8 flags, new_flags;

		do	{
			flags = this->flags;
			new_flags = 64 | ((flags & 12) << 2) | ((flags & 48) >> 2) | (flags & 3);
			}
		while (!z_uint8_atomic_set_if_equal(&this->flags, flags, new_flags));

		return this->buffers[(new_flags & 48) >> 4];
		}


	inline void *consume()
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
