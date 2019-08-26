/* Z Kit - inspection/C++/modules/C++17.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_CPP_modules_CPP17_H
#define Z_inspection_CPP_modules_CPP17_H

#include <Z/inspection/C++/modules/C++14.h>

#define Z_CPP_HAS_AGGREGATE_INITIALIZATION_FOR_DERIVED_CLASS	     TRUE /* P0017R1  __cpp_aggregate_bases		    >= 201603L */
#define Z_CPP_HAS_ATTRIBUTES_FOR_ENUMERATION			     TRUE /* N4266    __cpp_enumerator_attributes	    >= 201411L */
#define Z_CPP_HAS_ATTRIBUTES_FOR_NAMESPACE			     TRUE /* N4266    __cpp_namespace_attributes	    >= 201411L */
#define Z_CPP_HAS_ATTRIBUTE_USING_PREFIX			     TRUE /* P0028R4						       */
#define Z_CPP_HAS_CPP17_RULES_ON_AUTO_AND_BRACED_INITIALIZATION	     TRUE /* N3922						       */
#define Z_CPP_HAS_CPP17_RULES_ON_EXPRESSION_EVALUATION_ORDER	     TRUE /* P0145R3
									     P0400R0						       */
#define Z_CPP_HAS_CPP17_RULES_ON_INHERITING_CONSTRUCTORS	     TRUE /* P0136R1  __cpp_inheriting_constructors	    >= 201511L */
#define Z_CPP_HAS_CPP17_RULES_ON_NON_TYPE_TEMPLATE_ARGUMENTS	     TRUE /* N4268    __cpp_nontype_template_args	    >= 201411L */
#define Z_CPP_HAS_CPP17_RULES_ON_TEMPLATE_TEMPLATE_ARGUMENT_MATCHING TRUE /* P0522R0  __cpp_template_template_args	    >= 201611L */
#define Z_CPP_HAS_DIFFERING_BEGIN_AND_END_TYPES_IN_RANGE_BASED_FOR   TRUE /* P0184R0  __cpp_range_based_for		    >= 201603L */
#define Z_CPP_HAS_DIRECT_LIST_INITIALIZATION_FOR_ENUMERATION	     TRUE /* P0138R2						       */
#define Z_CPP_HAS_NOEXCEPT_AS_PART_OF_THE_TYPE			     TRUE /* P0012R1  __cpp_noexcept_function_type	    >= 201510L */
#define Z_CPP_HAS_FOLD_EXPRESSION				     TRUE /* N4295    __cpp_fold_expressions		    >= 201411L */
#define Z_CPP_HAS_FOLD_EXPRESSION_SAFETY_WITH_EMPTY_PARAMETER_PACK   TRUE /* P0036R0  __cpp_fold_expressions		    >= 201603L */
#define Z_CPP_HAS_GUARANTEED_COPY_ELISION			     TRUE /* P0135R1  __cpp_guaranteed_copy_elision	    >= 201606L */
#define Z_CPP_HAS_IF_WITH_INITIALIZER				     TRUE /* P0305R1						       */
#define Z_CPP_HAS_IGNORATION_OF_UNKNOWN_ATTRIBUTES		     TRUE /* P0283R2						       */
#define Z_CPP_HAS_LAMBDA_CAPTURE_OF_THIS_OBJECT_BY_VALUE	     TRUE /* P0018R3  __cpp_capture_star_this		    >= 201603L */
#define Z_CPP_HAS_LAUNDER /* Not a good name */			     TRUE /* P0137R1						       */
#define Z_CPP_HAS_NESTED_NAMESPACE_DEFINITION			     TRUE /* N4230						       */
#define Z_CPP_HAS_NON_TYPE_TEMPLATE_PARAMETER_WITH_AUTO_TYPE	     TRUE /* P0127R2  __cpp_nontype_template_parameter_auto >= 201606L */
#define Z_CPP_HAS_OVER_ALIGNED_DYNAMIC_ALLOCATION		     TRUE /* P0035R4  __cpp_aligned_new			    >= 201606L */
#define Z_CPP_HAS_REMOVAL_OF_DYNAMIC_EXCEPTION_SPECIFICATION	     TRUE /* P0003R5						       */
#define Z_CPP_HAS_REMOVAL_OF_INCREMENT_OPERATOR_WITH_BOOL_OPERAND    TRUE /* P0002R1						       */
#define Z_CPP_HAS_REMOVAL_OF_REGISTER_AS_STORAGE_CLASS		     TRUE /* P0001R1						       */
#define Z_CPP_HAS_REMOVAL_OF_TRIGRAPHS				     TRUE /* N4086						       */
#define Z_CPP_HAS_STATIC_ASSERTION_WITH_NO_MESSAGE		     TRUE /* N3928    __cpp_static_assert		    >= 201411L */
#define Z_CPP_HAS_STRUCTURED_BINDING				     TRUE /* P0217R3  __cpp_structured_bindings		    >= 201606L */
#define Z_CPP_HAS_SWITCH_WITH_INITIALIZER			     TRUE /* P0305R1						       */
#define Z_CPP_HAS_TEMPLATE_ARGUMENT_DEDUCTION_FOR_CLASS_TEMPLATE     TRUE /* P0091R3  __cpp_deduction_guides		    >= 201606L
									     P0512R0  __cpp_deduction_guides		    >= 201611L
									     P0620R0  __cpp_deduction_guides		    >= 201703L */
#define Z_CPP_HAS_TYPENAME_IN_TEMPLATE_TEMPLATE_PARAMETER	     TRUE /* N4051						       */
#define Z_CPP_HAS_VARIADIC_USING				     TRUE /* P0195R2  __cpp_variadic_using		    >= 201611L */
#define Z_CPP_HAS_ATTRIBUTE_FALLTHROUGH				     TRUE /* P0188R1  __has_cpp_attribute(fallthrough)	    >= 201603L */
#define Z_CPP_HAS_ATTRIBUTE_MAYBE_UNUSED			     TRUE /* P0212R1  __has_cpp_attribute(maybe_unused)	    >= 201603L */
#define Z_CPP_HAS_ATTRIBUTE_NODISCARD				     TRUE /* P0189R1  __has_cpp_attribute(nodiscard)	    >= 201603L */
#define Z_CPP_HAS_LITERAL_HEXADECIMAL_FLOATING_POINT		     TRUE /* P0245R1  __cpp_hex_float			    >= 201603L */
#define Z_CPP_HAS_LITERAL_UTF8_CHARACTER			     TRUE /* N4267						       */
#define Z_CPP_HAS_PREPROCESSOR_OPERATOR_HAS_INCLUDE		     TRUE /* P0061R1  defined(__has_include)		    == TRUE    */
#define Z_CPP_HAS_SPECIFIER_CASE_CONSTEXPR_IF			     TRUE /* P0292R2  __cpp_if_constexpr		    >= 201606L */
#define Z_CPP_HAS_SPECIFIER_CASE_CONSTEXPR_LAMBDA		     TRUE /* P0170R1  __cpp_constexpr			    >= 201603L */
#define Z_CPP_HAS_SPECIFIER_CASE_INLINE_VARIABLE		     TRUE /* P0386R2  __cpp_inline_variables		    >= 201606L */

#endif /* Z_inspection_CPP_modules_CPP17_H */
