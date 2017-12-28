/* Z Kit C++ API - traits/SelectType.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_SelectType_HPP__
#define __Z_traits_SelectType_HPP__

#include <Z/types/base.hpp>
#include <Z/traits/base.hpp>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {

		template<UInt I, class T0 = NaT, class... T> struct SelectType {
			typedef typename SelectType<I - 1, T...>::type type;
		};

		template<class T0, class... T> struct SelectType<0, T0, T...> {
			typedef T0 type;
		};

#		if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)
			template<UInt I, class... T>
			using select_type = typename SelectType<I, T...>::type;
#		endif
	}

#else

#	include <Z/macros/repetition.h>

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

#		define Z_TEMPLATE_SPECIALIZATION(type_count, index)		       \
		template <Z_ENUMERATE_APPENDING_INDEX(type_count, class T)>	       \
		struct SelectType<index, Z_ENUMERATE_APPENDING_INDEX(type_count, T)> { \
			typedef T##index type;					       \
		};

#		define Z_TEMPLATE_SPECIALIZATION_GROUP(type_count) \
		Z_FOR_##type_count##_CALL_WITH_TOKEN_AND_INDEX(Z_TEMPLATE_SPECIALIZATION, type_count,)

		Z_FOR_32_CALL_WITH_INDEX(Z_TEMPLATE_SPECIALIZATION_GROUP,)

#		undef Z_TEMPLATE_SPECIALIZATION_GROUP
#		undef Z_TEMPLATE_SPECIALIZATION
	}

#endif

#endif // __Z_traits_SelectType_HPP__
