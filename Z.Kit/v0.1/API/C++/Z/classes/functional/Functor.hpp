/* Z Kit C++ API - classes/functional/Functor.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_functional_Functor_HPP__
#define __Z_classes_functional_Functor_HPP__

#include <Z/classes/functional/ObjectMemberFunction.hpp>
//#include <Z/classes/functional/ObjectSelector.hpp>


#if Z_LANGUAGE_HAS(CPP, SFINAE) && Z_LANGUAGE_HAS(CPP, LAMBDA)


	namespace Zeta {

		template <class F> class Functor;

		template <class R, class... P> class Functor<R(P...)> {

			private:
			R    (* call   )(const Functor *, typename Type<P>::to_forwardable...);
			void (* destroy)(void *);

			union {	R (* function)(P...);
				ObjectMemberFunction<R(P...)> object_member_function;
#				if Z_HAS_CLASS(ObjectSelector)
					ObjectSelector<R(P...)> object_selector;
#				endif
			} target;

			public:

			Z_CT_MEMBER(CPP11) Functor() : call(NULL), destroy([](void *){}) {}


			Z_INLINE_MEMBER
			Functor(typename EnableIf<Type<R>::is_void, R (*)(P...)>::type function) :
			call([](const Functor *functor, typename Type<P>::to_forwardable... arguments)
				{functor->target.function(arguments...);}),
			destroy([](void *){})
				{target.function = function;}


			Z_INLINE_MEMBER
			Functor(typename EnableIf<!Type<R>::is_void, R (*)(P...)>::type function) :
			call([](const Functor *functor, typename Type<P>::to_forwardable... arguments)
				{return functor->target.function(arguments...);}),
			destroy([](void *){})
				{target.function = function;}


			Z_INLINE_MEMBER
			Functor(typename EnableIf<Type<R>::is_void, const ObjectMemberFunction<R(P...)> &>::type object_member_function) :
			call([](const Functor *functor, typename Type<P>::to_forwardable... arguments)
				{(functor->target.object_member_function->*functor->target.object_member_function->function)(arguments...);}),
			destroy([](void *){})
				{target.object_member_function = object_member_function;}


			Z_INLINE_MEMBER
			Functor(typename EnableIf<!Type<R>::is_void, const ObjectMemberFunction<R(P...)> &>::type object_member_function) :
			call([](const Functor *functor, typename Type<P>::to_forwardable... arguments)
				{return (functor->target.object_member_function->*functor->target.object_member_function->function)(arguments...);}),
			destroy([](void *){})
				{target.object_member_function = object_member_function;}


#			if Z_HAS_CLASS(ObjectSelector)

				Z_INLINE_MEMBER
				Functor(const ObjectSelector<R(P...)> &object_selector) :
				call([](const Functor *functor, typename Type<P>::to_forwardable... arguments)
					{return functor->target.object_selector(arguments...);}),
				destroy([](void *){})
					{target.object_selector = object_selector;}


				Z_INLINE_MEMBER
				Functor(id object, SEL selector) :
				call([](const Functor *functor, typename Type<P>::to_forwardable... arguments)
					{return functor->target.object_selector(arguments...);}),
				destroy([](void *){})
					{target.object_selector = ObjectSelector(object, selector);}

#			endif


			Z_INLINE_MEMBER ~Functor() {destroy(this);}


			Z_CT_MEMBER(CPP11) operator Boolean() const {return call != NULL;}


			template <bool void_return = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<void_return, void>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{call(this, arguments...);}


			template <bool void_return = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!void_return, R>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{return call(this, arguments...);}
		};

	}


#endif

#endif // __Z_classes_functional_Functor_HPP__
