/* Z Kit C++ API - classes/base/Pair.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Pair_HPP__
#define __Z_classes_base_Pair_HPP__

#include <Z/types/base.hpp>
#include <Z/traits/Type.hpp>

namespace Zeta {template <class T0, class T1> struct Pair;}


template <class T0, class T1> struct Zeta::Pair {
	typedef T0 first_type;
	typedef T1 second_type;

	T0 first;
	T1 second;

	Z_INLINE_MEMBER Pair(typename Type<T0>::to_argument first,
			     typename Type<T1>::to_argument second)
	: first(first), second(second) {}

	Z_INLINE_MEMBER ~Pair() {}
};


#endif // __Z_classes_base_Pair_HPP__
