/* Z Kit C API - macros/type enumeration.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_type_enumeration_H__
#define __Z_macros_type_enumeration_H__

#include <Z/macros/filtering.h>

#define Z_ENUMERATE_FIXED_NATURAL_TYPES(prefix, invalid) \
	prefix##8, prefix##16, prefix##32,		 \
	Z_IF_DEFINED_UINT64_ELSE (prefix##64,  invalid), \
	Z_IF_DEFINED_UINT128_ELSE(prefix##128, invalid)

#define Z_ENUMERATE_FIXED_INTEGER_TYPES(prefix, invalid) \
	prefix##8, prefix##16, prefix##32,		 \
	Z_IF_DEFINED_INT64_ELSE (prefix##64,  invalid),  \
	Z_IF_DEFINED_INT128_ELSE(prefix##128, invalid)

#define Z_ENUMERATE_FIXED_REAL_TYPES(prefix, invalid)				     \
	Z_IF_DEFINED_FLOAT16_ELSE (prefix##16,	invalid),			     \
	Z_IF_DEFINED_FLOAT24_ELSE (prefix##24,	invalid),			     \
	Z_IF_DEFINED_FLOAT32_ELSE (prefix##32,	invalid), invalid,		     \
	Z_IF_DEFINED_FLOAT48_ELSE (prefix##48,	invalid), invalid,		     \
	Z_IF_DEFINED_FLOAT64_ELSE (prefix##64,	invalid),			     \
	Z_IF_DEFINED_FLOAT72_ELSE (prefix##72,	invalid),			     \
	Z_IF_DEFINED_FLOAT80_ELSE (prefix##80,	invalid), invalid,		     \
	Z_IF_DEFINED_FLOAT96_ELSE (prefix##96,	invalid), invalid, invalid, invalid, \
	Z_IF_DEFINED_FLOAT128_ELSE(prefix##128, invalid)

#endif /* __Z_macros_type_enumeration_H__ */
