/* Z Kit C++ API - traits/TypeIsBase.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_TypeIsBase_HPP__
#define __Z_traits_TypeIsBase_HPP__

#include <Z/inspection/language.h>

namespace Zeta {

	// TODO
	template <class T, class of> struct TypeIsBase {
		enum {value = __is_base_of(T, of)};
	};

}

#endif // __Z_traits_TypeIsBase_HPP__
