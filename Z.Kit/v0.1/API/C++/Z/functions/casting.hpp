/* Z Kit C++ API - functions/casting.hpp
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_casting_HPP__
#define __Z_functions_casting_HPP__

namespace Zeta {

	template <typename To, typename From> inline To hard_cast(From what)
		{return *(To *)&what;}

}

#endif // __Z_functions_casting_HPP__
