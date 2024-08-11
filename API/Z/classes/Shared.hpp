/* Zeta API - Z/classes/Shared.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Shared_HPP
#define Z_classes_Shared_HPP

#include <Z/constants/pointer.h>
#include <Z/macros/language.hpp>
#include <Z/types/integral.hpp>
#include <Z/types/pointer.hpp>


namespace Zeta {template <class t> struct Shared {

	struct Owned {
		t*    data;
		USize owner_count;


		Z_INLINE Owned(t *data) Z_NOTHROW
		: data(data), owner_count(1) {}


		Z_INLINE ~Owned()
			{delete data;}

	};

	Owned *owned;


	Z_CT(CPP11) Shared() Z_NOTHROW
	: owned(Z_NULL) {}


	Z_INLINE Shared(const Shared &other) Z_NOTHROW
		{if ((owned = other.owned)) owned->owner_count++;}


	Z_INLINE Shared(t *data) Z_NOTHROW
		{owned = data ? new Owned(data) : Z_NULL;}


	Z_INLINE ~Shared()
		{if (owned && !--owned->owner_count) delete owned;}


	Z_INLINE operator Boolean() const Z_NOTHROW
		{return Boolean(owned);}


	Z_INLINE Shared &operator =(const Shared &rhs)
		{
		if (owned != rhs.owned)
			{
			if (owned && !--owned->owner_count) delete owned;
			if ((owned = rhs.owned)) owned->owner_count++;
			}

		return *this;
		}


	Z_INLINE Shared &operator =(t *rhs)
		{
		if (owned)
			{
			if (owned->data == rhs) return *this;
			if (!--owned->owner_count) delete owned;
			}

		owned = rhs ? new Owned(rhs) : Z_NULL;
		return *this;
		}


	friend Z_INLINE Boolean operator ==(const Shared &lhs, const Shared &rhs) Z_NOTHROW
		{return lhs.owned == rhs.owned;}


	friend Z_INLINE Boolean operator !=(const Shared &lhs, const Shared &rhs) Z_NOTHROW
		{return lhs.owned != rhs.owned;}


	Z_INLINE t &operator *() const Z_NOTHROW
		{return *owned->data;}


	Z_INLINE t *operator ->() const Z_NOTHROW
		{return owned->data;}


	Z_INLINE t *get() const Z_NOTHROW
		{return owned ? owned->data : Z_NULL;}


	Z_INLINE USize owner_count() const Z_NOTHROW
		{return owned->owner_count;}


	Z_INLINE void reset()
		{
		if (owned && !--owned->owner_count) delete owned;
		owned = Z_NULL;
		}


	Z_INLINE void swap(Shared &other) Z_NOTHROW
		{
		Owned *ex = owned;

		owned = other.owned;
		other.owned = ex;
		}


#	ifdef Z_NULLPTR

		Z_CT(CPP11) Shared(NullPtr) Z_NOTHROW
		: owned(nullptr) {}


		Z_INLINE Shared &operator =(NullPtr)
			{
			if (owned && !--owned->owner_count) delete owned;
			owned = nullptr;
			return *this;
			}


		friend Z_INLINE Boolean operator ==(const Shared &lhs, NullPtr) Z_NOTHROW
			{return !lhs.owned;}


		friend Z_INLINE Boolean operator ==(NullPtr, const Shared &rhs) Z_NOTHROW
			{return !rhs.owned;}


		friend Z_INLINE Boolean operator !=(const Shared &lhs, NullPtr) Z_NOTHROW
			{return !!lhs.owned;}


		friend Z_INLINE Boolean operator !=(NullPtr, const Shared &rhs) Z_NOTHROW
			{return !!rhs.owned;}

#	endif


#	if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)

		Z_INLINE Shared(Shared &&other) Z_NOTHROW
		: owned(other.owned)
			{other.owned = Z_NULL;}


		Z_INLINE Shared &operator =(Shared &&rhs)
			{
			if (owned != rhs.owned)
				{
				if (owned && !--owned->owner_count) delete owned;
				owned = rhs.owned;
				rhs.owned = Z_NULL;
				}

			return *this;
			}

#	endif
};}


#endif // Z_classes_Shared_HPP
