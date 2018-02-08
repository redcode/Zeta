/* Z Kit C++ API - traits/TypeList.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_TypeList_HPP__
#define __Z_traits_TypeList_HPP__

#include <Z/traits/SelectType.hpp>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)

	namespace Zeta {

		template <class L, class... types> struct TypeListAppend;

		template <template <class...> class L, class... A, class... T>
		struct TypeListAppend<L<A...>, T...> {
			typedef L<A..., T...> type;
		};

		template <class L> struct TypeListFirst;

		template <template <class...> class L, class... A>
		struct TypeListFirst<L<A...> > {
			typedef typename SelectType<0, A...>::type type;
		};

		template <template <class...> class L, class A>
		struct TypeListFirst<L<A> > {
			typedef A type;
		};

		template <class L, UInt index> struct TypeListGet;

		template <template <class...> class L, class... A, UInt I>
		struct TypeListGet<L<A...>, I> {
			typedef typename SelectType<I, A...>::type type;
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

		template <class L> struct TypeListLast;

		template <template <class...> class L, class... A>
		struct TypeListLast<L<A...> > {
			typedef typename SelectType<0, A...>::type type;
			typedef typename SelectType<sizeof...(A) ? sizeof...(A) - 1 : 0, A...>::type last;
		};

		template <template <class...> class L, class A>
		struct TypeListLast<L<A> > {
			typedef A type;
		};

		template <class L, class... types> struct TypeListPrepend;

		template <template <class...> class L, class... A, class... T>
		struct TypeListPrepend<L<A...>, T...> {
			typedef L<T..., A...> type;
		};

		template <class L, template <class...> class to> struct TypeListRename;

		template <template <class...> class L, class... A, template <class...> class to>
		struct TypeListRename<L<A...>, to> {
			typedef to<A...> type;
		};

		template <class L, UInt index> struct TypeListRemove;

		template <template <class...> class L, class A0, class... A>
		struct TypeListRemove<L<A0, A...>, 0> {
			typedef L<A...> type;
		};

		template <template <class...> class L, class A0, class... A, UInt I>
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

		template <class L, UInt head_size> struct TypeListRemoveHead;

		template <template <class...> class L, class... A, UInt S>
		struct TypeListRemoveHead<L<A...>, S> {
			typedef typename TypeListRemoveHead<typename TypeListRemoveFirst<L<A...> >::type, S - 1>::type type;
		};

		template <template <class...> class L, class... A>
		struct TypeListRemoveHead<L<A...>, 0> {
			typedef L<A...> type;
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

		template <class L, UInt tail_size> struct TypeListRemoveTail;

		template <template <class...> class L, class... A, UInt S>
		struct TypeListRemoveTail<L<A...>, S> {
			typedef typename TypeListRemoveTail<typename TypeListRemoveLast<L<A...> >::type, S - 1>::type type;
		};

		template <template <class...> class L, class... A>
		struct TypeListRemoveTail<L<A...>, 0> {
			typedef L<A...> type;
		};

		template <class L> struct TypeListReverse;

		template <template <class...> class L, class A0, class... A>
		struct TypeListReverse<L<A0, A...> > {
			typedef typename TypeListAppend<typename TypeListReverse<L<A...> >::type, A0>::type type;
		};

		template <template <class...> class L>
		struct TypeListReverse<L<> > {
			typedef L<> type;
		};

		template <class L, UInt rotation> struct TypeListRotateLeft;

		template <template <class...> class L, class... A, UInt R>
		struct TypeListRotateLeft<L<A...>, R> {
			typedef typename TypeListJoin<
				typename TypeListRemoveHead<L<A...>, R % sizeof...(A)>::type,
				typename TypeListRemoveTail<L<A...>, sizeof...(A) - (R % sizeof...(A))>::type
			>::type type;
		};

		template <template <class...> class L, UInt R>
		struct TypeListRotateLeft<L<>, R> {
			typedef L<> type;
		};

		template <class L, UInt rotation> struct TypeListRotateRight;

		template <template <class...> class L, class... A, UInt R>
		struct TypeListRotateRight<L<A...>, R> {
			typedef typename TypeListJoin<
				typename TypeListRemoveHead<L<A...>, sizeof...(A) - (R % sizeof...(A))>::type,
				typename TypeListRemoveTail<L<A...>, R % sizeof...(A)>::type
			>::type type;
		};

		template <template <class...> class L, UInt R>
		struct TypeListRotateRight<L<>, R> {
			typedef L<> type;
		};

		template <class L, class function_model> struct TypeListToFunction;

		template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...)		 > {typedef R type(A...)	       ;};
		template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...) const	 > {typedef R type(A...) const	       ;};
		template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...)	 volatile> {typedef R type(A...)       volatile;};
		template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...) const volatile> {typedef R type(A...) const volatile;};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...)		  & > {typedef R type(A...)		   & ;};
			template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...)		  &&> {typedef R type(A...)		   &&;};
			template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...) const	  & > {typedef R type(A...) const	   & ;};
			template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...) const	  &&> {typedef R type(A...) const	   &&;};
			template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...)	 volatile & > {typedef R type(A...)	  volatile & ;};
			template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...)	 volatile &&> {typedef R type(A...)	  volatile &&;};
			template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...) const volatile & > {typedef R type(A...) const volatile & ;};
			template <template <class...> class L, class... A, class R, class... P> struct TypeListToFunction<L<A...>, R(P...) const volatile &&> {typedef R type(A...) const volatile &&;};
#		endif

		template <class L, template <class...> class metafunction> struct TypeListTransform;

		template <template <class...> class L, class A0, class... A, template <class...> class M>
		struct TypeListTransform<L<A0, A...>, M> {
			typedef typename TypeListPrepend<
				typename TypeListTransform<L<A...>, M>::type,
				typename M<A0>::type
			>::type type;
		};

		template <template <class...> class L, template <class...> class M>
		struct TypeListTransform<L<>, M> {
			typedef L<> type;
		};

#		if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

			template <class L, class...		     types	   > using type_list_append	  = typename TypeListAppend	<L, types...	  >::type;
			template <class L					   > using type_list_first	  = typename TypeListFirst	<L		  >::type;
			template <class L, UInt			     index	   > using type_list_get	  = typename TypeListGet	<L, index	  >::type;
			template <class L					   > using type_list_last	  = typename TypeListLast	<L		  >::type;
			template <class L, class...		     types	   > using type_list_prepend	  = typename TypeListPrepend	<L, types...	  >::type;
			template <class L, UInt			     index	   > using type_list_remove	  = typename TypeListRemove	<L, index	  >::type;
			template <class L					   > using type_list_remove_first = typename TypeListRemoveFirst<L		  >::type;
			template <class L, UInt			     head_size	   > using type_list_remove_head  = typename TypeListRemoveHead	<L, head_size	  >::type;
			template <class L					   > using type_list_remove_last  = typename TypeListRemoveLast	<L		  >::type;
			template <class L, UInt			     head_size	   > using type_list_remove_tail  = typename TypeListRemoveTail	<L, head_size	  >::type;
			template <class L, template <class...> class to		   > using type_list_rename	  = typename TypeListRename	<L, to		  >::type;
			template <class L					   > using type_list_reverse	  = typename TypeListReverse	<L		  >::type;
			template <class L, UInt			     rotation	   > using type_list_rotate_left  = typename TypeListRotateLeft	<L, rotation	  >::type;
			template <class L, UInt			     rotation	   > using type_list_rotate_right = typename TypeListRotateRight<L, rotation	  >::type;
			template <class L, class		     function_model> using type_list_to_function  = typename TypeListToFunction	<L, function_model>::type;
			template <class L, template <class...> class metafunction  > using type_list_transform	  = typename TypeListTransform	<L, metafunction  >::type;

#		endif

		template <class... A> struct TypeList {
			enum {size = sizeof...(A)};

			typedef typename TypeListFirst	    <TypeList>::type first;
			typedef typename TypeListLast	    <TypeList>::type last;
			typedef	typename TypeListRemoveFirst<TypeList>::type remove_first;
			typedef typename TypeListRemoveLast <TypeList>::type remove_last;
			typedef typename TypeListReverse    <TypeList>::type reverse;

#			if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

				template <class...		    types	  > using append       = TypeList<A..., types...>;
				template <UInt			    index	  > using get	       = typename SelectType<index, A...>::type;
				template <class...		    types	  > using prepend      = TypeList<types..., A...>;
				template <UInt			    index	  > using remove       = typename TypeListRemove     <TypeList, index	      >::type;
				template <UInt			    head_size	  > using remove_head  = typename TypeListRemoveHead <TypeList, head_size     >::type;
				template <UInt			    tail_size	  > using remove_tail  = typename TypeListRemoveTail <TypeList, tail_size     >::type;
				template <template <class...> class to		  > using rename       = typename TypeListRename     <TypeList, to	      >::type;
				template <UInt			    rotation	  > using rotate_left  = typename TypeListRotateLeft <TypeList, rotation      >::type;
				template <UInt			    rotation	  > using rotate_right = typename TypeListRotateRight<TypeList, rotation      >::type;
				template <class			    function_model> using to_function  = typename TypeListToFunction <TypeList, function_model>::type;
				template <template <class...> class metafunction  > using transform    = typename TypeListTransform  <TypeList, metafunction  >::type;

#			endif
		};
	}

#	define Z_HAS_TRAIT_TYPE_LIST TRUE
#else
#	define Z_HAS_TRAIT_TYPE_LIST FALSE
#endif

#endif // __Z_traits_TypeList_HPP__
