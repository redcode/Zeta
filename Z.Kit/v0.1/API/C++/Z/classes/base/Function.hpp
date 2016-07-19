/* Z Kit C++ API - classes/base/Function.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Function_HPP__
#define __Z_classes_base_Function_HPP__

#include <Z/types/base.hpp>
#include <Z/traits/Type.hpp>


namespace Zeta {template <typename T> struct Function {

	typedef T type;
	typedef typename Type<T>::return_type return_type;

	/*T *function;

	inline Function(T function) : function(function) {}

	return_type operator()(...) {}*/

};}

#endif // __Z_classes_base_Function_HPP__
