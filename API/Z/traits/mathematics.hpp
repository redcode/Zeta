/* Z Kit - traits/mathematics.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_traits_mathematics_HPP_
#define _Z_traits_mathematics_HPP_

#include <Z/types/base.hpp>

namespace Zeta {

	template <UIntMax N> struct Factorial {
		enum {value = N * Factorial<N - 1>::value};
	};

	template <> struct Factorial<0> {enum {value = 1};};

	template <UIntMax N> struct TriangularNumber {
		enum {value = N + TriangularNumber<N - 1>::value};
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


	template <UIntMax N> struct Logarithm2 {
		enum {value = Logarithm2<N / 2>::value + 1};
	};

	template <> struct Logarithm2<1> {enum {value = 0};};
	template <> struct Logarithm2<0> {enum {value = 0};};
}

#endif // _Z_traits_mathematics_HPP_
