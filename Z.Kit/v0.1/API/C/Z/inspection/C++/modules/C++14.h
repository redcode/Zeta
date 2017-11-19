/* Z Kit C API - inspection/C++/modules/C++14.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_CPP_modules_CPP14_H__
#define __Z_inspection_CPP_modules_CPP14_H__

/* MARK: - Inherited */

#include <Z/inspection/C++/modules/C++11.h>

/* MARK: - Features */

#define Z_CPP_HAS_RELAXED_CONSTANT_EXPRESSION_FUNCTION	    TRUE /* N3652 */
#define Z_CPP_HAS_RETURN_TYPE_DEDUCTION_FOR_NORMAL_FUNCTION TRUE /* N3638 */
#define Z_CPP_HAS_VARIABLE_TEMPLATE			    TRUE /* N3651 */

/* MARK: - Attributes */

#define Z_CPP_HAS_ATTRIBUTE_DEPRECATED TRUE /* N3760: [[deprecated]] */

/* MARK: - Literals */

#define Z_CPP_HAS_LITERAL_BINARY TRUE /* N3472 */

#endif /* __Z_inspection_CPP_modules_CPP14_H__ */
