/* Z Kit C++ API - traits/conditionals.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_conditionals_HPP__
#define __Z_traits_conditionals_HPP__

namespace ZKit {
	template <bool, typename T = void> struct enable_if {};
	template <typename T> struct enable_if<true, T> {typedef T type;};
}

#endif // __Z_traits_conditionals_HPP__
