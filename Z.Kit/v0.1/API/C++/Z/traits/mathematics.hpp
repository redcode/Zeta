/* Z Kit C++ API - traits/mathematics.hpp
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_mathematics_HPP__
#define __Z_traits_mathematics_HPP__

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

	template <IntMax base, UIntMax exponent> struct IntegerPower {
		enum {value = base * IntegerPower<base, exponent - 1>::value};
	};

	template <IntMax base> struct IntegerPower<base, 0> {enum {value = 1};};


	template <UIntMax N> struct Logarithm2 {
		enum {value = Logarithm2<N / 2>::value + 1};
	};

	template <> struct Logarithm2<1> {enum {value = 0};};
	template <> struct Logarithm2<0> {enum {value = 0};};
}

#endif // __Z_traits_mathematics_HPP__
