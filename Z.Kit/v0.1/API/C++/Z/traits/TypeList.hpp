/* Z Kit C++ API - traits/TypeList.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_TypeList_HPP__
#define __Z_traits_TypeList_HPP__

#include <Z/traits/SelectType.hpp>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {

		template <class from, template <class...> class to> struct TypeListRename;

		template <template <class...> class from, class... A, template <class...> class to>
		struct TypeListRename<from<A...>, to> {
			typedef to<A...> type;
		};

		template <class L, class... A> struct TypeListPrepend;

		template <template <class...> class L, class... A, class... T>
		struct TypeListPrepend<L<A...>, T...> {
			typedef L<T..., A...> type;
		};

		template <class L, class... T> struct TypeListAppend;

		template <template <class...> class L, class... A, class... T>
		struct TypeListAppend<L<A...>, T...> {
			typedef L<A..., T...> type;
		};

		template <class L, unsigned int I> struct TypeListRemove;

		template <template <class...> class L, class A0, class... A>
		struct TypeListRemove<L<A0, A...>, 0> {
			typedef L<A...> type;
		};

		template <template <class...> class L, class A0, class... A, unsigned int I>
		struct TypeListRemove<L<A0, A...>, I> {
			typedef typename TypeListPrepend<typename TypeListRemove<L<A...>, I - 1>::type, A0>::type type;
		};

		template <class L> struct TypeListRemoveFirst;

		template <template <class...> class L, class A0, class... A>
		struct TypeListRemoveFirst<L<A0, A...> > {
			typedef L<A...> type;
		};

		template <template <class...> class L>
		struct TypeListRemoveFirst<L<> > {
			typedef L<> type;
		};

		template <class L> struct TypeListRemoveLast;

		template <template <class...> class L, class... A>
		struct TypeListRemoveLast<L<A...> > {
			typedef typename TypeListRemove<L<A...>, sizeof...(A) - 1>::type type;
		};

		template <template <class...> class L>
		struct TypeListRemoveLast<L<> > {
			typedef L<> type;
		};

		template <class L, unsigned int S> struct TypeListRemoveHead;

		template <template <class...> class L, class... A, unsigned int S>
		struct TypeListRemoveHead<L<A...>, S> {
			typedef typename TypeListRemoveHead<typename TypeListRemoveFirst<L<A...> >::type, S - 1>::type type;
		};

		template <template <class...> class L, class... A>
		struct TypeListRemoveHead<L<A...>, 0> {
			typedef L<A...> type;
		};

		template <class L, unsigned int S> struct TypeListRemoveTail;

		template <template <class...> class L, class... A, unsigned int S>
		struct TypeListRemoveTail<L<A...>, S> {
			typedef typename TypeListRemoveTail<typename TypeListRemoveLast<L<A...> >::type, S - 1>::type type;
		};

		template <template <class...> class L, class... A>
		struct TypeListRemoveTail<L<A...>, 0> {
			typedef L<A...> type;
		};

		template <class L0, class... L> struct TypeListJoin;

		template <class L0, template <class...> class L1, class... A1, class... L>
		struct TypeListJoin<L0, L1<A1...>, L...> {
			typedef typename TypeListJoin<typename TypeListAppend<L0, A1...>::type, L...>::type type;
		};

		template <class L>
		struct TypeListJoin<L> {
			typedef L type;
		};

		template <class L, unsigned int> struct TypeListRotateLeft;

		template <template <class...> class L, class... A, unsigned int N>
		struct TypeListRotateLeft<L<A...>, N> {
			typedef typename TypeListJoin<
				typename TypeListRemoveHead<L<A...>, N % sizeof...(A)>::type,
				typename TypeListRemoveTail<L<A...>, sizeof...(A) - (N % sizeof...(A))>::type
			>::type type;
		};

		template <template <class...> class L, unsigned int N>
		struct TypeListRotateLeft<L<>, N> {
			typedef L<> type;
		};

		template <class L, unsigned int> struct TypeListRotateRight;

		template <template <class...> class L, class... A, unsigned int N>
		struct TypeListRotateRight<L<A...>, N> {
			typedef typename TypeListJoin<
				typename TypeListRemoveHead<L<A...>, sizeof...(A) - (N % sizeof...(A))>::type,
				typename TypeListRemoveTail<L<A...>, N % sizeof...(A)>::type
			>::type type;
		};

		template <template <class...> class L, unsigned int N>
		struct TypeListRotateRight<L<>, N> {
			typedef L<> type;
		};

#		if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

			template <class from, template <class...> class to>
			using type_list_rename = typename TypeListRename<from, to>::type;

			template <class L, class... T	 > using type_list_prepend	= typename TypeListPrepend    <L, T...>::type;
			template <class L, class... T	 > using type_list_append	= typename TypeListAppend     <L, T...>::type;
			template <class L, unsigned int I> using type_list_remove	= typename TypeListRemove     <L, I   >::type;
			template <class L		 > using type_list_remove_first = typename TypeListRemoveFirst<L      >::type;
			template <class L		 > using type_list_remove_last	= typename TypeListRemoveLast <L      >::type;
			template <class L, unsigned int S> using type_list_remove_head	= typename TypeListRemoveHead <L, S   >::type;
			template <class L, unsigned int S> using type_list_remove_tail	= typename TypeListRemoveTail <L, S   >::type;

#		endif

		template <class... A> struct TypeList {
			enum {size = sizeof...(A)};

			typedef typename SelectType<0,			 A...>::type first;
			typedef typename SelectType<size ? size - 1 : 0, A...>::type last;

			typedef	typename TypeListRemoveFirst<TypeList>::type remove_first;
			typedef typename TypeListRemoveLast <TypeList>::type remove_last;

#			if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

				template <template <class...> class to> using rename = typename TypeListRename<TypeList, to>::type;

				template <unsigned int I> using get = typename SelectType<I, A...>::type;

				//template<unsigned int I, class T> set = typename SelectType<I, 


				template <class... T	> using prepend	    = TypeList<T..., A...>;
				template <class... T	> using append	    = TypeList<A..., T...>;
				template <unsigned int I> using remove	    = typename TypeListRemove	 <TypeList, I>::type;
				template <unsigned int S> using remove_head = typename TypeListRemoveHead<TypeList, S>::type;
				template <unsigned int S> using remove_tail = typename TypeListRemoveTail<TypeList, S>::type;

#			endif
		};
	}

#endif

#endif // __Z_traits_TypeList_HPP__
