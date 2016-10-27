/* Z Kit C API - macros/filtering.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_filtering_H__
#define __Z_macros_filtering_H__

#include <Z/types/base.h>

#ifdef Z_UINT64
#	define Z_IF_THERE_IS_UINT64(what) what
#	define Z_IF_THERE_IS_UINT64_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_UINT64(what)
#	define Z_IF_THERE_IS_UINT64_ELSE(what, else_what) else_what
#endif

#ifdef Z_UINT128
#	define Z_IF_THERE_IS_UINT128(what) what
#	define Z_IF_THERE_IS_UINT128_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_UINT128(what)
#	define Z_IF_THERE_IS_UINT128_ELSE(what, else_what) else_what
#endif

#ifdef Z_INT64
#	define Z_IF_THERE_IS_INT64(what) what
#	define Z_IF_THERE_IS_INT64_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_INT64(what)
#	define Z_IF_THERE_IS_INT64_ELSE(what, else_what) else_what
#endif

#ifdef Z_INT128
#	define Z_IF_THERE_IS_INT128(what) what
#	define Z_IF_THERE_IS_INT128_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_INT128(what)
#	define Z_IF_THERE_IS_INT128_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT16
#	define Z_IF_THERE_IS_FLOAT16(what) what
#	define Z_IF_THERE_IS_FLOAT16_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_FLOAT16(what)
#	define Z_IF_THERE_IS_FLOAT16_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT24
#	define Z_IF_THERE_IS_FLOAT24(what) what
#	define Z_IF_THERE_IS_FLOAT24_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_FLOAT24(what)
#	define Z_IF_THERE_IS_FLOAT24_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT32
#	define Z_IF_THERE_IS_FLOAT32(what) what
#	define Z_IF_THERE_IS_FLOAT32_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_FLOAT32(what)
#	define Z_IF_THERE_IS_FLOAT32_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT48
#	define Z_IF_THERE_IS_FLOAT48(what) what
#	define Z_IF_THERE_IS_FLOAT48_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_FLOAT48(what)
#	define Z_IF_THERE_IS_FLOAT48_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT64
#	define Z_IF_THERE_IS_FLOAT64(what) what
#	define Z_IF_THERE_IS_FLOAT64_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_FLOAT64(what)
#	define Z_IF_THERE_IS_FLOAT64_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT72
#	define Z_IF_THERE_IS_FLOAT72(what) what
#	define Z_IF_THERE_IS_FLOAT72_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_FLOAT72(what)
#	define Z_IF_THERE_IS_FLOAT72_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT80
#	define Z_IF_THERE_IS_FLOAT80(what) what
#	define Z_IF_THERE_IS_FLOAT80_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_FLOAT80(what)
#	define Z_IF_THERE_IS_FLOAT80_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT96
#	define Z_IF_THERE_IS_FLOAT96(what) what
#	define Z_IF_THERE_IS_FLOAT96_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_FLOAT96(what)
#	define Z_IF_THERE_IS_FLOAT96_ELSE(what, else_what) else_what
#endif

#ifdef Z_FLOAT128
#	define Z_IF_THERE_IS_FLOAT128(what) what
#	define Z_IF_THERE_IS_FLOAT128_ELSE(what, else_what) what
#else
#	define Z_IF_THERE_IS_FLOAT128(what)
#	define Z_IF_THERE_IS_FLOAT128_ELSE(what, else_what) else_what
#endif

#if Z_LANGUAGE_HAS(C, FLEXIBLE_ARRAY_MEMBER)
#	define Z_FLEXIBLE_ARRAY_MEMBER(what) what
#else
#	define Z_FLEXIBLE_ARRAY_MEMBER(what)
#endif

#endif /* __Z_macros_filtering_H__ */
