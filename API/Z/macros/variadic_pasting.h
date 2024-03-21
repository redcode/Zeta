/* Zeta API - Z/macros/variadic_pasting.h (C99)
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_variadic_pasting_H
#define Z_macros_variadic_pasting_H

#include <Z/macros/variadic.h>

#if	!defined(Z_AVOID_VARIADIC_MACROS) && \
	(Z_DIALECT_HAS(C99, VARIADIC_MACRO) || Z_DIALECT_HAS(CPP11, C99_PREPROCESSOR))

#	define Z_JOIN_N(n) \
		Z_PASTE_2(Z_JOIN_, n) /* Needed for Z_JOIN(...) only */

#	define Z_JOIN(...)							\
		Z_SAME(Z_JOIN_N(Z_ARGUMENT_COUNT_(__VA_ARGS__, L_PP_RSEQ_N()))) \
			(__VA_ARGS__)

#endif

#endif /* Z_macros_variadic_pasting_H */
