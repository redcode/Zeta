/* Z Kit C++ API - traits/mathematics.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_mathematics_HPP__
#define __Z_traits_mathematics_HPP__

#include <Z/types/base.h>

namespace Zeta {

	template <zuintmax N> struct Factorial {
		enum {value = N * Factorial<N - 1>::value};
	};

	template <> struct Factorial<0> {enum {value = 1};};

	template <zuintmax N> struct TriangularNumber {
		enum {value = N + TriangularNumber<N - 1>::value};
	};

	template <> struct TriangularNumber<0> {enum {value = 0};};

	template <zuintmax base, zuintmax exponent> struct NaturalPower {
		enum {value = base * NaturalPower<base, exponent - 1>::value};
	};

	template <zuintmax base> struct NaturalPower<base, 0> {enum {value = 1};};

	template <zintmax base, zuintmax exponent> struct IntegerPower {
		enum {value = base * IntegerPower<base, exponent - 1>::value};
	};

	template <zintmax base> struct IntegerPower<base, 0> {enum {value = 1};};


	template <zuintmax N> struct Logarithm2 {
		enum {value = Logarithm2<N / 2>::value + 1};
	};

	template <> struct Logarithm2<1> {enum {value = 0};};
	template <> struct Logarithm2<0> {enum {value = 0};};
}

#endif // __Z_traits_mathematics_HPP__
