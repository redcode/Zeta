/* Z Kit C API - macros/type enumeration.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_type_enumeration_H__
#define __Z_macros_type_enumeration_H__

#include <Z/types/base.h>

#define Z_ENUMERATE_FIXED_NATURAL_TYPES(prefix, invalid)		 \
	prefix##8, prefix##16, prefix##32,				 \
	Z_TERNARY(Z_DATA_MODEL_HAS_TYPE(UINT64 ))(prefix##64,  invalid), \
	Z_TERNARY(Z_DATA_MODEL_HAS_TYPE(UINT128))(prefix##128, invalid)

#define Z_ENUMERATE_FIXED_INTEGER_TYPES(prefix, invalid)		\
	prefix##8, prefix##16, prefix##32,				\
	Z_TERNARY(Z_DATA_MODEL_HAS_TYPE(INT64 ))(prefix##64,  invalid),	\
	Z_TERNARY(Z_DATA_MODEL_HAS_TYPE(INT128))(prefix##128, invalid)

#define Z_ENUMERATE_FIXED_REAL_TYPES(prefix, invalid)							 \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT16 ))(prefix##16,  invalid),				 \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT24 ))(prefix##24,  invalid),				 \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT32 ))(prefix##32,  invalid), invalid,			 \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT48 ))(prefix##48,  invalid), invalid,			 \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT64 ))(prefix##64,  invalid),				 \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT72 ))(prefix##72,  invalid),				 \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT80 ))(prefix##80,  invalid), invalid,			 \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT96 ))(prefix##96,  invalid), invalid, invalid, invalid, \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT128))(prefix##128, invalid)

#endif /* __Z_macros_type_enumeration_H__ */
