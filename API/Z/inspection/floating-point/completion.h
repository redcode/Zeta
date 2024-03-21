/* Zeta API - Z/inspection/floating-point/completion.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_floating_point_completion_H
#define Z_inspection_floating_point_completion_H

#ifdef Z_FLOATING_POINT_TYPE_BFP16
#	define Z_FLOATING_POINT_HAS_TYPE_BFP16 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_BFP32
#	define Z_FLOATING_POINT_HAS_TYPE_BFP32 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_BFP64
#	define Z_FLOATING_POINT_HAS_TYPE_BFP64 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_BFP128
#	define Z_FLOATING_POINT_HAS_TYPE_BFP128 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_DFP32
#	define Z_FLOATING_POINT_HAS_TYPE_DFP32 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_DFP64
#	define Z_FLOATING_POINT_HAS_TYPE_DFP64 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_DFP128
#	define Z_FLOATING_POINT_HAS_TYPE_DFP128 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_X87_DE80
#	define Z_FLOATING_POINT_HAS_TYPE_X87_DE80 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_X87_DE96
#	define Z_FLOATING_POINT_HAS_TYPE_X87_DE96 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_X87_DE128
#	define Z_FLOATING_POINT_HAS_TYPE_X87_DE128 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_IBM_ED
#	define Z_FLOATING_POINT_HAS_TYPE_IBM_ED 1
#endif

#ifdef Z_FLOATING_POINT_TYPE_BFLOAT16
#	define Z_FLOATING_POINT_HAS_TYPE_BFLOAT16 1
#endif

#endif /* Z_inspection_floating_point_completion_H */
