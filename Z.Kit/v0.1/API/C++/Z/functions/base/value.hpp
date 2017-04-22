/* Z Kit C++ API - functions/base/value.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_value_HPP__
#define __Z_functions_base_value_HPP__

#include <Z/traits/Type.hpp>
#include <Z/traits/filtering.hpp>

namespace Zeta {


	// MARK: - Functions for any type


	template <class T> Z_INLINE void swap(T *a, T *b)
		{
		T t = *a;
		*a = *b;
		*b = t;
		}


	// MARK: - Functions for comparable types


	template <class T> Z_CONSTANT(CPP11) T maximum(T a, T b) {return a > b ? a : b;}
	template <class T> Z_CONSTANT(CPP11) T minimum(T a, T b) {return a < b ? a : b;}


	template <class T> Z_CONSTANT(CPP11) T clamp(T value, T minimum, T maximum)
		{return Zeta::minimum(Zeta::maximum(value, minimum), maximum);}


	// MARK: - Functions for integer and real types


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_signed, T>::type
	absolute(T value)
		{return value < T(0) ? -value : value;}


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_signed, T>::type
	sign(T value)
		{return value >= T(0) ? T(1) : -T(1);}


	// MARK: - Functions for real types only


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_real, Boolean>::type
	are_almost_equal(T a, T b)
		{return absolute(a - b) <= Type<T>::epsilon();}


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_real, T>::type
	clamp_01(T value)
		{return minimum<T>(maximum<T>(value, T(0.0)), T(1.0));}


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_real, T>::type
	inverse_lerp(T a, T b, T t)
		{return (t - a) / (b - a);}


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_real, Boolean>::type
	is_almost_zero(T value)
		{return absolute<T>(value) <= Type<T>::epsilon();}


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_real, Boolean>::type
	is_finite(T value)
		{return value == value && value != Type<T>::infinity() && value != -Type<T>::infinity();}


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_real, Boolean>::type
	is_infinity(T value)
		{return value == Type<T>::infinity() || value == -Type<T>::infinity();}


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_real, Boolean>::type
	is_nan(T value)
		{return !(value == value);}


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_real, T>::type
	lerp(T a, T b, T t)
		{return a + t * (b - a);}


	template <class T> Z_CONSTANT(CPP11) typename EnableIf<Type<T>::is_real, T>::type
	sign_or_zero(T value)
		{
		return absolute<T>(value) <= Type<T>::epsilon()
			? T(0.0)
			: sign<T>(value);
		}


	template <class T> Z_CONSTANT(CPP14) typename EnableIf<Type<T>::is_real, T>::type
	smootherstep(T a, T b, T t)
		{
		if (t <= a) return T(0.0);
		if (t >= b) return T(1.0);
		t = (t - a) / (b - a);
		return t * t * t * (t * (t * T(6.0) - T(15.0)) + T(10.0));
		}


	template <class T> Z_CONSTANT(CPP14) typename EnableIf<Type<T>::is_real, T>::type
	smoothstep(T a, T b, T t)
		{
		if (t <= a) return T(0.0);
		if (t >= b) return T(1.0);
		t = (t - a) / (b - a);
		return t * t * (T(3.0) - T(2.0) * t);
		}


}

#endif // __Z_functions_base_value_HPP__
