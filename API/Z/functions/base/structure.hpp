/* Z Kit - functions/base/structure.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_functions_base_structure_HPP_
#define _Z_functions_base_structure_HPP_

#include <Z/types/base.hpp>

namespace Zeta {


	template <class T, class C>
	static Z_CT(CPP11) USize offset_of(T C::*member)
		{
		return	(&reinterpret_cast<const UInt8 &>(reinterpret_cast<const C *>(1)->*member) -
			  reinterpret_cast<const UInt8 *>(1));
		}


}

#endif // _Z_functions_base_structure_HPP_
