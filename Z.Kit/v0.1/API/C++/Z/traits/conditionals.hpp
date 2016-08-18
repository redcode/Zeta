/* Z Kit C++ API - traits/conditionals.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_conditionals_HPP__
#define __Z_traits_conditionals_HPP__

#include <Z/traits/TypeOrVoid.hpp>

#define Z_TEMPLATE_SAFER_ENABLE_DISABLE_IF(Prefix)			 \
									 \
template <bool, class T> struct Prefix##EnableIf {};			 \
									 \
template <class T> struct Prefix##EnableIf<false, T> : TypeOrVoid<> {};  \
template <class T> struct Prefix##EnableIf<true,  T> {typedef T type;};  \
									 \
template <bool, class T> struct Prefix##DisableIf {};			 \
									 \
template <class T> struct Prefix##DisableIf<false, T> {typedef T type;}; \
template <class T> struct Prefix##DisableIf<true,  T> : TypeOrVoid<> {};

namespace Zeta {
#	if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)
		template <bool, class T = void> struct EnableIf {};
		template <class T> struct EnableIf<true, T> {typedef T type;};

		template <bool, class T = void> struct DisableIf {};
		template <class T> struct DisableIf<false, T> {typedef T type;};

		Z_TEMPLATE_SAFER_ENABLE_DISABLE_IF(Safer)
#	else
		Z_TEMPLATE_SAFER_ENABLE_DISABLE_IF()
		Z_TEMPLATE_SAFER_ENABLE_DISABLE_IF(Safer)
#	endif
}

#endif // __Z_traits_conditionals_HPP__
