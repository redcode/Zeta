/* Z Kit - functions/structure.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_structure_HPP
#define Z_functions_structure_HPP

#include <Z/types/fundamental.hpp>

namespace Zeta {


	template <class T, class C>
	static Z_INLINE USize member_offset(T C::*member) Z_NOTHROW
		{
		return	(&reinterpret_cast<const UInt8 &>(reinterpret_cast<const C *>(sizeof(C))->*member) -
			  reinterpret_cast<const UInt8 *>(sizeof(C)));
		}


}

#endif // Z_functions_structure_HPP
