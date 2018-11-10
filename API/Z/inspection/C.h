/* Z Kit - inspection/C.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_C_H_
#define _Z_inspection_C_H_

#include <Z/constants/base.h>
#include <Z/keys/C.h>

#ifndef Z_C
#	if !defined(__STDC__)
#		define Z_C Z_KR_C

#	elif !defined(__STDC_VERSION__)
#		define Z_C Z_89

#	elif __STDC_VERSION__ >= 201710L
#		define Z_C Z_C18

#	elif __STDC_VERSION__ >= 201112L
#		define Z_C Z_C11

#	elif __STDC_VERSION__ >= 199901L
#		define Z_C Z_99

#	elif __STDC_VERSION__ >= 199409L
#		define Z_C Z_C94

#	else
#		define Z_C Z_C90
#	endif
#endif

#if Z_C == Z_C18
#	include <Z/inspection/C/modules/C18.h>
#	define Z_C_STRING Z_C_STRING_C18

#elif Z_C == Z_C11
#	include <Z/inspection/C/modules/C11.h>
#	define Z_C_STRING Z_C_STRING_C11

#elif Z_C == Z_C99
#	include <Z/inspection/C/modules/C99.h>
#	define Z_C_STRING Z_C_STRING_C99

#elif Z_C == Z_C94
#	include <Z/inspection/C/modules/C94.h>
#	define Z_C_STRING Z_C_STRING_C94

#elif Z_C == Z_C90
#	include <Z/inspection/C/modules/C90.h>
#	define Z_C_STRING Z_C_STRING_C90

#elif Z_C == Z_C89
#	include <Z/inspection/C/modules/C89.h>
#	define Z_C_STRING Z_C_STRING_C89

#elif Z_C == Z_KR_C
#	include <Z/inspection/C/modules/KR C.h>
#	define Z_C_STRING Z_C_STRING_KR_C

#endif

#include <Z/inspection/C/completion.h>

#define Z_C_HAS(	       WHAT ) Z_C_HAS_##WHAT
#define Z_C_HAS_ATTRIBUTE(     WHICH) Z_C_HAS_ATTRIBUTE_##WHICH
#define Z_C_HAS_LITERAL(       WHICH) Z_C_HAS_LITERAL_##WHICH
#define Z_C_HAS_OPERATOR(      WHICH) Z_C_HAS_OPERATOR_##WHICH
#define Z_C_HAS_SPECIFIER(     WHICH) Z_C_HAS_SPECIFIER_##WHICH
#define Z_C_HAS_STORAGE_CLASS( WHICH) Z_C_HAS_STORAGE_CLASS_##WHICH
#define Z_C_HAS_TYPE(	       WHICH) Z_C_HAS_TYPE_##WHICH
#define Z_C_HAS_TYPE_QUALIFIER(WHICH) Z_C_HAS_TYPE_QUALIFIER_##WHICH

#endif /* _Z_inspection_C_H_ */
