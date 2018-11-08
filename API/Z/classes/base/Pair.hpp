/* Z Kit - classes/base/Pair.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
-------------------------------------------------------------------------------
This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>.
---------------------------------------------------------------------------- */

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
