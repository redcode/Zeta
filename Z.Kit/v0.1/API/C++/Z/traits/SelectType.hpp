/* Z Kit C++ API - traits/SelectType.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_SelectType_HPP__
#define __Z_traits_SelectType_HPP__

namespace Zeta {
	template <int, class A, class B> struct SelectType {};

	template <class A, class B> struct SelectType<0, A, B> {typedef A type;};
	template <class A, class B> struct SelectType<1, A, B> {typedef B type;};
}

#endif // __Z_traits_SelectType_HPP__
