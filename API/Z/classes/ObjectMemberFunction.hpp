/* Z Kit - classes/ObjectMemberFunction.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_ObjectMemberFunction_HPP
#define Z_classes_ObjectMemberFunction_HPP

#include <Z/inspection/Z.h>
#include <Z/classes/MemberFunction.hpp>

#if Z_DECLARES(MemberFunction)


	namespace Zeta {

		template <class F> struct ObjectMemberFunction;

		template <class R, class... P> struct ObjectMemberFunction<R(P...)> : MemberFunction<R(P...)> {
			NaT *object;


			Z_INLINE ObjectMemberFunction() Z_NOTHROW
				Z_DEFAULTED({})


#			if Z_DIALECT_HAS(CPP, INHERITING_CONSTRUCTORS)
				using MemberFunction<R(P...)>::MemberFunction;
#			else
				template <class M, class E = typename TypeIf<
					Type<M>::is_member_function_pointer &&
					TypeIsSame<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value
				>::type>
				Z_INLINE ObjectMemberFunction(M function) Z_NOTHROW
				: MemberFunction<R(P...)>(function) {}
#			endif


#			ifdef Z_NULLPTR
				Z_CT(CPP11) ObjectMemberFunction(NullPtr) Z_NOTHROW
				: MemberFunction<R(P...)>(NULL), object(NULL) {};
#			endif


			template <class O, class M, class E = typename TypeIf<
				(Type<O>::is_void_pointer		  ||
				 (Type<O>::is_pointer			  &&
				  Type<O>::flow::pointee_type::is_class)) &&
				Type<M>::is_member_function_pointer	  &&
				TypeIsSame<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value
			>::type>
			Z_INLINE ObjectMemberFunction(O object, M function) Z_NOTHROW
			: MemberFunction<R(P...)>(function), object(reinterpret_cast<NaT *>(object)) {}


			template <class O, class M, class E = typename TypeIf<
				Type<O>::is_class		    &&
				Type<M>::is_member_function_pointer &&
				TypeIsSame<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value
			>::type>
			Z_INLINE ObjectMemberFunction(const O &object, M function) Z_NOTHROW
			: MemberFunction<R(P...)>(function), object(reinterpret_cast<NaT *>(&object)) {}


			template <class O, class E = typename TypeIf<Type<O>::is_class>::type>
			Z_INLINE operator O *() const Z_NOTHROW
				{return reinterpret_cast<O *>(object);}


			template <class O>
			Z_INLINE typename TypeIf<Type<O>::is_class, ObjectMemberFunction &>::type
			operator =(O *rhs) Z_NOTHROW
				{
				object = reinterpret_cast<NaT *>(rhs);
				return *this;
				}


			template <class O>
			Z_INLINE typename TypeIf<Type<O>::is_class, ObjectMemberFunction &>::type
			operator =(const O &rhs) Z_NOTHROW
				{
				object = reinterpret_cast<NaT *>(&rhs);
				return *this;
				}


			template <class M>
			Z_INLINE typename TypeIf<
				Type<M>::is_member_function_pointer &&
				TypeIsSame<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			ObjectMemberFunction &>::type
			operator =(M rhs) Z_NOTHROW
				{
				this->function = reinterpret_cast<R (NaT::*)(P...)>(rhs);
				return *this;
				}


			Z_INLINE R operator ()(typename Type<P>::to_forwardable... arguments) const
				{return (object->*this->function)(arguments...);}


			template <class O>
			Z_INLINE R operator ()(O *object, typename Type<P>::to_forwardable... arguments) const
				{return (reinterpret_cast<NaT *>(object)->*this->function)(arguments...);}


			template <class O>
			Z_INLINE R operator ()(const O &object, typename Type<P>::to_forwardable... arguments) const
				{return (reinterpret_cast<NaT *>(&object)->*this->function)(arguments...);}


			template <class O, class M>
			Z_INLINE typename TypeIf<
				(Type<O>::is_void || Type<O>::is_class) &&
				Type<M>::is_member_function_pointer	&&
				TypeIsSame<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			ObjectMemberFunction &>::type
			set(O *object, M function) Z_NOTHROW
				{
				this->function = reinterpret_cast<R (NaT::*)(P...)>(function);
				this->object   = reinterpret_cast<NaT *>(&object);
				return *this;
				}


			template <class O, class M>
			Z_INLINE typename TypeIf<
				Type<O>::is_class		    &&
				Type<M>::is_member_function_pointer &&
				TypeIsSame<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			ObjectMemberFunction &>::type
			set(const O &object, M function) Z_NOTHROW
				{
				this->function = reinterpret_cast<R (NaT::*)(P...)>(function);
				this->object   = const_cast<NaT *>(reinterpret_cast<const NaT *>(&object));
				return *this;
				}
		};
	}


#	define Z_DECLARES_ObjectMemberFunction TRUE
#else
#	define Z_DECLARES_ObjectMemberFunction FALSE
#endif

#endif // Z_classes_ObjectMemberFunction_HPP
