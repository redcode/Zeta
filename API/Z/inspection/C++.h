/* Zeta API - Z/inspection/C++.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_CPP_H
#define Z_inspection_CPP_H

#include <Z/keys/C++.h>
#include <Z/macros/token.h>

#ifdef __cplusplus

#	ifndef Z_CPP
#		if __cplusplus >= 202002L
#			define Z_CPP Z_CPP20
#		elif __cplusplus >= 201703L
#			define Z_CPP Z_CPP17
#		elif __cplusplus >= 201402L
#			define Z_CPP Z_CPP14
#		elif __cplusplus >= 201103L
#			define Z_CPP Z_CPP11
#		elif __cplusplus >= 199711L
#			define Z_CPP Z_CPP98
#		else
#			define Z_CPP Z_CPP1
#		endif
#	endif

#	if Z_CPP == Z_CPP20
#		include <Z/inspection/C++/modules/C++20.h>
#		define Z_CPP_NAME Z_CPP_NAME_CPP20
#	elif Z_CPP == Z_CPP17
#		include <Z/inspection/C++/modules/C++17.h>
#		define Z_CPP_NAME Z_CPP_NAME_CPP17
#	elif Z_CPP == Z_CPP14
#		include <Z/inspection/C++/modules/C++14.h>
#		define Z_CPP_NAME Z_CPP_NAME_CPP14
#	elif Z_CPP == Z_CPP11
#		include <Z/inspection/C++/modules/C++11.h>
#		define Z_CPP_NAME Z_CPP_NAME_CPP11
#	elif Z_CPP == Z_CPP03
#		include <Z/inspection/C++/modules/C++03.h>
#		define Z_CPP_NAME Z_CPP_NAME_CPP03
#	elif Z_CPP == Z_CPP98
#		include <Z/inspection/C++/modules/C++98.h>
#		define Z_CPP_NAME Z_CPP_NAME_CPP98
#	elif Z_CPP == Z_CPP2
#		define Z_CPP_NAME Z_CPP_NAME_CPP2
#	elif Z_CPP == Z_CPP1
#		define Z_CPP_NAME Z_CPP_NAME_CPP1
#	else
#		error "Invalid Z_CPP key."
#	endif

#endif

/* MARK: - Getters */

#define Z_CPP_HAS(			  FEATURE		 ) Z_IS_TRUE(Z_CPP_HAS_##FEATURE					)
#define Z_CPP_HAS_ATTRIBUTE(		  ATTRIBUTE		 ) Z_IS_TRUE(Z_CPP_HAS_ATTRIBUTE_##ATTRIBUTE				)
#define Z_CPP_HAS_IDENTIFIER(		  IDENTIFIER		 ) Z_IS_TRUE(Z_CPP_HAS_IDENTIFIER_##IDENTIFIER				)
#define Z_CPP_HAS_LITERAL(		  LITERAL		 ) Z_IS_TRUE(Z_CPP_HAS_LITERAL_##LITERAL				)
#define Z_CPP_HAS_OPERATOR(		  OPERATOR		 ) Z_IS_TRUE(Z_CPP_HAS_OPERATOR_##OPERATOR				)
#define Z_CPP_HAS_OPERATOR_CASE(	  OPERATOR, CASE	 ) Z_IS_TRUE(Z_CPP_HAS_OPERATOR_CASE_##OPERATOR##_##CASE		)
#define Z_CPP_HAS_PREPROCESSOR_IDENTIFIER(PREPROCESSOR_IDENTIFIER) Z_IS_TRUE(Z_CPP_HAS_PREPROCESSOR_IDENTIFIER_##PREPROCESSOR_IDENTIFIER)
#define Z_CPP_HAS_PREPROCESSOR_OPERATOR(  PREPROCESSOR_OPERATOR	 ) Z_IS_TRUE(Z_CPP_HAS_PREPROCESSOR_OPERATOR_##PREPROCESSOR_OPERATOR	)
#define Z_CPP_HAS_SPECIFIER(		  SPECIFIER		 ) Z_IS_TRUE(Z_CPP_HAS_SPECIFIER_##SPECIFIER				)
#define Z_CPP_HAS_SPECIFIER_CASE(	  SPECIFIER, CASE	 ) Z_IS_TRUE(Z_CPP_HAS_SPECIFIER_CASE_##SPECIFIER##_##CASE		)
#define Z_CPP_HAS_STORAGE_CLASS(	  STORAGE_CLASS		 ) Z_IS_TRUE(Z_CPP_HAS_STORAGE_CLASS_##STORAGE_CLASS			)
#define Z_CPP_HAS_TYPE(			  TYPE			 ) Z_IS_TRUE(Z_CPP_HAS_TYPE_##TYPE					)

#endif /* Z_inspection_CPP_H */
