/* Zeta API - Z/inspection/C++/modules/C++17.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_CPP_modules_CPP17_H
#define Z_inspection_CPP_modules_CPP17_H

#include <Z/inspection/C++/modules/C++14.h>					/* Paper    Test macro					    */
										/* -------  ---------------------------------------------------- */
#define Z_LANGUAGE_HAS_CPP17_AGGREGATE_INITIALIZATION_FOR_DERIVED_CLASS	      1 /* P0017R1  __cpp_aggregate_bases		  >= 201603L (!) */
#define Z_LANGUAGE_HAS_CPP17_ATTRIBUTE_USING_PREFIX			      1 /* P0028R4							 */
#define Z_LANGUAGE_HAS_CPP17_ATTRIBUTES_FOR_ENUMERATOR			      1 /* N4266    __cpp_enumerator_attributes		  >= 201411L (!) */
#define Z_LANGUAGE_HAS_CPP17_ATTRIBUTES_FOR_NAMESPACE			      1 /* N4266    __cpp_namespace_attributes		  >= 201411L (!) */
#define Z_LANGUAGE_HAS_CPP17_AUTO_DEDUCTION_FROM_LIST_INITIALIZATION	      1 /* N3922							 */
#define Z_LANGUAGE_HAS_CPP17_CONSTEXPR_IF				      1 /* P0292R2  __cpp_if_constexpr			  >= 201606L (!) */
#define Z_LANGUAGE_HAS_CPP17_CONSTEXPR_LAMBDA				      1 /* P0170R1  __cpp_constexpr			  >= 201603L (+) */
#define Z_LANGUAGE_HAS_CPP17_DEDUCTION_GUIDES_FOR_CLASS_TEMPLATE	      1 /* P0091R3  __cpp_deduction_guides		  >= 201606L (!)
										   P0512R0  __cpp_deduction_guides		  >= 201611L (+)
										   P0620R0  __cpp_deduction_guides		  >= 201703L (+) */
#define Z_LANGUAGE_HAS_CPP17_DIFFERING_BEGIN_AND_END_TYPES_IN_RANGE_BASED_FOR 1 /* P0184R0  __cpp_range_based_for		  >= 201603L (+) */
#define Z_LANGUAGE_HAS_CPP17_DIRECT_LIST_INITIALIZATION_FOR_FIXED_ENUMERATION 1 /* P0138R2							 */
#define Z_LANGUAGE_HAS_CPP17_EXPRESSION_EVALUATION_ORDER		      1 /* P0145R3
										   P0400R0							 */
#define Z_LANGUAGE_HAS_CPP17_FOLD_EXPRESSION				      1 /* N4295    __cpp_fold_expressions		  >= 201411L (!) */
#define Z_LANGUAGE_HAS_CPP17_GUARANTEED_COPY_ELISION			      1 /* P0135R1  __cpp_guaranteed_copy_elision	  >= 201606L (!) */
#define Z_LANGUAGE_HAS_CPP17_IF_WITH_INITIALIZER			      1 /* P0305R1							 */
#define Z_LANGUAGE_HAS_CPP17_IGNORING_OF_UNKNOWN_ATTRIBUTES		      1 /* P0283R2							 */
#define Z_LANGUAGE_HAS_CPP17_INHERITING_CONSTRUCTORS			      1 /* P0136R1  __cpp_inheriting_constructors	  >= 201511L (+) */
#define Z_LANGUAGE_HAS_CPP17_INLINE_VARIABLE				      1 /* P0386R2  __cpp_inline_variables		  >= 201606L (!) */
#define Z_LANGUAGE_HAS_CPP17_LAMBDA_CAPTURE_OF_STAR_THIS_BY_VALUE	      1 /* P0018R3  __cpp_capture_star_this		  >= 201603L (!) */
#define Z_LANGUAGE_HAS_CPP17_NESTED_NAMESPACE_DEFINITION		      1 /* N4230    __cpp_nested_namespace_definitions	  >= 201411L (?) */
#define Z_LANGUAGE_HAS_CPP17_NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE	      1 /* P0012R1  __cpp_noexcept_function_type	  >= 201510L (!) */
#define Z_LANGUAGE_HAS_CPP17_NON_TYPE_TEMPLATE_ARGUMENTS		      1 /* N4268    __cpp_nontype_template_args		  >= 201411L (!) */
#define Z_LANGUAGE_HAS_CPP17_NON_TYPE_TEMPLATE_PARAMETER_WITH_AUTO_TYPE	      1 /* P0127R2  __cpp_nontype_template_parameter_auto >= 201606L (!)
											    __cpp_template_auto			  >= 201606L (?) */
#define Z_LANGUAGE_HAS_CPP17_OVER_ALIGNED_DYNAMIC_MEMORY_ALLOCATION	      1 /* P0035R4  __cpp_aligned_new			  >= 201606L (!) */
#define Z_LANGUAGE_HAS_CPP17_REMOVAL_OF_BOOL_INCREMENT			      1 /* P0002R1							 */
#define Z_LANGUAGE_HAS_CPP17_REMOVAL_OF_DYNAMIC_EXCEPTION_SPECIFICATION	      1 /* P0003R5							 */
#define Z_LANGUAGE_HAS_CPP17_REMOVAL_OF_REGISTER_AS_STORAGE_CLASS	      1 /* P0001R1							 */
#define Z_LANGUAGE_HAS_CPP17_REMOVAL_OF_TRIGRAPHS			      1 /* N4086							 */
#define Z_LANGUAGE_HAS_CPP17_SAFE_UNARY_FOLD_EXPRESSION			      1 /* P0036R0  __cpp_fold_expressions		  >= 201603L (+) */
#define Z_LANGUAGE_HAS_CPP17_STATIC_ASSERTION_WITH_NO_MESSAGE		      1 /* N3928    __cpp_static_assert			  >= 201411L (+) */
#define Z_LANGUAGE_HAS_CPP17_STRUCTURED_BINDING				      1 /* P0217R3  __cpp_structured_bindings		  >= 201606L (!) */
#define Z_LANGUAGE_HAS_CPP17_SWITCH_WITH_INITIALIZER			      1 /* P0305R1							 */
#define Z_LANGUAGE_HAS_CPP17_TEMPLATE_TEMPLATE_ARGUMENT_MATCHING	      1 /* P0522R0  __cpp_template_template_args	  >= 201611L (!) */
#define Z_LANGUAGE_HAS_CPP17_TYPENAME_IN_TEMPLATE_TEMPLATE_PARAMETER	      1 /* N4051							 */
#define Z_LANGUAGE_HAS_CPP17_VARIADIC_USING				      1 /* P0195R2  __cpp_variadic_using		  >= 201611L (!) */
#define Z_LANGUAGE_HAS_CPP17_ATTRIBUTE_FALLTHROUGH			      1 /* P0188R1  __has_cpp_attribute(fallthrough)	  >= 201603L (!) */
#define Z_LANGUAGE_HAS_CPP17_ATTRIBUTE_MAYBE_UNUSED			      1 /* P0212R1  __has_cpp_attribute(maybe_unused)	  >= 201603L (!) */
#define Z_LANGUAGE_HAS_CPP17_ATTRIBUTE_NODISCARD			      1 /* P0189R1  __has_cpp_attribute(nodiscard)	  >= 201603L (!) */
#define Z_LANGUAGE_HAS_CPP17_LITERAL_HEXADECIMAL_FLOATING_POINT		      1 /* P0245R1  __cpp_hex_float			  >= 201603L (!) */
#define Z_LANGUAGE_HAS_CPP17_LITERAL_UTF8_CHARACTER			      1 /* N4267    __cpp_unicode_characters		  >= 201411L (?) */
#define Z_LANGUAGE_HAS_CPP17_PREPROCESSOR_OPERATOR_HAS_INCLUDE		      1 /* P0061R1  defined(__has_include)				 */

#endif /* Z_inspection_CPP_modules_CPP17_H */
