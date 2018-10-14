/* Z Kit - macros/variadic pasting.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_variadic_pasting_H_
#define _Z_macros_variadic_pasting_H_

#include <Z/macros/variadic.h>

#if	!defined(Z_AVOID_VARIADIC_MACROS) && \
	(Z_LANGUAGE_HAS(C, VARIADIC_MACRO) || Z_LANGUAGE_HAS(CPP, C99_PREPROCESSOR))

#	define Z_JOIN_N(n) Z_PASTE_2(Z_JOIN_, n) /* Needed for Z_JOIN(...) only */
#	define Z_JOIN(...) Z_SAME(Z_JOIN_N(Z_ARGUMENT_COUNT_(__VA_ARGS__, L_PP_RSEQ_N())))(__VA_ARGS__)

#endif

#endif /* _Z_macros_variadic_pasting_H_ */
