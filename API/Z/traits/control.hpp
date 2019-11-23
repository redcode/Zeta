/* Z Kit - traits/control.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_traits_control_HPP
#define Z_traits_control_HPP

#include <Z/inspection/Z.h>
#include <Z/types/fundamental.hpp>
#include <Z/classes/NaT.hpp>

#if Z_DIALECT_HAS(CPP, SFINAE)
#	define Z_DECLARES_TypeIf TRUE
#else
#	define Z_DECLARES_TypeIf FALSE
#endif

#if Z_DIALECT_HAS(CPP, SFINAE) && Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE)
#	define Z_DECLARES_type_if TRUE
#else
#	define Z_DECLARES_type_if FALSE
#endif

#if Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE) && Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE)
#	define Z_DECLARES_select_type TRUE
#else
#	define Z_DECLARES_select_type FALSE
#endif

namespace Zeta {

#	if Z_DECLARES(TypeIf)

		template <Boolean B, class T = void> struct TypeIf {};

		template <class T> struct TypeIf<true, T> {typedef T type;};

#		if Z_DECLARES(type_if)
			template <Boolean B, class T = void> using type_if = typename TypeIf<B, T>::type;
#		endif

#	endif

	template <Boolean condition, class if_true, class if_false> struct TernaryType;

	template <class A, class B> struct TernaryType<true,  A, B> {typedef A type;};
	template <class A, class B> struct TernaryType<false, A, B> {typedef B type;};
}

#if Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {

#		if Z_COMPILER_HAS_TRAIT(SELECT_TYPE)

			template <UInt I, class... T> struct SelectType {
				typedef Z_COMPILER_TRAIT(SELECT_TYPE)(I, T...) type;
			};

#			if Z_DECLARES(select_type)
				template <UInt I, class... T> using select_type = Z_COMPILER_TRAIT(SELECT_TYPE)(I, T...);
#			endif
#		else
			template <UInt I, class T0 = NaT, class... T> struct SelectType {
				typedef typename SelectType<I - 1, T...>::type type;
			};

			template <class T0, class... T> struct SelectType<0, T0, T...> {
				typedef T0 type;
			};

#			if Z_DECLARES(select_type)
				template <UInt I, class... T> using select_type = typename SelectType<I, T...>::type;
#			endif
#		endif
	}

#else

#	include <Z/macros/repetition.h>
#	include <Z/macros/tokens.h>

	namespace Zeta {

		template <UInt,
			class T00 = NaT, class T01 = NaT, class T02 = NaT, class T03 = NaT,
			class T04 = NaT, class T05 = NaT, class T06 = NaT, class T07 = NaT,
			class T08 = NaT, class T09 = NaT, class T10 = NaT, class T11 = NaT,
			class T12 = NaT, class T13 = NaT, class T14 = NaT, class T15 = NaT,
			class T16 = NaT, class T17 = NaT, class T18 = NaT, class T19 = NaT,
			class T20 = NaT, class T21 = NaT, class T22 = NaT, class T23 = NaT,
			class T24 = NaT, class T25 = NaT, class T26 = NaT, class T27 = NaT,
			class T28 = NaT, class T29 = NaT, class T30 = NaT, class T31 = NaT
		> struct SelectType {};

#		define Z_IMPLEMENTATION(type_count, index)				  \
		template <Z_FOR_##type_count##_APPEND_INDEX(class T, Z_COMMA)>		  \
		struct SelectType<index, Z_FOR_##type_count##_APPEND_INDEX(T, Z_COMMA)> { \
			typedef T##index type;						  \
		};

#		define Z_IMPLEMENTATION__GROUP(type_count) \
		Z_FOR_##type_count##_CALL_WITH_TOKEN_AND_INDEX(Z_IMPLEMENTATION, type_count, Z_EMPTY)

		Z_FOR_32_CALL_WITH_INDEX(Z_IMPLEMENTATION__GROUP, Z_EMPTY)

#		undef Z_IMPLEMENTATION
#		undef Z_IMPLEMENTATION__GROUP

	}

#endif

#endif // Z_traits_control_HPP
