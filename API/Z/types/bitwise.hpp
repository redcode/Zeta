/* Zeta API - Z/types/bitwise.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_bitwise_HPP
#define Z_types_bitwise_HPP

#include <Z/types/bitwise.h>
#include <Z/inspection/Z.h>

namespace Zeta {
#	if Z_HAS(ZInt8)
#		define Z_HAS_Int8 1
		typedef ZInt8 Int8;
#	endif

#	if Z_HAS(ZInt16)
#		define Z_HAS_Int16 1
		typedef ZInt16 Int16;
#	endif

#	if Z_HAS(ZInt32)
#		define Z_HAS_Int32 1
		typedef ZInt32 Int32;
#	endif

#	if Z_HAS(ZInt64)
#		define Z_HAS_Int64 1
		typedef ZInt64 Int64;
#	endif

#	if Z_HAS(ZInt128)
#		define Z_HAS_Int128 1
		typedef ZInt128 Int128;
#	endif
}

#endif // Z_types_bitwise_HPP
