/* Z Kit C++ API - traits/SelectType.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_SelectType_HPP__
#define __Z_traits_SelectType_HPP__

#include <Z/inspection/language.h>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {

		template<unsigned int index, class T0, class... T> struct SelectType {
			typedef typename SelectType<index - 1, T...>::type type;
		};

		template<class T0, class... T> struct SelectType<0, T0, T...> {
			typedef T0 type;
		};

	}

#else

#	include <Z/macros/repetition.h>

	namespace Zeta {

		template <unsigned int,
			class T00,	  class T01 = void, class T02 = void, class T03 = void,
			class T04 = void, class T05 = void, class T06 = void, class T07 = void,
			class T08 = void, class T09 = void, class T10 = void, class T11 = void,
			class T12 = void, class T13 = void, class T14 = void, class T15 = void,
			class T16 = void, class T17 = void, class T18 = void, class T19 = void,
			class T20 = void, class T21 = void, class T22 = void, class T23 = void,
			class T24 = void, class T25 = void, class T26 = void, class T27 = void,
			class T28 = void, class T29 = void, class T30 = void, class T31 = void
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
