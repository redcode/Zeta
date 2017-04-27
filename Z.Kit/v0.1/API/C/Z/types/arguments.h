/* Z Kit C API - types/arguments.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_arguments_H__
#define __Z_types_arguments_H__

#include <Z/inspection/compiler.h>

#if Z_COMPILER_HAS_TYPE(VAL)
	typedef Z_COMPILER_TYPE(VAL) ZVAL;
#else
	typedef void* ZVAL;
#endif

#endif /* __Z_types_arguments_H__ */
