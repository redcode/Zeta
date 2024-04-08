/* Zeta API - Z/constants/pointer.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_constants_pointer_H
#define Z_constants_pointer_H

#ifdef Z_NULL
#	undef Z_NULL
#endif

#ifdef __cplusplus
#	include <Z/inspection/language.h>

#	if Z_DIALECT_HAS_LITERAL(CPP11, NULLPTR)
#		define Z_NULL nullptr
#	else
#		define Z_NULL 0
#	endif

#else
#	define Z_NULL ((void *)0)
#endif

#endif /* Z_constants_pointer_H */
