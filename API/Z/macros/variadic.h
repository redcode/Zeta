/* Zeta API - Z/macros/variadic.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006 Laurent Deniau <laurent.deniau@cern.ch>.
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_variadic_H
#define Z_macros_variadic_H

#include <Z/inspection/language.h>

#if	!defined(Z_AVOID_VARIADIC_MACROS) && \
	(Z_DIALECT_HAS(C99, VARIADIC_MACRO) || Z_DIALECT_HAS(CPP11, C99_PREPROCESSOR))

#	include <Z/macros/token.h>

#	define L_PP_ARG_N( \
		 _1,  _2,  _3,	_4,  _5,  _6,  _7,  _8, \
		 _9, _10, _11, _12, _13, _14, _15, _16, \
		_17, _18, _19, _20, _21, _22, _23, _24, \
		_25, _26, _27, _28, _29, _30, _31, _32, \
		_33, _34, _35, _36, _37, _38, _39, _40, \
		_41, _42, _43, _44, _45, _46, _47, _48, \
		_49, _50, _51, _52, _53, _54, _55, _56, \
		_57, _58, _59, _60, _61, _62, _63,   n, \
		... \
	) n

#	define L_PP_RSEQ_N() \
		63, 62, 61, 60, 59, 58, 57, 56, \
		55, 54, 53, 52, 51, 50, 49, 48, \
		47, 46, 45, 44, 43, 42, 41, 40, \
		39, 38, 37, 36, 35, 34, 33, 32, \
		31, 30, 29, 28, 27, 26, 25, 24, \
		23, 22, 21, 20, 19, 18, 17, 16, \
		15, 14, 13, 12, 11, 10,  9,  8, \
		 7,  6,  5,  4,  3,  2,  1,  0

#	define Z_z_ARGUMENT_COUNT(...) \
		Z_SAME(L_PP_ARG_N(__VA_ARGS__))

#	define Z_ARGUMENT_COUNT(...) \
		Z_z_ARGUMENT_COUNT(__VA_ARGS__, L_PP_RSEQ_N())

#endif

#endif /* Z_macros_variadic_H */
