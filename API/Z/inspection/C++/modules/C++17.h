/* Z Kit - inspection/C++/modules/C++17.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_CPP_modules_CPP17_H_
#define _Z_inspection_CPP_modules_CPP17_H_

#include <Z/inspection/C++/modules/C++14.h>

#define Z_CPP_HAS_FOLD_EXPRESSION			  TRUE /* N4295	  */

#define Z_CPP_HAS_ATTRIBUTE_USING_PREFIX		  TRUE /* P0028R4 */
#define Z_CPP_HAS_CONSTANT_EXPRESSION_IF		  TRUE /* P0292R2 */
#define Z_CPP_HAS_CONSTANT_EXPRESSION_LAMBDA		  TRUE /* P0170R1 */
#define Z_CPP_HAS_CPP17_RULES_ON_BRACED_INITIALIZATION	  TRUE /* N3922	  */
#define Z_CPP_HAS_ENUMERATION_ATTRIBUTES		  TRUE /* N4266	  */
#define Z_CPP_HAS_IF_WITH_INITIALIZER			  TRUE /* P0305R1 */
#define Z_CPP_HAS_INLINE_VARIABLE			  TRUE /* P0386R2 */
#define Z_CPP_HAS_NAMESPACE_ATTRIBUTES			  TRUE /* N4266	  */
#define Z_CPP_HAS_NESTED_NAMESPACE_DEFINITION		  TRUE /* N4230	  */
#define Z_CPP_HAS_REMOVAL_OF_TRIGRAPHS			  TRUE /* N4086	  */
#define Z_CPP_HAS_STATIC_ASSERTION_WITH_NO_MESSAGE	  TRUE /* N3928	  */
#define Z_CPP_HAS_SWITCH_WITH_INITIALIZER		  TRUE /* P0305R1 */
#define Z_CPP_HAS_TYPENAME_IN_TEMPLATE_TEMPLATE_PARAMETER TRUE /* N4051	  */
#define Z_CPP_HAS_VARIADIC_USING			  TRUE /* P0195R2 */
#define Z_CPP_HAS_ATTRIBUTE_FALL_THROUGH		  TRUE /* P0188R1 [[fallthrough]]  */
#define Z_CPP_HAS_ATTRIBUTE_MAYBE_UNUSED		  TRUE /* P0212R1 [[maybe_unused]] */
#define Z_CPP_HAS_ATTRIBUTE_NO_DISCARD			  TRUE /* P0189R1 [[nodiscard]]    */
#define Z_CPP_HAS_LITERAL_HEXADECIMAL_FLOATING_POINT	  TRUE /* P0245R1 */
#define Z_CPP_HAS_LITERAL_UTF8_CHARACTER		  TRUE /* N4267	  */
#define Z_CPP_HAS_PREPROCESSOR_OPERATOR_HAS_INCLUDE	  TRUE /* P0061R1 */

#endif /* _Z_inspection_CPP_modules_CPP17_H_ */
