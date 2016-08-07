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
#include <Z/macros/pointer.h>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {

		template <typename T> struct Shared {

			struct Container {
				Size owner_count;
				T object;

				inline Container() : owner_count(0) {}

				template <class ...A>
				inline Container(A... arguments) : owner_count(0), object(arguments...) {}
			};

			Container *container;


			template <class ...A> static Shared<T> create(A...arguments)
				{
				Shared<T> shared;
				shared.container = new Container(arguments...);
				shared.container->owner_count = 1;
				return shared;
				}


			inline Shared<T>() : container(nullptr) {}


			inline Shared<T>(const Shared<T> &shared)
				{if ((container = shared.container)) container->owner_count++;}


			inline Shared<T>(Container *container)
				{if ((this->container = container)) container->owner_count++;}


			inline Shared<T>(void *object)
				{
				if (object)
					(container =
					 Z_BOP(Container *, object, -Z_OFFSET_OF(Container, object)))
						->owner_count++;
				}


			inline ~Shared<T>()
				{if (container && !--container->owner_count) delete container;}


			inline T* operator->()	  {return &container->object;}
			inline T* get()		  {return &container->object;}
			inline Size owner_count() {return container->owner_count;}
		};


		template <typename T, class ...A> Z_INLINE T *shared_new(A...arguments)
			{
			typename Shared<T>::Container *container =
			new typename Shared<T>::Container(arguments...);

			container->owner_count = 1;
			return &container->object;
			}


		template <typename T> Z_INLINE void shared_delete(T *object)
			{
			delete Z_BOP
				(typename Shared<T>::Container *, object,
				 -Z_OFFSET_OF(typename Shared<T>::Container, object));
			}

	}

#endif

#endif // __Z_classes_memory_Shared_HPP__
