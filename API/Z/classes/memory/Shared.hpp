/* Z Kit - classes/memory/Shared.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2016 r-lyeh.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_memory_Shared_HPP_
#define _Z_classes_memory_Shared_HPP_

#include <Z/functions/base/value.hpp>


namespace Zeta {template <class T> struct Shared {

	struct Owned {
		T*    data;
		USize owner_count;

		Z_INLINE Owned(T *data) : data(data), owner_count(1) {}
		Z_INLINE ~Owned() {delete data;}
	};

	Owned *owned;


	Z_CT(CPP11) Shared() : owned(NULL) {}


	Z_INLINE Shared(const Shared &other)
		{if ((owned = other.owned)) owned->owner_count++;}


	Z_INLINE Shared(T *data)
		{owned = data ? new Owned(data) : NULL;}


	Z_INLINE ~Shared()
		{if (owned && !--owned->owner_count) delete owned;}


	Z_INLINE Shared &operator =(const Shared &rhs)
		{
		if (owned != rhs.owned)
			{
			if (owned && !--owned->owner_count) delete owned;
			if ((owned = rhs.owned)) owned->owner_count++;
			}

		return *this;
		}


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


	Z_INLINE operator Boolean() const {return owned != NULL;}

	Z_INLINE Boolean operator ==(const Shared &rhs) const {return owned == rhs.owned;}
	Z_INLINE Boolean operator !=(const Shared &rhs) const {return owned != rhs.owned;}

	Z_INLINE T &operator * () const {return *owned->data;}
	Z_INLINE T *operator ->() const {return  owned->data;}


	Z_INLINE T *get() const
		{return owned ? owned->data : NULL;}


	Z_INLINE USize owner_count() const
		{return owned->owner_count;}


	Z_INLINE void swap(Shared &other)
		{Zeta::swap<Owned *>(&owned, &other.owned);}
};}


#endif // _Z_classes_memory_Shared_HPP_
