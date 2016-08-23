/* Z Kit C API - private/C++/C++11.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_private_CPP_CPP11_H__
#define __Z_private_CPP_CPP11_H__

#ifndef Z_CPP
#	include <Z/keys/C++.h>

#	define Z_CPP	    Z_CPP11
#	define Z_CPP_STRING Z_CPP_STRING_CPP11
#endif

/* MARK: - Inherited */

#include <Z/inspection/private/C++/C++07 TR1.h>

/* MARK: - Features */

#define Z_CPP_HAS_C99_PREPROCESSOR				 /* N1653 */
#define Z_CPP_HAS_EXPRESSION_SFINAE
#define Z_CPP_HAS_INITIALIZER_LIST				 /* N2672 */
#define Z_CPP_HAS_NON_STATIC_DATA_MEMBER_INITIALIZER		 /* N2756 */
#define Z_CPP_HAS_LAMBDA					 /* N2550(v0.9), N2658(v1.0), N2927(v1.1) */
#define Z_CPP_HAS_REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION /* N2439 */
#define Z_CPP_HAS_RVALUE_REFERENCE				 /* N2118(v1.0), N2844(v2.0), N2844+(v2.1), N3053(v3.0) */
#define Z_CPP_HAS_STATIC_CONSTANT_DATA_MEMBER_INITIALIZER
#define Z_CPP_HAS_STRONGLY_TYPED_ENUMERATION			 /* N2347 */
#define Z_CPP_HAS_TRAILING_RETURN_TYPE				 /* N2541 */
#define Z_CPP_HAS_VARIADIC_TEMPLATE				 /* N2242(v0.9), N2555(v1.0) */

/* MARK: - Types */

#define Z_CPP_HAS_TYPE_ULLONG /* N1811: unsigned long long [int] */
#define Z_CPP_HAS_TYPE_LLONG  /* N1811: [signed] long long [int] */

/* MARK: - Specifiers */

#define Z_CPP_HAS_SPECIFIER_ALIGN_AS		/* N2341:		     alignas()		  */
#define Z_CPP_HAS_SPECIFIER_AUTO		/* N1984(v1.0):		     auto		  */
#define Z_CPP_HAS_SPECIFIER_CONSTANT_EXPRESSION	/* N2235:		     constexpr		  */
#define Z_CPP_HAS_SPECIFIER_DECLARED_TYPE	/* N2343(v1.0), N3276(v1.1): decltype()		  */
#define Z_CPP_HAS_SPECIFIER_NO_EXCEPTION	/* N3050:		     noexcept, noexcept() */

/* MARK: - Operators */

#define Z_CPP_HAS_OPERATOR_ALIGN_OF	/* N2341: alignof()  */
#define Z_CPP_HAS_OPERATOR_NO_EXCEPTION /* N3050: noexcept() */

/* MARK: - Literals */

#define Z_CPP_HAS_LITERAL_NULL_POINTER /* N2431: nullptr */

#endif /* __Z_private_CPP_CPP11_H__ */
