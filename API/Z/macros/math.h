/* Zeta API - Z/macros/math.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_math_H
#define Z_macros_math_H

#define Z_SUM(	   a, b) ((a) + (b))
#define Z_SUBTRACT(a, b) ((a) - (b))
#define Z_MULTIPLY(a, b) ((a) * (b))
#define Z_DIVIDE(  a, b) ((a) / (b))
#define Z_MODULO(  a, b) ((a) % (b))
#define Z_MAXIMUM( a, b) ((a) > (b) ? (a) : (b))
#define Z_MINIMUM( a, b) ((a) < (b) ? (a) : (b))

#define Z_ABSOLUTE(value) \
	((value) < 0 ? -(value) : (value))

#define Z_IS_POWER_OF_2(value) \
	(!((value) & ((value) - 1)) && (value) > 1)

#define Z_NEXT_MULTIPLE(value, base) \
	((value) + (base) - ((value) % (base)))

#define Z_PREVIOUS_MULTIPLE(value, base) \
	((((value) - 1) / (base)) * (base))

#endif /* Z_macros_math_H */
