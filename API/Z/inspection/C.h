/* Zeta API - Z/inspection/C.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_C_H
#define Z_inspection_C_H

#include <Z/keys/C.h>
#include <Z/macros/token.h>

#ifndef Z_C
#	if !defined(__STDC__) && !defined(__cplusplus)
#		define Z_C Z_C78
#	elif !defined(__STDC_VERSION__)
#		define Z_C Z_C89
#	elif __STDC_VERSION__ >= 201710L
#		define Z_C Z_C17
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

#if Z_C == Z_C17
#	include <Z/inspection/C/modules/C11.h>
#	define Z_C_NAME Z_C_NAME_C17
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
#elif Z_C == Z_C78
#	include <Z/inspection/C/modules/C78.h>
#	define Z_C_NAME Z_C_NAME_C78
#else
#	error "Invalid Z_C key."
#endif

/* MARK: - Getters */

#define Z_C_HAS(		       FEATURE		     ) Z_IS_TRUE(Z_C_HAS_##FEATURE					)
#define Z_C_HAS_ATTRIBUTE(	       ATTRIBUTE	     ) Z_IS_TRUE(Z_C_HAS_ATTRIBUTE_##ATTRIBUTE				)
#define Z_C_HAS_ESCAPE_SEQUENCE(       ESCAPE_SEQUENCE	     ) Z_IS_TRUE(Z_C_HAS_ESCAPE_SEQUENCE_##ESCAPE_SEQUENCE		)
#define Z_C_HAS_IDENTIFIER(	       IDENTIFIER	     ) Z_IS_TRUE(Z_C_HAS_IDENTIFIER_##IDENTIFIER			)
#define Z_C_HAS_LITERAL(	       LITERAL		     ) Z_IS_TRUE(Z_C_HAS_LITERAL_##LITERAL				)
#define Z_C_HAS_OPERATOR(	       OPERATOR		     ) Z_IS_TRUE(Z_C_HAS_OPERATOR_##OPERATOR				)
#define Z_C_HAS_PREPROCESSOR_DIRECTIVE(PREPROCESSOR_DIRECTIVE) Z_IS_TRUE(Z_C_HAS_PREPROCESSOR_DIRECTIVE_##PREPROCESSOR_DIRECTIVE)
#define Z_C_HAS_PREPROCESSOR_OPERATOR( PREPROCESSOR_OPERATOR ) Z_IS_TRUE(Z_C_HAS_PREPROCESSOR_OPERATOR_##PREPROCESSOR_OPERATOR	)
#define Z_C_HAS_SPECIFIER(	       SPECIFIER	     ) Z_IS_TRUE(Z_C_HAS_SPECIFIER_##SPECIFIER				)
#define Z_C_HAS_STD_PRAGMA(	       STD_PRAGMA	     ) Z_IS_TRUE(Z_C_HAS_STD_PRAGMA_##STD_PRAGMA			)
#define Z_C_HAS_STORAGE_CLASS(	       STORAGE_CLASS	     ) Z_IS_TRUE(Z_C_HAS_STORAGE_CLASS_##STORAGE_CLASS			)
#define Z_C_HAS_TYPE(		       TYPE		     ) Z_IS_TRUE(Z_C_HAS_TYPE_##TYPE					)
#define Z_C_HAS_TYPE_MODIFIER(	       TYPE_MODIFIER	     ) Z_IS_TRUE(Z_C_HAS_TYPE_MODIFIER_##TYPE_MODIFIER			)
#define Z_C_HAS_TYPE_QUALIFIER(	       TYPE_QUALIFIER	     ) Z_IS_TRUE(Z_C_HAS_TYPE_QUALIFIER_##TYPE_QUALIFIER		)

#endif /* Z_inspection_C_H */
