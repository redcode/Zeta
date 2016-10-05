/* Z Kit C++ API - classes/base/Function.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Function_HPP__
#define __Z_classes_base_Function_HPP__

#include <Z/types/base.hpp>
#include <Z/traits/Type.hpp>


namespace Zeta {

	template <class, Size maximum_size = 1024> class Function;

	template <class R, class... A, Size maximum_size> class Function<R(A...), maximum_size> {
	};
}

#endif // __Z_classes_base_Function_HPP__
