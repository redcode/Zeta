/* Z Kit C++ API - traits/Same.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_Same_HPP__
#define __Z_traits_Same_HPP__

namespace ZKit {
	template <typename T = void> struct Same {typedef T type;};
}

#endif // __Z_traits_Same_HPP__
