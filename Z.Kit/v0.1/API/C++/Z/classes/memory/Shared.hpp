/* Z Kit C++ API - classes/memory/Shared.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_memory_Shared_HPP__
#define __Z_classes_memory_Shared_HPP__

#include <Z/types/base.hpp>


template <class T> struct Shared {
	T*   data;
	Size retain_count;

	Shared<T>()
		{
		data = nullptr;
		retain_count = 0;
		}

	Shared<T>(T*) {}
	Shared<T>(T&) {}
	Shared<T>(Shared<T>*) {}
	Shared<T>(Shared<T>&) {}


	~Shared()
		{
		}

};


#endif // __Z_classes_memory_Shared_HPP__
