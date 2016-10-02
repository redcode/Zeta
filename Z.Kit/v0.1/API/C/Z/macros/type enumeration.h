/* Z Kit C API - macros/type enumeration.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_type_enumeration_H__
#define __Z_macros_type_enumeration_H__

#include <Z/macros/conditionals.h>

#define Z_ENUMERATE_FIXED_NATURAL_TYPES(prefix, invalid)      \
	prefix##8, prefix##16, prefix##32,		      \
	Z_IF_UINT64_IS_AVAILABLE_ELSE (prefix##64,  invalid), \
	Z_IF_UINT128_IS_AVAILABLE_ELSE(prefix##128, invalid)

#define Z_ENUMERATE_FIXED_INTEGER_TYPES(prefix, invalid)     \
	prefix##8, prefix##16, prefix##32,		     \
	Z_IF_INT64_IS_AVAILABLE_ELSE (prefix##64,  invalid), \
	Z_IF_INT128_IS_AVAILABLE_ELSE(prefix##128, invalid)

#define Z_ENUMERATE_FIXED_REAL_TYPES(prefix, invalid)					  \
	Z_IF_FLOAT16_IS_AVAILABLE_ELSE (prefix##16,  invalid),				  \
	Z_IF_FLOAT24_IS_AVAILABLE_ELSE (prefix##24,  invalid),				  \
	Z_IF_FLOAT32_IS_AVAILABLE_ELSE (prefix##32,  invalid), invalid,			  \
	Z_IF_FLOAT48_IS_AVAILABLE_ELSE (prefix##48,  invalid), invalid,			  \
	Z_IF_FLOAT64_IS_AVAILABLE_ELSE (prefix##64,  invalid),				  \
	Z_IF_FLOAT72_IS_AVAILABLE_ELSE (prefix##72,  invalid),				  \
	Z_IF_FLOAT80_IS_AVAILABLE_ELSE (prefix##80,  invalid), invalid,			  \
	Z_IF_FLOAT96_IS_AVAILABLE_ELSE (prefix##96,  invalid), invalid, invalid, invalid, \
	Z_IF_FLOAT128_IS_AVAILABLE_ELSE(prefix##128, invalid)

#endif /* __Z_macros_type_enumeration_H__ */
