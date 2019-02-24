/* Z Kit - classes/MemberFunction.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_MemberFunction_HPP
#define Z_classes_MemberFunction_HPP

#include <Z/inspection/language.h>

#if	Z_DIALECT_HAS(CPP, SFINAE)	      && \
	Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE) && \
	Z_DIALECT_HAS(CPP, DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE)

#	include <Z/traits/Type.hpp>


	namespace Zeta {

		template <class F> struct MemberFunction;

		template <class R, class... P> struct MemberFunction<R(P...)> {
			R (NaT::* function)(P...);


			Z_INLINE MemberFunction() Z_NOTHROW
				Z_DEFAULTED({})


#			ifdef Z_NULL_POINTER
				Z_CT(CPP11) MemberFunction(NullPointer) Z_NOTHROW
				: function(NULL) {};
#			endif


			template <class M, class E = typename TypeIf<
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			M>::type>
			Z_INLINE MemberFunction(M function) Z_NOTHROW
			: function(reinterpret_cast<R (NaT::*)(P...)>(function)) {}


			Z_CT(CPP11) operator Boolean() const Z_NOTHROW
				{return function != NULL;}


			template <class M, class E = typename TypeIf<
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			M>::type>
			Z_INLINE operator M() const Z_NOTHROW
				{return reinterpret_cast<M>(function);}


			template <class M>
			Z_INLINE typename TypeIf<
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			MemberFunction &>::type
			operator =(M rhs) Z_NOTHROW
				{
				function = reinterpret_cast<R (NaT::*)(P...)>(rhs);
				return *this;
				}


			template <class O, class RR = R>
			Z_INLINE typename TypeIf<Type<RR>::is_void, RR>::type
			operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{(reinterpret_cast<NaT *>(object)->*function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE typename TypeIf<Type<R>::is_void, RR>::type
			operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{(reinterpret_cast<NaT *>(&object)->*function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE typename TypeIf<!Type<R>::is_void, RR>::type
			operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{return (reinterpret_cast<NaT *>(object)->*function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE typename TypeIf<!Type<R>::is_void, RR>::type
			operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{return (reinterpret_cast<NaT *>(&object)->*function)(arguments...);}
		};
	}


#	define Z_HAS_CLASS_MemberFunction TRUE
#else
#	define Z_HAS_CLASS_MemberFunction FALSE
#endif

#endif // Z_classes_MemberFunction_HPP
