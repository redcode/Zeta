/* Zeta API - Z/inspection/C++/modules/C++11.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_CPP_modules_CPP11_H
#define Z_inspection_CPP_modules_CPP11_H

#include <Z/inspection/C++/modules/C++03.h>					/* Paper    Test macro						   */
										/* -------  ------------------------------------------------------ */
#define Z_LANGUAGE_HAS_CPP11_ANONYMOUS_TYPE_AS_TEMPLATE_ARGUMENT	      1 /* N2657							   */
#define Z_LANGUAGE_HAS_CPP11_C99_PREPROCESSOR				      1 /* N1653							   */
#define Z_LANGUAGE_HAS_CPP11_COPY_LIST_INITIALIZATION			      1 /* N2672    __cpp_initializer_lists		    >= 200806L (!) */
#define Z_LANGUAGE_HAS_CPP11_DEFAULT_MEMBER_INITIALIZER			      1 /* N2756    __cpp_nsdmi				    >= 200809L (!) */
#define Z_LANGUAGE_HAS_CPP11_DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE 1 /* DR226							   */
#define Z_LANGUAGE_HAS_CPP11_DELEGATING_CONSTRUCTORS			      1 /* N1986    __cpp_delegating_constructors	    >= 200604L (!) */
#define Z_LANGUAGE_HAS_CPP11_DELETED_FUNCTION				      1 /* N2346							   */
#define Z_LANGUAGE_HAS_CPP11_DIRECT_LIST_INITIALIZATION			      1 /* N2672    __cpp_initializer_lists		    >= 200806L (!) */
#define Z_LANGUAGE_HAS_CPP11_EXPLICIT_CONVERSION_OPERATOR		      1 /* N2437							   */
#define Z_LANGUAGE_HAS_CPP11_EXPLICITLY_DEFAULTED_SPECIAL_MEMBER_FUNCTION     1 /* N2346							   */
#define Z_LANGUAGE_HAS_CPP11_EXPRESSION_SFINAE				      1 /* N2634
										   DR339?							   */
#define Z_LANGUAGE_HAS_CPP11_EXTENDED_FRIEND_DECLARATION		      1 /* N1791							   */
#define Z_LANGUAGE_HAS_CPP11_EXTENDED_VARIADIC_TEMPLATE_TEMPLATE_PARAMETERS   1 /* N2555							   */
#define Z_LANGUAGE_HAS_CPP11_EXTERN_TEMPLATE				      1 /* N1987							   */
#define Z_LANGUAGE_HAS_CPP11_FIXED_ENUMERATION				      1 /* N2347							   */
#define Z_LANGUAGE_HAS_CPP11_INHERITING_CONSTRUCTORS			      1 /* N2540    __cpp_inheriting_constructors	    >= 200802L (!) */
#define Z_LANGUAGE_HAS_CPP11_INITIALIZATION_OF_CLASS_OBJECT_BY_RVALUE	      1 /* N1610							   */
#define Z_LANGUAGE_HAS_CPP11_INITIALIZER_LIST				      1 /* N2672    __cpp_initializer_lists		    >= 200806L (!) */
#define Z_LANGUAGE_HAS_CPP11_INLINE_NAMESPACE				      1 /* N2535							   */
#define Z_LANGUAGE_HAS_CPP11_LAMBDA					      1 /* N2550    __cpp_lambdas			    >= 200907L (!)
										   N2658    __cpp_lambdas			    >= 200907L (!)
										   N2927    __cpp_lambdas			    >= 200907L (!) */
#define Z_LANGUAGE_HAS_CPP11_LOCAL_TYPE_AS_TEMPLATE_ARGUMENT		      1 /* N2657							   */
#define Z_LANGUAGE_HAS_CPP11_MOVE_SPECIAL_MEMBER_FUNCTIONS		      1 /* N3053							   */
#define Z_LANGUAGE_HAS_CPP11_MULTI_DECLARATOR_AUTO			      1 /* N1737							   */
#define Z_LANGUAGE_HAS_CPP11_OPAQUE_ENUMERATION_DECLARATION		      1 /* N2764							   */
										/* DR1206							   */
#define Z_LANGUAGE_HAS_CPP11_RANGE_BASED_FOR				      1 /* N2930    __cpp_range_based_for		    >= 200907L (!) */
#define Z_LANGUAGE_HAS_CPP11_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION   1 /* N2439    __cpp_ref_qualifiers		    >= 200710L (!) */
#define Z_LANGUAGE_HAS_CPP11_REMOVAL_OF_AUTO_AS_STORAGE_CLASS		      1 /* N2546							   */
#define Z_LANGUAGE_HAS_CPP11_RIGHT_ANGLE_BRACKETS			      1 /* N1757							   */
#define Z_LANGUAGE_HAS_CPP11_RVALUE_REFERENCE				      1 /* N2118    __cpp_rvalue_references		    >= 200610L (!)
										   N2844
										   CWG1138							   */
#define Z_LANGUAGE_HAS_CPP11_SCOPED_ENUMERATION				      1 /* N2347							   */
#define Z_LANGUAGE_HAS_CPP11_STD_LAYOUT					      1 /* N2342							   */
#define Z_LANGUAGE_HAS_CPP11_STANDARDIZED_ATTRIBUTE_SYNTAX		      1 /* N2761    __cpp_attributes			    >= 200809L (!) */
#define Z_LANGUAGE_HAS_CPP11_STATIC_ASSERTION				      1 /* N1720    __cpp_static_assert			    >= 200410L (!) */
#define Z_LANGUAGE_HAS_CPP11_THREAD_SAFE_STATIC_INITIALIZATION		      1 /* N2660    __cpp_threadsafe_static_init	    >= 200806L (!) */
#define Z_LANGUAGE_HAS_CPP11_TRAILING_COMMA_ALLOWED_IN_ENUMERATION	      1 /*								   */
#define Z_LANGUAGE_HAS_CPP11_TRAILING_RETURN_TYPE			      1 /* N2541							   */
#define Z_LANGUAGE_HAS_CPP11_TYPE_ALIAS					      1 /* N2258    __cpp_alias_templates		    >= 200704L (!) */
#define Z_LANGUAGE_HAS_CPP11_TYPE_ALIAS_TEMPLATE			      1 /* N2258    __cpp_alias_templates		    >= 200704L (!) */
#define Z_LANGUAGE_HAS_CPP11_UNIVERSAL_CHARACTER_NAME			      1 /* N2170							   */
#define Z_LANGUAGE_HAS_CPP11_UNRESTRICTED_UNION				      1 /* N2544							   */
#define Z_LANGUAGE_HAS_CPP11_VARIADIC_TEMPLATE				      1 /* N2242    __cpp_variadic_templates		    >= 200704L (!) */
#define Z_LANGUAGE_HAS_CPP11_ATTRIBUTE_CARRIES_DEPENDENCY		      1 /* N2782    __has_cpp_attribute(carries_dependency) >= 200809L (!) */
#define Z_LANGUAGE_HAS_CPP11_ATTRIBUTE_NORETURN				      1 /* N2761    __has_cpp_attribute(noreturn)	    >= 200809L (!) */
#define Z_LANGUAGE_HAS_CPP11_IDENTIFIER_FUNC				      1 /* N2340							   */
#define Z_LANGUAGE_HAS_CPP11_LITERAL_NULLPTR				      1 /* N2431							   */
#define Z_LANGUAGE_HAS_CPP11_LITERAL_RAW_STRING				      1 /* N2442    __cpp_raw_strings			    >= 200710L (!) */
#define Z_LANGUAGE_HAS_CPP11_LITERAL_USER_DEFINED			      1 /* N2765    __cpp_user_defined_literals		    >= 200809L (!) */
#define Z_LANGUAGE_HAS_CPP11_LITERAL_UTF8_STRING			      1 /* N2442    __cpp_unicode_literals		    >= 200710L (!) */
#define Z_LANGUAGE_HAS_CPP11_OPERATOR_ALIGNOF				      1 /* N2341							   */
#define Z_LANGUAGE_HAS_CPP11_OPERATOR_NOEXCEPT				      1 /* N3050							   */
#define Z_LANGUAGE_HAS_CPP11_OPERATOR_CASE_SIZEOF_NON_STATIC_DATA_MEMBER      1 /* N2253
										   DR850							   */
#define Z_LANGUAGE_HAS_CPP11_OPERATOR_CASE_SIZEOF_PARAMETER_PACK	      1 /* N2242    __cpp_variadic_templates		    >= 200704L (!) */
#define Z_LANGUAGE_HAS_CPP11_SPECIFIER_ALIGNAS				      1 /* N2341							   */
#define Z_LANGUAGE_HAS_CPP11_SPECIFIER_CONSTEXPR			      1 /* N2235    __cpp_constexpr			    >= 200704L (!) */
#define Z_LANGUAGE_HAS_CPP11_SPECIFIER_DECLTYPE				      1 /* N2343    __cpp_decltype			    >= 200707L (!) */
#define Z_LANGUAGE_HAS_CPP11_SPECIFIER_FINAL				      1 /* N2928
										   N3206
										   N3272							   */
#define Z_LANGUAGE_HAS_CPP11_SPECIFIER_NOEXCEPT				      1 /* N3050							   */
#define Z_LANGUAGE_HAS_CPP11_SPECIFIER_OVERRIDE				      1 /* N2928
										   N3206
										   N3272							   */
#define Z_LANGUAGE_HAS_CPP11_SPECIFIER_CASE_DECLTYPE_INCOMPLETE_RETURN_TYPE   1 /* N3276							   */
#define Z_LANGUAGE_HAS_CPP11_STORAGE_CLASS_THREAD_LOCAL			      1 /* N2659							   */
#define Z_LANGUAGE_HAS_CPP11_TYPE_AUTO					      1 /* N1984							   */
#define Z_LANGUAGE_HAS_CPP11_TYPE_CHAR16_T				      1 /* N2249    __cpp_unicode_characters		    >= 200704L (!) */
#define Z_LANGUAGE_HAS_CPP11_TYPE_CHAR32_T				      1 /* N2249    __cpp_unicode_characters		    >= 200704L (!) */
#define Z_LANGUAGE_HAS_CPP11_TYPE_LONG_LONG				      1 /* N1811							   */

#endif /* Z_inspection_CPP_modules_CPP11_H */
