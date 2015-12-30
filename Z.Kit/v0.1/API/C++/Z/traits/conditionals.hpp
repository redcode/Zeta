/* Z Kit C++ API - traits/conditionals.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_conditionals_HPP__
#define __Z_traits_conditionals_HPP__

#include <Z/traits/Same.hpp>

namespace ZKit {
	template <bool, typename T> struct enable_if {};

	template <typename T> struct enable_if<false, T> : Same<> {};
	template <typename T> struct enable_if<true,  T> {typedef T type;};

	template <bool, typename T> struct disable_if {};

	template <typename T> struct disable_if<false, T> {typedef T type;};
	template <typename T> struct disable_if<true,  T> : Same<> {};
}

#endif // __Z_traits_conditionals_HPP__
