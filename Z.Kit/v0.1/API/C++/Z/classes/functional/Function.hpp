/* Z Kit C++ API - classes/functional/Function.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_functional_Function_HPP__
#define __Z_classes_functional_Function_HPP__

#if	Z_LANGUAGE_HAS(CPP, LAMBDA) && \
	Z_LANGUAGE_HAS(CPP, INHERITING_CONSTRUCTORS)


	namespace Zeta {namespace Detail {

		template <class function, class parameter_list> struct Function;

		template <class F, class... P> struct Function<F, TypeList<P...> > {

			typedef typename Zeta::Type<F>::return_type R;

			R (* caller)(const Function *, typename Zeta::Type<P>::to_forwardable...);
			void *data;
			typename TypeToMemberPointer<F, NaT>::type member_function;


			template <bool returns_void = Zeta::Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<returns_void, void>::type
			operator ()(typename Zeta::Type<P>::to_forwardable... arguments) const
				{caller(this, arguments...);}


			template <bool returns_void = Zeta::Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!returns_void, R>::type
			operator ()(typename Zeta::Type<P>::to_forwardable... arguments) const
				{return caller(this, arguments...);}


			Z_INLINE_MEMBER Function() {};


			template <bool returns_void = Zeta::Type<R>::is_void>
			Z_INLINE_MEMBER Function(
				typename EnableIf<returns_void, typename Zeta::Type<F>::add_pointer>::type function
			) :
			caller([](const Function *function, typename Zeta::Type<P>::to_forwardable... arguments)
				{((typename Zeta::Type<F>::add_pointer)function->data)(arguments...);}),
			data((void *)function)
				{}


			template <bool returns_void = Zeta::Type<R>::is_void>
			Z_INLINE_MEMBER Function(
				typename EnableIf<!returns_void, typename Zeta::Type<F>::add_pointer>::type function
			) :
			caller([](const Function *function, typename Zeta::Type<P>::to_forwardable... arguments)
				{return ((typename Zeta::Type<F>::add_pointer)function->data)(arguments...);}),
			data((void *)function)
				{}


			template <bool returns_void = Zeta::Type<R>::is_void>
			Z_INLINE_MEMBER Function(
				typename EnableIf<returns_void, void *>::type object,
				OpaqueMemberFunctionPointer member_function
			) :
			caller([](const Function *function, typename Zeta::Type<P>::to_forwardable... arguments)
				{((NaT *)function->data)->*(function->member_function)(arguments...);}),
			data(object), member_function(member_function)
				{}


			template <bool returns_void = Zeta::Type<R>::is_void>
			Z_INLINE_MEMBER Function(
				typename EnableIf<!returns_void, void *>::type object,
				OpaqueMemberFunctionPointer member_function
			) :
			caller([](const Function *function, typename Zeta::Type<P>::to_forwardable... arguments)
				{return (((NaT *)function->data)->*(function->member_function))(arguments...);}),
			data(object), member_function(member_function)
				{}
		};
	}}


	namespace Zeta {template <class F> struct Function : Detail::Function<F, typename Type<F>::parameters> {
		typedef Detail::Function<F, typename Type<F>::parameters> Super;

		using Super::Super;
	};}


#endif

#endif // __Z_classes_functional_Function_HPP__
