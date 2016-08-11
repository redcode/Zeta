/* Z Kit C API - macros/filtering.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_filtering_H__
#define __Z_macros_filtering_H__

#include <Z/types/base.h>

#if Z_IS_AVAILABLE(UINT64)
#	define Z_IF_UINT64_IS_AVAILABLE(what) what
#	define Z_IF_UINT64_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_UINT64_IS_AVAILABLE(what)
#	define Z_IF_UINT64_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(UINT128)
#	define Z_IF_UINT128_IS_AVAILABLE(what) what
#	define Z_IF_UINT128_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_UINT128_IS_AVAILABLE(what)
#	define Z_IF_UINT128_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(INT64)
#	define Z_IF_INT64_IS_AVAILABLE(what) what
#	define Z_IF_INT64_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_INT64_IS_AVAILABLE(what)
#	define Z_IF_INT64_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(INT128)
#	define Z_IF_INT128_IS_AVAILABLE(what) what
#	define Z_IF_INT128_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_INT128_IS_AVAILABLE(what)
#	define Z_IF_INT128_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(FLOAT16)
#	define Z_IF_FLOAT16_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT16_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT16_IS_AVAILABLE(what)
#	define Z_IF_FLOAT16_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(FLOAT24)
#	define Z_IF_FLOAT24_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT24_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT24_IS_AVAILABLE(what)
#	define Z_IF_FLOAT24_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(FLOAT32)
#	define Z_IF_FLOAT32_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT32_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT32_IS_AVAILABLE(what)
#	define Z_IF_FLOAT32_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(FLOAT48)
#	define Z_IF_FLOAT48_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT48_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT48_IS_AVAILABLE(what)
#	define Z_IF_FLOAT48_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(FLOAT64)
#	define Z_IF_FLOAT64_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT64_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT64_IS_AVAILABLE(what)
#	define Z_IF_FLOAT64_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(FLOAT72)
#	define Z_IF_FLOAT72_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT72_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT72_IS_AVAILABLE(what)
#	define Z_IF_FLOAT72_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(FLOAT80)
#	define Z_IF_FLOAT80_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT80_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT80_IS_AVAILABLE(what)
#	define Z_IF_FLOAT80_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(FLOAT96)
#	define Z_IF_FLOAT96_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT96_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT96_IS_AVAILABLE(what)
#	define Z_IF_FLOAT96_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#if Z_IS_AVAILABLE(FLOAT128)
#	define Z_IF_FLOAT128_IS_AVAILABLE(what) what
#	define Z_IF_FLOAT128_IS_AVAILABLE_ELSE(what, else_what) what
#else
#	define Z_IF_FLOAT128_IS_AVAILABLE(what)
#	define Z_IF_FLOAT128_IS_AVAILABLE_ELSE(what, else_what) else_what
#endif

#endif /* __Z_macros_filtering_H__ */
