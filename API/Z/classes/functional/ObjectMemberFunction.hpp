/* Z Kit - classes/functional/ObjectMemberFunction.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_functional_ObjectMemberFunction_HPP_
#define _Z_classes_functional_ObjectMemberFunction_HPP_

#include <Z/inspection/Z.h>
#include <Z/classes/functional/MemberFunction.hpp>

#if Z_HAS_CLASS(MemberFunction)


	namespace Zeta {

		template <class F> struct ObjectMemberFunction;

		template <class R, class... P> struct ObjectMemberFunction<R(P...)> : MemberFunction<R(P...)> {
			NaT *object;

			Z_INLINE ObjectMemberFunction() Z_DEFAULTED({})


#			if Z_LANGUAGE_HAS(CPP, INHERITING_CONSTRUCTORS)
				using MemberFunction<R(P...)>::MemberFunction;
#			else
				template <class M, class E = typename EnableIf<
					Type<M>::is_member_function_pointer &&
					TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
				M>::type>
				Z_INLINE ObjectMemberFunction(M function)
				: MemberFunction<R(P...)>(function) {}
#			endif


#			if Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE) && Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)
				Z_CT(CPP11) ObjectMemberFunction(NullPointer)
				: MemberFunction<R(P...)>(NULL), object(NULL) {};
#			endif


			template <class O, class M, class E = typename EnableIf<
				(Type<O>::is_void_pointer			       ||
				 (Type<O>::is_pointer				       &&
				  Type<O>::flow::pointee_type::is_structure_or_union)) &&
				Type<M>::is_member_function_pointer		       &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			M>::type>
			Z_INLINE ObjectMemberFunction(O object, M function)
			: MemberFunction<R(P...)>(function), object((NaT *)object) {}


			template <class O, class M, class E = typename EnableIf<
				Type<O>::is_structure_or_union	    &&
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			M>::type>
			Z_INLINE ObjectMemberFunction(const O &object, M function)
			: MemberFunction<R(P...)>(function), object((NaT *)&object) {}


			template <class O, class E = typename EnableIf<Type<O>::is_structure_or_union, O>::type>
			Z_INLINE operator O *() const {return (O *)object;}


			template <class O>
			Z_INLINE typename EnableIf<Type<O>::is_structure_or_union, ObjectMemberFunction &>::type
			operator =(O *rhs)
				{
				object = (NaT *)rhs;
				return *this;
				}


			template <class O>
			Z_INLINE typename EnableIf<Type<O>::is_structure_or_union, ObjectMemberFunction &>::type
			operator =(const O &rhs)
				{
				object = (NaT *)&rhs;
				return *this;
				}


			template <class M>
			Z_INLINE typename EnableIf<
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			ObjectMemberFunction &>::type
			operator =(M rhs)
				{
				this->function = (R (NaT::*)(P...))rhs;
				return *this;
				}


			template <class RR = R>
			Z_INLINE typename EnableIf<Type<RR>::is_void, RR>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{(object->*this->function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE typename EnableIf<Type<RR>::is_void, RR>::type
			operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{(((NaT *)object)->*this->function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE typename EnableIf<Type<RR>::is_void, RR>::type
			operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{(((NaT *)&object)->*this->function)(arguments...);}


			template <class RR = R>
			Z_INLINE typename EnableIf<!Type<RR>::is_void, RR>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{return (object->*this->function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE typename EnableIf<!Type<RR>::is_void, RR>::type
			operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{return (((NaT *)object)->*this->function)(arguments...);}


			template <class O, class RR = R>
			Z_INLINE typename EnableIf<!Type<RR>::is_void, RR>::type
			operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{return (((NaT *)&object)->*this->function)(arguments...);}


			template <class O, class M>
			Z_INLINE typename EnableIf<
				(Type<O>::is_void_pointer			       ||
				 (Type<O>::is_pointer				       &&
				  Type<O>::flow::pointee_type::is_structure_or_union)) &&
				Type<M>::is_member_function_pointer		       &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			ObjectMemberFunction &>::type
			set(O object, M function)
				{
				this->function = (R (NaT::*)(P...))function;
				this->object   = (NaT *)&object;
				return *this;
				}


			template <class O, class M>
			Z_INLINE typename EnableIf<
				Type<O>::is_structure_or_union	    &&
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			ObjectMemberFunction &>::type
			set(const O &object, M function)
				{
				this->function = (R (NaT::*)(P...))function;
				this->object   = (NaT *)&object;
				return *this;
				}
		};
	}


#	define Z_HAS_CLASS_ObjectMemberFunction TRUE
#else
#	define Z_HAS_CLASS_ObjectMemberFunction FALSE
#endif

#endif // _Z_classes_functional_ObjectMemberFunction_HPP_
