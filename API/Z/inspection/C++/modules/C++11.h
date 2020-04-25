/* Z Kit - inspection/C++/modules/C++11.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_CPP_modules_CPP11_H
#define Z_inspection_CPP_modules_CPP11_H

#include <Z/inspection/C++/modules/C++03.h>				/* Paper	Test macro					       */
									/* -----------  ------------------------------------------------------ */
#define Z_CPP_HAS_ANONYMOUS_TYPE_AS_TEMPLATE_ARGUMENT		   TRUE /* N2657							       */
#define Z_CPP_HAS_C99_PREPROCESSOR				   TRUE /* N1653							       */
#define Z_CPP_HAS_COPY_LIST_INITIALIZATION			   TRUE /* N2672	__cpp_initializer_lists			>= 200806L (!) */
#define Z_CPP_HAS_CPP11_UNIVERSAL_CHARACTER_NAME		   TRUE /* N2170							       */
#define Z_CPP_HAS_DEFAULT_MEMBER_INITIALIZER			   TRUE /* N2756	__cpp_nsdmi				>= 200809L (!) */
#define Z_CPP_HAS_DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE TRUE /* DR226							       */
#define Z_CPP_HAS_DELEGATING_CONSTRUCTORS			   TRUE /* N1986	__cpp_delegating_constructors		>= 200604L (!) */
#define Z_CPP_HAS_DELETED_FUNCTION				   TRUE /* N2346							       */
#define Z_CPP_HAS_DIRECT_LIST_INITIALIZATION			   TRUE /* N2672	__cpp_initializer_lists			>= 200806L (!) */
#define Z_CPP_HAS_EXPLICIT_CONVERSION_OPERATOR			   TRUE /* N2437							       */
#define Z_CPP_HAS_EXPLICITLY_DEFAULTED_SPECIAL_MEMBER_FUNCTION	   TRUE /* N2346							       */
#define Z_CPP_HAS_EXPRESSION_SFINAE				   TRUE /* N2634
									   DR339?							       */
#define Z_CPP_HAS_EXTENDED_FRIEND_DECLARATION			   TRUE /* N1791							       */
#define Z_CPP_HAS_EXTENDED_VARIADIC_TEMPLATE_TEMPLATE_PARAMETERS   TRUE /* N2555							       */
#define Z_CPP_HAS_EXTERN_TEMPLATE				   TRUE /* N1987							       */
#define Z_CPP_HAS_FIXED_ENUMERATION				   TRUE /* N2347							       */
#define Z_CPP_HAS_INHERITING_CONSTRUCTORS			   TRUE /* N2540	__cpp_inheriting_constructors		>= 200802L (!) */
#define Z_CPP_HAS_INITIALIZATION_OF_CLASS_OBJECT_BY_RVALUE	   TRUE /* N1610							       */
#define Z_CPP_HAS_INITIALIZER_LIST				   TRUE /* N2672	__cpp_initializer_lists			>= 200806L (!) */
#define Z_CPP_HAS_INLINE_NAMESPACE				   TRUE /* N2535							       */
#define Z_CPP_HAS_LAMBDA					   TRUE /* N2550	__cpp_lambdas				>= 200907L (!)
									   N2658	__cpp_lambdas				>= 200907L (!)
									   N2927	__cpp_lambdas				>= 200907L (!) */
#define Z_CPP_HAS_LOCAL_TYPE_AS_TEMPLATE_ARGUMENT		   TRUE /* N2657							       */
#define Z_CPP_HAS_MOVE_SPECIAL_MEMBER_FUNCTIONS			   TRUE /* N3053							       */
#define Z_CPP_HAS_MULTI_DECLARATOR_AUTO				   TRUE /* N1737							       */
#define Z_CPP_HAS_OPAQUE_ENUMERATION_DECLARATION		   TRUE /* N2764							       */
									/* DR1206							       */
#define Z_CPP_HAS_RANGE_BASED_FOR				   TRUE /* N2930	__cpp_range_based_for			>= 200907L (!) */
#define Z_CPP_HAS_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION   TRUE /* N2439	__cpp_ref_qualifiers			>= 200710L (!) */
#define Z_CPP_HAS_REMOVAL_OF_AUTO_AS_STORAGE_CLASS		   TRUE /* N2546							       */
#define Z_CPP_HAS_RIGHT_ANGLE_BRACKETS				   TRUE /* N1757							       */
#define Z_CPP_HAS_RVALUE_REFERENCE				   TRUE /* N2118(v1.0)	__cpp_rvalue_references			>= 200610L (!)
									   N2844(v2.0)?
									   CWG1138?							       */
#define Z_CPP_HAS_SCOPED_ENUMERATION				   TRUE /* N2347							       */
#define Z_CPP_HAS_STANDARD_LAYOUT				   TRUE /* N2342							       */
#define Z_CPP_HAS_STANDARDIZED_ATTRIBUTE_SYNTAX			   TRUE /* N2761	__cpp_attributes			>= 200809L (!) */
#define Z_CPP_HAS_STATIC_ASSERTION				   TRUE /* N1720	__cpp_static_assert			>= 200410L (!) */
#define Z_CPP_HAS_THREAD_SAFE_STATIC_INITIALIZATION		   TRUE /* N2660	__cpp_threadsafe_static_init		>= 200806L (!) */
#define Z_CPP_HAS_TRAILING_COMMA_ALLOWED_IN_ENUMERATION		   TRUE /*								       */
#define Z_CPP_HAS_TRAILING_RETURN_TYPE				   TRUE /* N2541							       */
#define Z_CPP_HAS_TYPE_ALIAS					   TRUE /* N2258	__cpp_alias_templates			>= 200704L (!) */
#define Z_CPP_HAS_TYPE_ALIAS_TEMPLATE				   TRUE /* N2258	__cpp_alias_templates			>= 200704L (!) */
#define Z_CPP_HAS_UNRESTRICTED_UNION				   TRUE /* N2544							       */
#define Z_CPP_HAS_VARIADIC_TEMPLATE				   TRUE /* N2242	__cpp_variadic_templates		>= 200704L (!) */
#define Z_CPP_HAS_ATTRIBUTE_CARRIES_DEPENDENCY			   TRUE /* N2782	__has_cpp_attribute(carries_dependency) >= 200809L (!) */
#define Z_CPP_HAS_ATTRIBUTE_NORETURN				   TRUE /* N2761	__has_cpp_attribute(noreturn)		>= 200809L (!) */
#define Z_CPP_HAS_IDENTIFIER_FUNC				   TRUE /* N2340							       */
#define Z_CPP_HAS_LITERAL_NULLPTR				   TRUE /* N2431							       */
#define Z_CPP_HAS_LITERAL_RAW_STRING				   TRUE /* N2442	__cpp_raw_strings			>= 200710L (!) */
#define Z_CPP_HAS_LITERAL_USER_DEFINED				   TRUE /* N2765	__cpp_user_defined_literals		>= 200809L (!) */
#define Z_CPP_HAS_LITERAL_UTF8_STRING				   TRUE /* N2442	__cpp_unicode_literals			>= 200710L (!) */
#define Z_CPP_HAS_OPERATOR_ALIGNOF				   TRUE /* N2341							       */
#define Z_CPP_HAS_OPERATOR_NOEXCEPT				   TRUE /* N3050							       */
#define Z_CPP_HAS_OPERATOR_CASE_SIZEOF_NON_STATIC_DATA_MEMBER	   TRUE /* N2253
									   DR850							       */
#define Z_CPP_HAS_OPERATOR_CASE_SIZEOF_PARAMETER_PACK		   TRUE /* N2242	__cpp_variadic_templates		>= 200704L (!) */
#define Z_CPP_HAS_SPECIFIER_ALIGNAS				   TRUE /* N2341							       */
#define Z_CPP_HAS_SPECIFIER_CONSTEXPR				   TRUE /* N2235	__cpp_constexpr				>= 200704L (!) */
#define Z_CPP_HAS_SPECIFIER_DECLTYPE				   TRUE /* N2343	__cpp_decltype				>= 200707L (!) */
#define Z_CPP_HAS_SPECIFIER_FINAL				   TRUE /* N2928
									   N3206
									   N3272							       */
#define Z_CPP_HAS_SPECIFIER_NOEXCEPT				   TRUE /* N3050							       */
#define Z_CPP_HAS_SPECIFIER_OVERRIDE				   TRUE /* N2928
									   N3206
									   N3272							       */
#define Z_CPP_HAS_SPECIFIER_CASE_DECLTYPE_INCOMPLETE_RETURN_TYPE   TRUE /* N3276							       */
#define Z_CPP_HAS_STORAGE_CLASS_THREAD_LOCAL			   TRUE /* N2659							       */
#define Z_CPP_HAS_TYPE_AUTO					   TRUE /* N1984							       */
#define Z_CPP_HAS_TYPE_CHAR16_T					   TRUE /* N2249	__cpp_unicode_characters		>= 200704L (!) */
#define Z_CPP_HAS_TYPE_CHAR32_T					   TRUE /* N2249	__cpp_unicode_characters		>= 200704L (!) */
#define Z_CPP_HAS_TYPE_LONG_LONG				   TRUE /* N1811							       */

#endif /* Z_inspection_CPP_modules_CPP11_H */
