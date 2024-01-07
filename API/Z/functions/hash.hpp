/* Zeta API - Z/functions/hash.hpp
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_hash_HPP
#define Z_functions_hash_HPP

#include <Z/macros/language.hpp>
#include <Z/macros/hash.h>
#include <Z/types/integral.hpp>


#define Z__FNV(type, hash_function, HASH_FUNCTION)				    \
										    \
	Z_CT(CPP14) type hash_function(const Char *string) Z_NOTHROW		    \
		{								    \
		type hash = Z_##HASH_FUNCTION##_INITIALIZER;			    \
										    \
		while (*string) hash = Z_##HASH_FUNCTION##_UPDATE(hash, *string++); \
		return hash;							    \
		}								    \
										    \
										    \
	Z_CT(CPP14) type hash_function(const Char *string, USize size) Z_NOTHROW    \
		{								    \
		type hash = Z_##HASH_FUNCTION##_INITIALIZER;			    \
										    \
		while (size--) hash = Z_##HASH_FUNCTION##_UPDATE(hash, *string++);  \
		return hash;							    \
		}


namespace Zeta {
	Z__FNV(UInt32, fnv0_32,  FNV0_32)
	Z__FNV(UInt32, fnv1_32,  FNV1_32)
	Z__FNV(UInt32, fnv1a_32, FNV1A_32)

#	ifdef Z_UINT64
#		define Z_HAS_fnv0_64  1
#		define Z_HAS_fnv1_64  1
#		define Z_HAS_fnv1a_64 1

		Z__FNV(UInt64, fnv0_64,  FNV0_64)
		Z__FNV(UInt64, fnv1_64,  FNV1_64)
		Z__FNV(UInt64, fnv1a_64, FNV1A_64)
#	endif
}


#undef Z__FNV

#endif // Z_functions_hash_HPP
