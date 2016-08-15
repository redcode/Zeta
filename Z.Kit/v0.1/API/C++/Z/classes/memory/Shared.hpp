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
#include <Z/macros/pointer.h>


#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {struct Shared;}

	template <typename T> struct Zeta::Shared {

		struct Owned {
			Size owner_count;
			T object;

			Z_INLINE_MEMBER Owned() : owner_count(0) {}

			template <class ...A>
			Z_INLINE_MEMBER Owned(A&&... arguments) : owner_count(0), object(arguments...) {}
		};

		Owned *owned;


		template <class ...A>
		static Z_INLINE_MEMBER Shared<T> make(A&&...arguments)
			{
			Shared<T> shared;
			shared.owned = new Owned(arguments...);
			shared.owned->owner_count = 1;
			return shared;
			}


		Z_INLINE_MEMBER Shared<T>() : owned(NULL) {}


		Z_INLINE_MEMBER Shared<T>(const Shared<T> &shared)
			{if ((owned = shared.owned)) owned->owner_count++;}


		Z_INLINE_MEMBER Shared<T>(Owned *owned)
			{if ((this->owned = owned)) owned->owner_count++;}


		Z_INLINE_MEMBER Shared<T>(void *object)
			{
			if (object)
				(owned = Z_BOP(Owned *, object, -Z_OFFSET_OF(Owned, object)))
					->owner_count++;
			}


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


		Z_INLINE_MEMBER Boolean operator ==(const Shared<T> &shared) const {return owned == shared.owned;}
		Z_INLINE_MEMBER Boolean operator !=(const Shared<T> &shared) const {return owned != shared.owned;}
		Z_INLINE_MEMBER T*	operator ->()			     const {return &owned->object;}

		Z_INLINE_MEMBER T*   get	() const {return &owned->object;}
		Z_INLINE_MEMBER Size owner_count() const {return owned->owner_count;}
	};


	namespace Zeta {

		template <typename T, class ...A>
		Z_INLINE T *owned_new(A&&...arguments)
			{return &(new typename Shared<T>::Owned(arguments...))->object;}


		template <typename T>
		Z_INLINE void owned_delete(T *object)
			{
			delete Z_BOP
				(typename Shared<T>::Owned *, object,
				 -Z_OFFSET_OF(typename Shared<T>::Owned, object));
			}


		template <typename T, class ...A>
		Z_INLINE Shared<T> shared_make(A&&...arguments)
			{return Shared<T>::make(arguments...);}
	}

#endif


#endif // __Z_classes_memory_Shared_HPP__
