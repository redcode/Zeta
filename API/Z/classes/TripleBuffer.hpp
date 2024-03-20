/* Zeta API - Z/classes/TripleBuffer.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
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
		f	 = 6;
		}


	/// @brief Marks the current consumption slot as consumed.
	///
	/// @return A pointer to the new consumption slot.

	Z_INLINE void *consume() Z_NOTHROW
		{
		UChar fi, fo;

		do	{
			if (!((fi = f) & 64)) return Z_NULL;
			fo = UChar((fi & 48) | ((fi & 12) >> 2) | ((fi & 3) << 2));
			}
		while (!z_T_atomic_set_if_equal(UCHAR)(&f, fi, fo));

		return slots[fo & 3];
		}


	/// @brief Gets a pointer to the current consumption slot.
	///
	/// @return A pointer to the current consumption slot.

	Z_CT(CPP11) void *consumption() const Z_NOTHROW
		{return slots[f & 3];}


	/// @brief Gets the index of the current consumption slot.
	///
	/// @return The index of the current consumption slot.

	Z_CT(CPP11) UChar consumption_index() const Z_NOTHROW
		{return f & 3;}


	/// @brief Marks the the current production slot as produced.
	///
	/// @return A pointer to the new production slot.

	Z_INLINE void *produce() Z_NOTHROW
		{
		UChar fi, fo;

		do	{
			fi = f;
			fo = UChar(64 | ((fi & 48) >> 2) | ((fi & 12) << 2) | (fi & 3));
			}
		while (!z_T_atomic_set_if_equal(UCHAR)(&f, fi, fo));

		return slots[(fo & 48) >> 4];
		}


	/// @brief Gets a pointer to the production slot.
	///
	/// @return A pointer to the current production slot.

	Z_CT(CPP11) void *production() const Z_NOTHROW
		{return slots[(f & 48) >> 4];}


	/// @brief Gets the index of the current production slot.
	///
	/// @return The index of the current production slot.

	Z_CT(CPP11) UChar production_index() const Z_NOTHROW
		{return (f & 48) >> 4;}
};}


#endif // Z_classes_TripleBuffer_HPP
