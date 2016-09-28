/* Z Kit C++ API - traits/TypeOrVoid.hpp
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_TypeOrVoid_HPP__
#define __Z_traits_TypeOrVoid_HPP__

namespace Zeta {
	template <class T = void> struct TypeOrVoid {typedef T type;};
}

#endif // __Z_traits_TypeOrVoid_HPP__
