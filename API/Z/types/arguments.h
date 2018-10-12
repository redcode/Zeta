/* Z Kit - types/arguments.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_types_arguments_H_
#define _Z_types_arguments_H_

#include <Z/inspection/compiler.h>

#if Z_COMPILER_HAS_TYPE(VAL)
	typedef Z_COMPILER_TYPE(VAL) ZVAL;
#else
	typedef void* ZVAL;
#endif

#endif /* _Z_types_arguments_H_ */
