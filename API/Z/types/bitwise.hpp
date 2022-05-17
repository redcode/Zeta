/* Zeta API - Z/types/bitwise.hpp
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_bitwise_HPP
#define Z_types_bitwise_HPP

#include <Z/types/bitwise.h>
#include <Z/inspection/Z.h>

namespace Zeta {
#	if Z_HAS(ZInt8)
#		define Z_HAS_Int8 TRUE
		typedef ZInt8 Int8;
#	endif

#	if Z_HAS(ZInt16)
#		define Z_HAS_Int16 TRUE
		typedef ZInt16 Int16;
#	endif

#	if Z_HAS(ZInt32)
#		define Z_HAS_Int32 TRUE
		typedef ZInt32 Int32;
#	endif

#	if Z_HAS(ZInt64)
#		define Z_HAS_Int64 TRUE
		typedef ZInt64 Int64;
#	endif

#	if Z_HAS(ZInt128)
#		define Z_HAS_Int128 TRUE
		typedef ZInt128 Int128;
#	endif
}

#endif // Z_types_bitwise_HPP
