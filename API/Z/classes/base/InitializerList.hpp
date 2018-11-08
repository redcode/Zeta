/* Z Kit - classes/base/InitializerList.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_base_InitializerList_HPP_
#define _Z_classes_base_InitializerList_HPP_

#include <Z/types/base.hpp>


namespace Zeta {template <class T> class InitializerList {

	private:
	const T* _begin;
	USize	 _size;

	public:

	Z_INLINE InitializerList()
	: _begin(NULL), _size(0) {}

	Z_INLINE InitializerList(const T *begin, USize size)
	: _begin(begin), _size(size) {}

	Z_INLINE USize	  size () const {return _size;}
	Z_INLINE const T *begin() const {return _begin;}
	Z_INLINE const T *end  () const {return _begin + _size;}
};}


#endif // _Z_classes_base_InitializerList_HPP_
