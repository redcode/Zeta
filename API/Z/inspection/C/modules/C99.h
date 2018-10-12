/* Z Kit - inspection/C/modules/C99.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_C_modules_C99_H_
#define _Z_inspection_C_modules_C99_H_

#include <Z/inspection/C/modules/C94.h>

#define Z_C_HAS_COMPOUND_LITERAL				 TRUE
#define Z_C_HAS_CPP_STYLE_COMMENT				 TRUE
#define Z_C_HAS_DESIGNATED_INITIALIZER				 TRUE
#define Z_C_HAS_FLEXIBLE_ARRAY_MEMBER				 TRUE
#define Z_C_HAS_INLINE_FUNCION					 TRUE
#define Z_C_HAS_MIXED_DECLARATIONS_AND_CODE			 TRUE
#define Z_C_HAS_NON_CONSTANT_AGGREGATE_INITIALIZER		 TRUE
#define Z_C_HAS_PREPROCESSOR_ARITHMETIC_DONE_IN_MAXIMUM_INTEGRAL TRUE
#define Z_C_HAS_VARIADIC_MACRO					 TRUE
#define Z_C_HAS_VLA						 TRUE
#define Z_C_HAS_MAGIC_CONSTANT_FUNCTION_NAME			 TRUE /* __func__			   */
#define Z_C_HAS_SPECIFIER_INLINE				 TRUE /* inline				   */
#define Z_C_HAS_TYPE_BOOLEAN					 TRUE /* _Bool				   */
#define Z_C_HAS_TYPE_LLONG					 TRUE /* [unsigned|signed] long long [int] */
#define Z_C_HAS_TYPE_QUALIFIER_RESTRICT				 TRUE /* restrict			   */

#endif /* _Z_inspection_C_modules_C99_H_ */
