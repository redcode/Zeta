/* Z Kit - inspection/C.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_C_H
#define Z_inspection_C_H

#include <Z/constants/base.h>
#include <Z/keys/C.h>

#ifndef Z_C
#	if !defined(__STDC__)
#		define Z_C Z_KR_C

#	elif !defined(__STDC_VERSION__)
#		define Z_C Z_C89

#	elif __STDC_VERSION__ >= 201710L
#		define Z_C Z_C18

#	elif __STDC_VERSION__ >= 201112L
#		define Z_C Z_C11

#	elif __STDC_VERSION__ >= 199901L
#		define Z_C Z_C99

#	elif __STDC_VERSION__ >= 199409L
#		define Z_C Z_C95

#	else
#		define Z_C Z_C90
#	endif
#endif

#if Z_C == Z_C18
#	include <Z/inspection/C/modules/C11.h>
#	define Z_C_NAME Z_C_NAME_C18

#elif Z_C == Z_C11
#	include <Z/inspection/C/modules/C11.h>
#	define Z_C_NAME Z_C_NAME_C11

#elif Z_C == Z_C99
#	include <Z/inspection/C/modules/C99.h>
#	define Z_C_NAME Z_C_NAME_C99

#elif Z_C == Z_C95
#	include <Z/inspection/C/modules/C95.h>
#	define Z_C_NAME Z_C_NAME_C95

#elif Z_C == Z_C90
#	include <Z/inspection/C/modules/C89.h>
#	define Z_C_NAME Z_C_NAME_C90

#elif Z_C == Z_C89
#	include <Z/inspection/C/modules/C89.h>
#	define Z_C_NAME Z_C_NAME_C89

#elif Z_C == Z_KR_C
#	include <Z/inspection/C/modules/KR C.h>
#	define Z_C_NAME Z_C_NAME_KR_C

#else
#	error "Invalid Z_C key."
#endif

#include <Z/inspection/C/completion.h>

#define Z_C_HAS(		       FEATURE		     ) Z_C_HAS_##FEATURE
#define Z_C_HAS_ESCAPE_SEQUENCE(       ESCAPE_SEQUENCE	     ) Z_C_HAS_ESCAPE_SEQUENCE_##ESCAPE_SEQUENCE
#define Z_C_HAS_IDENTIFIER(	       IDENTIFIER	     ) Z_C_HAS_IDENTIFIER_##IDENTIFIER
#define Z_C_HAS_LITERAL(	       LITERAL		     ) Z_C_HAS_LITERAL_##LITERAL
#define Z_C_HAS_OPERATOR(	       OPERATOR		     ) Z_C_HAS_OPERATOR_##OPERATOR
#define Z_C_HAS_PREPROCESSOR_DIRECTIVE(PREPROCESSOR_DIRECTIVE) Z_C_HAS_PREPROCESSOR_DIRECTIVE_##PREPROCESSOR_DIRECTIVE
#define Z_C_HAS_PREPROCESSOR_OPERATOR( PREPROCESSOR_OPERATOR ) Z_C_HAS_PREPROCESSOR_OPERATOR_##PREPROCESSOR_OPERATOR
#define Z_C_HAS_SPECIFIER(	       SPECIFIER	     ) Z_C_HAS_SPECIFIER_##SPECIFIER
#define Z_C_HAS_STANDARD_PRAGMA(       STANDARD_PRAGMA	     ) Z_C_HAS_STANDARD_PRAGMA_##STANDARD_PRAGMA
#define Z_C_HAS_STORAGE_CLASS(	       STORAGE_CLASS	     ) Z_C_HAS_STORAGE_CLASS_##STORAGE_CLASS
#define Z_C_HAS_TYPE(		       TYPE		     ) Z_C_HAS_TYPE_##TYPE
#define Z_C_HAS_TYPE_MODIFIER(	       TYPE_MODIFIER	     ) Z_C_HAS_TYPE_MODIFIER_##TYPE_MODIFIER
#define Z_C_HAS_TYPE_QUALIFIER(	       TYPE_QUALIFIER	     ) Z_C_HAS_TYPE_QUALIFIER_##TYPE_QUALIFIER

#endif /* Z_inspection_C_H */
