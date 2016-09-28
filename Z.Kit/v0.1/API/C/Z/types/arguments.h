/* Z Kit C API - types/arguments.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_arguments_H__
#define __Z_types_arguments_H__

#include <Z/inspection/compiler.h>

#if Z_COMPILER_HAS(VAL)
	typedef Z_COMPILER_TYPE(VAL) ZVAL;
#else
	typedef void* ZVAL;
#endif

#endif /* __Z_types_arguments_H__ */
