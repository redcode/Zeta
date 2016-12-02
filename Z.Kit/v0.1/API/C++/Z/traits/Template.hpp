/* Z Kit C++ API - traits/Template.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_Template_HPP__
#define __Z_traits_Template_HPP__

#include <Z/traits/SelectType.hpp>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)

	namespace Zeta {struct Template;}

	struct Zeta::Template {

		template<class C, class... A> struct PrependType;

		template<template<class...> class C, class... A, class... T>
		struct PrependType<C<A...>, T...> {
			typedef C<T..., A...> type;
		};

		template<class C, class... T> struct AppendType;

		template<template<class...> class C, class... A, class... T>
		struct AppendType<C<A...>, T...> {
			typedef C<A..., T...> type;
		};

		template <class C, unsigned int I> struct Remove;

		template <template<class...> class C, class A0, class... A>
		struct Remove<C<A0, A...>, 0> {
			typedef C<A...> type;
		};

		template <template<class...> class C, class A0, class... A, unsigned int I>
		struct Remove<C<A0, A...>, I> {
			typedef typename PrependType<typename Remove<C<A...>, I - 1>::type, A0>::type type;
		};

		template<class C> struct RemoveFirst;

		template<template<class...> class C, class A0, class... A>
		struct RemoveFirst<C<A0, A...> > {
			typedef C<A...> type;
		};

		template<template<class...> class C>
		struct RemoveFirst<C<> > {
			typedef C<> type;
		};

		template<class C> struct RemoveLast;

		template<template<class...> class C, class... A>
		struct RemoveLast<C<A...> > {
			typedef typename Remove<C<A...>, sizeof...(A) - 1>::type type;
		};

		template<template<class...> class C>
		struct RemoveLast<C<> > {
			typedef C<> type;
		};

		template<class from, template<class...> class to> struct Rename;

		template<template<class...> class from, class... A, template<class...> class to>
		struct Rename<from<A...>, to> {
			typedef to<A...> type;
		};

#		if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

			template<class C, class... T>
			using prepend_type = typename PrependType<C, T...>::type;

			template<class C, class... T>
			using append_type = typename AppendType<C, T...>::type;

			template<class C>
			using remove_first = typename RemoveFirst<C>::type;

			template<class C>
			using remove_last = typename RemoveLast<C>::type;

			template<class C, unsigned int I>
			using remove = typename Remove<C, I>::type;

			template<class from, template<class...> class to>
			using rename = typename Rename<from, to>::type;

#		endif
	};

#endif

#endif // __Z_traits_Template_HPP__
