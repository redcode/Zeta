/* Zeta API - Z/traits/math.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_traits_math_HPP
#define Z_traits_math_HPP

#include <Z/types/integral.hpp>

namespace Zeta {
	template <UIntMax n> struct Factorial {
		enum {value = n * Factorial<n - 1>::value};
	};

	template <> struct Factorial<0> {enum {value = 1};};

	template <UIntMax n> struct TriangularNumber {
		enum {value = n + TriangularNumber<n - 1>::value};
	};

	template <> struct TriangularNumber<0> {enum {value = 0};};

	template <UIntMax base, UIntMax exponent> struct NaturalPower {
		enum {value = base * NaturalPower<base, exponent - 1>::value};
	};

	template <UIntMax base> struct NaturalPower<base, 0> {enum {value = 1};};

	template <SIntMax base, UIntMax exponent> struct IntegerPower {
		enum {value = base * IntegerPower<base, exponent - 1>::value};
	};

	template <SIntMax base> struct IntegerPower<base, 0> {enum {value = 1};};


	template <UIntMax n> struct Logarithm2 {
		enum {value = Logarithm2<n / 2>::value + 1};
	};

	template <> struct Logarithm2<1> {enum {value = 0};};
	template <> struct Logarithm2<0> {enum {value = 0};};
}

#endif // Z_traits_math_HPP
