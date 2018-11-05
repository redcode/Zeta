/* Z Kit - traits/TernaryType.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_traits_TernaryType_HPP_
#define _Z_traits_TernaryType_HPP_

#include <Z/types/base.hpp>

namespace Zeta {
	template <Boolean condition, class if_true, class if_false> struct TernaryType;

	template <class A, class B> struct TernaryType<true,  A, B> {typedef A type;};
	template <class A, class B> struct TernaryType<false, A, B> {typedef B type;};
}

#endif // _Z_traits_TernaryType_HPP_
