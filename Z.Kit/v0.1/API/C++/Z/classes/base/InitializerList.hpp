/* Z Kit C++ API - classes/base/InitializerList.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_InitializerList_HPP__
#define __Z_classes_base_InitializerList_HPP__

#include <Z/types/base.hpp>

namespace Zeta {template <class T> class InitializerList;}


template <class T> class Zeta::InitializerList {
	private:
	const T* _begin;
	Size	 _size;

	public:

	Z_INLINE_MEMBER InitializerList()
	: _begin(NULL), _size(0) {}

	Z_INLINE_MEMBER InitializerList(const T *begin, Size size)
	: _begin(begin), _size(size) {}

	Z_INLINE_MEMBER Size	 size () const {return _size;}
	Z_INLINE_MEMBER const T *begin() const {return _begin;}
	Z_INLINE_MEMBER const T *end  () const {return _begin + _size;} 
};


#endif // __Z_classes_base_InitializerList_HPP__
