/* Z Kit C API - private/C/C99.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_private_C_C99_H__
#define __Z_private_C_C99_H__

/* MARK: - Identification */

#ifndef Z_C
#	include <Z/keys/C.h>

#	define Z_C Z_C99
#	define Z_C_STRING Z_C_STRING_C99
#endif

/* MARK: - Inherited */

#include <Z/inspection/private/C/C94.h>

/* MARK: - Features */

#define Z_C_HAS_COMPOUND_LITERAL
#define Z_C_HAS_CPP_STYLE_COMMENT
#define Z_C_HAS_DESIGNATED_INITIALIZER
#define Z_C_HAS_FLEXIBLE_ARRAY_MEMBER
#define Z_C_HAS_INLINE_FUNCION
#define Z_C_HAS_INTERMINGLED_DECLARATIONS_AND_CODE
#define Z_C_HAS_VARIADIC_MACRO
#define Z_C_HAS_VLA

/* MARK: - Types */

#define Z_C_HAS_TYPE_LLONG

/* MARK: - Type qualifiers */

#define Z_C_HAS_TYPE_QUALIFIER_RESTRICT

/* MARK: - Specifiers */

#define Z_C_HAS_SPECIFIER_INLINE

#endif /* __Z_private_C_C99_H__ */
