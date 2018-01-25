/* Z Kit C++ API - traits/filtering.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_filtering_HPP__
#define __Z_traits_filtering_HPP__

#include <Z/types/base.hpp>

#if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)

	namespace Zeta {
		template <Boolean, class T = void> struct EnableIf {};
		template <class T> struct EnableIf<true, T> {typedef T type;};

		template <Boolean, class T = void> struct DisableIf {};
		template <class T> struct DisableIf<false, T> {typedef T type;};
	}

#endif

#endif // __Z_traits_filtering_HPP__
