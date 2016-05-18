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

#define Z_TEMPLATE_SAFER_ENABLE_DISABLE_IF(Prefix)			    \
									    \
template <bool, typename T> struct Prefix##EnableIf {};			    \
									    \
template <typename T> struct Prefix##EnableIf<false, T> : TypeOrVoid<> {};  \
template <typename T> struct Prefix##EnableIf<true,  T> {typedef T type;};  \
									    \
template <bool, typename T> struct Prefix##DisableIf {};		    \
									    \
template <typename T> struct Prefix##DisableIf<false, T> {typedef T type;}; \
template <typename T> struct Prefix##DisableIf<true,  T> : TypeOrVoid<> {};

namespace ZKit {
#	if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)
		template <bool, typename T = void> struct EnableIf {};
		template <typename T> struct EnableIf<true, T> {typedef T type;};

		template <bool, typename T = void> struct DisableIf {};
		template <typename T> struct DisableIf<false, T> {typedef T type;};

		Z_TEMPLATE_SAFER_ENABLE_DISABLE_IF(Safer)
#	else
		Z_TEMPLATE_SAFER_ENABLE_DISABLE_IF()
		Z_TEMPLATE_SAFER_ENABLE_DISABLE_IF(Safer)
#	endif
}

#endif // __Z_traits_conditionals_HPP__
