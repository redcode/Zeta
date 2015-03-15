/* Q Kit C API - private/C/C99.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_private_C_C99_H__
#define __Q_private_C_C99_H__

/* MARK: - Identification */

#ifndef Q_C
#	include <Q/keys/C.h>

#	define Q_C Q_C99
#	define Q_C_STRING Q_C_STRING_C99
#endif

/* MARK: - Inherited */

#include <Q/inspection/private/C/C94.h>

/* MARK: - Features */

#define Q_C_HAS_COMPOUND_LITERAL
#define Q_C_HAS_CPP_STYLE_COMMENT
#define Q_C_HAS_DESIGNATED_INITIALIZER
#define Q_C_HAS_FLEXIBLE_ARRAY_MEMBER
#define Q_C_HAS_INLINE_FUNCION
#define Q_C_HAS_INTERMINGLED_DECLARATIONS_AND_CODE
#define Q_C_HAS_VARIADIC_MACRO
#define Q_C_HAS_VLA

/* MARK: - Types */

#define Q_C_HAS_TYPE_LLONG

/* MARK: - Type qualifiers */

#define Q_C_HAS_TYPE_QUALIFIER_RESTRICT

/* MARK: - Specifiers */

#define Q_C_HAS_SPECIFIER_INLINE

#endif /* __Q_private_C_C99_H__ */
