/* Z Kit - inspection/floating-point/completion.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifdef Z_FLOATING_POINT_TYPE_FLOAT16
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT16 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT16 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT32
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT32 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT32 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT64
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT64 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT64 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT128
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT128 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT128 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT80_X87
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT80_X87 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT80_X87 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT96_X87
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT96_X87 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT96_X87 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT128_X87
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT128_X87 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT128_X87 FALSE
#endif

/* inspection/floating-point/completion.h EOF */
