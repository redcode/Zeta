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

	namespace Zeta {

		struct Template {

			template<class C, class... more> struct PrependType;

			template<template<class...> class C, class... T, class... more>
			struct PrependType<C<T...>, more...> {
				typedef C<more..., T...> type;
			};

			template<class C, class... more> struct AppendType;

			template<template<class...> class C, class... T, class... more>
			struct AppendType<C<T...>, more...> {
				typedef C<T..., more...> type;
			};

			template <class C, unsigned int I> struct Remove;

			template <template<class...> class C, class T0, class... T>
			struct Remove<C<T0, T...>, 0> {
				typedef C<T...> type;
			};

			template <template<class...> class C, class T0, class... T, unsigned int I>
			struct Remove<C<T0, T...>, I> {
				typedef typename PrependType<typename Remove<C<T...>, I - 1>::type, T0>::type type;
			};

			template<class C> struct RemoveFirst;

			template<template<class...> class C, class T0, class... T>
			struct RemoveFirst<C<T0, T...> > {
				typedef C<T...> type;
			};

			template<template<class...> class C>
			struct RemoveFirst<C<> > {
				typedef C<> type;
			};

			template<class C> struct RemoveLast;

			template<template<class...> class C, class... T>
			struct RemoveLast<C<T...> > {
				typedef typename Remove<C<T...>, sizeof...(T) - 1>::type type;
			};

			template<template<class...> class C>
			struct RemoveLast<C<> > {
				typedef C<> type;
			};

			template<class from, template<class...> class to> struct Rename;

			template<template<class...> class from, class... T, template<class...> class to>
			struct Rename<from<T...>, to> {
				typedef to<T...> type;
			};

#			if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

				template<class C, class... more>
				using prepend_type = typename PrependType<C, more...>::type;

				template<class C, class... more>
				using append_type = typename AppendType<C, more...>::type;

				template<class C>
				using remove_first = typename RemoveFirst<C>::type;

				template<class C>
				using remove_last = typename RemoveLast<C>::type;

				template<class C, unsigned int I>
				using remove = typename Remove<C, I>::type;

				template<class from, template<class...> class to>
				using rename = typename Rename<from, to>::type;

#			endif
		};
	}

#endif

#endif // __Z_traits_Template_HPP__
