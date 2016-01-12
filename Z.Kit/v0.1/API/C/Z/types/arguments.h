/* Z Kit C API - types/arguments.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_arguments_H__
#define __Z_types_arguments_H__

#include <Z/types/base.h>

#if Z_COMPILER_HAS(VAL)
	typedef Z_COMPILER_TYPE(VAL) ZVAL;
#else
	typedef void* ZVAL;
#endif

#endif /* __Z_types_arguments_H__ */
