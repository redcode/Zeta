/* Zeta API - Z/traits/TypeList.hpp
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_traits_TypeList_HPP
#define Z_traits_TypeList_HPP

#include <Z/inspection/language.h>

#if Z_DIALECT_HAS(CPP11, EXTENDED_VARIADIC_TEMPLATE_TEMPLATE_PARAMETERS)
#	include <Z/traits/control.hpp>
#	include <Z/traits/TypeCount.hpp>

#	define Z_HAS_TypeList		 TRUE
#	define Z_HAS_TypeListSize	 TRUE
#	define Z_HAS_TypeListApply	 TRUE
#	define Z_HAS_TypeListAppend	 TRUE
#	define Z_HAS_TypeListFirst	 TRUE
#	define Z_HAS_TypeListGet	 TRUE
#	define Z_HAS_TypeListJoin	 TRUE
#	define Z_HAS_TypeListLast	 TRUE
#	define Z_HAS_TypeListPrepend	 TRUE
#	define Z_HAS_TypeListRename	 TRUE
#	define Z_HAS_TypeListRemove	 TRUE
#	define Z_HAS_TypeListRemoveFirst TRUE
#	define Z_HAS_TypeListRemoveHead	 TRUE
#	define Z_HAS_TypeListRemoveLast	 TRUE
#	define Z_HAS_TypeListRemoveTail	 TRUE
#	define Z_HAS_TypeListReverse	 TRUE
#	define Z_HAS_TypeListRotateLeft	 TRUE
#	define Z_HAS_TypeListRotateRight TRUE
#	define Z_HAS_TypeListToFunction	 TRUE

#	if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
#		define Z_HAS_TypeList_MEMBER_apply	  TRUE
#		define Z_HAS_TypeList_MEMBER_append	  TRUE
#		define Z_HAS_TypeList_MEMBER_get	  TRUE
#		define Z_HAS_TypeList_MEMBER_prepend	  TRUE
#		define Z_HAS_TypeList_MEMBER_remove	  TRUE
#		define Z_HAS_TypeList_MEMBER_remove_head  TRUE
#		define Z_HAS_TypeList_MEMBER_remove_tail  TRUE
#		define Z_HAS_TypeList_MEMBER_rename	  TRUE
#		define Z_HAS_TypeList_MEMBER_rotate_left  TRUE
#		define Z_HAS_TypeList_MEMBER_rotate_right TRUE
#		define Z_HAS_TypeList_MEMBER_to_function  TRUE
#		define Z_HAS_type_list_apply		  TRUE
#		define Z_HAS_type_list_append		  TRUE
#		define Z_HAS_type_list_first		  TRUE
#		define Z_HAS_type_list_get		  TRUE
#		define Z_HAS_type_list_last		  TRUE
#		define Z_HAS_type_list_prepend		  TRUE
#		define Z_HAS_type_list_remove		  TRUE
#		define Z_HAS_type_list_remove_first	  TRUE
#		define Z_HAS_type_list_remove_head	  TRUE
#		define Z_HAS_type_list_remove_last	  TRUE
#		define Z_HAS_type_list_remove_tail	  TRUE
#		define Z_HAS_type_list_rename		  TRUE
#		define Z_HAS_type_list_reverse		  TRUE
#		define Z_HAS_type_list_rotate_left	  TRUE
#		define Z_HAS_type_list_rotate_right	  TRUE
#		define Z_HAS_type_list_to_function	  TRUE
#	endif

#	if Z_DIALECT_HAS(CPP14, VARIABLE_TEMPLATE) && Z_DIALECT_HAS_SPECIFIER(CPP11, CONSTEXPR)
#		define Z_HAS_type_list_size TRUE
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

#		define Z__NORMAL_SPECIALIZATION_GROUP	       \
			Z__SPECIALIZATION_PAIR(Z_EMPTY	     ) \
			Z__SPECIALIZATION_PAIR(const	     ) \
			Z__SPECIALIZATION_PAIR(const volatile) \
			Z__SPECIALIZATION_PAIR(	     volatile)

#		if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
#			define Z__REFERENCE_SPECIALIZATION_GROUP	  \
				Z__SPECIALIZATION_PAIR(		      & ) \
				Z__SPECIALIZATION_PAIR(		      &&) \
				Z__SPECIALIZATION_PAIR(const	      & ) \
				Z__SPECIALIZATION_PAIR(const	      &&) \
				Z__SPECIALIZATION_PAIR(const volatile & ) \
				Z__SPECIALIZATION_PAIR(const volatile &&) \
				Z__SPECIALIZATION_PAIR(	     volatile & ) \
				Z__SPECIALIZATION_PAIR(	     volatile &&)
#		else
#			define Z__REFERENCE_SPECIALIZATION_GROUP
#		endif

#		if Z_DIALECT_HAS(GNUPP17, NOEXCEPT_OPERAND_DEDUCTION)
#			define Z__NOEXCEPT_PARAMETER Boolean x,
#			define Z__NOEXCEPT_SPECIFIER noexcept(x)
#		else
#			define Z__NOEXCEPT_PARAMETER
#			define Z__NOEXCEPT_SPECIFIER
#		endif

#		define Z__SPECIALIZATION_PAIR(qualifiers)							      \
														      \
			template <template <class...> class l, class... a, Z__NOEXCEPT_PARAMETER class r, class... p> \
			struct TypeListToFunction<l<a...>, r(p...) qualifiers Z__NOEXCEPT_SPECIFIER> {		      \
				typedef r type(a...) qualifiers Z__NOEXCEPT_SPECIFIER;				      \
			};											      \
														      \
			template <template <class...> class l, class... a, Z__NOEXCEPT_PARAMETER class r, class... p> \
			struct TypeListToFunction<l<a...>, r(p..., ...) qualifiers Z__NOEXCEPT_SPECIFIER> {	      \
				typedef r type(a..., ...) qualifiers Z__NOEXCEPT_SPECIFIER;			      \
			};

		Z__NORMAL_SPECIALIZATION_GROUP
		Z__REFERENCE_SPECIALIZATION_GROUP

#		if !Z_DIALECT_HAS(GNUPP17, NOEXCEPT_OPERAND_DEDUCTION) && Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
#			undef  Z__NOEXCEPT_SPECIFIER
#			define Z__NOEXCEPT_SPECIFIER noexcept

			Z__NORMAL_SPECIALIZATION_GROUP
			Z__REFERENCE_SPECIALIZATION_GROUP
#		endif

#		undef Z__NORMAL_SPECIALIZATION_GROUP
#		undef Z__REFERENCE_SPECIALIZATION_GROUP
#		undef Z__NOEXCEPT_PARAMETER
#		undef Z__NOEXCEPT_SPECIFIER
#		undef Z__SPECIALIZATION_PAIR

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
