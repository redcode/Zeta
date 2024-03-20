/* Zeta API - Z/traits/TypeList.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_traits_TypeList_HPP
#define Z_traits_TypeList_HPP

#include <Z/inspection/language.h>

#if Z_DIALECT_HAS(CPP11, EXTENDED_VARIADIC_TEMPLATE_TEMPLATE_PARAMETERS)
#	include <Z/traits/control.hpp>
#	include <Z/traits/TypeCount.hpp>

#	define Z_HAS_TypeList		 1
#	define Z_HAS_TypeListSize	 1
#	define Z_HAS_TypeListApply	 1
#	define Z_HAS_TypeListAppend	 1
#	define Z_HAS_TypeListFirst	 1
#	define Z_HAS_TypeListGet	 1
#	define Z_HAS_TypeListJoin	 1
#	define Z_HAS_TypeListLast	 1
#	define Z_HAS_TypeListPrepend	 1
#	define Z_HAS_TypeListRename	 1
#	define Z_HAS_TypeListRemove	 1
#	define Z_HAS_TypeListRemoveFirst 1
#	define Z_HAS_TypeListRemoveHead	 1
#	define Z_HAS_TypeListRemoveLast	 1
#	define Z_HAS_TypeListRemoveTail	 1
#	define Z_HAS_TypeListReverse	 1
#	define Z_HAS_TypeListRotateLeft	 1
#	define Z_HAS_TypeListRotateRight 1
#	define Z_HAS_TypeListToFunction	 1

#	if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
#		define Z_HAS_TypeList_MEMBER_apply	  1
#		define Z_HAS_TypeList_MEMBER_append	  1
#		define Z_HAS_TypeList_MEMBER_get	  1
#		define Z_HAS_TypeList_MEMBER_prepend	  1
#		define Z_HAS_TypeList_MEMBER_remove	  1
#		define Z_HAS_TypeList_MEMBER_remove_head  1
#		define Z_HAS_TypeList_MEMBER_remove_tail  1
#		define Z_HAS_TypeList_MEMBER_rename	  1
#		define Z_HAS_TypeList_MEMBER_rotate_left  1
#		define Z_HAS_TypeList_MEMBER_rotate_right 1
#		define Z_HAS_TypeList_MEMBER_to_function  1
#		define Z_HAS_type_list_apply		  1
#		define Z_HAS_type_list_append		  1
#		define Z_HAS_type_list_first		  1
#		define Z_HAS_type_list_get		  1
#		define Z_HAS_type_list_last		  1
#		define Z_HAS_type_list_prepend		  1
#		define Z_HAS_type_list_remove		  1
#		define Z_HAS_type_list_remove_first	  1
#		define Z_HAS_type_list_remove_head	  1
#		define Z_HAS_type_list_remove_last	  1
#		define Z_HAS_type_list_remove_tail	  1
#		define Z_HAS_type_list_rename		  1
#		define Z_HAS_type_list_reverse		  1
#		define Z_HAS_type_list_rotate_left	  1
#		define Z_HAS_type_list_rotate_right	  1
#		define Z_HAS_type_list_to_function	  1
#	endif

#	if Z_DIALECT_HAS(CPP14, VARIABLE_TEMPLATE) && Z_DIALECT_HAS_SPECIFIER(CPP11, CONSTEXPR)
#		define Z_HAS_type_list_size 1
#	endif

	namespace Zeta {

		template <class l> struct TypeListSize;

		template <template <class...> class l, class... a>
		struct TypeListSize<l<a...> > {
			enum {value = TypeCount<a...>::value};
		};

		template <class l, template <class...> class metafunction> struct TypeListApply;

		template <template <class...> class l, class... a, template <class...> class m>
		struct TypeListApply<l<a...>, m> {
			typedef l<typename m<a>::type...> type;
		};

		template <class l, class... types> struct TypeListAppend;

		template <template <class...> class l, class... a, class... t>
		struct TypeListAppend<l<a...>, t...> {
			typedef l<a..., t...> type;
		};

		template <class l> struct TypeListFirst;

		template <template <class...> class l>
		struct TypeListFirst<l<> > {
			typedef NaT type;
		};

		template <template <class...> class l, class a>
		struct TypeListFirst<l<a> > {
			typedef a type;
		};

		template <template <class...> class l, class a0, class... a>
		struct TypeListFirst<l<a0, a...> > {
			typedef a0 type;
		};

		template <class l, UInt index> struct TypeListGet;

		template <template <class...> class l, class... a, UInt i>
		struct TypeListGet<l<a...>, i> {
			typedef typename SelectType<i, a...>::type type;
		};

		template <class l0, class... l> struct TypeListJoin;

		template <class l>
		struct TypeListJoin<l> {
			typedef l type;
		};

		template <class l0, template <class...> class l1, class... a1, class... l>
		struct TypeListJoin<l0, l1<a1...>, l...> {
			typedef typename TypeListJoin<typename TypeListAppend<l0, a1...>::type, l...>::type type;
		};

		template <class l> struct TypeListLast;

		template <template <class...> class l>
		struct TypeListLast<l<> > {
			typedef NaT type;
		};

		template <template <class...> class l, class a>
		struct TypeListLast<l<a> > {
			typedef a type;
		};

		template <template <class...> class l, class... a>
		struct TypeListLast<l<a...> > {
			typedef typename SelectType<TypeCount<a...>::value
				? TypeCount<a...>::value - 1
				: 0, a...
			>::type type;
		};

		template <class l, class... types> struct TypeListPrepend;

		template <template <class...> class l, class... a, class... t>
		struct TypeListPrepend<l<a...>, t...> {
			typedef l<t..., a...> type;
		};

		template <class l, template <class...> class to> struct TypeListRename;

		template <template <class...> class l, class... a, template <class...> class to>
		struct TypeListRename<l<a...>, to> {
			typedef to<a...> type;
		};

		template <class l, UInt index> struct TypeListRemove;

		template <template <class...> class l, class a0, class... a>
		struct TypeListRemove<l<a0, a...>, 0> {
			typedef l<a...> type;
		};

		template <template <class...> class l, class a0, class... a, UInt i>
		struct TypeListRemove<l<a0, a...>, i> {
			typedef typename TypeListPrepend<typename TypeListRemove<l<a...>, i - 1>::type, a0>::type type;
		};

		template <class L> struct TypeListRemoveFirst;

		template <template <class...> class l>
		struct TypeListRemoveFirst<l<> > {
			typedef l<> type;
		};

		template <template <class...> class l, class a0, class... a>
		struct TypeListRemoveFirst<l<a0, a...> > {
			typedef l<a...> type;
		};

		template <class l, UInt head_size> struct TypeListRemoveHead;

		template <template <class...> class l, class... a>
		struct TypeListRemoveHead<l<a...>, 0> {
			typedef l<a...> type;
		};

		template <template <class...> class l, class... a, UInt s>
		struct TypeListRemoveHead<l<a...>, s> {
			typedef typename TypeListRemoveHead<typename TypeListRemoveFirst<l<a...> >::type, s - 1>::type type;
		};

		template <class l> struct TypeListRemoveLast;

		template <template <class...> class l>
		struct TypeListRemoveLast<l<> > {
			typedef l<> type;
		};

		template <template <class...> class l, class... a>
		struct TypeListRemoveLast<l<a...> > {
			typedef typename TypeListRemove<l<a...>, TypeCount<a...>::value - 1>::type type;
		};

		template <class l, UInt tail_size> struct TypeListRemoveTail;

		template <template <class...> class l, class... a>
		struct TypeListRemoveTail<l<a...>, 0> {
			typedef l<a...> type;
		};

		template <template <class...> class l, class... a, UInt s>
		struct TypeListRemoveTail<l<a...>, s> {
			typedef typename TypeListRemoveTail<typename TypeListRemoveLast<l<a...> >::type, s - 1>::type type;
		};

		template <class l> struct TypeListReverse;

		template <template <class...> class l>
		struct TypeListReverse<l<> > {
			typedef l<> type;
		};

		template <template <class...> class l, class a0, class... a>
		struct TypeListReverse<l<a0, a...> > {
			typedef typename TypeListAppend<typename TypeListReverse<l<a...> >::type, a0>::type type;
		};

		template <class l, UInt rotation> struct TypeListRotateLeft;

		template <template <class...> class l, UInt r>
		struct TypeListRotateLeft<l<>, r> {
			typedef l<> type;
		};

		template <template <class...> class l, class... a, UInt r>
		struct TypeListRotateLeft<l<a...>, r> {
			typedef typename TypeListJoin<
				typename TypeListRemoveHead<l<a...>, r % TypeCount<a...>::value>::type,
				typename TypeListRemoveTail<l<a...>, TypeCount<a...>::value - (r % TypeCount<a...>::value)>::type
			>::type type;
		};

		template <class l, UInt rotation> struct TypeListRotateRight;

		template <template <class...> class l, UInt r>
		struct TypeListRotateRight<l<>, r> {
			typedef l<> type;
		};

		template <template <class...> class l, class... a, UInt r>
		struct TypeListRotateRight<l<a...>, r> {
			typedef typename TypeListJoin<
				typename TypeListRemoveHead<l<a...>, TypeCount<a...>::value - (r % TypeCount<a...>::value)>::type,
				typename TypeListRemoveTail<l<a...>, r % TypeCount<a...>::value>::type
			>::type type;
		};

		template <class l, class function_model> struct TypeListToFunction;

#		define Z_z_NORMAL_SPECIALIZATION_GROUP		\
			Z_z_SPECIALIZATION_PAIR(Z_EMPTY	      ) \
			Z_z_SPECIALIZATION_PAIR(const	      ) \
			Z_z_SPECIALIZATION_PAIR(const volatile) \
			Z_z_SPECIALIZATION_PAIR(      volatile)

#		if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
#			define Z_z_REFERENCE_SPECIALIZATION_GROUP	   \
				Z_z_SPECIALIZATION_PAIR(	       & ) \
				Z_z_SPECIALIZATION_PAIR(	       &&) \
				Z_z_SPECIALIZATION_PAIR(const	       & ) \
				Z_z_SPECIALIZATION_PAIR(const	       &&) \
				Z_z_SPECIALIZATION_PAIR(const volatile & ) \
				Z_z_SPECIALIZATION_PAIR(const volatile &&) \
				Z_z_SPECIALIZATION_PAIR(      volatile & ) \
				Z_z_SPECIALIZATION_PAIR(      volatile &&)
#		else
#			define Z_z_REFERENCE_SPECIALIZATION_GROUP
#		endif

#		if Z_DIALECT_HAS(GNUPP17, NOEXCEPT_OPERAND_DEDUCTION)
#			define Z_z_NOEXCEPT_PARAMETER Boolean x,
#			define Z_z_NOEXCEPT_SPECIFIER noexcept(x)
#		else
#			define Z_z_NOEXCEPT_PARAMETER
#			define Z_z_NOEXCEPT_SPECIFIER
#		endif

#		define Z_z_SPECIALIZATION_PAIR(qualifiers)							       \
														       \
			template <template <class...> class l, class... a, Z_z_NOEXCEPT_PARAMETER class r, class... p> \
			struct TypeListToFunction<l<a...>, r(p...) qualifiers Z_z_NOEXCEPT_SPECIFIER> {		       \
				typedef r type(a...) qualifiers Z_z_NOEXCEPT_SPECIFIER;				       \
			};											       \
														       \
			template <template <class...> class l, class... a, Z_z_NOEXCEPT_PARAMETER class r, class... p> \
			struct TypeListToFunction<l<a...>, r(p..., ...) qualifiers Z_z_NOEXCEPT_SPECIFIER> {	       \
				typedef r type(a..., ...) qualifiers Z_z_NOEXCEPT_SPECIFIER;			       \
			};

		Z_z_NORMAL_SPECIALIZATION_GROUP
		Z_z_REFERENCE_SPECIALIZATION_GROUP

#		if	!Z_DIALECT_HAS(GNUPP17, NOEXCEPT_OPERAND_DEDUCTION) && \
			Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)

#			undef  Z_z_NOEXCEPT_SPECIFIER
#			define Z_z_NOEXCEPT_SPECIFIER noexcept

			Z_z_NORMAL_SPECIALIZATION_GROUP
			Z_z_REFERENCE_SPECIALIZATION_GROUP
#		endif

#		undef Z_z_NORMAL_SPECIALIZATION_GROUP
#		undef Z_z_REFERENCE_SPECIALIZATION_GROUP
#		undef Z_z_NOEXCEPT_PARAMETER
#		undef Z_z_NOEXCEPT_SPECIFIER
#		undef Z_z_SPECIALIZATION_PAIR

		template <class... a> struct TypeList {
			enum {size = TypeCount<a...>::value};

			typedef typename TypeListFirst	    <TypeList>::type first;
			typedef typename TypeListLast	    <TypeList>::type last;
			typedef	typename TypeListRemoveFirst<TypeList>::type remove_first;
			typedef typename TypeListRemoveLast <TypeList>::type remove_last;
			typedef typename TypeListReverse    <TypeList>::type reverse;

#			if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
				template <template <class...> class metafunction  > using apply	       = typename TypeListApply	     <TypeList, metafunction  >::type;
				template <class...		    types	  > using append       =	  TypeList	     <a...,	types...      >;
				template <UInt			    index	  > using get	       = typename SelectType	     <index,	a...	      >::type;
				template <class...		    types	  > using prepend      =	  TypeList	     <types..., a...	      >;
				template <UInt			    index	  > using remove       = typename TypeListRemove     <TypeList, index	      >::type;
				template <UInt			    head_size	  > using remove_head  = typename TypeListRemoveHead <TypeList, head_size     >::type;
				template <UInt			    tail_size	  > using remove_tail  = typename TypeListRemoveTail <TypeList, tail_size     >::type;
				template <template <class...> class to		  > using rename       = typename TypeListRename     <TypeList, to	      >::type;
				template <UInt			    rotation	  > using rotate_left  = typename TypeListRotateLeft <TypeList, rotation      >::type;
				template <UInt			    rotation	  > using rotate_right = typename TypeListRotateRight<TypeList, rotation      >::type;
				template <class			    function_model> using to_function  = typename TypeListToFunction <TypeList, function_model>::type;
#			endif
		};

#		if Z_HAS(type_list_size)
			template <class l> static Z_CONSTANT USize type_list_size = TypeListSize<l>::value;
#		endif

#		if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
			template <class l, template <class...> class metafunction  > using type_list_apply	  = typename TypeListApply	<l, metafunction  >::type;
			template <class l, class...		     types	   > using type_list_append	  = typename TypeListAppend	<l, types...	  >::type;
			template <class l					   > using type_list_first	  = typename TypeListFirst	<l		  >::type;
			template <class l, UInt			     index	   > using type_list_get	  = typename TypeListGet	<l, index	  >::type;
			template <class l					   > using type_list_last	  = typename TypeListLast	<l		  >::type;
			template <class l, class...		     types	   > using type_list_prepend	  = typename TypeListPrepend	<l, types...	  >::type;
			template <class l, UInt			     index	   > using type_list_remove	  = typename TypeListRemove	<l, index	  >::type;
			template <class l					   > using type_list_remove_first = typename TypeListRemoveFirst<l		  >::type;
			template <class l, UInt			     head_size	   > using type_list_remove_head  = typename TypeListRemoveHead	<l, head_size	  >::type;
			template <class l					   > using type_list_remove_last  = typename TypeListRemoveLast	<l		  >::type;
			template <class l, UInt			     head_size	   > using type_list_remove_tail  = typename TypeListRemoveTail	<l, head_size	  >::type;
			template <class l, template <class...> class to		   > using type_list_rename	  = typename TypeListRename	<l, to		  >::type;
			template <class l					   > using type_list_reverse	  = typename TypeListReverse	<l		  >::type;
			template <class l, UInt			     rotation	   > using type_list_rotate_left  = typename TypeListRotateLeft	<l, rotation	  >::type;
			template <class l, UInt			     rotation	   > using type_list_rotate_right = typename TypeListRotateRight<l, rotation	  >::type;
			template <class l, class		     function_model> using type_list_to_function  = typename TypeListToFunction	<l, function_model>::type;
#		endif
	}
#endif

#endif // Z_traits_TypeList_HPP
