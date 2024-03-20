/* Zeta API - Z/traits/TypeCount.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_traits_TypeCount_HPP
#define Z_traits_TypeCount_HPP

#include <Z/inspection/language.h>

#if	Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE) && \
	Z_DIALECT_HAS_OPERATOR_CASE(CPP11, SIZEOF, PARAMETER_PACK)

	namespace Zeta {template <class... t> struct TypeCount {
		enum {value = sizeof...(t)};
	};}

#else
#	include <Z/classes/NaT.hpp>
#	include <Z/macros/iteration.h>

	namespace Zeta {
		template <
			class t00 = NaT, class t01 = NaT, class t02 = NaT, class t03 = NaT,
			class t04 = NaT, class t05 = NaT, class t06 = NaT, class t07 = NaT,
			class t08 = NaT, class t09 = NaT, class t10 = NaT, class t11 = NaT,
			class t12 = NaT, class t13 = NaT, class t14 = NaT, class t15 = NaT,
			class t16 = NaT, class t17 = NaT, class t18 = NaT, class t19 = NaT,
			class t20 = NaT, class t21 = NaT, class t22 = NaT, class t23 = NaT,
			class t24 = NaT, class t25 = NaT, class t26 = NaT, class t27 = NaT,
			class t28 = NaT, class t29 = NaT, class t30 = NaT, class t31 = NaT
		> struct TypeCount {};

#		define Z_z_SPECIALIZATION(arity)				   \
			template <Z_APPEND_INDEX_FOR_##arity(class t, Z_COMMA)>    \
			struct TypeCount<Z_APPEND_INDEX_FOR_##arity(t, Z_COMMA)> { \
				enum {value = arity};				   \
			};

		Z_CALL_WITH_INDEX_FOR_32(Z_z_SPECIALIZATION, Z_EMPTY)
#		undef Z_z_SPECIALIZATION
	}
#endif

#endif // Z_traits_TypeCount_HPP
