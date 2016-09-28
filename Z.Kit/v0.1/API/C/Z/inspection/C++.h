/* Z Kit C API - inspection/C++.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_CPP_H__
#define __Z_inspection_CPP_H__

#include <Z/constants/base.h>
#include <Z/keys/C++.h>

#if !defined(Z_CPP) && defined(__cplusplus)
#	if __cplusplus >= 201402L
#		define Z_CPP Z_CPP14
#	elif __cplusplus >= 201103L
#		define Z_CPP Z_CPP11
#	elif __cplusplus >= 199711L
#		define Z_CPP Z_CPP98
#	else
#		define Z_CPP Z_CPP85
#	endif
#endif

#ifdef Z_CPP

#	if Z_CPP == Z_CPP17

#		include <Z/inspection/C++/modules/C++17.h>

#		define Z_CPP_STRING Z_CPP_STRING_CPP17

#	elif Z_CPP == Z_CPP14

#		include <Z/inspection/C++/modules/C++14.h>

#		define Z_CPP_STRING Z_CPP_STRING_CPP14

#	elif Z_CPP == Z_CPP11

#		include <Z/inspection/C++/modules/C++11.h>

#		define Z_CPP_STRING Z_CPP_STRING_CPP11

#	elif Z_CPP == Z_CPP03

#		include <Z/inspection/C++/modules/C++03.h>

#		define Z_CPP_STRING Z_CPP_STRING_CPP03

#	elif Z_CPP == Z_CPP98

#		include <Z/inspection/C++/modules/C++98.h>

#		define Z_CPP_STRING Z_CPP_STRING_CPP98

#	elif Z_CPP == Z_CPP89

#		include <Z/inspection/C++/modules/C++89.h>

#		define Z_CPP_STRING Z_CPP_STRING_CPP89

#	elif Z_CPP == Z_CPP85

#		include <Z/inspection/C++/modules/C++85.h>

#		define Z_CPP_STRING Z_CPP_STRING_CPP85

#	endif

#endif

#include <Z/inspection/C++/completion.h>

#define Z_CPP_HAS(		 WHAT ) Z_CPP_HAS_##WHAT
#define Z_CPP_HAS_TYPE(		 WHICH) Z_CPP_HAS_TYPE_##WHICH
#define Z_CPP_HAS_TYPE_QUALIFIER(WHICH) Z_CPP_HAS_TYPE_QUALIFIER_##WHICH
#define Z_CPP_HAS_STORAGE_CLASS( WHICH) Z_CPP_HAS_STORAGE_CLASS_##WHICH
#define Z_CPP_HAS_SPECIFIER(	 WHICH) Z_CPP_HAS_SPECIFIER_##WHICH
#define Z_CPP_HAS_OPERATOR(	 WHICH) Z_CPP_HAS_OPERATOR_##WHICH
#define Z_CPP_HAS_LITERAL(	 WHICH) Z_CPP_HAS_LITERAL_##WHICH

#endif /* __Z_inspection_CPP_H__ */
