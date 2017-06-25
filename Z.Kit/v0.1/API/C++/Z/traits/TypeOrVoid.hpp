/* Z Kit C++ API - traits/TypeOrVoid.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_TypeOrVoid_HPP__
#define __Z_traits_TypeOrVoid_HPP__

namespace Zeta {
	template <class T = void> struct TypeOrVoid {typedef T type;};
}

#endif // __Z_traits_TypeOrVoid_HPP__
