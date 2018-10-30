/* Z Kit - traits/filtering.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_traits_filtering_HPP_
#define _Z_traits_filtering_HPP_

#include <Z/types/base.hpp>

#if Z_LANGUAGE_HAS(CPP, SFINAE)

	namespace Zeta {
		template <Boolean B, class T> struct EnableIf  {};
		template <Boolean B, class T> struct DisableIf {};

		template <class T> struct EnableIf <true,  T> {typedef T type;};
		template <class T> struct DisableIf<false, T> {typedef T type;};
	}

#	define Z_HAS_TRAIT_ENABLE_IF  TRUE
#	define Z_HAS_TRAIT_DISABLE_IF TRUE
#else
#	define Z_HAS_TRAIT_ENABLE_IF  FALSE
#	define Z_HAS_TRAIT_DISABLE_IF FALSE
#endif

#endif // _Z_traits_filtering_HPP_
