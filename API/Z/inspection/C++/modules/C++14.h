/* Z Kit - inspection/C++/modules/C++14.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_CPP_modules_CPP14_H_
#define _Z_inspection_CPP_modules_CPP14_H_

#include <Z/inspection/C++/modules/C++11.h>

#define Z_CPP_HAS_APOSTROPHE_AS_DIGIT_SEPARATOR		      TRUE /* N3781 */
#define Z_CPP_HAS_CPP14_RULES_ON_CONSTANT_EXPRESSION_FUNCTION TRUE /* N3652 */
#define Z_CPP_HAS_CPP14_RULES_ON_CONTEXTUAL_CONVERSION	      TRUE /* N3323 */
#define Z_CPP_HAS_DEFAULT_MEMBER_INITIALIZER_FOR_AGGREGATE    TRUE /* N3653 */
#define Z_CPP_HAS_GENERIC_LAMBDA			      TRUE /* N3649 */
#define Z_CPP_HAS_INITIALIZED_LAMBDA_CAPTURE		      TRUE /* N3648 */
#define Z_CPP_HAS_RETURN_TYPE_DEDUCTION_FOR_NORMAL_FUNCTION   TRUE /* N3638 */
#define Z_CPP_HAS_SIZED_DEALLOCATION			      TRUE /* N3778 */
#define Z_CPP_HAS_VARIABLE_TEMPLATE			      TRUE /* N3651 */
#define Z_CPP_HAS_ATTRIBUTE_DEPRECATED			      TRUE /* N3760: [[deprecated]] */
#define Z_CPP_HAS_LITERAL_BINARY			      TRUE /* N3472: 0[b|B]<number> */
#define Z_CPP_HAS_SPECIFIER_DECLARED_TYPE_OF_AUTO	      TRUE /* N3638: decltype(auto) */

#endif /* _Z_inspection_CPP_modules_CPP14_H_ */
