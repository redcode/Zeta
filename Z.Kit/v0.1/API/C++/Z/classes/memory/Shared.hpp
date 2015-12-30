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

namespace ZKit{
	namespace Abstract {struct Shared;}
	template <typename T> struct Shared;
}


struct ZKit::Abstract::Shared {
	void *___object;
	void (* ___deallocate)(void *object);
	zsize ___retain_count;

	inline ~Shared() {if (!retain_count) ___deallocate(___object);}
};


template <typename T> struct ZKit::Shared : ZKit::Abstract::Shared {

	inline static void deallocate(T *object) {delete object;}

	inline Shared<T>() {}
	inline Shared<T>(const Shared &other) {}
};


#endif // __Z_classes_memory_Shared_HPP__
