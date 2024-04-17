/* Zeta API - Z/macros/structure.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_structure_H
#define Z_macros_structure_H

#include <Z/inspection/compiler.h>

#if Z_COMPILER_HAS_MACRO(MEMBER_OFFSET)
#	define Z_MEMBER_OFFSET Z_COMPILER_MACRO(MEMBER_OFFSET)

#else
#	include <Z/types/integral.h>

#	ifdef __cplusplus
#		include <Z/constants/pointer.h>

#		define Z_MEMBER_OFFSET(type, member) \
			zusize(zuintptr(&(static_cast<type *>(Z_NULL))->member))

#	else
#		define Z_MEMBER_OFFSET(type, member) \
			((zusize)(zuintptr)&((type *)(0))->member)
#	endif
#endif

#endif /* Z_macros_structure_H */
