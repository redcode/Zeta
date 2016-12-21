/* Z Kit C++ API - traits/TypeIsConvertible.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_TypeIsConvertible_HPP__
#define __Z_traits_TypeIsConvertible_HPP__

#include <Z/inspection/language.h>

namespace Zeta {

	// TODO
	template <class T, class to> struct TypeIsConvertible {
		enum {value = __is_convertible_to(T, to)};
	};

}

#endif // __Z_traits_TypeIsConvertible_HPP__
