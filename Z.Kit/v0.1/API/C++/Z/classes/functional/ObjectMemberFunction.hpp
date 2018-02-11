/* Z Kit C++ API - classes/functional/ObjectMemberFunction.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_functional_ObjectMemberFunction_HPP__
#define __Z_classes_functional_ObjectMemberFunction_HPP__

#include <Z/classes/functional/MemberFunction.hpp>

#if Z_HAS_CLASS_MEMBER_FUNCTION


	namespace Zeta {

		template <class F> class ObjectMemberFunction;

		template <class R, class... P>
		class ObjectMemberFunction<R(P...)> : public MemberFunction<R(P...)> {

			private:
			typedef MemberFunction<R(P...)> Super;

			public:
			NaT *object;

			Z_INLINE_MEMBER ObjectMemberFunction() {}


#			if Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)
				Z_CT_MEMBER(CPP11) ObjectMemberFunction(NullPointer)
				: Super(NULL), object(NULL) {};
#			endif


			template <class O, class M, class E = typename EnableIf<
				Type<O>::is_pointer			 &&
				Type<O>::flow::pointee_type::is_compound &&
				Type<M>::is_member_function_pointer	 &&
				TypeAreEqual<
					typename Type<M>::flow::to_function::end::to_unqualified,
					typename Super::Function
				>::value,
			M>::type>
			Z_INLINE_MEMBER ObjectMemberFunction(O object, M function)
			: Super(function), object((NaT *)object) {}


			template <class O, class M, class E = typename EnableIf<
				Type<O>::is_compound		    &&
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<
					typename Type<M>::flow::to_function::end::to_unqualified,
					typename Super::Function
				>::value,
			M>::type>
			Z_INLINE_MEMBER ObjectMemberFunction(const O &object, M function)
			: Super(function), object((NaT *)&object) {}


			template <class O, class E = typename EnableIf<
				Type<O>::is_pointer &&
				Type<O>::flow::pointee_type::is_compound,
			O>::type>
			Z_INLINE_MEMBER operator O() const {return (O)object;}


			template <class O, class E = typename EnableIf<Type<O>::is_compound, O>::type>
			Z_INLINE_MEMBER O &operator *() const {return *(O *)object;}


			template <class O, bool void_return = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<void_return, void>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{(object->*this->function)(arguments...);}


			template <class O, bool void_return = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!void_return, R>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{return (object->*this->function)(arguments...);}
		};
	}


#	define Z_HAS_CLASS_OBJECT_MEMBER_FUNCTION TRUE
#else
#	define Z_HAS_CLASS_OBJECT_MEMBER_FUNCTION FALSE
#endif

#endif // __Z_classes_functional_ObjectMemberFunction_HPP__
