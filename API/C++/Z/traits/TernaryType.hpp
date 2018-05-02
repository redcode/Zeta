/* Z Kit - traits/TernaryType.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_TernaryType_HPP__
#define __Z_traits_TernaryType_HPP__

#include <Z/types/base.hpp>

namespace Zeta {
	template <Boolean condition, class if_true, class if_false> struct TernaryType;

	template <class A, class B> struct TernaryType<true,  A, B> {typedef A type;};
	template <class A, class B> struct TernaryType<false, A, B> {typedef B type;};
}

#endif // __Z_traits_TernaryType_HPP__
