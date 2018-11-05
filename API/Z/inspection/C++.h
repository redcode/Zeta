/* Z Kit - inspection/C++.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_inspection_CPP_H_
#define _Z_inspection_CPP_H_

#include <Z/constants/base.h>
#include <Z/keys/C++.h>

#if !defined(Z_CPP) && defined(__cplusplus)
#	if __cplusplus >= 201703L
#		define Z_CPP Z_CPP17
#	elif __cplusplus >= 201402L
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

#define Z_CPP_HAS(			WHAT ) Z_CPP_HAS_##WHAT
#define Z_CPP_HAS_ATTRIBUTE(		WHICH) Z_CPP_HAS_ATTRIBUTE_##WHICH
#define Z_CPP_HAS_LITERAL(		WHICH) Z_CPP_HAS_LITERAL_##WHICH
#define Z_CPP_HAS_OPERATOR(		WHICH) Z_CPP_HAS_OPERATOR_##WHICH
#define Z_CPP_HAS_SPECIFIER(		WHICH) Z_CPP_HAS_SPECIFIER_##WHICH
#define Z_CPP_HAS_STORAGE_CLASS(	WHICH) Z_CPP_HAS_STORAGE_CLASS_##WHICH
#define Z_CPP_HAS_TYPE(			WHICH) Z_CPP_HAS_TYPE_##WHICH
#define Z_CPP_HAS_TYPE_QUALIFIER(	WHICH) Z_CPP_HAS_TYPE_QUALIFIER_##WHICH
#define Z_CPP_HAS_PREPROCESSOR_OPERATOR(WHICH) Z_CPP_HAS_PREPROCESSOR_OPERATOR_##WHICH

#endif /* _Z_inspection_CPP_H_ */
