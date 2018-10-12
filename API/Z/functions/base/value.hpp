/* Z Kit - functions/base/value.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_base_value_HPP_
#define _Z_functions_base_value_HPP_

#include <Z/traits/Type.hpp>

namespace Zeta {


	// MARK: - Functions for any type


	template <class T> static Z_INLINE void swap(void *a, void *b)
		{
		T t = *(T *)a;
		*(T *)a = *(T *)b;
		*(T *)b = t;
		}


	// MARK: - Functions for comparable types


	template <class T> static Z_CT(CPP11) T maximum(T a, T b) {return a > b ? a : b;}
	template <class T> static Z_CT(CPP11) T minimum(T a, T b) {return a < b ? a : b;}


	template <class T> static Z_CT(CPP11) T clamp(T value, T minimum, T maximum)
		{return Zeta::minimum(Zeta::maximum(value, minimum), maximum);}


	// MARK: - Functions for signed types


	template <class T> static Z_CT(CPP11) T absolute(T value)
		{return value < T(0) ? -value : value;}


	template <class T> static Z_CT(CPP11) T sign(T value)
		{return value >= T(0) ? T(1) : -T(1);}


	// MARK: - Functions for real types


	template <class T> static Z_CT(CPP11) Boolean are_almost_equal(T a, T b)
		{return absolute(a - b) <= Type<T>::epsilon();}


	template <class T> static Z_CT(CPP11) T clamp_01(T value)
		{return minimum<T>(maximum<T>(value, T(0.0)), T(1.0));}


	template <class T> static Z_CT(CPP11) T inverse_lerp(T a, T b, T t)
		{return (t - a) / (b - a);}


	template <class T> static Z_CT(CPP11) Boolean is_almost_zero(T value)
		{return absolute<T>(value) <= Type<T>::epsilon();}


	template <class T> static Z_CT(CPP11) Boolean is_finite(T value)
		{return value == value && value != Type<T>::infinity() && value != -Type<T>::infinity();}


	template <class T> static Z_CT(CPP11) Boolean is_infinity(T value)
		{return value == Type<T>::infinity() || value == -Type<T>::infinity();}


	template <class T> static Z_CT(CPP11) Boolean is_nan(T value)
		{return !(value == value);}


	template <class T> static Z_CT(CPP11) T lerp(T a, T b, T t)
		{return a + t * (b - a);}


	template <class T> static Z_CT(CPP11) T sign_or_zero(T value)
		{
		return absolute<T>(value) <= Type<T>::epsilon()
			? T(0.0)
			: sign<T>(value);
		}


	template <class T> static Z_CT(CPP14) T smootherstep(T a, T b, T t)
		{
		if (t <= a) return T(0.0);
		if (t >= b) return T(1.0);
		t = (t - a) / (b - a);
		return t * t * t * (t * (t * T(6.0) - T(15.0)) + T(10.0));
		}


	template <class T> static Z_CT(CPP14) T smoothstep(T a, T b, T t)
		{
		if (t <= a) return T(0.0);
		if (t >= b) return T(1.0);
		t = (t - a) / (b - a);
		return t * t * (T(3.0) - T(2.0) * t);
		}


}

#endif // _Z_functions_base_value_HPP_
