/* Z Kit - traits/TypeCount.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_traits_TypeCount_HPP_
#define _Z_traits_TypeCount_HPP_

#include <Z/inspection/language.h>

#if	Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE) && \
	Z_LANGUAGE_HAS_OPERATOR(CPP, SIZE_OF_PARAMETER_PACK)

	namespace Zeta {template <class... T> struct TypeCount {
		enum {value = sizeof...(T)};
	};}

#else

#	include <Z/types/base.hpp>
#	include <Z/macros/repetition.h>
#	include <Z/macros/tokens.h>

	namespace Zeta {

		template <
			class T00 = NaT, class T01 = NaT, class T02 = NaT, class T03 = NaT,
			class T04 = NaT, class T05 = NaT, class T06 = NaT, class T07 = NaT,
			class T08 = NaT, class T09 = NaT, class T10 = NaT, class T11 = NaT,
			class T12 = NaT, class T13 = NaT, class T14 = NaT, class T15 = NaT,
			class T16 = NaT, class T17 = NaT, class T18 = NaT, class T19 = NaT,
			class T20 = NaT, class T21 = NaT, class T22 = NaT, class T23 = NaT,
			class T24 = NaT, class T25 = NaT, class T26 = NaT, class T27 = NaT,
			class T28 = NaT, class T29 = NaT, class T30 = NaT, class T31 = NaT
		> struct TypeCount {};

#		define Z_TEMPLATE_SPECIALIZATION(parameter_count)		       \
		template <Z_FOR_##parameter_count##_APPEND_INDEX(class T, Z_COMMA)>    \
		struct TypeCount<Z_FOR_##parameter_count##_APPEND_INDEX(T, Z_COMMA)> { \
			enum {value = parameter_count};				       \
		};

		Z_FOR_32_CALL_WITH_INDEX(Z_TEMPLATE_SPECIALIZATION, Z_EMPTY)
#		undef Z_TEMPLATE_SPECIALIZATION

	}

#endif

#endif // _Z_traits_TypeCount_HPP_
