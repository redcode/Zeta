/* Z Kit - functions/structure.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_structure_HPP_
#define _Z_functions_structure_HPP_

#include <Z/types/fundamental.hpp>

namespace Zeta {


	template <class T, class C>
	static Z_INLINE USize offset_of(T C::*member) Z_NOTHROW
		{
		return	(&reinterpret_cast<const UInt8 &>(reinterpret_cast<const C *>(sizeof(C))->*member) -
			  reinterpret_cast<const UInt8 *>(sizeof(C)));
		}


}

#endif // _Z_functions_structure_HPP_
