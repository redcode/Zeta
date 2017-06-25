/* Z Kit C API - inspection/C++/modules/C++11.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_CPP_modules_CPP11_H__
#define __Z_inspection_CPP_modules_CPP11_H__

/* MARK: - Inherited */

#include <Z/inspection/C++/modules/C++03.h>

/* MARK: - Features */

#define Z_CPP_HAS_C99_PREPROCESSOR				 TRUE /* N1653 */
#define Z_CPP_HAS_EXPLICIT_CONVERSION				 TRUE /* N2437 */
#define Z_CPP_HAS_EXPRESSION_SFINAE				 TRUE /* DR339 (?) */
#define Z_CPP_HAS_INHERITING_CONSTRUCTORS			 TRUE /* N2540 */
#define Z_CPP_HAS_INITIALIZER_LIST				 TRUE /* N2672 */
#define Z_CPP_HAS_LAMBDA					 TRUE /* N2550(v0.9), N2658(v1.0), N2927(v1.1) */
#define Z_CPP_HAS_NON_STATIC_DATA_MEMBER_INITIALIZER		 TRUE /* N2756 */
#define Z_CPP_HAS_RANGE_BASED_FOR				 TRUE /* N2930 */
#define Z_CPP_HAS_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION TRUE /* N2439 */
#define Z_CPP_HAS_RVALUE_REFERENCE				 TRUE /* N2118(v1.0), N2844(v2.0), N2844+(v2.1), N3053(v3.0) */
#define Z_CPP_HAS_STATIC_CONSTANT_DATA_MEMBER_INITIALIZER	 TRUE
#define Z_CPP_HAS_STRONGLY_TYPED_ENUMERATION			 TRUE /* N2347 */
#define Z_CPP_HAS_TEMPLATE_ALIAS				 TRUE /* N2258 */
#define Z_CPP_HAS_TRAILING_RETURN_TYPE				 TRUE /* N2541 */
#define Z_CPP_HAS_UNRESTRICTED_UNION				 TRUE /* N2544 */
#define Z_CPP_HAS_VARIADIC_TEMPLATE				 TRUE /* N2242(v0.9) */
#define Z_CPP_HAS_VARIADIC_TEMPLATE_EXTENDED_PARAMETERS		 TRUE /* N2555(v1.0) */

/* MARK: - Types */

#define Z_CPP_HAS_TYPE_ULLONG TRUE /* N1811: unsigned long long [int] */
#define Z_CPP_HAS_TYPE_LLONG  TRUE /* N1811: [signed] long long [int] */

/* MARK: - Specifiers */

#define Z_CPP_HAS_SPECIFIER_ALIGN_AS			    TRUE /* N2341:	 alignas()	      */
#define Z_CPP_HAS_SPECIFIER_AUTO			    TRUE /* N1984(v1.0): auto		      */
#define Z_CPP_HAS_SPECIFIER_CONSTANT_EXPRESSION		    TRUE /* N2235:	 constexpr	      */
#define Z_CPP_HAS_SPECIFIER_DECLARED_TYPE		    TRUE /* N2343(v1.0): decltype()	      */
#define Z_CPP_HAS_SPECIFIER_DECLARED_TYPE_INCOMPLETE_RETURN TRUE /* N3276(v1.1): decltype()	      */
#define Z_CPP_HAS_SPECIFIER_NO_EXCEPTION		    TRUE /* N3050:	 noexcept, noexcept() */

/* MARK: - Operators */

#define Z_CPP_HAS_OPERATOR_ALIGN_OF	TRUE /* N2341: alignof()  */
#define Z_CPP_HAS_OPERATOR_NO_EXCEPTION TRUE /* N3050: noexcept() */

/* MARK: - Literals */

#define Z_CPP_HAS_LITERAL_NULL_POINTER TRUE /* N2431: nullptr */

#endif /* __Z_inspection_CPP_modules_CPP11_H__ */
