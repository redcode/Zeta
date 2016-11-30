/* Z Kit C++ API - traits/Rename.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_Rename_HPP__
#define __Z_traits_Rename_HPP__

#include <Z/inspection/language.h>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)

	namespace Zeta {

		template<class from, template<class...> class to> struct Rename;

		template<template<class...> class from, class... T, template<class...> class to>
		struct Rename<from<T...>, to> {
			typedef to<T...> type;
		};

#		if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)
			template<class from, template<class...> class to>
			using rename = typename Rename<from, to>::type;
#		endif
	}

#endif

#endif // __Z_traits_Rename_HPP__
