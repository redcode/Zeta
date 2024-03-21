/* Zeta API - Z/traits/constants.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_traits_constants_HPP
#define Z_traits_constants_HPP

#include <Z/macros/language.hpp>

namespace Zeta {
	struct True  {enum {value = true };};
	struct False {enum {value = false};};

	template <Boolean = true> struct Maybe {};
}

#endif // Z_traits_constants_HPP
