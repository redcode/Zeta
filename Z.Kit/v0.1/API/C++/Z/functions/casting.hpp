/* Z Kit C++ API - functions/casting.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_casting_HPP__
#define __Z_functions_casting_HPP__

namespace Zeta {

	template <typename To, typename From> inline To hard_cast(From what)
		{return *(To *)&what;}

}

#endif // __Z_functions_casting_HPP__
