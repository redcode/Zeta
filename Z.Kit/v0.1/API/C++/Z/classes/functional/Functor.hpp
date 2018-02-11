/* Z Kit C++ API - classes/functional/Functor.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_functional_Functor_HPP__
#define __Z_classes_functional_Functor_HPP__

#if	Z_LANGUAGE_HAS(CPP, SFINAE) && \
	Z_LANGUAGE_HAS(CPP, LAMBDA) && \
	Z_LANGUAGE_HAS(CPP, INHERITING_CONSTRUCTORS)


	namespace Zeta {namespace Deferred {

		template <class function_prototype, class parameter_list> struct Functor;

		template <class F, class... P> struct Functor<F, TypeList<P...> > {

			typedef typename Type<F>::return_type R;

			R (* caller)(const Functor *, typename Type<P>::to_forwardable...);
			void *data;
			typename TypeToMemberPointer<F, NaT>::type member_function;


			Z_INLINE_MEMBER Functor() {};


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER Functor(
				typename EnableIf<returns_void, typename Type<F>::add_pointer>::type function
			) :
			caller([](const Functor *function, typename Type<P>::to_forwardable... arguments)
				{((typename Type<F>::add_pointer)function->data)(arguments...);}),
			data((void *)function)
				{}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER Functor(
				typename EnableIf<!returns_void, typename Type<F>::add_pointer>::type function
			) :
			caller([](const Functor *function, typename Type<P>::to_forwardable... arguments)
				{return ((typename Type<F>::add_pointer)function->data)(arguments...);}),
			data((void *)function)
				{}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER Functor(
				typename EnableIf<returns_void, void *>::type object,
				OpaqueMemberFunctionPointer member_function
			) :
			caller([](const Functor *function, typename Type<P>::to_forwardable... arguments)
				{((NaT *)function->data)->*(function->member_function)(arguments...);}),
			data(object), member_function(member_function)
				{}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER Functor(
				typename EnableIf<!returns_void, void *>::type object,
				OpaqueMemberFunctionPointer member_function
			) :
			caller([](const Functor *function, typename Type<P>::to_forwardable... arguments)
				{return (((NaT *)function->data)->*(function->member_function))(arguments...);}),
			data(object), member_function(member_function)
				{}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<returns_void, void>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{caller(this, arguments...);}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!returns_void, R>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{return caller(this, arguments...);}

		};
	}}


	namespace Zeta {template <class F> struct Functor : Deferred::Functor<F, typename Type<F>::parameters> {
		typedef Deferred::Functor<F, typename Type<F>::parameters> Super;

		using Super::Super;
	};}


#endif

#endif // __Z_classes_functional_Functor_HPP__
