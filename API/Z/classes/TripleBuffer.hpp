/* Zeta API - Z/classes/TripleBuffer.hpp
 ______ ______________  ___
|__   /|  ___|___  ___|/   \
  /  /_|  __|   |  |  /  -  \
 /_____|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
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


	Z_INLINE TripleBuffer(void *slot_0, void *slot_1, void *slot_2) Z_NOTHROW
		{initialize(slot_0, slot_1, slot_2);}


	Z_INLINE void initialize(void *slot_0, void *slot_1, void *slot_2) Z_NOTHROW
		{
		slots[0] = slot_0;
		slots[1] = slot_1;
		slots[2] = slot_2;
		flags	 = 6;
		}


	/// @brief Gets a pointer to the production slot.
	///
	/// @return A pointer to the current production slot.

	Z_INLINE void *production_slot() const Z_NOTHROW
		{return slots[(flags & 48) >> 4];}


	/// @brief Gets a pointer to the consumption slot.
	///
	/// @return A pointer to the current consumption slot.

	Z_INLINE void *consumption_slot() const Z_NOTHROW
		{return slots[flags & 3];}


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

		return slots[(new_flags & 48) >> 4];
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

		return slots[new_flags & 3];
		}
};}


#endif // Z_classes_TripleBuffer_HPP
