/* Z Kit C++ API - functions/casting.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_casting_HPP__
#define __Z_functions_casting_HPP__

namespace ZKit {

	template <typename To, typename From> inline To hard_cast(From what)
		{return *(To *)&what;}

}

#endif // __Z_functions_casting_HPP__
