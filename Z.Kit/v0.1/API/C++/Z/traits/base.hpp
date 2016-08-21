/* Z Kit C++ API - traits/base.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_base_HPP__
#define __Z_traits_base_HPP__

namespace Zeta {
	struct Empty {};
	struct True  {enum {value = true };};
	struct False {enum {value = false};};
}

#endif // __Z_traits_base_HPP__
