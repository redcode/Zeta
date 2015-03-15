/* Q Kit C API - private/C/C11.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_private_C_C11_H__
#define __Q_private_C_C11_H__

/* MARK: - Identification */

#ifndef Q_C
#	include <Q/keys/C.h>

#	define Q_C Q_C11
#	define Q_C_STRING Q_C_STRING_C11
#endif

/* MARK: - Inherited */

#include <Q/inspection/private/C/C99.h>

/* MARK: - Features */

#define Q_C_HAS_ANONYMOUS_UNION
#define Q_C_HAS_ANONYMOUS_STRUCTURE

#ifndef __STDC_NO_ATOMICS__
#	define Q_C_HAS_ATOMIC_OPERATIONS
#endif

#define Q_C_HAS_GENERIC_SELECTION
#define Q_C_HAS_STATIC_ASSERTION

#ifdef __STDC_NO_VLA__
#	undef Q_C_HAS_VLA
#endif

/* MARK: - Type qualifiers */

#ifndef __STDC_NO_ATOMICS__
#	define Q_C_HAS_TYPE_QUALIFIER_ATOMIC
#endif

/* MARK: - Storage classes */

#define Q_C_HAS_STORATE_CLASS_THREAD_LOCAL

/* MARK: - Specifiers */

#define Q_C_HAS_SPECIFIER_ALIGN_AS
#define Q_C_HAS_SPECIFIER_NO_RETURN

/* MARK: - Operators */

#define Q_C_HAS_OPERATOR_ALIGN_OF

#endif /* __Q_private_C_C11_H__ */
