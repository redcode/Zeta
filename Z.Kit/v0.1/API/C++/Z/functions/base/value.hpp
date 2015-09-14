/* Z Kit C++ API - functions/base/value.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_value_HPP__
#define __Z_functions_base_value_HPP__

#include <Z/types/base.hpp>
#include <Z/macros/value.h>


namespace ZKit {

	template <typename T> inline void swap(T *a, T *b) {T t = *a; *a = *b; *b = t;}

	template <typename T> inline T maximum(T a, T b) {return a > b ? a : b;}
	template <typename T> inline T minimum(T a, T b) {return a < b ? a : b;}

	template <typename T> inline T clamp(T value, T minimum, T maximum)
		{return ZKit::minimum(ZKit::maximum(value, minimum), maximum);}

}

#endif // __Z_functions_base_value_HPP__
