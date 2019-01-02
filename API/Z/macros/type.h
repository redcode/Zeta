/* Z Kit - macros/type.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_type_H_
#define _Z_macros_type_H_

#include <Z/macros/control.h>
#include <Z/types/fundamental.h>

#define Z_ENUMERATE_FIXED_NATURAL_TYPES_BITS(prefix, invalid)		 \
	prefix##8, prefix##16, prefix##32,				 \
	Z_TERNARY(Z_DATA_MODEL_HAS_TYPE(UINT64 ))(prefix##64,  invalid), \
	Z_TERNARY(Z_DATA_MODEL_HAS_TYPE(UINT128))(prefix##128, invalid)

#define Z_ENUMERATE_FIXED_INTEGER_TYPES_BITS(prefix, invalid)		 \
	prefix##8, prefix##16, prefix##32,				 \
	Z_TERNARY(Z_DATA_MODEL_HAS_TYPE(SINT64 ))(prefix##64,  invalid), \
	Z_TERNARY(Z_DATA_MODEL_HAS_TYPE(SINT128))(prefix##128, invalid)

#define Z_ENUMERATE_FIXED_REAL_TYPES_SUFFIXES(prefix, invalid)			      \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT16	))(prefix##16,	    invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT32	))(prefix##32,	    invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT64	))(prefix##64,	    invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT128	))(prefix##128,	    invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT80_X87	))(prefix##80_X87,  invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT96_X87	))(prefix##96_X87,  invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT128_X87))(prefix##128_X87, invalid)

#define Z_ENUMERATE_FIXED_REAL_TYPES_Suffixes(prefix, invalid)			      \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT16	))(prefix##16,	    invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT32	))(prefix##32,	    invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT64	))(prefix##64,	    invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT128	))(prefix##128,	    invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT80_X87	))(prefix##80_x87,  invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT96_X87	))(prefix##96_x87,  invalid), \
	Z_TERNARY(Z_FLOATING_POINT_HAS_TYPE(FLOAT128_X87))(prefix##128_x87, invalid)

#define Z_ENUMERATE_FIXED_REAL_TYPES_suffixes \
	Z_ENUMERATE_FIXED_REAL_TYPES_Suffixes

#define ZKey(NAME) \
	Z_JOIN_2(Z_APPEND_NUMBER_, Z_KEY_BITS_##NAME)(zuint)

#endif /* _Z_macros_type_H_ */
