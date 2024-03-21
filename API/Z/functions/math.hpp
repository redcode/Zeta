/* Zeta API - Z/functions/math.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_math_HPP
#define Z_functions_math_HPP

#include <Z/traits/type.hpp>


namespace Zeta {

	template <class t>
	static Z_CT(CPP11) t maximum(t a, t b) Z_NOTHROW
		{return a > b ? a : b;}


	template <class t>
	static Z_CT(CPP11) t minimum(t a, t b) Z_NOTHROW
		{return a < b ? a : b;}


	template <class t>
	static Z_CT(CPP11) t clamp(t value, t minimum, t maximum) Z_NOTHROW
		{return Zeta::minimum(Zeta::maximum(value, minimum), maximum);}


	// MARK: - Functions for signed types


	template <class t>
	static Z_CT(CPP11) t absolute(t value) Z_NOTHROW
		{return value < t(0) ? -value : value;}


	template <class t>
	static Z_CT(CPP11) t sign(t value) Z_NOTHROW
		{return value >= t(0) ? t(1) : -t(1);}


	// MARK: - Functions for real types


	template <class t>
	static Z_CT(CPP11) Boolean are_almost_equal(t a, t b) Z_NOTHROW
		{return absolute(a - b) <= Type<t>::epsilon();}


	template <class t>
	static Z_CT(CPP11) t clamp_01(t value) Z_NOTHROW
		{return minimum<t>(maximum<t>(value, t(0.0)), t(1.0));}


	template <class t>
	static Z_CT(CPP11) t inverse_lerp(t a, t b, t x) Z_NOTHROW
		{return (x - a) / (b - a);}


	template <class t>
	static Z_CT(CPP11) Boolean is_almost_zero(t value) Z_NOTHROW
		{return absolute<t>(value) <= Type<t>::epsilon();}


	template <class t>
	static Z_CT(CPP11) Boolean is_finite(t value) Z_NOTHROW
		{
		return	value ==  value		      &&
			value !=  Type<t>::infinity() &&
			value != -Type<t>::infinity();
		}


	template <class t>
	static Z_CT(CPP11) Boolean is_infinity(t value) Z_NOTHROW
		{
		return	value ==  Type<t>::infinity() ||
			value == -Type<t>::infinity();}


	template <class t>
	static Z_CT(CPP11) Boolean is_nan(t value) Z_NOTHROW
		{return !(value == value);}


	template <class t>
	static Z_CT(CPP11) t lerp(t a, t b, t x) Z_NOTHROW
		{return a + x * (b - a);}


	template <class t>
	static Z_CT(CPP11) t sign_or_zero(t value) Z_NOTHROW
		{
		return absolute<t>(value) <= Type<t>::epsilon()
			? t(0.0)
			: sign<t>(value);
		}


	template <class t>
	static Z_CT(CPP14) t smootherstep(t a, t b, t x) Z_NOTHROW
		{
		if (x <= a) return t(0.0);
		if (x >= b) return t(1.0);
		x = (x - a) / (b - a);
		return x * x * x * (x * (x * t(6.0) - t(15.0)) + t(10.0));
		}


	template <class t>
	static Z_CT(CPP14) t smoothstep(t a, t b, t x) Z_NOTHROW
		{
		if (x <= a) return t(0.0);
		if (x >= b) return t(1.0);
		x = (x - a) / (b - a);
		return x * x * (t(3.0) - t(2.0) * x);
		}
}


#endif // Z_functions_math_HPP
