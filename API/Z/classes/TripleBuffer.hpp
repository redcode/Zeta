/* Zeta API - Z/classes/TripleBuffer.hpp
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_TripleBuffer_HPP
#define Z_classes_TripleBuffer_HPP

#include <Z/constants/pointer.h>
#include <Z/macros/language.hpp>
#include <Z/types/buffer.h>
#include <Z/types/integral.hpp>
#include <Z/functions/atomic.h>


namespace Zeta {struct TripleBuffer : ZTripleBuffer {

	Z_INLINE TripleBuffer() Z_NOTHROW
		Z_DEFAULTED({})


	Z_INLINE TripleBuffer(void *data_, USize slot_size) Z_NOTHROW
		{initialize(data_, slot_size);}


	/// @brief Initializes the object.
	///
	/// @param data_ A pointer to a buffer.
	/// @param slot_size The size of the slot.

	Z_INLINE void initialize(void *data_, USize slot_size) Z_NOTHROW
		{
		data[0] = data_;
		data[1] = reinterpret_cast<Char *>(data_) + slot_size;
		data[2] = reinterpret_cast<Char *>(data_) + slot_size * 2;
		flags	= 6;
		}


	/// @brief Gets a pointer to the production slot.
	///
	/// @return A pointer to the current production slot.

	Z_INLINE void *production_slot() const Z_NOTHROW
		{return data[(flags & 48) >> 4];}


	/// @brief Gets a pointer to the consumption slot.
	///
	/// @return A pointer to the current consumption slot.

	Z_INLINE void *consumption_slot() const Z_NOTHROW
		{return data[flags & 3];}


	/// @brief Marks the the current production slot as produced.
	///
	/// @return A pointer to the new production slot.

	Z_INLINE void *produce() Z_NOTHROW
		{
		UChar flags, new_flags;

		do	{
			flags = this->flags;

			new_flags = UChar(
				64		    |
				((flags & 12) << 2) |
				((flags & 48) >> 2) |
				 (flags & 3));
			}
		while (!z_T_atomic_set_if_equal(UCHAR)(&this->flags, flags, new_flags));

		return data[(new_flags & 48) >> 4];
		}


	/// @brief Marks the current consumption slot as consumed.
	///
	/// @return A pointer to the new consumption slot.

	Z_INLINE void *consume() Z_NOTHROW
		{
		UChar flags, new_flags;

		do	{
			if (!((flags = this->flags) & 64)) return Z_NULL;

			new_flags = UChar(
				 (flags & 48)	    |
				((flags &  3) << 2) |
				((flags & 12) >> 2));
			}
		while (!z_T_atomic_set_if_equal(UCHAR)(&this->flags, flags, new_flags));

		return data[new_flags & 3];
		}
};}


#endif // Z_classes_TripleBuffer_HPP
