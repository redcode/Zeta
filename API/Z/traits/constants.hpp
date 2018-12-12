/* Z Kit - traits/constants.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_traits_constants_HPP_
#define _Z_traits_constants_HPP_

#include <Z/types/fundamental.hpp>

namespace Zeta {

	template <class T, T V> struct Constant {
		typedef T type;
		static Z_CONSTANT T value = V;

		Z_CT(CPP11) T operator ()() const Z_NO_EXCEPTION {return V;}
	};

	struct True  : Constant<Boolean, true > {};
	struct False : Constant<Boolean, false> {};
}

#endif // _Z_traits_constants_HPP_
