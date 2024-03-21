/* Zeta API - Z/classes/ObjectMemberFunction.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_ObjectMemberFunction_HPP
#define Z_classes_ObjectMemberFunction_HPP

#include <Z/inspection/Z.h>
#include <Z/classes/MemberFunction.hpp>

#if Z_HAS(MemberFunction)
#	define Z_HAS_ObjectMemberFunction 1


	namespace Zeta {
		template <class f> struct ObjectMemberFunction;

		template <class r, class... p>
		struct ObjectMemberFunction<r(p...)> : MemberFunction<r(p...)> {
			NaT *object;


			Z_INLINE ObjectMemberFunction() Z_NOTHROW
				Z_DEFAULTED({})


#			if Z_DIALECT_HAS(CPP11, INHERITING_CONSTRUCTORS)
				using MemberFunction<r(p...)>::MemberFunction;
#			else
				template <class m, class e = typename TypeIf<
					Type<m>::is_member_function_pointer &&
					TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value
				>::type>
				Z_INLINE ObjectMemberFunction(m function) Z_NOTHROW
				: MemberFunction<r(p...)>(function) {}
#			endif


#			ifdef Z_NULLPTR
				Z_CT(CPP11) ObjectMemberFunction(NullPtr) Z_NOTHROW
				: MemberFunction<r(p...)>(nullptr), object(nullptr) {};
#			endif


			template <class o, class m, class e = typename TypeIf<
				(Type<o>::is_void_pointer		  ||
				 (Type<o>::is_pointer			  &&
				  Type<o>::flow::pointee_type::is_class)) &&
				Type<m>::is_member_function_pointer	  &&
				TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value
			>::type>
			Z_INLINE ObjectMemberFunction(o object, m function) Z_NOTHROW
			: MemberFunction<r(p...)>(function), object(reinterpret_cast<NaT *>(object)) {}


			template <class o, class m, class e = typename TypeIf<
				Type<o>::is_class		    &&
				Type<m>::is_member_function_pointer &&
				TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value
			>::type>
			Z_INLINE ObjectMemberFunction(const o &object, m function) Z_NOTHROW
			: MemberFunction<r(p...)>(function), object(reinterpret_cast<NaT *>(&object)) {}


			template <class o, class e = typename TypeIf<Type<o>::is_class>::type>
			Z_INLINE operator o *() const Z_NOTHROW
				{return reinterpret_cast<o *>(object);}


			template <class o>
			Z_INLINE typename TypeIf<Type<o>::is_class, ObjectMemberFunction &>::type
			operator =(o *rhs) Z_NOTHROW
				{
				object = reinterpret_cast<NaT *>(rhs);
				return *this;
				}


			template <class o>
			Z_INLINE typename TypeIf<Type<o>::is_class, ObjectMemberFunction &>::type
			operator =(const o &rhs) Z_NOTHROW
				{
				object = reinterpret_cast<NaT *>(&rhs);
				return *this;
				}


			template <class m>
			Z_INLINE typename TypeIf<
				Type<m>::is_member_function_pointer &&
				TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value,
			ObjectMemberFunction &>::type
			operator =(m rhs) Z_NOTHROW
				{
				this->function = reinterpret_cast<r (NaT::*)(p...)>(rhs);
				return *this;
				}


			Z_INLINE r operator ()(typename Type<p>::to_forwardable... arguments) const
				{return (object->*this->function)(arguments...);}


			template <class o>
			Z_INLINE r operator ()(o *object, typename Type<p>::to_forwardable... arguments) const
				{return (reinterpret_cast<NaT *>(object)->*this->function)(arguments...);}


			template <class o>
			Z_INLINE r operator ()(const o &object, typename Type<p>::to_forwardable... arguments) const
				{return (reinterpret_cast<NaT *>(&object)->*this->function)(arguments...);}


			template <class o, class m>
			Z_INLINE typename TypeIf<
				(Type<o>::is_void || Type<o>::is_class) &&
				Type<m>::is_member_function_pointer	&&
				TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value,
			ObjectMemberFunction &>::type
			set(o *object, m function) Z_NOTHROW
				{
				this->function = reinterpret_cast<r (NaT::*)(p...)>(function);
				this->object   = reinterpret_cast<NaT *>(&object);
				return *this;
				}


			template <class o, class m>
			Z_INLINE typename TypeIf<
				Type<o>::is_class		    &&
				Type<m>::is_member_function_pointer &&
				TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value,
			ObjectMemberFunction &>::type
			set(const o &object, m function) Z_NOTHROW
				{
				this->function = reinterpret_cast<r (NaT::*)(p...)>(function);
				this->object   = const_cast<NaT *>(reinterpret_cast<const NaT *>(&object));
				return *this;
				}
		};
	}
#endif

#endif // Z_classes_ObjectMemberFunction_HPP
