/* Z Kit C++ API - classes/functional/ObjectMemberFunction.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_functional_ObjectMemberFunction_HPP__
#define __Z_classes_functional_ObjectMemberFunction_HPP__

#include <Z/classes/functional/MemberFunction.hpp>

#if Z_HAS_CLASS_MemberFunction


	namespace Zeta {

		template <class F> struct ObjectMemberFunction;

		template <class R, class... P> struct ObjectMemberFunction<R(P...)> : MemberFunction<R(P...)> {
			NaT *object;

			Z_INLINE_MEMBER ObjectMemberFunction() {}


#			if Z_LANGUAGE_HAS(CPP, INHERITING_CONSTRUCTORS)
				using MemberFunction<R(P...)>::MemberFunction;
#			else
				template <class M, class E = typename EnableIf<
					Type<M>::is_member_function_pointer &&
					TypeAreEqual<
						typename Type<M>::flow::to_function::end::to_unqualified,
						R(P...)
					>::value,
				M>::type>
				Z_INLINE_MEMBER ObjectMemberFunction(M function)
				: MemberFunction<R(P...)>(function) {}
#			endif


#			if Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)
				Z_CT_MEMBER(CPP11) ObjectMemberFunction(NullPointer)
				: MemberFunction<R(P...)>(NULL), object(NULL) {};
#			endif


			template <class O, class M, class E = typename EnableIf<
				Type<O>::is_pointer			 &&
				Type<O>::flow::pointee_type::is_compound &&
				Type<M>::is_member_function_pointer	 &&
				TypeAreEqual<
					typename Type<M>::flow::to_function::end::to_unqualified,
					R(P...)
				>::value,
			M>::type>
			Z_INLINE_MEMBER ObjectMemberFunction(O object, M function)
			: MemberFunction<R(P...)>(function), object((NaT *)object) {}


			template <class O, class M, class E = typename EnableIf<
				Type<O>::is_compound		    &&
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<
					typename Type<M>::flow::to_function::end::to_unqualified,
					R(P...)
				>::value,
			M>::type>
			Z_INLINE_MEMBER ObjectMemberFunction(const O &object, M function)
			: MemberFunction<R(P...)>(function), object((NaT *)&object) {}


			template <class O, class E = typename EnableIf<Type<O>::is_compound, O>::type>
			Z_INLINE_MEMBER operator O *() const {return (O *)object;}


			template <class O, class E = typename EnableIf<Type<O>::is_compound, O>::type>
			Z_INLINE_MEMBER ObjectMemberFunction &operator =(O *object)
				{
				this->object = (NaT *)object;
				return *this;
				}


			template <class O, class E = typename EnableIf<Type<O>::is_compound, O>::type>
			Z_INLINE_MEMBER ObjectMemberFunction &operator =(const O &object)
				{
				this->object = (NaT *)&object;
				return *this;
				}


			template <class M, class E = typename EnableIf<
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<
					typename Type<M>::flow::to_function::end::to_unqualified,
					R(P...)
				>::value,
			M>::type>
			Z_INLINE_MEMBER ObjectMemberFunction &operator =(M function)
				{
				this->function = (R (NaT::*)(P...))function;
				return *this;
				}


			template <class O, bool void_return = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<void_return, void>::type
			operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{(((NaT *)object)->*this->function)(arguments...);}


			template <class O, bool void_return = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<void_return, void>::type
			operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{(((NaT *)&object)->*this->function)(arguments...);}


			template <class O, bool void_return = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!void_return, R>::type
			operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{return (((NaT *)object)->*this->function)(arguments...);}


			template <class O, bool void_return = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!void_return, R>::type
			operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{return (((NaT *)&object)->*this->function)(arguments...);}


			template <bool void_return = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<void_return, void>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{(object->*this->function)(arguments...);}


			template <bool void_return = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!void_return, R>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{return (object->*this->function)(arguments...);}
		};
	}


#	define Z_HAS_CLASS_ObjectMemberFunction TRUE
#else
#	define Z_HAS_CLASS_ObjectMemberFunction FALSE
#endif

#endif // __Z_classes_functional_ObjectMemberFunction_HPP__
