/* Zeta API - Z/classes/MemberFunction.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_MemberFunction_HPP
#define Z_classes_MemberFunction_HPP

#include <Z/inspection/language.h>

#if	Z_DIALECT_HAS(CPP98, SFINAE)		&& \
	Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE) && \
	Z_DIALECT_HAS(CPP11, DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE)

#	define Z_HAS_MemberFunction 1

#	include <Z/constants/pointer.h>
#	include <Z/traits/type.hpp>


	namespace Zeta {
		template <class f> struct MemberFunction;

		template <class r, class... p> struct MemberFunction<r(p...)> {
			r (NaT::* function)(p...);


			Z_INLINE MemberFunction() Z_NOTHROW
				Z_DEFAULTED({})


#			ifdef Z_NULLPTR
				Z_CT(CPP11) MemberFunction(NullPtr) Z_NOTHROW
				: function(nullptr) {};
#			endif


			template <class m, class e = typename TypeIf<
				Type<m>::is_member_function_pointer &&
				TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value
			>::type>
			Z_INLINE MemberFunction(m function) Z_NOTHROW
			: function(reinterpret_cast<r (NaT::*)(p...)>(function)) {}


			Z_CT(CPP11) operator Boolean() const Z_NOTHROW
				{return function != Z_NULL;}


			template <class m, class e = typename TypeIf<
				Type<m>::is_member_function_pointer &&
				TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value
			>::type>
			Z_INLINE operator m() const Z_NOTHROW
				{return reinterpret_cast<m>(function);}


			template <class m>
			Z_INLINE typename TypeIf<
				Type<m>::is_member_function_pointer &&
				TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value,
			MemberFunction &>::type
			operator =(m rhs) Z_NOTHROW
				{
				function = reinterpret_cast<r (NaT::*)(p...)>(rhs);
				return *this;
				}


			template <class o>
			Z_INLINE r operator ()(o *object, typename Type<p>::to_forwardable... arguments) const
				{return (reinterpret_cast<NaT *>(object)->*function)(arguments...);}


			template <class o>
			Z_INLINE r operator ()(const o &object, typename Type<p>::to_forwardable... arguments) const
				{return (const_cast<NaT *>(reinterpret_cast<const NaT *>(&object))->*function)(arguments...);}
		};
	}
#endif

#endif // Z_classes_MemberFunction_HPP
