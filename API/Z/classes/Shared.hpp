/* Z Kit - classes/Shared.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Shared_HPP
#define Z_classes_Shared_HPP

#include <Z/types/integral.hpp>
#include <Z/types/pointer.hpp>


namespace Zeta {template <class T> struct Shared {

	struct Owned {
		T*    data;
		USize owner_count;


		Z_INLINE Owned(T *data) Z_NOTHROW
		: data(data), owner_count(1) {}


		Z_INLINE ~Owned()
			{delete data;}
	};

	Owned *owned;


	Z_CT(CPP11) Shared() Z_NOTHROW
	: owned(NULL) {}


	Z_INLINE Shared(const Shared &other) Z_NOTHROW
		{if ((owned = other.owned)) owned->owner_count++;}


	Z_INLINE Shared(T *data) Z_NOTHROW
		{owned = data ? new Owned(data) : NULL;}


	Z_INLINE ~Shared()
		{if (owned && !--owned->owner_count) delete owned;}


#	ifdef Z_NULLPTR

		Z_CT(CPP11) Shared(NullPtr) Z_NOTHROW
		: owned(nullptr) {}


		Z_INLINE Shared &operator =(NullPtr)
			{
			if (owned && !--owned->owner_count) delete owned;
			owned = nullptr;
			return *this;
			}

#	endif


	Z_INLINE Shared &operator =(const Shared &rhs)
		{
		if (owned != rhs.owned)
			{
			if (owned && !--owned->owner_count) delete owned;
			if ((owned = rhs.owned)) owned->owner_count++;
			}

		return *this;
		}


#	if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)

		Z_INLINE Shared &operator =(Shared &&rhs)
			{
			if (owned != rhs.owned)
				{
				if (owned && !--owned->owner_count) delete owned;
				owned = rhs.owned;
				rhs.owned = NULL;
				}

			return *this;
			}

#	endif


	Z_INLINE Shared &operator =(T *rhs)
		{
		if (owned)
			{
			if (owned->data == rhs) return *this;
			if (!--owned->owner_count) delete owned;
			}

		owned = rhs ? new Owned(rhs) : NULL;
		return *this;
		}


	Z_INLINE operator Boolean() const Z_NOTHROW
		{return owned != NULL;}


	Z_INLINE Boolean operator ==(const Shared &rhs) const Z_NOTHROW
		{return owned == rhs.owned;}


	Z_INLINE Boolean operator !=(const Shared &rhs) const Z_NOTHROW
		{return owned != rhs.owned;}


	Z_INLINE T &operator *() const Z_NOTHROW
		{return *owned->data;}


	Z_INLINE T *operator ->() const Z_NOTHROW
		{return owned->data;}


	Z_INLINE T *get() const Z_NOTHROW
		{return owned ? owned->data : NULL;}


	Z_INLINE USize owner_count() const Z_NOTHROW
		{return owned->owner_count;}


	Z_INLINE void reset()
		{
		if (owned && !--owned->owner_count) delete owned;
		owned = NULL;
		}


	Z_INLINE void swap(Shared &other) Z_NOTHROW
		{
		Owned *t = owned;

		owned = other.owned;
		other.owned = t;
		}
};}


#endif // Z_classes_Shared_HPP
