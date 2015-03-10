/* Q Kit C API - private/C/C11.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_private_C_H__
#define __Q_private_C_H__

#include <Q/keys/C.h>

/* MARK: - Identification */

#define Q_C	   Q_C11
#define Q_C_STRING Q_C_STRING_C11

/* MARK: - Features */

#define Q_C_HAS_ANONYMOUS_UNION
#define Q_C_HAS_ANONYMOUS_STRUCTURE

#ifndef __STDC_NO_ATOMICS__
#	define Q_C_HAS_ATOMIC_OPERATIONS
#endif

#define Q_C_HAS_COMPOUND_LITERAL
#define Q_C_HAS_CPP_STYLE_COMMENT
#define Q_C_HAS_DESIGNATED_INITIALIZER
#define Q_C_HAS_DIGRAPH
#define Q_C_HAS_ENUMERATION
#define Q_C_HAS_FLEXIBLE_ARRAY_MEMBER
#define Q_C_HAS_GENERIC_SELECTION
#define Q_C_HAS_INLINE_FUNCION
#define Q_C_HAS_INTERMINGLED_DECLARATIONS_AND_CODE
#define Q_C_HAS_STATIC_ASSERTION
#define Q_C_HAS_VARIADIC_MACRO

#ifndef __STDC_NO_VLA__
#	define Q_C_HAS_VLA
#endif

/* MARK: - Types */

#define Q_C_HAS_TYPE_LLONG
#define Q_C_HAS_TYPE_LDOUBLE

/* MARK: - Type qualifiers */

#define Q_C_HAS_TYPE_QUALIFIER_CONSTANT
#define Q_C_HAS_TYPE_QUALIFIER_VOLATILE
#define Q_C_HAS_TYPE_QUALIFIER_RESTRICT

#ifndef __STDC_NO_ATOMICS__
#	define Q_C_HAS_TYPE_QUALIFIER_ATOMIC
#endif

/* MARK: - Storage classes */

#define Q_C_HAS_STORAGE_CLASS_AUTO
#define Q_C_HAS_STORAGE_CLASS_REGISTER
#define Q_C_HAS_STORAGE_CLASS_STATIC
#define Q_C_HAS_STORAGE_CLASS_EXTERN
#define Q_C_HAS_STORATE_CLASS_THREAD_LOCAL

/* MARK: - Specifiers */

#define Q_C_HAS_SPECIFIER_ALIGN_AS
#define Q_C_HAS_SPECIFIER_NO_RETURN

/* MARK: - Operators */

#define Q_C_HAS_OPERATOR_SIZE_OF
#define Q_C_HAS_OPERATOR_ALIGN_OF

#endif /* __Q_private_C_H__ */
