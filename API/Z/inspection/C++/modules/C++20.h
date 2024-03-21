/* Zeta API - Z/inspection/C++/modules/C++20.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_CPP_modules_CPP20_H
#define Z_inspection_CPP_modules_CPP20_H

#include <Z/inspection/C++/modules/C++17.h>					     /* Paper	 Test macro					       */
										     /* -------	 ----------------------------------------------------- */
#define Z_LANGUAGE_HAS_CPP20_CONCEPT						   1 /* P0734R0							       */
#define Z_LANGUAGE_HAS_CPP20_CONST_LVALUE_MEMBER_FUNCTION_POINTER_FOR_RVALUE	   1 /* P0704R1							       */
//#define Z_LANGUAGE_HAS_CPP20_const mismatch with defaulted copy constructor	   1 /* P0641R2							       */
#define Z_LANGUAGE_HAS_CPP20_CONSTEXPR_VIRTUAL_FUNCTION				   1 /* P1064R0							       */
#define Z_LANGUAGE_HAS_CPP20_CONVERSION_TO_UNSIZED_ARRAY			   1 /* P0388R4							       */
#define Z_LANGUAGE_HAS_CPP20_STRUCTURED_BINDING					   1 /* P1091R3
											P1381R1							       */
#define Z_LANGUAGE_HAS_CPP20_DEDUCTION_GUIDES_FOR_AGGREGATE			   1 /* P1816R0	 __cpp_deduction_guides			>= 201907L (+) */
#define Z_LANGUAGE_HAS_CPP20_DEDUCTION_GUIDES_FOR_CLASS_ALIAS_TEMPLATE		   1 /* P1814R0	 __cpp_deduction_guides			>= 201907L (+) */
#define Z_LANGUAGE_HAS_CPP20_DEFAULT_CONSTRUCTIBLE_AND_ASSIGNABLE_STATELESS_LAMBDA 1 /* P0624R2							       */
#define Z_LANGUAGE_HAS_CPP20_DEFAULT_MEMBER_INITIALIZER_FOR_BIT_FIELD		   1 /* P0683R1							       */
#define Z_LANGUAGE_HAS_CPP20_DESIGNATED_INITIALIZATION				   1 /* P0329R4							       */
#define Z_LANGUAGE_HAS_CPP20_DESTROYING_DELETE					   1 /* P0722R3	 __cpp_impl_destroying_delete		>= 201806L (!) */
#define Z_LANGUAGE_HAS_CPP20_EXPLICIT_LAMBDA_CAPTURE_OF_THIS_BY_VALUE		   1 /* P0409R2							       */
#define Z_LANGUAGE_HAS_CPP20_LAMBDA_IN_UNEVALUATED_CONTEXT			   1 /* P0315R4							       */
#define Z_LANGUAGE_HAS_CPP20_NESTED_INLINE_NAMESPACE_DEFINITION			   1 /* P1094R2							       */
#define Z_LANGUAGE_HAS_CPP20_NO_ACCESS_CHECKING_ON_SPECIALIZATIONS		   1 /* P0692R1							       */
#define Z_LANGUAGE_HAS_CPP20_OPTIONAL_TYPENAME					   1 /* P0634R3							       */
#define Z_LANGUAGE_HAS_CPP20_PARAMETER_PACK_EXPANSION_IN_LAMBDA_CAPTURE		   1 /* P0780R2							       */
#define Z_LANGUAGE_HAS_CPP20_PARENTHESIZED_LIST_INITIALIZATION_FOR_AGGREGATE	   1 /* P0960R3	 __cpp_aggregate_paren_init		>= 201902L (!) */
#define Z_LANGUAGE_HAS_CPP20_PREPROCESSOR_IDENTIFIER_VA_OPT			   1 /* P0306R4
											P1042R1							       */
#define Z_LANGUAGE_HAS_CPP20_RANGE_BASED_FOR_WITH_INITIALIZER			   1 /* P0614R1							       */
#define Z_LANGUAGE_HAS_CPP20_SAFE_OPERATOR_LESS_THAN_WITH_FUNCTION_ON_LHS	   1 /* P0846R0							       */
#define Z_LANGUAGE_HAS_CPP20_STRUCTURE_AS_TEMPLATE_PARAMETER			   1 /* P0732R2	 __cpp_nontype_template_parameter_class >= 201806L (!) */
#define Z_LANGUAGE_HAS_CPP20_TEMPLATE_PARAMETER_LIST_FOR_GENERIC_LAMBDA		   1 /* P0428R2							       */
#define Z_LANGUAGE_HAS_CPP20_USING_ENUM						   1 /* P1099R5	 __cpp_using_enum			>= 201907L (!) */
#define Z_LANGUAGE_HAS_CPP20_ATTRIBUTE_LIKELY					   1 /* P0479R5	 __has_cpp_attribute(likely)		>= 201803L (!) */
#define Z_LANGUAGE_HAS_CPP20_ATTRIBUTE_NO_UNIQUE_ADDRESS			   1 /* P0840R2	 __has_cpp_attribute(no_unique_address) >= 201803L (!) */
#define Z_LANGUAGE_HAS_CPP20_ATTRIBUTE_UNLIKELY					   1 /* P0479R5	 __has_cpp_attribute(unlikely)		>= 201803L (!) */
#define Z_LANGUAGE_HAS_CPP20_OPERATOR_3_WAY_COMPARISON				   1 /* P0515R3	 __cpp_impl_three_way_comparison	>= 201711L (!)
											P1185R2	 __cpp_impl_three_way_comparison	>= 201907L (+)
											P1186R3	 __cpp_impl_three_way_comparison	>= 201907L (+)
											P1630R1	 __cpp_impl_three_way_comparison	>= 201907L (+) */
#define Z_LANGUAGE_HAS_CPP20_SPECIFIER_CONDITIONAL_EXPLICIT			   1 /* P0892R2	 __cpp_conditional_explicit		>= 201806L (!) */
#define Z_LANGUAGE_HAS_CPP20_SPECIFIER_CONSTEVAL				   1 /* P1073R3							       */
#define Z_LANGUAGE_HAS_CPP20_SPECIFIER_CONSTINIT				   1 /* P1143R2	 __cpp_constinit			>= 201907L (!) */
#define Z_LANGUAGE_HAS_CPP20_TYPE_CHAR8_T					   1 /* P0482R6	 __cpp_char8_t				>= 201811L (!) */

#endif /* Z_inspection_CPP_modules_CPP20_H */
