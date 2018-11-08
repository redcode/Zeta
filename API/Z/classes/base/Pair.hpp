/* Z Kit - classes/base/Pair.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_base_Pair_HPP_
#define _Z_classes_base_Pair_HPP_

#include <Z/functions/base/value.hpp>


namespace Zeta {template <class T1, class T2> struct Pair {
	typedef T1 First;
	typedef T2 Second;

	T1 first;
	T2 second;

	Z_INLINE Pair() Z_DEFAULTED({})

	Z_CT(CPP11) Pair(
		typename Type<T1>::to_forwardable first,
		typename Type<T2>::to_forwardable second
	) : first(first), second(second) {}


	Z_CT(CPP11) Boolean operator ==(const Pair &pair) const
		{return first == pair.first && second == pair.second;}


	Z_CT(CPP11) Boolean operator !=(const Pair &pair) const
		{return first != pair.first || second != pair.second;}


	Z_INLINE void swap(Pair &pair)
		{
		Zeta::swap<typename Type<Pair>::to_opaque>
			((typename Type<Pair>::to_opaque *)this,
			 (typename Type<Pair>::to_opaque *)&pair);
		}
};}


#endif // _Z_classes_base_Pair_HPP_
