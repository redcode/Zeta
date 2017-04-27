/* Z Kit C API - inspection/C/modules/C99.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_C_modules_C99_H__
#define __Z_inspection_C_modules_C99_H__

/* MARK: - Inherited */

#include <Z/inspection/C/modules/C94.h>

/* MARK: - Features */

#define Z_C_HAS_COMPOUND_LITERAL				TRUE
#define Z_C_HAS_CPP_STYLE_COMMENT				TRUE
#define Z_C_HAS_DESIGNATED_INITIALIZER				TRUE
#define Z_C_HAS_FLEXIBLE_ARRAY_MEMBER				TRUE
#define Z_C_HAS_INLINE_FUNCION					TRUE
#define Z_C_HAS_MIXED_DECLARATIONS_AND_CODE			TRUE
#define Z_C_HAS_PREPROCESSOR ARITHMETIC_DONE_IN_MAXIMUM_INTEGER TRUE
#define Z_C_HAS_VARIADIC_MACRO					TRUE
#define Z_C_HAS_VLA						TRUE

/* MARK: - Types */

#define Z_C_HAS_TYPE_BOOLEAN TRUE /* _Bool		     */
#define Z_C_HAS_TYPE_ULLONG  TRUE /* unsigned long long [int] */
#define Z_C_HAS_TYPE_LLONG   TRUE /* [signed] long long [int] */

/* MARK: - Type qualifiers */

#define Z_C_HAS_TYPE_QUALIFIER_RESTRICT TRUE /* restrict */

/* MARK: - Specifiers */

#define Z_C_HAS_SPECIFIER_INLINE TRUE /* inline */

#endif /* __Z_inspection_C_modules_C99_H__ */
