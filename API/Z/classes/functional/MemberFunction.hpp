/* Z Kit - classes/functional/MemberFunction.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_functional_MemberFunction_HPP_
#define _Z_classes_functional_MemberFunction_HPP_

#include <Z/inspection/language.h>

#if	Z_LANGUAGE_HAS(CPP, SFINAE)	       && \
	Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE) && \
	Z_LANGUAGE_HAS(CPP, DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE)

#	include <Z/traits/filtering.hpp>
#	include <Z/traits/Type.hpp>


	namespace Zeta {

		template <class F> struct MemberFunction;

		template <class R, class... P> struct MemberFunction<R(P...)> {
			R (NaT::* function)(P...);

			Z_INLINE MemberFunction() Z_DEFAULTED({})


#			if Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE) && Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)
				Z_CT(CPP11) MemberFunction(NullPointer)
				: function(NULL) {};
#			endif


			template <class M, class E = typename EnableIf<
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			M>::type>
			Z_INLINE MemberFunction(M function)
			: function((R (NaT::*)(P...))function) {}


			Z_CT(CPP11) operator Boolean() const {return function != NULL;}


			template <class M, class E = typename EnableIf<
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			M>::type>
			Z_INLINE operator M() const {return (M)function;}


			template <class M>
			Z_INLINE typename EnableIf<
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			MemberFunction &>::type
			operator =(M rhs)
				{
				function = (R (NaT::*)(P...))rhs;
				return *this;
				}


			template <class O, class RR = R>
			Z_INLINE typename EnableIf<Type<RR>::is_void, RR>::type
			operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{(((NaT *)object)->*function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE typename EnableIf<Type<R>::is_void, RR>::type
			operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{(((NaT *)&object)->*function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE typename EnableIf<!Type<R>::is_void, RR>::type
			operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{return (((NaT *)object)->*function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE typename EnableIf<!Type<R>::is_void, RR>::type
			operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{return (((NaT *)&object)->*function)(arguments...);}
		};
	}


#	define Z_HAS_CLASS_MemberFunction TRUE
#else
#	define Z_HAS_CLASS_MemberFunction FALSE
#endif

#endif // _Z_classes_functional_MemberFunction_HPP_
