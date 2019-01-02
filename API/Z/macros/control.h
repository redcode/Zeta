/* Z Kit - macros/control.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_control_H_
#define _Z_macros_control_H_

#include <Z/macros/pasting.h>

#define Z_IF_1(	   what) what
#define Z_IF_0(	   what)
#define Z_IF_TRUE( what) what
#define Z_IF_FALSE(what)

#define Z_IF(boolean) Z_JOIN_2(Z_IF_, boolean)

#define Z_UNLESS_1(    what)
#define Z_UNLESS_0(    what) what
#define Z_UNLESS_TRUE( what)
#define Z_UNLESS_FALSE(what) what

#define Z_UNLESS(boolean) Z_JOIN_2(Z_UNLESS_, boolean)

#define Z_TERNARY_1(	a, b) a
#define Z_TERNARY_0(	a, b) b
#define Z_TERNARY_TRUE( a, b) a
#define Z_TERNARY_FALSE(a, b) b

#define Z_TERNARY(boolean) Z_JOIN_2(Z_TERNARY_, boolean)

#endif /* _Z_macros_control_H_ */
