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

#define Z_CPP_HAS_REFERENCE_QUALIFIED_FUNCTION
#define Z_CPP_HAS_REFERENCE_QUALIFIED_MEMBER_FUNCTION
#define Z_CPP_HAS_VARIADIC_TEMPLATE

/* MARK: - Specifiers */

#define Z_CPP_HAS_SPECIFIER_CONSTANT_EXPRESSION
#define Z_CPP_HAS_SPECIFIER_NO_EXCEPTION

/* MARK: - Operators */

#define Z_CPP_HAS_OPERATOR_NO_EXCEPTION

#endif /* __Z_private_CPP_CPP11_H__ */
