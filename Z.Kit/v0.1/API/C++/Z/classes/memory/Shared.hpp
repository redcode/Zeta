/* Z Kit C++ API - classes/memory/Shared.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2016 r-lyeh.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_memory_Shared_HPP__
#define __Z_classes_memory_Shared_HPP__

#include <Z/functions/base/value.hpp>


namespace Zeta {template <class T> struct Shared {

	struct Owned {
		Size owner_count;
		T*   data;

		Z_INLINE_MEMBER Owned(T *data) : owner_count(1), data(data) {}
		Z_INLINE_MEMBER ~Owned() {delete data;}
	};

	Owned *owned;


	Z_CT_MEMBER(CPP11) Shared() : owned(NULL) {}


	Z_INLINE_MEMBER Shared(const Shared &shared)
		{if ((owned = shared.owned)) owned->owner_count++;}


	Z_INLINE_MEMBER Shared(T *data)
		{owned = data ? new Owned(data) : NULL;}


	Z_INLINE_MEMBER ~Shared()
		{if (owned && !--owned->owner_count) delete owned;}


	Z_INLINE_MEMBER Shared &operator =(const Shared &shared)
		{
		if (owned != shared.owned)
			{
			if (owned && !--owned->owner_count) delete owned;
			if ((owned = shared.owned)) owned->owner_count++;
			}

		return *this;
		}


	Z_INLINE_MEMBER Shared &operator =(T *data)
		{
		if (owned)
			{
			if (owned->data == data) return *this;
			if (!--owned->owner_count) delete owned;
			}

		owned = data ? new Owned(data) : NULL;
		return *this;
		}


	Z_INLINE_MEMBER operator Boolean() const {return owned != NULL;}

	Z_INLINE_MEMBER Boolean operator ==(const Shared &shared) const {return owned == shared.owned;}
	Z_INLINE_MEMBER Boolean operator !=(const Shared &shared) const {return owned != shared.owned;}

	Z_INLINE_MEMBER T* operator ->() const {return owned->data;}


	Z_INLINE_MEMBER T *get() const
		{return owned ? owned->data : NULL;}


	Z_INLINE_MEMBER Size owner_count() const
		{return owned->owner_count;}


	Z_INLINE_MEMBER void swap(Shared &shared)
		{Zeta::swap<Owned *>(&owned, &shared.owned);}
};}


#endif // __Z_classes_memory_Shared_HPP__
