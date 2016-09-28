/* Z Kit C++ API - classes/memory/Shared.hpp
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Copyright © 2016 r-lyeh.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_memory_Shared_HPP__
#define __Z_classes_memory_Shared_HPP__

#include <Z/types/base.hpp>
#include <Z/macros/language.hpp>

namespace Zeta {template <class T> struct Shared;}


template <class T> struct Zeta::Shared {

	struct Owned {
		Size owner_count;
		T*   data;

		Z_INLINE_MEMBER Owned(T *object) : owner_count(1), data(data) {}
		Z_INLINE_MEMBER ~Owned() {delete data;}
	};

	Owned *owned;


	Z_INLINE_MEMBER Shared() : owned(NULL) {}


	Z_INLINE_MEMBER Shared(const Shared &shared)
		{if ((owned = shared.owned)) owned->owner_count++;}


	Z_INLINE_MEMBER Shared(T *object)
		{owned = object ? new Owned(object) : NULL;}


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


	Z_INLINE_MEMBER Shared &operator =(T *object)
		{
		if (owned)
			{
			if (owned->object == object) return *this;
			if (!--owned->owner_count) delete owned;
			}

		owned = object ? new Owned(object) : NULL;
		return *this;
		}


	Z_INLINE_MEMBER operator Boolean() const {return owned != NULL;}

	Z_INLINE_MEMBER Boolean operator ==(const Shared &shared) const {return owned == shared.owned;}
	Z_INLINE_MEMBER Boolean operator !=(const Shared &shared) const {return owned != shared.owned;}
	Z_INLINE_MEMBER T*	operator ->()			  const {return owned->data;}

	Z_INLINE_MEMBER T*   get	() const {return owned ? owned->data : NULL;}
	Z_INLINE_MEMBER Size owner_count() const {return owned->owner_count;}
};


#endif // __Z_classes_memory_Shared_HPP__
