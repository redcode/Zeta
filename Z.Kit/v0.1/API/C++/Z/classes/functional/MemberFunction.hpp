/* Z Kit C++ API - classes/functional/MemberFunction.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_functional_MemberFunction_HPP__
#define __Z_classes_functional_MemberFunction_HPP__

#include <Z/classes/base/OpaqueMemberFunctionPointer.hpp>

#if	Z_LANGUAGE_HAS(CPP, SFINAE)	       && \
	Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE) && \
	Z_LANGUAGE_HAS(CPP, DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE)

#	include <Z/traits/filtering.hpp>
#	include <Z/traits/Type.hpp>


	namespace Zeta {

		template <class F> struct MemberFunction;

		template <class R, class... P> struct MemberFunction<R(P...)> {
			R (NaT::* function)(P...);

			Z_INLINE_MEMBER MemberFunction() {}


#			if Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)
				Z_CT_MEMBER(CPP11) MemberFunction(NullPointer)
				: function(NULL) {};
#			endif


			template <class M, class E = typename EnableIf<
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<
					typename Type<M>::flow::to_function::end::to_unqualified,
					R(P...)
				>::value,
			M>::type>
			Z_INLINE_MEMBER MemberFunction(M function)
			: function((R (NaT::*)(P...))function) {}


			Z_INLINE_MEMBER MemberFunction(const OpaqueMemberFunctionPointer &function)
			: function(function) {}


			Z_INLINE_MEMBER MemberFunction(const OpaqueMemberFunctionPointer *function)
			: function(*function) {}


			Z_CT_MEMBER(CPP11) operator Boolean() const {return function != NULL;}


			template <class M, class E = typename EnableIf<
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<
					typename Type<M>::flow::to_function::end::to_unqualified,
					R(P...)
				>::value,
			M>::type>
			Z_INLINE_MEMBER operator M() const {return (M)function;}


			template <class O, class RR = R>
			Z_INLINE_MEMBER typename EnableIf<Type<RR>::is_void, RR>::type
			operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{(((NaT *)object)->*function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE_MEMBER typename EnableIf<Type<R>::is_void, RR>::type
			operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{(((NaT *)&object)->*function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE_MEMBER typename EnableIf<!Type<R>::is_void, RR>::type
			operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{return (((NaT *)object)->*function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE_MEMBER typename EnableIf<!Type<R>::is_void, RR>::type
			operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{return (((NaT *)&object)->*function)(arguments...);}
		};
	}


#	define Z_HAS_CLASS_MemberFunction TRUE
#else
#	define Z_HAS_CLASS_MemberFunction FALSE
#endif

#endif // __Z_classes_functional_MemberFunction_HPP__
