/* Z Kit - macros/arguments.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_arguments_H__
#define __Z_macros_arguments_H__

#include <Z/types/arguments.h>

#if Z_COMPILER_HAS(VAL)

#	define Z_VAL_INITIALIZE	Z_COMPILER_MACRO(VAL_INITIALIZE)
#	define Z_VAL_FINALIZE	Z_COMPILER_MACRO(VAL_FINALIZE  )
#	define Z_VAL_READ	Z_COMPILER_MACRO(VAL_READ      )

#	if Z_COMPILER_HAS_MACRO(VAL_COPY)
#		define Z_VAL_COPY Z_COMPILER_MACRO(VAL_COPY)
#	endif

#endif

#endif /* __Z_macros_arguments_H__ */
