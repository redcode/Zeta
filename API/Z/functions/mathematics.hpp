/* Z Kit - functions/mathematics.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_mathematics_HPP
#define Z_functions_mathematics_HPP

#include <Z/traits/Type.hpp>

namespace Zeta {


	// MARK: - Functions for comparable types


	template <class T>
	static Z_CT(CPP11) T maximum(T a, T b) Z_NOTHROW
		{return a > b ? a : b;}


	template <class T>
	static Z_CT(CPP11) T minimum(T a, T b) Z_NOTHROW
		{return a < b ? a : b;}


	template <class T>
	static Z_CT(CPP11) T clamp(T value, T minimum, T maximum) Z_NOTHROW
		{return Zeta::minimum(Zeta::maximum(value, minimum), maximum);}


	// MARK: - Functions for signed types


	template <class T>
	static Z_CT(CPP11) T absolute(T value) Z_NOTHROW
		{return value < T(0) ? -value : value;}


	template <class T>
	static Z_CT(CPP11) T sign(T value) Z_NOTHROW
		{return value >= T(0) ? T(1) : -T(1);}


	// MARK: - Functions for real types


	template <class T>
	static Z_CT(CPP11) Boolean are_almost_equal(T a, T b) Z_NOTHROW
		{return absolute(a - b) <= Type<T>::epsilon();}


	template <class T>
	static Z_CT(CPP11) T clamp_01(T value) Z_NOTHROW
		{return minimum<T>(maximum<T>(value, T(0.0)), T(1.0));}


	template <class T>
	static Z_CT(CPP11) T inverse_lerp(T a, T b, T t) Z_NOTHROW
		{return (t - a) / (b - a);}


	template <class T>
	static Z_CT(CPP11) Boolean is_almost_zero(T value) Z_NOTHROW
		{return absolute<T>(value) <= Type<T>::epsilon();}


	template <class T>
	static Z_CT(CPP11) Boolean is_finite(T value) Z_NOTHROW
		{
		return	value ==  value		      &&
			value !=  Type<T>::infinity() &&
			value != -Type<T>::infinity();
		}


	template <class T>
	static Z_CT(CPP11) Boolean is_infinity(T value) Z_NOTHROW
		{
		return	value ==  Type<T>::infinity() ||
			value == -Type<T>::infinity();}


	template <class T>
	static Z_CT(CPP11) Boolean is_nan(T value) Z_NOTHROW
		{return !(value == value);}


	template <class T>
	static Z_CT(CPP11) T lerp(T a, T b, T t) Z_NOTHROW
		{return a + t * (b - a);}


	template <class T>
	static Z_CT(CPP11) T sign_or_zero(T value) Z_NOTHROW
		{
		return absolute<T>(value) <= Type<T>::epsilon()
			? T(0.0)
			: sign<T>(value);
		}


	template <class T>
	static Z_CT(CPP14) T smootherstep(T a, T b, T t) Z_NOTHROW
		{
		if (t <= a) return T(0.0);
		if (t >= b) return T(1.0);
		t = (t - a) / (b - a);
		return t * t * t * (t * (t * T(6.0) - T(15.0)) + T(10.0));
		}


	template <class T>
	static Z_CT(CPP14) T smoothstep(T a, T b, T t) Z_NOTHROW
		{
		if (t <= a) return T(0.0);
		if (t >= b) return T(1.0);
		t = (t - a) / (b - a);
		return t * t * (T(3.0) - T(2.0) * t);
		}


}

#endif // Z_functions_mathematics_HPP
