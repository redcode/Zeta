/* Z Kit C API - macros/variadic pasting.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_variadic_pasting_H__
#define __Z_macros_variadic_pasting_H__

#include <Z/macros/variadic.h>

#if !defined(Z_AVOID_VARIADIC_MACROS) && Z_LANGUAGE_HAS(C, VARIADIC_MACRO)

#	define Z_JOIN_N(n) Z_PASTE_2(Z_JOIN_, n) /* Needed for Z_JOIN(...) only */
#	define Z_JOIN(...) Z_SAME(Z_JOIN_N(Z_ARGUMENT_COUNT_(__VA_ARGS__, L_PP_RSEQ_N())))(__VA_ARGS__)

#endif

#endif /* __Z_macros_variadic_pasting_H__ */
