/* Z Kit - inspection/C++/modules/C++14.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_CPP_modules_CPP14_H__
#define __Z_inspection_CPP_modules_CPP14_H__

#include <Z/inspection/C++/modules/C++11.h>

#define Z_CPP_HAS_GENERIC_LAMBDA			    TRUE /* N3649 */
#define Z_CPP_HAS_RELAXED_CONSTANT_EXPRESSION_FUNCTION	    TRUE /* N3652 */
#define Z_CPP_HAS_RETURN_TYPE_DEDUCTION_FOR_NORMAL_FUNCTION TRUE /* N3638 */
#define Z_CPP_HAS_SIZED_DEALLOCATION			    TRUE /* N3778 */
#define Z_CPP_HAS_VARIABLE_TEMPLATE			    TRUE /* N3651 */
#define Z_CPP_HAS_ATTRIBUTE_DEPRECATED			    TRUE /* N3760: [[deprecated]] */
#define Z_CPP_HAS_LITERAL_BINARY			    TRUE /* N3472 */

#endif /* __Z_inspection_CPP_modules_CPP14_H__ */
