/* Z Kit - inspection/floating-point/completion.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_floating_point_completion_H
#define Z_inspection_floating_point_completion_H

#ifdef Z_FLOATING_POINT_TYPE_BFP16
#	define Z_FLOATING_POINT_HAS_TYPE_BFP16 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_BFP16 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_BFP32
#	define Z_FLOATING_POINT_HAS_TYPE_BFP32 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_BFP32 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_BFP64
#	define Z_FLOATING_POINT_HAS_TYPE_BFP64 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_BFP64 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_BFP128
#	define Z_FLOATING_POINT_HAS_TYPE_BFP128 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_BFP128 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_DFP32
#	define Z_FLOATING_POINT_HAS_TYPE_DFP32 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_DFP32 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_DFP64
#	define Z_FLOATING_POINT_HAS_TYPE_DFP64 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_DFP64 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_DFP128
#	define Z_FLOATING_POINT_HAS_TYPE_DFP128 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_DFP128 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_X87_DE80
#	define Z_FLOATING_POINT_HAS_TYPE_X87_DE80 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_X87_DE80 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_X87_DE96
#	define Z_FLOATING_POINT_HAS_TYPE_X87_DE96 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_X87_DE96 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_X87_DE128
#	define Z_FLOATING_POINT_HAS_TYPE_X87_DE128 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_X87_DE128 FALSE
#endif

#endif /* Z_inspection_floating_point_completion_H */
