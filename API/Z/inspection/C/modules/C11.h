/* Z Kit - inspection/C/modules/C11.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_C_modules_C11_H_
#define _Z_inspection_C_modules_C11_H_

#include <Z/inspection/C/modules/C99.h>

#define Z_C_HAS_ANONYMOUS_STRUCTURE TRUE
#define Z_C_HAS_ANONYMOUS_UNION	    TRUE

#ifndef __STDC_NO_ATOMICS__
#	define Z_C_HAS_ATOMIC_OPERATIONS TRUE
#endif

#define Z_C_HAS_GENERIC_SELECTION TRUE /* _Generic()	   */
#define Z_C_HAS_STATIC_ASSERTION  TRUE /* _Static_assert() */

#ifdef __STDC_NO_VLA__
#	undef Z_C_HAS_VLA
#endif

#define Z_C_HAS_OPERATOR_ALIGN_OF TRUE /* _Alignof() */

#ifndef __STDC_NO_ATOMICS__
#	define Z_C_HAS_SPECIFIER_ATOMIC TRUE /* _Atomic() */
#endif

#define Z_C_HAS_SPECIFIER_ALIGN_AS	   TRUE /* _Alignas()	 */
#define Z_C_HAS_SPECIFIER_NO_RETURN	   TRUE /* _Noreturn	 */
#define Z_C_HAS_STORATE_CLASS_THREAD_LOCAL TRUE /* _Thread_local */

#ifndef __STDC_NO_ATOMICS__
#	define Z_C_HAS_TYPE_QUALIFIER_ATOMIC TRUE /* _Atomic */
#endif

#endif /* _Z_inspection_C_modules_C11_H_ */
