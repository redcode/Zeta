/* Zeta API - Z/inspection/platform.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_platform_H
#define Z_inspection_platform_H

#include <Z/keys/platform.h>

#ifndef Z_PLATFORM
#	include <Z/inspection/compiler.h>

#	ifdef Z_COMPILER_PLATFORM
#		define Z_PLATFORM Z_COMPILER_PLATFORM
#	else
#		include <Z/inspection/platform/detection.h>
#	endif
#endif

#ifndef Z_PLATFORM
#	define Z_PLATFORM Z_PLATFORM_UNKNOWN
#endif

#define Z_PLATFORM_IS(PLATFORM) (Z_PLATFORM == Z_PLATFORM_##PLATFORM)

#endif /* Z_inspection_platform_H */
