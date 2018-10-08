/* Z Kit - functions/base/structure.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_structure_HPP__
#define __Z_functions_base_structure_HPP__

#include <Z/types/base.hpp>

namespace Zeta {


	template <class T, class C>
	static Z_CT(CPP11) USize offset_of(T C::*member)
		{
		return	(&reinterpret_cast<const UInt8 &>(reinterpret_cast<const C *>(1)->*member) -
			  reinterpret_cast<const UInt8 *>(1));
		}


}

#endif // __Z_functions_base_structure_HPP__
