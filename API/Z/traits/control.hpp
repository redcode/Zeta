/* Zeta API - Z/traits/control.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_traits_control_HPP
#define Z_traits_control_HPP

#include <Z/inspection/Z.h>
#include <Z/types/integral.hpp>
#include <Z/classes/NaT.hpp>

#if Z_DIALECT_HAS(CPP98, SFINAE)
#	define Z_HAS_TypeIf 1

#	if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
#		define Z_HAS_type_if 1
#	endif
#endif

#if Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE) && Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
#	define Z_HAS_select_type 1
#endif

namespace Zeta {
	template <Boolean condition, class if_true, class if_false> struct TernaryType;

	template <class t, class f> struct TernaryType<true,  t, f> {typedef t type;};
	template <class t, class f> struct TernaryType<false, t, f> {typedef f type;};

#	if Z_HAS(TypeIf)
		template <Boolean condition, class t = void> struct TypeIf {};

		template <class t> struct TypeIf<true, t> {typedef t type;};

#		if Z_HAS(type_if)
			template <Boolean condition, class t = void>
			using type_if = typename TypeIf<condition, t>::type;
#		endif
#	endif
}

#if Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE)
	namespace Zeta {
#		if Z_COMPILER_HAS_TRAIT(SELECT_TYPE)
			template <UInt index, class... t> struct SelectType {
				typedef Z_COMPILER_TRAIT(SELECT_TYPE)(index, t...) type;
			};

#			if Z_HAS(select_type)
				template <UInt index, class... t>
				using select_type = Z_COMPILER_TRAIT(SELECT_TYPE)(index, t...);
#			endif

#		else
			template <UInt index, class t0 = NaT, class... t> struct SelectType {
				typedef typename SelectType<index - 1, t...>::type type;
			};

			template <class t0, class... t> struct SelectType<0, t0, t...> {
				typedef t0 type;
			};

#			if Z_HAS(select_type)
				template <UInt index, class... t>
				using select_type = typename SelectType<index, t...>::type;
#			endif
#		endif
	}

#else
#	include <Z/macros/iteration.h>

	namespace Zeta {
		template <UInt index,
			class t00 = NaT, class t01 = NaT, class t02 = NaT, class t03 = NaT,
			class t04 = NaT, class t05 = NaT, class t06 = NaT, class t07 = NaT,
			class t08 = NaT, class t09 = NaT, class t10 = NaT, class t11 = NaT,
			class t12 = NaT, class t13 = NaT, class t14 = NaT, class t15 = NaT,
			class t16 = NaT, class t17 = NaT, class t18 = NaT, class t19 = NaT,
			class t20 = NaT, class t21 = NaT, class t22 = NaT, class t23 = NaT,
			class t24 = NaT, class t25 = NaT, class t26 = NaT, class t27 = NaT,
			class t28 = NaT, class t29 = NaT, class t30 = NaT, class t31 = NaT
		> struct SelectType {};

#		define Z_z_SPECIALIZATION(type_count, index)					  \
			template <Z_APPEND_INDEX_FOR_##type_count(class t, Z_COMMA)>		  \
			struct SelectType<index, Z_APPEND_INDEX_FOR_##type_count(t, Z_COMMA)> { \
				typedef t##index type;						  \
			};

#		define Z_z_SPECIALIZATION_GROUP(type_count) \
			Z_CALL_WITH_TOKEN_AND_INDEX_FOR_##type_count(Z_z_SPECIALIZATION, type_count, Z_EMPTY)

		Z_CALL_WITH_INDEX_FOR_32(Z_z_SPECIALIZATION_GROUP, Z_EMPTY)

#		undef Z_z_SPECIALIZATION
#		undef Z_z_SPECIALIZATION_GROUP
	}
#endif

#endif // Z_traits_control_HPP
