/* Zeta API - Z/functions/hash.hpp
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_hash_HPP
#define Z_functions_hash_HPP

#include <Z/macros/language.hpp>
#include <Z/types/integral.hpp>


#define Z__IMPLEMENTATION(bits, offset_basis, prime)			  \
									  \
	Z_CT(CPP14) UInt##bits fnv0_##bits(const Char *string) Z_NOTHROW  \
		{							  \
		UInt##bits hash = 0;					  \
									  \
		while (*string) hash = (hash * prime) ^ *string++;	  \
		return hash;						  \
		}							  \
									  \
									  \
	Z_CT(CPP14) UInt##bits fnv1_##bits(const Char *string) Z_NOTHROW  \
		{							  \
		UInt##bits hash = offset_basis;				  \
									  \
		while (*string) hash = (hash * prime) ^ *string++;	  \
		return hash;						  \
		}							  \
									  \
									  \
	Z_CT(CPP14) UInt##bits fnv1a_##bits(const Char *string) Z_NOTHROW \
		{							  \
		UInt##bits hash = offset_basis;				  \
									  \
		while (*string) hash = (hash ^ *string++) * prime;	  \
		return hash;						  \
		}


namespace Zeta {
	Z__IMPLEMENTATION(32, Z_UINT32(2166136261), Z_UINT32(16777619))

#	ifdef Z_UINT64
		Z__IMPLEMENTATION(64, Z_UINT64(14695981039346656037), Z_UINT64(1099511628211))
#	endif
}


#undef Z__IMPLEMENTATION


#endif // Z_functions_hash_HPP
