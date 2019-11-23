/* Z Kit - inspection/C++/modules/C++20.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_CPP_modules_CPP20_H
#define Z_inspection_CPP_modules_CPP20_H

#include <Z/inspection/C++/modules/C++17.h>

#define Z_CPP_HAS_CONCEPT					  TRUE /* P0734R0							 */
#define Z_CPP_HAS_CONST_LVALUE_MEMBER_FUNCTION_POINTER_FOR_RVALUE TRUE /* P0704R1							 */
#define Z_CPP_HAS_const mismatch with defaulted copy constructor  TRUE /* P0641R2							 */
#define Z_CPP_HAS_CONSTEXPR_VIRTUAL_FUNCTION			  TRUE /* P1064R0							 */
#define Z_CPP_HAS_CONVERSION_TO_UNSIZED_ARRAY			  TRUE /* P0388R4							 */
#define Z_CPP_HAS_CPP20_STRUCTURED_BINDING			  TRUE /* P1091R3
									  P1381R1							 */
#define Z_CPP_HAS_DEDUCTION_GUIDES_FOR_AGGREGATE		  TRUE /* P1816R0  __cpp_deduction_guides		  >= 201907L (+) */
#define Z_CPP_HAS_DEDUCTION_GUIDES_FOR_CLASS_ALIAS_TEMPLATE	  TRUE /* P1814R0  __cpp_deduction_guides		  >= 201907L (+) */
#define Z_CPP_HAS_DEFAULT_MEMBER_INITIALIZER_FOR_BIT_FIELD	  TRUE /* P0683R1							 */
#define Z_CPP_HAS_DESIGNATED_INITIALIZATION			  TRUE /* P0329R4							 */
#define Z_CPP_HAS_DESTROYING_DELETE				  TRUE /* P0722R3  __cpp_impl_destroying_delete		  >= 201806L (!) */
#define Z_CPP_HAS_EXPLICIT_LAMBDA_CAPTURE_OF_THIS_BY_VALUE	  TRUE /* P0409R2							 */
#define Z_CPP_HAS_LAMBDA_IN_UNEVALUATED_CONTEXT			  TRUE /* P0315R4							 */
#define Z_CPP_HAS_NESTED_INLINE_NAMESPACE_DEFINITION		  TRUE /* P1094R2							 */
#define Z_CPP_HAS_NO_ACCESS_CHECKING_ON_SPECIALIZATIONS		  TRUE /* P0692R1							 */
#define Z_CPP_HAS_OPTIONAL_TYPENAME				  TRUE /* P0634R3							 */
#define Z_CPP_HAS_PARAMETER_PACK_EXPANSION_IN_LAMBDA_CAPTURE	  TRUE /* P0780R2							 */
#define Z_CPP_HAS_PARENTHESIZED_LIST_INITIALIZATION_FOR_AGGREGATE TRUE /* P0960R3  __cpp_aggregate_paren_init		  >= 201902L (!) */
#define Z_CPP_HAS_PREPROCESSOR_IDENTIFIER_VA_OPT		  TRUE /* P0306R4
									  P1042R1							 */
#define Z_CPP_HAS_RANGE_BASED_FOR_WITH_INITIALIZER		  TRUE /* P0614R1							 */
#define Z_CPP_HAS_SAFE_OPERATOR_LESS_THAN_WITH_FUNCTION_ON_LHS	  TRUE /* P0846R0							 */
#define Z_CPP_HAS_STRUCTURE_AS_TEMPLATE_PARAMETER		  TRUE /* P0732R2  __cpp_nontype_template_parameter_class >= 201806L (!) */
#define Z_CPP_HAS_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDA	  TRUE /* P0428R2							 */
#define Z_CPP_HAS_USING_ENUM					  TRUE /* P1099R5  __cpp_using_enum			  >= 201907L (!) */
#define Z_CPP_HAS_ATTRIBUTE_LIKELY				  TRUE /* P0479R5  __has_cpp_attribute(likely)		  >= 201803L (!) */
#define Z_CPP_HAS_ATTRIBUTE_NO_UNIQUE_ADDRESS			  TRUE /* P0840R2  __has_cpp_attribute(no_unique_address) >= 201803L (!) */
#define Z_CPP_HAS_ATTRIBUTE_UNLIKELY				  TRUE /* P0479R5  __has_cpp_attribute(unlikely)	  >= 201803L (!) */
#define Z_CPP_HAS_OPERATOR_3_WAY_COMPARISON			  TRUE /* P0515R3  __cpp_impl_three_way_comparison	  >= 201711L (!)
									  P1185R2  __cpp_impl_three_way_comparison	  >= 201907L (+)
									  P1186R3  __cpp_impl_three_way_comparison	  >= 201907L (+)
									  P1630R1  __cpp_impl_three_way_comparison	  >= 201907L (+) */
#define Z_CPP_HAS_SPECIFIER_CONDITIONAL_EXPLICIT		  TRUE /* P0892R2  __cpp_conditional_explicit		  >= 201806L (!) */
#define Z_CPP_HAS_SPECIFIER_CONSTEVAL				  TRUE /* P1073R3							 */
#define Z_CPP_HAS_SPECIFIER_CONSTINIT				  TRUE /* P1143R2  __cpp_constinit			  >= 201907L (!) */
#define Z_CPP_HAS_TYPE_CHAR8_T					  TRUE /* P0482R6  __cpp_char8_t			  >= 201811L (!) */

#define Z_CPP_HAS_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDA TRUE /* P0624R2 */


#endif /* Z_inspection_CPP_modules_CPP20_H */
