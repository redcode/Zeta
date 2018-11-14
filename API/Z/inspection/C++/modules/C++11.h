/* Z Kit - inspection/C++/modules/C++11.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_CPP_modules_CPP11_H_
#define _Z_inspection_CPP_modules_CPP11_H_

#include <Z/inspection/C++/modules/C++03.h>

#define Z_CPP_HAS_C99_PREPROCESSOR				   TRUE /* N1653 */
#define Z_CPP_HAS_CONCURRENT_STATIC_LOCAL_VARIABLE		   TRUE /* N2660 */
#define Z_CPP_HAS_CONDITIONALLY_SUPPORTED_BEHAVIOR		   TRUE /* N1627 */
#define Z_CPP_HAS_COPY_LIST_INITIALIZATION			   TRUE /* N2672 */
#define Z_CPP_HAS_CPP11_RULES_ON_UNIVERSAL_CHARACTER_NAME	   TRUE /* N2170 */
#define Z_CPP_HAS_DEFAULT_MEMBER_INITIALIZER			   TRUE /* N2756 */
#define Z_CPP_HAS_DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE TRUE /* DR226 */
#define Z_CPP_HAS_DEFAULTED_FUNCTION				   TRUE /* N2346 */
#define Z_CPP_HAS_DELEGATING_CONSTRUCTORS			   TRUE /* N1986 */
#define Z_CPP_HAS_DELETED_FUNCTION				   TRUE /* N2346 */
#define Z_CPP_HAS_DIRECT_LIST_INITIALIZATION			   TRUE /* N2672 */
#define Z_CPP_HAS_EXPLICIT_CONVERSION_FUNCTION			   TRUE /* N2437 */
#define Z_CPP_HAS_EXPRESSION_SFINAE				   TRUE /* N2634 (DR339?) */
#define Z_CPP_HAS_EXTENDED_FRIEND_DECLARATION			   TRUE /* N1791 */
#define Z_CPP_HAS_EXTERN_TEMPLATE				   TRUE /* N1987 */
#define Z_CPP_HAS_FORWARD_DECLARATION_OF_ENUMERATION		   TRUE /* N2764, DR1206 */
#define Z_CPP_HAS_INHERITING_CONSTRUCTORS			   TRUE /* N2540 */
#define Z_CPP_HAS_INITIALIZATION_OF_CLASS_OBJECT_BY_RVALUE	   TRUE /* N1610 */
#define Z_CPP_HAS_INITIALIZER_LIST				   TRUE /* N2672 */
#define Z_CPP_HAS_INLINE_NAMESPACE				   TRUE /* N2535 */
#define Z_CPP_HAS_LAMBDA					   TRUE /* N2550(v0.9), N2658(v1.0), N2927(v1.1) */
#define Z_CPP_HAS_LOCAL_TYPE_AS_TEMPLATE_ARGUMENT		   TRUE /* N2657 */
#define Z_CPP_HAS_MOVE_SPECIAL_MEMBER_FUNCTIONS			   TRUE /* N3053 */
#define Z_CPP_HAS_MULTI_DECLARATOR_AUTO				   TRUE /* N1737 */
#define Z_CPP_HAS_RANGE_BASED_FOR				   TRUE /* N2930 */
#define Z_CPP_HAS_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION   TRUE /* N2439 */
#define Z_CPP_HAS_REMOVAL_OF_AUTO_AS_STORAGE_CLASS		   TRUE /* N2546 */
#define Z_CPP_HAS_RIGHT_ANGLE_BRACKETS				   TRUE /* N1757 */
#define Z_CPP_HAS_RVALUE_REFERENCE				   TRUE /* N2118(v1.0), N2844(v2.0), N2844+(v2.1) */
#define Z_CPP_HAS_STANDARD_LAYOUT				   TRUE /* N2342 */
#define Z_CPP_HAS_STANDARDIZED_ATTRIBUTE_SYNTAX			   TRUE /* N2761 */
#define Z_CPP_HAS_STATIC_ASSERTION				   TRUE /* N1720 */
#define Z_CPP_HAS_STRONGLY_TYPED_ENUMERATION			   TRUE /* N2347 */
#define Z_CPP_HAS_TEMPLATE_ALIAS				   TRUE /* N2258 */
#define Z_CPP_HAS_TRAILING_RETURN_TYPE				   TRUE /* N2541 */
#define Z_CPP_HAS_UNNAMED_TYPE_AS_TEMPLATE_ARGUMENT		   TRUE /* N2657 */
#define Z_CPP_HAS_UNRESTRICTED_UNION				   TRUE /* N2544 */
#define Z_CPP_HAS_VARIADIC_TEMPLATE				   TRUE /* N2242(v0.9) */
#define Z_CPP_HAS_VARIADIC_TEMPLATE_EXTENDED_PARAMETERS		   TRUE /* N2555(v1.0) */
#define Z_CPP_HAS_ATTRIBUTE_CARRIES_DEPENDENCY			   TRUE /* N2643: [[carries_dependency]]	    */
#define Z_CPP_HAS_ATTRIBUTE_NO_RETURN				   TRUE /* N2761: [[noreturn]]			    */
#define Z_CPP_HAS_LITERAL_CHAR16_CHARACTER			   TRUE /* N2249: u'c'				    */
#define Z_CPP_HAS_LITERAL_CHAR16_STRING				   TRUE /* N2249: u"string"			    */
#define Z_CPP_HAS_LITERAL_CHAR32_CHARACTER			   TRUE /* N2249: U'c'				    */
#define Z_CPP_HAS_LITERAL_CHAR32_STRING				   TRUE /* N2249: U"string"			    */
#define Z_CPP_HAS_LITERAL_NULL_POINTER				   TRUE /* N2431: nullptr			    */
#define Z_CPP_HAS_LITERAL_RAW_STRING				   TRUE /* N2442: [L|u|U|u8]R"string"		    */
#define Z_CPP_HAS_LITERAL_UNICODE_STRING			   TRUE /* N2442: u8"string"			    */
#define Z_CPP_HAS_LITERAL_USER_DEFINED				   TRUE /* N2765				    */
#define Z_CPP_HAS_MAGIC_CONSTANT_FUNCTION_NAME			   TRUE /* N2340: __func__			    */
#define Z_CPP_HAS_OPERATOR_ALIGN_OF				   TRUE /* N2341: alignof()			    */
#define Z_CPP_HAS_OPERATOR_NO_EXCEPTION				   TRUE /* N3050: noexcept()			    */
#define Z_CPP_HAS_OPERATOR_SIZE_OF_NON_STATIC_DATA_MEMBER	   TRUE /* N2253, DR850: sizeof(Class::data_member) */
#define Z_CPP_HAS_OPERATOR_SIZE_OF_PARAMETER_PACK		   TRUE /* N2242: sizeof...(parameter_pack)	    */
#define Z_CPP_HAS_SPECIFIER_ALIGN_AS				   TRUE /* N2341: alignas()			    */
#define Z_CPP_HAS_SPECIFIER_AUTO				   TRUE /* N1984(v1.0): auto			    */
#define Z_CPP_HAS_SPECIFIER_CONSTANT_EXPRESSION			   TRUE /* N2235: constexpr			    */
#define Z_CPP_HAS_SPECIFIER_DECLARED_TYPE			   TRUE /* N2343(v1.0): decltype()		    */
#define Z_CPP_HAS_SPECIFIER_DECLARED_TYPE_OF_INCOMPLETE_RETURN	   TRUE /* N3276(v1.1): decltype()		    */
#define Z_CPP_HAS_SPECIFIER_FINAL				   TRUE /* N2928(v0.8), N3206(v0.9), N3272(v1.0)    */
#define Z_CPP_HAS_SPECIFIER_NO_EXCEPTION			   TRUE /* N3050: noexcept, noexcept()		    */
#define Z_CPP_HAS_SPECIFIER_OVERRIDE				   TRUE /* N2928(v0.8), N3206(v0.9), N3272(v1.0)    */
#define Z_CPP_HAS_STORATE_CLASS_THREAD_LOCAL			   TRUE /* N2659: thread_local			    */
#define Z_CPP_HAS_TYPE_CHAR16					   TRUE /* N2249: char16_t			    */
#define Z_CPP_HAS_TYPE_CHAR32					   TRUE /* N2249: char32_t			    */
#define Z_CPP_HAS_TYPE_LLONG					   TRUE /* N1811: [unsigned|signed] long long [int] */

#endif /* _Z_inspection_CPP_modules_CPP11_H_ */
