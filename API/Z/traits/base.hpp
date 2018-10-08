/* Z Kit - traits/base.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_base_HPP__
#define __Z_traits_base_HPP__

#include <Z/macros/language.hpp>

namespace Zeta {
	struct Empty {};
	struct True  {enum {value = true };};
	struct False {enum {value = false};};
}

#endif // __Z_traits_base_HPP__
