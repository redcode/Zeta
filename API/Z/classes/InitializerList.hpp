/* Z Kit - classes/InitializerList.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_InitializerList_HPP
#define Z_classes_InitializerList_HPP

#include <Z/types/fundamental.hpp>


namespace Zeta {template <class T> class InitializerList {

	private:
	const T* _begin;
	USize	 _size;

	public:

	Z_INLINE InitializerList()
	: _begin(NULL), _size(0) {}

	Z_INLINE InitializerList(const T *begin, USize size)
	: _begin(begin), _size(size) {}

	Z_INLINE USize	  size () const Z_NOTHROW {return _size;}
	Z_INLINE const T *begin() const Z_NOTHROW {return _begin;}
	Z_INLINE const T *end  () const Z_NOTHROW {return _begin + _size;}
};}


#endif // Z_classes_InitializerList_HPP
