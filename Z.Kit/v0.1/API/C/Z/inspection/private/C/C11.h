/* Z Kit C API - private/C/C11.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_private_C_C11_H__
#define __Z_private_C_C11_H__

/* MARK: - Identification */

#ifndef Z_C
#	include <Z/keys/C.h>

#	define Z_C Z_C11
#	define Z_C_STRING Z_C_STRING_C11
#endif

/* MARK: - Inherited */

#include <Z/inspection/private/C/C99.h>

/* MARK: - Features */

#define Z_C_HAS_ANONYMOUS_STRUCTURE
#define Z_C_HAS_ANONYMOUS_UNION

#ifndef __STDC_NO_ATOMICS__
#	define Z_C_HAS_ATOMIC_OPERATIONS
#endif

#define Z_C_HAS_GENERIC_SELECTION
#define Z_C_HAS_STATIC_ASSERTION

#ifdef __STDC_NO_VLA__
#	undef Z_C_HAS_VLA
#endif

/* MARK: - Type qualifiers */

#ifndef __STDC_NO_ATOMICS__
#	define Z_C_HAS_TYPE_QUALIFIER_ATOMIC /* _Atomic */
#endif

/* MARK: - Storage classes */

#define Z_C_HAS_STORATE_CLASS_THREAD_LOCAL /* _Thread_local */

/* MARK: - Specifiers */

#ifndef __STDC_NO_ATOMICS__
#	define Z_C_HAS_SPECIFIER_ATOMIC /* _Atomic() */
#endif

#define Z_C_HAS_SPECIFIER_ALIGN_AS  /* _Alignas() */
#define Z_C_HAS_SPECIFIER_NO_RETURN /* _Noreturn  */

/* MARK: - Operators */

#define Z_C_HAS_OPERATOR_ALIGN_OF /* alignof() */

#endif /* __Z_private_C_C11_H__ */
