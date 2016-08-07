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

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {template <typename T> struct Shared;}


	template <typename T> struct Zeta::Shared {

		struct Container {
			Size owner_count;
			T object;

			inline Container() : owner_count(0) {}

			template <typename ...A>
			inline Container(A... args) : owner_count(0), object(args...) {}
		};

		Container *container;


		template <typename ...A> static Shared<T> create(A...args)
			{
			Shared<T> shared;
			shared.container = new Container(args...);
			shared.container->owner_count = 1;
			return shared;
			}


		inline Shared<T>() : container(nullptr) {}


		inline Shared<T>(const Shared<T> &shared)
			{if ((container = shared.container)) container->owner_count++;}


		inline Shared<T>(Shared<T>::Container *shared_container)
			{if ((container = shared_container)) container->owner_count++;}


		inline ~Shared<T>()
			{if (container && !--container->owner_count) delete container;}


		inline T* operator->()	  {return &container->object;}
		inline T* get()		  {return &container->object;}
		inline Size owner_count() {return container->owner_count;}
	};


#endif

#endif // __Z_classes_memory_Shared_HPP__
