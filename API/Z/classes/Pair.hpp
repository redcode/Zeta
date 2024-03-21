/* Zeta API - Z/classes/Pair.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Pair_HPP
#define Z_classes_Pair_HPP

#include <Z/macros/language.hpp>
#include <Z/types/integral.hpp>


namespace Zeta {template <class t1, class t2 = t1> struct Pair {
	typedef t1 First;
	typedef t2 Second;

	t1 first;
	t2 second;

	Z_INLINE Pair() Z_DEFAULTED({})

	Z_CT(CPP11) Pair(
		typename Type<t1>::to_forwardable first,
		typename Type<t2>::to_forwardable second
	) : first(first), second(second) {}


	Z_CT(CPP11) Boolean operator ==(const Pair &pair) const
		{return first == pair.first && second == pair.second;}


	Z_CT(CPP11) Boolean operator !=(const Pair &pair) const
		{return first != pair.first || second != pair.second;}


	/*Z_INLINE void swap(Pair &pair)
		{
		Zeta::swap<typename Type<Pair>::to_opaque>(
			reinterpret_cast<typename Type<Pair>::to_opaque *>(this),
			reinterpret_cast<typename Type<Pair>::to_opaque *>(&pair));
		}*/
};}


#endif // Z_classes_Pair_HPP
