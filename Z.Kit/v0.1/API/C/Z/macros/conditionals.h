/* Z Kit C API - macros/filtering.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_filtering_H__
#define __Z_macros_filtering_H__

#include <Z/types/base.h>

#ifdef Z_UINT64
#	define Z_IF_UINT64_IS_AVAILABLE(what) what
#	define Z_IF_UINT64_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_UINT64_IS_AVAILABLE(what)
#	define Z_IF_UINT64_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_UINT128
#	define Z_IF_UINT128_IS_AVAILABLE(what) what
#	define Z_IF_UINT128_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_UINT128_IS_AVAILABLE(what)
#	define Z_IF_UINT128_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_INT64
#	define Z_IF_INT64_IS_AVAILABLE(what) what
#	define Z_IF_INT64_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_INT64_IS_AVAILABLE(what)
#	define Z_IF_INT64_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_INT128
#	define Z_IF_INT128_IS_AVAILABLE(what) what
#	define Z_IF_INT128_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_INT128_IS_AVAILABLE(what)
#	define Z_IF_INT128_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT16
#	define Z_IF_FLOAT16_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT16_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT16_IS_AVAILABLE(what)
#	define Z_IF_FLOAT16_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT24
#	define Z_IF_FLOAT24_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT24_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT24_IS_AVAILABLE(what)
#	define Z_IF_FLOAT24_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT32
#	define Z_IF_FLOAT32_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT32_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT32_IS_AVAILABLE(what)
#	define Z_IF_FLOAT32_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT48
#	define Z_IF_FLOAT48_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT48_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT48_IS_AVAILABLE(what)
#	define Z_IF_FLOAT48_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT64
#	define Z_IF_FLOAT64_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT64_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT64_IS_AVAILABLE(what)
#	define Z_IF_FLOAT64_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT72
#	define Z_IF_FLOAT72_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT72_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT72_IS_AVAILABLE(what)
#	define Z_IF_FLOAT72_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT80
#	define Z_IF_FLOAT80_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT80_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT80_IS_AVAILABLE(what)
#	define Z_IF_FLOAT80_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT96
#	define Z_IF_FLOAT96_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT96_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT96_IS_AVAILABLE(what)
#	define Z_IF_FLOAT96_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT128
#	define Z_IF_FLOAT128_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT128_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT128_IS_AVAILABLE(what)
#	define Z_IF_FLOAT128_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#endif /* __Z_macros_filtering_H__ */
