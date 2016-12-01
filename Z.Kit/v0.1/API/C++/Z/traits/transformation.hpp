/* Z Kit C++ API - traits/transformation.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_transformation_HPP__
#define __Z_traits_transformation_HPP__

#include <Z/inspection/language.h>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {

		template<class T, class... more> struct AppendType;

		template<template<class...> class T, class... A, class... more>
		struct AppendType<T<A...>, more...> {
			typedef T<A..., more...> type;
		};

		template<class T, class... more> struct PrependType;

		template<template<class...> class T, class... A, class... more>
		struct PrependType<T<A...>, more...> {
			typedef T<more..., A...> type;
		};

		template<class from, template<class...> class to> struct Rename;

		template<template<class...> class from, class... A, template<class...> class to>
		struct Rename<from<A...>, to> {
			typedef to<A...> type;
		};

#		if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

			template<class T, class... more>
			using append_type = typename AppendType <T, more...>::type;

			template<class T, class... more>
			using prepend_type = typename PrependType<T, more...>::type;

			template<class from, template<class...> class to>
			using rename = typename Rename<from, to>::type;

#		endif
	}

#endif

#endif // __Z_traits_transformation_HPP__
