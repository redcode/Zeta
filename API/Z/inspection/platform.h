/* Z Kit - inspection/platform.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_platform_H
#define Z_inspection_platform_H

#include <Z/keys/platform.h>

#ifdef Z_PLATFORM
#	include <Z/constants/base.h>
#else
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

#endif /* Z_inspection_platform_H */
