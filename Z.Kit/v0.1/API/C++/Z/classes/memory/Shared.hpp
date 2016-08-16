/* Z Kit C++ API - classes/memory/Shared.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Copyright © 2016 r-lyeh.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_memory_Shared_HPP__
#define __Z_classes_memory_Shared_HPP__

#include <Z/types/base.hpp>
#include <Z/macros/language.hpp>

namespace Zeta {template <typename T> struct Shared;}


template <typename T> struct Zeta::Shared {

	struct Owned {
		Size owner_count;
		T*   object;

		Z_INLINE_MEMBER Owned(T *object) : owner_count(1), object(object) {}
		Z_INLINE_MEMBER ~Owned() {delete object;}
	};

	Owned *owned;


	Z_INLINE_MEMBER Shared<T>() : owned(nullptr) {}


	Z_INLINE_MEMBER Shared<T>(const Shared<T> &shared)
		{if ((owned = shared.owned)) owned->owner_count++;}


	Z_INLINE_MEMBER Shared<T>(T *object)
		{owned = object ? new Owned(object) : NULL;}


	Z_INLINE_MEMBER ~Shared<T>()
		{if (owned && !--owned->owner_count) delete owned;}


	Z_INLINE_MEMBER Shared<T> &operator =(const Shared<T> &shared)
		{
		if (owned != shared.owned)
			{
			if (owned && !--owned->owner_count) delete owned;
			if ((owned = shared.owned)) owned->owner_count++;
			}

		return *this;
		}


	Z_INLINE_MEMBER Shared<T> &operator =(T *object)
		{
		if (owned)
			{
			if (owned->object == object) return *this;
			if (!--owned->owner_count) delete owned;
			}

		owned = object ? new Owned(object) : NULL;

		return *this;
		}


	Z_INLINE_MEMBER Boolean operator ==(const Shared<T> &shared) const {return owned == shared.owned;}
	Z_INLINE_MEMBER Boolean operator !=(const Shared<T> &shared) const {return owned != shared.owned;}
	Z_INLINE_MEMBER T*	operator ->()			     const {return owned->object;}

	Z_INLINE_MEMBER T*   get	() const {return owned->object;}
	Z_INLINE_MEMBER Size owner_count() const {return owned->owner_count;}
};


#endif // __Z_classes_memory_Shared_HPP__
